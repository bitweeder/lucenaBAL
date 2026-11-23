# AGENTS.md

This file provides guidance to coding agents when working with code in this repository.

## What this is

lucenaBAL is a **header-only, preprocessor-only** C++ library (C++11+) that normalizes feature detection across compilers (AppleClang, Clang, GCC, MSVC), Standard Libraries (libc++, Apple libc++, libstdc++, MSVC STL), and platforms (Apple, POSIX/X11, WinAPI). It exposes `LBAL_*` macros, mostly modeled on SD-6 tokens with a Standard tag added (e.g. `__cpp_lib_optional` → `LBAL_LIBCPP17_OPTIONAL`, `__cpp_concepts` → `LBAL_CPP20_CONCEPTS`). Tokens are tracked up through C++26, plus accepted C++29 proposals under `CPP2D`/`LIBCPP2D` names. Consumers include `<lucenaBAL/lucenaBAL.hpp>`.

Known gap (README): compiler/library-specific fixups for C++23/26 aren't integrated yet. Those tokens rely on self-reporting via `<version>` and predefined macros, so false negatives and positives are expected. The optional false-positive tests (see Tests) exist to find them.

## Generated files

The maintainer generates some files with an external tool that isn't in this repository:
- every `include/lucenaBAL/details/fragments/*.inc`
- `tests/fragments/lbalFeatureTest-*.inc`

Don't hand-edit these as a lasting fix. Describe the change needed so it can be made in the generator; if a hand edit is unavoidable, say that it must also go upstream, or the next regeneration will undo it. Regenerated files may not be clang-format clean. Everything else is hand-written, including `tests/fragments/lbalFalsePositiveTest-*.inc` and `tests/probes/`.

## Commands

CMake ≥ 3.30. In-source builds are rejected; always use a separate `build/` dir.

```sh
cmake -DCMAKE_BUILD_TYPE=Release -S . -B build      # configure (add -DLBAL_BUILD_DOCS=ON for Doxygen docs)
cmake --build build                                  # builds tests/lbalTest (fetches GoogleTest v1.17.0)
ctest --test-dir build                               # or: cmake --build build --target test
ctest --test-dir build -R <regex>                    # single test (gtest_discover_tests names, e.g. lbalTest.Validation)
./build/tests/lbalTest --gtest_filter='lbalTest.*'   # run the gtest binary directly
cmake --build build --target Doxygen                 # docs, with -DLBAL_BUILD_DOCS=ON (output: build/docs/doxygen/html)
ctest --test-dir build -R '^cxx'                     # false-positive gtest probes (-DLBAL_BUILD_FALSE_POSITIVE_TESTS=ON)
cmake --build build --target lbalFalsePositiveProbes -- -k   # false-positive compile-only probes, keep going (-k 0 with Ninja)
cmake --build build --target format                  # clang-format every *.{hpp,inc} under include/ and *.{cpp,hpp,inc} under tests/
cmake --build build --target format-dry              # show the clang-format diff without applying it
cmake --build build --target install                 # install headers + CMake config
```

With a multi-config generator (Visual Studio, Xcode, Ninja Multi-Config), pass the configuration to both steps, e.g. `cmake --build build --config Release` and `ctest --test-dir build -C Release`. Without `-C`, `ctest` reports `lbalTokenCoverage` as "not available without configuration" and `gtest_discover_tests` registers no tests at all. CI passes `-C` on every platform.

Configure options: `LBAL_BUILD_DOCS`, `LBAL_BUILD_FALSE_POSITIVE_TESTS` (off by default; see Tests), `LBAL_FALSE_POSITIVE_TEST_STANDARDS` (default `latest`), `LBAL_CONFIG_DISABLE_PEDANTIC_WARNINGS`, `LBAL_CONFIG_TREAT_UNCERTAINTY_AS_FAILURE`. The library interface requires `cxx_std_26` (MSVC gets `/std:c++latest`). The build sets `LBAL_TARGET_OS_*` from `CMAKE_SYSTEM_NAME`. Non-CMake consumers must define one themselves, or `lbalDefinitionTests.hpp` will `#error`.

CI (`.github/workflows/main.yml`) runs configure/build/ctest on macOS (AppleClang from Xcode, using CMake's default Makefiles generator), Ubuntu/gcc-15 and Windows/MSVC (Visual Studio generator). It always enables the false-positive tests at `latest` and builds the compile-only probes in a separate `False-Positive Probes` step; see Tests. Failing tests' output is printed inline (`CTEST_OUTPUT_ON_FAILURE` is set for the whole job), printed again together in the `Failed Test Output` step, and uploaded as a `test-log-<runner>` artifact. `doxygen.yml` publishes the docs.

## Architecture: how a feature token is resolved

The include chain is `lucenaBAL.hpp` → `lbalConfig.hpp` + `lbalFeatureSetup.hpp`. Feature resolution is layered, and **every layer guards with `#if !defined(TOKEN)`, so the first definition wins**:

1. **`details/lbalDefinitionTests.hpp`**: `#error`s if any `LBAL_*` token was defined externally. The exceptions are `LBAL_TARGET_OS_*` and `LBAL_TARGET_API_*`, which the build system supplies. Every new token must be added to this list. The per-Standard checks live in `details/fragments/`: `lbalDefinitionTests-cppNN.inc` for `LBAL_CPPNN_*` and `lbalDefinitionTests-headers-cppNN.inc` for `LBAL_HAS_HEADER_*`. Tokens that aren't tied to a Standard (`LBAL_TARGET_*`, `LBAL_CPPTS_*`, `LBAL_DIAGNOSTIC_*` etc.) stay in the `.hpp`. `LBAL_LIBCPP*` tokens are deliberately not checked, because platform and compiler code may set them.
2. **`details/lbalCompilerSetup.hpp`**: does detection (`lbalDetectCompiler.hpp`), then includes `compilers/lbal<Compiler>Initialization.hpp`. It maps SD-6 language macros, and `__has_cpp_attribute` results, to `LBAL_CPPxx_*` through one fragment per Standard, `details/fragments/lbalCompilerSetup-definitions-cppNN.inc`. Each fragment holds that Standard's features followed by its attributes. It then includes `compilers/lbal<Compiler>PostInitialization.hpp`. Version-gated per-compiler overrides and fixups live in the Initialization and PostInitialization files, e.g. `LBAL_GCC_VERSION >= 40900`.

   Clang accepts many later-Standard features as extensions and predefines their SD-6 macros and `__has_cpp_attribute` values in every mode. The Clang and AppleClang PostInitialization headers therefore `#undef` those tokens and define them as `0` when both of these hold:
   - Extensions are errors. Under `-pedantic-errors`, `__has_extension` matches `__has_feature`, so this is detected with `!__has_extension(c_static_assert)`. Narrower flags such as `-Werror=c++26-extensions` can't be seen by the preprocessor.
   - The mode is older than the token's Standard. This is written as `LBAL_cpp_version <= LBAL_CPP<previous>_VERSION`, never `< LBAL_CPP<own>_VERSION`, because preview modes report a lower `__cplusplus`: Clang 23's `-std=c++26` gives `202400L`, below `LBAL_CPP26_VERSION` (`202603L`).
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

**Adding or updating a feature token** usually touches several places. Most are generated files (see Generated files), so the change usually belongs in the generator:
- the SD-6 mapping in `fragments/lbalCompilerSetup-definitions-cppNN.inc`, or for library tokens in `fragments/lbalLibrarySetup-definitions-libcppNN.inc`
- for library tokens that need specific headers, a check in `fragments/lbalLibrarySetup-header-tests-libcppNN.inc` (plus a `LBAL_HAS_HEADER_*` in `fragments/lbalLibrarySetup-headers-cppNN.inc` if the header is new)
- any per-compiler or per-library overrides
- the external-definition guard in `fragments/lbalDefinitionTests-cppNN.inc` for language tokens, and in `fragments/lbalDefinitionTests-headers-cppNN.inc` for any new `LBAL_HAS_HEADER_*`
- the docs (a `@def` inside the file's `@name` group) and `0`-default in the matching `fragments/lbalFeatureSetup-overview-*.inc`
- a `LBAL_DIAGNOSTIC_TEST(...)` line in `tests/fragments/lbalFeatureTest-{cpp,libcpp}NN.inc`
- a false-positive probe (expected for language and attribute tokens, optional for library tokens until those fragments are filled in): an `LBAL_FP_TEST` in `tests/fragments/lbalFalsePositiveTest-{cpp,libcpp}NN.inc` and/or a file in `tests/probes/{cpp,libcpp}NN/`. See Tests.

The `lbalTokenCoverage` test fails if a token declared in an `overview-*.inc` is missing its `LBAL_DIAGNOSTIC_TEST` line or, for a language token, its external-definition guard. It doesn't check SD-6 mappings, because some tokens legitimately have none.

Fragments under `include/` are included as `<lucenaBAL/details/fragments/…>`, the same way as other headers. Never use `<include/lucenaBAL/…>`: it only resolves when the repository root is on the include path, so the CMake build and installed copies fail.

Other headers:
- `lbalConfig.hpp`: user config knobs (`LBAL_CONFIG_*`).
- `details/lbalKnownVersions.hpp`: `LBAL_CPPnn_VERSION` constants.
- `details/lbalVersionSetup.hpp`: sets `LBAL_cpp_version` and pulls in `<version>`.
- `details/lbalGenerated.hpp`: **generated** by CMake from `tools/cmake/lbalGenerated.hpp.in`. Don't edit it by hand. The project version is set in the root `CMakeLists.txt`.

## Tests

`tests/lbalFeatureTest.cpp` compiles every token and logs any that are unsupported; it is mostly a compile-time validity check. The per-Standard `LBAL_DIAGNOSTIC_TEST(...)` lines live in `tests/fragments/lbalFeatureTest-{cpp,libcpp}NN.inc`, included as `"fragments/…"`. They're kept out of `include/` so they aren't installed or scanned by Doxygen. `tests/lbalFormattingTest.*` exercises the formatting and decorator macros. `tests/lbalTokenCoverage.cmake` is a CMake `-P` script registered as the `lbalTokenCoverage` CTest. It checks that every overview token has its test line and, for `cpp*` tokens, its guard in `lbalDefinitionTests-<std>.inc`. Run it on its own with `ctest --test-dir build -R lbalTokenCoverage`.

### False-positive tests (optional)

`-DLBAL_BUILD_FALSE_POSITIVE_TESTS=ON` builds tests that check whether a nonzero token is telling the truth. `LBAL_FALSE_POSITIVE_TEST_STANDARDS` gives the `-std` modes as Standard numbers (minimum 17, for GoogleTest) and/or `latest`, e.g. `"17;20;latest"`; each mode gets its own targets. `latest`, the default, resolves to the newest `cxx_std_NN` in `CMAKE_CXX_COMPILE_FEATURES` (candidates are listed in `tests/CMakeLists.txt`; add new Standards there). Duplicates are dropped. The targets don't link `lucenaBAL`, whose interface forces C++26; they copy its include directories and definitions instead. A test runtime can't observe compile errors, so the probes come in two kinds:

- **Soft probes** (`tests/lbalFalsePositiveTest.cpp`, which includes `tests/fragments/lbalFalsePositiveTest-{cpp,libcpp}NN.inc`) are built into `lbalFalsePositiveTest-cxxNN`. CTest registers them as `cxxNN.lbalFalsePositive.<TOKEN without LBAL_>`. Each uses `LBAL_FP_TEST`/`LBAL_FP_REQUIRE` from `tests/lbalFalsePositiveTest.hpp`. It is SKIPPED when the token is 0 and FAILED on a false positive, and its body is wrapped in `#if TOKEN`. Use them for runtime behavior and values, and for library members and overloads through `LBAL_FP_DETECT`, a detection idiom that yields `false` rather than an error. Anything that can only fail as a compile error would break the whole executable, so it doesn't belong here. That includes facilities a later Standard removes outright, such as `std::result_of` (gone from libc++ and the MSVC STL in C++20): a missing name is a hard error even inside `LBAL_FP_DETECT`, so probe those with a compile-only probe.
- **Hard probes** (`tests/probes/{cpp,libcpp}NN/<TOKEN_SUFFIX>.cpp`, one token per file, body in `#if TOKEN`) are syntax and `constexpr` checks. They're compiled into the object library `lbalFalsePositiveProbes-cxxNN`, which is never linked and is excluded from the default build; the aggregate target `lbalFalsePositiveProbes` builds every mode's. They're compiled with `-pedantic-errors` plus errors for ignored or unknown attributes (`/we5030` on MSVC), so features that are only extensions in that mode count as false positives. A failing probe therefore can't stop the gtest executables building. Use a keep-going build to see every failure at once: `cmake --build build --target lbalFalsePositiveProbes -- -k 0` (Ninja) or `-- -k` (Make). Xcode and MSBuild continue by default.

Run the soft probes with `ctest --test-dir build -R '^cxx'`.

CI always enables these tests on every platform at `latest`: the soft probes run in the Test step, and the `False-Positive Probes` step builds `lbalFalsePositiveProbes` with keep-going. A false positive of either kind fails the job. To also test older Standards in CI, set the GitHub repository variable `LBAL_FALSE_POSITIVE_TEST_STANDARDS` (e.g. `17;20;23;latest`), which is passed straight to CMake. The library fragments are populated for libcpp14 and libcpp17 only; libcpp20 to libcpp2d are stubs. `LBAL_CPP20_MODULES` isn't probed, because it needs a module-aware build. Probes marked SEEME were written from the paper and haven't yet been compiled by a compiler that implements the feature.

## Docs (Doxygen)

- `docs/Doxyfile.in` scans `*.inc`. It needs `EXTENSION_MAPPING = inc=C++`, or Doxygen won't parse the `.inc` files as C++.
- `docs/CMakeLists.txt` globs `*.hpp` and `*.inc` under `${PROJECT_SOURCE_DIR}/include/lucenaBAL`. Don't derive the glob from the target's `INTERFACE_INCLUDE_DIRECTORIES`: that property holds generator expressions, which break the glob.
- Doxygen assigns groups per file and doesn't carry a group across `#include`. That's why each `overview-*.inc` has its own `@addtogroup` and `@name` wrappers. A new `overview-*.inc` must follow the same pattern. The docs glob is recursive, so it picks up `details/fragments/`. The root `CMakeLists.txt` lint glob uses `GLOB_RECURSE` with patterns such as `include/*.inc` and `tests/*.cpp`, which match every subdirectory too, so the `format` and `format-dry` targets cover `details/fragments/`, `tests/fragments/` and `tests/probes/`.
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
- Sources are UTF-8, and the license headers and comments use non-ASCII punctuation. MSVC reads files without a BOM in the system code page unless it's given `/utf-8`, so every MSVC test target passes `/utf-8` (see `tests/CMakeLists.txt`). Put non-ASCII characters in string or character literals only where the encoding itself is under test; elsewhere use `\u` escapes.
- Style comes from `.clang-format`. Long `#if` conditions are wrapped with aligned trailing `\`.
- Only WG21 proposals with SD-6 tokens are generally tracked. Proprietary tokens are added only where an official one is missing, and are deprecated once SD-6 assigns one.
- License: University of Illinois/NCSA. Keep the existing file header blocks.
