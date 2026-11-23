/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalLibrarySetup-definitions-libcpp26.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if !defined(LBAL_LIBCPP26_ALGORITHM_DEFAULT_VALUE_TYPE)
  #if __cpp_lib_algorithm_default_value_type >= 202603L
    #define LBAL_LIBCPP26_ALGORITHM_DEFAULT_VALUE_TYPE                         \
      __cpp_lib_algorithm_default_value_type
  #endif
#endif  //  LBAL_LIBCPP26_ALGORITHM_DEFAULT_VALUE_TYPE

#if !defined(LBAL_LIBCPP26_ALIGNED_ACCESSOR)
  #if __cpp_lib_aligned_accessor >= 202411L
    #define LBAL_LIBCPP26_ALIGNED_ACCESSOR __cpp_lib_aligned_accessor
  #endif
#endif  //  LBAL_LIBCPP26_ALIGNED_ACCESSOR

#if !defined(LBAL_LIBCPP26_APPLY_RESULT)
  #if __cpp_lib_apply >= 202506L
    #define LBAL_LIBCPP26_APPLY_RESULT __cpp_lib_apply
  #endif
#endif  //  LBAL_LIBCPP26_APPLY_RESULT

#if !defined(LBAL_LIBCPP26_ASSOCIATIVE_HETEROGENEOUS_INSERTION)
  #if __cpp_lib_associative_heterogeneous_insertion >= 202306L
    #define LBAL_LIBCPP26_ASSOCIATIVE_HETEROGENEOUS_INSERTION                  \
      __cpp_lib_associative_heterogeneous_insertion
  #endif
#endif  //  LBAL_LIBCPP26_ASSOCIATIVE_HETEROGENEOUS_INSERTION

#if !defined(LBAL_LIBCPP26_ATOMIC_MIN_MAX)
  #if __cpp_lib_atomic_min_max >= 202403L
    #define LBAL_LIBCPP26_ATOMIC_MIN_MAX __cpp_lib_atomic_min_max
  #endif
#endif  //  LBAL_LIBCPP26_ATOMIC_MIN_MAX

#if !defined(LBAL_LIBCPP26_ATOMIC_MIN_MAX_FLOAT)
  #if __cpp_lib_atomic_min_max >= 202506L
    #define LBAL_LIBCPP26_ATOMIC_MIN_MAX_FLOAT __cpp_lib_atomic_min_max
  #endif
#endif  //  LBAL_LIBCPP26_ATOMIC_MIN_MAX_FLOAT

#if !defined(LBAL_LIBCPP26_ATOMIC_REDUCTIONS)
  #if __cpp_lib_atomic_reductions >= 202506L
    #define LBAL_LIBCPP26_ATOMIC_REDUCTIONS __cpp_lib_atomic_reductions
  #endif
#endif  //  LBAL_LIBCPP26_ATOMIC_REDUCTIONS

#if !defined(LBAL_LIBCPP26_ATOMIC_REF_ADDRESS)
  #if __cpp_lib_atomic_ref >= 202411L
    #define LBAL_LIBCPP26_ATOMIC_REF_ADDRESS __cpp_lib_atomic_ref
  #endif
#endif  //  LBAL_LIBCPP26_ATOMIC_REF_ADDRESS

#if !defined(LBAL_LIBCPP26_ATOMIC_REF_SAFER_ADDRESS)
  #if __cpp_lib_atomic_ref >= 202603L
    #define LBAL_LIBCPP26_ATOMIC_REF_SAFER_ADDRESS __cpp_lib_atomic_ref
  #endif
#endif  //  LBAL_LIBCPP26_ATOMIC_REF_SAFER_ADDRESS

#if !defined(LBAL_LIBCPP26_BIND_FRONT_NTTP_CALLABLES)
  #if __cpp_lib_bind_front >= 202306L
    #define LBAL_LIBCPP26_BIND_FRONT_NTTP_CALLABLES __cpp_lib_bind_front
  #endif
#endif  //  LBAL_LIBCPP26_BIND_FRONT_NTTP_CALLABLES

#if !defined(LBAL_LIBCPP26_BITSET)
  #if __cpp_lib_bitset >= 202306L
    #define LBAL_LIBCPP26_BITSET __cpp_lib_bitset
  #endif
#endif  //  LBAL_LIBCPP26_BITSET

#if !defined(LBAL_LIBCPP26_CHRONO_HASHING)
  #if __cpp_lib_chrono >= 202306L
    #define LBAL_LIBCPP26_CHRONO_HASHING __cpp_lib_chrono
  #endif
#endif  //  LBAL_LIBCPP26_CHRONO_HASHING

#if !defined(LBAL_LIBCPP26_CONSTANT_WRAPPER)
  #if __cpp_lib_constant_wrapper >= 202506L
    #define LBAL_LIBCPP26_CONSTANT_WRAPPER __cpp_lib_constant_wrapper
  #endif
#endif  //  LBAL_LIBCPP26_CONSTANT_WRAPPER

#if !defined(LBAL_LIBCPP26_CONSTANT_WRAPPER_UNWRAP_ON_CALL)
  #if __cpp_lib_constant_wrapper >= 202603L
    #define LBAL_LIBCPP26_CONSTANT_WRAPPER_UNWRAP_ON_CALL                      \
      __cpp_lib_constant_wrapper
  #endif
#endif  //  LBAL_LIBCPP26_CONSTANT_WRAPPER_UNWRAP_ON_CALL

#if !defined(LBAL_LIBCPP26_CONSTEXPR_ALGORITHMS_STABLE_SORT)
  #if __cpp_lib_constexpr_algorithms >= 202306L
    #define LBAL_LIBCPP26_CONSTEXPR_ALGORITHMS_STABLE_SORT                     \
      __cpp_lib_constexpr_algorithms
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_ALGORITHMS_STABLE_SORT

#if !defined(LBAL_LIBCPP26_CONSTEXPR_ATOMIC)
  #if __cpp_lib_constexpr_atomic >= 202411L
    #define LBAL_LIBCPP26_CONSTEXPR_ATOMIC __cpp_lib_constexpr_atomic
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_ATOMIC

#if !defined(LBAL_LIBCPP26_CONSTEXPR_COMPLEX)
  #if __cpp_lib_constexpr_complex >= 202306L
    #define LBAL_LIBCPP26_CONSTEXPR_COMPLEX __cpp_lib_constexpr_complex
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_COMPLEX

#if !defined(LBAL_LIBCPP26_CONSTEXPR_DEQUE)
  #if __cpp_lib_constexpr_deque >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_DEQUE __cpp_lib_constexpr_deque
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_DEQUE

#if !defined(LBAL_LIBCPP26_CONSTEXPR_EXCEPTIONS)
  #if __cpp_lib_constexpr_exceptions >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_EXCEPTIONS __cpp_lib_constexpr_exceptions
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_EXCEPTIONS

#if !defined(LBAL_LIBCPP26_CONSTEXPR_FLAT_MAP)
  #if __cpp_lib_constexpr_flat_map >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_FLAT_MAP __cpp_lib_constexpr_flat_map
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_FLAT_MAP

#if !defined(LBAL_LIBCPP26_CONSTEXPR_FLAT_SET)
  #if __cpp_lib_constexpr_flat_set >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_FLAT_SET __cpp_lib_constexpr_flat_set
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_FLAT_SET

#if !defined(LBAL_LIBCPP26_CONSTEXPR_FORMAT)
  #if __cpp_lib_constexpr_format >= 202511L
    #define LBAL_LIBCPP26_CONSTEXPR_FORMAT __cpp_lib_constexpr_format
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_FORMAT

#if !defined(LBAL_LIBCPP26_CONSTEXPR_FORWARD_LIST)
  #if __cpp_lib_constexpr_forward_list >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_FORWARD_LIST                               \
      __cpp_lib_constexpr_forward_list
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_FORWARD_LIST

#if !defined(LBAL_LIBCPP26_CONSTEXPR_LIST)
  #if __cpp_lib_constexpr_list >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_LIST __cpp_lib_constexpr_list
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_LIST

#if !defined(LBAL_LIBCPP26_CONSTEXPR_MAP)
  #if __cpp_lib_constexpr_map >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_MAP __cpp_lib_constexpr_map
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_MAP

#if !defined(LBAL_LIBCPP26_CONSTEXPR_MEMORY_SHARED_PTR)
  #if __cpp_lib_constexpr_memory >= 202506L
    #define LBAL_LIBCPP26_CONSTEXPR_MEMORY_SHARED_PTR __cpp_lib_constexpr_memory
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_MEMORY_SHARED_PTR

#if !defined(LBAL_LIBCPP26_CONSTEXPR_QUEUE)
  #if __cpp_lib_constexpr_queue >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_QUEUE __cpp_lib_constexpr_queue
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_QUEUE

#if !defined(LBAL_LIBCPP26_CONSTEXPR_SET)
  #if __cpp_lib_constexpr_set >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_SET __cpp_lib_constexpr_set
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_SET

#if !defined(LBAL_LIBCPP26_CONSTEXPR_STACK)
  #if __cpp_lib_constexpr_stack >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_STACK __cpp_lib_constexpr_stack
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_STACK

#if !defined(LBAL_LIBCPP26_CONSTEXPR_UNORDERED_MAP)
  #if __cpp_lib_constexpr_unordered_map >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_UNORDERED_MAP                              \
      __cpp_lib_constexpr_unordered_map
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_UNORDERED_MAP

#if !defined(LBAL_LIBCPP26_CONSTEXPR_UNORDERED_SET)
  #if __cpp_lib_constexpr_unordered_set >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_UNORDERED_SET                              \
      __cpp_lib_constexpr_unordered_set
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_UNORDERED_SET

#if !defined(LBAL_LIBCPP26_CONSTRAINED_EQUALITY)
  #if __cpp_lib_constrained_equality >= 202403L
    #define LBAL_LIBCPP26_CONSTRAINED_EQUALITY __cpp_lib_constrained_equality
  #endif
#endif  //  LBAL_LIBCPP26_CONSTRAINED_EQUALITY

#if !defined(LBAL_LIBCPP26_CONSTRAINED_EQUALITY_EXPECTED)
  #if __cpp_lib_constrained_equality >= 202411L
    #define LBAL_LIBCPP26_CONSTRAINED_EQUALITY_EXPECTED                        \
      __cpp_lib_constrained_equality
  #endif
#endif  //  LBAL_LIBCPP26_CONSTRAINED_EQUALITY_EXPECTED

#if !defined(LBAL_LIBCPP26_COPYABLE_FUNCTION)
  #if __cpp_lib_copyable_function >= 202306L
    #define LBAL_LIBCPP26_COPYABLE_FUNCTION __cpp_lib_copyable_function
  #endif
#endif  //  LBAL_LIBCPP26_COPYABLE_FUNCTION

#if !defined(LBAL_LIBCPP26_COUNTING_SCOPE)
  #if __cpp_lib_counting_scope >= 202506L
    #define LBAL_LIBCPP26_COUNTING_SCOPE __cpp_lib_counting_scope
  #endif
#endif  //  LBAL_LIBCPP26_COUNTING_SCOPE

#if !defined(LBAL_LIBCPP26_DEBUGGING)
  #if __cpp_lib_debugging >= 202311L
    #define LBAL_LIBCPP26_DEBUGGING __cpp_lib_debugging
  #endif
#endif  //  LBAL_LIBCPP26_DEBUGGING

#if !defined(LBAL_LIBCPP26_DEBUGGING_UTILITIES)
  #if __cpp_lib_debugging >= 202403L
    #define LBAL_LIBCPP26_DEBUGGING_UTILITIES __cpp_lib_debugging
  #endif
#endif  //  LBAL_LIBCPP26_DEBUGGING_UTILITIES

#if !defined(LBAL_LIBCPP26_DEFAULT_TEMPLATE_TYPE_FOR_ALGORITHM_VALUES)
  #if __cpp_lib_default_template_type_for_algorithm_values >= 202403L
    #define LBAL_LIBCPP26_DEFAULT_TEMPLATE_TYPE_FOR_ALGORITHM_VALUES           \
      __cpp_lib_default_template_type_for_algorithm_values
  #endif
#endif  //  LBAL_LIBCPP26_DEFAULT_TEMPLATE_TYPE_FOR_ALGORITHM_VALUES

#if !defined(LBAL_LIBCPP26_DEFINE_STATIC)
  #if __cpp_lib_define_static >= 202506L
    #define LBAL_LIBCPP26_DEFINE_STATIC __cpp_lib_define_static
  #endif
#endif  //  LBAL_LIBCPP26_DEFINE_STATIC

#if !defined(LBAL_LIBCPP26_EXCEPTION_PTR_CAST)
  #if __cpp_lib_exception_ptr_cast >= 202506L
    #define LBAL_LIBCPP26_EXCEPTION_PTR_CAST __cpp_lib_exception_ptr_cast
  #endif
#endif  //  LBAL_LIBCPP26_EXCEPTION_PTR_CAST

#if !defined(LBAL_LIBCPP26_EXCEPTION_PTR_CAST_BETTER_RETURN_TYPES)
  #if __cpp_lib_exception_ptr_cast >= 202603L
    #define LBAL_LIBCPP26_EXCEPTION_PTR_CAST_BETTER_RETURN_TYPES               \
      __cpp_lib_exception_ptr_cast
  #endif
#endif  //  LBAL_LIBCPP26_EXCEPTION_PTR_CAST_BETTER_RETURN_TYPES

#if !defined(LBAL_LIBCPP26_EXCEPTION_PTR_CAST_CONSTEXPR)
  #if __cpp_lib_exception_ptr_cast >= 202506L
    #define LBAL_LIBCPP26_EXCEPTION_PTR_CAST_CONSTEXPR                         \
      __cpp_lib_exception_ptr_cast
  #endif
#endif  //  LBAL_LIBCPP26_EXCEPTION_PTR_CAST_CONSTEXPR

#if !defined(LBAL_LIBCPP26_FLAT_MAP_FIXES)
  #if __cpp_lib_flat_map >= 202511L
    #define LBAL_LIBCPP26_FLAT_MAP_FIXES __cpp_lib_flat_map
  #endif
#endif  //  LBAL_LIBCPP26_FLAT_MAP_FIXES

#if !defined(LBAL_LIBCPP26_FLAT_SET_FIXES)
  #if __cpp_lib_flat_set >= 202511L
    #define LBAL_LIBCPP26_FLAT_SET_FIXES __cpp_lib_flat_set
  #endif
#endif  //  LBAL_LIBCPP26_FLAT_SET_FIXES

#if !defined(LBAL_LIBCPP26_FORMAT_MEMBER_VISIT)
  #if __cpp_lib_format >= 202306L
    #define LBAL_LIBCPP26_FORMAT_MEMBER_VISIT __cpp_lib_format
  #endif
#endif  //  LBAL_LIBCPP26_FORMAT_MEMBER_VISIT

#if !defined(LBAL_LIBCPP26_FORMAT_PATH)
  #if __cpp_lib_format_path >= 202403L
    #define LBAL_LIBCPP26_FORMAT_PATH __cpp_lib_format_path
  #endif
#endif  //  LBAL_LIBCPP26_FORMAT_PATH

#if !defined(LBAL_LIBCPP26_FORMAT_PATH_FIXES)
  #if __cpp_lib_format_path >= 202506L
    #define LBAL_LIBCPP26_FORMAT_PATH_FIXES __cpp_lib_format_path
  #endif
#endif  //  LBAL_LIBCPP26_FORMAT_PATH_FIXES

#if !defined(LBAL_LIBCPP26_FORMAT_POINTERS)
  #if __cpp_lib_format >= 202304L
    #define LBAL_LIBCPP26_FORMAT_POINTERS __cpp_lib_format
  #endif
#endif  //  LBAL_LIBCPP26_FORMAT_POINTERS

#if !defined(LBAL_LIBCPP26_FORMAT_RUNTIME)
  #if __cpp_lib_format >= 202311L
    #define LBAL_LIBCPP26_FORMAT_RUNTIME __cpp_lib_format
  #endif
#endif  //  LBAL_LIBCPP26_FORMAT_RUNTIME

#if !defined(LBAL_LIBCPP26_FORMAT_TYPE_CHECK)
  #if __cpp_lib_format >= 202305L
    #define LBAL_LIBCPP26_FORMAT_TYPE_CHECK __cpp_lib_format
  #endif
#endif  //  LBAL_LIBCPP26_FORMAT_TYPE_CHECK

#if !defined(LBAL_LIBCPP26_FORMAT_UCHAR)
  #if __cpp_lib_format_uchar >= 202311L
    #define LBAL_LIBCPP26_FORMAT_UCHAR __cpp_lib_format_uchar
  #endif
#endif  //  LBAL_LIBCPP26_FORMAT_UCHAR

#if !defined(LBAL_LIBCPP26_FREESTANDING_ALGORITHM)
  #if __cpp_lib_freestanding_algorithm >= 202311L
    #define LBAL_LIBCPP26_FREESTANDING_ALGORITHM                               \
      __cpp_lib_freestanding_algorithm
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_ALGORITHM

#if !defined(LBAL_LIBCPP26_FREESTANDING_ALGORITHM_MORE)
  #if __cpp_lib_freestanding_algorithm >= 202502L
    #define LBAL_LIBCPP26_FREESTANDING_ALGORITHM_MORE                          \
      __cpp_lib_freestanding_algorithm
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_ALGORITHM_MORE

#if !defined(LBAL_LIBCPP26_FREESTANDING_ARRAY)
  #if __cpp_lib_freestanding_array >= 202311L
    #define LBAL_LIBCPP26_FREESTANDING_ARRAY __cpp_lib_freestanding_array
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_ARRAY

#if !defined(LBAL_LIBCPP26_FREESTANDING_CHARCONV)
  #if __cpp_lib_freestanding_charconv >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_CHARCONV __cpp_lib_freestanding_charconv
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_CHARCONV

#if !defined(LBAL_LIBCPP26_FREESTANDING_CHAR_TRAITS)
  #if __cpp_lib_freestanding_char_traits >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_CHAR_TRAITS                             \
      __cpp_lib_freestanding_char_traits
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_CHAR_TRAITS

#if !defined(LBAL_LIBCPP26_FREESTANDING_CSTDLIB)
  #if __cpp_lib_freestanding_cstdlib >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_CSTDLIB __cpp_lib_freestanding_cstdlib
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_CSTDLIB

#if !defined(LBAL_LIBCPP26_FREESTANDING_CSTRING)
  #if __cpp_lib_freestanding_cstring >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_CSTRING __cpp_lib_freestanding_cstring
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_CSTRING

#if !defined(LBAL_LIBCPP26_FREESTANDING_CSTRING_REMOVE_STRTOK)
  #if __cpp_lib_freestanding_cstring >= 202311L
    #define LBAL_LIBCPP26_FREESTANDING_CSTRING_REMOVE_STRTOK                   \
      __cpp_lib_freestanding_cstring
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_CSTRING_REMOVE_STRTOK

#if !defined(LBAL_LIBCPP26_FREESTANDING_CWCHAR)
  #if __cpp_lib_freestanding_cwchar >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_CWCHAR __cpp_lib_freestanding_cwchar
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_CWCHAR

#if !defined(LBAL_LIBCPP26_FREESTANDING_ERRC)
  #if __cpp_lib_freestanding_errc >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_ERRC __cpp_lib_freestanding_errc
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_ERRC

#if !defined(LBAL_LIBCPP26_FREESTANDING_EXECUTION)
  #if __cpp_lib_freestanding_execution >= 202502L
    #define LBAL_LIBCPP26_FREESTANDING_EXECUTION                               \
      __cpp_lib_freestanding_execution
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_EXECUTION

#if !defined(LBAL_LIBCPP26_FREESTANDING_EXPECTED)
  #if __cpp_lib_freestanding_expected >= 202311L
    #define LBAL_LIBCPP26_FREESTANDING_EXPECTED __cpp_lib_freestanding_expected
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_EXPECTED

#if !defined(LBAL_LIBCPP26_FREESTANDING_FEATURE_TEST_MACROS)
  #if __cpp_lib_freestanding_feature_test_macros >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_FEATURE_TEST_MACROS                     \
      __cpp_lib_freestanding_feature_test_macros
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_FEATURE_TEST_MACROS

#if !defined(LBAL_LIBCPP26_FREESTANDING_FUNCTIONAL)
  #if __cpp_lib_freestanding_functional >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_FUNCTIONAL                              \
      __cpp_lib_freestanding_functional
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_FUNCTIONAL

#if !defined(LBAL_LIBCPP26_FREESTANDING_ITERATOR)
  #if __cpp_lib_freestanding_iterator >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_ITERATOR __cpp_lib_freestanding_iterator
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_ITERATOR

#if !defined(LBAL_LIBCPP26_FREESTANDING_MDSPAN)
  #if __cpp_lib_freestanding_mdspan >= 202311L
    #define LBAL_LIBCPP26_FREESTANDING_MDSPAN __cpp_lib_freestanding_mdspan
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_MDSPAN

#if !defined(LBAL_LIBCPP26_FREESTANDING_MEMORY)
  #if __cpp_lib_freestanding_memory >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_MEMORY __cpp_lib_freestanding_memory
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_MEMORY

#if !defined(LBAL_LIBCPP26_FREESTANDING_MEMORY_MORE)
  #if __cpp_lib_freestanding_memory >= 202502L
    #define LBAL_LIBCPP26_FREESTANDING_MEMORY_MORE __cpp_lib_freestanding_memory
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_MEMORY_MORE

#if !defined(LBAL_LIBCPP26_FREESTANDING_NUMERIC)
  #if __cpp_lib_freestanding_numeric >= 202502L
    #define LBAL_LIBCPP26_FREESTANDING_NUMERIC __cpp_lib_freestanding_numeric
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_NUMERIC

#if !defined(LBAL_LIBCPP26_FREESTANDING_OPERATOR_NEW)
  #if __cpp_lib_freestanding_operator_new >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_OPERATOR_NEW                            \
      __cpp_lib_freestanding_operator_new
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_OPERATOR_NEW

#if !defined(LBAL_LIBCPP26_FREESTANDING_OPTIONAL)
  #if __cpp_lib_freestanding_optional >= 202311L
    #define LBAL_LIBCPP26_FREESTANDING_OPTIONAL __cpp_lib_freestanding_optional
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_OPTIONAL

#if !defined(LBAL_LIBCPP26_FREESTANDING_RANDOM)
  #if __cpp_lib_freestanding_random >= 202502L
    #define LBAL_LIBCPP26_FREESTANDING_RANDOM __cpp_lib_freestanding_random
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_RANDOM

#if !defined(LBAL_LIBCPP26_FREESTANDING_RANGES)
  #if __cpp_lib_freestanding_ranges >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_RANGES __cpp_lib_freestanding_ranges
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_RANGES

#if !defined(LBAL_LIBCPP26_FREESTANDING_RATIO)
  #if __cpp_lib_freestanding_ratio >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_RATIO __cpp_lib_freestanding_ratio
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_RATIO

#if !defined(LBAL_LIBCPP26_FREESTANDING_STRING_VIEW)
  #if __cpp_lib_freestanding_string_view >= 202311L
    #define LBAL_LIBCPP26_FREESTANDING_STRING_VIEW                             \
      __cpp_lib_freestanding_string_view
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_STRING_VIEW

#if !defined(LBAL_LIBCPP26_FREESTANDING_TUPLE)
  #if __cpp_lib_freestanding_tuple >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_TUPLE __cpp_lib_freestanding_tuple
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_TUPLE

#if !defined(LBAL_LIBCPP26_FREESTANDING_UTILITY)
  #if __cpp_lib_freestanding_utility >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_UTILITY __cpp_lib_freestanding_utility
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_UTILITY

#if !defined(LBAL_LIBCPP26_FREESTANDING_VARIANT)
  #if __cpp_lib_freestanding_variant >= 202311L
    #define LBAL_LIBCPP26_FREESTANDING_VARIANT __cpp_lib_freestanding_variant
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_VARIANT

#if !defined(LBAL_LIBCPP26_FSTREAM_NATIVE_HANDLE)
  #if __cpp_lib_fstream_native_handle >= 202306L
    #define LBAL_LIBCPP26_FSTREAM_NATIVE_HANDLE __cpp_lib_fstream_native_handle
  #endif
#endif  //  LBAL_LIBCPP26_FSTREAM_NATIVE_HANDLE

#if !defined(LBAL_LIBCPP26_FUNCTION_REF)
  #if __cpp_lib_function_ref >= 202306L
    #define LBAL_LIBCPP26_FUNCTION_REF __cpp_lib_function_ref
  #endif
#endif  //  LBAL_LIBCPP26_FUNCTION_REF

#if !defined(LBAL_LIBCPP26_FUNCTION_REF_LESS_DOUBLE_INDIRECTION)
  #if __cpp_lib_function_ref >= 202603L
    #define LBAL_LIBCPP26_FUNCTION_REF_LESS_DOUBLE_INDIRECTION                 \
      __cpp_lib_function_ref
  #endif
#endif  //  LBAL_LIBCPP26_FUNCTION_REF_LESS_DOUBLE_INDIRECTION

#if !defined(LBAL_LIBCPP26_FUNCTION_REF_RENAME_NONTYPE)
  #if __cpp_lib_function_ref >= 202511L
    #define LBAL_LIBCPP26_FUNCTION_REF_RENAME_NONTYPE __cpp_lib_function_ref
  #endif
#endif  //  LBAL_LIBCPP26_FUNCTION_REF_RENAME_NONTYPE

#if !defined(LBAL_LIBCPP26_GENERATE_RANDOM)
  #if __cpp_lib_generate_random >= 202403L
    #define LBAL_LIBCPP26_GENERATE_RANDOM __cpp_lib_generate_random
  #endif
#endif  //  LBAL_LIBCPP26_GENERATE_RANDOM

#if !defined(LBAL_LIBCPP26_HARDENED_ARRAY)
  #if __cpp_lib_hardened_array >= 202502L
    #define LBAL_LIBCPP26_HARDENED_ARRAY __cpp_lib_hardened_array
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_ARRAY

#if !defined(LBAL_LIBCPP26_HARDENED_BASIC_STACKTRACE)
  #if __cpp_lib_hardened_basic_stacktrace >= 202506L
    #define LBAL_LIBCPP26_HARDENED_BASIC_STACKTRACE                            \
      __cpp_lib_hardened_basic_stacktrace
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_BASIC_STACKTRACE

#if !defined(LBAL_LIBCPP26_HARDENED_BASIC_STRING)
  #if __cpp_lib_hardened_basic_string >= 202502L
    #define LBAL_LIBCPP26_HARDENED_BASIC_STRING __cpp_lib_hardened_basic_string
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_BASIC_STRING

#if !defined(LBAL_LIBCPP26_HARDENED_BASIC_STRING_VIEW)
  #if __cpp_lib_hardened_basic_string_view >= 202502L
    #define LBAL_LIBCPP26_HARDENED_BASIC_STRING_VIEW                           \
      __cpp_lib_hardened_basic_string_view
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_BASIC_STRING_VIEW

#if !defined(LBAL_LIBCPP26_HARDENED_BITSET)
  #if __cpp_lib_hardened_bitset >= 202502L
    #define LBAL_LIBCPP26_HARDENED_BITSET __cpp_lib_hardened_bitset
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_BITSET

#if !defined(LBAL_LIBCPP26_HARDENED_COMMON_ITERATOR)
  #if __cpp_lib_hardened_common_iterator >= 202506L
    #define LBAL_LIBCPP26_HARDENED_COMMON_ITERATOR                             \
      __cpp_lib_hardened_common_iterator
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_COMMON_ITERATOR

#if !defined(LBAL_LIBCPP26_HARDENED_COUNTED_ITERATOR)
  #if __cpp_lib_hardened_counted_iterator >= 202506L
    #define LBAL_LIBCPP26_HARDENED_COUNTED_ITERATOR                            \
      __cpp_lib_hardened_counted_iterator
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_COUNTED_ITERATOR

#if !defined(LBAL_LIBCPP26_HARDENED_DEQUE)
  #if __cpp_lib_hardened_deque >= 202502L
    #define LBAL_LIBCPP26_HARDENED_DEQUE __cpp_lib_hardened_deque
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_DEQUE

#if !defined(LBAL_LIBCPP26_HARDENED_EXPECTED)
  #if __cpp_lib_hardened_expected >= 202502L
    #define LBAL_LIBCPP26_HARDENED_EXPECTED __cpp_lib_hardened_expected
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_EXPECTED

#if !defined(LBAL_LIBCPP26_HARDENED_FORWARD_LIST)
  #if __cpp_lib_hardened_forward_list >= 202502L
    #define LBAL_LIBCPP26_HARDENED_FORWARD_LIST __cpp_lib_hardened_forward_list
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_FORWARD_LIST

#if !defined(LBAL_LIBCPP26_HARDENED_INPLACE_VECTOR)
  #if __cpp_lib_hardened_inplace_vector >= 202502L
    #define LBAL_LIBCPP26_HARDENED_INPLACE_VECTOR                              \
      __cpp_lib_hardened_inplace_vector
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_INPLACE_VECTOR

#if !defined(LBAL_LIBCPP26_HARDENED_LIST)
  #if __cpp_lib_hardened_list >= 202502L
    #define LBAL_LIBCPP26_HARDENED_LIST __cpp_lib_hardened_list
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_LIST

#if !defined(LBAL_LIBCPP26_HARDENED_MDSPAN)
  #if __cpp_lib_hardened_mdspan >= 202502L
    #define LBAL_LIBCPP26_HARDENED_MDSPAN __cpp_lib_hardened_mdspan
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_MDSPAN

#if !defined(LBAL_LIBCPP26_HARDENED_OPTIONAL)
  #if __cpp_lib_hardened_optional >= 202502L
    #define LBAL_LIBCPP26_HARDENED_OPTIONAL __cpp_lib_hardened_optional
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_OPTIONAL

#if !defined(LBAL_LIBCPP26_HARDENED_SHARED_PTR_ARRAY)
  #if __cpp_lib_hardened_shared_ptr_array >= 202506L
    #define LBAL_LIBCPP26_HARDENED_SHARED_PTR_ARRAY                            \
      __cpp_lib_hardened_shared_ptr_array
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_SHARED_PTR_ARRAY

#if !defined(LBAL_LIBCPP26_HARDENED_SPAN)
  #if __cpp_lib_hardened_span >= 202502L
    #define LBAL_LIBCPP26_HARDENED_SPAN __cpp_lib_hardened_span
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_SPAN

#if !defined(LBAL_LIBCPP26_HARDENED_VALARRAY)
  #if __cpp_lib_hardened_valarray >= 202502L
    #define LBAL_LIBCPP26_HARDENED_VALARRAY __cpp_lib_hardened_valarray
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_VALARRAY

#if !defined(LBAL_LIBCPP26_HARDENED_VECTOR)
  #if __cpp_lib_hardened_vector >= 202502L
    #define LBAL_LIBCPP26_HARDENED_VECTOR __cpp_lib_hardened_vector
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_VECTOR

#if !defined(LBAL_LIBCPP26_HARDENED_VIEW_INTERFACE)
  #if __cpp_lib_hardened_view_interface >= 202506L
    #define LBAL_LIBCPP26_HARDENED_VIEW_INTERFACE                              \
      __cpp_lib_hardened_view_interface
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_VIEW_INTERFACE

#if !defined(LBAL_LIBCPP26_HAZARD_POINTER)
  #if __cpp_lib_hazard_pointer >= 202306L
    #define LBAL_LIBCPP26_HAZARD_POINTER __cpp_lib_hazard_pointer
  #endif
#endif  //  LBAL_LIBCPP26_HAZARD_POINTER

#if !defined(LBAL_LIBCPP26_HIVE)
  #if __cpp_lib_hive >= 202502L
    #define LBAL_LIBCPP26_HIVE __cpp_lib_hive
  #endif
#endif  //  LBAL_LIBCPP26_HIVE

#if !defined(LBAL_LIBCPP26_INDIRECT)
  #if __cpp_lib_indirect >= 202502L
    #define LBAL_LIBCPP26_INDIRECT __cpp_lib_indirect
  #endif
#endif  //  LBAL_LIBCPP26_INDIRECT

#if !defined(LBAL_LIBCPP26_INITIALIZER_LIST)
  #if __cpp_lib_initializer_list >= 202511L
    #define LBAL_LIBCPP26_INITIALIZER_LIST __cpp_lib_initializer_list
  #endif
#endif  //  LBAL_LIBCPP26_INITIALIZER_LIST

#if !defined(LBAL_LIBCPP26_INPLACE_VECTOR)
  #if __cpp_lib_inplace_vector >= 202406L
    #define LBAL_LIBCPP26_INPLACE_VECTOR __cpp_lib_inplace_vector
  #endif
#endif  //  LBAL_LIBCPP26_INPLACE_VECTOR

#if !defined(LBAL_LIBCPP26_INPLACE_VECTOR_BETTER_RETURN_TYPES)
  #if __cpp_lib_inplace_vector >= 202603L
    #define LBAL_LIBCPP26_INPLACE_VECTOR_BETTER_RETURN_TYPES                   \
      __cpp_lib_inplace_vector
  #endif
#endif  //  LBAL_LIBCPP26_INPLACE_VECTOR_BETTER_RETURN_TYPES

#if !defined(LBAL_LIBCPP26_INPLACE_VECTOR_REMOVE_TRY_APPEND_RANGE)
  #if __cpp_lib_inplace_vector >= 202603L
    #define LBAL_LIBCPP26_INPLACE_VECTOR_REMOVE_TRY_APPEND_RANGE               \
      __cpp_lib_inplace_vector
  #endif
#endif  //  LBAL_LIBCPP26_INPLACE_VECTOR_REMOVE_TRY_APPEND_RANGE

#if !defined(LBAL_LIBCPP26_INTEGER_SEQUENCE_EXPANSION_STATEMENTS)
  #if __cpp_lib_integer_sequence >= 202511L
    #define LBAL_LIBCPP26_INTEGER_SEQUENCE_EXPANSION_STATEMENTS                \
      __cpp_lib_integer_sequence
  #endif
#endif  //  LBAL_LIBCPP26_INTEGER_SEQUENCE_EXPANSION_STATEMENTS

#if !defined(LBAL_LIBCPP26_IS_STRUCTURAL)
  #if __cpp_lib_is_structural >= 202603L
    #define LBAL_LIBCPP26_IS_STRUCTURAL __cpp_lib_is_structural
  #endif
#endif  //  LBAL_LIBCPP26_IS_STRUCTURAL

#if !defined(LBAL_LIBCPP26_IS_VIRTUAL_BASE_OF)
  #if __cpp_lib_is_virtual_base_of >= 202406L
    #define LBAL_LIBCPP26_IS_VIRTUAL_BASE_OF __cpp_lib_is_virtual_base_of
  #endif
#endif  //  LBAL_LIBCPP26_IS_VIRTUAL_BASE_OF

#if !defined(LBAL_LIBCPP26_IS_WITHIN_LIFETIME)
  #if __cpp_lib_is_within_lifetime >= 202306L
    #define LBAL_LIBCPP26_IS_WITHIN_LIFETIME __cpp_lib_is_within_lifetime
  #endif
#endif  //  LBAL_LIBCPP26_IS_WITHIN_LIFETIME

#if !defined(LBAL_LIBCPP26_IS_WITHIN_LIFETIME_EXTEND)
  #if __cpp_lib_is_within_lifetime >= 202603L
    #define LBAL_LIBCPP26_IS_WITHIN_LIFETIME_EXTEND __cpp_lib_is_within_lifetime
  #endif
#endif  //  LBAL_LIBCPP26_IS_WITHIN_LIFETIME_EXTEND

#if !defined(LBAL_LIBCPP26_LINALG)
  #if __cpp_lib_linalg >= 202311L
    #define LBAL_LIBCPP26_LINALG __cpp_lib_linalg
  #endif
#endif  //  LBAL_LIBCPP26_LINALG

#if !defined(LBAL_LIBCPP26_LINALG_BLAS_RANK)
  #if __cpp_lib_linalg >= 202511L
    #define LBAL_LIBCPP26_LINALG_BLAS_RANK __cpp_lib_linalg
  #endif
#endif  //  LBAL_LIBCPP26_LINALG_BLAS_RANK

#if !defined(LBAL_LIBCPP26_LINALG_FIX_TRANSPOSED)
  #if __cpp_lib_linalg >= 202411L
    #define LBAL_LIBCPP26_LINALG_FIX_TRANSPOSED __cpp_lib_linalg
  #endif
#endif  //  LBAL_LIBCPP26_LINALG_FIX_TRANSPOSED

#if !defined(LBAL_LIBCPP26_LINALG_OPTIMIZE_CONJUGATED)
  #if __cpp_lib_linalg >= 202411L
    #define LBAL_LIBCPP26_LINALG_OPTIMIZE_CONJUGATED __cpp_lib_linalg
  #endif
#endif  //  LBAL_LIBCPP26_LINALG_OPTIMIZE_CONJUGATED

#if !defined(LBAL_LIBCPP26_MDSPAN_DEXTENTS)
  #if __cpp_lib_mdspan >= 202406L
    #define LBAL_LIBCPP26_MDSPAN_DEXTENTS __cpp_lib_mdspan
  #endif
#endif  //  LBAL_LIBCPP26_MDSPAN_DEXTENTS

#if !defined(LBAL_LIBCPP26_NOT_FN_NTTP_CALLABLES)
  #if __cpp_lib_not_fn >= 202306L
    #define LBAL_LIBCPP26_NOT_FN_NTTP_CALLABLES __cpp_lib_not_fn
  #endif
#endif  //  LBAL_LIBCPP26_NOT_FN_NTTP_CALLABLES

#if !defined(LBAL_LIBCPP26_OBSERVABLE_CHECKPOINT)
  #if __cpp_lib_observable_checkpoint >= 202506L
    #define LBAL_LIBCPP26_OBSERVABLE_CHECKPOINT __cpp_lib_observable_checkpoint
  #endif
#endif  //  LBAL_LIBCPP26_OBSERVABLE_CHECKPOINT

#if !defined(LBAL_LIBCPP26_OPTIONAL_RANGE_SUPPORT)
  #if __cpp_lib_optional_range_support >= 202406L
    #define LBAL_LIBCPP26_OPTIONAL_RANGE_SUPPORT                               \
      __cpp_lib_optional_range_support
  #endif
#endif  //  LBAL_LIBCPP26_OPTIONAL_RANGE_SUPPORT

#if !defined(LBAL_LIBCPP26_OPTIONAL_REFERENCE)
  #if __cpp_lib_optional >= 202506L
    #define LBAL_LIBCPP26_OPTIONAL_REFERENCE __cpp_lib_optional
  #endif
#endif  //  LBAL_LIBCPP26_OPTIONAL_REFERENCE

#if !defined(LBAL_LIBCPP26_OUT_PTR_MORE)
  #if __cpp_lib_out_ptr >= 202311L
    #define LBAL_LIBCPP26_OUT_PTR_MORE __cpp_lib_out_ptr
  #endif
#endif  //  LBAL_LIBCPP26_OUT_PTR_MORE

#if !defined(LBAL_LIBCPP26_PARALLEL_ALGORITHM_RANGE)
  #if __cpp_lib_parallel_algorithm >= 202506L
    #define LBAL_LIBCPP26_PARALLEL_ALGORITHM_RANGE __cpp_lib_parallel_algorithm
  #endif
#endif  //  LBAL_LIBCPP26_PARALLEL_ALGORITHM_RANGE

#if !defined(LBAL_LIBCPP26_PARALLEL_SCHEDULER)
  #if __cpp_lib_parallel_scheduler >= 202506L
    #define LBAL_LIBCPP26_PARALLEL_SCHEDULER __cpp_lib_parallel_scheduler
  #endif
#endif  //  LBAL_LIBCPP26_PARALLEL_SCHEDULER

#if !defined(LBAL_LIBCPP26_PHILOX_ENGINE)
  #if __cpp_lib_philox_engine >= 202406L
    #define LBAL_LIBCPP26_PHILOX_ENGINE __cpp_lib_philox_engine
  #endif
#endif  //  LBAL_LIBCPP26_PHILOX_ENGINE

#if !defined(LBAL_LIBCPP26_POLYMORPHIC)
  #if __cpp_lib_polymorphic >= 202502L
    #define LBAL_LIBCPP26_POLYMORPHIC __cpp_lib_polymorphic
  #endif
#endif  //  LBAL_LIBCPP26_POLYMORPHIC

#if !defined(LBAL_LIBCPP26_PRINT_EFFICIENT)
  #if __cpp_lib_print >= 202403L
    #define LBAL_LIBCPP26_PRINT_EFFICIENT __cpp_lib_print
  #endif
#endif  //  LBAL_LIBCPP26_PRINT_EFFICIENT

#if !defined(LBAL_LIBCPP26_PRINT_MORE_EFFICIENT)
  #if __cpp_lib_print >= 202406L
    #define LBAL_LIBCPP26_PRINT_MORE_EFFICIENT __cpp_lib_print
  #endif
#endif  //  LBAL_LIBCPP26_PRINT_MORE_EFFICIENT

#if !defined(LBAL_LIBCPP26_RANGES_AS_CONST_FIX_CONVERTIBILITY)
  #if __cpp_lib_ranges_as_const >= 202311L
    #define LBAL_LIBCPP26_RANGES_AS_CONST_FIX_CONVERTIBILITY                   \
      __cpp_lib_ranges_as_const
  #endif
#endif  //  LBAL_LIBCPP26_RANGES_AS_CONST_FIX_CONVERTIBILITY

#if !defined(LBAL_LIBCPP26_RANGES_AS_INPUT)
  #if __cpp_lib_ranges_as_input >= 202502L
    #define LBAL_LIBCPP26_RANGES_AS_INPUT __cpp_lib_ranges_as_input
  #endif
#endif  //  LBAL_LIBCPP26_RANGES_AS_INPUT

#if !defined(LBAL_LIBCPP26_RANGES_AS_INPUT_RENAME)
  #if __cpp_lib_ranges_as_input >= 202502L
    #define LBAL_LIBCPP26_RANGES_AS_INPUT_RENAME __cpp_lib_ranges_as_input
  #endif
#endif  //  LBAL_LIBCPP26_RANGES_AS_INPUT_RENAME

#if !defined(LBAL_LIBCPP26_RANGES_CACHE_LATEST)
  #if __cpp_lib_ranges_cache_latest >= 202411L
    #define LBAL_LIBCPP26_RANGES_CACHE_LATEST __cpp_lib_ranges_cache_latest
  #endif
#endif  //  LBAL_LIBCPP26_RANGES_CACHE_LATEST

#if !defined(LBAL_LIBCPP26_RANGES_CONCAT)
  #if __cpp_lib_ranges_concat >= 202403L
    #define LBAL_LIBCPP26_RANGES_CONCAT __cpp_lib_ranges_concat
  #endif
#endif  //  LBAL_LIBCPP26_RANGES_CONCAT

#if !defined(LBAL_LIBCPP26_RANGES_FILTER)
  #if __cpp_lib_ranges_filter >= 202603L
    #define LBAL_LIBCPP26_RANGES_FILTER __cpp_lib_ranges_filter
  #endif
#endif  //  LBAL_LIBCPP26_RANGES_FILTER

#if !defined(LBAL_LIBCPP26_RANGES_INDICES)
  #if __cpp_lib_ranges_indices >= 202506L
    #define LBAL_LIBCPP26_RANGES_INDICES __cpp_lib_ranges_indices
  #endif
#endif  //  LBAL_LIBCPP26_RANGES_INDICES

#if !defined(LBAL_LIBCPP26_RANGES_REMOVE_COMMON_REF_REQ)
  #if __cpp_lib_ranges >= 202406L
    #define LBAL_LIBCPP26_RANGES_REMOVE_COMMON_REF_REQ __cpp_lib_ranges
  #endif
#endif  //  LBAL_LIBCPP26_RANGES_REMOVE_COMMON_REF_REQ

#if !defined(LBAL_LIBCPP26_RANGES_RESERVE_HINT)
  #if __cpp_lib_ranges_reserve_hint >= 202502L
    #define LBAL_LIBCPP26_RANGES_RESERVE_HINT __cpp_lib_ranges_reserve_hint
  #endif
#endif  //  LBAL_LIBCPP26_RANGES_RESERVE_HINT

#if !defined(LBAL_LIBCPP26_RATIO)
  #if __cpp_lib_ratio >= 202306L
    #define LBAL_LIBCPP26_RATIO __cpp_lib_ratio
  #endif
#endif  //  LBAL_LIBCPP26_RATIO

#if !defined(LBAL_LIBCPP26_RAW_MEMORY_ALGORITHMS_CONSTEXPR)
  #if __cpp_lib_raw_memory_algorithms >= 202411L
    #define LBAL_LIBCPP26_RAW_MEMORY_ALGORITHMS_CONSTEXPR                      \
      __cpp_lib_raw_memory_algorithms
  #endif
#endif  //  LBAL_LIBCPP26_RAW_MEMORY_ALGORITHMS_CONSTEXPR

#if !defined(LBAL_LIBCPP26_RCU)
  #if __cpp_lib_rcu >= 202306L
    #define LBAL_LIBCPP26_RCU __cpp_lib_rcu
  #endif
#endif  //  LBAL_LIBCPP26_RCU

#if !defined(LBAL_LIBCPP26_REFERENCE_WRAPPER)
  #if __cpp_lib_reference_wrapper >= 202403L
    #define LBAL_LIBCPP26_REFERENCE_WRAPPER __cpp_lib_reference_wrapper
  #endif
#endif  //  LBAL_LIBCPP26_REFERENCE_WRAPPER

#if !defined(LBAL_LIBCPP26_REFLECTION)
  #if __cpp_lib_reflection >= 202506L
    #define LBAL_LIBCPP26_REFLECTION __cpp_lib_reflection
  #endif
#endif  //  LBAL_LIBCPP26_REFLECTION

#if !defined(LBAL_LIBCPP26_REFLECTION_CLEANUP)
  #if __cpp_lib_reflection >= 202603L
    #define LBAL_LIBCPP26_REFLECTION_CLEANUP __cpp_lib_reflection
  #endif
#endif  //  LBAL_LIBCPP26_REFLECTION_CLEANUP

#if !defined(LBAL_LIBCPP26_REFLECTION_RENAME_TO_IS_VARARG_FUNCTION)
  #if __cpp_lib_reflection >= 202603L
    #define LBAL_LIBCPP26_REFLECTION_RENAME_TO_IS_VARARG_FUNCTION              \
      __cpp_lib_reflection
  #endif
#endif  //  LBAL_LIBCPP26_REFLECTION_RENAME_TO_IS_VARARG_FUNCTION

#if !defined(LBAL_LIBCPP26_REPLACEABLE_CONTRACT_VIOLATION_HANDLER)
  #if __cpp_lib_replaceable_contract_violation_handler >= 202306L
    #define LBAL_LIBCPP26_REPLACEABLE_CONTRACT_VIOLATION_HANDLER               \
      __cpp_lib_replaceable_contract_violation_handler
  #endif
#endif  //  LBAL_LIBCPP26_REPLACEABLE_CONTRACT_VIOLATION_HANDLER

#if !defined(LBAL_LIBCPP26_SATURATION_ARITHMETIC)
  #if __cpp_lib_saturation_arithmetic >= 202311L
    #define LBAL_LIBCPP26_SATURATION_ARITHMETIC __cpp_lib_saturation_arithmetic
  #endif
#endif  //  LBAL_LIBCPP26_SATURATION_ARITHMETIC

#if !defined(LBAL_LIBCPP26_SATURATION_ARITHMETIC_RENAMING)
  #if __cpp_lib_saturation_arithmetic >= 202603L
    #define LBAL_LIBCPP26_SATURATION_ARITHMETIC_RENAMING                       \
      __cpp_lib_saturation_arithmetic
  #endif
#endif  //  LBAL_LIBCPP26_SATURATION_ARITHMETIC_RENAMING

#if !defined(LBAL_LIBCPP26_SENDERS)
  #if __cpp_lib_senders >= 202406L
    #define LBAL_LIBCPP26_SENDERS __cpp_lib_senders
  #endif
#endif  //  LBAL_LIBCPP26_SENDERS

#if !defined(LBAL_LIBCPP26_SENDERS_OPTIONAL)
  #if __cpp_lib_senders >= 202506L
    #define LBAL_LIBCPP26_SENDERS_OPTIONAL __cpp_lib_senders
  #endif
#endif  //  LBAL_LIBCPP26_SENDERS_OPTIONAL

#if !defined(LBAL_LIBCPP26_SIMD)
  #if __cpp_lib_simd >= 202411L
    #define LBAL_LIBCPP26_SIMD __cpp_lib_simd
  #endif
#endif  //  LBAL_LIBCPP26_SIMD

#if !defined(LBAL_LIBCPP26_SIMD_BIT)
  #if __cpp_lib_simd >= 202502L
    #define LBAL_LIBCPP26_SIMD_BIT __cpp_lib_simd
  #endif
#endif  //  LBAL_LIBCPP26_SIMD_BIT

#if !defined(LBAL_LIBCPP26_SIMD_CHUNK)
  #if __cpp_lib_simd >= 202502L
    #define LBAL_LIBCPP26_SIMD_CHUNK __cpp_lib_simd
  #endif
#endif  //  LBAL_LIBCPP26_SIMD_CHUNK

#if !defined(LBAL_LIBCPP26_SIMD_COMPLEX)
  #if __cpp_lib_simd_complex >= 202502L
    #define LBAL_LIBCPP26_SIMD_COMPLEX __cpp_lib_simd_complex
  #endif
#endif  //  LBAL_LIBCPP26_SIMD_COMPLEX

#if !defined(LBAL_LIBCPP26_SIMD_DEDUCTION_GUIDES)
  #if __cpp_lib_simd >= 202511L
    #define LBAL_LIBCPP26_SIMD_DEDUCTION_GUIDES __cpp_lib_simd
  #endif
#endif  //  LBAL_LIBCPP26_SIMD_DEDUCTION_GUIDES

#if !defined(LBAL_LIBCPP26_SIMD_EXTEND)
  #if __cpp_lib_simd >= 202506L
    #define LBAL_LIBCPP26_SIMD_EXTEND __cpp_lib_simd
  #endif
#endif  //  LBAL_LIBCPP26_SIMD_EXTEND

#if !defined(LBAL_LIBCPP26_SIMD_IOTA)
  #if __cpp_lib_simd >= 202603L
    #define LBAL_LIBCPP26_SIMD_IOTA __cpp_lib_simd
  #endif
#endif  //  LBAL_LIBCPP26_SIMD_IOTA

#if !defined(LBAL_LIBCPP26_SIMD_NAMESPACES)
  #if __cpp_lib_simd >= 202502L
    #define LBAL_LIBCPP26_SIMD_NAMESPACES __cpp_lib_simd
  #endif
#endif  //  LBAL_LIBCPP26_SIMD_NAMESPACES

#if !defined(LBAL_LIBCPP26_SIMD_PERMUTATIONS)
  #if __cpp_lib_simd_permutations >= 202506L
    #define LBAL_LIBCPP26_SIMD_PERMUTATIONS __cpp_lib_simd_permutations
  #endif
#endif  //  LBAL_LIBCPP26_SIMD_PERMUTATIONS

#if !defined(LBAL_LIBCPP26_SIMD_RANGE)
  #if __cpp_lib_simd >= 202506L
    #define LBAL_LIBCPP26_SIMD_RANGE __cpp_lib_simd
  #endif
#endif  //  LBAL_LIBCPP26_SIMD_RANGE

#if !defined(LBAL_LIBCPP26_SMART_POINTER_OWNER_EQUALITY)
  #if __cpp_lib_smart_pointer_owner_equality >= 202306L
    #define LBAL_LIBCPP26_SMART_POINTER_OWNER_EQUALITY                         \
      __cpp_lib_smart_pointer_owner_equality
  #endif
#endif  //  LBAL_LIBCPP26_SMART_POINTER_OWNER_EQUALITY

#if !defined(LBAL_LIBCPP26_SMART_PTR_OWNER_EQUALITY)
  #if __cpp_lib_smart_ptr_owner_equality >= 202306L
    #define LBAL_LIBCPP26_SMART_PTR_OWNER_EQUALITY                             \
      __cpp_lib_smart_ptr_owner_equality
  #endif
#endif  //  LBAL_LIBCPP26_SMART_PTR_OWNER_EQUALITY

#if !defined(LBAL_LIBCPP26_SPAN_AT)
  #if __cpp_lib_span >= 202311L
    #define LBAL_LIBCPP26_SPAN_AT __cpp_lib_span
  #endif
#endif  //  LBAL_LIBCPP26_SPAN_AT

#if !defined(LBAL_LIBCPP26_SPAN_MORE)
  #if __cpp_lib_span >= 202311L
    #define LBAL_LIBCPP26_SPAN_MORE __cpp_lib_span
  #endif
#endif  //  LBAL_LIBCPP26_SPAN_MORE

#if !defined(LBAL_LIBCPP26_SSTREAM_FROM_STRING_VIEW)
  #if __cpp_lib_sstream_from_string_view >= 202306L
    #define LBAL_LIBCPP26_SSTREAM_FROM_STRING_VIEW                             \
      __cpp_lib_sstream_from_string_view
  #endif
#endif  //  LBAL_LIBCPP26_SSTREAM_FROM_STRING_VIEW

#if !defined(LBAL_LIBCPP26_START_LIFETIME)
  #if __cpp_lib_start_lifetime >= 202603L
    #define LBAL_LIBCPP26_START_LIFETIME __cpp_lib_start_lifetime
  #endif
#endif  //  LBAL_LIBCPP26_START_LIFETIME

#if !defined(LBAL_LIBCPP26_STDBIT_H)
  #if __cpp_lib_stdbit_h >= 202603L
    #define LBAL_LIBCPP26_STDBIT_H __cpp_lib_stdbit_h
  #endif
#endif  //  LBAL_LIBCPP26_STDBIT_H

#if !defined(LBAL_LIBCPP26_STDCKDINT_H)
  #if __cpp_lib_stdckdint_h >= 202603L
    #define LBAL_LIBCPP26_STDCKDINT_H __cpp_lib_stdckdint_h
  #endif
#endif  //  LBAL_LIBCPP26_STDCKDINT_H

#if !defined(LBAL_LIBCPP26_STRING_SUBVIEW)
  #if __cpp_lib_string_subview >= 202506L
    #define LBAL_LIBCPP26_STRING_SUBVIEW __cpp_lib_string_subview
  #endif
#endif  //  LBAL_LIBCPP26_STRING_SUBVIEW

#if !defined(LBAL_LIBCPP26_STRING_VIEW_CONCAT)
  #if __cpp_lib_string_view >= 202403L
    #define LBAL_LIBCPP26_STRING_VIEW_CONCAT __cpp_lib_string_view
  #endif
#endif  //  LBAL_LIBCPP26_STRING_VIEW_CONCAT

#if !defined(LBAL_LIBCPP26_SUBMDSPAN)
  #if __cpp_lib_submdspan >= 202306L
    #define LBAL_LIBCPP26_SUBMDSPAN __cpp_lib_submdspan
  #endif
#endif  //  LBAL_LIBCPP26_SUBMDSPAN

#if !defined(LBAL_LIBCPP26_SUBMDSPAN_FIX)
  #if __cpp_lib_submdspan >= 202411L
    #define LBAL_LIBCPP26_SUBMDSPAN_FIX __cpp_lib_submdspan
  #endif
#endif  //  LBAL_LIBCPP26_SUBMDSPAN_FIX

#if !defined(LBAL_LIBCPP26_SUBMDSPAN_FUTURE_PROOF)
  #if __cpp_lib_submdspan >= 202511L
    #define LBAL_LIBCPP26_SUBMDSPAN_FUTURE_PROOF __cpp_lib_submdspan
  #endif
#endif  //  LBAL_LIBCPP26_SUBMDSPAN_FUTURE_PROOF

#if !defined(LBAL_LIBCPP26_SUBMDSPAN_PADDED)
  #if __cpp_lib_submdspan >= 202403L
    #define LBAL_LIBCPP26_SUBMDSPAN_PADDED __cpp_lib_submdspan
  #endif
#endif  //  LBAL_LIBCPP26_SUBMDSPAN_PADDED

#if !defined(LBAL_LIBCPP26_SUBMDSPAN_UPDATE)
  #if __cpp_lib_submdspan >= 202603L
    #define LBAL_LIBCPP26_SUBMDSPAN_UPDATE __cpp_lib_submdspan
  #endif
#endif  //  LBAL_LIBCPP26_SUBMDSPAN_UPDATE

#if !defined(LBAL_LIBCPP26_TASK)
  #if __cpp_lib_task >= 202506L
    #define LBAL_LIBCPP26_TASK __cpp_lib_task
  #endif
#endif  //  LBAL_LIBCPP26_TASK

#if !defined(LBAL_LIBCPP26_TEXT_ENCODING)
  #if __cpp_lib_text_encoding >= 202306L
    #define LBAL_LIBCPP26_TEXT_ENCODING __cpp_lib_text_encoding
  #endif
#endif  //  LBAL_LIBCPP26_TEXT_ENCODING

#if !defined(LBAL_LIBCPP26_TO_CHARS_BOOL_TEST)
  #if __cpp_lib_to_chars >= 202306L
    #define LBAL_LIBCPP26_TO_CHARS_BOOL_TEST __cpp_lib_to_chars
  #endif
#endif  //  LBAL_LIBCPP26_TO_CHARS_BOOL_TEST

#if !defined(LBAL_LIBCPP26_TO_STRING)
  #if __cpp_lib_to_string >= 202306L
    #define LBAL_LIBCPP26_TO_STRING __cpp_lib_to_string
  #endif
#endif  //  LBAL_LIBCPP26_TO_STRING

#if !defined(LBAL_LIBCPP26_TUPLE_LIKE_COMPLEX)
  #if __cpp_lib_tuple_like >= 202311L
    #define LBAL_LIBCPP26_TUPLE_LIKE_COMPLEX __cpp_lib_tuple_like
  #endif
#endif  //  LBAL_LIBCPP26_TUPLE_LIKE_COMPLEX

#if !defined(LBAL_LIBCPP26_TYPE_ORDER)
  #if __cpp_lib_type_order >= 202506L
    #define LBAL_LIBCPP26_TYPE_ORDER __cpp_lib_type_order
  #endif
#endif  //  LBAL_LIBCPP26_TYPE_ORDER

#if !defined(LBAL_LIBCPP26_VALARRAY)
  #if __cpp_lib_valarray >= 202511L
    #define LBAL_LIBCPP26_VALARRAY __cpp_lib_valarray
  #endif
#endif  //  LBAL_LIBCPP26_VALARRAY

#if !defined(LBAL_LIBCPP26_VARIANT_VISITOR)
  #if __cpp_lib_variant >= 202306L
    #define LBAL_LIBCPP26_VARIANT_VISITOR __cpp_lib_variant
  #endif
#endif  //  LBAL_LIBCPP26_VARIANT_VISITOR
