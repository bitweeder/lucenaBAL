/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“CompilermMSVC.hpp”
	Copyright © 2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/


#pragma once


//	std
//	__SEEME__ We always guard inclusion of system headers when using MSVS due
//	its noisiness at high warning levels.
#if defined (_MSC_VER) && defined (_WIN32)
	#pragma warning (push, 0)
#endif

#include <ciso646>
	//	In C++, this is a do-nothing header we include just for the side
	//	effects: the Standard Library implementation will be configured
	//	and many assorted compiler-dependent feature detection macros will
	//	be defined.

#if defined (_MSC_VER) && defined (_WIN32)
	#pragma warning (pop)
#endif


//	lbal
#include <lucenaBAL/details/lbalConfig.hpp>


/*------------------------------------------------------------------------------
	MSVC compiler
*/

//	This duplicates the test peformed to include this file in the first place.
#if defined (_MSC_VER) && defined (_WIN32)
	//	__FIXME__ This is unnecessarily conservative. In practice, things are
	//	unlikely to get squiffy until we go back before MSVS 2015 Update 3
	//	(`_MSC_FULL_VER` at least `190024210`).
	#if (_MSC_VER < 1914)
		#error "Settings are only known to be valid for MSVS 2017 15.7+."
	#endif

	#if LBAL_cpp_version < 201703L
		#error "std=c++17 or higher is required"
	#endif


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


	//	__SEEME__ Re: SD-6 macros: full support started getting rolled out as
	//	of MSVC 2019 16.0, but testing with that series didn’t start until
	//	16.3. As a result, it’s unclear exactly when the various macros started
	//	going live. For that reason, prior to 16.3, we rely on version checks,
	//	but after that, we use the SD-6 macros first. It’s possible some
	//	supported features will fallthrough the cracks with some versions, but
	//	it’s unlikely; all the same, this will be updated as new information
	//	becomes available.

	//	C++98 features
	//	These can be conditionally disabled.

	//	We can’t rely on `__cpp_exceptions` being set properly in older MSVCs,
	//	so we also test for a proprietary token, as well.
	//	__SEEME__ _CPPUNWIND is not an exact analog, but seems to serve.
	#if __cpp_exceptions || _CPPUNWIND
		#if __cpp_exceptions
			#define LBAL_CPP98_EXCEPTIONS __cpp_exceptions
		#else
			#define LBAL_CPP98_EXCEPTIONS 199711L
		#endif
	#endif

	//	We can’t rely on `__cpp_rtti` being set properly in older MSVCs, so we
	//	also test for a proprietary token, as well.
	#if __cpp_rtti || _CPPRTTI
		#if __cpp_rtti
			#define LBAL_CPP98_RTTI __cpp_rtti
		#else
			#define LBAL_CPP98_RTTI 199711L
		#endif
	#endif


	//	C++11 features

	#if (__cpp_alias_templates >= 200704L)
		#define LBAL_CPP11_ALIAS_TEMPLATES __cpp_alias_templates
	#elif (LBAL_cpp_version >= 201103L) && (_MSC_VER >= 1800)
		#define LBAL_CPP11_ALIAS_TEMPLATES 200704L
	#endif

	#if (__cpp_attributes >= 200809L)
		#define LBAL_CPP11_ATTRIBUTES __cpp_attributes
	#elif (LBAL_cpp_version >= 201103L) && (_MSC_VER >= 1900)
		#define LBAL_CPP11_ATTRIBUTES 200809L
	#endif

	//	__SEEME__ Available in `_MSC_VER``1900` for partial, unsure of full
	#if (__cpp_constexpr >= 200704L)
		#define LBAL_CPP11_CONSTEXPR __cpp_constexpr
	#elif (LBAL_cpp_version >= 201103L) && (_MSC_VER >= 1900)
		#define LBAL_CPP11_CONSTEXPR 200704L
	#endif

	#if (__cpp_decltype >= 200707L)
		#define LBAL_CPP11_DECLTYPE __cpp_decltype
	#elif (LBAL_cpp_version >= 201103L)
		#define LBAL_CPP11_DECLTYPE 200707L
	#endif

	#if (__cpp_delegating_constructors >= 200604L)
		#define LBAL_CPP11_DELEGATING_CONSTRUCTORS __cpp_delegating_constructors
	#elif (LBAL_cpp_version >= 201103L)
		#define LBAL_CPP11_DELEGATING_CONSTRUCTORS 200604L
	#endif

	#if (__cpp_inheriting_constructors >= 200802L)
		#define LBAL_CPP11_INHERITING_CONSTRUCTORS __cpp_inheriting_constructors
	#elif (LBAL_cpp_version >= 201103L)
		#define LBAL_CPP11_INHERITING_CONSTRUCTORS 200802L
	#endif

	#if (__cpp_initializer_lists >= 200806L)
		#define LBAL_CPP11_INITIALIZER_LISTS __cpp_initializer_lists
	#elif (LBAL_cpp_version >= 201103L)
		#define LBAL_CPP11_INITIALIZER_LISTS 200806L
	#endif

	#if (__cpp_lambdas >= 200907L)
		#define LBAL_CPP11_LAMBDAS __cpp_lambdas
	#elif (LBAL_cpp_version >= 201103L)
		#define LBAL_CPP11_LAMBDAS 200907L
	#endif

	#if (__cpp_nsdmi >= 200809L)
		#define LBAL_CPP11_NSDMI __cpp_nsdmi
	#elif (LBAL_cpp_version >= 201103L)
		#define LBAL_CPP11_NSDMI 200809L
	#endif

	#if (__cpp_range_based_for >= 200907L)
		#define LBAL_CPP11_RANGE_BASED_FOR __cpp_range_based_for
	#elif (LBAL_cpp_version >= 201103L)
		#define LBAL_CPP11_RANGE_BASED_FOR 200907L
	#endif

	#if (__cpp_raw_strings >= 200710L)
		#define LBAL_CPP11_RAW_STRINGS __cpp_raw_strings
	#elif (LBAL_cpp_version >= 201103L)
		#define LBAL_CPP11_RAW_STRINGS 200710L
	#endif

	#if (__cpp_ref_qualifiers >= 200710L)
		#define LBAL_CPP11_REF_QUALIFIERS __cpp_ref_qualifiers
	#elif (LBAL_cpp_version >= 201103L)
		#define LBAL_CPP11_REF_QUALIFIERS 200710L
	#endif

	#if (__cpp_rvalue_references >= 200610L)
		#define LBAL_CPP11_RVALUE_REFERENCES __cpp_rvalue_references
	#elif (LBAL_cpp_version >= 201103L)
		#define LBAL_CPP11_RVALUE_REFERENCES 200610L
	#endif

	#if (__cpp_static_assert >= 200410L)
		#define LBAL_CPP11_STATIC_ASSERT __cpp_static_assert
	#elif (LBAL_cpp_version >= 201103L)
		#define LBAL_CPP11_STATIC_ASSERT 200410L
	#endif

	//	Available in `_MSC_VER`: `1900`
	//	This can be conditionally disabled.
	//	__SEEME__ In the absence of `__cpp_threadsafe_static_init` - i.e., in
	//	MSVS 2017 or earlier - there isn’t a way to determine whether this has
	//	been disabled, which can be done with `/Zc:threadSafeInit-`. We’ll just
	//	assume it _has_ been disabled, which is not ideal, but unavoidable
	//	without incorporating a test app into the build process.
	#if (__cpp_threadsafe_static_init >= 200806L)
		#define LBAL_CPP11_THREADSAFE_STATIC_INIT __cpp_threadsafe_static_init
	#endif

	#if (__cpp_unicode_characters >= 200704L)
		#define LBAL_CPP11_UNICODE_CHARACTERS __cpp_unicode_characters
	#elif (LBAL_cpp_version >= 201103L)
		#define LBAL_CPP11_UNICODE_CHARACTERS 200704L
	#endif

	#if (__cpp_unicode_literals >= 200710L)
		#define LBAL_CPP11_UNICODE_LITERALS __cpp_unicode_literals
	#elif (LBAL_cpp_version >= 201103L)
		#define LBAL_CPP11_UNICODE_LITERALS 200710L
	#endif

	#if (__cpp_user_defined_literals >= 200809L)
		#define LBAL_CPP11_USER_DEFINED_LITERALS __cpp_user_defined_literals
	#elif (LBAL_cpp_version >= 201103L)
		#define LBAL_CPP11_USER_DEFINED_LITERALS 200809L
	#endif

	#if (__cpp_variadic_templates >= 200704L)
		#define LBAL_CPP11_VARIADIC_TEMPLATES __cpp_variadic_templates
	#elif (LBAL_cpp_version >= 201103L)
		#define LBAL_CPP11_VARIADIC_TEMPLATES 200704L
	#endif

	//	__SEEME__ MSVC Follows the letter of the proposal and disallows
	//	the use of __has_cpp_attribute in contexts other than preprocessor
	//	conditionals.
	#if defined(__has_cpp_attribute) && (__has_cpp_attribute(carries_dependency) >= 200809L)
		#define LBAL_CPP11_ATTRIBUTE_CARRIES_DEPENDENCY 200809L
	#elif (LBAL_cpp_version >= 201103L) && (_MSC_VER >= 1900)
		#define LBAL_CPP11_ATTRIBUTE_CARRIES_DEPENDENCY 200809L
	#endif

	//	__SEEME__ MSVC Follows the letter of the proposal and disallows
	//	the use of __has_cpp_attribute in contexts other than preprocessor
	//	conditionals.
	#if defined(__has_cpp_attribute) && (__has_cpp_attribute(noreturn) >= 200809L)
		#define LBAL_CPP11_ATTRIBUTE_NORETURN 200809L
	#elif (LBAL_cpp_version >= 201103L) && (_MSC_VER >= 1900)
		#define LBAL_CPP11_ATTRIBUTE_NORETURN 200809L
	#endif


	//	C++14 features

	#if (__cpp_aggregate_nsdmi >= 201304L)
		#define LBAL_CPP14_AGGREGATE_NSDMI __cpp_aggregate_nsdmi
	#elif (LBAL_cpp_version >= 201402L) && (_MSC_VER >= 1900)
		#define LBAL_CPP14_AGGREGATE_NSDMI 201304L
	#endif

	#if (__cpp_binary_literals >= 201304L)
		#define LBAL_CPP14_BINARY_LITERALS __cpp_binary_literals
	#elif (LBAL_cpp_version >= 201402L) && (_MSC_VER >= 1900)
		#define LBAL_CPP14_BINARY_LITERALS 201304L
	#endif

	#if (__cpp_constexpr >= 201304L)
		#define LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS __cpp_constexpr
	#elif (LBAL_cpp_version >= 201402L) && (_MSC_VER >= 1910)
		#define LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS 201304L
	#endif

	#if (__cpp_decltype_auto >= 201304L)
		#define LBAL_CPP14_DECLTYPE_AUTO __cpp_decltype_auto
	#elif (LBAL_cpp_version >= 201402L) && (_MSC_VER >= 1900)
		#define LBAL_CPP14_DECLTYPE_AUTO 201304L
	#endif

	#if (__cpp_generic_lambdas >= 201304L)
		#define LBAL_CPP14_GENERIC_LAMBDAS __cpp_generic_lambdas
	#elif (LBAL_cpp_version >= 201402L) && (_MSC_VER >= 1900)
		#define LBAL_CPP14_GENERIC_LAMBDAS 201304L
	#endif

	#if (__cpp_init_captures >= 201304L)
		#define LBAL_CPP14_INIT_CAPTURES __cpp_init_captures
	#elif (LBAL_cpp_version >= 201402L) && (_MSC_VER >= 1900)
		#define LBAL_CPP14_INIT_CAPTURES 201304L
	#endif

	#if (__cpp_return_type_deduction >= 201304L)
		#define LBAL_CPP14_RETURN_TYPE_DEDUCTION __cpp_return_type_deduction
	#elif (LBAL_cpp_version >= 201402L) && (_MSC_VER >= 1900)
		#define LBAL_CPP14_RETURN_TYPE_DEDUCTION 201304L
	#endif

	//	This can be conditionally disabled.
	//	__SEEME__ In the absence of `__cpp_sized_deallocation` - i.e., in
	//	MSVS 2017 or earlier - there isn’t a way to determine whether this has
	//	been disabled, which can be done with `/Zc:sizedDealloc-`. We’ll just
	//	assume it _has_ been disabled, which is not ideal, but unavoidable
	//	without incorporating a test app into the build process.
	#if (__cpp_sized_deallocation >= 201304L)
		#define LBAL_CPP14_SIZED_DEALLOCATION __cpp_sized_deallocation
	#endif

	#if (__cpp_variable_templates >= 201304L)
		#define LBAL_CPP14_VARIABLE_TEMPLATES __cpp_variable_templates
	#elif (LBAL_cpp_version >= 201402L) && (_MSC_VER >= 1900)
		#define LBAL_CPP14_VARIABLE_TEMPLATES 201304L
	#endif

	//	__SEEME__ MSVC Follows the letter of the proposal and disallows
	//	the use of __has_cpp_attribute in contexts other than preprocessor
	//	conditionals.
	#if defined(__has_cpp_attribute) && (__has_cpp_attribute(deprecated) >= 201309L)
		#define LBAL_CPP14_ATTRIBUTE_DEPRECATED 201309L
	#elif (LBAL_cpp_version >= 201402L) && (_MSC_VER >= 1900)
		#define LBAL_CPP14_ATTRIBUTE_DEPRECATED 201309L
	#endif


	//	C++17 features

	#if (__cpp_aggregate_bases >= 201603L)
		#define LBAL_CPP17_AGGREGATE_BASES __cpp_aggregate_bases
	#elif (LBAL_cpp_version >= 201703L) &&  (_MSC_VER >= 1914)
		#define LBAL_CPP17_AGGREGATE_BASES 201603L
	#endif

	#if (__cpp_aligned_new >= 201606L)
		#define LBAL_CPP17_ALIGNED_NEW __cpp_aligned_new
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1912)
		#define LBAL_CPP17_ALIGNED_NEW 201606L
	#endif

	#if (__cpp_capture_star_this >= 201603)
		#define LBAL_CPP17_CAPTURE_STAR_THIS __cpp_capture_star_this
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1911)
		#define LBAL_CPP17_CAPTURE_STAR_THIS 201603
	#endif

	#if (__cpp_constexpr >= 201603L)
		#define LBAL_CPP17_CONSTEXPR_LAMBDA __cpp_constexpr
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1911)
		#define LBAL_CPP17_CONSTEXPR_LAMBDA 201603L
	#endif

	#if (__cpp_deduction_guides >= 201606L)
		#define LBAL_CPP17_DEDUCTION_GUIDES __cpp_deduction_guides
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1914)
		#define LBAL_CPP17_DEDUCTION_GUIDES 201606L
	#endif

	#if (__cpp_deduction_guides >= 201611L)
		#define LBAL_CPP17_DEDUCTION_GUIDES_NB __cpp_deduction_guides
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1914)
		#define LBAL_CPP17_DEDUCTION_GUIDES_NB 201611L
	#endif

	#if (__cpp_deduction_guides >= 201703L)
		#define LBAL_CPP17_DEDUCTION_GUIDES_DR __cpp_deduction_guides
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1914)
		#define LBAL_CPP17_DEDUCTION_GUIDES_DR 201703L
	#endif

	#if (__cpp_enumerator_attributes >= 201411L)
		#define LBAL_CPP17_ENUMERATOR_ATTRIBUTES __cpp_enumerator_attributes
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1900)
		#define LBAL_CPP17_ENUMERATOR_ATTRIBUTES 201411L
	#endif

	#if (__cpp_fold_expressions >= 201411L)
		#define LBAL_CPP17_FOLD_EXPRESSIONS __cpp_fold_expressions
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1912)
		#define LBAL_CPP17_FOLD_EXPRESSIONS 201411L
	#endif

	#if (__cpp_fold_expressions >= 201603L)
		#define LBAL_CPP17_FOLD_EXPRESSIONS_REVISED __cpp_fold_expressions
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1912)
		#define LBAL_CPP17_FOLD_EXPRESSIONS_REVISED 201603L
	#endif

	#if (__cpp_guaranteed_copy_elision >= 201606L)
		#define LBAL_CPP17_GUARANTEED_COPY_ELISION __cpp_guaranteed_copy_elision
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1913)
		#define LBAL_CPP17_GUARANTEED_COPY_ELISION 201606L
	#endif

	#if (__cpp_hex_float >= 201603L)
		#define LBAL_CPP17_HEX_FLOAT __cpp_hex_float
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1911)
		#define LBAL_CPP17_HEX_FLOAT 201603L
	#endif

	#if (__cpp_if_constexpr >= 201606L)
		#define LBAL_CPP17_IF_CONSTEXPR __cpp_if_constexpr
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1911)
		#define LBAL_CPP17_IF_CONSTEXPR 201606L
	#endif

	#if (__cpp_inheriting_constructors >= 201511L)
		#define LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED __cpp_inheriting_constructors
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1914)
		#define LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED 201511L
	#endif

	#if (__cpp_inline_variables >= 201606L)
		#define LBAL_CPP17_INLINE_VARIABLES __cpp_inline_variables
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1912)
		#define LBAL_CPP17_INLINE_VARIABLES 201606L
	#endif

	#if (__cpp_namespace_attributes >= 201411L)
		#define LBAL_CPP17_NAMESPACE_ATTRIBUTES __cpp_namespace_attributes
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1900)
		#define LBAL_CPP17_NAMESPACE_ATTRIBUTES 201411L
	#endif

	#if (__cpp_noexcept_function_type >= 201510L)
		#define LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE __cpp_noexcept_function_type
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1912)
		#define LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE 201510L
	#endif

	#if (__cpp_nontype_template_args >= 201411L)
		#define LBAL_CPP17_NONTYPE_TEMPLATE_ARGS __cpp_nontype_template_args
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1912)
		#define LBAL_CPP17_NONTYPE_TEMPLATE_ARGS 201411L
	#endif

	#if (__cpp_nontype_template_parameter_auto >= 201606L)
		#define LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO __cpp_nontype_template_parameter_auto
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1914)
		#define LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO 201606L
	#endif

	#if (__cpp_range_based_for >= 201603L)
		#define LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED __cpp_range_based_for
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1910)
		#define LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED 201603L
	#endif

	#if (__cpp_static_assert >= 201411L)
		#define LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE __cpp_static_assert
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1910)
		#define LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE 201411L
	#endif

	#if (__cpp_structured_bindings >= 201606L)
		#define LBAL_CPP17_STRUCTURED_BINDINGS __cpp_structured_bindings
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1911)
		#define LBAL_CPP17_STRUCTURED_BINDINGS 201606L
	#endif

	//	__SEEME__ This is implemented, but it’s unclear if/when the DR that
	//	affected the proposal was addressed.
	#if (__cpp_template_template_args >= 201611L)
		#define LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS __cpp_template_template_args
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1912)
		#define LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS 201611L
	#endif

	#if (__cpp_variadic_using >= 201611L)
		#define LBAL_CPP17_VARIADIC_USING __cpp_variadic_using
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1914)
		#define LBAL_CPP17_VARIADIC_USING 201611L
	#endif

	//	__SEEME__ MSVC Follows the letter of the proposal and disallows
	//	the use of __has_cpp_attribute in contexts other than preprocessor
	//	conditionals.
	#if defined(__has_cpp_attribute) && (__has_cpp_attribute(fallthrough) >= 201603L)
		#define LBAL_CPP17_ATTRIBUTE_FALLTHROUGH 201603L
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1910)
		#define LBAL_CPP17_ATTRIBUTE_FALLTHROUGH 201603L
	#endif

	//	__SEEME__ MSVC Follows the letter of the proposal and disallows
	//	the use of __has_cpp_attribute in contexts other than preprocessor
	//	conditionals.
	#if defined(__has_cpp_attribute) && (__has_cpp_attribute(maybe_unused) >= 201603L)
		#define LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED 201603L
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1911)
		#define LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED 201603L
	#endif

	//	__SEEME__ MSVC Follows the letter of the proposal and disallows
	//	the use of __has_cpp_attribute in contexts other than preprocessor
	//	conditionals.
	#if defined(__has_cpp_attribute) && (__has_cpp_attribute(nodiscard) >= 201603L)
		#define LBAL_CPP17_ATTRIBUTE_NODISCARD 201603L
	#elif (LBAL_cpp_version >= 201703L) && (_MSC_VER >= 1911)
		#define LBAL_CPP17_ATTRIBUTE_NODISCARD 201603L
	#endif


	//	C++2a features

	//	__SEEME__ None of these have SD-6 macros, so we rely on a compiler
	//	version check and a language test.
	#if (_MSC_VER >= 1900) && (LBAL_cpp_version > 201703L)
		#define LBAL_CPP2A_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS 1L
	#endif

	#if (_MSC_VER >= 1914) && (LBAL_cpp_version > 201703L)
		#define LBAL_CPP2A_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION 1L
	#endif

	#if (_MSC_VER >= 1920) && (LBAL_cpp_version > 201703L)
		#define LBAL_CPP2A_INTEGRATING_OUR_FEATURE_TEST_MACROS 1L
	#endif

	#if (_MSC_VER >= 1921) && (LBAL_cpp_version > 201703L)
		#define LBAL_CPP2A_DESIGNATED_INITIALIZERS 1L
	#endif

	#if (_MSC_VER >= 1922) && (LBAL_cpp_version > 201703L)
		#define LBAL_CPP2A_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS 1L
		#define LBAL_CPP2A_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS 1L
		#define LBAL_CPP2A_PACK_EXPANSION_IN_LAMBDA_INIT_CAPTURE 1L
		#define LBAL_CPP2A_TEMPLATE_PARAMETER_LIST_FOR_GENERIC_LAMBDAS 1L
	#endif

	#if (__cpp_aggregate_paren_init >= 201902L)
		#define LBAL_CPP2A_AGGREGATE_PAREN_INIT __cpp_aggregate_paren_init
	#endif

	#if (__cpp_char8_t >= 201811L)
		#define LBAL_CPP2A_CHAR8_T __cpp_char8_t
	#endif

	#if (__cpp_concepts >= 201806L)
		#define LBAL_CPP2A_CONCEPTS __cpp_concepts
	#endif

	#if (__cpp_conditional_explicit >= 201806L)
		#define LBAL_CPP2A_CONDITIONAL_EXPLICIT __cpp_conditional_explicit
	#endif

	#if (__cpp_constexpr >= 201907L)
		#define LBAL_CPP2A_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION __cpp_constexpr
	#endif

	#if (__cpp_constexpr_dynamic_alloc >= 201907L)
		#define LBAL_CPP2A_CONSTEXPR_DYNAMIC_ALLOC __cpp_constexpr_dynamic_alloc
	#endif

	#if (__cpp_constinit >= 201907L)
		#define LBAL_CPP2A_CONSTINIT __cpp_constinit
	#endif

	#if (__cpp_coroutines >= 201902L)
		#define LBAL_CPP2A_COROUTINES __cpp_coroutines
	#endif

	#if (__cpp_deduction_guides >= 201907L)
		#define LBAL_CPP2A_DEDUCTION_GUIDES_FOR_AGGREGATES __cpp_deduction_guides
	#endif

	#if (__cpp_impl_destroying_delete >= 201806L)
		#define LBAL_CPP2A_DESTROYING_DELETE __cpp_impl_destroying_delete
	#endif

	#if (__cpp_modules >= 201907L)
		#define LBAL_CPP2A_NONTYPE_TEMPLATE_PARAMETER_CLASS __cpp_modules
	#endif

	#if (__cpp_nontype_template_parameter_class >= 201806L)
		#define LBAL_CPP2A_NONTYPE_TEMPLATE_PARAMETER_CLASS __cpp_nontype_template_parameter_class
	#endif

	#if (__cpp_impl_three_way_comparison >= 201711L)
		#define LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR __cpp_impl_three_way_comparison
	#endif

	#if (__cpp_impl_three_way_comparison >= 201907L)
		#define LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR_TUNEUP __cpp_impl_three_way_comparison
	#endif

	#if (__cpp_using_enum >= 201907L)
		#define LBAL_CPP2A_USING_ENUM __cpp_using_enum
	#endif

	//	__SEEME__ MSVC Follows the letter of the proposal and disallows
	//	the use of __has_cpp_attribute in contexts other than preprocessor
	//	conditionals.
	#if defined(__has_cpp_attribute) && (__has_cpp_attribute(likely) >= 201803L)
		#define LBAL_CPP2A_ATTRIBUTE_LIKELY 201803L
	#endif

	//	__SEEME__ MSVC Follows the letter of the proposal and disallows
	//	the use of __has_cpp_attribute in contexts other than preprocessor
	//	conditionals.
	#if defined(__has_cpp_attribute) && (__has_cpp_attribute(nodiscard) >= 201907L)
		#define LBAL_CPP2A_ATTRIBUTE_NODISCARD_EXPANDED 201907L
	#endif

	//	__SEEME__ MSVC Follows the letter of the proposal and disallows
	//	the use of __has_cpp_attribute in contexts other than preprocessor
	//	conditionals.
	#if defined(__has_cpp_attribute) && (__has_cpp_attribute(no_unique_address) >= 201803L)
		#define LBAL_CPP2A_ATTRIBUTE_NO_UNIQUE_ADDRESS 201803L
	#endif

	//	__SEEME__ MSVC Follows the letter of the proposal and disallows
	//	the use of __has_cpp_attribute in contexts other than preprocessor
	//	conditionals.
	#if defined(__has_cpp_attribute) && (__has_cpp_attribute(unlikely) >= 201803L)
		#define LBAL_CPP2A_ATTRIBUTE_UNLIKELY 201803L
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


	//	Set up identifiers
	#define LBAL_NAME_COMPILER u8"MSVC version " LBAL_Stringify_ (_MSC_VER)
	#define LBAL_TARGET_COMPILER_MSVC 1
#else
	#error "lbalCompilerMSVC.hpp was directly included while using the wrong compiler"
#endif
