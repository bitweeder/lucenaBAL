/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalGCCInitialization.hpp”
	Copyright © 2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/


#pragma once


//	lbal
#include <lucenaBAL/details/lbalConfig.hpp>
#include <lucenaBAL/details/lbalKnownVersions.hpp>
#include <lucenaBAL/details/compilers/lbalDetectCompiler.hpp>


/*------------------------------------------------------------------------------
	gcc compiler
*/

#if LBAL_TARGET_COMPILER_VANILLA_GCC
	//	Convenience macro
	#if defined (LBAL_GCC_VERSION)
		#error "Don’t define LBAL_GCC_VERSION outside of this header"
	#endif

	#define LBAL_GCC_VERSION ( \
		__GNUC__ * 10000 + \
		__GNUC_MINOR__ * 100 +\
		__GNUC_PATCHLEVEL__ )

	//	Identify processor.
	//	Note that AMD64 and x86_64 both trigger each other’s identifiers. We
	//	simply refer to all of them as LBAL_TARGET_CPU_X86_64.
	#if defined (__x86_64__) or defined (__amd64__)
		#define LBAL_TARGET_CPU_X86_64 1
		#define LBAL_TARGET_CPU_FAMILY_X86 1
	#elif defined (__i386__) //	 or defined (__i486__) or defined (__i586__) or defined (__i686__)
		#define LBAL_TARGET_CPU_X86 1
		#define LBAL_TARGET_CPU_FAMILY_X86 1
	#elif defined (__aarch64__)
		#define LBAL_TARGET_CPU_ARM_64 1
		#define LBAL_TARGET_CPU_FAMILY_ARM 1
	#elif defined (__arm__)
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


	//	Identify executable file fromat
	//	__SEEME__ Architecture is the same across Linux derivatives (ignoring old
	//	a.out), but binary compatibility is not guaranteed.
	#if defined (__ELF__)
		#define LBAL_TARGET_RT_ELF 1
	#elif defined (_WIN32)
		#define LBAL_TARGET_RT_COFF 1
	#elif defined (__MACH__)
		#define LBAL_TARGET_RT_MACHO 1
	#elif defined (__wasm__)
		#define LBAL_TARGET_RT_WASM 1
	#else
		#error "Unknown executable file format"
	#endif


	#if __SIZEOF_LONG_LONG__ == 8
		#define LBAL_TYPE_HAS_INT64 1
	#endif

	#if __SIZEOF_INT128__ == 16
		#define LBAL_TYPE_HAS_INT128 1
	#endif

	#define LBAL_TYPE_EXACT_WIDTH_INTEGERS 1

	#define LBAL_C99_PREPROCESSOR 1


	//	C++98 features

	//	It’s unclear whether we can count on `__cpp_exceptions` being unset if
	//	this is explicitly disabled, so we rely on the token that _is_
	//	guaranteed to have that behavior.
	//
	//	__SEEME__ This will probably need to be conditionally handled in a
	//	later version of gcc if they deprecate `__EXCEPTIONS`.
	#if !defined(LBAL_CPP98_EXCEPTIONS) && __EXCEPTIONS
		#define LBAL_CPP98_EXCEPTIONS 199711L
	#endif

	//	It’s unclear whether we can count on `__cpp_rtti` being unset if this
	//	is explicitly disabled, so we rely on the token that _is_ guaranteed to
	//	have that behavior.
	//
	//	__SEEME__ This will probably need to be conditionally handled in a
	//	later version of gcc if they deprecate `__GXX_RTTI`.
	#if !defined(LBAL_CPP98_RTTI) && __GXX_RTTI
		#define LBAL_CPP98_RTTI 199711L
	#endif


	//	C++11 features

	//	__SEEME__ There is no `LBAL_cpp_version` check since this can be
	//	conditionally disabled. We explicitly disable this if we don’t get a
	//	hit on the SD-6 macro, as otherwise there’s no way to detect it.
	#if (__cpp_threadsafe_static_init >= 200806L)
		#define LBAL_CPP11_THREADSAFE_STATIC_INIT __cpp_threadsafe_static_init
	#else
		#define LBAL_CPP11_THREADSAFE_STATIC_INIT 0
	#endif


	//	C++14 features

	//	__SEEME__ There is no `LBAL_cpp_version` check since this can be
	//	conditionally disabled.
	#if (__cpp_sized_deallocation >= 201304L)
		#define LBAL_CPP14_SIZED_DEALLOCATION __cpp_sized_deallocation
	#else
		#define LBAL_CPP14_SIZED_DEALLOCATION 0
	#endif


	//	C++2a features

	#if (LBAL_GCC_VERSION < 70300))
		#define LBAL_CPP2A_INTEGRATING_OUR_FEATURE_TEST_MACROS 1L
	#endif


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

	#define LBAL_VIS_MEMBER_FUNCTION_TEMPLATE __attribute__ ((__visibility__("hidden")))
		//	__FIXME__ There is a clang defect which requires an extraneous “inline”
		//	declaration to be prepended here; it’s currently unknown if gcc is
		//	impacted by the same defect.

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


	//	We get rid of this since it isn’t an officially supported feature.
	#undef LBAL_GCC_VERSION
#else
	#error "lbalGCCInitialization.hpp was directly included while using the wrong compiler"
#endif
