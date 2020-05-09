/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalFeatureSetup.hpp”
	Copyright © 2018-2020 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

------------------------------------------------------------------------------*/

#pragma once


//	lbal
#include <lucenaBAL/details/lbalConfig.hpp>

#include <lucenaBAL/details/lbalDefinitionTests.hpp>
#include <lucenaBAL/details/lbalPlatformSetup.hpp>
#include <lucenaBAL/details/lbalCompilerSetup.hpp>
#include <lucenaBAL/details/lbalLibrarySetup.hpp>
	//	The order in which these are initially included is important.


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

	__SEEME__ These are blunt instruments. In particular, there may be no
	differentiation between frontened (e.g., c1xx or clang) and backend
	(e.g., c2 or llvm). In practice, this mattered more when c2/clang was a
	thing, but seems less important now. We’ll consider revisiting if the extra
	granularity turns out to be useful.

	@{
*/

/**
	@def LBAL_TARGET_COMPILER_CLANG
	@brief The compiler being used is an llvm/clang derivative.
	@details This probably won’t match c2/clang, but no testing has been done
	to see what that setup may be emulating. More information is available from
	[the llvm project](https://clang.llvm.org/).

	@remarks __SEEME__ It would be trivial to split this identifier into one
	for clang and one for llvm, but it’s unclear how useful this would be.
*/
#ifndef LBAL_TARGET_COMPILER_CLANG
	#define LBAL_TARGET_COMPILER_CLANG 0
#endif

/**
	@def LBAL_TARGET_COMPILER_VANILLA_CLANG
	@brief The compiler being used is pure llvm/clang.
	@details More information is available from
	[the llvm project](https://clang.llvm.org/).

	@remarks __SEEME__ This is a more loose definition than it sounds like, as
	we’ll classify any clang as “vanilla clang” if some other check hasn’t
	previously claimed it, so order of evaluation matters, as does how thorough
	the previous checks were.
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

	@remarks __SEEME__ This is a more loose definition than it sounds like, as
	we’ll classify any gcc as “vanilla gcc” if some other check hasn’t
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

	@remarks __SEEME__ This is a more loose definition than it sounds like, as
	we’ll classify any MSVC as “vanilla MSVC” if some other check hasn’t
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

///@cond LBAL_INTERNAL
//	__APIME__ The library was previously being misidentified. This is here as
//	a temporary measure, but it is deprecated and will be going away.
#ifndef LBAL_TARGET_STANDARD_LIBRARY_STDLIBCPP
	#define LBAL_TARGET_STANDARD_LIBRARY_STDLIBCPP LBAL_TARGET_STANDARD_LIBRARY_LIBSTDCPP
#endif
///@endcond

///	@}	LBAL_TARGET_STANDARD_LIBRARY

/**
	@name LBAL_TARGET_CPU_FAMILY

	@brief Specify roughly which microprocessor family code is being generated
	for.

	@details At most one of these is 1, the rest are 0.

	@remarks __SEEME__ One additional candidate for inclusion is
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

	@remarks __SEEME__ There used to be more of these, but they’ve been largely
	mooted. Candidates for additions include console-specific processors and
	explicit differentiation for AMD processors.

	@remarks __SEEME__ More granular responses are possible, though it’s been
	viewed as more useful to differentiate on feature sets, instead (e.g.,
	AVX2 availability).

	@remarks __FIXME__ Testing for specific non-SIMD instruction availability,
	and additionally providing instrinsics, would be very helpful.
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

	@remarks __APIME__ There is no corresponding test for AVX-512, as it’s not
	a monolithic instruction set, and we don’t have the operational experience
	needed to evaluate a meaningful breakdown beyond just mirroring any
	predfined macros the compiler may happen to have.

	@remarks __SEEME__ We don’t currently independently check for SSE-Math and
	similar instruction splits; this may be a defect.

	@remarks __SEEME__ There used to be more of these, but they’ve been largely
	mooted. Candidates for additions include console-specific vector
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

	@remarks __SEEME__ Candidates for additions include console-specific
	operating systems, Android, tvOS, and watchOS. BSD could conceivably have
	its own flag, but we currently roll it in under LBAL_TARGET_OS_X11.

	@remarks __SEEME__ These focus primarily on UI characteristics, as opposed
	to system internals, which is why we have LBAL_TARGET_OS_X11 and not
	LBAL_TARGET_OS_POSIX. A case could be made that we realistically need to
	track both, but in practice - during the implementation of lucenaPAL - no
	practical need was found. It’s possible that once additional platform
	support is added to that library, we’ll find we need to revisit this design
	decision.

	@remarks __FIXME__ Wayland needs to be accounted for; currently, it’s
	rolled into LBAL_TARGET_OS_X11.

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

	@remarks __APIME__ Inclusion of specific formats is somewhat arbitrary,
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

	@remarks __SEEME__ This is not intended to be an exhaustive list of APIs.
	Originally, it was useful for differentiating between possible supported
	and available Apple APIs (e.g., QuickDraw, Carbon, Cocoa, and whatever
	other toolbox flavor of the week floats in), but it’s academic on platforms
	that don’t deprecate their APIs with abandon. Further operational
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

	@remarks __APIME__ Really only necessary for Windows.
*/
#ifndef LBAL_FEATURE_UTF16_FILE_SYSTEM
	#define LBAL_FEATURE_UTF16_FILE_SYSTEM 0
#endif

/**
	@def LBAL_FEATURE_CONSTEXPR_INTRINSICS

	@brief Indicate whether the current compiler’s intrinsics are constant
	expressions in the C++ sense.

	@details In the absence of a means to identify whether a given function is
	constexpr at compile-time, we rely on tools like this to aid us in
	determining, expression-by-expression, whether a given function is
	_probably_ able to be declared constexpr.

	@remarks __SEEME__ This is most likely insufficiently granular, but it’s
	academic for now: none of the supported compilers advertise constexpr
	intrinsics, and to the extent that they have any, it’s pure happenstance
	and dangerous to rely on.
*/
#ifndef LBAL_FEATURE_CONSTEXPR_INTRINSICS
	#define LBAL_FEATURE_CONSTEXPR_INTRINSICS 0
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
	accepted into the Standard from C++2a onwards will appear here.

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

	@remarks __APIME__ Some SD-6 tokens have their values bumped by newer
	iterations of the Document. Generally, we will issue new unique tokens here
	when this happens, _but the values of all such tokens will reflect that of
	the equivalent supported SD-6 token value_. For example, if SD-6 token
	`__cpp_meow` has 4 different values associated with it from 4 proposals
	against 4 successive Standards, we will define 4 unique tokens, one for
	each proposal. If the current build environment only supports the first 3
	of the 4 proposals, 3 of our tokens will be set to the most recent
	suppoeted proposal’s value for `__cpp_meow`, while the 4th of our tokens,
	representing the most recent—and unsupported—proposal, will be set to `0`.

	@remarks __SEEME__ Note that there are ambiguous cases where a feature may
	have been updated, e.g., as a result of a Defect Report (DR), but a new
	SD-6 value has not been assigned; this can be further complicated if the DR
	resolution is not finalized, meaning that the available feature is in an
	intermediate state. Currently, we have no policy for dealing with this
	situation, as it has not arisen yet in practice.

	@remarks __APIME__ Previous iterations of this header also attempted to
	determine whether various C99 and C11 features were available. This turned
	out to be impractical and a bit pointless. As a result, such features are
	only tracked - if they are tracked at all - in the context of their
	applicability to a given C++ Standard, e.g., support for the C99
	preprocessor as required by C++11, and the C11 preprocessor as required by
	C++2a.

	@remarks __SEEME__ Some implementations may choose to make a feature
	available to an earlier C++ release than the the first officially supported
	one. This can be done, for example, to make features available from a Draft
	Standard. Generally, we don’t second-guess the implementation if they set
	an SD-6 macro a particular—unless we have good reason to know it was set
	incorrectly. More challenging is dealing with implementations that _don’t_
	have SD-6 macros. Our approach in this case is to identify a feature as
	available if the implementation is known to support it _and_ the Language
	version in use is greater than the last unsupported version; this latter
	condition catches the frequent convention of compilers identifying a future
	unreleased dialect as the last Standard (e.g., 201103L) plus one (e.g.,
	201104L), until the Standard is official and the the version changes (e.g.,
	to 201402L).

	@remarks __APIME__ Features prior to the C++2a Standard are represented by
	tokens generally only if they have equivalent SD-6 tokens. Support can be
	broadened if there is demand.

	@remarks The SD-6 tokens and their values referenced here are current as of
	the 2019-10-02 revision.

	@{
*/

/**
	@name LBAL_CPP98
	These are here only because compilers can be made to disable specific
	features for various reasons and we want to have a universal way of
	determining whether that’s happened.

	@{
*/

/**
	@def LBAL_CPP98_EXCEPTIONS
	@brief Language-level support for C++ Exceptions
	@details This can be conditionally disabled at build-time, so we can’t rely
	on a language version test to detect it.

	Equivalent SD-6 macro: `__cpp_exceptions`
	- 199711L
*/
#ifndef LBAL_CPP98_EXCEPTIONS
	#define LBAL_CPP98_EXCEPTIONS 0
#endif

/**
	@def LBAL_CPP98_RTTI
	@brief Language-level support for run-time type identification (RTTI)
	@details This can be conditionally disabled at build-time, so we can’t rely
	on a language version test to detect it.

	Equivalent SD-6 macro: `__cpp_rtti`
	- 199711L
*/
#ifndef LBAL_CPP98_RTTI
	#define LBAL_CPP98_RTTI 0
#endif

///	@}	LBAL_CPP98

/**
	@name LBAL_CPP11
	All supported compilers support all required features of C++11. However,
	@ref LBAL_CPP11_THREADSAFE_STATIC_INIT "thread-safe static initialization"
	can be explicitly disabled in some implementations, and
	@ref LBAL_CPP11_MINIMAL_GARBAGE_COLLECTION "garbage collection" is an
	optional feature in C++. The rest of these are supplied to allow testing
	for specific features when using older language dialects, unsupported
	compilers, or when general language version detection is unavailable.

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
	@details Equivalent SD-6 macro: `__cpp_alias_templates`
	- [200704L](https://wg21.link/N2258) __PDF__
*/
#ifndef LBAL_CPP11_ALIAS_TEMPLATES
	#define LBAL_CPP11_ALIAS_TEMPLATES 0
#endif

/**
	@def LBAL_CPP11_ATTRIBUTE_CARRIES_DEPENDENCY
	@brief Optimization hint when compiling with certain memory models
	@details Equivalent SD-6 test: `__has_cpp_attribute(carries_dependency)`
	- [200809L](https://wg21.link/N2782) __PDF__
*/
#ifndef LBAL_CPP11_ATTRIBUTE_CARRIES_DEPENDENCY
	#define LBAL_CPP11_ATTRIBUTE_CARRIES_DEPENDENCY 0
#endif

/**
	@def LBAL_CPP11_ATTRIBUTE_NORETURN
	@brief Indicate that a function does not return
	@details Equivalent SD-6 test: `__has_cpp_attribute(noreturn)`
	- [200809L](https://wg21.link/N2761) __PDF__
*/
#ifndef LBAL_CPP11_ATTRIBUTE_NORETURN
	#define LBAL_CPP11_ATTRIBUTE_NORETURN 0
#endif

/**
	@def LBAL_CPP11_ATTRIBUTES
	@brief Formalize attributes as a language feature.
	@details Equivalent SD-6 macro: `__cpp_attributes`
	- [200809L](https://wg21.link/N2761) __PDF__
*/
#ifndef LBAL_CPP11_ATTRIBUTES
	#define LBAL_CPP11_ATTRIBUTES 0
#endif

/**
	@def LBAL_CPP11_CONSTEXPR
	@brief Specify generalized constant expressions
	@details Equivalent SD-6 macro: `__cpp_constexpr`. This token corresponds
	to the `200704L` variant, but it will have the value of the latest
	supported variant, or `0` if this variant is not supported.
	- [200704L](https://wg21.link/N2235) __PDF__
	- [201304L](https://wg21.link/n3652)
	- [201603L](https://wg21.link/p0170r1) __PDF__
	- [201806L](https://wg21.link/P1064R0)
	- [201811L](https://wg21.link/P1002R1)
	- [201811L](https://wg21.link/P1327R1)
	- [201811L](https://wg21.link/P1330R0)
	- [201907L](https://wg21.link/p1331r2) __PDF__
	- [201907L](https://wg21.link/P1668R1)

	@remarks `__cpp_constexpr` has many values associated with it, taken from a
	number of different proposals.
*/
#ifndef LBAL_CPP11_CONSTEXPR
	#define LBAL_CPP11_CONSTEXPR 0
#endif

/**
	@def LBAL_CPP11_DECLTYPE
	@brief Query the type of an expression
	@details Equivalent SD-6 macro: `__cpp_decltype`
	- [200707L](https://wg21.link/N2343) __PDF__
*/
#ifndef LBAL_CPP11_DECLTYPE
	#define LBAL_CPP11_DECLTYPE 0
#endif

/**
	@def LBAL_CPP11_DELEGATING_CONSTRUCTORS
	@brief Delegating constructors
	@details Equivalent SD-6 macro: `__cpp_delegating_constructors`
	- [200604L](https://wg21.link/N1986) __PDF__
*/
#ifndef LBAL_CPP11_DELEGATING_CONSTRUCTORS
	#define LBAL_CPP11_DELEGATING_CONSTRUCTORS 0
#endif

/**
	@def LBAL_CPP11_INHERITING_CONSTRUCTORS
	@brief Inheriting Constructors
	@details Equivalent SD-6 macro: `__cpp_inheriting_constructors`. This token
	corresponds to the `200802L` variant, but it will have the value of the
	latest supported variant, or `0` if this variant is not supported.
	- [200802L](https://wg21.link/n2540)
	- [201511L](https://wg21.link/p0136r1)

	@remarks `__cpp_inheriting_constructors` has at least 2 values associated
	with it, each from a different proposal.
*/
#ifndef LBAL_CPP11_INHERITING_CONSTRUCTORS
	#define LBAL_CPP11_INHERITING_CONSTRUCTORS 0
#endif

/**
	@def LBAL_CPP11_INITIALIZER_LISTS
	@brief Initializer lists
	@details Equivalent SD-6 macro: `__cpp_initializer_lists`
	- [200806L](https://wg21.link/n2672)
*/
#ifndef LBAL_CPP11_INITIALIZER_LISTS
	#define LBAL_CPP11_INITIALIZER_LISTS 0
#endif

/**
	@def LBAL_CPP11_LAMBDAS
	@brief Support for Lambda functions
	@details Equivalent SD-6 macro: `__cpp_lambdas`
	- [200907L](https://wg21.link/N2927) __PDF__
*/
#ifndef LBAL_CPP11_LAMBDAS
	#define LBAL_CPP11_LAMBDAS 0
#endif

/**
	@def LBAL_CPP11_MINIMAL_GARBAGE_COLLECTION
	@brief Support for optional C++ garbage collection.
	@details Equivalent SD-6 macro: none
	- [default](https://wg21.link/n2670)
*/
#ifndef LBAL_CPP11_MINIMAL_GARBAGE_COLLECTION
	#define LBAL_CPP11_MINIMAL_GARBAGE_COLLECTION 0
#endif

/**
	@def LBAL_CPP11_NSDMI
	@brief Support for non-static data member initializers.
	@details Equivalent SD-6 macro: `__cpp_nsdmi`
	- [200809L](https://wg21.link/n2756)
*/
#ifndef LBAL_CPP11_NSDMI
	#define LBAL_CPP11_NSDMI 0
#endif

/**
	@def LBAL_CPP11_RANGE_BASED_FOR
	@brief Range-based for-loops
	@details Equivalent SD-6 macro: `__cpp_range_based_for`. This token
	corresponds to the `200907L` variant, but it will have the value of the
	latest supported variant, or `0` if this variant is not supported.
	- [200907L](https://wg21.link/N2930)
	- [201603L](https://wg21.link/P0184R0)

	@remarks `__cpp_range_based_for` has at least 2 values associated with it,
	each from a different proposal.
*/
#ifndef LBAL_CPP11_RANGE_BASED_FOR
	#define LBAL_CPP11_RANGE_BASED_FOR 0
#endif

/**
	@def LBAL_CPP11_RAW_STRINGS
	@brief Support for raw string literals
	@details Equivalent SD-6 macro: `__cpp_raw_strings`
	- [200710L](https://wg21.link/n2442)
*/
#ifndef LBAL_CPP11_RAW_STRINGS
	#define LBAL_CPP11_RAW_STRINGS 0
#endif

/**
	@def LBAL_CPP11_REF_QUALIFIERS
	@brief Extend move semantics to *this
	@details Equivalent SD-6 macro: `__cpp_ref_qualifiers`
	- [200710L](https://wg21.link/n2439)
*/
#ifndef LBAL_CPP11_REF_QUALIFIERS
	#define LBAL_CPP11_REF_QUALIFIERS 0
#endif

/**
	@def LBAL_CPP11_RVALUE_REFERENCES
	@brief Add rvalue references
	@details Equivalent SD-6 macro: `__cpp_rvalue_references`
	- [200610L](https://wg21.link/n2118)
*/
#ifndef LBAL_CPP11_RVALUE_REFERENCES
	#define LBAL_CPP11_RVALUE_REFERENCES 0
#endif

/**
	@def LBAL_CPP11_STATIC_ASSERT
	@brief Add static assertions
	@details Equivalent SD-6 macro: `__cpp_static_assert`. This token
	   corresponds to the `200410L` variant, but it will have the value of the
	   latest supported variant, or `0` if this variant is not supported.
	- [200410L](https://wg21.link/n1720)
	- [201411L](https://wg21.link/N3928)

	@remarks `__cpp_static_assert` has at least 2 values associated with it,
	each from a different proposal.
*/
#ifndef LBAL_CPP11_STATIC_ASSERT
	#define LBAL_CPP11_STATIC_ASSERT 0
#endif

/**
	@def LBAL_CPP11_THREADSAFE_STATIC_INIT
	@brief Support for thread-safe static initialization.
	@details Some compilers can disable this feature if asked; the token will
	be set to `0` if that has happened.

	Equivalent SD-6 macro: `__cpp_threadsafe_static_init`
	- [200806L](https://wg21.link/n2660)
*/
#ifndef LBAL_CPP11_THREADSAFE_STATIC_INIT
	#define LBAL_CPP11_THREADSAFE_STATIC_INIT 0
#endif

/**
	@def LBAL_CPP11_UNICODE_CHARACTERS
	@brief Add `char16_t` and `char32_t` with requisite Unicode encoding
	@details Equivalent SD-6 macro: `__cpp_unicode_characters`
	- [200704L](https://wg21.link/n2249)
*/
#ifndef LBAL_CPP11_UNICODE_CHARACTERS
	#define LBAL_CPP11_UNICODE_CHARACTERS 0
#endif

/**
	@def LBAL_CPP11_UNICODE_LITERALS
	@brief Support for Unicode string literals
	@details Equivalent SD-6 macro: `__cpp_unicode_literals`
	- [200710L](https://wg21.link/n2442)
*/
#ifndef LBAL_CPP11_UNICODE_LITERALS
	#define LBAL_CPP11_UNICODE_LITERALS 0
#endif

/**
	@def LBAL_CPP11_USER_DEFINED_LITERALS
	@brief Support for user-defined literals
	@details Equivalent SD-6 macro: `__cpp_user_defined_literals`
	- [200809L](https://wg21.link/N2765) __PDF__
*/
#ifndef LBAL_CPP11_USER_DEFINED_LITERALS
	#define LBAL_CPP11_USER_DEFINED_LITERALS 0
#endif

/**
	@def LBAL_CPP11_VARIADIC_TEMPLATES
	@brief Support for templates with variable numbers of arguments
	@details Equivalent SD-6 macro: `__cpp_variadic_templates`
	- [200704L](https://wg21.link/N2242) __PDF__
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
	@details Equivalent SD-6 macro: `__cpp_aggregate_nsdmi`
	- [201304L](https://wg21.link/n3653)
*/
#ifndef LBAL_CPP14_AGGREGATE_NSDMI
	#define LBAL_CPP14_AGGREGATE_NSDMI 0
#endif

/**
	@def LBAL_CPP14_ATTRIBUTE_DEPRECATED
	@brief Support for marking symbols as deprecated
	@details Equivalent SD-6 test: `__has_cpp_attribute(deprecated)`
	- [201309L](https://wg21.link/n3760)
*/
#ifndef LBAL_CPP14_ATTRIBUTE_DEPRECATED
	#define LBAL_CPP14_ATTRIBUTE_DEPRECATED 0
#endif

/**
	@def LBAL_CPP14_BINARY_LITERALS
	@brief Add binary literal support.
	@details Equivalent SD-6 macro: `__cpp_binary_literals`
	- [201304L](https://wg21.link/N3472) __PDF__
*/
#ifndef LBAL_CPP14_BINARY_LITERALS
	#define LBAL_CPP14_BINARY_LITERALS 0
#endif

/**
	@def LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS
	@brief Relax constraints on `constexpr` functions, `constexpr` member
	functions and implicit `const`
	@details Equivalent SD-6 macro: `__cpp_constexpr`. This token corresponds
	to the `201304L` variant, but it will have the value of the latest
	supported variant, or `0` if this variant is not supported.
	- [200704L](https://wg21.link/N2235) __PDF__
	- [201304L](https://wg21.link/n3652)
	- [201603L](https://wg21.link/p0170r1) __PDF__
	- [201806L](https://wg21.link/P1064R0)
	- [201811L](https://wg21.link/P1002R1)
	- [201811L](https://wg21.link/P1327R1)
	- [201811L](https://wg21.link/P1330R0)
	- [201907L](https://wg21.link/p1331r2) __PDF__
	- [201907L](https://wg21.link/P1668R1)

	@remarks `__cpp_constexpr` has many values associated with it, taken from a
	number of different proposals.
*/
#ifndef LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS
	#define LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS 0
#endif

/**
	@def LBAL_CPP14_DECLTYPE_AUTO
	@brief Allow deduced return types and `decltype (auto)`
	@details Equivalent SD-6 macro: `__cpp_decltype_auto`
	- [201304L](https://wg21.link/n3638)
*/
#ifndef LBAL_CPP14_DECLTYPE_AUTO
	#define LBAL_CPP14_DECLTYPE_AUTO 0
#endif

/**
	@def LBAL_CPP14_GENERIC_LAMBDAS
	@brief Generic (Polymorphic) Lambda Expressions
	@details Equivalent SD-6 macro: `__cpp_generic_lambdas`. This token
	corresponds to the `201304L` variant, but it will have the value of the
	latest supported variant, or `0` if this variant is not supported.
	- [201304L](https://wg21.link/n3649)
	- [201707L](https://wg21.link/P0428R2)
*/
#ifndef LBAL_CPP14_GENERIC_LAMBDAS
	#define LBAL_CPP14_GENERIC_LAMBDAS 0
#endif

/**
	@def LBAL_CPP14_INIT_CAPTURES
	@brief Generalized Lambda-capture changes
	@details Equivalent SD-6 macro: `__cpp_init_captures`. This token
	corresponds to the `201304L` variant, but it will have the value of the
	latest supported variant, or `0` if this variant is not supported.
	- [201304L](https://wg21.link/n3648)
	- [201803L](https://wg21.link/P0780R2)
*/
#ifndef LBAL_CPP14_INIT_CAPTURES
	#define LBAL_CPP14_INIT_CAPTURES 0
#endif

/**
	@def LBAL_CPP14_RETURN_TYPE_DEDUCTION
	@brief Support for return type deduction for normal functions
	@details Equivalent SD-6 macro: `__cpp_return_type_deduction`
	- [201304L](https://wg21.link/n3638)
*/
#ifndef LBAL_CPP14_RETURN_TYPE_DEDUCTION
	#define LBAL_CPP14_RETURN_TYPE_DEDUCTION 0
#endif

/**
	@def LBAL_CPP14_SIZED_DEALLOCATION
	@brief Make available a global `operator delete` that takes a size argument
	@details Equivalent SD-6 macro: `__cpp_sized_deallocation`
	- [201309L](https://wg21.link/n3778)

	@remarks Some compilers disable this by default since it’s an ABI-breaking
	change; clang, in particular, does this.

*/
#ifndef LBAL_CPP14_SIZED_DEALLOCATION
	#define LBAL_CPP14_SIZED_DEALLOCATION 0
#endif

/**
	@def LBAL_CPP14_VARIABLE_TEMPLATES
	@brief Support for variable templates
	@details Equivalent SD-6 macro: `__cpp_variable_templates`
	- [201304L](https://wg21.link/N3651) __PDF__
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
	@details Equivalent SD-6 macro: `__cpp_aggregate_bases`
	- [201603L](https://wg21.link/p0017r1)
*/
#ifndef LBAL_CPP17_AGGREGATE_BASES
	#define LBAL_CPP17_AGGREGATE_BASES 0
#endif

/**
	@def LBAL_CPP17_ALIGNED_NEW
	@brief Specify handling of dynamic memory allocation for over-aligned data.
	@details Equivalent SD-6 macro: `__cpp_aligned_new`
	- [201606L](https://wg21.link/p0035r4)
*/
#ifndef LBAL_CPP17_ALIGNED_NEW
	#define LBAL_CPP17_ALIGNED_NEW 0
#endif

/**
	@def LBAL_CPP17_ATTRIBUTE_FALLTHROUGH
	@brief Indicate that a case within a switch statements falls through
	@details Equivalent SD-6 test: `__has_cpp_attribute(fallthrough)`
	- [201603L](https://wg21.link/P0188R1) __PDF__
*/
#ifndef LBAL_CPP17_ATTRIBUTE_FALLTHROUGH
	#define LBAL_CPP17_ATTRIBUTE_FALLTHROUGH 0
#endif

/**
	@def LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED
	@brief Indicate that a name or entity is possibly intentionally unused
	@details Equivalent SD-6 test: `__has_cpp_attribute(maybe_unused)`
	- [201603L](https://wg21.link/P0212R1) __PDF__
*/
#ifndef LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED
	#define LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED 0
#endif

/**
	@def LBAL_CPP17_ATTRIBUTE_NODISCARD
	@brief Indicate that a function return, class, or enum should not be
	ignored
	@details Equivalent SD-6 test: `__has_cpp_attribute(nodiscard)`. This token
	corresponds to the `201603L` variant, but it will have the value of the
	latest supported variant, or `0` if this variant is not supported.
	- [201603L](https://wg21.link/P0189R1) __PDF__
	- [201907L](https://wg21.link/P1301R4) __PDF__
	- [201907L](https://wg21.link/P1771R1) __PDF__

	@remarks The `nodiscard` attribute has at least 2 values associated with
	it, from a number of different proposals.
*/
#ifndef LBAL_CPP17_ATTRIBUTE_NODISCARD
	#define LBAL_CPP17_ATTRIBUTE_NODISCARD 0
#endif

/**
	@def LBAL_CPP17_CAPTURE_STAR_THIS
	@brief Allow lambda capture of `*this` by value as `as [=,*this]`.
	@details Equivalent SD-6 macro: `__cpp_capture_star_this`
	- [201603L](https://wg21.link/p0018r3)
*/
#ifndef LBAL_CPP17_CAPTURE_STAR_THIS
	#define LBAL_CPP17_CAPTURE_STAR_THIS 0
#endif

/**
	@def LBAL_CPP17_CONSTEXPR_LAMBDA
	@brief Allow lambdas to be constexpr explicitly or implicitly
	@details Equivalent SD-6 macro: `__cpp_constexpr`. This token corresponds
	to the `201603L` variant, but it will have the value of the latest
	supported variant, or `0` if this variant is not supported.
	- [200704L](https://wg21.link/N2235) __PDF__
	- [201304L](https://wg21.link/n3652)
	- [201603L](https://wg21.link/p0170r1) __PDF__
	- [201806L](https://wg21.link/P1064R0)
	- [201811L](https://wg21.link/P1002R1)
	- [201811L](https://wg21.link/P1327R1)
	- [201811L](https://wg21.link/P1330R0)
	- [201907L](https://wg21.link/p1331r2) __PDF__
	- [201907L](https://wg21.link/P1668R1)

	@remarks `__cpp_constexpr` has many values associated with it, taken from a
	number of different proposals.
*/
#ifndef LBAL_CPP17_CONSTEXPR_LAMBDA
	#define LBAL_CPP17_CONSTEXPR_LAMBDA 0
#endif

/**
	@def LBAL_CPP17_DEDUCTION_GUIDES
	@brief Template argument deduction for class templates
	@details Equivalent SD-6 macro: `__cpp_deduction_guides`. This token
	corresponds to the `201606L` variant, but it will have the value of the
	latest supported variant, or `0` if this variant is not supported.
	- [201606L](https://wg21.link/p0091r3)
	- [201611L](https://wg21.link/P0512R0) __PDF__
	- [201703L](https://wg21.link/p0620r0)
	- [201907L](https://wg21.link/p1814r0)
	- [201907L](https://wg21.link/P1816R0) __PDF__

	@remarks `__cpp_deduction_guides` has at least 4 values associated with it,
	across at least 5 proposals.
*/
#ifndef LBAL_CPP17_DEDUCTION_GUIDES
	#define LBAL_CPP17_DEDUCTION_GUIDES 0
#endif

/**
	@def LBAL_CPP17_DEDUCTION_GUIDES_DR
	@brief Address additional class template argument deduction issues
	@details Equivalent SD-6 macro: `__cpp_deduction_guides`. This token
	corresponds to the `201703L` variant, but it will have the value of the
	latest supported variant, or `0` if this variant is not supported.
	- [201606L](https://wg21.link/p0091r3)
	- [201611L](https://wg21.link/P0512R0) __PDF__
	- [201703L](https://wg21.link/p0620r0)
	- [201907L](https://wg21.link/p1814r0)
	- [201907L](https://wg21.link/P1816R0) __PDF__

	@remarks `__cpp_deduction_guides` has at least 4 values associated with it,
	across at least 5 proposals.
*/
#ifndef LBAL_CPP17_DEDUCTION_GUIDES_DR
	#define LBAL_CPP17_DEDUCTION_GUIDES_DR 0
#endif

/**
	@def LBAL_CPP17_DEDUCTION_GUIDES_NB
	@brief Address issues that came up during C++17 balloting regarding
	class template argument deduction
	@details Equivalent SD-6 macro: `__cpp_deduction_guides`. This token
	corresponds to the `201611L` variant, but it will have the value of the
	latest supported variant, or `0` if this variant is not supported.
	- [201606L](https://wg21.link/p0091r3)
	- [201611L](https://wg21.link/P0512R0) __PDF__
	- [201703L](https://wg21.link/p0620r0)
	- [201907L](https://wg21.link/p1814r0)
	- [201907L](https://wg21.link/P1816R0) __PDF__

	@remarks `__cpp_deduction_guides` has at least 4 values associated with it,
	across at least 5 proposals.
*/
#ifndef LBAL_CPP17_DEDUCTION_GUIDES_NB
	#define LBAL_CPP17_DEDUCTION_GUIDES_NB 0
#endif

/**
	@def LBAL_CPP17_ENUMERATOR_ATTRIBUTES
	@brief Attributes for enumerators
	@details Equivalent SD-6 macro: `__cpp_enumerator_attributes`
	- [201411L](https://wg21.link/n4266)
*/
#ifndef LBAL_CPP17_ENUMERATOR_ATTRIBUTES
	#define LBAL_CPP17_ENUMERATOR_ATTRIBUTES 0
#endif

/**
	@def LBAL_CPP17_FOLD_EXPRESSIONS
	@brief Allow folding a template parameter pack over a binary operator
	@details Equivalent SD-6 macro: `__cpp_fold_expressions`. This token
	corresponds to the `201411L` variant, but it will have the value of the
	latest supported variant, or `0` if this variant is not supported.
	- [201411L](https://wg21.link/n4295)
	- [201603L](https://wg21.link/P0036R0) __PDF__

	@remarks `__cpp_fold_expressions` has at least 2 values associated with it,
	across at least 2 proposals.
*/
#ifndef LBAL_CPP17_FOLD_EXPRESSIONS
	#define LBAL_CPP17_FOLD_EXPRESSIONS 0
#endif

/**
	@def LBAL_CPP17_FOLD_EXPRESSIONS_REVISED
	@brief Add support for unary folds and empty parameter packs to fold
	expressions
	@details Equivalent SD-6 macro: `__cpp_fold_expressions`. This token
	corresponds to the `201603L` variant, but it will have the value of the
	latest supported variant, or `0` if this variant is not supported.
	- [201411L](https://wg21.link/n4295)
	- [201603L](https://wg21.link/P0036R0) __PDF__

	@remarks `__cpp_fold_expressions` has at least 2 values associated with it,
	across at least 2 proposals.
*/
#ifndef LBAL_CPP17_FOLD_EXPRESSIONS_REVISED
	#define LBAL_CPP17_FOLD_EXPRESSIONS_REVISED 0
#endif

/**
	@def LBAL_CPP17_GUARANTEED_COPY_ELISION
	@brief Guarantee copy and move elision in well-defined situations
	@details Equivalent SD-6 macro: `__cpp_guaranteed_copy_elision`
	- [201606L](https://wg21.link/p0135r1)
*/
#ifndef LBAL_CPP17_GUARANTEED_COPY_ELISION
	#define LBAL_CPP17_GUARANTEED_COPY_ELISION 0
#endif

/**
	@def LBAL_CPP17_HEX_FLOAT
	@brief Specify Hexadecimal float literals
	@details Equivalent SD-6 macro: `__cpp_hex_float`
	- [201603L](https://wg21.link/p0245r1)
*/
#ifndef LBAL_CPP17_HEX_FLOAT
	#define LBAL_CPP17_HEX_FLOAT 0
#endif

/**
	@def LBAL_CPP17_IF_CONSTEXPR
	@brief Allow constant expressions as if statements
	@details Equivalent SD-6 macro: `__cpp_if_constexpr`
	- [201606L](https://wg21.link/p0292r2)
*/
#ifndef LBAL_CPP17_IF_CONSTEXPR
	#define LBAL_CPP17_IF_CONSTEXPR 0
#endif

/**
	@def LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED
	@brief Address core issues raised by Inheriting Constructors
	@details Equivalent SD-6 macro: `__cpp_inheriting_constructors`. This token
	corresponds to the `201511L` variant, but it will have the value of the
	latest supported variant, or `0` if this variant is not supported.
	- [200802L](https://wg21.link/n2540)
	- [201511L](https://wg21.link/p0136r1)

	@remarks `__cpp_inheriting_constructors` has at least 2 values associated
	with it, each from a different proposal.
*/
#ifndef LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED
	#define LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED 0
#endif

/**
	@def LBAL_CPP17_INLINE_VARIABLES
	@brief `inline` variables
	@details Equivalent SD-6 macro: `__cpp_inline_variables`
	- [201606L](https://wg21.link/P0386R2) __PDF__
*/
#ifndef LBAL_CPP17_INLINE_VARIABLES
	#define LBAL_CPP17_INLINE_VARIABLES 0
#endif

/**
	@def LBAL_CPP17_NAMESPACE_ATTRIBUTES
	@brief Attributes for namespaces
	@details Equivalent SD-6 macro: `__cpp_namespace_attributes`
	- [201411L](https://wg21.link/n4266)
*/
#ifndef LBAL_CPP17_NAMESPACE_ATTRIBUTES
	#define LBAL_CPP17_NAMESPACE_ATTRIBUTES 0
#endif

/**
	@def LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE
	@brief Make exception specifications be part of the type system
	@details Equivalent SD-6 macro: `__cpp_noexcept_function_type`
	- [201510L](https://wg21.link/p0012r1)
*/
#ifndef LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE
	#define LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE 0
#endif

/**
	@def LBAL_CPP17_NONTYPE_TEMPLATE_ARGS
	@brief Allow constant evaluation for all non-type template arguments
	@details Equivalent SD-6 macro: `__cpp_nontype_template_args`. This token
	corresponds to the `201411L` variant, but it will have the value of the
	latest supported variant, or `0` if this variant is not supported.
	- [201411L](https://wg21.link/n4268)
	- [201911L](https://wg21.link/P1907R1)
*/
#ifndef LBAL_CPP17_NONTYPE_TEMPLATE_ARGS
	#define LBAL_CPP17_NONTYPE_TEMPLATE_ARGS 0
#endif

/**
	@def LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO
	@brief Allow declaring non-type template arguments with auto
	@details Equivalent SD-6 macro: `__cpp_nontype_template_parameter_auto`
	- [201606L](https://wg21.link/p0127r2)
*/
#ifndef LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO
	#define LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO 0
#endif

/**
	@def LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED
	@brief Generalize range-based for-loops
	@details Equivalent SD-6 macro: `__cpp_range_based_for`. This token
	corresponds to the `201603L` variant, but it will have the value of the
	latest supported variant, or `0` if this variant is not supported.
	- [200907L](https://wg21.link/N2930)
	- [201603L](https://wg21.link/P0184R0)

	@remarks `__cpp_range_based_for` has at least 2 values associated with it,
	each from a different proposal.
*/
#ifndef LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED
	#define LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED 0
#endif

/**
	@def LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE
	@brief Allow static assertions with no messages
	@details Equivalent SD-6 macro: `__cpp_static_assert`. This token
	corresponds to the `201411L` variant, but it will have the value of the
	latest supported variant, or `0` if this variant is not supported.
	- [200410L](https://wg21.link/n1720)
	- [201411L](https://wg21.link/N3928) __PDF__

	@remarks `__cpp_static_assert` has at least 2 values associated with it,
	each from a different proposal.
*/
#ifndef LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE
	#define LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE 0
#endif

/**
	@def LBAL_CPP17_STRUCTURED_BINDINGS
	@brief Add support for multiple function return values and more
	@details Equivalent SD-6 macro: `__cpp_structured_bindings`
	- [201606L](https://wg21.link/p0217r3)
*/
#ifndef LBAL_CPP17_STRUCTURED_BINDINGS
	#define LBAL_CPP17_STRUCTURED_BINDINGS 0
#endif

/**
	@def LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS
	@brief Resolve a defect in the matching of template arguments with template
	parameters
	@details Equivalent SD-6 macro: `__cpp_template_template_args`
	- [201611L](https://wg21.link/p0522r0)

	@remarks The proposal this is from is intended to resolve a Defect Report,
	but unfortunately introduces a defect of its own. Some compilers
	are disabling this until a revised patch is in.
*/
#ifndef LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS
	#define LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS 0
#endif

/**
	@def LBAL_CPP17_VARIADIC_USING
	@brief Add support for pack expansions in using-declarations
	@details Equivalent SD-6 macro: `__cpp_variadic_using`
	- [201611L](https://wg21.link/p0195r2)
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

	@remarks __APIME__ Most of these have deprecated variants that use the
	`LBAL_CPP2A` prefix, dating from the time prior to the finalization of the
	C++20 Standard. Prefer using the `LBAL_CPP20` variants, as the deprecated
	versions will eventually be removed.

	@{
*/

/**
	@def LBAL_CPP20_AGGREGATE_PAREN_INIT
	@brief Allow aggregate initialization from parentheses as well as braces.
	@details Equivalent SD-6 macro: `__cpp_aggregate_paren_init`
	- [201902L](https://wg21.link/p0960r3)

	@remarks Note that paren initialization allows narrowing conversions, as
	usual.
*/
#ifndef LBAL_CPP20_AGGREGATE_PAREN_INIT
	#define LBAL_CPP20_AGGREGATE_PAREN_INIT 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_AGGREGATE_PAREN_INIT
		#define LBAL_CPP2A_AGGREGATE_PAREN_INIT LBAL_CPP20_AGGREGATE_PAREN_INIT
	#endif
///@endcond

/**
	@def LBAL_CPP20_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS

	Equivalent SD-6 macro: none
	- [default](https://wg21.link/p0409r2)
*/
#ifndef LBAL_CPP20_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS
	#define LBAL_CPP20_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS
		#define LBAL_CPP2A_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS \
			LBAL_CPP20_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS
	#endif
///@endcond

/**
	@def LBAL_CPP20_ATTRIBUTE_LIKELY

	Equivalent SD-6 test: `__has_cpp_attribute(likely)`
	- [201803L](https://wg21.link/p0479r5)
*/
#ifndef LBAL_CPP20_ATTRIBUTE_LIKELY
	#define LBAL_CPP20_ATTRIBUTE_LIKELY 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_ATTRIBUTE_LIKELY
		#define LBAL_CPP2A_ATTRIBUTE_LIKELY LBAL_CPP20_ATTRIBUTE_LIKELY
	#endif
///@endcond

/**
	@def LBAL_CPP20_ATTRIBUTE_NODISCARD_EXPANDED
	@brief Add explanatory text to the `nodiscard` attribute and allow it on
	constructors
	@details Equivalent SD-6 test: `__has_cpp_attribute(nodiscard)`. This token
	corresponds to the `201907L` variant, but it will have the value of the
	latest supported variant, or `0` if this variant is not supported.
	- [201603L](https://wg21.link/P0189R1) __PDF__
	- [201907L](https://wg21.link/p1301r4)
	- [201907L](https://wg21.link/P1771R1) __PDF__

	@remarks The `nodiscard` attribute has at least 2 values associated with
	it, from a number of different proposals.
*/
#ifndef LBAL_CPP20_ATTRIBUTE_NODISCARD_EXPANDED
	#define LBAL_CPP20_ATTRIBUTE_NODISCARD_EXPANDED 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_ATTRIBUTE_NODISCARD_EXPANDED
		#define LBAL_CPP2A_ATTRIBUTE_NODISCARD_EXPANDED \
			LBAL_CPP20_ATTRIBUTE_NODISCARD_EXPANDED
	#endif
///@endcond

/**
	@def LBAL_CPP20_ATTRIBUTE_UNLIKELY

	Equivalent SD-6 test: `__has_cpp_attribute(unlikely)`
	- [201803L](https://wg21.link/p0479r5)
*/
#ifndef LBAL_CPP20_ATTRIBUTE_UNLIKELY
	#define LBAL_CPP20_ATTRIBUTE_UNLIKELY 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_ATTRIBUTE_UNLIKELY
		#define LBAL_CPP2A_ATTRIBUTE_UNLIKELY LBAL_CPP20_ATTRIBUTE_UNLIKELY
	#endif
///@endcond

/**
	@def LBAL_CPP20_ATTRIBUTES_LIKELY_AND_UNLIKELY
	@brief Aggregate tracking the availability of `likely` and `unlikely`
	attributes
	@details We track the availability of each attribute separately, as well as
	provide this aggregate to test for compliance. The aggregate’s value
	will be `0` if either attribute is unavailable, or `1` otherwise.

	Equivalent SD-6 macro: none
	- [default](https://wg21.link/p0479r5)
*/
//	__SEEME__ To be defined correctly, this must be evaluated after the
//	component tokens have been defined.
#ifndef LBAL_CPP20_ATTRIBUTES_LIKELY_AND_UNLIKELY
	#define LBAL_CPP20_ATTRIBUTES_LIKELY_AND_UNLIKELY \
		((LBAL_CPP20_ATTRIBUTE_LIKELY != 0) && (LBAL_CPP20_ATTRIBUTE_UNLIKELY != 0))
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_ATTRIBUTES_LIKELY_AND_UNLIKELY
		#define LBAL_CPP2A_ATTRIBUTES_LIKELY_AND_UNLIKELY \
			LBAL_CPP20_ATTRIBUTES_LIKELY_AND_UNLIKELY
	#endif
///@endcond

/**
	@def LBAL_CPP20_ATTRIBUTE_NO_UNIQUE_ADDRESS

	Equivalent SD-6 macro: `__has_cpp_attribute(no_unique_address)`
	- [201803L](https://wg21.link/p0840r2)
*/
#ifndef LBAL_CPP20_ATTRIBUTE_NO_UNIQUE_ADDRESS
	#define LBAL_CPP20_ATTRIBUTE_NO_UNIQUE_ADDRESS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_ATTRIBUTE_NO_UNIQUE_ADDRESS
		#define LBAL_CPP2A_ATTRIBUTE_NO_UNIQUE_ADDRESS \
			LBAL_CPP20_ATTRIBUTE_NO_UNIQUE_ADDRESS
	#endif
///@endcond

/**
	@def LBAL_CPP20_CHAR8_T
	@brief Add `char8_t` as a UTF-8 equivalent for `char16_t` and `char32_t`.
	@details Equivalent SD-6 macro: `__cpp_char8_t`
	- [201811L](https://wg21.link/p0482r6)
*/
#ifndef LBAL_CPP20_CHAR8_T
	#define LBAL_CPP20_CHAR8_T 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_CHAR8_T
		#define LBAL_CPP2A_CHAR8_T LBAL_CPP20_CHAR8_T
	#endif
///@endcond

/**
	@def LBAL_CPP20_CONCEPTS
	@brief Incorporate the Concepts TS into the Standard
	@details Equivalent (SD-6) macro: `__cpp_concepts`. This token corresponds
	to the `201707L` variant, but it will have the value of the latest
	supported variant, or `0` if this variant is not supported.
	- [201707L](https://wg21.link/p0734r0) __PDF__
	- [201811L](https://wg21.link/P1084R2) __PDF__
	- [201907L](https://wg21.link/P1452R2)

	@remarks `__cpp_concepts` has at least 3 values associated with it, each
	from a different proposal.

	@remarks __SEEME__ Earlier versions of lucenaBAL used a placeholder value
	for this token. We’ve since updated to the official values from SD-6. No
	migration mechanism is in place since no impacted implementations were in
	the wild at the time.
*/
#ifndef LBAL_CPP20_CONCEPTS
	#define LBAL_CPP20_CONCEPTS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_CONCEPTS
		#define LBAL_CPP2A_CONCEPTS LBAL_CPP20_CONCEPTS
	#endif
///@endcond

/**
	@def LBAL_CPP20_CONCEPTS_RESPECIFY_RETURN_TYPE_REQUIREMENTS
	@brief Refine definition of return-type-requirements
	@details Equivalent (SD-6) macro: `__cpp_concepts`. This token corresponds
	to the `201811L` variant, but it will have the value of the latest
	supported variant, or `0` if this variant is not supported.
	- [201707L](https://wg21.link/p0734r0) __PDF__
	- [201811L](https://wg21.link/P1084R2) __PDF__
	- [201907L](https://wg21.link/P1452R2)

	@remarks `__cpp_concepts` has at least 3 values associated with it, each
	from a different proposal.

	@remarks __SEEME__ Earlier versions of lucenaBAL used a placeholder value
	for this token. We’ve since updated to the official values from SD-6. No
	migration mechanism is in place since no impacted implementations were in
	the wild at the time.
*/
#ifndef LBAL_CPP20_CONCEPTS_RESPECIFY_RETURN_TYPE_REQUIREMENTS
	#define LBAL_CPP20_CONCEPTS_RESPECIFY_RETURN_TYPE_REQUIREMENTS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_CONCEPTS_RESPECIFY_RETURN_TYPE_REQUIREMENTS
		#define LBAL_CPP2A_CONCEPTS_RESPECIFY_RETURN_TYPE_REQUIREMENTS \
			LBAL_CPP20_CONCEPTS_RESPECIFY_RETURN_TYPE_REQUIREMENTS
	#endif
///@endcond

/**
	@def LBAL_CPP20_CONCEPTS_REFINE_RETURN_TYPE_REQUIREMENTS
	@brief Refine definition of return-type-requirements
	@details Equivalent (SD-6) macro: `__cpp_concepts`. This token corresponds
	to the `201907L` variant, but it will have the value of the latest
	supported variant, or `0` if this variant is not supported.
	- [201707L](https://wg21.link/p0734r0) __PDF__
	- [201811L](https://wg21.link/P1084R2) __PDF__
	- [201907L](https://wg21.link/P1452R2)

	@remarks `__cpp_concepts` has at least 3 values associated with it, each
	from a different proposal.

	@remarks __SEEME__ Earlier versions of lucenaBAL used a placeholder value
	for this token. We’ve since updated to the official values from SD-6. No
	migration mechanism is in place since no impacted implementations were in
	the wild at the time.
*/
#ifndef LBAL_CPP20_CONCEPTS_REFINE_RETURN_TYPE_REQUIREMENTS
	#define LBAL_CPP20_CONCEPTS_REFINE_RETURN_TYPE_REQUIREMENTS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_CONCEPTS_REFINE_RETURN_TYPE_REQUIREMENTS
		#define LBAL_CPP2A_CONCEPTS_REFINE_RETURN_TYPE_REQUIREMENTS \
			LBAL_CPP20_CONCEPTS_REFINE_RETURN_TYPE_REQUIREMENTS
	#endif
///@endcond

/**
	@def LBAL_CPP20_CONDITIONAL_EXPLICIT
	Aka, `explicit (bool)`; allows simplification of templated constructors
	that have the potential to incorrectly convert their arguments.

	Equivalent SD-6 macro: `__cpp_conditional_explicit`
	- [201806L](https://wg21.link/p0892r2)
*/
#ifndef LBAL_CPP20_CONDITIONAL_EXPLICIT
	#define LBAL_CPP20_CONDITIONAL_EXPLICIT 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_CONDITIONAL_EXPLICIT
		#define LBAL_CPP2A_CONDITIONAL_EXPLICIT LBAL_CPP20_CONDITIONAL_EXPLICIT
	#endif
///@endcond

/**
	@def LBAL_CPP20_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS

	Equivalent SD-6 macro: none
	- [default](https://wg21.link/p0704r1)
*/
#ifndef LBAL_CPP20_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS
	#define LBAL_CPP20_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS
		#define LBAL_CPP2A_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS \
			LBAL_CPP20_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS
	#endif
///@endcond

/**
	@def LBAL_CPP20_CONSTEVAL
	@brief Immediate functions
	@details Equivalent SD-6 macro: `__cpp_consteval`
	- [201811L](https://wg21.link/P1073R3)
*/
#ifndef LBAL_CPP20_CONSTEVAL
	#define LBAL_CPP20_CONSTEVAL 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_CONSTEVAL
		#define LBAL_CPP2A_CONSTEVAL LBAL_CPP20_CONSTEVAL
	#endif
///@endcond

/**
	@def LBAL_CPP20_CONSTEXPR_DYNAMIC_ALLOC
	@brief Language support for variable-sized containers suitable for use in
	constexpr computations.
	@details Equivalent SD-6 macro: `__cpp_constexpr_dynamic_alloc`
	- [201907L](https://wg21.link/p0784r7)

	@remarks AKA, “More constexpr containers”.
*/
#ifndef LBAL_CPP20_CONSTEXPR_DYNAMIC_ALLOC
	#define LBAL_CPP20_CONSTEXPR_DYNAMIC_ALLOC 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_CONSTEXPR_DYNAMIC_ALLOC
		#define LBAL_CPP2A_CONSTEXPR_DYNAMIC_ALLOC \
			LBAL_CPP20_CONSTEXPR_DYNAMIC_ALLOC
	#endif
///@endcond

/**
	@def LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM
	@brief Allow `dynamic_cast`, polymorphic `typeid` in `constexpr` functions
	@details Equivalent SD-6 macro: `__cpp_constexpr`. This token corresponds
	to the [201811L](https://wg21.link/P1002R1) variant, but it will have the
	value of the latest supported variant, or `0` if this variant is not
	supported.
	- [200704L](https://wg21.link/N2235) __PDF__
	- [201304L](https://wg21.link/n3652)
	- [201603L](https://wg21.link/p0170r1) __PDF__
	- [201806L](https://wg21.link/P1064R0)
	- [201811L](https://wg21.link/P1002R1)
	- [201811L](https://wg21.link/P1327R1)
	- [201811L](https://wg21.link/P1330R0)
	- [201907L](https://wg21.link/p1331r2) __PDF__
	- [201907L](https://wg21.link/P1668R1)

	@remarks `__cpp_constexpr` has many values associated with it, taken from a
	number of different proposals.
	@remarks This and the `LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM` and
	`LBAL_CPP20_CONSTEXPR_UNION_ALTERATION` variants are aliases for each
	other.
*/
#ifndef LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM
	#define LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_CONSTEXPR_DYNAMIC_POLYMORPHISM
		#define LBAL_CPP2A_CONSTEXPR_DYNAMIC_POLYMORPHISM \
			LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM
	#endif
///@endcond

/**
	@def LBAL_CPP20_CONSTEXPR_IN_DECLTYPE
	@brief Address Core Issue regarding when `constexpr` functions are defined
	@details Equivalent SD-6 macro: `__cpp_constexpr_in_decltype`. This has the
	effect of allowing constant expressions in `decltype` declarations.
	- [201711L](https://wg21.link/P0859R0)
*/
#ifndef LBAL_CPP20_CONSTEXPR_IN_DECLTYPE
	#define LBAL_CPP20_CONSTEXPR_IN_DECLTYPE 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_CONSTEXPR_IN_DECLTYPE
		#define LBAL_CPP2A_CONSTEXPR_IN_DECLTYPE \
			LBAL_CPP20_CONSTEXPR_IN_DECLTYPE
	#endif
///@endcond

/**
	@def LBAL_CPP20_CONSTEXPR_INTRINSICS
	@brief Permit unevaluated inline assembly in `constexpr` functions
	@details Equivalent SD-6 macro: `__cpp_constexpr`. This token corresponds
	to the [201907L](https://wg21.link/P1668R1) variant, but it will have the
	value of the latest supported variant, or `0` if this variant is not
	supported.
	- [200704L](https://wg21.link/N2235) __PDF__
	- [201304L](https://wg21.link/n3652)
	- [201603L](https://wg21.link/p0170r1) __PDF__
	- [201806L](https://wg21.link/P1064R0)
	- [201811L](https://wg21.link/P1002R1)
	- [201811L](https://wg21.link/P1327R1)
	- [201811L](https://wg21.link/P1330R0)
	- [201907L](https://wg21.link/p1331r2) __PDF__
	- [201907L](https://wg21.link/P1668R1)

	@remarks `__cpp_constexpr` has many values associated with it, taken from a
	number of different proposals.
	@remarks This and the `LBAL_CPP20_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION`
	variant are aliases for each other.
*/
#ifndef LBAL_CPP20_CONSTEXPR_INTRINSICS
	#define LBAL_CPP20_CONSTEXPR_INTRINSICS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_CONSTEXPR_INTRINSICS
		#define LBAL_CPP2A_CONSTEXPR_INTRINSICS \
			LBAL_CPP20_CONSTEXPR_INTRINSICS
	#endif
///@endcond

/**
	@def LBAL_CPP20_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION
	@brief Address an inconsistency in the lambda specification
	@details Equivalent SD-6 macro: `__cpp_constexpr`. This token corresponds
	to the [201907L](https://wg21.link/p1331r2) variant, but it will have the
	value of the latest supported variant, or `0` if this variant is not
	supported.
	- [200704L](https://wg21.link/N2235) __PDF__
	- [201304L](https://wg21.link/n3652)
	- [201603L](https://wg21.link/p0170r1) __PDF__
	- [201806L](https://wg21.link/P1064R0)
	- [201811L](https://wg21.link/P1002R1)
	- [201811L](https://wg21.link/P1327R1)
	- [201811L](https://wg21.link/P1330R0)
	- [201907L](https://wg21.link/p1331r2) __PDF__
	- [201907L](https://wg21.link/P1668R1)

	@remarks `__cpp_constexpr` has many values associated with it, taken from a
	number of different proposals.
	@remarks This and the `LBAL_CPP20_CONSTEXPR_INTRINSICS` variant are aliases
	for each other.
*/
#ifndef LBAL_CPP20_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION
	#define LBAL_CPP20_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION
		#define LBAL_CPP2A_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION \
			LBAL_CPP20_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION
	#endif
///@endcond

/**
	@def LBAL_CPP20_CONSTEXPR_TRY_CATCH
	@brief Permit unevaluated inline assembly in constexpr functions
	@details Equivalent SD-6 macro: `__cpp_constexpr`. This token corresponds
	to the [201811L](https://wg21.link/P1002R1) variant, but it will have the
	value of the latest supported variant, or `0` if this variant is not
	supported.
	- [200704L](https://wg21.link/N2235) __PDF__
	- [201304L](https://wg21.link/n3652)
	- [201603L](https://wg21.link/p0170r1) __PDF__
	- [201806L](https://wg21.link/P1064R0)
	- [201811L](https://wg21.link/P1002R1)
	- [201811L](https://wg21.link/P1327R1)
	- [201811L](https://wg21.link/P1330R0)
	- [201907L](https://wg21.link/p1331r2) __PDF__
	- [201907L](https://wg21.link/P1668R1)

	@remarks `__cpp_constexpr` has many values associated with it, taken from a
	number of different proposals.
	@remarks This and the `LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM` and
	`LBAL_CPP20_CONSTEXPR_UNION_ALTERATION` variants are aliases for each
	other.
*/
#ifndef LBAL_CPP20_CONSTEXPR_TRY_CATCH
	#define LBAL_CPP20_CONSTEXPR_TRY_CATCH 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_CONSTEXPR_TRY_CATCH
		#define LBAL_CPP2A_CONSTEXPR_TRY_CATCH \
			LBAL_CPP20_CONSTEXPR_TRY_CATCH
	#endif
///@endcond

/**
	@def LBAL_CPP20_CONSTEXPR_UNION_ALTERATION
	@brief Allow changing the active member of a `union` in constexpr functions
	@details Equivalent SD-6 macro: `__cpp_constexpr`. This token corresponds
	to the [201811L](https://wg21.link/P1330R0) variant, but it will have the
	value of the latest supported variant, or `0` if this variant is not
	supported.
	- [200704L](https://wg21.link/N2235) __PDF__
	- [201304L](https://wg21.link/n3652)
	- [201603L](https://wg21.link/p0170r1) __PDF__
	- [201806L](https://wg21.link/P1064R0)
	- [201811L](https://wg21.link/P1002R1)
	- [201811L](https://wg21.link/P1327R1)
	- [201811L](https://wg21.link/P1330R0)
	- [201907L](https://wg21.link/p1331r2) __PDF__
	- [201907L](https://wg21.link/P1668R1)

	@remarks `__cpp_constexpr` has many values associated with it, taken from a
	number of different proposals.
	@remarks This and the `LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM` and
	`LBAL_CPP20_CONSTEXPR_TRY_CATCH` variants are aliases for each other.
*/
#ifndef LBAL_CPP20_CONSTEXPR_UNION_ALTERATION
	#define LBAL_CPP20_CONSTEXPR_UNION_ALTERATION 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_CONSTEXPR_UNION_ALTERATION
		#define LBAL_CPP2A_CONSTEXPR_UNION_ALTERATION \
			LBAL_CPP20_CONSTEXPR_UNION_ALTERATION
	#endif
///@endcond

/**
	@def LBAL_CPP20_CONSTEXPR_VIRTUAL_FUNCTION
	@brief Allow virtual function calls in constexpr functions
	@details Equivalent SD-6 macro: `__cpp_constexpr`. This token corresponds
	to the `201806L` variant, but it will have the value of the latest
	supported variant, or `0` if this variant is not supported.
	- [200704L](https://wg21.link/N2235) __PDF__
	- [201304L](https://wg21.link/n3652)
	- [201603L](https://wg21.link/p0170r1) __PDF__
	- [201806L](https://wg21.link/P1064R0)
	- [201811L](https://wg21.link/P1002R1)
	- [201811L](https://wg21.link/P1327R1)
	- [201811L](https://wg21.link/P1330R0)
	- [201907L](https://wg21.link/p1331r2) __PDF__
	- [201907L](https://wg21.link/P1668R1)

	@remarks `__cpp_constexpr` has many values associated with it, taken from a
	number of different proposals.
*/
#ifndef LBAL_CPP20_CONSTEXPR_VIRTUAL_FUNCTION
	#define LBAL_CPP20_CONSTEXPR_VIRTUAL_FUNCTION 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_CONSTEXPR_VIRTUAL_FUNCTION
		#define LBAL_CPP2A_CONSTEXPR_VIRTUAL_FUNCTION \
			LBAL_CPP20_CONSTEXPR_VIRTUAL_FUNCTION
	#endif
///@endcond

/**
	@def LBAL_CPP20_CONSTINIT
	@brief Add the `constinit` keyword
	@details This keyword provides a decorator that can be used to ensure that
	initialization of a constant is actually occuring as expected, regardless
	of any changing (i.e., dialect-specific) rules that might be in play.

	Equivalent SD-6 macro: __cpp_constinit
	- [201907L](https://wg21.link/p1143r2)

	@remarks This feature is broadly intended to be back-portable to older C++
	dialects; in certain circumstances it’s conceivable that `__cpp_constinit`
	will be set even if the dialect is older than C++2a.
*/
#ifndef LBAL_CPP20_CONSTINIT
	#define LBAL_CPP20_CONSTINIT 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_CONSTINIT
		#define LBAL_CPP2A_CONSTINIT LBAL_CPP20_CONSTINIT
	#endif
///@endcond

/**
	@def LBAL_CPP20_IMPL_COROUTINE
	@brief Add necessary language support for the `<coroutine>` library feature
	@details Equivalent SD-6 macro: `__cpp_impl_coroutine`
	- [201902L](https://wg21.link/p0912r5)
	- [201902L](https://wg21.link/LWG3393)

	@remarks Technically, the proposal this is from only directs that the
	Coroutines TS be merged into the Standard. For reference the latest draft
	is [n4775](https://wg21.link/n4775) __PDF__.
*/
#ifndef LBAL_CPP20_IMPL_COROUTINE
	#define LBAL_CPP20_IMPL_COROUTINE 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ These tokens have been renamed. The old names are deprecated
	//	and will be removed in a future release.
	#ifndef LBAL_CPP2A_COROUTINES
		#define LBAL_CPP2A_COROUTINES LBAL_CPP20_IMPL_COROUTINE
	#endif

	#ifndef LBAL_CPP2A_IMPL_COROUTINE
		#define LBAL_CPP2A_IMPL_COROUTINE LBAL_CPP20_IMPL_COROUTINE
	#endif
///@endcond

/**
	@def LBAL_CPP20_DEDUCTION_GUIDES_FOR_AGGREGATES
	@brief Class template argument deduction for aggregates
	@details Equivalent SD-6 macro: `__cpp_deduction_guides`. This token
	corresponds to the `201907L` variant, but it will have the value of the
	latest supported variant, or `0` if this variant is not supported.
	- [201606L](https://wg21.link/p0091r3)
	- [201611L](https://wg21.link/P0512R0) __PDF__
	- [201703L](https://wg21.link/p0620r0)
	- [201907L](https://wg21.link/p1814r0)
	- [201907L](https://wg21.link/P1816R0) __PDF__

	@remarks `__cpp_deduction_guides` has at least 4 values associated with it,
	across at least 5 proposals.
*/
#ifndef LBAL_CPP20_DEDUCTION_GUIDES_FOR_AGGREGATES
	#define LBAL_CPP20_DEDUCTION_GUIDES_FOR_AGGREGATES 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_DEDUCTION_GUIDES_FOR_AGGREGATES
		#define LBAL_CPP2A_DEDUCTION_GUIDES_FOR_AGGREGATES \
			LBAL_CPP20_DEDUCTION_GUIDES_FOR_AGGREGATES
	#endif
///@endcond

/**
	@def LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS
	@details Equivalent SD-6 macro: none
	- [default](https://wg21.link/p0624r2) __PDF__
*/
#ifndef LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS
	#define LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS
		#define LBAL_CPP2A_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS \
			LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS
	#endif
///@endcond

/**
	@def LBAL_CPP20_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS

	Equivalent SD-6 macro: none
	- [default](https://wg21.link/p0683r1)
*/
#ifndef LBAL_CPP20_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS
	#define LBAL_CPP20_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS
		#define LBAL_CPP2A_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS \
			LBAL_CPP20_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS
	#endif
///@endcond

/**
	@def LBAL_CPP20_DESIGNATED_INITIALIZERS

	Equivalent SD-6 macro: `__cpp_designated_initializers`
	- [201707L](https://wg21.link/P0329R4) __PDF__
*/
#ifndef LBAL_CPP20_DESIGNATED_INITIALIZERS
	#define LBAL_CPP20_DESIGNATED_INITIALIZERS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_DESIGNATED_INITIALIZERS
		#define LBAL_CPP2A_DESIGNATED_INITIALIZERS \
			LBAL_CPP20_DESIGNATED_INITIALIZERS
	#endif
///@endcond

/**
	@def LBAL_CPP20_DESTROYING_DELETE
	@brief Efficient sized delete for variable sized classes
	@details Equivalent SD-6 macro: `__cpp_impl_destroying_delete`
	- [201806L](https://wg21.link/p0722r3)
*/
#ifndef LBAL_CPP20_DESTROYING_DELETE
	#define LBAL_CPP20_DESTROYING_DELETE 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_DESTROYING_DELETE
		#define LBAL_CPP2A_DESTROYING_DELETE \
			LBAL_CPP20_DESTROYING_DELETE
	#endif
///@endcond

/**
	@def LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST
	@brief Generic (Polymorphic) Lambda Expressions
	@details Equivalent SD-6 macro: `__cpp_generic_lambdas`. This token
	corresponds to the `201707L` variant, but it will have the value of the
	latest supported variant, or `0` if this variant is not supported.
	- [201304L](https://wg21.link/n3649)
	- [201707L](https://wg21.link/P0428R2)
*/
#ifndef LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST
	#define LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ These tokens have been renamed. The old names are deprecated
	//	and will be removed in a future release.
	#ifndef LBAL_CPP2A_TEMPLATE_PARAMETER_LIST_FOR_GENERIC_LAMBDAS
		#define LBAL_CPP2A_TEMPLATE_PARAMETER_LIST_FOR_GENERIC_LAMBDAS \
				LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST
	#endif

	#ifndef LBAL_CPP2A_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST
		#define LBAL_CPP2A_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST \
			LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST
	#endif
///@endcond

/**
	@def LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION
	@brief Allow pack-expansion in lambda init-capture
	@details Equivalent SD-6 macro: `__cpp_init_captures`. This token
	corresponds to the `201803L` variant, but it will have the value of the
	latest supported variant, or `0` if this variant is not supported.
	- [201304L](https://wg21.link/n3648)
	- [201803L](https://wg21.link/P0780R2)
*/
#ifndef LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION
	#define LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ These tokens have been renamed. The old names are deprecated
	//	and will be removed in a future release.
	#ifndef LBAL_CPP2A_PACK_EXPANSION_IN_LAMBDA_INIT_CAPTURE
		#define LBAL_CPP2A_PACK_EXPANSION_IN_LAMBDA_INIT_CAPTURE \
				LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION
	#endif

	#ifndef LBAL_CPP2A_INIT_CAPTURES_PACK_EXPANSION
		#define LBAL_CPP2A_INIT_CAPTURES_PACK_EXPANSION \
			LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION
	#endif
///@endcond

/**
	@def LBAL_CPP20_INIT_STATEMENTS_FOR_RANGE_BASED_FOR

	Equivalent SD-6 macro: none
	- [default](https://wg21.link/p0614r1)
*/
#ifndef LBAL_CPP20_INIT_STATEMENTS_FOR_RANGE_BASED_FOR
	#define LBAL_CPP20_INIT_STATEMENTS_FOR_RANGE_BASED_FOR 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_INIT_STATEMENTS_FOR_RANGE_BASED_FOR
		#define LBAL_CPP2A_INIT_STATEMENTS_FOR_RANGE_BASED_FOR \
			LBAL_CPP20_INIT_STATEMENTS_FOR_RANGE_BASED_FOR
	#endif
///@endcond

/**
	@def LBAL_CPP20_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION

	Equivalent SD-6 macro: none
	- [default](https://wg21.link/p0702r1)
*/
#ifndef LBAL_CPP20_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION
	#define LBAL_CPP20_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION	0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION
		#define LBAL_CPP2A_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION \
			LBAL_CPP20_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION
	#endif
///@endcond

/**
	@def LBAL_CPP20_INTEGRATING_OUR_FEATURE_TEST_MACROS
	@brief Integrate universal feature test macros into the Standard
	@details Equivalent SD-6 macro: none (ironically)
	- [default](https://wg21.link/p0941r2)

	@remarks It appears this is only here to get Microsoft to support SD-6, as
	the other major compilers de facto meet the requirement.
*/
#ifndef LBAL_CPP20_INTEGRATING_OUR_FEATURE_TEST_MACROS
	#define LBAL_CPP20_INTEGRATING_OUR_FEATURE_TEST_MACROS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_INTEGRATING_OUR_FEATURE_TEST_MACROS
		#define LBAL_CPP2A_INTEGRATING_OUR_FEATURE_TEST_MACROS \
			LBAL_CPP20_INTEGRATING_OUR_FEATURE_TEST_MACROS
	#endif
///@endcond

/**
	@def LBAL_CPP20_MODULES
	@brief Incorporate modules
	@details Equivalent SD-6 macro: `__cpp_modules`
	- [201907L](https://wg21.link/P1103R3) __PDF__
	- [201907L](https://wg21.link/p1811r0)
*/
#ifndef LBAL_CPP20_MODULES
	#define LBAL_CPP20_MODULES 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_MODULES
		#define LBAL_CPP2A_MODULES LBAL_CPP20_MODULES
	#endif
///@endcond

/**
	@def LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FIXES
	@brief Address inconsistencies in handling of non-type template arguments
	@details Equivalent SD-6 macro: `__cpp_nontype_template_args`. This token
	corresponds to the `201911L` variant, but it will have the value of the
	latest supported variant, or `0` if this variant is not supported.
	- [201411L](https://wg21.link/n4268)
	- [201911L](https://wg21.link/P1907R1)
*/
#ifndef LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FIXES
	#define LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FIXES 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_NONTYPE_TEMPLATE_ARGS_FIXES
		#define LBAL_CPP2A_NONTYPE_TEMPLATE_ARGS_FIXES \
			LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FIXES
	#endif
///@endcond

/**
	@def LBAL_CPP20_NONTYPE_TEMPLATE_PARAMETER_CLASS
	@brief Class Types in Non-Type Template Parameters
	@details Equivalent SD-6 macro: `__cpp_nontype_template_parameter_class`
	- [201806L](https://wg21.link/p0732r2) __PDF__

	@remarks __SEEME__ There’s a slightly confusing note in the SD-6 document
	as of December 2019 which indicates a potential issue with this token. One
	interpretation is that an earlier version of the doc had incorrectly
	associated an unrelated proposal as an iteration on this feature; this is
	the interpretation we’re following.
*/
#ifndef LBAL_CPP20_NONTYPE_TEMPLATE_PARAMETER_CLASS
	#define LBAL_CPP20_NONTYPE_TEMPLATE_PARAMETER_CLASS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ These tokens have been renamed. The old names are deprecated
	//	and will be removed in a future release.
	#ifndef LBAL_CPP2A_CLASS_TYPES_AS_NON_TYPE_TEMPLATE_PARAMETERS
		#define LBAL_CPP2A_CLASS_TYPES_AS_NON_TYPE_TEMPLATE_PARAMETERS \
			LBAL_CPP20_NONTYPE_TEMPLATE_PARAMETER_CLASS
	#endif

	#ifndef LBAL_CPP2A_NONTYPE_TEMPLATE_PARAMETER_CLASS
		#define LBAL_CPP2A_NONTYPE_TEMPLATE_PARAMETER_CLASS \
			LBAL_CPP20_NONTYPE_TEMPLATE_PARAMETER_CLASS
	#endif
///@endcond

/**
	@def LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR
	@brief This is the original three-way comparison operator
	@details Equivalent SD-6 macro: `__cpp_impl_three_way_comparison`. This
	token corresponds to the `201711L` variant, but it will have a value of
	`201907L` if that variant is available.
	- [201711L](https://wg21.link/p0515r3) __PDF__
	- [201711L](https://wg21.link/p0768r1) __PDF__
	- [201902L](https://wg21.link/p1185r2)
	- [201907L](https://wg21.link/p1186r3)
	- [201907L](https://wg21.link/p1630r1)
*/
#ifndef LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR
	#define LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR
		#define LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR \
			LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR
	#endif
///@endcond

/**
	@def LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_EQUALITY_FIX
	@brief This is the original three-way comparison operator
	@details Equivalent SD-6 macro: `__cpp_impl_three_way_comparison`. This
	token corresponds to the `201902L` variant, but it will have a value of
	`201907L` if that variant is available.
	- [201711L](https://wg21.link/p0515r3) __PDF__
	- [201711L](https://wg21.link/p0768r1) __PDF__
	- [201902L](https://wg21.link/p1185r2)
	- [201907L](https://wg21.link/p1186r3)
	- [201907L](https://wg21.link/p1630r1)
*/
#ifndef LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_EQUALITY_FIX
	#define LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_EQUALITY_FIX 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR_EQUALITY_FIX
		#define LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR_EQUALITY_FIX \
			LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_EQUALITY_FIX
	#endif
///@endcond

/**
	@def LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_TUNEUP
	@brief This is the updated three-way comparison operator
	@details Equivalent SD-6 macro: `__cpp_impl_three_way_comparison`. This
	token corresponds to the `201907L` variant; it will only be set to a
	non-`0` value if that variant is available.
	- [201711L](https://wg21.link/p0515r3) __PDF__
	- [201711L](https://wg21.link/p0768r1) __PDF__
	- [201902L](https://wg21.link/p1185r2)
	- [201907L](https://wg21.link/p1186r3)
	- [201907L](https://wg21.link/p1630r1)
*/
#ifndef LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_TUNEUP
	#define LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_TUNEUP 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR_TUNEUP
		#define LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR_TUNEUP \
			LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_TUNEUP
	#endif
///@endcond

/**
	@def LBAL_CPP20_TYPENAME_OPTIONAL

	Equivalent SD-6 macro: none
	- [default](https://wg21.link/p0634r2)
*/
#ifndef LBAL_CPP20_TYPENAME_OPTIONAL
	#define LBAL_CPP20_TYPENAME_OPTIONAL 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_TYPENAME_OPTIONAL
		#define LBAL_CPP2A_TYPENAME_OPTIONAL LBAL_CPP20_TYPENAME_OPTIONAL
	#endif
///@endcond

/**
	@def LBAL_CPP20_USING_ENUM
	@brief Specify using aliases for enums
	@details Equivalent SD-6 macro: `__cpp_using_enum`
	- [201907L](https://wg21.link/p1099r5)
*/
#ifndef LBAL_CPP20_USING_ENUM
	#define LBAL_CPP20_USING_ENUM 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_USING_ENUM
		#define LBAL_CPP2A_USING_ENUM LBAL_CPP20_USING_ENUM
	#endif
///@endcond

/**
	@def LBAL_CPP20_VA_OPT
	@brief Provide a smarter predefined macro equivalent to __VA__ARGS__
	@details This behaves similarly to Microsoft’s old “broken” C preprocessor
	implementation in regards to variadic macro handling, in that [0..n]
	arguments are allowed rather than [1..n], with any extraneous comma being
	dropped.

	Equivalent SD-6 macro: none
	- [default](https://wg21.link/p0306r4)
	- [default](https://wg21.link/p1042r1)

	@remarks Ironically, MSVC has no implementation of this.
*/
#ifndef LBAL_CPP20_VA_OPT
	#define LBAL_CPP20_VA_OPT 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_CPP2A_VA_OPT
		#define LBAL_CPP2A_VA_OPT LBAL_CPP20_VA_OPT
	#endif
///@endcond

///	@}	LBAL_CPP20

/**
	@name Technical Specifications and Proposals
	Most of these will eventually migrate to one of the other sections, at
	which time the associated macro will be renamed (and possibly aliased).

	@{
*/

/**
	@brief Contracts: Assert Attribute

	@details This is one of a bundle of attributes using a new syntax. It takes
	the place of preprocessor-style asserts and serves the same purpose.

	Equivalent SD-6 test: `__has_cpp_attribute(assert)`
	- [unassigned](https://wg21.link/p0542r5)

	@remarks These were yoinked from C++2A prior to national balloting for
	various reasons and are currently back in the oven, but expected to pop in
	the C++23 Draft Standard.
*/
#ifndef LBAL_CPPTS_ATTRIBUTE_ASSERT
	#define LBAL_CPPTS_ATTRIBUTE_ASSERT 0
#endif

/**
	@brief Contracts: Postcondition Attribute

	@details This is one of a bundle of attributes using a new syntax. It
	identifies function postconditions amd is intended to allow at least
	partial enforcement by a static analyzer.

	Equivalent SD-6 test: `__has_cpp_attribute(assert)`
	- [unassigned](https://wg21.link/p0542r5)

	@remarks These were yoinked from C++2A prior to national balloting for
	various reasons and are currently back in the oven, but expected to pop in
	the C++23 Draft Standard.
*/
#ifndef LBAL_CPPTS_ATTRIBUTE_ENSURES
	#define LBAL_CPPTS_ATTRIBUTE_ENSURES 0
#endif

/**
	@brief Contracts: Precondition Attribute

	@details This is one of a bundle of attributes using a new syntax. It
	identifies function preconditions amd is intended to allow at least partial
	enforcement by a static analyzer.

	Equivalent SD-6 test: `__has_cpp_attribute(expects)`
	- [unassigned](https://wg21.link/p0542r5)

	@remarks These were yoinked from C++2A prior to national balloting for
	various reasons and are currently back in the oven, but expected to pop in
	the C++23 Draft Standard.
*/
#ifndef LBAL_CPPTS_ATTRIBUTE_EXPECTS
	#define LBAL_CPPTS_ATTRIBUTE_EXPECTS 0
#endif

/**
	@brief Contracts

	@details This is actually a bundle of attributes using a new syntax; the
	syntax itself has no SD-6 macro, so we rely on the presence of the
	attributes to determine support. We track the availability of each
	attribute separately, as well as provide an aggregate to test for
	compliance. The aggregate’s value will be `0` if any attribute is
	unavailable, or `1` otherwise.

	Equivalent SD-6 macro: none
	- [default](https://wg21.link/p0542r5)

	@remarks These were yoinked from C++2A prior to national balloting for
	various reasons and are currently back in the oven, but expected to pop in
	the C++23 Draft Standard.
*/
#ifndef LBAL_CPPTS_CONTRACTS
	#define LBAL_CPPTS_CONTRACTS 0
#endif

///@cond LBAL_INTERNAL
//	__APIME__ These tokens were all renamed after being stripped from the
//	Draft Standard. They have not yet been formally resubmitted for the next
//	cycle.
#ifndef LBAL_CPP2A_ATTRIBUTE_ASSERT
	#define LBAL_CPP2A_ATTRIBUTE_ASSERT LBAL_CPPTS_ATTRIBUTE_ASSERT
#endif

#ifndef LBAL_CPP2A_ATTRIBUTE_ENSURES
	#define LBAL_CPP2A_ATTRIBUTE_ENSURES LBAL_CPPTS_ATTRIBUTE_ENSURES
#endif

#ifndef LBAL_CPP2A_ATTRIBUTE_EXPECTS
	#define LBAL_CPP2A_ATTRIBUTE_EXPECTS LBAL_CPPTS_ATTRIBUTE_EXPECTS
#endif

#ifndef LBAL_CPP2A_CONTRACTS
	#define LBAL_CPP2A_CONTRACTS LBAL_CPPTS_CONTRACTS
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
	__SEEME__ Only older versions of MSVS are known to have problems with this,
	despite otherwise conforming to the C++11 Standard. Note that if support
	requires having a particular compiler switch set to get compatibility,
	this token will mirror that condition.
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
	given feature being part of a [Technical Specification](https://en.cppreference.com/w/cpp/experimental)
	that has not yet been incorporated into the Standard. Note that
	`LBAL_LIBCPP*_*` and `LBAL_LIBCPP*_*_EXP` are mutually exclusive:

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

	@remarks __APIME__ As implied above, sometimes it is possible to definitely
	determine that a feature is _not_ available, even if we cannot definitelty
	determine whether it _is_ available. In both cases, we set the
	corresponding token to `0`, but in the latter case the client may override
	us, and in the former we’ll override the override.

	@remarks __SEEME__ Note that some of these _also_ require language support.
	We try to note such cases when they arise.

	@remarks __SEEME__ It is possible for a feature to be “available” on the
	basis of the presence of its header, SD-6 macro value, etc, but still have
	its token overridden depending on the build environment. An example of this
	is support for `std::filesystem` under macOS (and other Apple OSes): while
	it is part of the C++17 Standard, and Xcode 11.0+ ships with the
	`<filesystem>` header, the feature only works under macOS 10.15+, and as
	such will only be made available if the build is targeting a minimum of
	macOS 10.15. This is specifically _not_ a runtime check, but rather happens
	at compile-time.

	@remarks __APIME__ There is some ambiguity regarding when we track the
	experimental version of a feature. Generally, we don’t bother if:
	- no major compiler ever shipped an experimental version
	- no major compiler ever shipped an experimental version in a non-preview
	release
	- the experimental version is/was completely broken

	@remarks __SEEME__ Some implementations may choose to make a feature
	available to an earlier C++ release than the the first officially supported
	one. This can be done, for example, to make features available from a Draft
	Standard. Generally, we don’t second-guess the implementation if they set
	an SD-6 macro a particular—unless we have good reason to know it was set
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
	@details Equivalent SD-6 macro: `__cpp_lib_chrono_udls`
	- [201304L](https://wg21.link/N3642)

	@sa `<chrono>`
*/
#ifndef LBAL_LIBCPP14_CHRONO_UDLS
	#define LBAL_LIBCPP14_CHRONO_UDLS 0
#endif

/**
	@def LBAL_LIBCPP14_COMPLEX_UDLS
	@brief User-defined Literals for `<complex>`
	@details Equivalent SD-6 macro: `__cpp_lib_complex_udls`
	- [201309L](https://wg21.link/N3779) __PDF__

	@sa `<complex>`
*/
#ifndef LBAL_LIBCPP14_COMPLEX_UDLS
	#define LBAL_LIBCPP14_COMPLEX_UDLS 0
#endif

/**
	@def LBAL_LIBCPP14_EXCHANGE_FUNCTION
	@brief Add `std::exchange` utility function
	@details Equivalent SD-6 macro: `__cpp_lib_exchange_function`
	- [201304L](https://wg21.link/N3668)

	@sa `<utility>`
*/
#ifndef LBAL_LIBCPP14_EXCHANGE_FUNCTION
	#define LBAL_LIBCPP14_EXCHANGE_FUNCTION 0
#endif

/**
	@def LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP
	@brief Add heterogeneous comparison lookup to associative containers
	@details Equivalent SD-6 macro: `__cpp_lib_generic_associative_lookup`
	- [201304L](https://wg21.link/N3657)

	@sa `<map>` `<set>`
*/
#ifndef LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP
	#define LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP 0
#endif

/**
	@def LBAL_LIBCPP14_INTEGER_SEQUENCE
	@brief Add template-based integer sequences
	@details Equivalent SD-6 macro: `__cpp_lib_integer_sequence`
	- [201304L](https://wg21.link/N3658)

	@sa `<utility>`
*/
#ifndef LBAL_LIBCPP14_INTEGER_SEQUENCE
	#define LBAL_LIBCPP14_INTEGER_SEQUENCE 0
#endif

/**
	@def LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE
	@brief Add `constexpr` operator-() to `std::integral_constant`
	@details Equivalent SD-6 macro: `__cpp_lib_integral_constant_callable`
	- [201304L](https://wg21.link/N3545) __PDF__

	@sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE
	#define LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE 0
#endif

/**
	@def LBAL_LIBCPP14_IS_FINAL
	@brief Detect finalized classes
	@details Equivalent SD-6 macro: `__cpp_lib_is_final`
	- [201402L](https://wg21.link/LWG2112)

	@sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP14_IS_FINAL
	#define LBAL_LIBCPP14_IS_FINAL 0
#endif

/**
	@def LBAL_LIBCPP14_IS_NULL_POINTER
	@brief Detect null pointers
	@details Equivalent SD-6 macro: `__cpp_lib_is_null_pointer`
	- [201309L](https://wg21.link/LWG2247)

	@sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP14_IS_NULL_POINTER
	#define LBAL_LIBCPP14_IS_NULL_POINTER 0
#endif

/**
	@def LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR
	@brief `std::make_reverse_iterator`
	@details Equivalent SD-6 macro: `__cpp_lib_make_reverse_iterator`
	- [201402L](https://wg21.link/LWG2285)

	@sa `<iterator>`
*/
#ifndef LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR
	#define LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR 0
#endif

/**
	@def LBAL_LIBCPP14_MAKE_UNIQUE
	@brief `std::make_unique`
	@details Equivalent SD-6 macro: `__cpp_lib_make_unique`
	- [201304L](https://wg21.link/N3656)

	@sa `<memory>`
*/
#ifndef LBAL_LIBCPP14_MAKE_UNIQUE
	#define LBAL_LIBCPP14_MAKE_UNIQUE 0
#endif

/**
	@def LBAL_LIBCPP14_NULL_ITERATORS
	@brief Allow value-initialized forward iterators to be compared
	@details Equivalent SD-6 macro: `__cpp_lib_null_iterators`
	- [201304L](https://wg21.link/N3644) __PDF__

	@sa `<iterator>`
*/
#ifndef LBAL_LIBCPP14_NULL_ITERATORS
	#define LBAL_LIBCPP14_NULL_ITERATORS 0
#endif

/**
	@def LBAL_LIBCPP14_QUOTED_STRING_IO
	@brief Add quoted-string sream i/o manipulator
	@details Equivalent SD-6 macro: `__cpp_lib_quoted_string_io`
	- [201304L](https://wg21.link/N3654)

	@sa `<iomanip>`
*/
#ifndef LBAL_LIBCPP14_QUOTED_STRING_IO
	#define LBAL_LIBCPP14_QUOTED_STRING_IO 0
#endif

/**
	@def LBAL_LIBCPP14_RESULT_OF_SFINAE
	@brief Make `std::result_of` SFINAE-friendly
	@details Equivalent SD-6 macro: `__cpp_lib_result_of_sfinae`
	- [201210L](https://wg21.link/N3462)

	@sa `<functional>` `<type_traits>`
*/
#ifndef LBAL_LIBCPP14_RESULT_OF_SFINAE
	#define LBAL_LIBCPP14_RESULT_OF_SFINAE 0
#endif

/**
	@def LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS
	@brief Make non-modifying sequence operations more robust
	@details Equivalent SD-6 macro: `__cpp_lib_robust_nonmodifying_seq_ops`
	- [201304L](https://wg21.link/N3671)

	@sa `<algorithm>`
*/
#ifndef LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS
	#define LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS 0
#endif

/**
	@def LBAL_LIBCPP14_SHARED_TIMED_MUTEX
	@brief Rename `std::shared_mutex` to `std::shared_timed_mutex`
	@details Equivalent SD-6 macro: `__cpp_lib_shared_timed_mutex`
	- [201402L](https://wg21.link/N3891)

	@sa `<shared_mutex>`
*/
#ifndef LBAL_LIBCPP14_SHARED_TIMED_MUTEX
	#define LBAL_LIBCPP14_SHARED_TIMED_MUTEX 0
#endif

/**
	@def LBAL_LIBCPP14_STRING_UDLS
	@brief Predefine UDLs for strings
	@details Equivalent SD-6 macro: `__cpp_lib_string_udls`
	- [201304L](https://wg21.link/N3642) __PDF__

	@sa `<string>`
*/
#ifndef LBAL_LIBCPP14_STRING_UDLS
	#define LBAL_LIBCPP14_STRING_UDLS 0
#endif

/**
	@def LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES
	@brief Provide type aliases for transformation traits
	@details Equivalent SD-6 macro: `__cpp_lib_transformation_trait_aliases`
	- [201304L](https://wg21.link/N3655) __PDF__

	@sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES
	#define LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES 0
#endif

/**
	@def LBAL_LIBCPP14_TRANSPARENT_OPERATORS
	@brief Allow heterogeneous arguments to operator functors and template
	their function call operators
	@details Equivalent SD-6 macro: `__cpp_lib_transparent_operators`
	- [201210L](https://wg21.link/N3421)

	@sa `<functional>` `<memory>`
*/
#ifndef LBAL_LIBCPP14_TRANSPARENT_OPERATORS
	#define LBAL_LIBCPP14_TRANSPARENT_OPERATORS 0
#endif

/**
	@def LBAL_LIBCPP14_TUPLE_ELEMENT_T
	@brief Add `std::tuple element t` type alias
	@details Equivalent SD-6 macro: `__cpp_lib_tuple_element_t`
	- [201402L](https://wg21.link/N3887) __PDF__

	@sa `<tuple>`
*/
#ifndef LBAL_LIBCPP14_TUPLE_ELEMENT_T
	#define LBAL_LIBCPP14_TUPLE_ELEMENT_T 0
#endif

/**
	@def LBAL_LIBCPP14_TUPLES_BY_TYPE
	@brief Allow addressing `std::tuple`s by type
	@details Equivalent SD-6 macro: `__cpp_lib_tuples_by_type`
	- [201304L](https://wg21.link/N3670) __PDF__

	@sa `<tuple>` `<utility>`
*/
#ifndef LBAL_LIBCPP14_TUPLES_BY_TYPE
	#define LBAL_LIBCPP14_TUPLES_BY_TYPE 0
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
	@details Equivalent SD-6 macro: `__cpp_lib_addressof_constexpr`
	- [201603L](https://wg21.link/LWG2296)

	@sa `<memory>`
*/
#ifndef LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR
	#define LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR 0
#endif

/**
	@def LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL
	@brief Clean up `noexcept` usage (Rev 3)
	@details Equivalent SD-6 macro: `__cpp_lib_allocator_traits_is_always_equal`
	- [201411L](https://wg21.link/N4258) __PDF__

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
	@details Equivalent SD-6 macro: `__cpp_lib_any`. This token corresponds to
	the `201603L` variant; it will only be set to a non-`0` value if that
	variant is available.
	- [201603L](https://wg21.link/P0220R1)
	- [201606L](https://wg21.link/P0032R3)

	@remarks __APIME__ We do not track experimental versions of this.

	@sa `<any>`
*/
#ifndef LBAL_LIBCPP17_ANY
	#define LBAL_LIBCPP17_ANY 0
#endif

/**
	@def LBAL_LIBCPP17_ANY_INTERFACE
	@brief Impose homogeneous interface for `std::variant`, `std::any` and
	`std::optional` (Rev 3)
	@details Equivalent SD-6 macro: `__cpp_lib_any`. This token corresponds to
	the `201606L` variant; it will only be set to a non-`0` value if that
	variant is available.
	- [201603L](https://wg21.link/P0220R1)
	- [201606L](https://wg21.link/P0032R3)

	@remarks __APIME__ We do not track experimental versions of this.

	@sa `<any>`
*/
#ifndef LBAL_LIBCPP17_ANY_INTERFACE
	#define LBAL_LIBCPP17_ANY_INTERFACE 0
#endif

/**
	@def LBAL_LIBCPP17_APPLY
	@brief `std::apply` component from Library Fundamentals V1 TS
	@details Equivalent SD-6 macro: `__cpp_lib_apply`
	- [201603L](https://wg21.link/P0220R1)

	@sa `<tuple>`
*/
#ifndef LBAL_LIBCPP17_APPLY
	#define LBAL_LIBCPP17_APPLY 0
#endif

/**
	@def LBAL_LIBCPP17_ARRAY_CONSTEXPR

	@brief Add `constexpr` modifiers to `std::reverse_iterator`,
	`std::move_iterator`, `<array>` and Range Access types

	@details Equivalent SD-6 macro: `__cpp_lib_array_constexpr`. This token
	corresponds to the `201603L` variant; it will only be set to a non-`0`
	value if that variant is available.
	- [201603L](https://wg21.link/P0031R0)
	- [201803L](https://wg21.link/P0858R0)
	- [201803L](https://wg21.link/LWG3257)
	- [201806L](https://wg21.link/P1023R0)
	- [201811L](https://wg21.link/P1032R1)

	@sa `<array>` `<iterator>`
*/
#ifndef LBAL_LIBCPP17_ARRAY_CONSTEXPR
	#define LBAL_LIBCPP17_ARRAY_CONSTEXPR 0
#endif

/**
	@def LBAL_LIBCPP17_AS_CONST
	@brief Add `std::as_const` helper function template
	@details Equivalent SD-6 macro: `__cpp_lib_as_const`
	- [201510L](https://wg21.link/P0007R1)

	@sa `<utility>`
*/
#ifndef LBAL_LIBCPP17_AS_CONST
	#define LBAL_LIBCPP17_AS_CONST 0
#endif

/**
	@def LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE
	@brief Add `constexpr` `atomic<T>::is_always_lock_free`
	@details Equivalent SD-6 macro: `__cpp_lib_atomic_is_always_lock_free`
	- [201603L](https://wg21.link/P0152R1)

	@sa `<atomic>`
*/
#ifndef LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE
	#define LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE 0
#endif

/**
	@def LBAL_LIBCPP17_BOOL_CONSTANT
	@brief Introduce `std::bool_constant`
	@details Equivalent SD-6 macro: `__cpp_lib_bool_constant`
	- [201505L](https://wg21.link/N4389)

	@sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_BOOL_CONSTANT
	#define LBAL_LIBCPP17_BOOL_CONSTANT 0
#endif

/**
	@def LBAL_LIBCPP17_BOYER_MOORE_SEARCHER
	@brief Add text search components from Library Fundamentals V1 TS
	@details Equivalent SD-6 macro: `__cpp_lib_boyer_moore_searcher`
	- [201603L](https://wg21.link/P0220R1)

	@sa `<functional>`
*/
#ifndef LBAL_LIBCPP17_BOYER_MOORE_SEARCHER
	#define LBAL_LIBCPP17_BOYER_MOORE_SEARCHER 0
#endif

/**
	@def LBAL_LIBCPP17_BYTE
	@brief Define `std::byte` type
	@details Equivalent SD-6 macro: `__cpp_lib_byte`
	- [201603L](https://wg21.link/P0298R3)

	@sa `<cstddef>`
*/
#ifndef LBAL_LIBCPP17_BYTE
	#define LBAL_LIBCPP17_BYTE 0
#endif

/**
	@def LBAL_LIBCPP17_CHRONO
	@brief Rounding and `abs` fixes for `<chrono>`
	@details Equivalent SD-6 macro: `__cpp_lib_chrono`. This token corresponds
	to the `201510L` variant; it will only be set to a non-`0` value if that
	variant is available.
	- [201510L](https://wg21.link/P0092R1)
	- [201611L](https://wg21.link/P0505R0)
	- [201803L](https://wg21.link/P0355R7)
	- [201907L](https://wg21.link/P1466R3)

	@sa `<chrono>`
*/
#ifndef LBAL_LIBCPP17_CHRONO
	#define LBAL_LIBCPP17_CHRONO 0
#endif

/**
	@def LBAL_LIBCPP17_CHRONO_CONSTEXPR
	@brief Add `constexpr` to certain `<chrono>` functions
	@details Equivalent SD-6 macro: `__cpp_lib_chrono`. This token corresponds
	to the `201611L` variant; it will only be set to a non-`0` value if that
	variant is available.
	- [201510L](https://wg21.link/P0092R1)
	- [201611L](https://wg21.link/P0505R0)
	- [201803L](https://wg21.link/P0355R7)
	- [201907L](https://wg21.link/P1466R3)

	@sa `<chrono>`
*/
#ifndef LBAL_LIBCPP17_CHRONO_CONSTEXPR
	#define LBAL_LIBCPP17_CHRONO_CONSTEXPR 0
#endif

/**
	@def LBAL_LIBCPP17_CLAMP
	@brief Standard clamping algorithm
	@details Equivalent SD-6 macro: `__cpp_lib_clamp`
	- [201603L](https://wg21.link/P0025R0)

	@sa `<algorithm>`
*/
#ifndef LBAL_LIBCPP17_CLAMP
	#define LBAL_LIBCPP17_CLAMP 0
#endif

/**
	@def LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS
	@brief Re-enable `std::shared_from_this`
	@details Equivalent SD-6 macro: `__cpp_lib_enable_shared_from_this`
	- [201603L](https://wg21.link/P0033R1)

	@remarks __SEEME__ Prior to the December 2019 release, the official
	SD-6 doc contains an error wherein this token is mistakenly tied to
	[P0074R0](https://wg21.link/P0074R0), a different proposal dealing with
	`std::owner_less`. We reflect the correct proposal here, but the date
	associated with this token may be incorrect.

	@sa `<memory>`
*/
#ifndef LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS
	#define LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS 0
#endif

/**
	@def LBAL_LIBCPP17_EXECUTION
	@brief Add Library components of the Parallelism TS
	@details Equivalent SD-6 macro: `__cpp_lib_execution`
	- [201603L](https://wg21.link/P0024R2)
	- [201902L](https://wg21.link/P1001R2)

	This token corresponds to the `201603L` variant; it will only be set to a
	non-`0` value if that variant is available.

	By itself, this token does not measure compliance with the referenced
	Working Group paper; use LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS.

	@remarks __APIME__ We do not track experimental versions of this.

	@sa `<execution>`
*/
#ifndef LBAL_LIBCPP17_EXECUTION
	#define LBAL_LIBCPP17_EXECUTION 0
#endif

/**
	@def LBAL_LIBCPP17_FILESYSTEM

	@brief Adopt File System TS

	@details Equivalent SD-6 macro: `__cpp_lib_filesystem`. This token
	corresponds to the `201603L` variant; it will only be set to a non-`0`
	value if that variant is available.
	- [201603L](https://wg21.link/P0218R1)
	- [201606L](https://wg21.link/P0219R1)
	- [201606L](https://wg21.link/P0392R0)
	- [201703L](https://wg21.link/P0317R1)

	@remarks __SEEME__ Full implementation missing on Apple platforms prior to
	macOS 10.15.

	@sa `<filesystem>`
*/
#ifndef LBAL_LIBCPP17_FILESYSTEM
	#define LBAL_LIBCPP17_FILESYSTEM 0
#endif

/**
	@def LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED

	@brief Add relative path and `std::string_view` support to `<filesystem>`

	@details Equivalent SD-6 macro: `__cpp_lib_filesystem`. This token
	corresponds to the `201606L` variants (both P0219R1 and P0392R0 were
	adopted at the same time). It will only be set to a non-`0` value if these
	variants are available.
	- [201603L](https://wg21.link/P0218R1)
	- [201606L](https://wg21.link/P0219R1)
	- [201606L](https://wg21.link/P0392R0)
	- [201703L](https://wg21.link/P0317R1)

	@remarks __SEEME__ Full implementation missing on Apple platforms prior to
	macOS 10.15.

	@sa `<filesystem>`
*/
#ifndef LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED
	#define LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED 0
#endif

/**
	@def LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING

	@brief Add directory entry caching to `<filesystem>`

	@details Equivalent SD-6 macro: `__cpp_lib_filesystem`. This token
	corresponds to the `201703L` variant; it will only be set to a non-`0`
	value if that variant is available.
	- [201603L](https://wg21.link/P0218R1)
	- [201606L](https://wg21.link/P0219R1)
	- [201606L](https://wg21.link/P0392R0)
	- [201703L](https://wg21.link/P0317R1)

	@remarks __SEEME__ Full implementation missing on Apple platforms prior to
	macOS 10.15.

	@sa `<filesystem>`
*/
#ifndef LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING
	#define LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING 0
#endif

/**
	@def LBAL_LIBCPP17_FILESYSTEM_EXP
	@brief Experimental implementation of the Filesystem TS
	@details Equivalent SD-6 macro: `__cpp_lib_experimental_filesystem`
	- [201603L](https://wg21.link/P0218R1)

	@remarks __SEEME__ The experimental version differs in many ways from the
	final version, but it’s all that is offered until gcc 8 and clang 7.
*/
#ifndef LBAL_LIBCPP17_FILESYSTEM_EXP
	#define LBAL_LIBCPP17_FILESYSTEM_EXP 0
#endif

/**
	@def LBAL_LIBCPP17_GCD_LCM
	@brief Add `std::gcd` and `std::lcm`
	@details Equivalent SD-6 macro: `__cpp_lib_gcd_lcm`
	- [201606L](https://wg21.link/P0295R0)

	@sa `<numeric>`
*/
#ifndef LBAL_LIBCPP17_GCD_LCM
	#define LBAL_LIBCPP17_GCD_LCM 0
#endif

/**
	@def LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE
	@brief Provide relevant cache line sizes for construction and destruction.
	@details Equivalent SD-6 macro: `__cpp_lib_hardware_interference_size`
	- [201703L](https://wg21.link/P0154R1)

	@sa `<new>`
*/
#ifndef LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE
	#define LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE 0
#endif

/**
	@def LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS
	@brief Add `std::has_unique_object_representations`
	@details Equivalent SD-6 macro: `__cpp_lib_has_unique_object_representations`
	- [201606L](https://wg21.link/P0258R2)

	This obliquely-named trait indicates whether a given type can be trivially
	hashed (e.g., it has no padding bits that would require special handling).

	@sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS
	#define LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS 0
#endif

/**
	@def LBAL_LIBCPP17_HYPOT
	@brief Introduce a 3-argument overload to `std::hypot`
	@details Equivalent SD-6 macro: `__cpp_lib_hypot`
	- [201603L](https://wg21.link/P0030R1)

	This standardizes finding 3-dimensional distance as well as 2-dimensional
	distance.

	@sa `<cmath>`
*/
#ifndef LBAL_LIBCPP17_HYPOT
	#define LBAL_LIBCPP17_HYPOT 0
#endif

/**
	@def LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS
	@brief Introduce minimal incomplete type support for Standard containers
	@details Equivalent SD-6 macro: `__cpp_lib_incomplete_container_elements`
	- [201505L](https://wg21.link/N4510)

	This standardizes finding 3-dimensional distance as well as 2-dimensional
	distance.

	@sa `<forward_list>` `<list>` `<vector>`
*/
#ifndef LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS
	#define LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS 0
#endif

/**
	@def LBAL_LIBCPP17_INVOKE
	@brief Add `std::invoke` function template
	@details Equivalent SD-6 macro: `__cpp_lib_invoke`
	- [201411L](https://wg21.link/N4169)

	@sa `<functional>`
*/
#ifndef LBAL_LIBCPP17_INVOKE
	#define LBAL_LIBCPP17_INVOKE 0
#endif

/**
	@def LBAL_LIBCPP17_IS_AGGREGATE
	@brief Add `std::is_aggregate` type trait
	@details Equivalent SD-6 macro: `__cpp_lib_is_aggregate`
	- [201703L](https://wg21.link/LWG2911)

	@sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_IS_AGGREGATE
	#define LBAL_LIBCPP17_IS_AGGREGATE 0
#endif

/**
	@def LBAL_LIBCPP17_IS_INVOCABLE
	@brief Add `std::is_invocable` type trait to replace `is_callable`
	@details Equivalent SD-6 macro: `__cpp_lib_is_invocable`
	- [201703L](https://wg21.link/P0604R0)

	@sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_IS_INVOCABLE
	#define LBAL_LIBCPP17_IS_INVOCABLE 0
#endif

/**
	@def LBAL_LIBCPP17_IS_SWAPPABLE
	@brief Add `std::is_swappable` type trait family
	@details Equivalent SD-6 macro: `__cpp_lib_is_swappable`
	- [201603L](https://wg21.link/P0185R1)

	@sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_IS_SWAPPABLE
	#define LBAL_LIBCPP17_IS_SWAPPABLE 0
#endif

/**
	@def LBAL_LIBCPP17_LAUNDER
	@brief Replacement of class objects containing reference members
	@details Equivalent SD-6 macro: `__cpp_lib_launder`
	- [201606L](https://wg21.link/p0137r1)

	@sa `<new>`
*/
#ifndef LBAL_LIBCPP17_LAUNDER
	#define LBAL_LIBCPP17_LAUNDER 0
#endif

/**
	@def LBAL_LIBCPP17_LOGICAL_TRAITS
	@brief Provide type traits for performing logical operations
	@details Equivalent SD-6 macro: `__cpp_lib_logical_traits`
	- [201510L](https://wg21.link/P0013R1)

	@sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_LOGICAL_TRAITS
	#define LBAL_LIBCPP17_LOGICAL_TRAITS 0
#endif

/**
	@def LBAL_LIBCPP17_MAKE_FROM_TUPLE
	@brief Introduce `std::make_from_tuple` to unpack a tuple into arguments
	@details Equivalent SD-6 macro: `__cpp_lib_make_from_tuple`
	- [201606L](https://wg21.link/P0209R2) __PDF__

	@sa `<tuple>`
*/
#ifndef LBAL_LIBCPP17_MAKE_FROM_TUPLE
	#define LBAL_LIBCPP17_MAKE_FROM_TUPLE 0
#endif

/**
	@def LBAL_LIBCPP17_MAP_TRY_EMPLACE
	@brief Improve insertion into `std::map`
	@details Equivalent SD-6 macro: `__cpp_lib_map_try_emplace`
	- [201411L](https://wg21.link/N4279)

	@sa `<map>`
*/
#ifndef LBAL_LIBCPP17_MAP_TRY_EMPLACE
	#define LBAL_LIBCPP17_MAP_TRY_EMPLACE 0
#endif

/**
	@def LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS
	@brief Incorporate math functions specified in IS 29124:2010
	@details Equivalent SD-6 macro: `__cpp_lib_math_special_functions`
	- [201603L](https://wg21.link/P0226R1) __PDF__

	@sa `<cmath>`
*/
#ifndef LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS
	#define LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS 0
#endif

/**
	@def LBAL_LIBCPP17_MEMORY_RESOURCE

	@brief Incorporate memory management components from
	Library Fundamentals V1 TS

	@details Equivalent SD-6 macro: `__cpp_lib_memory_resource`
	- [201603L](https://wg21.link/P0220R1)

	@sa `<memory_resource>`
*/
#ifndef LBAL_LIBCPP17_MEMORY_RESOURCE
	#define LBAL_LIBCPP17_MEMORY_RESOURCE 0
#endif

/**
	@def LBAL_LIBCPP17_NODE_EXTRACT
	@brief Add splicing to associative containers
	@details Equivalent SD-6 macro: `__cpp_lib_node_extract`
	- [201606L](https://wg21.link/P0083R3) __PDF__

	@sa `<map>` `<set>` `<unordered_map>` `<unordered_set>`
*/
#ifndef LBAL_LIBCPP17_NODE_EXTRACT
	#define LBAL_LIBCPP17_NODE_EXTRACT 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed. The old name is deprecated and
	//	will be removed in a future release.
	#ifndef LBAL_LIBCPP17_NODE_EXTRACT
		#define LBAL_LIBCPP17_NODE_EXTRACT LBAL_LIBCPP17_NODE_EXTRACT
	#endif
///@endcond

/**
	@def LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS

	@brief Incorporate non-member functions into Standard container class
	interfaces

	@details Equivalent SD-6 macro: `__cpp_lib_nonmember_container_access`
	- [201411L](https://wg21.link/N4280)

	@sa `<array>` `<deque>` `<forward_list>` `<iterator>` `<list>` `<map>`
	`<regex>` `<set>` `<string>` `<unordered_map>` `<unordered_set>` `<vector>`
*/
#ifndef LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS
	#define LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS 0
#endif

/**
	@def LBAL_LIBCPP17_NOT_FN
	@brief Add `std::not_fn`
	@details Equivalent SD-6 macro: `__cpp_lib_not_fn`
	- [201603L](https://wg21.link/P0005R4) __PDF__

	@sa `<functional>`
*/
#ifndef LBAL_LIBCPP17_NOT_FN
	#define LBAL_LIBCPP17_NOT_FN 0
#endif

/**
	@def LBAL_LIBCPP17_OPTIONAL

	@brief Add `std::optional`

	@details Equivalent SD-6 macro: `__cpp_lib_optional`. This token
	corresponds to the `201603L` variant; it will only be set to a non-`0`
	value if that variant is available.
	- [201603L](https://wg21.link/P0220R1)
	- [201606L](https://wg21.link/P0032R3) __PDF__
	- [201606L](https://wg21.link/P0307R2) __PDF__

	@sa `<optional>`
*/
#ifndef LBAL_LIBCPP17_OPTIONAL
	#define LBAL_LIBCPP17_OPTIONAL 0
#endif

/**
	@def LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL

	@brief Homogenize `std::optional` interface with `std::any` and
	`std::variant`

	@details Equivalent SD-6 macro: `__cpp_lib_optional`. This token
	corresponds to the `201606L` [P0307R2](https://wg21.link/P0307R2) variant
	([P0032R3](https://wg21.link/P0032R3) was approved at the same time). It
	will only be set to a non-`0` value if that variant is available.
	- [201603L](https://wg21.link/P0220R1)
	- [201606L](https://wg21.link/P0032R3) __PDF__
	- [201606L](https://wg21.link/P0307R2) __PDF__

	@sa `<optional>`
*/
#ifndef LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL
	#define LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL 0
#endif

/**
	@def LBAL_LIBCPP17_OPTIONAL_INTERFACE

	@brief Homogenize `std::optional` interface with `std::any` and
	`std::variant`

	@details Equivalent SD-6 macro: `__cpp_lib_optional`. This token
	corresponds to the `201606L` `P0032R3` variant (`P0307R2` was approved at
	the same time). It will only be set to a non-`0` value if that variant is
	available.
	- [201603L](https://wg21.link/P0220R1)
	- [201606L](https://wg21.link/P0032R3) __PDF__
	- [201606L](https://wg21.link/P0307R2) __PDF__

	@sa `<optional>`
*/
#ifndef LBAL_LIBCPP17_OPTIONAL_INTERFACE
	#define LBAL_LIBCPP17_OPTIONAL_INTERFACE 0
#endif

/**
	@def LBAL_LIBCPP17_PARALLEL_ALGORITHM

	@brief Standardize the Parallelism TS

	@details Equivalent SD-6 macro: `__cpp_lib_parallel_algorithm`
	- [201603L](https://wg21.link/p0024r2) __PDF__

	@remarks By itself, this macro does not measure compliance with the
	Working Group paper; for that, use
	LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS.

	@remarks __APIME__ We do not track experimental versions of this.

	@sa `<algorithm>` `<numeric>`
*/
#ifndef LBAL_LIBCPP17_PARALLEL_ALGORITHM
	#define LBAL_LIBCPP17_PARALLEL_ALGORITHM 0
#endif

/**
	@def LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS
	@brief Supply tools for raw memory management
	@details Equivalent SD-6 macro: `__cpp_lib_raw_memory_algorithms`
	- [201606L](https://wg21.link/P0040R3)

	@sa `<memory>`
*/
#ifndef LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS
	#define LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS 0
#endif

/**
	@def LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS

	@brief Track full compliance with the Parallelism Standard

 	@details This token tracks compliance with the Standard as it relates to
 	implementing the referenced Working Group paper; there is no correspoding
 	SD-6 macro, or rather, there are _two_ relevant macros which each track the
 	different features required for compliance. We actually track both of
 	those, as well as this meta-feature, separately. As such, this token
 	represents an aggregate condition: if both `LBAL_LIBCPP17_EXECUTION` and
 	`LBAL_LIBCPP17_PARALLEL_ALGORITHM` indicate compliance, this gets set to
 	`1`; otherwise, it’s set to `0`.
	- [Parallelism TS](https://wg21.link/P0024R2)

	@remarks __APIME__ We do not track experimental versions of this, partly
	because the Draft versions tracked a different set of features, in
	different places, which were refactored/replaced.

	@remarks __SEEME__ We do not check compliance with iterations on the
	constituent components (e.g., `LBAL_LIBCPP20_EXECUTION_VECTORIZATION`),
	only that we have met the base requirements for supporting Parallelism.
	Extending tracking is one option; another is to eliminate this meta-token
	to avoid over-complicating things.
*/
#ifndef LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS
	#define LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS 0
#endif

/**
	@def LBAL_LIBCPP17_SAMPLE
	@brief Adopt `std::sample` from the Library Fundamentals V1 TS
	@details Equivalent SD-6 macro: `__cpp_lib_sample`
	- [201603L](https://wg21.link/P0220R1)

	@sa `<algorithm>`
*/
#ifndef LBAL_LIBCPP17_SAMPLE
	#define LBAL_LIBCPP17_SAMPLE 0
#endif

/**
	@def LBAL_LIBCPP17_SCOPED_LOCK
	@brief Add a variadic variant of `std::lock_guard` under a new name
	@details Equivalent SD-6 macro: `__cpp_lib_scoped_lock`.
	- [201703L](https://wg21.link/P0156R2)

	@remarks It was determined that simply making `std::lock_guard` variadic
	would break ABI, hence the name change.

	@sa `<mutex>`
*/
#ifndef LBAL_LIBCPP17_SCOPED_LOCK
	#define LBAL_LIBCPP17_SCOPED_LOCK 0
#endif

/**
	@def LBAL_LIBCPP17_SHARED_MUTEX
	@brief Officially change `std::shared_mutex` to an untimed mutex
	@details Equivalent SD-6 macro: `__cpp_lib_shared_mutex`. This change was
	corresponds to the addition of an explicit `std::shared_timed_mutex`.
	- [201505L](https://wg21.link/N4508)

	@sa `<shared_mutex>`
*/
#ifndef LBAL_LIBCPP17_SHARED_MUTEX
	#define LBAL_LIBCPP17_SHARED_MUTEX 0
#endif

/**
	@def LBAL_LIBCPP17_SHARED_PTR_ARRAYS
	@brief Fix `std::shared_ptr` support for arrays
	@details Equivalent SD-6 macro: `__cpp_lib_shared_ptr_arrays`
	- [201611L](https://wg21.link/P0497R0)

	@sa `<memory>`
*/
#ifndef LBAL_LIBCPP17_SHARED_PTR_ARRAYS
	#define LBAL_LIBCPP17_SHARED_PTR_ARRAYS 0
#endif

/**
	@def LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE
	@brief Add `shared_ptr::weak_type`
	@details Equivalent SD-6 macro: `__cpp_lib_shared_ptr_weak_type`
	- [201606L](https://wg21.link/P0163R0)

	@sa `<memory>`
*/
#ifndef LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE
	#define LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE 0
#endif

/**
	@def LBAL_LIBCPP17_STRING_VIEW

	@brief Adopt `std::string_view` from the Library Fundamentals V1 TS

	@details Equivalent SD-6 macro: `__cpp_lib_string_view`. This token
	corresponds to the `201603L` variant; it will only be set to a non-`0`
	value if that variant is available.
	- [201603L](https://wg21.link/P0220R1)
	- [201606L](https://wg21.link/P0254R2) __PDF__
	- [201803L](https://wg21.link/P0858R0)
	- [201803L](https://wg21.link/LWG3257)

	@sa `<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP17_STRING_VIEW
	#define LBAL_LIBCPP17_STRING_VIEW 0
#endif

/**
	@def LBAL_LIBCPP17_STRING_VIEW_INTERFACE

	@brief Address interface inversion between `<string>` and `<string_view>`

	@details Equivalent SD-6 macro: `__cpp_lib_string_view`. This token
	corresponds to the `201606L` variant; it will only be set to a non-`0`
	value if that variant is available.
	- [201603L](https://wg21.link/P0220R1)
	- [201606L](https://wg21.link/P0254R2) __PDF__
	- [201803L](https://wg21.link/P0858R0)
	- [201803L](https://wg21.link/LWG3257)

	@sa `<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP17_STRING_VIEW_INTERFACE
	#define LBAL_LIBCPP17_STRING_VIEW_INTERFACE 0
#endif

/**
	@def LBAL_LIBCPP17_TO_CHARS
	@brief Elementary string conversions, revision 5
	@details Equivalent SD-6 macro: `__cpp_lib_to_chars`
	- [201611L](https://wg21.link/P0067R5)
	- [201611L](https://wg21.link/P0682R1)
	- [201611L](https://wg21.link/LWG3137)

	This token tracks compliance with both the integer and floating-point
	variants of `to_chars` and `from_chars`.

	@remarks __SEEME__ This got weird since the functions were moved to their
	own header and their signatures were altered, post-Standardization, all as
	part of a Defect Report resolution.

	@remarks __SEEME__ This got weirder since multiple major implementations
	falsely set their SD-6 macros as if they are in full compliance, when they
	actually only support integer conversions. This is reflected by the
	creation of two tokens that feed into this one, despite there only being
	one underlying SD-6 macro.

	@sa `<charconv>` `LBAL_LIBCPP17_TO_CHARS_FP`
	`LBAL_LIBCPP17_TO_CHARS_INTEGER`
*/
#ifndef LBAL_LIBCPP17_TO_CHARS
	#define LBAL_LIBCPP17_TO_CHARS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed. The old name is deprecated and
	//	will be removed in a future release.
	#ifndef LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS
		#define LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS LBAL_LIBCPP17_TO_CHARS
	#endif
///@endcond

/**
	@def LBAL_LIBCPP17_TO_CHARS_FP
	@brief Floating-point compliance with Elementary string conversions
	@details Equivalent SD-6 macro: none
	- [201611L](https://wg21.link/P0067R5)
	- [201611L](https://wg21.link/P0682R1)
	- [201611L](https://wg21.link/LWG3137)

	This tracks the floating-point conversion portion of
	`LBAL_LIBCPP17_TO_CHARS`.

	@remarks __SEEME__ This got weird since the functions were moved to their
	own header and their signatures were altered, post-Standardization, all as
	part of a Defect Report resolution.

	@remarks __SEEME__ This got weirder since multiple major implementations
	falsely set their SD-6 macros as if they are in full compliance, when they
	actually only support integer conversions. This is reflected by the
	creation of two tokens that feed into this one, despite there only being
	one underlying SD-6 macro.

	@sa `<charconv>` `LBAL_LIBCPP17_TO_CHARS`
	`LBAL_LIBCPP17_TO_CHARS_INTEGER`
*/
#ifndef LBAL_LIBCPP17_TO_CHARS_FP
	#define LBAL_LIBCPP17_TO_CHARS_FP 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed. The old name is deprecated and
	//	will be removed in a future release.
	#ifndef LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS_FP
		#define LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS_FP LBAL_LIBCPP17_TO_CHARS_FP
	#endif
///@endcond

/**
	@def LBAL_LIBCPP17_TO_CHARS_INTEGER
	@brief Integer compliance with Elementary string conversions
	@details Equivalent SD-6 macro: none
	- [201611L](https://wg21.link/P0067R5)
	- [201611L](https://wg21.link/P0682R1)
	- [201611L](https://wg21.link/LWG3137)

	This tracks the integer conversion portion of `LBAL_LIBCPP17_TO_CHARS`.

	@remarks __SEEME__ This got weird since the functions were moved to their
	own header and their signatures were altered, post-Standardization, all as
	part of a Defect Report resolution.

	@remarks __SEEME__ This got weirder since multiple major implementations
	falsely set their SD-6 macros as if they are in full compliance, when they
	actually only support integer conversions. This is reflected by the
	creation of two tokens that feed into this one, despite there only being
	one underlying SD-6 macro.

	@sa `<charconv>` `LBAL_LIBCPP17_TO_CHARS` `LBAL_LIBCPP17_TO_CHARS_FP`
*/
#ifndef LBAL_LIBCPP17_TO_CHARS_INTEGER
	#define LBAL_LIBCPP17_TO_CHARS_INTEGER 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed. The old name is deprecated and
	//	will be removed in a future release.
	#ifndef LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS_INTEGER
		#define LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS_INTEGER LBAL_LIBCPP17_TO_CHARS_INTEGER
	#endif
///@endcond

/**
	@def LBAL_LIBCPP17_TRANSPARENT_OPERATORS
	@brief Make `std::owner_less` more flexible
	@details Equivalent SD-6 macro: `__cpp_lib_transparent_operators`
	- [201510L](https://wg21.link/P0074R0)

	@remarks __SEEME__ The official SD-6 doc prior to December 2019 contains an
	error wherein this proposal and functionality are mistakenly tied to
	`__cpp_lib_enable_shared_from_this`.

	@sa `<functional>` `<memory>`
*/
#ifndef LBAL_LIBCPP17_TRANSPARENT_OPERATORS
	#define LBAL_LIBCPP17_TRANSPARENT_OPERATORS 0
#endif

/**
	@def LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES

	@brief Adopt variable templates for type traits from the
	Library Fundamentals V1 TS

	@details Equivalent SD-6 macro: `__cpp_lib_type_trait_variable_templates`
	- [201510L](https://wg21.link/P0006R0)

	@sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES
	#define LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES 0
#endif

/**
	@def LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS

	@brief Add `std::uncaught_exceptions`

	@details Equivalent SD-6 macro: `__cpp_lib_uncaught_exceptions`
	- [201411L](https://wg21.link/N4259)

	@sa `<exception>`
*/
#ifndef LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS
	#define LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS 0
#endif

/**
	@def LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE
	@brief Improve insertion into `std::unordered_map`
	@details Equivalent SD-6 macro: `__cpp_lib_unordered_map_try_emplace`
	- [201411L](https://wg21.link/N4279)

	@sa `<unordered_map>`
*/
#ifndef LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE
	#define LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE 0
#endif

/**
	@def LBAL_LIBCPP17_VARIANT

	@brief Add `std::variant`

	@details Equivalent SD-6 macro: `__cpp_lib_variant`
	- [201606L](https://wg21.link/P0088R3)
	- [201606L](https://wg21.link/P0393R3) __PDF__
	- [201606L](https://wg21.link/P0032R3) __PDF__

	@remarks We track all three proposals as one variant, as they were all
	voted in at the same time, and no implementation we’re aware of implemented
	them piecemeal.

	@sa `<variant>`
*/
#ifndef LBAL_LIBCPP17_VARIANT
	#define LBAL_LIBCPP17_VARIANT 0
#endif

/**
	@def LBAL_LIBCPP17_VOID_T
	@brief Add `std::void_t` as a transformation type trait
	@details Equivalent SD-6 macro: `__cpp_lib_void_t`
	- [201411L](https://wg21.link/N3911)

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

	@remarks The Draft Standard was referred to informally as C++2a; draft
	variants of these tokens began with a `LBAL_LIBCPP2A` prefix.

	@{
*/

/**
	@def LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR

	@brief Define requirements for `constexpr` iterators

	@details Equivalent SD-6 macro: `__cpp_lib_array_constexpr`. This token
	corresponds to the `201803L` variants; it will only be set to a non-`0`
	value if those variants are available.
	- [201603L](https://wg21.link/P0031R0)
	- [201803L](https://wg21.link/P0858R0)
	- [201803L](https://wg21.link/LWG3257)
	- [201806L](https://wg21.link/P1023R0)
	- [201811L](https://wg21.link/P1032R1)

	@remarks The issue raised in [LWG3257](https://wg21.link/LWG3257) was
	simply that the SD-6 macro update voted in with
	[201803L](https://wg21.link/P0858R0) had not been applied.

	@sa `<array>` `<iterator>`
*/
#ifndef LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR
	#define LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ These tokens have been renamed. The old names are deprecated
	//	and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_ARRAY_CONSTEXPR_ITERS
		#define LBAL_LIBCPP2A_ARRAY_CONSTEXPR_ITERS LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR
	#endif

	#ifndef LBAL_LIBCPP2A_ARRAY_CONSTEXPR_ITERATOR
		#define LBAL_LIBCPP2A_ARRAY_CONSTEXPR_ITERATOR LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS

	@brief Provide `constexpr` comparison operators for `std::array`

	@details Equivalent SD-6 macro: `__cpp_lib_array_constexpr`. This token
	corresponds to the `201806L` variant; it will only be set to a non-`0`
	value if that variant is available.
	- [201603L](https://wg21.link/P0031R0)
	- [201803L](https://wg21.link/P0858R0)
	- [201803L](https://wg21.link/LWG3257)
	- [201806L](https://wg21.link/P1023R0)
	- [201811L](https://wg21.link/P1032R1)

	@sa `<array>` `<iterator>`
*/
#ifndef LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS
	#define LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_ARRAY_CONSTEXPR_COMPARISONS
		#define LBAL_LIBCPP2A_ARRAY_CONSTEXPR_COMPARISONS LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES

	@brief Provide `constexpr` `std::array` `swap` and `fill`

	@details Equivalent SD-6 macro: `__cpp_lib_array_constexpr`. This token
	corresponds to the `201811L` variant; it will only be set to a non-`0`
	value if that variant is available.
	- [201603L](https://wg21.link/P0031R0)
	- [201803L](https://wg21.link/P0858R0)
	- [201803L](https://wg21.link/LWG3257)
	- [201806L](https://wg21.link/P1023R0)
	- [201811L](https://wg21.link/P1032R1)

	@sa `<array>` `<iterator>`
*/
#ifndef LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES
	#define LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_ARRAY_CONSTEXPR_UTILITIES
		#define LBAL_LIBCPP2A_ARRAY_CONSTEXPR_UTILITIES LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_ASSUME_ALIGNED

	@brief Provide `std::assume_aligned` compiler hint utility function
	Library

	@details Equivalent SD-6 macro: `__cpp_lib_assume_aligned`
	- [201811L](https://wg21.link/P1007R3)

	@sa `<memory>`
*/
#ifndef LBAL_LIBCPP20_ASSUME_ALIGNED
	#define LBAL_LIBCPP20_ASSUME_ALIGNED 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_ASSUME_ALIGNED
		#define LBAL_LIBCPP2A_ASSUME_ALIGNED LBAL_LIBCPP20_ASSUME_ALIGNED
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_ATOMIC_FLAG_TEST

	@brief Add `atomic_flag::test` components of the C++20 Synchronization
	Library

	@details Equivalent SD-6 macro: `__cpp_lib_atomic_flag_test`
	- [201907L](https://wg21.link/P1135R6)

	@sa `<atomic>`
*/
#ifndef LBAL_LIBCPP20_ATOMIC_FLAG_TEST
	#define LBAL_LIBCPP20_ATOMIC_FLAG_TEST 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_ATOMIC_FLAG_TEST
		#define LBAL_LIBCPP2A_ATOMIC_FLAG_TEST LBAL_LIBCPP20_ATOMIC_FLAG_TEST
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_ATOMIC_FLOAT
	@brief Extend `<atomic>` support to floating point types
	@details Equivalent SD-6 macro: `__cpp_lib_atomic_float`
	- [201711L](https://wg21.link/P0020R6)

	@sa `<atomic>`
*/
#ifndef LBAL_LIBCPP20_ATOMIC_FLOAT
	#define LBAL_LIBCPP20_ATOMIC_FLOAT 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ These tokens have been renamed. The old names are deprecated
	//	and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_FLOATING_POINT_ATOMIC
		#define LBAL_LIBCPP2A_FLOATING_POINT_ATOMIC LBAL_LIBCPP20_ATOMIC_FLOAT
	#endif

	#ifndef LBAL_LIBCPP2A_ATOMIC_FLOAT
		#define LBAL_LIBCPP2A_ATOMIC_FLOAT LBAL_LIBCPP20_ATOMIC_FLOAT
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES
	@brief Add atomic lockfree type aliases from the C++20 Synchronization
	@details Equivalent SD-6 macro: `__cpp_lib_atomic_lock_free_type_aliases`
	- [201907L](https://wg21.link/P1135R6)

	@sa `<atomic>`
*/
#ifndef LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES
	#define LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_ATOMIC_LOCK_FREE_TYPE_ALIASES
		#define LBAL_LIBCPP2A_ATOMIC_LOCK_FREE_TYPE_ALIASES LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_ATOMIC_REF
	@brief Allow atomic operations to apply to non-atomic objects
	@details Equivalent SD-6 macro: `__cpp_lib_atomic_ref`
	- [201806L](https://wg21.link/P0019R8)

	@sa `<atomic>`
*/
#ifndef LBAL_LIBCPP20_ATOMIC_REF
	#define LBAL_LIBCPP20_ATOMIC_REF 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ These tokens have been renamed. The old names are deprecated
	//	and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_STD_ATOMIC_REF
		#define LBAL_LIBCPP2A_STD_ATOMIC_REF LBAL_LIBCPP20_ATOMIC_REF
	#endif

	#ifndef LBAL_LIBCPP2A_ATOMIC_REF
		#define LBAL_LIBCPP2A_ATOMIC_REF LBAL_LIBCPP20_ATOMIC_REF
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_ATOMIC_SHARED_PTR
	@brief Fixes for atomic `std::shared_ptr` and `std::weak_ptr`
	@details Equivalent SD-6 macro: `__cpp_lib_atomic_shared_ptr`
	- [201711L](https://wg21.link/P0718R2)

	@sa `<memory>`
*/
#ifndef LBAL_LIBCPP20_ATOMIC_SHARED_PTR
	#define LBAL_LIBCPP20_ATOMIC_SHARED_PTR 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_ATOMIC_SHARED_PTR
		#define LBAL_LIBCPP2A_ATOMIC_SHARED_PTR LBAL_LIBCPP20_ATOMIC_SHARED_PTR
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION

	@brief Eliminate the surprising value-initialization behavior of
	`std::atomic`

	@details Equivalent SD-6 macro: `__cpp_lib_atomic_value_initialization`
	- [201911L](https://wg21.link/P0883R2)

	@sa `<atomic>` `<memory>`
*/
#ifndef LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION
	#define LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_ATOMIC_VALUE_INITIALIZATION
		#define LBAL_LIBCPP2A_ATOMIC_VALUE_INITIALIZATION LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_ATOMIC_WAIT
	@brief Add atomic wait components of the C++20 Synchronization Library
	@details Equivalent SD-6 macro: `__cpp_lib_atomic_wait`
	- [201907L](https://wg21.link/P1135R6)

	@sa `<atomic>`
*/
#ifndef LBAL_LIBCPP20_ATOMIC_WAIT
	#define LBAL_LIBCPP20_ATOMIC_WAIT 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_ATOMIC_WAIT
		#define LBAL_LIBCPP2A_ATOMIC_WAIT LBAL_LIBCPP20_ATOMIC_WAIT
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_BARRIER
	@brief Add `std::barrier` components of the C++20 Synchronization Library
	@details Equivalent SD-6 macro: `__cpp_lib_barrier`
	- [201907L](https://wg21.link/P1135R6)

	@sa `<barrier>`
*/
#ifndef LBAL_LIBCPP20_BARRIER
	#define LBAL_LIBCPP20_BARRIER 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_BARRIER
		#define LBAL_LIBCPP2A_BARRIER LBAL_LIBCPP20_ATOMIC_WAIT
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_BIND_FRONT
	@brief Introduce `std::bind_front` to supersede `std::bind`
	@details Equivalent SD-6 macro: `__cpp_lib_bind_front`
	- [201811L](https://wg21.link/P0356R5)
	- [201907L](https://wg21.link/P1651R0)

	This token corresponds to the `201811L` variant; it will only be set to a
	non-`0` value if that variant is available.

	@sa `<functional>`
*/
#ifndef LBAL_LIBCPP20_BIND_FRONT
	#define LBAL_LIBCPP20_BIND_FRONT 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_BIND_FRONT
		#define LBAL_LIBCPP2A_BIND_FRONT LBAL_LIBCPP20_BIND_FRONT
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP
	@brief Prevent `std::bind_front` from unwrapping `std::reference_wrapper`
	@details Equivalent SD-6 macro: `__cpp_lib_bind_front`
	- [201811L](https://wg21.link/P0356R5)
	- [201907L](https://wg21.link/P1651R0)

	This token corresponds to the `201907L` variant; it will only be set to a
	non-`0` value if that variant is available.

	@sa `<functional>`
*/
#ifndef LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP
	#define LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_BIND_FRONT_NO_UNWRAP
		#define LBAL_LIBCPP2A_BIND_FRONT_NO_UNWRAP LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_BIT_CAST
	@brief Introduce robust casts between bit-compatible types
	@details Equivalent SD-6 macro: `__cpp_lib_bit_cast`
	- [201806L](https://wg21.link/P0476R2)

	@sa `<bit>`
*/
#ifndef LBAL_LIBCPP20_BIT_CAST
	#define LBAL_LIBCPP20_BIT_CAST 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_BIT_CAST
		#define LBAL_LIBCPP2A_BIT_CAST LBAL_LIBCPP20_BIT_CAST
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_BITOPS
	@brief Introduce support for hardware-level bit operations
	@details Equivalent SD-6 macro: `__cpp_lib_bitops`
	- [201907L](https://wg21.link/P0553R4)

	@sa `<bit>`
*/
#ifndef LBAL_LIBCPP20_BITOPS
	#define LBAL_LIBCPP20_BITOPS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_BITOPS
		#define LBAL_LIBCPP2A_BITOPS LBAL_LIBCPP20_BITOPS
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS
	@brief Introduce traits to distinguish between bounded and unbounded arrays
	@details Equivalent SD-6 macro: `__cpp_lib_bounded_array_traits`
	- [201902L](https://wg21.link/P1357R1)

	@sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS
	#define LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_BOUNDED_ARRAY_TRAITS
		#define LBAL_LIBCPP2A_BOUNDED_ARRAY_TRAITS LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_CHAR8_T
	@brief Define `char8_t` as the base type for UTF-8 encodings (Rev 6)
	@details Equivalent SD-6 macro: `__cpp_lib_char8_t`
	- [201811L](https://wg21.link/P0482R6)
	- [201907L](https://wg21.link/P1423R3)

	This token corresponds to the `201811L` variant; it will only be set to a
	non-`0` value if that variant is available.

	@sa `<atomic>` `<filesystem>` `<istream>` `<limits>` `<locale>` `<ostream>`
	`<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP20_CHAR8_T
	#define LBAL_LIBCPP20_CHAR8_T 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_CHAR8_T
		#define LBAL_LIBCPP2A_CHAR8_T LBAL_LIBCPP20_CHAR8_T
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_CHAR8_T_COMPAT
	@brief Fix backward compatibility issues introduced by `char8_t`
	@details Equivalent SD-6 macro: `__cpp_lib_char8_t`
	- [201811L](https://wg21.link/P0482R6)
	- [201907L](https://wg21.link/P1423R3)

	This token corresponds to the `201907L` variant; it will only be set to a
	non-`0` value if that variant is available.

	@sa `<atomic>` `<filesystem>` `<istream>` `<limits>` `<locale>` `<ostream>`
	`<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP20_CHAR8_T_COMPAT
	#define LBAL_LIBCPP20_CHAR8_T_COMPAT 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_CHAR8_T_COMPAT
		#define LBAL_LIBCPP2A_CHAR8_T_COMPAT LBAL_LIBCPP20_CHAR8_T_COMPAT
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_CHRONO_CALENDAR
	@brief Add support for Calendars and Time Zones to `<chrono>`
	@details Equivalent SD-6 macro: `__cpp_lib_chrono`. This token corresponds
	to the `201803L` variant; it will only be set to a non-`0` value if that
	variant is available.
	- [201510L](https://wg21.link/P0092R1)
	- [201611L](https://wg21.link/P0505R0)
	- [201803L](https://wg21.link/P0355R7)
	- [201907L](https://wg21.link/P1466R3)

	@sa `<chrono>`
*/
#ifndef LBAL_LIBCPP20_CHRONO_CALENDAR
	#define LBAL_LIBCPP20_CHRONO_CALENDAR 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ These tokens have been renamed. The old names are deprecated
	//	and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_CALENDAR_AND_TIMEZONE
		#define LBAL_LIBCPP20_CALENDAR_AND_TIMEZONE \
				LBAL_LIBCPP20_CHRONO_CALENDAR
	#endif

	#ifndef LBAL_LIBCPP2A_CHRONO_CALENDAR
		#define LBAL_LIBCPP2A_CHRONO_CALENDAR \
				LBAL_LIBCPP20_CHRONO_CALENDAR
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_CHRONO_FIXES
	@brief Miscellaneous minor fixes for `<chrono>`
	@details Equivalent SD-6 macro: `__cpp_lib_chrono`. This token corresponds
	to the `201907L` variant; it will only be set to a non-`0` value if that
	variant is available.
	- [201510L](https://wg21.link/P0092R1)
	- [201611L](https://wg21.link/P0505R0)
	- [201803L](https://wg21.link/P0355R7)
	- [201907L](https://wg21.link/P1466R3)

	@sa `<chrono>`
*/
#ifndef LBAL_LIBCPP20_CHRONO_FIXES
	#define LBAL_LIBCPP20_CHRONO_FIXES 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_CHRONO_FIXES
		#define LBAL_LIBCPP2A_CHRONO_FIXES LBAL_LIBCPP20_CHRONO_FIXES
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_CONCEPTS
	@brief Standard Library Concepts
	@details Equivalent SD-6 macro: `__cpp_lib_concepts`. This token
	corresponds to the `201806L` variant; it will only be set to a non-`0`
	value if that variant is available.
	- [201806L](https://wg21.link/P0898R3) __PDF__
	- [201907L](https://wg21.link/P1754R1) __PDF__
	- [202002L](https://wg21.link/P1964R2)

	@sa `<concepts>`
*/
#ifndef LBAL_LIBCPP20_CONCEPTS
	#define LBAL_LIBCPP20_CONCEPTS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_CONCEPTS
		#define LBAL_LIBCPP2A_CONCEPTS LBAL_LIBCPP20_CONCEPTS
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_CONCEPTS_EXP
	@brief Experimental version of Standard Library Concepts
	@details Equivalent SD-6 macro: `__cpp_lib_experimental_concepts`
	- [201806L](https://wg21.link/P0898R3) __PDF__

	@sa `<experimental/concepts>`
*/
#ifndef LBAL_LIBCPP20_CONCEPTS_EXP
	#define LBAL_LIBCPP20_CONCEPTS_EXP 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ These tokens have been renamed. The old names are deprecated
	//	and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP
		#define LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP LBAL_LIBCPP20_CONCEPTS_EXP
	#endif

	#ifndef LBAL_LIBCPP2A_CONCEPTS_EXP
		#define LBAL_LIBCPP2A_CONCEPTS_EXP LBAL_LIBCPP20_CONCEPTS_EXP
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE
	@brief Rename C++ Concepts to use standard_case
	@details Equivalent SD-6 macro: `__cpp_lib_concepts`. This token
	corresponds to the `201907L` variant; it will only be set to a non-`0`
	value if that variant is available.
	- [201806L](https://wg21.link/P0898R3) __PDF__
	- [201907L](https://wg21.link/P1754R1) __PDF__
	- [202002L](https://wg21.link/P1964R2)

	@sa `<concepts>`
*/
#ifndef LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE
	#define LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_CONCEPTS_STANDARD_CASE
		#define LBAL_LIBCPP2A_CONCEPTS_STANDARD_CASE LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE
	@brief Wording for boolean-testable
	@details Equivalent SD-6 macro: `__cpp_lib_concepts`. This token
	corresponds to the `202002L` variant; it will only be set to a non-`0`
	value if that variant is available.
	- [201806L](https://wg21.link/P0898R3) __PDF__
	- [201907L](https://wg21.link/P1754R1) __PDF__
	- [202002L](https://wg21.link/P1964R2)

	@sa `<concepts>`
*/
#ifndef LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE
	#define LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_CONCEPTS_BOOLEAN_TESTABLE
		#define LBAL_LIBCPP2A_CONCEPTS_BOOLEAN_TESTABLE LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS
	@brief Add `constexpr` to `<algorithm>` and `<utility>` functions
	@details Equivalent SD-6 macro: `__cpp_lib_constexpr_algorithms`
	- [201703L](https://wg21.link/P0202R3)
	- [201806L](https://wg21.link/P0879R0)
	- [201806L](https://wg21.link/LWG3256)

	This token corresponds to the `201703L` variant; it will only be set to a
	non-`0` value if that variant is available.

	@sa `<algorithm>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS
	#define LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ These tokens have been renamed. The old names are deprecated
	//	and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_CONSTEXPR_FOR_ALGORITHM_AND_UTILITY
		#define LBAL_LIBCPP2A_CONSTEXPR_FOR_ALGORITHM_AND_UTILITY LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS
	#endif

	#ifndef LBAL_LIBCPP2A_CONSTEXPR_ALGORITHMS
		#define LBAL_LIBCPP2A_CONSTEXPR_ALGORITHMS LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP
	@brief Add `constexpr` to `std::swap` and related functions
	@details Equivalent SD-6 macro: `__cpp_lib_constexpr_algorithms`. This
	token corresponds to the `201806L` variant; it will only be set to a
	non-`0` value if that variant is available.
	- [201703L](https://wg21.link/P0202R3)
	- [201806L](https://wg21.link/P0879R0)
	- [201806L](https://wg21.link/LWG3256)

	@sa `<algorithm>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP
	#define LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_CONSTEXPR_ALGORITHMS_SWAP
		#define LBAL_LIBCPP2A_CONSTEXPR_ALGORITHMS_SWAP LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_CONSTEXPR_COMPLEX
	@brief Add more `constexpr` support to `<complex>`
	@details Equivalent SD-6 macro: `__cpp_lib_constexpr_complex`
	- [201711L](https://wg21.link/P0415R1) __PDF__

	@sa `<complex>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_COMPLEX
	#define LBAL_LIBCPP20_CONSTEXPR_COMPLEX 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ These tokens have been renamed. The old names are deprecated
	//	and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_MORE_CONSTEXPR_FOR_COMPLEX
		#define LBAL_LIBCPP2A_MORE_CONSTEXPR_FOR_COMPLEX \
				LBAL_LIBCPP20_CONSTEXPR_COMPLEX
	#endif

	#ifndef LBAL_LIBCPP2A_CONSTEXPR_COMPLEX
		#define LBAL_LIBCPP2A_CONSTEXPR_COMPLEX LBAL_LIBCPP20_CONSTEXPR_COMPLEX
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC
	@brief Add `constexpr` memory allocators used by dynamic containers
	@details Equivalent SD-6 macro: `__cpp_lib_constexpr_dynamic_alloc`
	- [201907L](https://wg21.link/P0784R7)

	@sa `<memory>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC
	#define LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_CONSTEXPR_DYNAMIC_ALLOC
		#define LBAL_LIBCPP2A_CONSTEXPR_DYNAMIC_ALLOC LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL
	@brief Make more of `<functional>` `constexpr`
	@details Equivalent SD-6 macro: `__cpp_lib_constexpr_functional`. This
	token corresponds to the `201811L` variant; it will only be set to a
	non-`0` value if that variant is available.
	- [201811L](https://wg21.link/P1032R1)
	- [201907L](https://wg21.link/P1065R2)

	@sa `<functional>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL
	#define LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ These tokens have been renamed. The old names are deprecated
	//	and will be removed in a future release.

	//	__SEEME__ Note that the original token was split over many other
	//	tokens, so selecting this particular one is somewhat arbitrary.
	#ifndef LBAL_LIBCPP2A_CONSTEXPR
		#define LBAL_LIBCPP2A_CONSTEXPR LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL
	#endif

	#ifndef LBAL_LIBCPP2A_CONSTEXPR_FUNCTIONAL
		#define LBAL_LIBCPP2A_CONSTEXPR_FUNCTIONAL LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE
	@brief Make `std::invoke` `constexpr`
	@details Equivalent SD-6 macro: `__cpp_lib_constexpr_functional`. This
	token corresponds to the `201907L` variant; it will only be set to a
	non-`0` value if that variant is available.
	- [201811L](https://wg21.link/P1032R1)
	- [201907L](https://wg21.link/P1065R2)

	@sa `<functional>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE
	#define LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_CONSTEXPR_FUNCTIONAL_INVOKE
		#define LBAL_LIBCPP2A_CONSTEXPR_FUNCTIONAL_INVOKE LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_CONSTEXPR_ITERATOR
	@brief Make more of `<iterator>` `constexpr`
	@details Equivalent SD-6 macro: `__cpp_lib_constexpr_iterator`
	- [201811L](https://wg21.link/P1032R1)

	@sa `<iterator>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_ITERATOR
	#define LBAL_LIBCPP20_CONSTEXPR_ITERATOR 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_CONSTEXPR_ITERATOR
		#define LBAL_LIBCPP2A_CONSTEXPR_ITERATOR LBAL_LIBCPP20_CONSTEXPR_ITERATOR
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_CONSTEXPR_MEMORY
	@brief Make `std::pointer_traits` `constexpr`
	@details Equivalent SD-6 macro: `__cpp_lib_constexpr_memory`
	- [201811L](https://wg21.link/P1006R1)

	@sa `<memory>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_MEMORY
	#define LBAL_LIBCPP20_CONSTEXPR_MEMORY 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_CONSTEXPR_MEMORY
		#define LBAL_LIBCPP2A_CONSTEXPR_MEMORY LBAL_LIBCPP20_CONSTEXPR_MEMORY
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_CONSTEXPR_NUMERIC
	@brief Make numeric algorithms `constexpr`
	@details Equivalent SD-6 macro: `__cpp_lib_constexpr_numeric`
	- [201911L](https://wg21.link/P1645R1)

	@sa `<numeric>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_NUMERIC
	#define LBAL_LIBCPP20_CONSTEXPR_NUMERIC 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_CONSTEXPR_NUMERIC
		#define LBAL_LIBCPP2A_CONSTEXPR_NUMERIC LBAL_LIBCPP20_CONSTEXPR_NUMERIC
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_CONSTEXPR_STRING
	@brief Make `std::string` `constexpr`
	@details Equivalent SD-6 macro: `__cpp_lib_constexpr_string`
	- [201907L](https://wg21.link/P0980R1)

	@sa `<string>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_STRING
	#define LBAL_LIBCPP20_CONSTEXPR_STRING 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_CONSTEXPR_STRING
		#define LBAL_LIBCPP2A_CONSTEXPR_STRING LBAL_LIBCPP20_CONSTEXPR_STRING
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW
	@brief Make more of `<string_view>` `constexpr`
	@details Equivalent SD-6 macro: `__cpp_lib_constexpr_string_view`
	- [201811L](https://wg21.link/P1032R1)

	@sa `<string_view>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW
	#define LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_CONSTEXPR_STRING_VIEW
		#define LBAL_LIBCPP2A_CONSTEXPR_STRING_VIEW LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_CONSTEXPR_TUPLE
	@brief Make more of `<tuple>` `constexpr`
	@details Equivalent SD-6 macro: `__cpp_lib_constexpr_tuple`
	- [201811L](https://wg21.link/P1032R1)

	@sa `<tuple>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_TUPLE
	#define LBAL_LIBCPP20_CONSTEXPR_TUPLE 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_CONSTEXPR_TUPLE
		#define LBAL_LIBCPP2A_CONSTEXPR_TUPLE LBAL_LIBCPP20_CONSTEXPR_TUPLE
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_CONSTEXPR_UTILITY
	@brief Make more of `<tuple>` `constexpr`
	@details Equivalent SD-6 macro: `__cpp_lib_constexpr_utility`
	- [201811L](https://wg21.link/P1032R1)

	@sa `<utility>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_UTILITY
	#define LBAL_LIBCPP20_CONSTEXPR_UTILITY 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_CONSTEXPR_UTILITY
		#define LBAL_LIBCPP2A_CONSTEXPR_UTILITY LBAL_LIBCPP20_CONSTEXPR_UTILITY
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_CONSTEXPR_VECTOR
	@brief Make `std::vector` `constexpr`
	@details Equivalent SD-6 macro: `__cpp_lib_constexpr_vector`
	- [201907L](https://wg21.link/P1004R2) __PDF__

	@sa `<vector>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_VECTOR
	#define LBAL_LIBCPP20_CONSTEXPR_VECTOR 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_CONSTEXPR_VECTOR
		#define LBAL_LIBCPP2A_CONSTEXPR_VECTOR LBAL_LIBCPP20_CONSTEXPR_VECTOR
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_COROUTINE
	@brief Standard Library coroutines
	@details Equivalent SD-6 macro: `__cpp_lib_coroutine`
	- [201902L](https://wg21.link/P0912R5)
	- [201902L](https://wg21.link/LWG3393)

	@remarks Note that `<coroutine>` requires language support.

	@remarks __SEEME__ Confusingly, [n4736](https://wg21.link/n4736) __PDF__
	was voted into the Standard, but [n4760](https://wg21.link/n4760) __PDF__
	is the fixed version of it.

	@sa `<coroutine>`
*/
#ifndef LBAL_LIBCPP20_COROUTINE
	#define LBAL_LIBCPP20_COROUTINE 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ These tokens have been renamed. The old names are deprecated
	//	and will be removed in a future release.

	//	__SEEME__ Our old token has been replaced by an official version. The
	//	old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_COROUTINES
		#define LBAL_LIBCPP2A_COROUTINES LBAL_LIBCPP20_COROUTINE
	#endif

	#ifndef LBAL_LIBCPP2A_COROUTINE
		#define LBAL_LIBCPP2A_COROUTINE LBAL_LIBCPP20_COROUTINE
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_COROUTINE_EXP
	@brief Experimental Standard Library coroutines
	@details Equivalent SD-6 macro: `__cpp_lib_experimental_coroutine`
	- [201902L](https://wg21.link/P0912R5)
	- [201902L](https://wg21.link/LWG3393)

	@remarks Note that `<coroutine>` requires language support.

	@remarks __SEEME__ Confusingly, [n4736](https://wg21.link/n4736) __PDF__
	was voted into the Standard, but [n4760](https://wg21.link/n4760) __PDF__
	is the fixed version of it.

	@sa `<experimental/coroutine>`
*/
#ifndef LBAL_LIBCPP20_COROUTINE_EXP
	#define LBAL_LIBCPP20_COROUTINE_EXP 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ These tokens have been renamed. The old names are deprecated
	//	and will be removed in a future release.

	//	__SEEME__ Our old token has been replaced by an official version. The
	//	old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_COROUTINES_EXP
		#define LBAL_LIBCPP2A_COROUTINES_EXP LBAL_LIBCPP20_COROUTINE_EXP
	#endif

	#ifndef LBAL_LIBCPP2A_COROUTINE_EXP
		#define LBAL_LIBCPP2A_COROUTINE_EXP LBAL_LIBCPP20_COROUTINE_EXP
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_DESTROYING_DELETE
	@brief Efficient sized `delete` for variable-sized classes
	@details Equivalent SD-6 macro: `__cpp_lib_destroying_delete`
	- [201806L](https://wg21.link/P0722R3)

	@sa `<new>`
*/
#ifndef LBAL_LIBCPP20_DESTROYING_DELETE
	#define LBAL_LIBCPP20_DESTROYING_DELETE 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_DESTROYING_DELETE
		#define LBAL_LIBCPP2A_DESTROYING_DELETE LBAL_LIBCPP20_DESTROYING_DELETE
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_ENDIAN
	@brief Add `std::endian` enum
	@details Equivalent SD-6 macro: `__cpp_lib_endian`
	- [201907L](https://wg21.link/P0463R1)
	- [201907L](https://wg21.link/P1612R1) __PDF__

	This token corresponds to the P0463R1 variant; it will only be set to a
	non-`0` value if that variant is available.

	@sa `<bit>`
*/
#ifndef LBAL_LIBCPP20_ENDIAN
	#define LBAL_LIBCPP20_ENDIAN 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ These tokens have been renamed. The old names are deprecated
	//	and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_STD_ENDIAN
		#define LBAL_LIBCPP2A_STD_ENDIAN LBAL_LIBCPP20_ENDIAN
	#endif

	#ifndef LBAL_LIBCPP2A_ENDIAN
		#define LBAL_LIBCPP2A_ENDIAN LBAL_LIBCPP20_ENDIAN
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_ENDIAN_BIT
	@brief Relocate `std::endian` to `<bit>`
	@details Equivalent SD-6 macro: `__cpp_lib_endian`
	- [201907L](https://wg21.link/P0463R1)
	- [201907L](https://wg21.link/P1612R1) __PDF__

	This token corresponds to the P1612R1 variant; it will only be set to a
	non-`0` value if that variant is available.

	@sa `<bit>`
*/
#ifndef LBAL_LIBCPP20_ENDIAN_BIT
	#define LBAL_LIBCPP20_ENDIAN_BIT 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_ENDIAN_BIT
		#define LBAL_LIBCPP2A_ENDIAN_BIT LBAL_LIBCPP20_ENDIAN_BIT
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_ERASE_IF
	@brief Adopt consistent container erasure
	@details Equivalent SD-6 macro: `__cpp_lib_erase_if`
	- [201811L](https://wg21.link/P1209R0)
	- [202002L](https://wg21.link/P1115R3) __PDF__

	This token corresponds to the `201811L` variant; it will only be set to a
	non-`0` value if that variant is available.

	@sa `<deque>` `<forward_list>` `<list>` `<map>` `<set>` `<string>`
	`<unordered_map>` `<unordered_set>` `<vector>`
*/
#ifndef LBAL_LIBCPP20_ERASE_IF
	#define LBAL_LIBCPP20_ERASE_IF 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_ERASE_IF
		#define LBAL_LIBCPP2A_ERASE_IF LBAL_LIBCPP20_ERASE_IF
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS
	@brief Update `erase_if` free function return types
	@details Equivalent SD-6 macro: `__cpp_lib_erase_if`
	- [201811L](https://wg21.link/P1209R0)
	- [202002L](https://wg21.link/P1115R3) __PDF__

	This token corresponds to the `202002L` variant; it will only be set to a
	non-`0` value if that variant is available.

	@sa `<deque>` `<forward_list>` `<list>` `<map>` `<set>` `<string>`
	`<unordered_map>` `<unordered_set>` `<vector>`
*/
#ifndef LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS
	#define LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_ERASE_IF_FREE_FUNCTIONS
		#define LBAL_LIBCPP2A_ERASE_IF_FREE_FUNCTIONS LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_EXECUTION_VECTORIZATION
	@brief Add target vectorization policies from the Parallelism V2 TS
	@details Equivalent SD-6 macro: `__cpp_lib_execution`
	- [201603L](https://wg21.link/P0024R2)
	- [201902L](https://wg21.link/P1001R2)

	This token corresponds to the `201902L` variant; it will only be set to a
	non-`0` value if that variant is available.

	By itself, this token does not measure compliance with the referenced
	Working Group paper; use LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS.

	@remarks __APIME__ We do not track experimental versions of this.

	@sa `<execution>`
*/
#ifndef LBAL_LIBCPP20_EXECUTION_VECTORIZATION
	#define LBAL_LIBCPP20_EXECUTION_VECTORIZATION 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_EXECUTION_VECTORIZATION
		#define LBAL_LIBCPP2A_EXECUTION_VECTORIZATION LBAL_LIBCPP20_EXECUTION_VECTORIZATION
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_FORMAT
	@brief Add text formatting functionality to properly replace `printf`
	@details Equivalent SD-6 macro: `__cpp_lib_format`
	- [201907L](https://wg21.link/P0645R10)
	- [201907L](https://wg21.link/P1361R2)
	- [201907L](https://wg21.link/P1652R1)

	@sa `<format>`
*/
#ifndef LBAL_LIBCPP20_FORMAT
	#define LBAL_LIBCPP20_FORMAT 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_FORMAT
		#define LBAL_LIBCPP2A_FORMAT LBAL_LIBCPP20_FORMAT
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP
	@brief The feature was removed prior to Standardization
	@details Equivalent SD-6 macro: `__cpp_lib_generic_unordered_hash_lookup`
	- [201902L](https://wg21.link/P0920R2)
	- [deleted](https://wg21.link/P1661R1)

	This is an unusual example of a feature that was voted into the Standard
	and then promptly voted out.

	@remarks `LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP` will always evaluate
	to `0`; it is only here by way of documentation.

	@sa `<unordered_map>` `<unordered_set>`
*/
#ifndef LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP
	#define LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_GENERIC_UNORDERED_HASH_LOOKUP
		#define LBAL_LIBCPP2A_GENERIC_UNORDERED_HASH_LOOKUP LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP
	@brief Heterogeneous lookup for unordered containers
	@details Equivalent SD-6 macro: `__cpp_lib_generic_unordered_lookup`
	- [201811L](https://wg21.link/P0919R3)

	@sa `<unordered_map>` `<unordered_set>`
*/
#ifndef LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP
	#define LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_GENERIC_UNORDERED_LOOKUP
		#define LBAL_LIBCPP2A_GENERIC_UNORDERED_LOOKUP LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_INT_POW2
	@brief Integral power-of-2 operations
	@details Equivalent SD-6 macro: `__cpp_lib_int_pow2`. This token
	corresponds to the `201806L` variant; it will only be set to a non-`0`
	value if that variant is available.
	- [201806L](https://wg21.link/P0556R3)
	- [202002L](https://wg21.link/P1956R1)

	@sa `<bit>`
*/
#ifndef LBAL_LIBCPP20_INT_POW2
	#define LBAL_LIBCPP20_INT_POW2 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_INT_POW2
		#define LBAL_LIBCPP2A_INT_POW2 LBAL_LIBCPP20_INT_POW2
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME
	@brief Rename the assorted bit-manipulation fucntions
	@details Equivalent SD-6 macro: `__cpp_lib_int_pow2`. This token
	corresponds to the `202002L` variant; it will only be set to a non-`0`
	value if that variant is available.
	- [201806L](https://wg21.link/P0556R3)
	- [202002L](https://wg21.link/P1956R1)

	@sa `<bit>`
*/
#ifndef LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME
	#define LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_INT_POW2_FUNCTION_RENAME
		#define LBAL_LIBCPP2A_INT_POW2_FUNCTION_RENAME LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS
	@brief Add Safe integral comparisons
	@details Equivalent SD-6 macro: `__cpp_lib_integer_comparison_functions`
	- [202002L](https://wg21.link/P0586R2)

	@sa `<utility>`
*/
#ifndef LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS
	#define LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_INTEGER_COMPARISON_FUNCTIONS
		#define LBAL_LIBCPP2A_INTEGER_COMPARISON_FUNCTIONS LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_INTERPOLATE
	@brief Add well-behaved interpolation for numbers and pointers
	@details Equivalent SD-6 macro: `__cpp_lib_interpolate`
	- [201902L](https://wg21.link/P0811R3)

	@sa `<cmath>` `<numeric>`
*/
#ifndef LBAL_LIBCPP20_INTERPOLATE
	#define LBAL_LIBCPP20_INTERPOLATE 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_INTERPOLATE
		#define LBAL_LIBCPP2A_INTERPOLATE LBAL_LIBCPP20_INTERPOLATE
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_IS_CONSTANT_EVALUATED
	@brief Add `std::is_constant_evaluated` type trait
	@details Equivalent SD-6 macro: `__cpp_lib_is_constant_evaluated`
	- [201811L](https://wg21.link/P0595R2)

	@sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP20_IS_CONSTANT_EVALUATED
	#define LBAL_LIBCPP20_IS_CONSTANT_EVALUATED 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_IS_CONSTANT_EVALUATED
		#define LBAL_LIBCPP2A_IS_CONSTANT_EVALUATED LBAL_LIBCPP20_IS_CONSTANT_EVALUATED
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE
	@brief Add `std::is_layout_compatible` type trait
	@details Equivalent SD-6 macro: `__cpp_lib_is_layout_compatible`
	- [201907L](https://wg21.link/P0466R5)

	@sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE
	#define LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_IS_LAYOUT_COMPATIBLE
		#define LBAL_LIBCPP2A_IS_LAYOUT_COMPATIBLE LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE
	@brief Add `std::is_pointer_interconvertible` type trait
	@details Equivalent SD-6 macro: `__cpp_lib_is_pointer_interconvertible`
	- [201907L](https://wg21.link/P0466R5)

	@sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE
	#define LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_IS_POINTER_INTERCONVERTIBLE
		#define LBAL_LIBCPP2A_IS_POINTER_INTERCONVERTIBLE LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_JTHREAD
	@brief Add a cooperatively interruptible joining thread
	@details Equivalent SD-6 macro: `__cpp_lib_jthread`. This token corresponds
	to the `201907L` variant; it will only be set to a non-`0` value if that
	variant is available.
	- [201907L](https://wg21.link/P0660R10)
	- [201911L](https://wg21.link/P1869R1)

	@sa `<stop_token>` `<thread>`
*/
#ifndef LBAL_LIBCPP20_JTHREAD
	#define LBAL_LIBCPP20_JTHREAD 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_JTHREAD
		#define LBAL_LIBCPP2A_JTHREAD LBAL_LIBCPP20_JTHREAD
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_JTHREAD_CV
	@brief Simplify condition variable API
	@details Equivalent SD-6 macro: `__cpp_lib_jthread`. This token corresponds
	to the `201911L` variant; it will only be set to a non-`0` value if that
	variant is available.
	- [201907L](https://wg21.link/P0660R10)
	- [201911L](https://wg21.link/P1869R1)

	@sa `<stop_token>` `<thread>`
*/
#ifndef LBAL_LIBCPP20_JTHREAD_CV
	#define LBAL_LIBCPP20_JTHREAD_CV 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_JTHREAD_CV
		#define LBAL_LIBCPP2A_JTHREAD_CV LBAL_LIBCPP20_JTHREAD_CV
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_LATCH
	@brief Incorporate `std::latch` from the C++20 Synchronization Library
	@details Equivalent SD-6 macro: `__cpp_lib_latch`
	- [201907L](https://wg21.link/P1135R6)

	@sa `<latch>`
*/
#ifndef LBAL_LIBCPP20_LATCH
	#define LBAL_LIBCPP20_LATCH 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_LATCH
		#define LBAL_LIBCPP2A_LATCH LBAL_LIBCPP20_LATCH
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE
	@brief Improve the return value of erase-like algorithms
	@details Equivalent SD-6 macro: `__cpp_lib_list_remove_return_type`
	- [201806L](https://wg21.link/P0646R1) __PDF__

	@sa `<forward_list>` `<list>`
*/
#ifndef LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE
	#define LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_LIST_REMOVE_RETURN_TYPE
		#define LBAL_LIBCPP2A_LIST_REMOVE_RETURN_TYPE LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_MATH_CONSTANTS
	@brief Add common math constants to the C++ Standard
	@details Equivalent SD-6 macro: `__cpp_lib_math_constants`
	- [201907L](https://wg21.link/P0631R8) __PDF__

	@sa `<numbers>`
*/
#ifndef LBAL_LIBCPP20_MATH_CONSTANTS
	#define LBAL_LIBCPP20_MATH_CONSTANTS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_MATH_CONSTANTS
		#define LBAL_LIBCPP2A_MATH_CONSTANTS LBAL_LIBCPP20_MATH_CONSTANTS
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE
	@brief Add `std::is_nothrow_convertible` type trait
	@details Equivalent SD-6 macro: `__cpp_lib_is_nothrow_convertible`
	- [201806L](https://wg21.link/P0758R1)
	- [201806L](https://wg21.link/LWG3356)
	@remarks __SEEME__ LWG3356 should probably have gotten its own value;
	the argument against that is that it was a defect corrected prior to
	Standardization.

	@sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE
	#define LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ These tokens have been renamed. The old names are deprecated
	//	and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_NOTHROW_CONVERTIBLE
		#define LBAL_LIBCPP2A_NOTHROW_CONVERTIBLE \
				LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE
	#endif

	#ifndef LBAL_LIBCPP2A_IS_NOTHROW_CONVERTIBLE
		#define LBAL_LIBCPP2A_IS_NOTHROW_CONVERTIBLE LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR
	@brief Provide a default template argument for `std::polymorphic_allocator`
	@details Equivalent SD-6 macro: `__cpp_lib_polymorphic_allocator`
	- [201902L](https://wg21.link/P0339R6) __PDF__

	@sa `<memory>`
*/
#ifndef LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR
	#define LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_POLYMORPHIC_ALLOCATOR
		#define LBAL_LIBCPP2A_POLYMORPHIC_ALLOCATOR LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_RANGES
	@brief Incorporate ranges into the C++ Standard
	@details Equivalent SD-6 macro: `__cpp_lib_ranges`. This token corresponds
	to the `201811L` variant; it will only be set to a non-`0` value if that
	variant is available.
	- [201811L](https://wg21.link/P0896R4) __PDF__
	- [201907L](https://wg21.link/P1035R7) __PDF__
	- [201911L](https://wg21.link/P1716R3)

	@sa `<algorithm>` `<functional>` `<iterator>` `<memory>` `<ranges>`
*/
#ifndef LBAL_LIBCPP20_RANGES
	#define LBAL_LIBCPP20_RANGES 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_RANGES
		#define LBAL_LIBCPP2A_RANGES LBAL_LIBCPP20_RANGES
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS
	@brief Add input range adaptors
	@details Equivalent SD-6 macro: `__cpp_lib_ranges`. This token corresponds
	to the `201907L` variant; it will only be set to a non-`0` value if that
	variant is available.
	- [201811L](https://wg21.link/P0896R4) __PDF__
	- [201907L](https://wg21.link/P1035R7) __PDF__
	- [201911L](https://wg21.link/P1716R3)

	@sa `<algorithm>` `<functional>` `<iterator>` `<memory>` `<ranges>`
*/
#ifndef LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS
	#define LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_RANGES_INPUT_ADAPTORS
		#define LBAL_LIBCPP2A_RANGES_INPUT_ADAPTORS LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE
	@brief Loosen the constraints on range-based compare algorithms
	@details Equivalent SD-6 macro: `__cpp_lib_ranges`. This token corresponds
	to the `201911L` variant; it will only be set to a non-`0` value if that
	variant is available.
	- [201811L](https://wg21.link/P0896R4) __PDF__
	- [201907L](https://wg21.link/P1035R7) __PDF__
	- [201911L](https://wg21.link/P1716R3)

	@sa `<algorithm>` `<functional>` `<iterator>` `<memory>` `<ranges>`
*/
#ifndef LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE
	#define LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_RANGES_LOOSENED_COMPARE
		#define LBAL_LIBCPP2A_RANGES_LOOSENED_COMPARE LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_REMOVE_CVREF
	@brief Add `std::remove_cvref` type trait
	@details Equivalent SD-6 macro: `__cpp_lib_remove_cvref`
	- [201711L](https://wg21.link/p0550r2) __PDF__

	@sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP20_REMOVE_CVREF
	#define LBAL_LIBCPP20_REMOVE_CVREF 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ These tokens have been renamed. The old names are deprecated
	//	and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_STD_REMOVE_CVREF
		#define LBAL_LIBCPP2A_STD_REMOVE_CVREF LBAL_LIBCPP20_REMOVE_CVREF
	#endif

	#ifndef LBAL_LIBCPP2A_REMOVE_CVREF
		#define LBAL_LIBCPP2A_REMOVE_CVREF LBAL_LIBCPP20_REMOVE_CVREF
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_SEMAPHORE
	@brief Incorporate `std::semaphore` from the C++20 Synchronization Library
	@details Equivalent SD-6 macro: `__cpp_lib_semaphore`
	- [201907L](https://wg21.link/P1135R6)

	@sa `<semaphore>`
*/
#ifndef LBAL_LIBCPP20_SEMAPHORE
	#define LBAL_LIBCPP20_SEMAPHORE 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_SEMAPHORE
		#define LBAL_LIBCPP2A_SEMAPHORE LBAL_LIBCPP20_SEMAPHORE
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_SHARED_PTR_ARRAYS
	@brief Extend `std::make_shared` to support C-style arrays
	@details Equivalent SD-6 macro: `__cpp_lib_shared_ptr_arrays`
	- [201707L](https://wg21.link/P0674R1)

	@sa `<memory>`
*/
#ifndef LBAL_LIBCPP20_SHARED_PTR_ARRAYS
	#define LBAL_LIBCPP20_SHARED_PTR_ARRAYS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ These tokens have been renamed. The old names are deprecated
	//	and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_EXTENDING_MAKE_SHARED_TO_SUPPORT_ARRAYS
		#define LBAL_LIBCPP2A_EXTENDING_MAKE_SHARED_TO_SUPPORT_ARRAYS \
				LBAL_LIBCPP20_SHARED_PTR_ARRAYS
	#endif

	#ifndef LBAL_LIBCPP2A_SHARED_PTR_ARRAYS
		#define LBAL_LIBCPP2A_SHARED_PTR_ARRAYS \
				LBAL_LIBCPP20_SHARED_PTR_ARRAYS
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_SHIFT
	@brief Add `std::shift_left` and `std::shift_right`
	@details Equivalent SD-6 macro: `__cpp_lib_shared_ptr_arrays`
	- [201806L](https://wg21.link/P0769R2)

	@sa `<algorithm>`
*/
#ifndef LBAL_LIBCPP20_SHIFT
	#define LBAL_LIBCPP20_SHIFT 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_SHIFT
		#define LBAL_LIBCPP2A_SHIFT LBAL_LIBCPP20_SHIFT
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE
	@brief Support smart pointer creation with default initialization
	@details Equivalent SD-6 macro: `__cpp_lib_smart_ptr_for_overwrite`
	- [201811L](https://wg21.link/P1020R1)
	- [202002L](https://wg21.link/P1973R1)
	@remarks The SD-6 token name was renamed as part of
	[P1973R1](https://wg21.link/P1973R1).

	@sa `<memory>`
*/
#ifndef LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE
	#define LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ These tokens have been renamed. The old names are deprecated
	//	and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_SMART_PTR_DEFAULT_INIT
		#define LBAL_LIBCPP2A_SMART_PTR_DEFAULT_INIT \
				LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE
	#endif

	#ifndef LBAL_LIBCPP2A_SMART_PTR_FOR_OVERWRITE
		#define LBAL_LIBCPP2A_SMART_PTR_FOR_OVERWRITE \
				LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_SOURCE_LOCATION
	@brief Adopt `std::source_location` from the Library Fundamentals V3 TS
	@details Equivalent SD-6 macro: `__cpp_lib_source_location`
	- [201907L](https://wg21.link/P1208R6)

	@sa `<source_location>`
*/
#ifndef LBAL_LIBCPP20_SOURCE_LOCATION
	#define LBAL_LIBCPP20_SOURCE_LOCATION 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_SOURCE_LOCATION
		#define LBAL_LIBCPP2A_SOURCE_LOCATION LBAL_LIBCPP20_SOURCE_LOCATION
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_SPAN
	@brief Add `std::span`
	@details Equivalent SD-6 macro: `__cpp_lib_span`. This token corresponds to
	the `201803L` variant; it will only be set to a non-`0` value if that
	variant is available.
	- [201803L](https://wg21.link/P0122R7)
	- [201803L](https://wg21.link/LWG3274)
	- [201902L](https://wg21.link/P1024R3) __PDF__
	- [202002L](https://wg21.link/P1976R2)

	@remarks The issue raised in [LWG3274](https://wg21.link/LWG3274) was
	simply that [P0122R7](https://wg21.link/P0122R7) had been voted in without
	specifying an SD-6 macro.

	@sa `<span>`
*/
#ifndef LBAL_LIBCPP20_SPAN
	#define LBAL_LIBCPP20_SPAN 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_SPAN
		#define LBAL_LIBCPP2A_SPAN LBAL_LIBCPP20_SPAN
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_SPAN_USABILITY
	@brief Enhance usability for `std::span`
	@details Equivalent SD-6 macro: `__cpp_lib_span`. This token corresponds to
	the `201902L` variant; it will only be set to a non-`0` value if that
	variant is available.
	- [201803L](https://wg21.link/P0122R7)
	- [201803L](https://wg21.link/LWG3274)
	- [201902L](https://wg21.link/P1024R3)
	- [202002L](https://wg21.link/P1976R2)

	@sa `<span>`
*/
#ifndef LBAL_LIBCPP20_SPAN_USABILITY
	#define LBAL_LIBCPP20_SPAN_USABILITY 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_SPAN_USABILITY
		#define LBAL_LIBCPP2A_SPAN_USABILITY LBAL_LIBCPP20_SPAN_USABILITY
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_SPAN_FIXED_SIZE
	@brief Fix constructing a fixed-size `std::span` from a dynamic range
	@details Equivalent SD-6 macro: `__cpp_lib_span`. This token corresponds to
	the `202002L` variant; it will only be set to a non-`0` value if that
	variant is available.
	- [201803L](https://wg21.link/P0122R7)
	- [201803L](https://wg21.link/LWG3274)
	- [201902L](https://wg21.link/P1024R3)
	- [202002L](https://wg21.link/P1976R2)

	@sa `<span>`
*/
#ifndef LBAL_LIBCPP20_SPAN_FIXED_SIZE
	#define LBAL_LIBCPP20_SPAN_FIXED_SIZE 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_SPAN_FIXED_SIZE
		#define LBAL_LIBCPP2A_SPAN_FIXED_SIZE LBAL_LIBCPP20_SPAN_FIXED_SIZE
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_SSIZE
	@brief Add `std::ssize` and fix `std::span`’s `size` return values
	@details Equivalent SD-6 macro: `__cpp_lib_ssize`
	- [201902L](https://wg21.link/P1227R2)

	@remarks It’s conceivable that the `<span>`-affecting portions of this will
	be shifted to the `__cpp_lib_span` token.

	@sa `<iterator>` `<span>`
*/
#ifndef LBAL_LIBCPP20_SSIZE
	#define LBAL_LIBCPP20_SSIZE 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_SSIZE
		#define LBAL_LIBCPP2A_SSIZE LBAL_LIBCPP20_SSIZE
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_STARTS_ENDS_WITH
	@brief Add string prefix- and suffix-checking
	@details Equivalent SD-6 macro: `__cpp_lib_starts_ends_with`
	- [201711L](https://wg21.link/P0457R2)

	@sa `<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP20_STARTS_ENDS_WITH
	#define LBAL_LIBCPP20_STARTS_ENDS_WITH 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ These tokens have been renamed. The old names are deprecated
	//	and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_STRING_PREFIX_AND_SUFFIX_CHECKING
		#define LBAL_LIBCPP2A_STRING_PREFIX_AND_SUFFIX_CHECKING \
			LBAL_LIBCPP20_STARTS_ENDS_WITH
	#endif

	#ifndef LBAL_LIBCPP2A_STARTS_ENDS_WITH
		#define LBAL_LIBCPP2A_STARTS_ENDS_WITH \
			LBAL_LIBCPP20_STARTS_ENDS_WITH
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR

	@brief Add support for `constexpr` iterators to `<string_view>`

	@details Equivalent SD-6 macro: `__cpp_lib_string_view`. This token
	corresponds to the `201803L` variant; it will only be set to a non-`0`
	value if that variant is available.
	- [201603L](https://wg21.link/P0220R1)
	- [201606L](https://wg21.link/P0254R2) __PDF__
	- [201803L](https://wg21.link/P0858R0)
	- [201803L](https://wg21.link/LWG3257)

	@remarks The issue raised in [LWG3257](https://wg21.link/LWG3257) was
	simply that the SD-6 macro update voted in with
	[201803L](https://wg21.link/P0858R0) had not been applied.

	@sa `<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR
	#define LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_STRING_VIEW_CONSTEXPR_ITERATOR
		#define LBAL_LIBCPP2A_STRING_VIEW_CONSTEXPR_ITERATOR \
			LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_SYNCBUF
	@brief Add synchronized buffered output streams
	@details Equivalent SD-6 macro: `__cpp_lib_syncbuf`. This token
	corresponds to the `201711L` variant; it will only be set to a non-`0`
	value if that variant is available.
	- [201711L](https://wg21.link/P0053R7) __PDF__
	- [201803L](https://wg21.link/P0753R2) __PDF__

	@sa `<syncstream>`
*/
#ifndef LBAL_LIBCPP20_SYNCBUF
	#define LBAL_LIBCPP20_SYNCBUF 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ These tokens have been renamed. The old names are deprecated
	//	and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_SYNCHRONIZED_BUFFERED_OSTREAM
		#define LBAL_LIBCPP2A_SYNCHRONIZED_BUFFERED_OSTREAM \
			LBAL_LIBCPP20_SYNCBUF
	#endif

	#ifndef LBAL_LIBCPP2A_SYNCBUF
		#define LBAL_LIBCPP2A_SYNCBUF \
			LBAL_LIBCPP20_SYNCBUF
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_SYNCBUF_MANIPULATORS
	@brief Add manipulators for synchronized buffered output streams
	@details Equivalent SD-6 macro: `__cpp_lib_syncbuf`. This token
	corresponds to the `201803L` variant; it will only be set to a non-`0`
	value if that variant is available.
	- [201711L](https://wg21.link/P0053R7) __PDF__
	- [201803L](https://wg21.link/P0753R2) __PDF__

	@sa `<syncstream>`
*/
#ifndef LBAL_LIBCPP20_SYNCBUF_MANIPULATORS
	#define LBAL_LIBCPP20_SYNCBUF_MANIPULATORS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_SYNCBUF_MANIPULATORS
		#define LBAL_LIBCPP2A_SYNCBUF_MANIPULATORS \
			LBAL_LIBCPP20_SYNCBUF_MANIPULATORS
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_THREE_WAY_COMPARISON
	@brief Add `<compare>` to the Standard Library
	@details Equivalent SD-6 macro: `__cpp_lib_three_way_comparison`. This
	token corresponds to the `201711L` variant; it will only be set to a
	non-`0` value if that variant is available.
	- [201711L](https://wg21.link/P0768R1)
	- [201907L](https://wg21.link/P1614R2)

	@sa `<compare>`
*/
#ifndef LBAL_LIBCPP20_THREE_WAY_COMPARISON
	#define LBAL_LIBCPP20_THREE_WAY_COMPARISON 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ These tokens have been renamed. The old names are deprecated
	//	and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_THREE_WAY_COMPARISON_OPERATOR_SUPPORT_COMPARE
		#define LBAL_LIBCPP2A_THREE_WAY_COMPARISON_OPERATOR_SUPPORT_COMPARE \
			LBAL_LIBCPP20_THREE_WAY_COMPARISON
	#endif

	#ifndef LBAL_LIBCPP2A_THREE_WAY_COMPARISON
		#define LBAL_LIBCPP2A_THREE_WAY_COMPARISON \
			LBAL_LIBCPP20_THREE_WAY_COMPARISON
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY
	@brief Add three-way comparison support to the Standard Library
	@details Equivalent SD-6 macro: `__cpp_lib_three_way_comparison`. This
	token corresponds to the `201907L` variant; it will only be set to a
	non-`0` value if that variant is available.
	- [201711L](https://wg21.link/P0768R1)
	- [201907L](https://wg21.link/P1614R2)

	@sa `<compare>`
*/
#ifndef LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY
	#define LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_THREE_WAY_COMPARISON_LIBRARY
		#define LBAL_LIBCPP2A_THREE_WAY_COMPARISON_LIBRARY \
			LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_TO_ADDRESS
	@brief Provide a utility to convert a pointer to a raw pointer
	@details Equivalent SD-6 macro: `__cpp_lib_to_address`
	- [201711L](https://wg21.link/P0653R2) __PDF__

	@sa `<memory>`
*/
#ifndef LBAL_LIBCPP20_TO_ADDRESS
	#define LBAL_LIBCPP20_TO_ADDRESS 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ These tokens have been renamed. The old names are deprecated
	//	and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_UTILITY_TO_CONVERT_A_POINTER_TO_A_RAW_POINTER
		#define LBAL_LIBCPP2A_UTILITY_TO_CONVERT_A_POINTER_TO_A_RAW_POINTER \
			LBAL_LIBCPP20_TO_ADDRESS
	#endif

	#ifndef LBAL_LIBCPP2A_TO_ADDRESS
		#define LBAL_LIBCPP2A_TO_ADDRESS \
			LBAL_LIBCPP20_TO_ADDRESS
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_TO_ARRAY
	@brief Adopt `std::to_array` from the Library Fundamentals TS
	@details Equivalent SD-6 macro: `__cpp_lib_to_array`
	- [201907L](https://wg21.link/P0325R4)

	@sa `<array>`
*/
#ifndef LBAL_LIBCPP20_TO_ARRAY
	#define LBAL_LIBCPP20_TO_ARRAY 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_TO_ARRAY
		#define LBAL_LIBCPP2A_TO_ARRAY \
			LBAL_LIBCPP20_TO_ARRAY
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_TYPE_IDENTITY
	@brief Add the `std::identity` metafunction
	@details Equivalent SD-6 macro: `__cpp_lib_type_identity`
	- [201806L](https://wg21.link/P0887R1) __PDF__

	@sa `<type_traits>`
*/
#ifndef LBAL_LIBCPP20_TYPE_IDENTITY
	#define LBAL_LIBCPP20_TYPE_IDENTITY 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_TYPE_IDENTITY
		#define LBAL_LIBCPP2A_TYPE_IDENTITY \
			LBAL_LIBCPP20_TYPE_IDENTITY
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_UNWRAP_REF
	@brief Add `std::unwrap_reference` and `std::unwrap_ref_decay`
	@details Equivalent SD-6 macro: `__cpp_lib_unwrap_ref`
	- [201811L](https://wg21.link/P0318R1) __PDF__
	- [201811L](https://wg21.link/LWG3348)
	@remarks LWG3348 just moved this to `<functional>` from `<type_traits>`.

	@sa `<functional>`
*/
#ifndef LBAL_LIBCPP20_UNWRAP_REF
	#define LBAL_LIBCPP20_UNWRAP_REF 0
#endif

///@cond LBAL_INTERNAL
	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_UNWRAP_REF
		#define LBAL_LIBCPP2A_UNWRAP_REF \
			LBAL_LIBCPP20_UNWRAP_REF
	#endif
///@endcond

/**
	@def LBAL_LIBCPP20_VERSION

	Equivalent SD-6 macro: none

	This identifies whether `<version>` is present and include-able given the
	current C++ Standard dialect in use (some implementations may choose to
	back-port `<version>` to earlier releases).

	Note that unlike `<version>`, lucenaBAL tracks “correct”, functioning
	implementations only. So, for example, Xcode’s false positives for `<any>`
	and friends won’t be reported as support for the library feature. For this
	reason, it is recommended to _always_ favor the lucenaBAL reporting of a
	given feature’s availability, even when `<version>` is available.

	https://wg21.link/p0754r2 __PDF__
*/
#ifndef LBAL_LIBCPP20_VERSION
	#define LBAL_LIBCPP20_VERSION 0
#endif

	//	__APIME__ This token has been renamed for the official C++20 release.
	//	The old name is deprecated and will be removed in a future release.
	#ifndef LBAL_LIBCPP2A_VERSION
		#define LBAL_LIBCPP2A_VERSION \
			LBAL_LIBCPP20_VERSION
	#endif
///@endcond

///	@}	LBAL_LIBCPP20

/**
	@name LBAL_LIBCPPTS

	@brief C++ Technical Specifications that have not (yet?) been Standardized.

	@details These are typically very far along and likely to clear
	the bar. Generally, these will eventually be aliased—and then moved—into
	LBAL_LIBCPP2B/LBAL_LIBCPP23, etc.

	@remarks __SEEME__ The TSs can be highly mutable, and support should be
	considered very experimental. No effort at all will be expended to maintain
	backwards- compatibility with a TS once a feature has been voted in.

	@{
*/

/**
	@def LBAL_LIBCPPTS_NETWORKING

	Equivalent SD-6 macro: `__cpp_lib_net`

	https://wg21.link/n4734 __PDF__
*/
#ifndef LBAL_LIBCPPTS_NETWORKING
	#define LBAL_LIBCPPTS_NETWORKING 0
#endif

/**
	@def LBAL_LIBCPPTS_NETWORKING_EXP

	Equivalent SD-6 macro: `__cpp_lib_experimental_net`

	https://wg21.link/n4734 __PDF__
*/
#ifndef LBAL_LIBCPPTS_NETWORKING_EXP
	#define LBAL_LIBCPPTS_NETWORKING_EXP 0
#endif

/**
	@def LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE

	Equivalent SD-6 macro: `__cpp_lib_net_extensible`

	https://wg21.link/n4734 __PDF__
*/
#ifndef LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE
	#define LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE 0
#endif

/**
	@def LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP

	Equivalent SD-6 macro: `__cpp_lib_experimental_net_extensible`

	https://wg21.link/n4734 __PDF__
*/
#ifndef LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP
	#define LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP 0
#endif

/**
	@def LBAL_LIBCPPTS_OBSERVER_PTR

	Equivalent SD-6 macro: `__cpp_lib_observer_ptr`

	https://wg21.link/n4282 __PDF__
	https://wg21.link/n4758
*/
#ifndef LBAL_LIBCPPTS_OBSERVER_PTR
	#define LBAL_LIBCPPTS_OBSERVER_PTR 0
#endif

/**
	@def LBAL_LIBCPPTS_OBSERVER_PTR_EXP

	Equivalent SD-6 macro: `__cpp_lib_experimental_observer_ptr`

	https://wg21.link/n4282 __PDF__
	https://wg21.link/n4758
*/
#ifndef LBAL_LIBCPPTS_OBSERVER_PTR_EXP
	#define LBAL_LIBCPPTS_OBSERVER_PTR_EXP 0
#endif

///	@}	LBAL_LIBCPP20

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

	@remarks __FIXME__ This needs a usage example.

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

///@cond LBAL_INTERNAL
	//	__APIME__ These functions have been renamed. The old names are
	//	deprecated and will be removed in a future release.
	#ifndef LBAL_BUILTIN_likely
		#define LBAL_BUILTIN_likely(LBAL_expr_) LBAL_HINT_likely(LBAL_expr_)
	#endif

	#ifndef LBAL_BUILTIN_unlikely
		#define LBAL_BUILTIN_unlikely(LBAL_expr_) LBAL_HINT_unlikely(LBAL_expr_)
	#endif
///@endcond

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

/**
	@name LBAL_VIS

	@brief Decorators to control symbol visibility in the ABI

	@details These allow explicit control over what gets exported - and
	subsequently imported - by the linker. This task is somewhat complicated by
	different approaches on each platform toward what constitutes the contents
	of a library, e.g., whether inline functions are header-only constructs or
	whether they contribute object code to the library itself. We’ve noted
	usage issues to be aware of, as well as some relevant historical oddities.
	Note that some of these macros should be used conditionally; they should
	not be used to decorate symbols directly, but should instead be used to
	define decorators specific to a given project. Such decorators’ values
	should be dependent upon whether the project is being built or used; when
	building, set the decorator to the `EXPORT` variant of a given macro, but
	when using the build product, set it to the `IMPORT` variant. Macros that
	do not have multiple versions are not context-dependent and can be used
	directly - or used to define a library-specific macro unconditionally.

	If there are multiple declarations of a given symbol, all declarations
	should have the same decorators; in particular, do not leave some
	declarations undecorated. Failing to adhere to this policy will give
	warnings and possibly unpredictable behavior with some compilers.

	Establishing visibility rules for templates is fraught; read all the notes
	carefully before attempting to decorate templates of any kind, including
	classes containing member templates.

	Usage example:

		#if MY_LIB_CONFIG_buiding

		#define MY_LIB_VIS_CLASS                        LBAL_VIS_CLASS_EXPORT
		#define MY_LIB_VIS_EXTERN_CLASS_TEMPLATE        LBAL_VIS_EXTERN_CLASS_TEMPLATE_EXPORT
		#define MY_LIB_VIS_CLASS_TEMPLATE_INSTANTIATION LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_EXPORT
		#define MY_LIB_VIS_FUNC                         LBAL_VIS_FUNC_EXPORT
		#define MY_LIB_VIS_OVERLOADABLE_FUNC            LBAL_VIS_OVERLOADABLE_FUNC_EXPORT
		#define MY_LIB_VIS_EXCEPTION                    LBAL_VIS_EXCEPTION_EXPORT
		#define MY_LIB_VIS_EXTERN                       LBAL_VIS_EXTERN_EXPORT

		#else

		#define MY_LIB_VIS_CLASS                        LBAL_VIS_CLASS_IMPORT
		#define MY_LIB_VIS_EXTERN_CLASS_TEMPLATE        LBAL_VIS_EXTERN_CLASS_TEMPLATE_IMPORT
		#define MY_LIB_VIS_CLASS_TEMPLATE_INSTANTIATION LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_IMPORT
		#define MY_LIB_VIS_FUNC	                        LBAL_VIS_FUNC_IMPORT
		#define MY_LIB_VIS_OVERLOADABLE_FUNC            LBAL_VIS_OVERLOADABLE_FUNC_IMPORT
		#define MY_LIB_VIS_EXCEPTION                    LBAL_VIS_EXCEPTION_IMPORT
		#define MY_LIB_VIS_EXTERN                       LBAL_VIS_EXTERN_IMPORT

		#endif

	In this example, `MY_LIB_CONFIG_buiding` is only defined when building the
	binary, and left undefined otherwise. Symbols should be decorated with
	the appropriate `MY_LIB_VIS classifier`, and the compiler will do the right
	thing. Note that it’s only necessary to define macros for decorators that
	have `IMPORT`/`EXPORT` variants; for others (e.g., `LBAL_VIS_ENUM`) the
	unaliased macro can be used - or those may be aliased uniformly aliased as
	well, for API consistency.

	@remarks __SEEME__ These have been changed to more closely approximate
	libc++’s usage, mostly because it’s thoughfully designed for use with
	modules and the emerging C++ ABI proposals. Note, however, that many of
	these designations are currently only meaningful as annotations, in
	particular when running compilers that aren’t clang; we’ve tried to note
	those cases. Additionally, some compilers impose unexpected limitations,
	e.g., MSVC will not allow member functions to have different explicitly
	declared visibility than that of the class if the class itself was given an
	explicit visibilitydecorator.

	@remarks __SEEME__ Without support from a static analyzer, there’s no way
	to know if a decorator has been misused, e.g., applying
	`LBAL_VIS_FUNC_EXPORT` to a class. Such misuses may not be immediately
	obvious with a given implementation; additionally, misuses that are not
	problematic now may become problematic in the future when compilers gain
	new capabilities. For this reason, it’s strongly advised to test code
	periodically with a good static analyzer—as if you needed another reason.

	@{
*/

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

	@remarks __SEEME__ gcc makes enum typeinfo visible by default, and then
	throws up warnings if a visibility attribute conflicts with this; for this
	reason, this macro is a no-op under gcc.
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

	@remarks __SEEME__ This only works as described under clang. Under gcc,
	there is currently no `__type_visibility__` attribute, so we fall back to
	using `__visibility__`, which means members inherit the class visibility.
	For this reason, class template members should have explicit decorators, in
	particular if visibility is supposed to differ from that of the class
	itself. MSVC has a similar issue, except that since class templates can’t
	have visibility decorators, the macro is a no-op; once again, members
	require explicit visibility decorators, but now they’re required for every
	member with visibility different from the translation unit default. Failing
	to adhere to this policy may result in exposing too many symbols or not
	enough symbols, depending on the compiler and the compiler options.
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

	@remarks __SEEME__ “inline” in this context means, literally, “defined in
	the header”, and not necessarily just “functions explicitly declared
	`inline`”. libc++ names their equivalent macro `_LIBCPP_HIDE_FROM_ABI`,
	describing what it does, insted of how it’s used. In this case, though, the
	“how it’s used” may be confusing because of the `INLINE` part of the name,
	which may cause users to apply it too narrowly. On the other hand,
	`HIDE_FROM_ABI` is basically what `LBAL_VIS_HIDDEN` does, so going the
	other way would also be confusing. We’re currently going this route and
	relying on documentation to provide clarity.

	@remarks __APIME__ Because of the brittle usage requirements,
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

	@remarks __SEEME__ Note that we could eliminate this macro entirely by
	folding its extra handling into `LBAL_VIS_INLINE_FUNC`, but this would be
	at the cost of some symbol table bloat on certain compilers. This means
	that a given project could choose to alias their own general-purpose inline
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

	@remarks __SEEME__ Pragmatically, this sort of customization point is a bad
	idea. That aside, in practice, this separate designation for
	`LBAL_VIS_FUNC_EXPORT` is only needed by Windows due to how DLLs are
	handled: namely, a function marked with `dllimport` cannot be overloaded
	locally.

	@remarks __FIXME__ Our method for handling this derives from how libc++
	does it: they simply don’t decorate the function declaration for import.
	The method has not been tested, and I haven’t seen examples in the wild of
	other people using it.
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

	@remarks __SEEME__ Pragmatically, this sort of customization point is a bad
	idea. That aside, in practice, this separate designation for
	`LBAL_VIS_FUNC_IMPORT` is only needed by Windows due to how DLLs are
	handled: namely, a function marked with `dllimport` cannot be overloaded
	locally.

	@remarks __FIXME__ Our method for handling this derives from how libc++
	does it: they simply don’t decorate the function declaration for import.
	The method has not been tested, and I haven’t seen examples in the wild of
	other people using it.
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

	@remarks __SEEME__ This is really only necessary when using multiple
	inheritance and targeting MSVS; at least VS2015 Update 3 is required (note
	that Update 2, which actually introduced the feature, had a bug which
	caused it to violate the Standard).

	@remarks __APIME__ How aggravating is it that you can’t decorate the empty
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
