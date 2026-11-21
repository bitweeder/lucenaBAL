/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalLibrarySetup-header-tests-libcpp23.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if LBAL_LIBCPP23_ADAPTOR_ITERATOR_PAIR_CONSTRUCTOR
  #if LBAL_HAS_HEADER_QUEUE != 1 || LBAL_HAS_HEADER_STACK != 1
    #undef LBAL_LIBCPP23_ADAPTOR_ITERATOR_PAIR_CONSTRUCTOR
    #define LBAL_LIBCPP23_ADAPTOR_ITERATOR_PAIR_CONSTRUCTOR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_ADAPTOR_ITERATOR_PAIR_CONSTRUCTOR: at "
    "least one of {<queue>, <stack>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_ADAPTOR_ITERATOR_PAIR_CONSTRUCTOR

#if LBAL_LIBCPP23_ALGORITHM_ITERATOR_REQUIREMENTS
  #if LBAL_HAS_HEADER_ALGORITHM != 1                                           \
      || LBAL_HAS_HEADER_MEMORY != 1                                           \
      || LBAL_HAS_HEADER_NUMERIC != 1
    #undef LBAL_LIBCPP23_ALGORITHM_ITERATOR_REQUIREMENTS
    #define LBAL_LIBCPP23_ALGORITHM_ITERATOR_REQUIREMENTS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_ALGORITHM_ITERATOR_REQUIREMENTS: at "
    "least one of {<algorithm>, <memory>, <numeric>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_ALGORITHM_ITERATOR_REQUIREMENTS

#if LBAL_LIBCPP23_ALLOCATE_AT_LEAST
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP23_ALLOCATE_AT_LEAST
    #define LBAL_LIBCPP23_ALLOCATE_AT_LEAST 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_ALLOCATE_AT_LEAST: <memory> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_ALLOCATE_AT_LEAST

#if LBAL_LIBCPP23_ALLOCATE_AT_LEAST_DISALLOW_USER_SPEC
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP23_ALLOCATE_AT_LEAST_DISALLOW_USER_SPEC
    #define LBAL_LIBCPP23_ALLOCATE_AT_LEAST_DISALLOW_USER_SPEC 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_ALLOCATE_AT_LEAST_DISALLOW_USER_SPEC: "
    "<memory> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_ALLOCATE_AT_LEAST_DISALLOW_USER_SPEC

#if LBAL_LIBCPP23_ASSOCIATIVE_HETEROGENEOUS_ERASURE
  #if LBAL_HAS_HEADER_MAP != 1                                                 \
      || LBAL_HAS_HEADER_SET != 1                                              \
      || LBAL_HAS_HEADER_UNORDERED_MAP != 1                                    \
      || LBAL_HAS_HEADER_UNORDERED_SET != 1
    #undef LBAL_LIBCPP23_ASSOCIATIVE_HETEROGENEOUS_ERASURE
    #define LBAL_LIBCPP23_ASSOCIATIVE_HETEROGENEOUS_ERASURE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_ASSOCIATIVE_HETEROGENEOUS_ERASURE: at "
    "least one of {<map>, <set>, <unordered_map>, <unordered_set>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_ASSOCIATIVE_HETEROGENEOUS_ERASURE

#if LBAL_LIBCPP23_BARRIER_RELAXED_COMPLETION
  #if LBAL_HAS_HEADER_BARRIER != 1
    #undef LBAL_LIBCPP23_BARRIER_RELAXED_COMPLETION
    #define LBAL_LIBCPP23_BARRIER_RELAXED_COMPLETION 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_BARRIER_RELAXED_COMPLETION: <barrier> "
    "not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_BARRIER_RELAXED_COMPLETION

#if LBAL_LIBCPP23_BIND_BACK
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1
    #undef LBAL_LIBCPP23_BIND_BACK
    #define LBAL_LIBCPP23_BIND_BACK 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_BIND_BACK: <functional> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_BIND_BACK

#if LBAL_LIBCPP23_BYTESWAP
  #if LBAL_HAS_HEADER_BIT != 1
    #undef LBAL_LIBCPP23_BYTESWAP
    #define LBAL_LIBCPP23_BYTESWAP 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP23_BYTESWAP: <bit> not found")
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_BYTESWAP

#if LBAL_LIBCPP23_COMMON_REFERENCE
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP23_COMMON_REFERENCE
    #define LBAL_LIBCPP23_COMMON_REFERENCE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_COMMON_REFERENCE: <type_traits> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_COMMON_REFERENCE

#if LBAL_LIBCPP23_COMMON_REFERENCE_WRAPPER
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1
    #undef LBAL_LIBCPP23_COMMON_REFERENCE_WRAPPER
    #define LBAL_LIBCPP23_COMMON_REFERENCE_WRAPPER 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_COMMON_REFERENCE_WRAPPER: <functional> "
    "not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_COMMON_REFERENCE_WRAPPER

#if LBAL_LIBCPP23_CONCEPTS_MOVE_ONLY
  #if LBAL_HAS_HEADER_COMPARE != 1 || LBAL_HAS_HEADER_CONCEPTS != 1
    #undef LBAL_LIBCPP23_CONCEPTS_MOVE_ONLY
    #define LBAL_LIBCPP23_CONCEPTS_MOVE_ONLY 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_CONCEPTS_MOVE_ONLY: at least one of "
    "{<compare>, <concepts>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_CONCEPTS_MOVE_ONLY

#if LBAL_LIBCPP23_CONSTEXPR_BITSET
  #if LBAL_HAS_HEADER_BITSET != 1
    #undef LBAL_LIBCPP23_CONSTEXPR_BITSET
    #define LBAL_LIBCPP23_CONSTEXPR_BITSET 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_CONSTEXPR_BITSET: <bitset> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_CONSTEXPR_BITSET

#if LBAL_LIBCPP23_CONSTEXPR_CHARCONV
  #if LBAL_HAS_HEADER_CHARCONV != 1
    #undef LBAL_LIBCPP23_CONSTEXPR_CHARCONV
    #define LBAL_LIBCPP23_CONSTEXPR_CHARCONV 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_CONSTEXPR_CHARCONV: <charconv> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_CONSTEXPR_CHARCONV

#if LBAL_LIBCPP23_CONSTEXPR_CMATH
  #if LBAL_HAS_HEADER_CMATH != 1 || LBAL_HAS_HEADER_CSTDLIB != 1
    #undef LBAL_LIBCPP23_CONSTEXPR_CMATH
    #define LBAL_LIBCPP23_CONSTEXPR_CMATH 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_CONSTEXPR_CMATH: at least one of "
    "{<cmath>, <cstdlib>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_CONSTEXPR_CMATH

#if LBAL_LIBCPP23_CONSTEXPR_MEMORY_UNIQUE_PTR
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP23_CONSTEXPR_MEMORY_UNIQUE_PTR
    #define LBAL_LIBCPP23_CONSTEXPR_MEMORY_UNIQUE_PTR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_CONSTEXPR_MEMORY_UNIQUE_PTR: <memory> "
    "not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_CONSTEXPR_MEMORY_UNIQUE_PTR

#if LBAL_LIBCPP23_CONSTEXPR_TYPEINFO
  #if LBAL_HAS_HEADER_TYPEINFO != 1
    #undef LBAL_LIBCPP23_CONSTEXPR_TYPEINFO
    #define LBAL_LIBCPP23_CONSTEXPR_TYPEINFO 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_CONSTEXPR_TYPEINFO: <typeinfo> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_CONSTEXPR_TYPEINFO

#if LBAL_LIBCPP23_CONTAINERS_RANGES
  #if LBAL_HAS_HEADER_DEQUE != 1                                               \
      || LBAL_HAS_HEADER_FORWARD_LIST != 1                                     \
      || LBAL_HAS_HEADER_LIST != 1                                             \
      || LBAL_HAS_HEADER_MAP != 1                                              \
      || LBAL_HAS_HEADER_QUEUE != 1                                            \
      || LBAL_HAS_HEADER_SET != 1                                              \
      || LBAL_HAS_HEADER_STACK != 1                                            \
      || LBAL_HAS_HEADER_STRING != 1                                           \
      || LBAL_HAS_HEADER_UNORDERED_MAP != 1                                    \
      || LBAL_HAS_HEADER_UNORDERED_SET != 1                                    \
      || LBAL_HAS_HEADER_VECTOR != 1
    #undef LBAL_LIBCPP23_CONTAINERS_RANGES
    #define LBAL_LIBCPP23_CONTAINERS_RANGES 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_CONTAINERS_RANGES: at least one of "
    "{<deque>, <forward_list>, <list>, <map>, <queue>, <set>, <stack>, "
    "<string>, <unordered_map>, <unordered_set>, <vector>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_CONTAINERS_RANGES

#if LBAL_LIBCPP23_EXPECTED
  #if LBAL_HAS_HEADER_EXPECTED != 1
    #undef LBAL_LIBCPP23_EXPECTED
    #define LBAL_LIBCPP23_EXPECTED 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_EXPECTED: <expected> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_EXPECTED

#if LBAL_LIBCPP23_EXPECTED_MONADIC
  #if LBAL_HAS_HEADER_EXPECTED != 1
    #undef LBAL_LIBCPP23_EXPECTED_MONADIC
    #define LBAL_LIBCPP23_EXPECTED_MONADIC 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_EXPECTED_MONADIC: <expected> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_EXPECTED_MONADIC

#if LBAL_LIBCPP23_FLAT_MAP
  #if LBAL_HAS_HEADER_FLAT_MAP != 1
    #undef LBAL_LIBCPP23_FLAT_MAP
    #define LBAL_LIBCPP23_FLAT_MAP 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_FLAT_MAP: <flat_map> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_FLAT_MAP

#if LBAL_LIBCPP23_FLAT_SET
  #if LBAL_HAS_HEADER_FLAT_SET != 1
    #undef LBAL_LIBCPP23_FLAT_SET
    #define LBAL_LIBCPP23_FLAT_SET 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_FLAT_SET: <flat_set> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_FLAT_SET

#if LBAL_LIBCPP23_FORMAT
  #if LBAL_HAS_HEADER_FORMAT != 1
    #undef LBAL_LIBCPP23_FORMAT
    #define LBAL_LIBCPP23_FORMAT 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP23_FORMAT: <format> not found")
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_FORMAT

#if LBAL_LIBCPP23_FORMATTERS
  #if LBAL_HAS_HEADER_STACKTRACE != 1 || LBAL_HAS_HEADER_THREAD != 1
    #undef LBAL_LIBCPP23_FORMATTERS
    #define LBAL_LIBCPP23_FORMATTERS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_FORMATTERS: at least one of "
    "{<stacktrace>, <thread>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_FORMATTERS

#if LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING
  #if LBAL_HAS_HEADER_FORMAT != 1
    #undef LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING
    #define LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING: <format> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING

#if LBAL_LIBCPP23_FORMAT_ENCODINGS
  #if LBAL_HAS_HEADER_FORMAT != 1
    #undef LBAL_LIBCPP23_FORMAT_ENCODINGS
    #define LBAL_LIBCPP23_FORMAT_ENCODINGS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_FORMAT_ENCODINGS: <format> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_FORMAT_ENCODINGS

#if LBAL_LIBCPP23_FORMAT_GENERATOR
  #if LBAL_HAS_HEADER_FORMAT != 1
    #undef LBAL_LIBCPP23_FORMAT_GENERATOR
    #define LBAL_LIBCPP23_FORMAT_GENERATOR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_FORMAT_GENERATOR: <format> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_FORMAT_GENERATOR

#if LBAL_LIBCPP23_FORMAT_LOCALE
  #if LBAL_HAS_HEADER_FORMAT != 1
    #undef LBAL_LIBCPP23_FORMAT_LOCALE
    #define LBAL_LIBCPP23_FORMAT_LOCALE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_FORMAT_LOCALE: <format> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_FORMAT_LOCALE

#if LBAL_LIBCPP23_FORMAT_RANGES
  #if LBAL_HAS_HEADER_FORMAT != 1
    #undef LBAL_LIBCPP23_FORMAT_RANGES
    #define LBAL_LIBCPP23_FORMAT_RANGES 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_FORMAT_RANGES: <format> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_FORMAT_RANGES

#if LBAL_LIBCPP23_FORWARD_LIKE
  #if LBAL_HAS_HEADER_UTILITY != 1
    #undef LBAL_LIBCPP23_FORWARD_LIKE
    #define LBAL_LIBCPP23_FORWARD_LIKE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_FORWARD_LIKE: <utility> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_FORWARD_LIKE

#if LBAL_LIBCPP23_GENERATOR
  #if LBAL_HAS_HEADER_GENERATOR != 1
    #undef LBAL_LIBCPP23_GENERATOR
    #define LBAL_LIBCPP23_GENERATOR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_GENERATOR: <generator> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_GENERATOR

#if LBAL_LIBCPP23_INVOKE_R
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1
    #undef LBAL_LIBCPP23_INVOKE_R
    #define LBAL_LIBCPP23_INVOKE_R 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_INVOKE_R: <functional> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_INVOKE_R

#if LBAL_LIBCPP23_IOS_NOREPLACE
  #if LBAL_HAS_HEADER_IOS != 1
    #undef LBAL_LIBCPP23_IOS_NOREPLACE
    #define LBAL_LIBCPP23_IOS_NOREPLACE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_IOS_NOREPLACE: <ios> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_IOS_NOREPLACE

#if LBAL_LIBCPP23_IS_IMPLICIT_LIFETIME
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP23_IS_IMPLICIT_LIFETIME
    #define LBAL_LIBCPP23_IS_IMPLICIT_LIFETIME 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_IS_IMPLICIT_LIFETIME: <type_traits> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_IS_IMPLICIT_LIFETIME

#if LBAL_LIBCPP23_IS_SCOPED_ENUM
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP23_IS_SCOPED_ENUM
    #define LBAL_LIBCPP23_IS_SCOPED_ENUM 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_IS_SCOPED_ENUM: <type_traits> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_IS_SCOPED_ENUM

#if LBAL_LIBCPP23_MDSPAN
  #if LBAL_HAS_HEADER_MDSPAN != 1
    #undef LBAL_LIBCPP23_MDSPAN
    #define LBAL_LIBCPP23_MDSPAN 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP23_MDSPAN: <mdspan> not found")
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_MDSPAN

#if LBAL_LIBCPP23_MONADIC_OPTIONAL
  #if LBAL_HAS_HEADER_OPTIONAL != 1
    #undef LBAL_LIBCPP23_MONADIC_OPTIONAL
    #define LBAL_LIBCPP23_MONADIC_OPTIONAL 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_MONADIC_OPTIONAL: <optional> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_MONADIC_OPTIONAL

#if LBAL_LIBCPP23_MOVE_ITERATOR_CONCEPT
  #if LBAL_HAS_HEADER_ITERATOR != 1
    #undef LBAL_LIBCPP23_MOVE_ITERATOR_CONCEPT
    #define LBAL_LIBCPP23_MOVE_ITERATOR_CONCEPT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_MOVE_ITERATOR_CONCEPT: <iterator> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_MOVE_ITERATOR_CONCEPT

#if LBAL_LIBCPP23_MOVE_ONLY_FUNCTION
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1
    #undef LBAL_LIBCPP23_MOVE_ONLY_FUNCTION
    #define LBAL_LIBCPP23_MOVE_ONLY_FUNCTION 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_MOVE_ONLY_FUNCTION: <functional> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_MOVE_ONLY_FUNCTION

#if LBAL_LIBCPP23_OPTIONAL_CONSTEXPR
  #if LBAL_HAS_HEADER_OPTIONAL != 1
    #undef LBAL_LIBCPP23_OPTIONAL_CONSTEXPR
    #define LBAL_LIBCPP23_OPTIONAL_CONSTEXPR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_OPTIONAL_CONSTEXPR: <optional> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_OPTIONAL_CONSTEXPR

#if LBAL_LIBCPP23_OPTIONAL_MONADIC
  #if LBAL_HAS_HEADER_OPTIONAL != 1
    #undef LBAL_LIBCPP23_OPTIONAL_MONADIC
    #define LBAL_LIBCPP23_OPTIONAL_MONADIC 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_OPTIONAL_MONADIC: <optional> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_OPTIONAL_MONADIC

#if LBAL_LIBCPP23_OUT_PTR
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP23_OUT_PTR
    #define LBAL_LIBCPP23_OUT_PTR 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP23_OUT_PTR: <memory> not found")
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_OUT_PTR

#if LBAL_LIBCPP23_PRINT
  #if LBAL_HAS_HEADER_OSTREAM != 1 || LBAL_HAS_HEADER_PRINT != 1
    #undef LBAL_LIBCPP23_PRINT
    #define LBAL_LIBCPP23_PRINT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_PRINT: at least one of {<ostream>, "
    "<print>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_PRINT

#if LBAL_LIBCPP23_RANGES_AS_CONST
  #if LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP23_RANGES_AS_CONST
    #define LBAL_LIBCPP23_RANGES_AS_CONST 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_AS_CONST: <ranges> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_AS_CONST

#if LBAL_LIBCPP23_RANGES_AS_RVALUE
  #if LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP23_RANGES_AS_RVALUE
    #define LBAL_LIBCPP23_RANGES_AS_RVALUE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_AS_RVALUE: <ranges> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_AS_RVALUE

#if LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT
  #if LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT
    #define LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT: <ranges> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT

#if LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT_EMPTY
  #if LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT_EMPTY
    #define LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT_EMPTY 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT_EMPTY: <ranges> "
    "not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT_EMPTY

#if LBAL_LIBCPP23_RANGES_CHUNK
  #if LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP23_RANGES_CHUNK
    #define LBAL_LIBCPP23_RANGES_CHUNK 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_CHUNK: <ranges> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_CHUNK

#if LBAL_LIBCPP23_RANGES_CHUNK_BY
  #if LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP23_RANGES_CHUNK_BY
    #define LBAL_LIBCPP23_RANGES_CHUNK_BY 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_CHUNK_BY: <ranges> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_CHUNK_BY

#if LBAL_LIBCPP23_RANGES_CONTAINS
  #if LBAL_HAS_HEADER_ALGORITHM != 1
    #undef LBAL_LIBCPP23_RANGES_CONTAINS
    #define LBAL_LIBCPP23_RANGES_CONTAINS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_CONTAINS: <algorithm> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_CONTAINS

#if LBAL_LIBCPP23_RANGES_ENUMERATE
  #if LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP23_RANGES_ENUMERATE
    #define LBAL_LIBCPP23_RANGES_ENUMERATE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_ENUMERATE: <ranges> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_ENUMERATE

#if LBAL_LIBCPP23_RANGES_FIND_LAST
  #if LBAL_HAS_HEADER_ALGORITHM != 1
    #undef LBAL_LIBCPP23_RANGES_FIND_LAST
    #define LBAL_LIBCPP23_RANGES_FIND_LAST 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_FIND_LAST: <algorithm> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_FIND_LAST

#if LBAL_LIBCPP23_RANGES_FOLD
  #if LBAL_HAS_HEADER_ALGORITHM != 1
    #undef LBAL_LIBCPP23_RANGES_FOLD
    #define LBAL_LIBCPP23_RANGES_FOLD 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_FOLD: <algorithm> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_FOLD

#if LBAL_LIBCPP23_RANGES_FORMALIZED_VIEW
  #if LBAL_HAS_HEADER_ALGORITHM != 1                                           \
      || LBAL_HAS_HEADER_FUNCTIONAL != 1                                       \
      || LBAL_HAS_HEADER_ITERATOR != 1                                         \
      || LBAL_HAS_HEADER_MEMORY != 1                                           \
      || LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP23_RANGES_FORMALIZED_VIEW
    #define LBAL_LIBCPP23_RANGES_FORMALIZED_VIEW 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_FORMALIZED_VIEW: at least one of "
    "{<algorithm>, <functional>, <iterator>, <memory>, <ranges>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_FORMALIZED_VIEW

#if LBAL_LIBCPP23_RANGES_IOTA
  #if LBAL_HAS_HEADER_NUMERIC != 1
    #undef LBAL_LIBCPP23_RANGES_IOTA
    #define LBAL_LIBCPP23_RANGES_IOTA 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_IOTA: <numeric> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_IOTA

#if LBAL_LIBCPP23_RANGES_JOIN_WITH
  #if LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP23_RANGES_JOIN_WITH
    #define LBAL_LIBCPP23_RANGES_JOIN_WITH 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_JOIN_WITH: <ranges> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_JOIN_WITH

#if LBAL_LIBCPP23_RANGES_NON_DEFAULT_CONSTRUCTIBLE
  #if LBAL_HAS_HEADER_ALGORITHM != 1                                           \
      || LBAL_HAS_HEADER_FUNCTIONAL != 1                                       \
      || LBAL_HAS_HEADER_ITERATOR != 1                                         \
      || LBAL_HAS_HEADER_MEMORY != 1                                           \
      || LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP23_RANGES_NON_DEFAULT_CONSTRUCTIBLE
    #define LBAL_LIBCPP23_RANGES_NON_DEFAULT_CONSTRUCTIBLE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_NON_DEFAULT_CONSTRUCTIBLE: at "
    "least one of {<algorithm>, <functional>, <iterator>, <memory>, <ranges>} "
    "not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_NON_DEFAULT_CONSTRUCTIBLE

#if LBAL_LIBCPP23_RANGES_RELAXED
  #if LBAL_HAS_HEADER_ALGORITHM != 1                                           \
      || LBAL_HAS_HEADER_FUNCTIONAL != 1                                       \
      || LBAL_HAS_HEADER_ITERATOR != 1                                         \
      || LBAL_HAS_HEADER_MEMORY != 1                                           \
      || LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP23_RANGES_RELAXED
    #define LBAL_LIBCPP23_RANGES_RELAXED 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_RELAXED: at least one of "
    "{<algorithm>, <functional>, <iterator>, <memory>, <ranges>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_RELAXED

#if LBAL_LIBCPP23_RANGES_REMOVE_POISON_PILLS
  #if LBAL_HAS_HEADER_ALGORITHM != 1                                           \
      || LBAL_HAS_HEADER_FUNCTIONAL != 1                                       \
      || LBAL_HAS_HEADER_ITERATOR != 1                                         \
      || LBAL_HAS_HEADER_MEMORY != 1                                           \
      || LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP23_RANGES_REMOVE_POISON_PILLS
    #define LBAL_LIBCPP23_RANGES_REMOVE_POISON_PILLS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_REMOVE_POISON_PILLS: at least one "
    "of {<algorithm>, <functional>, <iterator>, <memory>, <ranges>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_REMOVE_POISON_PILLS

#if LBAL_LIBCPP23_RANGES_REPEAT
  #if LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP23_RANGES_REPEAT
    #define LBAL_LIBCPP23_RANGES_REPEAT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_REPEAT: <ranges> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_REPEAT

#if LBAL_LIBCPP23_RANGES_SLIDE
  #if LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP23_RANGES_SLIDE
    #define LBAL_LIBCPP23_RANGES_SLIDE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_SLIDE: <ranges> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_SLIDE

#if LBAL_LIBCPP23_RANGES_STARTS_ENDS_WITH
  #if LBAL_HAS_HEADER_ALGORITHM != 1
    #undef LBAL_LIBCPP23_RANGES_STARTS_ENDS_WITH
    #define LBAL_LIBCPP23_RANGES_STARTS_ENDS_WITH 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_STARTS_ENDS_WITH: <algorithm> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_STARTS_ENDS_WITH

#if LBAL_LIBCPP23_RANGES_STRIDE
  #if LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP23_RANGES_STRIDE
    #define LBAL_LIBCPP23_RANGES_STRIDE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_STRIDE: <ranges> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_STRIDE

#if LBAL_LIBCPP23_RANGES_SUPPORT_MOVE_ONLY_TYPES
  #if LBAL_HAS_HEADER_ALGORITHM != 1                                           \
      || LBAL_HAS_HEADER_FUNCTIONAL != 1                                       \
      || LBAL_HAS_HEADER_ITERATOR != 1                                         \
      || LBAL_HAS_HEADER_MEMORY != 1                                           \
      || LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP23_RANGES_SUPPORT_MOVE_ONLY_TYPES
    #define LBAL_LIBCPP23_RANGES_SUPPORT_MOVE_ONLY_TYPES 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_SUPPORT_MOVE_ONLY_TYPES: at least "
    "one of {<algorithm>, <functional>, <iterator>, <memory>, <ranges>} not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_SUPPORT_MOVE_ONLY_TYPES

#if LBAL_LIBCPP23_RANGES_TO_CONTAINER
  #if LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP23_RANGES_TO_CONTAINER
    #define LBAL_LIBCPP23_RANGES_TO_CONTAINER 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_TO_CONTAINER: <ranges> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_TO_CONTAINER

#if LBAL_LIBCPP23_RANGES_USER_ADAPTOR_PIPES
  #if LBAL_HAS_HEADER_ALGORITHM != 1                                           \
      || LBAL_HAS_HEADER_FUNCTIONAL != 1                                       \
      || LBAL_HAS_HEADER_ITERATOR != 1                                         \
      || LBAL_HAS_HEADER_MEMORY != 1                                           \
      || LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP23_RANGES_USER_ADAPTOR_PIPES
    #define LBAL_LIBCPP23_RANGES_USER_ADAPTOR_PIPES 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_USER_ADAPTOR_PIPES: at least one "
    "of {<algorithm>, <functional>, <iterator>, <memory>, <ranges>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_USER_ADAPTOR_PIPES

#if LBAL_LIBCPP23_RANGES_ZIP
  #if LBAL_HAS_HEADER_RANGES != 1                                              \
      || LBAL_HAS_HEADER_TUPLE != 1                                            \
      || LBAL_HAS_HEADER_UTILITY != 1
    #undef LBAL_LIBCPP23_RANGES_ZIP
    #define LBAL_LIBCPP23_RANGES_ZIP 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_RANGES_ZIP: at least one of {<ranges>, "
    "<tuple>, <utility>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_RANGES_ZIP

#if LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY
    #define LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY: <type_traits> "
    "not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY

#if LBAL_LIBCPP23_SHIFT_RANGES
  #if LBAL_HAS_HEADER_ALGORITHM != 1
    #undef LBAL_LIBCPP23_SHIFT_RANGES
    #define LBAL_LIBCPP23_SHIFT_RANGES 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_SHIFT_RANGES: <algorithm> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_SHIFT_RANGES

#if LBAL_LIBCPP23_SPANSTREAM
  #if LBAL_HAS_HEADER_IOSFWD != 1 || LBAL_HAS_HEADER_SPANSTREAM != 1
    #undef LBAL_LIBCPP23_SPANSTREAM
    #define LBAL_LIBCPP23_SPANSTREAM 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_SPANSTREAM: at least one of {<iosfwd>, "
    "<spanstream>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_SPANSTREAM

#if LBAL_LIBCPP23_STACKTRACE
  #if LBAL_HAS_HEADER_STACKTRACE != 1
    #undef LBAL_LIBCPP23_STACKTRACE
    #define LBAL_LIBCPP23_STACKTRACE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_STACKTRACE: <stacktrace> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_STACKTRACE

#if LBAL_LIBCPP23_START_LIFETIME_AS
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP23_START_LIFETIME_AS
    #define LBAL_LIBCPP23_START_LIFETIME_AS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_START_LIFETIME_AS: <memory> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_START_LIFETIME_AS

#if LBAL_LIBCPP23_STDATOMIC_H
  #if LBAL_HAS_HEADER_STDATOMIC_H != 1
    #undef LBAL_LIBCPP23_STDATOMIC_H
    #define LBAL_LIBCPP23_STDATOMIC_H 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_STDATOMIC_H: <stdatomic.h> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_STDATOMIC_H

#if LBAL_LIBCPP23_STRING_CONTAINS
  #if LBAL_HAS_HEADER_STRING != 1 || LBAL_HAS_HEADER_STRING_VIEW != 1
    #undef LBAL_LIBCPP23_STRING_CONTAINS
    #define LBAL_LIBCPP23_STRING_CONTAINS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_STRING_CONTAINS: at least one of "
    "{<string>, <string_view>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_STRING_CONTAINS

#if LBAL_LIBCPP23_STRING_RESIZE_AND_OVERWRITE
  #if LBAL_HAS_HEADER_STRING != 1
    #undef LBAL_LIBCPP23_STRING_RESIZE_AND_OVERWRITE
    #define LBAL_LIBCPP23_STRING_RESIZE_AND_OVERWRITE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_STRING_RESIZE_AND_OVERWRITE: <string> "
    "not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_STRING_RESIZE_AND_OVERWRITE

#if LBAL_LIBCPP23_TO_UNDERLYING
  #if LBAL_HAS_HEADER_UTILITY != 1
    #undef LBAL_LIBCPP23_TO_UNDERLYING
    #define LBAL_LIBCPP23_TO_UNDERLYING 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_TO_UNDERLYING: <utility> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_TO_UNDERLYING

#if LBAL_LIBCPP23_TUPLE_LIKE
  #if LBAL_HAS_HEADER_MAP != 1                                                 \
      || LBAL_HAS_HEADER_TUPLE != 1                                            \
      || LBAL_HAS_HEADER_UNORDERED_MAP != 1                                    \
      || LBAL_HAS_HEADER_UTILITY != 1
    #undef LBAL_LIBCPP23_TUPLE_LIKE
    #define LBAL_LIBCPP23_TUPLE_LIKE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_TUPLE_LIKE: at least one of {<map>, "
    "<tuple>, <unordered_map>, <utility>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_TUPLE_LIKE

#if LBAL_LIBCPP23_UNREACHABLE
  #if LBAL_HAS_HEADER_UTILITY != 1
    #undef LBAL_LIBCPP23_UNREACHABLE
    #define LBAL_LIBCPP23_UNREACHABLE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_UNREACHABLE: <utility> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_UNREACHABLE

#if LBAL_LIBCPP23_VARIANT_CONSTEXPR
  #if LBAL_HAS_HEADER_VARIANT != 1
    #undef LBAL_LIBCPP23_VARIANT_CONSTEXPR
    #define LBAL_LIBCPP23_VARIANT_CONSTEXPR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_VARIANT_CONSTEXPR: <variant> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_VARIANT_CONSTEXPR

#if LBAL_LIBCPP23_VARIANT_INHERITANCE
  #if LBAL_HAS_HEADER_VARIANT != 1
    #undef LBAL_LIBCPP23_VARIANT_INHERITANCE
    #define LBAL_LIBCPP23_VARIANT_INHERITANCE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_VARIANT_INHERITANCE: <variant> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP23_VARIANT_INHERITANCE
