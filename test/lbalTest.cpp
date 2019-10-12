/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalTest”
	Copyright © 2015-2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

------------------------------------------------------------------------------*/


//	std
#include <iostream>


//	gtest
#include <gtest/gtest.h>


//	lbal
#include <lucenaBAL/lucenaBAL.hpp>


/*------------------------------------------------------------------------------
	Declarations
*/



#define LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING 0
#define LBAL_DIAGNOSTIC_LOG_ALL_STATUS 1
#define LBAL_DIAGNOSTIC_LOG_ALL_UNSUPPORTED 1

#if LBAL_DIAGNOSTIC_LOG_ALL_STATUS
	#define LBAL_DIAGNOSTIC_LOG_SUPPORTED(LBAL_DIAGNOSTIC_feature_) \
		std::cerr << LBAL_DIAGNOSTIC_feature_ " is supported" << std::endl;
#elif
	#define LBAL_DIAGNOSTIC_LOG_SUPPORTED(LBAL_DIAGNOSTIC_feature_)
#endif

#if LBAL_LOG_DIAGNOSTIC_ALL_STATUS || LBAL_DIAGNOSTIC_LOG_ALL_UNSUPPORTED
	#define LBAL_DIAGNOSTIC_LOG_UNSUPPORTED(LBAL_DIAGNOSTIC_feature_) \
		std::cerr << LBAL_DIAGNOSTIC_feature_ " is UNSUPPORTED" << std::endl;
#elif
	#define LBAL_DIAGNOSTIC_LOG_UNSUPPORTED(LBAL_DIAGNOSTIC_feature_)
#endif

#define LBAL_DIAGNOSTIC_TEST(LBAL_DIAGNOSTIC_feature_) \
	do { \
		if constexpr (0 == LBAL_DIAGNOSTIC_feature_) { \
			LBAL_DIAGNOSTIC_LOG_UNSUPPORTED (#LBAL_DIAGNOSTIC_feature_) \
		} else { \
			LBAL_DIAGNOSTIC_LOG_SUPPORTED (#LBAL_DIAGNOSTIC_feature_) \
		} \
	} while (false)


using namespace LBAL_;


/*------------------------------------------------------------------------------
*/

GTEST_TEST (lbalTest, Validation)
{
	/*	Report the results of the various feature tests. In addition to
		runtime reporting, there is also compile-time reporting; depending on
		your IDE, you may not even need to explicitly compile to see the test
		results.

		__SEEME__ Note that we can’t use preprocessor or template magic when
		displaying compile-time messages; if #warning allowed macro
		substitution, we’d be in luck, but unfortunately, that feature is an
		MSVC extension, only, so gratuitous boilerplate is needed.
	*/

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP98_EXCEPTIONS);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP98_EXCEPTIONS
		#warning "LBAL_CPP98_EXCEPTIONS is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP98_RTTI);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP98_RTTI
		#warning "LBAL_CPP98_RTTI is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_ALIAS_TEMPLATES);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP11_ALIAS_TEMPLATES
		#warning "LBAL_CPP11_ALIAS_TEMPLATES is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_ATTRIBUTES);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP11_ATTRIBUTES
		#warning "LBAL_CPP11_ATTRIBUTES is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_CONSTEXPR);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP11_CONSTEXPR
		#warning "LBAL_CPP11_CONSTEXPR is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_DECLTYPE);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP11_DECLTYPE
		#warning "LBAL_CPP11_DECLTYPE is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_MINIMAL_GARBAGE_COLLECTION);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP11_MINIMAL_GARBAGE_COLLECTION
		#warning "LBAL_CPP11_MINIMAL_GARBAGE_COLLECTION is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_THREADSAFE_STATIC_INIT);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP11_THREADSAFE_STATIC_INIT
		#warning "LBAL_CPP11_THREADSAFE_STATIC_INIT is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP14_AGGREGATE_NSDMI);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP14_AGGREGATE_NSDMI
		#warning "LBAL_CPP14_AGGREGATE_NSDMI is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP14_BINARY_LITERALS);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP14_BINARY_LITERALS
		#warning "LBAL_CPP14_BINARY_LITERALS is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS
		#warning "LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP14_DECLTYPE_AUTO);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP14_DECLTYPE_AUTO
		#warning "LBAL_CPP14_DECLTYPE_AUTO is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP14_SIZED_DEALLOCATION);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP14_SIZED_DEALLOCATION
		#warning "LBAL_CPP14_SIZED_DEALLOCATION is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_AGGREGATE_BASES);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP17_AGGREGATE_BASES
		#warning "LBAL_CPP17_AGGREGATE_BASES is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_ALIGNED_NEW);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP17_ALIGNED_NEW
		#warning "LBAL_CPP17_ALIGNED_NEW is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_CAPTURE_STAR_THIS);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP17_CAPTURE_STAR_THIS
		#warning "LBAL_CPP17_CAPTURE_STAR_THIS is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_CONSTEXPR_LAMBDA);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP17_CONSTEXPR_LAMBDA
		#warning "LBAL_CPP17_CONSTEXPR_LAMBDA is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_DEDUCTION_GUIDES);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP17_DEDUCTION_GUIDES
		#warning "LBAL_CPP17_DEDUCTION_GUIDES is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_DEDUCTION_GUIDES_DR);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP17_DEDUCTION_GUIDES_DR
		#warning "LBAL_CPP17_DEDUCTION_GUIDES_DR is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_DEDUCTION_GUIDES_NB);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP17_DEDUCTION_GUIDES_NB
		#warning "LBAL_CPP17_DEDUCTION_GUIDES_NB is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS
		#warning "LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_AGGREGATE_PAREN_INIT);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_AGGREGATE_PAREN_INIT
		#warning "LBAL_CPP2A_AGGREGATE_PAREN_INIT is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_CHAR8_T);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_CHAR8_T
		#warning "LBAL_CPP2A_CHAR8_T is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS
		#warning "LBAL_CPP2A_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_ATTRIBUTE_NO_UNIQUE_ADDRESS);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_ATTRIBUTE_NO_UNIQUE_ADDRESS
		#warning "LBAL_CPP2A_ATTRIBUTE_NO_UNIQUE_ADDRESS is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_ATTRIBUTE_LIKELY);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_ATTRIBUTE_LIKELY
		#warning "LBAL_CPP2A_ATTRIBUTE_LIKELY is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_ATTRIBUTE_UNLIKELY);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_ATTRIBUTE_UNLIKELY
		#warning "LBAL_CPP2A_ATTRIBUTE_UNLIKELY is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_ATTRIBUTES_LIKELY_AND_UNLIKELY);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_ATTRIBUTES_LIKELY_AND_UNLIKELY
		#warning "LBAL_CPP2A_ATTRIBUTES_LIKELY_AND_UNLIKELY is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_CONCEPTS);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_CONCEPTS
		#warning "LBAL_CPP2A_CONCEPTS is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_CONDITIONAL_EXPLICIT);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_CONDITIONAL_EXPLICIT
		#warning "LBAL_CPP2A_CONDITIONAL_EXPLICIT is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS
		#warning "LBAL_CPP2A_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_CONSTEXPR_DYNAMIC_ALLOC);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_CONSTEXPR_DYNAMIC_ALLOC
		#warning "LBAL_CPP2A_CONSTEXPR_DYNAMIC_ALLOC is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION
		#warning "LBAL_CPP2A_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_CONSTEXPR_VIRTUAL_FUNCTION);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_CONSTEXPR_VIRTUAL_FUNCTION
		#warning "LBAL_CPP2A_CONSTEXPR_VIRTUAL_FUNCTION is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_CONSTINIT);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_CONSTINIT
		#warning "LBAL_CPP2A_CONSTINIT is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_COROUTINES);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_COROUTINES
		#warning "LBAL_CPP2A_COROUTINES is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_DEDUCTION_GUIDES_FOR_AGGREGATES);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_DEDUCTION_GUIDES_FOR_AGGREGATES
		#warning "LBAL_CPP2A_DEDUCTION_GUIDES_FOR_AGGREGATES is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS
		#warning "LBAL_CPP2A_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS
		#warning "LBAL_CPP2A_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_DESIGNATED_INITIALIZERS);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_DESIGNATED_INITIALIZERS
		#warning "LBAL_CPP2A_DESIGNATED_INITIALIZERS is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_DESTROYING_DELETE);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_DESTROYING_DELETE
		#warning "LBAL_CPP2A_DESTROYING_DELETE is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_INIT_STATEMENTS_FOR_RANGE_BASED_FOR);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_INIT_STATEMENTS_FOR_RANGE_BASED_FOR
		#warning "LBAL_CPP2A_INIT_STATEMENTS_FOR_RANGE_BASED_FOR is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION
		#warning "LBAL_CPP2A_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_INTEGRATING_OUR_FEATURE_TEST_MACROS);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_INTEGRATING_OUR_FEATURE_TEST_MACROS
		#warning "LBAL_CPP2A_INTEGRATING_OUR_FEATURE_TEST_MACROS is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_NONTYPE_TEMPLATE_PARAMETER_CLASS);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_NONTYPE_TEMPLATE_PARAMETER_CLASS
		#warning "LBAL_CPP2A_NONTYPE_TEMPLATE_PARAMETER_CLASS is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_PACK_EXPANSION_IN_LAMBDA_INIT_CAPTURE);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_PACK_EXPANSION_IN_LAMBDA_INIT_CAPTURE
		#warning "LBAL_CPP2A_PACK_EXPANSION_IN_LAMBDA_INIT_CAPTURE is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR
		#warning "LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR_TUNEUP);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR_TUNEUP
		#warning "LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR_TUNEUP is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_TEMPLATE_PARAMETER_LIST_FOR_GENERIC_LAMBDAS);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_TEMPLATE_PARAMETER_LIST_FOR_GENERIC_LAMBDAS
		#warning "LBAL_CPP2A_TEMPLATE_PARAMETER_LIST_FOR_GENERIC_LAMBDAS is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_TYPENAME_OPTIONAL);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_TYPENAME_OPTIONAL
		#warning "LBAL_CPP2A_TYPENAME_OPTIONAL is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP2A_VA_OPT);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPP2A_VA_OPT
		#warning "LBAL_CPP2A_VA_OPT is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_C99_PREPROCESSOR);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_C99_PREPROCESSOR
		#warning "LBAL_C99_PREPROCESSOR is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_ANY);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP17_ANY
		#warning "LBAL_LIBCPP17_ANY is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS
		#warning "LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_EXECUTION);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP17_EXECUTION
		#warning "LBAL_LIBCPP17_EXECUTION is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_FILESYSTEM);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP17_FILESYSTEM
		#warning "LBAL_LIBCPP17_FILESYSTEM is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_FILESYSTEM_EXP);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP17_FILESYSTEM_EXP
		#warning "LBAL_LIBCPP17_FILESYSTEM_EXP is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE
		#warning "LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_LAUNDER);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP17_LAUNDER
		#warning "LBAL_LIBCPP17_LAUNDER is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_OPTIONAL);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP17_OPTIONAL
		#warning "LBAL_LIBCPP17_OPTIONAL is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_PARALLEL_ALGORITHM);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP17_PARALLEL_ALGORITHM
		#warning "LBAL_LIBCPP17_PARALLEL_ALGORITHM is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_SPLICING_MAPS_AND_SETS);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP17_SPLICING_MAPS_AND_SETS
		#warning "LBAL_LIBCPP17_SPLICING_MAPS_AND_SETS is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS
		#warning "LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_VARIANT);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP17_VARIANT
		#warning "LBAL_LIBCPP17_VARIANT is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP2A_BIT_CAST);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP2A_BIT_CAST
		#warning "LBAL_LIBCPP2A_BIT_CAST is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP2A_CALENDAR_AND_TIMEZONE);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP2A_CALENDAR_AND_TIMEZONE
		#warning "LBAL_LIBCPP2A_CALENDAR_AND_TIMEZONE is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP2A_CONCEPT_LIBRARY);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP2A_CONCEPT_LIBRARY
		#warning "LBAL_LIBCPP2A_CONCEPT_LIBRARY is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP
		#warning "LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP2A_CONSTEXPR_FOR_ALGORITHM_AND_UTILITY);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP2A_CONSTEXPR_FOR_ALGORITHM_AND_UTILITY
		#warning "LBAL_LIBCPP2A_CONSTEXPR_FOR_ALGORITHM_AND_UTILITY is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP2A_COROUTINES);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP2A_COROUTINES
		#warning "LBAL_LIBCPP2A_COROUTINES is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP2A_COROUTINES_EXP);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP2A_COROUTINES_EXP
		#warning "LBAL_LIBCPP2A_COROUTINES_EXP is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP2A_EXTENDING_MAKE_SHARED_TO_SUPPORT_ARRAYS);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP2A_EXTENDING_MAKE_SHARED_TO_SUPPORT_ARRAYS
		#warning "LBAL_LIBCPP2A_EXTENDING_MAKE_SHARED_TO_SUPPORT_ARRAYS is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP2A_FLOATING_POINT_ATOMIC);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP2A_FLOATING_POINT_ATOMIC
		#warning "LBAL_LIBCPP2A_FLOATING_POINT_ATOMIC is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP2A_LIST_REMOVE_RETURN_TYPE);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP2A_LIST_REMOVE_RETURN_TYPE
		#warning "LBAL_LIBCPP2A_LIST_REMOVE_RETURN_TYPE is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP2A_MORE_CONSTEXPR_FOR_COMPLEX);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP2A_MORE_CONSTEXPR_FOR_COMPLEX
		#warning "LBAL_LIBCPP2A_MORE_CONSTEXPR_FOR_COMPLEX is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP2A_SPAN);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP2A_SPAN
		#warning "LBAL_LIBCPP2A_SPAN is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP2A_STD_ATOMIC_REF);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP2A_STD_ATOMIC_REF
		#warning "LBAL_LIBCPP2A_STD_ATOMIC_REF is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP2A_STD_ENDIAN);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP2A_STD_ENDIAN
		#warning "LBAL_LIBCPP2A_STD_ENDIAN is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP2A_STD_REMOVE_CVREF);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP2A_STD_REMOVE_CVREF
		#warning "LBAL_LIBCPP2A_STD_REMOVE_CVREF is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP2A_STRING_PREFIX_AND_SUFFIX_CHECKING);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP2A_STRING_PREFIX_AND_SUFFIX_CHECKING
		#warning "LBAL_LIBCPP2A_STRING_PREFIX_AND_SUFFIX_CHECKING is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP2A_SYNCHRONIZED_BUFFERED_OSTREAM);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP2A_SYNCHRONIZED_BUFFERED_OSTREAM
		#warning "LBAL_LIBCPP2A_SYNCHRONIZED_BUFFERED_OSTREAM is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP2A_THREE_WAY_COMPARISON_OPERATOR_SUPPORT_COMPARE);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP2A_THREE_WAY_COMPARISON_OPERATOR_SUPPORT_COMPARE
		#warning "LBAL_LIBCPP2A_THREE_WAY_COMPARISON_OPERATOR_SUPPORT_COMPARE is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP2A_TYPE_IDENTITY);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP2A_TYPE_IDENTITY
		#warning "LBAL_LIBCPP2A_TYPE_IDENTITY is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP2A_UTILITY_TO_CONVERT_A_POINTER_TO_A_RAW_POINTER);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP2A_UTILITY_TO_CONVERT_A_POINTER_TO_A_RAW_POINTER
		#warning "LBAL_LIBCPP2A_UTILITY_TO_CONVERT_A_POINTER_TO_A_RAW_POINTER is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP2A_VERSION);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_LIBCPP2A_VERSION
		#warning "LBAL_LIBCPP2A_VERSION is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPPTS_ATTRIBUTE_ASSERT);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPPTS_ATTRIBUTE_ASSERT
		#warning "LBAL_CPPTS_ATTRIBUTE_ASSERT is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPPTS_ATTRIBUTE_ENSURES);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPPTS_ATTRIBUTE_ENSURES
		#warning "LBAL_CPPTS_ATTRIBUTE_ENSURES is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPPTS_ATTRIBUTE_EXPECTS);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPPTS_ATTRIBUTE_EXPECTS
		#warning "LBAL_CPPTS_ATTRIBUTE_EXPECTS is UNSUPPORTED"
	#endif

	LBAL_DIAGNOSTIC_TEST(LBAL_CPPTS_CONTRACTS);
	#if LBAL_DIAGNOSTIC_COMPILE_TIME_REPORTING && !LBAL_CPPTS_CONTRACTS
		#warning "LBAL_CPPTS_CONTRACTS is UNSUPPORTED"
	#endif

	EXPECT_TRUE (true);
}
