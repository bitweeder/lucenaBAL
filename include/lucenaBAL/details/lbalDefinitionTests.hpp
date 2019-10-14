/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“DefinitionTests.hpp”
	Copyright © 2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See lbalFeatureSetup.hpp for descriptions of the various macros and flags.

------------------------------------------------------------------------------*/


#pragma once


//	lbal
#include <lucenaBAL/lbalConfig.hpp>


/*------------------------------------------------------------------------------
	Definition Tests

	Note that none of the LBAL_XXX macros are set to 0 until after the 
	definition tests, so it’s sufficient to simply test them for existence. 
	Just to be sure, though, we make sure someone didn’t define one of these 
	behind our backs, with the following exceptions:

		- LBAL_TARGET_OS_xxx should be set by the build system or in some
			similar fashion, as otherwise there may be no way to differentiate
			between certain platforms.

		- LBAL_TARGET_API_xxx can be set by the build system or in some
			similar fashion to avoid ambiguities (e.g., determine whether we’re
			targeting Carbon or Cocoa APIs deuner older MacOS X’s). It’s not
			generally necessary to do this any more.
*/

#if !defined (LBAL_TARGET_OS_X11) && \
	!defined (LBAL_TARGET_OS_MACOS) && \
	!defined (LBAL_TARGET_OS_WINAPI) && \
	!defined (LBAL_TARGET_OS_IOS) && \
	!defined (LBAL_TARGET_OS_IOS_SIM)

	#error "A LBAL_TARGET_OS_xxx token must be defined externally at build time."
#endif	//	LBAL_TARGET_OS check

#if defined (LBAL_FEATURE_UTF16_FILE_SYSTEM)
	#error "Don’t define LBAL_FEATURE_UTF16_FILE_SYSTEM externally."
#endif	//	LBAL_FEATURE_UTF16_FILE_SYSTEM

#if defined (LBAL_NAME_COMPILER)
#error "Don’t define LBAL_NAME_COMPILER externally."
#endif	//	LBAL_NAME_COMPILER

#if defined (LBAL_TARGET_COMPILER_CLANG) || \
	defined (LBAL_TARGET_COMPILER_GCC) || \
	defined (LBAL_TARGET_COMPILER_MSVC)

#error "Don’t define LBAL_TARGET_COMPILER_xxx externally."
#endif	//	LBAL_TARGET_COMPILER check

#if defined (LBAL_TARGET_CPU_X86) || \
	defined (LBAL_TARGET_CPU_X86_64) || \
	defined (LBAL_TARGET_CPU_IA64) || \
	defined (LBAL_TARGET_CPU_ARM) || \
	defined (LBAL_TARGET_CPU_ARM_64)

#error "Don’t define LBAL_TARGET_CPU_xxx externally."
#endif	//	LBAL_TARGET_CPU check

#if defined (LBAL_TARGET_CPU_FAMILY_X86) || \
	defined (LBAL_TARGET_CPU_FAMILY_ARM)

#error "Don’t define LBAL_TARGET_CPU_xxx_FAMILY externally."
#endif	//	LBAL_TARGET_CPU_FAMILY check

#if defined (LBAL_TARGET_VEC_SSE) || \
	defined (LBAL_TARGET_VEC_SSE2) || \
	defined (LBAL_TARGET_VEC_SSE3) || \
	defined (LBAL_TARGET_VEC_SSE41) || \
	defined (LBAL_TARGET_VEC_SSE42) || \
	defined (LBAL_TARGET_VEC_AVX) || \
	defined (LBAL_TARGET_VEC_AVX2)

#error "Don’t define LBAL_TARGET_VEC_xxx externally."
#endif	//	LBAL_TARGET_VEC check

#if defined (LBAL_TARGET_RT_LITTLE_ENDIAN) || \
	defined (LBAL_TARGET_RT_BIG_ENDIAN) || \
	defined (LBAL_TARGET_RT_32_BIT) || \
	defined (LBAL_TARGET_RT_64_BIT) || \
	defined (LBAL_TARGET_RT_COFF) || \
	defined (LBAL_TARGET_RT_ELF) || \
	defined (LBAL_TARGET_RT_MACHO) || \
	defined (LBAL_TARGET_RT_WASM)

#error "Don’t define LBAL_TARGET_RT_xxx externally."
#endif	//	LBAL_TARGET_RT check

#if defined (LBAL_TYPE_HAS_INT64) || \
	defined (LBAL_TYPE_HAS_INT128) || \
	defined (LBAL_TYPE_EXACT_WIDTH_INTEGERS) || \
	defined (LBAL_TYPE_DOUBLE_GT_FLOAT) || \
	defined (LBAL_TYPE_LONG_DOUBLE_GT_DOUBLE) || \
	defined (LBAL_TYPE_WCHAR_T_IS_16_BITS)

#error "Don’t define LBAL_TYPE_xxx externally."
#endif	//	LBAL_TYPE check

#if defined (LBAL_CPP98_EXCEPTIONS) || \
	defined (LBAL_CPP98_RTTI)

#error "Don’t define LBAL_CPP98_xxx externally."
#endif	//	LBAL_CPP98 check

#if defined (LBAL_CPP11_ALIAS_TEMPLATES) || \
	defined (LBAL_CPP11_ATTRIBUTES) || \
	defined (LBAL_CPP11_ATTRIBUTES) || \
	defined (LBAL_CPP11_CONSTEXPR) || \
	defined (LBAL_CPP11_DECLTYPE) || \
	defined (LBAL_CPP11_DELEGATING_CONSTRUCTORS) || \
	defined (LBAL_CPP11_INHERITING_CONSTRUCTORS) || \
	defined (LBAL_CPP11_INITIALIZER_LISTS) || \
	defined (LBAL_CPP11_LAMBDAS) || \
	defined (LBAL_CPP11_NSDMI) || \
	defined (LBAL_CPP11_RANGE_BASED_FOR) || \
	defined (LBAL_CPP11_RAW_STRINGS) || \
	defined (LBAL_CPP11_REF_QUALIFIERS) || \
	defined (LBAL_CPP11_RVALUE_REFERENCES) || \
	defined (LBAL_CPP11_STATIC_ASSERT) || \
	defined (LBAL_CPP11_THREADSAFE_STATIC_INIT) || \
	defined (LBAL_CPP11_UNICODE_CHARACTERS) || \
	defined (LBAL_CPP11_UNICODE_LITERALS) || \
	defined (LBAL_CPP11_USER_DEFINED_LITERALS) || \
	defined (LBAL_CPP11_VARIADIC_TEMPLATES)

#error "Don’t define LBAL_CPP11_xxx externally."
#endif	//	LBAL_CPP11 check

#if defined (LBAL_CPP14_AGGREGATE_NSDMI) || \
	defined (LBAL_CPP14_BINARY_LITERALS) || \
	defined (LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS) || \
	defined (LBAL_CPP14_DECLTYPE_AUTO) || \
	defined (LBAL_CPP14_GENERIC_LAMBDAS) || \
	defined (LBAL_CPP14_INIT_CAPTURES) || \
	defined (LBAL_CPP14_RETURN_TYPE_DEDUCTION) || \
	defined (LBAL_CPP14_SIZED_DEALLOCATION) || \
	defined (LBAL_CPP14_VARIABLE_TEMPLATES)
#error "Don’t define LBAL_CPP14_xxx externally."
#endif	//	LBAL_CPP14 check

#if defined (LBAL_CPP17_AGGREGATE_BASES) || \
	defined (LBAL_CPP17_ALIGNED_NEW) || \
	defined (LBAL_CPP17_CAPTURE_STAR_THIS) || \
	defined (LBAL_CPP17_CONSTEXPR_LAMBDA) || \
	defined (LBAL_CPP17_DEDUCTION_GUIDES) || \
	defined (LBAL_CPP17_DEDUCTION_GUIDES_DR) || \
	defined (LBAL_CPP17_DEDUCTION_GUIDES_NB) || \
	defined (LBAL_CPP17_ENUMERATOR_ATTRIBUTES) || \
	defined (LBAL_CPP17_FOLD_EXPRESSIONS) || \
	defined (LBAL_CPP17_FOLD_EXPRESSIONS_REVISED) || \
	defined (LBAL_CPP17_GUARANTEED_COPY_ELISION) || \
	defined (LBAL_CPP17_HEX_FLOAT) || \
	defined (LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED) || \
	defined (LBAL_CPP17_INLINE_VARIABLES) || \
	defined (LBAL_CPP17_NAMESPACE_ATTRIBUTES) || \
	defined (LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE) || \
	defined (LBAL_CPP17_NONTYPE_TEMPLATE_ARGS) || \
	defined (LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO) || \
	defined (LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED) || \
	defined (LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE) || \
	defined (LBAL_CPP17_STRUCTURED_BINDINGS) || \
	defined (LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS) || \
	defined (LBAL_CPP17_VARIADIC_USING)
#error "Don’t define LBAL_CPP17_xxx externally."
#endif	//	LBAL_CPP17 check

#if defined (LBAL_CPP2A_AGGREGATE_PAREN_INIT) || \
	defined (LBAL_CPP2A_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS) || \
	defined (LBAL_CPP2A_ATTRIBUTE_LIKELY) || \
	defined (LBAL_CPP2A_ATTRIBUTE_NO_UNIQUE_ADDRESS) || \
	defined (LBAL_CPP2A_ATTRIBUTE_UNLIKELY) || \
	defined (LBAL_CPP2A_ATTRIBUTES_LIKELY_AND_UNLIKELY) || \
	defined (LBAL_CPP2A_CHAR8_T) || \
	defined (LBAL_CPP2A_CONCEPTS) || \
	defined (LBAL_CPP2A_CONDITIONAL_EXPLICIT) || \
	defined (LBAL_CPP2A_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS) || \
	defined (LBAL_CPP2A_CONSTEXPR_DYNAMIC_ALLOC) || \
	defined (LBAL_CPP2A_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION) || \
	defined (LBAL_CPP2A_CONSTEXPR_VIRTUAL_FUNCTION) || \
	defined (LBAL_CPP2A_CONSTINIT) || \
	defined (LBAL_CPP2A_COROUTINES) || \
	defined (LBAL_CPP2A_DEDUCTION_GUIDES_FOR_AGGREGATES) || \
	defined (LBAL_CPP2A_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS) || \
	defined (LBAL_CPP2A_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS) || \
	defined (LBAL_CPP2A_DESIGNATED_INITIALIZERS) || \
	defined (LBAL_CPP2A_DESTROYING_DELETE) || \
	defined (LBAL_CPP2A_INIT_STATEMENTS_FOR_RANGE_BASED_FOR) || \
	defined (LBAL_CPP2A_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION) || \
	defined (LBAL_CPP2A_INTEGRATING_OUR_FEATURE_TEST_MACROS) || \
	defined (LBAL_CPP2A_MODULES) || \
	defined (LBAL_CPP2A_NONTYPE_TEMPLATE_PARAMETER_CLASS) || \
	defined (LBAL_CPP2A_PACK_EXPANSION_IN_LAMBDA_INIT_CAPTURE) || \
	defined (LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR) || \
	defined (LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR_TUNEUP) || \
	defined (LBAL_CPP2A_TEMPLATE_PARAMETER_LIST_FOR_GENERIC_LAMBDAS) || \
	defined (LBAL_CPP2A_TYPENAME_OPTIONAL) || \
	defined (LBAL_CPP2A_USING_ENUM) || \
	defined (LBAL_CPP2A_VA_OPT)

#error "Don’t define LBAL_CPP2A_xxx externally."
#endif	//	LBAL_CPP2A check

#if defined (LBAL_CPPTS_ATTRIBUTE_ASSERT) || \
	defined (LBAL_CPPTS_ATTRIBUTE_ENSURES) || \
	defined (LBAL_CPPTS_ATTRIBUTE_EXPECTS) || \
	defined (LBAL_CPPTS_CONTRACTS)
#error "Don’t define LBAL_CPPTS_xxx externally."
#endif	//	LBAL_CPPTS check

#if defined (LBAL_C99_PREPROCESSOR)
#error "Don’t define LBAL_C99_xxx externally."
#endif	//	LBAL_C99 check

#if defined (LBAL_CLASS_FORCE_EBCO)
#error "Don’t define LBAL_CLASS_xxx externally."
#endif	//	LBAL_CLASS_xxx check

#if defined (LBAL_FUNC_CALL_C) || \
	defined (LBAL_FUNC_CALL_STD) || \
	defined (LBAL_FUNC_CALLBACK_C) || \
	defined (LBAL_FUNC_CALLBACK_STD)

#error "Don’t define LBAL_FUNC_xxx externally."
#endif	//	LBAL_FUNC_xxx check

#if defined (LBAL_HINT_likely) || \
	defined (LBAL_HINT_unlikely)

#error "Don’t define LBAL_BUILTIN_xxx externally."
#endif	//	LBAL_BUILTIN_xxx check


/*
	__SEEME__ This section is fairly limited since LBAL_LIBCPP tokens _can_ be
	legitimately set elsewhere, typically because of platform or compiler
	limitations.
*/

#if defined (LBAL_NAME_STANDARD_LIBRARY)
#error "Don’t define LBAL_NAME_STANDARD_LIBRARY externally."
#endif	//	LBAL_NAME_STANDARD_LIBRARY

#if defined (LBAL_TARGET_STANDARD_LIBRARY_LIBCPP) \
	|| defined (LBAL_TARGET_STANDARD_LIBRARY_MSVC) \
	|| defined (LBAL_TARGET_STANDARD_LIBRARY_LIBSTDCPP) \
	|| defined (LBAL_TARGET_STANDARD_LIBRARY_STDLIBCPP)

#error "Don’t define LBAL_TARGET_STANDARD_LIBRARY_xxx externally."
#endif	//	LBAL_TARGET_STANDARD_LIBRARY check
