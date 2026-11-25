/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFeatureSetup-overview-libcpp20.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

/**
  @addtogroup lbal_library
  @{
*/

/**
  @name LBAL_LIBCPP20

  @brief These are all taken from features that have been incorporated into
  the C++20 Standard.

  @{
*/

/**
  @def LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS
  @brief Provide `constexpr` comparison operators for `std::array`
  @details SD-6 equivalent: `__cpp_lib_array_constexpr >= 201806L`. Note that
  `__cpp_lib_array_constexpr` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201806L` [P1023R0 __PDF__](https://wg21.link/P1023R0) `constexpr`
  comparison operators for `std::array`

  @sa `<array>` `freestanding` `<iterator>`
*/
#ifndef LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS
  #define LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS 0
#endif

/**
  @def LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR
  @brief Define requirements for `constexpr` iterators
  @details SD-6 equivalent: `__cpp_lib_array_constexpr >= 201803L`. Note that
  `__cpp_lib_array_constexpr` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201803L` [LWG3257](https://wg21.link/LWG3257) Missing feature testing macro
  update from P0858
  - `201803L` [P0858R0](https://wg21.link/P0858R0) Constexpr iterator
  requirements

  @remark The issue raised in [LWG3257](https://wg21.link/LWG3257) was simply
  that the SD-6 macro update voted in with [201803L](https://wg21.link/P0858R0)
  had not been applied.

  @sa `<array>` `freestanding` `<iterator>`
*/
#ifndef LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR
  #define LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR 0
#endif

/**
  @def LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES
  @brief Provide `constexpr` `std::array` `swap` and `fill`
  @details SD-6 equivalent: `__cpp_lib_array_constexpr >= 201811L`. Note that
  `__cpp_lib_array_constexpr` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P1032R1](https://wg21.link/P1032R1) Misc constexpr bits

  @sa `<array>` `freestanding` `<iterator>`
*/
#ifndef LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES
  #define LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES 0
#endif

/**
  @def LBAL_LIBCPP20_ASSUME_ALIGNED
  @brief Provide `std::assume_aligned` compiler hint utility function Library
  @details SD-6 equivalent: `__cpp_lib_assume_aligned >= 201811L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201811L` [P1007R3 __PDF__](https://wg21.link/P1007R3) `std::assume_aligned`

  @sa `freestanding` `<memory>`
*/
#ifndef LBAL_LIBCPP20_ASSUME_ALIGNED
  #define LBAL_LIBCPP20_ASSUME_ALIGNED 0
#endif

/**
  @def LBAL_LIBCPP20_ATOMIC_FLAG_TEST
  @brief Add `atomic_flag::test` components of the C++20 Synchronization Library
  @details SD-6 equivalent: `__cpp_lib_atomic_flag_test >= 201907L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201907L` [P1135R6](https://wg21.link/P1135R6) The C++20 Synchronization
  Library

  @sa `<atomic>` `freestanding`
*/
#ifndef LBAL_LIBCPP20_ATOMIC_FLAG_TEST
  #define LBAL_LIBCPP20_ATOMIC_FLAG_TEST 0
#endif

/**
  @def LBAL_LIBCPP20_ATOMIC_FLOAT
  @brief Extend `<atomic>` support to floating point types
  @details SD-6 equivalent: `__cpp_lib_atomic_float >= 201711L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201711L` [P0020R6](https://wg21.link/P0020R6) Floating Point Atomic

  @sa `<atomic>` `freestanding`
*/
#ifndef LBAL_LIBCPP20_ATOMIC_FLOAT
  #define LBAL_LIBCPP20_ATOMIC_FLOAT 0
#endif

/**
  @def LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES
  @brief Add atomic lockfree type aliases from the C++20 Synchronization
  @details SD-6 equivalent: `__cpp_lib_atomic_lock_free_type_aliases >=
  201907L`. This token will have a value of `0` if the proposal described here
  is not supported.
  - `201907L` [P1135R6](https://wg21.link/P1135R6) The C++20 Synchronization
  Library

  @sa `<atomic>`
*/
#ifndef LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES
  #define LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES 0
#endif

/**
  @def LBAL_LIBCPP20_ATOMIC_REF
  @brief Allow atomic operations to apply to non-atomic objects
  @details SD-6 equivalent: `__cpp_lib_atomic_ref >= 201806L`. Note that
  `__cpp_lib_atomic_ref` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201806L` [P0019R8](https://wg21.link/P0019R8) Atomic Ref

  @sa `<atomic>` `freestanding`
*/
#ifndef LBAL_LIBCPP20_ATOMIC_REF
  #define LBAL_LIBCPP20_ATOMIC_REF 0
#endif

/**
  @def LBAL_LIBCPP20_ATOMIC_SHARED_PTR
  @brief Fixes for atomic `std::shared_ptr` and `std::weak_ptr`
  @details SD-6 equivalent: `__cpp_lib_atomic_shared_ptr >= 201711L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201711L` [P0718R2](https://wg21.link/P0718R2) Revising `atomic_shared_ptr`
  for C++20

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP20_ATOMIC_SHARED_PTR
  #define LBAL_LIBCPP20_ATOMIC_SHARED_PTR 0
#endif

/**
  @def LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION
  @brief Eliminate the surprising value-initialization behavior of `std::atomic`
  @details SD-6 equivalent: `__cpp_lib_atomic_value_initialization >= 201911L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201911L` [P0883R2 __PDF__](https://wg21.link/P0883R2) Fixing Atomic
  Initialization

  @sa `<atomic>` `freestanding` `<memory>`
*/
#ifndef LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION
  #define LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION 0
#endif

/**
  @def LBAL_LIBCPP20_ATOMIC_WAIT
  @brief Add atomic wait components of the C++20 Synchronization Library
  @details SD-6 equivalent: `__cpp_lib_atomic_wait >= 201907L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201907L` [P1135R6](https://wg21.link/P1135R6) The C++20 Synchronization
  Library

  @sa `<atomic>` `freestanding`
*/
#ifndef LBAL_LIBCPP20_ATOMIC_WAIT
  #define LBAL_LIBCPP20_ATOMIC_WAIT 0
#endif

/**
  @def LBAL_LIBCPP20_BARRIER
  @brief Add `std::barrier` components of the C++20 Synchronization Library
  @details SD-6 equivalent: `__cpp_lib_barrier >= 201907L`. Note that
  `__cpp_lib_barrier` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P1135R6](https://wg21.link/P1135R6) The C++20 Synchronization
  Library

  @sa `<barrier>`
*/
#ifndef LBAL_LIBCPP20_BARRIER
  #define LBAL_LIBCPP20_BARRIER 0
#endif

/**
  @def LBAL_LIBCPP20_BIND_FRONT
  @brief Introduce `std::bind_front` to supersede `std::bind`
  @details SD-6 equivalent: `__cpp_lib_bind_front >= 201811L`. Note that
  `__cpp_lib_bind_front` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P0356R5](https://wg21.link/P0356R5) Simplified partial function
  application

  @sa `freestanding` `<functional>`
*/
#ifndef LBAL_LIBCPP20_BIND_FRONT
  #define LBAL_LIBCPP20_BIND_FRONT 0
#endif

/**
  @def LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP
  @brief Prevent `std::bind_front` from unwrapping `std::reference_wrapper`
  @details SD-6 equivalent: `__cpp_lib_bind_front >= 201907L`. Note that
  `__cpp_lib_bind_front` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P1651R0](https://wg21.link/P1651R0) `bind_front` should not
  unwrap `reference_wrapper`

  @sa `freestanding` `<functional>`
*/
#ifndef LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP
  #define LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP 0
#endif

/**
  @def LBAL_LIBCPP20_BITOPS
  @brief Introduce support for hardware-level bit operations
  @details SD-6 equivalent: `__cpp_lib_bitops >= 201907L`. Note that
  `__cpp_lib_bitops` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P0553R4](https://wg21.link/P0553R4) Bit operations

  @sa `<bit>` `freestanding`
*/
#ifndef LBAL_LIBCPP20_BITOPS
  #define LBAL_LIBCPP20_BITOPS 0
#endif

/**
  @def LBAL_LIBCPP20_BIT_CAST
  @brief Introduce robust casts between bit-compatible types
  @details SD-6 equivalent: `__cpp_lib_bit_cast >= 201806L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201806L` [P0476R2](https://wg21.link/P0476R2) Bit-casting object
  representations

  @sa `<bit>` `freestanding`
*/
#ifndef LBAL_LIBCPP20_BIT_CAST
  #define LBAL_LIBCPP20_BIT_CAST 0
#endif

/**
  @def LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS
  @brief Introduce traits to distinguish between bounded and unbounded arrays
  @details SD-6 equivalent: `__cpp_lib_bounded_array_traits >= 201902L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201902L` [P1357R1 __PDF__](https://wg21.link/P1357R1) Traits for
  [Un]bounded Arrays

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS
  #define LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS 0
#endif

/**
  @def LBAL_LIBCPP20_CHAR8_T
  @brief Define `char8_t` as the base type for UTF-8 encodings (Rev 6)
  @details SD-6 equivalent: `__cpp_lib_char8_t >= 201811L`. Note that
  `__cpp_lib_char8_t` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P0482R6](https://wg21.link/P0482R6) char8_t: A type for UTF-8
  characters and strings (Revision 6)

  @sa `<atomic>` `<filesystem>` `freestanding` `<iosfwd>` `<istream>` `<limits>`
  `<locale>` `<ostream>` `<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP20_CHAR8_T
  #define LBAL_LIBCPP20_CHAR8_T 0
#endif

/**
  @def LBAL_LIBCPP20_CHAR8_T_COMPAT
  @brief Fix backward compatibility issues introduced by `char8_t`
  @details SD-6 equivalent: `__cpp_lib_char8_t >= 201907L`. Note that
  `__cpp_lib_char8_t` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P1423R3](https://wg21.link/P1423R3) char8_t backward
  compatibility remediation

  @sa `<atomic>` `<filesystem>` `freestanding` `<iosfwd>` `<istream>` `<limits>`
  `<locale>` `<ostream>` `<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP20_CHAR8_T_COMPAT
  #define LBAL_LIBCPP20_CHAR8_T_COMPAT 0
#endif

/**
  @def LBAL_LIBCPP20_CHRONO_CALENDAR
  @brief Add support for Calendars and Time Zones to `<chrono>`
  @details SD-6 equivalent: `__cpp_lib_chrono >= 201803L`. Note that
  `__cpp_lib_chrono` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201803L` [P0355R7](https://wg21.link/P0355R7) Extending `<chrono>` to
  Calendars and Time Zones

  @sa `<chrono>`
*/
#ifndef LBAL_LIBCPP20_CHRONO_CALENDAR
  #define LBAL_LIBCPP20_CHRONO_CALENDAR 0
#endif

/**
  @def LBAL_LIBCPP20_CHRONO_CALENDAR_TYPES
  @brief Proxy to indicate support for just the types associated with
  `__cpp_lib_chrono>=201803`
  @details SD-6 equivalent: `__cpp_lib_chrono >= 201803L`. Note that
  `__cpp_lib_chrono` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201803L` [P0355R7](https://wg21.link/P0355R7) Extending `<chrono>` to
  Calendars and Time Zones

  @remark Older `libc++` releases don’t support the entirety of
  `__cpp_lib_chrono`, but they do support the types associated with that token,
  which are useful on their own.

  @sa `<chrono>`
*/
#ifndef LBAL_LIBCPP20_CHRONO_CALENDAR_TYPES
  #define LBAL_LIBCPP20_CHRONO_CALENDAR_TYPES 0
#endif

/**
  @def LBAL_LIBCPP20_CHRONO_FIXES
  @brief Miscellaneous minor fixes for `<chrono>`
  @details SD-6 equivalent: `__cpp_lib_chrono >= 201907L`. Note that
  `__cpp_lib_chrono` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P1466R3](https://wg21.link/P1466R3) Miscellaneous minor fixes
  for chrono

  @sa `<chrono>`
*/
#ifndef LBAL_LIBCPP20_CHRONO_FIXES
  #define LBAL_LIBCPP20_CHRONO_FIXES 0
#endif

/**
  @def LBAL_LIBCPP20_CONCEPTS
  @brief Standard Library Concepts
  @details SD-6 equivalent: `__cpp_lib_concepts >= 201806L`. Note that
  `__cpp_lib_concepts` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201806L` [P0898R3 __PDF__](https://wg21.link/P0898R3) Standard Library
  Concepts

  @sa `<compare>` `<concepts>` `freestanding`
*/
#ifndef LBAL_LIBCPP20_CONCEPTS
  #define LBAL_LIBCPP20_CONCEPTS 0
#endif

/**
  @def LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE
  @brief Wording for boolean-testable
  @details SD-6 equivalent: `__cpp_lib_concepts >= 202002L`. Note that
  `__cpp_lib_concepts` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202002L` [P1964R2](https://wg21.link/P1964R2) Wording for
  `boolean-testable`

  @sa `<compare>` `<concepts>` `freestanding`
*/
#ifndef LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE
  #define LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE 0
#endif

/**
  @def LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE
  @brief Rename C++ Concepts to use standard_case
  @details SD-6 equivalent: `__cpp_lib_concepts >= 201907L`. Note that
  `__cpp_lib_concepts` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P1754R1 __PDF__](https://wg21.link/P1754R1) Rename concepts to
  standard_case for C++20, while we still can

  @sa `<compare>` `<concepts>` `freestanding`
*/
#ifndef LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE
  #define LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS
  @brief Add `constexpr` to `<algorithm>` and `<utility>` functions
  @details SD-6 equivalent: `__cpp_lib_constexpr_algorithms >= 201703L`. Note
  that `__cpp_lib_constexpr_algorithms` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `201703L` [P0202R3](https://wg21.link/P0202R3) Add Constexpr Modifiers to
  Functions in `<algorithm>` and `<utility>` Headers

  @sa `<algorithm>` `<utility>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS
  #define LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP
  @brief Add `constexpr` to `std::swap` and related functions
  @details SD-6 equivalent: `__cpp_lib_constexpr_algorithms >= 201806L`. Note
  that `__cpp_lib_constexpr_algorithms` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `201806L` [LWG3256](https://wg21.link/LWG3256) Feature testing macro for
  `constexpr` algorithms
  - `201806L` [LWG3792](https://wg21.link/LWG3792)
  __cpp_lib_constexpr_algorithms should also be defined in
  - `201806L` [P0879R0](https://wg21.link/P0879R0) Constexpr for swap and swap
  related functions

  @sa `<algorithm>` `<utility>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP
  #define LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_COMPLEX
  @brief Add more `constexpr` support to `<complex>`
  @details SD-6 equivalent: `__cpp_lib_constexpr_complex >= 201711L`. Note that
  `__cpp_lib_constexpr_complex` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201711L` [P0415R1](https://wg21.link/P0415R1) Constexpr for std::complex

  @sa `<complex>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_COMPLEX
  #define LBAL_LIBCPP20_CONSTEXPR_COMPLEX 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC
  @brief Add `constexpr` memory allocators used by dynamic containers
  @details SD-6 equivalent: `__cpp_lib_constexpr_dynamic_alloc >= 201907L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201907L` [P0784R7](https://wg21.link/P0784R7) More constexpr containers

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC
  #define LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL
  @brief Make more of `<functional>` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_functional >= 201811L`. Note
  that `__cpp_lib_constexpr_functional` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `201811L` [P1032R1](https://wg21.link/P1032R1) Misc constexpr bits

  @sa `freestanding` `<functional>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL
  #define LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE
  @brief Make `std::invoke` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_functional >= 201907L`. Note
  that `__cpp_lib_constexpr_functional` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `201907L` [P1065R2](https://wg21.link/P1065R2) `constexpr` `INVOKE`

  @sa `freestanding` `<functional>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE
  #define LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_ITERATOR
  @brief Make more of `<iterator>` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_iterator >= 201811L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201811L` [P1032R1](https://wg21.link/P1032R1) Misc constexpr bits

  @sa `freestanding` `<iterator>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_ITERATOR
  #define LBAL_LIBCPP20_CONSTEXPR_ITERATOR 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_MEMORY
  @brief Make `std::pointer_traits` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_memory >= 201811L`. Note that
  `__cpp_lib_constexpr_memory` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P1006R1 __PDF__](https://wg21.link/P1006R1) Constexpr in
  `std::pointer_traits`

  @sa `freestanding` `<memory>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_MEMORY
  #define LBAL_LIBCPP20_CONSTEXPR_MEMORY 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_NUMERIC
  @brief Make numeric algorithms `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_numeric >= 201911L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201911L` [P1645R1](https://wg21.link/P1645R1) constexpr for `<numeric>`
  algorithms

  @sa `freestanding` `<numeric>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_NUMERIC
  #define LBAL_LIBCPP20_CONSTEXPR_NUMERIC 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_STRING
  @brief Make `std::string` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_string >= 201907L`. Note that
  `__cpp_lib_constexpr_string` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P0980R1 __PDF__](https://wg21.link/P0980R1) Making `std::string`
  constexpr

  @sa `<string>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_STRING
  #define LBAL_LIBCPP20_CONSTEXPR_STRING 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL
  @brief Make parts of `std::string` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_string >= 201811L`. Note that
  `__cpp_lib_constexpr_string` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P1032R1](https://wg21.link/P1032R1) Misc constexpr bits

  @sa `<string>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL
  #define LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW
  @brief Make more of `<string_view>` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_string_view >= 201811L`. Note
  that `__cpp_lib_constexpr_string_view` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `201811L` [P1032R1](https://wg21.link/P1032R1) Misc constexpr bits

  @sa `<string_view>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW
  #define LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_TUPLE
  @brief Make more of `<tuple>` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_tuple >= 201811L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201811L` [P1032R1](https://wg21.link/P1032R1) Misc constexpr bits

  @sa `freestanding` `<tuple>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_TUPLE
  #define LBAL_LIBCPP20_CONSTEXPR_TUPLE 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_UTILITY
  @brief Make more of `<tuple>` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_utility >= 201811L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201811L` [P1032R1](https://wg21.link/P1032R1) Misc constexpr bits

  @sa `freestanding` `<utility>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_UTILITY
  #define LBAL_LIBCPP20_CONSTEXPR_UTILITY 0
#endif

/**
  @def LBAL_LIBCPP20_CONSTEXPR_VECTOR
  @brief Make `std::vector` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_vector >= 201907L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201907L` [P1004R2 __PDF__](https://wg21.link/P1004R2) Making `std::vector`
  constexpr

  @sa `<vector>`
*/
#ifndef LBAL_LIBCPP20_CONSTEXPR_VECTOR
  #define LBAL_LIBCPP20_CONSTEXPR_VECTOR 0
#endif

/**
  @def LBAL_LIBCPP20_COROUTINE
  @brief Standard Library coroutines
  @details SD-6 equivalent: `__cpp_lib_coroutine >= 201902L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201902L` [LWG3393](https://wg21.link/LWG3393) Missing/incorrect feature
  test macro for coroutines
  - `201902L` [P0912R5](https://wg21.link/P0912R5) Merge Coroutines TS into
  C++20 working draft

  @remark Note that `<coroutine>` requires language support.

  @sa `<coroutine>` `freestanding`
*/
#ifndef LBAL_LIBCPP20_COROUTINE
  #define LBAL_LIBCPP20_COROUTINE 0
#endif

/**
  @def LBAL_LIBCPP20_DESTROYING_DELETE
  @brief Efficient sized `delete` for variable-sized classes
  @details SD-6 equivalent: `__cpp_lib_destroying_delete >= 201806L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201806L` [P0722R3](https://wg21.link/P0722R3) Efficient sized delete for
  variable sized classes

  @sa `freestanding` `<new>`
*/
#ifndef LBAL_LIBCPP20_DESTROYING_DELETE
  #define LBAL_LIBCPP20_DESTROYING_DELETE 0
#endif

/**
  @def LBAL_LIBCPP20_ENDIAN
  @brief Add `std::endian` enum
  @details SD-6 equivalent: `__cpp_lib_endian >= 201907L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `201907L` [P0463R1](https://wg21.link/P0463R1) `endian`, Just `endian`

  @sa `<bit>` `freestanding`
*/
#ifndef LBAL_LIBCPP20_ENDIAN
  #define LBAL_LIBCPP20_ENDIAN 0
#endif

/**
  @def LBAL_LIBCPP20_ENDIAN_BIT
  @brief Relocate `std::endian` to `<bit>`
  @details SD-6 equivalent: `__cpp_lib_endian >= 201907L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `201907L` [P1612R1 __PDF__](https://wg21.link/P1612R1) Relocate Endian’s
  Specification

  @sa `<bit>` `freestanding`
*/
#ifndef LBAL_LIBCPP20_ENDIAN_BIT
  #define LBAL_LIBCPP20_ENDIAN_BIT 0
#endif

/**
  @def LBAL_LIBCPP20_ERASE_IF
  @brief Adopt consistent container erasure
  @details SD-6 equivalent: `__cpp_lib_erase_if >= 201811L`. Note that
  `__cpp_lib_erase_if` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P1209R0](https://wg21.link/P1209R0) Adopt Consistent Container
  Erasure from Library Fundamentals 2 for C++20

  @sa `<deque>` `<forward_list>` `<list>` `<map>` `<set>` `<string>`
  `<unordered_map>` `<unordered_set>` `<vector>`
*/
#ifndef LBAL_LIBCPP20_ERASE_IF
  #define LBAL_LIBCPP20_ERASE_IF 0
#endif

/**
  @def LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS
  @brief Update `erase_if` free function return types
  @details SD-6 equivalent: `__cpp_lib_erase_if >= 202002L`. Note that
  `__cpp_lib_erase_if` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202002L` [P1115R3 __PDF__](https://wg21.link/P1115R3) Improving the Return
  Value of Erase-Like Algorithms II: Free erase/erase_if

  @sa `<deque>` `<forward_list>` `<list>` `<map>` `<set>` `<string>`
  `<unordered_map>` `<unordered_set>` `<vector>`
*/
#ifndef LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS
  #define LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS 0
#endif

/**
  @def LBAL_LIBCPP20_EXECUTION_VECTORIZATION
  @brief Add target vectorization policies from the Parallelism V2 TS
  @details SD-6 equivalent: `__cpp_lib_execution >= 201902L`. Note that
  `__cpp_lib_execution` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201902L` [P1001R2](https://wg21.link/P1001R2) Target Vectorization Policies
  from Parallelism V2 TS to C++20

  @remark (APIME) We do not track experimental versions of this.

  @sa `<execution>`
*/
#ifndef LBAL_LIBCPP20_EXECUTION_VECTORIZATION
  #define LBAL_LIBCPP20_EXECUTION_VECTORIZATION 0
#endif

/**
  @def LBAL_LIBCPP20_FORMAT
  @brief Add text formatting functionality to properly replace `printf`
  @details SD-6 equivalent: `__cpp_lib_format >= 201907L`. Note that
  `__cpp_lib_format` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P0645R10](https://wg21.link/P0645R10) Text Formatting
  - `201907L` [P1361R2 __PDF__](https://wg21.link/P1361R2) Integration of chrono
  with text formatting
  - `201907L` [P1652R1](https://wg21.link/P1652R1) Printf corner cases in
  `std::format`

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP20_FORMAT
  #define LBAL_LIBCPP20_FORMAT 0
#endif

/**
  @def LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP
  @brief Heterogeneous lookup for unordered containers
  @details SD-6 equivalent: `__cpp_lib_generic_unordered_lookup >= 201811L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201811L` [P0919R3](https://wg21.link/P0919R3) Heterogeneous lookup for
  unordered containers

  @sa `<unordered_map>` `<unordered_set>`
*/
#ifndef LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP
  #define LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP 0
#endif

/**
  @def LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS
  @brief Add Safe integral comparisons
  @details SD-6 equivalent: `__cpp_lib_integer_comparison_functions >= 202002L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202002L` [P0586R2](https://wg21.link/P0586R2) Safe integral comparisons

  @sa `freestanding` `<utility>`
*/
#ifndef LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS
  #define LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS 0
#endif

/**
  @def LBAL_LIBCPP20_INTERPOLATE
  @brief Add well-behaved interpolation for numbers and pointers
  @details SD-6 equivalent: `__cpp_lib_interpolate >= 201902L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201902L` [P0811R3](https://wg21.link/P0811R3) Well-behaved interpolation
  for numbers and pointers

  @sa `<cmath>` `<numeric>`
*/
#ifndef LBAL_LIBCPP20_INTERPOLATE
  #define LBAL_LIBCPP20_INTERPOLATE 0
#endif

/**
  @def LBAL_LIBCPP20_INT_POW2
  @brief Integral power-of-2 operations
  @details SD-6 equivalent: `__cpp_lib_int_pow2 >= 201806L`. Note that
  `__cpp_lib_int_pow2` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201806L` [P0556R3](https://wg21.link/P0556R3) Integral power-of-2
  operations

  @sa `<bit>` `freestanding`
*/
#ifndef LBAL_LIBCPP20_INT_POW2
  #define LBAL_LIBCPP20_INT_POW2 0
#endif

/**
  @def LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME
  @brief Rename the assorted bit-manipulation fucntions
  @details SD-6 equivalent: `__cpp_lib_int_pow2 >= 202002L`. Note that
  `__cpp_lib_int_pow2` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202002L` [P1956R1 __PDF__](https://wg21.link/P1956R1) On the naming of
  low-level bit manipulation functions

  @sa `<bit>` `freestanding`
*/
#ifndef LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME
  #define LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME 0
#endif

/**
  @def LBAL_LIBCPP20_IS_CONSTANT_EVALUATED
  @brief Add `std::is_constant_evaluated` type trait
  @details SD-6 equivalent: `__cpp_lib_is_constant_evaluated >= 201811L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201811L` [P0595R2](https://wg21.link/P0595R2) std::is_constant_evaluated

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP20_IS_CONSTANT_EVALUATED
  #define LBAL_LIBCPP20_IS_CONSTANT_EVALUATED 0
#endif

/**
  @def LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE
  @brief Add `std::is_layout_compatible` type trait
  @details SD-6 equivalent: `__cpp_lib_is_layout_compatible >= 201907L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201907L` [P0466R5 __PDF__](https://wg21.link/P0466R5) Layout-compatibility
  and Pointer-interconvertibility Traits

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE
  #define LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE 0
#endif

/**
  @def LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE
  @brief Add `std::is_nothrow_convertible` type trait
  @details SD-6 equivalent: `__cpp_lib_is_nothrow_convertible >= 201806L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201806L` [LWG3356](https://wg21.link/LWG3356)
  `__cpp_lib_nothrow_convertible` should be `__cpp_lib_is_nothrow_convertible`
  - `201806L` [P0758R1](https://wg21.link/P0758R1) Implicit conversion traits
  and utility functions

  @remark (SEEME - bitweeder) LWG3356 should probably have gotten its own
  value; the argument against that is that it was a defect corrected prior to
  Standardization.

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE
  #define LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE 0
#endif

/**
  @def LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE
  @brief Add `std::is_pointer_interconvertible` type trait
  @details SD-6 equivalent: `__cpp_lib_is_pointer_interconvertible >= 201907L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201907L` [P0466R5 __PDF__](https://wg21.link/P0466R5) Layout-compatibility
  and Pointer-interconvertibility Traits

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE
  #define LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE 0
#endif

/**
  @def LBAL_LIBCPP20_JTHREAD
  @brief Add a cooperatively interruptible joining thread
  @details SD-6 equivalent: `__cpp_lib_jthread >= 201907L`. Note that
  `__cpp_lib_jthread` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P0660R10 __PDF__](https://wg21.link/P0660R10) Stop Token and
  Joining Thread

  @sa `<stop_token>` `<thread>`
*/
#ifndef LBAL_LIBCPP20_JTHREAD
  #define LBAL_LIBCPP20_JTHREAD 0
#endif

/**
  @def LBAL_LIBCPP20_JTHREAD_CV
  @brief Simplify condition variable API
  @details SD-6 equivalent: `__cpp_lib_jthread >= 201911L`. Note that
  `__cpp_lib_jthread` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201911L` [P1869R1](https://wg21.link/P1869R1) Rename
  ‘condition_variable_any’ interruptible wait methods

  @sa `<stop_token>` `<thread>`
*/
#ifndef LBAL_LIBCPP20_JTHREAD_CV
  #define LBAL_LIBCPP20_JTHREAD_CV 0
#endif

/**
  @def LBAL_LIBCPP20_LATCH
  @brief Incorporate `std::latch` from the C++20 Synchronization Library
  @details SD-6 equivalent: `__cpp_lib_latch >= 201907L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `201907L` [P1135R6](https://wg21.link/P1135R6) The C++20 Synchronization
  Library

  @sa `<latch>`
*/
#ifndef LBAL_LIBCPP20_LATCH
  #define LBAL_LIBCPP20_LATCH 0
#endif

/**
  @def LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE
  @brief Improve the return value of erase-like algorithms
  @details SD-6 equivalent: `__cpp_lib_list_remove_return_type >= 201806L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201806L` [P0646R1 __PDF__](https://wg21.link/P0646R1) Improving the Return
  Value of Erase-Like Algorithms I: `list`/`forward list`

  @sa `<forward_list>` `<list>`
*/
#ifndef LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE
  #define LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE 0
#endif

/**
  @def LBAL_LIBCPP20_MATH_CONSTANTS
  @brief Add common math constants to the C++ Standard
  @details SD-6 equivalent: `__cpp_lib_math_constants >= 201907L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201907L` [P0631R8 __PDF__](https://wg21.link/P0631R8) Math Constants

  @sa `<numbers>`
*/
#ifndef LBAL_LIBCPP20_MATH_CONSTANTS
  #define LBAL_LIBCPP20_MATH_CONSTANTS 0
#endif

/**
  @def LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR
  @brief Provide a default template argument for `std::polymorphic_allocator`
  @details SD-6 equivalent: `__cpp_lib_polymorphic_allocator >= 201902L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201902L` [LWG3437](https://wg21.link/LWG3437)
  `__cpp_lib_polymorphic_allocator` is in the wrong header
  - `201902L` [P0339R6 __PDF__](https://wg21.link/P0339R6)
  polymorphic_allocator<> as a vocabulary type

  @sa `<memory_resource>`
*/
#ifndef LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR
  #define LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR 0
#endif

/**
  @def LBAL_LIBCPP20_RANGES
  @brief Incorporate ranges into the C++ Standard
  @details SD-6 equivalent: `__cpp_lib_ranges >= 201811L`. Note that
  `__cpp_lib_ranges` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P0896R4 __PDF__](https://wg21.link/P0896R4) The One Ranges
  Proposal

  @sa `<algorithm>` `<functional>` `<iterator>` `<memory>` `<ranges>`
*/
#ifndef LBAL_LIBCPP20_RANGES
  #define LBAL_LIBCPP20_RANGES 0
#endif

/**
  @def LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS
  @brief Add input range adaptors
  @details SD-6 equivalent: `__cpp_lib_ranges >= 201907L`. Note that
  `__cpp_lib_ranges` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P1035R7 __PDF__](https://wg21.link/P1035R7) Input Range Adaptors

  @sa `<algorithm>` `<functional>` `<iterator>` `<memory>` `<ranges>`
*/
#ifndef LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS
  #define LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS 0
#endif

/**
  @def LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE
  @brief Loosen the constraints on range-based compare algorithms
  @details SD-6 equivalent: `__cpp_lib_ranges >= 201911L`. Note that
  `__cpp_lib_ranges` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201911L` [P1716R3](https://wg21.link/P1716R3) `ranges` compare algorithm
  are over-constrained

  @sa `<algorithm>` `<functional>` `<iterator>` `<memory>` `<ranges>`
*/
#ifndef LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE
  #define LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE 0
#endif

/**
  @def LBAL_LIBCPP20_REMOVE_CVREF
  @brief Add `std::remove_cvref` type trait
  @details SD-6 equivalent: `__cpp_lib_remove_cvref >= 201711L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201711L` [P0550R2 __PDF__](https://wg21.link/P0550R2) Transformation Trait
  remove_cvref

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP20_REMOVE_CVREF
  #define LBAL_LIBCPP20_REMOVE_CVREF 0
#endif

/**
  @def LBAL_LIBCPP20_SEMAPHORE
  @brief Incorporate `std::semaphore` from the C++20 Synchronization Library
  @details SD-6 equivalent: `__cpp_lib_semaphore >= 201907L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201907L` [P1135R6](https://wg21.link/P1135R6) The C++20 Synchronization
  Library

  @sa `<semaphore>`
*/
#ifndef LBAL_LIBCPP20_SEMAPHORE
  #define LBAL_LIBCPP20_SEMAPHORE 0
#endif

/**
  @def LBAL_LIBCPP20_SHARED_PTR_ARRAYS
  @brief Extend `std::make_shared` to support C-style arrays
  @details SD-6 equivalent: `__cpp_lib_shared_ptr_arrays >= 201707L`. Note that
  `__cpp_lib_shared_ptr_arrays` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201707L` [P0674R1](https://wg21.link/P0674R1) Extending make_shared to
  Support Arrays

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP20_SHARED_PTR_ARRAYS
  #define LBAL_LIBCPP20_SHARED_PTR_ARRAYS 0
#endif

/**
  @def LBAL_LIBCPP20_SHIFT
  @brief Add `std::shift_left` and `std::shift_right`
  @details SD-6 equivalent: `__cpp_lib_shift >= 201806L`. Note that
  `__cpp_lib_shift` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201806L` [P0769R2 __PDF__](https://wg21.link/P0769R2) Add shift to
  `<algorithm>`

  @sa `<algorithm>`
*/
#ifndef LBAL_LIBCPP20_SHIFT
  #define LBAL_LIBCPP20_SHIFT 0
#endif

/**
  @def LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE
  @brief Support smart pointer creation with default initialization
  @details SD-6 equivalent: `__cpp_lib_smart_ptr_for_overwrite >= 202002L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202002L` [P1020R1](https://wg21.link/P1020R1) Smart pointer creation with
  default initialization
  - `202002L` [P1973R1 __PDF__](https://wg21.link/P1973R1) Rename _default_init
  functions (NB Comment DE002)

  @remark The SD-6 token was renamed as part of
  [P1973R1](https://wg21.link/P1973R1), which also updated its value. We don’t
  track the original.

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE
  #define LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE 0
#endif

/**
  @def LBAL_LIBCPP20_SOURCE_LOCATION
  @brief Adopt `std::source_location` from the Library Fundamentals V3 TS
  @details SD-6 equivalent: `__cpp_lib_source_location >= 201907L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201907L` [P1208R6 __PDF__](https://wg21.link/P1208R6) Adopt source location
  from Library Fundamentals V3 for C++20

  @sa `freestanding` `<source_location>`
*/
#ifndef LBAL_LIBCPP20_SOURCE_LOCATION
  #define LBAL_LIBCPP20_SOURCE_LOCATION 0
#endif

/**
  @def LBAL_LIBCPP20_SPAN
  @brief Add `std::span`
  @details SD-6 equivalent: `__cpp_lib_span >= 201803L`. Note that
  `__cpp_lib_span` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201803L` [LWG3274](https://wg21.link/LWG3274) Missing feature test macro
  for `<span>`
  - `201803L` [P0122R7 __PDF__](https://wg21.link/P0122R7) `span`: bounds-safe
  views for sequences of objects

  @remark The issue raised in [LWG3274](https://wg21.link/LWG3274) was simply
  that [P0122R7](https://wg21.link/P0122R7) had been voted in without specifying
  an SD-6 macro.

  @sa `freestanding` `<span>`
*/
#ifndef LBAL_LIBCPP20_SPAN
  #define LBAL_LIBCPP20_SPAN 0
#endif

/**
  @def LBAL_LIBCPP20_SPAN_FIXED_SIZE
  @brief Fix constructing a fixed-size `std::span` from a dynamic range
  @details SD-6 equivalent: `__cpp_lib_span >= 202002L`. Note that
  `__cpp_lib_span` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202002L` [P1976R2](https://wg21.link/P1976R2) Fixed-size `span`
  construction from dynamic range

  @sa `freestanding` `<span>`
*/
#ifndef LBAL_LIBCPP20_SPAN_FIXED_SIZE
  #define LBAL_LIBCPP20_SPAN_FIXED_SIZE 0
#endif

/**
  @def LBAL_LIBCPP20_SPAN_USABILITY
  @brief Enhance usability for `std::span`
  @details SD-6 equivalent: `__cpp_lib_span >= 201902L`. Note that
  `__cpp_lib_span` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201902L` [P1024R3 __PDF__](https://wg21.link/P1024R3) Usability
  Enhancements for `std::span`

  @sa `freestanding` `<span>`
*/
#ifndef LBAL_LIBCPP20_SPAN_USABILITY
  #define LBAL_LIBCPP20_SPAN_USABILITY 0
#endif

/**
  @def LBAL_LIBCPP20_SSIZE
  @brief Add `std::ssize` and fix `std::span`’s `size` return values
  @details SD-6 equivalent: `__cpp_lib_ssize >= 201902L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `201902L` [P1227R2](https://wg21.link/P1227R2) Signed ssize() functions,
  unsigned size() functions

  @remark It’s conceivable that the `<span>`-affecting portions of this will be
  shifted to the `__cpp_lib_span` token.

  @sa `freestanding` `<iterator>`
*/
#ifndef LBAL_LIBCPP20_SSIZE
  #define LBAL_LIBCPP20_SSIZE 0
#endif

/**
  @def LBAL_LIBCPP20_STARTS_ENDS_WITH
  @brief Add string prefix- and suffix-checking
  @details SD-6 equivalent: `__cpp_lib_starts_ends_with >= 201711L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201711L` [P0457R2](https://wg21.link/P0457R2) String Prefix and Suffix
  Checking

  @sa `<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP20_STARTS_ENDS_WITH
  #define LBAL_LIBCPP20_STARTS_ENDS_WITH 0
#endif

/**
  @def LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR
  @brief Add support for `constexpr` iterators to `<string_view>`
  @details SD-6 equivalent: `__cpp_lib_string_view >= 201803L`. Note that
  `__cpp_lib_string_view` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201803L` [LWG3257](https://wg21.link/LWG3257) Missing feature testing macro
  update from P0858
  - `201803L` [P0858R0](https://wg21.link/P0858R0) Constexpr iterator
  requirements

  @remark The issue raised in [LWG3257](https://wg21.link/LWG3257) was simply
  that the SD-6 macro update voted in with [P0858R0](https://wg21.link/P0858R0)
  had not been applied.

  @sa `<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR
  #define LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR 0
#endif

/**
  @def LBAL_LIBCPP20_SYNCBUF
  @brief Add synchronized buffered output streams
  @details SD-6 equivalent: `__cpp_lib_syncbuf >= 201711L`. Note that
  `__cpp_lib_syncbuf` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201711L` [P0053R7 __PDF__](https://wg21.link/P0053R7) C++ Synchronized
  Buffered Ostream

  @sa `<iosfwd>` `<syncstream>`
*/
#ifndef LBAL_LIBCPP20_SYNCBUF
  #define LBAL_LIBCPP20_SYNCBUF 0
#endif

/**
  @def LBAL_LIBCPP20_SYNCBUF_MANIPULATORS
  @brief Add manipulators for synchronized buffered output streams
  @details SD-6 equivalent: `__cpp_lib_syncbuf >= 201803L`. Note that
  `__cpp_lib_syncbuf` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201803L` [P0753R2 __PDF__](https://wg21.link/P0753R2) Manipulators for C++
  Synchronized Buffered Ostream

  @sa `<iosfwd>` `<syncstream>`
*/
#ifndef LBAL_LIBCPP20_SYNCBUF_MANIPULATORS
  #define LBAL_LIBCPP20_SYNCBUF_MANIPULATORS 0
#endif

/**
  @def LBAL_LIBCPP20_THREE_WAY_COMPARISON
  @brief Add `<compare>` to the Standard Library
  @details SD-6 equivalent: `__cpp_lib_three_way_comparison >= 201711L`. Note
  that `__cpp_lib_three_way_comparison` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `201711L` [P0768R1 __PDF__](https://wg21.link/P0768R1) Library Support for
  the Spaceship (Comparison) Operator

  @sa `<compare>` `freestanding`
*/
#ifndef LBAL_LIBCPP20_THREE_WAY_COMPARISON
  #define LBAL_LIBCPP20_THREE_WAY_COMPARISON 0
#endif

/**
  @def LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY
  @brief Add three-way comparison support to the Standard Library
  @details SD-6 equivalent: `__cpp_lib_three_way_comparison >= 201907L`. Note
  that `__cpp_lib_three_way_comparison` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `201907L` [P1614R2](https://wg21.link/P1614R2) The Mothership Has Landed:
  Adding <=> to the Library

  @sa `<compare>` `freestanding`
*/
#ifndef LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY
  #define LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY 0
#endif

/**
  @def LBAL_LIBCPP20_TO_ADDRESS
  @brief Provide a utility to convert a pointer to a raw pointer
  @details SD-6 equivalent: `__cpp_lib_to_address >= 201711L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201711L` [P0653R2](https://wg21.link/P0653R2) Utility to convert a pointer
  to a raw pointer

  @sa `freestanding` `<memory>`
*/
#ifndef LBAL_LIBCPP20_TO_ADDRESS
  #define LBAL_LIBCPP20_TO_ADDRESS 0
#endif

/**
  @def LBAL_LIBCPP20_TO_ARRAY
  @brief Adopt `std::to_array` from the Library Fundamentals TS
  @details SD-6 equivalent: `__cpp_lib_to_array >= 201907L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201907L` [P0325R4](https://wg21.link/P0325R4) `to_array` from LFTS with
  updates

  @sa `<array>` `freestanding`
*/
#ifndef LBAL_LIBCPP20_TO_ARRAY
  #define LBAL_LIBCPP20_TO_ARRAY 0
#endif

/**
  @def LBAL_LIBCPP20_TYPE_IDENTITY
  @brief Add the `std::identity` metafunction
  @details SD-6 equivalent: `__cpp_lib_type_identity >= 201806L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201806L` [P0887R1 __PDF__](https://wg21.link/P0887R1) The identity
  metafunction

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP20_TYPE_IDENTITY
  #define LBAL_LIBCPP20_TYPE_IDENTITY 0
#endif

/**
  @def LBAL_LIBCPP20_UNWRAP_REF
  @brief Add `std::unwrap_reference` and `std::unwrap_ref_decay`
  @details SD-6 equivalent: `__cpp_lib_unwrap_ref >= 201811L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201811L` [LWG3348](https://wg21.link/LWG3348) `__cpp_lib_unwrap_ref` in
  wrong header
  - `201811L` [P0318R1 __PDF__](https://wg21.link/P0318R1) `unwrap_ref_decay`
  and `unwrap_reference`

  @remark Originally, this was in `<type_traits>`.

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP20_UNWRAP_REF
  #define LBAL_LIBCPP20_UNWRAP_REF 0
#endif

/**
  @def LBAL_LIBCPP20_VERSION
  @brief Identifies whether `<version>` is present and include-able given the
  current C++ Standard dialect in use
  @details Unlike `<version>`, lucenaBAL tracks “correct”, functioning
  implementations only. For this reason, it is recommended to _always_ favor the
  `lucenaBAL` reporting of a given feature’s availability, even when `<version>`
  is available.

  @remark An example of false negative reporting is Xcode (again) always
  reporting certain library fearures as unavailable when they’re actually gated
  depending on the version of the SDK in use (e.g., `__cpp_lib_to_chars`).

  @remark An example of false positive reporting in `version` is older Xcodes’
  claim for support for `<any>` and friends before they were actually working.

  @remark Some implementations may choose to back-port `<version>` to earlier
  releases, in which case this token will be set.
*/
#ifndef LBAL_LIBCPP20_VERSION
  #define LBAL_LIBCPP20_VERSION 0
#endif

///	@}	LBAL_LIBCPP20

///	@}	lbal_library
