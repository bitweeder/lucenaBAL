/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“CompilerClang.hpp”
	Copyright © 2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See lbalFeatureSetup.hpp for descriptions of the various macros and flags.

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
#include <lucenaBAL/lbalConfig.hpp>


/*------------------------------------------------------------------------------
	llvm/clang compiler

	__FIXME__ Support could be added for c2/clang, possibly in its own file.
*/

//	This duplicates the test peformed to include this file in the first place.
#if defined (__clang__) && defined (__llvm__)
	#if (__clang_major__ < 6)
		#error "Settings are only valid for clang 6.0+"
	#else
		//	__FIXME__ This is actually untested, as it’s just a fix-up of the
		//	Apple LLVM section.
	#endif

	#if LBAL_CONFIG_cpp_version < 201703L
		#error "std=c++17 or higher is required"
	#endif

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


	//	Identify executable file fromat
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


	//	__SEEME__ Apparently, __STDC_VERSION__ only gets set if we’re using the C
	//	compiler, so this test doesn’t work. Since we’re requiring C++14 or
	//	greater, we assume the following C99 features are available.
	#if 1	//	__STDC_VERSION__ >= 199901L
		#define LBAL_C99_PREPROCESSOR 1
	#else
		#warning "D'oh!"
	#endif	//	__STDC_VERSION__


	//	C++98 features

	//	These can be conditionally disabled.
	#if (__cpp_exceptions >= 199711L)
		#define LBAL_CPP98_EXCEPTIONS __cpp_exceptions
	#elif __has_feature(cxx_exceptions)
		#define LBAL_CPP98_EXCEPTIONS 199711L
	#endif

	#if (__cpp_rtti >= 199711L)
		#define LBAL_CPP98_RTTI __cpp_rtti
	#elif __has_feature(cxx_rtti)
		#define LBAL_CPP98_RTTI 199711L
	#endif


	//	C++11 features

	#if (__cpp_alias_templates >= 200704L)
		#define LBAL_CPP11_ALIAS_TEMPLATES __cpp_alias_templates
	#elif (LBAL_CONFIG_cpp_version >= 201103L)
		#define LBAL_CPP11_ALIAS_TEMPLATES 200704L
	#endif

	#if (__cpp_attributes >= 200809L)
		#define LBAL_CPP11_ATTRIBUTES __cpp_attributes
	#elif (LBAL_CONFIG_cpp_version >= 201103L)
		#define LBAL_CPP11_ATTRIBUTES 200809L
	#endif

	#if (__cpp_constexpr >= 200704L)
		#define LBAL_CPP11_CONSTEXPR __cpp_constexpr
	#elif (LBAL_CONFIG_cpp_version >= 201103L)
		#define LBAL_CPP11_CONSTEXPR 200704L
	#endif

	#if (__cpp_decltype >= 200707L)
		#define LBAL_CPP11_DECLTYPE __cpp_decltype
	#elif (LBAL_CONFIG_cpp_version >= 201103L)
		#define LBAL_CPP11_DECLTYPE 200707L
	#endif

	#if (__cpp_delegating_constructors >= 200604L)
		#define LBAL_CPP11_DELEGATING_CONSTRUCTORS __cpp_delegating_constructors
	#elif (LBAL_CONFIG_cpp_version >= 201103L)
		#define LBAL_CPP11_DELEGATING_CONSTRUCTORS 200604L
	#endif

	#if (__cpp_inheriting_constructors >= 200802L)
		#define LBAL_CPP11_INHERITING_CONSTRUCTORS __cpp_inheriting_constructors
	#elif (LBAL_CONFIG_cpp_version >= 201103L)
		#define LBAL_CPP11_INHERITING_CONSTRUCTORS 200802L
	#endif

	#if (__cpp_initializer_lists >= 200806L)
		#define LBAL_CPP11_INITIALIZER_LISTS __cpp_initializer_lists
	#elif (LBAL_CONFIG_cpp_version >= 201103L)
		#define LBAL_CPP11_INITIALIZER_LISTS 200806L
	#endif

	#if (__cpp_lambdas >= 200907L)
		#define LBAL_CPP11_LAMBDAS __cpp_lambdas
	#elif (LBAL_CONFIG_cpp_version >= 201103L)
		#define LBAL_CPP11_LAMBDAS 200907L
	#endif

	#if (__cpp_nsdmi >= 200809L)
		#define LBAL_CPP11_NSDMI __cpp_nsdmi
	#elif (LBAL_CONFIG_cpp_version >= 201103L)
		#define LBAL_CPP11_NSDMI 200809L
	#endif

	#if (__cpp_range_based_for >= 200907L)
		#define LBAL_CPP11_RANGE_BASED_FOR __cpp_range_based_for
	#elif (LBAL_CONFIG_cpp_version >= 201103L)
		#define LBAL_CPP11_RANGE_BASED_FOR 200907L
	#endif

	#if (__cpp_raw_strings >= 200710L)
		#define LBAL_CPP11_RAW_STRINGS __cpp_raw_strings
	#elif (LBAL_CONFIG_cpp_version >= 201103L)
		#define LBAL_CPP11_RAW_STRINGS 200710L
	#endif

	#if (__cpp_ref_qualifiers >= 200710L)
		#define LBAL_CPP11_REF_QUALIFIERS __cpp_ref_qualifiers
	#elif (LBAL_CONFIG_cpp_version >= 201103L)
		#define LBAL_CPP11_REF_QUALIFIERS 200710L
	#endif

	#if (__cpp_rvalue_references >= 200610L)
		#define LBAL_CPP11_RVALUE_REFERENCES __cpp_rvalue_references
	#elif (LBAL_CONFIG_cpp_version >= 201103L)
		#define LBAL_CPP11_RVALUE_REFERENCES 200610L
	#endif

	#if (__cpp_static_assert >= 200410L)
		#define LBAL_CPP11_STATIC_ASSERT __cpp_static_assert
	#elif (LBAL_CONFIG_cpp_version >= 201103L)
		#define LBAL_CPP11_STATIC_ASSERT 200410L
	#endif

	//	__SEEME__ There is no `LBAL_CONFIG_cpp_version` check since this can be
	//	conditionally disabled.
	#if (__cpp_threadsafe_static_init >= 200806L)
		#define LBAL_CPP11_THREADSAFE_STATIC_INIT __cpp_threadsafe_static_init
	#endif

	#if (__cpp_unicode_characters >= 200704L)
		#define LBAL_CPP11_UNICODE_CHARACTERS __cpp_unicode_characters
	#elif (LBAL_CONFIG_cpp_version >= 201103L)
		#define LBAL_CPP11_UNICODE_CHARACTERS 200704L
	#endif

	#if (__cpp_unicode_literals >= 200710L)
		#define LBAL_CPP11_UNICODE_LITERALS __cpp_unicode_literals
	#elif (LBAL_CONFIG_cpp_version >= 201103L)
		#define LBAL_CPP11_UNICODE_LITERALS 200710L
	#endif

	#if (__cpp_user_defined_literals >= 200809L)
		#define LBAL_CPP11_USER_DEFINED_LITERALS __cpp_user_defined_literals
	#elif (LBAL_CONFIG_cpp_version >= 201103L)
		#define LBAL_CPP11_USER_DEFINED_LITERALS 200809L
	#endif

	#if (__cpp_variadic_templates >= 200704L)
		#define LBAL_CPP11_VARIADIC_TEMPLATES __cpp_variadic_templates
	#elif (LBAL_CONFIG_cpp_version >= 201103L)
		#define LBAL_CPP11_VARIADIC_TEMPLATES 200704L
	#endif

	#if defined(__has_cpp_attribute) && (__has_cpp_attribute(carries_dependency) >= 200809L)
		#define LBAL_CPP11_ATTRIBUTE_CARRIES_DEPENDENCY __has_cpp_attribute(carries_dependency)
	#elif (LBAL_CONFIG_cpp_version >= 201103L)
		#define LBAL_CPP11_ATTRIBUTE_CARRIES_DEPENDENCY 200809L
	#endif

	#if defined(__has_cpp_attribute) && (__has_cpp_attribute(noreturn) >= 200809L)
		#define LBAL_CPP11_ATTRIBUTE_NORETURN __has_cpp_attribute(noreturn)
	#elif (LBAL_CONFIG_cpp_version >= 201103L)
		#define LBAL_CPP11_ATTRIBUTE_NORETURN 200809L
	#endif


	//	C++14 features

	#if (__cpp_aggregate_nsdmi >= 201304L)
		#define LBAL_CPP14_AGGREGATE_NSDMI __cpp_aggregate_nsdmi
	#elif (LBAL_CONFIG_cpp_version >= 201402L)
		#define LBAL_CPP14_AGGREGATE_NSDMI 201304L
	#endif

	#if (__cpp_binary_literals >= 201304L)
		#define LBAL_CPP14_BINARY_LITERALS __cpp_binary_literals
	#elif (LBAL_CONFIG_cpp_version >= 201402L)
		#define LBAL_CPP14_BINARY_LITERALS 201304L
	#endif

	#if (__cpp_constexpr >= 201304L)
		#define LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS __cpp_constexpr
	#elif (LBAL_CONFIG_cpp_version >= 201402L)
		#define LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS 201304L
	#endif

	#if (__cpp_decltype_auto >= 201304L)
		#define LBAL_CPP14_DECLTYPE_AUTO __cpp_decltype_auto
	#elif (LBAL_CONFIG_cpp_version >= 201402L)
		#define LBAL_CPP14_DECLTYPE_AUTO 201304L
	#endif

	#if (__cpp_generic_lambdas >= 201304L)
		#define LBAL_CPP14_GENERIC_LAMBDAS __cpp_generic_lambdas
	#elif (LBAL_CONFIG_cpp_version >= 201402L)
		#define LBAL_CPP14_GENERIC_LAMBDAS 201304L
	#endif

	#if (__cpp_init_captures >= 201304L)
		#define LBAL_CPP14_INIT_CAPTURES __cpp_init_captures
	#elif (LBAL_CONFIG_cpp_version >= 201402L)
		#define LBAL_CPP14_INIT_CAPTURES 201304L
	#endif

	#if (__cpp_return_type_deduction >= 201304L)
		#define LBAL_CPP14_RETURN_TYPE_DEDUCTION __cpp_return_type_deduction
	#elif (LBAL_CONFIG_cpp_version >= 201402L)
		#define LBAL_CPP14_RETURN_TYPE_DEDUCTION 201304L
	#endif

	//	As of vanilla clang 8, this is disabled by default in order to avoid
	//	ABI-breaking changes. It’s unclear when it will be enabled by default.
	#if (__cpp_sized_deallocation >= 201304L)
		#define LBAL_CPP14_SIZED_DEALLOCATION __cpp_sized_deallocation
	#endif

	#if (__cpp_variable_templates >= 201304L)
		#define LBAL_CPP14_VARIABLE_TEMPLATES __cpp_variable_templates
	#elif (LBAL_CONFIG_cpp_version >= 201402L)
		#define LBAL_CPP14_VARIABLE_TEMPLATES 201304L
	#endif

	#if defined(__has_cpp_attribute) && (__has_cpp_attribute(deprecated) >= 201309L)
		#define LBAL_CPP14_ATTRIBUTE_DEPRECATED __has_cpp_attribute(deprecated)
	#elif (LBAL_CONFIG_cpp_version >= 201402L)
		#define LBAL_CPP14_ATTRIBUTE_DEPRECATED 201309L
	#endif


	//	C++17 features

	#if (__cpp_aggregate_bases >= 201603L)
		#define LBAL_CPP17_AGGREGATE_BASES __cpp_aggregate_bases
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_AGGREGATE_BASES 201603L
	#endif

	#if (__cpp_aligned_new >= 201606L)
		#define LBAL_CPP17_ALIGNED_NEW __cpp_aligned_new
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_ALIGNED_NEW 201606L
	#endif

	#if (__cpp_capture_star_this >= 201603)
		#define LBAL_CPP17_CAPTURE_STAR_THIS __cpp_capture_star_this
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_CAPTURE_STAR_THIS 201603
	#endif

	#if (__cpp_constexpr >= 201603L)
		#define LBAL_CPP17_CONSTEXPR_LAMBDA __cpp_constexpr
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_CONSTEXPR_LAMBDA 201603L
	#endif

	#if (__cpp_deduction_guides >= 201606L)
		#define LBAL_CPP17_DEDUCTION_GUIDES __cpp_deduction_guides
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_DEDUCTION_GUIDES 201606L
	#endif

	#if (__cpp_deduction_guides >= 201611L)
		#define LBAL_CPP17_DEDUCTION_GUIDES_NB __cpp_deduction_guides
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_DEDUCTION_GUIDES_NB 201611L
	#endif

	#if (__cpp_deduction_guides >= 201703L)
		#define LBAL_CPP17_DEDUCTION_GUIDES_DR __cpp_deduction_guides
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_DEDUCTION_GUIDES_DR 201703L
	#endif

	#if (__cpp_enumerator_attributes >= 201411L)
		#define LBAL_CPP17_ENUMERATOR_ATTRIBUTES __cpp_enumerator_attributes
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_ENUMERATOR_ATTRIBUTES 201411L
	#endif

	#if (__cpp_fold_expressions >= 201411L)
		#define LBAL_CPP17_FOLD_EXPRESSIONS __cpp_fold_expressions
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_FOLD_EXPRESSIONS 201411L
	#endif

	#if (__cpp_fold_expressions >= 201603L)
		#define LBAL_CPP17_FOLD_EXPRESSIONS_REVISED __cpp_fold_expressions
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_FOLD_EXPRESSIONS_REVISED 201603L
	#endif

	#if (__cpp_guaranteed_copy_elision >= 201606L)
		#define LBAL_CPP17_GUARANTEED_COPY_ELISION __cpp_guaranteed_copy_elision
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_GUARANTEED_COPY_ELISION 201606L
	#endif

	#if (__cpp_hex_float >= 201603L)
		#define LBAL_CPP17_HEX_FLOAT __cpp_hex_float
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_HEX_FLOAT 201603L
	#endif

	#if (__cpp_if_constexpr >= 201606L)
		#define LBAL_CPP17_IF_CONSTEXPR __cpp_if_constexpr
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_IF_CONSTEXPR 201606L
	#endif

	#if (__cpp_inheriting_constructors >= 201511L)
		#define LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED __cpp_inheriting_constructors
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED 201511L
	#endif

	#if (__cpp_inline_variables >= 201606L)
		#define LBAL_CPP17_INLINE_VARIABLES __cpp_inline_variables
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_INLINE_VARIABLES 201606L
	#endif

	#if (__cpp_namespace_attributes >= 201411L)
		#define LBAL_CPP17_NAMESPACE_ATTRIBUTES __cpp_namespace_attributes
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_NAMESPACE_ATTRIBUTES 201411L
	#endif

	#if (__cpp_noexcept_function_type >= 201510L)
		#define LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE __cpp_noexcept_function_type
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE 201510L
	#endif

	#if (__cpp_nontype_template_args >= 201411L)
		#define LBAL_CPP17_NONTYPE_TEMPLATE_ARGS __cpp_nontype_template_args
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_NONTYPE_TEMPLATE_ARGS 201411L
	#endif

	#if (__cpp_nontype_template_parameter_auto >= 201606L)
		#define LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO __cpp_nontype_template_parameter_auto
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO 201606L
	#endif

	#if (__cpp_range_based_for >= 201603L)
		#define LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED __cpp_range_based_for
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED 201603L
	#endif

	#if (__cpp_static_assert >= 201411L)
		#define LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE __cpp_static_assert
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE 201411L
	#endif

	#if (__cpp_structured_bindings >= 201606L)
		#define LBAL_CPP17_STRUCTURED_BINDINGS __cpp_structured_bindings
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_STRUCTURED_BINDINGS 201606L
	#endif

	//	As of clang 8, this is disabled by default in order to avoid a defect
	//	introduced by the associated proposal (which was intended to resolve
	//	another defect).
	#if (__cpp_template_template_args >= 201611L)
		#define LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS __cpp_template_template_args
	#endif

	#if (__cpp_variadic_using >= 201611L)
		#define LBAL_CPP17_VARIADIC_USING __cpp_variadic_using
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_VARIADIC_USING 201611L
	#endif

	#if defined(__has_cpp_attribute) && (__has_cpp_attribute(fallthrough) >= 201603L)
		#define LBAL_CPP17_ATTRIBUTE_FALLTHROUGH __has_cpp_attribute(fallthrough)
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_ATTRIBUTE_FALLTHROUGH 201603L
	#endif

	#if defined(__has_cpp_attribute) && (__has_cpp_attribute(maybe_unused) >= 201603L)
		#define LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED __has_cpp_attribute(maybe_unused)
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED 201603L
	#endif

	#if defined(__has_cpp_attribute) && (__has_cpp_attribute(nodiscard) >= 201603L)
		#define LBAL_CPP17_ATTRIBUTE_NODISCARD __has_cpp_attribute(nodiscard)
	#elif (LBAL_CONFIG_cpp_version >= 201703L)
		#define LBAL_CPP17_ATTRIBUTE_NODISCARD 201603L
	#endif


	//	C++2a features

	#define LBAL_CPP2A_INTEGRATING_OUR_FEATURE_TEST_MACROS 1L

	//	__SEEME__ None of these have SD-6 macros, so we rely on a compiler
	//	version check and a language test.
	#if (__clang_major__ >= 6) && (LBAL_CONFIG_cpp_version > 201703L)
		#define LBAL_CPP2A_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS 1L
		#define LBAL_CPP2A_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS 1L
		#define LBAL_CPP2A_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS 1L
		#define LBAL_CPP2A_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION	1L
	#endif

	#if (__clang_major__ >= 8) && (LBAL_CONFIG_cpp_version > 201703L)
		#define LBAL_CPP2A_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS 1L
		#define LBAL_CPP2A_INIT_STATEMENTS_FOR_RANGE_BASED_FOR 1L
	#endif

	#if (__clang_major__ >= 9) && (LBAL_CONFIG_cpp_version > 201703L)
		#define LBAL_CPP2A_CONSTEXPR_VIRTUAL_FUNCTION 1L
		#define LBAL_CPP2A_PACK_EXPANSION_IN_LAMBDA_INIT_CAPTURE 1L
		#define LBAL_CPP2A_TEMPLATE_PARAMETER_LIST_FOR_GENERIC_LAMBDAS 1L
		#define LBAL_CPP2A_VA_OPT 1L
	#endif

	#if (__clang_major__ >= 10) && (LBAL_CONFIG_cpp_version > 201703L)
		#define LBAL_CPP2A_DESIGNATED_INITIALIZERS 1L
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

	#if defined(__has_cpp_attribute) && (__has_cpp_attribute(likely) >= 201803L)
		#define LBAL_CPP2A_ATTRIBUTE_LIKELY __has_cpp_attribute(likely)
	#endif

	#if defined(__has_cpp_attribute) && (__has_cpp_attribute(nodiscard) >= 201907L)
		#define LBAL_CPP2A_ATTRIBUTE_NODISCARD_EXPANDED __has_cpp_attribute(nodiscard)
	#endif

	#if defined(__has_cpp_attribute) && (__has_cpp_attribute(no_unique_address) >= 201803L)
		#define LBAL_CPP2A_ATTRIBUTE_NO_UNIQUE_ADDRESS __has_cpp_attribute(no_unique_address)
	#endif

	#if defined(__has_cpp_attribute) && (__has_cpp_attribute(unlikely) >= 201803L)
		#define LBAL_CPP2A_ATTRIBUTE_UNLIKELY __has_cpp_attribute(unlikely)
	#endif


	//	intrinsic functions
	#define LBAL_HINT_likely(LBAL_expr_)  __builtin_expect (LBAL_expr_, true)
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


	//	Set up identifiers
	#define LBAL_NAME_COMPILER u8"clang version " __clang_version__
	#define LBAL_TARGET_COMPILER_CLANG 1
#else
	#error "lbalCompilerClang.hpp was directly included while using the wrong compiler"
#endif
