/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalGCCPostInitialization.hpp”
	Copyright © 2019-2020 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/


#pragma once


//	lbal
#include <lucenaBAL/lbalConfig.hpp>
#include <lucenaBAL/details/lbalDetectCompiler.hpp>
#include <lucenaBAL/details/lbalKnownVersions.hpp>


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


	//	C++14 features
	//	Note that SD-6 macros didn’t appear until gcc 7.3, so we have to rely
	//	on compiler and language version checks in earlier iterations. We check
	//	for any Standard version greater than C++11, which will ensure we can
	//	use features which may have been made available as extensions or
	//	previews.

	#if LBAL_cpp_version > LBAL_CPP11_VERSION
		#if !defined(LBAL_CPP14_AGGREGATE_NSDMI) \
				&& (LBAL_GCC_VERSION >= 50000)
			#define LBAL_CPP14_AGGREGATE_NSDMI 201304L
		#endif

		#if !defined(LBAL_CPP14_BINARY_LITERALS) \
				&& (LBAL_GCC_VERSION >= 40900)
			#define LBAL_CPP14_BINARY_LITERALS 201304L
		#endif

		#if !defined(LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS) \
				&& (LBAL_GCC_VERSION >= 50000)
			#define LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS 201304L
		#endif

		#if !defined(LBAL_CPP14_DECLTYPE_AUTO) \
				&& (LBAL_GCC_VERSION >= 40900)
			#define LBAL_CPP14_DECLTYPE_AUTO 201304L
		#endif

		#if !defined(LBAL_CPP14_GENERIC_LAMBDAS) \
				&& (LBAL_GCC_VERSION >= 40900)
			#define LBAL_CPP14_GENERIC_LAMBDAS 201304L
		#endif

		#if !defined(LBAL_CPP14_INIT_CAPTURES) \
				&& (LBAL_GCC_VERSION >= 40900)
			#define LBAL_CPP14_INIT_CAPTURES 201304L
		#endif

		#if !defined(LBAL_CPP14_RETURN_TYPE_DEDUCTION) \
				&& (LBAL_GCC_VERSION >= 40900)
			#define LBAL_CPP14_RETURN_TYPE_DEDUCTION 201304L
		#endif

		//	__SEEME__ `__cpp_sized_deallocation`—and therefor
		//	`LBAL_CPP14_SIZED_DEALLOCATION`—can be conditionally disabled, and
		//	we have no way of telling without the SD-6 macro. For this reason,
		//	we don’t provide a version override.

		#if !defined(LBAL_CPP14_VARIABLE_TEMPLATES) \
				&& (LBAL_GCC_VERSION >= 50000)
			#define LBAL_CPP14_VARIABLE_TEMPLATES 201304L
		#endif
	#endif	//	LBAL_CPP11_VERSION


	//	C++17 features
	//	Note that SD-6 macros didn’t appear until gcc 7.3, so we have to rely
	//	on compiler and language version checks in earlier iterations. We check
	//	for any Standard version greater than C++14, which will ensure we can
	//	use features which may have been made available as extensions or
	//	previews.

	#if LBAL_cpp_version > LBAL_CPP14_VERSION
		#if !defined(LBAL_CPP17_AGGREGATE_BASES) && (LBAL_GCC_VERSION >= 70000)
			#define LBAL_CPP17_AGGREGATE_BASES 201603L
		#endif

		#if !defined(LBAL_CPP17_ALIGNED_NEW) && (LBAL_GCC_VERSION >= 70000)
			#define LBAL_CPP17_ALIGNED_NEW 201603L
		#endif

		#if !defined(LBAL_CPP17_CAPTURE_STAR_THIS) \
				&& (LBAL_GCC_VERSION >= 70000)
			#define LBAL_CPP17_CAPTURE_STAR_THIS 201603L
		#endif

		#if !defined(LBAL_CPP17_CONSTEXPR_LAMBDA) \
				&& (LBAL_GCC_VERSION >= 70000)
			#define LBAL_CPP17_CONSTEXPR_LAMBDA 201603L
		#endif

		#if !defined(LBAL_CPP17_DEDUCTION_GUIDES) \
				&& (LBAL_GCC_VERSION >= 70000)
			#define LBAL_CPP17_DEDUCTION_GUIDES 201606L
		#endif

		#if !defined(LBAL_CPP17_DEDUCTION_GUIDES_NB) \
				&& (LBAL_GCC_VERSION >= 80000)
			#define LBAL_CPP17_DEDUCTION_GUIDES_NB 201611L
		#endif

		//	__SEEME__ The minimimum version is speculative; I couldn’t find a
		//	reference to indicate when - or if - gcc addressed this DR, aside
		//	from vague references to it being part of C++17. Note that gcc 8
		//	was the first version claiming full C++17 language support, while
		//	gcc 9 has most--or-all of the C++17 library support; DRs are a
		//	different story, however.
		#if !defined(LBAL_CPP17_DEDUCTION_GUIDES_DR) \
				&& (LBAL_GCC_VERSION >= 80000)
			#define LBAL_CPP17_DEDUCTION_GUIDES_DR 201703L
		#endif

		#if !defined(LBAL_CPP17_ENUMERATOR_ATTRIBUTES) \
				&& (LBAL_GCC_VERSION >= 60000)
			#define LBAL_CPP17_ENUMERATOR_ATTRIBUTES 201411L
		#endif

		#if !defined(LBAL_CPP17_FOLD_EXPRESSIONS) \
				&& (LBAL_GCC_VERSION >= 60000)
			#define LBAL_CPP17_FOLD_EXPRESSIONS 201411L
		#endif

		#if !defined(LBAL_CPP17_FOLD_EXPRESSIONS_REVISED) \
				&& (LBAL_GCC_VERSION >= 60000)
			#define LBAL_CPP17_FOLD_EXPRESSIONS_REVISED 201603L
		#endif

		#if !defined(LBAL_CPP17_GUARANTEED_COPY_ELISION) \
				&& (LBAL_GCC_VERSION >= 70000)
			#define LBAL_CPP17_GUARANTEED_COPY_ELISION 201606L
		#endif

		#if !defined(LBAL_CPP17_HEX_FLOAT) && (LBAL_GCC_VERSION >= 201603L)
			#define LBAL_CPP17_HEX_FLOAT 30000
		#endif

		#if !defined(LBAL_CPP17_IF_CONSTEXPR) && (LBAL_GCC_VERSION >= 201606L)
			#define LBAL_CPP17_IF_CONSTEXPR 70000
		#endif

		#if !defined(LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED) \
				&& (LBAL_GCC_VERSION >= 70000)
			#define LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED 201511L
		#endif

		#if !defined(LBAL_CPP17_INLINE_VARIABLES) \
				&& (LBAL_GCC_VERSION >= 70000)
			#define LBAL_CPP17_INLINE_VARIABLES 201606L
		#endif

		#if !defined(LBAL_CPP17_NAMESPACE_ATTRIBUTES) \
				&& (LBAL_GCC_VERSION >= 60000)
			#define LBAL_CPP17_NAMESPACE_ATTRIBUTES 201411L
		#endif

		#if !defined(LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE) \
				&& (LBAL_GCC_VERSION >= 70000)
			#define LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE 201510L
		#endif

		#if !defined(LBAL_CPP17_NONTYPE_TEMPLATE_ARGS) \
				&& (LBAL_GCC_VERSION >= 60000)
			#define LBAL_CPP17_NONTYPE_TEMPLATE_ARGS 201411L
		#endif

		#if !defined(LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO) \
				&& (LBAL_GCC_VERSION >= 70000)
			#define LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO 201606L
		#endif

		#if !defined(LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED) \
				&& (LBAL_GCC_VERSION >= 60000)
			#define LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED 201603L
		#endif

		#if !defined(LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE) \
				&& (LBAL_GCC_VERSION >= 60000)
			#define LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE 201411L
		#endif

		#if !defined(LBAL_CPP17_STRUCTURED_BINDINGS) \
				&& (LBAL_GCC_VERSION >= 70000)
			#define LBAL_CPP17_STRUCTURED_BINDINGS 201606L
		#endif

		#if !defined(LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS) \
				&& (LBAL_GCC_VERSION >= 70000)
			#define LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS 201611L
		#endif

		#if !defined(LBAL_CPP17_VARIADIC_USING) && (LBAL_GCC_VERSION >= 70000)
			#define LBAL_CPP17_VARIADIC_USING 201611L
		#endif
	#endif	//	LBAL_CPP14_VERSION


	//	C++20 features
	//
	//	In the absence of SD-6 macros, we rely on language and compiler version
	//	tests. We check for any Standard version greater than C++17, which will
	//	ensure we can use features which may have been made available as
	//	extensions or previews.

	//	__SEEME__ None of these have SD-6 macros, so we rely on a compiler
	//	version check and a language test.
	#if LBAL_cpp_version > LBAL_CPP17_VERSION
		#if (LBAL_GCC_VERSION >= 80000)
			//	__SEEME__ None of these have SD-6 macros, so we rely on a compiler
			//	version check and a language test. This will miss back-ported
			//	extensions, but will pick up preview implementations.

			#if !defined(LBAL_CPP20_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS)
				#define LBAL_CPP20_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS 1L
			#endif

			#if !defined(LBAL_CPP20_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS)
				#define LBAL_CPP20_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS 1L
			#endif

			#if !defined(LBAL_CPP20_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS)
				#define LBAL_CPP20_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS 1L
			#endif

			#if !defined(LBAL_CPP20_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION)
				#define LBAL_CPP20_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION 1L
			#endif

			//	__SEEME__ This did not have a proper SD-6 token value until
			//	Dec 2019.
			#if !defined(LBAL_CPP20_DESIGNATED_INITIALIZERS)
				#if defined(__cpp_designated_initializers) \
						&& (__cpp_designated_initializers >= 201707L)
					#define LBAL_CPP20_DESIGNATED_INITIALIZERS \
							__cpp_designated_initializers
				#else
					#define LBAL_CPP20_DESIGNATED_INITIALIZERS 201707L
				#endif
			#endif

			//	__SEEME__ This did not have a proper SD-6 token value until
			//	Dec 2019.
			#if !defined(LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST)
				#if defined(__cpp_generic_lambdas) && (__cpp_generic_lambdas >= 201707L)
					#define LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST \
							__cpp_generic_lambdas
				#else
					#define LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST 201707L
				#endif
			#endif

			//	__FIXME__ gcc hasn’t yet shipped a fully functioning version of
			//	this feature. In particular, the latest one from gcc 8 fails
			//	when it encounters `#__VA_OPT__`. We treat this as unavailable,
			//	but it’s actually a good candidate for a new “partial
			//	implementation” value, or a special token (`LBAL_OOPS_xxx`?).
//			#define LBAL_CPP20_VA_OPT 1L
		#endif

		#if (LBAL_GCC_VERSION >= 90000)
			//	__SEEME__ This did not have a proper SD-6 token value until
			//	Dec 2019.
			#if !defined(LBAL_CPP20_CONSTEXPR_VIRTUAL_FUNCTION)
				#if defined(__cpp_constexpr) && (__cpp_constexpr >= 201806L)
					#define LBAL_CPP20_CONSTEXPR_VIRTUAL_FUNCTION __cpp_constexpr
				#else
					#define LBAL_CPP20_CONSTEXPR_VIRTUAL_FUNCTION 201806L
				#endif
			#endif

			#if !defined(LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS)
				#define LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS 1L
			#endif

			#if !defined(LBAL_CPP20_INIT_STATEMENTS_FOR_RANGE_BASED_FOR)
				#define LBAL_CPP20_INIT_STATEMENTS_FOR_RANGE_BASED_FOR 1L
			#endif

			//	__SEEME__ This did not have a proper SD-6 token value until
			//	Dec 2019.
			#if !defined(LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION)
				#if defined(__cpp_init_captures) && (__cpp_init_captures >= 201803L)
					#define LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION __cpp_init_captures
				#else
					#define LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION 201803L
				#endif
			#endif

			#define LBAL_CPP20_TYPENAME_OPTIONAL 1L
		#endif
	#endif	//	LBAL_CPP17_VERSION


	//	C++14 Attributes
	//	Note that SD-6 macros didn’t appear until gcc 7.3, so we have to rely
	//	on compiler and language version checks in earlier iterations. We check
	//	for any Standard version greater than C++11, which will ensure we can
	//	use features which may have been made available as extensions or
	//	previews.

	#if LBAL_cpp_version > LBAL_CPP11_VERSION
		#if !defined(LBAL_CPP14_ATTRIBUTE_DEPRECATED) \
				&& (LBAL_GCC_VERSION >= 40900)
			#define LBAL_CPP14_ATTRIBUTE_DEPRECATED 201309L
		#endif
	#endif	//	LBAL_CPP11_VERSION


	//	We get rid of this since it isn’t an officially supported feature.
	#undef LBAL_GCC_VERSION
#else
	#error "lbalGCCPostInitialization.hpp was directly included while using the wrong compiler"
#endif
