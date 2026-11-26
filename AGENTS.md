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
ctest --test-dir build -R '^cxx'                     # false-positive and false-negative tests (see Tests)
cmake --build build --target lbalFalsePositiveProbes -- -k   # false-positive compile-only probes, keep going (-k 0 with Ninja)
cmake --build build --target format                  # clang-format every *.{hpp,inc} under include/ and *.{cpp,hpp,inc} under tests/
cmake --build build --target format-dry              # show the clang-format diff without applying it
cmake --build build --target install                 # install headers + CMake config
```

Don't configure two build directories at the same time: configure writes `include/lucenaBAL/details/lbalGenerated.hpp` into the source tree, so concurrent configures race on it.

With a multi-config generator (Visual Studio, Xcode, Ninja Multi-Config), pass the configuration to both steps, e.g. `cmake --build build --config Release` and `ctest --test-dir build -C Release`. Without `-C`, `ctest` reports `lbalTokenCoverage` as "not available without configuration" and `gtest_discover_tests` registers no tests at all. CI passes `-C` on every platform.

Configure options: `LBAL_BUILD_DOCS`, `LBAL_BUILD_FALSE_POSITIVE_TESTS` (off by default; see Tests), `LBAL_FALSE_POSITIVE_TEST_STANDARDS` (default `latest`), `LBAL_BUILD_FALSE_NEGATIVE_TESTS` (off by default), `LBAL_FALSE_NEGATIVE_TEST_STANDARDS` (default `latest`), `LBAL_BUILD_ALL_FEATURE_TESTS` (builds both kinds), `LBAL_CONFIG_DISABLE_PEDANTIC_WARNINGS`, `LBAL_CONFIG_TREAT_UNCERTAINTY_AS_FAILURE`. The library interface requires `cxx_std_26` (MSVC gets `/std:c++latest`). The build sets `LBAL_TARGET_OS_*` from `CMAKE_SYSTEM_NAME`. Non-CMake consumers must define one themselves, or `lbalDefinitionTests.hpp` will `#error`.

CI (`.github/workflows/main.yml`) runs configure/build/ctest on macOS (AppleClang from Xcode, using CMake's default Makefiles generator), Ubuntu/gcc-15 and Windows/MSVC (Visual Studio generator). It always enables the false-positive and false-negative tests at `latest`, and builds the compile-only false-positive probes in a separate `False-Positive Probes` step; see Tests. Failing tests' output is printed inline (`CTEST_OUTPUT_ON_FAILURE` is set for the whole job), printed again together in the `Failed Test Output` step, and uploaded as a `test-log-<runner>` artifact. `doxygen.yml` publishes the docs.

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

   The libstdc++ headers gate their fixups on `LBAL_GCC_VERSION`, which comes from the library's own `_GLIBCXX_RELEASE` (major version only, treated as x.1) and falls back to `__GNUC__` for libraries older than GCC 7. Don't use `__GNUC__` directly there: Clang reports 4.2.1.

   Where a library feature depends on macros the compiler predefines, those macros decide, not the library version. For example, libc++ and libstdc++ only provide `std::hardware_{de,con}structive_interference_size` when the compiler predefines `__GCC_DESTRUCTIVE_SIZE` and `__GCC_CONSTRUCTIVE_SIZE` (GCC 12+, Clang 19+). The libc++ and Apple libc++ PostInitialization headers check those macros for `LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE`.

   On Apple platforms, features that live in the OS's libc++ dylib depend on the deployment target (the minimum OS), never the SDK version. Use libc++'s own `_LIBCPP_AVAILABILITY_HAS_*` macros where the headers have them (`<version>` pulls them in from LLVM 19), and otherwise the `*_MIN_REQUIRED` macros from `<Availability.h>`, as `lbalPlatformApple.hpp` does. For example, `LBAL_LIBCPP17_TO_CHARS_FP` is set when `to_chars` and `from_chars` both work for `float` and `double`. `LBAL_LIBCPP17_TO_CHARS`, the full feature, also needs `long double`, so it stays `0` on libc++, which has no `long double` `from_chars`.

   Token policy: a feature counts as available in a mode if it compiles there without an error or a default-on warning, even under `-pedantic-errors`. So retroactive fixes (DRs) and silently accepted extensions are reported in older modes too (e.g. `LBAL_CPP20_CONSTEXPR_IN_DECLTYPE` on GCC 9+, `LBAL_CPP20_VA_OPT` on Clang 12+). `LBAL_CPP11_MINIMAL_GARBAGE_COLLECTION` means real garbage collection (strict pointer safety), which no implementation offers, so it is always `0`.

   Fixup patterns in the Initialization and PostInitialization headers:
   - **Unreported features.** An implementation may ship a feature without reporting it. Either there is no SD-6 macro (e.g. MSVC and `LBAL_CPP20_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS`), or the implementation holds a shared macro low because another paper with the same value is unfinished (MSVC's `__cpp_constexpr`; libc++'s `__cpp_lib_format`, for `LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING`). PostInitialization then sets the token, version-gated, with a SEEME citing the source: the implementer's status or conformance page first, cppreference's compiler-support tables otherwise.
   - **Partial implementations.** The full token stays `0`, and a narrower proxy token reports the part that exists, e.g. `LBAL_LIBCPP20_CHRONO_CALENDAR_TYPES`, `LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY_TRAITS`, `LBAL_LIBCPP17_TO_CHARS_FP`/`_INTEGER`, `LBAL_LIBCPP23_FORMATTERS_THREAD_ID`. Proxy tokens come from the generator. One with no generated SD-6 mapping (e.g. `FORMATTERS_THREAD_ID`) must be set in every library's PostInitialization header.
   - **Known false positives.** Zero the token below an upper version bound marked VERME, so newer toolsets are tested again automatically, e.g. MSVC's `LBAL_CPP23_RANGE_BASED_FOR_TEMPORARIES` while `_MSC_VER < 1960`.
   - **Facilities a later Standard removes.** Zero the token from that Standard on, unless the library's opt-in is set, e.g. `LBAL_LIBCPP14_RESULT_OF_SFINAE` with `_LIBCPP_ENABLE_CXX20_REMOVED_TYPE_TRAITS` or `_HAS_DEPRECATED_RESULT_OF`.
   - **Versions.** MSVC fixups gate on `_MSC_VER`; map product versions carefully (VS 2019 16.5 = 1925, VS 2022 17.1 = 1931, 17.14 = 1944, Build Tools 14.50 = 1950, VS 2026 = 1950+). AppleClang fixups gate on `__clang_major__`, which is Apple's own numbering, not LLVM's; map each Clang fixup to the matching AppleClang release.
4. **`details/lbalPlatformSetup.hpp`**: includes `platforms/lbalPlatform{Apple,POSIX,WinAPI}.hpp`.
5. **`lbalFeatureSetup.hpp`**: the documented public surface. It holds the Doxygen group docs and the non-feature tokens: build environment, platform, compiler control (`LBAL_DIAGNOSTIC_*`), builtins and decorators (`LBAL_VIS_*`, `LBAL_CLASS_*`, `LBAL_NO_UNIQUE_ADDRESS` etc.). Compiler Initialization headers define a decorator's compiler-specific form, and `lbalFeatureSetup.hpp` documents it and supplies the fallback; `LBAL_NO_UNIQUE_ADDRESS` uses `[[msvc::no_unique_address]]` for the MSVC ABI (MSVC and clang-cl), which ignores the standard spelling. It also includes one `details/fragments/lbalFeatureSetup-overview-{cpp,libcpp}NN.inc` per Standard. Each `overview-*.inc` is self-contained for Doxygen. It has:
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
- a false-positive probe, which should fail when the feature is missing so the false-negative tests can use it (otherwise tag it `LBAL_FP_SMOKE`): an `LBAL_FP_TEST` in `tests/fragments/lbalFalsePositiveTest-{cpp,libcpp}NN.inc` and/or a file in `tests/probes/{cpp,libcpp}NN/`. See Tests.

The `lbalTokenCoverage` test fails if a token declared in an `overview-*.inc` is missing its `LBAL_DIAGNOSTIC_TEST` line, its false-positive probe or, for a language token, its external-definition guard. It also fails if a header uses a `LBAL_(LIB)CPPnn_*` name that no overview declares (see Tests). It doesn't check SD-6 mappings, because some tokens legitimately have none.

Fragments under `include/` are included as `<lucenaBAL/details/fragments/…>`, the same way as other headers. Never use `<include/lucenaBAL/…>`: it only resolves when the repository root is on the include path, so the CMake build and installed copies fail.

Other headers:
- `lbalConfig.hpp`: user config knobs (`LBAL_CONFIG_*`).
- `details/lbalKnownVersions.hpp`: `LBAL_CPPnn_VERSION` constants.
- `details/lbalVersionSetup.hpp`: sets `LBAL_cpp_version` and pulls in `<version>`.
- `details/lbalGenerated.hpp`: **generated** by CMake from `tools/cmake/lbalGenerated.hpp.in`. Don't edit it by hand. The project version is set in the root `CMakeLists.txt`.

## Tests

`tests/lbalFeatureTest.cpp` compiles every token and logs any that are unsupported; it is mostly a compile-time validity check. The per-Standard `LBAL_DIAGNOSTIC_TEST(...)` lines live in `tests/fragments/lbalFeatureTest-{cpp,libcpp}NN.inc`, included as `"fragments/…"`. They're kept out of `include/` so they aren't installed or scanned by Doxygen. `tests/lbalFormattingTest.*` exercises the formatting and decorator macros. `tests/lbalTokenCoverage.cmake` is a CMake `-P` script registered as the `lbalTokenCoverage` CTest. Run it on its own with `ctest --test-dir build -R lbalTokenCoverage`. It checks that:
- every overview token has its `LBAL_DIAGNOSTIC_TEST` line and, for `cpp*` tokens, its guard in `lbalDefinitionTests-<std>.inc`
- every overview token has a false-positive probe (`tests/probes/<std>/<NAME>.cpp`, or `LBAL_FP_TEST(<STD>, <NAME>)` written exactly that way, since the false-negative tests search for that text), unless it's in the script's `LBAL_COVERAGE_NO_PROBE` list
- every probe names a declared token of its own Standard and guards its body with `#if TOKEN`
- a probe is tagged `LBAL_FP_SMOKE` exactly when its token is in the script's `LBAL_COVERAGE_SMOKE` list, so tagging or tightening a smoke probe means updating that list
- every `LBAL_(LIB)CPPnn_*` name in `include/lucenaBAL` and `tests/lbalFalseNegativeKnown.hpp` is declared in an overview (the `LBAL_CPPnn_VERSION` constants aside), so a misspelled or retired token in a fixup fails
- `tests/lbalFalsePositiveTest.cpp` includes exactly one `fragments/lbalFalsePositiveTest-<std>.inc` per overview Standard (the false-negative tests find their Standards from the overviews themselves)

### False-positive tests (optional)

`-DLBAL_BUILD_FALSE_POSITIVE_TESTS=ON` builds tests that check whether a nonzero token is telling the truth. `LBAL_FALSE_POSITIVE_TEST_STANDARDS` gives the `-std` modes as Standard numbers (minimum 17, for GoogleTest) and/or `latest`, e.g. `"17;20;latest"`; each mode gets its own targets. `latest`, the default, resolves to the newest `cxx_std_NN` in `CMAKE_CXX_COMPILE_FEATURES` (candidates are listed in `tests/CMakeLists.txt`; add new Standards there). Duplicates are dropped. The targets don't link `lucenaBAL`, whose interface forces C++26; they copy its include directories and definitions instead. A test runtime can't observe compile errors, so the probes come in two kinds:

- **Soft probes** (`tests/lbalFalsePositiveTest.cpp`, which includes `tests/fragments/lbalFalsePositiveTest-{cpp,libcpp}NN.inc`) are built into `lbalFalsePositiveTest-cxxNN`. CTest registers them as `cxxNN.lbalFalsePositive.<TOKEN without LBAL_>`. Each uses `LBAL_FP_TEST`/`LBAL_FP_REQUIRE` from `tests/lbalFalsePositiveTest.hpp`. It is SKIPPED when the token is 0 and FAILED on a false positive, and its body is wrapped in `#if TOKEN`. Use them for runtime behavior and values, and for library members and overloads through `LBAL_FP_DETECT`, a detection idiom that yields `false` rather than an error. Anything that can only fail as a compile error would break the whole executable, so it doesn't belong here. That includes facilities a later Standard removes outright, such as `std::result_of` (gone from libc++ and the MSVC STL in C++20): a missing name is a hard error even inside `LBAL_FP_DETECT`, so probe those with a compile-only probe.
- **Hard probes** (`tests/probes/{cpp,libcpp}NN/<TOKEN_SUFFIX>.cpp`, one token per file, body in `#if TOKEN`) are syntax and `constexpr` checks. They're compiled into the object library `lbalFalsePositiveProbes-cxxNN`, which is never linked and is excluded from the default build; the aggregate target `lbalFalsePositiveProbes` builds every mode's. They're compiled with `-pedantic-errors` plus errors for ignored or unknown attributes (`/we5030` on MSVC), so features that are only extensions in that mode count as false positives. With GCC and Clang they're also compiled with `-Werror` (deprecation warnings excepted; `LBAL_PROBE_WERROR_OPTIONS`): a feature the compiler warns about by default doesn't count as available. GCC, for example, accepts `1uz` in C++17 with a warning no narrower option can make an error. MSVC doesn't get `/WX`, so a feature MSVC only warns about still counts there. A failing probe therefore can't stop the gtest executables building. Use a keep-going build to see every failure at once: `cmake --build build --target lbalFalsePositiveProbes -- -k 0` (Ninja) or `-- -k` (Make). Xcode and MSBuild continue by default.

Run the soft probes with `ctest --test-dir build -R '^cxx'`.

CI always enables these tests on every platform at `latest`: the soft probes run in the Test step, and the `False-Positive Probes` step builds `lbalFalsePositiveProbes` with keep-going. A false positive of either kind fails the job. To also test older Standards in CI, set the GitHub repository variable `LBAL_FALSE_POSITIVE_TEST_STANDARDS` (e.g. `17;20;23;latest`), which is passed straight to CMake. Every language, attribute and library token has a probe, except `LBAL_CPP20_MODULES` and `LBAL_LIBCPP23_MODULES`, which need a module-aware build; `lbalTokenCoverage` enforces this. Library tokens follow the libcpp17 pattern: gtest probes first, and compile-only probes only for `constexpr`/`consteval`-only tokens and for facilities a later Standard removes. Probes marked SEEME were written from the paper and haven't yet been run against an implementation that reports the feature; a failure there may be a mistake in the probe. The `HARDENED_*` library probes are gtest death tests, using `LBAL_FP_EXPECT_HARDENED` in `lbalFalsePositiveTest-libcpp26.inc`. libstdc++ keeps `<stacktrace>` and some other facilities in `libstdc++exp`, so `tests/CMakeLists.txt` links `stdc++exp` into the gtest targets when it's available.

### False-negative tests (optional)

`-DLBAL_BUILD_FALSE_NEGATIVE_TESTS=ON` (or `LBAL_BUILD_ALL_FEATURE_TESTS`) builds tests that check whether a token that is `0` is telling the truth, for every token in every Standard with an overview fragment, `cpp2d` and `libcpp2d` included; `tests/lbalFalseNegative.cmake` finds the Standards by globbing the overviews. `LBAL_FALSE_NEGATIVE_TEST_STANDARDS` works like the false-positive list. There are no separate snippets: the tests reuse the false-positive probes.

- **Configure time** (`tests/lbalFalseNegative.cmake`, included from `tests/CMakeLists.txt`): for each mode, one `try_compile` builds a static library that embeds every token's value as a string, read back with `file(STRINGS)`; no `try_run`, so it works when cross-compiling. Then each zero-valued token's probe is compiled with `#undef`/`#define TOKEN 1` ahead of the probe file or its whole fragment, with the strict probe options (`LBAL_PROBE_STRICT_OPTIONS`, plus `LBAL_PROBE_WERROR_OPTIONS` for compile-only probes), so features that are only extensions don't count. Each fragment is first compiled with nothing forced; one that fails is reported with a warning, left out of that mode's test executable, and its gtest-probe tokens are skipped, so one broken fragment can't stop the executable building. Results are cached by content: the toolchain, options, lucenaBAL headers and `lbalFalsePositiveTest.hpp`, plus the token's probe file or fragment. Editing a fragment retries all of that fragment's tokens. Results go into the generated `lbalFalseNegative-cxxNN/lbalFalseNegative.hpp` (X-macro lists), `lbalFalseNegativeForce.hpp` and `lbalFalseNegativeFragments.hpp` (the fragments that compile in that mode).
- **Test executable** `lbalFalseNegativeTest-cxxNN` (`tests/lbalFalseNegativeTest.cpp`, built with the strict options): it records the real token values, forces on the tokens whose gtest probes compiled, redefines `LBAL_FP_TEST` to declare a plain function and `LBAL_FP_REQUIRE` as a no-op, and includes the fragments that compile in that mode, unchanged. Each token's test, `cxxNN.lbalFalseNegative.<TOKEN without LBAL_>`, is:
  - SKIPPED if the token is nonzero, if it's a known absence (below), if its probe is marked `LBAL_FP_SMOKE`, if it has no probe, or if its fragment doesn't compile in that mode
  - PASSED if its probe doesn't compile
  - FAILED if a compile-only probe compiles
  - for a gtest probe that compiles: run under `testing::ScopedFakeTestPartResultReporter`; FAILED if it passes, PASSED otherwise
- **Known absences** (`tests/lbalFalseNegativeKnown.hpp`): a token can be `0` on purpose although its probe compiles, because the implementer documents the feature as incomplete and the probe can't reach the missing part (e.g. Clang's partial P1907R1 for `LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FIXES`). `known_absent()` gives the reason, conditioned on the compiler or library, and the test is SKIPPED with it. Add an entry only when the gap is documented; otherwise tighten the probe or fix the token.
- **`LBAL_FP_SMOKE`** is a comment tag, in a gtest probe's body or a compile-only probe's header comment, for a probe that would also pass without its feature, so it can't detect a false negative. Prefer tightening a probe until it fails without its feature, which helps the false-positive tests too; mark it only when that isn't practical, and add the token to `LBAL_COVERAGE_SMOKE` in `tests/lbalTokenCoverage.cmake`.
- **Probes must fail without their feature.** A probe for a later revision must fail where the earlier revision is all there is. Lessons so far:
  - Check the effect, not just acceptance: MSVC accepts `[[no_unique_address]]` but ignores it, so that probe also checks `sizeof`.
  - Use rules that require a diagnostic. A rule the older Standard made "no diagnostic required" won't fail (see the P2448R2 probe, `CONSTEXPR_RELAX_RESTRICTIONS`).
  - Avoid compiler built-ins: GCC evaluates `fabs` and similar at compile time in every mode, so `LIBCPP23_CONSTEXPR_CMATH` also checks `std::div`.
  - Don't rely on undefined behavior or indeterminate values (e.g. construct over storage filled with a non-zero pattern; `RANGE_BASED_FOR_TEMPORARIES` iterates a namespace-scope array).
  - Compile-only probes are included under `-Werror`, so silence any warning the feature itself brings with a pragma, as `HARDWARE_INTERFERENCE_SIZE` does for `-Winterference-size`.
- **Cost:** roughly 0.5–1 s per try, only for zero-valued tokens that have a probe and aren't smoke. With every Standard in scope, a mode tries about 160–200 probes at C++26 (2–3 minutes) and about 400 at C++17 (5–6 minutes); configuring `17;20;23;latest` took 11–15 minutes per toolchain locally (GCC 15, Clang 23 with libstdc++ or libc++). `try_compile` is slower under MSBuild, so the Windows configure step takes longer. CI uses `latest`, plus the `LBAL_FALSE_NEGATIVE_TEST_STANDARDS` repository variable.
- **Cross-compiling:** detection works, but the test executables must still run; CMake warns when either suite is enabled while cross-compiling without `CMAKE_CROSSCOMPILING_EMULATOR`. It's up to the user to turn the suites off or provide an emulator.

### Expected local results

With GCC 15, Clang 23 with libstdc++ 15, and Clang 23 with libc++ 23 (`-stdlib=libc++`, with `CMAKE_C_COMPILER=clang` so the flag doesn't reach GCC) on Linux, both suites pass in every mode, and every compile-only probe builds. Clang with libstdc++ used to fail `LIBCPP20_CONSTEXPR_COMPLEX` and `LIBCPP26_FORMAT_TYPE_CHECK`; those tokens are now `0` there (see the VERME fixups in `lbalStandardLibraryLibStdCppPostInitialization.hpp`).

These results aren't local, but they're the reference for the other toolchains:
- **Xcode 27.2 (Apple Clang 21 with Apple libc++):** the maintainer reports no failures, warnings or notes from lucenaBAL.
- **CI at `latest`:** GCC 15.2 on Ubuntu 26.04 passes. Xcode 26.4 (Apple libc++ 21) and MSVS 2026 (C++23 for `latest`) are expected to pass once CI reruns with the fixes listed in `HANDOFF.md`.

## Checking platforms you don't have

MSVC, libc++ and Apple aren't usually available locally. These techniques check the preprocessor logic only; say so when reporting, and leave confirmation to CI.
- **MSVC:** preprocess with GCC or Clang using `-U__clang__ -U__llvm__ -U__GNUC__ -D_MSC_VER=… -D_MSC_FULL_VER=… -D_WIN32=1 -D_MSVC_LANG=<value> -DLBAL_TARGET_OS_WINAPI=1`. Set the mode through `_MSVC_LANG`; `LBAL_cpp_version` can't be defined externally (`lbalConfig.hpp` `#error`s).
- **clang-cl / the MSVC ABI:** `clang++ --target=x86_64-pc-windows-msvc -fsyntax-only`.
- **libc++ and Apple libc++:** put stub headers (`<version>`, `<Availability.h>`, and whichever others the logic reads) defining the version and `_LIBCPP_AVAILABILITY_HAS_*` macros ahead on the include path. Follow up with a mutation check: flip the gating condition and confirm the result changes.
- **Older libstdc++:** a wrapper `<version>` that `#include_next`s the real one, then redefines `_GLIBCXX_RELEASE`.

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

- Never make a git commit on your own, even when a task seems finished: leave every change uncommitted in the working tree for the maintainer to review.
- Source comment tags: `FIXME`, `APIME`, `OPTME`, `VERME`, `SEEME` (defined in `lucenaBAL.hpp`).
- Sources are UTF-8, and the license headers and comments use non-ASCII punctuation. MSVC reads files without a BOM in the system code page unless it's given `/utf-8`, so every MSVC test target passes `/utf-8` (see `tests/CMakeLists.txt`). Put non-ASCII characters in string or character literals only where the encoding itself is under test; elsewhere use `\u` escapes.
- Style comes from `.clang-format`. Long `#if` conditions are wrapped with aligned trailing `\`.
- Only WG21 proposals with SD-6 tokens are generally tracked. Proprietary tokens are added only where an official one is missing, and are deprecated once SD-6 assigns one.
- License: University of Illinois/NCSA. Keep the existing file header blocks.
