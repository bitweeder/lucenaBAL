[![Actions Status](https://github.com/bitweeder/lucenaBAL/workflows/Build%20Matrix/badge.svg)](https://github.com/bitweeder/lucenaBAL/actions)

# Lucena Build Abstraction Library

The purpose of the Lucena Build Abstraction Library (**lucenaBAL**) is to provide tools to smooth over the differences between build environments when working with C++11 and later Standards (currently up thru the entirety of C++26 and proposals adopted into C++2d). It’s a foundational header-only library that allows code built upon it to remain agnostic to compilers, C++ Standard Library variants, and aspects of the runtime. 

**lucenaBAL** is _not_ a build system; when deployed, it’s just a C++ header library which can be managed by CMake. This repo additionally includes a substantial number of buildable tests and associated scripts, but none of that is needed at build-time unless you’re modifying the library or validating against a particular build environment.

We don’t track every accepted proposal to the Standard—as represented by [WG21 papers](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/)—but rather mostly only those that have been assigned an [SD-6 token value](https://isocpp.org/std/standing-documents/sd-6-sg10-feature-test-recommendations) (i.e., features which will ultimately appear in the Standard under `tab:cpp.predefined.ft`, `tab:cpp.cond.ha`, or `version.syn`). There are some exceptions:
- Features that probably _should_ have official tokens.
- Meta-features that bundle related tokens together—typically Language+Library—when they are useless without each other; these will still have per-component tokens.
- Proxy tokens representing partial implmentation of a given feature when that implementation is useful on its own and the token would represent the shipping state of a major compiler or Standard library implementation.

In addition to the feature detection tokens, there are a number of decorator symbols and preprocessor functions defined which provide abstractions around common concepts that are useful, e.g., ABI control.

Note that token definitions only reflect the build environment as it exists at build-time, including as a result of specific arguments passed to the compiler, etc. In other words, they do not represent _what might be possible_, only _what is going to work right now_.

## Motivating Example

Imagine that you are working on a project that would benefit from using the C++17 parallelized algorithm for `std::sort`, and you would like to use it conditionally based on availability.
- Simply querying `__cplusplus` won’t tell you if the parallelized algorithms are available, as they are part of the Standard Library.
- Ignoring that will get you into trouble since 2 out of the 3 major Standard Library implementations did not include the parallelized algorithms for most of their post-C++17-release existence.
-  Checking for the presence of a header won’t work since the parallelized versions of the Standard Library algorithms are part of the existing `<algorithm>` header.
- Even though you _could_ check for the `<execution>` header, that will only tell you that Execution Policies are _probably_ available—it specifically won’t tell you about the availability of the algorithm implementations themselves.
- Checking the values of both `__cpp_lib_execution` and `__cpp_lib_parallel_algorithm` would probably work, but those are only guaranteed to be defined if the [SD-6 macros](https://isocpp.org/std/standing-documents/sd-6-sg10-feature-test-recommendations) are defined, and those weren’t formally integrated into the Standard until C++20 and the introduction of the `<version>` header.
- Of course, the `<version>` header might be available, anyway, as a vendor extension, but at least one major IDE vendor shipped such a header for multiple releases that didn’t actually include SD-6 macro definitions.

Enter **lucenaBAL**:
```cpp
#include <lucenaBAL/lucenaBAL.hpp>

#include <algorithm>
#include <vector>

#if LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS
    #include <execution>
#endif

/**
    Sort the supplied vector in place and return a reference to it,
    using a parallelized sort if available.
*/
inline std::vector<int> &
sort_vector (
    std::vector<int> & io_vector
) {
    #if LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS
        std::sort (std::execution::par, io_vector.begin(), io_vector.end());
    #else
        std::sort (io_vector.begin(), io_vector.end());
    #endif
    
    return io_vector;
}
```

## Getting Started

[CMake](https://cmake.org/) scripts are provided which will install the library itself, build and run test applications, and generate documentation. We require at least CMake 3.30 to use the scripts, so that will need to be [installed first](https://cmake.org/download/).

More detailed instructions are provided below, but for a quick start, simply clone the repository, open up a terminal window, change to the local repo directory, and execute the following:

```sh
mkdir -p build
cmake -DCMAKE_INSTALL_PREFIX=/path/to/install -DCMAKE_BUILD_TYPE=Release -S ./ -B build
cmake --build build
cmake --build build --target install
```

This will generate headers and test binaries in the build directory (docs too, if you add `-DLBAL_BUILD_DOCS=ON`; see below), then install to subdirectories in an optionally-specified directory (the default is `/usr/local` if `-DCMAKE_INSTALL_PREFIX` is not provided):
- headers will go into `include/`
- CMake configs will go into `share/`

Note that if installing to `/usr/local`, you may need to replace the last line with `cd build && sudo make install`; tests and docs will always remain in the `build` directory.

Since lucenaBAL is a header-only library, it is not necessary to link to it; simply `#include <lucenaBAL/lucenaBAL.hpp>` where you need feature tests once the headers are installed. Usage information is available in the [online docs](https://bitweeder.github.io/lucenaBAL/html/index.html), which are sourced from headers themselves (primarily in `<lucenaBAL/lbalFeatureSetup.hpp>` and its included fragments).

If you link against the installed CMake target (`lucenaBAL::lucenaBAL`), the target platform is set for you, based on the `CMAKE_SYSTEM_NAME` that was in effect when lucenaBAL was configured. If you use the headers some other way, you must define exactly one of the following to `1` yourself, or `lbalDefinitionTests.hpp` will stop the build with an `#error`:

| Platform | Token |
| :- | :- |
| macOS | `LBAL_TARGET_OS_MACOS` |
| iOS | `LBAL_TARGET_OS_IOS` |
| tvOS | `LBAL_TARGET_OS_TVOS` |
| watchOS | `LBAL_TARGET_OS_WATCHOS` |
| Windows | `LBAL_TARGET_OS_WINAPI` |
| Linux, FreeBSD, NetBSD, OpenBSD | `LBAL_TARGET_OS_X11`* |

* Note that `LBAL_TARGET_OS_X11` doesn’t imply an X Windows requirement; it’s named that way for historical reasons.

## Prerequisites

The lucenaBAL headers require compiler support for C++11 or later. By default, the CMake target assumes C++26 (`cxx_std_26`, or `/std:c++latest` under MSVC); building the tests requires a minimum of C++17. The library has been tested with many versions of **gcc**, **Microsoft Visual Studio**, **Xcode**, and **llvm/clang**, both with the compilers’ bundled Standard Library implementations, as well as with others. Support for pre-C++17 compilers should be considered spotty, and generally we only actively maintain compatibility with the 2 most recent major macOS family versions when it comes to Xcode.

## Building, Installing, and Testing

The project uses **CMake** as its base build system. Originally, hand-built project files for a number of different IDEs were used, but they were dependent on a particular folder hierarchy and also didn’t lend themselves very well to automation.

lucenaBAL is a header-only library. The basic build instructions are provided above under **Getting Started**.  We give two different methods since, by default, **macOS** and **Linux** installs are to `/usr/local`, which requires sudo or root access, while **Windows** uses a different model. Ignoring these differences, we have the following:

| | |
| :- | :- |
| 1 | `mkdir -p build` |
| 2 | `cmake -DCMAKE_INSTALL_PREFIX=/path/to/install -DCMAKE_BUILD_TYPE=Release -S ./ -B build` |
| 3 | `cmake --build build` |
| 4 | `cmake --build build --target install` |

Line 2 can be modified with `-G "<generator>"`, where `<generator>` should be replaced with one of the supported [generator strings](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html).

Also in line 2, the `-DCMAKE_INSTALL_PREFIX` switch can be left out if the default installation directory of `/usr/local` is acceptable.

Additionally in line 2, the build type may be chosen from the usual set with the usual meanings for CMake: Debug, Release, RelWithDebInfo and MinSizeRel.

Line 4 can be replaced by `cd build && sudo make install` when installing to a system dir such as `/usr/local`. Tests are generated by default and left in `build/tests`. They can be run in situ by changing line 4 to `ctest --test-dir build` (or `cmake --build build --target test`). With a multi-config generator such as Visual Studio or Xcode, pass the configuration to both the build and the tests, e.g. `cmake --build build --config Release` and `ctest --test-dir build -C Release`; without `-C`, no tests will run. Tests can be scripted in the usual way for CMake and CTest, for example in order to only install the library if testing succeeds.

The default tests are:
- `lbalTest.Validation`, which compiles every feature token and logs those that are unsupported, along with tests of the formatting and decorator macros
- `lbalTokenCoverage`, which checks that every documented token has a test and, for language tokens, a guard against being defined outside the library

Linting is possible by changing line 4 to `cmake --build build --target format` to run `clang-format` against all source files under `include` and `tests`, which is handy if you’re not using `git` prehooks or some code editor facility to lint as you go. Relatedly, using `format-dry` instead of `format` will preview the changes instead of simply applying them.

Docs can also be generated, if desired, by adding `-DLBAL_BUILD_DOCS=ON` to line 2 and building normally. This requires [Doxygen](https://www.doxygen.nl/), and the docs are left in `build/docs/doxygen/html`.

### Feature-detection tests

Two optional test suites check that feature tokens tell the truth. Add `-DLBAL_BUILD_ALL_FEATURE_TESTS=ON` to line 2 to build both, or enable them separately as described below. Both suites need to actually _run_ their test programs, so when cross-compiling, either turn them off or set `CMAKE_CROSSCOMPILING_EMULATOR`, depending on whether you have emulation on hand.

#### False positives

A token that claims a feature is available when it isn’t, or isn’t usable as specified, is a false positive. An optional test suite checks for these. Enable it by adding `-DLBAL_BUILD_FALSE_POSITIVE_TESTS=ON` to line 2. `LBAL_FALSE_POSITIVE_TEST_STANDARDS` chooses the C++ Standard modes to test in: `latest` (the default) means the newest Standard the compiler supports, and you can list others with it, e.g. `-DLBAL_FALSE_POSITIVE_TEST_STANDARDS="17;20;latest"` (C++17 is the minimum, as required by Google Test).

The suite has two parts:
- Tests of behavior and library interfaces, which run with the other tests under CTest and are named `cxx<NN>.lbalFalsePositive.<token>`. A token that is `0` is reported as skipped.
- Compile-only probes, for syntax that can only fail to compile. These aren’t part of the default build, so a failure can’t stop the other tests from building. Build them with `cmake --build build --target lbalFalsePositiveProbes -- -k` (use `-k 0` with Ninja) to see every failure at once.

CI always runs the suite on every platform at `latest`, and a false positive fails the build. To test older Standards in CI as well, set the GitHub repository variable `LBAL_FALSE_POSITIVE_TEST_STANDARDS`, e.g. to `17;20;23;latest`.

#### False negatives

A token that is `0` although its feature works is a false negative. A second optional suite checks for these, for every language, attribute and library token up through C++23, by reusing the false-positive tests: each zero-valued token’s probe is compiled with the token forced on, and if the probe compiles (and, for a behavioral test, passes), the token is wrong. Enable it by adding `-DLBAL_BUILD_FALSE_NEGATIVE_TESTS=ON` to line 2; `LBAL_FALSE_NEGATIVE_TEST_STANDARDS` chooses the Standard modes, in the same way as for false positives.

The forced compiles happen when CMake configures the project, since failing to compile is the expected result. This adds a few seconds for the newest Standard, and a few minutes for each older Standard requested, as more tokens are `0` there. Results are cached, so reconfiguring only re-runs what changed. The results are reported under CTest as `cxx<NN>.lbalFalseNegative.<token>`: a nonzero token is skipped, as the false-positive suite covers it.

CI always runs this suite too, at `latest`; set the repository variable `LBAL_FALSE_NEGATIVE_TEST_STANDARDS` to add older Standards.

As indicated above, we do _not_ currently perform false-negative tests for tokens specific to C++26 and later. This is a work-in-progress.

## To-Do
_Roughly in order of precedence:_
- confirm the false-positive tests written ahead of compiler support (marked `SEEME`) once compilers implement those features
- add more examples
- update the false-negative tests for C++26 and later
- generate nicer-looking IDE project files

A more formal action items list will be maintained on our [GitHub issues page](https://github.com/bitweeder/lucenaBAL/issues).

## Support

lucenaBAL aggressively tracks the latest tools and standards, but maintaining support for older tools in new releases is unlikely to happen. The cold reality is that we do not have the bandwidth to pay the interest on anyone else’s technical debt. If you’re stuck with older tooling and an older release of lucenaBAL does what you need, use that one. If you find a bug in any release, we greatly appreciate patches, though we strongly encourage you to at least [open an issue](https://github.com/bitweeder/lucenaBAL/issues) even if you can’t [submit a pull request](https://github.com/bitweeder/lucenaBAL/pulls). Feature requests will be considered, but requests to increase our maintenance surface are unlikely to be carried out.

## Contributing

Please read [CONTRIBUTING.md](./CONTRIBUTING.md) for details on the process for [submitting pull requests](https://github.com/bitweeder/lucenaBAL/pulls) to us.

Please note that this project is released with a Contributor Code of Conduct, documented in [CODE_OF_CONDUCT.md](./CODE_OF_CONDUCT.md) By participating in this project you agree to abide by its terms.

## Versioning

We use [SemVer](https://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/bitweeder/lucenaBAL/tags).

## Authors

-   [**bitweeder**](https://bitweeder.com/) - _Originator and maintainer_

## License

This project is licensed under the University of Illinois/NCSA Open Source License - see the [LICENSE.md](./LICENSE.md) file for details. Some portions of the project are governed by other compatible licenses included in that same file, notably:

- [Google Test](https://github.com/google/googletest) is used under the terms of the BSD 3-Clause license. Note that we do not include Google Test itself, but have the build system fetch it as a dependency when generating tests.

## Acknowledgments

- [**Barry Revzin**](https://github.com/BRevzin)—_For maintaining_ [_the SD-6: SG10 Feature Test Recommendations_](https://isocpp.org/std/standing-documents/sd-6-sg10-feature-test-recommendations) _and answering my questions._
- [**cppreference.com**](https://en.cppreference.com/w/)—_For collating a wonderful_ [_time-saving resource_](https://en.cppreference.com/w/cpp/compiler_support) _I used for cross-checking and filling in holes for untested compiler versions._
- [**Dominik Berner**](http://dominikberner.ch/)—_Without whom I’d probably still have CMake 3 as a To-Do item._
- [**Sy Brand**](https://devblogs.microsoft.com/cppblog/author/sibrandmicrosoft-com/)—_Without whose blog post on_ [_Doxygen and Sphinx_](https://devblogs.microsoft.com/cppblog/clear-functional-c-documentation-with-sphinx-breathe-doxygen-cmake/) _I would probably still not be generating proper docs._
- [**Cristian Adam**](https://cristianadam.eu/)—_For providing a_ [_pragmatic example_](https://cristianadam.eu/20191222/using-github-actions-with-c-plus-plus-and-cmake/) _of how to use GitHub actions for continuous integration._
- [**Evan Nemerson**](https://evan.nemerson.com/)—_Who figured out a_ [_viable cross-platform_ `#warning` _replacement_](https://nemequ.github.io/hedley/) _._
- [**Billie Thompson**](https://github.com/PurpleBooth)—_Thanks for the_ [_Readme template_](https://gist.github.com/PurpleBooth/109311bb0361f32d87a2)_!_
- [**Coraline Ada Ehmke**](http://where.coraline.codes/  "Coraline Ada Ehmke")—_Creator of_ [_The Contributor Covenant_](https://www.contributor-covenant.org/)_, used here under the terms of the_ [_Creative Commons Attribution License_](https://github.com/ContributorCovenant/contributor_covenant/blob/master/LICENSE.md)
- [**Pitchfork**](https://github.com/vector-of-bool/pitchfork)—_For providing a formalized project layout convention based on the work done by John Lakos in_ Large-Scale C++ Software Design _back in 1996._
