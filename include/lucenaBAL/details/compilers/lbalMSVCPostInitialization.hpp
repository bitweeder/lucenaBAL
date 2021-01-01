/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalMSVCPostInitialization.hpp”
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
	MSVC compiler

	__SEEME__ Re: SD-6 macros: full support started getting rolled out as
	of MSVC 2019 16.0, but testing with that series didn’t start until
	16.3. As a result, it’s unclear exactly when the various macros started
	going live. For that reason, prior to 16.3, we fall back to compiler and
	language version checks, but after that, we rely on the SD-6 macros. It’s
	possible some supported features will fall through the cracks with some
	versions, but it’s unlikely; all the same, this will be updated as new
	information becomes available.
*/

#if LBAL_TARGET_COMPILER_VANILLA_MSVC
	//	C++98 features
	//	These can be conditionally disabled.
	//
	//	We can’t rely on `__cpp_exceptions` and `__cpp_rtti` being set properly
	//	in older MSVCs, so we also test for proprietary tokens, as well. We
	//	save the proprietary checks for post-initialization since we consider
	//	the SD-6 tests to be more reliable, if they are available.
	//
	//	__SEEME__ _CPPUNWIND is not an exact analog, but seems to serve.

	#if !defined(LBAL_CPP98_EXCEPTIONS)&& _CPPUNWIND
		#define LBAL_CPP98_EXCEPTIONS 199711L
	#endif

	#if !defined(LBAL_CPP98_RTTI) && _CPPRTTI
		#define LBAL_CPP98_RTTI 199711L
	#endif


	//	C++11 features
	//
	//	We check for “C++11 or greater” (as opposed to “greater than C++98”)
	//	since our earliest supported dialect is C++11.
	#if (LBAL_cpp_version >= LBAL_CPP11_VERSION)
		#if (_MSC_VER >= 1600)
			#if !defined(LBAL_CPP11_LAMBDAS)
				#define LBAL_CPP11_LAMBDAS 200907L
			#endif

			#if !defined(LBAL_CPP11_STATIC_ASSERT)
				#define LBAL_CPP11_STATIC_ASSERT 200410L
			#endif
		#endif	//	1600

		#if (_MSC_VER >= 1700)
			#if !defined(LBAL_CPP11_DECLTYPE)
				#define LBAL_CPP11_DECLTYPE 200707L
			#endif

			#if !defined(LBAL_CPP11_RANGE_BASED_FOR)
				#define LBAL_CPP11_RANGE_BASED_FOR 200907L
			#endif

			#if !defined(LBAL_CPP11_RVALUE_REFERENCES)
				#define LBAL_CPP11_RVALUE_REFERENCES 200610L
			#endif
		#endif	//	1700

		#if (_MSC_VER >= 1800)
			#if !defined(LBAL_CPP11_ALIAS_TEMPLATES)
				#define LBAL_CPP11_ALIAS_TEMPLATES 200704L
			#endif

			#if !defined(LBAL_CPP11_DELEGATING_CONSTRUCTORS)
				#define LBAL_CPP11_DELEGATING_CONSTRUCTORS 200604L
			#endif

			#if !defined(LBAL_CPP11_INITIALIZER_LISTS)
				#define LBAL_CPP11_INITIALIZER_LISTS 200806L
			#endif

			#if !defined(LBAL_CPP11_NSDMI)
				#define LBAL_CPP11_NSDMI 200809L
			#endif

			#if !defined(LBAL_CPP11_RAW_STRINGS)
				#define LBAL_CPP11_RAW_STRINGS 200710L
			#endif

			#if !defined(LBAL_CPP11_VARIADIC_TEMPLATES)
				#define LBAL_CPP11_VARIADIC_TEMPLATES 200704L
			#endif
		#endif	//	1800

		#if (_MSC_VER >= 1900)
			#if !defined(LBAL_CPP11_ATTRIBUTES)
				#define LBAL_CPP11_ATTRIBUTES 200809L
			#endif

			//	__SEEME__ Available in `_MSC_VER``1900` for partial, unsure of
			//	full.
			#if !defined(LBAL_CPP11_CONSTEXPR)
				#define LBAL_CPP11_CONSTEXPR 200704L
			#endif

			#if !defined(LBAL_CPP11_INHERITING_CONSTRUCTORS)
				#define LBAL_CPP11_INHERITING_CONSTRUCTORS 200802L
			#endif

			#if !defined(LBAL_CPP11_REF_QUALIFIERS)
				#define LBAL_CPP11_REF_QUALIFIERS 200710L
			#endif

			#if !defined(LBAL_CPP11_UNICODE_CHARACTERS)
				#define LBAL_CPP11_UNICODE_CHARACTERS 200704L
			#endif

			#if !defined(LBAL_CPP11_UNICODE_LITERALS)
				#define LBAL_CPP11_UNICODE_LITERALS 200710L
			#endif

			#if !defined(LBAL_CPP11_USER_DEFINED_LITERALS)
				#define LBAL_CPP11_USER_DEFINED_LITERALS 200809L
			#endif
		#endif	//	1900
	#endif	//	LBAL_CPP11_VERSION


	//	C++14 features

	#if (LBAL_cpp_version > LBAL_CPP11_VERSION)
		#if (_MSC_VER >= 1900)
			#if !defined(LBAL_CPP14_AGGREGATE_NSDMI)
				#define LBAL_CPP14_AGGREGATE_NSDMI 201304L
			#endif

			#if !defined(LBAL_CPP14_BINARY_LITERALS)
				#define LBAL_CPP14_BINARY_LITERALS 201304L
			#endif

			#if !defined(LBAL_CPP14_DECLTYPE_AUTO)
				#define LBAL_CPP14_DECLTYPE_AUTO 201304L
			#endif

			#if !defined(LBAL_CPP14_GENERIC_LAMBDAS)
				#define LBAL_CPP14_GENERIC_LAMBDAS 201304L
			#endif

			#if !defined(LBAL_CPP14_INIT_CAPTURES)
				#define LBAL_CPP14_INIT_CAPTURES 201304L
			#endif

			#if !defined(LBAL_CPP14_RETURN_TYPE_DEDUCTION)
				#define LBAL_CPP14_RETURN_TYPE_DEDUCTION 201304L
			#endif

			#if !defined(LBAL_CPP14_VARIABLE_TEMPLATES)
				#define LBAL_CPP14_VARIABLE_TEMPLATES 201304L
			#endif
		#endif	//	1900

		#if (_MSC_VER >= 1910)
			#if !defined(LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS)
				#define LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS 201304L
			#endif
		#endif	//	1910
	#endif	//	LBAL_CPP14_VERSION


	//	C++17 features

	#if (LBAL_cpp_version > LBAL_CPP14_VERSION)
		#if (_MSC_VER >= 1900)
			#if !defined(LBAL_CPP17_ENUMERATOR_ATTRIBUTES)
				#define LBAL_CPP17_ENUMERATOR_ATTRIBUTES 201411L
			#endif

			#if !defined(LBAL_CPP17_NAMESPACE_ATTRIBUTES)
				#define LBAL_CPP17_NAMESPACE_ATTRIBUTES 201411L
			#endif
		#endif	//	1900

		#if (_MSC_VER >= 1910)
			#if !defined(LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED)
				#define LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED 201603L
			#endif

			#if !defined(LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE)
				#define LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE 201411L
			#endif
		#endif	//	1910

		#if (_MSC_VER >= 1911)
			#if !defined(LBAL_CPP17_CAPTURE_STAR_THIS)
				#define LBAL_CPP17_CAPTURE_STAR_THIS 201603L
			#endif

			#if !defined(LBAL_CPP17_CONSTEXPR_LAMBDA)
				#define LBAL_CPP17_CONSTEXPR_LAMBDA 201603L
			#endif

			#if !defined(LBAL_CPP17_HEX_FLOAT)
				#define LBAL_CPP17_HEX_FLOAT 201603L
			#endif

			#if !defined(LBAL_CPP17_IF_CONSTEXPR)
				#define LBAL_CPP17_IF_CONSTEXPR 201606L
			#endif

			#if !defined(LBAL_CPP17_STRUCTURED_BINDINGS)
				#define LBAL_CPP17_STRUCTURED_BINDINGS 201606L
			#endif
		#endif	//	1911

		#if (_MSC_VER >= 1912)
			#if !defined(LBAL_CPP17_ALIGNED_NEW)
				#define LBAL_CPP17_ALIGNED_NEW 201606L
			#endif

			#if !defined(LBAL_CPP17_FOLD_EXPRESSIONS)
				#define LBAL_CPP17_FOLD_EXPRESSIONS 201411L
			#endif

			#if !defined(LBAL_CPP17_FOLD_EXPRESSIONS_REVISED)
				#define LBAL_CPP17_FOLD_EXPRESSIONS_REVISED 201603L
			#endif

			#if !defined(LBAL_CPP17_INLINE_VARIABLES)
				#define LBAL_CPP17_INLINE_VARIABLES 201606L
			#endif

			#if !defined(LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE)
				#define LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE 201510L
			#endif

			#if !defined(LBAL_CPP17_NONTYPE_TEMPLATE_ARGS)
				#define LBAL_CPP17_NONTYPE_TEMPLATE_ARGS 201411L
			#endif

			//	__SEEME__ This is implemented, but it’s unclear if/when the DR
			//	that affected the proposal was addressed.
			#if !defined(LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS)
				#define LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS 201611L
			#endif
		#endif	//	1912

		#if (_MSC_VER >= 1913)
			#if !defined(LBAL_CPP17_GUARANTEED_COPY_ELISION)
				#define LBAL_CPP17_GUARANTEED_COPY_ELISION 201606L
			#endif
		#endif	//	1913

		#if (_MSC_VER >= 1914)
			#if !defined(LBAL_CPP17_AGGREGATE_BASES)
				#define LBAL_CPP17_AGGREGATE_BASES 201603L
			#endif

			#if !defined(LBAL_CPP17_DEDUCTION_GUIDES)
				#define LBAL_CPP17_DEDUCTION_GUIDES 201606L
			#endif

			#if !defined(LBAL_CPP17_DEDUCTION_GUIDES_NB)
				#define LBAL_CPP17_DEDUCTION_GUIDES_NB 201611L
			#endif

			#if !defined(LBAL_CPP17_DEDUCTION_GUIDES_DR)
				#define LBAL_CPP17_DEDUCTION_GUIDES_DR 201703L
			#endif

			#if !defined(LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED)
				#define LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED 201511L
			#endif

			#if !defined(LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO)
				#define LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO 201606L
			#endif

			#if !defined(LBAL_CPP17_VARIADIC_USING)
				#define LBAL_CPP17_VARIADIC_USING 201611L
			#endif
		#endif	//	1914
	#endif	//	LBAL_CPP17_VERSION


	//	C++20 features

	#if LBAL_cpp_version > LBAL_CPP17_VERSION
		#if (_MSC_VER >= 1900)
			//	__SEEME__ None of these have SD-6 macros, so we rely on a
			//	compiler version check and a language test.
			#if !defined(LBAL_CPP20_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS)
				#define LBAL_CPP20_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS 1L
			#endif
		#endif	//	1900

		#if (_MSC_VER >= 1914)
			//	__SEEME__ None of these have SD-6 macros, so we rely on a
			//	compiler version check and a language test.
			#if !defined(LBAL_CPP20_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION)
				#define LBAL_CPP20_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION 1L
			#endif
		#endif	//	1914

		#if (_MSC_VER >= 1920)
			//	__SEEME__ None of these have SD-6 macros, so we rely on a
			//	compiler version check and a language test.
			#if !defined(LBAL_CPP20_INTEGRATING_OUR_FEATURE_TEST_MACROS)
				#define LBAL_CPP20_INTEGRATING_OUR_FEATURE_TEST_MACROS 1L
			#endif
		#endif	//	1920

		#if (_MSC_VER >= 1921)
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
		#endif	//	1921

		#if (_MSC_VER >= 1922)
			//	__SEEME__ No SD-6 macro.
			#if !defined(LBAL_CPP20_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS)
				#define LBAL_CPP20_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS 1L
			#endif

			//	__SEEME__ No SD-6 macro.
			#if !defined(LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS)
				#define LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS 1L
			#endif

			//	__SEEME__ This did not have a proper SD-6 token value until
			//	Dec 2019.
			#if !defined(LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION)
				#if defined(__cpp_init_captures) \
						&& (__cpp_init_captures >= 201803L)
					#define LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION\
							__cpp_init_captures
				#else
					#define LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION 201803L
				#endif
			#endif

			//	__SEEME__ This did not have a proper SD-6 token value until
			//	Dec 2019.
			#if !defined(LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST)
				#if defined(__cpp_generic_lambdas) \
						&& (__cpp_generic_lambdas >= 201707L)
					#define LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST \
							__cpp_generic_lambdas
				#else
					#define LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST \
							201707L
				#endif
			#endif
		#endif
	#endif	//	LBAL_CPP20_VERSION


	//	C++11 attributes

	#if (LBAL_cpp_version >= LBAL_CPP11_VERSION)
		#if (_MSC_VER >= 1900)
			#if !defined(LBAL_CPP11_ATTRIBUTE_CARRIES_DEPENDENCY)
				#define LBAL_CPP11_ATTRIBUTE_CARRIES_DEPENDENCY 200809L
			#endif

			#if !defined(LBAL_CPP11_ATTRIBUTE_NORETURN)
				#define LBAL_CPP11_ATTRIBUTE_NORETURN 200809L
			#endif
		#endif	//	1900
	#endif	//	LBAL_CPP11_VERSION


	//	C++14 Attributes

	#if (LBAL_cpp_version > LBAL_CPP11_VERSION)
		#if (_MSC_VER >= 1900)
			#if !defined(LBAL_CPP14_ATTRIBUTE_DEPRECATED)
				#define LBAL_CPP14_ATTRIBUTE_DEPRECATED 201309L
			#endif
		#endif	//	1900
	#endif	//	LBAL_CPP14_VERSION


	//	C++17 Attributes

	#if (LBAL_cpp_version > LBAL_CPP14_VERSION)
		#if (_MSC_VER >= 1910)
			#if !defined(LBAL_CPP17_ATTRIBUTE_FALLTHROUGH)
				#define LBAL_CPP17_ATTRIBUTE_FALLTHROUGH 201603L
			#endif
		#endif	//	1910

		#if (_MSC_VER >= 1911)
			#if !defined(LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED)
				#define LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED 201603L
			#endif

			#if !defined(LBAL_CPP17_ATTRIBUTE_NODISCARD)
				#define LBAL_CPP17_ATTRIBUTE_NODISCARD 201603L
			#endif
		#endif	//	1911
	#endif	//	LBAL_CPP17_VERSION
#else
	#error "lbalMSVCPostInitialization.hpp was directly included while using the wrong compiler"
#endif
