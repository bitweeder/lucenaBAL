
# Lucena Build Abstraction Library

The purpose of the Lucena Build Abstraction Library (lucenaBAL) is to provide tools to smooth over differences between build environments when working with C++17 and later Standards. It’s a foundational tool that allows code built upon it to remain agnostic to compilers, C++ Standard Library variants, and aspects of the runtime. Note that lucenaBAL is **not** a build system, but rather a C++ header library with a collection of build system support scripts.

**lucenaBAL 2.0 is in active development. Breaking changes are possible—though unlikely—until the tagged 2.0 release.**

## Motivating Example

Imagine that you are working on a project that would benefit from using the C++17 parallelized algorithm for `sort`. Simply querying `__cplusplus` won't tell you if the parallelized algorithms are available, as they are part of the Standard Library; ignoring that will get you into trouble since 2 out of the 3 major Standard Library implementations did not include the parallelized algorithms for most of their post-C++17-release existence, despite them being part of C++17. Checking for the presence of a header won't work since the parallelized algorithms are part of the existing `<algorithm>` header. Even though you _could_ check for the `<execution>` header, that will only tell you that Execution Policies are _probably_ available; it won't tell you about the availability of the algorithm implementations themselves. Checking the values of `__cpp_lib_execution` and `__cpp_lib_parallel_algorithm` would probably work, but those are only guaranteed to be defined if the [SD-6 macros](https://isocpp.org/std/standing-documents/sd-6-sg10-feature-test-recommendations) are in use, and those weren't formally integrated into the Standard until C++20 and the introduction of the `<version>` header. Of course, the `<version>` header might be available, anyway, as a vendor extension, but at least one major vendor shipped such a header for multiple releases that didn't actually include SD-6 macro definitions. Enter lucenaBAL:

    #include <lucenaBAL/lucenaBAL.hpp>
    
    #include <algorithm>
    #include <vector>
    
    #if LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS
        #include <execution>
    #endif
    
    /**
        Sort the supplied vector in place and return a reference to it, using a parallelized sort if available.
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

Under macOS or Linux:

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

This will generate headers, test binaries, and docs in the build directory, then copy the headers  to `/usr/local/include/lucenaBAL` (or the equivalent specified directory) and copy any support files to `/usr/local/share/lucebaBAL` (or the equivalent specified directory). Tests and docs will remain in the build directory. Since lucenaBAL is a header-only library, it is not necessary to link it; simply `#include <lucenaBAL/lucenaBAL.hpp>`. Usage information is available in the documentation and in the headers, primarily in `<lucenaBAL/lbalFeatureSetup.hpp>`. Note that the docs are generated from the headers.

## Prerequisites

lucenaBAL currently requires a C++17 compiler. It has been tested with gcc 7 thru 9, Microsoft Visual Studio 15.7 thru 16.2, and Xcode 9 thru 11. Experimental support is in for clang 6+. All testing thus far has been with the compilers’ bundled Standard Library implementations, although lucenaBAL should support mixing them.

## Building, Installing, and Testing

The project uses CMake as its primary build system. Originally, hand-built project files for a number of different IDEs were used, but they were dependent on a particular folder hierarchy and also didn’t lend themselves very well to automation.

lucenaBAL is a header-only library. The basic build instructions are provided under **Getting Started**.  We give two different methods since, by default, macOS and Linux installs are to `/usr/local`, which requires sudo (or root) privileges, while Windows uses a different model. Ignoring these differences, we have the following, with line numbers added:

    1 > mkdir build
    2 > cd build
    3 > cmake -DCMAKE_INSTALL_PREFIX=/path/to/install ..
    4 > cmake --build . --config Release
    5 > cmake --build . --target install

Line 3 can be changed to:

    3 > cmake -G "<generator>" -DCMAKE_INSTALL_PREFIX=/path/to/install ..

`<generator>` should be replaced with one of the supported [generator strings](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html). The `-DCMAKE_INSTALL_PREFIX` switch could be left out if the default installation directory is acceptable.

In line 4, the config may be chosen from the usual set with the usual meanings for CMake: Debug, Release, RelWithDebInfo and MinSizeRel. Alternatively, you may simply call `make`.

Line 5 can be replaced by `make install` (or `sudo make install`). Tests are generated by default and left in `<build>/test`. They can be automatically run by changing line 5 to:

    5 > cmake --build . --target test

Tests can be scripted in the usual way for CMake and CTest, for example in order to only install the library if testing succeeds.

Docs are also generated by default and left in `<build>/docs`.

## To-Do
_Roughly in order of precedence_
- incorporate C++2a changes through the Cologne meeting
- break out pre-C++17 features (maybe)
- generate nicer-looking IDE project files

## Support

lucenaBAL aggressively tracks the latest tools and standards, and back-porting new features to old versions or attempting to support old tools and standards in new releases is unlikely to happen. The cold reality is that we do not have the bandwidth to pay the interest on anyone else’s technical debt. If an older release does what you need, use it. If you find a bug in any release, we greatly appreciate patches, though we strongly encourage you to at least file a bug report. Feature requests will be considered, but requests to increase our maintenance surface are unlikely to pass muster.

## Contributing

Please read [CONTRIBUTING.md](./CONTRIBUTING.md) for details on the process for submitting pull requests to us.

Please note that this project is released with a Contributor Code of Conduct, documented in [CODE_OF_CONDUCT.md](./CODE_OF_CONDUCT.md) By participating in this project you agree to abide by its terms.

## Versioning

We use [SemVer](https://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/bitweeder/lucenaBAL/tags).

## Authors

-   [**bitweeder**](https://bitweeder.com/) - _Originator and maintainer_

## License

This project is licensed under the University of Illinois/NCSA Open Source License - see the [LICENSE.md](./LICENSE.md) file for details.

Some portions of the project are governed by other, compatible licenses, as described in the licenses directory, notably:

- [Google Test](https://github.com/google/googletest) is used under the terms of the BSD 3-Clause license. See [licenses/bit_cast License.txt](./licenses/bit_cast%20License.txt). Note that we do not include Google Test itself, but have the build system fetch it as a dependency when generating tests.

## Acknowledgments

- **[Dominik Berner](http://dominikberner.ch/)**—_Without whom I’d probably still have CMake 3 as a To-Do item._
- [**Sy Brand**](https://devblogs.microsoft.com/cppblog/author/sibrandmicrosoft-com/)—_Without whose blog post on [Doxygen and Sphinx](https://devblogs.microsoft.com/cppblog/clear-functional-c-documentation-with-sphinx-breathe-doxygen-cmake/) I would probably still not be generating proper docs._
- **Billie Thompson** of [PurpleBooth](https://github.com/PurpleBooth)—_Thanks for the [Readme template](https://gist.github.com/PurpleBooth/109311bb0361f32d87a2)!_
- **[Coraline Ada Ehmke](http://where.coraline.codes/ "Coraline Ada Ehmke")**—_Creator of [The Contributor Covenant](https://www.contributor-covenant.org/), used here under the terms of the [Creative Commons Attribution License](https://github.com/ContributorCovenant/contributor_covenant/blob/master/LICENSE.md)_
