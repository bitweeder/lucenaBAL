/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalMSVCInitialization.hpp”
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
	MSVC compiler
*/

#if LBAL_TARGET_COMPILER_VANILLA_MSVC
	//	Implement some cross-platform `#pragma` handling
	#define LBAL_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS \
		__pragma(warning(disable:4068))

	#define LBAL_DIAGNOSTIC_PUSH __pragma(warning(push))
	#define LBAL_DIAGNOSTIC_POP __pragma(warning(pop))

	#define LBAL_PRAGMA(LBAL_PRAGMA_pragma) __pragma(LBAL_PRAGMA_pragma)


	//	Implement a cross-platform `#warning` substitute
	#define LBAL_CPP_WARNING(LBAL_CPP_WARNING_message) \
		LBAL_PRAGMA(message("warning: " LBAL_CPP_WARNING_message))


	//	Identify processor.
	//	Note that AMD64 and x86_64 have the same identifier.
	#if defined (_M_IX86)
		#define LBAL_TARGET_CPU_X86 1
		#define LBAL_TARGET_CPU_FAMILY_X86 1
		#define LBAL_TARGET_RT_LITTLE_ENDIAN 1
	#elif defined (_M_X64)
		#define LBAL_TARGET_CPU_X86_64 1
		#define LBAL_TARGET_CPU_FAMILY_X86 1
		#define LBAL_TARGET_RT_LITTLE_ENDIAN 1
	#elif defined (_M_IA64)
		#define LBAL_TARGET_CPU_IA64 1
		#define LBAL_TARGET_CPU_FAMILY_X86 1
		#define LBAL_TARGET_RT_LITTLE_ENDIAN 1
	#else
		#error "Processor unknown. Update lbalCompilerSetup.hpp."
	#endif


	//	Identify vector instruction sets, if any.
	#ifdef _M_IX86_FP
		#if (_M_IX86_FP == 1)
			//	32-bit processor
			#define LBAL_TARGET_VEC_SSE 1
		#elif (_M_IX86_FP == 2)
			//	32-bit processor
			#define LBAL_TARGET_VEC_SSE 1
			#define LBAL_TARGET_VEC_SSE2 1
		#else
			#pragma message ("Unknown value given by _M_IX86_FP: " #_M_IX86_FP)
		#endif
	#else
		#if (defined(_M_AMD64) || defined(_M_X64))
			//	64-bit processor
			#define LBAL_TARGET_VEC_SSE 1
			#define LBAL_TARGET_VEC_SSE2 1

			//	__SEEME__ There are no independent tests for these in MSVC, and
			//	it’s unclear if support for these particular instruction sets
			//	is implied for 64-bit architectures, as is the case for SSE1
			//	and SSE2; we make an assumption, as these should be available
			//	in any post-2011 Intel-class CPU.
			#define LBAL_TARGET_VEC_SSE3 1
			#define LBAL_TARGET_VEC_SSE41 1
			#define LBAL_TARGET_VEC_SSE42 1
		#else
			#error "Unsupported processor. Update lbalCompilerSetup.hpp."
		#endif

		#ifdef __AVX__
			#define LBAL_TARGET_VEC_AVX 1
		#endif

		#ifdef __AVX2__
			#define LBAL_TARGET_VEC_AVX2 1
		#endif

		//	__SEEME__ There appear to be no intrinsics for detecting AVX-512
		//	support in MSVC, yet, though support may be undocumented or
		//	under-reported. It’s currently moot, though, as we don’t support
		//	this instruction set family at this time.
	#endif


	//	__SEEME__ These are unverified for Win32
	#define LBAL_TYPE_DOUBLE_GT_FLOAT 1
	#define LBAL_TYPE_LONG_DOUBLE_GT_DOUBLE 1


	//	We ignore the possibility of other OS’s
	#define LBAL_TARGET_RT_COFF 1


	#define LBAL_TYPE_HAS_INT64 1
		//	__SEEME__ We assume the availability of 64-bit ints under supported
		//	versions of MSVC, and also assume the unavaibility of intrinsic
		//	128-bit ints.

	#define LBAL_TYPE_EXACT_WIDTH_INTEGERS 1

	#define LBAL_TYPE_WCHAR_T_IS_16_BITS 1


	//	Continuing the Windows tradition of security through annoyance...
	//	Of course, it gets better: in order for this to work, it actually
	//	has to be defined before any includes, even the ones that should
	//	pose no problem. In practice, this definition is probably not coming
	//	early enough, so there will still need to be another one, perhaps in a
	//	project-level property sheet. Consider this “documentation”.
	#define _CRT_SECURE_NO_WARNINGS 1

	//	Standardize on a gcc-ism.
	//	__SEEME__ This violates the rule about defining preprocessor macros
	//	with double-underscores (among other things). The usage should be
	//	safe.
	#ifndef __PRETTY_FUNCTION__
		#define __PRETTY_FUNCTION__ __FUNCSIG__
	#endif


	//	C99 features

	//	__SEEME__ The key missing component for C99 compliance was correct
	//	variadic macro handling. This is in place as of MSVS 2019 16.0, and
	//	may have been available sooner with the use of the `/permissive-`
	//	switch. Note that as of at least MSVS 2019 16.3, the preprocessor
	//	is actually almost completely compliant with the C11 standard.
	//	__SEEME__ It’s unclear if there is a method for controlling
	//	preprocessor compliance.
	#if (_MSC_VER >= 1920)
		#define LBAL_C99_PREPROCESSOR 1
	#endif


	//	C++11 features

	//	Available in `_MSC_VER`: `1900`
	//	This can be conditionally disabled.
	//
	//	__SEEME__ In the absence of `__cpp_threadsafe_static_init` - i.e., in
	//	MSVS 2017 or earlier - there isn’t a way to determine whether this has
	//	been disabled (which can be done with `/Zc:threadSafeInit-`). We’ll
	//	just assume it _has_ been disabled, which is not ideal, but unavoidable
	//	without incorporating a test app into the build process.
	#if (__cpp_threadsafe_static_init >= 200806L)
		#define LBAL_CPP11_THREADSAFE_STATIC_INIT __cpp_threadsafe_static_init
	#else
		#define LBAL_CPP11_THREADSAFE_STATIC_INIT 0
	#endif


	//	C++14 features

	//	This can be conditionally disabled.
	//
	//	__SEEME__ In the absence of `__cpp_sized_deallocation` - i.e., in
	//	MSVS 2017 or earlier - there isn’t a way to determine whether this has
	//	been disabled, which can be done with `/Zc:sizedDealloc-`. We’ll just
	//	assume it _has_ been disabled, which is not ideal, but unavoidable
	//	without incorporating a test app into the build process.
	#if (__cpp_sized_deallocation >= 201309L)
		#define LBAL_CPP14_SIZED_DEALLOCATION __cpp_sized_deallocation
	#else
		#define LBAL_CPP14_SIZED_DEALLOCATION 0
	#endif


	//	Symbol visibility macros
	#define LBAL_VIS_HIDDEN

	#define LBAL_VIS_ENUM

	#define LBAL_VIS_CLASS_TEMPLATE

	#define LBAL_VIS_CLASS_EXPORT __declspec(dllexport)
	#define LBAL_VIS_CLASS_IMPORT __declspec(dllimport)

	#define LBAL_VIS_EXTERN_CLASS_TEMPLATE_EXPORT
	#define LBAL_VIS_EXTERN_CLASS_TEMPLATE_IMPORT __declspec(dllimport)

	#define LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_EXPORT __declspec(dllexport)
	#define LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_IMPORT

	#define LBAL_VIS_MEMBER_CLASS_TEMPLATE

	#define LBAL_VIS_MEMBER_FUNCTION_TEMPLATE

	#define LBAL_VIS_FUNC_EXPORT __declspec(dllexport)
	#define LBAL_VIS_FUNC_IMPORT __declspec(dllimport)

	//	__SEEME__ These appear to be required by DLLs, as they like to save
	//	fallback versions of inline functions as object code in case the
	//	header version is unavailable for some reason; if not for this
	//	requirement, these would just be LBAL_VIS_HIDDEN.
	#define LBAL_VIS_INLINE_FUNC __forceinline
	#define LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC __forceinline

	#define LBAL_VIS_OVERLOADABLE_FUNC_EXPORT __declspec(dllexport)
	#define LBAL_VIS_OVERLOADABLE_FUNC_IMPORT

	#define LBAL_VIS_EXTERN_EXPORT __declspec(dllexport)
	#define LBAL_VIS_EXTERN_IMPORT __declspec(dllimport)

	#define LBAL_VIS_EXCEPTION_EXPORT __declspec(dllexport)
	#define LBAL_VIS_EXCEPTION_IMPORT __declspec(dllimport)


	//	Class decorators
	#define LBAL_CLASS_FORCE_EBCO __declspec(empty_bases)


	//	Function calling conventions
	#define LBAL_FUNC_CALL_C(LBAL_func_name_) __cdecl LBAL_func_name_
	#define LBAL_FUNC_CALL_STD(LBAL_func_name_) __stdcall LBAL_func_name_
	#define LBAL_FUNC_CALLBACK_C(LBAL_func_name_) (__cdecl *LBAL_func_name_)
	#define LBAL_FUNC_CALLBACK_STD(LBAL_func_name_) (__stdcall *LBAL_func_name_)
#else
	#error "lbalMSVCInitialization.hpp was directly included while using the wrong compiler"
#endif
