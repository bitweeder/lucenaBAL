/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalLibrarySetup-header-tests-libcpp20.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS
  #if LBAL_HAS_HEADER_ARRAY != 1 || LBAL_HAS_HEADER_ITERATOR != 1
    #undef LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS
    #define LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS: at least "
    "one of {<array>, <iterator>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS

#if LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR
  #if LBAL_HAS_HEADER_ARRAY != 1 || LBAL_HAS_HEADER_ITERATOR != 1
    #undef LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR
    #define LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR: at least one "
    "of {<array>, <iterator>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR

#if LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES
  #if LBAL_HAS_HEADER_ARRAY != 1 || LBAL_HAS_HEADER_ITERATOR != 1
    #undef LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES
    #define LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES: at least one "
    "of {<array>, <iterator>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES

#if LBAL_LIBCPP20_ASSUME_ALIGNED
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP20_ASSUME_ALIGNED
    #define LBAL_LIBCPP20_ASSUME_ALIGNED 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ASSUME_ALIGNED: <memory> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_ASSUME_ALIGNED

#if LBAL_LIBCPP20_ATOMIC_FLAG_TEST
  #if LBAL_HAS_HEADER_ATOMIC != 1
    #undef LBAL_LIBCPP20_ATOMIC_FLAG_TEST
    #define LBAL_LIBCPP20_ATOMIC_FLAG_TEST 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ATOMIC_FLAG_TEST: <atomic> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_ATOMIC_FLAG_TEST

#if LBAL_LIBCPP20_ATOMIC_FLOAT
  #if LBAL_HAS_HEADER_ATOMIC != 1
    #undef LBAL_LIBCPP20_ATOMIC_FLOAT
    #define LBAL_LIBCPP20_ATOMIC_FLOAT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ATOMIC_FLOAT: <atomic> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_ATOMIC_FLOAT

#if LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES
  #if LBAL_HAS_HEADER_ATOMIC != 1
    #undef LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES
    #define LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES: <atomic> "
    "not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES

#if LBAL_LIBCPP20_ATOMIC_REF
  #if LBAL_HAS_HEADER_ATOMIC != 1
    #undef LBAL_LIBCPP20_ATOMIC_REF
    #define LBAL_LIBCPP20_ATOMIC_REF 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ATOMIC_REF: <atomic> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_ATOMIC_REF

#if LBAL_LIBCPP20_ATOMIC_SHARED_PTR
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP20_ATOMIC_SHARED_PTR
    #define LBAL_LIBCPP20_ATOMIC_SHARED_PTR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ATOMIC_SHARED_PTR: <memory> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_ATOMIC_SHARED_PTR

#if LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION
  #if LBAL_HAS_HEADER_ATOMIC != 1 || LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION
    #define LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION: at least "
    "one of {<atomic>, <memory>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION

#if LBAL_LIBCPP20_ATOMIC_WAIT
  #if LBAL_HAS_HEADER_ATOMIC != 1
    #undef LBAL_LIBCPP20_ATOMIC_WAIT
    #define LBAL_LIBCPP20_ATOMIC_WAIT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ATOMIC_WAIT: <atomic> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_ATOMIC_WAIT

#if LBAL_LIBCPP20_BARRIER
  #if LBAL_HAS_HEADER_BARRIER != 1
    #undef LBAL_LIBCPP20_BARRIER
    #define LBAL_LIBCPP20_BARRIER 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_BARRIER: <barrier> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_BARRIER

#if LBAL_LIBCPP20_BIND_FRONT
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1
    #undef LBAL_LIBCPP20_BIND_FRONT
    #define LBAL_LIBCPP20_BIND_FRONT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_BIND_FRONT: <functional> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_BIND_FRONT

#if LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1
    #undef LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP
    #define LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP: <functional> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP

#if LBAL_LIBCPP20_BITOPS
  #if LBAL_HAS_HEADER_BIT != 1
    #undef LBAL_LIBCPP20_BITOPS
    #define LBAL_LIBCPP20_BITOPS 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP20_BITOPS: <bit> not found")
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_BITOPS

#if LBAL_LIBCPP20_BIT_CAST
  #if LBAL_HAS_HEADER_BIT != 1
    #undef LBAL_LIBCPP20_BIT_CAST
    #define LBAL_LIBCPP20_BIT_CAST 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP20_BIT_CAST: <bit> not found")
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_BIT_CAST

#if LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS
    #define LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS: <type_traits> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS

#if LBAL_LIBCPP20_CHAR8_T
  #if LBAL_HAS_HEADER_ATOMIC != 1                                              \
      || LBAL_HAS_HEADER_FILESYSTEM != 1                                       \
      || LBAL_HAS_HEADER_IOSFWD != 1                                           \
      || LBAL_HAS_HEADER_ISTREAM != 1                                          \
      || LBAL_HAS_HEADER_LIMITS != 1                                           \
      || LBAL_HAS_HEADER_LOCALE != 1                                           \
      || LBAL_HAS_HEADER_OSTREAM != 1                                          \
      || LBAL_HAS_HEADER_STRING != 1                                           \
      || LBAL_HAS_HEADER_STRING_VIEW != 1
    #undef LBAL_LIBCPP20_CHAR8_T
    #define LBAL_LIBCPP20_CHAR8_T 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CHAR8_T: at least one of {<atomic>, "
    "<filesystem>, <iosfwd>, <istream>, <limits>, <locale>, <ostream>, "
    "<string>, <string_view>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_CHAR8_T

#if LBAL_LIBCPP20_CHAR8_T_COMPAT
  #if LBAL_HAS_HEADER_ATOMIC != 1                                              \
      || LBAL_HAS_HEADER_FILESYSTEM != 1                                       \
      || LBAL_HAS_HEADER_IOSFWD != 1                                           \
      || LBAL_HAS_HEADER_ISTREAM != 1                                          \
      || LBAL_HAS_HEADER_LIMITS != 1                                           \
      || LBAL_HAS_HEADER_LOCALE != 1                                           \
      || LBAL_HAS_HEADER_OSTREAM != 1                                          \
      || LBAL_HAS_HEADER_STRING != 1                                           \
      || LBAL_HAS_HEADER_STRING_VIEW != 1
    #undef LBAL_LIBCPP20_CHAR8_T_COMPAT
    #define LBAL_LIBCPP20_CHAR8_T_COMPAT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CHAR8_T_COMPAT: at least one of "
    "{<atomic>, <filesystem>, <iosfwd>, <istream>, <limits>, <locale>, "
    "<ostream>, <string>, <string_view>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_CHAR8_T_COMPAT

#if LBAL_LIBCPP20_CHRONO_CALENDAR
  #if LBAL_HAS_HEADER_CHRONO != 1
    #undef LBAL_LIBCPP20_CHRONO_CALENDAR
    #define LBAL_LIBCPP20_CHRONO_CALENDAR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CHRONO_CALENDAR: <chrono> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_CHRONO_CALENDAR

#if LBAL_LIBCPP20_CHRONO_FIXES
  #if LBAL_HAS_HEADER_CHRONO != 1
    #undef LBAL_LIBCPP20_CHRONO_FIXES
    #define LBAL_LIBCPP20_CHRONO_FIXES 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CHRONO_FIXES: <chrono> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_CHRONO_FIXES

#if LBAL_LIBCPP20_CONCEPTS
  #if LBAL_HAS_HEADER_COMPARE != 1 || LBAL_HAS_HEADER_CONCEPTS != 1
    #undef LBAL_LIBCPP20_CONCEPTS
    #define LBAL_LIBCPP20_CONCEPTS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONCEPTS: at least one of {<compare>, "
    "<concepts>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_CONCEPTS

#if LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE
  #if LBAL_HAS_HEADER_COMPARE != 1 || LBAL_HAS_HEADER_CONCEPTS != 1
    #undef LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE
    #define LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE: at least one "
    "of {<compare>, <concepts>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE

#if LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE
  #if LBAL_HAS_HEADER_COMPARE != 1 || LBAL_HAS_HEADER_CONCEPTS != 1
    #undef LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE
    #define LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE: at least one of "
    "{<compare>, <concepts>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE

#if LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS
  #if LBAL_HAS_HEADER_ALGORITHM != 1 || LBAL_HAS_HEADER_UTILITY != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS
    #define LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS: at least one of "
    "{<algorithm>, <utility>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS

#if LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP
  #if LBAL_HAS_HEADER_ALGORITHM != 1 || LBAL_HAS_HEADER_UTILITY != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP
    #define LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP: at least one "
    "of {<algorithm>, <utility>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP

#if LBAL_LIBCPP20_CONSTEXPR_COMPLEX
  #if LBAL_HAS_HEADER_COMPLEX != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_COMPLEX
    #define LBAL_LIBCPP20_CONSTEXPR_COMPLEX 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_COMPLEX: <complex> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_CONSTEXPR_COMPLEX

#if LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC
    #define LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC: <memory> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC

#if LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL
    #define LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL: <functional> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL

#if LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE
    #define LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE: "
    "<functional> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE

#if LBAL_LIBCPP20_CONSTEXPR_ITERATOR
  #if LBAL_HAS_HEADER_ITERATOR != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_ITERATOR
    #define LBAL_LIBCPP20_CONSTEXPR_ITERATOR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_ITERATOR: <iterator> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_CONSTEXPR_ITERATOR

#if LBAL_LIBCPP20_CONSTEXPR_MEMORY
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_MEMORY
    #define LBAL_LIBCPP20_CONSTEXPR_MEMORY 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_MEMORY: <memory> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_CONSTEXPR_MEMORY

#if LBAL_LIBCPP20_CONSTEXPR_NUMERIC
  #if LBAL_HAS_HEADER_NUMERIC != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_NUMERIC
    #define LBAL_LIBCPP20_CONSTEXPR_NUMERIC 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_NUMERIC: <numeric> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_CONSTEXPR_NUMERIC

#if LBAL_LIBCPP20_CONSTEXPR_STRING
  #if LBAL_HAS_HEADER_STRING != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_STRING
    #define LBAL_LIBCPP20_CONSTEXPR_STRING 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_STRING: <string> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_CONSTEXPR_STRING

#if LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL
  #if LBAL_HAS_HEADER_STRING != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL
    #define LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL: <string> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL

#if LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW
  #if LBAL_HAS_HEADER_STRING_VIEW != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW
    #define LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW: <string_view> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW

#if LBAL_LIBCPP20_CONSTEXPR_TUPLE
  #if LBAL_HAS_HEADER_TUPLE != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_TUPLE
    #define LBAL_LIBCPP20_CONSTEXPR_TUPLE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_TUPLE: <tuple> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_CONSTEXPR_TUPLE

#if LBAL_LIBCPP20_CONSTEXPR_UTILITY
  #if LBAL_HAS_HEADER_UTILITY != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_UTILITY
    #define LBAL_LIBCPP20_CONSTEXPR_UTILITY 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_UTILITY: <utility> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_CONSTEXPR_UTILITY

#if LBAL_LIBCPP20_CONSTEXPR_VECTOR
  #if LBAL_HAS_HEADER_VECTOR != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_VECTOR
    #define LBAL_LIBCPP20_CONSTEXPR_VECTOR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_VECTOR: <vector> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_CONSTEXPR_VECTOR

#if LBAL_LIBCPP20_COROUTINE
  #if LBAL_HAS_HEADER_COROUTINE != 1
    #undef LBAL_LIBCPP20_COROUTINE
    #define LBAL_LIBCPP20_COROUTINE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_COROUTINE: <coroutine> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_COROUTINE

#if LBAL_LIBCPP20_DESTROYING_DELETE
  #if LBAL_HAS_HEADER_NEW != 1
    #undef LBAL_LIBCPP20_DESTROYING_DELETE
    #define LBAL_LIBCPP20_DESTROYING_DELETE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_DESTROYING_DELETE: <new> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_DESTROYING_DELETE

#if LBAL_LIBCPP20_ENDIAN
  #if LBAL_HAS_HEADER_BIT != 1
    #undef LBAL_LIBCPP20_ENDIAN
    #define LBAL_LIBCPP20_ENDIAN 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP20_ENDIAN: <bit> not found")
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_ENDIAN

#if LBAL_LIBCPP20_ENDIAN_BIT
  #if LBAL_HAS_HEADER_BIT != 1
    #undef LBAL_LIBCPP20_ENDIAN_BIT
    #define LBAL_LIBCPP20_ENDIAN_BIT 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP20_ENDIAN_BIT: <bit> not found")
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_ENDIAN_BIT

#if LBAL_LIBCPP20_ERASE_IF
  #if LBAL_HAS_HEADER_DEQUE != 1                                               \
      || LBAL_HAS_HEADER_FORWARD_LIST != 1                                     \
      || LBAL_HAS_HEADER_LIST != 1                                             \
      || LBAL_HAS_HEADER_MAP != 1                                              \
      || LBAL_HAS_HEADER_SET != 1                                              \
      || LBAL_HAS_HEADER_STRING != 1                                           \
      || LBAL_HAS_HEADER_UNORDERED_MAP != 1                                    \
      || LBAL_HAS_HEADER_UNORDERED_SET != 1                                    \
      || LBAL_HAS_HEADER_VECTOR != 1
    #undef LBAL_LIBCPP20_ERASE_IF
    #define LBAL_LIBCPP20_ERASE_IF 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ERASE_IF: at least one of {<deque>, "
    "<forward_list>, <list>, <map>, <set>, <string>, <unordered_map>, "
    "<unordered_set>, <vector>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_ERASE_IF

#if LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS
  #if LBAL_HAS_HEADER_DEQUE != 1                                               \
      || LBAL_HAS_HEADER_FORWARD_LIST != 1                                     \
      || LBAL_HAS_HEADER_LIST != 1                                             \
      || LBAL_HAS_HEADER_MAP != 1                                              \
      || LBAL_HAS_HEADER_SET != 1                                              \
      || LBAL_HAS_HEADER_STRING != 1                                           \
      || LBAL_HAS_HEADER_UNORDERED_MAP != 1                                    \
      || LBAL_HAS_HEADER_UNORDERED_SET != 1                                    \
      || LBAL_HAS_HEADER_VECTOR != 1
    #undef LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS
    #define LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS: at least one of "
    "{<deque>, <forward_list>, <list>, <map>, <set>, <string>, "
    "<unordered_map>, <unordered_set>, <vector>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS

#if LBAL_LIBCPP20_EXECUTION_VECTORIZATION
  #if LBAL_HAS_HEADER_EXECUTION != 1
    #undef LBAL_LIBCPP20_EXECUTION_VECTORIZATION
    #define LBAL_LIBCPP20_EXECUTION_VECTORIZATION 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_EXECUTION_VECTORIZATION: <execution> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_EXECUTION_VECTORIZATION

#if LBAL_LIBCPP20_FORMAT
  #if LBAL_HAS_HEADER_FORMAT != 1
    #undef LBAL_LIBCPP20_FORMAT
    #define LBAL_LIBCPP20_FORMAT 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP20_FORMAT: <format> not found")
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_FORMAT

#if LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP
  #if LBAL_HAS_HEADER_UNORDERED_MAP != 1 || LBAL_HAS_HEADER_UNORDERED_SET != 1
    #undef LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP
    #define LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP: at least one "
    "of {<unordered_map>, <unordered_set>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP

#if LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS
  #if LBAL_HAS_HEADER_UTILITY != 1
    #undef LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS
    #define LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS: <utility> "
    "not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS

#if LBAL_LIBCPP20_INTERPOLATE
  #if LBAL_HAS_HEADER_CMATH != 1 || LBAL_HAS_HEADER_NUMERIC != 1
    #undef LBAL_LIBCPP20_INTERPOLATE
    #define LBAL_LIBCPP20_INTERPOLATE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_INTERPOLATE: at least one of {<cmath>, "
    "<numeric>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_INTERPOLATE

#if LBAL_LIBCPP20_INT_POW2
  #if LBAL_HAS_HEADER_BIT != 1
    #undef LBAL_LIBCPP20_INT_POW2
    #define LBAL_LIBCPP20_INT_POW2 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP20_INT_POW2: <bit> not found")
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_INT_POW2

#if LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME
  #if LBAL_HAS_HEADER_BIT != 1
    #undef LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME
    #define LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME: <bit> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME

#if LBAL_LIBCPP20_IS_CONSTANT_EVALUATED
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP20_IS_CONSTANT_EVALUATED
    #define LBAL_LIBCPP20_IS_CONSTANT_EVALUATED 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_IS_CONSTANT_EVALUATED: <type_traits> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_IS_CONSTANT_EVALUATED

#if LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE
    #define LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE: <type_traits> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE

#if LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE
    #define LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE: <type_traits> "
    "not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE

#if LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE
    #define LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE: "
    "<type_traits> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE

#if LBAL_LIBCPP20_JTHREAD
  #if LBAL_HAS_HEADER_STOP_TOKEN != 1 || LBAL_HAS_HEADER_THREAD != 1
    #undef LBAL_LIBCPP20_JTHREAD
    #define LBAL_LIBCPP20_JTHREAD 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_JTHREAD: at least one of {<stop_token>, "
    "<thread>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_JTHREAD

#if LBAL_LIBCPP20_JTHREAD_CV
  #if LBAL_HAS_HEADER_STOP_TOKEN != 1 || LBAL_HAS_HEADER_THREAD != 1
    #undef LBAL_LIBCPP20_JTHREAD_CV
    #define LBAL_LIBCPP20_JTHREAD_CV 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_JTHREAD_CV: at least one of "
    "{<stop_token>, <thread>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_JTHREAD_CV

#if LBAL_LIBCPP20_LATCH
  #if LBAL_HAS_HEADER_LATCH != 1
    #undef LBAL_LIBCPP20_LATCH
    #define LBAL_LIBCPP20_LATCH 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP20_LATCH: <latch> not found")
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_LATCH

#if LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE
  #if LBAL_HAS_HEADER_FORWARD_LIST != 1 || LBAL_HAS_HEADER_LIST != 1
    #undef LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE
    #define LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE: at least one of "
    "{<forward_list>, <list>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE

#if LBAL_LIBCPP20_MATH_CONSTANTS
  #if LBAL_HAS_HEADER_NUMBERS != 1
    #undef LBAL_LIBCPP20_MATH_CONSTANTS
    #define LBAL_LIBCPP20_MATH_CONSTANTS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_MATH_CONSTANTS: <numbers> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_MATH_CONSTANTS

#if LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR
  #if LBAL_HAS_HEADER_MEMORY_RESOURCE != 1
    #undef LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR
    #define LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR: <memory_resource> "
    "not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR

#if LBAL_LIBCPP20_RANGES
  #if LBAL_HAS_HEADER_ALGORITHM != 1                                           \
      || LBAL_HAS_HEADER_FUNCTIONAL != 1                                       \
      || LBAL_HAS_HEADER_ITERATOR != 1                                         \
      || LBAL_HAS_HEADER_MEMORY != 1                                           \
      || LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP20_RANGES
    #define LBAL_LIBCPP20_RANGES 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_RANGES: at least one of {<algorithm>, "
    "<functional>, <iterator>, <memory>, <ranges>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_RANGES

#if LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS
  #if LBAL_HAS_HEADER_ALGORITHM != 1                                           \
      || LBAL_HAS_HEADER_FUNCTIONAL != 1                                       \
      || LBAL_HAS_HEADER_ITERATOR != 1                                         \
      || LBAL_HAS_HEADER_MEMORY != 1                                           \
      || LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS
    #define LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS: at least one of "
    "{<algorithm>, <functional>, <iterator>, <memory>, <ranges>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS

#if LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE
  #if LBAL_HAS_HEADER_ALGORITHM != 1                                           \
      || LBAL_HAS_HEADER_FUNCTIONAL != 1                                       \
      || LBAL_HAS_HEADER_ITERATOR != 1                                         \
      || LBAL_HAS_HEADER_MEMORY != 1                                           \
      || LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE
    #define LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE: at least one of "
    "{<algorithm>, <functional>, <iterator>, <memory>, <ranges>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE

#if LBAL_LIBCPP20_REMOVE_CVREF
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP20_REMOVE_CVREF
    #define LBAL_LIBCPP20_REMOVE_CVREF 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_REMOVE_CVREF: <type_traits> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_REMOVE_CVREF

#if LBAL_LIBCPP20_SEMAPHORE
  #if LBAL_HAS_HEADER_SEMAPHORE != 1
    #undef LBAL_LIBCPP20_SEMAPHORE
    #define LBAL_LIBCPP20_SEMAPHORE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_SEMAPHORE: <semaphore> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_SEMAPHORE

#if LBAL_LIBCPP20_SHARED_PTR_ARRAYS
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP20_SHARED_PTR_ARRAYS
    #define LBAL_LIBCPP20_SHARED_PTR_ARRAYS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_SHARED_PTR_ARRAYS: <memory> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_SHARED_PTR_ARRAYS

#if LBAL_LIBCPP20_SHIFT
  #if LBAL_HAS_HEADER_ALGORITHM != 1
    #undef LBAL_LIBCPP20_SHIFT
    #define LBAL_LIBCPP20_SHIFT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_SHIFT: <algorithm> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_SHIFT

#if LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE
    #define LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE: <memory> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE

#if LBAL_LIBCPP20_SOURCE_LOCATION
  #if LBAL_HAS_HEADER_SOURCE_LOCATION != 1
    #undef LBAL_LIBCPP20_SOURCE_LOCATION
    #define LBAL_LIBCPP20_SOURCE_LOCATION 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_SOURCE_LOCATION: <source_location> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_SOURCE_LOCATION

#if LBAL_LIBCPP20_SPAN
  #if LBAL_HAS_HEADER_SPAN != 1
    #undef LBAL_LIBCPP20_SPAN
    #define LBAL_LIBCPP20_SPAN 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP20_SPAN: <span> not found")
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_SPAN

#if LBAL_LIBCPP20_SPAN_FIXED_SIZE
  #if LBAL_HAS_HEADER_SPAN != 1
    #undef LBAL_LIBCPP20_SPAN_FIXED_SIZE
    #define LBAL_LIBCPP20_SPAN_FIXED_SIZE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_SPAN_FIXED_SIZE: <span> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_SPAN_FIXED_SIZE

#if LBAL_LIBCPP20_SPAN_USABILITY
  #if LBAL_HAS_HEADER_SPAN != 1
    #undef LBAL_LIBCPP20_SPAN_USABILITY
    #define LBAL_LIBCPP20_SPAN_USABILITY 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_SPAN_USABILITY: <span> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_SPAN_USABILITY

#if LBAL_LIBCPP20_SSIZE
  #if LBAL_HAS_HEADER_ITERATOR != 1
    #undef LBAL_LIBCPP20_SSIZE
    #define LBAL_LIBCPP20_SSIZE 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP20_SSIZE: <iterator> not found")
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_SSIZE

#if LBAL_LIBCPP20_STARTS_ENDS_WITH
  #if LBAL_HAS_HEADER_STRING != 1 || LBAL_HAS_HEADER_STRING_VIEW != 1
    #undef LBAL_LIBCPP20_STARTS_ENDS_WITH
    #define LBAL_LIBCPP20_STARTS_ENDS_WITH 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_STARTS_ENDS_WITH: at least one of "
    "{<string>, <string_view>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_STARTS_ENDS_WITH

#if LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR
  #if LBAL_HAS_HEADER_STRING != 1 || LBAL_HAS_HEADER_STRING_VIEW != 1
    #undef LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR
    #define LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR: at least "
    "one of {<string>, <string_view>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR

#if LBAL_LIBCPP20_SYNCBUF
  #if LBAL_HAS_HEADER_IOSFWD != 1 || LBAL_HAS_HEADER_SYNCSTREAM != 1
    #undef LBAL_LIBCPP20_SYNCBUF
    #define LBAL_LIBCPP20_SYNCBUF 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_SYNCBUF: at least one of {<iosfwd>, "
    "<syncstream>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_SYNCBUF

#if LBAL_LIBCPP20_SYNCBUF_MANIPULATORS
  #if LBAL_HAS_HEADER_IOSFWD != 1 || LBAL_HAS_HEADER_SYNCSTREAM != 1
    #undef LBAL_LIBCPP20_SYNCBUF_MANIPULATORS
    #define LBAL_LIBCPP20_SYNCBUF_MANIPULATORS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_SYNCBUF_MANIPULATORS: at least one of "
    "{<iosfwd>, <syncstream>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_SYNCBUF_MANIPULATORS

#if LBAL_LIBCPP20_THREE_WAY_COMPARISON
  #if LBAL_HAS_HEADER_COMPARE != 1
    #undef LBAL_LIBCPP20_THREE_WAY_COMPARISON
    #define LBAL_LIBCPP20_THREE_WAY_COMPARISON 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_THREE_WAY_COMPARISON: <compare> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_THREE_WAY_COMPARISON

#if LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY
  #if LBAL_HAS_HEADER_COMPARE != 1
    #undef LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY
    #define LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY: <compare> "
    "not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY

#if LBAL_LIBCPP20_TO_ADDRESS
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP20_TO_ADDRESS
    #define LBAL_LIBCPP20_TO_ADDRESS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_TO_ADDRESS: <memory> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_TO_ADDRESS

#if LBAL_LIBCPP20_TO_ARRAY
  #if LBAL_HAS_HEADER_ARRAY != 1
    #undef LBAL_LIBCPP20_TO_ARRAY
    #define LBAL_LIBCPP20_TO_ARRAY 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP20_TO_ARRAY: <array> not found")
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_TO_ARRAY

#if LBAL_LIBCPP20_TYPE_IDENTITY
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP20_TYPE_IDENTITY
    #define LBAL_LIBCPP20_TYPE_IDENTITY 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_TYPE_IDENTITY: <type_traits> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_TYPE_IDENTITY

#if LBAL_LIBCPP20_UNWRAP_REF
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP20_UNWRAP_REF
    #define LBAL_LIBCPP20_UNWRAP_REF 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_UNWRAP_REF: <type_traits> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP20_UNWRAP_REF
