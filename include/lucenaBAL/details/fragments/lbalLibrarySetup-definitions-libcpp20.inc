/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalLibrarySetup-definitions-libcpp20.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if !defined(LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS)
  #if __cpp_lib_array_constexpr >= 201806L
    #define LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS __cpp_lib_array_constexpr
  #endif
#endif  //  LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS

#if !defined(LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR)
  #if __cpp_lib_array_constexpr >= 201803L
    #define LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR __cpp_lib_array_constexpr
  #endif
#endif  //  LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR

#if !defined(LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES)
  #if __cpp_lib_array_constexpr >= 201811L
    #define LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES __cpp_lib_array_constexpr
  #endif
#endif  //  LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES

#if !defined(LBAL_LIBCPP20_ASSUME_ALIGNED)
  #if __cpp_lib_assume_aligned >= 201811L
    #define LBAL_LIBCPP20_ASSUME_ALIGNED __cpp_lib_assume_aligned
  #endif
#endif  //  LBAL_LIBCPP20_ASSUME_ALIGNED

#if !defined(LBAL_LIBCPP20_ATOMIC_FLAG_TEST)
  #if __cpp_lib_atomic_flag_test >= 201907L
    #define LBAL_LIBCPP20_ATOMIC_FLAG_TEST __cpp_lib_atomic_flag_test
  #endif
#endif  //  LBAL_LIBCPP20_ATOMIC_FLAG_TEST

#if !defined(LBAL_LIBCPP20_ATOMIC_FLOAT)
  #if __cpp_lib_atomic_float >= 201711L
    #define LBAL_LIBCPP20_ATOMIC_FLOAT __cpp_lib_atomic_float
  #endif
#endif  //  LBAL_LIBCPP20_ATOMIC_FLOAT

#if !defined(LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES)
  #if __cpp_lib_atomic_lock_free_type_aliases >= 201907L
    #define LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES                        \
      __cpp_lib_atomic_lock_free_type_aliases
  #endif
#endif  //  LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES

#if !defined(LBAL_LIBCPP20_ATOMIC_REF)
  #if __cpp_lib_atomic_ref >= 201806L
    #define LBAL_LIBCPP20_ATOMIC_REF __cpp_lib_atomic_ref
  #endif
#endif  //  LBAL_LIBCPP20_ATOMIC_REF

#if !defined(LBAL_LIBCPP20_ATOMIC_SHARED_PTR)
  #if __cpp_lib_atomic_shared_ptr >= 201711L
    #define LBAL_LIBCPP20_ATOMIC_SHARED_PTR __cpp_lib_atomic_shared_ptr
  #endif
#endif  //  LBAL_LIBCPP20_ATOMIC_SHARED_PTR

#if !defined(LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION)
  #if __cpp_lib_atomic_value_initialization >= 201911L
    #define LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION                          \
      __cpp_lib_atomic_value_initialization
  #endif
#endif  //  LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION

#if !defined(LBAL_LIBCPP20_ATOMIC_WAIT)
  #if __cpp_lib_atomic_wait >= 201907L
    #define LBAL_LIBCPP20_ATOMIC_WAIT __cpp_lib_atomic_wait
  #endif
#endif  //  LBAL_LIBCPP20_ATOMIC_WAIT

#if !defined(LBAL_LIBCPP20_BARRIER)
  #if __cpp_lib_barrier >= 201907L
    #define LBAL_LIBCPP20_BARRIER __cpp_lib_barrier
  #endif
#endif  //  LBAL_LIBCPP20_BARRIER

#if !defined(LBAL_LIBCPP20_BIND_FRONT)
  #if __cpp_lib_bind_front >= 201811L
    #define LBAL_LIBCPP20_BIND_FRONT __cpp_lib_bind_front
  #endif
#endif  //  LBAL_LIBCPP20_BIND_FRONT

#if !defined(LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP)
  #if __cpp_lib_bind_front >= 201907L
    #define LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP __cpp_lib_bind_front
  #endif
#endif  //  LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP

#if !defined(LBAL_LIBCPP20_BITOPS)
  #if __cpp_lib_bitops >= 201907L
    #define LBAL_LIBCPP20_BITOPS __cpp_lib_bitops
  #endif
#endif  //  LBAL_LIBCPP20_BITOPS

#if !defined(LBAL_LIBCPP20_BIT_CAST)
  #if __cpp_lib_bit_cast >= 201806L
    #define LBAL_LIBCPP20_BIT_CAST __cpp_lib_bit_cast
  #endif
#endif  //  LBAL_LIBCPP20_BIT_CAST

#if !defined(LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS)
  #if __cpp_lib_bounded_array_traits >= 201902L
    #define LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS __cpp_lib_bounded_array_traits
  #endif
#endif  //  LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS

#if !defined(LBAL_LIBCPP20_CHAR8_T)
  #if __cpp_lib_char8_t >= 201811L
    #define LBAL_LIBCPP20_CHAR8_T __cpp_lib_char8_t
  #endif
#endif  //  LBAL_LIBCPP20_CHAR8_T

#if !defined(LBAL_LIBCPP20_CHAR8_T_COMPAT)
  #if __cpp_lib_char8_t >= 201907L
    #define LBAL_LIBCPP20_CHAR8_T_COMPAT __cpp_lib_char8_t
  #endif
#endif  //  LBAL_LIBCPP20_CHAR8_T_COMPAT

#if !defined(LBAL_LIBCPP20_CHRONO_CALENDAR)
  #if __cpp_lib_chrono >= 201803L
    #define LBAL_LIBCPP20_CHRONO_CALENDAR __cpp_lib_chrono
  #endif
#endif  //  LBAL_LIBCPP20_CHRONO_CALENDAR

#if !defined(LBAL_LIBCPP20_CHRONO_FIXES)
  #if __cpp_lib_chrono >= 201907L
    #define LBAL_LIBCPP20_CHRONO_FIXES __cpp_lib_chrono
  #endif
#endif  //  LBAL_LIBCPP20_CHRONO_FIXES

#if !defined(LBAL_LIBCPP20_CONCEPTS)
  #if __cpp_lib_concepts >= 201806L
    #define LBAL_LIBCPP20_CONCEPTS __cpp_lib_concepts
  #endif
#endif  //  LBAL_LIBCPP20_CONCEPTS

#if !defined(LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE)
  #if __cpp_lib_concepts >= 202002L
    #define LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE __cpp_lib_concepts
  #endif
#endif  //  LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE

#if !defined(LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE)
  #if __cpp_lib_concepts >= 201907L
    #define LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE __cpp_lib_concepts
  #endif
#endif  //  LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE

#if !defined(LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS)
  #if __cpp_lib_constexpr_algorithms >= 201703L
    #define LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS __cpp_lib_constexpr_algorithms
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS

#if !defined(LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP)
  #if __cpp_lib_constexpr_algorithms >= 201806L
    #define LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP                            \
      __cpp_lib_constexpr_algorithms
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP

#if !defined(LBAL_LIBCPP20_CONSTEXPR_COMPLEX)
  #if __cpp_lib_constexpr_complex >= 201711L
    #define LBAL_LIBCPP20_CONSTEXPR_COMPLEX __cpp_lib_constexpr_complex
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_COMPLEX

#if !defined(LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC)
  #if __cpp_lib_constexpr_dynamic_alloc >= 201907L
    #define LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC                              \
      __cpp_lib_constexpr_dynamic_alloc
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC

#if !defined(LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL)
  #if __cpp_lib_constexpr_functional >= 201811L
    #define LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL __cpp_lib_constexpr_functional
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL

#if !defined(LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE)
  #if __cpp_lib_constexpr_functional >= 201907L
    #define LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE                          \
      __cpp_lib_constexpr_functional
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE

#if !defined(LBAL_LIBCPP20_CONSTEXPR_ITERATOR)
  #if __cpp_lib_constexpr_iterator >= 201811L
    #define LBAL_LIBCPP20_CONSTEXPR_ITERATOR __cpp_lib_constexpr_iterator
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_ITERATOR

#if !defined(LBAL_LIBCPP20_CONSTEXPR_MEMORY)
  #if __cpp_lib_constexpr_memory >= 201811L
    #define LBAL_LIBCPP20_CONSTEXPR_MEMORY __cpp_lib_constexpr_memory
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_MEMORY

#if !defined(LBAL_LIBCPP20_CONSTEXPR_NUMERIC)
  #if __cpp_lib_constexpr_numeric >= 201911L
    #define LBAL_LIBCPP20_CONSTEXPR_NUMERIC __cpp_lib_constexpr_numeric
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_NUMERIC

#if !defined(LBAL_LIBCPP20_CONSTEXPR_STRING)
  #if __cpp_lib_constexpr_string >= 201907L
    #define LBAL_LIBCPP20_CONSTEXPR_STRING __cpp_lib_constexpr_string
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_STRING

#if !defined(LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL)
  #if __cpp_lib_constexpr_string >= 201811L
    #define LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL __cpp_lib_constexpr_string
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL

#if !defined(LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW)
  #if __cpp_lib_constexpr_string_view >= 201811L
    #define LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW __cpp_lib_constexpr_string_view
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW

#if !defined(LBAL_LIBCPP20_CONSTEXPR_TUPLE)
  #if __cpp_lib_constexpr_tuple >= 201811L
    #define LBAL_LIBCPP20_CONSTEXPR_TUPLE __cpp_lib_constexpr_tuple
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_TUPLE

#if !defined(LBAL_LIBCPP20_CONSTEXPR_UTILITY)
  #if __cpp_lib_constexpr_utility >= 201811L
    #define LBAL_LIBCPP20_CONSTEXPR_UTILITY __cpp_lib_constexpr_utility
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_UTILITY

#if !defined(LBAL_LIBCPP20_CONSTEXPR_VECTOR)
  #if __cpp_lib_constexpr_vector >= 201907L
    #define LBAL_LIBCPP20_CONSTEXPR_VECTOR __cpp_lib_constexpr_vector
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_VECTOR

#if !defined(LBAL_LIBCPP20_COROUTINE)
  #if __cpp_lib_coroutine >= 201902L
    #define LBAL_LIBCPP20_COROUTINE __cpp_lib_coroutine
  #endif
#endif  //  LBAL_LIBCPP20_COROUTINE

#if !defined(LBAL_LIBCPP20_DESTROYING_DELETE)
  #if __cpp_lib_destroying_delete >= 201806L
    #define LBAL_LIBCPP20_DESTROYING_DELETE __cpp_lib_destroying_delete
  #endif
#endif  //  LBAL_LIBCPP20_DESTROYING_DELETE

#if !defined(LBAL_LIBCPP20_ENDIAN)
  #if __cpp_lib_endian >= 201907L
    #define LBAL_LIBCPP20_ENDIAN __cpp_lib_endian
  #endif
#endif  //  LBAL_LIBCPP20_ENDIAN

#if !defined(LBAL_LIBCPP20_ENDIAN_BIT)
  #if __cpp_lib_endian >= 201907L
    #define LBAL_LIBCPP20_ENDIAN_BIT __cpp_lib_endian
  #endif
#endif  //  LBAL_LIBCPP20_ENDIAN_BIT

#if !defined(LBAL_LIBCPP20_ERASE_IF)
  #if __cpp_lib_erase_if >= 201811L
    #define LBAL_LIBCPP20_ERASE_IF __cpp_lib_erase_if
  #endif
#endif  //  LBAL_LIBCPP20_ERASE_IF

#if !defined(LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS)
  #if __cpp_lib_erase_if >= 202002L
    #define LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS __cpp_lib_erase_if
  #endif
#endif  //  LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS

#if !defined(LBAL_LIBCPP20_EXECUTION_VECTORIZATION)
  #if __cpp_lib_execution >= 201902L
    #define LBAL_LIBCPP20_EXECUTION_VECTORIZATION __cpp_lib_execution
  #endif
#endif  //  LBAL_LIBCPP20_EXECUTION_VECTORIZATION

#if !defined(LBAL_LIBCPP20_FORMAT)
  #if __cpp_lib_format >= 201907L
    #define LBAL_LIBCPP20_FORMAT __cpp_lib_format
  #endif
#endif  //  LBAL_LIBCPP20_FORMAT

#if !defined(LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP)
  #if __cpp_lib_generic_unordered_lookup >= 201811L
    #define LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP                             \
      __cpp_lib_generic_unordered_lookup
  #endif
#endif  //  LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP

#if !defined(LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS)
  #if __cpp_lib_integer_comparison_functions >= 202002L
    #define LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS                         \
      __cpp_lib_integer_comparison_functions
  #endif
#endif  //  LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS

#if !defined(LBAL_LIBCPP20_INTERPOLATE)
  #if __cpp_lib_interpolate >= 201902L
    #define LBAL_LIBCPP20_INTERPOLATE __cpp_lib_interpolate
  #endif
#endif  //  LBAL_LIBCPP20_INTERPOLATE

#if !defined(LBAL_LIBCPP20_INT_POW2)
  #if __cpp_lib_int_pow2 >= 201806L
    #define LBAL_LIBCPP20_INT_POW2 __cpp_lib_int_pow2
  #endif
#endif  //  LBAL_LIBCPP20_INT_POW2

#if !defined(LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME)
  #if __cpp_lib_int_pow2 >= 202002L
    #define LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME __cpp_lib_int_pow2
  #endif
#endif  //  LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME

#if !defined(LBAL_LIBCPP20_IS_CONSTANT_EVALUATED)
  #if __cpp_lib_is_constant_evaluated >= 201811L
    #define LBAL_LIBCPP20_IS_CONSTANT_EVALUATED __cpp_lib_is_constant_evaluated
  #endif
#endif  //  LBAL_LIBCPP20_IS_CONSTANT_EVALUATED

#if !defined(LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE)
  #if __cpp_lib_is_layout_compatible >= 201907L
    #define LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE __cpp_lib_is_layout_compatible
  #endif
#endif  //  LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE

#if !defined(LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE)
  #if __cpp_lib_is_nothrow_convertible >= 201806L
    #define LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE                               \
      __cpp_lib_is_nothrow_convertible
  #endif
#endif  //  LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE

#if !defined(LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE)
  #if __cpp_lib_is_pointer_interconvertible >= 201907L
    #define LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE                          \
      __cpp_lib_is_pointer_interconvertible
  #endif
#endif  //  LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE

#if !defined(LBAL_LIBCPP20_JTHREAD)
  #if __cpp_lib_jthread >= 201907L
    #define LBAL_LIBCPP20_JTHREAD __cpp_lib_jthread
  #endif
#endif  //  LBAL_LIBCPP20_JTHREAD

#if !defined(LBAL_LIBCPP20_JTHREAD_CV)
  #if __cpp_lib_jthread >= 201911L
    #define LBAL_LIBCPP20_JTHREAD_CV __cpp_lib_jthread
  #endif
#endif  //  LBAL_LIBCPP20_JTHREAD_CV

#if !defined(LBAL_LIBCPP20_LATCH)
  #if __cpp_lib_latch >= 201907L
    #define LBAL_LIBCPP20_LATCH __cpp_lib_latch
  #endif
#endif  //  LBAL_LIBCPP20_LATCH

#if !defined(LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE)
  #if __cpp_lib_list_remove_return_type >= 201806L
    #define LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE                              \
      __cpp_lib_list_remove_return_type
  #endif
#endif  //  LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE

#if !defined(LBAL_LIBCPP20_MATH_CONSTANTS)
  #if __cpp_lib_math_constants >= 201907L
    #define LBAL_LIBCPP20_MATH_CONSTANTS __cpp_lib_math_constants
  #endif
#endif  //  LBAL_LIBCPP20_MATH_CONSTANTS

#if !defined(LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR)
  #if __cpp_lib_polymorphic_allocator >= 201902L
    #define LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR __cpp_lib_polymorphic_allocator
  #endif
#endif  //  LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR

#if !defined(LBAL_LIBCPP20_RANGES)
  #if __cpp_lib_ranges >= 201811L
    #define LBAL_LIBCPP20_RANGES __cpp_lib_ranges
  #endif
#endif  //  LBAL_LIBCPP20_RANGES

#if !defined(LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS)
  #if __cpp_lib_ranges >= 201907L
    #define LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS __cpp_lib_ranges
  #endif
#endif  //  LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS

#if !defined(LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE)
  #if __cpp_lib_ranges >= 201911L
    #define LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE __cpp_lib_ranges
  #endif
#endif  //  LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE

#if !defined(LBAL_LIBCPP20_REMOVE_CVREF)
  #if __cpp_lib_remove_cvref >= 201711L
    #define LBAL_LIBCPP20_REMOVE_CVREF __cpp_lib_remove_cvref
  #endif
#endif  //  LBAL_LIBCPP20_REMOVE_CVREF

#if !defined(LBAL_LIBCPP20_SEMAPHORE)
  #if __cpp_lib_semaphore >= 201907L
    #define LBAL_LIBCPP20_SEMAPHORE __cpp_lib_semaphore
  #endif
#endif  //  LBAL_LIBCPP20_SEMAPHORE

#if !defined(LBAL_LIBCPP20_SHARED_PTR_ARRAYS)
  #if __cpp_lib_shared_ptr_arrays >= 201707L
    #define LBAL_LIBCPP20_SHARED_PTR_ARRAYS __cpp_lib_shared_ptr_arrays
  #endif
#endif  //  LBAL_LIBCPP20_SHARED_PTR_ARRAYS

#if !defined(LBAL_LIBCPP20_SHIFT)
  #if __cpp_lib_shift >= 201806L
    #define LBAL_LIBCPP20_SHIFT __cpp_lib_shift
  #endif
#endif  //  LBAL_LIBCPP20_SHIFT

#if !defined(LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE)
  #if __cpp_lib_smart_ptr_for_overwrite >= 202002L
    #define LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE                              \
      __cpp_lib_smart_ptr_for_overwrite
  #endif
#endif  //  LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE

#if !defined(LBAL_LIBCPP20_SOURCE_LOCATION)
  #if __cpp_lib_source_location >= 201907L
    #define LBAL_LIBCPP20_SOURCE_LOCATION __cpp_lib_source_location
  #endif
#endif  //  LBAL_LIBCPP20_SOURCE_LOCATION

#if !defined(LBAL_LIBCPP20_SPAN)
  #if __cpp_lib_span >= 201803L
    #define LBAL_LIBCPP20_SPAN __cpp_lib_span
  #endif
#endif  //  LBAL_LIBCPP20_SPAN

#if !defined(LBAL_LIBCPP20_SPAN_FIXED_SIZE)
  #if __cpp_lib_span >= 202002L
    #define LBAL_LIBCPP20_SPAN_FIXED_SIZE __cpp_lib_span
  #endif
#endif  //  LBAL_LIBCPP20_SPAN_FIXED_SIZE

#if !defined(LBAL_LIBCPP20_SPAN_USABILITY)
  #if __cpp_lib_span >= 201902L
    #define LBAL_LIBCPP20_SPAN_USABILITY __cpp_lib_span
  #endif
#endif  //  LBAL_LIBCPP20_SPAN_USABILITY

#if !defined(LBAL_LIBCPP20_SSIZE)
  #if __cpp_lib_ssize >= 201902L
    #define LBAL_LIBCPP20_SSIZE __cpp_lib_ssize
  #endif
#endif  //  LBAL_LIBCPP20_SSIZE

#if !defined(LBAL_LIBCPP20_STARTS_ENDS_WITH)
  #if __cpp_lib_starts_ends_with >= 201711L
    #define LBAL_LIBCPP20_STARTS_ENDS_WITH __cpp_lib_starts_ends_with
  #endif
#endif  //  LBAL_LIBCPP20_STARTS_ENDS_WITH

#if !defined(LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR)
  #if __cpp_lib_string_view >= 201803L
    #define LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR __cpp_lib_string_view
  #endif
#endif  //  LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR

#if !defined(LBAL_LIBCPP20_SYNCBUF)
  #if __cpp_lib_syncbuf >= 201711L
    #define LBAL_LIBCPP20_SYNCBUF __cpp_lib_syncbuf
  #endif
#endif  //  LBAL_LIBCPP20_SYNCBUF

#if !defined(LBAL_LIBCPP20_SYNCBUF_MANIPULATORS)
  #if __cpp_lib_syncbuf >= 201803L
    #define LBAL_LIBCPP20_SYNCBUF_MANIPULATORS __cpp_lib_syncbuf
  #endif
#endif  //  LBAL_LIBCPP20_SYNCBUF_MANIPULATORS

#if !defined(LBAL_LIBCPP20_THREE_WAY_COMPARISON)
  #if __cpp_lib_three_way_comparison >= 201711L
    #define LBAL_LIBCPP20_THREE_WAY_COMPARISON __cpp_lib_three_way_comparison
  #endif
#endif  //  LBAL_LIBCPP20_THREE_WAY_COMPARISON

#if !defined(LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY)
  #if __cpp_lib_three_way_comparison >= 201907L
    #define LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY                         \
      __cpp_lib_three_way_comparison
  #endif
#endif  //  LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY

#if !defined(LBAL_LIBCPP20_TO_ADDRESS)
  #if __cpp_lib_to_address >= 201711L
    #define LBAL_LIBCPP20_TO_ADDRESS __cpp_lib_to_address
  #endif
#endif  //  LBAL_LIBCPP20_TO_ADDRESS

#if !defined(LBAL_LIBCPP20_TO_ARRAY)
  #if __cpp_lib_to_array >= 201907L
    #define LBAL_LIBCPP20_TO_ARRAY __cpp_lib_to_array
  #endif
#endif  //  LBAL_LIBCPP20_TO_ARRAY

#if !defined(LBAL_LIBCPP20_TYPE_IDENTITY)
  #if __cpp_lib_type_identity >= 201806L
    #define LBAL_LIBCPP20_TYPE_IDENTITY __cpp_lib_type_identity
  #endif
#endif  //  LBAL_LIBCPP20_TYPE_IDENTITY

#if !defined(LBAL_LIBCPP20_UNWRAP_REF)
  #if __cpp_lib_unwrap_ref >= 201811L
    #define LBAL_LIBCPP20_UNWRAP_REF __cpp_lib_unwrap_ref
  #endif
#endif  //  LBAL_LIBCPP20_UNWRAP_REF
