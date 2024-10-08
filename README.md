[![Actions Status](https://github.com/bitweeder/lucenaBAL/workflows/Build%20Matrix/badge.svg)](https://github.com/bitweeder/lucenaBAL/actions)

# Lucena Build Abstraction Library

The purpose of the Lucena Build Abstraction Library (**lucenaBAL**) is to provide tools to smooth over the differences between build environments when working with C++11 and later Standards. It’s a foundational tool that allows code built upon it to remain agnostic to compilers, C++ Standard Library variants, and aspects of the runtime. Note that lucenaBAL is **not** a build system, but rather a C++ header library with a collection of build system support scripts.

## Motivating Example

Imagine that you are working on a project that would benefit from using the C++17 parallelized algorithm for `std::sort`, and you would like to use it conditionally based on availability.
- Simply querying `__cplusplus` won't tell you if the parallelized algorithms are available, as they are part of the Standard Library.
- Ignoring that will get you into trouble since 2 out of the 3 major Standard Library implementations did not include the parallelized algorithms for most of their post-C++17-release existence.
-  Checking for the presence of a header won't work since the parallelized versions of the Standard Library algorithms are part of the existing `<algorithm>` header.
- Even though you _could_ check for the `<execution>` header, that will only tell you that Execution Policies are _probably_ available—it specifically won't tell you about the availability of the algorithm implementations themselves.
- Checking the values of both `__cpp_lib_execution` and `__cpp_lib_parallel_algorithm` would probably work, but those are only guaranteed to be defined if the [SD-6 macros](https://isocpp.org/std/standing-documents/sd-6-sg10-feature-test-recommendations) are defined, and those weren't formally integrated into the Standard until C++20 and the introduction of the `<version>` header.
- Of course, the `<version>` header might be available, anyway, as a vendor extension, but at least one major IDE vendor shipped such a header for multiple releases that didn't actually include SD-6 macro definitions.

Enter **lucenaBAL**:

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
    inline std::vector<int> & sort_vector (std::vector<int> & io_vector)
    {
        #if LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS
            std::sort (std::execution::par, io_vector.begin(), io_vector.end());
        #else
            std::sort (io_vector.begin(), io_vector.end());
        #endif
        
        return io_vector;
    }

## Getting Started

[CMake](https://cmake.org/) scripts are provided which will install the library itself, build and run test applications, and generate documentation. We require at least CMake 3.15, so that will need to be [installed first](https://cmake.org/download/).

More detailed instructions are provided below, but for a quick start, simply clone the repository, open up a terminal window, change to the local repo directory, and execute the following:

Under macOS or Linux (or other UNIX derivatives):
  
    > mkdir build
    > cd build
    > cmake ..
    > cmake --build . --config Release
    > sudo make install

Under Windows:

    > mkdir build
    > cd build
    > cmake -DCMAKE_INSTALL_PREFIX=/path/to/install ..
    > cmake --build . --config Release
    > cmake --build . --target install

This will:
1. Generate headers, test binaries, and docs in the build directory.
2. Copy the headers  to `/usr/local/include/lucenaBAL` (or the equivalent specified directory).
3. Copy any support files to `/usr/local/share/lucenaBAL` (or the equivalent specified directory).

(Note that tests and docs will remain in the build directory.)

Since lucenaBAL is a header-only library, it is not necessary to link to it; simply `#include <lucenaBAL/lucenaBAL.hpp>` where you need feature tests once the headers are installed. Usage information is available in the [online docs](https://bitweeder.github.io/lucenaBAL/html/index.html), as well as in the headers themselves (primarily in  `<lucenaBAL/lbalFeatureSetup.hpp>`).

## Prerequisites

lucenaBAL requires compiler support for C++11 or later. It has been tested with **gcc** 6 thru 14.2, **Microsoft Visual Studio** 2015 Update 3 thru MSVS 2022 17.11.4, **Xcode** 9 thru 16.0, and **llvm/clang** 6 thru 20. All testing thus far has been with the compilers’ bundled Standard Library implementations, although lucenaBAL should support mixing them.

## Building, Installing, and Testing

The project uses **CMake** as its primary build system. Originally, hand-built project files for a number of different IDEs were used, but they were dependent on a particular folder hierarchy and also didn’t lend themselves very well to automation.

lucenaBAL is a header-only library. The basic build instructions are provided above under **Getting Started**.  We give two different methods since, by default, **macOS** and **Linux** installs are to `/usr/local`, which requires sudo or root access, while **Windows** uses a different model. Ignoring these differences, we have the following, with line numbers added:


    1 > mkdir build
    2 > cd build
    3 > cmake -DCMAKE_INSTALL_PREFIX=/path/to/install ..
    4 > cmake --build . --config Release
    5 > cmake --build . --target install

Line 3 can be changed to:

    3 > cmake -G "<generator>" -DCMAKE_INSTALL_PREFIX=/path/to/install ..

`<generator>` should be replaced with one of the supported [generator strings](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html). The `-DCMAKE_INSTALL_PREFIX` switch could be left out if the default installation directory is acceptable.

In line 4, the config may be chosen from the usual set with the usual meanings for CMake: Debug, Release, RelWithDebInfo and MinSizeRel. Alternatively, you may simply call `make`.

Line 5 can be replaced by `make install` (or `sudo make install`). Tests are generated by default and left in `<build>/tests`. They can be automatically run by changing line 5 to:

    5 > cmake --build . --target tests

Tests can be scripted in the usual way for CMake and CTest, for example in order to only install the library if testing succeeds.

Docs can also be generated, if desired, and are left in `<build>/docs`.

## Planning
Tokens deprecated prior to the official lucenaBAL 2.0 release—in particular, placeholder tokens superseded by formalized C++20/C++23 variants—will be removed as part of the eventual lucenaBAL 3.0 release, but will remain available until then.

As always, prefer to use the non-deprecated version of a token, especially when starting a new project.

## To-Do
_Roughly in order of precedence_
- add more examples
- flesh out the unit tests
- generate nicer-looking IDE project files

A more formal action items list will be maintained on our [GitHub issues page](https://github.com/bitweeder/lucenaBAL/issues).

## Support

lucenaBAL aggressively tracks the latest tools and standards, but maintaining support for older tools in new releases is unlikely to happen. The cold reality is that we do not have the bandwidth to pay the interest on anyone else’s technical debt. If an older release does what you need, use it. If you find a bug in any release, we greatly appreciate patches, though we strongly encourage you to at least [open an issue](https://github.com/bitweeder/lucenaBAL/issues) even if you can’t [submit a pull request](https://github.com/bitweeder/lucenaBAL/pulls). Feature requests will be considered, but requests to increase our maintenance surface are unlikely to be carried out.

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
