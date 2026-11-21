/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFeatureSetup.hpp”
  Copyright © 2018-2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

/**
  @file lucenaBAL/lbalFeatureSetup.hpp

  @brief Documents the complete set of feature macros defined by lucenaBAL

  @details Tokens described herein may be considered part of the public
  interface of lucenaBAL. An effort will be made to maintain these in a
  stable fashion in keeping with the principles of
  [semantic versioning](https://semver.org/).

  @remarks Do not include this header directly. It is intended only to
  document the public interface of lucenaBAL.
*/

#pragma once

//	lbal
#include <lucenaBAL/lbalConfig.hpp>

#include <lucenaBAL/details/lbalCompilerSetup.hpp>
#include <lucenaBAL/details/lbalDefinitionTests.hpp>
#include <lucenaBAL/details/lbalLibrarySetup.hpp>
#include <lucenaBAL/details/lbalPlatformSetup.hpp>

/**
  @addtogroup lbal_features

  @brief Provides feature detection describing the target platform, compiler,
  and Standard Library

  @details Note that we set all preprocessor conditionals unless we
  explicitly state otherwise in the conditional description; those whose
  requirements are not met are set to `0`. By default, we set conditionals
  that are met to `1`, but they could conceivably be set to any non-`0`
  value, as per their specific usage instructions, so tests of these
  conditionals need to reflect that.
*/

/**
  @addtogroup lbal_build_env

  @brief Describes aspects of the build-time environment relevant to library
  clients

  @details These are mostly descriptors of various kinds.

  @{
*/

/**
  @name LBAL_NAME

  @brief These macros resolve to human-readable strings that identify the
  specified entities.

  @details If the entity has a version value associated with it, such as a
  compiler does, the string -may- include that version, but it is not
  required to do so. It is important to understand that since these values
  are generated in a header at compile time, and so they will change; if it
  is desired to cache the value, e.g., to report the compiler a library was
  built with in an executable that links to it, it will be necessary to cache
  it yourself, e.g., by storing the character array in a string with external
  storage in a source file in the library and providing an accessor to it.

  Note that it is not safe to use these for comparisons, either directly or
  in parsed form, as their format is not guaranteed. While these are intended
  strictly for reporting, there are other macros more appropriate for
  testing.

  @{
*/

/**
  @def LBAL_NAME_TARGET_CPU
  At a minimum, this will name the CPU family that the code was compiled
  for, but it may contain much more detailed information.
*/
#ifndef LBAL_NAME_TARGET_CPU
  #define LBAL_NAME_TARGET_CPU u8"Doxygen CPU"
  #error "LBAL_NAME_TARGET_CPU must be defined"
#endif

/**
  @def LBAL_NAME_TARGET_OS
  This names the target OS, and may identify the minimum supported
  version of the target OS, as well, though is not required to do so.
*/
#ifndef LBAL_NAME_TARGET_OS
  #define LBAL_NAME_TARGET_OS u8"Doxygen OS"
  #error "LBAL_NAME_TARGET_OS must be defined"
#endif

/**
  @def LBAL_NAME_COMPILER
  This names the compiler used to build the code.
*/
#ifndef LBAL_NAME_COMPILER
  #define LBAL_NAME_COMPILER u8"Doxygen Compiler"
  #error "LBAL_NAME_COMPILER must be defined"
#endif

/**
  @def LBAL_NAME_STANDARD_LIBRARY
  This names the implementation of the C++ Standard Library used
  to build the code.
*/
#ifndef LBAL_NAME_STANDARD_LIBRARY
  #define LBAL_NAME_STANDARD_LIBRARY u8"Doxygen C++ Standard Library"
  #error "LBAL_NAME_STANDARD_LIBRARY must be defined"
#endif

///	@}	LBAL_NAME

/**	@name LBAL_TARGET_COMPILER

  @brief Report 1 or 0 depending on which macros match the compiler used to
  build the code.

  @details These identifers take the place of direct querying, as some
  compilers are in the habit of self-identifying as something else, and it
  can be challenging to suss out their actual identities. These are not
  generally useful, as there’s typically another, better mechanism for
  addressing whatever issue these can resolve, but they’re here for when
  nothing else will do. Note that if you also need version information,
  you’ll have to resort to direct querying, though it may still sensible to
  filter first on these for the aforementioned reason.

  Generally, a given compiler will match at least two tokens: one identifying
  the rough compiler “family” to which it belongs, and one that identifies it
  more uniquely.

  @remarks (SEEME - bitweeder) These are blunt instruments. In particular,
  there may be no differentiation between frontened (e.g., c1xx or clang) and
  backend (e.g., c2 or llvm). In practice, this mattered more when c2/clang was
  a thing, but seems less important now. We’ll consider revisiting if the extra
  granularity turns out to be useful.

  @{
*/

/**
  @def LBAL_TARGET_COMPILER_CLANG
  @brief The compiler being used is an llvm/clang derivative.
  @details This probably won’t match c2/clang, but no testing has been done
  to see what that setup may be emulating. More information is available from
  [the llvm project](https://clang.llvm.org/).

  @remarks (SEEME - bitweeder) It would be trivial to split this identifier
  into one for clang and one for llvm, but it’s unclear how useful this would
  be.
*/
#ifndef LBAL_TARGET_COMPILER_CLANG
  #define LBAL_TARGET_COMPILER_CLANG 0
#endif

/**
  @def LBAL_TARGET_COMPILER_VANILLA_CLANG
  @brief The compiler being used is pure llvm/clang.
  @details More information is available from
  [the llvm project](https://clang.llvm.org/).

  @remarks (SEEME - bitweeder) This is a more loose definition than it sounds
  like, as we’ll classify any clang as “vanilla clang” if some other check
  hasn’t previously claimed it, so order of evaluation matters, as does how
  thorough the previous checks were.
*/
#ifndef LBAL_TARGET_COMPILER_VANILLA_CLANG
  #define LBAL_TARGET_COMPILER_VANILLA_CLANG 0
#endif

/**
  @def LBAL_TARGET_COMPILER_APPLE_CLANG
  @brief The compiler being used is the llvm/clang variant shipped with
  Apple’s Xcode.
  @details More information is available from
  [the llvm project](https://clang.llvm.org/).
*/
#ifndef LBAL_TARGET_COMPILER_APPLE_CLANG
  #define LBAL_TARGET_COMPILER_APPLE_CLANG 0
#endif

/**
  @def LBAL_TARGET_COMPILER_GCC
  @brief The compiler being used is a gcc derivative.
  @details More information is available from
  [the gcc project](https://gcc.gnu.org/).
*/
#ifndef LBAL_TARGET_COMPILER_GCC
  #define LBAL_TARGET_COMPILER_GCC 0
#endif

/**
  @def LBAL_TARGET_COMPILER_VANILLA_GCC
  @brief The compiler being used is pure gcc.
  @details More information is available from
  [the llvm project](https://clang.llvm.org/).

  @remarks (SEEME - bitweeder) This is a more loose definition than it sounds
  like, as we’ll classify any gcc as “vanilla gcc” if some other check hasn’t
  previously claimed it, so order of evaluation matters, as does how thorough
  the previous checks were.
*/
#ifndef LBAL_TARGET_COMPILER_VANILLA_GCC
  #define LBAL_TARGET_COMPILER_VANILLA_GCC 0
#endif

/**
  @def LBAL_TARGET_COMPILER_MSVC
  @brief The compiler being used is an MSVC derivative.
  @details More information is available from
  [Microsoft](https://visualstudio.microsoft.com/).
*/
#ifndef LBAL_TARGET_COMPILER_MSVC
  #define LBAL_TARGET_COMPILER_MSVC 0
#endif

/**
  @def LBAL_TARGET_COMPILER_VANILLA_MSVC
  @brief The compiler being used is pure MSVC.
  @details More information is available from
  [Microsoft](https://visualstudio.microsoft.com/).

  @remarks (SEEME - bitweeder) This is a more loose definition than it sounds
  like, as we’ll classify any MSVC as “vanilla MSVC” if some other check hasn’t
  previously claimed it, so order of evaluation matters, as does how thorough
  the previous checks were.
*/
#ifndef LBAL_TARGET_COMPILER_VANILLA_MSVC
  #define LBAL_TARGET_COMPILER_VANILLA_MSVC 0
#endif

///	@}	LBAL_TARGET_COMPILER

/**
  @name LBAL_TARGET_STANDARD_LIBRARY

  @brief Report 1 or 0 depending on which mutually exclusive macro matches
  the C++ Standard Library used to build the code.

  @details This takes the place of direct querying, as this may not even be
  an option in some cases. These are not generally useful, as there’s
  typically another, better mechanism for solving whatever this is meant to
  solve, but they’re here for when nothing else will do. Note that if you
  also need version information, you’ll have to resort to direct querying.

  @{
*/

/**
  @def LBAL_TARGET_STANDARD_LIBRARY_APPLE_LIBCPP
  @brief C++ Standard Library implementation is Apple’s libc++
  @details Information available from
  [the llvm project](https://libcxx.llvm.org/).
*/
#ifndef LBAL_TARGET_STANDARD_LIBRARY_APPLE_LIBCPP
  #define LBAL_TARGET_STANDARD_LIBRARY_APPLE_LIBCPP 0
#endif

/**
  @def LBAL_TARGET_STANDARD_LIBRARY_LIBCPP
  @brief C++ Standard Library implementation is libc++
  @details Information available from
  [the llvm project](https://libcxx.llvm.org/).
*/
#ifndef LBAL_TARGET_STANDARD_LIBRARY_LIBCPP
  #define LBAL_TARGET_STANDARD_LIBRARY_LIBCPP 0
#endif

/**
  @def LBAL_TARGET_STANDARD_LIBRARY_MSVC
  @brief C++ Standard Library implementation is Microsoft’s.
  @details Information available from
  [Microsoft](https://docs.microsoft.com/en-us/cpp/standard-library/cpp-standard-library-overview).
*/
#ifndef LBAL_TARGET_STANDARD_LIBRARY_MSVC
  #define LBAL_TARGET_STANDARD_LIBRARY_MSVC 0
#endif

/**
  @def LBAL_TARGET_STANDARD_LIBRARY_LIBSTDCPP
  @brief C++ Standard Library implementation is libstdc++
  @details Information available from
  [the gcc project](https://gcc.gnu.org/onlinedocs/libstdc++/).
*/
#ifndef LBAL_TARGET_STANDARD_LIBRARY_LIBSTDCPP
  #define LBAL_TARGET_STANDARD_LIBRARY_LIBSTDCPP 0
#endif

///	@}	LBAL_TARGET_STANDARD_LIBRARY

/**
  @name LBAL_TARGET_CPU_FAMILY

  @brief Specify roughly which microprocessor family code is being generated
  for.

  @details At most one of these is 1, the rest are 0.

  @remarks (SEEME - bitweeder) One additional candidate for inclusion is
  LBAL_TARGET_CPU_FAMILY_AMD, but there has been no pragmatic reason to add
  it.

  @{
*/

/**
  @def LBAL_TARGET_CPU_FAMILY_ARM
  The CPU is in the ARM chip family.
*/
#ifndef LBAL_TARGET_CPU_FAMILY_ARM
  #define LBAL_TARGET_CPU_FAMILY_ARM 0
#endif

/**
  @def LBAL_TARGET_CPU_FAMILY_X86
  The CPU is x86 instruction set-compatible, including Intel and AMD
  processors.
*/
#ifndef LBAL_TARGET_CPU_FAMILY_X86
  #define LBAL_TARGET_CPU_FAMILY_X86 0
#endif

///	@}	LBAL_TARGET_CPU_FAMILY

/**
  @name LBAL_TARGET_CPU

  @brief Specify for which microprocessor instruction set code is being
  generated.

  @details At most one of these is 1, the rest are 0.

  @remarks (SEEME - bitweeder) There used to be more of these, but they’ve been
  largely mooted. Candidates for additions include console-specific processors
  and explicit differentiation for AMD processors.

  @remarks (SEEME - bitweeder) More granular responses are possible, though
  it’s been viewed as more useful to differentiate on feature sets, instead
  (e.g., AVX2 availability).

  @remarks ((FIXME - bitweeder)) Testing for specific non-SIMD instruction
  availability, and additionally providing instrinsics, would be very helpful.
  Specifically, generic ways to invoke POPCNT and LZCNT would be helpful.

  @{
*/

/**
  @def LBAL_TARGET_CPU_ARM
  Generic 32-bit ARM
*/
#ifndef LBAL_TARGET_CPU_ARM
  #define LBAL_TARGET_CPU_ARM 0
#endif

/**
  @def LBAL_TARGET_CPU_ARM_64
  Generic 64-bit ARM
*/
#ifndef LBAL_TARGET_CPU_ARM_64
  #define LBAL_TARGET_CPU_ARM_64 0
#endif

/**
  @def LBAL_TARGET_CPU_X86
  Generic 32-bit x86
*/
#ifndef LBAL_TARGET_CPU_X86
  #define LBAL_TARGET_CPU_X86 0
#endif

/**
  @def LBAL_TARGET_CPU_X86_64
  Generic 64-bit x86
*/
#ifndef LBAL_TARGET_CPU_X86_64
  #define LBAL_TARGET_CPU_X86_64 0
#endif

/**
  @def LBAL_TARGET_CPU_IA64
  Generic 64-bit Itanium
*/
#ifndef LBAL_TARGET_CPU_IA64
  #define LBAL_TARGET_CPU_IA64 0
#endif

///	@}	LBAL_TARGET_CPU

/**
  @name LBAL_TARGET_VEC

  @brief Specify which vector instruction set is being generated, if any.

  @details Multiple conditionals may be true, but some are mutually
  exclusive.

  @remarks (APIME) There is no corresponding test for AVX-512, as it’s not
  a monolithic instruction set, and we don’t have the operational experience
  needed to evaluate a meaningful breakdown beyond just mirroring any
  predfined macros the compiler may happen to have.

  @remarks (SEEME - bitweeder) We don’t currently independently check for
  SSE-Math and similar instruction splits; this may be a defect.

  @remarks (SEEME - bitweeder) There used to be more of these, but they’ve been
  largely mooted. Candidates for additions include console-specific vector
  instruction sets, and explicit differentiation for AMD instruction sets.

  @{
*/

/**
  @def LBAL_TARGET_VEC_SSE
  Intel SSE SIMD instruction set.
*/
#ifndef LBAL_TARGET_VEC_SSE
  #define LBAL_TARGET_VEC_SSE 0
#endif

/**
  @def LBAL_TARGET_VEC_SSE2
  Intel SSE2 SIMD instruction set.
*/
#ifndef LBAL_TARGET_VEC_SSE2
  #define LBAL_TARGET_VEC_SSE2 0
#endif

/**
  @def LBAL_TARGET_VEC_SSE3
  Intel SSE3 SIMD instruction set.
*/
#ifndef LBAL_TARGET_VEC_SSE3
  #define LBAL_TARGET_VEC_SSE3 0
#endif

/**
  @def LBAL_TARGET_VEC_SSE41
  Intel SSE4.1 SIMD instruction set.
*/
#ifndef LBAL_TARGET_VEC_SSE41
  #define LBAL_TARGET_VEC_SSE41 0
#endif

/**
  @def LBAL_TARGET_VEC_SSE42
  Intel SSE4.2 SIMD instruction set.
*/
#ifndef LBAL_TARGET_VEC_SSE42
  #define LBAL_TARGET_VEC_SSE42 0
#endif

/**
  @def LBAL_TARGET_VEC_AVX
  Intel AVX SIMD instruction set.
*/
#ifndef LBAL_TARGET_VEC_AVX
  #define LBAL_TARGET_VEC_AVX 0
#endif

/**
  @def LBAL_TARGET_VEC_AVX2
  Intel AVX2 SIMD instruction set.
*/
#ifndef LBAL_TARGET_VEC_AVX2
  #define LBAL_TARGET_VEC_AVX2 0
#endif

///	@}	LBAL_TARGET_VEC

/**
  @name LBAL_TARGET_OS

  @brief Specify which Operating System code is being generated for.

  @details At most one of the these is 1, the rest are 0 (except for
  LBAL_TARGET_OS_IOS, which is set whenever LBAL_TARGET_OS_IOS_SIM is set,
  but can also be set alone).

  @remarks (SEEME - bitweeder) Candidates for additions include
  console-specific operating systems, Android, tvOS, and watchOS. BSD could
  conceivably have its own flag, but we currently roll it in under
  LBAL_TARGET_OS_X11.

  @remarks (SEEME - bitweeder) These focus primarily on UI characteristics, as
  opposed to system internals, which is why we have LBAL_TARGET_OS_X11 and not
  LBAL_TARGET_OS_POSIX. A case could be made that we realistically need to
  track both, but in practice - during the implementation of lucenaPAL - no
  practical need was found. It’s possible that once additional platform support
  is added to that library, we’ll find we need to revisit this design decision.

  @remarks (FIXME - bitweeder) Wayland needs to be accounted for; currently,
  it’s rolled into LBAL_TARGET_OS_X11.

  @{
*/

/**
  @def LBAL_TARGET_OS_IOS
  Apple’s iOS
*/
#ifndef LBAL_TARGET_OS_IOS
  #define LBAL_TARGET_OS_IOS 0
#endif

/**
  @def LBAL_TARGET_OS_IOS_SIM
  Apple‘s iOS running under a Simulator
*/
#ifndef LBAL_TARGET_OS_IOS_SIM
  #define LBAL_TARGET_OS_IOS_SIM 0
#endif

/**
  @def LBAL_TARGET_OS_X11
  X.org‘s X11
*/
#ifndef LBAL_TARGET_OS_X11
  #define LBAL_TARGET_OS_X11 0
#endif

/**
  @def LBAL_TARGET_OS_MACOS
  Apple’s macOS
*/
#ifndef LBAL_TARGET_OS_MACOS
  #define LBAL_TARGET_OS_MACOS 0
#endif

/**
  @def LBAL_TARGET_OS_WINAPI
  Microsoft’s Windows
*/
#ifndef LBAL_TARGET_OS_WINAPI
  #define LBAL_TARGET_OS_WINAPI 0
#endif

///	@}	LBAL_TARGET_OS

/**
  @name LBAL_TARGET_RT_[EXECUTABLE_FORMAT]

  @brief Identiy the executable format which the compiled code is being
  linked in.

  @details These are most needed when the OS and/or CPU supports more than
  one format (e.g. Mac OS X on PPC supports CFM and Mach-O). Note that values
  are descriptive; if the condition is met, the value will be 1, otherwise 0.

  @remarks (APIME) Inclusion of specific formats is somewhat arbitrary,
  as we’ve only bothered to define them for cases we’ve encountered in
  practice. Additional operational experience—and supported platforms—will
  probably lead to some additions.

  @{
*/

/**
  @def LBAL_TARGET_RT_COFF
  A COFF derivative is being used, including COFF and PE/COFF.
*/

#ifndef LBAL_TARGET_RT_COFF
  #define LBAL_TARGET_RT_COFF 0
#endif

/**
  @def LBAL_TARGET_RT_ELF
  The ELF executable format, currently the default for Linux and BSD, is
  being used.
*/

#ifndef LBAL_TARGET_RT_ELF
  #define LBAL_TARGET_RT_ELF 0
#endif

/**
  @def LBAL_TARGET_RT_MACHO
  The Mach-O executable format, currently the default for macOS and iOS, is
  being used.
*/

#ifndef LBAL_TARGET_RT_MACHO
  #define LBAL_TARGET_RT_MACHO 0
#endif

/**
  @def LBAL_TARGET_RT_WASM
  The Wasm byte code executable format is being used.
*/

#ifndef LBAL_TARGET_RT_WASM
  #define LBAL_TARGET_RT_WASM 0
#endif

///	@}	LBAL_TARGET_RT_[EXECUTABLE_FORMAT]

/**
  @name LBAL_TARGET_RT_[ENDIANESS]

  @brief Identify the byte-ordering of the code being generated.

  @details Note that this is only used to determine the “native” format. We
  don’t call out processors that can do either; all the processors we support
  operate in one mode or the other for the duration of execution, which is
  all we care about.

  @{
*/

/**
  @def LBAL_TARGET_RT_LITTLE_ENDIAN
  The Intel-standard Little Endian byte-ordering is being used.
*/
#ifndef LBAL_TARGET_RT_LITTLE_ENDIAN
  #define LBAL_TARGET_RT_LITTLE_ENDIAN 0
#endif

/**
  @def LBAL_TARGET_RT_BIG_ENDIAN
  The PowerPC-standard Big Endian byte-ordering is being used.
*/
#ifndef LBAL_TARGET_RT_BIG_ENDIAN
  #define LBAL_TARGET_RT_BIG_ENDIAN 0
#endif

///	@}	LBAL_TARGET_RT_[ENDIANESS]

/**
  @name LBAL_TARGET_RT_[ADDRESSING]

  @brief Identify the address table size of the runtime environment which the
  code is being generated for.

  @details This identifies whether the binary is being generated for 32-bit
  or 64-bit execution.

  @{
*/

/**
  @def LBAL_TARGET_RT_32_BIT
  32-bit addressing is being used.
*/
#ifndef LBAL_TARGET_RT_32_BIT
  #define LBAL_TARGET_RT_32_BIT 0
#endif

/**
  @def LBAL_TARGET_RT_64_BIT
  64-bit addressing is being used.
*/
#ifndef LBAL_TARGET_RT_64_BIT
  #define LBAL_TARGET_RT_64_BIT 0
#endif

///	@}	LBAL_TARGET_RT_[ADDRESSING]

/**
  @name LBAL_TARGET_API

  @brief Differentiate between sets of core System API’s on the same
  processor under the same OS.

  @details Unlike LBAL_TARGET_OS and LBAL_TARGET_CPU, these tokens are not
  mutally exclusive. lucenaBAL attempts to auto-configure all LBAL_TARGET_API
  values, but will often need a LBAL_TARGET_API value predefined—e.g., in a
  build file—in order to disambiguate.  Note that values are descriptive; if
  the condition is met, the value will be 1, otherwise 0.

  @remarks (SEEME - bitweeder) This is not intended to be an exhaustive list of
  APIs. Originally, it was useful for differentiating between possible
  supported and available Apple APIs (e.g., QuickDraw, Carbon, Cocoa, and
  whatever other toolbox flavor of the week floats in), but it’s academic on
  platforms that don’t deprecate their APIs with abandon. Further operational
  experience might find us wanting to differentiate between other available
  OS-level APIs.

  @{
*/

/**
  @def LBAL_TARGET_API_COCOA
  Apple’s object-oriented API for macOS.
*/

#ifndef LBAL_TARGET_API_COCOA
  #define LBAL_TARGET_API_COCOA 0
#endif

/**
  @def LBAL_TARGET_API_COCOA_TOUCH
  Apple’s object-oriented API for iOS, watchOS, and tvOS.
*/

#ifndef LBAL_TARGET_API_COCOA_TOUCH
  #define LBAL_TARGET_API_COCOA_TOUCH 0
#endif

/**
  @def LBAL_TARGET_API_POSIX
  The standard C API used by all flavors of UNIX.
*/

#ifndef LBAL_TARGET_API_POSIX
  #define LBAL_TARGET_API_POSIX 0
#endif

/**
  @def LBAL_TARGET_API_WIN32
  A Microsoft’s C API for Windows.
*/

#ifndef LBAL_TARGET_API_WIN32
  #define LBAL_TARGET_API_WIN32 0
#endif

/**
  @def LBAL_TARGET_API_WIN64
  A Microsoft’s C API for Windows, specific to 64-bit implementations.
*/

#ifndef LBAL_TARGET_API_WIN64
  #define LBAL_TARGET_API_WIN64 0
#endif

/**
  @def LBAL_TARGET_API_X11
  The standard C Graphics API used by most flavors of UNIX.
*/

#ifndef LBAL_TARGET_API_X11
  #define LBAL_TARGET_API_X11 0
#endif

///	@}	LBAL_TARGET_API

///	@}	lbal_build_env

/**
  @addtogroup lbal_platform

  @brief Provides feature detection describing the capabilities of platform

  @details These are all simple availability flags, and will be set to `1`
  if a feature is available and `0` otherwise.

  Mostly, the platform features are actually compiler features whose
  availability is intentionally dependent on the target platform.

  @remarks There are compiler features whose availability is dependent on the
  target platform, _but not by design_. These are documented under
  [compiler feature detection](@ref lbal_compiler).

  @{
*/

/**
  @name LBAL_TYPE
  These identify characteristics of certain POD types for a given compiler;
  preprocessor definitions are used since `sizeof` can’t be used by the
  preprocessor (reliably). These can be defined since we have special
  knowledge of the compile/build flags that wouldn’t necessarily be
  available to conforming portable code.

  @{
*/

/**
  @def LBAL_TYPE_HAS_INT64
  native 64-bit `int`s - including `usigned int`s - as `int64_t` and
  `uint64_t` (and possibly also `long long` and `unsigned long long`,
  depending)
*/
#ifndef LBAL_TYPE_HAS_INT64
  #define LBAL_TYPE_HAS_INT64 0
#endif

/**
  @def LBAL_TYPE_HAS_INT128
  native 128-bit `ints` - including `usigned int`s - as `__int128_t` and
  `__uint128_t`
*/
#ifndef LBAL_TYPE_HAS_INT128
  #define LBAL_TYPE_HAS_INT128 0
#endif

/**
  @def LBAL_TYPE_EXACT_WIDTH_INTEGERS
  availability of C99 exact width `int` types
*/
#ifndef LBAL_TYPE_EXACT_WIDTH_INTEGERS
  #define LBAL_TYPE_EXACT_WIDTH_INTEGERS 0
#endif

/**
  @def LBAL_TYPE_DOUBLE_GT_FLOAT
  `double` is distinct from `float`
*/
#ifndef LBAL_TYPE_DOUBLE_GT_FLOAT
  #define LBAL_TYPE_DOUBLE_GT_FLOAT 0
#endif

/**
  @def LBAL_TYPE_LONG_DOUBLE_GT_DOUBLE
  `long double` is distinct from `double`
*/
#ifndef LBAL_TYPE_LONG_DOUBLE_GT_DOUBLE
  #define LBAL_TYPE_LONG_DOUBLE_GT_DOUBLE 0
#endif

/**
  @def LBAL_TYPE_WCHAR_T_IS_16_BITS
  if this is `0`, `wchar_t` is assumed to be a 32-bit integer type
*/
#ifndef LBAL_TYPE_WCHAR_T_IS_16_BITS
  #define LBAL_TYPE_WCHAR_T_IS_16_BITS 0
#endif

///	@}	LBAL_TYPE

/**
  @name LBAL_FEATURE
  Some compilers and platforms do things in a peculiar way that we may need
  to work around or otherwise deal with. Those features are noted here.

  @{
*/

/**
  @def LBAL_FEATURE_UTF16_FILE_SYSTEM

  @brief File system requires UTF-16 encoding.

  @details It is assumed that the file system uses UTF-8 encoding unless this
  feature conditional is set.

  @remarks (APIME) Really only necessary for Windows.
*/
#ifndef LBAL_FEATURE_UTF16_FILE_SYSTEM
  #define LBAL_FEATURE_UTF16_FILE_SYSTEM 0
#endif

///	@}	LBAL_FEATURE

///	@}	lbal_platform

/**
  @addtogroup lbal_compiler

  @brief Language feature availability flags to indicate whether a given C++
  feature is supported by the current compiler.

  @details These are set to a non-zero value if available and `0` otherwise;
  every token is always set to _some_ value. Where possible, these mimic the
  equivalent [SD-6 macros](https://wg21.link/sd6), both in their naming and
  in their range of values, so a value will be:

  - `0`, to indicate no availability, or
  - the SD-6 value equivalent to the available feature support, or
  - `1`, if there is no equivalent SD-6 macro

  Note that these tokens are neither exhaustive nor bounded:

  - Features which are available in all supported compilers are not required
  to have associated tokens. However, features that could conceivably be
  manually disabled in a given compiler—e.g., exception handling—always
  have tokens; whether the token is set to a non-`0` value depends on the
  feature’s availability at build time.

  - Features we (the developers) have not had cause to use or care about
  are often not represented right away. Eventually, all language features
  accepted into the Standard from C++20 onwards will appear here.

  - Features from proposals to the Standard may have flags here; in some
  cases, this may occur for proposed features that have not been accepted
  into the Standard, e.g., as part of a Technical Specification. This
  typically happens with de facto standards (e.g., variants on symbol
  visibility handling) when it relates to language features. This sort of
  thing is much more common for proposed library features (e.g.,
  `likely`/`unlikely` support was made available long before it was formally
  voted in).

  Finally, the descriptions of the various language and library features
  listed here tend to be terse or oblique. This is because this documentation
  is not intended to be a C++ reference there are much better references out
  there. Rather, it is hoped that enough context is given to remind you of
  what a given feature does, and then any additional notes are intended only
  to describe gotchas and implementation oddities specific to the feature
  detection problem domain.

  @remarks (APIME) Some SD-6 tokens have their values bumped by newer iterations
  of the Document. Generally, we will issue new unique tokens here when this
  happens, _but the values of all such tokens will reflect that of the
  equivalent supported SD-6 token value_. For example, if SD-6 token
  `__cpp_meow` has 4 different values associated with it from 4 proposals
  against 4 successive Standards, we will define 4 unique tokens, one for each
  proposal. If the current build environment only supports the first 3 of the 4
  proposals, 3 of our tokens will be set to the most recent suppoeted
  proposal’s value for `__cpp_meow`, while the 4th of our tokens, representing
  the most recent—and unsupported—proposal, will be set to `0`.

  @remarks (SEEME - bitweeder) Note that there are ambiguous cases where a
  feature may have been updated, e.g., as a result of a Defect Report (DR), but
  a new SD-6 value has not been assigned; this can be further complicated if
  the DR resolution is not finalized, meaning that the available feature is in
  an intermediate state. Currently, we have no policy for dealing with this
  situation, as it has not arisen yet in practice.

  @remarks (APIME) Previous iterations of this header also attempted to
  determine whether various C99 and C11 features were available. This turned
  out to be impractical and a bit pointless. As a result, such features are
  only tracked - if they are tracked at all - in the context of their
  applicability to a given C++ Standard, e.g., support for the C99 preprocessor
  as required by C++11, and the C11 preprocessor as required by C++20.

  @remarks (SEEME - bitweeder) Some implementations may choose to make a
  feature available to an earlier C++ release than the the first officially
  supported one. This can be done, for example, to make features available from
  a Draft Standard. Generally, we don’t second-guess the implementation if they
  set an SD-6 macro a particular—unless we have good reason to know it was set
  incorrectly. More challenging is dealing with implementations that _don’t_
  have SD-6 macros. Our approach in this case is to identify a feature as
  available if the implementation is known to support it _and_ the Language
  version in use is greater than the last unsupported version; this latter
  condition catches the frequent convention of compilers identifying a future
  unreleased dialect as the last Standard (e.g., 201103L) plus one (e.g.,
  201104L), until the Standard is official and the the version changes (e.g.,
  to 201402L).

  @remarks (APIME) Features prior to the C++20 Standard are represented by
  tokens generally only if they have equivalent SD-6 tokens. Support can be
  broadened if there is demand.

  @remarks The SD-6 tokens and their values referenced here are current as of
  the 2026-02-02 revision.

  @{
*/

/*
  SEEME (bitweeder) Doxygen documents the `.inc` files as separate inputs, so
  their includes are hidden from it. Each `#include` Doxygen follows makes it
  treat the next empty `#ifndef X`/`#define X` pair (e.g.
  `LBAL_DIAGNOSTIC_PUSH`) as an include guard and drop its documentation.
*/
///	@cond LBAL_INTERNAL
#include <lucenaBAL/details/fragments/lbalFeatureSetup-overview-cpp03.inc>
///	@endcond

///	@cond LBAL_INTERNAL
#include <lucenaBAL/details/fragments/lbalFeatureSetup-overview-cpp11.inc>
///	@endcond

///	@cond LBAL_INTERNAL
#include <lucenaBAL/details/fragments/lbalFeatureSetup-overview-cpp14.inc>
///	@endcond

///	@cond LBAL_INTERNAL
#include <lucenaBAL/details/fragments/lbalFeatureSetup-overview-cpp17.inc>
///	@endcond

///	@cond LBAL_INTERNAL
#include <lucenaBAL/details/fragments/lbalFeatureSetup-overview-cpp20.inc>
///	@endcond

///	@cond LBAL_INTERNAL
#include <lucenaBAL/details/fragments/lbalFeatureSetup-overview-cpp23.inc>
///	@endcond

///	@cond LBAL_INTERNAL
#include <lucenaBAL/details/fragments/lbalFeatureSetup-overview-cpp26.inc>
///	@endcond

///	@cond LBAL_INTERNAL
#include <lucenaBAL/details/fragments/lbalFeatureSetup-overview-cpp2d.inc>
///	@endcond

/**
  @name Technical Specifications and Proposals

  @brief C++ Technical Specifications that have not (yet?) been Standardized.

  @details These are typically implemented somewhere, but have not garnered
  enough support to merge into the Standard. If approved, these will eventually
  be aliased—and then moved—into the appropriate Standard section, etc.

  @remarks (SEEME - bitweeder) The TSs can be highly mutable, and support
  should be considered very experimental. No effort at all will be expended to
  maintain backwards-compatibility with a TS once a feature has been voted in;
  it will be deprecated and eventually removed, with the official version
  being gated by an updated token. Relatedly, if a TS is dropped, we will
  immediately deprecate it, hide the token in our published docs, and drop it
  in the next major release.

  @{
*/

///@cond LBAL_INTERNAL
//	APIME These tokens related to the now-dropped
//  [C++2a Contracts proposal](https://wg21.link/p0542r5). The feature was not
//  widely implemented, and since it’s been superseded by C++26 Contracts, the
//  token will be removed in a future release.
#ifndef LBAL_CPPTS_ATTRIBUTE_ASSERT
  #define LBAL_CPPTS_ATTRIBUTE_ASSERT 0
#endif

#ifndef LBAL_CPPTS_ATTRIBUTE_ENSURES
  #define LBAL_CPPTS_ATTRIBUTE_ENSURES 0
#endif

#ifndef LBAL_CPPTS_ATTRIBUTE_EXPECTS
  #define LBAL_CPPTS_ATTRIBUTE_EXPECTS 0
#endif

#ifndef LBAL_CPPTS_CONTRACTS
  #define LBAL_CPPTS_CONTRACTS 0
#endif
///@endcond

///	@}	Technical Specifications and Proposals

/**
  @name LBAL_C99
  Feature availability macros to indicate whether a given C99 feature is
  supported by the current compiler. Each one is set to 1 if available and 0
  otherwise.

  @{
*/

/**
  @def LBAL_C99_PREPROCESSOR
  @remarks (SEEME - bitweeder) Only older versions of MSVS are known to have
  problems with this, despite otherwise conforming to the C++11 Standard. Note
  that if support requires having a particular compiler switch set to get
  compatibility, this token will mirror that condition.
*/
#ifndef LBAL_C99_PREPROCESSOR
  #define LBAL_C99_PREPROCESSOR 0
#endif

///	@}	LBAL_C99

///	@}	lbal_compiler

/**
  @addtogroup lbal_library

  @brief Provides feature detection describing the capabilities of the
  Standard Library implementation

  @details These tokens relate to library features. They are a mix of binary
  availability flags and versioned values describing levels of support. Where
  possible, these mimic the equivalent [SD-6 macros](https://wg21.link/sd6),
  both in their naming and in their ranges of values. A variety of detection
  methods are used, but ultimately if availability of a given feature could
  only be determined by doing something that might cause a compilation error,
  we choose instead to assume the feature is not available. This behavior may
  be overridden by the client by explicitly setting the relevant macro. For
  example, if we’re unable to determine whether there is library support for
  `Complex` literals, we’ll set `LBAL_LIBCPP14_COMPLEX_UDLS` to `0`; however,
  if the client is aware of support, they can manually set it `1` prior to
  our testing, and we will not override this setting unless we explicitly
  determine that it is incorrect.

  Certain `LBAL_LIBCPP*_*` macros have corresponding `LBAL_LIBCPP*_*_EXP`
  macros; these latter macros are only set to a non-zero value if an
  experimental header is being used, which typically happens as a result of a
  given feature being part of a [Technical
  Specification](https://en.cppreference.com/w/cpp/experimental) that has not
  yet been incorporated into the Standard. Note that `LBAL_LIBCPP*_*` and
  `LBAL_LIBCPP*_*_EXP` are mutually exclusive:

  - If a Standard Library implementation ships with both regular and
  experimental versions of a given header, the experimental version will be
  ignored.
  - If both `LBAL_LIBCPP*_*` and `LBAL_LIBCPP*_*_EXP` are user-defined to
  non-zero values, and the Standard header exists, `LBAL_LIBCPP*_*_EXP`
  will be set to `0` and a warning will be generated.
  - If `LBAL_LIBCPP*_*` has been user-set to `0` and `LBAL_LIBCPP*_*_EXP`
  left undefined, `LBAL_LIBCPP*_*_EXP` will also be set to `0`, even if the
  experimental feature in question is available; this is done to prevent
  surprises in the event that a feature was explicitly disabled, and then
  later an experimental version of the same feature is made available. The
  reverse, case, though, is not true; if left undefined, `LBAL_LIBCPP*_*`
  will always be assigned a value based on actual feature detection.

  Finally, note that if either macro is user-set to `0`, its value will not
  be changed, regardless of circumstances.

  @remarks (APIME) As implied above, sometimes it is possible to definitely
  determine that a feature is _not_ available, even if we cannot definitelty
  determine whether it _is_ available. In both cases, we set the
  corresponding token to `0`, but in the latter case the client may override
  us, and in the former we’ll override the override.

  @remarks (SEEME - bitweeder) Note that some of these _also_ require language
  support. We try to note such cases when they arise.

  @remarks (SEEME - bitweeder) It is possible for a feature to be “available”
  on the basis of the presence of its header, SD-6 macro value, etc, but still
  have its token overridden depending on the build environment. An example of
  this is support for `std::filesystem` under macOS (and other Apple OSes):
  while it is part of the C++17 Standard, and Xcode 11.0+ ships with the
  `<filesystem>` header, the feature only works under macOS 10.15+, and as such
  will only be made available if the build is targeting a minimum of macOS
  10.15. This is specifically _not_ a runtime check, but rather happens at
  compile-time.

  @remarks (APIME) There is some ambiguity regarding when we track the
  experimental version of a feature. Generally, we don’t bother if:
  - no major compiler ever shipped an experimental version
  - no major compiler ever shipped an experimental version in a non-preview
  release
  - the experimental version is/was completely broken

  @remarks (SEEME - bitweeder) Some implementations may choose to make a
  feature available to an earlier C++ release than the the first officially
  supported one. This can be done, for example, to make features available from
  a Draft Standard. Generally, we don’t second-guess the implementation if they
  set an SD-6 macro a particular—unless we have good reason to know it was set
  incorrectly. More challenging is dealing with implementations that _don’t_
  have SD-6 macros. Our approach in this case is to identify a feature as
  available if the implementation is known to support it _and_ the Language
  version in use is greater than the last unsupported version; this latter
  condition catches the frequent convention of compilers identifying a future
  unreleased dialect as the last Standard (e.g., 201103L) plus one (e.g.,
  201104L), until the Standard is official and the the version changes (e.g.,
  to 201402L).

  @{
*/

/*
  SEEME (bitweeder) See the above SEEME note on why we have to mask these
  includes from Doxygen.
*/
///	@cond LBAL_INTERNAL
#include <lucenaBAL/details/fragments/lbalFeatureSetup-overview-libcpp14.inc>
///	@endcond

///	@cond LBAL_INTERNAL
#include <lucenaBAL/details/fragments/lbalFeatureSetup-overview-libcpp17.inc>
///	@endcond

///	@cond LBAL_INTERNAL
#include <lucenaBAL/details/fragments/lbalFeatureSetup-overview-libcpp20.inc>
///	@endcond

///	@cond LBAL_INTERNAL
#include <lucenaBAL/details/fragments/lbalFeatureSetup-overview-libcpp23.inc>
///	@endcond

///	@cond LBAL_INTERNAL
#include <lucenaBAL/details/fragments/lbalFeatureSetup-overview-libcpp26.inc>
///	@endcond

///	@cond LBAL_INTERNAL
#include <lucenaBAL/details/fragments/lbalFeatureSetup-overview-libcpp2d.inc>
///	@endcond

/**
  @name LBAL_LIBCPPTS

  @brief C++ Technical Specifications for library features that have not (yet?)
  been Standardized.

  @details These are typically implemented somewhere, but have not garnered
  enough support to merge into the Standard. If approved, these will eventually
  be aliased—and then moved—into the appropriate Standard section, etc.

  @remarks (SEEME - bitweeder) The TSs can be highly mutable, and support
  should be considered very experimental. No effort at all will be expended to
  maintain backwards-compatibility with a TS once a feature has been voted in;
  it will be deprecated and eventually removed, with the official version
  being gated by an updated token. Relatedly, if a TS is dropped, we will
  immediately deprecate it, hide the token in our published docs, and drop it
  in the next major release.

  @{
*/

///	@}	LBAL_LIBCPPTS

///	@}	lbal_library

/**
  @addtogroup lbal_compiler_control

  @brief Provides compiler-agnostic control over compiler diagnostics,
  warnings, and pragmas

  @details Currently, this provides a minimal set of controls geared
  specifically towards allowing the generation of compile-time warnings. This
  section may gain more controls as needs arise.

  @{
*/

/**
  @def LBAL_DIAGNOSTIC_PUSH

  @brief Begin a new diagnostic context

  @details Any diagnostic controls engaged after this call may be reverted to
  their previous settings with a subsequent call to `LBAL_DIAGNOSTIC_POP`.
*/
#ifndef LBAL_DIAGNOSTIC_PUSH
  #define LBAL_DIAGNOSTIC_PUSH
#endif

/**
  @def LBAL_DIAGNOSTIC_POP

  @brief Dispose of the current diagnostic context

  @details This will revert any settings changed by diagnostic controls since
  the last call to `LBAL_DIAGNOSTIC_PUSH`.
*/
#ifndef LBAL_DIAGNOSTIC_POP
  #define LBAL_DIAGNOSTIC_POP
#endif

/**
  @def LBAL_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS

  @brief Disable warning generation if the compiler encounters a `#pragma` it
  doesn’t recognize

  @details Not all compilers expose this functionality, but most do.
*/
#ifndef LBAL_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS
  #define LBAL_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS
#endif

/**
  @def LBAL_PRAGMA(LBAL_PRAGMA_pragma)

  @brief Invoke the specified pragma.

  @details This is mostly for use as an internal macro, as its pragmatic
  use in generic code is profoundly limited.
*/
#ifndef LBAL_PRAGMA
  #define LBAL_PRAGMA(LBAL_PRAGMA_pragma)
#endif

/**
  @def LBAL_CPP_WARNING(LBAL_CPP_WARNING_message)

  @brief Generate a compile-time warning

  @details This is intended to be a cross-platform replacement for the
  C preprocessor `#warning` directive, which is sadly unsupported by most
  compilers that aren’t clang. Notably, warnings generate visible diagnostic
  messages when compiling, but do not halt compilation. Behaviorally, these
  warnings are preprocesor constructs, and are subject to the same
  limitations as `#error`, which are more rigid than those of, for example,
  `static_assert`. In particular, assume there is no macro substitution, and
  that constructs that depend upon compile-time evaluation are unavailable
  (e.g., Standard Library type traits).
*/
#ifndef LBAL_CPP_WARNING
  #define LBAL_CPP_WARNING(LBAL_CPP_WARNING_message)
#endif

///	@}	lbal_compiler_control

/**
  @addtogroup lbal_builtins

  @brief Provides generalized access to compiler intrinsics and built-in
  functions

  @details These are wrappers for intrinsic functions that may not be
  available on every platform. Where a given function is not available, it
  may be emulated, or simply replaced with a no-op.

  @{
*/

/**
  @name LBAL_HINT

  @brief In-line hints to the compiler to guide code optimization

  @details These provide compiler hints used to wrap code statements
  and provide guidance to the compiler regarding intended usage or planned
  consumption patterns. None of these is guaranteed to have any effect; in
  the absence of effect, the statement will simply compile normally.

  @remarks (FIXME - bitweeder) This needs a usage example.

  @{
*/

/**
  @def LBAL_HINT_likely(LBAL_expr_)

  @brief Branch prediction hinting that something is most likely true

  @details `LBAL_expr_` must resolve to a boolean.

  This is roughly equivalent to the C++20 `[[likely]]` attribute, and may
  resolve to it, if it is available.
*/
#ifndef LBAL_HINT_likely
  #define LBAL_HINT_likely(LBAL_expr_) LBAL_expr_
#endif

/**
  @def LBAL_HINT_unlikely(LBAL_expr_)

  @brief Branch prediction hinting that something is most likely false

  @details `LBAL_expr_` must resolve to a boolean.

  This is roughly equivalent to the C++20 `[[unlikely]]` attribute, and may
  resolve to it, if it is available.
*/
#ifndef LBAL_HINT_unlikely
  #define LBAL_HINT_unlikely(LBAL_expr_) LBAL_expr_
#endif

///	@}	LBAL_HINT

///	@}	lbal_builtins

/**
  @addtogroup lbal_decorators

  @brief Provides decorators that may be added to declarations of
  various kinds

  @details These are a collection of compiler- and linker-agnostic
  modifiers that may be used to indicate symbol visibility, calling
  conventions, and usage hints. On platforms where a given decorator has
  no equivalent or has no meaning, it resolves to nothing.

  @{
*/

// clang-format off: Doxygen code example
/**
  @name LBAL_VIS

  @brief Decorators to control symbol visibility in the ABI

  @details These allow explicit control over what gets exported—and
  subsequently imported—by the linker. This task is somewhat complicated by
  different approaches on each platform toward what constitutes the contents of
  a library, e.g., whether inline functions are header-only constructs or
  whether they contribute object code to the library itself. We’ve noted usage
  issues to be aware of, as well as some relevant historical oddities. Note
  that some of these macros should be used conditionally; they should not be
  used to decorate symbols directly, but should instead be used to define
  decorators specific to a given project. Such decorators’ values should be
  dependent upon whether the project is being built or used; when building, set
  the decorator to the `EXPORT` variant of a given macro, but when using the
  build product, set it to the `IMPORT` variant. Macros that do not have
  multiple versions are not context-dependent and can be used directly—or
  used to define a library-specific macro unconditionally.

  If there are multiple declarations of a given symbol, all declarations should
  have the same decorators; in particular, do not leave some declarations
  undecorated. Failing to adhere to this policy will give warnings and possibly
  unpredictable behavior with some compilers.

  Establishing visibility rules for templates is fraught; read all the notes
  carefully before attempting to decorate templates of any kind, including
  classes containing member templates.

  Usage example:
  ```cpp
  #if MY_LIB_CONFIG_buiding
    #define MY_LIB_VIS_CLASS LBAL_VIS_CLASS_EXPORT
    #define MY_LIB_VIS_EXTERN_CLASS_TEMPLATE LBAL_VIS_EXTERN_CLASS_TEMPLATE_EXPORT
    #define MY_LIB_VIS_CLASS_TEMPLATE_INSTANTIATION LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_EXPORT
    #define MY_LIB_VIS_FUNC LBAL_VIS_FUNC_EXPORT
    #define MY_LIB_VIS_OVERLOADABLE_FUNC LBAL_VIS_OVERLOADABLE_FUNC_EXPORT
    #define MY_LIB_VIS_EXCEPTION LBAL_VIS_EXCEPTION_EXPORT
    #define MY_LIB_VIS_EXTERN LBAL_VIS_EXTERN_EXPORT
  #else
    #define MY_LIB_VIS_CLASS LBAL_VIS_CLASS_IMPORT
    #define MY_LIB_VIS_EXTERN_CLASS_TEMPLATE LBAL_VIS_EXTERN_CLASS_TEMPLATE_IMPORT
    #define MY_LIB_VIS_CLASS_TEMPLATE_INSTANTIATION LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_IMPORT
    #define MY_LIB_VIS_FUNC LBAL_VIS_FUNC_IMPORT
    #define MY_LIB_VIS_OVERLOADABLE_FUNC LBAL_VIS_OVERLOADABLE_FUNC_IMPORT
    #define MY_LIB_VIS_EXCEPTION LBAL_VIS_EXCEPTION_IMPORT
    #define MY_LIB_VIS_EXTERN LBAL_VIS_EXTERN_IMPORT
  #endif
  ```

  In this example, `MY_LIB_CONFIG_buiding` is only defined when building the
  binary, and left undefined otherwise. Symbols should be decorated with
  the appropriate `MY_LIB_VIS classifier`, and the compiler will do the right
  thing. Note that it’s only necessary to define macros for decorators that
  have `IMPORT`/`EXPORT` variants; for others (e.g., `LBAL_VIS_ENUM`) the
  unaliased macro can be used - or those may be aliased uniformly aliased as
  well, for API consistency.

  @remarks (SEEME - bitweeder) These have been changed to more closely
  approximate libc++’s usage, mostly because it’s thoughfully designed for use
  with modules and the emerging C++ ABI proposals. Note, however, that many of
  these designations are currently only meaningful as annotations, in
  particular when running compilers that aren’t clang; we’ve tried to note
  those cases. Additionally, some compilers impose unexpected limitations,
  e.g., MSVC will not allow member functions to have different explicitly
  declared visibility than that of the class if the class itself was given an
  explicit visibilitydecorator.

  @remarks (SEEME - bitweeder) Without support from a static analyzer, there’s
  no way to know if a decorator has been misused, e.g., applying
  `LBAL_VIS_FUNC_EXPORT` to a class. Such misuses may not be immediately
  obvious with a given implementation; additionally, misuses that are not
  problematic now may become problematic in the future when compilers gain new
  capabilities. For this reason, it’s strongly advised to test code
  periodically with a good static analyzer—as if you needed another reason.

  @{
*/
// clang-format on

/**
  @def LBAL_VIS_HIDDEN

  @brief General-purpose visibility decorator for hiding symbols

  @details Indicates that the decorated symbol is not exported. If symbols
  are hidden by default, this does not need to be explicitly applied, but
  will not cause problems if it is.
*/
#ifndef LBAL_VIS_HIDDEN
  #define LBAL_VIS_HIDDEN
#endif

/**
  @def LBAL_VIS_ENUM

  @brief Enum symbol visibility decorator

  @details Apply this to [class] enum declarations to mark the symbols for
  the type’s typeinfo as visible.

  @remarks (SEEME - bitweeder) gcc makes enum typeinfo visible by default, and
  then throws up warnings if a visibility attribute conflicts with this; for
  this reason, this macro is a no-op under gcc.
*/
#ifndef LBAL_VIS_ENUM
  #define LBAL_VIS_ENUM
#endif

/**
  @def LBAL_VIS_CLASS_EXPORT

  @brief Class symbol visibility decorator for use at build-time

  @details Apply this to class, struct, and union declarations to mark the
  symbols for the type’s typeinfo, vtable, and members as visible. Do not use
  this with the various flavors of class template, and do not use it if a
  class contains member template classes; instead, use
  `LBAL_VIS_CLASS_TEMPLATE_EXPORT`.
*/
#ifndef LBAL_VIS_CLASS_EXPORT
  #define LBAL_VIS_CLASS_EXPORT
#endif

/**
  @def LBAL_VIS_CLASS_IMPORT

  @brief Class symbol visibility decorator for use at link-time

  @details Apply this to class, struct, and union declarations to mark the
  symbols for the type’s typeinfo, vtable, and members as visible. Do not use
  this with the various flavors of class template, and do not use it if a
  class contains member template classes; instead, use
  `LBAL_VIS_CLASS_TEMPLATE_IMPORT`.
*/
#ifndef LBAL_VIS_CLASS_IMPORT
  #define LBAL_VIS_CLASS_IMPORT
#endif

/**
  @def LBAL_VIS_CLASS_TEMPLATE

  @brief Class template symbol visibility decorator

  @details Apply this to class template declarations to mark the symbols for
  the type’s typeinfo and vtable as visible; members are unaffected. Do not
  use this with classes that are not templates; instead, use the appropriate
  `LBAL_VIS_CLASS_EXPORT`/`LBAL_VIS_CLASS_IMPORT` decorator.

  @remarks (SEEME - bitweeder) This only works as described under clang. Under
  gcc, there is currently no `__type_visibility__` attribute, so we fall back
  to using `__visibility__`, which means members inherit the class visibility.
  For this reason, class template members should have explicit decorators, in
  particular if visibility is supposed to differ from that of the class itself.
  MSVC has a similar issue, except that since class templates can’t have
  visibility decorators, the macro is a no-op; once again, members require
  explicit visibility decorators, but now they’re required for every member
  with visibility different from the translation unit default. Failing to
  adhere to this policy may result in exposing too many symbols or not enough
  symbols, depending on the compiler and the compiler options.
*/
#ifndef LBAL_VIS_CLASS_TEMPLATE
  #define LBAL_VIS_CLASS_TEMPLATE
#endif

/**
  @def LBAL_VIS_EXTERN_CLASS_TEMPLATE_EXPORT

  @brief Extern class template symbol visibility decorator for use at
  build-time

  @details Apply this to all extern class template declarations to mark the
  symbols for the type’s typeinfo, vtable, and member functions as visible.
  Do not use this with regular class template declarations; use
  `LBAL_VIS_CLASS_TEMPLATE` for those. This is intended specifically to
  override a `LBAL_VIS_CLASS_TEMPLATE` decorator on the primary template and
  explicitly export the member functions of its explicit instantiations. Note
  that there is a complementary decorator pair,
  `LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_EXPORT`\
  `LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_IMPORT`, which must be used on the
  actual template instantiations.
*/
#ifndef LBAL_VIS_EXTERN_CLASS_TEMPLATE_EXPORT
  #define LBAL_VIS_EXTERN_CLASS_TEMPLATE_EXPORT
#endif

/**
  @def LBAL_VIS_EXTERN_CLASS_TEMPLATE_IMPORT

  @brief Extern class template symbol visibility decorator for use at
  link-time

  @details Apply this to all extern class template declarations to mark the
  symbols for the type’s typeinfo, vtable, and member functions as visible.
  Do not use this with regular class template declarations; use
  `LBAL_VIS_CLASS_TEMPLATE` for those. This is intended specifically to
  override a `LBAL_VIS_CLASS_TEMPLATE` decorator on the primary template and
  explicitly export the member functions of its explicit instantiations. Note
  that there is a complementary decorator pair,
  `LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_EXPORT`\
  `LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_IMPORT`, which must be used on the
  actual template instantiations.
*/
#ifndef LBAL_VIS_EXTERN_CLASS_TEMPLATE_IMPORT
  #define LBAL_VIS_EXTERN_CLASS_TEMPLATE_IMPORT
#endif

/**
  @def LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_EXPORT

  @brief Class template instantiation symbol visibility decorator for use at
  build-time

  @details Apply this to all explicit instantiations of class templates to
  mark the symbols for the type’s typeinfo, vtable, and member functions as
  visible. While `LBAL_VIS_EXTERN_CLASS_TEMPLATE_EXPORT` is intended for use
  in headers, this complementary decorator is primarily used in source files.
  The former can be seen as a decorator for the general definition of a given
  template, while this is for specific instances of it.
*/
#ifndef LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_EXPORT
  #define LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_EXPORT
#endif

/**
  @def LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_IMPORT

  @brief Class template instantiation symbol visibility decorator for use at
  link-time

  @details Apply this to all explicit instantiations of class templates to
  mark the symbols for the type’s typeinfo, vtable, and member functions as
  visible. While `LBAL_VIS_EXTERN_CLASS_TEMPLATE_IMPORT` is intended for use
  in headers, this complementary decorator is primarily used in source files.
  The former can be seen as a decorator for the general definition of a given
  template, while this is for specific instances of it.
*/
#ifndef LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_IMPORT
  #define LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_IMPORT
#endif

/**
  @def LBAL_VIS_MEMBER_CLASS_TEMPLATE

  @brief Member class template symbol visibility decorator

  @details Apply this to all member class templates of all:
  - classes decorated with `LBAL_VIS_CLASS_EXPORT`/`LBAL_VIS_CLASS_IMPORT`
  - class templates decorated with `LBAL_VIS_EXTERN_CLASS_TEMPLATE_EXPORT`/
  `LBAL_VIS_EXTERN_CLASS_TEMPLATE_IMPORT`

  This will hide symbols generated by implicit instantiations of the
  member class template, preventing spurious symbol exports should
  such instantiations occur in some other library which links to this
  one. Explicit instantiations should be handled normally via
  `LBAL_VIS_EXTERN_CLASS_TEMPLATE_EXPORT`/
  `LBAL_VIS_EXTERN_CLASS_TEMPLATE_IMPORT`.
*/
#ifndef LBAL_VIS_MEMBER_CLASS_TEMPLATE
  #define LBAL_VIS_MEMBER_CLASS_TEMPLATE
#endif

/**
  @def LBAL_VIS_MEMBER_FUNCTION_TEMPLATE

  @brief Member function template symbol visibility decorator

  @details Apply this to member function templates of:
  - classes decorated with `LBAL_VIS_CLASS_EXPORT`/`LBAL_VIS_CLASS_IMPORT`
  - class templates decorated with `LBAL_VIS_EXTERN_CLASS_TEMPLATE_EXPORT`/
  `LBAL_VIS_EXTERN_CLASS_TEMPLATE_IMPORT`

  This will hide symbols generated by implicit instantiations of the
  member function template, preventing spurious symbol exports should
  such instantiations occur in some other library which links to this
  one. Note that if a function template is already decorated with
  `LBAL_VIS_INLINE_FUNC` or `LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC`, this
  decorator should not be applied. Similarly, explicit instantiations
  should be decorated normally with either `LBAL_VIS_INLINE_FUNC` or
  `LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC`, as appropriate.
*/
#ifndef LBAL_VIS_MEMBER_FUNCTION_TEMPLATE
  #define LBAL_VIS_MEMBER_FUNCTION_TEMPLATE
#endif

/**
  @def LBAL_VIS_FUNC_EXPORT

  @brief Function symbol visibility decorator for use at build-time

  @details Apply this to declarations of visible functions that are defined
  in the library binary, i.e., not inline functions, function templates, or
  (usually) class template member functions.
*/
#ifndef LBAL_VIS_FUNC_EXPORT
  #define LBAL_VIS_FUNC_EXPORT
#endif

/**
  @def LBAL_VIS_FUNC_IMPORT

  @brief Function symbol visibility decorator for use at link-time

  @details Apply this to declarations of visible functions that are defined
  in the library binary, i.e., not inline functions, function templates, or
  (usually) class template member functions.
*/
#ifndef LBAL_VIS_FUNC_IMPORT
  #define LBAL_VIS_FUNC_IMPORT
#endif

/**
  @def LBAL_VIS_INLINE_FUNC
  Do not export the symbol, and guarantee that it will not be subject to
  incorrect de-duping when two incompatible functions with the same symbol
  are linked into the same binary, e.g., in a situation where two different
  versions of the same library end up linked into one app. This can occur
  with inline functions when the linker writes a fallback copy to a library
  and the fallback is used instead of generating new object code from the
  header. This decorator can be used with all inline functions, except inline
  member functions of extern templates.

  @remarks (SEEME - bitweeder) “inline” in this context means, literally,
  “defined in the header”, and not necessarily just “functions explicitly
  declared `inline`”. libc++ names their equivalent macro
  `_LIBCPP_HIDE_FROM_ABI`, describing what it does, insted of how it’s used. In
  this case, though, the “how it’s used” may be confusing because of the
  `INLINE` part of the name, which may cause users to apply it too narrowly. On
  the other hand, `HIDE_FROM_ABI` is basically what `LBAL_VIS_HIDDEN` does, so
  going the other way would also be confusing. We’re currently going this route
  and relying on documentation to provide clarity.

  @remarks (APIME) Because of the brittle usage requirements,
  `LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC` may just end up getting removed,
  with `LBAL_VIS_INLINE_FUNC` inheriting its implementation.
*/
#ifndef LBAL_VIS_INLINE_FUNC
  #define LBAL_VIS_INLINE_FUNC
#endif

/**
  @def LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC
  This behaves identically to `LBAL_VIS_INLINE_FUNC` except that it’s for
  member functions of extern templates that have been declared `inline` but
  are defined out-of-line. This unfortunately specific decorator is needed
  because of differences in how different compilers handle visibility in this
  situation.

  @remarks (SEEME - bitweeder) Note that we could eliminate this macro entirely
  by folding its extra handling into `LBAL_VIS_INLINE_FUNC`, but this would be
  at the cost of some symbol table bloat on certain compilers. This means that
  a given project could choose to alias their own general-purpose inline
  visibility decorator macro to this and just use it for all inline function
  decorations.
*/
#ifndef LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC
  #define LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC
#endif

/**
  @def LBAL_VIS_OVERLOADABLE_FUNC_EXPORT

  @brief Overloadable function symbol visibility decorator for use at
  build-time

  @details Apply this to declarations of visible free functions that are
  defined in the library binary but that allow user-supplied overloads.

  @remarks (SEEME - bitweeder) Pragmatically, this sort of customization point
  is a bad idea. That aside, in practice, this separate designation for
  `LBAL_VIS_FUNC_EXPORT` is only needed by Windows due to how DLLs are handled:
  namely, a function marked with `dllimport` cannot be overloaded locally.

  @remarks (FIXME - bitweeder) Our method for handling this derives from how
  libc++ does it: they simply don’t decorate the function declaration for
  import. The method has not been tested, and I haven’t seen examples in the
  wild of other people using it.
*/
#ifndef LBAL_VIS_OVERLOADABLE_FUNC_EXPORT
  #define LBAL_VIS_OVERLOADABLE_FUNC_EXPORT
#endif

/**
  @def LBAL_VIS_OVERLOADABLE_FUNC_IMPORT

  @brief Overloadable function symbol visibility decorator for use at
  link-time

  @details Apply this to declarations of visible free functions that are
  defined in the library binary but that allow user-supplied overloads.

  @remarks (SEEME - bitweeder) Pragmatically, this sort of customization point
  is a bad idea. That aside, in practice, this separate designation for
  `LBAL_VIS_FUNC_IMPORT` is only needed by Windows due to how DLLs are handled:
  namely, a function marked with `dllimport` cannot be overloaded locally.

  @remarks (FIXME - bitweeder) Our method for handling this derives from how
  libc++ does it: they simply don’t decorate the function declaration for
  import. The method has not been tested, and I haven’t seen examples in the
  wild of other people using it.
*/
#ifndef LBAL_VIS_OVERLOADABLE_FUNC_IMPORT
  #define LBAL_VIS_OVERLOADABLE_FUNC_IMPORT
#endif

/**
  @def LBAL_VIS_EXTERN_EXPORT

  @brief General-purpose extern symbol visibility decorator for use at
  build-time

  @details Apply this to symbols marked `extern` that are required to be
  visible. Objects that are not explicitly `extern` do not need this. Note
  that this does not take the place of the `extern` decorator, but rather
  supplements it.
*/
#ifndef LBAL_VIS_EXTERN_EXPORT
  #define LBAL_VIS_EXTERN_EXPORT
#endif

/**
  @def LBAL_VIS_EXTERN_IMPORT

  @brief General-purpose extern symbol visibility decorator for use at
  link-time

  @details Apply this to symbols marked `extern` that are required to be
  visible. Objects that are not explicitly `extern` do not need this. Note
  that this does not take the place of the `extern` decorator, but rather
  supplements it.
*/
#ifndef LBAL_VIS_EXTERN_IMPORT
  #define LBAL_VIS_EXTERN_IMPORT
#endif

/**
  @def LBAL_VIS_EXCEPTION_EXPORT

  @brief Exception class symbol visibility decorator for use at build-time

  @details Apply this to exception declarations to mark the symbols for the
  type’s typeinfo, vtable, and members as visible. In practice, this behaves
  identically to `LBAL_VIS_CLASS_EXPORT`, but different annotations may apply
  for static analysis purposes.
*/
#ifndef LBAL_VIS_EXCEPTION_EXPORT
  #define LBAL_VIS_EXCEPTION_EXPORT
#endif

/**
  @def LBAL_VIS_EXCEPTION_IMPORT

  @brief Exception class symbol visibility decorator for use at link-time

  @details Apply this to exception declarations to mark the symbols for the
  type’s typeinfo, vtable, and members as visible. In practice, this behaves
  identically to `LBAL_VIS_CLASS_IMPORT`, but different annotations may apply
  for static analysis purposes.
*/
#ifndef LBAL_VIS_EXCEPTION_IMPORT
  #define LBAL_VIS_EXCEPTION_IMPORT
#endif

///	@}	LBAL_VIS

/**
  @name LBAL_CLASS
  These tokens describe class decorators whose details are
  implementation-specific.

  @{
*/

/**
  @def LBAL_CLASS_FORCE_EBCO
  Force the use of the Empty Base [Class] Optimization (EBCO). The decorator
  should precede the class name in its declaration. Note that this is used
  specifically to indicate that the bases of a given class are empty, not
  that a given class is an Empty Base Class; this means it must be applied by
  the end user in a large number of practical use cases. Also note that the
  decorator must be applied in the most direct descendant to have effect. For
  example:

    struct Empty1 { };
    struct Empty2 { };
    struct Derived1 : Empty1, Empty2 { };
    struct LBAL_CLASS_FORCE_EBCO Derived2 : Derived 1 { };

  In this example, neither `Derived1` _nor_ `Derived2` will necessarily
  benefit from the EBCO; we can’t guarantee the behavior. However, if
  `Derived1` _also_ has the `LBAL_CLASS_FORCE_EBCO` decorator applied, then
  any compiler that supports the EBCO will apply it to both `Derived1` _and_
  `Derived2`.

  @remarks (SEEME - bitweeder) This is really only necessary when using
  multiple inheritance and targeting MSVS; at least VS2015 Update 3 is required
  (note that Update 2, which actually introduced the feature, had a bug which
  caused it to violate the Standard).

  @remarks (APIME) How aggravating is it that you can’t decorate the empty
  base class itself instead of having to force a weird requirement onto
  derived classes? Sadly, we’re at the mercy of the built-in compiler
  decorators, here.
*/
#ifndef LBAL_CLASS_FORCE_EBCO
  #define LBAL_CLASS_FORCE_EBCO
#endif

///	@}	LBAL_CLASS

/**
  @name LBAL_FUNC
  These macros describe function calling conventions whose details are
  implementation-specific.

  @{
*/

/**
  @def LBAL_FUNC_CALL_C(LBAL_func_name_)
  C calling convention; default
*/
#ifndef LBAL_FUNC_CALL_C
  #define LBAL_FUNC_CALL_C(LBAL_func_name_)
#endif

/**
  @def LBAL_FUNC_CALL_STD(LBAL_func_name_)
  Std calling convention
*/
#ifndef LBAL_FUNC_CALL_STD
  #define LBAL_FUNC_CALL_STD(LBAL_func_name_)
#endif

/**
  @def LBAL_FUNC_CALLBACK_C(LBAL_func_name_)
  C-style function pointer
*/
#ifndef LBAL_FUNC_CALLBACK_C
  #define LBAL_FUNC_CALLBACK_C(LBAL_func_name_)
#endif

/**
  @def LBAL_FUNC_CALLBACK_STD(LBAL_func_name_)
  Std-style function pointer
*/
#ifndef LBAL_FUNC_CALLBACK_STD
  #define LBAL_FUNC_CALLBACK_STD(LBAL_func_name_)
#endif

///	@}	LBAL_FUNC

///	@}	lbal_decorators
