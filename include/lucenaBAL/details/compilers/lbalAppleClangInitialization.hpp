/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalAppleClangInitialization.hpp”
	Copyright © 2019-2024 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See LICENSE.md for details.

	See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/


#pragma once


//	lbal
#include <lucenaBAL/lbalConfig.hpp>
#include <lucenaBAL/details/lbalDetectCompiler.hpp>
#include <lucenaBAL/details/lbalKnownVersions.hpp>


/*------------------------------------------------------------------------------
	Apple clang compiler
*/

#if LBAL_TARGET_COMPILER_APPLE_CLANG
	//	Implement some cross-platform `#pragma` handling
	#define LBAL_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS \
		_Pragma("clang diagnostic ignored \"-Wunknown-pragmas\"")

	#define LBAL_DIAGNOSTIC_PUSH _Pragma("clang diagnostic push")
	#define LBAL_DIAGNOSTIC_POP _Pragma("clang diagnostic pop")

	#define LBAL_PRAGMA(LBAL_PRAGMA_pragma) _Pragma(#LBAL_PRAGMA_pragma)


	//	Implement a cross-platform `#warning` substitute
	#define LBAL_CPP_WARNING(LBAL_CPP_WARNING_message) \
		LBAL_DIAGNOSTIC_PUSH \
		LBAL_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS \
		LBAL_PRAGMA(GCC warning LBAL_CPP_WARNING_message) \
		LBAL_DIAGNOSTIC_POP


	//	Identify processor and characteristics.
	//	Note that AMD64 and x86_64 both trigger each other’s identifiers. We
	//	simply refer to all of them as LBAL_TARGET_CPU_X86_64.
	#if __x86_64__ or __amd64__
		#define LBAL_TARGET_CPU_X86_64 1
		#define LBAL_TARGET_CPU_FAMILY_X86 1
	#elif __i386__
		#define LBAL_TARGET_CPU_X86 1
		#define LBAL_TARGET_CPU_FAMILY_X86 1
	#elif __aarch64__
		#define LBAL_TARGET_CPU_ARM_64 1
		#define LBAL_TARGET_CPU_FAMILY_ARM 1
	#elif __arm__
		#define LBAL_TARGET_CPU_ARM 1
		#define LBAL_TARGET_CPU_FAMILY_ARM 1
	#else
		#error "Processor unknown. Update lbalCompilerSetup.hpp."
	#endif

	#if __LITTLE_ENDIAN__
		#define LBAL_TARGET_RT_LITTLE_ENDIAN 1
	#elif __BIG_ENDIAN__
		#define LBAL_TARGET_RT_BIG_ENDIAN 1
	#endif

	#if __LP64__
		#define LBAL_TARGET_RT_64_BIT 1
	#else
		#define LBAL_TARGET_RT_32_BIT 1
	#endif

	#if __SIZEOF_DOUBLE__ > __SIZEOF_FLOAT__
		#define LBAL_TYPE_DOUBLE_GT_FLOAT 1
	#endif

	#if __SIZEOF_LONG_DOUBLE__ > __SIZEOF_DOUBLE__
		#define LBAL_TYPE_LONG_DOUBLE_GT_DOUBLE 1
	#endif


	//	Identify vector instruction sets, if any.
	#ifdef __SSE__
		#define LBAL_TARGET_VEC_SSE 1
	#endif

	#ifdef __SSE2__
		#define LBAL_TARGET_VEC_SSE2 1
	#endif

	#ifdef __SSE3__
		#define LBAL_TARGET_VEC_SSE3 1
	#endif

	#ifdef __SSE4_1__
		#define LBAL_TARGET_VEC_SSE41 1
	#endif

	#ifdef __SSE4_2__
		#define LBAL_TARGET_VEC_SSE42 1
	#endif

	#ifdef __AVX__
		#define LBAL_TARGET_VEC_AVX 1
	#endif

	#ifdef __AVX2__
		#define LBAL_TARGET_VEC_AVX2 1
	#endif

	//	Currently unused
	#ifdef __AVX512BW__
	#endif

	#ifdef __AVX512CD__
	#endif

	#ifdef __AVX512DQ__
	#endif

	#ifdef __AVX512F__
	#endif

	#ifdef __AVX5124FMAPS__
	#endif

	#ifdef __AVX5124VNNIW__
	#endif

	#ifdef __AVX512IFMA__
	#endif

	#ifdef __AVX512VBMI__
	#endif

	#ifdef __AVX512VPOPCNTDQ__
	#endif

	#ifdef __AVX512VL__
	#endif


	//	Identify executable file fromat.
	#ifdef __MACH__
		#define LBAL_TARGET_RT_MACHO 1
	#else
		#error "No other executable file formats supported for Apple targets"
	#endif


	#if __SIZEOF_LONG_LONG__ == 8
		#define LBAL_TYPE_HAS_INT64 1
	#endif

	#if __SIZEOF_INT128__ == 16
		#define LBAL_TYPE_HAS_INT128 1
	#endif

	#define LBAL_TYPE_EXACT_WIDTH_INTEGERS 1


	//	C99 features

	//	__SEEME__ Apparently, __STDC_VERSION__ only gets set if we’re using the
	//	C compiler, so this test doesn’t work. Since we’re requiring C++11 or
	//	greater, we assume the following C99 features are available.
	#define LBAL_C99_PREPROCESSOR 1


	//	C++11 features

	//	__SEEME__ There is no `LBAL_cpp_version` check since this can be
	//	conditionally disabled. We explicitly disable this if we don’t get a
	//	hit on the SD-6 macro, as otherwise there’s no way to detect it—in
	//	particular, there is no `__has_extension()` value that can detect it.
	#if (__cpp_threadsafe_static_init >= 200806L)
		#define LBAL_CPP11_THREADSAFE_STATIC_INIT __cpp_threadsafe_static_init
	#else
		#define LBAL_CPP11_THREADSAFE_STATIC_INIT 0
	#endif


	//	C++14 features
	//
	//	clang has supported SD-6 macros since 3.4; _Apple LLVM_, however, took
	//	a bit longer to flip the switch in their variant. We cheat a bit here
	//	and take advanatge of our minimum Xcode requirement to know we’ll only
	//	ever deal with Apple LLVM versions with support for SD-6 macros.

	//	As of vanilla clang 8, this is disabled by default in order to avoid
	//	ABI-breaking changes. It’s unclear when it will be enabled by default.
	//
	//	__SEEME__ This explicit test is here for documentation, but could
	//	actually be dropped as the common test will serve just as well.
	#if (__cpp_sized_deallocation >= 201309L)
		#define LBAL_CPP14_SIZED_DEALLOCATION __cpp_sized_deallocation
	#else
		#define LBAL_CPP14_SIZED_DEALLOCATION 0
	#endif


	//	C++17 features
	//
	//	__SEEME__ Apple continues to lag vanilla clang by over a year in odd
	//	ways. As of Apple LLVM 10.0, their clang compiler advertises full C++17
	//	compliance, but a number of feature test macros fail (and then there’s
	//	the real Standard Library deficiencies...):
	//
	//	- __cpp_guaranteed_copy_elision is undefined; testing suggests
	//		the feature is effectively implemented; no tracking
	//	- __cpp_deduction_guides returns an outdated value; no tracking,
	//		as it’s unclear if this needs it
	//	- __cpp_nontype_template_parameter_auto is undefined; testing
	//		suggests the feature is implemented; no tracking

	//	As of vanilla clang 8, this is disabled by default in order to avoid a
	//	defect introduced by the associated proposal (which was intended to
	//	resolve another defect).
	//
	//	__SEEME__ This explicit test is here for documentation, but could
	//	actually be dropped as the common test will serve just as well.
	#if (__cpp_template_template_args >= 201611L)
		#define LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS __cpp_template_template_args
	#else
		#define LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS 0
	#endif


	//	C++20 features

	//	__SEEME__ <https://en.cppreference.com/w/cpp/compiler_support> reports
	//	that this is non-compliant, but that’s not exactly correct. Rather,
	//	Apple selectively disables detection for features it doesn’t want to
	//	advertise support for, typically because they would break ABI and/or
	//	they’ve had the implementation stripped out. Additionally, Apple lags a
	//	bit in updating the token values to reflect updates; it’s not always
	//	clear if this is an oversight or if an update has been held back.
	#define LBAL_CPP20_INTEGRATING_OUR_FEATURE_TEST_MACROS 1L


	//	intrinsic functions
	#define LBAL_HINT_likely(LBAL_expr_) __builtin_expect (LBAL_expr_, true)
	#define LBAL_HINT_unlikely(LBAL_expr_) __builtin_expect (LBAL_expr_, false)


	//	Symbol visibility macros
	#define LBAL_VIS_HIDDEN __attribute__ ((__visibility__("hidden")))

	#define LBAL_VIS_CLASS_EXPORT __attribute__ ((__visibility__("default")))
	#define LBAL_VIS_CLASS_IMPORT __attribute__ ((__visibility__("default")))

	#if __has_attribute (__type_visibility__)
		#define LBAL_VIS_ENUM __attribute__ ((__type_visibility__("default")))

		#define LBAL_VIS_CLASS_TEMPLATE __attribute__ ((__type_visibility__("default")))

		#define LBAL_VIS_EXTERN_CLASS_TEMPLATE_EXPORT __attribute__ ((__visibility__("default")))
		#define LBAL_VIS_EXTERN_CLASS_TEMPLATE_IMPORT __attribute__ ((__visibility__("default")))
	#else
		#define LBAL_VIS_ENUM

		#define LBAL_VIS_CLASS_TEMPLATE __attribute__ ((__visibility__("default")))

		#define LBAL_VIS_EXTERN_CLASS_TEMPLATE_EXPORT
		#define LBAL_VIS_EXTERN_CLASS_TEMPLATE_IMPORT
	#endif

	#define LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_EXPORT
	#define LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_IMPORT

	#define LBAL_VIS_MEMBER_CLASS_TEMPLATE __attribute__ ((__visibility__("hidden")))

	#define LBAL_VIS_MEMBER_FUNCTION_TEMPLATE inline __attribute__ ((__visibility__("hidden")))
		//	__SEEME__ The “inline” declaration is extraneous, but required due to
		//	 a currently unaddressed clang defect (cf., the elusive PR32114).

	#define LBAL_VIS_FUNC_EXPORT __attribute__ ((__visibility__("default")))
	#define LBAL_VIS_FUNC_IMPORT __attribute__ ((__visibility__("default")))

	//	__SEEME__ The first definition is a fallback if it turns out I’ve
	//	misunderstood the requirements on general inline functions.
//	#define LBAL_VIS_INLINE_FUNC LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC
	#define LBAL_VIS_INLINE_FUNC __attribute__ ((__visibility__("hidden")))

	//	__SEEME__ Using the internal_linkage attribute is equivalent to using the
	//	static keyword in C, and is semantically preferrable to inlining.
	//	However, what we -really- want is be able to strip this down to just
	//	LBAL_VIS_HIDDEN, but this requires linker support we don’t have, yet.
	//	See <http://lists.llvm.org/pipermail/cfe-dev/2018-July/058450.html> and
	//	<https://reviews.llvm.org/D49240?id=155185> for details.
	#if __has_attribute (internal_linkage)
		#define LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC __attribute__ ((__visibility__("hidden"), internal_linkage))
	#else
		#define LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC __attribute__ ((__visibility__("hidden"), __always_inline__))
	#endif

	#define LBAL_VIS_OVERLOADABLE_FUNC_EXPORT __attribute__ ((__visibility__("default")))
	#define LBAL_VIS_OVERLOADABLE_FUNC_IMPORT __attribute__ ((__visibility__("default")))

	#define LBAL_VIS_EXTERN_EXPORT
	#define LBAL_VIS_EXTERN_IMPORT

	#define LBAL_VIS_EXCEPTION_EXPORT __attribute__ ((__visibility__("default")))
	#define LBAL_VIS_EXCEPTION_IMPORT __attribute__ ((__visibility__("default")))

	#define LBAL_FUNC_CALL_C(LBAL_func_name_) LBAL_func_name_
	#define LBAL_FUNC_CALL_STD(LBAL_func_name_) LBAL_func_name_
	#define LBAL_FUNC_CALLBACK_C(LBAL_func_name_) (*LBAL_func_name_)
	#define LBAL_FUNC_CALLBACK_STD(LBAL_func_name_) (*LBAL_func_name_)
#else
	#error "lbalAppleClangInitialization.hpp was directly included while using the wrong compiler"
#endif
