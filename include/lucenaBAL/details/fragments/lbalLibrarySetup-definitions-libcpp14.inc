/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalLibrarySetup-definitions-libcpp14.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if !defined(LBAL_LIBCPP14_CHRONO_UDLS)
  #if __cpp_lib_chrono_udls >= 201304L
    #define LBAL_LIBCPP14_CHRONO_UDLS __cpp_lib_chrono_udls
  #endif
#endif  //  LBAL_LIBCPP14_CHRONO_UDLS

#if !defined(LBAL_LIBCPP14_COMPLEX_UDLS)
  #if __cpp_lib_complex_udls >= 201309L
    #define LBAL_LIBCPP14_COMPLEX_UDLS __cpp_lib_complex_udls
  #endif
#endif  //  LBAL_LIBCPP14_COMPLEX_UDLS

#if !defined(LBAL_LIBCPP14_EXCHANGE_FUNCTION)
  #if __cpp_lib_exchange_function >= 201304L
    #define LBAL_LIBCPP14_EXCHANGE_FUNCTION __cpp_lib_exchange_function
  #endif
#endif  //  LBAL_LIBCPP14_EXCHANGE_FUNCTION

#if !defined(LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP)
  #if __cpp_lib_generic_associative_lookup >= 201304L
    #define LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP                           \
      __cpp_lib_generic_associative_lookup
  #endif
#endif  //  LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP

#if !defined(LBAL_LIBCPP14_INTEGER_SEQUENCE)
  #if __cpp_lib_integer_sequence >= 201304L
    #define LBAL_LIBCPP14_INTEGER_SEQUENCE __cpp_lib_integer_sequence
  #endif
#endif  //  LBAL_LIBCPP14_INTEGER_SEQUENCE

#if !defined(LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE)
  #if __cpp_lib_integral_constant_callable >= 201304L
    #define LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE                           \
      __cpp_lib_integral_constant_callable
  #endif
#endif  //  LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE

#if !defined(LBAL_LIBCPP14_IS_FINAL)
  #if __cpp_lib_is_final >= 201402L
    #define LBAL_LIBCPP14_IS_FINAL __cpp_lib_is_final
  #endif
#endif  //  LBAL_LIBCPP14_IS_FINAL

#if !defined(LBAL_LIBCPP14_IS_NULL_POINTER)
  #if __cpp_lib_is_null_pointer >= 201309L
    #define LBAL_LIBCPP14_IS_NULL_POINTER __cpp_lib_is_null_pointer
  #endif
#endif  //  LBAL_LIBCPP14_IS_NULL_POINTER

#if !defined(LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR)
  #if __cpp_lib_make_reverse_iterator >= 201402L
    #define LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR __cpp_lib_make_reverse_iterator
  #endif
#endif  //  LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR

#if !defined(LBAL_LIBCPP14_MAKE_UNIQUE)
  #if __cpp_lib_make_unique >= 201304L
    #define LBAL_LIBCPP14_MAKE_UNIQUE __cpp_lib_make_unique
  #endif
#endif  //  LBAL_LIBCPP14_MAKE_UNIQUE

#if !defined(LBAL_LIBCPP14_NULL_ITERATORS)
  #if __cpp_lib_null_iterators >= 201304L
    #define LBAL_LIBCPP14_NULL_ITERATORS __cpp_lib_null_iterators
  #endif
#endif  //  LBAL_LIBCPP14_NULL_ITERATORS

#if !defined(LBAL_LIBCPP14_QUOTED_STRING_IO)
  #if __cpp_lib_quoted_string_io >= 201304L
    #define LBAL_LIBCPP14_QUOTED_STRING_IO __cpp_lib_quoted_string_io
  #endif
#endif  //  LBAL_LIBCPP14_QUOTED_STRING_IO

#if !defined(LBAL_LIBCPP14_RESULT_OF_SFINAE)
  #if __cpp_lib_result_of_sfinae >= 201210L
    #define LBAL_LIBCPP14_RESULT_OF_SFINAE __cpp_lib_result_of_sfinae
  #endif
#endif  //  LBAL_LIBCPP14_RESULT_OF_SFINAE

#if !defined(LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS)
  #if __cpp_lib_robust_nonmodifying_seq_ops >= 201304L
    #define LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS                          \
      __cpp_lib_robust_nonmodifying_seq_ops
  #endif
#endif  //  LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS

#if !defined(LBAL_LIBCPP14_SHARED_TIMED_MUTEX)
  #if __cpp_lib_shared_timed_mutex >= 201402L
    #define LBAL_LIBCPP14_SHARED_TIMED_MUTEX __cpp_lib_shared_timed_mutex
  #endif
#endif  //  LBAL_LIBCPP14_SHARED_TIMED_MUTEX

#if !defined(LBAL_LIBCPP14_STRING_UDLS)
  #if __cpp_lib_string_udls >= 201304L
    #define LBAL_LIBCPP14_STRING_UDLS __cpp_lib_string_udls
  #endif
#endif  //  LBAL_LIBCPP14_STRING_UDLS

#if !defined(LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES)
  #if __cpp_lib_transformation_trait_aliases >= 201304L
    #define LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES                         \
      __cpp_lib_transformation_trait_aliases
  #endif
#endif  //  LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES

#if !defined(LBAL_LIBCPP14_TRANSPARENT_OPERATORS)
  #if __cpp_lib_transparent_operators >= 201210L
    #define LBAL_LIBCPP14_TRANSPARENT_OPERATORS __cpp_lib_transparent_operators
  #endif
#endif  //  LBAL_LIBCPP14_TRANSPARENT_OPERATORS

#if !defined(LBAL_LIBCPP14_TUPLES_BY_TYPE)
  #if __cpp_lib_tuples_by_type >= 201304L
    #define LBAL_LIBCPP14_TUPLES_BY_TYPE __cpp_lib_tuples_by_type
  #endif
#endif  //  LBAL_LIBCPP14_TUPLES_BY_TYPE

#if !defined(LBAL_LIBCPP14_TUPLE_ELEMENT_T)
  #if __cpp_lib_tuple_element_t >= 201402L
    #define LBAL_LIBCPP14_TUPLE_ELEMENT_T __cpp_lib_tuple_element_t
  #endif
#endif  //  LBAL_LIBCPP14_TUPLE_ELEMENT_T
