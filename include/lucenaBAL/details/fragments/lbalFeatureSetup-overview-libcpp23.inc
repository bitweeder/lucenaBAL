/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFeatureSetup-overview-libcpp23.inc”
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
  @name LBAL_LIBCPP23

  @brief These are all taken from features that have been incorporated into
  the C++23 Standard.

  @{
*/

/**
  @def LBAL_LIBCPP23_ADAPTOR_ITERATOR_PAIR_CONSTRUCTOR
  @brief Iterators `pair` constructors for `stack` and `queue`
  @details SD-6 equivalent: `__cpp_lib_adaptor_iterator_pair_constructor >=
  202106L`. This token will have a value of `0` if the proposal described here
  is not supported.
  - `202106L` [P1425R4](https://wg21.link/P1425R4) **PDF** Iterators pair
  constructors for stack and queue

  @sa `<queue>` `<stack>`
*/
#ifndef LBAL_LIBCPP23_ADAPTOR_ITERATOR_PAIR_CONSTRUCTOR
  #define LBAL_LIBCPP23_ADAPTOR_ITERATOR_PAIR_CONSTRUCTOR 0
#endif

/**
  @def LBAL_LIBCPP23_ALGORITHM_ITERATOR_REQUIREMENTS
  @brief Ranges iterators as inputs to non-Ranges algorithms
  @details SD-6 equivalent: `__cpp_lib_algorithm_iterator_requirements >=
  202207L`. This token will have a value of `0` if the proposal described here
  is not supported.
  - `202207L` [P2408R5](https://wg21.link/P2408R5) Ranges iterators as inputs to
  non-Ranges algorithms

  @sa `<algorithm>` `<memory>` `<numeric>`
*/
#ifndef LBAL_LIBCPP23_ALGORITHM_ITERATOR_REQUIREMENTS
  #define LBAL_LIBCPP23_ALGORITHM_ITERATOR_REQUIREMENTS 0
#endif

/**
  @def LBAL_LIBCPP23_ALLOCATE_AT_LEAST
  @brief Provide size feedback in the Allocator interface
  @details SD-6 equivalent: `__cpp_lib_allocate_at_least >= 202106L`. Note that
  `__cpp_lib_allocate_at_least` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202106L` [P0401R6](https://wg21.link/P0401R6) Providing size feedback in
  the Allocator interface

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP23_ALLOCATE_AT_LEAST
  #define LBAL_LIBCPP23_ALLOCATE_AT_LEAST 0
#endif

/**
  @def LBAL_LIBCPP23_ALLOCATE_AT_LEAST_DISALLOW_USER_SPEC
  @brief Disallow user specialization of `allocator_traits`
  @details SD-6 equivalent: `__cpp_lib_allocate_at_least >= 202302L`. Note that
  `__cpp_lib_allocate_at_least` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202302L` [LWG3887](https://wg21.link/LWG3887) Version macro for
  `allocate_at_least`
  - `202302L` [P2652R2](https://wg21.link/P2652R2) Disallow user specialization
  of allocator_traits

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP23_ALLOCATE_AT_LEAST_DISALLOW_USER_SPEC
  #define LBAL_LIBCPP23_ALLOCATE_AT_LEAST_DISALLOW_USER_SPEC 0
#endif

/**
  @def LBAL_LIBCPP23_ASSOCIATIVE_HETEROGENEOUS_ERASURE
  @brief Heterogeneous erasure overloads for associative containers
  @details SD-6 equivalent: `__cpp_lib_associative_heterogeneous_erasure >=
  202110L`. This token will have a value of `0` if the proposal described here
  is not supported.
  - `202110L` [P2077R3](https://wg21.link/P2077R3) Heterogeneous erasure
  overloads for associative containers

  @sa `<map>` `<set>` `<unordered_map>` `<unordered_set>`
*/
#ifndef LBAL_LIBCPP23_ASSOCIATIVE_HETEROGENEOUS_ERASURE
  #define LBAL_LIBCPP23_ASSOCIATIVE_HETEROGENEOUS_ERASURE 0
#endif

/**
  @def LBAL_LIBCPP23_BARRIER_RELAXED_COMPLETION
  @brief Relax `std::barrier` phase completion step guarantees
  @details SD-6 equivalent: `__cpp_lib_barrier >= 202302L`. Note that
  `__cpp_lib_barrier` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202302L` [P2588R3](https://wg21.link/P2588R3) Relax std::barrier phase
  completion step guarantees

  @sa `<barrier>`
*/
#ifndef LBAL_LIBCPP23_BARRIER_RELAXED_COMPLETION
  #define LBAL_LIBCPP23_BARRIER_RELAXED_COMPLETION 0
#endif

/**
  @def LBAL_LIBCPP23_BIND_BACK
  @brief Pipe support for user-defined range adaptors
  @details SD-6 equivalent: `__cpp_lib_bind_back >= 202202L`. Note that
  `__cpp_lib_bind_back` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202202L` [P2387R3](https://wg21.link/P2387R3) Pipe support for user-defined
  range adaptors

  @sa `freestanding` `<functional>`
*/
#ifndef LBAL_LIBCPP23_BIND_BACK
  #define LBAL_LIBCPP23_BIND_BACK 0
#endif

/**
  @def LBAL_LIBCPP23_BYTESWAP
  @brief Byteswapping for fun&&nuf
  @details SD-6 equivalent: `__cpp_lib_byteswap >= 202110L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202110L` [P1272R4](https://wg21.link/P1272R4) Byteswapping for fun&&nuf

  @sa `<bit>` `freestanding`
*/
#ifndef LBAL_LIBCPP23_BYTESWAP
  #define LBAL_LIBCPP23_BYTESWAP 0
#endif

/**
  @def LBAL_LIBCPP23_COMMON_REFERENCE
  @brief common_reference_t of reference_wrapper Should Be a Reference Type
  @details SD-6 equivalent: `__cpp_lib_common_reference >= 202302L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202302L` [P2655R3](https://wg21.link/P2655R3) `common_reference_t` of
  `reference_wrapper` Should Be a Reference Type

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP23_COMMON_REFERENCE
  #define LBAL_LIBCPP23_COMMON_REFERENCE 0
#endif

/**
  @def LBAL_LIBCPP23_COMMON_REFERENCE_WRAPPER
  @brief common_reference_t of reference_wrapper Should Be a Reference Type
  @details SD-6 equivalent: `__cpp_lib_common_reference_wrapper >= 202302L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202302L` [P2655R3](https://wg21.link/P2655R3) `common_reference_t` of
  `reference_wrapper` Should Be a Reference Type

  @sa `freestanding` `<functional>`
*/
#ifndef LBAL_LIBCPP23_COMMON_REFERENCE_WRAPPER
  #define LBAL_LIBCPP23_COMMON_REFERENCE_WRAPPER 0
#endif

/**
  @def LBAL_LIBCPP23_CONCEPTS_MOVE_ONLY
  @brief Add move-only types for `equality_comparable_with`,
  `totally_ordered_with`, and `three_way_comparable_with`
  @details SD-6 equivalent: `__cpp_lib_concepts >= 202207L`. Note that
  `__cpp_lib_concepts` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P2404R3](https://wg21.link/P2404R3) **PDF** Move-only types for
  equality_comparable_with, totally_ordered_with, and three_way_comparable_with

  @sa `<compare>` `<concepts>` `freestanding`
*/
#ifndef LBAL_LIBCPP23_CONCEPTS_MOVE_ONLY
  #define LBAL_LIBCPP23_CONCEPTS_MOVE_ONLY 0
#endif

/**
  @def LBAL_LIBCPP23_CONSTEXPR_BITSET
  @brief A more constexpr bitset
  @details SD-6 equivalent: `__cpp_lib_constexpr_bitset >= 202207L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202207L` [P2417R2](https://wg21.link/P2417R2) **PDF** A more constexpr
  bitset

  @sa `<bitset>`
*/
#ifndef LBAL_LIBCPP23_CONSTEXPR_BITSET
  #define LBAL_LIBCPP23_CONSTEXPR_BITSET 0
#endif

/**
  @def LBAL_LIBCPP23_CONSTEXPR_CHARCONV
  @brief Add Constexpr Modifiers to Functions to_chars and from_chars for
  Integral Types in Header
  @details SD-6 equivalent: `__cpp_lib_constexpr_charconv >= 202207L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202207L` [P2291R3](https://wg21.link/P2291R3) **PDF** Add Constexpr
  Modifiers to Functions to_chars and from_chars for Integral Types in Header

  @sa `<charconv>` `freestanding`
*/
#ifndef LBAL_LIBCPP23_CONSTEXPR_CHARCONV
  #define LBAL_LIBCPP23_CONSTEXPR_CHARCONV 0
#endif

/**
  @def LBAL_LIBCPP23_CONSTEXPR_CMATH
  @brief constexpr for cmath and cstdlib
  @details SD-6 equivalent: `__cpp_lib_constexpr_cmath >= 202202L`. Note that
  `__cpp_lib_constexpr_cmath` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202202L` [P0533R9](https://wg21.link/P0533R9) **PDF** `constexpr` for
  `<cmath>` and `<cstdlib>`

  @sa `<cmath>` `<cstdlib>`
*/
#ifndef LBAL_LIBCPP23_CONSTEXPR_CMATH
  #define LBAL_LIBCPP23_CONSTEXPR_CMATH 0
#endif

/**
  @def LBAL_LIBCPP23_CONSTEXPR_MEMORY_UNIQUE_PTR
  @brief Make `std::unique_ptr` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_memory >= 202202L`. Note that
  `__cpp_lib_constexpr_memory` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202202L` [P2273R3](https://wg21.link/P2273R3) **PDF** Making
  `std::unique_ptr` constexpr

  @sa `freestanding` `<memory>`
*/
#ifndef LBAL_LIBCPP23_CONSTEXPR_MEMORY_UNIQUE_PTR
  #define LBAL_LIBCPP23_CONSTEXPR_MEMORY_UNIQUE_PTR 0
#endif

/**
  @def LBAL_LIBCPP23_CONSTEXPR_TYPEINFO
  @brief Making std::type_info::operator== constexpr
  @details SD-6 equivalent: `__cpp_lib_constexpr_typeinfo >= 202106L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202106L` [P1328R1](https://wg21.link/P1328R1) Making
  `std::type_info::operator==` `constexpr`

  @sa `freestanding` `<typeinfo>`
*/
#ifndef LBAL_LIBCPP23_CONSTEXPR_TYPEINFO
  #define LBAL_LIBCPP23_CONSTEXPR_TYPEINFO 0
#endif

/**
  @def LBAL_LIBCPP23_CONTAINERS_RANGES
  @brief Conversions from ranges to containers
  @details SD-6 equivalent: `__cpp_lib_containers_ranges >= 202202L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202202L` [P1206R7](https://wg21.link/P1206R7) **PDF** Conversions from
  ranges to containers

  @sa `<deque>` `<forward_list>` `<list>` `<map>` `<queue>` `<set>` `<stack>`
  `<string>` `<unordered_map>` `<unordered_set>` `<vector>`
*/
#ifndef LBAL_LIBCPP23_CONTAINERS_RANGES
  #define LBAL_LIBCPP23_CONTAINERS_RANGES 0
#endif

/**
  @def LBAL_LIBCPP23_EXPECTED
  @brief std::expected
  @details SD-6 equivalent: `__cpp_lib_expected >= 202202L`. Note that
  `__cpp_lib_expected` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202202L` [P0323R12](https://wg21.link/P0323R12) std::expected

  @sa `<expected>`
*/
#ifndef LBAL_LIBCPP23_EXPECTED
  #define LBAL_LIBCPP23_EXPECTED 0
#endif

/**
  @def LBAL_LIBCPP23_EXPECTED_MONADIC
  @brief Monadic Functions for std::expected
  @details SD-6 equivalent: `__cpp_lib_expected >= 202211L`. Note that
  `__cpp_lib_expected` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202211L` [P2505R5](https://wg21.link/P2505R5) Monadic Functions for
  `std::expected`

  @sa `<expected>`
*/
#ifndef LBAL_LIBCPP23_EXPECTED_MONADIC
  #define LBAL_LIBCPP23_EXPECTED_MONADIC 0
#endif

/**
  @def LBAL_LIBCPP23_FLAT_MAP
  @brief A Standard flat_map
  @details SD-6 equivalent: `__cpp_lib_flat_map >= 202207L`. Note that
  `__cpp_lib_flat_map` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P0429R9](https://wg21.link/P0429R9) **PDF** A Standard `flat_map`

  @sa `<flat_map>`
*/
#ifndef LBAL_LIBCPP23_FLAT_MAP
  #define LBAL_LIBCPP23_FLAT_MAP 0
#endif

/**
  @def LBAL_LIBCPP23_FLAT_SET
  @brief A Standard flat_set
  @details SD-6 equivalent: `__cpp_lib_flat_set >= 202207L`. Note that
  `__cpp_lib_flat_set` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202207L` [LWG3751](https://wg21.link/LWG3751) Missing feature macro for
  `flat_set`
  - `202207L` [P1222R4](https://wg21.link/P1222R4) **PDF** A Standard `flat_set`

  @sa `<flat_set>`
*/
#ifndef LBAL_LIBCPP23_FLAT_SET
  #define LBAL_LIBCPP23_FLAT_SET 0
#endif

/**
  @def LBAL_LIBCPP23_FORMAT
  @brief Add `std::format` improvements
  @details SD-6 equivalent: `__cpp_lib_format >= 202106L`. Note that
  `__cpp_lib_format` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202106L` [P2216R3](https://wg21.link/P2216R3) std::format improvements

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP23_FORMAT
  #define LBAL_LIBCPP23_FORMAT 0
#endif

/**
  @def LBAL_LIBCPP23_FORMATTERS
  @brief Formatting thread::id and stacktrace
  @details SD-6 equivalent: `__cpp_lib_formatters >= 202302L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202302L` [P2693R1](https://wg21.link/P2693R1) **PDF** Formatting
  `thread::id` and `stacktrace`

  @sa `<stacktrace>` `<thread>`
*/
#ifndef LBAL_LIBCPP23_FORMATTERS
  #define LBAL_LIBCPP23_FORMATTERS 0
#endif

/**
  @def LBAL_LIBCPP23_FORMATTERS_THREAD_ID
  @brief Formatting thread::id

  @remark This token is a proxy indicating support for the `std::thread::id`
  portion of `__cpp_lib_formatters`, unlike `LBAL_LIBCPP23_FORMATTERS` which
  indicates support for both that and `std::stacktrace`.
*/
#ifndef LBAL_LIBCPP23_FORMATTERS_THREAD_ID
  #define LBAL_LIBCPP23_FORMATTERS_THREAD_ID 0
#endif

/**
  @def LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING
  @brief Exposing `std::basic_format_string`
  @details SD-6 equivalent: `__cpp_lib_format >= 202207L`. Note that
  `__cpp_lib_format` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P2508R1](https://wg21.link/P2508R1) Exposing
  std::basic-format-string

  @remark This and `LBAL_LIBCPP23_FORMAT_ENCODINGS` were voted in at the same
  time and share the same SD-6 token and value; however, we track them as
  separate features.

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING
  #define LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING 0
#endif

/**
  @def LBAL_LIBCPP23_FORMAT_ENCODINGS
  @brief Clarify encoding handling in localized formatting of `<chrono>` types
  @details SD-6 equivalent: `__cpp_lib_format >= 202207L`. Note that
  `__cpp_lib_format` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P2419R2](https://wg21.link/P2419R2) Clarify handling of encodings
  in localized formatting of chrono types

  @remark This and `LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING` were voted in at
  the same time and share the same SD-6 token and value; however, we track them
  as separate features.

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP23_FORMAT_ENCODINGS
  #define LBAL_LIBCPP23_FORMAT_ENCODINGS 0
#endif

/**
  @def LBAL_LIBCPP23_FORMAT_GENERATOR
  @brief Add support for `std::generator`-like types to `std::format`
  @details SD-6 equivalent: `__cpp_lib_format >= 202110L`. Note that
  `__cpp_lib_format` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202110L` [P2418R2](https://wg21.link/P2418R2) Add support for
  `std::generator`-like types to `std::format`

  @remark This and `LBAL_LIBCPP23_FORMAT_LOCALE` were voted in at the same time
  and share the same SD-6 token and value; however, we track them as separate
  features.

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP23_FORMAT_GENERATOR
  #define LBAL_LIBCPP23_FORMAT_GENERATOR 0
#endif

/**
  @def LBAL_LIBCPP23_FORMAT_LOCALE
  @brief Fix locale handling in `std::chrono` formatters
  @details SD-6 equivalent: `__cpp_lib_format >= 202110L`. Note that
  `__cpp_lib_format` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202110L` [P2372R3](https://wg21.link/P2372R3) Fixing locale handling in
  chrono formatters

  @remark This and `LBAL_LIBCPP23_FORMAT_GENERATOR` were voted in at the same
  time and share the same SD-6 token and value; however, we track them as
  separate features.

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP23_FORMAT_LOCALE
  #define LBAL_LIBCPP23_FORMAT_LOCALE 0
#endif

/**
  @def LBAL_LIBCPP23_FORMAT_RANGES
  @brief Formatting Ranges
  @details SD-6 equivalent: `__cpp_lib_format_ranges >= 202207L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202207L` [LWG3750](https://wg21.link/LWG3750) Too many papers bump
  `__cpp_lib_format`
  - `202207L` [P2286R8](https://wg21.link/P2286R8) Formatting Ranges
  - `202207L` [P2585R1](https://wg21.link/P2585R1) Improving default container
  formatting

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP23_FORMAT_RANGES
  #define LBAL_LIBCPP23_FORMAT_RANGES 0
#endif

/**
  @def LBAL_LIBCPP23_FORWARD_LIKE
  @brief forward_like
  @details SD-6 equivalent: `__cpp_lib_forward_like >= 202207L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202207L` [P2445R1](https://wg21.link/P2445R1) **PDF** forward_like

  @sa `freestanding` `<utility>`
*/
#ifndef LBAL_LIBCPP23_FORWARD_LIKE
  #define LBAL_LIBCPP23_FORWARD_LIKE 0
#endif

/**
  @def LBAL_LIBCPP23_GENERATOR
  @brief std::generator: Synchronous Coroutine Generator for Ranges
  @details SD-6 equivalent: `__cpp_lib_generator >= 202207L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202207L` [P2502R2](https://wg21.link/P2502R2) **PDF** `std::generator`:
  Synchronous Coroutine Generator for Ranges

  @sa `<generator>`
*/
#ifndef LBAL_LIBCPP23_GENERATOR
  #define LBAL_LIBCPP23_GENERATOR 0
#endif

/**
  @def LBAL_LIBCPP23_INVOKE_R
  @brief invoke_r
  @details SD-6 equivalent: `__cpp_lib_invoke_r >= 202106L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202106L` [P2136R3](https://wg21.link/P2136R3) `invoke_r`

  @sa `freestanding` `<functional>`
*/
#ifndef LBAL_LIBCPP23_INVOKE_R
  #define LBAL_LIBCPP23_INVOKE_R 0
#endif

/**
  @def LBAL_LIBCPP23_IOS_NOREPLACE
  @brief Support exclusive mode for fstreams
  @details SD-6 equivalent: `__cpp_lib_ios_noreplace >= 202207L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202207L` [P2467R1](https://wg21.link/P2467R1) Support exclusive mode for
  fstreams

  @sa `<ios>`
*/
#ifndef LBAL_LIBCPP23_IOS_NOREPLACE
  #define LBAL_LIBCPP23_IOS_NOREPLACE 0
#endif

/**
  @def LBAL_LIBCPP23_IS_IMPLICIT_LIFETIME
  @brief A trait for implicit lifetime types
  @details SD-6 equivalent: `__cpp_lib_is_implicit_lifetime >= 202302L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202302L` [P2674R1](https://wg21.link/P2674R1) **PDF** A trait for implicit
  lifetime types

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP23_IS_IMPLICIT_LIFETIME
  #define LBAL_LIBCPP23_IS_IMPLICIT_LIFETIME 0
#endif

/**
  @def LBAL_LIBCPP23_IS_SCOPED_ENUM
  @brief A proposal for a type trait to detect scoped enumerations
  @details SD-6 equivalent: `__cpp_lib_is_scoped_enum >= 202011L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202011L` [P1048R1](https://wg21.link/P1048R1) **PDF** A proposal for a type
  trait to detect scoped enumerations

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP23_IS_SCOPED_ENUM
  #define LBAL_LIBCPP23_IS_SCOPED_ENUM 0
#endif

/**
  @def LBAL_LIBCPP23_MDSPAN
  @brief `mdspan`
  @details SD-6 equivalent: `__cpp_lib_mdspan >= 202207L`. Note that
  `__cpp_lib_mdspan` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P0009R18](https://wg21.link/P0009R18) `MDSPAN`
  - `202207L` [P2599R2](https://wg21.link/P2599R2) **PDF** index _type &
  size_type in mdspan
  - `202207L` [P2604R0](https://wg21.link/P2604R0) MDSPAN: rename pointer and
  contiguous
  - `202207L` [P2613R1](https://wg21.link/P2613R1) Add the missing `empty` to
  `mdspan`

  @sa `freestanding` `<mdspan>`
*/
#ifndef LBAL_LIBCPP23_MDSPAN
  #define LBAL_LIBCPP23_MDSPAN 0
#endif

/**
  @def LBAL_LIBCPP23_MODULES
  @brief Standard Library Modules std and std.compat
  @details SD-6 equivalent: `__cpp_lib_modules >= 202207L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `202207L` [P2465R3](https://wg21.link/P2465R3) **PDF** Standard Library
  Modules `std` and `std.compat`

  @sa `freestanding`
*/
#ifndef LBAL_LIBCPP23_MODULES
  #define LBAL_LIBCPP23_MODULES 0
#endif

/**
  @def LBAL_LIBCPP23_MOVE_ITERATOR_CONCEPT
  @brief move_iterator should be a random access iterator
  @details SD-6 equivalent: `__cpp_lib_move_iterator_concept >= 202207L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202207L` [P2520R0](https://wg21.link/P2520R0) move_iterator should be a
  random access iterator

  @sa `freestanding` `<iterator>`
*/
#ifndef LBAL_LIBCPP23_MOVE_ITERATOR_CONCEPT
  #define LBAL_LIBCPP23_MOVE_ITERATOR_CONCEPT 0
#endif

/**
  @def LBAL_LIBCPP23_MOVE_ONLY_FUNCTION
  @brief move_only_function (was any_invocable)
  @details SD-6 equivalent: `__cpp_lib_move_only_function >= 202110L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202110L` [P0288R9](https://wg21.link/P0288R9) move_only_function (was
  any_invocable)

  @sa `<functional>`
*/
#ifndef LBAL_LIBCPP23_MOVE_ONLY_FUNCTION
  #define LBAL_LIBCPP23_MOVE_ONLY_FUNCTION 0
#endif

/**
  @def LBAL_LIBCPP23_OPTIONAL_CONSTEXPR
  @brief Add further `constexpr` support for `std::optional`
  @details SD-6 equivalent: `__cpp_lib_optional >= 202106L`. Note that
  `__cpp_lib_optional` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202106L` [P2231R1](https://wg21.link/P2231R1) Add further constexpr support
  for optional/variant

  @sa `<optional>`
*/
#ifndef LBAL_LIBCPP23_OPTIONAL_CONSTEXPR
  #define LBAL_LIBCPP23_OPTIONAL_CONSTEXPR 0
#endif

/**
  @def LBAL_LIBCPP23_OPTIONAL_MONADIC
  @brief Add monadic operations for `std::optional`
  @details SD-6 equivalent: `__cpp_lib_optional >= 202110L`. Note that
  `__cpp_lib_optional` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202110L` [LWG3621](https://wg21.link/LWG3621) Remove feature-test macro
  `__cpp_lib_monadic_optional`
  - `202110L` [P0798R8](https://wg21.link/P0798R8) Monadic operations for
  std::optional

  @remark Note that this is mostly about [`p0798r8`](https://wg21.link/p0798r8);
  [`lwg3621`](https://wg21.link/lwg3621) was an SD-6 administrative fixup for an
  oversight in the approval process for `p0798r8`.

  @sa `<optional>`
*/
#ifndef LBAL_LIBCPP23_OPTIONAL_MONADIC
  #define LBAL_LIBCPP23_OPTIONAL_MONADIC 0
#endif

/**
  @def LBAL_LIBCPP23_OUT_PTR
  @brief out_ptr - a scalable output pointer abstraction
  @details SD-6 equivalent: `__cpp_lib_out_ptr >= 202106L`. Note that
  `__cpp_lib_out_ptr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202106L` [P1132R8](https://wg21.link/P1132R8) out_ptr - a scalable output
  pointer abstraction

  @sa `freestanding` `<memory>`
*/
#ifndef LBAL_LIBCPP23_OUT_PTR
  #define LBAL_LIBCPP23_OUT_PTR 0
#endif

/**
  @def LBAL_LIBCPP23_PRINT
  @brief Formatted output
  @details SD-6 equivalent: `__cpp_lib_print >= 202207L`. Note that
  `__cpp_lib_print` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P2093R14](https://wg21.link/P2093R14) Formatted output

  @sa `<ostream>` `<print>`
*/
#ifndef LBAL_LIBCPP23_PRINT
  #define LBAL_LIBCPP23_PRINT 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_AS_CONST
  @brief cbegin should always return a constant iterator
  @details SD-6 equivalent: `__cpp_lib_ranges_as_const >= 202207L`. Note that
  `__cpp_lib_ranges_as_const` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P2278R4](https://wg21.link/P2278R4) `cbegin` should always return
  a constant iterator

  @sa `freestanding` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_AS_CONST
  #define LBAL_LIBCPP23_RANGES_AS_CONST 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_AS_RVALUE
  @brief views::as_rvalue
  @details SD-6 equivalent: `__cpp_lib_ranges_as_rvalue >= 202207L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202207L` [P2446R2](https://wg21.link/P2446R2) `views::as_rvalue`

  @sa `freestanding` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_AS_RVALUE
  #define LBAL_LIBCPP23_RANGES_AS_RVALUE 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT
  @brief views::cartesian_product
  @details SD-6 equivalent: `__cpp_lib_ranges_cartesian_product >= 202207L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202207L` [P2374R4](https://wg21.link/P2374R4) `views::cartesian_product`

  @sa `freestanding` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT
  #define LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT_EMPTY
  @brief Empty Product for certain Views
  @details SD-6 equivalent: `__cpp_lib_ranges_cartesian_product >= 202207L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202207L` [P2540R1](https://wg21.link/P2540R1) Empty Product for certain
  Views

  @sa `freestanding` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT_EMPTY
  #define LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT_EMPTY 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_CHUNK
  @brief Windowing range adaptors: views::chunk and views::slide
  @details SD-6 equivalent: `__cpp_lib_ranges_chunk >= 202202L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202202L` [P2442R1](https://wg21.link/P2442R1) Windowing range adaptors:
  `views::chunk` and `views::slide`

  @sa `freestanding` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_CHUNK
  #define LBAL_LIBCPP23_RANGES_CHUNK 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_CHUNK_BY
  @brief views::chunk_by
  @details SD-6 equivalent: `__cpp_lib_ranges_chunk_by >= 202202L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202202L` [P2443R1](https://wg21.link/P2443R1) `views::chunk_by`

  @sa `freestanding` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_CHUNK_BY
  #define LBAL_LIBCPP23_RANGES_CHUNK_BY 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_CONTAINS
  @brief std::ranges::contains
  @details SD-6 equivalent: `__cpp_lib_ranges_contains >= 202207L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202207L` [P2302R4](https://wg21.link/P2302R4) `std::ranges::contains`

  @sa `<algorithm>` `freestanding`
*/
#ifndef LBAL_LIBCPP23_RANGES_CONTAINS
  #define LBAL_LIBCPP23_RANGES_CONTAINS 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_ENUMERATE
  @brief views::enumerate
  @details SD-6 equivalent: `__cpp_lib_ranges_enumerate >= 202302L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202302L` [P2164R9](https://wg21.link/P2164R9) **PDF** `views::enumerate`

  @sa `freestanding` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_ENUMERATE
  #define LBAL_LIBCPP23_RANGES_ENUMERATE 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_FIND_LAST
  @brief find_last
  @details SD-6 equivalent: `__cpp_lib_ranges_find_last >= 202207L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202207L` [LWG3807](https://wg21.link/LWG3807) The feature test macro for
  `ranges::find_last` should be renamed
  - `202207L` [P1223R5](https://wg21.link/P1223R5) **PDF** `find_last`

  @sa `<algorithm>` `freestanding`
*/
#ifndef LBAL_LIBCPP23_RANGES_FIND_LAST
  #define LBAL_LIBCPP23_RANGES_FIND_LAST 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_FOLD
  @brief ranges::fold
  @details SD-6 equivalent: `__cpp_lib_ranges_fold >= 202207L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202207L` [P2322R6](https://wg21.link/P2322R6) `ranges::fold`

  @sa `<algorithm>` `freestanding`
*/
#ifndef LBAL_LIBCPP23_RANGES_FOLD
  #define LBAL_LIBCPP23_RANGES_FOLD 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_FORMALIZED_VIEW
  @brief What is a view?
  @details SD-6 equivalent: `__cpp_lib_ranges >= 202110L`. Note that
  `__cpp_lib_ranges` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202110L` [P2415R2](https://wg21.link/P2415R2) What is a `view`?

  @sa `<algorithm>` `<functional>` `<iterator>` `<memory>` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_FORMALIZED_VIEW
  #define LBAL_LIBCPP23_RANGES_FORMALIZED_VIEW 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_IOTA
  @brief ranges::iota, ranges::shift_left, and ranges::shift_right
  @details SD-6 equivalent: `__cpp_lib_ranges_iota >= 202202L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202202L` [P2440R1](https://wg21.link/P2440R1) `ranges::iota`,
  `ranges::shift_left`, and `ranges::shift_right`

  @sa `freestanding` `<numeric>`
*/
#ifndef LBAL_LIBCPP23_RANGES_IOTA
  #define LBAL_LIBCPP23_RANGES_IOTA 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_JOIN_WITH
  @brief views::join_with
  @details SD-6 equivalent: `__cpp_lib_ranges_join_with >= 202202L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202202L` [P2441R2](https://wg21.link/P2441R2) `views::join_with`

  @sa `freestanding` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_JOIN_WITH
  #define LBAL_LIBCPP23_RANGES_JOIN_WITH 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_NON_DEFAULT_CONSTRUCTIBLE
  @brief Views should not be required to be default constructible
  @details SD-6 equivalent: `__cpp_lib_ranges >= 202106L`. Note that
  `__cpp_lib_ranges` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202106L` [P2325R3](https://wg21.link/P2325R3) Views should not be required
  to be default constructible

  @sa `<algorithm>` `<functional>` `<iterator>` `<memory>` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_NON_DEFAULT_CONSTRUCTIBLE
  #define LBAL_LIBCPP23_RANGES_NON_DEFAULT_CONSTRUCTIBLE 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_RELAXED
  @brief Relaxing Ranges Just A Smidge
  @details SD-6 equivalent: `__cpp_lib_ranges >= 202302L`. Note that
  `__cpp_lib_ranges` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202302L` [P2609R3](https://wg21.link/P2609R3) Relaxing Ranges Just A Smidge

  @sa `<algorithm>` `<functional>` `<iterator>` `<memory>` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_RELAXED
  #define LBAL_LIBCPP23_RANGES_RELAXED 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_REMOVE_POISON_PILLS
  @brief Poison Pills are Too Toxic
  @details SD-6 equivalent: `__cpp_lib_ranges >= 202211L`. Note that
  `__cpp_lib_ranges` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202211L` [P2602R2](https://wg21.link/P2602R2) Poison Pills are Too Toxic

  @sa `<algorithm>` `<functional>` `<iterator>` `<memory>` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_REMOVE_POISON_PILLS
  #define LBAL_LIBCPP23_RANGES_REMOVE_POISON_PILLS 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_REPEAT
  @brief views::repeat
  @details SD-6 equivalent: `__cpp_lib_ranges_repeat >= 202207L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202207L` [P2474R2](https://wg21.link/P2474R2) `views::repeat`

  @sa `freestanding` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_REPEAT
  #define LBAL_LIBCPP23_RANGES_REPEAT 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_SLIDE
  @brief Windowing range adaptors: views::chunk and views::slide
  @details SD-6 equivalent: `__cpp_lib_ranges_slide >= 202202L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202202L` [P2442R1](https://wg21.link/P2442R1) Windowing range adaptors:
  `views::chunk` and `views::slide`

  @sa `freestanding` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_SLIDE
  #define LBAL_LIBCPP23_RANGES_SLIDE 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_STARTS_ENDS_WITH
  @brief starts_with and ends_with
  @details SD-6 equivalent: `__cpp_lib_ranges_starts_ends_with >= 202106L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202106L` [P1659R3](https://wg21.link/P1659R3) starts_with and ends_with

  @sa `<algorithm>` `freestanding`
*/
#ifndef LBAL_LIBCPP23_RANGES_STARTS_ENDS_WITH
  #define LBAL_LIBCPP23_RANGES_STARTS_ENDS_WITH 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_STRIDE
  @brief stride_view
  @details SD-6 equivalent: `__cpp_lib_ranges_stride >= 202207L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202207L` [P1899R3](https://wg21.link/P1899R3) `stride_view`

  @sa `freestanding` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_STRIDE
  #define LBAL_LIBCPP23_RANGES_STRIDE 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_SUPPORT_MOVE_ONLY_TYPES
  @brief Relaxing range adaptors to allow for move only types
  @details SD-6 equivalent: `__cpp_lib_ranges >= 202207L`. Note that
  `__cpp_lib_ranges` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P2494R2](https://wg21.link/P2494R2) Relaxing range adaptors to
  allow for move only types

  @sa `<algorithm>` `<functional>` `<iterator>` `<memory>` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_SUPPORT_MOVE_ONLY_TYPES
  #define LBAL_LIBCPP23_RANGES_SUPPORT_MOVE_ONLY_TYPES 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_TO_CONTAINER
  @brief Conversions from ranges to containers
  @details SD-6 equivalent: `__cpp_lib_ranges_to_container >= 202202L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202202L` [P1206R7](https://wg21.link/P1206R7) **PDF** Conversions from
  ranges to containers

  @sa `freestanding` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_TO_CONTAINER
  #define LBAL_LIBCPP23_RANGES_TO_CONTAINER 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_USER_ADAPTOR_PIPES
  @brief Pipe support for user-defined range adaptors
  @details SD-6 equivalent: `__cpp_lib_ranges >= 202202L`. Note that
  `__cpp_lib_ranges` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202202L` [P2387R3](https://wg21.link/P2387R3) Pipe support for user-defined
  range adaptors

  @sa `<algorithm>` `<functional>` `<iterator>` `<memory>` `<ranges>`
*/
#ifndef LBAL_LIBCPP23_RANGES_USER_ADAPTOR_PIPES
  #define LBAL_LIBCPP23_RANGES_USER_ADAPTOR_PIPES 0
#endif

/**
  @def LBAL_LIBCPP23_RANGES_ZIP
  @brief zip
  @details SD-6 equivalent: `__cpp_lib_ranges_zip >= 202110L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202110L` [P2321R2](https://wg21.link/P2321R2) `zip`

  @sa `freestanding` `<ranges>` `<tuple>` `<utility>`
*/
#ifndef LBAL_LIBCPP23_RANGES_ZIP
  #define LBAL_LIBCPP23_RANGES_ZIP 0
#endif

/**
  @def LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY
  @brief A type trait to detect reference binding to temporary
  @details SD-6 equivalent: `__cpp_lib_reference_from_temporary >= 202202L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202202L` [P2255R2](https://wg21.link/P2255R2) A type trait to detect
  reference binding to temporary

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY
  #define LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY 0
#endif

/**
  @def LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY_TRAITS
  @brief Just the type traits implementation part of
  `__cpp_lib_reference_from_temporary`
  @details SD-6 equivalent: `__cpp_lib_reference_from_temporary >= 202202L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202202L` [P2255R2](https://wg21.link/P2255R2) A type trait to detect
  reference binding to temporary

  @remark This token is a proxy indicating partial support for
  `__cpp_lib_reference_from_temporary`; it reflects a state where a given
  Standard Library implementation claims to have full support, but may not
  actually have it.

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY_TRAITS
  #define LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY_TRAITS 0
#endif

/**
  @def LBAL_LIBCPP23_SHIFT_RANGES
  @brief ranges::iota, ranges::shift_left, and ranges::shift_right
  @details SD-6 equivalent: `__cpp_lib_shift >= 202202L`. Note that
  `__cpp_lib_shift` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202202L` [P2440R1](https://wg21.link/P2440R1) `ranges::iota`,
  `ranges::shift_left`, and `ranges::shift_right`

  @sa `<algorithm>`
*/
#ifndef LBAL_LIBCPP23_SHIFT_RANGES
  #define LBAL_LIBCPP23_SHIFT_RANGES 0
#endif

/**
  @def LBAL_LIBCPP23_SPANSTREAM
  @brief A strstream replacement using span as buffer
  @details SD-6 equivalent: `__cpp_lib_spanstream >= 202106L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202106L` [P0448R4](https://wg21.link/P0448R4) **PDF** A strstream
  replacement using span as buffer

  @sa `<iosfwd>` `<spanstream>`
*/
#ifndef LBAL_LIBCPP23_SPANSTREAM
  #define LBAL_LIBCPP23_SPANSTREAM 0
#endif

/**
  @def LBAL_LIBCPP23_STACKTRACE
  @brief A Proposal to add stacktrace library
  @details SD-6 equivalent: `__cpp_lib_stacktrace >= 202011L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202011L` [P0881R7](https://wg21.link/P0881R7) A Proposal to add stacktrace
  library

  @sa `<stacktrace>`
*/
#ifndef LBAL_LIBCPP23_STACKTRACE
  #define LBAL_LIBCPP23_STACKTRACE 0
#endif

/**
  @def LBAL_LIBCPP23_START_LIFETIME_AS
  @brief Explicit lifetime management
  @details SD-6 equivalent: `__cpp_lib_start_lifetime_as >= 202207L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202207L` [P2590R2](https://wg21.link/P2590R2) **PDF** Explicit lifetime
  management

  @sa `freestanding` `<memory>`
*/
#ifndef LBAL_LIBCPP23_START_LIFETIME_AS
  #define LBAL_LIBCPP23_START_LIFETIME_AS 0
#endif

/**
  @def LBAL_LIBCPP23_STDATOMIC_H
  @brief Support C atomics in C++
  @details SD-6 equivalent: `__cpp_lib_stdatomic_h >= 202011L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202011L` [P0943R6](https://wg21.link/P0943R6) Support C atomics in C++

  @sa `<stdatomic.h>`
*/
#ifndef LBAL_LIBCPP23_STDATOMIC_H
  #define LBAL_LIBCPP23_STDATOMIC_H 0
#endif

/**
  @def LBAL_LIBCPP23_STRING_CONTAINS
  @brief String Contains function
  @details SD-6 equivalent: `__cpp_lib_string_contains >= 202011L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202011L` [P1679R3](https://wg21.link/P1679R3) String Contains function

  @sa `<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP23_STRING_CONTAINS
  #define LBAL_LIBCPP23_STRING_CONTAINS 0
#endif

/**
  @def LBAL_LIBCPP23_STRING_RESIZE_AND_OVERWRITE
  @brief basic_string::resize_and_overwrite
  @details SD-6 equivalent: `__cpp_lib_string_resize_and_overwrite >= 202110L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202110L` [P1072R10](https://wg21.link/P1072R10)
  basic_string::resize_and_overwrite

  @sa `<string>`
*/
#ifndef LBAL_LIBCPP23_STRING_RESIZE_AND_OVERWRITE
  #define LBAL_LIBCPP23_STRING_RESIZE_AND_OVERWRITE 0
#endif

/**
  @def LBAL_LIBCPP23_TO_UNDERLYING
  @brief std::to_underlying
  @details SD-6 equivalent: `__cpp_lib_to_underlying >= 202102L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202102L` [P1682R3](https://wg21.link/P1682R3) std::to_underlying for
  enumerations

  @sa `freestanding` `<utility>`
*/
#ifndef LBAL_LIBCPP23_TO_UNDERLYING
  #define LBAL_LIBCPP23_TO_UNDERLYING 0
#endif

/**
  @def LBAL_LIBCPP23_TUPLE_LIKE
  @brief Compatibility between tuple, pair and tuple-like objects
  @details SD-6 equivalent: `__cpp_lib_tuple_like >= 202207L`. Note that
  `__cpp_lib_tuple_like` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P2165R4](https://wg21.link/P2165R4) **PDF** Compatibility between
  `tuple`, `pair` and tuple-like objects

  @sa `<map>` `<tuple>` `<unordered_map>` `<utility>`
*/
#ifndef LBAL_LIBCPP23_TUPLE_LIKE
  #define LBAL_LIBCPP23_TUPLE_LIKE 0
#endif

/**
  @def LBAL_LIBCPP23_UNREACHABLE
  @brief Function to mark unreachable code
  @details SD-6 equivalent: `__cpp_lib_unreachable >= 202202L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202202L` [P0627R6](https://wg21.link/P0627R6) **PDF** Function to mark
  unreachable code

  @sa `freestanding` `<utility>`
*/
#ifndef LBAL_LIBCPP23_UNREACHABLE
  #define LBAL_LIBCPP23_UNREACHABLE 0
#endif

/**
  @def LBAL_LIBCPP23_VARIANT_CONSTEXPR
  @brief Add further `constexpr` support for `std::variant`
  @details SD-6 equivalent: `__cpp_lib_variant >= 202106L`. Note that
  `__cpp_lib_variant` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202106L` [P2231R1](https://wg21.link/P2231R1) Add further constexpr support
  for optional/variant

  @sa `<variant>`
*/
#ifndef LBAL_LIBCPP23_VARIANT_CONSTEXPR
  #define LBAL_LIBCPP23_VARIANT_CONSTEXPR 0
#endif

/**
  @def LBAL_LIBCPP23_VARIANT_INHERITANCE
  @brief Address inheriting from `std::variant`
  @details SD-6 equivalent: `__cpp_lib_variant >= 202102L`. Note that
  `__cpp_lib_variant` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202102L` [P2162R2](https://wg21.link/P2162R2) Inheriting from std::variant
  (resolving LWG3052)

  @sa `<variant>`
*/
#ifndef LBAL_LIBCPP23_VARIANT_INHERITANCE
  #define LBAL_LIBCPP23_VARIANT_INHERITANCE 0
#endif

///	@}	LBAL_LIBCPP23

///	@}	lbal_library
