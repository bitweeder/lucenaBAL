/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“FeatureSetup.hpp”
	Copyright © 2018-2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

------------------------------------------------------------------------------*/

#pragma once


//	std
#if defined (_MSC_VER) && defined (_WIN32)
	//	We guard inclusion of system headers when using MSVS due to its
	//	noisiness at high warning levels.
	#pragma warning (push, 0)
#endif

#if __has_include (<version>)
	#include <version>
		//	Once this header is universally available, it will take the place
		//	of <ciso646> abuse, providing the same functionality as well as
		//	(eventually) acting as a clearinghouse for SD-6 macros related to
		//	library features.
#else
	#include <ciso646>
		//	In C++, this is a do-nothing header we include just for the side
		//	effects: the Standard Library implementation will be configured
		//	and many assorted compiler-dependent feature detection macros will
		//	be defined.
#endif

#if defined (_MSC_VER) && defined (_WIN32)
	#pragma warning (pop)
#endif


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

	@brief Report 1 or 0 depending on which mutually exclusive macro matches
	the compiler used to build the code.

	@details This takes the place of direct querying, as some compilers are in
	the habit of self-identifying as something else. These are not generally
	useful, as there’s typically another, better mechanism for solving whatever
	this is meant to solve, but they’re here for when nothing else will do.
	Note that if you also need version information, you’ll have to resort to
	direct querying, though it may still sensible to filter first on these for
	the aforementioned reason.

	__SEEME__ These are blunt instruments. In particular, there‘s no
	differentiation between frontened (e.g., c1xx or clang) and backend
	(e.g., c2 or llvm). In practice, this mattered more when c2/clang was a
	thing, but is moot now. We’ll consider revisiting if the extra granularity
	turns out to be useful

	@{
*/

/**
	@def LBAL_TARGET_COMPILER_CLANG
	@brief The compiler being used is llvm/clang.
	@details More information is available from
	[the llvm project](https://clang.llvm.org/).
*/
#ifndef LBAL_TARGET_COMPILER_CLANG
	#define LBAL_TARGET_COMPILER_CLANG 0
#endif

/**
	@def LBAL_TARGET_COMPILER_GCC
	@brief The compiler being used is gcc.
	@details More information is available from
	[the gcc project](https://gcc.gnu.org/).
*/
#ifndef LBAL_TARGET_COMPILER_GCC
	#define LBAL_TARGET_COMPILER_GCC 0
#endif

/**
	@def LBAL_TARGET_COMPILER_MSVC
	@brief The compiler being used is MSVC.
	@details More information is available from
	[Microsoft](https://visualstudio.microsoft.com/).
*/
#ifndef LBAL_TARGET_COMPILER_MSVC
	#define LBAL_TARGET_COMPILER_MSVC 0
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

	@remarks __SEEME__ Some compilers, notably older MSVC versions, make select
	language features from the Draft Standard available as extensions without
	providing an opt-out, or in some cases, a way to cleanly detect them. Since
	this state of affairs mostly cleared up in the C++14 era, and we only
	officially support C++17 and later dialects, we don’t go out of our way to
	expose such features. We do, however, note such occurrences, and may change
	this policy in the future.

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
	- [200809L](https://wg21.link/N2761) __PDF__
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
	- [201907L](https://wg21.link/p1331r2) __PDF__

	@remarks `__cpp_constexpr` has at least 4 values associated with it, each
	from a different proposal.
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
	- [201907L](https://wg21.link/p1331r2) __PDF__

	@remarks `__cpp_constexpr` has at least 4 values associated with it, each
	from a different proposal.
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
	@details Equivalent SD-6 macro: `__cpp_generic_lambdas`
	- [201304L](https://wg21.link/n3649)
*/
#ifndef LBAL_CPP14_GENERIC_LAMBDAS
	#define LBAL_CPP14_GENERIC_LAMBDAS 0
#endif

/**
	@def LBAL_CPP14_INIT_CAPTURES
	@brief Generalized Lambda-capture changes
	@details Equivalent SD-6 macro: `__cpp_init_captures`
	- [201304L](https://wg21.link/n3648)
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
	- [201304L](https://wg21.link/n3778)

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
	- [201907L](https://wg21.link/p1331r2) __PDF__

	@remarks `__cpp_constexpr` has at least 4 values associated with it, each
	from a different proposal.
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
	@details Equivalent SD-6 macro: `__cpp_nontype_template_args`
	- [201411L](https://wg21.link/n4268)
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
	@name LBAL_CPP2A

	@brief Identify language features specific to the C++2a draft standard

	@details Support across compilers for C++2a features is unsurprisingly
	inconsistent, and is one of the fundamental reasons why lucenaBAL exists.
	These will be updated regularly as the Standard develops.

	Note that a very large number of features do not have SD-6 macros, so we
	often provide our own tokens. Should an official macro be created, we will
	synchronize with it and deprecate the proprietary one.

	@remarks __SEEME__ A proposal to standardize SD-6 macros was accepted for
	C++2a, and is updated regularly to track new features, but it tends to lag
	the adoption rate. Additionally, a lot of proposed new language and library
	features—and fixes—don’t suggest corresponding SD-6 macros, which can make
	identifying availability more challenging than it needs to be. Taken
	together, many of these are either placeholders awaiting testing or depend
	on compiler version-differentiated activation.

	@remarks __APIME__ These will eventually all be renamed, most likely to
	use the `LBAL_CPP20` prefix, once the Draft Standard finalizes. Once that
	happens, the original names will persist for a while as aliases for the new
	ones.

	@{
*/

/**
	@def LBAL_CPP2A_AGGREGATE_PAREN_INIT
	@brief Allow aggregate initialization from parentheses as well as braces.
	@details Equivalent SD-6 macro: `__cpp_aggregate_paren_init`
	- [201902L](https://wg21.link/p0960r3)

	@remarks Note that paren initialization allows narrowing conversions, as
	usual.
*/
#ifndef LBAL_CPP2A_AGGREGATE_PAREN_INIT
	#define LBAL_CPP2A_AGGREGATE_PAREN_INIT 0
#endif

/**
	@def LBAL_CPP2A_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS

	Equivalent SD-6 macro: none
	- [default](https://wg21.link/p0409r2)
*/
#ifndef LBAL_CPP2A_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS
	#define LBAL_CPP2A_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS 0
#endif

/**
	@def LBAL_CPP2A_ATTRIBUTE_LIKELY

	Equivalent SD-6 test: `__has_cpp_attribute(likely)`
	- [201803L](https://wg21.link/p0479r5)
*/
#ifndef LBAL_CPP2A_ATTRIBUTE_LIKELY
	#define LBAL_CPP2A_ATTRIBUTE_LIKELY 0
#endif

/**
	@def LBAL_CPP2A_ATTRIBUTE_NODISCARD_EXPANDED
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
#ifndef LBAL_CPP2A_ATTRIBUTE_NODISCARD_EXPANDED
	#define LBAL_CPP2A_ATTRIBUTE_NODISCARD_EXPANDED 0
#endif

/**
	@def LBAL_CPP2A_ATTRIBUTE_UNLIKELY

	Equivalent SD-6 test: `__has_cpp_attribute(unlikely)`
	- [201803L](https://wg21.link/p0479r5)
*/
#ifndef LBAL_CPP2A_ATTRIBUTE_UNLIKELY
	#define LBAL_CPP2A_ATTRIBUTE_UNLIKELY 0
#endif

/**
	@def LBAL_CPP2A_ATTRIBUTES_LIKELY_AND_UNLIKELY
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
#ifndef LBAL_CPP2A_ATTRIBUTES_LIKELY_AND_UNLIKELY
	#define LBAL_CPP2A_ATTRIBUTES_LIKELY_AND_UNLIKELY \
		((LBAL_CPP2A_ATTRIBUTE_LIKELY != 0) && (LBAL_CPP2A_ATTRIBUTE_UNLIKELY != 0))
#endif

/**
	@def LBAL_CPP2A_ATTRIBUTE_NO_UNIQUE_ADDRESS

	Equivalent SD-6 macro: `__has_cpp_attribute(no_unique_address)`
	- [201803L](https://wg21.link/p0840r2)
*/
#ifndef LBAL_CPP2A_ATTRIBUTE_NO_UNIQUE_ADDRESS
	#define LBAL_CPP2A_ATTRIBUTE_NO_UNIQUE_ADDRESS 0
#endif

/**
	@def LBAL_CPP2A_CHAR8_T
	@brief Add `char8_t` as a UTF-8 equivalent for `char16_t` and `char32_t`.
	@details Equivalent SD-6 macro: `__cpp_char8_t`
	- [201811L](https://wg21.link/p0482r6)
*/
#ifndef LBAL_CPP2A_CHAR8_T
	#define LBAL_CPP2A_CHAR8_T 0
#endif

/**
	@def LBAL_CPP2A_CONCEPTS

	Equivalent (SD-6) macro: `__cpp_concepts`
	- [201806L](https://wg21.link/p0734r0) __PDF__

	@remarks __SEEME__ The current SD-6 revision does not actually define this
	token, though the proposal that was voted into the Standard _does_. We
	assume it’s an oversight; there are several known ones, and it’s one of the
	motivators for the coming SD-6 review. The only available Concepts
	implementations do honor the token, so we rely on it for detection.
*/
#ifndef LBAL_CPP2A_CONCEPTS
	#define LBAL_CPP2A_CONCEPTS 0
#endif

/**
	@def LBAL_CPP2A_CONDITIONAL_EXPLICIT
	Aka, `explicit (bool)`; allows simplification of templated constructors
	that have the potential to incorrectly convert their arguments.

	Equivalent SD-6 macro: `__cpp_conditional_explicit`
	- [201806L](https://wg21.link/p0892r2)
*/
#ifndef LBAL_CPP2A_CONDITIONAL_EXPLICIT
	#define LBAL_CPP2A_CONDITIONAL_EXPLICIT 0
#endif

/**
	@def LBAL_CPP2A_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS

	Equivalent SD-6 macro: none
	- [default](https://wg21.link/p0704r1)
*/
#ifndef LBAL_CPP2A_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS
	#define LBAL_CPP2A_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS 0
#endif

/**
	@def LBAL_CPP2A_CONSTEXPR_DYNAMIC_ALLOC
	@brief Language support for variable-sized containers suitable for use in
	constexpr computations.
	@details Equivalent SD-6 macro: `__cpp_constexpr_dynamic_alloc`
	- [201907L](https://wg21.link/p0784r7)

	@remarks AKA, “More constexpr containers”.
*/
#ifndef LBAL_CPP2A_CONSTEXPR_DYNAMIC_ALLOC
	#define LBAL_CPP2A_CONSTEXPR_DYNAMIC_ALLOC 0
#endif

/**
	@def LBAL_CPP2A_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION
	@brief Address an inconsistency in the lambda specification
	@details Equivalent SD-6 macro: `__cpp_constexpr`. This token corresponds
	to the `201907L` variant, but it will have the value of the latest
	supported variant, or `0` if this variant is not supported.
	- [200704L](https://wg21.link/N2235) __PDF__
	- [201304L](https://wg21.link/n3652)
	- [201603L](https://wg21.link/p0170r1) __PDF__
	- [201907L](https://wg21.link/p1331r2) __PDF__

	@remarks `__cpp_constexpr` has at least 4 values associated with it, each
	from a different proposal.
*/
#ifndef LBAL_CPP2A_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION
	#define LBAL_CPP2A_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION 0
#endif

/**
	@def LBAL_CPP2A_CONSTEXPR_VIRTUAL_FUNCTION
	@details Equivalent SD-6 macro: none
	- [default](https://wg21.link/p1064r0)
*/
#ifndef LBAL_CPP2A_CONSTEXPR_VIRTUAL_FUNCTION
	#define LBAL_CPP2A_CONSTEXPR_VIRTUAL_FUNCTION 0
#endif

/**
	@def LBAL_CPP2A_CONSTINIT
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
#ifndef LBAL_CPP2A_CONSTINIT
	#define LBAL_CPP2A_CONSTINIT 0
#endif

/**
	@def LBAL_CPP2A_COROUTINES
	@brief Add necessary language support for the `<coroutine>` library feature
	@details Equivalent SD-6 macro: `__cpp_coroutines`
	- [201902L](https://wg21.link/p0912r1)

	@remarks Technically, the proposal this is from only directs that the
	Coroutines TS be merged into the Standard. For reference the latest draft
	is [n4775](https://wg21.link/n4775) __PDF__.
*/
#ifndef LBAL_CPP2A_COROUTINES
	#define LBAL_CPP2A_COROUTINES 0
#endif

/**
	@def LBAL_CPP2A_DEDUCTION_GUIDES_FOR_AGGREGATES
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
#ifndef LBAL_CPP2A_DEDUCTION_GUIDES_FOR_AGGREGATES
	#define LBAL_CPP2A_DEDUCTION_GUIDES_FOR_AGGREGATES 0
#endif

/**
	@def LBAL_CPP2A_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS
	@details Equivalent SD-6 macro: none
	- [default](https://wg21.link/p0624r2) __PDF__
*/
#ifndef LBAL_CPP2A_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS
	#define LBAL_CPP2A_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS 0
#endif

/**
	@def LBAL_CPP2A_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS

	Equivalent SD-6 macro: none
	- [default](https://wg21.link/p0683r1)
*/
#ifndef LBAL_CPP2A_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS
	#define LBAL_CPP2A_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS 0
#endif

/**
	@def LBAL_CPP2A_DESIGNATED_INITIALIZERS

	Equivalent SD-6 macro: none
	- [default](https://wg21.link/p0329r4) __PDF__
*/
#ifndef LBAL_CPP2A_DESIGNATED_INITIALIZERS
	#define LBAL_CPP2A_DESIGNATED_INITIALIZERS 0
#endif

/**
	@def LBAL_CPP2A_DESTROYING_DELETE
	@brief Efficient sized delete for variable sized classes
	@details Equivalent SD-6 macro: `__cpp_impl_destroying_delete`
	- [201806L](https://wg21.link/p0722r3)
*/
#ifndef LBAL_CPP2A_DESTROYING_DELETE
	#define LBAL_CPP2A_DESTROYING_DELETE 0
#endif

/**
	@def LBAL_CPP2A_INIT_STATEMENTS_FOR_RANGE_BASED_FOR

	Equivalent SD-6 macro: none
	- [default](https://wg21.link/p0614r1)
*/
#ifndef LBAL_CPP2A_INIT_STATEMENTS_FOR_RANGE_BASED_FOR
	#define LBAL_CPP2A_INIT_STATEMENTS_FOR_RANGE_BASED_FOR 0
#endif

/**
	@def LBAL_CPP2A_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION

	Equivalent SD-6 macro: none
	- [default](https://wg21.link/p0702r1)
*/
#ifndef LBAL_CPP2A_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION
	#define LBAL_CPP2A_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION	0
#endif

/**
	@def LBAL_CPP2A_INTEGRATING_OUR_FEATURE_TEST_MACROS
	@brief Integrate universal feature test macros into the Standard
	@details Equivalent SD-6 macro: none (ironically)
	- [default](https://wg21.link/p0941r2)

	@remarks It appears this is only here to get Microsoft to support SD-6, as
	the other major compilers de facto meet the requirement.
*/
#ifndef LBAL_CPP2A_INTEGRATING_OUR_FEATURE_TEST_MACROS
	#define LBAL_CPP2A_INTEGRATING_OUR_FEATURE_TEST_MACROS 0
#endif

/**
	@def LBAL_CPP2A_MODULES
	@brief Incorporate modules
	@details Equivalent SD-6 macro: `__cpp_modules`
	- [201907L](https://wg21.link/P1103R3) __PDF__
	- [201907L](https://wg21.link/p1811r0)
*/
#ifndef LBAL_CPP2A_MODULES
	#define LBAL_CPP2A_MODULES 0
#endif

/**
	@def LBAL_CPP2A_NONTYPE_TEMPLATE_PARAMETER_CLASS
	@brief Class Types in Non-Type Template Parameters
	@details Equivalent SD-6 macro: `__cpp_nontype_template_parameter_class`
	- [201806L](https://wg21.link/p0732r2) __PDF__
*/
#ifndef LBAL_CPP2A_NONTYPE_TEMPLATE_PARAMETER_CLASS
	#define LBAL_CPP2A_NONTYPE_TEMPLATE_PARAMETER_CLASS 0
#endif

///@cond LBAL_INTERNAL
//	__APIME__ The SD-6 macro for this changed, so we renamed the token.
#ifndef LBAL_CPP2A_CLASS_TYPES_AS_NON_TYPE_TEMPLATE_PARAMETERS
	#define LBAL_CPP2A_CLASS_TYPES_AS_NON_TYPE_TEMPLATE_PARAMETERS LBAL_CPP2A_NONTYPE_TEMPLATE_PARAMETER_CLASS
#endif
///@endcond

/**
	@def LBAL_CPP2A_PACK_EXPANSION_IN_LAMBDA_INIT_CAPTURE

	Equivalent SD-6 macro: none
	- [default](https://wg21.link/p0780r2)
*/
#ifndef LBAL_CPP2A_PACK_EXPANSION_IN_LAMBDA_INIT_CAPTURE
	#define LBAL_CPP2A_PACK_EXPANSION_IN_LAMBDA_INIT_CAPTURE 0
#endif

/**
	@def LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR
	@brief This is the original three-way comparison operator
	@details Equivalent SD-6 macro: `__cpp_impl_three_way_comparison`. This
	token corresponds to the `201711L` variant, but it will have a value of
	`201907L` if that variant is available.
	- [201711L](https://wg21.link/p0515r3) __PDF__
	- [201711L](https://wg21.link/p0768r1) __PDF__
	- [201907L](https://wg21.link/p1185r2)
	- [201907L](https://wg21.link/p1186r3)
	- [201907L](https://wg21.link/p1630r1)
*/
#ifndef LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR
	#define LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR 0
#endif

/**
	@def LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR_TUNEUP
	@brief This is the updated three-way comparison operator
	@details Equivalent SD-6 macro: `__cpp_impl_three_way_comparison`. This
	token corresponds to the `201907L` variant; it will only be set to a
	non-`0` value if that variant is available.
	- [201711L](https://wg21.link/p0515r3) __PDF__
	- [201711L](https://wg21.link/p0768r1) __PDF__
	- [201907L](https://wg21.link/p1185r2)
	- [201907L](https://wg21.link/p1186r3)
	- [201907L](https://wg21.link/p1630r1)
*/
#ifndef LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR_TUNEUP
	#define LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR_TUNEUP 0
#endif

/**
	@def LBAL_CPP2A_TEMPLATE_PARAMETER_LIST_FOR_GENERIC_LAMBDAS

	Equivalent SD-6 macro: none
	- [default](https://wg21.link/p0428r2) __PDF__
*/
#ifndef LBAL_CPP2A_TEMPLATE_PARAMETER_LIST_FOR_GENERIC_LAMBDAS
	#define LBAL_CPP2A_TEMPLATE_PARAMETER_LIST_FOR_GENERIC_LAMBDAS 0
#endif

/**
	@def LBAL_CPP2A_TYPENAME_OPTIONAL

	Equivalent SD-6 macro: none
	- [default](https://wg21.link/p0634r2)
*/
#ifndef LBAL_CPP2A_TYPENAME_OPTIONAL
	#define LBAL_CPP2A_TYPENAME_OPTIONAL 0
#endif

/**
	@def LBAL_CPP2A_USING_ENUM
	@brief Specify using aliases for enums
	@details Equivalent SD-6 macro: `__cpp_using_enum`
	- [201907L](https://wg21.link/p1099r5)
*/
#ifndef LBAL_CPP2A_USING_ENUM
	#define LBAL_CPP2A_USING_ENUM 0
#endif

/**
	@def LBAL_CPP2A_VA_OPT
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
#ifndef LBAL_CPP2A_VA_OPT
	#define LBAL_CPP2A_VA_OPT 0
#endif

///	@}	LBAL_CPP2A

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
	__SEEME__ Only MSVS is known to have problems with this, and it appears
	progress is finally being made to fully address it, at which point this
	flag will be retired. Note that if support requires having a particular
	compiler switch set to get compatibility, setting the switch will
	likely be mandated.
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

	@{
*/

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
	@def LBAL_LIBCPP17_ADRESSOF_CONSTEXPR
	@brief `std::addressof` should be `constexpr`, as per defect report
	@details Equivalent SD-6 macro: `__cpp_lib_addressof_constexpr`
	- [201603L](https://wg21.link/LWG2296)
*/
#ifndef LBAL_LIBCPP17_ADRESSOF_CONSTEXPR
	#define LBAL_LIBCPP17_ADRESSOF_CONSTEXPR 0
#endif

/**
	@def LBAL_LIBCPP17_ANY
	@brief `<any>` components from Library Fundamentals V1 TS
	@details Equivalent SD-6 macro: `__cpp_lib_any`
	- [201603L](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0220r1.html)

	@remarks __APIME__ We do not track experimental versions of this.
*/
#ifndef LBAL_LIBCPP17_ANY
	#define LBAL_LIBCPP17_ANY 0
#endif

/**
	@def LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS

	Equivalent SD-6 macro: `__cpp_lib_to_chars`

	https://wg21.link/p0067r5
	https://wg21.link/p0682r1

	@remarks __SEEME__ This got weird since the functions were moved to their
	own header and their signatures were altered, post-Standardization, all as
	part of a Defect Report resolution.
*/
#ifndef LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS
	#define LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS 0
#endif

/**
	@def LBAL_LIBCPP17_EXECUTION
	By itself, this token does not measure compliance with the referenced
	Working Group paper; use LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS.

	Equivalent SD-6 macro: `__cpp_lib_execution`

	https://wg21.link/p0024r2

	@remarks __APIME__ We neither track nor use experimental versions of this.
*/
#ifndef LBAL_LIBCPP17_EXECUTION
	#define LBAL_LIBCPP17_EXECUTION 0
#endif

/**
	@def LBAL_LIBCPP17_FILESYSTEM

	Equivalent SD-6 macro: `__cpp_lib_filesystem`

	@remarks __SEEME__ Full implementation missing on Apple platforms prior to
	macOS 10.15.
*/
#ifndef LBAL_LIBCPP17_FILESYSTEM
	#define LBAL_LIBCPP17_FILESYSTEM 0
#endif

/**
	@def LBAL_LIBCPP17_FILESYSTEM_EXP

	Equivalent SD-6 macro: `__cpp_lib_experimental_filesystem`

	@remarks __SEEME__ The experimental version differs in many ways from the
	final version, but it’s all that is offered until gcc 8 and clang 7.
*/
#ifndef LBAL_LIBCPP17_FILESYSTEM_EXP
	#define LBAL_LIBCPP17_FILESYSTEM_EXP 0
#endif

/**
	@def LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE
	Provides relevant cache line sizes for construction and destruction.

	Equivalent SD-6 macro: `__cpp_lib_thread_hardware_interference_size`

	https://wg21.link/p0154r1

	@remarks __APIME__ We neither track nor use experimental versions of this.
*/
#ifndef LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE
	#define LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE 0
#endif

/**
	@def LBAL_LIBCPP17_LAUNDER
	Replacement of class objects containing reference members.

	Equivalent SD-6 macro: `__cpp_lib_launder`

	https://wg21.link/p0137r1

	@remarks __APIME__ We neither track nor use experimental versions of this.
*/
#ifndef LBAL_LIBCPP17_LAUNDER
	#define LBAL_LIBCPP17_LAUNDER 0
#endif

/**
	@def LBAL_LIBCPP17_OPTIONAL

	Equivalent SD-6 macro: `__cpp_lib_optional`

	@remarks __APIME__ Only tracked because of incomplete implementations on
	older Apple platforms.

	@remarks __APIME__ We neither track nor use experimental versions of this.
*/
#ifndef LBAL_LIBCPP17_OPTIONAL
	#define LBAL_LIBCPP17_OPTIONAL 0
#endif

/**
	@def LBAL_LIBCPP17_PARALLEL_ALGORITHM

	Equivalent SD-6 macro: `__cpp_lib_parallel_algorithm`

	https://wg21.link/p0024r2

	This is set in this header. No wrapper is provided; the
	functionality would be good to have, but challenging and messy to
	implement effectively. Note that by itself, this macro does not
	measure compliance with the Working Group paper; for that, use
	LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS.

	@remarks __APIME__ We neither track nor use experimental versions of this.
*/
#ifndef LBAL_LIBCPP17_PARALLEL_ALGORITHM
	#define LBAL_LIBCPP17_PARALLEL_ALGORITHM 0
#endif

/**
	@def LBAL_LIBCPP17_SPLICING_MAPS_AND_SETS

	Equivalent SD-6 macro: `__cpp_lib_node_extract`

	http://wg21.link/p0083r3
	
	@remarks __APIME__ We neither track nor use experimental versions of this.
*/
#ifndef LBAL_LIBCPP17_SPLICING_MAPS_AND_SETS
	#define LBAL_LIBCPP17_SPLICING_MAPS_AND_SETS 0
#endif

/**
	LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS
 	This token tracks compliance with the Standard as it  relates to
 	implementing the referenced Working Group paper; there is no correspoding
 	SD-6 macro, or rather, there are -two- relevant macros which each track the
 	different features required for compliance. We actually track both of
 	those, as well as this meta-feature, separately. As such, this token
 	represents an aggregate condition: if both `LBAL_LIBCPP17_EXECUTION` and
 	`LBAL_LIBCPP17_PARALLEL_ALGORITHM` indicate compliance, this gets set to
 	`1`; otherwise, it’s set to `0`.

	Equivalent SD-6 macro: none

	https://wg21.link/p0024r2

	@remarks __APIME__ We neither track nor use experimental versions of this,
	partly because the Draft versions tracked a different set of features, in
	different places, which were refactored/replaced
*/
#ifndef LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS
	#define LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS 0
#endif

/**
	@def LBAL_LIBCPP17_VARIANT

	Equivalent SD-6 macro: `__cpp_lib_variant`

	@remarks __APIME__ Only tracked because of incomplete implementations on
	older Apple platforms.

	@remarks __APIME__ We neither track nor use experimental versions of this.
*/
#ifndef LBAL_LIBCPP17_VARIANT
	#define LBAL_LIBCPP17_VARIANT 0
#endif

///	@}	LBAL_LIBCPP17

/**
	@name LBAL_LIBCPP2A
	@brief These are all taken from features that have been incorporated into
	the draft Standard currently called C++2a and likely to become C++20.

	@{
*/

/**
	@def LBAL_LIBCPP2A_BIT_CAST

	Equivalent SD-6 macro: `__cpp_lib_bit_cast`

	https://wg21.link/p0476r2
*/
#ifndef LBAL_LIBCPP2A_BIT_CAST
	#define LBAL_LIBCPP2A_BIT_CAST 0
#endif

/**
	@def LBAL_LIBCPP2A_CALENDAR_AND_TIMEZONE

	Equivalent SD-6 macro: none

	https://wg21.link/p0355r7
*/
#ifndef LBAL_LIBCPP2A_CALENDAR_AND_TIMEZONE
	#define LBAL_LIBCPP2A_CALENDAR_AND_TIMEZONE 0
#endif

/**
	@def LBAL_LIBCPP2A_CONCEPT_LIBRARY

	Equivalent SD-6 macro: `__cpp_lib_concepts`

	https://wg21.link/p0898r3 __PDF__
*/
#ifndef LBAL_LIBCPP2A_CONCEPT_LIBRARY
	#define LBAL_LIBCPP2A_CONCEPT_LIBRARY 0
#endif

/**
	@def LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP

	Equivalent SD-6 macro: `__cpp_lib_experimental_concepts`

	https://wg21.link/p0898r3 __PDF__
*/
#ifndef LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP
	#define LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP 0
#endif

/**
	@def LBAL_LIBCPP2A_CONSTEXPR_FOR_ALGORITHM_AND_UTILITY

	Equivalent SD-6 macro: none

	https://wg21.link/p0202r3
*/
#ifndef LBAL_LIBCPP2A_CONSTEXPR_FOR_ALGORITHM_AND_UTILITY
	#define LBAL_LIBCPP2A_CONSTEXPR_FOR_ALGORITHM_AND_UTILITY 0
#endif

/**
	@def LBAL_LIBCPP2A_COROUTINES

	Equivalent SD-6 macro: `__cpp_coroutines`

	https://wg21.link/n4736 __PDF__
	https://wg21.link/n4760 __PDF__
	https://wg21.link/p0912r2

	@remarks Note that `<coroutine>` requires language support.

	@remarks This does not currently have its own SD-6 macro. We use the
	value of the language feature macro as a proxy for library support.

	@remarks __SEEME__ Confusingly, [n4736](https://wg21.link/n4736) __PDF__
	was voted into the Standard, but [n4760](https://wg21.link/n4760) __PDF__
	is the fixed version of it.
*/
#ifndef LBAL_LIBCPP2A_COROUTINES
	#define LBAL_LIBCPP2A_COROUTINES 0
#endif

/**
	@def LBAL_LIBCPP2A_COROUTINES_EXP

	Equivalent SD-6 macro: `__cpp_coroutines`

	https://wg21.link/n4736 __PDF__
	https://wg21.link/n4760 __PDF__
	https://wg21.link/p0912r2

	@remarks Note that `<coroutine>` requires language support.

	@remarks This does not currently have its own SD-6 macro. We use the
	value of the language feature macro as a proxy for library support.

	@remarks __SEEME__ Confusingly, [n4736](https://wg21.link/n4736) __PDF__
	was voted into the Standard, but [n4760](https://wg21.link/n4760) __PDF__
	is the fixed version of it.
*/
#ifndef LBAL_LIBCPP2A_COROUTINES_EXP
	#define LBAL_LIBCPP2A_COROUTINES_EXP 0
#endif

/**
	@def LBAL_LIBCPP2A_DESTROYING_DELETE

	Equivalent SD-6 macro: `__cpp_lib_destroying_delete`

	https://wg21.link/p0722r3
*/
#ifndef LBAL_LIBCPP2A_DESTROYING_DELETE
	#define LBAL_LIBCPP2A_DESTROYING_DELETE 0
#endif

/**
	@def LBAL_LIBCPP2A_EXTENDING_MAKE_SHARED_TO_SUPPORT_ARRAYS

	Equivalent SD-6 macro: none

	https://wg21.link/p0674r1
*/
#ifndef LBAL_LIBCPP2A_EXTENDING_MAKE_SHARED_TO_SUPPORT_ARRAYS
	#define LBAL_LIBCPP2A_EXTENDING_MAKE_SHARED_TO_SUPPORT_ARRAYS 0
#endif


/**
	@def LBAL_LIBCPP2A_FLOATING_POINT_ATOMIC

	Equivalent SD-6 macro: none

	https://wg21.link/p0020r6
*/
#ifndef LBAL_LIBCPP2A_FLOATING_POINT_ATOMIC
	#define LBAL_LIBCPP2A_FLOATING_POINT_ATOMIC 0
#endif

/**
	@def LBAL_LIBCPP2A_LIST_REMOVE_RETURN_TYPE
	This represents changes to some member functions in `<list>` and
	`<forward_list>`.

	Equivalent SD-6 macro: `__cpp_lib_list_remove_return_type`

	https://wg21.link/p0646r1 __PDF__
*/
#ifndef LBAL_LIBCPP2A_LIST_REMOVE_RETURN_TYPE
	#define LBAL_LIBCPP2A_LIST_REMOVE_RETURN_TYPE 0
#endif

/**
	@def LBAL_LIBCPP2A_LIST_REMOVE_RETURN_TYPE_EXP
	This represents changes to some member functions in `<list>` and
	`<forward_list>`.

	Equivalent SD-6 macro: `__cpp_lib_experimental_list_remove_return_type`

	https://wg21.link/p0646r1 __PDF__
*/
#ifndef LBAL_LIBCPP2A_LIST_REMOVE_RETURN_TYPE_EXP
	#define LBAL_LIBCPP2A_LIST_REMOVE_RETURN_TYPE_EXP 0
#endif

/**
	@def LBAL_LIBCPP2A_MORE_CONSTEXPR_FOR_COMPLEX
 	This represents changes to some function signatures in `<complex>`.

	Equivalent SD-6 macro: `__cpp_lib_constexpr_complex`

	https://wg21.link/p0415r1
*/
#ifndef LBAL_LIBCPP2A_MORE_CONSTEXPR_FOR_COMPLEX
	#define LBAL_LIBCPP2A_MORE_CONSTEXPR_FOR_COMPLEX 0
#endif

/**
	@def LBAL_LIBCPP2A_MORE_CONSTEXPR_FOR_COMPLEX_EXP
 	This represents changes to some function signatures in `<complex>`.

	Equivalent SD-6 macro: `__cpp_lib_experimental_constexpr_complex`

	https://wg21.link/p0415r1
*/
#ifndef LBAL_LIBCPP2A_MORE_CONSTEXPR_FOR_COMPLEX_EXP
	#define LBAL_LIBCPP2A_MORE_CONSTEXPR_FOR_COMPLEX_EXP 0
#endif

/**
	@def LBAL_LIBCPP2A_SPAN

	Equivalent SD-6 macro: none

	https://wg21.link/p0122r7 __PDF__
*/
#ifndef LBAL_LIBCPP2A_SPAN
	#define LBAL_LIBCPP2A_SPAN 0
#endif

/**
	@def LBAL_LIBCPP2A_STD_ATOMIC_REF

	Equivalent SD-6 macro: `__cpp_lib_atomic_ref`

	https://wg21.link/p0019r8
*/
#ifndef LBAL_LIBCPP2A_STD_ATOMIC_REF
	#define LBAL_LIBCPP2A_STD_ATOMIC_REF 0
#endif

/**
	@def LBAL_LIBCPP2A_STD_ENDIAN

	Equivalent SD-6 macro: none

	https://wg21.link/p0463r1
*/
#ifndef LBAL_LIBCPP2A_STD_ENDIAN
	#define LBAL_LIBCPP2A_STD_ENDIAN 0
#endif

/**
	@def LBAL_LIBCPP2A_STD_REMOVE_CVREF

	Equivalent SD-6 macro: none

	https://wg21.link/p0550r2 __PDF__
*/
#ifndef LBAL_LIBCPP2A_STD_REMOVE_CVREF
	#define LBAL_LIBCPP2A_STD_REMOVE_CVREF 0
#endif

/**
	@def LBAL_LIBCPP2A_STRING_PREFIX_AND_SUFFIX_CHECKING

	Equivalent SD-6 macro: none

	https://wg21.link/p0457r2
*/
#ifndef LBAL_LIBCPP2A_STRING_PREFIX_AND_SUFFIX_CHECKING
	#define LBAL_LIBCPP2A_STRING_PREFIX_AND_SUFFIX_CHECKING 0
#endif

/**
	@def LBAL_LIBCPP2A_SYNCHRONIZED_BUFFERED_OSTREAM

	Equivalent SD-6 macro: `__cpp_lib_syncstream`

	https://wg21.link/p0053r7 __PDF__
*/
#ifndef LBAL_LIBCPP2A_SYNCHRONIZED_BUFFERED_OSTREAM
	#define LBAL_LIBCPP2A_SYNCHRONIZED_BUFFERED_OSTREAM 0
#endif

/**
	@def LBAL_LIBCPP2A_THREE_WAY_COMPARISON_OPERATOR_SUPPORT_COMPARE

	Equivalent SD-6 macro: `__cpp_lib_three_way_comparison`

	https://wg21.link/p0515r3 __PDF__

	@remarks `<compare>` is interdependent with the `operator <=>` language
	feature.
*/
#ifndef LBAL_LIBCPP2A_THREE_WAY_COMPARISON_OPERATOR_SUPPORT_COMPARE
	#define LBAL_LIBCPP2A_THREE_WAY_COMPARISON_OPERATOR_SUPPORT_COMPARE 0
#endif

/**
	@def LBAL_LIBCPP2A_TYPE_IDENTITY

	Equivalent SD-6 macro: none

	https://wg21.link/p0887r1 __PDF__
*/
#ifndef LBAL_LIBCPP2A_TYPE_IDENTITY
	#define LBAL_LIBCPP2A_TYPE_IDENTITY 0
#endif

/**
	@def LBAL_LIBCPP2A_UTILITY_TO_CONVERT_A_POINTER_TO_A_RAW_POINTER

	Equivalent SD-6 macro: none

	https://wg21.link/p0653r2
*/
#ifndef LBAL_LIBCPP2A_UTILITY_TO_CONVERT_A_POINTER_TO_A_RAW_POINTER
	#define LBAL_LIBCPP2A_UTILITY_TO_CONVERT_A_POINTER_TO_A_RAW_POINTER 0
#endif

/**
	@def LBAL_LIBCPP2A_VERSION

	Equivalent SD-6 macro: none

	This identifies whether `<version>` is present and include-able given the
	current C++ Standard dialect in use (some implementations may choose to
	back-port <version> to earlier releases).

	Note that unlike `<version>`, lucenaBAL tracks “correct”, functioning
	implementations only. So, for example, Xcode’s false positives for `<any>`
	and friends won’t be reported as support for the library feature. For this
	reason, it is recommended to _always_ favor the lucenaBAL reporting of a
	given feature’s availability, even when `<version>` is available.

	https://wg21.link/p0754r2 __PDF__
*/
#ifndef LBAL_LIBCPP2A_VERSION
	#define LBAL_LIBCPP2A_VERSION 0
#endif

///	@}	LBAL_LIBCPP2A

/**
	@name LBAL_LIBCPPTS

	@brief C++ Technical Specifications that have not (yet?) been Standardized.

	@details These are typically very far along and likely to clear
	the bar. Generally, these will eventually be aliased—and then moved—into
	LBAL_LIBCPP20, LBAL_LIBCPP23, etc.

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

///	@}	LBAL_LIBCPP2A

///	@}	lbal_library

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
