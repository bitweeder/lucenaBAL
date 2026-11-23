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
cmake --build build --target format                  # clang-format all include/**/*.{hpp,inc} and tests/**/*.{cpp,hpp,inc}
cmake --build build --target format-dry              # show the clang-format diff without applying it
cmake --build build --target install                 # install headers + CMake config
```

With a multi-config generator (Visual Studio, Xcode, Ninja Multi-Config), pass the configuration to both steps, e.g. `cmake --build build --config Release` and `ctest --test-dir build -C Release`. Without `-C`, `ctest` reports `lbalTokenCoverage` as "not available without configuration" and `gtest_discover_tests` registers no tests at all. CI passes `-C` on every platform.

Configure options: `LBAL_BUILD_DOCS`, `LBAL_CONFIG_DISABLE_PEDANTIC_WARNINGS`, `LBAL_CONFIG_TREAT_UNCERTAINTY_AS_FAILURE`. The library interface requires `cxx_std_26` (MSVC gets `/std:c++latest`). The build sets `LBAL_TARGET_OS_*` from `CMAKE_SYSTEM_NAME`. Non-CMake consumers must define one themselves, or `lbalDefinitionTests.hpp` will `#error`.

CI (`.github/workflows/main.yml`) runs configure/build/ctest on macOS/Xcode, Ubuntu/gcc-15 and Windows/MSVC. `doxygen.yml` publishes the docs.

## Architecture: how a feature token is resolved

The include chain is `lucenaBAL.hpp` → `lbalConfig.hpp` + `lbalFeatureSetup.hpp`. Feature resolution is layered, and **every layer guards with `#if !defined(TOKEN)`, so the first definition wins**:

1. **`details/lbalDefinitionTests.hpp`**: `#error`s if any `LBAL_*` token was defined externally. The exceptions are `LBAL_TARGET_OS_*` and `LBAL_TARGET_API_*`, which the build system supplies. Every new token must be added to this list. The per-Standard checks live in `details/fragments/`: `lbalDefinitionTests-cppNN.inc` for `LBAL_CPPNN_*` and `lbalDefinitionTests-headers-cppNN.inc` for `LBAL_HAS_HEADER_*`. Tokens that aren't tied to a Standard (`LBAL_TARGET_*`, `LBAL_CPPTS_*`, `LBAL_DIAGNOSTIC_*` etc.) stay in the `.hpp`. `LBAL_LIBCPP*` tokens are deliberately not checked, because platform and compiler code may set them.
2. **`details/lbalCompilerSetup.hpp`**: does detection (`lbalDetectCompiler.hpp`), then includes `compilers/lbal<Compiler>Initialization.hpp`. It maps SD-6 language macros, and `__has_cpp_attribute` results, to `LBAL_CPPxx_*` through one fragment per Standard, `details/fragments/lbalCompilerSetup-definitions-cppNN.inc`. Each fragment holds that Standard's features followed by its attributes. It then includes `compilers/lbal<Compiler>PostInitialization.hpp`. Version-gated per-compiler overrides and fixups live in the Initialization and PostInitialization files, e.g. `LBAL_GCC_VERSION >= 40900`.
3. **`details/lbalLibrarySetup.hpp`** (large): applies the same pattern to Standard Library tokens (`LBAL_LIBCPPxx_*`), using `lbalDetectStandardLibrary.hpp` and `libraries/lbalStandardLibrary<Impl>{,Post}Initialization.hpp`. Most of its content lives in per-Standard fragments in `details/fragments/`, included in this order:
   - `lbalLibrarySetup-definitions-libcppNN.inc`: maps SD-6 library macros to `LBAL_LIBCPPxx_*`. Included before the PostInitialization overrides.
   - `lbalLibrarySetup-headers-cppNN.inc`: sets `LBAL_HAS_HEADER_*` with `__has_include`.
   - `lbalLibrarySetup-header-tests-libcppNN.inc`: resets a token to `0`, with a warning, when a header it needs is missing.
4. **`details/lbalPlatformSetup.hpp`**: includes `platforms/lbalPlatform{Apple,POSIX,WinAPI}.hpp`.
5. **`lbalFeatureSetup.hpp`**: the documented public surface. It holds the Doxygen group docs and the non-feature tokens: build environment, platform, compiler control (`LBAL_DIAGNOSTIC_*`), builtins and decorators (`LBAL_VIS_*` etc.). It also includes one `details/fragments/lbalFeatureSetup-overview-{cpp,libcpp}NN.inc` per Standard. Each `overview-*.inc` is self-contained for Doxygen. It has:
   - the license header
   - an `@addtogroup lbal_compiler` wrapper, or `lbal_library` for `libcpp*`
   - its own `@name LBAL_CPPxx` / `LBAL_LIBCPPxx` member group, holding each token's `@def` docs (the SD-6 equivalent, proposal papers and values) and its fallback `#ifndef TOKEN / #define TOKEN 0`

   See "Docs (Doxygen)" below.

Token values are the SD-6 date value (e.g. `201707L`) when the feature is available and `0` otherwise. A few meta-tokens aggregate related tokens, e.g. `LBAL_CPP20_ATTRIBUTES_LIKELY_AND_UNLIKELY`.

**Adding or updating a feature token** usually touches several places:
- the SD-6 mapping in `fragments/lbalCompilerSetup-definitions-cppNN.inc`, or for library tokens in `fragments/lbalLibrarySetup-definitions-libcppNN.inc`
- for library tokens that need specific headers, a check in `fragments/lbalLibrarySetup-header-tests-libcppNN.inc` (plus a `LBAL_HAS_HEADER_*` in `fragments/lbalLibrarySetup-headers-cppNN.inc` if the header is new)
- any per-compiler or per-library overrides
- the external-definition guard in `fragments/lbalDefinitionTests-cppNN.inc` for language tokens, and in `fragments/lbalDefinitionTests-headers-cppNN.inc` for any new `LBAL_HAS_HEADER_*`
- the docs (a `@def` inside the file's `@name` group) and `0`-default in the matching `fragments/lbalFeatureSetup-overview-*.inc`
- a `LBAL_DIAGNOSTIC_TEST(...)` line in `tests/fragments/lbalFeatureTest-{cpp,libcpp}NN.inc`

The `lbalTokenCoverage` test fails if a token declared in an `overview-*.inc` is missing its `LBAL_DIAGNOSTIC_TEST` line or, for a language token, its external-definition guard. It doesn't check SD-6 mappings, because some tokens legitimately have none.

Fragments under `include/` are included as `<lucenaBAL/details/fragments/…>`, the same way as other headers. Never use `<include/lucenaBAL/…>`: it only resolves when the repository root is on the include path, so the CMake build and installed copies fail.

Other headers:
- `lbalConfig.hpp`: user config knobs (`LBAL_CONFIG_*`).
- `details/lbalKnownVersions.hpp`: `LBAL_CPPnn_VERSION` constants.
- `details/lbalVersionSetup.hpp`: sets `LBAL_cpp_version` and pulls in `<version>`.
- `details/lbalGenerated.hpp`: **generated** by CMake from `tools/cmake/lbalGenerated.hpp.in`. Don't edit it by hand. The project version is set in the root `CMakeLists.txt`.

## Tests

`tests/lbalFeatureTest.cpp` compiles every token and logs any that are unsupported; it is mostly a compile-time validity check. The per-Standard `LBAL_DIAGNOSTIC_TEST(...)` lines live in `tests/fragments/lbalFeatureTest-{cpp,libcpp}NN.inc`, included as `"fragments/…"`. They're kept out of `include/` so they aren't installed or scanned by Doxygen. `tests/lbalFormattingTest.*` exercises the formatting and decorator macros. `tests/lbalTokenCoverage.cmake` is a CMake `-P` script registered as the `lbalTokenCoverage` CTest. It checks that every overview token has its test line and, for `cpp*` tokens, its guard in `lbalDefinitionTests-<std>.inc`. Run it on its own with `ctest --test-dir build -R lbalTokenCoverage`.

## Docs (Doxygen)

- `docs/Doxyfile.in` scans `*.inc`. It needs `EXTENSION_MAPPING = inc=C++`, or Doxygen won't parse the `.inc` files as C++.
- `docs/CMakeLists.txt` globs `*.hpp` and `*.inc` under `${PROJECT_SOURCE_DIR}/include/lucenaBAL`. Don't derive the glob from the target's `INTERFACE_INCLUDE_DIRECTORIES`: that property holds generator expressions, which break the glob.
- Doxygen assigns groups per file and doesn't carry a group across `#include`. That's why each `overview-*.inc` has its own `@addtogroup` and `@name` wrappers. A new `overview-*.inc` must follow the same pattern. The docs glob is recursive, so it picks up `details/fragments/`. The root `CMakeLists.txt` lint glob includes `include/**/*.inc` and `tests/*.inc` (recursive), so the `format` and `format-dry` targets cover the fragments too.
- In `lbalFeatureSetup.hpp`, every `overview-*.inc` `#include` is wrapped in `///	@cond LBAL_INTERNAL` … `///	@endcond`, with a SEEME comment explaining why. Keep this wrapping.
  - Doxygen guesses include guards: it treats an `#ifndef X` / `#define X` pair with an empty body (or `1`) as a guard and drops that define.
  - Every `#include` Doxygen resolves restarts that guessing.
  - Without the wrapping, the next empty fallback after the last `.inc` (`LBAL_DIAGNOSTIC_PUSH`, then POP, then `LBAL_VIS_*` and so on) loses its docs, and Doxygen reports "documentation for unknown define".
  - Fallbacks with value `0` don't trigger the guess.
  - Giving individual macros a placeholder body only moves the problem to the next empty fallback.
  - `ENABLED_SECTIONS` is empty, so `@cond LBAL_INTERNAL` content (including the TS section) is hidden from the docs on purpose.
- To debug what Doxygen's preprocessor sees, run `doxygen -d preprocessor`.

## Conventions

- Source comment tags: `FIXME`, `APIME`, `OPTME`, `VERME`, `SEEME` (defined in `lucenaBAL.hpp`).
- Style comes from `.clang-format`. Long `#if` conditions are wrapped with aligned trailing `\`.
- Only WG21 proposals with SD-6 tokens are generally tracked. Proprietary tokens are added only where an official one is missing, and are deprecated once SD-6 assigns one.
- License: University of Illinois/NCSA. Keep the existing file header blocks.
