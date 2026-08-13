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

/**
  @name LBAL_CPP03
  These are here only because compilers can be made to disable specific
  features for various reasons and we want to have a universal way of
  determining whether that’s happened.

  @{
*/

/**
  @def LBAL_CPP03_EXCEPTIONS
  @brief Language-level support for C++ Exceptions
  @details This can be conditionally disabled at build-time, so we can’t rely on
  a language version test to detect it.

  SD-6 equivalent: `__cpp_exceptions >= 199711L`. This token will have a value
  of `0` if the proposal described here is not supported.
  - `199711L` [N1146](https://wg21.link/N1146) C++98 Final Working Draft
*/
#ifndef LBAL_CPP03_EXCEPTIONS
  #define LBAL_CPP03_EXCEPTIONS 0
#endif

/**
  @def LBAL_CPP03_RTTI
  @brief Language-level support for run-time type identification (RTTI)
  @details This can be conditionally disabled at build-time, so we can’t rely on
  a language version test to detect it.

  SD-6 equivalent: `__cpp_rtti >= 199711L`. This token will have a value of `0`
  if the proposal described here is not supported.
  - `199711L` [N1146](https://wg21.link/N1146) C++98 Final Working Draft
*/
#ifndef LBAL_CPP03_RTTI
  #define LBAL_CPP03_RTTI 0
#endif

///	@}	LBAL_CPP03

/**
  @name LBAL_CPP11
  All supported compilers support all required features of C++11. However,
  @ref LBAL_CPP11_THREADSAFE_STATIC_INIT "thread-safe static initialization"
  can be explicitly disabled in some implementations, and
  @ref LBAL_CPP11_MINIMAL_GARBAGE_COLLECTION "garbage collection" was an
  optional feature from C++11 until C++23, when it was removed. The rest of
  these are supplied to allow testing for specific features when using older
  language dialects, unsupported compilers, or when general language version
  detection is unavailable.

  @remarks This is not an exhaustive list of C++11 language features. Rather,
  it is currently mostly a collection of those with SD-6 macros. The feature
  checks themselves are not necessarily tested on the minimal-supported
  compiler versions, as we will often rely on external reporting or make
  assumptions based on what `__cplusplus` returns, which is not the case for
  more recent features.

  @{
*/

/**
  @def LBAL_CPP11_ALIAS_TEMPLATES
  @brief Allow type aliases to be templated.
  @details SD-6 equivalent: `__cpp_alias_templates >= 200704L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `200704L` [N2258 __PDF__](https://wg21.link/N2258) Templates Aliases
*/
#ifndef LBAL_CPP11_ALIAS_TEMPLATES
  #define LBAL_CPP11_ALIAS_TEMPLATES 0
#endif

/**
  @def LBAL_CPP11_ATTRIBUTES
  @brief Formalize attributes as a language feature.
  @details SD-6 equivalent: `__cpp_attributes >= 200809L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `200809L` [N2761 __PDF__](https://wg21.link/N2761) Towards support for
  attributes in C++ (Revision 6)
*/
#ifndef LBAL_CPP11_ATTRIBUTES
  #define LBAL_CPP11_ATTRIBUTES 0
#endif

/**
  @def LBAL_CPP11_ATTRIBUTE_CARRIES_DEPENDENCY
  @brief Optimization hint when compiling with certain memory models
  @details SD-6 equivalent: `__has_cpp_attribute(carries_dependency) >=
  200809L`. This token will have a value of `0` if the proposal described here
  is not supported.
  - `200809L` [N2782 __PDF__](https://wg21.link/N2782) C++ Data-Dependency
  Ordering: Function Annotation
*/
#ifndef LBAL_CPP11_ATTRIBUTE_CARRIES_DEPENDENCY
  #define LBAL_CPP11_ATTRIBUTE_CARRIES_DEPENDENCY 0
#endif

/**
  @def LBAL_CPP11_ATTRIBUTE_NORETURN
  @brief Indicate that a function does not return
  @details SD-6 equivalent: `__has_cpp_attribute(noreturn) >= 200809L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `200809L` [N2761 __PDF__](https://wg21.link/N2761) Towards support for
  attributes in C++ (Revision 6)
*/
#ifndef LBAL_CPP11_ATTRIBUTE_NORETURN
  #define LBAL_CPP11_ATTRIBUTE_NORETURN 0
#endif

/**
  @def LBAL_CPP11_CONSTEXPR
  @brief Specify generalized constant expressions
  @details SD-6 equivalent: `__cpp_constexpr >= 200704L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `200704L` [N2235 __PDF__](https://wg21.link/N2235) Generalized Constant
  Expressions—Revision 5
*/
#ifndef LBAL_CPP11_CONSTEXPR
  #define LBAL_CPP11_CONSTEXPR 0
#endif

/**
  @def LBAL_CPP11_DECLTYPE
  @brief Query the type of an expression
  @details SD-6 equivalent: `__cpp_decltype >= 200707L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `200707L` [N2343 __PDF__](https://wg21.link/N2343) Decltype (revision 7):
  proposed wording
*/
#ifndef LBAL_CPP11_DECLTYPE
  #define LBAL_CPP11_DECLTYPE 0
#endif

/**
  @def LBAL_CPP11_DELEGATING_CONSTRUCTORS
  @brief Delegating constructors
  @details SD-6 equivalent: `__cpp_delegating_constructors >= 200604L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `200604L` [N1986 __PDF__](https://wg21.link/N1986) Delegating Constructors
  (revision 3)
*/
#ifndef LBAL_CPP11_DELEGATING_CONSTRUCTORS
  #define LBAL_CPP11_DELEGATING_CONSTRUCTORS 0
#endif

/**
  @def LBAL_CPP11_INHERITING_CONSTRUCTORS
  @brief Inheriting Constructors
  @details SD-6 equivalent: `__cpp_inheriting_constructors >= 200802L`. Note
  that `__cpp_inheriting_constructors` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `200802L` [N2540](https://wg21.link/N2540) Inheriting Constructors (revision
  5)
*/
#ifndef LBAL_CPP11_INHERITING_CONSTRUCTORS
  #define LBAL_CPP11_INHERITING_CONSTRUCTORS 0
#endif

/**
  @def LBAL_CPP11_INITIALIZER_LISTS
  @brief Initializer lists
  @details SD-6 equivalent: `__cpp_initializer_lists >= 200806L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `200806L` [N2672](https://wg21.link/N2672) Initializer List proposed wording
*/
#ifndef LBAL_CPP11_INITIALIZER_LISTS
  #define LBAL_CPP11_INITIALIZER_LISTS 0
#endif

/**
  @def LBAL_CPP11_LAMBDAS
  @brief Support for Lambda functions
  @details SD-6 equivalent: `__cpp_lambdas >= 200907L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `200907L` [N2927 __PDF__](https://wg21.link/N2927) New wording for C++0x
  Lambdas (rev. 2)
*/
#ifndef LBAL_CPP11_LAMBDAS
  #define LBAL_CPP11_LAMBDAS 0
#endif

/**
  @def LBAL_CPP11_MINIMAL_GARBAGE_COLLECTION
  @brief Support for optional C++ garbage collection.
*/
#ifndef LBAL_CPP11_MINIMAL_GARBAGE_COLLECTION
  #define LBAL_CPP11_MINIMAL_GARBAGE_COLLECTION 0
#endif

/**
  @def LBAL_CPP11_NSDMI
  @brief Support for non-static data member initializers.
  @details SD-6 equivalent: `__cpp_nsdmi >= 200809L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `200809L` [N2756](https://wg21.link/N2756) Non-static data member
  initializers
*/
#ifndef LBAL_CPP11_NSDMI
  #define LBAL_CPP11_NSDMI 0
#endif

/**
  @def LBAL_CPP11_RANGE_BASED_FOR
  @brief Range-based for-loops
  @details SD-6 equivalent: `__cpp_range_based_for >= 200907L`. Note that
  `__cpp_range_based_for` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `200907L` [N2930](https://wg21.link/N2930) Range-Based For Loop Wording
  (Without Concepts)
*/
#ifndef LBAL_CPP11_RANGE_BASED_FOR
  #define LBAL_CPP11_RANGE_BASED_FOR 0
#endif

/**
  @def LBAL_CPP11_RAW_STRINGS
  @brief Support for raw string literals
  @details SD-6 equivalent: `__cpp_raw_strings >= 200710L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `200710L` [N2442](https://wg21.link/N2442) Raw and Unicode String Literals;
  Unified Proposal (Rev. 2)
*/
#ifndef LBAL_CPP11_RAW_STRINGS
  #define LBAL_CPP11_RAW_STRINGS 0
#endif

/**
  @def LBAL_CPP11_REF_QUALIFIERS
  @brief Extend move semantics to *this
  @details SD-6 equivalent: `__cpp_ref_qualifiers >= 200710L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `200710L` [N2439](https://wg21.link/N2439) Extending move semantics to *this
  (revised wording)
*/
#ifndef LBAL_CPP11_REF_QUALIFIERS
  #define LBAL_CPP11_REF_QUALIFIERS 0
#endif

/**
  @def LBAL_CPP11_RVALUE_REFERENCES
  @brief Add rvalue references
  @details SD-6 equivalent: `__cpp_rvalue_references >= 200610L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `200610L` [N2118](https://wg21.link/N2118) A Proposal to Add an Rvalue
  Reference to the C++ Language: Proposed Wording: Revision 3
*/
#ifndef LBAL_CPP11_RVALUE_REFERENCES
  #define LBAL_CPP11_RVALUE_REFERENCES 0
#endif

/**
  @def LBAL_CPP11_STATIC_ASSERT
  @brief Add static assertions
  @details SD-6 equivalent: `__cpp_static_assert >= 200410L`. Note that
  `__cpp_static_assert` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `200410L` [N1720](https://wg21.link/N1720) Proposal to Add Static Assertions
  to the Core Language (Revision 3)
*/
#ifndef LBAL_CPP11_STATIC_ASSERT
  #define LBAL_CPP11_STATIC_ASSERT 0
#endif

/**
  @def LBAL_CPP11_THREADSAFE_STATIC_INIT
  @brief Support for thread-safe static initialization.
  @details Some compilers can disable this feature if asked; the token will be
  set to `0` if that has happened.

  SD-6 equivalent: `__cpp_threadsafe_static_init >= 200806L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `200806L` [N2660](https://wg21.link/N2660) Dynamic Initialization and
  Destruction with Concurrency
*/
#ifndef LBAL_CPP11_THREADSAFE_STATIC_INIT
  #define LBAL_CPP11_THREADSAFE_STATIC_INIT 0
#endif

/**
  @def LBAL_CPP11_UNICODE_CHARACTERS
  @brief Add `char16_t` and `char32_t` with requisite Unicode encoding
  @details SD-6 equivalent: `__cpp_unicode_characters >= 200704L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `200704L` [N2249](https://wg21.link/N2249) New Character Types in C++
*/
#ifndef LBAL_CPP11_UNICODE_CHARACTERS
  #define LBAL_CPP11_UNICODE_CHARACTERS 0
#endif

/**
  @def LBAL_CPP11_UNICODE_LITERALS
  @brief Support for Unicode string literals
  @details SD-6 equivalent: `__cpp_unicode_literals >= 200710L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `200710L` [N2442](https://wg21.link/N2442) Raw and Unicode String Literals;
  Unified Proposal (Rev. 2)
*/
#ifndef LBAL_CPP11_UNICODE_LITERALS
  #define LBAL_CPP11_UNICODE_LITERALS 0
#endif

/**
  @def LBAL_CPP11_USER_DEFINED_LITERALS
  @brief Support for user-defined literals
  @details SD-6 equivalent: `__cpp_user_defined_literals >= 200809L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `200809L` [N2765 __PDF__](https://wg21.link/N2765) User-defined Literals
  (aka. Extensible Literals (revision 5))
*/
#ifndef LBAL_CPP11_USER_DEFINED_LITERALS
  #define LBAL_CPP11_USER_DEFINED_LITERALS 0
#endif

/**
  @def LBAL_CPP11_VARIADIC_TEMPLATES
  @brief Support for templates with variable numbers of arguments
  @details SD-6 equivalent: `__cpp_variadic_templates >= 200704L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `200704L` [N2242 __PDF__](https://wg21.link/N2242) Proposed Wording for
  Variadic Templates (Revision 2)
*/
#ifndef LBAL_CPP11_VARIADIC_TEMPLATES
  #define LBAL_CPP11_VARIADIC_TEMPLATES 0
#endif

///	@}	LBAL_CPP11

/**
  @name LBAL_CPP14
  All supported compilers support all features of C++14, but some of them may
  require that @ref LBAL_CPP14_SIZED_DEALLOCATION "sized deallocation" be
  explicitly enabled.

  @{
*/

/**
  @def LBAL_CPP14_AGGREGATE_NSDMI
  @brief Relax the requirements on aggregates and specify aggregate member
  initialization
  @details SD-6 equivalent: `__cpp_aggregate_nsdmi >= 201304L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3653](https://wg21.link/N3653) Member initializers and
  aggregates
*/
#ifndef LBAL_CPP14_AGGREGATE_NSDMI
  #define LBAL_CPP14_AGGREGATE_NSDMI 0
#endif

/**
  @def LBAL_CPP14_ATTRIBUTE_DEPRECATED
  @brief Support for marking symbols as deprecated
  @details SD-6 equivalent: `__has_cpp_attribute(deprecated) >= 201309L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201309L` [N3760](https://wg21.link/N3760) [[deprecated]] attribute
*/
#ifndef LBAL_CPP14_ATTRIBUTE_DEPRECATED
  #define LBAL_CPP14_ATTRIBUTE_DEPRECATED 0
#endif

/**
  @def LBAL_CPP14_BINARY_LITERALS
  @brief Add binary literal support.
  @details SD-6 equivalent: `__cpp_binary_literals >= 201304L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3472 __PDF__](https://wg21.link/N3472) Binary Literals in the C+
  + Core Language
*/
#ifndef LBAL_CPP14_BINARY_LITERALS
  #define LBAL_CPP14_BINARY_LITERALS 0
#endif

/**
  @def LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS
  @brief Relax constraints on `constexpr` functions, `constexpr` member
  functions and implicit `const`
  @details SD-6 equivalent: `__cpp_constexpr >= 201304L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201304L` [N3652](https://wg21.link/N3652) Relaxing constraints on constexpr
  functions / constexpr member functions and implicit const
*/
#ifndef LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS
  #define LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS 0
#endif

/**
  @def LBAL_CPP14_DECLTYPE_AUTO
  @brief Allow deduced return types and `decltype (auto)`
  @details SD-6 equivalent: `__cpp_decltype_auto >= 201304L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3638](https://wg21.link/N3638) Return type deduction for normal
  functions
*/
#ifndef LBAL_CPP14_DECLTYPE_AUTO
  #define LBAL_CPP14_DECLTYPE_AUTO 0
#endif

/**
  @def LBAL_CPP14_GENERIC_LAMBDAS
  @brief Generic (Polymorphic) Lambda Expressions
  @details SD-6 equivalent: `__cpp_generic_lambdas >= 201304L`. Note that
  `__cpp_generic_lambdas` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201304L` [N3649](https://wg21.link/N3649) Generic (Polymorphic) Lambda
  Expressions (Revision 3)
*/
#ifndef LBAL_CPP14_GENERIC_LAMBDAS
  #define LBAL_CPP14_GENERIC_LAMBDAS 0
#endif

/**
  @def LBAL_CPP14_INIT_CAPTURES
  @brief Generalized Lambda-capture changes
  @details SD-6 equivalent: `__cpp_init_captures >= 201304L`. Note that
  `__cpp_init_captures` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201304L` [N3648](https://wg21.link/N3648) Wording Changes for Generalized
  Lambda-capture
*/
#ifndef LBAL_CPP14_INIT_CAPTURES
  #define LBAL_CPP14_INIT_CAPTURES 0
#endif

/**
  @def LBAL_CPP14_RETURN_TYPE_DEDUCTION
  @brief Support for return type deduction for normal functions
  @details SD-6 equivalent: `__cpp_return_type_deduction >= 201304L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3638](https://wg21.link/N3638) Return type deduction for normal
  functions
*/
#ifndef LBAL_CPP14_RETURN_TYPE_DEDUCTION
  #define LBAL_CPP14_RETURN_TYPE_DEDUCTION 0
#endif

/**
  @def LBAL_CPP14_SIZED_DEALLOCATION
  @brief Make available a global `operator delete` that takes a size argument
  @details SD-6 equivalent: `__cpp_sized_deallocation >= 201309L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201309L` [N3778](https://wg21.link/N3778) C++ Sized Deallocation

  @remark Some compilers disable this by default since it’s an ABI-breaking
  change; clang, in particular, does this.
*/
#ifndef LBAL_CPP14_SIZED_DEALLOCATION
  #define LBAL_CPP14_SIZED_DEALLOCATION 0
#endif

/**
  @def LBAL_CPP14_VARIABLE_TEMPLATES
  @brief Support for variable templates
  @details SD-6 equivalent: `__cpp_variable_templates >= 201304L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3651 __PDF__](https://wg21.link/N3651) Variable Templates
  (Revision 1)
*/
#ifndef LBAL_CPP14_VARIABLE_TEMPLATES
  #define LBAL_CPP14_VARIABLE_TEMPLATES 0
#endif

///	@}	LBAL_CPP14

/**
  @name LBAL_CPP17
  All supported compilers support all language features of C++17, but some of
  them may require that
  @ref LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS "template template arguments" be
  explicitly enabled.

  @{
*/

/**
  @def LBAL_CPP17_AGGREGATE_BASES
  @brief Relax the restrictions on aggregate initialization.
  @details SD-6 equivalent: `__cpp_aggregate_bases >= 201603L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201603L` [P0017R1](https://wg21.link/P0017R1) Extension to aggregate
  initialization
*/
#ifndef LBAL_CPP17_AGGREGATE_BASES
  #define LBAL_CPP17_AGGREGATE_BASES 0
#endif

/**
  @def LBAL_CPP17_ALIGNED_NEW
  @brief Specify handling of dynamic memory allocation for over-aligned data.
  @details SD-6 equivalent: `__cpp_aligned_new >= 201606L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `201606L` [P0035R4](https://wg21.link/P0035R4) Dynamic memory allocation for
  over-aligned data
*/
#ifndef LBAL_CPP17_ALIGNED_NEW
  #define LBAL_CPP17_ALIGNED_NEW 0
#endif

/**
  @def LBAL_CPP17_ATTRIBUTE_FALLTHROUGH
  @brief Indicate that a case within a switch statements falls through
  @details SD-6 equivalent: `__has_cpp_attribute(fallthrough) >= 201603L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201603L` [P0188R1 __PDF__](https://wg21.link/P0188R1) Wording for
  [[fallthrough]] attribute
*/
#ifndef LBAL_CPP17_ATTRIBUTE_FALLTHROUGH
  #define LBAL_CPP17_ATTRIBUTE_FALLTHROUGH 0
#endif

/**
  @def LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED
  @brief Indicate that a name or entity is possibly intentionally unused
  @details SD-6 equivalent: `__has_cpp_attribute(maybe_unused) >= 201603L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201603L` [P0212R1 __PDF__](https://wg21.link/P0212R1) Wording for
  [[maybe_unused]] attribute
*/
#ifndef LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED
  #define LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED 0
#endif

/**
  @def LBAL_CPP17_ATTRIBUTE_NODISCARD
  @brief Indicate that a function return, class, or enum should not be ignored
  @details SD-6 equivalent: `__has_cpp_attribute(nodiscard) >= 201603L`. Note
  that `__has_cpp_attribute(nodiscard)` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `201603L` [P0189R1 __PDF__](https://wg21.link/P0189R1) Wording for
  [[nodiscard]] attribute
*/
#ifndef LBAL_CPP17_ATTRIBUTE_NODISCARD
  #define LBAL_CPP17_ATTRIBUTE_NODISCARD 0
#endif

/**
  @def LBAL_CPP17_CAPTURE_STAR_THIS
  @brief Allow lambda capture of `*this` by value as `as [=,*this]`.
  @details SD-6 equivalent: `__cpp_capture_star_this >= 201603L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201603L` [P0018R3](https://wg21.link/P0018R3) Lambda Capture of *this by
  Value as [=,*this]
*/
#ifndef LBAL_CPP17_CAPTURE_STAR_THIS
  #define LBAL_CPP17_CAPTURE_STAR_THIS 0
#endif

/**
  @def LBAL_CPP17_CONSTEXPR_LAMBDA
  @brief Allow lambdas to be constexpr explicitly or implicitly
  @details SD-6 equivalent: `__cpp_constexpr >= 201603L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201603L` [P0170R1 __PDF__](https://wg21.link/P0170R1) Wording for Constexpr
  Lambda
*/
#ifndef LBAL_CPP17_CONSTEXPR_LAMBDA
  #define LBAL_CPP17_CONSTEXPR_LAMBDA 0
#endif

/**
  @def LBAL_CPP17_DEDUCTION_GUIDES
  @brief Template argument deduction for class templates
  @details SD-6 equivalent: `__cpp_deduction_guides >= 201606L`. Note that
  `__cpp_deduction_guides` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201606L` [P0091R3](https://wg21.link/P0091R3) Template argument deduction
  for class templates (Rev. 6)
*/
#ifndef LBAL_CPP17_DEDUCTION_GUIDES
  #define LBAL_CPP17_DEDUCTION_GUIDES 0
#endif

/**
  @def LBAL_CPP17_DEDUCTION_GUIDES_DR
  @brief Address additional class template argument deduction issues
  @details SD-6 equivalent: `__cpp_deduction_guides >= 201703L`. Note that
  `__cpp_deduction_guides` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201703L` [P0620R0](https://wg21.link/P0620R0) Drafting for class template
  argument deduction issues
*/
#ifndef LBAL_CPP17_DEDUCTION_GUIDES_DR
  #define LBAL_CPP17_DEDUCTION_GUIDES_DR 0
#endif

/**
  @def LBAL_CPP17_DEDUCTION_GUIDES_NB
  @brief Address issues that came up during C++17 balloting regarding class
  template argument deduction
  @details SD-6 equivalent: `__cpp_deduction_guides >= 201611L`. Note that
  `__cpp_deduction_guides` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201611L` [P0512R0 __PDF__](https://wg21.link/P0512R0) Class Template
  Argument Deduction Assorted NB resolution and issues
*/
#ifndef LBAL_CPP17_DEDUCTION_GUIDES_NB
  #define LBAL_CPP17_DEDUCTION_GUIDES_NB 0
#endif

/**
  @def LBAL_CPP17_ENUMERATOR_ATTRIBUTES
  @brief Attributes for enumerators
  @details SD-6 equivalent: `__cpp_enumerator_attributes >= 201411L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201411L` [N4266](https://wg21.link/N4266) Attributes for namespaces and
  enumerators
*/
#ifndef LBAL_CPP17_ENUMERATOR_ATTRIBUTES
  #define LBAL_CPP17_ENUMERATOR_ATTRIBUTES 0
#endif

/**
  @def LBAL_CPP17_FOLD_EXPRESSIONS
  @brief Allow folding a template parameter pack over a binary operator
  @details SD-6 equivalent: `__cpp_fold_expressions >= 201411L`. Note that
  `__cpp_fold_expressions` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201411L` [N4295](https://wg21.link/N4295) Folding Expressions
*/
#ifndef LBAL_CPP17_FOLD_EXPRESSIONS
  #define LBAL_CPP17_FOLD_EXPRESSIONS 0
#endif

/**
  @def LBAL_CPP17_FOLD_EXPRESSIONS_REVISED
  @brief Add support for unary folds and empty parameter packs to fold
  expressions
  @details SD-6 equivalent: `__cpp_fold_expressions >= 201603L`. Note that
  `__cpp_fold_expressions` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201603L` [P0036R0 __PDF__](https://wg21.link/P0036R0) Unary Folds and Empty
  Parameter Packs (Revision 1)
*/
#ifndef LBAL_CPP17_FOLD_EXPRESSIONS_REVISED
  #define LBAL_CPP17_FOLD_EXPRESSIONS_REVISED 0
#endif

/**
  @def LBAL_CPP17_GUARANTEED_COPY_ELISION
  @brief Guarantee copy and move elision in well-defined situations
  @details SD-6 equivalent: `__cpp_guaranteed_copy_elision >= 201606L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201606L` [P0135R1](https://wg21.link/P0135R1) Wording for guaranteed copy
  elision through simplified value categories
*/
#ifndef LBAL_CPP17_GUARANTEED_COPY_ELISION
  #define LBAL_CPP17_GUARANTEED_COPY_ELISION 0
#endif

/**
  @def LBAL_CPP17_HEX_FLOAT
  @brief Specify Hexadecimal float literals
  @details SD-6 equivalent: `__cpp_hex_float >= 201603L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `201603L` [P0245R1](https://wg21.link/P0245R1) Hexadecimal float literals
  for C++
*/
#ifndef LBAL_CPP17_HEX_FLOAT
  #define LBAL_CPP17_HEX_FLOAT 0
#endif

/**
  @def LBAL_CPP17_IF_CONSTEXPR
  @brief Allow constant expressions as if statements
  @details SD-6 equivalent: `__cpp_if_constexpr >= 201606L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201606L` [P0292R2](https://wg21.link/P0292R2) constexpr if: A slightly
  different syntax
*/
#ifndef LBAL_CPP17_IF_CONSTEXPR
  #define LBAL_CPP17_IF_CONSTEXPR 0
#endif

/**
  @def LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED
  @brief Address core issues raised by Inheriting Constructors
  @details SD-6 equivalent: `__cpp_inheriting_constructors >= 201511L`. Note
  that `__cpp_inheriting_constructors` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `201511L` [P0136R1](https://wg21.link/P0136R1) Rewording inheriting
  constructors (core issue 1941 et al)
*/
#ifndef LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED
  #define LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED 0
#endif

/**
  @def LBAL_CPP17_INLINE_VARIABLES
  @brief `inline` variables
  @details SD-6 equivalent: `__cpp_inline_variables >= 201606L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201606L` [P0386R2 __PDF__](https://wg21.link/P0386R2) Inline Variables
*/
#ifndef LBAL_CPP17_INLINE_VARIABLES
  #define LBAL_CPP17_INLINE_VARIABLES 0
#endif

/**
  @def LBAL_CPP17_NAMESPACE_ATTRIBUTES
  @brief Attributes for namespaces
  @details SD-6 equivalent: `__cpp_namespace_attributes >= 201411L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201411L` [N4266](https://wg21.link/N4266) Attributes for namespaces and
  enumerators
*/
#ifndef LBAL_CPP17_NAMESPACE_ATTRIBUTES
  #define LBAL_CPP17_NAMESPACE_ATTRIBUTES 0
#endif

/**
  @def LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE
  @brief Make exception specifications be part of the type system
  @details SD-6 equivalent: `__cpp_noexcept_function_type >= 201510L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201510L` [P0012R1](https://wg21.link/P0012R1) Make exception specifications
  be part of the type system, version 5
*/
#ifndef LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE
  #define LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE 0
#endif

/**
  @def LBAL_CPP17_NONTYPE_TEMPLATE_ARGS
  @brief Allow constant evaluation for all non-type template arguments
  @details SD-6 equivalent: `__cpp_nontype_template_args >= 201411L`. Note that
  `__cpp_nontype_template_args` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201411L` [N4268](https://wg21.link/N4268) Allow constant evaluation for all
  non-type template arguments
*/
#ifndef LBAL_CPP17_NONTYPE_TEMPLATE_ARGS
  #define LBAL_CPP17_NONTYPE_TEMPLATE_ARGS 0
#endif

/**
  @def LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO
  @brief Allow declaring non-type template arguments with auto
  @details SD-6 equivalent: `__cpp_nontype_template_parameter_auto >= 201606L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201606L` [P0127R2](https://wg21.link/P0127R2) Declaring non-type template
  arguments with auto
*/
#ifndef LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO
  #define LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO 0
#endif

/**
  @def LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED
  @brief Generalize range-based for-loops
  @details SD-6 equivalent: `__cpp_range_based_for >= 201603L`. Note that
  `__cpp_range_based_for` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201603L` [P0184R0](https://wg21.link/P0184R0) Generalizing the Range-Based
  For Loop
*/
#ifndef LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED
  #define LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED 0
#endif

/**
  @def LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE
  @brief Allow static assertions with no messages
  @details SD-6 equivalent: `__cpp_static_assert >= 201411L`. Note that
  `__cpp_static_assert` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201411L` [N3928](https://wg21.link/N3928) Extending static_assert, v2
*/
#ifndef LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE
  #define LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE 0
#endif

/**
  @def LBAL_CPP17_STRUCTURED_BINDINGS
  @brief Add support for multiple function return values and more
  @details SD-6 equivalent: `__cpp_structured_bindings >= 201606L`. Note that
  `__cpp_structured_bindings` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201606L` [P0217R3](https://wg21.link/P0217R3) Proposed wording for
  structured bindings
*/
#ifndef LBAL_CPP17_STRUCTURED_BINDINGS
  #define LBAL_CPP17_STRUCTURED_BINDINGS 0
#endif

/**
  @def LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS
  @brief Resolve a defect in the matching of template arguments with template
  parameters
  @details SD-6 equivalent: `__cpp_template_template_args >= 201611L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201611L` [P0522R0](https://wg21.link/P0522R0) DR: Matching of template
  template-arguments excludes compatible templates

  @remark The proposal this is from is intended to resolve a Defect Report, but
  unfortunately introduces a defect of its own. Some compilers are disabling
  this until a revised patch is in.
*/
#ifndef LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS
  #define LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS 0
#endif

/**
  @def LBAL_CPP17_VARIADIC_USING
  @brief Add support for pack expansions in using-declarations
  @details SD-6 equivalent: `__cpp_variadic_using >= 201611L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201611L` [P0195R2](https://wg21.link/P0195R2) Pack expansions in using-
  declarations
*/
#ifndef LBAL_CPP17_VARIADIC_USING
  #define LBAL_CPP17_VARIADIC_USING 0
#endif

///	@}	LBAL_CPP17

/**
  @name LBAL_CPP20

  @brief Identify language features specific to the C++20 Standard

  @details Support across compilers for C++20 features is currently
  inconsistent, and is one of the fundamental reasons why lucenaBAL exists.
  These will be updated regularly as the Standard develops.

  Note that a very large number of features do not have SD-6 macros, so we
  often provide our own tokens. Should an official macro be created, we will
  synchronize with it and deprecate the proprietary one.

  @{
*/

/**
  @def LBAL_CPP20_AGGREGATE_PAREN_INIT
  @brief Allow aggregate initialization from parentheses as well as braces.
  @details SD-6 equivalent: `__cpp_aggregate_paren_init >= 201902L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201902L` [P0960R3](https://wg21.link/P0960R3) Allow initializing aggregates
  from a parenthesized list of values

  @remark Note that paren initialization allows narrowing conversions, as usual.
*/
#ifndef LBAL_CPP20_AGGREGATE_PAREN_INIT
  #define LBAL_CPP20_AGGREGATE_PAREN_INIT 0
#endif

/**
  @def LBAL_CPP20_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS
  @brief Allow lambda capture `[=, this]`
*/
#ifndef LBAL_CPP20_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS
  #define LBAL_CPP20_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS 0
#endif

/**
  @def LBAL_CPP20_ATTRIBUTES_LIKELY_AND_UNLIKELY
  @brief Aggregate tracking the availability of `likely` and `unlikely`
  attributes
  @details We track the availability of each attribute separately, as well as
  provide this aggregate to test for compliance. The aggregate’s value will be
  `0` if either attribute is unavailable, or `1` otherwise.
*/
#ifndef LBAL_CPP20_ATTRIBUTES_LIKELY_AND_UNLIKELY
  #define LBAL_CPP20_ATTRIBUTES_LIKELY_AND_UNLIKELY 0
#endif

/**
  @def LBAL_CPP20_ATTRIBUTE_LIKELY
  @brief Add `likely` attribute for labels and statements
  @details SD-6 equivalent: `__has_cpp_attribute(likely) >= 201803L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201803L` [P0479R5](https://wg21.link/P0479R5) Proposed wording for likely
  and unlikely attributes
*/
#ifndef LBAL_CPP20_ATTRIBUTE_LIKELY
  #define LBAL_CPP20_ATTRIBUTE_LIKELY 0
#endif

/**
  @def LBAL_CPP20_ATTRIBUTE_NODISCARD_EXPANDED
  @brief Add explanatory text to the `nodiscard` attribute and allow it on
  constructors
  @details SD-6 equivalent: `__has_cpp_attribute(nodiscard) >= 201907L`. Note
  that `__has_cpp_attribute(nodiscard)` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `201907L` [P1301R4](https://wg21.link/P1301R4) [[nodiscard(should have
  a reason)]]
  - `201907L` [P1771R1 __PDF__](https://wg21.link/P1771R1) [[nodiscard]] for
  constructors
*/
#ifndef LBAL_CPP20_ATTRIBUTE_NODISCARD_EXPANDED
  #define LBAL_CPP20_ATTRIBUTE_NODISCARD_EXPANDED 0
#endif

/**
  @def LBAL_CPP20_ATTRIBUTE_NO_UNIQUE_ADDRESS
  @brief Add language support for for empty objects
  @details SD-6 equivalent: `__has_cpp_attribute(no_unique_address) >= 201803L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201803L` [P0840R2](https://wg21.link/P0840R2) Language support for empty
  objects
*/
#ifndef LBAL_CPP20_ATTRIBUTE_NO_UNIQUE_ADDRESS
  #define LBAL_CPP20_ATTRIBUTE_NO_UNIQUE_ADDRESS 0
#endif

/**
  @def LBAL_CPP20_ATTRIBUTE_UNLIKELY
  @brief Add `unlikely` attribute for labels and statements
  @details SD-6 equivalent: `__has_cpp_attribute(unlikely) >= 201803L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201803L` [P0479R5](https://wg21.link/P0479R5) Proposed wording for likely
  and unlikely attributes
*/
#ifndef LBAL_CPP20_ATTRIBUTE_UNLIKELY
  #define LBAL_CPP20_ATTRIBUTE_UNLIKELY 0
#endif

/**
  @def LBAL_CPP20_CHAR8_T
  @brief Add `char8_t` as a UTF-8 equivalent for `char16_t` and `char32_t`.
  @details SD-6 equivalent: `__cpp_char8_t >= 201811L`. Note that
  `__cpp_char8_t` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P0482R6](https://wg21.link/P0482R6) char8_t: A type for UTF-8
  characters and strings (Revision 6)
*/
#ifndef LBAL_CPP20_CHAR8_T
  #define LBAL_CPP20_CHAR8_T 0
#endif

/**
  @def LBAL_CPP20_CONCEPTS
  @brief Incorporate the Concepts TS into the Standard
  @details SD-6 equivalent: `__cpp_concepts >= 201707L`. Note that
  `__cpp_concepts` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201707L` [P0734R0 __PDF__](https://wg21.link/P0734R0) Wording Paper, C++
  extensions for Concepts
*/
#ifndef LBAL_CPP20_CONCEPTS
  #define LBAL_CPP20_CONCEPTS 0
#endif

/**
  @def LBAL_CPP20_CONCEPTS_CONDITIONALLY_TRIVIAL_SPECIAL_MEMBER_FUNCTIONS
  @brief Make special member functions conditionally trivial
  @details SD-6 equivalent: `__cpp_concepts >= 202002L`. Note that
  `__cpp_concepts` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202002L` [P0848R3](https://wg21.link/P0848R3) Conditionally Trivial Special
  Member Functions
*/
#ifndef LBAL_CPP20_CONCEPTS_CONDITIONALLY_TRIVIAL_SPECIAL_MEMBER_FUNCTIONS
  #define LBAL_CPP20_CONCEPTS_CONDITIONALLY_TRIVIAL_SPECIAL_MEMBER_FUNCTIONS 0
#endif

/**
  @def LBAL_CPP20_CONCEPTS_REFINE_RETURN_TYPE_REQUIREMENTS
  @brief Refine definition of return-type-requirements
  @details SD-6 equivalent: `__cpp_concepts >= 201907L`. Note that
  `__cpp_concepts` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P1452R2](https://wg21.link/P1452R2) On the non-uniform semantics
  of return-type-requirements
*/
#ifndef LBAL_CPP20_CONCEPTS_REFINE_RETURN_TYPE_REQUIREMENTS
  #define LBAL_CPP20_CONCEPTS_REFINE_RETURN_TYPE_REQUIREMENTS 0
#endif

/**
  @def LBAL_CPP20_CONCEPTS_RESPECIFY_RETURN_TYPE_REQUIREMENTS
  @brief Refine definition of return-type-requirements
  @details SD-6 equivalent: `__cpp_concepts >= 201811L`. Note that
  `__cpp_concepts` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P1084R2 __PDF__](https://wg21.link/P1084R2) Today’s return-type-
  requirements Are Insufficient
*/
#ifndef LBAL_CPP20_CONCEPTS_RESPECIFY_RETURN_TYPE_REQUIREMENTS
  #define LBAL_CPP20_CONCEPTS_RESPECIFY_RETURN_TYPE_REQUIREMENTS 0
#endif

/**
  @def LBAL_CPP20_CONDITIONAL_EXPLICIT
  @brief Support `explicit (bool)`
  @details Allow simplification of templated constructors that have the
  potential to incorrectly convert their arguments.

  SD-6 equivalent: `__cpp_conditional_explicit >= 201806L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `201806L` [P0892R2](https://wg21.link/P0892R2) explicit(bool)
*/
#ifndef LBAL_CPP20_CONDITIONAL_EXPLICIT
  #define LBAL_CPP20_CONDITIONAL_EXPLICIT 0
#endif

/**
  @def LBAL_CPP20_CONSTEVAL
  @brief Immediate functions
  @details SD-6 equivalent: `__cpp_consteval >= 201811L`. Note that
  `__cpp_consteval` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P1073R3](https://wg21.link/P1073R3) Immediate functions
*/
#ifndef LBAL_CPP20_CONSTEVAL
  #define LBAL_CPP20_CONSTEVAL 0
#endif

/**
  @def LBAL_CPP20_CONSTEXPR_CHANGE_ACTIVE_UNION_MEMBER
  @brief Allow the active member of a `union` inside `constexpr` to change
  @details SD-6 equivalent: `__cpp_constexpr >= 202002L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202002L` [P1330R0 __PDF__](https://wg21.link/P1330R0) Changing the active
  member of a union inside constexpr
*/
#ifndef LBAL_CPP20_CONSTEXPR_CHANGE_ACTIVE_UNION_MEMBER
  #define LBAL_CPP20_CONSTEXPR_CHANGE_ACTIVE_UNION_MEMBER 0
#endif

/**
  @def LBAL_CPP20_CONSTEXPR_DYNAMIC_ALLOC
  @brief Language support for variable-sized containers suitable for use in
  constexpr computations.
  @details SD-6 equivalent: `__cpp_constexpr_dynamic_alloc >= 201907L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201907L` [P0784R7](https://wg21.link/P0784R7) More constexpr containers

  @remark AKA, “More constexpr containers”.
*/
#ifndef LBAL_CPP20_CONSTEXPR_DYNAMIC_ALLOC
  #define LBAL_CPP20_CONSTEXPR_DYNAMIC_ALLOC 0
#endif

/**
  @def LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM
  @brief Allow `dynamic_cast`, polymorphic `typeid` in `constexpr` functions
  @details SD-6 equivalent: `__cpp_constexpr >= 201811L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P1002R1](https://wg21.link/P1002R1) Try-catch blocks in constexpr
  functions
  - `201811L` [P1327R1](https://wg21.link/P1327R1) Allowing dynamic_cast,
  polymorphic typeid in Constant Expressions

  @remark This and the `LBAL_CPP20_CONSTEXPR_TRY_CATCH` and
  `LBAL_CPP20_CONSTEXPR_UNION_ALTERATION` tokens are aliases for each other.
*/
#ifndef LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM
  #define LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM 0
#endif

/**
  @def LBAL_CPP20_CONSTEXPR_INTRINSICS
  @brief Permit unevaluated inline assembly in `constexpr` functions
  @details SD-6 equivalent: `__cpp_constexpr >= 201907L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P1668R1](https://wg21.link/P1668R1) Enabling constexpr Intrinsics
  By Permitting Unevaluated inline-assembly in constexpr Functions

  @remark This and the `LBAL_CPP20_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION`
  token are aliases for each other.
*/
#ifndef LBAL_CPP20_CONSTEXPR_INTRINSICS
  #define LBAL_CPP20_CONSTEXPR_INTRINSICS 0
#endif

/**
  @def LBAL_CPP20_CONSTEXPR_IN_DECLTYPE
  @brief Address Core Issue regarding when `constexpr` functions are defined
  @details This has the effect of allowing constant expressions in `decltype`
  declarations.

  SD-6 equivalent: `__cpp_constexpr_in_decltype >= 201711L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201711L` [P0859R0](https://wg21.link/P0859R0) Core Issue 1581: When are
  constexpr member functions defined?
*/
#ifndef LBAL_CPP20_CONSTEXPR_IN_DECLTYPE
  #define LBAL_CPP20_CONSTEXPR_IN_DECLTYPE 0
#endif

/**
  @def LBAL_CPP20_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION
  @brief Address an inconsistency in the lambda specification
  @details SD-6 equivalent: `__cpp_constexpr >= 201907L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P1331R2](https://wg21.link/P1331R2) Permitting trivial default
  initialization in constexpr contexts

  @remark This and the `LBAL_CPP20_CONSTEXPR_INTRINSICS` token are aliases for
  each other.
*/
#ifndef LBAL_CPP20_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION
  #define LBAL_CPP20_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION 0
#endif

/**
  @def LBAL_CPP20_CONSTEXPR_TRY_CATCH
  @brief Permit unevaluated inline assembly in constexpr functions
  @details SD-6 equivalent: `__cpp_constexpr >= 201811L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P1002R1](https://wg21.link/P1002R1) Try-catch blocks in constexpr
  functions

  @remark This and the `LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM` and
  `LBAL_CPP20_CONSTEXPR_UNION_ALTERATION` tokens are aliases for each other.
*/
#ifndef LBAL_CPP20_CONSTEXPR_TRY_CATCH
  #define LBAL_CPP20_CONSTEXPR_TRY_CATCH 0
#endif

/**
  @def LBAL_CPP20_CONSTEXPR_UNION_ALTERATION
  @brief Allow changing the active member of a `union` inside `constexpr`
  @details SD-6 equivalent: `__cpp_constexpr >= 201811L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202002L` [P1330R0 __PDF__](https://wg21.link/P1330R0) Changing the active
  member of a union inside constexpr

  @remark This and the `LBAL_CPP20_CONSTEXPR_TRY_CATCH` and
  `LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM` tokens are aliases for each other.
*/
#ifndef LBAL_CPP20_CONSTEXPR_UNION_ALTERATION
  #define LBAL_CPP20_CONSTEXPR_UNION_ALTERATION 0
#endif

/**
  @def LBAL_CPP20_CONSTEXPR_VIRTUAL_FUNCTION
  @brief Allow virtual function calls in constexpr functions
  @details SD-6 equivalent: `__cpp_constexpr >= 201806L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201806L` [P1064R0](https://wg21.link/P1064R0) Allowing Virtual Function
  Calls in Constant Expressions
*/
#ifndef LBAL_CPP20_CONSTEXPR_VIRTUAL_FUNCTION
  #define LBAL_CPP20_CONSTEXPR_VIRTUAL_FUNCTION 0
#endif

/**
  @def LBAL_CPP20_CONSTINIT
  @brief Add the `constinit` keyword
  @details This keyword provides a decorator that can be used to ensure that
  initialization of a constant is actually occuring as expected, regardless of
  any changing (i.e., dialect-specific) rules that might be in play.

  SD-6 equivalent: `__cpp_constinit >= 201907L`. This token will have a value of
  `0` if the proposal described here is not supported.
  - `201907L` [P1143R2](https://wg21.link/P1143R2) Adding the constinit keyword

  @remark This feature is broadly intended to be back-portable to older C+
  + dialects; in certain circumstances it’s conceivable that `__cpp_constinit`
  will be set even if the dialect is older than C++20.
*/
#ifndef LBAL_CPP20_CONSTINIT
  #define LBAL_CPP20_CONSTINIT 0
#endif

/**
  @def LBAL_CPP20_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS
  @brief Fix `const`-qualified pointers to members
*/
#ifndef LBAL_CPP20_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS
  #define LBAL_CPP20_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS 0
#endif

/**
  @def LBAL_CPP20_DEDUCTION_GUIDES_FOR_AGGREGATES
  @brief Class template argument deduction for aggregates
  @details SD-6 equivalent: `__cpp_deduction_guides >= 201907L`. Note that
  `__cpp_deduction_guides` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P1814R0](https://wg21.link/P1814R0) Wording for Class Template
  Argument Deduction for Alias Templates
  - `201907L` [P1816R0 __PDF__](https://wg21.link/P1816R0) Wording for class
  template argument deduction for aggregates
*/
#ifndef LBAL_CPP20_DEDUCTION_GUIDES_FOR_AGGREGATES
  #define LBAL_CPP20_DEDUCTION_GUIDES_FOR_AGGREGATES 0
#endif

/**
  @def LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS
  @brief Support default-constructible and -assignable stateless lambdas
*/
#ifndef LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS
  #define LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS 0
#endif

/**
  @def LBAL_CPP20_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS
  @brief Default member initializers for bit-fields
*/
#ifndef LBAL_CPP20_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS
  #define LBAL_CPP20_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS 0
#endif

/**
  @def LBAL_CPP20_DESIGNATED_INITIALIZERS
  @brief Add designated initializers
  @details SD-6 equivalent: `__cpp_designated_initializers >= 201707L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201707L` [P0329R4 __PDF__](https://wg21.link/P0329R4) Designated
  Initialization Wording
*/
#ifndef LBAL_CPP20_DESIGNATED_INITIALIZERS
  #define LBAL_CPP20_DESIGNATED_INITIALIZERS 0
#endif

/**
  @def LBAL_CPP20_DESTROYING_DELETE
  @brief Efficient sized delete for variable sized classes
  @details SD-6 equivalent: `__cpp_impl_destroying_delete >= 201806L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201806L` [P0722R3](https://wg21.link/P0722R3) Efficient sized delete for
  variable sized classes
*/
#ifndef LBAL_CPP20_DESTROYING_DELETE
  #define LBAL_CPP20_DESTROYING_DELETE 0
#endif

/**
  @def LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST
  @brief Generic (Polymorphic) Lambda Expressions
  @details SD-6 equivalent: `__cpp_generic_lambdas >= 201707L`. Note that
  `__cpp_generic_lambdas` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201707L` [P0428R2](https://wg21.link/P0428R2) Familiar template syntax for
  generic lambdas
*/
#ifndef LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST
  #define LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST 0
#endif

/**
  @def LBAL_CPP20_IMPL_COROUTINE
  @brief Add necessary language support for the `<coroutine>` library feature
  @details SD-6 equivalent: `__cpp_impl_coroutine >= 201902L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201902L` [LWG3393](https://wg21.link/LWG3393) Missing/incorrect feature
  test macro for coroutines
  - `201902L` [P0912R5](https://wg21.link/P0912R5) Merge Coroutines TS into C+
  +20 working draft

  @remark Technically, the proposal this is from only directs that the
  Coroutines TS be merged into the Standard.
*/
#ifndef LBAL_CPP20_IMPL_COROUTINE
  #define LBAL_CPP20_IMPL_COROUTINE 0
#endif

/**
  @def LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION
  @brief Allow pack-expansion in lambda init-capture
  @details SD-6 equivalent: `__cpp_init_captures >= 201803L`. Note that
  `__cpp_init_captures` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201803L` [P0780R2](https://wg21.link/P0780R2) Allow pack expansion in
  lambda init-capture
*/
#ifndef LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION
  #define LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION 0
#endif

/**
  @def LBAL_CPP20_INIT_STATEMENTS_FOR_RANGE_BASED_FOR
  @brief Add range-based `for` statements with initializer
*/
#ifndef LBAL_CPP20_INIT_STATEMENTS_FOR_RANGE_BASED_FOR
  #define LBAL_CPP20_INIT_STATEMENTS_FOR_RANGE_BASED_FOR 0
#endif

/**
  @def LBAL_CPP20_INTEGRATING_OUR_FEATURE_TEST_MACROS
  @brief Integrate universal feature test macros into the Standard

  @remark It appears this is only here to get Microsoft to support SD-6, as the
  other major compilers de facto meet the requirement.
*/
#ifndef LBAL_CPP20_INTEGRATING_OUR_FEATURE_TEST_MACROS
  #define LBAL_CPP20_INTEGRATING_OUR_FEATURE_TEST_MACROS 0
#endif

/**
  @def LBAL_CPP20_MODULES
  @brief Incorporate modules
  @details SD-6 equivalent: `__cpp_modules >= 201907L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `201907L` [P1103R3 __PDF__](https://wg21.link/P1103R3) Merging Modules
  - `201907L` [P1811R0](https://wg21.link/P1811R0) Relaxing redefinition
  restrictions for re-exportation robustness
*/
#ifndef LBAL_CPP20_MODULES
  #define LBAL_CPP20_MODULES 0
#endif

/**
  @def LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FIXES
  @brief Address inconsistencies in handling of non-type template arguments
  @details SD-6 equivalent: `__cpp_nontype_template_args >= 201911L`. Note that
  `__cpp_nontype_template_args` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201911L` [P1907R1](https://wg21.link/P1907R1) Inconsistencies with non-type
  template parameters

  @remark Most mainstream compilers support this, except for `float`-type
  arguments, but there is no “partial support” value to qualify this. The latest
  versions of some compilers even support `floats` “experimentally”, but have
  not yet updated the macro value.
*/
#ifndef LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FIXES
  #define LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FIXES 0
#endif

/**
  @def LBAL_CPP20_NONTYPE_TEMPLATE_PARAMETER_CLASS
  @brief Class Types in Non-Type Template Parameters
  @details SD-6 equivalent: `__cpp_nontype_template_parameter_class >= 201806L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201806L` [P0732R2 __PDF__](https://wg21.link/P0732R2) Class Types in Non-
  Type Template Parameters
*/
#ifndef LBAL_CPP20_NONTYPE_TEMPLATE_PARAMETER_CLASS
  #define LBAL_CPP20_NONTYPE_TEMPLATE_PARAMETER_CLASS 0
#endif

/**
  @def LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR
  @brief This is the original three-way comparison operator
  @details SD-6 equivalent: `__cpp_impl_three_way_comparison >= 201711L`. Note
  that `__cpp_impl_three_way_comparison` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `201711L` [P0515R3 __PDF__](https://wg21.link/P0515R3) Consistent comparison
  - `201711L` [P0768R1 __PDF__](https://wg21.link/P0768R1) Library Support for
  the Spaceship (Comparison) Operator
*/
#ifndef LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR
  #define LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR 0
#endif

/**
  @def LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_EQUALITY_FIX
  @brief This is the original three-way comparison operator
  @details SD-6 equivalent: `__cpp_impl_three_way_comparison >= 201902L`. Note
  that `__cpp_impl_three_way_comparison` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `201902L` [P1185R2](https://wg21.link/P1185R2) `<=> != ==`
*/
#ifndef LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_EQUALITY_FIX
  #define LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_EQUALITY_FIX 0
#endif

/**
  @def LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_TUNEUP
  @brief This is the updated three-way comparison operator
  @details SD-6 equivalent: `__cpp_impl_three_way_comparison >= 201907L`. Note
  that `__cpp_impl_three_way_comparison` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `201907L` [P1630R1](https://wg21.link/P1630R1) Spaceship needs a tune-up
*/
#ifndef LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_TUNEUP
  #define LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_TUNEUP 0
#endif

/**
  @def LBAL_CPP20_TYPENAME_OPTIONAL
  @brief Down with `typename`!
*/
#ifndef LBAL_CPP20_TYPENAME_OPTIONAL
  #define LBAL_CPP20_TYPENAME_OPTIONAL 0
#endif

/**
  @def LBAL_CPP20_USING_ENUM
  @brief Specify using aliases for enums
  @details SD-6 equivalent: `__cpp_using_enum >= 201907L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `201907L` [P1099R5](https://wg21.link/P1099R5) Using Enum
*/
#ifndef LBAL_CPP20_USING_ENUM
  #define LBAL_CPP20_USING_ENUM 0
#endif

/**
  @def LBAL_CPP20_VA_OPT
  @brief Provide a smarter predefined macro equivalent to __VA__ARGS__
  @details This behaves similarly to Microsoft’s old “broken” C preprocessor
  implementation in regards to variadic macro handling, in that [0..n] arguments
  are allowed rather than [1..n], with any extraneous comma being dropped.

  @remark Ironically, MSVC has no implementation of this.
*/
#ifndef LBAL_CPP20_VA_OPT
  #define LBAL_CPP20_VA_OPT 0
#endif

///	@}	LBAL_CPP20

/**
  @name LBAL_CPP23

  @brief Identify language features specific to the C++23 Standard

  @details Support across compilers for C++23 features is currently
  inconsistent, and is one of the fundamental reasons why lucenaBAL exists.
  These will be updated regularly as the Standard develops. Note that a some
  features do not have formal SD-6 tokens, so we often provide our own. Should
  an official token be created, we will synchronize with it and deprecate the
  proprietary one.

  @{
*/

/**
  @def LBAL_CPP23_ATTRIBUTE_ASSUME
  @brief Optimization hint to indicate an expression is true
  @details SD-6 equivalent: `__has_cpp_attribute(assume) >= 202207L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202207L` [CWG2615](https://wg21.link/CWG2615) Missing
  __has_cpp_attribute(assume)
  - `202207L` [P1774R8 __PDF__](https://wg21.link/P1774R8) Portable assumptions
*/
#ifndef LBAL_CPP23_ATTRIBUTE_ASSUME
  #define LBAL_CPP23_ATTRIBUTE_ASSUME 0
#endif

/**
  @def LBAL_CPP23_AUTO_CAST
  @brief `auto(x)`: `decay-copy` in the language
  @details SD-6 equivalent: `__cpp_auto_cast >= 202110L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `202110L` [P0849R8](https://wg21.link/P0849R8) auto(x): decay-copy in the
  language
*/
#ifndef LBAL_CPP23_AUTO_CAST
  #define LBAL_CPP23_AUTO_CAST 0
#endif

/**
  @def LBAL_CPP23_CHAR8_T_COMPATIBILITY
  @brief `char8_t` Compatibility and Portability Fix
  @details SD-6 equivalent: `__cpp_char8_t >= 202207L`. Note that
  `__cpp_char8_t` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P2513R3](https://wg21.link/P2513R3) char8_t Compatibility and
  Portability Fix
*/
#ifndef LBAL_CPP23_CHAR8_T_COMPATIBILITY
  #define LBAL_CPP23_CHAR8_T_COMPATIBILITY 0
#endif

/**
  @def LBAL_CPP23_CONSTEVAL_PROPAGATE_UP
  @brief `consteval` needs to propagate up
  @details SD-6 equivalent: `__cpp_consteval >= 202211L`. Note that
  `__cpp_consteval` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202211L` [P2564R3](https://wg21.link/P2564R3) consteval needs to propagate
  up
*/
#ifndef LBAL_CPP23_CONSTEVAL_PROPAGATE_UP
  #define LBAL_CPP23_CONSTEVAL_PROPAGATE_UP 0
#endif

/**
  @def LBAL_CPP23_CONSTEXPR_NON_LITERAL_VARIABLES
  @brief Allow non-literal variables, labels, and gotos in `constexpr` functions
  @details SD-6 equivalent: `__cpp_constexpr >= 202110L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202110L` [P2242R3](https://wg21.link/P2242R3) Non-literal variables (and
  labels and gotos) in constexpr functions
*/
#ifndef LBAL_CPP23_CONSTEXPR_NON_LITERAL_VARIABLES
  #define LBAL_CPP23_CONSTEXPR_NON_LITERAL_VARIABLES 0
#endif

/**
  @def LBAL_CPP23_CONSTEXPR_PERMIT_STATIC_CONSTEXPR
  @brief Permit `static constexpr` variables in `constexpr` functions
  @details SD-6 equivalent: `__cpp_constexpr >= 202211L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202211L` [P2647R1](https://wg21.link/P2647R1) Permitting static constexpr
  variables in constexpr functions
*/
#ifndef LBAL_CPP23_CONSTEXPR_PERMIT_STATIC_CONSTEXPR
  #define LBAL_CPP23_CONSTEXPR_PERMIT_STATIC_CONSTEXPR 0
#endif

/**
  @def LBAL_CPP23_CONSTEXPR_RELAX_RESTRICTIONS
  @brief Relax some constexpr restrictions
  @details SD-6 equivalent: `__cpp_constexpr >= 202207L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P2448R2](https://wg21.link/P2448R2) Relaxing some constexpr
  restrictions
*/
#ifndef LBAL_CPP23_CONSTEXPR_RELAX_RESTRICTIONS
  #define LBAL_CPP23_CONSTEXPR_RELAX_RESTRICTIONS 0
#endif

/**
  @def LBAL_CPP23_DEDUCTION_GUIDES_FROM_INHERITED_CONSTRUCTORS
  @brief Allow class template argument deduction from inherited constructors
  @details SD-6 equivalent: `__cpp_deduction_guides >= 202207L`. Note that
  `__cpp_deduction_guides` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P2582R1 __PDF__](https://wg21.link/P2582R1) Wording for class
  template argument deduction from inherited constructors
*/
#ifndef LBAL_CPP23_DEDUCTION_GUIDES_FROM_INHERITED_CONSTRUCTORS
  #define LBAL_CPP23_DEDUCTION_GUIDES_FROM_INHERITED_CONSTRUCTORS 0
#endif

/**
  @def LBAL_CPP23_EXPLICIT_THIS_PARAMETER
  @brief Deduce `this`
  @details SD-6 equivalent: `__cpp_explicit_this_parameter >= 202110L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202110L` [P0847R7](https://wg21.link/P0847R7) Deducing this
*/
#ifndef LBAL_CPP23_EXPLICIT_THIS_PARAMETER
  #define LBAL_CPP23_EXPLICIT_THIS_PARAMETER 0
#endif

/**
  @def LBAL_CPP23_IF_CONSTEVAL
  @brief `if consteval`
  @details SD-6 equivalent: `__cpp_if_consteval >= 202106L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202106L` [P1938R3](https://wg21.link/P1938R3) if consteval
*/
#ifndef LBAL_CPP23_IF_CONSTEVAL
  #define LBAL_CPP23_IF_CONSTEVAL 0
#endif

/**
  @def LBAL_CPP23_IMPLICIT_MOVE
  @brief Simpler implicit move
  @details SD-6 equivalent: `__cpp_implicit_move >= 202207L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202207L` [P2266R3](https://wg21.link/P2266R3) Simpler implicit move
*/
#ifndef LBAL_CPP23_IMPLICIT_MOVE
  #define LBAL_CPP23_IMPLICIT_MOVE 0
#endif

/**
  @def LBAL_CPP23_MULTIDIMENSIONAL_SUBSCRIPT
  @brief Add a multidimensional subscript operator
  @details SD-6 equivalent: `__cpp_multidimensional_subscript >= 202110L`. Note
  that `__cpp_multidimensional_subscript` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `202110L` [P2128R6 __PDF__](https://wg21.link/P2128R6) Multidimensional
  subscript operator
*/
#ifndef LBAL_CPP23_MULTIDIMENSIONAL_SUBSCRIPT
  #define LBAL_CPP23_MULTIDIMENSIONAL_SUBSCRIPT 0
#endif

/**
  @def LBAL_CPP23_MULTIDIMENSIONAL_SUBSCRIPT_STATIC
  @brief `static` `operator []`
  @details SD-6 equivalent: `__cpp_multidimensional_subscript >= 202211L`. Note
  that `__cpp_multidimensional_subscript` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `202211L` [P2589R1 __PDF__](https://wg21.link/P2589R1) static operator[]
*/
#ifndef LBAL_CPP23_MULTIDIMENSIONAL_SUBSCRIPT_STATIC
  #define LBAL_CPP23_MULTIDIMENSIONAL_SUBSCRIPT_STATIC 0
#endif

/**
  @def LBAL_CPP23_NAMED_CHARACTER_ESCAPES
  @brief Add named universal character escapes
  @details SD-6 equivalent: `__cpp_named_character_escapes >= 202207L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202207L` [P2071R2](https://wg21.link/P2071R2) Named universal character
  escapes
*/
#ifndef LBAL_CPP23_NAMED_CHARACTER_ESCAPES
  #define LBAL_CPP23_NAMED_CHARACTER_ESCAPES 0
#endif

/**
  @def LBAL_CPP23_RANGE_BASED_FOR_TEMPORARIES
  @brief Allow some temporaries in range-based for-loops
  @details SD-6 equivalent: `__cpp_range_based_for >= 202211L`. Note that
  `__cpp_range_based_for` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202211L` [CWG2659](https://wg21.link/CWG2659) Missing feature-test macro
  for lifetime extension in range-for loop
  - `202211L` [P2644R1 __PDF__](https://wg21.link/P2644R1) Final Fix of Broken
  Range based for Loop Rev 1
  - `202211L` [P2718R0 __PDF__](https://wg21.link/P2718R0) Wording for P2644R1
  Fix for Range-based for Loop
*/
#ifndef LBAL_CPP23_RANGE_BASED_FOR_TEMPORARIES
  #define LBAL_CPP23_RANGE_BASED_FOR_TEMPORARIES 0
#endif

/**
  @def LBAL_CPP23_SIZE_T_SUFFIX
  @brief Add literal suffixes for (signed) `size_t`
  @details SD-6 equivalent: `__cpp_size_t_suffix >= 202011L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202011L` [P0330R8](https://wg21.link/P0330R8) Literal Suffixes for (signed)
  size_t
*/
#ifndef LBAL_CPP23_SIZE_T_SUFFIX
  #define LBAL_CPP23_SIZE_T_SUFFIX 0
#endif

/**
  @def LBAL_CPP23_STATIC_CALL_OPERATOR
  @brief Static `operator ()`
  @details SD-6 equivalent: `__cpp_static_call_operator >= 202207L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202207L` [P1169R4](https://wg21.link/P1169R4) static operator()
*/
#ifndef LBAL_CPP23_STATIC_CALL_OPERATOR
  #define LBAL_CPP23_STATIC_CALL_OPERATOR 0
#endif

///	@}	LBAL_CPP23

/**
  @name LBAL_CPP26

  @brief Identify language features specific to the C++26 Standard

  @details Support across compilers for C++26 features is currently
  inconsistent, and is one of the fundamental reasons why lucenaBAL exists.
  These will be updated regularly as the Standard develops. Note that a some
  features do not have formal SD-6 tokens, so we often provide our own. Should
  an official token be created, we will synchronize with it and deprecate the
  proprietary one.

  @{
*/

/**
  @def LBAL_CPP26_CONSTEXPR_CAST_FROM_VOID_STAR
  @brief All `constexpr` cast from `void *`
  @details SD-6 equivalent: `__cpp_constexpr >= 202306L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P2738R1 __PDF__](https://wg21.link/P2738R1) constexpr cast from
  void*: towards constexpr type-erasure
*/
#ifndef LBAL_CPP26_CONSTEXPR_CAST_FROM_VOID_STAR
  #define LBAL_CPP26_CONSTEXPR_CAST_FROM_VOID_STAR 0
#endif

/**
  @def LBAL_CPP26_CONSTEXPR_EXCEPTIONS
  @brief Allow exception throwing in _constant-evaluation_
  @details SD-6 equivalent: `__cpp_constexpr_exceptions >= 202411L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202411L` [P3068R6](https://wg21.link/P3068R6) Allowing exception throwing
  in constant-evaluation
*/
#ifndef LBAL_CPP26_CONSTEXPR_EXCEPTIONS
  #define LBAL_CPP26_CONSTEXPR_EXCEPTIONS 0
#endif

/**
  @def LBAL_CPP26_CONSTEXPR_PLACEMENT_NEW
  @brief Add `constexpr` placement `new`
  @details SD-6 equivalent: `__cpp_constexpr >= 202406L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202406L` [P2747R2](https://wg21.link/P2747R2) constexpr placement new
*/
#ifndef LBAL_CPP26_CONSTEXPR_PLACEMENT_NEW
  #define LBAL_CPP26_CONSTEXPR_PLACEMENT_NEW 0
#endif

/**
  @def LBAL_CPP26_CONSTEXPR_VIRTUAL_INHERITANCE
  @brief Allow exception throwing in _constant-evaluation_
  @details SD-6 equivalent: `__cpp_constexpr_virtual_inheritance >= 202506L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202506L` [P3533R2](https://wg21.link/P3533R2) constexpr virtual inheritance
*/
#ifndef LBAL_CPP26_CONSTEXPR_VIRTUAL_INHERITANCE
  #define LBAL_CPP26_CONSTEXPR_VIRTUAL_INHERITANCE 0
#endif

/**
  @def LBAL_CPP26_CONTRACTS
  @brief Contracts for C++
  @details SD-6 equivalent: `__cpp_contracts >= 202502L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `202502L` [P2900R14 __PDF__](https://wg21.link/P2900R14) Contracts for C++
*/
#ifndef LBAL_CPP26_CONTRACTS
  #define LBAL_CPP26_CONTRACTS 0
#endif

/**
  @def LBAL_CPP26_DELETED_FUNCTION
  @brief `= delete(\should have a reason\)`.
  @details SD-6 equivalent: `__cpp_deleted_function >= 202403L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202403L` [P2573R2](https://wg21.link/P2573R2) = delete(“should have a
  reason”);
*/
#ifndef LBAL_CPP26_DELETED_FUNCTION
  #define LBAL_CPP26_DELETED_FUNCTION 0
#endif

/**
  @def LBAL_CPP26_EXPANSION_STATEMENTS
  @brief Expansion statements
  @details SD-6 equivalent: `__cpp_expansion_statements >= 202506L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202506L` [P1306R5](https://wg21.link/P1306R5) Expansion statements
*/
#ifndef LBAL_CPP26_EXPANSION_STATEMENTS
  #define LBAL_CPP26_EXPANSION_STATEMENTS 0
#endif

/**
  @def LBAL_CPP26_IMPL_REFLECTION
  @brief Reflection for C++26
  @details SD-6 equivalent: `__cpp_impl_reflection >= 202506L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202506L` [P2996R13](https://wg21.link/P2996R13) Reflection for C++26
  - `202506L` [P3096R12 __PDF__](https://wg21.link/P3096R12) Function Parameter
  Reflection in Reflection for C++26
  - `202506L` [P3293R3](https://wg21.link/P3293R3) Splicing a base class
  subobject
  - `202506L` [P3394R4](https://wg21.link/P3394R4) Annotations for Reflection
*/
#ifndef LBAL_CPP26_IMPL_REFLECTION
  #define LBAL_CPP26_IMPL_REFLECTION 0
#endif

/**
  @def LBAL_CPP26_PACK_INDEXING
  @brief Pack Indexing
  @details SD-6 equivalent: `__cpp_pack_indexing >= 202311L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202311L` [P2662R3 __PDF__](https://wg21.link/P2662R3) Pack Indexing
*/
#ifndef LBAL_CPP26_PACK_INDEXING
  #define LBAL_CPP26_PACK_INDEXING 0
#endif

/**
  @def LBAL_CPP26_PLACEHOLDER_VARIABLES
  @brief Add placeholder variables (aka underscore, underbar, low line)
  @details SD-6 equivalent: `__cpp_placeholder_variables >= 202306L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202306L` [P2169R4 __PDF__](https://wg21.link/P2169R4) A Nice Placeholder
  With No Name
*/
#ifndef LBAL_CPP26_PLACEHOLDER_VARIABLES
  #define LBAL_CPP26_PLACEHOLDER_VARIABLES 0
#endif

/**
  @def LBAL_CPP26_STATIC_ASSERT_USER_MESSAGE
  @brief Allow static assertions with user-generated messages
  @details SD-6 equivalent: `__cpp_static_assert >= 202306L`. Note that
  `__cpp_static_assert` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P2741R3 __PDF__](https://wg21.link/P2741R3) user-generated
  static_assert messages
*/
#ifndef LBAL_CPP26_STATIC_ASSERT_USER_MESSAGE
  #define LBAL_CPP26_STATIC_ASSERT_USER_MESSAGE 0
#endif

/**
  @def LBAL_CPP26_STRUCTURED_BINDINGS_ATTRIBUTES
  @brief Allow attributes for Structured Bindings
  @details SD-6 equivalent: `__cpp_structured_bindings >= 202403L`. Note that
  `__cpp_structured_bindings` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202411L` [P1061R10](https://wg21.link/P1061R10) Structured Bindings can
  introduce a Pack
*/
#ifndef LBAL_CPP26_STRUCTURED_BINDINGS_ATTRIBUTES
  #define LBAL_CPP26_STRUCTURED_BINDINGS_ATTRIBUTES 0
#endif

/**
  @def LBAL_CPP26_STRUCTURED_BINDINGS_PACK
  @brief Structured Bindings can introduce a Pack
  @details SD-6 equivalent: `__cpp_structured_bindings >= 202403L`. Note that
  `__cpp_structured_bindings` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202403L` [P0609R3 __PDF__](https://wg21.link/P0609R3) Attributes for
  Structured Bindings
*/
#ifndef LBAL_CPP26_STRUCTURED_BINDINGS_PACK
  #define LBAL_CPP26_STRUCTURED_BINDINGS_PACK 0
#endif

/**
  @def LBAL_CPP26_TEMPLATE_PARAMETERS
  @brief Allow _concept_ and _variable-template_ _template-parameters_
  @details SD-6 equivalent: `__cpp_template_parameters >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P2841R7 __PDF__](https://wg21.link/P2841R7) Concept and variable-
  template template-parameters
*/
#ifndef LBAL_CPP26_TEMPLATE_PARAMETERS
  #define LBAL_CPP26_TEMPLATE_PARAMETERS 0
#endif

/**
  @def LBAL_CPP26_TRIVIAL_UNION
  @brief Allow trivial `unions`
  @details SD-6 equivalent: `__cpp_trivial_union >= 202502L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3074R7](https://wg21.link/P3074R7) trivial unions (was
  std::uninitialized<T>)
*/
#ifndef LBAL_CPP26_TRIVIAL_UNION
  #define LBAL_CPP26_TRIVIAL_UNION 0
#endif

/**
  @def LBAL_CPP26_VARIADIC_FRIEND
  @brief Support variadic friends
  @details SD-6 equivalent: `__cpp_variadic_friend >= 202403L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202403L` [P2893R3](https://wg21.link/P2893R3) Variadic Friends
*/
#ifndef LBAL_CPP26_VARIADIC_FRIEND
  #define LBAL_CPP26_VARIADIC_FRIEND 0
#endif

///	@}	LBAL_CPP26

/**
  @name LBAL_CPP2D

  @brief Identify language features specific to the proposed C++29 Standard

  @details C++29—which in draft form is referenced as C++2d—is undergoing
  active development. In order to allow testing, we track approved language
  features here. Since this is all non-final, we use `LBAL_CPP2D_xxx` tokens
  instead of `LBAL_CPP29_xxx` tokens; upon finalization, we’ll update the
  token names and deprecate the old forms. Designation of formal SD-6 tokens
  tends to lag approval of proposals, so we will used the proposed tokens and
  derive our own tokens from those; where there is not even a proposed token,
  we’ll make one up. Once official tokens are created, we will synchronize with
  them it and deprecate the speculative ones.

  @remarks (FIXME - bitweeder) These are on hold till the associated proposals
  are published publicly.

  @{
*/

///	@}	LBAL_CPP2D

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

/**
  @name LBAL_LIBCPP14
  C++14 features described here track the corresponding SD-6 macros, which
  are not as comprehensive as those for more recent Standards. More C++14
  Library features can be tracked as needed.

  @{
*/

/**
  @def LBAL_LIBCPP14_CHRONO_UDLS
  @brief User-defined Literals for `<chrono>` types
  @details SD-6 equivalent: `__cpp_lib_chrono_udls >= 201304L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3642 __PDF__](https://wg21.link/N3642) User-defined Literals for
  Standard Library Types (part 1 - version 4)

  @sa `<chrono>`
*/
#ifndef LBAL_LIBCPP14_CHRONO_UDLS
  #define LBAL_LIBCPP14_CHRONO_UDLS 0
#endif

/**
  @def LBAL_LIBCPP14_COMPLEX_UDLS
  @brief User-defined Literals for `<complex>`
  @details SD-6 equivalent: `__cpp_lib_complex_udls >= 201309L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201309L` [N3779 __PDF__](https://wg21.link/N3779) User-defined Literals
  for std::complex

  @sa `<complex>`
*/
#ifndef LBAL_LIBCPP14_COMPLEX_UDLS
  #define LBAL_LIBCPP14_COMPLEX_UDLS 0
#endif

/**
  @def LBAL_LIBCPP14_EXCHANGE_FUNCTION
  @brief Add `std::exchange` utility function
  @details SD-6 equivalent: `__cpp_lib_exchange_function >= 201304L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3668](https://wg21.link/N3668) exchange() utility function,
  revision 3

  @sa `<utility>`
*/
#ifndef LBAL_LIBCPP14_EXCHANGE_FUNCTION
  #define LBAL_LIBCPP14_EXCHANGE_FUNCTION 0
#endif

/**
  @def LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP
  @brief Add heterogeneous comparison lookup to associative containers
  @details SD-6 equivalent: `__cpp_lib_generic_associative_lookup >= 201304L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201304L` [N3657](https://wg21.link/N3657) Adding heterogeneous comparison
  lookup to associative containers (rev 4)

  @sa `<map>` `<set>`
*/
#ifndef LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP
  #define LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP 0
#endif

/**
  @def LBAL_LIBCPP14_INTEGER_SEQUENCE
  @brief Add template-based integer sequences
  @details SD-6 equivalent: `__cpp_lib_integer_sequence >= 201304L`. Note that
  `__cpp_lib_integer_sequence` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201304L` [N3658](https://wg21.link/N3658) Compile-time integer sequences

  @sa `<utility>`
*/
#ifndef LBAL_LIBCPP14_INTEGER_SEQUENCE
  #define LBAL_LIBCPP14_INTEGER_SEQUENCE 0
#endif

/**
  @def LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE
  @brief Add `constexpr` operator-() to `std::integral_constant`
  @details SD-6 equivalent: `__cpp_lib_integral_constant_callable >= 201304L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201304L` [N3545 __PDF__](https://wg21.link/N3545) An Incremental
  Improvement to integral_constant

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE
  #define LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE 0
#endif

/**
  @def LBAL_LIBCPP14_IS_FINAL
  @brief Detect finalized classes
  @details SD-6 equivalent: `__cpp_lib_is_final >= 201402L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201402L` [LWG2112](https://wg21.link/LWG2112) User-defined classes that
  cannot be derived from

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP14_IS_FINAL
  #define LBAL_LIBCPP14_IS_FINAL 0
#endif

/**
  @def LBAL_LIBCPP14_IS_NULL_POINTER
  @brief Detect null pointers
  @details SD-6 equivalent: `__cpp_lib_is_null_pointer >= 201309L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201309L` [LWG2247](https://wg21.link/LWG2247) Type traits and
  std::nullptr_t

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP14_IS_NULL_POINTER
  #define LBAL_LIBCPP14_IS_NULL_POINTER 0
#endif

/**
  @def LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR
  @brief `std::make_reverse_iterator`
  @details SD-6 equivalent: `__cpp_lib_make_reverse_iterator >= 201402L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201402L` [LWG2285](https://wg21.link/LWG2285) make_reverse_iterator

  @sa `<iterator>`
*/
#ifndef LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR
  #define LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR 0
#endif

/**
  @def LBAL_LIBCPP14_MAKE_UNIQUE
  @brief `std::make_unique`
  @details SD-6 equivalent: `__cpp_lib_make_unique >= 201304L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3656](https://wg21.link/N3656) make_unique (Revision 1)

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP14_MAKE_UNIQUE
  #define LBAL_LIBCPP14_MAKE_UNIQUE 0
#endif

/**
  @def LBAL_LIBCPP14_NULL_ITERATORS
  @brief Allow value-initialized forward iterators to be compared
  @details SD-6 equivalent: `__cpp_lib_null_iterators >= 201304L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3644 __PDF__](https://wg21.link/N3644) Null Forward Iterators

  @sa `<iterator>`
*/
#ifndef LBAL_LIBCPP14_NULL_ITERATORS
  #define LBAL_LIBCPP14_NULL_ITERATORS 0
#endif

/**
  @def LBAL_LIBCPP14_QUOTED_STRING_IO
  @brief Add quoted-string sream i/o manipulator
  @details SD-6 equivalent: `__cpp_lib_quoted_string_io >= 201304L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3654](https://wg21.link/N3654) Quoted Strings Library Proposal
  (Revision 2)

  @sa `<iomanip>`
*/
#ifndef LBAL_LIBCPP14_QUOTED_STRING_IO
  #define LBAL_LIBCPP14_QUOTED_STRING_IO 0
#endif

/**
  @def LBAL_LIBCPP14_RESULT_OF_SFINAE
  @brief Make `std::result_of` SFINAE-friendly
  @details SD-6 equivalent: `__cpp_lib_result_of_sfinae >= 201210L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201210L` [N3462](https://wg21.link/N3462) std::result_of and SFINAE

  @sa `<functional>` `<type_traits>`
*/
#ifndef LBAL_LIBCPP14_RESULT_OF_SFINAE
  #define LBAL_LIBCPP14_RESULT_OF_SFINAE 0
#endif

/**
  @def LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS
  @brief Make non-modifying sequence operations more robust
  @details SD-6 equivalent: `__cpp_lib_robust_nonmodifying_seq_ops >= 201304L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201304L` [N3671](https://wg21.link/N3671) Making non-modifying sequence
  operations more robust: Revision 2

  @sa `<algorithm>`
*/
#ifndef LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS
  #define LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS 0
#endif

/**
  @def LBAL_LIBCPP14_SHARED_TIMED_MUTEX
  @brief Rename `std::shared_mutex` to `std::shared_timed_mutex`
  @details SD-6 equivalent: `__cpp_lib_shared_timed_mutex >= 201402L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201402L` [N3891](https://wg21.link/N3891) A proposal to rename shared_mutex
  to shared_timed_mutex

  @sa `<shared_mutex>`
*/
#ifndef LBAL_LIBCPP14_SHARED_TIMED_MUTEX
  #define LBAL_LIBCPP14_SHARED_TIMED_MUTEX 0
#endif

/**
  @def LBAL_LIBCPP14_STRING_UDLS
  @brief Predefine UDLs for strings
  @details SD-6 equivalent: `__cpp_lib_string_udls >= 201304L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3642 __PDF__](https://wg21.link/N3642) User-defined Literals for
  Standard Library Types (part 1 - version 4)

  @sa `<string>`
*/
#ifndef LBAL_LIBCPP14_STRING_UDLS
  #define LBAL_LIBCPP14_STRING_UDLS 0
#endif

/**
  @def LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES
  @brief Provide type aliases for transformation traits
  @details SD-6 equivalent: `__cpp_lib_transformation_trait_aliases >= 201304L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201304L` [N3655 __PDF__](https://wg21.link/N3655) TransformationTraits
  Redux, v2

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES
  #define LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES 0
#endif

/**
  @def LBAL_LIBCPP14_TRANSPARENT_OPERATORS
  @brief Allow heterogeneous arguments to operator functors and template their
  function call operators
  @details SD-6 equivalent: `__cpp_lib_transparent_operators >= 201210L`. Note
  that `__cpp_lib_transparent_operators` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `201210L` [N3421](https://wg21.link/N3421) Making Operator Functors
  greater<>

  @sa `<functional>` `<memory>`
*/
#ifndef LBAL_LIBCPP14_TRANSPARENT_OPERATORS
  #define LBAL_LIBCPP14_TRANSPARENT_OPERATORS 0
#endif

/**
  @def LBAL_LIBCPP14_TUPLES_BY_TYPE
  @brief Allow addressing `std::tuple`s by type
  @details SD-6 equivalent: `__cpp_lib_tuples_by_type >= 201304L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3670 __PDF__](https://wg21.link/N3670) Wording for Addressing
  Tuples by Type: Revision 2

  @sa `<tuple>` `<utility>`
*/
#ifndef LBAL_LIBCPP14_TUPLES_BY_TYPE
  #define LBAL_LIBCPP14_TUPLES_BY_TYPE 0
#endif

/**
  @def LBAL_LIBCPP14_TUPLE_ELEMENT_T
  @brief Add `std::tuple` `element_t` type alias
  @details SD-6 equivalent: `__cpp_lib_tuple_element_t >= 201402L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201402L` [N3887 __PDF__](https://wg21.link/N3887) Consistent Metafunction
  Aliases

  @sa `<tuple>`
*/
#ifndef LBAL_LIBCPP14_TUPLE_ELEMENT_T
  #define LBAL_LIBCPP14_TUPLE_ELEMENT_T 0
#endif

///	@}	LBAL_LIBCPP14

/**
  @name LBAL_LIBCPP17
  A large number of C++17 Standard Library features are not available in
  the implementations bundled with otherwise-conforming C++17 compilers.
  Additionally, sometimes support is simply broken or has surprising
  limitations, presenting further challenges. Here we track and document all
  such situations we’re aware of.

  @{
*/

/**
  @def LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR
  @brief Make `std::addressof` `constexpr`, as per defect report
  @details SD-6 equivalent: `__cpp_lib_addressof_constexpr >= 201603L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201603L` [LWG2296](https://wg21.link/LWG2296) std::addressof should be
  constexpr

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR
  #define LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR 0
#endif

/**
  @def LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL
  @brief Clean up `noexcept` usage (Rev 3)
  @details SD-6 equivalent: `__cpp_lib_allocator_traits_is_always_equal >=
  201411L`. This token will have a value of `0` if the proposal described here
  is not supported.
  - `201411L` [N4258 __PDF__](https://wg21.link/N4258) Cleaning up noexcept in
  the Library (Rev 3)

  @sa `<deque>` `<forward_list>` `<list>` `<map>` `<memory>`
  `<scoped_allocator>` `<set>` `<string>` `<unordered_map>` `<unordered_set>`
  `<vector>`
*/
#ifndef LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL
  #define LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL 0
#endif

/**
  @def LBAL_LIBCPP17_ANY
  @brief `<any>` components from Library Fundamentals V1 TS
  @details SD-6 equivalent: `__cpp_lib_any >= 201603L`. Note that
  `__cpp_lib_any` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201603L` [P0220R1](https://wg21.link/P0220R1) Adopt Library Fundamentals V1
  TS Components for C++17 (R1)

  @remark (APIME) We do not track experimental versions of this.

  @sa `<any>`
*/
#ifndef LBAL_LIBCPP17_ANY
  #define LBAL_LIBCPP17_ANY 0
#endif

/**
  @def LBAL_LIBCPP17_ANY_INTERFACE
  @brief Impose homogeneous interface for `std::variant`, `std::any` and
  `std::optional` (Rev 3)
  @details SD-6 equivalent: `__cpp_lib_any >= 201606L`. Note that
  `__cpp_lib_any` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201606L` [P0032R3 __PDF__](https://wg21.link/P0032R3) Homogeneous interface
  for variant, any and optional (Revision 3)

  @remark (APIME) We do not track experimental versions of this.

  @sa `<any>`
*/
#ifndef LBAL_LIBCPP17_ANY_INTERFACE
  #define LBAL_LIBCPP17_ANY_INTERFACE 0
#endif

/**
  @def LBAL_LIBCPP17_APPLY
  @brief `std::apply` component from Library Fundamentals V1 TS
  @details SD-6 equivalent: `__cpp_lib_apply >= 201603L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `201603L` [P0220R1](https://wg21.link/P0220R1) Adopt Library Fundamentals V1
  TS Components for C++17 (R1)

  @sa `<tuple>`
*/
#ifndef LBAL_LIBCPP17_APPLY
  #define LBAL_LIBCPP17_APPLY 0
#endif

/**
  @def LBAL_LIBCPP17_ARRAY_CONSTEXPR
  @brief Add `constexpr` modifiers to `std::reverse_iterator`,
  `std::move_iterator`, `<array>` and Range Access types
  @details SD-6 equivalent: `__cpp_lib_array_constexpr >= 201603L`. Note that
  `__cpp_lib_array_constexpr` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201603L` [P0031R0](https://wg21.link/P0031R0) A Proposal to Add Constexpr
  Modifiers to reverse_iterator, move_iterator, array and Range Access

  @sa `<array>` `<iterator>`
*/
#ifndef LBAL_LIBCPP17_ARRAY_CONSTEXPR
  #define LBAL_LIBCPP17_ARRAY_CONSTEXPR 0
#endif

/**
  @def LBAL_LIBCPP17_AS_CONST
  @brief Add `std::as_const` helper function template
  @details SD-6 equivalent: `__cpp_lib_as_const >= 201510L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201510L` [P0007R1](https://wg21.link/P0007R1) Constant View: A proposal for
  a std::as_const helper function template

  @sa `<utility>`
*/
#ifndef LBAL_LIBCPP17_AS_CONST
  #define LBAL_LIBCPP17_AS_CONST 0
#endif

/**
  @def LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE
  @brief Add `constexpr` `atomic<T>::is_always_lock_free`
  @details SD-6 equivalent: `__cpp_lib_atomic_is_always_lock_free >= 201603L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201603L` [P0152R1](https://wg21.link/P0152R1) constexpr
  atomic<T>::is_always_lock_free

  @sa `<atomic>`
*/
#ifndef LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE
  #define LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE 0
#endif

/**
  @def LBAL_LIBCPP17_BOOL_CONSTANT
  @brief Introduce `std::bool_constant`
  @details SD-6 equivalent: `__cpp_lib_bool_constant >= 201505L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201505L` [N4389](https://wg21.link/N4389) Wording for bool_constant,
  revision 1

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_BOOL_CONSTANT
  #define LBAL_LIBCPP17_BOOL_CONSTANT 0
#endif

/**
  @def LBAL_LIBCPP17_BOYER_MOORE_SEARCHER
  @brief Add text search components from Library Fundamentals V1 TS
  @details SD-6 equivalent: `__cpp_lib_boyer_moore_searcher >= 201603L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201603L` [P0220R1](https://wg21.link/P0220R1) Adopt Library Fundamentals V1
  TS Components for C++17 (R1)

  @sa `<functional>`
*/
#ifndef LBAL_LIBCPP17_BOYER_MOORE_SEARCHER
  #define LBAL_LIBCPP17_BOYER_MOORE_SEARCHER 0
#endif

/**
  @def LBAL_LIBCPP17_BYTE
  @brief Define `std::byte` type
  @details SD-6 equivalent: `__cpp_lib_byte >= 201603L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `201603L` [P0298R3](https://wg21.link/P0298R3) A byte type definition

  @sa `<cstddef>`
*/
#ifndef LBAL_LIBCPP17_BYTE
  #define LBAL_LIBCPP17_BYTE 0
#endif

/**
  @def LBAL_LIBCPP17_CHRONO
  @brief Rounding and `abs` fixes for `<chrono>`
  @details SD-6 equivalent: `__cpp_lib_chrono >= 201510L`. Note that
  `__cpp_lib_chrono` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201510L` [P0092R1](https://wg21.link/P0092R1) Polishing `<chrono>`

  @sa `<chrono>`
*/
#ifndef LBAL_LIBCPP17_CHRONO
  #define LBAL_LIBCPP17_CHRONO 0
#endif

/**
  @def LBAL_LIBCPP17_CHRONO_CONSTEXPR
  @brief Add `constexpr` to certain `<chrono>` functions
  @details SD-6 equivalent: `__cpp_lib_chrono >= 201611L`. Note that
  `__cpp_lib_chrono` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201611L` [P0505R0](https://wg21.link/P0505R0) Wording for GB 50

  @sa `<chrono>`
*/
#ifndef LBAL_LIBCPP17_CHRONO_CONSTEXPR
  #define LBAL_LIBCPP17_CHRONO_CONSTEXPR 0
#endif

/**
  @def LBAL_LIBCPP17_CLAMP
  @brief Standard clamping algorithm
  @details SD-6 equivalent: `__cpp_lib_clamp >= 201603L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `201603L` [P0025R0](https://wg21.link/P0025R0) An algorithm to “clamp” a
  value between a pair of boundary values

  @sa `<algorithm>`
*/
#ifndef LBAL_LIBCPP17_CLAMP
  #define LBAL_LIBCPP17_CLAMP 0
#endif

/**
  @def LBAL_LIBCPP17_CONSTEXPR_STRING
  @brief Make `std::char_traits` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_string >= 201611L`. Note that
  `__cpp_lib_constexpr_string` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201611L` [P0426R1](https://wg21.link/P0426R1) Constexpr for
  std::char_traits

  @sa `<string>`
*/
#ifndef LBAL_LIBCPP17_CONSTEXPR_STRING
  #define LBAL_LIBCPP17_CONSTEXPR_STRING 0
#endif

/**
  @def LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW
  @brief Make `std::char_traits` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_string_view >= 201611L`. Note
  that `__cpp_lib_constexpr_string_view` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `201611L` [P0426R1](https://wg21.link/P0426R1) Constexpr for
  std::char_traits

  @sa `<string_view>`
*/
#ifndef LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW
  #define LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW 0
#endif

/**
  @def LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS
  @brief Re-enable `std::shared_from_this`
  @details SD-6 equivalent: `__cpp_lib_enable_shared_from_this >= 201603L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201603L` [P0033R1](https://wg21.link/P0033R1) Re-enabling shared_from_this
  (revision 1)

  @remark (SEEME - bitweeder) Prior to the December 2019 release, the
  official SD-6 doc contains an error wherein this token is mistakenly tied
  to [P0074R0](https://wg21.link/P0074R0), a different proposal dealing
  with `std::owner_less`. We reflect the correct proposal here, but the date
  associated with this token may be incorrect.

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS
  #define LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS 0
#endif

/**
  @def LBAL_LIBCPP17_EXECUTION
  @brief Add Library components of the Parallelism TS
  @details SD-6 equivalent: `__cpp_lib_execution >= 201603L`. Note that
  `__cpp_lib_execution` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201603L` [P0024R2 __PDF__](https://wg21.link/P0024R2) The Parallelism TS
  Should be Standardized

  @remark (APIME) We do not track experimental versions of this.

  @remark By itself, this token does not measure compliance with the referenced
  Working Group paper; use LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS.

  @sa `<execution>`
*/
#ifndef LBAL_LIBCPP17_EXECUTION
  #define LBAL_LIBCPP17_EXECUTION 0
#endif

/**
  @def LBAL_LIBCPP17_FILESYSTEM
  @brief Adopt File System TS
  @details SD-6 equivalent: `__cpp_lib_filesystem >= 201603L`. Note that
  `__cpp_lib_filesystem` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201603L` [P0218R1](https://wg21.link/P0218R1) Adopt File System TS for
  C++17

  @remark (SEEME - bitweeder) Full implementation missing on Apple platforms
  prior to macOS 10.15.

  @sa `<filesystem>`
*/
#ifndef LBAL_LIBCPP17_FILESYSTEM
  #define LBAL_LIBCPP17_FILESYSTEM 0
#endif

/**
  @def LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING
  @brief Add directory entry caching to `<filesystem>`
  @details SD-6 equivalent: `__cpp_lib_filesystem >= 201703L`. Note that
  `__cpp_lib_filesystem` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201703L` [P0317R1](https://wg21.link/P0317R1) Directory Entry Caching for
  Filesystem

  @remark (SEEME - bitweeder) Full implementation missing on Apple platforms
  prior to macOS 10.15.

  @sa `<filesystem>`
*/
#ifndef LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING
  #define LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING 0
#endif

/**
  @def LBAL_LIBCPP17_FILESYSTEM_EXP
  @brief Experimental implementation of the Filesystem TS
  @details SD-6 equivalent: `__cpp_lib_experimental_filesystem >= 201603L`.
  This token will have a value of `0` if the proposal described here is not
  supported.

  @remark (SEEME - bitweeder) The experimental version differs in many ways
  from the final version, but it’s all that is offered until gcc 8 and clang 7.
  Generally, no one should use this, and it has been dropped from SD-6.
*/
#ifndef LBAL_LIBCPP17_FILESYSTEM_EXP
  #define LBAL_LIBCPP17_FILESYSTEM_EXP 0
#endif

/**
  @def LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED
  @brief Add relative path and `std::string_view` support to `<filesystem>`
  @details SD-6 equivalent: `__cpp_lib_filesystem >= 201606L`. Note that
  `__cpp_lib_filesystem` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201606L` [P0392R0](https://wg21.link/P0392R0) Adapting string_view by
  filesystem paths

  @remark (SEEME - bitweeder) Full implementation missing on Apple platforms
  prior to macOS 10.15.

  @sa `<filesystem>`
*/
#ifndef LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED
  #define LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED 0
#endif

/**
  @def LBAL_LIBCPP17_GCD_LCM
  @brief Add `std::gcd` and `std::lcm`
  @details SD-6 equivalent: `__cpp_lib_gcd_lcm >= 201606L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `201606L` [P0295R0](https://wg21.link/P0295R0) Adopt Selected Library
  Fundamentals V2 Components for C++17

  @sa `<numeric>`
*/
#ifndef LBAL_LIBCPP17_GCD_LCM
  #define LBAL_LIBCPP17_GCD_LCM 0
#endif

/**
  @def LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE
  @brief Provide relevant cache line sizes for construction and destruction.
  @details SD-6 equivalent: `__cpp_lib_hardware_interference_size >= 201703L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201703L` [P0154R1](https://wg21.link/P0154R1) constexpr
  std::thread::hardware_{true,false}_sharing_size

  @sa `<new>`
*/
#ifndef LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE
  #define LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE 0
#endif

/**
  @def LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS
  @brief Add `std::has_unique_object_representations`
  @details This obliquely-named trait indicates whether a given type can be
  trivially hashed (e.g., it has no padding bits that would require special
  handling).

  SD-6 equivalent: `__cpp_lib_has_unique_object_representations >= 201606L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201606L` [P0258R2](https://wg21.link/P0258R2)
  has_unique_object_representations - wording

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS
  #define LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS 0
#endif

/**
  @def LBAL_LIBCPP17_HYPOT
  @brief Introduce a 3-argument overload to `std::hypot`
  @details This standardizes finding 3-dimensional distance as well as 2-
  dimensional distance.

  SD-6 equivalent: `__cpp_lib_hypot >= 201603L`. This token will have a value of
  `0` if the proposal described here is not supported.
  - `201603L` [P0030R1](https://wg21.link/P0030R1) Proposal to Introduce a 3-
  Argument Overload to std::hypot

  @sa `<cmath>`
*/
#ifndef LBAL_LIBCPP17_HYPOT
  #define LBAL_LIBCPP17_HYPOT 0
#endif

/**
  @def LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS
  @brief Introduce minimal incomplete type support for Standard containers
  @details SD-6 equivalent: `__cpp_lib_incomplete_container_elements >=
  201505L`. This token will have a value of `0` if the proposal described here
  is not supported.
  - `201505L` [N4510](https://wg21.link/N4510) Minimal incomplete type support
  for standard containers, revision 4

  @sa `<forward_list>` `<list>` `<vector>`
*/
#ifndef LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS
  #define LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS 0
#endif

/**
  @def LBAL_LIBCPP17_INVOKE
  @brief Add `std::invoke` function template
  @details SD-6 equivalent: `__cpp_lib_invoke >= 201411L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `201411L` [N4169](https://wg21.link/N4169) A proposal to add invoke function
  template (Revision 1)

  @sa `<functional>`
*/
#ifndef LBAL_LIBCPP17_INVOKE
  #define LBAL_LIBCPP17_INVOKE 0
#endif

/**
  @def LBAL_LIBCPP17_IS_AGGREGATE
  @brief Add `std::is_aggregate` type trait
  @details SD-6 equivalent: `__cpp_lib_is_aggregate >= 201703L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201703L` [LWG2911](https://wg21.link/LWG2911) An is_aggregate type trait
  is needed

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_IS_AGGREGATE
  #define LBAL_LIBCPP17_IS_AGGREGATE 0
#endif

/**
  @def LBAL_LIBCPP17_IS_INVOCABLE
  @brief Add `std::is_invocable` type trait to replace `is_callable`
  @details SD-6 equivalent: `__cpp_lib_is_invocable >= 201703L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201703L` [P0604R0](https://wg21.link/P0604R0) Resolving GB 55, US 84, US
  85, US 86

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_IS_INVOCABLE
  #define LBAL_LIBCPP17_IS_INVOCABLE 0
#endif

/**
  @def LBAL_LIBCPP17_IS_SWAPPABLE
  @brief Add `std::is_swappable` type trait family
  @details SD-6 equivalent: `__cpp_lib_is_swappable >= 201603L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201603L` [P0185R1](https://wg21.link/P0185R1) Adding [nothrow-]swappable
  traits, revision 3

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_IS_SWAPPABLE
  #define LBAL_LIBCPP17_IS_SWAPPABLE 0
#endif

/**
  @def LBAL_LIBCPP17_LAUNDER
  @brief Replacement of class objects containing reference members
  @details SD-6 equivalent: `__cpp_lib_launder >= 201606L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `201606L` [P0137R1](https://wg21.link/P0137R1) Core Issue 1776: Replacement
  of class objects containing reference members

  @sa `<new>`
*/
#ifndef LBAL_LIBCPP17_LAUNDER
  #define LBAL_LIBCPP17_LAUNDER 0
#endif

/**
  @def LBAL_LIBCPP17_LOGICAL_TRAITS
  @brief Provide type traits for performing logical operations
  @details SD-6 equivalent: `__cpp_lib_logical_traits >= 201510L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201510L` [P0013R1](https://wg21.link/P0013R1) Logical Operator Type Traits
  (revison 1)

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_LOGICAL_TRAITS
  #define LBAL_LIBCPP17_LOGICAL_TRAITS 0
#endif

/**
  @def LBAL_LIBCPP17_MAKE_FROM_TUPLE
  @brief Introduce `std::make_from_tuple` to unpack a tuple into arguments
  @details SD-6 equivalent: `__cpp_lib_make_from_tuple >= 201606L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201606L` [P0209R2 __PDF__](https://wg21.link/P0209R2) make_from_tuple:
  apply for construction

  @sa `<tuple>`
*/
#ifndef LBAL_LIBCPP17_MAKE_FROM_TUPLE
  #define LBAL_LIBCPP17_MAKE_FROM_TUPLE 0
#endif

/**
  @def LBAL_LIBCPP17_MAP_TRY_EMPLACE
  @brief Improve insertion into `std::map`
  @details SD-6 equivalent: `__cpp_lib_map_try_emplace >= 201411L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201411L` [N4279](https://wg21.link/N4279) Improved insertion interface for
  unique-key maps (Revision 2.3)

  @sa `<map>`
*/
#ifndef LBAL_LIBCPP17_MAP_TRY_EMPLACE
  #define LBAL_LIBCPP17_MAP_TRY_EMPLACE 0
#endif

/**
  @def LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS
  @brief Incorporate math functions specified in IS 29124:2010
  @details SD-6 equivalent: `__cpp_lib_math_special_functions >= 201603L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201603L` [P0226R1 __PDF__](https://wg21.link/P0226R1) Mathematical Special
  Functions for C++17, v5

  @sa `<cmath>`
*/
#ifndef LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS
  #define LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS 0
#endif

/**
  @def LBAL_LIBCPP17_MEMORY_RESOURCE
  @brief Incorporate memory management components from Library Fundamentals
  V1 TS
  @details SD-6 equivalent: `__cpp_lib_memory_resource >= 201603L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201603L` [P0220R1](https://wg21.link/P0220R1) Adopt Library Fundamentals V1
  TS Components for C++17 (R1)

  @sa `<memory_resource>`
*/
#ifndef LBAL_LIBCPP17_MEMORY_RESOURCE
  #define LBAL_LIBCPP17_MEMORY_RESOURCE 0
#endif

/**
  @def LBAL_LIBCPP17_NODE_EXTRACT
  @brief Add splicing to associative containers
  @details SD-6 equivalent: `__cpp_lib_node_extract >= 201606L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201606L` [P0083R3 __PDF__](https://wg21.link/P0083R3) Splicing Maps and
  Sets (Revision 5)

  @sa `<map>` `<set>` `<unordered_map>` `<unordered_set>`
*/
#ifndef LBAL_LIBCPP17_NODE_EXTRACT
  #define LBAL_LIBCPP17_NODE_EXTRACT 0
#endif

/**
  @def LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS
  @brief Incorporate non-member functions into Standard container class
  interfaces
  @details SD-6 equivalent: `__cpp_lib_nonmember_container_access >= 201411L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201411L` [N4280](https://wg21.link/N4280) Non-member size() and more
  (Revison 2)

  @sa `<array>` `<deque>` `<forward_list>` `<iterator>` `<list>` `<map>`
  `<regex>` `<set>` `<string>` `<unordered_map>` `<unordered_set>` `<vector>`
*/
#ifndef LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS
  #define LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS 0
#endif

/**
  @def LBAL_LIBCPP17_NOT_FN
  @brief Add `std::not_fn`
  @details SD-6 equivalent: `__cpp_lib_not_fn >= 201603L`. Note that
  `__cpp_lib_not_fn` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201603L` [P0005R4 __PDF__](https://wg21.link/P0005R4) Adopt not_fn from
  Library Fundamentals 2 for C++17

  @sa `<functional>`
*/
#ifndef LBAL_LIBCPP17_NOT_FN
  #define LBAL_LIBCPP17_NOT_FN 0
#endif

/**
  @def LBAL_LIBCPP17_OPTIONAL
  @brief Add `std::optional`
  @details SD-6 equivalent: `__cpp_lib_optional >= 201603L`. Note that
  `__cpp_lib_optional` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201603L` [P0220R1](https://wg21.link/P0220R1) Adopt Library Fundamentals V1
  TS Components for C++17 (R1)

  @sa `<optional>`
*/
#ifndef LBAL_LIBCPP17_OPTIONAL
  #define LBAL_LIBCPP17_OPTIONAL 0
#endif

/**
  @def LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL
  @brief Homogenize `std::optional` interface with `std::any` and `std::variant`
  @details SD-6 equivalent: `__cpp_lib_optional >= 201606L`. Note that
  `__cpp_lib_optional` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201606L` [P0032R3 __PDF__](https://wg21.link/P0032R3) Homogeneous interface
  for variant, any and optional (Revision 3)

  @remark Note that the [`P0032R3`](https://wg21.link/P0032R3) and [`P0307R2`]
  (https://wg21.link/P0307R2) proposals were approved at the same time,
  and hence shared a token value. While we provide separate features for
  `LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL` and `LBAL_LIBCPP17_OPTIONAL_INTERFACE`,
  they’re not actually differentiated by the SD-6 rules (though they might be at
  the platform level).

  @sa `<optional>`
*/
#ifndef LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL
  #define LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL 0
#endif

/**
  @def LBAL_LIBCPP17_OPTIONAL_INTERFACE
  @brief Homogenize `std::optional` interface with `std::any` and `std::variant`
  @details SD-6 equivalent: `__cpp_lib_optional >= 201606L`. Note that
  `__cpp_lib_optional` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201606L` [P0307R2 __PDF__](https://wg21.link/P0307R2) Making Optional
  Greater Equal Again

  @remark Note that the [`P0032R3`](https://wg21.link/P0032R3) and [`P0307R2`]
  (https://wg21.link/P0307R2) proposals were approved at the same time,
  and hence shared a token value. While we provide separate features for
  `LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL` and `LBAL_LIBCPP17_OPTIONAL_INTERFACE`,
  they’re not actually differentiated by the SD-6 rules (though they might be at
  the platform level).

  @sa `<optional>`
*/
#ifndef LBAL_LIBCPP17_OPTIONAL_INTERFACE
  #define LBAL_LIBCPP17_OPTIONAL_INTERFACE 0
#endif

/**
  @def LBAL_LIBCPP17_PARALLEL_ALGORITHM
  @brief Standardize the Parallelism TS
  @details SD-6 equivalent: `__cpp_lib_parallel_algorithm >= 201603L`. Note that
  `__cpp_lib_parallel_algorithm` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201603L` [P0024R2 __PDF__](https://wg21.link/P0024R2) The Parallelism TS
  Should be Standardized

  @remark (APIME) We do not track experimental versions of this.

  @remark By itself, this macro does not measure compliance
  with the original Working Group paper; for that, use
  LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS.

  @sa `<algorithm>` `<numeric>`
*/
#ifndef LBAL_LIBCPP17_PARALLEL_ALGORITHM
  #define LBAL_LIBCPP17_PARALLEL_ALGORITHM 0
#endif

/**
  @def LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS
  @brief Supply tools for raw memory management
  @details SD-6 equivalent: `__cpp_lib_raw_memory_algorithms >= 201606L`. Note
  that `__cpp_lib_raw_memory_algorithms` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `201606L` [P0040R3](https://wg21.link/P0040R3) Extending memory management
  tools

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS
  #define LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS 0
#endif

/**
  @def LBAL_LIBCPP17_SAMPLE
  @brief Adopt `std::sample` from the Library Fundamentals V1 TS
  @details SD-6 equivalent: `__cpp_lib_sample >= 201603L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `201603L` [P0220R1](https://wg21.link/P0220R1) Adopt Library Fundamentals V1
  TS Components for C++17 (R1)

  @sa `<algorithm>`
*/
#ifndef LBAL_LIBCPP17_SAMPLE
  #define LBAL_LIBCPP17_SAMPLE 0
#endif

/**
  @def LBAL_LIBCPP17_SCOPED_LOCK
  @brief Add a variadic variant of `std::lock_guard` under a new name
  @details SD-6 equivalent: `__cpp_lib_scoped_lock >= 201703L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201703L` [P0156R2](https://wg21.link/P0156R2) Variadic lock_guard (Rev. 4)

  @remark It was determined that simply making `std::lock_guard` variadic would
  break ABI, hence the name change.

  @sa `<mutex>`
*/
#ifndef LBAL_LIBCPP17_SCOPED_LOCK
  #define LBAL_LIBCPP17_SCOPED_LOCK 0
#endif

/**
  @def LBAL_LIBCPP17_SHARED_MUTEX
  @brief Officially change `std::shared_mutex` to an untimed mutex
  @details This change was corresponds to the addition of an explicit
  `std::shared_timed_mutex`.

  SD-6 equivalent: `__cpp_lib_shared_mutex >= 201505L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `201505L` [N4508](https://wg21.link/N4508) A proposal to add shared_mutex
  (untimed) (Revision 4)

  @sa `<shared_mutex>`
*/
#ifndef LBAL_LIBCPP17_SHARED_MUTEX
  #define LBAL_LIBCPP17_SHARED_MUTEX 0
#endif

/**
  @def LBAL_LIBCPP17_SHARED_PTR_ARRAYS
  @brief Fix `std::shared_ptr` support for arrays
  @details SD-6 equivalent: `__cpp_lib_shared_ptr_arrays >= 201611L`. Note that
  `__cpp_lib_shared_ptr_arrays` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201611L` [P0497R0](https://wg21.link/P0497R0) Fixes to shared_ptr support
  for arrays

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP17_SHARED_PTR_ARRAYS
  #define LBAL_LIBCPP17_SHARED_PTR_ARRAYS 0
#endif

/**
  @def LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE
  @brief Add `shared_ptr::weak_type`
  @details SD-6 equivalent: `__cpp_lib_shared_ptr_weak_type >= 201606L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201606L` [P0163R0](https://wg21.link/P0163R0) shared_ptr::weak_type

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE
  #define LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE 0
#endif

/**
  @def LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS
  @brief Track full compliance with the Parallelism Standard
  @details This token tracks compliance with the Standard as it relates to
  implementing the referenced Working Group paper; there is no correspoding
  SD-6 macro, or rather, there are _two_ relevant macros which each track
  the different features required for compliance. We actually track both
  of those, as well as this meta-feature, separately. As such, this token
  represents an aggregate condition: if both `LBAL_LIBCPP17_EXECUTION` and
  `LBAL_LIBCPP17_PARALLEL_ALGORITHM` indicate compliance, this gets set to `1`;
  otherwise, it’s set to `0`.

  @remark (APIME) We do not track experimental versions of this, partly because
  the Draft versions tracked a different set of features, in different places,
  which were refactored/replaced.

  @remark (SEEME - bitweeder) We do not check compliance with iterations on the
  constituent components (e.g., `LBAL_LIBCPP20_EXECUTION_VECTORIZATION`), only
  that we have met the base requirements for supporting Parallelism. Extending
  tracking is one option; another is to eliminate this meta-token to avoid over-
  complicating things.
*/
#ifndef LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS
  #define LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS 0
#endif

/**
  @def LBAL_LIBCPP17_STRING_VIEW
  @brief Adopt `std::string_view` from the Library Fundamentals V1 TS
  @details SD-6 equivalent: `__cpp_lib_string_view >= 201603L`. Note that
  `__cpp_lib_string_view` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201603L` [P0220R1](https://wg21.link/P0220R1) Adopt Library Fundamentals V1
  TS Components for C++17 (R1)

  @sa `<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP17_STRING_VIEW
  #define LBAL_LIBCPP17_STRING_VIEW 0
#endif

/**
  @def LBAL_LIBCPP17_STRING_VIEW_INTERFACE
  @brief Address interface inversion between `<string>` and `<string_view>`
  @details SD-6 equivalent: `__cpp_lib_string_view >= 201606L`. Note that
  `__cpp_lib_string_view` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201606L` [P0254R2 __PDF__](https://wg21.link/P0254R2) Integrating
  std::string_view and std::string

  @sa `<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP17_STRING_VIEW_INTERFACE
  #define LBAL_LIBCPP17_STRING_VIEW_INTERFACE 0
#endif

/**
  @def LBAL_LIBCPP17_TO_CHARS
  @brief Elementary string conversions, revision 5
  @details This token tracks compliance with both the integer and floating-point
  tokens for `to_chars` and `from_chars`.

  SD-6 equivalent: `__cpp_lib_to_chars >= 201611L`. Note that
  `__cpp_lib_to_chars` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201611L` [LWG3137](https://wg21.link/LWG3137) Header for __cpp_lib_to_chars
  - `201611L` [P0067R5](https://wg21.link/P0067R5) Elementary string
  conversions, revision 5
  - `201611L` [P0682R1](https://wg21.link/P0682R1) Repairing elementary string
  conversions

  @remark (SEEME - bitweeder) This got weird since the functions were moved to
  their own header and their signatures were altered, post-Standardization, all
  as part of a Defect Report resolution.

  @remark (SEEME - bitweeder) This got weirder since multiple major
  implementations falsely set their SD-6 macros as if they are in full
  compliance, when they actually only support integer conversions. This is
  reflected by the creation of two tokens that feed into this one, despite there
  only being one underlying SD-6 macro.

  @sa `<charconv>`
*/
#ifndef LBAL_LIBCPP17_TO_CHARS
  #define LBAL_LIBCPP17_TO_CHARS 0
#endif

/**
  @def LBAL_LIBCPP17_TO_CHARS_FP
  @brief Floating-point compliance with Elementary string conversions
  @details This tracks the floating-point conversion portion of
  `LBAL_LIBCPP17_TO_CHARS`.

  SD-6 equivalent: `__cpp_lib_to_chars >= 201611L`. Note that
  `__cpp_lib_to_chars` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201611L` [LWG3137](https://wg21.link/LWG3137) Header for __cpp_lib_to_chars
  - `201611L` [P0067R5](https://wg21.link/P0067R5) Elementary string
  conversions, revision 5
  - `201611L` [P0682R1](https://wg21.link/P0682R1) Repairing elementary string
  conversions

  @remark (SEEME - bitweeder) This got weird since the functions were moved to
  their own header and their signatures were altered, post-Standardization, all
  as part of a Defect Report resolution.

  @remark (SEEME - bitweeder) This got weirder since multiple major
  implementations falsely set their SD-6 macros as if they are in full
  compliance, when they actually only support integer conversions. This is
  reflected by the creation of two tokens that feed into this one, despite there
  only being one underlying SD-6 macro.

  @sa `<charconv>`
*/
#ifndef LBAL_LIBCPP17_TO_CHARS_FP
  #define LBAL_LIBCPP17_TO_CHARS_FP 0
#endif

/**
  @def LBAL_LIBCPP17_TO_CHARS_INTEGER
  @brief Integer compliance with Elementary string conversions
  @details This tracks the integer conversion portion of
  `LBAL_LIBCPP17_TO_CHARS`.

  SD-6 equivalent: `__cpp_lib_to_chars >= 201611L`. Note that
  `__cpp_lib_to_chars` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201611L` [LWG3137](https://wg21.link/LWG3137) Header for __cpp_lib_to_chars
  - `201611L` [P0067R5](https://wg21.link/P0067R5) Elementary string
  conversions, revision 5
  - `201611L` [P0682R1](https://wg21.link/P0682R1) Repairing elementary string
  conversions

  @remark (SEEME - bitweeder) This got weird since the functions were moved to
  their own header and their signatures were altered, post-Standardization, all
  as part of a Defect Report resolution.

  @remark (SEEME - bitweeder) This got weirder since multiple major
  implementations falsely set their SD-6 macros as if they are in full
  compliance, when they actually only support integer conversions. This is
  reflected by the creation of two tokens that feed into this one, despite there
  only being one underlying SD-6 macro.

  @sa `<charconv>`
*/
#ifndef LBAL_LIBCPP17_TO_CHARS_INTEGER
  #define LBAL_LIBCPP17_TO_CHARS_INTEGER 0
#endif

/**
  @def LBAL_LIBCPP17_TRANSPARENT_OPERATORS
  @brief Make `std::owner_less` more flexible
  @details SD-6 equivalent: `__cpp_lib_transparent_operators >= 201510L`. Note
  that `__cpp_lib_transparent_operators` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `201510L` [P0074R0](https://wg21.link/P0074R0) Making std::owner_less more
  flexible

  @remark (SEEME - bitweeder) The official SD-6 doc prior to December 2019
  contains an error wherein this proposal and functionality are mistakenly tied
  to `__cpp_lib_enable_shared_from_this`.

  @sa `<functional>` `<memory>`
*/
#ifndef LBAL_LIBCPP17_TRANSPARENT_OPERATORS
  #define LBAL_LIBCPP17_TRANSPARENT_OPERATORS 0
#endif

/**
  @def LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES
  @brief Adopt variable templates for type traits from the Library Fundamentals
  V1 TS
  @details SD-6 equivalent: `__cpp_lib_type_trait_variable_templates >=
  201510L`. This token will have a value of `0` if the proposal described here
  is not supported.
  - `201510L` [P0006R0](https://wg21.link/P0006R0) Adopt Type Traits Variable
  Templates from Library Fundamentals TS for C++17

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES
  #define LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES 0
#endif

/**
  @def LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS
  @brief Add `std::uncaught_exceptions`
  @details SD-6 equivalent: `__cpp_lib_uncaught_exceptions >= 201411L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201411L` [N4259](https://wg21.link/N4259) Wording for
  std::uncaught_exceptions

  @sa `<exception>`
*/
#ifndef LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS
  #define LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS 0
#endif

/**
  @def LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE
  @brief Improve insertion into `std::unordered_map`
  @details SD-6 equivalent: `__cpp_lib_unordered_map_try_emplace >= 201411L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201411L` [N4279](https://wg21.link/N4279) Improved insertion interface for
  unique-key maps (Revision 2.3)

  @sa `<unordered_map>`
*/
#ifndef LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE
  #define LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE 0
#endif

/**
  @def LBAL_LIBCPP17_VARIANT
  @brief Add `std::variant`
  @details SD-6 equivalent: `__cpp_lib_variant >= 201606L`. Note that
  `__cpp_lib_variant` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201606L` [P0032R3 __PDF__](https://wg21.link/P0032R3) Homogeneous interface
  for variant, any and optional (Revision 3)
  - `201606L` [P0088R3](https://wg21.link/P0088R3) Variant: a type-safe union
  for C++17 (v8)
  - `201606L` [P0393R3 __PDF__](https://wg21.link/P0393R3) Making Variant
  Greater Equal

  @remark We track all three `202106L` proposals with one token, as they
  were all voted in at the same time, and no implementation we’re aware of
  implemented them piecemeal.

  @sa `<variant>`
*/
#ifndef LBAL_LIBCPP17_VARIANT
  #define LBAL_LIBCPP17_VARIANT 0
#endif

/**
  @def LBAL_LIBCPP17_VOID_T
  @brief Add `std::void_t` as a transformation type trait
  @details SD-6 equivalent: `__cpp_lib_void_t >= 201411L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `201411L` [N3911](https://wg21.link/N3911) TransformationTrait Alias void_t

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_VOID_T
  #define LBAL_LIBCPP17_VOID_T 0
#endif

///	@}	LBAL_LIBCPP17

/**
  @name LBAL_LIBCPP20

  @brief These are all taken from features that have been incorporated into
  the C++20 Standard.

  @{
*/

/**
  @def LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS
  @brief Provide `constexpr` comparison operators for `std::array`
  @details SD-6 equivalent: `__cpp_lib_array_constexpr >= 201806L`. Note that
  `__cpp_lib_array_constexpr` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201806L` [P1023R0](https://wg21.link/P1023R0) constexpr comparison
  operators for std::array

  @sa `<array>` `<iterator>`
*/
#ifndef LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS
  #define LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS 0
#endif

/**
  @def LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR
  @brief Define requirements for `constexpr` iterators
  @details SD-6 equivalent: `__cpp_lib_array_constexpr >= 201803L`. Note that
  `__cpp_lib_array_constexpr` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201803L` [LWG3257](https://wg21.link/LWG3257) Missing feature testing macro
  update from P0858
  - `201803L` [P0858R0](https://wg21.link/P0858R0) Constexpr iterator
  requirements

  @remark The issue raised in [LWG3257](https://wg21.link/LWG3257) was simply
  that the SD-6 macro update voted in with [201803L](https://wg21.link/P0858R0)
  had not been applied.

  @sa `<array>` `<iterator>`
*/
#ifndef LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR
  #define LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR 0
#endif

/**
  @def LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES
  @brief Provide `constexpr` `std::array` `swap` and `fill`
  @details SD-6 equivalent: `__cpp_lib_array_constexpr >= 201811L`. Note that
  `__cpp_lib_array_constexpr` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P1032R1](https://wg21.link/P1032R1) Misc constexpr bits

  @sa `<array>` `<iterator>`
*/
#ifndef LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES
  #define LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES 0
#endif

/**
  @def LBAL_LIBCPP20_ASSUME_ALIGNED
  @brief Provide `std::assume_aligned` compiler hint utility function Library
  @details SD-6 equivalent: `__cpp_lib_assume_aligned >= 201811L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201811L` [P1007R3](https://wg21.link/P1007R3) std::assume_aligned

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP20_ASSUME_ALIGNED
  #define LBAL_LIBCPP20_ASSUME_ALIGNED 0
#endif

/**
  @def LBAL_LIBCPP20_ATOMIC_FLAG_TEST
  @brief Add `atomic_flag::test` components of the C++20 Synchronization Library
  @details SD-6 equivalent: `__cpp_lib_atomic_flag_test >= 201907L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201907L` [P1135R6](https://wg21.link/P1135R6) The C++20 Synchronization
  Library

  @sa `<atomic>`
*/
#ifndef LBAL_LIBCPP20_ATOMIC_FLAG_TEST
  #define LBAL_LIBCPP20_ATOMIC_FLAG_TEST 0
#endif

/**
  @def LBAL_LIBCPP20_ATOMIC_FLOAT
  @brief Extend `<atomic>` support to floating point types
  @details SD-6 equivalent: `__cpp_lib_atomic_float >= 201711L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201711L` [P0020R6](https://wg21.link/P0020R6) Floating Point Atomic

  @sa `<atomic>`
*/
#ifndef LBAL_LIBCPP20_ATOMIC_FLOAT
  #define LBAL_LIBCPP20_ATOMIC_FLOAT 0
#endif

/**
  @def LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES
  @brief Add atomic lockfree type aliases from the C++20 Synchronization
  @details SD-6 equivalent: `__cpp_lib_atomic_lock_free_type_aliases >=
  201907L`. This token will have a value of `0` if the proposal described here
  is not supported.
  - `201907L` [P1135R6](https://wg21.link/P1135R6) The C++20 Synchronization
  Library

  @sa `<atomic>`
*/
#ifndef LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES
  #define LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES 0
#endif

/**
  @def LBAL_LIBCPP20_ATOMIC_REF
  @brief Allow atomic operations to apply to non-atomic objects
  @details SD-6 equivalent: `__cpp_lib_atomic_ref >= 201806L`. Note that
  `__cpp_lib_atomic_ref` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201806L` [P0019R8](https://wg21.link/P0019R8) Atomic Ref

  @sa `<atomic>`
*/
#ifndef LBAL_LIBCPP20_ATOMIC_REF
  #define LBAL_LIBCPP20_ATOMIC_REF 0
#endif

/**
  @def LBAL_LIBCPP20_ATOMIC_SHARED_PTR
  @brief Fixes for atomic `std::shared_ptr` and `std::weak_ptr`
  @details SD-6 equivalent: `__cpp_lib_atomic_shared_ptr >= 201711L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201711L` [P0718R2](https://wg21.link/P0718R2) Revising atomic_shared_ptr
  for C++20

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP20_ATOMIC_SHARED_PTR
  #define LBAL_LIBCPP20_ATOMIC_SHARED_PTR 0
#endif

/**
  @def LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION
  @brief Eliminate the surprising value-initialization behavior of `std::atomic`
  @details SD-6 equivalent: `__cpp_lib_atomic_value_initialization >= 201911L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201911L` [P0883R2](https://wg21.link/P0883R2) Fixing Atomic Initialization

  @sa `<atomic>` `<memory>`
*/
#ifndef LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION
  #define LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION 0
#endif

/**
  @def LBAL_LIBCPP20_ATOMIC_WAIT
  @brief Add atomic wait components of the C++20 Synchronization Library
  @details SD-6 equivalent: `__cpp_lib_atomic_wait >= 201907L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201907L` [P1135R6](https://wg21.link/P1135R6) The C++20 Synchronization
  Library

  @sa `<atomic>`
*/
#ifndef LBAL_LIBCPP20_ATOMIC_WAIT
  #define LBAL_LIBCPP20_ATOMIC_WAIT 0
#endif

/**
  @def LBAL_LIBCPP20_BARRIER
  @brief Add `std::barrier` components of the C++20 Synchronization Library
  @details SD-6 equivalent: `__cpp_lib_barrier >= 201907L`. Note that
  `__cpp_lib_barrier` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P1135R6](https://wg21.link/P1135R6) The C++20 Synchronization
  Library

  @sa `<barrier>`
*/
#ifndef LBAL_LIBCPP20_BARRIER
  #define LBAL_LIBCPP20_BARRIER 0
#endif

/**
  @def LBAL_LIBCPP20_BIND_FRONT
  @brief Introduce `std::bind_front` to supersede `std::bind`
  @details SD-6 equivalent: `__cpp_lib_bind_front >= 201811L`. Note that
  `__cpp_lib_bind_front` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P0356R5](https://wg21.link/P0356R5) Simplified partial function
  application

  @sa `<functional>`
*/
#ifndef LBAL_LIBCPP20_BIND_FRONT
  #define LBAL_LIBCPP20_BIND_FRONT 0
#endif

/**
  @def LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP
  @brief Prevent `std::bind_front` from unwrapping `std::reference_wrapper`
  @details SD-6 equivalent: `__cpp_lib_bind_front >= 201907L`. Note that
  `__cpp_lib_bind_front` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P1651R0](https://wg21.link/P1651R0) bind_front should not unwrap
  reference_wrapper

  @sa `<functional>`
*/
#ifndef LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP
  #define LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP 0
#endif

/**
  @def LBAL_LIBCPP20_BITOPS
  @brief Introduce support for hardware-level bit operations
  @details SD-6 equivalent: `__cpp_lib_bitops >= 201907L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `201907L` [P0553R4](https://wg21.link/P0553R4) Bit operations

  @sa `<bit>`
*/
#ifndef LBAL_LIBCPP20_BITOPS
  #define LBAL_LIBCPP20_BITOPS 0
#endif

/**
  @def LBAL_LIBCPP20_BIT_CAST
  @brief Introduce robust casts between bit-compatible types
  @details SD-6 equivalent: `__cpp_lib_bit_cast >= 201806L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201806L` [P0476R2](https://wg21.link/P0476R2) Bit-casting object
  representations

  @sa `<bit>`
*/
#ifndef LBAL_LIBCPP20_BIT_CAST
  #define LBAL_LIBCPP20_BIT_CAST 0
#endif

/**
  @def LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS
  @brief Introduce traits to distinguish between bounded and unbounded arrays
  @details SD-6 equivalent: `__cpp_lib_bounded_array_traits >= 201902L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201902L` [P1357R1](https://wg21.link/P1357R1) Traits for [Un]bounded Arrays

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS
  #define LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS 0
#endif

/**
  @def LBAL_LIBCPP20_CHAR8_T
  @brief Define `char8_t` as the base type for UTF-8 encodings (Rev 6)
  @details SD-6 equivalent: `__cpp_lib_char8_t >= 201811L`. Note that
  `__cpp_lib_char8_t` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P0482R6](https://wg21.link/P0482R6) char8_t: A type for UTF-8
  characters and strings (Revision 6)

  @sa `<atomic>` `<filesystem>` `<istream>` `<limits>` `<locale>` `<ostream>`
  `<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP20_CHAR8_T
  #define LBAL_LIBCPP20_CHAR8_T 0
#endif

/**
  @def LBAL_LIBCPP20_CHAR8_T_COMPAT
  @brief Fix backward compatibility issues introduced by `char8_t`
  @details SD-6 equivalent: `__cpp_lib_char8_t >= 201907L`. Note that
  `__cpp_lib_char8_t` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P1423R3](https://wg21.link/P1423R3) char8_t backward
  compatibility remediation

  @sa `<atomic>` `<filesystem>` `<istream>` `<limits>` `<locale>` `<ostream>`
  `<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP20_CHAR8_T_COMPAT
  #define LBAL_LIBCPP20_CHAR8_T_COMPAT 0
#endif

/**
  @def LBAL_LIBCPP20_CHRONO_CALENDAR
  @brief Add support for Calendars and Time Zones to `<chrono>`
  @details SD-6 equivalent: `__cpp_lib_chrono >= 201803L`. Note that
  `__cpp_lib_chrono` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201803L` [P0355R7](https://wg21.link/P0355R7) Extending `<chrono>` to
  Calendars and Time Zones

  @sa `<chrono>`
*/
#ifndef LBAL_LIBCPP20_CHRONO_CALENDAR
  #define LBAL_LIBCPP20_CHRONO_CALENDAR 0
#endif

/**
  @def LBAL_LIBCPP20_CHRONO_FIXES
  @brief Miscellaneous minor fixes for `<chrono>`
  @details SD-6 equivalent: `__cpp_lib_chrono >= 201907L`. Note that
  `__cpp_lib_chrono` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P1466R3](https://wg21.link/P1466R3) Miscellaneous minor fixes
  for chrono

  @sa `<chrono>`
*/
#ifndef LBAL_LIBCPP20_CHRONO_FIXES
  #define LBAL_LIBCPP20_CHRONO_FIXES 0
#endif

/**
  @def LBAL_LIBCPP20_CONCEPTS
  @brief Standard Library Concepts
  @details SD-6 equivalent: `__cpp_lib_concepts >= 201806L`. Note that
  `__cpp_lib_concepts` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201806L` [P0898R3 __PDF__](https://wg21.link/P0898R3) Standard Library
  Concepts

  @sa `<compare>` `<concepts>`
*/
#ifndef LBAL_LIBCPP20_CONCEPTS
  #define LBAL_LIBCPP20_CONCEPTS 0
#endif

/**
  @def LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE
  @brief Wording for boolean-testable
  @details SD-6 equivalent: `__cpp_lib_concepts >= 202002L`. Note that
  `__cpp_lib_concepts` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202002L` [P1964R2](https://wg21.link/P1964R2) Wording for boolean-testable

  @sa `<compare>` `<concepts>`
*/
#ifndef LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE
  #define LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE 0
#endif

/**
  @def LBAL_LIBCPP20_CONCEPTS_EXP
  @brief Experimental version of Standard Library Concepts
  @details SD-6 equivalent: `__cpp_lib_experimental_concepts >= 201806L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
*/
#ifndef LBAL_LIBCPP20_CONCEPTS_EXP
  #define LBAL_LIBCPP20_CONCEPTS_EXP 0
#endif

/**
  @def LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE
  @brief Rename C++ Concepts to use standard_case
  @details SD-6 equivalent: `__cpp_lib_concepts >= 201907L`. Note that
  `__cpp_lib_concepts` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P1754R1 __PDF__](https://wg21.link/P1754R1) Rename concepts to
  standard_case for C++20, while we still can

  @sa `<compare>` `<concepts>`
*/
#ifndef LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE
  #define LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS
  @brief Add `constexpr` to `<algorithm>` and `<utility>` functions
  @details SD-6 equivalent: `__cpp_lib_constexpr_algorithms >= 201703L`. Note
  that `__cpp_lib_constexpr_algorithms` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `201703L` [P0202R3](https://wg21.link/P0202R3) Add Constexpr Modifiers to
  Functions in `<algorithm>` and `<utility>` Headers

  @sa `<algorithm>` `<utility>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS
  #define LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP
  @brief Add `constexpr` to `std::swap` and related functions
  @details SD-6 equivalent: `__cpp_lib_constexpr_algorithms >= 201806L`. Note
  that `__cpp_lib_constexpr_algorithms` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `201806L` [LWG3256](https://wg21.link/LWG3256) Feature testing macro for
  constexpr algorithms
  - `201806L` [LWG3792](https://wg21.link/LWG3792)
  __cpp_lib_constexpr_algorithms should also be defined in
  - `201806L` [P0879R0](https://wg21.link/P0879R0) Constexpr for swap and swap
  related functions

  @sa `<algorithm>` `<utility>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP
  #define LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_COMPLEX
  @brief Add more `constexpr` support to `<complex>`
  @details SD-6 equivalent: `__cpp_lib_constexpr_complex >= 201711L`. Note that
  `__cpp_lib_constexpr_complex` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201711L` [P0415R1 __PDF__](https://wg21.link/P0415R1) Constexpr for
  std::complex

  @sa `<complex>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_COMPLEX
  #define LBAL_LIBCPP20_CONSTEXPR_COMPLEX 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC
  @brief Add `constexpr` memory allocators used by dynamic containers
  @details SD-6 equivalent: `__cpp_lib_constexpr_dynamic_alloc >= 201907L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201907L` [P0784R7](https://wg21.link/P0784R7) More constexpr containers

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC
  #define LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL
  @brief Make more of `<functional>` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_functional >= 201811L`. Note
  that `__cpp_lib_constexpr_functional` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `201811L` [P1032R1](https://wg21.link/P1032R1) Misc constexpr bits

  @sa `<functional>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL
  #define LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE
  @brief Make `std::invoke` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_functional >= 201907L`. Note
  that `__cpp_lib_constexpr_functional` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `201907L` [P1065R2](https://wg21.link/P1065R2) constexpr INVOKE

  @sa `<functional>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE
  #define LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_ITERATOR
  @brief Make more of `<iterator>` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_iterator >= 201811L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201811L` [P1032R1](https://wg21.link/P1032R1) Misc constexpr bits

  @sa `<iterator>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_ITERATOR
  #define LBAL_LIBCPP20_CONSTEXPR_ITERATOR 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_MEMORY
  @brief Make `std::pointer_traits` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_memory >= 201811L`. Note that
  `__cpp_lib_constexpr_memory` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P1006R1](https://wg21.link/P1006R1) Constexpr in
  std::pointer_traits

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_MEMORY
  #define LBAL_LIBCPP20_CONSTEXPR_MEMORY 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_NUMERIC
  @brief Make numeric algorithms `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_numeric >= 201911L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201911L` [P1645R1](https://wg21.link/P1645R1) constexpr for numeric
  algorithms

  @sa `<numeric>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_NUMERIC
  #define LBAL_LIBCPP20_CONSTEXPR_NUMERIC 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_STRING
  @brief Make `std::string` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_string >= 201907L`. Note that
  `__cpp_lib_constexpr_string` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P0980R1](https://wg21.link/P0980R1) Making std::string constexpr

  @sa `<string>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_STRING
  #define LBAL_LIBCPP20_CONSTEXPR_STRING 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL
  @brief Make parts of `std::string` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_string >= 201811L`. Note that
  `__cpp_lib_constexpr_string` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P1032R1](https://wg21.link/P1032R1) Misc constexpr bits

  @sa `<string>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL
  #define LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW
  @brief Make more of `<string_view>` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_string_view >= 201811L`. Note
  that `__cpp_lib_constexpr_string_view` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `201811L` [P1032R1](https://wg21.link/P1032R1) Misc constexpr bits

  @sa `<string_view>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW
  #define LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_TUPLE
  @brief Make more of `<tuple>` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_tuple >= 201811L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201811L` [P1032R1](https://wg21.link/P1032R1) Misc constexpr bits

  @sa `<tuple>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_TUPLE
  #define LBAL_LIBCPP20_CONSTEXPR_TUPLE 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_UTILITY
  @brief Make more of `<tuple>` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_utility >= 201811L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201811L` [P1032R1](https://wg21.link/P1032R1) Misc constexpr bits

  @sa `<utility>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_UTILITY
  #define LBAL_LIBCPP20_CONSTEXPR_UTILITY 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_VECTOR
  @brief Make `std::vector` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_vector >= 201907L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201907L` [P1004R2 __PDF__](https://wg21.link/P1004R2) Making std::vector
  constexpr

  @sa `<vector>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_VECTOR
  #define LBAL_LIBCPP20_CONSTEXPR_VECTOR 0
#endif

/**
  @def LBAL_LIBCPP20_COROUTINE
  @brief Standard Library coroutines
  @details SD-6 equivalent: `__cpp_lib_coroutine >= 201902L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201902L` [LWG3393](https://wg21.link/LWG3393) Missing/incorrect feature
  test macro for coroutines
  - `201902L` [P0912R5](https://wg21.link/P0912R5) Merge Coroutines TS into C+
  +20 working draft

  @remark Note that `<coroutine>` requires language support.

  @sa `<coroutine>`
*/
#ifndef LBAL_LIBCPP20_COROUTINE
  #define LBAL_LIBCPP20_COROUTINE 0
#endif

/**
  @def LBAL_LIBCPP20_COROUTINE_EXP
  @brief Experimental Standard Library coroutines
  @details SD-6 equivalent: `__cpp_lib_experimental_coroutine >= 201902L`.
  This token will have a value of `0` if the proposal described here is not
  supported.

  @remark Note that `<coroutine>` requires language support.

  @remark This was dropped in favor of `__cpp_lib_coroutine`
  (`LBAL_LIBCPP20_COROUTINE`) once acceptance into C++20 was formalized.
*/
#ifndef LBAL_LIBCPP20_COROUTINE_EXP
  #define LBAL_LIBCPP20_COROUTINE_EXP 0
#endif

/**
  @def LBAL_LIBCPP20_DESTROYING_DELETE
  @brief Efficient sized `delete` for variable-sized classes
  @details SD-6 equivalent: `__cpp_lib_destroying_delete >= 201806L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201806L` [P0722R3](https://wg21.link/P0722R3) Efficient sized delete for
  variable sized classes

  @sa `<new>`
*/
#ifndef LBAL_LIBCPP20_DESTROYING_DELETE
  #define LBAL_LIBCPP20_DESTROYING_DELETE 0
#endif

/**
  @def LBAL_LIBCPP20_ENDIAN
  @brief Add `std::endian` enum
  @details SD-6 equivalent: `__cpp_lib_endian >= 201907L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `201907L` [P0463R1](https://wg21.link/P0463R1) endian, Just endian

  @sa `<bit>`
*/
#ifndef LBAL_LIBCPP20_ENDIAN
  #define LBAL_LIBCPP20_ENDIAN 0
#endif

/**
  @def LBAL_LIBCPP20_ENDIAN_BIT
  @brief Relocate `std::endian` to `<bit>`
  @details SD-6 equivalent: `__cpp_lib_endian >= 201907L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `201907L` [P1612R1 __PDF__](https://wg21.link/P1612R1) Relocate Endian’s
  Specification

  @sa `<bit>`
*/
#ifndef LBAL_LIBCPP20_ENDIAN_BIT
  #define LBAL_LIBCPP20_ENDIAN_BIT 0
#endif

/**
  @def LBAL_LIBCPP20_ERASE_IF
  @brief Adopt consistent container erasure
  @details SD-6 equivalent: `__cpp_lib_erase_if >= 201811L`. Note that
  `__cpp_lib_erase_if` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P1209R0](https://wg21.link/P1209R0) Adopt Consistent Container
  Erasure from Library Fundamentals 2 for C++20

  @sa `<deque>` `<forward_list>` `<list>` `<map>` `<set>` `<string>`
  `<unordered_map>` `<unordered_set>` `<vector>`
*/
#ifndef LBAL_LIBCPP20_ERASE_IF
  #define LBAL_LIBCPP20_ERASE_IF 0
#endif

/**
  @def LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS
  @brief Update `erase_if` free function return types
  @details SD-6 equivalent: `__cpp_lib_erase_if >= 202002L`. Note that
  `__cpp_lib_erase_if` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202002L` [P1115R3 __PDF__](https://wg21.link/P1115R3) Improving the Return
  Value of Erase-Like Algorithms II: Free erase/erase_if

  @sa `<deque>` `<forward_list>` `<list>` `<map>` `<set>` `<string>`
  `<unordered_map>` `<unordered_set>` `<vector>`
*/
#ifndef LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS
  #define LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS 0
#endif

/**
  @def LBAL_LIBCPP20_EXECUTION_VECTORIZATION
  @brief Add target vectorization policies from the Parallelism V2 TS
  @details SD-6 equivalent: `__cpp_lib_execution >= 201902L`. Note that
  `__cpp_lib_execution` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201902L` [P1001R2](https://wg21.link/P1001R2) Target Vectorization Policies
  from Parallelism V2 TS to C++20

  @remark (APIME) We do not track experimental versions of this.

  @sa `<execution>`
*/
#ifndef LBAL_LIBCPP20_EXECUTION_VECTORIZATION
  #define LBAL_LIBCPP20_EXECUTION_VECTORIZATION 0
#endif

/**
  @def LBAL_LIBCPP20_FORMAT
  @brief Add text formatting functionality to properly replace `printf`
  @details SD-6 equivalent: `__cpp_lib_format >= 201907L`. Note that
  `__cpp_lib_format` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P0645R10](https://wg21.link/P0645R10) Text Formatting
  - `201907L` [P1361R2](https://wg21.link/P1361R2) Integration of chrono with
  text formatting
  - `201907L` [P1652R1](https://wg21.link/P1652R1) Printf corner cases in
  std::format

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP20_FORMAT
  #define LBAL_LIBCPP20_FORMAT 0
#endif

/**
  @def LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP
  @brief The feature was removed prior to Standardization
  @details SD-6 equivalent: `__cpp_lib_generic_unordered_hash_lookup >=
  201902L`. This token will have a value of `0` if the proposal described here
  is not supported.
  - `201902L` [P0920R2](https://wg21.link/P0920R2) Precalculated hash values
  in lookup

  @remark This is an unusual example of a feature that was voted into the
  Standard and then promptly voted out.

  @remark `LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP` will always evaluate to
  `0`; it is only here by way of documentation.

  @sa `<unordered_map>` `<unordered_set>`
*/
#ifndef LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP
  #define LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP 0
#endif

/**
  @def LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP
  @brief Heterogeneous lookup for unordered containers
  @details SD-6 equivalent: `__cpp_lib_generic_unordered_lookup >= 201811L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201811L` [P0919R3](https://wg21.link/P0919R3) Heterogeneous lookup for
  unordered containers

  @sa `<unordered_map>` `<unordered_set>`
*/
#ifndef LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP
  #define LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP 0
#endif

/**
  @def LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS
  @brief Add Safe integral comparisons
  @details SD-6 equivalent: `__cpp_lib_integer_comparison_functions >= 202002L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202002L` [P0586R2](https://wg21.link/P0586R2) Safe integral comparisons

  @sa `<utility>`
*/
#ifndef LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS
  #define LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS 0
#endif

/**
  @def LBAL_LIBCPP20_INTERPOLATE
  @brief Add well-behaved interpolation for numbers and pointers
  @details SD-6 equivalent: `__cpp_lib_interpolate >= 201902L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201902L` [P0811R3](https://wg21.link/P0811R3) Well-behaved interpolation
  for numbers and pointers

  @sa `<cmath>` `<numeric>`
*/
#ifndef LBAL_LIBCPP20_INTERPOLATE
  #define LBAL_LIBCPP20_INTERPOLATE 0
#endif

/**
  @def LBAL_LIBCPP20_INT_POW2
  @brief Integral power-of-2 operations
  @details SD-6 equivalent: `__cpp_lib_int_pow2 >= 201806L`. Note that
  `__cpp_lib_int_pow2` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201806L` [P0556R3](https://wg21.link/P0556R3) Integral power-of-
  2 operations

  @sa `<bit>`
*/
#ifndef LBAL_LIBCPP20_INT_POW2
  #define LBAL_LIBCPP20_INT_POW2 0
#endif

/**
  @def LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME
  @brief Rename the assorted bit-manipulation fucntions
  @details SD-6 equivalent: `__cpp_lib_int_pow2 >= 202002L`. Note that
  `__cpp_lib_int_pow2` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202002L` [P1956R1](https://wg21.link/P1956R1) On the naming of low-level
  bit manipulation functions

  @sa `<bit>`
*/
#ifndef LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME
  #define LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME 0
#endif

/**
  @def LBAL_LIBCPP20_IS_CONSTANT_EVALUATED
  @brief Add `std::is_constant_evaluated` type trait
  @details SD-6 equivalent: `__cpp_lib_is_constant_evaluated >= 201811L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201811L` [P0595R2](https://wg21.link/P0595R2) std::is_constant_evaluated

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP20_IS_CONSTANT_EVALUATED
  #define LBAL_LIBCPP20_IS_CONSTANT_EVALUATED 0
#endif

/**
  @def LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE
  @brief Add `std::is_layout_compatible` type trait
  @details SD-6 equivalent: `__cpp_lib_is_layout_compatible >= 201907L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201907L` [P0466R5](https://wg21.link/P0466R5) Layout-compatibility and
  Pointer-interconvertibility Traits

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE
  #define LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE 0
#endif

/**
  @def LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE
  @brief Add `std::is_nothrow_convertible` type trait
  @details SD-6 equivalent: `__cpp_lib_is_nothrow_convertible >= 201806L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201806L` [LWG3356](https://wg21.link/LWG3356) __cpp_lib_nothrow_convertible
  should be __cpp_lib_is_nothrow_convertible
  - `201806L` [P0758R1](https://wg21.link/P0758R1) Implicit conversion traits
  and utility functions

  @remark (SEEME - bitweeder) LWG3356 should probably have gotten its own
  value; the argument against that is that it was a defect corrected prior to
  Standardization.

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE
  #define LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE 0
#endif

/**
  @def LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE
  @brief Add `std::is_pointer_interconvertible` type trait
  @details SD-6 equivalent: `__cpp_lib_is_pointer_interconvertible >= 201907L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201907L` [P0466R5](https://wg21.link/P0466R5) Layout-compatibility and
  Pointer-interconvertibility Traits

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE
  #define LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE 0
#endif

/**
  @def LBAL_LIBCPP20_JTHREAD
  @brief Add a cooperatively interruptible joining thread
  @details SD-6 equivalent: `__cpp_lib_jthread >= 201907L`. Note that
  `__cpp_lib_jthread` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P0660R10](https://wg21.link/P0660R10) Stop Token and Joining
  Thread

  @sa `<stop_token>` `<thread>`
*/
#ifndef LBAL_LIBCPP20_JTHREAD
  #define LBAL_LIBCPP20_JTHREAD 0
#endif

/**
  @def LBAL_LIBCPP20_JTHREAD_CV
  @brief Simplify condition variable API
  @details SD-6 equivalent: `__cpp_lib_jthread >= 201911L`. Note that
  `__cpp_lib_jthread` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201911L` [P1869R1](https://wg21.link/P1869R1) Rename
  ‘condition_variable_any’ interruptible wait methods

  @sa `<stop_token>` `<thread>`
*/
#ifndef LBAL_LIBCPP20_JTHREAD_CV
  #define LBAL_LIBCPP20_JTHREAD_CV 0
#endif

/**
  @def LBAL_LIBCPP20_LATCH
  @brief Incorporate `std::latch` from the C++20 Synchronization Library
  @details SD-6 equivalent: `__cpp_lib_latch >= 201907L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `201907L` [P1135R6](https://wg21.link/P1135R6) The C++20 Synchronization
  Library

  @sa `<latch>`
*/
#ifndef LBAL_LIBCPP20_LATCH
  #define LBAL_LIBCPP20_LATCH 0
#endif

/**
  @def LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE
  @brief Improve the return value of erase-like algorithms
  @details SD-6 equivalent: `__cpp_lib_list_remove_return_type >= 201806L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201806L` [P0646R1 __PDF__](https://wg21.link/P0646R1) Improving the Return
  Value of Erase-Like Algorithms I: list/forward list

  @sa `<forward_list>` `<list>`
*/
#ifndef LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE
  #define LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE 0
#endif

/**
  @def LBAL_LIBCPP20_MATH_CONSTANTS
  @brief Add common math constants to the C++ Standard
  @details SD-6 equivalent: `__cpp_lib_math_constants >= 201907L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201907L` [P0631R8 __PDF__](https://wg21.link/P0631R8) Math Constants

  @sa `<numbers>`
*/
#ifndef LBAL_LIBCPP20_MATH_CONSTANTS
  #define LBAL_LIBCPP20_MATH_CONSTANTS 0
#endif

/**
  @def LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR
  @brief Provide a default template argument for `std::polymorphic_allocator`
  @details SD-6 equivalent: `__cpp_lib_polymorphic_allocator >= 201902L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201902L` [LWG3437](https://wg21.link/LWG3437)
  __cpp_lib_polymorphic_allocator is in the wrong header
  - `201902L` [P0339R6 __PDF__](https://wg21.link/P0339R6)
  polymorphic_allocator<> as a vocabulary type

  @sa `<memory_resource>`
*/
#ifndef LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR
  #define LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR 0
#endif

/**
  @def LBAL_LIBCPP20_RANGES
  @brief Incorporate ranges into the C++ Standard
  @details SD-6 equivalent: `__cpp_lib_ranges >= 201811L`. Note that
  `__cpp_lib_ranges` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P0896R4 __PDF__](https://wg21.link/P0896R4) The One Ranges
  Proposal

  @sa `<algorithm>` `<functional>` `<iterator>` `<memory>` `<ranges>`
*/
#ifndef LBAL_LIBCPP20_RANGES
  #define LBAL_LIBCPP20_RANGES 0
#endif

/**
  @def LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS
  @brief Add input range adaptors
  @details SD-6 equivalent: `__cpp_lib_ranges >= 201907L`. Note that
  `__cpp_lib_ranges` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P1035R7 __PDF__](https://wg21.link/P1035R7) Input Range Adaptors

  @sa `<algorithm>` `<functional>` `<iterator>` `<memory>` `<ranges>`
*/
#ifndef LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS
  #define LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS 0
#endif

/**
  @def LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE
  @brief Loosen the constraints on range-based compare algorithms
  @details SD-6 equivalent: `__cpp_lib_ranges >= 201911L`. Note that
  `__cpp_lib_ranges` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201911L` [P1716R3](https://wg21.link/P1716R3) ranges compare algorithm are
  over-constrained

  @sa `<algorithm>` `<functional>` `<iterator>` `<memory>` `<ranges>`
*/
#ifndef LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE
  #define LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE 0
#endif

/**
  @def LBAL_LIBCPP20_REMOVE_CVREF
  @brief Add `std::remove_cvref` type trait
  @details SD-6 equivalent: `__cpp_lib_remove_cvref >= 201711L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201711L` [P0550R2 __PDF__](https://wg21.link/P0550R2) Transformation Trait
  remove_cvref

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP20_REMOVE_CVREF
  #define LBAL_LIBCPP20_REMOVE_CVREF 0
#endif

/**
  @def LBAL_LIBCPP20_SEMAPHORE
  @brief Incorporate `std::semaphore` from the C++20 Synchronization Library
  @details SD-6 equivalent: `__cpp_lib_semaphore >= 201907L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201907L` [P1135R6](https://wg21.link/P1135R6) The C++20 Synchronization
  Library

  @sa `<semaphore>`
*/
#ifndef LBAL_LIBCPP20_SEMAPHORE
  #define LBAL_LIBCPP20_SEMAPHORE 0
#endif

/**
  @def LBAL_LIBCPP20_SHARED_PTR_ARRAYS
  @brief Extend `std::make_shared` to support C-style arrays
  @details SD-6 equivalent: `__cpp_lib_shared_ptr_arrays >= 201707L`. Note that
  `__cpp_lib_shared_ptr_arrays` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201707L` [P0674R1](https://wg21.link/P0674R1) Extending make_shared to
  Support Arrays

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP20_SHARED_PTR_ARRAYS
  #define LBAL_LIBCPP20_SHARED_PTR_ARRAYS 0
#endif

/**
  @def LBAL_LIBCPP20_SHIFT
  @brief Add `std::shift_left` and `std::shift_right`
  @details SD-6 equivalent: `__cpp_lib_shift >= 201806L`. Note that
  `__cpp_lib_shift` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201806L` [P0769R2](https://wg21.link/P0769R2) Add shift to `<algorithm>`

  @sa `<algorithm>`
*/
#ifndef LBAL_LIBCPP20_SHIFT
  #define LBAL_LIBCPP20_SHIFT 0
#endif

/**
  @def LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE
  @brief Support smart pointer creation with default initialization
  @details SD-6 equivalent: `__cpp_lib_smart_ptr_for_overwrite >= 202002L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202002L` [P1020R1](https://wg21.link/P1020R1) Smart pointer creation with
  default initialization
  - `202002L` [P1973R1](https://wg21.link/P1973R1) Rename _default_init
  functions (NB Comment DE002)

  @remark The SD-6 token was renamed as part of [P1973R1](https://wg21.link/
  P1973R1), which also updated its value. We don’t track the original.

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE
  #define LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE 0
#endif

/**
  @def LBAL_LIBCPP20_SOURCE_LOCATION
  @brief Adopt `std::source_location` from the Library Fundamentals V3 TS
  @details SD-6 equivalent: `__cpp_lib_source_location >= 201907L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201907L` [P1208R6](https://wg21.link/P1208R6) Adopt source location from
  Library Fundamentals V3 for C++20

  @sa `<source_location>`
*/
#ifndef LBAL_LIBCPP20_SOURCE_LOCATION
  #define LBAL_LIBCPP20_SOURCE_LOCATION 0
#endif

/**
  @def LBAL_LIBCPP20_SPAN
  @brief Add `std::span`
  @details SD-6 equivalent: `__cpp_lib_span >= 201803L`. Note that
  `__cpp_lib_span` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201803L` [LWG3274](https://wg21.link/LWG3274) Missing feature test macro
  for `<span>`
  - `201803L` [P0122R7](https://wg21.link/P0122R7) `span`: bounds-safe views for
  sequences of objects

  @remark The issue raised in [LWG3274](https://wg21.link/LWG3274) was simply
  that [P0122R7](https://wg21.link/P0122R7) had been voted in without specifying
  an SD-6 macro.

  @sa `<span>`
*/
#ifndef LBAL_LIBCPP20_SPAN
  #define LBAL_LIBCPP20_SPAN 0
#endif

/**
  @def LBAL_LIBCPP20_SPAN_FIXED_SIZE
  @brief Fix constructing a fixed-size `std::span` from a dynamic range
  @details SD-6 equivalent: `__cpp_lib_span >= 202002L`. Note that
  `__cpp_lib_span` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202002L` [P1976R2](https://wg21.link/P1976R2) Fixed-size span construction
  from dynamic range

  @sa `<span>`
*/
#ifndef LBAL_LIBCPP20_SPAN_FIXED_SIZE
  #define LBAL_LIBCPP20_SPAN_FIXED_SIZE 0
#endif

/**
  @def LBAL_LIBCPP20_SPAN_USABILITY
  @brief Enhance usability for `std::span`
  @details SD-6 equivalent: `__cpp_lib_span >= 201902L`. Note that
  `__cpp_lib_span` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201902L` [P1024R3](https://wg21.link/P1024R3) Usability Enhancements for
  std::span

  @sa `<span>`
*/
#ifndef LBAL_LIBCPP20_SPAN_USABILITY
  #define LBAL_LIBCPP20_SPAN_USABILITY 0
#endif

/**
  @def LBAL_LIBCPP20_SSIZE
  @brief Add `std::ssize` and fix `std::span`’s `size` return values
  @details SD-6 equivalent: `__cpp_lib_ssize >= 201902L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `201902L` [P1227R2](https://wg21.link/P1227R2) Signed ssize() functions,
  unsigned size() functions

  @remark It’s conceivable that the `<span>`-affecting portions of this will be
  shifted to the `__cpp_lib_span` token.

  @sa `<iterator>`
*/
#ifndef LBAL_LIBCPP20_SSIZE
  #define LBAL_LIBCPP20_SSIZE 0
#endif

/**
  @def LBAL_LIBCPP20_STARTS_ENDS_WITH
  @brief Add string prefix- and suffix-checking
  @details SD-6 equivalent: `__cpp_lib_starts_ends_with >= 201711L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201711L` [P0457R2](https://wg21.link/P0457R2) String Prefix and Suffix
  Checking

  @sa `<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP20_STARTS_ENDS_WITH
  #define LBAL_LIBCPP20_STARTS_ENDS_WITH 0
#endif

/**
  @def LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR
  @brief Add support for `constexpr` iterators to `<string_view>`
  @details SD-6 equivalent: `__cpp_lib_string_view >= 201803L`. Note that
  `__cpp_lib_string_view` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201803L` [LWG3257](https://wg21.link/LWG3257) Missing feature testing macro
  update from P0858
  - `201803L` [P0858R0](https://wg21.link/P0858R0) Constexpr iterator
  requirements

  @remark The issue raised in [LWG3257](https://wg21.link/LWG3257) was simply
  that the SD-6 macro update voted in with [P0858R0](https://wg21.link/P0858R0)
  had not been applied.

  @sa `<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR
  #define LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR 0
#endif

/**
  @def LBAL_LIBCPP20_SYNCBUF
  @brief Add synchronized buffered output streams
  @details SD-6 equivalent: `__cpp_lib_syncbuf >= 201711L`. Note that
  `__cpp_lib_syncbuf` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201711L` [P0053R7 __PDF__](https://wg21.link/P0053R7) C++ Synchronized
  Buffered Ostream

  @sa `<syncstream>`
*/
#ifndef LBAL_LIBCPP20_SYNCBUF
  #define LBAL_LIBCPP20_SYNCBUF 0
#endif

/**
  @def LBAL_LIBCPP20_SYNCBUF_MANIPULATORS
  @brief Add manipulators for synchronized buffered output streams
  @details SD-6 equivalent: `__cpp_lib_syncbuf >= 201803L`. Note that
  `__cpp_lib_syncbuf` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201803L` [P0753R2 __PDF__](https://wg21.link/P0753R2) Manipulators for C++
  Synchronized Buffered Ostream

  @sa `<syncstream>`
*/
#ifndef LBAL_LIBCPP20_SYNCBUF_MANIPULATORS
  #define LBAL_LIBCPP20_SYNCBUF_MANIPULATORS 0
#endif

/**
  @def LBAL_LIBCPP20_THREE_WAY_COMPARISON
  @brief Add `<compare>` to the Standard Library
  @details SD-6 equivalent: `__cpp_lib_three_way_comparison >= 201711L`. Note
  that `__cpp_lib_three_way_comparison` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `201711L` [P0768R1 __PDF__](https://wg21.link/P0768R1) Library Support for
  the Spaceship (Comparison) Operator

  @sa `<compare>`
*/
#ifndef LBAL_LIBCPP20_THREE_WAY_COMPARISON
  #define LBAL_LIBCPP20_THREE_WAY_COMPARISON 0
#endif

/**
  @def LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY
  @brief Add three-way comparison support to the Standard Library
  @details SD-6 equivalent: `__cpp_lib_three_way_comparison >= 201907L`. Note
  that `__cpp_lib_three_way_comparison` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `201907L` [P1614R2](https://wg21.link/P1614R2) The Mothership Has Landed:
  Adding <=> to the Library

  @sa `<compare>`
*/
#ifndef LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY
  #define LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY 0
#endif

/**
  @def LBAL_LIBCPP20_TO_ADDRESS
  @brief Provide a utility to convert a pointer to a raw pointer
  @details SD-6 equivalent: `__cpp_lib_to_address >= 201711L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201711L` [P0653R2 __PDF__](https://wg21.link/P0653R2) Utility to convert a
  pointer to a raw pointer

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP20_TO_ADDRESS
  #define LBAL_LIBCPP20_TO_ADDRESS 0
#endif

/**
  @def LBAL_LIBCPP20_TO_ARRAY
  @brief Adopt `std::to_array` from the Library Fundamentals TS
  @details SD-6 equivalent: `__cpp_lib_to_array >= 201907L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201907L` [P0325R4](https://wg21.link/P0325R4) to_array from LFTS with
  updates

  @sa `<array>`
*/
#ifndef LBAL_LIBCPP20_TO_ARRAY
  #define LBAL_LIBCPP20_TO_ARRAY 0
#endif

/**
  @def LBAL_LIBCPP20_TYPE_IDENTITY
  @brief Add the `std::identity` metafunction
  @details SD-6 equivalent: `__cpp_lib_type_identity >= 201806L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201806L` [P0887R1 __PDF__](https://wg21.link/P0887R1) The identity
  metafunction

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP20_TYPE_IDENTITY
  #define LBAL_LIBCPP20_TYPE_IDENTITY 0
#endif

/**
  @def LBAL_LIBCPP20_UNWRAP_REF
  @brief Add `std::unwrap_reference` and `std::unwrap_ref_decay`
  @details SD-6 equivalent: `__cpp_lib_unwrap_ref >= 201811L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201811L` [LWG3348](https://wg21.link/LWG3348) __cpp_lib_unwrap_ref in wrong
  header
  - `201811L` [P0318R1 __PDF__](https://wg21.link/P0318R1) unwrap_ref_decay
  and unwrap_reference

  @remark Originally, this was in `<type_traits>`.

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP20_UNWRAP_REF
  #define LBAL_LIBCPP20_UNWRAP_REF 0
#endif

/**
  @def LBAL_LIBCPP20_VERSION
  @brief Identifies whether `<version>` is present and include-able given the
  current C++ Standard dialect in use
  @details Unlike `<version>`, lucenaBAL tracks “correct”, functioning
  implementations only. For this reason, it is recommended to _always_ favor the
  `lucenaBAL` reporting of a given feature’s availability, even when `<version>`
  is available.

  @remark An example of false negative reporting is Xcode (again) always
  reporting certain library fearures as unavailable when they’re actually gated
  depending on the version of the SDK in use (e.g., `__cpp_lib_to_chars`).

  @remark An example of false positive reporting in `version` is older Xcodes’
  claim for support for `<any>` and friends before they were actually working.

  @remark Some implementations may choose to back-port `<version>` to earlier
  releases, in which case this token will be set.
*/
#ifndef LBAL_LIBCPP20_VERSION
  #define LBAL_LIBCPP20_VERSION 0
#endif

///	@}	LBAL_LIBCPP20

/**
  @name LBAL_LIBCPP23

  @brief These are all taken from features that have been incorporated into
  the C++23 Standard.

  @{
*/

/**
  @def LBAL_LIBCPP23_ADAPTOR_ITERATOR_PAIR_CONSTRUCTOR
  @brief Iterators `pair` constructors for `stack` and `queue`
  @details SD-6 equivalent: `__cpp_lib_adaptor_iterator_pair_constructor >=
  202106L`. This token will have a value of `0` if the proposal described here
  is not supported.
  - `202106L` [P1425R4 __PDF__](https://wg21.link/P1425R4) Iterators pair
  constructors for stack and queue

  @sa `<queue>` `<stack>`
*/
#ifndef LBAL_LIBCPP23_ADAPTOR_ITERATOR_PAIR_CONSTRUCTOR
  #define LBAL_LIBCPP23_ADAPTOR_ITERATOR_PAIR_CONSTRUCTOR 0
#endif

/**
  @def LBAL_LIBCPP23_ALGORITHM_ITERATOR_REQUIREMENTS
  @brief Ranges iterators as inputs to non-Ranges algorithms
  @details SD-6 equivalent: `__cpp_lib_algorithm_iterator_requirements >=
  202207L`. This token will have a value of `0` if the proposal described here
  is not supported.
  - `202207L` [P2408R5 __PDF__](https://wg21.link/P2408R5) Ranges iterators as
  inputs to non-Ranges algorithms

  @sa `<algorithm>` `<memory>` `<numeric>`
*/
#ifndef LBAL_LIBCPP23_ALGORITHM_ITERATOR_REQUIREMENTS
  #define LBAL_LIBCPP23_ALGORITHM_ITERATOR_REQUIREMENTS 0
#endif

/**
  @def LBAL_LIBCPP23_ALLOCATE_AT_LEAST
  @brief Provide size feedback in the Allocator interface
  @details SD-6 equivalent: `__cpp_lib_allocate_at_least >= 202106L`. Note that
  `__cpp_lib_allocate_at_least` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202106L` [P0401R6](https://wg21.link/P0401R6) Providing size feedback in
  the Allocator interface

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP23_ALLOCATE_AT_LEAST
  #define LBAL_LIBCPP23_ALLOCATE_AT_LEAST 0
#endif

/**
  @def LBAL_LIBCPP23_ALLOCATE_AT_LEAST_DISALLOW_USER_SPEC
  @brief Disallow user specialization of `allocator_traits`
  @details SD-6 equivalent: `__cpp_lib_allocate_at_least >= 202302L`. Note that
  `__cpp_lib_allocate_at_least` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202302L` [LWG3887](https://wg21.link/LWG3887) Version macro for
  allocate_at_least
  - `202302L` [P2652R2](https://wg21.link/P2652R2) Disallow user specialization
  of allocator_traits

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP23_ALLOCATE_AT_LEAST_DISALLOW_USER_SPEC
  #define LBAL_LIBCPP23_ALLOCATE_AT_LEAST_DISALLOW_USER_SPEC 0
#endif

/**
  @def LBAL_LIBCPP23_ASSOCIATIVE_HETEROGENEOUS_ERASURE
  @brief Heterogeneous erasure overloads for associative containers
  @details SD-6 equivalent: `__cpp_lib_associative_heterogeneous_erasure >=
  202110L`. This token will have a value of `0` if the proposal described here
  is not supported.
  - `202110L` [P2077R3](https://wg21.link/P2077R3) Heterogeneous erasure
  overloads for associative containers

  @sa `<map>` `<set>` `<unordered_map>` `<unordered_set>`
*/
#ifndef LBAL_LIBCPP23_ASSOCIATIVE_HETEROGENEOUS_ERASURE
  #define LBAL_LIBCPP23_ASSOCIATIVE_HETEROGENEOUS_ERASURE 0
#endif

/**
  @def LBAL_LIBCPP23_BARRIER_RELAXED_COMPLETION
  @brief Relax `std::barrier` phase completion step guarantees
  @details SD-6 equivalent: `__cpp_lib_barrier >= 202302L`. Note that
  `__cpp_lib_barrier` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202302L` [P2588R3](https://wg21.link/P2588R3) Relax std::barrier phase
  completion step guarantees

  @sa `<barrier>`
*/
#ifndef LBAL_LIBCPP23_BARRIER_RELAXED_COMPLETION
  #define LBAL_LIBCPP23_BARRIER_RELAXED_COMPLETION 0
#endif

/**
  @def LBAL_LIBCPP23_BIND_BACK
  @brief Pipe support for user-defined range adaptors
  @details SD-6 equivalent: `__cpp_lib_bind_back >= 202202L`. Note that
  `__cpp_lib_bind_back` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202202L` [P2387R3](https://wg21.link/P2387R3) Pipe support for user-defined
  range adaptors

  @sa `<functional>`
*/
#ifndef LBAL_LIBCPP23_BIND_BACK
  #define LBAL_LIBCPP23_BIND_BACK 0
#endif

/**
  @def LBAL_LIBCPP23_BYTESWAP
  @brief Byteswapping for fun&&nuf
  @details SD-6 equivalent: `__cpp_lib_byteswap >= 202110L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202110L` [P1272R4](https://wg21.link/P1272R4) Byteswapping for fun&&nuf

  @sa `<bit>`
*/
#ifndef LBAL_LIBCPP23_BYTESWAP
  #define LBAL_LIBCPP23_BYTESWAP 0
#endif

/**
  @def LBAL_LIBCPP23_COMMON_REFERENCE
  @brief common_reference_t of reference_wrapper Should Be a Reference Type
  @details SD-6 equivalent: `__cpp_lib_common_reference >= 202302L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202302L` [P2655R3](https://wg21.link/P2655R3) common_reference_t of
  reference_wrapper Should Be a Reference Type

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP23_COMMON_REFERENCE
  #define LBAL_LIBCPP23_COMMON_REFERENCE 0
#endif

/**
  @def LBAL_LIBCPP23_COMMON_REFERENCE_WRAPPER
  @brief common_reference_t of reference_wrapper Should Be a Reference Type
  @details SD-6 equivalent: `__cpp_lib_common_reference_wrapper >= 202302L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202302L` [P2655R3](https://wg21.link/P2655R3) common_reference_t of
  reference_wrapper Should Be a Reference Type

  @sa `<functional>`
*/
#ifndef LBAL_LIBCPP23_COMMON_REFERENCE_WRAPPER
  #define LBAL_LIBCPP23_COMMON_REFERENCE_WRAPPER 0
#endif

/**
  @def LBAL_LIBCPP23_CONCEPTS_MOVE_ONLY
  @brief Add move-only types for `equality_comparable_with`,
  `totally_ordered_with`, and `three_way_comparable_with`
  @details SD-6 equivalent: `__cpp_lib_concepts >= 202207L`. Note that
  `__cpp_lib_concepts` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P2404R3](https://wg21.link/P2404R3) Move-only types for
  equality_comparable_with, totally_ordered_with, and three_way_comparable_with

  @sa `<compare>` `<concepts>`
*/
#ifndef LBAL_LIBCPP23_CONCEPTS_MOVE_ONLY
  #define LBAL_LIBCPP23_CONCEPTS_MOVE_ONLY 0
#endif

/**
  @def LBAL_LIBCPP23_CONSTEXPR_BITSET
  @brief A more constexpr bitset
  @details SD-6 equivalent: `__cpp_lib_constexpr_bitset >= 202207L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202207L` [P2417R2](https://wg21.link/P2417R2) A more constexpr bitset

  @sa `<bitset>`
*/
#ifndef LBAL_LIBCPP23_CONSTEXPR_BITSET
  #define LBAL_LIBCPP23_CONSTEXPR_BITSET 0
#endif

/**
  @def LBAL_LIBCPP23_CONSTEXPR_CHARCONV
  @brief Add Constexpr Modifiers to Functions to_chars and from_chars for
  Integral Types in Header
  @details SD-6 equivalent: `__cpp_lib_constexpr_charconv >= 202207L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202207L` [P2291R3](https://wg21.link/P2291R3) Add Constexpr Modifiers to
  Functions to_chars and from_chars for Integral Types in Header

  @sa `<charconv>`
*/
#ifndef LBAL_LIBCPP23_CONSTEXPR_CHARCONV
  #define LBAL_LIBCPP23_CONSTEXPR_CHARCONV 0
#endif

/**
  @def LBAL_LIBCPP23_CONSTEXPR_CMATH
  @brief constexpr for cmath and cstdlib
  @details SD-6 equivalent: `__cpp_lib_constexpr_cmath >= 202202L`. Note that
  `__cpp_lib_constexpr_cmath` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202202L` [P0533R9](https://wg21.link/P0533R9) constexpr for cmath and
  cstdlib

  @sa `<cmath>` `<cstdlib>`
*/
#ifndef LBAL_LIBCPP23_CONSTEXPR_CMATH
  #define LBAL_LIBCPP23_CONSTEXPR_CMATH 0
#endif

/**
  @def LBAL_LIBCPP23_CONSTEXPR_MEMORY_UNIQUE_PTR
  @brief Make `std::unique_ptr` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_memory >= 202202L`. Note that
  `__cpp_lib_constexpr_memory` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202202L` [P2273R3](https://wg21.link/P2273R3) Making std::unique_ptr
  constexpr

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP23_CONSTEXPR_MEMORY_UNIQUE_PTR
  #define LBAL_LIBCPP23_CONSTEXPR_MEMORY_UNIQUE_PTR 0
#endif

/**
  @def LBAL_LIBCPP23_CONSTEXPR_TYPEINFO
  @brief Making std::type_info::operator== constexpr
  @details SD-6 equivalent: `__cpp_lib_constexpr_typeinfo >= 202106L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202106L` [P1328R1](https://wg21.link/P1328R1) Making
  std::type_info::operator== constexpr

  @sa `<typeinfo>`
*/
#ifndef LBAL_LIBCPP23_CONSTEXPR_TYPEINFO
  #define LBAL_LIBCPP23_CONSTEXPR_TYPEINFO 0
#endif

/**
  @def LBAL_LIBCPP23_CONTAINERS_RANGES
  @brief Conversions from ranges to containers
  @details SD-6 equivalent: `__cpp_lib_containers_ranges >= 202202L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202202L` [P1206R7](https://wg21.link/P1206R7) Conversions from ranges to
  containers

  @sa `<deque>` `<forward_list>` `<list>` `<map>` `<queue>` `<set>` `<stack>`
  `<string>` `<unordered_map>` `<unordered_set>` `<vector>`
*/
#ifndef LBAL_LIBCPP23_CONTAINERS_RANGES
  #define LBAL_LIBCPP23_CONTAINERS_RANGES 0
#endif

/**
  @def LBAL_LIBCPP23_EXPECTED
  @brief std::expected
  @details SD-6 equivalent: `__cpp_lib_expected >= 202202L`. Note that
  `__cpp_lib_expected` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202202L` [P0323R12](https://wg21.link/P0323R12) std::expected

  @sa `<expected>`
*/
#ifndef LBAL_LIBCPP23_EXPECTED
  #define LBAL_LIBCPP23_EXPECTED 0
#endif

/**
  @def LBAL_LIBCPP23_EXPECTED_MONADIC
  @brief Monadic Functions for std::expected
  @details SD-6 equivalent: `__cpp_lib_expected >= 202211L`. Note that
  `__cpp_lib_expected` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202211L` [P2505R5](https://wg21.link/P2505R5) Monadic Functions for
  std::expected

  @sa `<expected>`
*/
#ifndef LBAL_LIBCPP23_EXPECTED_MONADIC
  #define LBAL_LIBCPP23_EXPECTED_MONADIC 0
#endif

/**
  @def LBAL_LIBCPP23_FLAT_MAP
  @brief A Standard flat_map
  @details SD-6 equivalent: `__cpp_lib_flat_map >= 202207L`. Note that
  `__cpp_lib_flat_map` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P0429R9](https://wg21.link/P0429R9) A Standard flat_map

  @sa `<flat_map>`
*/
#ifndef LBAL_LIBCPP23_FLAT_MAP
  #define LBAL_LIBCPP23_FLAT_MAP 0
#endif

/**
  @def LBAL_LIBCPP23_FLAT_SET
  @brief A Standard flat_set
  @details SD-6 equivalent: `__cpp_lib_flat_set >= 202207L`. Note that
  `__cpp_lib_flat_set` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202207L` [LWG3751](https://wg21.link/LWG3751) Missing feature macro for
  flat_set
  - `202207L` [P1222R4](https://wg21.link/P1222R4) A Standard flat_set

  @sa `<flat_set>`
*/
#ifndef LBAL_LIBCPP23_FLAT_SET
  #define LBAL_LIBCPP23_FLAT_SET 0
#endif

/**
  @def LBAL_LIBCPP23_FORMAT
  @brief Add `std::format` improvements
  @details SD-6 equivalent: `__cpp_lib_format >= 202106L`. Note that
  `__cpp_lib_format` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202106L` [P2216R3](https://wg21.link/P2216R3) std::format improvements

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP23_FORMAT
  #define LBAL_LIBCPP23_FORMAT 0
#endif

/**
  @def LBAL_LIBCPP23_FORMATTERS
  @brief Formatting thread::id and stacktrace
  @details SD-6 equivalent: `__cpp_lib_formatters >= 202302L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202302L` [P2693R1](https://wg21.link/P2693R1) Formatting thread::id and
  stacktrace

  @sa `<stacktrace>` `<thread>`
*/
#ifndef LBAL_LIBCPP23_FORMATTERS
  #define LBAL_LIBCPP23_FORMATTERS 0
#endif

/**
  @def LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING
  @brief Exposing `std::basic_format_string`
  @details SD-6 equivalent: `__cpp_lib_format >= 202207L`. Note that
  `__cpp_lib_format` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P2508R1](https://wg21.link/P2508R1) Exposing std::basic-format-
  string

  @remark This and `LBAL_LIBCPP23_FORMAT_ENCODINGS` were voted in at the same
  time and share the same SD-6 token and value; however, we track them as
  separate features.

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING
  #define LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING 0
#endif

/**
  @def LBAL_LIBCPP23_FORMAT_ENCODINGS
  @brief Clarify encoding handling in localized formatting of `<chrono>` types
  @details SD-6 equivalent: `__cpp_lib_format >= 202207L`. Note that
  `__cpp_lib_format` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P2419R2](https://wg21.link/P2419R2) Clarify handling of encodings
  in localized formatting of chrono types

  @remark This and `LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING` were voted in at
  the same time and share the same SD-6 token and value; however, we track them
  as separate features.

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP23_FORMAT_ENCODINGS
  #define LBAL_LIBCPP23_FORMAT_ENCODINGS 0
#endif

/**
  @def LBAL_LIBCPP23_FORMAT_GENERATOR
  @brief Add support for `std::generator`-like types to `std::format`
  @details SD-6 equivalent: `__cpp_lib_format >= 202110L`. Note that
  `__cpp_lib_format` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202110L` [P2418R2](https://wg21.link/P2418R2) Add support for
  std::generator-like types to std::format

  @remark This and `LBAL_LIBCPP23_FORMAT_LOCALE` were voted in at the same time
  and share the same SD-6 token and value; however, we track them as separate
  features.

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP23_FORMAT_GENERATOR
  #define LBAL_LIBCPP23_FORMAT_GENERATOR 0
#endif

/**
  @def LBAL_LIBCPP23_FORMAT_LOCALE
  @brief Fix locale handling in `std::chrono` formatters
  @details SD-6 equivalent: `__cpp_lib_format >= 202110L`. Note that
  `__cpp_lib_format` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202110L` [P2372R3](https://wg21.link/P2372R3) Fixing locale handling in
  chrono formatters

  @remark This and `LBAL_LIBCPP23_FORMAT_GENERATOR` were voted in at the same
  time and share the same SD-6 token and value; however, we track them as
  separate features.

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP23_FORMAT_LOCALE
  #define LBAL_LIBCPP23_FORMAT_LOCALE 0
#endif

/**
  @def LBAL_LIBCPP23_FORMAT_RANGES
  @brief Formatting Ranges
  @details SD-6 equivalent: `__cpp_lib_format_ranges >= 202207L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202207L` [LWG3750](https://wg21.link/LWG3750) Too many papers bump
  __cpp_lib_format
  - `202207L` [P2286R8](https://wg21.link/P2286R8) Formatting Ranges
  - `202207L` [P2585R1](https://wg21.link/P2585R1) Improving default container
  formatting

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP23_FORMAT_RANGES
  #define LBAL_LIBCPP23_FORMAT_RANGES 0
#endif

/**
  @def LBAL_LIBCPP23_FORWARD_LIKE
  @brief forward_like
  @details SD-6 equivalent: `__cpp_lib_forward_like >= 202207L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202207L` [P2445R1](https://wg21.link/P2445R1) forward_like

  @sa `<utility>`
*/
#ifndef LBAL_LIBCPP23_FORWARD_LIKE
  #define LBAL_LIBCPP23_FORWARD_LIKE 0
#endif

/**
  @def LBAL_LIBCPP23_GENERATOR
  @brief std::generator: Synchronous Coroutine Generator for Ranges
  @details SD-6 equivalent: `__cpp_lib_generator >= 202207L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202207L` [P2502R2](https://wg21.link/P2502R2) std::generator: Synchronous
  Coroutine Generator for Ranges

  @sa `<generator>`
*/
#ifndef LBAL_LIBCPP23_GENERATOR
  #define LBAL_LIBCPP23_GENERATOR 0
#endif

/**
  @def LBAL_LIBCPP23_INVOKE_R
  @brief invoke_r
  @details SD-6 equivalent: `__cpp_lib_invoke_r >= 202106L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202106L` [P2136R3](https://wg21.link/P2136R3) invoke_r

  @sa `<functional>`
*/
#ifndef LBAL_LIBCPP23_INVOKE_R
  #define LBAL_LIBCPP23_INVOKE_R 0
#endif

/**
  @def LBAL_LIBCPP23_IOS_NOREPLACE
  @brief Support exclusive mode for fstreams
  @details SD-6 equivalent: `__cpp_lib_ios_noreplace >= 202207L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202207L` [P2467R1](https://wg21.link/P2467R1) Support exclusive mode for
  fstreams

  @sa `<ios>`
*/
#ifndef LBAL_LIBCPP23_IOS_NOREPLACE
  #define LBAL_LIBCPP23_IOS_NOREPLACE 0
#endif

/**
  @def LBAL_LIBCPP23_IS_IMPLICIT_LIFETIME
  @brief A trait for implicit lifetime types
  @details SD-6 equivalent: `__cpp_lib_is_implicit_lifetime >= 202302L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202302L` [P2674R1](https://wg21.link/P2674R1) A trait for implicit lifetime
  types

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP23_IS_IMPLICIT_LIFETIME
  #define LBAL_LIBCPP23_IS_IMPLICIT_LIFETIME 0
#endif

/**
  @def LBAL_LIBCPP23_IS_SCOPED_ENUM
  @brief A proposal for a type trait to detect scoped enumerations
  @details SD-6 equivalent: `__cpp_lib_is_scoped_enum >= 202011L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202011L` [P1048R1](https://wg21.link/P1048R1) A proposal for a type trait
  to detect scoped enumerations

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP23_IS_SCOPED_ENUM
  #define LBAL_LIBCPP23_IS_SCOPED_ENUM 0
#endif

/**
  @def LBAL_LIBCPP23_MDSPAN
  @brief `mdspan`
  @details SD-6 equivalent: `__cpp_lib_mdspan >= 202207L`. Note that
  `__cpp_lib_mdspan` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P0009R18](https://wg21.link/P0009R18) MDSPAN
  - `202207L` [P2599R2](https://wg21.link/P2599R2) index _type & size_type in
  mdspan
  - `202207L` [P2604R0](https://wg21.link/P2604R0) MDSPAN: rename pointer and
  contiguous
  - `202207L` [P2613R1](https://wg21.link/P2613R1) Add the missing empty to
  mdspan

  @sa `<mdspan>`
*/
#ifndef LBAL_LIBCPP23_MDSPAN
  #define LBAL_LIBCPP23_MDSPAN 0
#endif

/**
  @def LBAL_LIBCPP23_MODULES
  @brief Standard Library Modules std and std.compat
  @details SD-6 equivalent: `__cpp_lib_modules >= 202207L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `202207L` [P2465R3](https://wg21.link/P2465R3) Standard Library Modules std
  and std.compat
*/
#ifndef LBAL_LIBCPP23_MODULES
  #define LBAL_LIBCPP23_MODULES 0
#endif

/**
  @def LBAL_LIBCPP23_MOVE_ITERATOR_CONCEPT
  @brief move_iterator should be a random access iterator
  @details SD-6 equivalent: `__cpp_lib_move_iterator_concept >= 202207L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202207L` [P2520R0](https://wg21.link/P2520R0) move_iterator should be a
  random access iterator

  @sa `<iterator>`
*/
#ifndef LBAL_LIBCPP23_MOVE_ITERATOR_CONCEPT
  #define LBAL_LIBCPP23_MOVE_ITERATOR_CONCEPT 0
#endif

/**
  @def LBAL_LIBCPP23_MOVE_ONLY_FUNCTION
  @brief move_only_function (was any_invocable)
  @details SD-6 equivalent: `__cpp_lib_move_only_function >= 202110L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202110L` [P0288R9](https://wg21.link/P0288R9) move_only_function (was
  any_invocable)

  @sa `<functional>`
*/
#ifndef LBAL_LIBCPP23_MOVE_ONLY_FUNCTION
  #define LBAL_LIBCPP23_MOVE_ONLY_FUNCTION 0
#endif

/**
  @def LBAL_LIBCPP23_OPTIONAL_CONSTEXPR
  @brief Add further `constexpr` support for `std::optional`
  @details SD-6 equivalent: `__cpp_lib_optional >= 202106L`. Note that
  `__cpp_lib_optional` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202106L` [P2231R1](https://wg21.link/P2231R1) Add further constexpr support
  for optional/variant

  @sa `<optional>`
*/
#ifndef LBAL_LIBCPP23_OPTIONAL_CONSTEXPR
  #define LBAL_LIBCPP23_OPTIONAL_CONSTEXPR 0
#endif

/**
  @def LBAL_LIBCPP23_OPTIONAL_MONADIC
  @brief Add monadic operations for `std::optional`
  @details SD-6 equivalent: `__cpp_lib_optional >= 202110L`. Note that
  `__cpp_lib_optional` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202110L` [LWG3621](https://wg21.link/LWG3621) Remove feature-test macro
  __cpp_lib_monadic_optional
  - `202110L` [P0798R8](https://wg21.link/P0798R8) Monadic operations for
  std::optional

  @remark Note that this is mostly about [`p0798r8`](https://wg21.link/p0798r8);
  [`lwg3621`](https://wg21.link/lwg3621) was an SD-6 administrative fixup for an
  oversight in the approval process for `p0798r8`.

  @sa `<optional>`
*/
#ifndef LBAL_LIBCPP23_OPTIONAL_MONADIC
  #define LBAL_LIBCPP23_OPTIONAL_MONADIC 0
#endif

/**
  @def LBAL_LIBCPP23_OUT_PTR
  @brief out_ptr - a scalable output pointer abstraction
  @details SD-6 equivalent: `__cpp_lib_out_ptr >= 202106L`. Note that
  `__cpp_lib_out_ptr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202106L` [P1132R7](https://wg21.link/P1132R7) out_ptr - a scalable output
  pointer abstraction

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP23_OUT_PTR
  #define LBAL_LIBCPP23_OUT_PTR 0
#endif

/**
  @def LBAL_LIBCPP23_PRINT
  @brief Formatted output
  @details SD-6 equivalent: `__cpp_lib_print >= 202207L`. Note that
  `__cpp_lib_print` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P2093R14](https://wg21.link/P2093R14) Formatted output

  @sa `<ostream>` `<print>`
*/
#ifndef LBAL_LIBCPP23_PRINT
  #define LBAL_LIBCPP23_PRINT 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_AS_CONST
  @brief cbegin should always return a constant iterator
  @details SD-6 equivalent: `__cpp_lib_ranges_as_const >= 202207L`. Note that
  `__cpp_lib_ranges_as_const` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P2278R4](https://wg21.link/P2278R4) cbegin should always return a
  constant iterator

  @sa `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_AS_CONST
  #define LBAL_LIBCPP23_RANGES_AS_CONST 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_AS_RVALUE
  @brief views::as_rvalue
  @details SD-6 equivalent: `__cpp_lib_ranges_as_rvalue >= 202207L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202207L` [P2446R2](https://wg21.link/P2446R2) views::as_rvalue

  @sa `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_AS_RVALUE
  #define LBAL_LIBCPP23_RANGES_AS_RVALUE 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT
  @brief views::cartesian_product
  @details SD-6 equivalent: `__cpp_lib_ranges_cartesian_product >= 202207L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202207L` [P2374R4](https://wg21.link/P2374R4) views::cartesian_product

  @sa `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT
  #define LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT_EMPTY
  @brief Empty Product for certain Views
  @details SD-6 equivalent: `__cpp_lib_ranges_cartesian_product >= 202207L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202207L` [P2540R1](https://wg21.link/P2540R1) Empty Product for certain
  Views

  @sa `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT_EMPTY
  #define LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT_EMPTY 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_CHUNK
  @brief Windowing range adaptors: views::chunk and views::slide
  @details SD-6 equivalent: `__cpp_lib_ranges_chunk >= 202202L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202202L` [P2442R1](https://wg21.link/P2442R1) Windowing range adaptors:
  views::chunk and views::slide

  @sa `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_CHUNK
  #define LBAL_LIBCPP23_RANGES_CHUNK 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_CHUNK_BY
  @brief views::chunk_by
  @details SD-6 equivalent: `__cpp_lib_ranges_chunk_by >= 202202L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202202L` [P2443R1](https://wg21.link/P2443R1) views::chunk_by

  @sa `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_CHUNK_BY
  #define LBAL_LIBCPP23_RANGES_CHUNK_BY 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_CONTAINS
  @brief std::ranges::contains
  @details SD-6 equivalent: `__cpp_lib_ranges_contains >= 202207L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202207L` [P2302R4](https://wg21.link/P2302R4) std::ranges::contains

  @sa `<algorithm>`
*/
#ifndef LBAL_LIBCPP23_RANGES_CONTAINS
  #define LBAL_LIBCPP23_RANGES_CONTAINS 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_ENUMERATE
  @brief views::enumerate
  @details SD-6 equivalent: `__cpp_lib_ranges_enumerate >= 202302L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202302L` [P2164R9](https://wg21.link/P2164R9) views::enumerate

  @sa `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_ENUMERATE
  #define LBAL_LIBCPP23_RANGES_ENUMERATE 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_FIND_LAST
  @brief find_last
  @details SD-6 equivalent: `__cpp_lib_ranges_find_last >= 202207L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202207L` [LWG3807](https://wg21.link/LWG3807) The feature test macro for
  ranges::find_last should be renamed
  - `202207L` [P1223R5](https://wg21.link/P1223R5) find_last

  @sa `<algorithm>`
*/
#ifndef LBAL_LIBCPP23_RANGES_FIND_LAST
  #define LBAL_LIBCPP23_RANGES_FIND_LAST 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_FOLD
  @brief ranges::fold
  @details SD-6 equivalent: `__cpp_lib_ranges_fold >= 202207L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202207L` [P2322R6](https://wg21.link/P2322R6) ranges::fold

  @sa `<algorithm>`
*/
#ifndef LBAL_LIBCPP23_RANGES_FOLD
  #define LBAL_LIBCPP23_RANGES_FOLD 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_FORMALIZED_VIEW
  @brief What is a view?
  @details SD-6 equivalent: `__cpp_lib_ranges >= 202110L`. Note that
  `__cpp_lib_ranges` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202110L` [P2415R2](https://wg21.link/P2415R2) What is a view?

  @sa `<algorithm>` `<functional>` `<iterator>` `<memory>` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_FORMALIZED_VIEW
  #define LBAL_LIBCPP23_RANGES_FORMALIZED_VIEW 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_IOTA
  @brief ranges::iota, ranges::shift_left, and ranges::shift_right
  @details SD-6 equivalent: `__cpp_lib_ranges_iota >= 202202L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202202L` [P2440R1](https://wg21.link/P2440R1) ranges::iota,
  ranges::shift_left, and ranges::shift_right

  @sa `<numeric>`
*/
#ifndef LBAL_LIBCPP23_RANGES_IOTA
  #define LBAL_LIBCPP23_RANGES_IOTA 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_JOIN_WITH
  @brief views::join_with
  @details SD-6 equivalent: `__cpp_lib_ranges_join_with >= 202202L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202202L` [P2441R2](https://wg21.link/P2441R2) views::join_with

  @sa `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_JOIN_WITH
  #define LBAL_LIBCPP23_RANGES_JOIN_WITH 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_NON_DEFAULT_CONSTRUCTIBLE
  @brief Views should not be required to be default constructible
  @details SD-6 equivalent: `__cpp_lib_ranges >= 202106L`. Note that
  `__cpp_lib_ranges` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202106L` [P2325R3](https://wg21.link/P2325R3) Views should not be required
  to be default constructible

  @sa `<algorithm>` `<functional>` `<iterator>` `<memory>` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_NON_DEFAULT_CONSTRUCTIBLE
  #define LBAL_LIBCPP23_RANGES_NON_DEFAULT_CONSTRUCTIBLE 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_RELAXED
  @brief Relaxing Ranges Just A Smidge
  @details SD-6 equivalent: `__cpp_lib_ranges >= 202302L`. Note that
  `__cpp_lib_ranges` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202302L` [P2609R3](https://wg21.link/P2609R3) Relaxing Ranges Just A Smidge

  @sa `<algorithm>` `<functional>` `<iterator>` `<memory>` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_RELAXED
  #define LBAL_LIBCPP23_RANGES_RELAXED 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_REMOVE_POISON_PILLS
  @brief Poison Pills are Too Toxic
  @details SD-6 equivalent: `__cpp_lib_ranges >= 202211L`. Note that
  `__cpp_lib_ranges` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202211L` [P2602R2](https://wg21.link/P2602R2) Poison Pills are Too Toxic

  @sa `<algorithm>` `<functional>` `<iterator>` `<memory>` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_REMOVE_POISON_PILLS
  #define LBAL_LIBCPP23_RANGES_REMOVE_POISON_PILLS 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_REPEAT
  @brief views::repeat
  @details SD-6 equivalent: `__cpp_lib_ranges_repeat >= 202207L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202207L` [P2474R2](https://wg21.link/P2474R2) views::repeat

  @sa `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_REPEAT
  #define LBAL_LIBCPP23_RANGES_REPEAT 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_SLIDE
  @brief Windowing range adaptors: views::chunk and views::slide
  @details SD-6 equivalent: `__cpp_lib_ranges_slide >= 202202L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202202L` [P2442R1](https://wg21.link/P2442R1) Windowing range adaptors:
  views::chunk and views::slide

  @sa `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_SLIDE
  #define LBAL_LIBCPP23_RANGES_SLIDE 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_STARTS_ENDS_WITH
  @brief starts_with and ends_with
  @details SD-6 equivalent: `__cpp_lib_ranges_starts_ends_with >= 202106L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202106L` [P1659R3](https://wg21.link/P1659R3) starts_with and ends_with

  @sa `<algorithm>`
*/
#ifndef LBAL_LIBCPP23_RANGES_STARTS_ENDS_WITH
  #define LBAL_LIBCPP23_RANGES_STARTS_ENDS_WITH 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_STRIDE
  @brief stride_view
  @details SD-6 equivalent: `__cpp_lib_ranges_stride >= 202207L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202207L` [P1899R3](https://wg21.link/P1899R3) stride_view

  @sa `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_STRIDE
  #define LBAL_LIBCPP23_RANGES_STRIDE 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_SUPPORT_MOVE_ONLY_TYPES
  @brief Relaxing range adaptors to allow for move only types
  @details SD-6 equivalent: `__cpp_lib_ranges >= 202207L`. Note that
  `__cpp_lib_ranges` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P2494R2](https://wg21.link/P2494R2) Relaxing range adaptors to
  allow for move only types

  @sa `<algorithm>` `<functional>` `<iterator>` `<memory>` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_SUPPORT_MOVE_ONLY_TYPES
  #define LBAL_LIBCPP23_RANGES_SUPPORT_MOVE_ONLY_TYPES 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_TO_CONTAINER
  @brief Conversions from ranges to containers
  @details SD-6 equivalent: `__cpp_lib_ranges_to_container >= 202202L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202202L` [P1206R7](https://wg21.link/P1206R7) Conversions from ranges to
  containers

  @sa `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_TO_CONTAINER
  #define LBAL_LIBCPP23_RANGES_TO_CONTAINER 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_USER_ADAPTOR_PIPES
  @brief Pipe support for user-defined range adaptors
  @details SD-6 equivalent: `__cpp_lib_ranges >= 202202L`. Note that
  `__cpp_lib_ranges` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202202L` [P2387R3](https://wg21.link/P2387R3) Pipe support for user-defined
  range adaptors

  @sa `<algorithm>` `<functional>` `<iterator>` `<memory>` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_USER_ADAPTOR_PIPES
  #define LBAL_LIBCPP23_RANGES_USER_ADAPTOR_PIPES 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_ZIP
  @brief zip
  @details SD-6 equivalent: `__cpp_lib_ranges_zip >= 202110L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202110L` [P2321R2](https://wg21.link/P2321R2) zip

  @sa `<ranges>` `<tuple>` `<utility>`
*/
#ifndef LBAL_LIBCPP23_RANGES_ZIP
  #define LBAL_LIBCPP23_RANGES_ZIP 0
#endif

/**
  @def LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY
  @brief A type trait to detect reference binding to temporary
  @details SD-6 equivalent: `__cpp_lib_reference_from_temporary >= 202202L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202202L` [P2255R2](https://wg21.link/P2255R2) A type trait to detect
  reference binding to temporary

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY
  #define LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY 0
#endif

/**
  @def LBAL_LIBCPP23_SHIFT_RANGES
  @brief ranges::iota, ranges::shift_left, and ranges::shift_right
  @details SD-6 equivalent: `__cpp_lib_shift >= 202202L`. Note that
  `__cpp_lib_shift` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202202L` [P2440R1](https://wg21.link/P2440R1) ranges::iota,
  ranges::shift_left, and ranges::shift_right

  @sa `<algorithm>`
*/
#ifndef LBAL_LIBCPP23_SHIFT_RANGES
  #define LBAL_LIBCPP23_SHIFT_RANGES 0
#endif

/**
  @def LBAL_LIBCPP23_SPANSTREAM
  @brief A strstream replacement using span as buffer
  @details SD-6 equivalent: `__cpp_lib_spanstream >= 202106L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202106L` [P0448R4](https://wg21.link/P0448R4) A strstream replacement using
  span as buffer

  @sa `<spanstream>`
*/
#ifndef LBAL_LIBCPP23_SPANSTREAM
  #define LBAL_LIBCPP23_SPANSTREAM 0
#endif

/**
  @def LBAL_LIBCPP23_STACKTRACE
  @brief A Proposal to add stacktrace library
  @details SD-6 equivalent: `__cpp_lib_stacktrace >= 202011L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202011L` [P0881R7](https://wg21.link/P0881R7) A Proposal to add stacktrace
  library

  @sa `<stacktrace>`
*/
#ifndef LBAL_LIBCPP23_STACKTRACE
  #define LBAL_LIBCPP23_STACKTRACE 0
#endif

/**
  @def LBAL_LIBCPP23_START_LIFETIME_AS
  @brief Explicit lifetime management
  @details SD-6 equivalent: `__cpp_lib_start_lifetime_as >= 202207L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202207L` [P2590R2](https://wg21.link/P2590R2) Explicit lifetime management

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP23_START_LIFETIME_AS
  #define LBAL_LIBCPP23_START_LIFETIME_AS 0
#endif

/**
  @def LBAL_LIBCPP23_STDATOMIC_H
  @brief Support C atomics in C++
  @details SD-6 equivalent: `__cpp_lib_stdatomic_h >= 202011L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202011L` [P0943R6](https://wg21.link/P0943R6) Support C atomics in C++

  @sa `<stdatomic.h>`
*/
#ifndef LBAL_LIBCPP23_STDATOMIC_H
  #define LBAL_LIBCPP23_STDATOMIC_H 0
#endif

/**
  @def LBAL_LIBCPP23_STRING_CONTAINS
  @brief String Contains function
  @details SD-6 equivalent: `__cpp_lib_string_contains >= 202011L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202011L` [P1679R3](https://wg21.link/P1679R3) String Contains function

  @sa `<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP23_STRING_CONTAINS
  #define LBAL_LIBCPP23_STRING_CONTAINS 0
#endif

/**
  @def LBAL_LIBCPP23_STRING_RESIZE_AND_OVERWRITE
  @brief basic_string::resize_and_overwrite
  @details SD-6 equivalent: `__cpp_lib_string_resize_and_overwrite >= 202110L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202110L` [P1072R10](https://wg21.link/P1072R10)
  basic_string::resize_and_overwrite

  @sa `<string>`
*/
#ifndef LBAL_LIBCPP23_STRING_RESIZE_AND_OVERWRITE
  #define LBAL_LIBCPP23_STRING_RESIZE_AND_OVERWRITE 0
#endif

/**
  @def LBAL_LIBCPP23_TO_UNDERLYING
  @brief std::to_underlying
  @details SD-6 equivalent: `__cpp_lib_to_underlying >= 202102L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202102L` [P1682R2](https://wg21.link/P1682R2) std::to_underlying

  @sa `<utility>`
*/
#ifndef LBAL_LIBCPP23_TO_UNDERLYING
  #define LBAL_LIBCPP23_TO_UNDERLYING 0
#endif

/**
  @def LBAL_LIBCPP23_TUPLE_LIKE
  @brief Compatibility between tuple, pair and tuple-like objects
  @details SD-6 equivalent: `__cpp_lib_tuple_like >= 202207L`. Note that
  `__cpp_lib_tuple_like` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P2165R4](https://wg21.link/P2165R4) Compatibility between tuple,
  pair and tuple-like objects

  @sa `<map>` `<tuple>` `<unordered_map>` `<utility>`
*/
#ifndef LBAL_LIBCPP23_TUPLE_LIKE
  #define LBAL_LIBCPP23_TUPLE_LIKE 0
#endif

/**
  @def LBAL_LIBCPP23_UNREACHABLE
  @brief Function to mark unreachable code
  @details SD-6 equivalent: `__cpp_lib_unreachable >= 202202L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202202L` [P0627R6](https://wg21.link/P0627R6) Function to mark unreachable
  code

  @sa `<utility>`
*/
#ifndef LBAL_LIBCPP23_UNREACHABLE
  #define LBAL_LIBCPP23_UNREACHABLE 0
#endif

/**
  @def LBAL_LIBCPP23_VARIANT_CONSTEXPR
  @brief Add further `constexpr` support for `std::variant`
  @details SD-6 equivalent: `__cpp_lib_variant >= 202106L`. Note that
  `__cpp_lib_variant` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202106L` [P2231R1](https://wg21.link/P2231R1) Add further constexpr support
  for optional/variant

  @sa `<variant>`
*/
#ifndef LBAL_LIBCPP23_VARIANT_CONSTEXPR
  #define LBAL_LIBCPP23_VARIANT_CONSTEXPR 0
#endif

/**
  @def LBAL_LIBCPP23_VARIANT_INHERITANCE
  @brief Address inheriting from `std::variant`
  @details SD-6 equivalent: `__cpp_lib_variant >= 202102L`. Note that
  `__cpp_lib_variant` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202102L` [P2162R2](https://wg21.link/P2162R2) Inheriting from std::variant
  (resolving LWG3052)

  @sa `<variant>`
*/
#ifndef LBAL_LIBCPP23_VARIANT_INHERITANCE
  #define LBAL_LIBCPP23_VARIANT_INHERITANCE 0
#endif

///	@}	LBAL_LIBCPP23

/**
  @name LBAL_LIBCPP26

  @brief These are all taken from features that have been incorporated into
  the C++26 Standard.

  @{
*/

/**
  @def LBAL_LIBCPP26_ALIGNED_ACCESSOR
  @brief An `mdspan` accessor expressing pointer overalignment
  @details SD-6 equivalent: `__cpp_lib_aligned_accessor >= 202411L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202411L` [P2897R7](https://wg21.link/P2897R7) aligned_accessor: An mdspan
  accessor expressing pointer overalignment

  @sa `<mdspan>`
*/
#ifndef LBAL_LIBCPP26_ALIGNED_ACCESSOR
  #define LBAL_LIBCPP26_ALIGNED_ACCESSOR 0
#endif

/**
  @def LBAL_LIBCPP26_ASSOCIATIVE_HETEROGENEOUS_INSERTION
  @brief Extending associative containers with the remaining heterogeneous
  overloads
  @details SD-6 equivalent: `__cpp_lib_associative_heterogeneous_insertion >=
  202306L`. This token will have a value of `0` if the proposal described here
  is not supported.
  - `202306L` [P2363R5](https://wg21.link/P2363R5) Extending associative
  containers with the remaining heterogeneous overloads

  @sa `<map>` `<set>` `<unordered_map>` `<unordered_set>`
*/
#ifndef LBAL_LIBCPP26_ASSOCIATIVE_HETEROGENEOUS_INSERTION
  #define LBAL_LIBCPP26_ASSOCIATIVE_HETEROGENEOUS_INSERTION 0
#endif

/**
  @def LBAL_LIBCPP26_ATOMIC_MIN_MAX
  @brief Atomic maximum/minimum
  @details SD-6 equivalent: `__cpp_lib_atomic_min_max >= 202403L`. Note that
  `__cpp_lib_atomic_min_max` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202403L` [P0493R5](https://wg21.link/P0493R5) Atomic maximum/minimum

  @sa `<atomic>`
*/
#ifndef LBAL_LIBCPP26_ATOMIC_MIN_MAX
  #define LBAL_LIBCPP26_ATOMIC_MIN_MAX 0
#endif

/**
  @def LBAL_LIBCPP26_ATOMIC_MIN_MAX_FLOAT
  @brief Atomic floating-point min/max
  @details SD-6 equivalent: `__cpp_lib_atomic_min_max >= 202506L`. Note that
  `__cpp_lib_atomic_min_max` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P3008R6](https://wg21.link/P3008R6) Atomic floating-point min/max

  @sa `<atomic>`
*/
#ifndef LBAL_LIBCPP26_ATOMIC_MIN_MAX_FLOAT
  #define LBAL_LIBCPP26_ATOMIC_MIN_MAX_FLOAT 0
#endif

/**
  @def LBAL_LIBCPP26_ATOMIC_REDUCTIONS
  @brief Atomic Reduction Operations
  @details SD-6 equivalent: `__cpp_lib_atomic_reductions >= 202506L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202506L` [P3111R8](https://wg21.link/P3111R8) Atomic Reduction Operations

  @sa `<atomic>`
*/
#ifndef LBAL_LIBCPP26_ATOMIC_REDUCTIONS
  #define LBAL_LIBCPP26_ATOMIC_REDUCTIONS 0
#endif

/**
  @def LBAL_LIBCPP26_ATOMIC_REF_ADDRESS
  @brief Expose `std::atomic_ref`’s object address
  @details SD-6 equivalent: `__cpp_lib_atomic_ref >= 202411L`. Note that
  `__cpp_lib_atomic_ref` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202411L` [P2835R7](https://wg21.link/P2835R7) Expose std::atomic_ref’s
  object address

  @sa `<atomic>`
*/
#ifndef LBAL_LIBCPP26_ATOMIC_REF_ADDRESS
  #define LBAL_LIBCPP26_ATOMIC_REF_ADDRESS 0
#endif

/**
  @def LBAL_LIBCPP26_BIND_FRONT_NTTP_CALLABLES
  @brief Bind `front` and `back` to NTTP callables
  @details SD-6 equivalent: `__cpp_lib_bind_front >= 202306L`. Note that
  `__cpp_lib_bind_front` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P2714R1](https://wg21.link/P2714R1) Bind front and back to NTTP
  callables

  @sa `<functional>`
*/
#ifndef LBAL_LIBCPP26_BIND_FRONT_NTTP_CALLABLES
  #define LBAL_LIBCPP26_BIND_FRONT_NTTP_CALLABLES 0
#endif

/**
  @def LBAL_LIBCPP26_BITSET
  @brief Interfacing bitset with string_view
  @details SD-6 equivalent: `__cpp_lib_bitset >= 202306L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `202306L` [P2697R1](https://wg21.link/P2697R1) Interfacing bitset with
  string_view

  @sa `<bitset>`
*/
#ifndef LBAL_LIBCPP26_BITSET
  #define LBAL_LIBCPP26_BITSET 0
#endif

/**
  @def LBAL_LIBCPP26_CHRONO_HASHING
  @brief Add hashing support for `std::chrono` value classes
  @details SD-6 equivalent: `__cpp_lib_chrono >= 202306L`. Note that
  `__cpp_lib_chrono` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P2592R3](https://wg21.link/P2592R3) Hashing support for
  std::chrono value classes

  @sa `<chrono>`
*/
#ifndef LBAL_LIBCPP26_CHRONO_HASHING
  #define LBAL_LIBCPP26_CHRONO_HASHING 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTANT_WRAPPER
  @brief std::constexpr_wrapper
  @details SD-6 equivalent: `__cpp_lib_constant_wrapper >= 202506L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202506L` [P2781R9](https://wg21.link/P2781R9) std::constexpr_wrapper

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP26_CONSTANT_WRAPPER
  #define LBAL_LIBCPP26_CONSTANT_WRAPPER 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_ALGORITHMS_STABLE_SORT
  @brief Add `constexpr` to `std::swap` and related functions
  @details SD-6 equivalent: `__cpp_lib_constexpr_algorithms >= 202306L`. Note
  that `__cpp_lib_constexpr_algorithms` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `202306L` [P2562R1 __PDF__](https://wg21.link/P2562R1) constexpr Stable
  Sorting

  @sa `<algorithm>` `<utility>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_ALGORITHMS_STABLE_SORT
  #define LBAL_LIBCPP26_CONSTEXPR_ALGORITHMS_STABLE_SORT 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_ATOMIC
  @brief constexpr atomic and atomic_ref
  @details SD-6 equivalent: `__cpp_lib_constexpr_atomic >= 202411L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202411L` [P3309R3](https://wg21.link/P3309R3) constexpr atomic and
  atomic_ref

  @sa `<atomic>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_ATOMIC
  #define LBAL_LIBCPP26_CONSTEXPR_ATOMIC 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_COMPLEX
  @brief Add more `constexpr` support to `<cmath>` and `<complex>`
  @details SD-6 equivalent: `__cpp_lib_constexpr_complex >= 202306L`. Note that
  `__cpp_lib_constexpr_complex` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P1383R2](https://wg21.link/P1383R2) More constexpr for cmath
  and complex

  @sa `<complex>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_COMPLEX
  #define LBAL_LIBCPP26_CONSTEXPR_COMPLEX 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_DEQUE
  @brief constexpr containers and adapters
  @details SD-6 equivalent: `__cpp_lib_constexpr_deque >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3372R3](https://wg21.link/P3372R3) constexpr containers and
  adapters

  @sa `<deque>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_DEQUE
  #define LBAL_LIBCPP26_CONSTEXPR_DEQUE 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_EXCEPTIONS
  @brief constexpr exception types
  @details SD-6 equivalent: `__cpp_lib_constexpr_exceptions >= 202502L`. Note
  that `__cpp_lib_constexpr_exceptions` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `202502L` [P3378R2](https://wg21.link/P3378R2) constexpr exception types

  @sa `<exception>` `<expected>` `<format>` `<optional>` `<stdexcept>`
  `<variant>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_EXCEPTIONS
  #define LBAL_LIBCPP26_CONSTEXPR_EXCEPTIONS 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_FLAT_MAP
  @brief constexpr containers and adapters
  @details SD-6 equivalent: `__cpp_lib_constexpr_flat_map >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P3372R3](https://wg21.link/P3372R3) constexpr containers and
  adapters

  @sa `<flat_map>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_FLAT_MAP
  #define LBAL_LIBCPP26_CONSTEXPR_FLAT_MAP 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_FLAT_SET
  @brief constexpr containers and adapters
  @details SD-6 equivalent: `__cpp_lib_constexpr_flat_set >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P3372R3](https://wg21.link/P3372R3) constexpr containers and
  adapters

  @sa `<flat_set>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_FLAT_SET
  #define LBAL_LIBCPP26_CONSTEXPR_FLAT_SET 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_FORMAT
  @brief constexpr std::format
  @details SD-6 equivalent: `__cpp_lib_constexpr_format >= 202511L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202511L` [P3391R2](https://wg21.link/P3391R2) constexpr std::format

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_FORMAT
  #define LBAL_LIBCPP26_CONSTEXPR_FORMAT 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_FORWARD_LIST
  @brief constexpr containers and adapters
  @details SD-6 equivalent: `__cpp_lib_constexpr_forward_list >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P3372R3](https://wg21.link/P3372R3) constexpr containers and
  adapters

  @sa `<forward_list>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_FORWARD_LIST
  #define LBAL_LIBCPP26_CONSTEXPR_FORWARD_LIST 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_LIST
  @brief constexpr containers and adapters
  @details SD-6 equivalent: `__cpp_lib_constexpr_list >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3372R3](https://wg21.link/P3372R3) constexpr containers and
  adapters

  @sa `<list>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_LIST
  #define LBAL_LIBCPP26_CONSTEXPR_LIST 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_MAP
  @brief constexpr containers and adapters
  @details SD-6 equivalent: `__cpp_lib_constexpr_map >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3372R3](https://wg21.link/P3372R3) constexpr containers and
  adapters

  @sa `<map>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_MAP
  #define LBAL_LIBCPP26_CONSTEXPR_MAP 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_MEMORY_SHARED_PTR
  @brief Make `std::shared_ptr` and friends `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_memory >= 202506L`. Note that
  `__cpp_lib_constexpr_memory` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P3037R6](https://wg21.link/P3037R6) constexpr std::shared_ptr
  and friends

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_MEMORY_SHARED_PTR
  #define LBAL_LIBCPP26_CONSTEXPR_MEMORY_SHARED_PTR 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_QUEUE
  @brief constexpr containers and adapters
  @details SD-6 equivalent: `__cpp_lib_constexpr_queue >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3372R3](https://wg21.link/P3372R3) constexpr containers and
  adapters

  @sa `<queue>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_QUEUE
  #define LBAL_LIBCPP26_CONSTEXPR_QUEUE 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_SET
  @brief constexpr containers and adapters
  @details SD-6 equivalent: `__cpp_lib_constexpr_set >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3372R3](https://wg21.link/P3372R3) constexpr containers and
  adapters

  @sa `<set>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_SET
  #define LBAL_LIBCPP26_CONSTEXPR_SET 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_STACK
  @brief constexpr containers and adapters
  @details SD-6 equivalent: `__cpp_lib_constexpr_stack >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3372R3](https://wg21.link/P3372R3) constexpr containers and
  adapters

  @sa `<stack>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_STACK
  #define LBAL_LIBCPP26_CONSTEXPR_STACK 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_UNORDERED_MAP
  @brief constexpr containers and adapters
  @details SD-6 equivalent: `__cpp_lib_constexpr_unordered_map >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P3372R3](https://wg21.link/P3372R3) constexpr containers and
  adapters

  @sa `<unordered_map>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_UNORDERED_MAP
  #define LBAL_LIBCPP26_CONSTEXPR_UNORDERED_MAP 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_UNORDERED_SET
  @brief constexpr containers and adapters
  @details SD-6 equivalent: `__cpp_lib_constexpr_unordered_set >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P3372R3](https://wg21.link/P3372R3) constexpr containers and
  adapters

  @sa `<unordered_set>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_UNORDERED_SET
  #define LBAL_LIBCPP26_CONSTEXPR_UNORDERED_SET 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTRAINED_EQUALITY
  @brief Comparisons for reference_wrapper
  @details SD-6 equivalent: `__cpp_lib_constrained_equality >= 202403L`. Note
  that `__cpp_lib_constrained_equality` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `202403L` [P2944R3](https://wg21.link/P2944R3) Comparisons for
  reference_wrapper
  - `202411L` [P3379R0](https://wg21.link/P3379R0) Constrain std::expected
  equality operators

  @sa `<expected>` `<optional>` `<tuple>` `<utility>` `<variant>`
*/
#ifndef LBAL_LIBCPP26_CONSTRAINED_EQUALITY
  #define LBAL_LIBCPP26_CONSTRAINED_EQUALITY 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTRAINED_EQUALITY_EXPECTED
  @brief Constrain std::expected equality operators
  @details SD-6 equivalent: `__cpp_lib_constrained_equality >= 202411L`. Note
  that `__cpp_lib_constrained_equality` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.

  @sa `<expected>` `<optional>` `<tuple>` `<utility>` `<variant>`
*/
#ifndef LBAL_LIBCPP26_CONSTRAINED_EQUALITY_EXPECTED
  #define LBAL_LIBCPP26_CONSTRAINED_EQUALITY_EXPECTED 0
#endif

/**
  @def LBAL_LIBCPP26_COPYABLE_FUNCTION
  @brief copyable_function
  @details SD-6 equivalent: `__cpp_lib_copyable_function >= 202306L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202306L` [P2548R6](https://wg21.link/P2548R6) copyable_function

  @sa `<functional>`
*/
#ifndef LBAL_LIBCPP26_COPYABLE_FUNCTION
  #define LBAL_LIBCPP26_COPYABLE_FUNCTION 0
#endif

/**
  @def LBAL_LIBCPP26_COUNTING_SCOPE
  @brief async_scope — Creating scopes for non-sequential concurrency
  @details SD-6 equivalent: `__cpp_lib_counting_scope >= 202506L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202506L` [P3149R11](https://wg21.link/P3149R11) async_scope — Creating
  scopes for non-sequential concurrency

  @sa `<execution>`
*/
#ifndef LBAL_LIBCPP26_COUNTING_SCOPE
  #define LBAL_LIBCPP26_COUNTING_SCOPE 0
#endif

/**
  @def LBAL_LIBCPP26_DEBUGGING
  @brief Debugging Support
  @details SD-6 equivalent: `__cpp_lib_debugging >= 202311L`. Note that
  `__cpp_lib_debugging` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202311L` [P2546R5](https://wg21.link/P2546R5) Debugging Support

  @sa `<debugging>`
*/
#ifndef LBAL_LIBCPP26_DEBUGGING
  #define LBAL_LIBCPP26_DEBUGGING 0
#endif

/**
  @def LBAL_LIBCPP26_DEBUGGING_UTILITIES
  @brief is_debugger_present is_replaceable
  @details SD-6 equivalent: `__cpp_lib_debugging >= 202403L`. Note that
  `__cpp_lib_debugging` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202403L` [P2810R4](https://wg21.link/P2810R4) is_debugger_present
  is_replaceable

  @sa `<debugging>`
*/
#ifndef LBAL_LIBCPP26_DEBUGGING_UTILITIES
  #define LBAL_LIBCPP26_DEBUGGING_UTILITIES 0
#endif

/**
  @def LBAL_LIBCPP26_DEFAULT_TEMPLATE_TYPE_FOR_ALGORITHM_VALUES
  @brief Enabling list-initialization for algorithms
  @details SD-6 equivalent: `__cpp_lib_default_template_type_for_algorithm_values
  >= 202403L`. This token will have a value of `0` if the proposal described
  here is not supported.
  - `202403L` [P2248R8](https://wg21.link/P2248R8) Enabling list-initialization
  for algorithms

  @sa `<algorithm>` `<deque>` `<forward_list>` `<list>` `<ranges>` `<string>`
  `<vector>`
*/
#ifndef LBAL_LIBCPP26_DEFAULT_TEMPLATE_TYPE_FOR_ALGORITHM_VALUES
  #define LBAL_LIBCPP26_DEFAULT_TEMPLATE_TYPE_FOR_ALGORITHM_VALUES 0
#endif

/**
  @def LBAL_LIBCPP26_DEFINE_STATIC
  @brief define_static_{string,object,array}
  @details SD-6 equivalent: `__cpp_lib_define_static >= 202506L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202506L` [P3491R3](https://wg21.link/P3491R3)
  define_static_{string,object,array}

  @sa `<meta>`
*/
#ifndef LBAL_LIBCPP26_DEFINE_STATIC
  #define LBAL_LIBCPP26_DEFINE_STATIC 0
#endif

/**
  @def LBAL_LIBCPP26_EXCEPTION_PTR_CAST
  @brief Observing exceptions stored in exception_ptr
  @details SD-6 equivalent: `__cpp_lib_exception_ptr_cast >= 202506L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202506L` [P2927R3](https://wg21.link/P2927R3) Observing exceptions stored
  in exception_ptr

  @sa `<exception>`
*/
#ifndef LBAL_LIBCPP26_EXCEPTION_PTR_CAST
  #define LBAL_LIBCPP26_EXCEPTION_PTR_CAST 0
#endif

/**
  @def LBAL_LIBCPP26_EXCEPTION_PTR_CAST_CONSTEXPR
  @brief Inspecting exception_ptr works should be constexpr.
  @details SD-6 equivalent: `__cpp_lib_exception_ptr_cast >= 202506L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202506L` [P3748R0](https://wg21.link/P3748R0) Inspecting exception_ptr
  works should be constexpr.

  @sa `<exception>`
*/
#ifndef LBAL_LIBCPP26_EXCEPTION_PTR_CAST_CONSTEXPR
  #define LBAL_LIBCPP26_EXCEPTION_PTR_CAST_CONSTEXPR 0
#endif

/**
  @def LBAL_LIBCPP26_FLAT_MAP_FIXES
  @brief flat_meow Fixes
  @details SD-6 equivalent: `__cpp_lib_flat_map >= 202511L`. Note that
  `__cpp_lib_flat_map` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202511L` [P3567R2](https://wg21.link/P3567R2) flat_meow Fixes

  @sa `<flat_map>`
*/
#ifndef LBAL_LIBCPP26_FLAT_MAP_FIXES
  #define LBAL_LIBCPP26_FLAT_MAP_FIXES 0
#endif

/**
  @def LBAL_LIBCPP26_FLAT_SET_FIXES
  @brief flat_meow Fixes
  @details SD-6 equivalent: `__cpp_lib_flat_set >= 202511L`. Note that
  `__cpp_lib_flat_set` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202511L` [P3567R2](https://wg21.link/P3567R2) flat_meow Fixes

  @sa `<flat_set>`
*/
#ifndef LBAL_LIBCPP26_FLAT_SET_FIXES
  #define LBAL_LIBCPP26_FLAT_SET_FIXES 0
#endif

/**
  @def LBAL_LIBCPP26_FORMAT_MEMBER_VISIT
  @brief Member `visit`
  @details SD-6 equivalent: `__cpp_lib_format >= 202306L`. Note that
  `__cpp_lib_format` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P2637R3](https://wg21.link/P2637R3) Member visit

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP26_FORMAT_MEMBER_VISIT
  #define LBAL_LIBCPP26_FORMAT_MEMBER_VISIT 0
#endif

/**
  @def LBAL_LIBCPP26_FORMAT_PATH
  @brief Formatting of std::filesystem::path
  @details SD-6 equivalent: `__cpp_lib_format_path >= 202403L`. Note that
  `__cpp_lib_format_path` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202403L` [P2845R8](https://wg21.link/P2845R8) Formatting of
  std::filesystem::path

  @sa `<filesystem>`
*/
#ifndef LBAL_LIBCPP26_FORMAT_PATH
  #define LBAL_LIBCPP26_FORMAT_PATH 0
#endif

/**
  @def LBAL_LIBCPP26_FORMAT_PATH_FIXES
  @brief Prevent path presentation problems
  @details SD-6 equivalent: `__cpp_lib_format_path >= 202506L`. Note that
  `__cpp_lib_format_path` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P2319R5](https://wg21.link/P2319R5) Prevent path presentation
  problems

  @sa `<filesystem>`
*/
#ifndef LBAL_LIBCPP26_FORMAT_PATH_FIXES
  #define LBAL_LIBCPP26_FORMAT_PATH_FIXES 0
#endif

/**
  @def LBAL_LIBCPP26_FORMAT_POINTERS
  @brief Format pointers
  @details SD-6 equivalent: `__cpp_lib_format >= 202304L`. Note that
  `__cpp_lib_format` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202304L` [P2510R3](https://wg21.link/P2510R3) Formatting pointers

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP26_FORMAT_POINTERS
  #define LBAL_LIBCPP26_FORMAT_POINTERS 0
#endif

/**
  @def LBAL_LIBCPP26_FORMAT_RUNTIME
  @brief Add runtime format strings
  @details SD-6 equivalent: `__cpp_lib_format >= 202311L`. Note that
  `__cpp_lib_format` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202311L` [P2918R2](https://wg21.link/P2918R2) Runtime format strings II

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP26_FORMAT_RUNTIME
  #define LBAL_LIBCPP26_FORMAT_RUNTIME 0
#endif

/**
  @def LBAL_LIBCPP26_FORMAT_TYPE_CHECK
  @brief Type check format args
  @details SD-6 equivalent: `__cpp_lib_format >= 202305L`. Note that
  `__cpp_lib_format` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202305L` [P2757R3](https://wg21.link/P2757R3) Type checking format args

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP26_FORMAT_TYPE_CHECK
  #define LBAL_LIBCPP26_FORMAT_TYPE_CHECK 0
#endif

/**
  @def LBAL_LIBCPP26_FORMAT_UCHAR
  @brief Fix formatting of code units as integers (Dude, where’s my char?)
  @details SD-6 equivalent: `__cpp_lib_format_uchar >= 202311L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202311L` [P2909R4](https://wg21.link/P2909R4) Fix formatting of code units
  as integers (Dude, where’s my char?)

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP26_FORMAT_UCHAR
  #define LBAL_LIBCPP26_FORMAT_UCHAR 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_ALGORITHM
  @brief Freestanding Library: Partial Classes
  @details SD-6 equivalent: `__cpp_lib_freestanding_algorithm >= 202311L`. Note
  that `__cpp_lib_freestanding_algorithm` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `202311L` [P2407R5](https://wg21.link/P2407R5) Freestanding Library: Partial
  Classes

  @sa `<algorithm>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_ALGORITHM
  #define LBAL_LIBCPP26_FREESTANDING_ALGORITHM 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_ALGORITHM_MORE
  @brief Freestanding Library: algorithm, numeric, and random
  @details SD-6 equivalent: `__cpp_lib_freestanding_algorithm >= 202502L`. Note
  that `__cpp_lib_freestanding_algorithm` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `202502L` [P2976R1](https://wg21.link/P2976R1) Freestanding Library:
  algorithm, numeric, and random

  @sa `<algorithm>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_ALGORITHM_MORE
  #define LBAL_LIBCPP26_FREESTANDING_ALGORITHM_MORE 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_ARRAY
  @brief Freestanding Library: Partial Classes
  @details SD-6 equivalent: `__cpp_lib_freestanding_array >= 202311L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202311L` [P2407R5](https://wg21.link/P2407R5) Freestanding Library: Partial
  Classes

  @sa `<array>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_ARRAY
  #define LBAL_LIBCPP26_FREESTANDING_ARRAY 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_CHARCONV
  @brief Freestanding Library: Character primitives and the C library
  @details SD-6 equivalent: `__cpp_lib_freestanding_charconv >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2338R4](https://wg21.link/P2338R4) Freestanding Library:
  Character primitives and the C library

  @sa `<charconv>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_CHARCONV
  #define LBAL_LIBCPP26_FREESTANDING_CHARCONV 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_CHAR_TRAITS
  @brief Freestanding Library: Character primitives and the C library
  @details SD-6 equivalent: `__cpp_lib_freestanding_char_traits >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2338R4](https://wg21.link/P2338R4) Freestanding Library:
  Character primitives and the C library

  @sa `<string>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_CHAR_TRAITS
  #define LBAL_LIBCPP26_FREESTANDING_CHAR_TRAITS 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_CSTDLIB
  @brief Freestanding Library: Character primitives and the C library
  @details SD-6 equivalent: `__cpp_lib_freestanding_cstdlib >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2338R4](https://wg21.link/P2338R4) Freestanding Library:
  Character primitives and the C library

  @sa `<cmath>` `<cstdlib>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_CSTDLIB
  #define LBAL_LIBCPP26_FREESTANDING_CSTDLIB 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_CSTRING
  @brief Freestanding Library: Character primitives and the C library
  @details SD-6 equivalent: `__cpp_lib_freestanding_cstring >= 202306L`. Note
  that `__cpp_lib_freestanding_cstring` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `202306L` [P2338R4](https://wg21.link/P2338R4) Freestanding Library:
  Character primitives and the C library

  @sa `<cstring>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_CSTRING
  #define LBAL_LIBCPP26_FREESTANDING_CSTRING 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_CSTRING_REMOVE_STRTOK
  @brief Freestanding: Remove strtok
  @details SD-6 equivalent: `__cpp_lib_freestanding_cstring >= 202311L`. Note
  that `__cpp_lib_freestanding_cstring` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `202311L` [P2937R0](https://wg21.link/P2937R0) Freestanding: Remove strtok

  @sa `<cstring>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_CSTRING_REMOVE_STRTOK
  #define LBAL_LIBCPP26_FREESTANDING_CSTRING_REMOVE_STRTOK 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_CWCHAR
  @brief Freestanding Library: Character primitives and the C library
  @details SD-6 equivalent: `__cpp_lib_freestanding_cwchar >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2338R4](https://wg21.link/P2338R4) Freestanding Library:
  Character primitives and the C library

  @sa `<cwchar>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_CWCHAR
  #define LBAL_LIBCPP26_FREESTANDING_CWCHAR 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_ERRC
  @brief Freestanding Library: Character primitives and the C library
  @details SD-6 equivalent: `__cpp_lib_freestanding_errc >= 202306L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202306L` [P2338R4](https://wg21.link/P2338R4) Freestanding Library:
  Character primitives and the C library

  @sa `<cerrno>` `<system_error>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_ERRC
  #define LBAL_LIBCPP26_FREESTANDING_ERRC 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_EXECUTION
  @brief Freestanding Library: algorithm, numeric, and random
  @details SD-6 equivalent: `__cpp_lib_freestanding_execution >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P2976R1](https://wg21.link/P2976R1) Freestanding Library:
  algorithm, numeric, and random

  @sa `<execution>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_EXECUTION
  #define LBAL_LIBCPP26_FREESTANDING_EXECUTION 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_EXPECTED
  @brief Freestanding Library: inout expected span
  @details SD-6 equivalent: `__cpp_lib_freestanding_expected >= 202311L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202311L` [P2833R2](https://wg21.link/P2833R2) Freestanding Library: inout
  expected span

  @sa `<expected>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_EXPECTED
  #define LBAL_LIBCPP26_FREESTANDING_EXPECTED 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_FEATURE_TEST_MACROS
  @brief Freestanding Feature-Test Macros and Implementation-Defined Extensions
  @details SD-6 equivalent: `__cpp_lib_freestanding_feature_test_macros >=
  202306L`. This token will have a value of `0` if the proposal described here
  is not supported.
  - `202306L` [P2198R7](https://wg21.link/P2198R7) Freestanding Feature-Test
  Macros and Implementation-Defined Extensions
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_FEATURE_TEST_MACROS
  #define LBAL_LIBCPP26_FREESTANDING_FEATURE_TEST_MACROS 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_FUNCTIONAL
  @brief Freestanding Feature-Test Macros and Implementation-Defined Extensions
  @details SD-6 equivalent: `__cpp_lib_freestanding_functional >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2198R7](https://wg21.link/P2198R7) Freestanding Feature-Test
  Macros and Implementation-Defined Extensions

  @sa `<functional>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_FUNCTIONAL
  #define LBAL_LIBCPP26_FREESTANDING_FUNCTIONAL 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_ITERATOR
  @brief Freestanding Feature-Test Macros and Implementation-Defined Extensions
  @details SD-6 equivalent: `__cpp_lib_freestanding_iterator >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2198R7](https://wg21.link/P2198R7) Freestanding Feature-Test
  Macros and Implementation-Defined Extensions

  @sa `<iterator>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_ITERATOR
  #define LBAL_LIBCPP26_FREESTANDING_ITERATOR 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_MDSPAN
  @brief Freestanding Library: inout expected span
  @details SD-6 equivalent: `__cpp_lib_freestanding_mdspan >= 202311L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202311L` [P2833R2](https://wg21.link/P2833R2) Freestanding Library: inout
  expected span

  @sa `<mdspan>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_MDSPAN
  #define LBAL_LIBCPP26_FREESTANDING_MDSPAN 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_MEMORY
  @brief Freestanding Feature-Test Macros and Implementation-Defined Extensions
  @details SD-6 equivalent: `__cpp_lib_freestanding_memory >= 202306L`. Note
  that `__cpp_lib_freestanding_memory` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `202306L` [P2198R7](https://wg21.link/P2198R7) Freestanding Feature-Test
  Macros and Implementation-Defined Extensions

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_MEMORY
  #define LBAL_LIBCPP26_FREESTANDING_MEMORY 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_MEMORY_MORE
  @brief Freestanding Library: algorithm, numeric, and random
  @details SD-6 equivalent: `__cpp_lib_freestanding_memory >= 202502L`. Note
  that `__cpp_lib_freestanding_memory` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `202502L` [P2976R1](https://wg21.link/P2976R1) Freestanding Library:
  algorithm, numeric, and random

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_MEMORY_MORE
  #define LBAL_LIBCPP26_FREESTANDING_MEMORY_MORE 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_NUMERIC
  @brief Freestanding Library: algorithm, numeric, and random
  @details SD-6 equivalent: `__cpp_lib_freestanding_numeric >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P2976R1](https://wg21.link/P2976R1) Freestanding Library:
  algorithm, numeric, and random

  @sa `<numeric>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_NUMERIC
  #define LBAL_LIBCPP26_FREESTANDING_NUMERIC 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_OPERATOR_NEW
  @brief Freestanding Feature-Test Macros and Implementation-Defined Extensions
  @details SD-6 equivalent: `__cpp_lib_freestanding_operator_new >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2198R7](https://wg21.link/P2198R7) Freestanding Feature-Test
  Macros and Implementation-Defined Extensions

  @sa `<new>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_OPERATOR_NEW
  #define LBAL_LIBCPP26_FREESTANDING_OPERATOR_NEW 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_OPTIONAL
  @brief Freestanding Library: Partial Classes
  @details SD-6 equivalent: `__cpp_lib_freestanding_optional >= 202311L`. Note
  that `__cpp_lib_freestanding_optional` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `202311L` [P2407R5](https://wg21.link/P2407R5) Freestanding Library: Partial
  Classes

  @sa `<optional>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_OPTIONAL
  #define LBAL_LIBCPP26_FREESTANDING_OPTIONAL 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_RANDOM
  @brief Freestanding Library: algorithm, numeric, and random
  @details SD-6 equivalent: `__cpp_lib_freestanding_random >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P2976R1](https://wg21.link/P2976R1) Freestanding Library:
  algorithm, numeric, and random

  @sa `<random>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_RANDOM
  #define LBAL_LIBCPP26_FREESTANDING_RANDOM 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_RANGES
  @brief Freestanding Feature-Test Macros and Implementation-Defined Extensions
  @details SD-6 equivalent: `__cpp_lib_freestanding_ranges >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2198R7](https://wg21.link/P2198R7) Freestanding Feature-Test
  Macros and Implementation-Defined Extensions

  @sa `<ranges>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_RANGES
  #define LBAL_LIBCPP26_FREESTANDING_RANGES 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_RATIO
  @brief Freestanding Feature-Test Macros and Implementation-Defined Extensions
  @details SD-6 equivalent: `__cpp_lib_freestanding_ratio >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2198R7](https://wg21.link/P2198R7) Freestanding Feature-Test
  Macros and Implementation-Defined Extensions

  @sa `<ratio>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_RATIO
  #define LBAL_LIBCPP26_FREESTANDING_RATIO 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_STRING_VIEW
  @brief Freestanding Library: Partial Classes
  @details SD-6 equivalent: `__cpp_lib_freestanding_string_view >= 202311L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202311L` [P2407R5](https://wg21.link/P2407R5) Freestanding Library: Partial
  Classes

  @sa `<string_view>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_STRING_VIEW
  #define LBAL_LIBCPP26_FREESTANDING_STRING_VIEW 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_TUPLE
  @brief Freestanding Feature-Test Macros and Implementation-Defined Extensions
  @details SD-6 equivalent: `__cpp_lib_freestanding_tuple >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2198R7](https://wg21.link/P2198R7) Freestanding Feature-Test
  Macros and Implementation-Defined Extensions

  @sa `<tuple>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_TUPLE
  #define LBAL_LIBCPP26_FREESTANDING_TUPLE 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_UTILITY
  @brief Freestanding Feature-Test Macros and Implementation-Defined Extensions
  @details SD-6 equivalent: `__cpp_lib_freestanding_utility >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2198R7](https://wg21.link/P2198R7) Freestanding Feature-Test
  Macros and Implementation-Defined Extensions

  @sa `<utility>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_UTILITY
  #define LBAL_LIBCPP26_FREESTANDING_UTILITY 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_VARIANT
  @brief Freestanding Library: Partial Classes
  @details SD-6 equivalent: `__cpp_lib_freestanding_variant >= 202311L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202311L` [P2407R5](https://wg21.link/P2407R5) Freestanding Library: Partial
  Classes

  @sa `<variant>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_VARIANT
  #define LBAL_LIBCPP26_FREESTANDING_VARIANT 0
#endif

/**
  @def LBAL_LIBCPP26_FSTREAM_NATIVE_HANDLE
  @brief Native handles and file streams
  @details SD-6 equivalent: `__cpp_lib_fstream_native_handle >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P1759R6](https://wg21.link/P1759R6) Native handles and file
  streams

  @sa `<fstream>`
*/
#ifndef LBAL_LIBCPP26_FSTREAM_NATIVE_HANDLE
  #define LBAL_LIBCPP26_FSTREAM_NATIVE_HANDLE 0
#endif

/**
  @def LBAL_LIBCPP26_FUNCTION_REF
  @brief function_ref: a non-owning reference to a Callable
  @details SD-6 equivalent: `__cpp_lib_function_ref >= 202306L`. Note that
  `__cpp_lib_function_ref` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P0792R14](https://wg21.link/P0792R14) function_ref: a non-owning
  reference to a Callable

  @sa `<functional>`
*/
#ifndef LBAL_LIBCPP26_FUNCTION_REF
  #define LBAL_LIBCPP26_FUNCTION_REF 0
#endif

/**
  @def LBAL_LIBCPP26_FUNCTION_REF_RENAME_NONTYPE
  @brief Rename std::nontype, and make it broadly useful
  @details SD-6 equivalent: `__cpp_lib_function_ref >= 202511L`. Note that
  `__cpp_lib_function_ref` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202511L` [P3774R1](https://wg21.link/P3774R1) Rename std::nontype, and make
  it broadly useful

  @sa `<functional>`
*/
#ifndef LBAL_LIBCPP26_FUNCTION_REF_RENAME_NONTYPE
  #define LBAL_LIBCPP26_FUNCTION_REF_RENAME_NONTYPE 0
#endif

/**
  @def LBAL_LIBCPP26_GENERATE_RANDOM
  @brief Vector API for random number generation
  @details SD-6 equivalent: `__cpp_lib_generate_random >= 202403L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202403L` [P1068R11](https://wg21.link/P1068R11) Vector API for random
  number generation

  @sa `<random>`
*/
#ifndef LBAL_LIBCPP26_GENERATE_RANDOM
  #define LBAL_LIBCPP26_GENERATE_RANDOM 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_ARRAY
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_array >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<array>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_ARRAY
  #define LBAL_LIBCPP26_HARDENED_ARRAY 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_BASIC_STACKTRACE
  @brief Minor additions to C++26 standard library hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_basic_stacktrace >= 202506L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202506L` [P3697R1](https://wg21.link/P3697R1) Minor additions to C++26
  standard library hardening

  @sa `<stacktrace>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_BASIC_STACKTRACE
  #define LBAL_LIBCPP26_HARDENED_BASIC_STACKTRACE 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_BASIC_STRING
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_basic_string >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<string>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_BASIC_STRING
  #define LBAL_LIBCPP26_HARDENED_BASIC_STRING 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_BASIC_STRING_VIEW
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_basic_string_view >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<string_view>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_BASIC_STRING_VIEW
  #define LBAL_LIBCPP26_HARDENED_BASIC_STRING_VIEW 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_BITSET
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_bitset >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<bitset>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_BITSET
  #define LBAL_LIBCPP26_HARDENED_BITSET 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_COMMON_ITERATOR
  @brief Minor additions to C++26 standard library hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_common_iterator >= 202506L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202506L` [P3697R1](https://wg21.link/P3697R1) Minor additions to C++26
  standard library hardening

  @sa `<iterator>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_COMMON_ITERATOR
  #define LBAL_LIBCPP26_HARDENED_COMMON_ITERATOR 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_COUNTED_ITERATOR
  @brief Minor additions to C++26 standard library hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_counted_iterator >= 202506L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202506L` [P3697R1](https://wg21.link/P3697R1) Minor additions to C++26
  standard library hardening

  @sa `<iterator>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_COUNTED_ITERATOR
  #define LBAL_LIBCPP26_HARDENED_COUNTED_ITERATOR 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_DEQUE
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_deque >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<deque>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_DEQUE
  #define LBAL_LIBCPP26_HARDENED_DEQUE 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_EXPECTED
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_expected >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<expected>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_EXPECTED
  #define LBAL_LIBCPP26_HARDENED_EXPECTED 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_FORWARD_LIST
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_forward_list >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<forward_list>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_FORWARD_LIST
  #define LBAL_LIBCPP26_HARDENED_FORWARD_LIST 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_INPLACE_VECTOR
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_inplace_vector >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<inplace_vector>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_INPLACE_VECTOR
  #define LBAL_LIBCPP26_HARDENED_INPLACE_VECTOR 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_LIST
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_list >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<list>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_LIST
  #define LBAL_LIBCPP26_HARDENED_LIST 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_MDSPAN
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_mdspan >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<mdspan>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_MDSPAN
  #define LBAL_LIBCPP26_HARDENED_MDSPAN 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_OPTIONAL
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_optional >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<optional>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_OPTIONAL
  #define LBAL_LIBCPP26_HARDENED_OPTIONAL 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_SHARED_PTR_ARRAY
  @brief Minor additions to C++26 standard library hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_shared_ptr_array >= 202506L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202506L` [P3697R1](https://wg21.link/P3697R1) Minor additions to C++26
  standard library hardening

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_SHARED_PTR_ARRAY
  #define LBAL_LIBCPP26_HARDENED_SHARED_PTR_ARRAY 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_SPAN
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_span >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<span>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_SPAN
  #define LBAL_LIBCPP26_HARDENED_SPAN 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_VALARRAY
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_valarray >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<valarray>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_VALARRAY
  #define LBAL_LIBCPP26_HARDENED_VALARRAY 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_VECTOR
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_vector >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<vector>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_VECTOR
  #define LBAL_LIBCPP26_HARDENED_VECTOR 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_VIEW_INTERFACE
  @brief Minor additions to C++26 standard library hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_view_interface >= 202506L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202506L` [P3697R1](https://wg21.link/P3697R1) Minor additions to C++26
  standard library hardening

  @sa `<ranges>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_VIEW_INTERFACE
  #define LBAL_LIBCPP26_HARDENED_VIEW_INTERFACE 0
#endif

/**
  @def LBAL_LIBCPP26_HAZARD_POINTER
  @brief Hazard Pointers for C++26
  @details SD-6 equivalent: `__cpp_lib_hazard_pointer >= 202306L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202306L` [P2530R3](https://wg21.link/P2530R3) Hazard Pointers for C++26

  @sa `<hazard_pointer>`
*/
#ifndef LBAL_LIBCPP26_HAZARD_POINTER
  #define LBAL_LIBCPP26_HAZARD_POINTER 0
#endif

/**
  @def LBAL_LIBCPP26_HIVE
  @brief Introduction of std::hive to the standard library
  @details SD-6 equivalent: `__cpp_lib_hive >= 202502L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `202502L` [P0447R28](https://wg21.link/P0447R28) Introduction of std::hive
  to the standard library

  @sa `<hive>`
*/
#ifndef LBAL_LIBCPP26_HIVE
  #define LBAL_LIBCPP26_HIVE 0
#endif

/**
  @def LBAL_LIBCPP26_INDIRECT
  @brief Vocabulary Types for Composite Class Design
  @details SD-6 equivalent: `__cpp_lib_indirect >= 202502L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3019R11](https://wg21.link/P3019R11) Vocabulary Types for
  Composite Class Design

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP26_INDIRECT
  #define LBAL_LIBCPP26_INDIRECT 0
#endif

/**
  @def LBAL_LIBCPP26_INITIALIZER_LIST
  @brief Resolve inconsistencies in begin/end for valarray and braced
  initializer lists
  @details SD-6 equivalent: `__cpp_lib_initializer_list >= 202511L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202511L` [P3016R6](https://wg21.link/P3016R6) Resolve inconsistencies in
  begin/end for valarray and braced initializer lists

  @sa `<initializer_list>`
*/
#ifndef LBAL_LIBCPP26_INITIALIZER_LIST
  #define LBAL_LIBCPP26_INITIALIZER_LIST 0
#endif

/**
  @def LBAL_LIBCPP26_INPLACE_VECTOR
  @brief inplace_vector
  @details SD-6 equivalent: `__cpp_lib_inplace_vector >= 202406L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202406L` [P0843R14](https://wg21.link/P0843R14) inplace_vector

  @sa `<inplace_vector>`
*/
#ifndef LBAL_LIBCPP26_INPLACE_VECTOR
  #define LBAL_LIBCPP26_INPLACE_VECTOR 0
#endif

/**
  @def LBAL_LIBCPP26_INTEGER_SEQUENCE_EXPANSION_STATEMENTS
  @brief Add library Support for Expansion Statements
  @details SD-6 equivalent: `__cpp_lib_integer_sequence >= 202511L`. Note that
  `__cpp_lib_integer_sequence` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202511L` [P1789R3](https://wg21.link/P1789R3) Library Support for Expansion
  Statements

  @sa `<utility>`
*/
#ifndef LBAL_LIBCPP26_INTEGER_SEQUENCE_EXPANSION_STATEMENTS
  #define LBAL_LIBCPP26_INTEGER_SEQUENCE_EXPANSION_STATEMENTS 0
#endif

/**
  @def LBAL_LIBCPP26_IS_VIRTUAL_BASE_OF
  @brief A type trait for detecting virtual base classes
  @details SD-6 equivalent: `__cpp_lib_is_virtual_base_of >= 202406L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202406L` [P2985R0](https://wg21.link/P2985R0) A type trait for detecting
  virtual base classes

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP26_IS_VIRTUAL_BASE_OF
  #define LBAL_LIBCPP26_IS_VIRTUAL_BASE_OF 0
#endif

/**
  @def LBAL_LIBCPP26_IS_WITHIN_LIFETIME
  @brief Checking if a union alternative is active
  @details SD-6 equivalent: `__cpp_lib_is_within_lifetime >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2641R4](https://wg21.link/P2641R4) Checking if a union
  alternative is active

  @sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP26_IS_WITHIN_LIFETIME
  #define LBAL_LIBCPP26_IS_WITHIN_LIFETIME 0
#endif

/**
  @def LBAL_LIBCPP26_LINALG
  @brief A free function linear algebra interface based on the BLAS
  @details SD-6 equivalent: `__cpp_lib_linalg >= 202311L`. Note that
  `__cpp_lib_linalg` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202311L` [P1673R13](https://wg21.link/P1673R13) A free function linear
  algebra interface based on the BLAS

  @sa `<linalg>`
*/
#ifndef LBAL_LIBCPP26_LINALG
  #define LBAL_LIBCPP26_LINALG 0
#endif

/**
  @def LBAL_LIBCPP26_LINALG_BLAS_RANK
  @brief Fix C++26 by making the rank-1, rank-2, rank-k, and rank-2k updates
  consistent with the BLAS
  @details SD-6 equivalent: `__cpp_lib_linalg >= 202511L`. Note that
  `__cpp_lib_linalg` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202511L` [P3371R5](https://wg21.link/P3371R5) Fix C++26 by making the rank-
  1, rank-2, rank-k, and rank-2k updates consistent with the BLAS

  @sa `<linalg>`
*/
#ifndef LBAL_LIBCPP26_LINALG_BLAS_RANK
  #define LBAL_LIBCPP26_LINALG_BLAS_RANK 0
#endif

/**
  @def LBAL_LIBCPP26_LINALG_FIX_TRANSPOSED
  @brief Fix C++26 by adding `transposed` special cases for P2642 layouts
  @details SD-6 equivalent: `__cpp_lib_linalg >= 202411L`. Note that
  `__cpp_lib_linalg` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202411L` [P3222R0](https://wg21.link/P3222R0) Fix C++26 by adding
  transposed special cases for P2642 layouts

  @sa `<linalg>`
*/
#ifndef LBAL_LIBCPP26_LINALG_FIX_TRANSPOSED
  #define LBAL_LIBCPP26_LINALG_FIX_TRANSPOSED 0
#endif

/**
  @def LBAL_LIBCPP26_LINALG_OPTIMIZE_CONJUGATED
  @brief Fix C++26 by optimizing linalg::conjugated for noncomplex value types
  @details SD-6 equivalent: `__cpp_lib_linalg >= 202411L`. Note that
  `__cpp_lib_linalg` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202411L` [P3050R2](https://wg21.link/P3050R2) Fix C++26 by optimizing
  linalg::conjugated for noncomplex value types

  @sa `<linalg>`
*/
#ifndef LBAL_LIBCPP26_LINALG_OPTIMIZE_CONJUGATED
  #define LBAL_LIBCPP26_LINALG_OPTIMIZE_CONJUGATED 0
#endif

/**
  @def LBAL_LIBCPP26_MDSPAN_DEXTENTS
  @brief `dextents` Index Type Parameter
  @details SD-6 equivalent: `__cpp_lib_mdspan >= 202406L`. Note that
  `__cpp_lib_mdspan` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202406L` [P2389R2](https://wg21.link/P2389R2) dextents Index Type Parameter

  @sa `<mdspan>`
*/
#ifndef LBAL_LIBCPP26_MDSPAN_DEXTENTS
  #define LBAL_LIBCPP26_MDSPAN_DEXTENTS 0
#endif

/**
  @def LBAL_LIBCPP26_NOT_FN_NTTP_CALLABLES
  @brief Bind `not_fn` to NTTP callables
  @details SD-6 equivalent: `__cpp_lib_not_fn >= 202306L`. Note that
  `__cpp_lib_not_fn` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P2714R1](https://wg21.link/P2714R1) Bind front and back to NTTP
  callables

  @sa `<functional>`
*/
#ifndef LBAL_LIBCPP26_NOT_FN_NTTP_CALLABLES
  #define LBAL_LIBCPP26_NOT_FN_NTTP_CALLABLES 0
#endif

/**
  @def LBAL_LIBCPP26_OBSERVABLE_CHECKPOINT
  @brief Rename std::observable to std::observable_checkpoint, and add a
  feature-test macro
  @details SD-6 equivalent: `__cpp_lib_observable_checkpoint >= 202506L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202506L` [P3641R0](https://wg21.link/P3641R0) Rename std::observable to
  std::observable_checkpoint, and add a feature-test macro

  @sa `<utility>`
*/
#ifndef LBAL_LIBCPP26_OBSERVABLE_CHECKPOINT
  #define LBAL_LIBCPP26_OBSERVABLE_CHECKPOINT 0
#endif

/**
  @def LBAL_LIBCPP26_OPTIONAL_RANGE_SUPPORT
  @brief Give std::optional Range Support
  @details SD-6 equivalent: `__cpp_lib_optional_range_support >= 202406L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202406L` [P3168R2](https://wg21.link/P3168R2) Give std::optional Range
  Support

  @sa `<optional>`
*/
#ifndef LBAL_LIBCPP26_OPTIONAL_RANGE_SUPPORT
  #define LBAL_LIBCPP26_OPTIONAL_RANGE_SUPPORT 0
#endif

/**
  @def LBAL_LIBCPP26_OPTIONAL_REFERENCE
  @brief `std::optional<T&>`
  @details SD-6 equivalent: `__cpp_lib_optional >= 202506L`. Note that
  `__cpp_lib_optional` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P2988R12](https://wg21.link/P2988R12) std::optional<T&>

  @sa `<optional>`
*/
#ifndef LBAL_LIBCPP26_OPTIONAL_REFERENCE
  #define LBAL_LIBCPP26_OPTIONAL_REFERENCE 0
#endif

/**
  @def LBAL_LIBCPP26_OUT_PTR_MORE
  @brief Freestanding Library: inout expected span
  @details SD-6 equivalent: `__cpp_lib_out_ptr >= 202311L`. Note that
  `__cpp_lib_out_ptr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202311L` [P2833R2](https://wg21.link/P2833R2) Freestanding Library: inout
  expected span

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP26_OUT_PTR_MORE
  #define LBAL_LIBCPP26_OUT_PTR_MORE 0
#endif

/**
  @def LBAL_LIBCPP26_PARALLEL_ALGORITHM_RANGE
  @brief Add C++ parallel `range` algorithms
  @details SD-6 equivalent: `__cpp_lib_parallel_algorithm >= 202506L`. Note that
  `__cpp_lib_parallel_algorithm` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P3179R9](https://wg21.link/P3179R9) C++ parallel range algorithms

  @sa `<algorithm>` `<numeric>`
*/
#ifndef LBAL_LIBCPP26_PARALLEL_ALGORITHM_RANGE
  #define LBAL_LIBCPP26_PARALLEL_ALGORITHM_RANGE 0
#endif

/**
  @def LBAL_LIBCPP26_PARALLEL_SCHEDULER
  @brief Parallel Scheduler
  @details SD-6 equivalent: `__cpp_lib_parallel_scheduler >= 202506L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202506L` [P2079R10](https://wg21.link/P2079R10) Parallel Scheduler

  @sa `<execution>`
*/
#ifndef LBAL_LIBCPP26_PARALLEL_SCHEDULER
  #define LBAL_LIBCPP26_PARALLEL_SCHEDULER 0
#endif

/**
  @def LBAL_LIBCPP26_PHILOX_ENGINE
  @brief Philox as an extension of the C++ RNG engines
  @details SD-6 equivalent: `__cpp_lib_philox_engine >= 202406L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202406L` [P2075R6](https://wg21.link/P2075R6) Philox as an extension of the
  C++ RNG engines

  @sa `<random>`
*/
#ifndef LBAL_LIBCPP26_PHILOX_ENGINE
  #define LBAL_LIBCPP26_PHILOX_ENGINE 0
#endif

/**
  @def LBAL_LIBCPP26_POLYMORPHIC
  @brief Vocabulary Types for Composite Class Design
  @details SD-6 equivalent: `__cpp_lib_polymorphic >= 202502L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3019R11](https://wg21.link/P3019R11) Vocabulary Types for
  Composite Class Design

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP26_POLYMORPHIC
  #define LBAL_LIBCPP26_POLYMORPHIC 0
#endif

/**
  @def LBAL_LIBCPP26_PRINT_EFFICIENT
  @brief Permit an efficient implementation of std::print
  @details SD-6 equivalent: `__cpp_lib_print >= 202403L`. Note that
  `__cpp_lib_print` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202403L` [P3107R5](https://wg21.link/P3107R5) Permit an efficient
  implementation of std::print

  @sa `<ostream>` `<print>`
*/
#ifndef LBAL_LIBCPP26_PRINT_EFFICIENT
  #define LBAL_LIBCPP26_PRINT_EFFICIENT 0
#endif

/**
  @def LBAL_LIBCPP26_PRINT_MORE_EFFICIENT
  @brief std::print more types faster with less memory
  @details SD-6 equivalent: `__cpp_lib_print >= 202406L`. Note that
  `__cpp_lib_print` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202406L` [P3235R3](https://wg21.link/P3235R3) std::print more types faster
  with less memory

  @sa `<ostream>` `<print>`
*/
#ifndef LBAL_LIBCPP26_PRINT_MORE_EFFICIENT
  #define LBAL_LIBCPP26_PRINT_MORE_EFFICIENT 0
#endif

/**
  @def LBAL_LIBCPP26_RANGES_AS_CONST_FIX_CONVERTIBILITY
  @brief std::basic_const_iterator should follow its underlying type’s
  convertibility
  @details SD-6 equivalent: `__cpp_lib_ranges_as_const >= 202311L`. Note that
  `__cpp_lib_ranges_as_const` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202311L` [P2836R1](https://wg21.link/P2836R1) std::basic_const_iterator
  should follow its underlying type’s convertibility

  @sa `<ranges>`
*/
#ifndef LBAL_LIBCPP26_RANGES_AS_CONST_FIX_CONVERTIBILITY
  #define LBAL_LIBCPP26_RANGES_AS_CONST_FIX_CONVERTIBILITY 0
#endif

/**
  @def LBAL_LIBCPP26_RANGES_CACHE_LATEST
  @brief views::cache_latest
  @details SD-6 equivalent: `__cpp_lib_ranges_cache_latest >= 202411L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202411L` [P3138R5](https://wg21.link/P3138R5) views::cache_latest

  @sa `<ranges>`
*/
#ifndef LBAL_LIBCPP26_RANGES_CACHE_LATEST
  #define LBAL_LIBCPP26_RANGES_CACHE_LATEST 0
#endif

/**
  @def LBAL_LIBCPP26_RANGES_CONCAT
  @brief views::concat
  @details SD-6 equivalent: `__cpp_lib_ranges_concat >= 202403L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202403L` [P2542R8](https://wg21.link/P2542R8) views::concat

  @sa `<ranges>`
*/
#ifndef LBAL_LIBCPP26_RANGES_CONCAT
  #define LBAL_LIBCPP26_RANGES_CONCAT 0
#endif

/**
  @def LBAL_LIBCPP26_RANGES_INDICES
  @brief Add std::views::indices(n)
  @details SD-6 equivalent: `__cpp_lib_ranges_indices >= 202506L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202506L` [P3060R3](https://wg21.link/P3060R3) Add std::views::indices(n)

  @sa `<ranges>`
*/
#ifndef LBAL_LIBCPP26_RANGES_INDICES
  #define LBAL_LIBCPP26_RANGES_INDICES 0
#endif

/**
  @def LBAL_LIBCPP26_RANGES_REMOVE_COMMON_REF_REQ
  @brief Removing the common reference requirement from the indirectly invocable
  concepts
  @details SD-6 equivalent: `__cpp_lib_ranges >= 202406L`. Note that
  `__cpp_lib_ranges` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202406L` [P2997R1](https://wg21.link/P2997R1) Removing the common reference
  requirement from the indirectly invocable concepts

  @sa `<algorithm>` `<functional>` `<iterator>` `<memory>` `<ranges>`
*/
#ifndef LBAL_LIBCPP26_RANGES_REMOVE_COMMON_REF_REQ
  #define LBAL_LIBCPP26_RANGES_REMOVE_COMMON_REF_REQ 0
#endif

/**
  @def LBAL_LIBCPP26_RANGES_RESERVE_HINT
  @brief reserve_hint: Eagerly reserving memory for not-quite-sized lazy ranges
  @details SD-6 equivalent: `__cpp_lib_ranges_reserve_hint >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P2846R6](https://wg21.link/P2846R6) reserve_hint: Eagerly
  reserving memory for not-quite-sized lazy ranges

  @sa `<ranges>`
*/
#ifndef LBAL_LIBCPP26_RANGES_RESERVE_HINT
  #define LBAL_LIBCPP26_RANGES_RESERVE_HINT 0
#endif

/**
  @def LBAL_LIBCPP26_RANGES_TO_INPUT
  @brief views::to_input
  @details SD-6 equivalent: `__cpp_lib_ranges_to_input >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3137R3](https://wg21.link/P3137R3) views::to_input

  @sa `<ranges>`
*/
#ifndef LBAL_LIBCPP26_RANGES_TO_INPUT
  #define LBAL_LIBCPP26_RANGES_TO_INPUT 0
#endif

/**
  @def LBAL_LIBCPP26_RATIO
  @brief Adding the new 2022 SI prefixes
  @details SD-6 equivalent: `__cpp_lib_ratio >= 202306L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `202306L` [P2734R0](https://wg21.link/P2734R0) Adding the new 2022 SI
  prefixes

  @sa `<ratio>`
*/
#ifndef LBAL_LIBCPP26_RATIO
  #define LBAL_LIBCPP26_RATIO 0
#endif

/**
  @def LBAL_LIBCPP26_RAW_MEMORY_ALGORITHMS_CONSTEXPR
  @brief Improve `constexpr` supprt for raw memory management
  @details SD-6 equivalent: `__cpp_lib_raw_memory_algorithms >= 202411L`. Note
  that `__cpp_lib_raw_memory_algorithms` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `202411L` [P3369R0](https://wg21.link/P3369R0) constexpr for
  uninitialized_default_construct
  - `202411L` [P3508R0](https://wg21.link/P3508R0) Wording for constexpr for
  specialized memory algorithms

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP26_RAW_MEMORY_ALGORITHMS_CONSTEXPR
  #define LBAL_LIBCPP26_RAW_MEMORY_ALGORITHMS_CONSTEXPR 0
#endif

/**
  @def LBAL_LIBCPP26_RCU
  @brief Read-Copy Update (RCU)
  @details SD-6 equivalent: `__cpp_lib_rcu >= 202306L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `202306L` [P2545R4](https://wg21.link/P2545R4) Read-Copy Update (RCU)

  @sa `<rcu>`
*/
#ifndef LBAL_LIBCPP26_RCU
  #define LBAL_LIBCPP26_RCU 0
#endif

/**
  @def LBAL_LIBCPP26_REFERENCE_WRAPPER
  @brief Comparisons for reference_wrapper
  @details SD-6 equivalent: `__cpp_lib_reference_wrapper >= 202403L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202403L` [P2944R3](https://wg21.link/P2944R3) Comparisons for
  reference_wrapper

  @sa `<functional>`
*/
#ifndef LBAL_LIBCPP26_REFERENCE_WRAPPER
  #define LBAL_LIBCPP26_REFERENCE_WRAPPER 0
#endif

/**
  @def LBAL_LIBCPP26_REFLECTION
  @brief Error Handling in Reflection
  @details SD-6 equivalent: `__cpp_lib_reflection >= 202506L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202506L` [P3560R2](https://wg21.link/P3560R2) Error Handling in Reflection

  @sa `<meta>`
*/
#ifndef LBAL_LIBCPP26_REFLECTION
  #define LBAL_LIBCPP26_REFLECTION 0
#endif

/**
  @def LBAL_LIBCPP26_SATURATION_ARITHMETIC
  @brief Saturation arithmetic
  @details SD-6 equivalent: `__cpp_lib_saturation_arithmetic >= 202311L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202311L` [P0543R3](https://wg21.link/P0543R3) Saturation arithmetic

  @sa `<numeric>`
*/
#ifndef LBAL_LIBCPP26_SATURATION_ARITHMETIC
  #define LBAL_LIBCPP26_SATURATION_ARITHMETIC 0
#endif

/**
  @def LBAL_LIBCPP26_SENDERS
  @brief std::execution
  @details SD-6 equivalent: `__cpp_lib_senders >= 202406L`. Note that
  `__cpp_lib_senders` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202406L` [P2300R10](https://wg21.link/P2300R10) std::execution

  @sa `<execution>`
*/
#ifndef LBAL_LIBCPP26_SENDERS
  #define LBAL_LIBCPP26_SENDERS 0
#endif

/**
  @def LBAL_LIBCPP26_SENDERS_OPTIONAL
  @brief `optional` variants in sender/receiver
  @details SD-6 equivalent: `__cpp_lib_senders >= 202506L`. Note that
  `__cpp_lib_senders` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P3570R2](https://wg21.link/P3570R2) optional variants in sender/
  receiver

  @sa `<execution>`
*/
#ifndef LBAL_LIBCPP26_SENDERS_OPTIONAL
  #define LBAL_LIBCPP26_SENDERS_OPTIONAL 0
#endif

/**
  @def LBAL_LIBCPP26_SIMD
  @brief std::simd - Merge data-parallel types from the Parallelism TS 2
  @details SD-6 equivalent: `__cpp_lib_simd >= 202411L`. Note that
  `__cpp_lib_simd` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202411L` [P1928R15](https://wg21.link/P1928R15) std::simd - Merge data-
  parallel types from the Parallelism TS 2

  @sa `<simd>`
*/
#ifndef LBAL_LIBCPP26_SIMD
  #define LBAL_LIBCPP26_SIMD 0
#endif

/**
  @def LBAL_LIBCPP26_SIMD_BIT
  @brief Extend `<bit>` header function with overloads for std::simd
  @details SD-6 equivalent: `__cpp_lib_simd >= 202502L`. Note that
  `__cpp_lib_simd` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202502L` [P2933R4](https://wg21.link/P2933R4) Extend header function with
  overloads for std::simd

  @sa `<simd>`
*/
#ifndef LBAL_LIBCPP26_SIMD_BIT
  #define LBAL_LIBCPP26_SIMD_BIT 0
#endif

/**
  @def LBAL_LIBCPP26_SIMD_CHUNK
  @brief Rename simd_split to simd_chunk
  @details SD-6 equivalent: `__cpp_lib_simd >= 202502L`. Note that
  `__cpp_lib_simd` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202502L` [P3441R2](https://wg21.link/P3441R2) Rename simd_split to
  simd_chunk

  @sa `<simd>`
*/
#ifndef LBAL_LIBCPP26_SIMD_CHUNK
  #define LBAL_LIBCPP26_SIMD_CHUNK 0
#endif

/**
  @def LBAL_LIBCPP26_SIMD_COMPLEX
  @brief Proposal to support interleaved complex values in std::simd
  @details SD-6 equivalent: `__cpp_lib_simd_complex >= 202502L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202502L` [P2663R7](https://wg21.link/P2663R7) Proposal to support
  interleaved complex values in std::simd

  @sa `<simd>`
*/
#ifndef LBAL_LIBCPP26_SIMD_COMPLEX
  #define LBAL_LIBCPP26_SIMD_COMPLEX 0
#endif

/**
  @def LBAL_LIBCPP26_SIMD_DEDUCTION_GUIDES
  @brief Missing deduction guide from simd::mask to simd::vec
  @details SD-6 equivalent: `__cpp_lib_simd >= 202511L`. Note that
  `__cpp_lib_simd` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202511L` [P3922R1](https://wg21.link/P3922R1) Missing deduction guide from
  simd::mask to simd::vec

  @sa `<simd>`
*/
#ifndef LBAL_LIBCPP26_SIMD_DEDUCTION_GUIDES
  #define LBAL_LIBCPP26_SIMD_DEDUCTION_GUIDES 0
#endif

/**
  @def LBAL_LIBCPP26_SIMD_EXTEND
  @brief Proposal to extend std::simd with more constructors and accessors
  @details SD-6 equivalent: `__cpp_lib_simd >= 202506L`. Note that
  `__cpp_lib_simd` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P2876R3](https://wg21.link/P2876R3) Proposal to extend std::simd
  with more constructors and accessors

  @sa `<simd>`
*/
#ifndef LBAL_LIBCPP26_SIMD_EXTEND
  #define LBAL_LIBCPP26_SIMD_EXTEND 0
#endif

/**
  @def LBAL_LIBCPP26_SIMD_NAMESPACES
  @brief Exploration of namespaces for std::simd
  @details SD-6 equivalent: `__cpp_lib_simd >= 202502L`. Note that
  `__cpp_lib_simd` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202502L` [P3287R3](https://wg21.link/P3287R3) Exploration of namespaces
  for std::simd

  @sa `<simd>`
*/
#ifndef LBAL_LIBCPP26_SIMD_NAMESPACES
  #define LBAL_LIBCPP26_SIMD_NAMESPACES 0
#endif

/**
  @def LBAL_LIBCPP26_SIMD_PERMUTATIONS
  @brief Proposal to extend std::simd with permutation API
  @details SD-6 equivalent: `__cpp_lib_simd_permutations >= 202506L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202506L` [P2664R11](https://wg21.link/P2664R11) Proposal to extend
  std::simd with permutation API

  @sa `<simd>`
*/
#ifndef LBAL_LIBCPP26_SIMD_PERMUTATIONS
  #define LBAL_LIBCPP26_SIMD_PERMUTATIONS 0
#endif

/**
  @def LBAL_LIBCPP26_SIMD_RANGE
  @brief std::simd is a range
  @details SD-6 equivalent: `__cpp_lib_simd >= 202506L`. Note that
  `__cpp_lib_simd` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P3480R6](https://wg21.link/P3480R6) std::simd is a range

  @sa `<simd>`
*/
#ifndef LBAL_LIBCPP26_SIMD_RANGE
  #define LBAL_LIBCPP26_SIMD_RANGE 0
#endif

/**
  @def LBAL_LIBCPP26_SMART_POINTER_OWNER_EQUALITY
  @brief Enabling the Use of weak_ptr as Keys in Unordered Associative
  Containers
  @details SD-6 equivalent: `__cpp_lib_smart_pointer_owner_equality >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P1901R2](https://wg21.link/P1901R2) Enabling the Use of weak_ptr
  as Keys in Unordered Associative Containers

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP26_SMART_POINTER_OWNER_EQUALITY
  #define LBAL_LIBCPP26_SMART_POINTER_OWNER_EQUALITY 0
#endif

/**
  @def LBAL_LIBCPP26_SMART_PTR_OWNER_EQUALITY
  @brief Enabling the Use of weak_ptr as Keys in Unordered Associative
  Containers
  @details SD-6 equivalent: `__cpp_lib_smart_ptr_owner_equality >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P1901R2](https://wg21.link/P1901R2) Enabling the Use of weak_ptr
  as Keys in Unordered Associative Containers

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP26_SMART_PTR_OWNER_EQUALITY
  #define LBAL_LIBCPP26_SMART_PTR_OWNER_EQUALITY 0
#endif

/**
  @def LBAL_LIBCPP26_SPAN_AT
  @brief `span.at()`
  @details SD-6 equivalent: `__cpp_lib_span >= 202311L`. Note that
  `__cpp_lib_span` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202311L` [P2821R5](https://wg21.link/P2821R5) span.at()

  @sa `<span>`
*/
#ifndef LBAL_LIBCPP26_SPAN_AT
  #define LBAL_LIBCPP26_SPAN_AT 0
#endif

/**
  @def LBAL_LIBCPP26_SPAN_INITIALIZER_LIST
  @brief std::span over an initializer list
  @details SD-6 equivalent: `__cpp_lib_span_initializer_list >= 202311L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202311L` [P2447R6](https://wg21.link/P2447R6) std::span over an initializer
  list

  @sa `<span>`
*/
#ifndef LBAL_LIBCPP26_SPAN_INITIALIZER_LIST
  #define LBAL_LIBCPP26_SPAN_INITIALIZER_LIST 0
#endif

/**
  @def LBAL_LIBCPP26_SPAN_MORE
  @brief Freestanding Library: inout expected span
  @details SD-6 equivalent: `__cpp_lib_span >= 202311L`. Note that
  `__cpp_lib_span` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202311L` [P2833R2](https://wg21.link/P2833R2) Freestanding Library: inout
  expected span

  @sa `<span>`
*/
#ifndef LBAL_LIBCPP26_SPAN_MORE
  #define LBAL_LIBCPP26_SPAN_MORE 0
#endif

/**
  @def LBAL_LIBCPP26_SSTREAM_FROM_STRING_VIEW
  @brief Interfacing stringstreams with string_view
  @details SD-6 equivalent: `__cpp_lib_sstream_from_string_view >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2495R3](https://wg21.link/P2495R3) Interfacing stringstreams
  with string_view

  @sa `<sstream>`
*/
#ifndef LBAL_LIBCPP26_SSTREAM_FROM_STRING_VIEW
  #define LBAL_LIBCPP26_SSTREAM_FROM_STRING_VIEW 0
#endif

/**
  @def LBAL_LIBCPP26_STRING_SUBVIEW
  @brief sub-string_view from string
  @details SD-6 equivalent: `__cpp_lib_string_subview >= 202506L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202506L` [P3044R2](https://wg21.link/P3044R2) sub-string_view from string

  @sa `<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP26_STRING_SUBVIEW
  #define LBAL_LIBCPP26_STRING_SUBVIEW 0
#endif

/**
  @def LBAL_LIBCPP26_STRING_VIEW_CONCAT
  @brief Allow concatenation of `std::string` and `std::string_view`
  @details SD-6 equivalent: `__cpp_lib_string_view >= 202403L`. Note that
  `__cpp_lib_string_view` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202403L` [P2591R5](https://wg21.link/P2591R5) Concatenation of strings and
  string views

  @sa `<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP26_STRING_VIEW_CONCAT
  #define LBAL_LIBCPP26_STRING_VIEW_CONCAT 0
#endif

/**
  @def LBAL_LIBCPP26_SUBMDSPAN
  @brief `submdspan`
  @details SD-6 equivalent: `__cpp_lib_submdspan >= 202306L`. Note that
  `__cpp_lib_submdspan` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P2630R4](https://wg21.link/P2630R4) Submdspan

  @sa `<mdspan>`
*/
#ifndef LBAL_LIBCPP26_SUBMDSPAN
  #define LBAL_LIBCPP26_SUBMDSPAN 0
#endif

/**
  @def LBAL_LIBCPP26_SUBMDSPAN_FIX
  @brief Fix `submdspan` for C++26
  @details SD-6 equivalent: `__cpp_lib_submdspan >= 202411L`. Note that
  `__cpp_lib_submdspan` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202411L` [P3355R1](https://wg21.link/P3355R1) Fix submdspan for C++26

  @sa `<mdspan>`
*/
#ifndef LBAL_LIBCPP26_SUBMDSPAN_FIX
  #define LBAL_LIBCPP26_SUBMDSPAN_FIX 0
#endif

/**
  @def LBAL_LIBCPP26_SUBMDSPAN_FUTURE_PROOF
  @brief Future-proof `submdspan`-mapping
  @details SD-6 equivalent: `__cpp_lib_submdspan >= 202511L`. Note that
  `__cpp_lib_submdspan` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202511L` [P3663R3](https://wg21.link/P3663R3) Future-proof submdspan-
  mapping

  @sa `<mdspan>`
*/
#ifndef LBAL_LIBCPP26_SUBMDSPAN_FUTURE_PROOF
  #define LBAL_LIBCPP26_SUBMDSPAN_FUTURE_PROOF 0
#endif

/**
  @def LBAL_LIBCPP26_SUBMDSPAN_PADDED
  @brief Padded `mdspan` layouts
  @details SD-6 equivalent: `__cpp_lib_submdspan >= 202403L`. Note that
  `__cpp_lib_submdspan` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202403L` [P2642R6](https://wg21.link/P2642R6) Padded mdspan layouts

  @sa `<mdspan>`
*/
#ifndef LBAL_LIBCPP26_SUBMDSPAN_PADDED
  #define LBAL_LIBCPP26_SUBMDSPAN_PADDED 0
#endif

/**
  @def LBAL_LIBCPP26_TASK
  @brief Add a Coroutine Task Type
  @details SD-6 equivalent: `__cpp_lib_task >= 202506L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `202506L` [P3552R3](https://wg21.link/P3552R3) Add a Coroutine Task Type

  @sa `<execution>`
*/
#ifndef LBAL_LIBCPP26_TASK
  #define LBAL_LIBCPP26_TASK 0
#endif

/**
  @def LBAL_LIBCPP26_TEXT_ENCODING
  @brief Naming Text Encodings to Demystify Them
  @details SD-6 equivalent: `__cpp_lib_text_encoding >= 202306L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202306L` [P1885R12](https://wg21.link/P1885R12) Naming Text Encodings to
  Demystify Them

  @sa `<text_encoding>`
*/
#ifndef LBAL_LIBCPP26_TEXT_ENCODING
  #define LBAL_LIBCPP26_TEXT_ENCODING 0
#endif

/**
  @def LBAL_LIBCPP26_TO_CHARS_BOOL_TEST
  @brief Test for success or failure of `<charconv>` functions
  @details SD-6 equivalent: `__cpp_lib_to_chars >= 202306L`. Note that
  `__cpp_lib_to_chars` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P2497R0](https://wg21.link/P2497R0) Testing for success or
  failure of charconv functions

  @sa `<charconv>`
*/
#ifndef LBAL_LIBCPP26_TO_CHARS_BOOL_TEST
  #define LBAL_LIBCPP26_TO_CHARS_BOOL_TEST 0
#endif

/**
  @def LBAL_LIBCPP26_TO_STRING
  @brief to_string or not to_string
  @details SD-6 equivalent: `__cpp_lib_to_string >= 202306L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202306L` [P2587R3](https://wg21.link/P2587R3) to_string or not to_string

  @sa `<string>`
*/
#ifndef LBAL_LIBCPP26_TO_STRING
  #define LBAL_LIBCPP26_TO_STRING 0
#endif

/**
  @def LBAL_LIBCPP26_TUPLE_LIKE_COMPLEX
  @brief Add tuple protocol to complex
  @details SD-6 equivalent: `__cpp_lib_tuple_like >= 202311L`. Note that
  `__cpp_lib_tuple_like` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202311L` [P2819R2](https://wg21.link/P2819R2) Add tuple protocol to complex

  @sa `<map>` `<tuple>` `<unordered_map>` `<utility>`
*/
#ifndef LBAL_LIBCPP26_TUPLE_LIKE_COMPLEX
  #define LBAL_LIBCPP26_TUPLE_LIKE_COMPLEX 0
#endif

/**
  @def LBAL_LIBCPP26_TYPE_ORDER
  @brief Standardized Constexpr Type Ordering
  @details SD-6 equivalent: `__cpp_lib_type_order >= 202506L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202506L` [P2830R10](https://wg21.link/P2830R10) Standardized Constexpr
  Type Ordering

  @sa `<compare>`
*/
#ifndef LBAL_LIBCPP26_TYPE_ORDER
  #define LBAL_LIBCPP26_TYPE_ORDER 0
#endif

/**
  @def LBAL_LIBCPP26_VALARRAY
  @brief Resolve inconsistencies in begin/end for valarray and braced
  initializer lists
  @details SD-6 equivalent: `__cpp_lib_valarray >= 202511L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202511L` [P3016R6](https://wg21.link/P3016R6) Resolve inconsistencies in
  begin/end for valarray and braced initializer lists

  @sa `<valarray>`
*/
#ifndef LBAL_LIBCPP26_VALARRAY
  #define LBAL_LIBCPP26_VALARRAY 0
#endif

/**
  @def LBAL_LIBCPP26_VARIANT_VISITOR
  @brief Member visit for `std::variant`
  @details SD-6 equivalent: `__cpp_lib_variant >= 202306L`. Note that
  `__cpp_lib_variant` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P2637R3](https://wg21.link/P2637R3) Member visit

  @sa `<variant>`
*/
#ifndef LBAL_LIBCPP26_VARIANT_VISITOR
  #define LBAL_LIBCPP26_VARIANT_VISITOR 0
#endif

///	@}	LBAL_LIBCPP26

/**
  @name LBAL_LIBCPP2D

  @brief These are all taken from features that have been incorporated into
  the C++2d Draft Standard.

  @remarks (FIXME - bitweeder) These are on hold till the associated proposals
  are published publicly.

  @{
*/

///	@}	LBAL_LIBCPP2D

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
