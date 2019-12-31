/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalCompilerSetup.hpp”
	Copyright © 2007-2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

------------------------------------------------------------------------------*/


#pragma once


//	lbal
#include <lucenaBAL/details/lbalConfig.hpp>
#include <lucenaBAL/details/lbalKnownVersions.hpp>
#include <lucenaBAL/details/compilers/lbalDetectCompiler.hpp>


/*------------------------------------------------------------------------------
	Compiler-specific Pre-initialization
*/

#if LBAL_TARGET_COMPILER_APPLE_CLANG
	#include <lucenaBAL/details/compilers/lbalAppleClangInitialization.hpp>
#elif LBAL_TARGET_COMPILER_VANILLA_CLANG
	#include <lucenaBAL/details/compilers/lbalClangInitialization.hpp>
#elif LBAL_TARGET_COMPILER_VANILLA_GCC
	#include <lucenaBAL/details/compilers/lbalGCCInitialization.hpp>
#elif LBAL_TARGET_COMPILER_VANILLA_MSVC
	#include <lucenaBAL/details/compilers/lbalMSVCInitialization.hpp>
#else
	#error "Unsupported compiler"
#endif


/*------------------------------------------------------------------------------
	Common Compiler Initialization

	Perform feature tests based on SD-6 macro definitions. Note that token
	values may be overridden during initialization by the compiler, so we
	explicitly check that the tokens are undefined before we set them, as we
	otherwise can’t know if a given token was set during the initialization
	phase.

	__SEEME__ Implicit in these tests is that if an SD-6 macro is defined, it
	is assumed the feature is and should be available. Specifically, we don’t
	perform Standard version tests here to ensure that features are constrained
	to their associated C++ dialects. In a situation where a compiler is known
	to incorrectly define a macro when a feature is actually unavailable—even
	as a back-port—we’ll set our own tokens correctly during compiler
	initialization before we ever get here. This approach allows features to be
	made available as extensions or as previews in earlier Standard
	implementations.

	__SEEME__ Note that tokens may not necessarily be initialized after these
	tests complete; they may subsequently be assigned a value during the
	compiler’s post-initialization phase, or will otherwise be explicitly
	`0`-initialized at the end of feature setup.
*/

//	C++98 features
//	These can be conditionally disabled.

#if !defined(LBAL_CPP98_EXCEPTIONS) && (__cpp_exceptions >= 199711L)
	#define LBAL_CPP98_EXCEPTIONS __cpp_exceptions
#endif

#if !defined(LBAL_CPP98_RTTI) && (__cpp_rtti >= 199711L)
	#define LBAL_CPP98_RTTI __cpp_rtti
#endif


//	C++11 features.
//
//	We check for “C++11 or greater” (as opposed to “greater than C++98”)
//	since our earliest supported dialect is C++11; these should (mostly) always
//	be available, though we still go through the formality of checking.
//	Individual compilers may still override, of course.
#if LBAL_cpp_version >= LBAL_CPP11_VERSION
	#if !defined(LBAL_CPP11_ALIAS_TEMPLATES)
		#if (__cpp_alias_templates >= 200704L)
			#define LBAL_CPP11_ALIAS_TEMPLATES __cpp_alias_templates
		#else
			#define LBAL_CPP11_ALIAS_TEMPLATES 200704L
		#endif
	#endif

	#if !defined(LBAL_CPP11_ATTRIBUTES)
		#if (__cpp_attributes >= 200809L)
			#define LBAL_CPP11_ATTRIBUTES __cpp_attributes
		#else
			#define LBAL_CPP11_ATTRIBUTES 200809L
		#endif
	#endif

	#if !defined(LBAL_CPP11_CONSTEXPR)
		#if (__cpp_constexpr >= 200704L)
			#define LBAL_CPP11_CONSTEXPR __cpp_constexpr
		#else
			#define LBAL_CPP11_CONSTEXPR 200704L
		#endif
	#endif

	#if !defined(LBAL_CPP11_DECLTYPE)
		#if (__cpp_decltype >= 200704L)
			#define LBAL_CPP11_DECLTYPE __cpp_decltype
		#else
			#define LBAL_CPP11_DECLTYPE 200704L
		#endif
	#endif

	#if !defined(LBAL_CPP11_DELEGATING_CONSTRUCTORS)
		#if (__cpp_delegating_constructors >= 200604L)
			#define LBAL_CPP11_DELEGATING_CONSTRUCTORS __cpp_delegating_constructors
		#else
			#define LBAL_CPP11_DELEGATING_CONSTRUCTORS 200604L
		#endif
	#endif

	#if !defined(LBAL_CPP11_INHERITING_CONSTRUCTORS)
		#if (__cpp_inheriting_constructors >= 200802L)
			#define LBAL_CPP11_INHERITING_CONSTRUCTORS __cpp_inheriting_constructors
		#else
			#define LBAL_CPP11_INHERITING_CONSTRUCTORS 200802L
		#endif
	#endif

	#if !defined(LBAL_CPP11_INITIALIZER_LISTS)
		#if (__cpp_initializer_lists >= 200806L)
			#define LBAL_CPP11_INITIALIZER_LISTS __cpp_initializer_lists
		#else
			#define LBAL_CPP11_INITIALIZER_LISTS 200806L
		#endif
	#endif

	#if !defined(LBAL_CPP11_LAMBDAS)
		#if (__cpp_lambdas >= 200907L)
			#define LBAL_CPP11_LAMBDAS __cpp_lambdas
		#else
			#define LBAL_CPP11_LAMBDAS 200907L
		#endif
	#endif

	#if !defined(LBAL_CPP11_NSDMI)
		#if (__cpp_nsdmi >= 200809L)
			#define LBAL_CPP11_NSDMI __cpp_nsdmi
		#else
			#define LBAL_CPP11_NSDMI 200809L
		#endif
	#endif

	#if !defined(LBAL_CPP11_RANGE_BASED_FOR)
		#if (__cpp_range_based_for >= 200907L)
			#define LBAL_CPP11_RANGE_BASED_FOR __cpp_range_based_for
		#else
			#define LBAL_CPP11_RANGE_BASED_FOR 200907L
		#endif
	#endif

	#if !defined(LBAL_CPP11_RAW_STRINGS)
		#if (__cpp_raw_strings >= 200710L)
			#define LBAL_CPP11_RAW_STRINGS __cpp_raw_strings
		#else
			#define LBAL_CPP11_RAW_STRINGS 200710L
		#endif
	#endif

	#if !defined(LBAL_CPP11_REF_QUALIFIERS)
		#if (__cpp_ref_qualifiers >= 200710L)
			#define LBAL_CPP11_REF_QUALIFIERS __cpp_ref_qualifiers
		#else
			#define LBAL_CPP11_REF_QUALIFIERS 200710L
		#endif
	#endif

	#if !defined(LBAL_CPP11_RVALUE_REFERENCES)
		#if (__cpp_rvalue_references >= 200610L)
			#define LBAL_CPP11_RVALUE_REFERENCES __cpp_rvalue_references
		#else
			#define LBAL_CPP11_RVALUE_REFERENCES 200610L
		#endif
	#endif

	#if !defined(LBAL_CPP11_STATIC_ASSERT)
		#if (__cpp_static_assert >= 200410L)
			#define LBAL_CPP11_STATIC_ASSERT __cpp_static_assert
		#else
			#define LBAL_CPP11_STATIC_ASSERT 200410L
		#endif
	#endif

	#if !defined(LBAL_CPP11_THREADSAFE_STATIC_INIT)
		#if (__cpp_threadsafe_static_init >= 200806L)
			#define LBAL_CPP11_THREADSAFE_STATIC_INIT \
					__cpp_threadsafe_static_init
		#else
			#define LBAL_CPP11_THREADSAFE_STATIC_INIT 200806L
		#endif
	#endif

	#if !defined(LBAL_CPP11_UNICODE_CHARACTERS)
		#if (__cpp_unicode_characters >= 200704L)
			#define LBAL_CPP11_UNICODE_CHARACTERS __cpp_unicode_characters
		#else
			#define LBAL_CPP11_UNICODE_CHARACTERS 200704L
		#endif
	#endif

	#if !defined(LBAL_CPP11_UNICODE_LITERALS)
		#if (__cpp_unicode_literals >= 200710L)
			#define LBAL_CPP11_UNICODE_LITERALS __cpp_unicode_literals
		#else
			#define LBAL_CPP11_UNICODE_LITERALS 200710L
		#endif
	#endif

	#if !defined(LBAL_CPP11_USER_DEFINED_LITERALS)
		#if (__cpp_user_defined_literals >= 200809L)
			#define LBAL_CPP11_USER_DEFINED_LITERALS __cpp_user_defined_literals
		#else
			#define LBAL_CPP11_USER_DEFINED_LITERALS 200809L
		#endif
	#endif

	#if !defined(LBAL_CPP11_VARIADIC_TEMPLATES)
		#if (__cpp_variadic_templates >= 200704L)
			#define LBAL_CPP11_VARIADIC_TEMPLATES __cpp_variadic_templates
		#else
			#define LBAL_CPP11_VARIADIC_TEMPLATES 200704L
		#endif
	#endif
#endif	//	LBAL_CPP11_VERSION


//	C++14 features

#if !defined(LBAL_CPP14_AGGREGATE_NSDMI) && (__cpp_aggregate_nsdmi >= 201304L)
	#define LBAL_CPP14_AGGREGATE_NSDMI __cpp_aggregate_nsdmi
#endif

#if !defined(LBAL_CPP14_BINARY_LITERALS) && (__cpp_binary_literals >= 201304L)
	#define LBAL_CPP14_BINARY_LITERALS __cpp_binary_literals
#endif

#if !defined(LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS) \
		&& (__cpp_constexpr >= 201304L)
	#define LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS __cpp_constexpr
#endif

#if !defined(LBAL_CPP14_DECLTYPE_AUTO) && (__cpp_decltype_auto >= 201304L)
	#define LBAL_CPP14_DECLTYPE_AUTO __cpp_decltype_auto
#endif

#if !defined(LBAL_CPP14_GENERIC_LAMBDAS) && (__cpp_generic_lambdas >= 201304L)
	#define LBAL_CPP14_GENERIC_LAMBDAS __cpp_generic_lambdas
#endif

#if !defined(LBAL_CPP14_INIT_CAPTURES) && (__cpp_init_captures >= 201304L)
	#define LBAL_CPP14_INIT_CAPTURES __cpp_init_captures
#endif

#if !defined(LBAL_CPP14_RETURN_TYPE_DEDUCTION) \
		&& (__cpp_return_type_deduction >= 201304L)
	#define LBAL_CPP14_RETURN_TYPE_DEDUCTION __cpp_return_type_deduction
#endif

#if !defined(LBAL_CPP14_SIZED_DEALLOCATION) \
		&& (__cpp_sized_deallocation >= 201304L)
	#define LBAL_CPP14_SIZED_DEALLOCATION __cpp_sized_deallocation
#endif

#if !defined(LBAL_CPP14_VARIABLE_TEMPLATES) \
		&& (__cpp_variable_templates >= 201304L)
	#define LBAL_CPP14_VARIABLE_TEMPLATES __cpp_variable_templates
#endif


//	C++17 features

#if !defined(LBAL_CPP17_AGGREGATE_BASES) && (__cpp_aggregate_bases >= 201603L)
	#define LBAL_CPP17_AGGREGATE_BASES __cpp_aggregate_bases
#endif

#if !defined(LBAL_CPP17_ALIGNED_NEW) && (__cpp_aligned_new >= 201603L)
	#define LBAL_CPP17_ALIGNED_NEW __cpp_aligned_new
#endif

#if !defined(LBAL_CPP17_CAPTURE_STAR_THIS) \
		&& (__cpp_capture_star_this >= 201603L)
	#define LBAL_CPP17_CAPTURE_STAR_THIS __cpp_capture_star_this
#endif

#if !defined(LBAL_CPP17_CONSTEXPR_LAMBDA) && (__cpp_constexpr >= 201603L)
	#define LBAL_CPP17_CONSTEXPR_LAMBDA __cpp_constexpr
#endif

#if !defined(LBAL_CPP17_DEDUCTION_GUIDES) \
		&& (__cpp_deduction_guides >= 201606L)
	#define LBAL_CPP17_DEDUCTION_GUIDES __cpp_deduction_guides
#endif

#if !defined(LBAL_CPP17_DEDUCTION_GUIDES_NB) \
		&& (__cpp_deduction_guides >= 201611L)
	#define LBAL_CPP17_DEDUCTION_GUIDES_NB __cpp_deduction_guides
#endif

#if !defined(LBAL_CPP17_DEDUCTION_GUIDES_DR) \
		&& (__cpp_deduction_guides >= 201703L)
	#define LBAL_CPP17_DEDUCTION_GUIDES_DR __cpp_deduction_guides
#endif

#if !defined(LBAL_CPP17_ENUMERATOR_ATTRIBUTES) \
		&& (__cpp_enumerator_attributes >= 201411L)
	#define LBAL_CPP17_ENUMERATOR_ATTRIBUTES __cpp_enumerator_attributes
#endif

#if !defined(LBAL_CPP17_FOLD_EXPRESSIONS) \
		&& (__cpp_fold_expressions >= 201411L)
	#define LBAL_CPP17_FOLD_EXPRESSIONS __cpp_fold_expressions
#endif

#if !defined(LBAL_CPP17_FOLD_EXPRESSIONS_REVISED) \
		&& (__cpp_fold_expressions >= 201603L)
	#define LBAL_CPP17_FOLD_EXPRESSIONS_REVISED __cpp_fold_expressions
#endif

#if !defined(LBAL_CPP17_GUARANTEED_COPY_ELISION) \
		&& (__cpp_guaranteed_copy_elision >= 201606L)
	#define LBAL_CPP17_GUARANTEED_COPY_ELISION __cpp_guaranteed_copy_elision
#endif

#if !defined(LBAL_CPP17_HEX_FLOAT) && (__cpp_hex_float >= 201603L)
	#define LBAL_CPP17_HEX_FLOAT __cpp_hex_float
#endif

#if !defined(LBAL_CPP17_IF_CONSTEXPR) && (__cpp_if_constexpr >= 201606L)
	#define LBAL_CPP17_IF_CONSTEXPR __cpp_if_constexpr
#endif

#if !defined(LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED) \
		&& (__cpp_inheriting_constructors >= 201511L)
	#define LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED \
			__cpp_inheriting_constructors
#endif

#if !defined(LBAL_CPP17_INLINE_VARIABLES) \
		&& (__cpp_inline_variables >= 201606L)
	#define LBAL_CPP17_INLINE_VARIABLES __cpp_inline_variables
#endif

#if !defined(LBAL_CPP17_NAMESPACE_ATTRIBUTES) \
		&& (__cpp_namespace_attributes >= 201411L)
	#define LBAL_CPP17_NAMESPACE_ATTRIBUTES __cpp_namespace_attributes
#endif

#if !defined(LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE) \
		&& (__cpp_noexcept_function_type >= 201510L)
	#define LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE __cpp_noexcept_function_type
#endif

#if !defined(LBAL_CPP17_NONTYPE_TEMPLATE_ARGS) \
		&& (__cpp_nontype_template_args >= 201411L)
	#define LBAL_CPP17_NONTYPE_TEMPLATE_ARGS __cpp_nontype_template_args
#endif

#if !defined(LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO) \
		&& (__cpp_nontype_template_parameter_auto >= 201606L)
	#define LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO \
			__cpp_nontype_template_parameter_auto
#endif

#if !defined(LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED) \
		&& (__cpp_range_based_for >= 201603L)
	#define LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED __cpp_range_based_for
#endif

#if !defined(LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE) \
		&& (__cpp_static_assert >= 201411L)
	#define LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE __cpp_static_assert
#endif

#if !defined(LBAL_CPP17_STRUCTURED_BINDINGS) \
		&& (__cpp_structured_bindings >= 201606L)
	#define LBAL_CPP17_STRUCTURED_BINDINGS __cpp_structured_bindings
#endif

#if !defined(LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS) \
		&& (__cpp_template_template_args >= 201611L)
	#define LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS __cpp_template_template_args
#endif

#if !defined(LBAL_CPP17_VARIADIC_USING) \
		&& (__cpp_variadic_using >= 201611L)
	#define LBAL_CPP17_VARIADIC_USING __cpp_variadic_using
#endif


//	C++2a features

#if !defined(LBAL_CPP2A_AGGREGATE_PAREN_INIT) \
		&& (__cpp_aggregate_paren_init >= 201902L)
	#define LBAL_CPP2A_AGGREGATE_PAREN_INIT __cpp_aggregate_paren_init
#endif

#if !defined(LBAL_CPP2A_CHAR8_T) && (__cpp_char8_t >= 201811L)
	#define LBAL_CPP2A_CHAR8_T __cpp_char8_t
#endif

#if !defined(LBAL_CPP2A_CONCEPTS) && (__cpp_concepts >= 201707L)
	#define LBAL_CPP2A_CONCEPTS __cpp_concepts
#endif

#if !defined(LBAL_CPP2A_CONCEPTS_RESPECIFY_RETURN_TYPE_REQUIREMENTS) \
		&& (__cpp_concepts >= 201811L)
	#define LBAL_CPP2A_CONCEPTS_RESPECIFY_RETURN_TYPE_REQUIREMENTS \
			__cpp_concepts
#endif

#if !defined(LBAL_CPP2A_CONCEPTS_REFINE_RETURN_TYPE_REQUIREMENTS) \
		&& (__cpp_concepts >= 201907L)
	#define LBAL_CPP2A_CONCEPTS_REFINE_RETURN_TYPE_REQUIREMENTS \
			__cpp_concepts
#endif

#if !defined(LBAL_CPP2A_CONDITIONAL_EXPLICIT) \
		&& (__cpp_conditional_explicit >= 201806L)
	#define LBAL_CPP2A_CONDITIONAL_EXPLICIT __cpp_conditional_explicit
#endif

#if !defined(LBAL_CPP2A_CONSTEVAL) && (__cpp_consteval >= 201811L)
	#define LBAL_CPP2A_CONSTEVAL __cpp_consteval
#endif

#if !defined(LBAL_CPP2A_CONSTEXPR_VIRTUAL_FUNCTION) \
		&& (__cpp_constexpr >= 201806L)
	#define LBAL_CPP2A_CONSTEXPR_VIRTUAL_FUNCTION __cpp_constexpr
#endif

#if !defined(LBAL_CPP2A_CONSTEXPR_DYNAMIC_POLYMORPHISM) \
		&& (__cpp_constexpr >= 201811L)
	#define LBAL_CPP2A_CONSTEXPR_DYNAMIC_POLYMORPHISM __cpp_constexpr
#endif

#if !defined(LBAL_CPP2A_CONSTEXPR_TRY_CATCH) \
		&& (__cpp_constexpr >= 201811L)
	#define LBAL_CPP2A_CONSTEXPR_TRY_CATCH __cpp_constexpr
#endif

#if !defined(LBAL_CPP2A_CONSTEXPR_UNION_ALTERATION) \
		&& (__cpp_constexpr >= 201811L)
	#define LBAL_CPP2A_CONSTEXPR_UNION_ALTERATION __cpp_constexpr
#endif

#if !defined(LBAL_CPP2A_CONSTEXPR_INTRINSICS) \
		&& (__cpp_constexpr >= 201907L)
	#define LBAL_CPP2A_CONSTEXPR_INTRINSICS __cpp_constexpr
#endif

#if !defined(LBAL_CPP2A_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION) \
		&& (__cpp_constexpr >= 201907L)
	#define LBAL_CPP2A_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION __cpp_constexpr
#endif

#if !defined(LBAL_CPP2A_CONSTEXPR_DYNAMIC_ALLOC) \
		&& (__cpp_constexpr_dynamic_alloc >= 201907L)
	#define LBAL_CPP2A_CONSTEXPR_DYNAMIC_ALLOC __cpp_constexpr_dynamic_alloc
#endif

#if !defined(LBAL_CPP2A_CONSTEXPR_IN_DECLTYPE) \
		&& (__cpp_constexpr_in_decltype >= 201711L)
	#define LBAL_CPP2A_CONSTEXPR_IN_DECLTYPE __cpp_constexpr_in_decltype
#endif

#if !defined(LBAL_CPP2A_CONSTINIT) && (__cpp_constinit >= 201907L)
	#define LBAL_CPP2A_CONSTINIT __cpp_constinit
#endif

#if !defined(LBAL_CPP2A_COROUTINES) && (__cpp_coroutines >= 201902L)
	#define LBAL_CPP2A_COROUTINES __cpp_coroutines
#endif

#if !defined(LBAL_CPP2A_DEDUCTION_GUIDES_FOR_AGGREGATES) \
		&& (__cpp_deduction_guides >= 201907L)
	#define LBAL_CPP2A_DEDUCTION_GUIDES_FOR_AGGREGATES \
			__cpp_deduction_guides
#endif

#if !defined(LBAL_CPP2A_DESIGNATED_INITIALIZERS) \
		&& (__cpp_designated_initializers >= 201707L)
	#define LBAL_CPP2A_DESIGNATED_INITIALIZERS __cpp_designated_initializers
#endif

#if !defined(LBAL_CPP2A_DESTROYING_DELETE) \
		&& (__cpp_impl_destroying_delete >= 201806L)
	#define LBAL_CPP2A_DESTROYING_DELETE __cpp_impl_destroying_delete
#endif

#if !defined(LBAL_CPP2A_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST) \
		&& (__cpp_generic_lambdas >= 201707L)
	#define LBAL_CPP2A_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST \
			__cpp_generic_lambdas
#endif

#if !defined(LBAL_CPP2A_INIT_CAPTURES_PACK_EXPANSION) \
		&& (__cpp_init_captures >= 201803L)
	#define LBAL_CPP2A_INIT_CAPTURES_PACK_EXPANSION __cpp_init_captures
#endif

#if !defined(LBAL_CPP2A_NONTYPE_TEMPLATE_PARAMETER_CLASS) \
		&& (__cpp_modules >= 201907L)
	#define LBAL_CPP2A_NONTYPE_TEMPLATE_PARAMETER_CLASS __cpp_modules
#endif

#if !defined(LBAL_CPP2A_NONTYPE_TEMPLATE_PARAMETER_CLASS) \
		&& (__cpp_nontype_template_parameter_class >= 201806L)
	#define LBAL_CPP2A_NONTYPE_TEMPLATE_PARAMETER_CLASS \
			__cpp_nontype_template_parameter_class
#endif

#if !defined(LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR) \
		&& (__cpp_impl_three_way_comparison >= 201711L)
	#define LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR \
			__cpp_impl_three_way_comparison
#endif

#if !defined(LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR_TUNEUP) \
		&& (__cpp_impl_three_way_comparison >= 201907L)
	#define LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR_TUNEUP \
			__cpp_impl_three_way_comparison
#endif

#if !defined(LBAL_CPP2A_USING_ENUM) && (__cpp_using_enum >= 201907L)
	#define LBAL_CPP2A_USING_ENUM __cpp_using_enum
#endif


//	C++ Attributes
//	__SEEME__ The letter of the C++ attributes proposal disallows the use of
//	__has_cpp_attribute in contexts other than preprocessor conditionals; MSVC
//	honors this, though other compilers generally do not. We adhere to the
//	proposal, even though it will make tracking future iterations on existing
//	attributes more convoluted.

//	C++11 Attributes
//
//	We check for “C++11 or greater” (as opposed to “greater than C++98”)
//	since our earliest supported dialect is C++11; these should (mostly) always
//	be available, though we still go through the formality of checking. We also
//	go through the motions of explicitly checking the SD-6 macro results as a
//	placeholder. Individual compilers may still override these, of course.

#if LBAL_cpp_version >= LBAL_CPP11_VERSION
	#if !defined(LBAL_CPP11_ATTRIBUTE_CARRIES_DEPENDENCY)
		#if defined(__has_cpp_attribute) \
				&& (__has_cpp_attribute(carries_dependency) >= 200809L)
			#define LBAL_CPP11_ATTRIBUTE_CARRIES_DEPENDENCY 200809L
		#else
			#define LBAL_CPP11_ATTRIBUTE_CARRIES_DEPENDENCY 200809L
		#endif
	#endif

	#if !defined(LBAL_CPP11_ATTRIBUTE_NORETURN)
		#if defined(__has_cpp_attribute) \
				&& (__has_cpp_attribute(noreturn) >= 200809L)
			#define LBAL_CPP11_ATTRIBUTE_NORETURN 200809L
		#else
			#define LBAL_CPP11_ATTRIBUTE_NORETURN 200809L
		#endif
	#endif
#endif	//	LBAL_CPP11_VERSION


//	C++14 Attributes

#if !defined(LBAL_CPP14_ATTRIBUTE_DEPRECATED) \
		&& defined(__has_cpp_attribute) \
		&& (__has_cpp_attribute(deprecated) >= 201309L)
	#define LBAL_CPP14_ATTRIBUTE_DEPRECATED 201309L
#endif


//	C++17 Attributes

#if !defined(LBAL_CPP17_ATTRIBUTE_FALLTHROUGH) \
		&& defined(__has_cpp_attribute) \
		&& (__has_cpp_attribute(fallthrough) >= 201603L)
	#define LBAL_CPP17_ATTRIBUTE_FALLTHROUGH 201603L
#endif

#if !defined(LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED) \
		&& defined(__has_cpp_attribute) \
		&& (__has_cpp_attribute(maybe_unused) >= 201603L)
	#define LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED 201603L
#endif

#if !defined(LBAL_CPP17_ATTRIBUTE_NODISCARD) \
		&& defined(__has_cpp_attribute) \
		&& (__has_cpp_attribute(nodiscard) >= 201603L)
	#define LBAL_CPP17_ATTRIBUTE_NODISCARD 201603L
#endif


//	C++2a Attributes

#if !defined(LBAL_CPP2A_ATTRIBUTE_LIKELY) && defined(__has_cpp_attribute) \
		&& (__has_cpp_attribute(likely) >= 201803L)
	#define LBAL_CPP2A_ATTRIBUTE_LIKELY 201803L
#endif

#if !defined(LBAL_CPP2A_ATTRIBUTE_NODISCARD_EXPANDED) \
		&& defined(__has_cpp_attribute) \
		&& (__has_cpp_attribute(nodiscard) >= 201907L)
	#define LBAL_CPP2A_ATTRIBUTE_NODISCARD_EXPANDED 201907L
#endif

#if !defined(LBAL_CPP2A_ATTRIBUTE_NO_UNIQUE_ADDRESS) \
		&& defined(__has_cpp_attribute) \
		&& (__has_cpp_attribute(no_unique_address) >= 201803L)
	#define LBAL_CPP2A_ATTRIBUTE_NO_UNIQUE_ADDRESS 201803L
#endif

#if !defined(LBAL_CPP2A_ATTRIBUTE_UNLIKELY) \
		&& defined(__has_cpp_attribute) \
		&& (__has_cpp_attribute(unlikely) >= 201803L)
	#define LBAL_CPP2A_ATTRIBUTE_UNLIKELY 201803L
#endif


/*------------------------------------------------------------------------------
	Compiler-specific Post-initialization
*/

#if LBAL_TARGET_COMPILER_APPLE_CLANG
	#include <lucenaBAL/details/compilers/lbalAppleClangPostInitialization.hpp>
#elif LBAL_TARGET_COMPILER_VANILLA_CLANG
	#include <lucenaBAL/details/compilers/lbalClangPostInitialization.hpp>
#elif LBAL_TARGET_COMPILER_VANILLA_GCC
	#include <lucenaBAL/details/compilers/lbalGCCPostInitialization.hpp>
#elif LBAL_TARGET_COMPILER_VANILLA_MSVC
	#include <lucenaBAL/details/compilers/lbalMSVCPostInitialization.hpp>
#else
	#error "Unsupported compiler"
#endif


/*------------------------------------------------------------------------------
	Set up the CPU name.
*/

#if LBAL_TARGET_CPU_ARM_64
	#define LBAL_NAME_TARGET_CPU u8"ARM64"
#elif LBAL_TARGET_CPU_ARM
	#define LBAL_NAME_TARGET_CPU u8"ARM"
#elif LBAL_TARGET_CPU_IA64
	#define LBAL_NAME_TARGET_CPU u8"ia64"
#elif LBAL_TARGET_CPU_X86_64
	#define LBAL_NAME_TARGET_CPU u8"x86_64"
#elif LBAL_TARGET_CPU_X86
	#define LBAL_NAME_TARGET_CPU u8"i386"
#endif
