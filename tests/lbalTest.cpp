/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalTest”
	Copyright © 2015-2024 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See LICENSE.md for details.

------------------------------------------------------------------------------*/


//	lbal
#include <lucenaBAL/lucenaBAL.hpp>


//	gtest
#include <gtest/gtest.h>


//	std
#include <iostream>


/*------------------------------------------------------------------------------
	Declarations
*/


#define LBAL_DIAGNOSTIC_LOG_ALL_STATUS false
#define LBAL_DIAGNOSTIC_LOG_ALL_UNSUPPORTED true

#if LBAL_DIAGNOSTIC_LOG_ALL_STATUS
	#define LBAL_DIAGNOSTIC_LOG_SUPPORTED(LBAL_DIAGNOSTIC_feature_) \
		std::cerr << LBAL_DIAGNOSTIC_feature_ " is supported" << std::endl;
#else
	#define LBAL_DIAGNOSTIC_LOG_SUPPORTED(LBAL_DIAGNOSTIC_feature_)
#endif

#if LBAL_DIAGNOSTIC_LOG_ALL_STATUS || LBAL_DIAGNOSTIC_LOG_ALL_UNSUPPORTED
	#define LBAL_DIAGNOSTIC_LOG_UNSUPPORTED(LBAL_DIAGNOSTIC_feature_) \
		std::cerr << LBAL_DIAGNOSTIC_feature_ " is UNSUPPORTED" << std::endl;
#elif
	#define LBAL_DIAGNOSTIC_LOG_UNSUPPORTED(LBAL_DIAGNOSTIC_feature_)
#endif

#if LBAL_CPP17_IF_CONSTEXPR
	#define LBAL_IF_CONSTEXPR if constexpr
#else
	#define LBAL_IF_CONSTEXPR if
#endif

#define LBAL_DIAGNOSTIC_TEST(LBAL_DIAGNOSTIC_feature_) \
	do { \
		LBAL_IF_CONSTEXPR (0 == LBAL_DIAGNOSTIC_feature_) { \
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
	/*	Report the results of the various feature tests; depending on your IDE,
		you may not even need to explicitly compile to see the test results.
	*/

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP98_EXCEPTIONS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP98_RTTI);

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_ALIAS_TEMPLATES);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_ATTRIBUTE_CARRIES_DEPENDENCY);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_ATTRIBUTE_NORETURN);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_ATTRIBUTES);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_CONSTEXPR);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_DECLTYPE);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_DELEGATING_CONSTRUCTORS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_INHERITING_CONSTRUCTORS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_INITIALIZER_LISTS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_LAMBDAS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_MINIMAL_GARBAGE_COLLECTION);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_NSDMI);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_RANGE_BASED_FOR);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_RAW_STRINGS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_REF_QUALIFIERS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_RVALUE_REFERENCES);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_STATIC_ASSERT);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_THREADSAFE_STATIC_INIT);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_UNICODE_CHARACTERS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_UNICODE_LITERALS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_USER_DEFINED_LITERALS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP11_VARIADIC_TEMPLATES);

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP14_AGGREGATE_NSDMI);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP14_ATTRIBUTE_DEPRECATED);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP14_BINARY_LITERALS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP14_DECLTYPE_AUTO);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP14_GENERIC_LAMBDAS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP14_INIT_CAPTURES);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP14_RETURN_TYPE_DEDUCTION);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP14_SIZED_DEALLOCATION);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP14_VARIABLE_TEMPLATES);

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_AGGREGATE_BASES);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_ALIGNED_NEW);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_ATTRIBUTE_FALLTHROUGH);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_ATTRIBUTE_NODISCARD);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_CAPTURE_STAR_THIS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_CONSTEXPR_LAMBDA);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_DEDUCTION_GUIDES);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_DEDUCTION_GUIDES_DR);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_DEDUCTION_GUIDES_NB);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_ENUMERATOR_ATTRIBUTES);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_FOLD_EXPRESSIONS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_FOLD_EXPRESSIONS_REVISED);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_GUARANTEED_COPY_ELISION);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_HEX_FLOAT);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_INLINE_VARIABLES);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_NAMESPACE_ATTRIBUTES);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_NONTYPE_TEMPLATE_ARGS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_STRUCTURED_BINDINGS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP17_VARIADIC_USING);

	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_AGGREGATE_PAREN_INIT);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_CHAR8_T);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_ATTRIBUTE_LIKELY);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_ATTRIBUTES_LIKELY_AND_UNLIKELY);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_ATTRIBUTE_NO_UNIQUE_ADDRESS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_ATTRIBUTE_NODISCARD_EXPANDED);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_ATTRIBUTE_UNLIKELY);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_CONCEPTS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_CONCEPTS_RESPECIFY_RETURN_TYPE_REQUIREMENTS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_CONCEPTS_REFINE_RETURN_TYPE_REQUIREMENTS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_CONDITIONAL_EXPLICIT);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_CONSTEVAL);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_CONSTEXPR_DYNAMIC_ALLOC);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_CONSTEXPR_IN_DECLTYPE);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_CONSTEXPR_INTRINSICS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_CONSTEXPR_TRY_CATCH);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_CONSTEXPR_UNION_ALTERATION);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_CONSTEXPR_VIRTUAL_FUNCTION);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_CONSTINIT);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_DEDUCTION_GUIDES_FOR_AGGREGATES);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_DESIGNATED_INITIALIZERS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_DESTROYING_DELETE);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_IMPL_COROUTINE);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_INIT_STATEMENTS_FOR_RANGE_BASED_FOR);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_INTEGRATING_OUR_FEATURE_TEST_MACROS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_MODULES);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FIXES);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_NONTYPE_TEMPLATE_PARAMETER_CLASS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_EQUALITY_FIX);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_TUNEUP);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_TYPENAME_OPTIONAL);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_USING_ENUM);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPP20_VA_OPT);

	LBAL_DIAGNOSTIC_TEST(LBAL_C99_PREPROCESSOR);

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP14_CHRONO_UDLS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP14_COMPLEX_UDLS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP14_EXCHANGE_FUNCTION);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP14_INTEGER_SEQUENCE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP14_IS_FINAL);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP14_IS_NULL_POINTER);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP14_MAKE_UNIQUE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP14_NULL_ITERATORS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP14_QUOTED_STRING_IO);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP14_RESULT_OF_SFINAE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP14_SHARED_TIMED_MUTEX);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP14_STRING_UDLS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP14_TRANSPARENT_OPERATORS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP14_TUPLE_ELEMENT_T);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP14_TUPLES_BY_TYPE);

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_ANY);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_ANY_INTERFACE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_APPLY);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_ARRAY_CONSTEXPR);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_AS_CONST);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_BOOL_CONSTANT);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_BOYER_MOORE_SEARCHER);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_BYTE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_CHRONO);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_CHRONO_CONSTEXPR);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_CLAMP);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_CONSTEXPR_STRING);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_EXECUTION);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_FILESYSTEM);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_FILESYSTEM_EXP);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_GCD_LCM);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_HYPOT);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_INVOKE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_IS_AGGREGATE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_IS_INVOCABLE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_IS_SWAPPABLE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_LAUNDER);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_LOGICAL_TRAITS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_MAKE_FROM_TUPLE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_MAP_TRY_EMPLACE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_MEMORY_RESOURCE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_NODE_EXTRACT);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_NOT_FN);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_OPTIONAL);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_OPTIONAL_INTERFACE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_PARALLEL_ALGORITHM);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_SAMPLE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_SCOPED_LOCK);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_SHARED_MUTEX);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_SHARED_PTR_ARRAYS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_STRING_VIEW);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_STRING_VIEW_INTERFACE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_TO_CHARS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_TO_CHARS_FP);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_TO_CHARS_INTEGER);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_TRANSPARENT_OPERATORS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_VARIANT);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP17_VOID_T);

	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_ASSUME_ALIGNED);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_ATOMIC_FLAG_TEST);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_ATOMIC_FLOAT);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_ATOMIC_REF);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_ATOMIC_SHARED_PTR);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_ATOMIC_WAIT);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_BARRIER);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_BIND_FRONT);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_BIT_CAST);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_BITOPS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CHAR8_T);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CHAR8_T_COMPAT);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CHRONO_CALENDAR);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CHRONO_FIXES);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CONCEPTS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CONCEPTS_EXP);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CONCEPTS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CONSTEXPR_COMPLEX);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CONSTEXPR_ITERATOR);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CONSTEXPR_MEMORY);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CONSTEXPR_NUMERIC);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CONSTEXPR_STRING);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CONSTEXPR_TUPLE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CONSTEXPR_UTILITY);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_CONSTEXPR_VECTOR);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_COROUTINE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_COROUTINE_EXP);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_DESTROYING_DELETE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_ENDIAN);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_ENDIAN_BIT);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_ERASE_IF);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_FORMAT);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_INTERPOLATE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_INT_POW2);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_IS_CONSTANT_EVALUATED);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_JTHREAD);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_JTHREAD_CV);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_LATCH);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_MATH_CONSTANTS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_RANGES);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_REMOVE_CVREF);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_SEMAPHORE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_SHARED_PTR_ARRAYS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_SHIFT);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_SOURCE_LOCATION);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_SPAN);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_SPAN_USABILITY);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_SPAN_FIXED_SIZE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_SSIZE);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_STARTS_ENDS_WITH);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_SYNCBUF);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_SYNCBUF_MANIPULATORS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_THREE_WAY_COMPARISON);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_TO_ADDRESS);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_TO_ARRAY);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_TYPE_IDENTITY);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_UNWRAP_REF);
	LBAL_DIAGNOSTIC_TEST(LBAL_LIBCPP20_VERSION);

	LBAL_DIAGNOSTIC_TEST(LBAL_CPPTS_ATTRIBUTE_ASSERT);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPPTS_ATTRIBUTE_ENSURES);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPPTS_ATTRIBUTE_EXPECTS);
	LBAL_DIAGNOSTIC_TEST(LBAL_CPPTS_CONTRACTS);

	EXPECT_TRUE (true);
}

#undef LBAL_IF_CONSTEXPR
