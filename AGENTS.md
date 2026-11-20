# AGENTS.md

This file provides guidance to coding agents when working with code in this repository.

## What this is

lucenaBAL is a **header-only, preprocessor-only** C++ library (C++11+) that normalizes feature detection across compilers (AppleClang, Clang, GCC, MSVC), Standard Libraries (libc++, Apple libc++, libstdc++, MSVC STL), and platforms (Apple, POSIX/X11, WinAPI). It exposes `LBAL_*` macros, mostly modeled on SD-6 tokens with a Standard tag added (e.g. `__cpp_lib_optional` → `LBAL_LIBCPP17_OPTIONAL`, `__cpp_concepts` → `LBAL_CPP20_CONCEPTS`). Tokens are tracked up through C++26, plus accepted C++29 proposals under `CPP2D`/`LIBCPP2D` names. Consumers include `<lucenaBAL/lucenaBAL.hpp>`.

Known gap (README): compiler/library-specific fixups for C++23/26 aren't integrated yet. Those tokens rely on self-reporting via `<version>` and predefined macros, so false negatives and positives are expected.

## Commands

CMake ≥ 3.30. In-source builds are rejected; always use a separate `build/` dir.

```sh
cmake -DCMAKE_BUILD_TYPE=Release -S . -B build      # configure (add -DLBAL_BUILD_DOCS=ON for Doxygen docs)
cmake --build build                                  # builds tests/lbalTest (fetches GoogleTest v1.17.0)
ctest --test-dir build                               # or: cmake --build build --target test
ctest --test-dir build -R <regex>                    # single test (gtest_discover_tests names, e.g. lbalTest.Validation)
./build/tests/lbalTest --gtest_filter='lbalTest.*'   # run the gtest binary directly
cmake --build build --target format                  # clang-format all include/**/*.hpp and tests/*.{cpp,hpp}
cmake --build build --target format-dry              # show the clang-format diff without applying it
cmake --build build --target install                 # install headers + CMake config
```

Configure options: `LBAL_BUILD_DOCS`, `LBAL_CONFIG_DISABLE_PEDANTIC_WARNINGS`, `LBAL_CONFIG_TREAT_UNCERTAINTY_AS_FAILURE`. The library interface requires `cxx_std_26` (MSVC gets `/std:c++latest`). The build sets `LBAL_TARGET_OS_*` from `CMAKE_SYSTEM_NAME`. Non-CMake consumers must define one themselves, or `lbalDefinitionTests.hpp` will `#error`.

CI (`.github/workflows/main.yml`) runs configure/build/ctest on macOS/Xcode, Ubuntu/gcc-15 and Windows/MSVC. `doxygen.yml` publishes the docs.

## Architecture: how a feature token is resolved

The include chain is `lucenaBAL.hpp` → `lbalConfig.hpp` + `lbalFeatureSetup.hpp`. Feature resolution is layered, and **every layer guards with `#if !defined(TOKEN)`, so the first definition wins**:

1. **`details/lbalDefinitionTests.hpp`**: `#error`s if any `LBAL_*` token was defined externally. The exceptions are `LBAL_TARGET_OS_*` and `LBAL_TARGET_API_*`, which the build system supplies. Every new token must be added to this list.
2. **`details/lbalCompilerSetup.hpp`**: does detection (`lbalDetectCompiler.hpp`), then includes `compilers/lbal<Compiler>Initialization.hpp`. It maps SD-6 language macros to `LBAL_CPPxx_*`, then includes `compilers/lbal<Compiler>PostInitialization.hpp`. Version-gated per-compiler overrides and fixups live in the Initialization and PostInitialization files, e.g. `LBAL_GCC_VERSION >= 40900`.
3. **`details/lbalLibrarySetup.hpp`** (large): applies the same pattern to Standard Library tokens (`LBAL_LIBCPPxx_*`), using `lbalDetectStandardLibrary.hpp` and `libraries/lbalStandardLibrary<Impl>{,Post}Initialization.hpp`.
4. **`details/lbalPlatformSetup.hpp`**: includes `platforms/lbalPlatform{Apple,POSIX,WinAPI}.hpp`.
5. **`lbalFeatureSetup.hpp`**: the documented public surface. It holds the Doxygen `@name` groups and includes `details/lbalFeatureSetup-overview-{cpp,libcpp}NN.inc`, one per Standard. Each `.inc` holds a token's Doxygen `@def` docs (the SD-6 equivalent, proposal papers and values) and the fallback `#ifndef TOKEN / #define TOKEN 0`. Doxygen is configured to scan `*.inc`.

Token values are the SD-6 date value (e.g. `201707L`) when the feature is available and `0` otherwise. A few meta-tokens aggregate related tokens, e.g. `LBAL_CPP20_ATTRIBUTES_LIKELY_AND_UNLIKELY`.

**Adding or updating a feature token** usually touches several places:
- the SD-6 mapping in `lbalCompilerSetup.hpp` or `lbalLibrarySetup.hpp`
- any per-compiler or per-library overrides
- the external-definition guard in `lbalDefinitionTests.hpp`
- the docs and `0`-default in the matching `overview-*.inc`
- a `LBAL_DIAGNOSTIC_TEST(...)` line in `tests/lbalFeatureTest.cpp`

Other headers:
- `lbalConfig.hpp`: user config knobs (`LBAL_CONFIG_*`).
- `details/lbalKnownVersions.hpp`: `LBAL_CPPnn_VERSION` constants.
- `details/lbalVersionSetup.hpp`: sets `LBAL_cpp_version` and pulls in `<version>`.
- `details/lbalGenerated.hpp`: **generated** by CMake from `tools/cmake/lbalGenerated.hpp.in`. Don't edit it by hand. The project version is set in the root `CMakeLists.txt`.

## Tests

`tests/lbalFeatureTest.cpp` compiles every token and logs any that are unsupported; it is mostly a compile-time validity check. `tests/lbalFormattingTest.*` exercises the formatting and decorator macros. `tests/reference/` is excluded from `format` and must be maintained by hand.

## Conventions

- Source comment tags: `FIXME`, `APIME`, `OPTME`, `VERME`, `SEEME` (defined in `lucenaBAL.hpp`).
- Style comes from `.clang-format`. Long `#if` conditions are wrapped with aligned trailing `\`.
- Only WG21 proposals with SD-6 tokens are generally tracked. Proprietary tokens are added only where an official one is missing, and are deprecated once SD-6 assigns one.
- License: University of Illinois/NCSA. Keep the existing file header blocks.
