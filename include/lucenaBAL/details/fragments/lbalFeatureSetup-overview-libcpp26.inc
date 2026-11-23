/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFeatureSetup-overview-libcpp26.inc”
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
  @name LBAL_LIBCPP26

  @brief These are all taken from features that have been incorporated into
  the C++26 Standard.

  @{
*/

/**
  @def LBAL_LIBCPP26_ALGORITHM_DEFAULT_VALUE_TYPE
  @brief Adjoints to 'Enabling list-initialization for algorithms': `find_last`
  and `uninitialized_fill`
  @details

  SD-6 equivalent: `__cpp_lib_algorithm_default_value_type >= 202603L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202603L` [P3217R0](https://wg21.link/P3217R0) Adjoints to "Enabling
  list-initialization for algorithms": `find_last`
  - `202603L` [P3787R2](https://wg21.link/P3787R2) Adjoints to "Enabling
  list-initialization for algorithms": `uninitialized_fill`

  @sa `<algorithm>` `<deque>` `<forward_list>` `<list>` `<memory>` `<ranges>`
  `<string>` `<vector>`
*/
#ifndef LBAL_LIBCPP26_ALGORITHM_DEFAULT_VALUE_TYPE
  #define LBAL_LIBCPP26_ALGORITHM_DEFAULT_VALUE_TYPE 0
#endif

/**
  @def LBAL_LIBCPP26_ALIGNED_ACCESSOR
  @brief An `mdspan` accessor expressing pointer overalignment
  @details SD-6 equivalent: `__cpp_lib_aligned_accessor >= 202411L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202411L` [P2897R7](https://wg21.link/P2897R7) aligned_accessor: An mdspan
  accessor expressing pointer overalignment

  @sa `freestanding` `<mdspan>`
*/
#ifndef LBAL_LIBCPP26_ALIGNED_ACCESSOR
  #define LBAL_LIBCPP26_ALIGNED_ACCESSOR 0
#endif

/**
  @def LBAL_LIBCPP26_APPLY_RESULT
  @brief `std::apply` result
  @details SD-6 equivalent: `__cpp_lib_apply >= 202506L`. Note that
  `__cpp_lib_apply` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P1317R2 __PDF__](https://wg21.link/P1317R2) 3 `std::apply result`

  @sa `freestanding` `<tuple>` `<type_traits>`
*/
#ifndef LBAL_LIBCPP26_APPLY_RESULT
  #define LBAL_LIBCPP26_APPLY_RESULT 0
#endif

/**
  @def LBAL_LIBCPP26_ASSOCIATIVE_HETEROGENEOUS_INSERTION
  @brief Extending associative containers with the remaining heterogeneous
  overloads
  @details SD-6 equivalent: `__cpp_lib_associative_heterogeneous_insertion >=
  202306L`. This token will have a value of `0` if the proposal described here
  is not supported.
  - `202306L` [P2363R5](https://wg21.link/P2363R5) Extending associative
  containers with the remaining heterogeneous overloads

  @sa `<map>` `<set>` `<unordered_map>` `<unordered_set>`
*/
#ifndef LBAL_LIBCPP26_ASSOCIATIVE_HETEROGENEOUS_INSERTION
  #define LBAL_LIBCPP26_ASSOCIATIVE_HETEROGENEOUS_INSERTION 0
#endif

/**
  @def LBAL_LIBCPP26_ATOMIC_MIN_MAX
  @brief Atomic maximum/minimum
  @details SD-6 equivalent: `__cpp_lib_atomic_min_max >= 202403L`. Note that
  `__cpp_lib_atomic_min_max` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202403L` [P0493R5 __PDF__](https://wg21.link/P0493R5) Atomic
  maximum/minimum

  @sa `<atomic>` `freestanding`
*/
#ifndef LBAL_LIBCPP26_ATOMIC_MIN_MAX
  #define LBAL_LIBCPP26_ATOMIC_MIN_MAX 0
#endif

/**
  @def LBAL_LIBCPP26_ATOMIC_MIN_MAX_FLOAT
  @brief Atomic floating-point min/max
  @details SD-6 equivalent: `__cpp_lib_atomic_min_max >= 202506L`. Note that
  `__cpp_lib_atomic_min_max` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P3008R6](https://wg21.link/P3008R6) Atomic floating-point min/max

  @sa `<atomic>` `freestanding`
*/
#ifndef LBAL_LIBCPP26_ATOMIC_MIN_MAX_FLOAT
  #define LBAL_LIBCPP26_ATOMIC_MIN_MAX_FLOAT 0
#endif

/**
  @def LBAL_LIBCPP26_ATOMIC_REDUCTIONS
  @brief Atomic Reduction Operations
  @details SD-6 equivalent: `__cpp_lib_atomic_reductions >= 202506L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202506L` [P3111R8](https://wg21.link/P3111R8) Atomic Reduction Operations

  @sa `<atomic>` `freestanding`
*/
#ifndef LBAL_LIBCPP26_ATOMIC_REDUCTIONS
  #define LBAL_LIBCPP26_ATOMIC_REDUCTIONS 0
#endif

/**
  @def LBAL_LIBCPP26_ATOMIC_REF_ADDRESS
  @brief Expose `std::atomic_ref`’s object address
  @details SD-6 equivalent: `__cpp_lib_atomic_ref >= 202411L`. Note that
  `__cpp_lib_atomic_ref` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202411L` [P2835R7](https://wg21.link/P2835R7) Expose std::atomic_ref’s
  object address
  - `202603L` [P2835R7](https://wg21.link/P2835R7) Expose std::atomic_ref’s
  object address

  @sa `<atomic>` `freestanding`
*/
#ifndef LBAL_LIBCPP26_ATOMIC_REF_ADDRESS
  #define LBAL_LIBCPP26_ATOMIC_REF_ADDRESS 0
#endif

/**
  @def LBAL_LIBCPP26_ATOMIC_REF_SAFER_ADDRESS
  @brief Safer `atomic_ref::address`
  @details

  SD-6 equivalent: `__cpp_lib_atomic_ref >= 202603L`. Note that
  `__cpp_lib_atomic_ref` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202603L` [P3936R1 __PDF__](https://wg21.link/P3936R1) Safer
  `atomic_ref::address`

  @sa `<atomic>` `freestanding`
*/
#ifndef LBAL_LIBCPP26_ATOMIC_REF_SAFER_ADDRESS
  #define LBAL_LIBCPP26_ATOMIC_REF_SAFER_ADDRESS 0
#endif

/**
  @def LBAL_LIBCPP26_BIND_FRONT_NTTP_CALLABLES
  @brief Bind `front` and `back` to NTTP callables
  @details SD-6 equivalent: `__cpp_lib_bind_front >= 202306L`. Note that
  `__cpp_lib_bind_front` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P2714R1](https://wg21.link/P2714R1) Bind front and back to NTTP
  callables

  @sa `freestanding` `<functional>`
*/
#ifndef LBAL_LIBCPP26_BIND_FRONT_NTTP_CALLABLES
  #define LBAL_LIBCPP26_BIND_FRONT_NTTP_CALLABLES 0
#endif

/**
  @def LBAL_LIBCPP26_BITSET
  @brief Interfacing bitset with string_view
  @details SD-6 equivalent: `__cpp_lib_bitset >= 202306L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `202306L` [P2697R1 __PDF__](https://wg21.link/P2697R1) Interfacing bitset
  with string_view

  @sa `<bitset>`
*/
#ifndef LBAL_LIBCPP26_BITSET
  #define LBAL_LIBCPP26_BITSET 0
#endif

/**
  @def LBAL_LIBCPP26_CHRONO_HASHING
  @brief Add hashing support for `std::chrono` value classes
  @details SD-6 equivalent: `__cpp_lib_chrono >= 202306L`. Note that
  `__cpp_lib_chrono` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P2592R3](https://wg21.link/P2592R3) Hashing support for
  std::chrono value classes

  @sa `<chrono>`
*/
#ifndef LBAL_LIBCPP26_CHRONO_HASHING
  #define LBAL_LIBCPP26_CHRONO_HASHING 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTANT_WRAPPER
  @brief std::constexpr_wrapper
  @details SD-6 equivalent: `__cpp_lib_constant_wrapper >= 202506L`. Note that
  `__cpp_lib_constant_wrapper` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P2781R9](https://wg21.link/P2781R9) std::constexpr_wrapper

  @sa `freestanding` `<type_traits>` `<utility>`
*/
#ifndef LBAL_LIBCPP26_CONSTANT_WRAPPER
  #define LBAL_LIBCPP26_CONSTANT_WRAPPER 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTANT_WRAPPER_UNWRAP_ON_CALL
  @brief `constant_wrapper` should unwrap on call and subscript
  @details

  SD-6 equivalent: `__cpp_lib_constant_wrapper >= 202603L`. Note that
  `__cpp_lib_constant_wrapper` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202603L` [P3978R3 __PDF__](https://wg21.link/P3978R3) `constant_wrapper`
  should unwrap on call and subscript

  @sa `freestanding` `<type_traits>` `<utility>`
*/
#ifndef LBAL_LIBCPP26_CONSTANT_WRAPPER_UNWRAP_ON_CALL
  #define LBAL_LIBCPP26_CONSTANT_WRAPPER_UNWRAP_ON_CALL 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_ALGORITHMS_STABLE_SORT
  @brief Add `constexpr` to `std::swap` and related functions
  @details SD-6 equivalent: `__cpp_lib_constexpr_algorithms >= 202306L`. Note
  that `__cpp_lib_constexpr_algorithms` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `202306L` [P2562R1 __PDF__](https://wg21.link/P2562R1) `constexpr` Stable
  Sorting

  @sa `<algorithm>` `<utility>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_ALGORITHMS_STABLE_SORT
  #define LBAL_LIBCPP26_CONSTEXPR_ALGORITHMS_STABLE_SORT 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_ATOMIC
  @brief constexpr atomic and atomic_ref
  @details SD-6 equivalent: `__cpp_lib_constexpr_atomic >= 202411L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202411L` [P3309R3](https://wg21.link/P3309R3) constexpr atomic and
  atomic_ref

  @sa `<atomic>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_ATOMIC
  #define LBAL_LIBCPP26_CONSTEXPR_ATOMIC 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_COMPLEX
  @brief Add more `constexpr` support to `<cmath>` and `<complex>`
  @details SD-6 equivalent: `__cpp_lib_constexpr_complex >= 202306L`. Note that
  `__cpp_lib_constexpr_complex` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P1383R2 __PDF__](https://wg21.link/P1383R2) More `constexpr` for
  `<cmath>` and `<complex>`

  @sa `<complex>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_COMPLEX
  #define LBAL_LIBCPP26_CONSTEXPR_COMPLEX 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_DEQUE
  @brief constexpr containers and adapters
  @details SD-6 equivalent: `__cpp_lib_constexpr_deque >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3372R3](https://wg21.link/P3372R3) constexpr containers and
  adapters

  @sa `<deque>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_DEQUE
  #define LBAL_LIBCPP26_CONSTEXPR_DEQUE 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_EXCEPTIONS
  @brief constexpr exception types
  @details SD-6 equivalent: `__cpp_lib_constexpr_exceptions >= 202502L`. Note
  that `__cpp_lib_constexpr_exceptions` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `202502L` [P3378R2](https://wg21.link/P3378R2) constexpr exception types

  @sa `<exception>` `<expected>` `<format>` `<optional>` `<stdexcept>`
  `<variant>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_EXCEPTIONS
  #define LBAL_LIBCPP26_CONSTEXPR_EXCEPTIONS 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_FLAT_MAP
  @brief constexpr containers and adapters
  @details SD-6 equivalent: `__cpp_lib_constexpr_flat_map >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P3372R3](https://wg21.link/P3372R3) constexpr containers and
  adapters

  @sa `<flat_map>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_FLAT_MAP
  #define LBAL_LIBCPP26_CONSTEXPR_FLAT_MAP 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_FLAT_SET
  @brief constexpr containers and adapters
  @details SD-6 equivalent: `__cpp_lib_constexpr_flat_set >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P3372R3](https://wg21.link/P3372R3) constexpr containers and
  adapters

  @sa `<flat_set>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_FLAT_SET
  #define LBAL_LIBCPP26_CONSTEXPR_FLAT_SET 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_FORMAT
  @brief constexpr std::format
  @details SD-6 equivalent: `__cpp_lib_constexpr_format >= 202511L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202511L` [P3391R2](https://wg21.link/P3391R2) `constexpr std::format`

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_FORMAT
  #define LBAL_LIBCPP26_CONSTEXPR_FORMAT 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_FORWARD_LIST
  @brief constexpr containers and adapters
  @details SD-6 equivalent: `__cpp_lib_constexpr_forward_list >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P3372R3](https://wg21.link/P3372R3) constexpr containers and
  adapters

  @sa `<forward_list>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_FORWARD_LIST
  #define LBAL_LIBCPP26_CONSTEXPR_FORWARD_LIST 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_LIST
  @brief constexpr containers and adapters
  @details SD-6 equivalent: `__cpp_lib_constexpr_list >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3372R3](https://wg21.link/P3372R3) constexpr containers and
  adapters

  @sa `<list>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_LIST
  #define LBAL_LIBCPP26_CONSTEXPR_LIST 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_MAP
  @brief constexpr containers and adapters
  @details SD-6 equivalent: `__cpp_lib_constexpr_map >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3372R3](https://wg21.link/P3372R3) constexpr containers and
  adapters

  @sa `<map>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_MAP
  #define LBAL_LIBCPP26_CONSTEXPR_MAP 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_MEMORY_SHARED_PTR
  @brief Make `std::shared_ptr` and friends `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_memory >= 202506L`. Note that
  `__cpp_lib_constexpr_memory` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P3037R6 __PDF__](https://wg21.link/P3037R6) `constexpr
  std::shared_ptr` and friends

  @sa `freestanding` `<memory>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_MEMORY_SHARED_PTR
  #define LBAL_LIBCPP26_CONSTEXPR_MEMORY_SHARED_PTR 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_QUEUE
  @brief constexpr containers and adapters
  @details SD-6 equivalent: `__cpp_lib_constexpr_queue >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3372R3](https://wg21.link/P3372R3) constexpr containers and
  adapters

  @sa `<queue>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_QUEUE
  #define LBAL_LIBCPP26_CONSTEXPR_QUEUE 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_SET
  @brief constexpr containers and adapters
  @details SD-6 equivalent: `__cpp_lib_constexpr_set >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3372R3](https://wg21.link/P3372R3) constexpr containers and
  adapters

  @sa `<set>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_SET
  #define LBAL_LIBCPP26_CONSTEXPR_SET 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_STACK
  @brief constexpr containers and adapters
  @details SD-6 equivalent: `__cpp_lib_constexpr_stack >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3372R3](https://wg21.link/P3372R3) constexpr containers and
  adapters

  @sa `<stack>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_STACK
  #define LBAL_LIBCPP26_CONSTEXPR_STACK 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_UNORDERED_MAP
  @brief constexpr containers and adapters
  @details SD-6 equivalent: `__cpp_lib_constexpr_unordered_map >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P3372R3](https://wg21.link/P3372R3) constexpr containers and
  adapters

  @sa `<unordered_map>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_UNORDERED_MAP
  #define LBAL_LIBCPP26_CONSTEXPR_UNORDERED_MAP 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTEXPR_UNORDERED_SET
  @brief constexpr containers and adapters
  @details SD-6 equivalent: `__cpp_lib_constexpr_unordered_set >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P3372R3](https://wg21.link/P3372R3) constexpr containers and
  adapters

  @sa `<unordered_set>`
*/
#ifndef LBAL_LIBCPP26_CONSTEXPR_UNORDERED_SET
  #define LBAL_LIBCPP26_CONSTEXPR_UNORDERED_SET 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTRAINED_EQUALITY
  @brief Comparisons for reference_wrapper
  @details SD-6 equivalent: `__cpp_lib_constrained_equality >= 202403L`. Note
  that `__cpp_lib_constrained_equality` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `202403L` [P2944R3](https://wg21.link/P2944R3) Comparisons for
  `reference_wrapper`
  - `202411L` [P3379R0](https://wg21.link/P3379R0) Constrain std::expected
  equality operators

  @sa `<expected>` `freestanding` `<optional>` `<tuple>` `<utility>` `<variant>`
*/
#ifndef LBAL_LIBCPP26_CONSTRAINED_EQUALITY
  #define LBAL_LIBCPP26_CONSTRAINED_EQUALITY 0
#endif

/**
  @def LBAL_LIBCPP26_CONSTRAINED_EQUALITY_EXPECTED
  @brief Constrain std::expected equality operators
  @details SD-6 equivalent: `__cpp_lib_constrained_equality >= 202411L`. Note
  that `__cpp_lib_constrained_equality` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.

  @sa `<expected>` `freestanding` `<optional>` `<tuple>` `<utility>` `<variant>`
*/
#ifndef LBAL_LIBCPP26_CONSTRAINED_EQUALITY_EXPECTED
  #define LBAL_LIBCPP26_CONSTRAINED_EQUALITY_EXPECTED 0
#endif

/**
  @def LBAL_LIBCPP26_COPYABLE_FUNCTION
  @brief copyable_function
  @details SD-6 equivalent: `__cpp_lib_copyable_function >= 202306L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202306L` [P2548R6 __PDF__](https://wg21.link/P2548R6) copyable_function

  @sa `<functional>`
*/
#ifndef LBAL_LIBCPP26_COPYABLE_FUNCTION
  #define LBAL_LIBCPP26_COPYABLE_FUNCTION 0
#endif

/**
  @def LBAL_LIBCPP26_COUNTING_SCOPE
  @brief async_scope — Creating scopes for non-sequential concurrency
  @details SD-6 equivalent: `__cpp_lib_counting_scope >= 202506L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202506L` [P3149R11](https://wg21.link/P3149R11) async_scope — Creating
  scopes for non-sequential concurrency
  - `202506L` [P3815R1](https://wg21.link/P3815R1) Add `scope_association`
  concept to P3149

  @sa `<execution>`
*/
#ifndef LBAL_LIBCPP26_COUNTING_SCOPE
  #define LBAL_LIBCPP26_COUNTING_SCOPE 0
#endif

/**
  @def LBAL_LIBCPP26_DEBUGGING
  @brief Debugging Support
  @details SD-6 equivalent: `__cpp_lib_debugging >= 202311L`. Note that
  `__cpp_lib_debugging` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202311L` [P2546R5](https://wg21.link/P2546R5) Debugging Support

  @sa `<debugging>` `freestanding`
*/
#ifndef LBAL_LIBCPP26_DEBUGGING
  #define LBAL_LIBCPP26_DEBUGGING 0
#endif

/**
  @def LBAL_LIBCPP26_DEBUGGING_UTILITIES
  @brief is_debugger_present is_replaceable
  @details SD-6 equivalent: `__cpp_lib_debugging >= 202403L`. Note that
  `__cpp_lib_debugging` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202403L` [P2810R4](https://wg21.link/P2810R4) `is_debugger_present`
  `is_replaceable`

  @sa `<debugging>` `freestanding`
*/
#ifndef LBAL_LIBCPP26_DEBUGGING_UTILITIES
  #define LBAL_LIBCPP26_DEBUGGING_UTILITIES 0
#endif

/**
  @def LBAL_LIBCPP26_DEFINE_STATIC
  @brief define_static_{string,object,array}
  @details SD-6 equivalent: `__cpp_lib_define_static >= 202506L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202506L` [P3491R3](https://wg21.link/P3491R3)
  `define_static_{string,object,array}`

  @sa `freestanding` `<meta>`
*/
#ifndef LBAL_LIBCPP26_DEFINE_STATIC
  #define LBAL_LIBCPP26_DEFINE_STATIC 0
#endif

/**
  @def LBAL_LIBCPP26_EXCEPTION_PTR_CAST
  @brief Observing exceptions stored in exception_ptr
  @details SD-6 equivalent: `__cpp_lib_exception_ptr_cast >= 202506L`. Note that
  `__cpp_lib_exception_ptr_cast` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P2927R3](https://wg21.link/P2927R3) Observing exceptions stored
  in exception_ptr

  @sa `<exception>`
*/
#ifndef LBAL_LIBCPP26_EXCEPTION_PTR_CAST
  #define LBAL_LIBCPP26_EXCEPTION_PTR_CAST 0
#endif

/**
  @def LBAL_LIBCPP26_EXCEPTION_PTR_CAST_BETTER_RETURN_TYPES
  @brief Better return types in `std::inplace_vector` and
  `std::exception_ptr_cast`
  @details

  SD-6 equivalent: `__cpp_lib_exception_ptr_cast >= 202603L`. Note that
  `__cpp_lib_exception_ptr_cast` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202603L` [P3981R2](https://wg21.link/P3981R2) Better return types in
  `std::inplace_vector` and `std::exception_ptr_cast`

  @sa `<exception>`
*/
#ifndef LBAL_LIBCPP26_EXCEPTION_PTR_CAST_BETTER_RETURN_TYPES
  #define LBAL_LIBCPP26_EXCEPTION_PTR_CAST_BETTER_RETURN_TYPES 0
#endif

/**
  @def LBAL_LIBCPP26_EXCEPTION_PTR_CAST_CONSTEXPR
  @brief Inspecting exception_ptr works should be constexpr.
  @details SD-6 equivalent: `__cpp_lib_exception_ptr_cast >= 202506L`. Note that
  `__cpp_lib_exception_ptr_cast` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P3748R0](https://wg21.link/P3748R0) Inspecting exception_ptr
  works should be constexpr.

  @sa `<exception>`
*/
#ifndef LBAL_LIBCPP26_EXCEPTION_PTR_CAST_CONSTEXPR
  #define LBAL_LIBCPP26_EXCEPTION_PTR_CAST_CONSTEXPR 0
#endif

/**
  @def LBAL_LIBCPP26_FLAT_MAP_FIXES
  @brief flat_meow Fixes
  @details SD-6 equivalent: `__cpp_lib_flat_map >= 202511L`. Note that
  `__cpp_lib_flat_map` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202511L` [P3567R2](https://wg21.link/P3567R2) flat_meow Fixes

  @sa `<flat_map>`
*/
#ifndef LBAL_LIBCPP26_FLAT_MAP_FIXES
  #define LBAL_LIBCPP26_FLAT_MAP_FIXES 0
#endif

/**
  @def LBAL_LIBCPP26_FLAT_SET_FIXES
  @brief flat_meow Fixes
  @details SD-6 equivalent: `__cpp_lib_flat_set >= 202511L`. Note that
  `__cpp_lib_flat_set` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202511L` [P3567R2](https://wg21.link/P3567R2) flat_meow Fixes

  @sa `<flat_set>`
*/
#ifndef LBAL_LIBCPP26_FLAT_SET_FIXES
  #define LBAL_LIBCPP26_FLAT_SET_FIXES 0
#endif

/**
  @def LBAL_LIBCPP26_FORMAT_MEMBER_VISIT
  @brief Member `visit`
  @details SD-6 equivalent: `__cpp_lib_format >= 202306L`. Note that
  `__cpp_lib_format` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P2637R3](https://wg21.link/P2637R3) Member `visit`

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP26_FORMAT_MEMBER_VISIT
  #define LBAL_LIBCPP26_FORMAT_MEMBER_VISIT 0
#endif

/**
  @def LBAL_LIBCPP26_FORMAT_PATH
  @brief Formatting of std::filesystem::path
  @details SD-6 equivalent: `__cpp_lib_format_path >= 202403L`. Note that
  `__cpp_lib_format_path` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202403L` [P2845R8](https://wg21.link/P2845R8) Formatting of
  std::filesystem::path

  @sa `<filesystem>`
*/
#ifndef LBAL_LIBCPP26_FORMAT_PATH
  #define LBAL_LIBCPP26_FORMAT_PATH 0
#endif

/**
  @def LBAL_LIBCPP26_FORMAT_PATH_FIXES
  @brief Prevent path presentation problems
  @details SD-6 equivalent: `__cpp_lib_format_path >= 202506L`. Note that
  `__cpp_lib_format_path` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P2319R5](https://wg21.link/P2319R5) Prevent path presentation
  problems

  @sa `<filesystem>`
*/
#ifndef LBAL_LIBCPP26_FORMAT_PATH_FIXES
  #define LBAL_LIBCPP26_FORMAT_PATH_FIXES 0
#endif

/**
  @def LBAL_LIBCPP26_FORMAT_POINTERS
  @brief Format pointers
  @details SD-6 equivalent: `__cpp_lib_format >= 202304L`. Note that
  `__cpp_lib_format` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202304L` [P2510R3 __PDF__](https://wg21.link/P2510R3) Formatting pointers

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP26_FORMAT_POINTERS
  #define LBAL_LIBCPP26_FORMAT_POINTERS 0
#endif

/**
  @def LBAL_LIBCPP26_FORMAT_RUNTIME
  @brief Add runtime format strings
  @details SD-6 equivalent: `__cpp_lib_format >= 202311L`. Note that
  `__cpp_lib_format` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202311L` [P2918R2](https://wg21.link/P2918R2) Runtime format strings II
  - `202603L` [P2918R2](https://wg21.link/P2918R2) Runtime format strings II

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP26_FORMAT_RUNTIME
  #define LBAL_LIBCPP26_FORMAT_RUNTIME 0
#endif

/**
  @def LBAL_LIBCPP26_FORMAT_TYPE_CHECK
  @brief Type check format args
  @details SD-6 equivalent: `__cpp_lib_format >= 202305L`. Note that
  `__cpp_lib_format` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202305L` [P2757R3](https://wg21.link/P2757R3) Type checking format args

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP26_FORMAT_TYPE_CHECK
  #define LBAL_LIBCPP26_FORMAT_TYPE_CHECK 0
#endif

/**
  @def LBAL_LIBCPP26_FORMAT_UCHAR
  @brief Fix formatting of code units as integers (Dude, where’s my char?)
  @details SD-6 equivalent: `__cpp_lib_format_uchar >= 202311L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202311L` [P2909R4](https://wg21.link/P2909R4) Fix formatting of code units
  as integers (Dude, where’s my char?)

  @sa `<format>`
*/
#ifndef LBAL_LIBCPP26_FORMAT_UCHAR
  #define LBAL_LIBCPP26_FORMAT_UCHAR 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_ALGORITHM
  @brief Freestanding Library: Partial Classes
  @details SD-6 equivalent: `__cpp_lib_freestanding_algorithm >= 202311L`. Note
  that `__cpp_lib_freestanding_algorithm` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `202311L` [P2407R5](https://wg21.link/P2407R5) Freestanding Library: Partial
  Classes

  @sa `<algorithm>` `freestanding`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_ALGORITHM
  #define LBAL_LIBCPP26_FREESTANDING_ALGORITHM 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_ALGORITHM_MORE
  @brief Freestanding Library: algorithm, numeric, and random
  @details SD-6 equivalent: `__cpp_lib_freestanding_algorithm >= 202502L`. Note
  that `__cpp_lib_freestanding_algorithm` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `202502L` [P2976R1](https://wg21.link/P2976R1) Freestanding Library:
  algorithm, numeric, and random

  @sa `<algorithm>` `freestanding`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_ALGORITHM_MORE
  #define LBAL_LIBCPP26_FREESTANDING_ALGORITHM_MORE 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_ARRAY
  @brief Freestanding Library: Partial Classes
  @details SD-6 equivalent: `__cpp_lib_freestanding_array >= 202311L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202311L` [P2407R5](https://wg21.link/P2407R5) Freestanding Library: Partial
  Classes

  @sa `<array>` `freestanding`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_ARRAY
  #define LBAL_LIBCPP26_FREESTANDING_ARRAY 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_CHARCONV
  @brief Freestanding Library: Character primitives and the C library
  @details SD-6 equivalent: `__cpp_lib_freestanding_charconv >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2338R4](https://wg21.link/P2338R4) Freestanding Library:
  Character primitives and the C library

  @sa `<charconv>` `freestanding`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_CHARCONV
  #define LBAL_LIBCPP26_FREESTANDING_CHARCONV 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_CHAR_TRAITS
  @brief Freestanding Library: Character primitives and the C library
  @details SD-6 equivalent: `__cpp_lib_freestanding_char_traits >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2338R4](https://wg21.link/P2338R4) Freestanding Library:
  Character primitives and the C library

  @sa `freestanding` `<string>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_CHAR_TRAITS
  #define LBAL_LIBCPP26_FREESTANDING_CHAR_TRAITS 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_CSTDLIB
  @brief Freestanding Library: Character primitives and the C library
  @details SD-6 equivalent: `__cpp_lib_freestanding_cstdlib >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2338R4](https://wg21.link/P2338R4) Freestanding Library:
  Character primitives and the C library

  @sa `<cmath>` `<cstdlib>` `freestanding`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_CSTDLIB
  #define LBAL_LIBCPP26_FREESTANDING_CSTDLIB 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_CSTRING
  @brief Freestanding Library: Character primitives and the C library
  @details SD-6 equivalent: `__cpp_lib_freestanding_cstring >= 202306L`. Note
  that `__cpp_lib_freestanding_cstring` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `202306L` [P2338R4](https://wg21.link/P2338R4) Freestanding Library:
  Character primitives and the C library

  @sa `<cstring>` `freestanding`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_CSTRING
  #define LBAL_LIBCPP26_FREESTANDING_CSTRING 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_CSTRING_REMOVE_STRTOK
  @brief Freestanding: Remove strtok
  @details SD-6 equivalent: `__cpp_lib_freestanding_cstring >= 202311L`. Note
  that `__cpp_lib_freestanding_cstring` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `202311L` [P2937R0](https://wg21.link/P2937R0) Freestanding: Remove `strtok`

  @sa `<cstring>` `freestanding`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_CSTRING_REMOVE_STRTOK
  #define LBAL_LIBCPP26_FREESTANDING_CSTRING_REMOVE_STRTOK 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_CWCHAR
  @brief Freestanding Library: Character primitives and the C library
  @details SD-6 equivalent: `__cpp_lib_freestanding_cwchar >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2338R4](https://wg21.link/P2338R4) Freestanding Library:
  Character primitives and the C library

  @sa `<cwchar>` `freestanding`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_CWCHAR
  #define LBAL_LIBCPP26_FREESTANDING_CWCHAR 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_ERRC
  @brief Freestanding Library: Character primitives and the C library
  @details SD-6 equivalent: `__cpp_lib_freestanding_errc >= 202306L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202306L` [P2338R4](https://wg21.link/P2338R4) Freestanding Library:
  Character primitives and the C library

  @sa `<cerrno>` `freestanding` `<system_error>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_ERRC
  #define LBAL_LIBCPP26_FREESTANDING_ERRC 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_EXECUTION
  @brief Freestanding Library: algorithm, numeric, and random
  @details SD-6 equivalent: `__cpp_lib_freestanding_execution >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P2976R1](https://wg21.link/P2976R1) Freestanding Library:
  algorithm, numeric, and random

  @sa `<execution>` `freestanding`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_EXECUTION
  #define LBAL_LIBCPP26_FREESTANDING_EXECUTION 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_EXPECTED
  @brief Freestanding Library: inout expected span
  @details SD-6 equivalent: `__cpp_lib_freestanding_expected >= 202311L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202311L` [P2833R2](https://wg21.link/P2833R2) Freestanding Library: inout
  expected span

  @sa `<expected>` `freestanding`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_EXPECTED
  #define LBAL_LIBCPP26_FREESTANDING_EXPECTED 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_FEATURE_TEST_MACROS
  @brief Freestanding Feature-Test Macros and Implementation-Defined Extensions
  @details SD-6 equivalent: `__cpp_lib_freestanding_feature_test_macros >=
  202306L`. This token will have a value of `0` if the proposal described here
  is not supported.
  - `202306L` [P2198R7](https://wg21.link/P2198R7) Freestanding Feature-Test
  Macros and Implementation-Defined Extensions

  @sa `freestanding`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_FEATURE_TEST_MACROS
  #define LBAL_LIBCPP26_FREESTANDING_FEATURE_TEST_MACROS 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_FUNCTIONAL
  @brief Freestanding Feature-Test Macros and Implementation-Defined Extensions
  @details SD-6 equivalent: `__cpp_lib_freestanding_functional >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2198R7](https://wg21.link/P2198R7) Freestanding Feature-Test
  Macros and Implementation-Defined Extensions

  @sa `freestanding` `<functional>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_FUNCTIONAL
  #define LBAL_LIBCPP26_FREESTANDING_FUNCTIONAL 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_ITERATOR
  @brief Freestanding Feature-Test Macros and Implementation-Defined Extensions
  @details SD-6 equivalent: `__cpp_lib_freestanding_iterator >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2198R7](https://wg21.link/P2198R7) Freestanding Feature-Test
  Macros and Implementation-Defined Extensions

  @sa `freestanding` `<iterator>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_ITERATOR
  #define LBAL_LIBCPP26_FREESTANDING_ITERATOR 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_MDSPAN
  @brief Freestanding Library: inout expected span
  @details SD-6 equivalent: `__cpp_lib_freestanding_mdspan >= 202311L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202311L` [P2833R2](https://wg21.link/P2833R2) Freestanding Library: inout
  expected span

  @sa `freestanding` `<mdspan>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_MDSPAN
  #define LBAL_LIBCPP26_FREESTANDING_MDSPAN 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_MEMORY
  @brief Freestanding Feature-Test Macros and Implementation-Defined Extensions
  @details SD-6 equivalent: `__cpp_lib_freestanding_memory >= 202306L`. Note
  that `__cpp_lib_freestanding_memory` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `202306L` [P2198R7](https://wg21.link/P2198R7) Freestanding Feature-Test
  Macros and Implementation-Defined Extensions

  @sa `freestanding` `<memory>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_MEMORY
  #define LBAL_LIBCPP26_FREESTANDING_MEMORY 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_MEMORY_MORE
  @brief Freestanding Library: algorithm, numeric, and random
  @details SD-6 equivalent: `__cpp_lib_freestanding_memory >= 202502L`. Note
  that `__cpp_lib_freestanding_memory` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `202502L` [P2976R1](https://wg21.link/P2976R1) Freestanding Library:
  algorithm, numeric, and random

  @sa `freestanding` `<memory>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_MEMORY_MORE
  #define LBAL_LIBCPP26_FREESTANDING_MEMORY_MORE 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_NUMERIC
  @brief Freestanding Library: algorithm, numeric, and random
  @details SD-6 equivalent: `__cpp_lib_freestanding_numeric >= 202502L`. Note
  that `__cpp_lib_freestanding_numeric` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `202502L` [P2976R1](https://wg21.link/P2976R1) Freestanding Library:
  algorithm, numeric, and random

  @sa `freestanding` `<numeric>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_NUMERIC
  #define LBAL_LIBCPP26_FREESTANDING_NUMERIC 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_OPERATOR_NEW
  @brief Freestanding Feature-Test Macros and Implementation-Defined Extensions
  @details SD-6 equivalent: `__cpp_lib_freestanding_operator_new >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2198R7](https://wg21.link/P2198R7) Freestanding Feature-Test
  Macros and Implementation-Defined Extensions

  @sa `freestanding` `<new>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_OPERATOR_NEW
  #define LBAL_LIBCPP26_FREESTANDING_OPERATOR_NEW 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_OPTIONAL
  @brief Freestanding Library: Partial Classes
  @details SD-6 equivalent: `__cpp_lib_freestanding_optional >= 202311L`. Note
  that `__cpp_lib_freestanding_optional` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `202311L` [P2407R5](https://wg21.link/P2407R5) Freestanding Library: Partial
  Classes

  @sa `freestanding` `<optional>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_OPTIONAL
  #define LBAL_LIBCPP26_FREESTANDING_OPTIONAL 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_RANDOM
  @brief Freestanding Library: algorithm, numeric, and random
  @details SD-6 equivalent: `__cpp_lib_freestanding_random >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P2976R1](https://wg21.link/P2976R1) Freestanding Library:
  algorithm, numeric, and random

  @sa `freestanding` `<random>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_RANDOM
  #define LBAL_LIBCPP26_FREESTANDING_RANDOM 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_RANGES
  @brief Freestanding Feature-Test Macros and Implementation-Defined Extensions
  @details SD-6 equivalent: `__cpp_lib_freestanding_ranges >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2198R7](https://wg21.link/P2198R7) Freestanding Feature-Test
  Macros and Implementation-Defined Extensions

  @sa `freestanding` `<ranges>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_RANGES
  #define LBAL_LIBCPP26_FREESTANDING_RANGES 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_RATIO
  @brief Freestanding Feature-Test Macros and Implementation-Defined Extensions
  @details SD-6 equivalent: `__cpp_lib_freestanding_ratio >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2198R7](https://wg21.link/P2198R7) Freestanding Feature-Test
  Macros and Implementation-Defined Extensions

  @sa `freestanding` `<ratio>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_RATIO
  #define LBAL_LIBCPP26_FREESTANDING_RATIO 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_STRING_VIEW
  @brief Freestanding Library: Partial Classes
  @details SD-6 equivalent: `__cpp_lib_freestanding_string_view >= 202311L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202311L` [P2407R5](https://wg21.link/P2407R5) Freestanding Library: Partial
  Classes

  @sa `freestanding` `<string_view>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_STRING_VIEW
  #define LBAL_LIBCPP26_FREESTANDING_STRING_VIEW 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_TUPLE
  @brief Freestanding Feature-Test Macros and Implementation-Defined Extensions
  @details SD-6 equivalent: `__cpp_lib_freestanding_tuple >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2198R7](https://wg21.link/P2198R7) Freestanding Feature-Test
  Macros and Implementation-Defined Extensions

  @sa `freestanding` `<tuple>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_TUPLE
  #define LBAL_LIBCPP26_FREESTANDING_TUPLE 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_UTILITY
  @brief Freestanding Feature-Test Macros and Implementation-Defined Extensions
  @details SD-6 equivalent: `__cpp_lib_freestanding_utility >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2198R7](https://wg21.link/P2198R7) Freestanding Feature-Test
  Macros and Implementation-Defined Extensions

  @sa `freestanding` `<utility>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_UTILITY
  #define LBAL_LIBCPP26_FREESTANDING_UTILITY 0
#endif

/**
  @def LBAL_LIBCPP26_FREESTANDING_VARIANT
  @brief Freestanding Library: Partial Classes
  @details SD-6 equivalent: `__cpp_lib_freestanding_variant >= 202311L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202311L` [P2407R5](https://wg21.link/P2407R5) Freestanding Library: Partial
  Classes

  @sa `freestanding` `<variant>`
*/
#ifndef LBAL_LIBCPP26_FREESTANDING_VARIANT
  #define LBAL_LIBCPP26_FREESTANDING_VARIANT 0
#endif

/**
  @def LBAL_LIBCPP26_FSTREAM_NATIVE_HANDLE
  @brief Native handles and file streams
  @details SD-6 equivalent: `__cpp_lib_fstream_native_handle >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P1759R6](https://wg21.link/P1759R6) Native handles and file
  streams

  @sa `<fstream>`
*/
#ifndef LBAL_LIBCPP26_FSTREAM_NATIVE_HANDLE
  #define LBAL_LIBCPP26_FSTREAM_NATIVE_HANDLE 0
#endif

/**
  @def LBAL_LIBCPP26_FUNCTION_REF
  @brief function_ref: a non-owning reference to a Callable
  @details SD-6 equivalent: `__cpp_lib_function_ref >= 202306L`. Note that
  `__cpp_lib_function_ref` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P0792R14](https://wg21.link/P0792R14) function_ref: a non-owning
  reference to a Callable

  @sa `freestanding` `<functional>`
*/
#ifndef LBAL_LIBCPP26_FUNCTION_REF
  #define LBAL_LIBCPP26_FUNCTION_REF 0
#endif

/**
  @def LBAL_LIBCPP26_FUNCTION_REF_LESS_DOUBLE_INDIRECTION
  @brief Less double indirection in `function_ref`
  @details

  SD-6 equivalent: `__cpp_lib_function_ref >= 202603L`. Note that
  `__cpp_lib_function_ref` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202603L` [P3961R1](https://wg21.link/P3961R1) Less double indirection in
  `function_ref`

  @remark The C++26 FDIS erroneously gives `__cpp_lib_function_ref` a value of
  `202604L` for this, but it’s a C++26 feature.

  @sa `freestanding` `<functional>`
*/
#ifndef LBAL_LIBCPP26_FUNCTION_REF_LESS_DOUBLE_INDIRECTION
  #define LBAL_LIBCPP26_FUNCTION_REF_LESS_DOUBLE_INDIRECTION 0
#endif

/**
  @def LBAL_LIBCPP26_FUNCTION_REF_RENAME_NONTYPE
  @brief Rename std::nontype, and make it broadly useful
  @details SD-6 equivalent: `__cpp_lib_function_ref >= 202511L`. Note that
  `__cpp_lib_function_ref` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202511L` [P3774R1](https://wg21.link/P3774R1) Rename `std::nontype`, and
  make it broadly useful

  @sa `freestanding` `<functional>`
*/
#ifndef LBAL_LIBCPP26_FUNCTION_REF_RENAME_NONTYPE
  #define LBAL_LIBCPP26_FUNCTION_REF_RENAME_NONTYPE 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_ARRAY
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_array >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<array>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_ARRAY
  #define LBAL_LIBCPP26_HARDENED_ARRAY 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_BASIC_STACKTRACE
  @brief Minor additions to C++26 standard library hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_basic_stacktrace >= 202506L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202506L` [P3697R1](https://wg21.link/P3697R1) Minor additions to C++26
  standard library hardening

  @sa `<stacktrace>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_BASIC_STACKTRACE
  #define LBAL_LIBCPP26_HARDENED_BASIC_STACKTRACE 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_BASIC_STRING
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_basic_string >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<string>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_BASIC_STRING
  #define LBAL_LIBCPP26_HARDENED_BASIC_STRING 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_BASIC_STRING_VIEW
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_basic_string_view >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<string_view>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_BASIC_STRING_VIEW
  #define LBAL_LIBCPP26_HARDENED_BASIC_STRING_VIEW 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_BITSET
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_bitset >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<bitset>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_BITSET
  #define LBAL_LIBCPP26_HARDENED_BITSET 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_COMMON_ITERATOR
  @brief Minor additions to C++26 standard library hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_common_iterator >= 202506L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202506L` [P3697R1](https://wg21.link/P3697R1) Minor additions to C++26
  standard library hardening

  @sa `<iterator>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_COMMON_ITERATOR
  #define LBAL_LIBCPP26_HARDENED_COMMON_ITERATOR 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_COUNTED_ITERATOR
  @brief Minor additions to C++26 standard library hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_counted_iterator >= 202506L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202506L` [P3697R1](https://wg21.link/P3697R1) Minor additions to C++26
  standard library hardening

  @sa `<iterator>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_COUNTED_ITERATOR
  #define LBAL_LIBCPP26_HARDENED_COUNTED_ITERATOR 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_DEQUE
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_deque >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<deque>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_DEQUE
  #define LBAL_LIBCPP26_HARDENED_DEQUE 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_EXPECTED
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_expected >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<expected>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_EXPECTED
  #define LBAL_LIBCPP26_HARDENED_EXPECTED 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_FORWARD_LIST
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_forward_list >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<forward_list>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_FORWARD_LIST
  #define LBAL_LIBCPP26_HARDENED_FORWARD_LIST 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_INPLACE_VECTOR
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_inplace_vector >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<inplace_vector>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_INPLACE_VECTOR
  #define LBAL_LIBCPP26_HARDENED_INPLACE_VECTOR 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_LIST
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_list >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<list>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_LIST
  #define LBAL_LIBCPP26_HARDENED_LIST 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_MDSPAN
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_mdspan >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<mdspan>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_MDSPAN
  #define LBAL_LIBCPP26_HARDENED_MDSPAN 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_OPTIONAL
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_optional >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<optional>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_OPTIONAL
  #define LBAL_LIBCPP26_HARDENED_OPTIONAL 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_SHARED_PTR_ARRAY
  @brief Minor additions to C++26 standard library hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_shared_ptr_array >= 202506L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202506L` [P3697R1](https://wg21.link/P3697R1) Minor additions to C++26
  standard library hardening

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_SHARED_PTR_ARRAY
  #define LBAL_LIBCPP26_HARDENED_SHARED_PTR_ARRAY 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_SPAN
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_span >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<span>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_SPAN
  #define LBAL_LIBCPP26_HARDENED_SPAN 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_VALARRAY
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_valarray >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<valarray>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_VALARRAY
  #define LBAL_LIBCPP26_HARDENED_VALARRAY 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_VECTOR
  @brief Standard Library Hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_vector >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3471R4](https://wg21.link/P3471R4) Standard Library Hardening

  @sa `<vector>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_VECTOR
  #define LBAL_LIBCPP26_HARDENED_VECTOR 0
#endif

/**
  @def LBAL_LIBCPP26_HARDENED_VIEW_INTERFACE
  @brief Minor additions to C++26 standard library hardening
  @details SD-6 equivalent: `__cpp_lib_hardened_view_interface >= 202506L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202506L` [P3697R1](https://wg21.link/P3697R1) Minor additions to C++26
  standard library hardening

  @sa `<ranges>`
*/
#ifndef LBAL_LIBCPP26_HARDENED_VIEW_INTERFACE
  #define LBAL_LIBCPP26_HARDENED_VIEW_INTERFACE 0
#endif

/**
  @def LBAL_LIBCPP26_HAZARD_POINTER
  @brief Hazard Pointers for C++26
  @details SD-6 equivalent: `__cpp_lib_hazard_pointer >= 202306L`. Note that
  `__cpp_lib_hazard_pointer` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P2530R3 __PDF__](https://wg21.link/P2530R3) Hazard Pointers for
  C++26

  @sa `<hazard_pointer>`
*/
#ifndef LBAL_LIBCPP26_HAZARD_POINTER
  #define LBAL_LIBCPP26_HAZARD_POINTER 0
#endif

/**
  @def LBAL_LIBCPP26_HIVE
  @brief Introduction of std::hive to the standard library
  @details SD-6 equivalent: `__cpp_lib_hive >= 202502L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `202502L` [P0447R28](https://wg21.link/P0447R28) Introduction of std::hive
  to the standard library

  @sa `<hive>`
*/
#ifndef LBAL_LIBCPP26_HIVE
  #define LBAL_LIBCPP26_HIVE 0
#endif

/**
  @def LBAL_LIBCPP26_INDIRECT
  @brief Vocabulary Types for Composite Class Design
  @details SD-6 equivalent: `__cpp_lib_indirect >= 202502L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3019R14 __PDF__](https://wg21.link/P3019R14) `indirect` and
  `polymorphic`: Vocabulary Types for Composite Class Design

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP26_INDIRECT
  #define LBAL_LIBCPP26_INDIRECT 0
#endif

/**
  @def LBAL_LIBCPP26_INITIALIZER_LIST
  @brief Resolve inconsistencies in begin/end for valarray and braced
  initializer lists
  @details SD-6 equivalent: `__cpp_lib_initializer_list >= 202511L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202511L` [P3016R6](https://wg21.link/P3016R6) Resolve inconsistencies in
  begin/end for `valarray` and braced initializer lists

  @sa `freestanding` `<initializer_list>`
*/
#ifndef LBAL_LIBCPP26_INITIALIZER_LIST
  #define LBAL_LIBCPP26_INITIALIZER_LIST 0
#endif

/**
  @def LBAL_LIBCPP26_INPLACE_VECTOR
  @brief inplace_vector
  @details SD-6 equivalent: `__cpp_lib_inplace_vector >= 202406L`. Note that
  `__cpp_lib_inplace_vector` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202406L` [P0843R14](https://wg21.link/P0843R14) `inplace_vector`

  @sa `<inplace_vector>`
*/
#ifndef LBAL_LIBCPP26_INPLACE_VECTOR
  #define LBAL_LIBCPP26_INPLACE_VECTOR 0
#endif

/**
  @def LBAL_LIBCPP26_INPLACE_VECTOR_BETTER_RETURN_TYPES
  @brief Better return types in `std::inplace_vector` and
  `std::exception_ptr_cast`
  @details

  SD-6 equivalent: `__cpp_lib_inplace_vector >= 202603L`. Note that
  `__cpp_lib_inplace_vector` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202603L` [P3981R2](https://wg21.link/P3981R2) Better return types in
  `std::inplace_vector` and `std::exception_ptr_cast`

  @sa `<inplace_vector>`
*/
#ifndef LBAL_LIBCPP26_INPLACE_VECTOR_BETTER_RETURN_TYPES
  #define LBAL_LIBCPP26_INPLACE_VECTOR_BETTER_RETURN_TYPES 0
#endif

/**
  @def LBAL_LIBCPP26_INPLACE_VECTOR_REMOVE_TRY_APPEND_RANGE
  @brief Remove `try_append_range` from `inplace_vector` for now
  @details

  SD-6 equivalent: `__cpp_lib_inplace_vector >= 202603L`. Note that
  `__cpp_lib_inplace_vector` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202603L` [P4022R0](https://wg21.link/P4022R0) Remove `try_append_range`
  from `inplace_vector` for now

  @sa `<inplace_vector>`
*/
#ifndef LBAL_LIBCPP26_INPLACE_VECTOR_REMOVE_TRY_APPEND_RANGE
  #define LBAL_LIBCPP26_INPLACE_VECTOR_REMOVE_TRY_APPEND_RANGE 0
#endif

/**
  @def LBAL_LIBCPP26_INTEGER_SEQUENCE_EXPANSION_STATEMENTS
  @brief Add library Support for Expansion Statements
  @details SD-6 equivalent: `__cpp_lib_integer_sequence >= 202511L`. Note that
  `__cpp_lib_integer_sequence` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202511L` [P1789R3 __PDF__](https://wg21.link/P1789R3) Library Support for
  Expansion Statements

  @sa `freestanding` `<utility>`
*/
#ifndef LBAL_LIBCPP26_INTEGER_SEQUENCE_EXPANSION_STATEMENTS
  #define LBAL_LIBCPP26_INTEGER_SEQUENCE_EXPANSION_STATEMENTS 0
#endif

/**
  @def LBAL_LIBCPP26_IS_STRUCTURAL
  @brief New reflection metafunction—
  @details

  SD-6 equivalent: `__cpp_lib_is_structural >= 202603L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `202603L` [P3856R8 __PDF__](https://wg21.link/P3856R8) New reflection
  metafunction—

  @sa `freestanding` `<meta>` `<type_traits>`
*/
#ifndef LBAL_LIBCPP26_IS_STRUCTURAL
  #define LBAL_LIBCPP26_IS_STRUCTURAL 0
#endif

/**
  @def LBAL_LIBCPP26_IS_VIRTUAL_BASE_OF
  @brief A type trait for detecting virtual base classes
  @details SD-6 equivalent: `__cpp_lib_is_virtual_base_of >= 202406L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202406L` [P2985R0](https://wg21.link/P2985R0) A type trait for detecting
  virtual base classes

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP26_IS_VIRTUAL_BASE_OF
  #define LBAL_LIBCPP26_IS_VIRTUAL_BASE_OF 0
#endif

/**
  @def LBAL_LIBCPP26_IS_WITHIN_LIFETIME
  @brief Checking if a union alternative is active
  @details SD-6 equivalent: `__cpp_lib_is_within_lifetime >= 202306L`. Note that
  `__cpp_lib_is_within_lifetime` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P2641R4](https://wg21.link/P2641R4) Checking if a union
  alternative is active

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP26_IS_WITHIN_LIFETIME
  #define LBAL_LIBCPP26_IS_WITHIN_LIFETIME 0
#endif

/**
  @def LBAL_LIBCPP26_IS_WITHIN_LIFETIME_EXTEND
  @brief Extend `std::is_within_lifetime`
  @details

  SD-6 equivalent: `__cpp_lib_is_within_lifetime >= 202603L`. Note that
  `__cpp_lib_is_within_lifetime` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202603L` [P3450R1](https://wg21.link/P3450R1) Extend
  `std::is_within_lifetime`

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP26_IS_WITHIN_LIFETIME_EXTEND
  #define LBAL_LIBCPP26_IS_WITHIN_LIFETIME_EXTEND 0
#endif

/**
  @def LBAL_LIBCPP26_LINALG
  @brief A free function linear algebra interface based on the BLAS
  @details SD-6 equivalent: `__cpp_lib_linalg >= 202311L`. Note that
  `__cpp_lib_linalg` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202311L` [P1673R13](https://wg21.link/P1673R13) A free function linear
  algebra interface based on the BLAS

  @sa `<linalg>`
*/
#ifndef LBAL_LIBCPP26_LINALG
  #define LBAL_LIBCPP26_LINALG 0
#endif

/**
  @def LBAL_LIBCPP26_LINALG_BLAS_RANK
  @brief Fix C++26 by making the rank-1, rank-2, rank-k, and rank-2k updates
  consistent with the BLAS
  @details SD-6 equivalent: `__cpp_lib_linalg >= 202511L`. Note that
  `__cpp_lib_linalg` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202511L` [P3371R5](https://wg21.link/P3371R5) Fix C++26 by making the
  rank-1, rank-2, rank-k, and rank-2k updates consistent with the BLAS

  @sa `<linalg>`
*/
#ifndef LBAL_LIBCPP26_LINALG_BLAS_RANK
  #define LBAL_LIBCPP26_LINALG_BLAS_RANK 0
#endif

/**
  @def LBAL_LIBCPP26_LINALG_FIX_TRANSPOSED
  @brief Fix C++26 by adding `transposed` special cases for P2642 layouts
  @details SD-6 equivalent: `__cpp_lib_linalg >= 202411L`. Note that
  `__cpp_lib_linalg` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202411L` [P3222R0](https://wg21.link/P3222R0) Fix C++26 by adding
  transposed special cases for P2642 layouts

  @sa `<linalg>`
*/
#ifndef LBAL_LIBCPP26_LINALG_FIX_TRANSPOSED
  #define LBAL_LIBCPP26_LINALG_FIX_TRANSPOSED 0
#endif

/**
  @def LBAL_LIBCPP26_LINALG_OPTIMIZE_CONJUGATED
  @brief Fix C++26 by optimizing linalg::conjugated for noncomplex value types
  @details SD-6 equivalent: `__cpp_lib_linalg >= 202411L`. Note that
  `__cpp_lib_linalg` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202411L` [P3050R2](https://wg21.link/P3050R2) Fix C++26 by optimizing
  linalg::conjugated for noncomplex value types

  @sa `<linalg>`
*/
#ifndef LBAL_LIBCPP26_LINALG_OPTIMIZE_CONJUGATED
  #define LBAL_LIBCPP26_LINALG_OPTIMIZE_CONJUGATED 0
#endif

/**
  @def LBAL_LIBCPP26_MDSPAN_DEXTENTS
  @brief `dextents` Index Type Parameter
  @details SD-6 equivalent: `__cpp_lib_mdspan >= 202406L`. Note that
  `__cpp_lib_mdspan` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202406L` [P2389R2](https://wg21.link/P2389R2) `dextents` Index Type
  Parameter

  @sa `freestanding` `<mdspan>`
*/
#ifndef LBAL_LIBCPP26_MDSPAN_DEXTENTS
  #define LBAL_LIBCPP26_MDSPAN_DEXTENTS 0
#endif

/**
  @def LBAL_LIBCPP26_NOT_FN_NTTP_CALLABLES
  @brief Bind `not_fn` to NTTP callables
  @details SD-6 equivalent: `__cpp_lib_not_fn >= 202306L`. Note that
  `__cpp_lib_not_fn` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P2714R1](https://wg21.link/P2714R1) Bind front and back to NTTP
  callables

  @sa `freestanding` `<functional>`
*/
#ifndef LBAL_LIBCPP26_NOT_FN_NTTP_CALLABLES
  #define LBAL_LIBCPP26_NOT_FN_NTTP_CALLABLES 0
#endif

/**
  @def LBAL_LIBCPP26_OBSERVABLE_CHECKPOINT
  @brief Rename std::observable to std::observable_checkpoint, and add a
  feature-test macro
  @details SD-6 equivalent: `__cpp_lib_observable_checkpoint >= 202506L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202506L` [P1494R5](https://wg21.link/P1494R5) Partial program correctness
  - `202506L` [P3641R0](https://wg21.link/P3641R0) Rename `std::observable` to
  `std::observable_checkpoint`, and add a feature-test macro

  @sa `freestanding` `<utility>`
*/
#ifndef LBAL_LIBCPP26_OBSERVABLE_CHECKPOINT
  #define LBAL_LIBCPP26_OBSERVABLE_CHECKPOINT 0
#endif

/**
  @def LBAL_LIBCPP26_OPTIONAL_RANGE_SUPPORT
  @brief Give std::optional Range Support
  @details SD-6 equivalent: `__cpp_lib_optional_range_support >= 202406L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202406L` [P3168R2](https://wg21.link/P3168R2) Give std::optional Range
  Support

  @sa `freestanding` `<optional>`
*/
#ifndef LBAL_LIBCPP26_OPTIONAL_RANGE_SUPPORT
  #define LBAL_LIBCPP26_OPTIONAL_RANGE_SUPPORT 0
#endif

/**
  @def LBAL_LIBCPP26_OPTIONAL_REFERENCE
  @brief `std::optional<T&>`
  @details SD-6 equivalent: `__cpp_lib_optional >= 202506L`. Note that
  `__cpp_lib_optional` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P2988R12 __PDF__](https://wg21.link/P2988R12) std::optional<T&>

  @sa `<optional>`
*/
#ifndef LBAL_LIBCPP26_OPTIONAL_REFERENCE
  #define LBAL_LIBCPP26_OPTIONAL_REFERENCE 0
#endif

/**
  @def LBAL_LIBCPP26_OUT_PTR_MORE
  @brief Freestanding Library: inout expected span
  @details SD-6 equivalent: `__cpp_lib_out_ptr >= 202311L`. Note that
  `__cpp_lib_out_ptr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202311L` [P2833R2](https://wg21.link/P2833R2) Freestanding Library: inout
  expected span

  @sa `freestanding` `<memory>`
*/
#ifndef LBAL_LIBCPP26_OUT_PTR_MORE
  #define LBAL_LIBCPP26_OUT_PTR_MORE 0
#endif

/**
  @def LBAL_LIBCPP26_PARALLEL_ALGORITHM_RANGE
  @brief Add C++ parallel `range` algorithms
  @details SD-6 equivalent: `__cpp_lib_parallel_algorithm >= 202506L`. Note that
  `__cpp_lib_parallel_algorithm` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P3179R9](https://wg21.link/P3179R9) C++ parallel range algorithms
  - `202506L` [P3709R2](https://wg21.link/P3709R2) Reconsider parallel
  `ranges::rotate_copy` and `ranges::reverse_copy`

  @sa `<algorithm>` `<memory>` `<numeric>`
*/
#ifndef LBAL_LIBCPP26_PARALLEL_ALGORITHM_RANGE
  #define LBAL_LIBCPP26_PARALLEL_ALGORITHM_RANGE 0
#endif

/**
  @def LBAL_LIBCPP26_PARALLEL_SCHEDULER
  @brief Parallel Scheduler
  @details SD-6 equivalent: `__cpp_lib_parallel_scheduler >= 202506L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202506L` [P2079R10](https://wg21.link/P2079R10) Parallel Scheduler
  - `202506L` [P3804R2](https://wg21.link/P3804R2) Iterating on
  `parallel_scheduler`

  @sa `<execution>`
*/
#ifndef LBAL_LIBCPP26_PARALLEL_SCHEDULER
  #define LBAL_LIBCPP26_PARALLEL_SCHEDULER 0
#endif

/**
  @def LBAL_LIBCPP26_PHILOX_ENGINE
  @brief Philox as an extension of the C++ RNG engines
  @details SD-6 equivalent: `__cpp_lib_philox_engine >= 202406L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202406L` [P2075R6 __PDF__](https://wg21.link/P2075R6) Philox as an
  extension of the C++ RNG engines

  @sa `<random>`
*/
#ifndef LBAL_LIBCPP26_PHILOX_ENGINE
  #define LBAL_LIBCPP26_PHILOX_ENGINE 0
#endif

/**
  @def LBAL_LIBCPP26_POLYMORPHIC
  @brief Vocabulary Types for Composite Class Design
  @details SD-6 equivalent: `__cpp_lib_polymorphic >= 202502L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3019R14 __PDF__](https://wg21.link/P3019R14) `indirect` and
  `polymorphic`: Vocabulary Types for Composite Class Design

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP26_POLYMORPHIC
  #define LBAL_LIBCPP26_POLYMORPHIC 0
#endif

/**
  @def LBAL_LIBCPP26_PRINT_EFFICIENT
  @brief Permit an efficient implementation of std::print
  @details SD-6 equivalent: `__cpp_lib_print >= 202403L`. Note that
  `__cpp_lib_print` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202403L` [P3107R5](https://wg21.link/P3107R5) Permit an efficient
  implementation of std::print

  @sa `<ostream>` `<print>`
*/
#ifndef LBAL_LIBCPP26_PRINT_EFFICIENT
  #define LBAL_LIBCPP26_PRINT_EFFICIENT 0
#endif

/**
  @def LBAL_LIBCPP26_PRINT_MORE_EFFICIENT
  @brief std::print more types faster with less memory
  @details SD-6 equivalent: `__cpp_lib_print >= 202406L`. Note that
  `__cpp_lib_print` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202406L` [P3235R3](https://wg21.link/P3235R3) std::print more types faster
  with less memory

  @sa `<ostream>` `<print>`
*/
#ifndef LBAL_LIBCPP26_PRINT_MORE_EFFICIENT
  #define LBAL_LIBCPP26_PRINT_MORE_EFFICIENT 0
#endif

/**
  @def LBAL_LIBCPP26_RANGES_AS_CONST_FIX_CONVERTIBILITY
  @brief std::basic_const_iterator should follow its underlying type’s
  convertibility
  @details SD-6 equivalent: `__cpp_lib_ranges_as_const >= 202311L`. Note that
  `__cpp_lib_ranges_as_const` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202311L` [P2836R1](https://wg21.link/P2836R1) `std::basic_const_iterator`
  should follow its underlying type’s convertibility

  @sa `freestanding` `<ranges>`
*/
#ifndef LBAL_LIBCPP26_RANGES_AS_CONST_FIX_CONVERTIBILITY
  #define LBAL_LIBCPP26_RANGES_AS_CONST_FIX_CONVERTIBILITY 0
#endif

/**
  @def LBAL_LIBCPP26_RANGES_AS_INPUT
  @brief `views::to_input`
  @details SD-6 equivalent: `__cpp_lib_ranges_as_input >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3137R3](https://wg21.link/P3137R3) views::to_input

  @sa `freestanding` `<ranges>`
*/
#ifndef LBAL_LIBCPP26_RANGES_AS_INPUT
  #define LBAL_LIBCPP26_RANGES_AS_INPUT 0
#endif

/**
  @def LBAL_LIBCPP26_RANGES_AS_INPUT_RENAME
  @brief Rename the `to_input` view to `as_input`
  @details SD-6 equivalent: `__cpp_lib_ranges_as_input >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P3828R1 __PDF__](https://wg21.link/P3828R1) Rename the `to_input`
  view to `as_input`

  @sa `freestanding` `<ranges>`
*/
#ifndef LBAL_LIBCPP26_RANGES_AS_INPUT_RENAME
  #define LBAL_LIBCPP26_RANGES_AS_INPUT_RENAME 0
#endif

/**
  @def LBAL_LIBCPP26_RANGES_CACHE_LATEST
  @brief views::cache_latest
  @details SD-6 equivalent: `__cpp_lib_ranges_cache_latest >= 202411L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202411L` [P3138R5](https://wg21.link/P3138R5) `views::cache_latest`

  @sa `freestanding` `<ranges>`
*/
#ifndef LBAL_LIBCPP26_RANGES_CACHE_LATEST
  #define LBAL_LIBCPP26_RANGES_CACHE_LATEST 0
#endif

/**
  @def LBAL_LIBCPP26_RANGES_CONCAT
  @brief views::concat
  @details SD-6 equivalent: `__cpp_lib_ranges_concat >= 202403L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202403L` [P2542R8](https://wg21.link/P2542R8) `views::concat`

  @sa `freestanding` `<ranges>`
*/
#ifndef LBAL_LIBCPP26_RANGES_CONCAT
  #define LBAL_LIBCPP26_RANGES_CONCAT 0
#endif

/**
  @def LBAL_LIBCPP26_RANGES_FILTER
  @brief Filter View Extensions for Safer Use, Rev 3
  @details

  SD-6 equivalent: `__cpp_lib_ranges_filter >= 202603L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `202603L` [P3725R3 __PDF__](https://wg21.link/P3725R3) Filter View
  Extensions for Safer Use, Rev 3

  @sa `freestanding` `<ranges>`
*/
#ifndef LBAL_LIBCPP26_RANGES_FILTER
  #define LBAL_LIBCPP26_RANGES_FILTER 0
#endif

/**
  @def LBAL_LIBCPP26_RANGES_GENERATE_RANDOM
  @brief Vector API for random number generation
  @details SD-6 equivalent: `__cpp_lib_ranges_generate_random >= 202403L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202403L` [P1068R11 __PDF__](https://wg21.link/P1068R11) Vector API for
  random number generation

  @sa `<random>`
*/
#ifndef LBAL_LIBCPP26_RANGES_GENERATE_RANDOM
  #define LBAL_LIBCPP26_RANGES_GENERATE_RANDOM 0
#endif

/**
  @def LBAL_LIBCPP26_RANGES_INDICES
  @brief Add std::views::indices(n)
  @details SD-6 equivalent: `__cpp_lib_ranges_indices >= 202506L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202506L` [P3060R3](https://wg21.link/P3060R3) Add std::views::indices(n)

  @sa `<ranges>`
*/
#ifndef LBAL_LIBCPP26_RANGES_INDICES
  #define LBAL_LIBCPP26_RANGES_INDICES 0
#endif

/**
  @def LBAL_LIBCPP26_RANGES_REMOVE_COMMON_REF_REQ
  @brief Removing the common reference requirement from the indirectly invocable
  concepts
  @details SD-6 equivalent: `__cpp_lib_ranges >= 202406L`. Note that
  `__cpp_lib_ranges` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202406L` [P2997R1](https://wg21.link/P2997R1) Removing the common reference
  requirement from the indirectly invocable concepts

  @sa `<algorithm>` `<functional>` `<iterator>` `<memory>` `<ranges>`
*/
#ifndef LBAL_LIBCPP26_RANGES_REMOVE_COMMON_REF_REQ
  #define LBAL_LIBCPP26_RANGES_REMOVE_COMMON_REF_REQ 0
#endif

/**
  @def LBAL_LIBCPP26_RANGES_RESERVE_HINT
  @brief reserve_hint: Eagerly reserving memory for not-quite-sized lazy ranges
  @details SD-6 equivalent: `__cpp_lib_ranges_reserve_hint >= 202502L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202502L` [P2846R6 __PDF__](https://wg21.link/P2846R6) `reserve_hint`:
  Eagerly reserving memory for not-quite-sized lazy ranges

  @sa `<ranges>`
*/
#ifndef LBAL_LIBCPP26_RANGES_RESERVE_HINT
  #define LBAL_LIBCPP26_RANGES_RESERVE_HINT 0
#endif

/**
  @def LBAL_LIBCPP26_RATIO
  @brief Adding the new 2022 SI prefixes
  @details SD-6 equivalent: `__cpp_lib_ratio >= 202306L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `202306L` [P2734R0 __PDF__](https://wg21.link/P2734R0) Adding the new 2022
  SI prefixes

  @sa `freestanding` `<ratio>`
*/
#ifndef LBAL_LIBCPP26_RATIO
  #define LBAL_LIBCPP26_RATIO 0
#endif

/**
  @def LBAL_LIBCPP26_RAW_MEMORY_ALGORITHMS_CONSTEXPR
  @brief Improve `constexpr` supprt for raw memory management
  @details SD-6 equivalent: `__cpp_lib_raw_memory_algorithms >= 202411L`. Note
  that `__cpp_lib_raw_memory_algorithms` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `202411L` [P3369R0](https://wg21.link/P3369R0) constexpr for
  uninitialized_default_construct
  - `202411L` [P3508R0](https://wg21.link/P3508R0) Wording for constexpr for
  specialized memory algorithms

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP26_RAW_MEMORY_ALGORITHMS_CONSTEXPR
  #define LBAL_LIBCPP26_RAW_MEMORY_ALGORITHMS_CONSTEXPR 0
#endif

/**
  @def LBAL_LIBCPP26_RCU
  @brief Read-Copy Update (RCU)
  @details SD-6 equivalent: `__cpp_lib_rcu >= 202306L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `202306L` [P2545R4 __PDF__](https://wg21.link/P2545R4) Read-Copy Update
  (RCU)

  @sa `<rcu>`
*/
#ifndef LBAL_LIBCPP26_RCU
  #define LBAL_LIBCPP26_RCU 0
#endif

/**
  @def LBAL_LIBCPP26_REFERENCE_WRAPPER
  @brief Comparisons for reference_wrapper
  @details SD-6 equivalent: `__cpp_lib_reference_wrapper >= 202403L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202403L` [P2944R3](https://wg21.link/P2944R3) Comparisons for
  `reference_wrapper`

  @sa `freestanding` `<functional>`
*/
#ifndef LBAL_LIBCPP26_REFERENCE_WRAPPER
  #define LBAL_LIBCPP26_REFERENCE_WRAPPER 0
#endif

/**
  @def LBAL_LIBCPP26_REFLECTION
  @brief Error Handling in Reflection
  @details SD-6 equivalent: `__cpp_lib_reflection >= 202506L`. Note that
  `__cpp_lib_reflection` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P3560R2](https://wg21.link/P3560R2) Error Handling in Reflection

  @sa `<meta>`
*/
#ifndef LBAL_LIBCPP26_REFLECTION
  #define LBAL_LIBCPP26_REFLECTION 0
#endif

/**
  @def LBAL_LIBCPP26_REFLECTION_CLEANUP
  @brief Miscellaneous Reflection Cleanup
  @details

  SD-6 equivalent: `__cpp_lib_reflection >= 202603L`. Note that
  `__cpp_lib_reflection` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P3795R2](https://wg21.link/P3795R2) Miscellaneous Reflection
  Cleanup
  - `202603L` [P3795R2](https://wg21.link/P3795R2) Miscellaneous Reflection
  Cleanup

  @sa `<meta>`
*/
#ifndef LBAL_LIBCPP26_REFLECTION_CLEANUP
  #define LBAL_LIBCPP26_REFLECTION_CLEANUP 0
#endif

/**
  @def LBAL_LIBCPP26_REFLECTION_RENAME_TO_IS_VARARG_FUNCTION
  @brief Rename `meta::has_ellipsis_parameter` to `meta::is_vararg_function`
  @details

  SD-6 equivalent: `__cpp_lib_reflection >= 202603L`. Note that
  `__cpp_lib_reflection` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P4156R0](https://wg21.link/P4156R0) Rename
  `meta::has_ellipsis_parameter` to `meta::is_vararg_function`
  - `202603L` [P4156R0](https://wg21.link/P4156R0) Rename
  `meta::has_ellipsis_parameter` to `meta::is_vararg_function`

  @sa `<meta>`
*/
#ifndef LBAL_LIBCPP26_REFLECTION_RENAME_TO_IS_VARARG_FUNCTION
  #define LBAL_LIBCPP26_REFLECTION_RENAME_TO_IS_VARARG_FUNCTION 0
#endif

/**
  @def LBAL_LIBCPP26_REPLACEABLE_CONTRACT_VIOLATION_HANDLER
  @brief Wording for AT1-057
  @details

  SD-6 equivalent: `__cpp_lib_replaceable_contract_violation_handler >=
  202306L`. Note that `__cpp_lib_replaceable_contract_violation_handler` has
  multiple values associated with it from a number of different proposals, so
  this token will have the value of the latest supported proposal, or `0` if the
  proposal described here is not supported.
  - `202306L` [P3886R0 __PDF__](https://wg21.link/P3886R0) Wording for AT1-057
  - `202603L` [P3886R0 __PDF__](https://wg21.link/P3886R0) Wording for AT1-057

  @sa `<contracts>` `freestanding`
*/
#ifndef LBAL_LIBCPP26_REPLACEABLE_CONTRACT_VIOLATION_HANDLER
  #define LBAL_LIBCPP26_REPLACEABLE_CONTRACT_VIOLATION_HANDLER 0
#endif

/**
  @def LBAL_LIBCPP26_SATURATION_ARITHMETIC
  @brief Saturation arithmetic
  @details SD-6 equivalent: `__cpp_lib_saturation_arithmetic >= 202311L`. Note
  that `__cpp_lib_saturation_arithmetic` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `202311L` [P0543R3](https://wg21.link/P0543R3) Saturation arithmetic

  @sa `freestanding` `<numeric>`
*/
#ifndef LBAL_LIBCPP26_SATURATION_ARITHMETIC
  #define LBAL_LIBCPP26_SATURATION_ARITHMETIC 0
#endif

/**
  @def LBAL_LIBCPP26_SATURATION_ARITHMETIC_RENAMING
  @brief Renaming saturation arithmetic functions
  @details

  SD-6 equivalent: `__cpp_lib_saturation_arithmetic >= 202603L`. Note that
  `__cpp_lib_saturation_arithmetic` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `202603L` [P4052R0](https://wg21.link/P4052R0) Renaming saturation
  arithmetic functions

  @sa `freestanding` `<numeric>`
*/
#ifndef LBAL_LIBCPP26_SATURATION_ARITHMETIC_RENAMING
  #define LBAL_LIBCPP26_SATURATION_ARITHMETIC_RENAMING 0
#endif

/**
  @def LBAL_LIBCPP26_SENDERS
  @brief std::execution
  @details SD-6 equivalent: `__cpp_lib_senders >= 202406L`. Note that
  `__cpp_lib_senders` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202406L` [P2300R10](https://wg21.link/P2300R10) `std::execution`

  @sa `<execution>`
*/
#ifndef LBAL_LIBCPP26_SENDERS
  #define LBAL_LIBCPP26_SENDERS 0
#endif

/**
  @def LBAL_LIBCPP26_SENDERS_OPTIONAL
  @brief `optional` variants in sender/receiver
  @details SD-6 equivalent: `__cpp_lib_senders >= 202506L`. Note that
  `__cpp_lib_senders` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P3570R2](https://wg21.link/P3570R2) optional variants in
  sender/receiver

  @sa `<execution>`
*/
#ifndef LBAL_LIBCPP26_SENDERS_OPTIONAL
  #define LBAL_LIBCPP26_SENDERS_OPTIONAL 0
#endif

/**
  @def LBAL_LIBCPP26_SIMD
  @brief std::simd - Merge data-parallel types from the Parallelism TS 2
  @details SD-6 equivalent: `__cpp_lib_simd >= 202411L`. Note that
  `__cpp_lib_simd` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202411L` [P1928R15 __PDF__](https://wg21.link/P1928R15) std::simd - Merge
  data-parallel types from the Parallelism TS 2

  @sa `<simd>`
*/
#ifndef LBAL_LIBCPP26_SIMD
  #define LBAL_LIBCPP26_SIMD 0
#endif

/**
  @def LBAL_LIBCPP26_SIMD_BIT
  @brief Extend `<bit>` header function with overloads for std::simd
  @details SD-6 equivalent: `__cpp_lib_simd >= 202502L`. Note that
  `__cpp_lib_simd` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202502L` [P2933R4](https://wg21.link/P2933R4) Extend header function with
  overloads for std::simd

  @sa `<simd>`
*/
#ifndef LBAL_LIBCPP26_SIMD_BIT
  #define LBAL_LIBCPP26_SIMD_BIT 0
#endif

/**
  @def LBAL_LIBCPP26_SIMD_CHUNK
  @brief Rename simd_split to simd_chunk
  @details SD-6 equivalent: `__cpp_lib_simd >= 202502L`. Note that
  `__cpp_lib_simd` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202502L` [P3441R2](https://wg21.link/P3441R2) Rename simd_split to
  simd_chunk

  @sa `<simd>`
*/
#ifndef LBAL_LIBCPP26_SIMD_CHUNK
  #define LBAL_LIBCPP26_SIMD_CHUNK 0
#endif

/**
  @def LBAL_LIBCPP26_SIMD_COMPLEX
  @brief Proposal to support interleaved complex values in std::simd
  @details SD-6 equivalent: `__cpp_lib_simd_complex >= 202502L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202502L` [P2663R7](https://wg21.link/P2663R7) Proposal to support
  interleaved complex values in std::simd

  @sa `<simd>`
*/
#ifndef LBAL_LIBCPP26_SIMD_COMPLEX
  #define LBAL_LIBCPP26_SIMD_COMPLEX 0
#endif

/**
  @def LBAL_LIBCPP26_SIMD_DEDUCTION_GUIDES
  @brief Missing deduction guide from simd::mask to simd::vec
  @details SD-6 equivalent: `__cpp_lib_simd >= 202511L`. Note that
  `__cpp_lib_simd` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202511L` [P3922R1 __PDF__](https://wg21.link/P3922R1) Missing deduction
  guide from `simd::mask` to `simd::vec`

  @sa `<simd>`
*/
#ifndef LBAL_LIBCPP26_SIMD_DEDUCTION_GUIDES
  #define LBAL_LIBCPP26_SIMD_DEDUCTION_GUIDES 0
#endif

/**
  @def LBAL_LIBCPP26_SIMD_EXTEND
  @brief Proposal to extend std::simd with more constructors and accessors
  @details SD-6 equivalent: `__cpp_lib_simd >= 202506L`. Note that
  `__cpp_lib_simd` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P2876R3](https://wg21.link/P2876R3) Proposal to extend
  `std::simd` with more constructors and accessors

  @sa `<simd>`
*/
#ifndef LBAL_LIBCPP26_SIMD_EXTEND
  #define LBAL_LIBCPP26_SIMD_EXTEND 0
#endif

/**
  @def LBAL_LIBCPP26_SIMD_IOTA
  @brief Add an `iota` object for `simd` (and more)
  @details

  SD-6 equivalent: `__cpp_lib_simd >= 202603L`. Note that `__cpp_lib_simd` has
  multiple values associated with it from a number of different proposals, so
  this token will have the value of the latest supported proposal, or `0` if the
  proposal described here is not supported.
  - `202603L` [P3319R6 __PDF__](https://wg21.link/P3319R6) Add an `iota` object
  for `simd` (and more)
  - `202606L` [P3319R6 __PDF__](https://wg21.link/P3319R6) Add an `iota` object
  for `simd` (and more)

  @sa `<simd>`
*/
#ifndef LBAL_LIBCPP26_SIMD_IOTA
  #define LBAL_LIBCPP26_SIMD_IOTA 0
#endif

/**
  @def LBAL_LIBCPP26_SIMD_NAMESPACES
  @brief Exploration of namespaces for std::simd
  @details SD-6 equivalent: `__cpp_lib_simd >= 202502L`. Note that
  `__cpp_lib_simd` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202502L` [P3287R3](https://wg21.link/P3287R3) Exploration of namespaces
  for std::simd

  @sa `<simd>`
*/
#ifndef LBAL_LIBCPP26_SIMD_NAMESPACES
  #define LBAL_LIBCPP26_SIMD_NAMESPACES 0
#endif

/**
  @def LBAL_LIBCPP26_SIMD_PERMUTATIONS
  @brief Proposal to extend std::simd with permutation API
  @details SD-6 equivalent: `__cpp_lib_simd_permutations >= 202506L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202506L` [P2664R11](https://wg21.link/P2664R11) Proposal to extend
  std::simd with permutation API

  @sa `<simd>`
*/
#ifndef LBAL_LIBCPP26_SIMD_PERMUTATIONS
  #define LBAL_LIBCPP26_SIMD_PERMUTATIONS 0
#endif

/**
  @def LBAL_LIBCPP26_SIMD_RANGE
  @brief std::simd is a range
  @details SD-6 equivalent: `__cpp_lib_simd >= 202506L`. Note that
  `__cpp_lib_simd` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P3480R6 __PDF__](https://wg21.link/P3480R6) std::simd is a range

  @sa `<simd>`
*/
#ifndef LBAL_LIBCPP26_SIMD_RANGE
  #define LBAL_LIBCPP26_SIMD_RANGE 0
#endif

/**
  @def LBAL_LIBCPP26_SMART_POINTER_OWNER_EQUALITY
  @brief Enabling the Use of weak_ptr as Keys in Unordered Associative
  Containers
  @details SD-6 equivalent: `__cpp_lib_smart_pointer_owner_equality >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P1901R2](https://wg21.link/P1901R2) Enabling the Use of
  `weak_ptr` as Keys in Unordered Associative Containers

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP26_SMART_POINTER_OWNER_EQUALITY
  #define LBAL_LIBCPP26_SMART_POINTER_OWNER_EQUALITY 0
#endif

/**
  @def LBAL_LIBCPP26_SMART_PTR_OWNER_EQUALITY
  @brief Enabling the Use of weak_ptr as Keys in Unordered Associative
  Containers
  @details SD-6 equivalent: `__cpp_lib_smart_ptr_owner_equality >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P1901R2](https://wg21.link/P1901R2) Enabling the Use of
  `weak_ptr` as Keys in Unordered Associative Containers

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP26_SMART_PTR_OWNER_EQUALITY
  #define LBAL_LIBCPP26_SMART_PTR_OWNER_EQUALITY 0
#endif

/**
  @def LBAL_LIBCPP26_SPAN_AT
  @brief `span.at()`
  @details SD-6 equivalent: `__cpp_lib_span >= 202311L`. Note that
  `__cpp_lib_span` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202311L` [P2821R5](https://wg21.link/P2821R5) span.at()

  @sa `freestanding` `<span>`
*/
#ifndef LBAL_LIBCPP26_SPAN_AT
  #define LBAL_LIBCPP26_SPAN_AT 0
#endif

/**
  @def LBAL_LIBCPP26_SPAN_MORE
  @brief Freestanding Library: inout expected span
  @details SD-6 equivalent: `__cpp_lib_span >= 202311L`. Note that
  `__cpp_lib_span` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202311L` [P2833R2](https://wg21.link/P2833R2) Freestanding Library: inout
  expected span

  @sa `freestanding` `<span>`
*/
#ifndef LBAL_LIBCPP26_SPAN_MORE
  #define LBAL_LIBCPP26_SPAN_MORE 0
#endif

/**
  @def LBAL_LIBCPP26_SSTREAM_FROM_STRING_VIEW
  @brief Interfacing stringstreams with string_view
  @details SD-6 equivalent: `__cpp_lib_sstream_from_string_view >= 202306L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202306L` [P2495R3 __PDF__](https://wg21.link/P2495R3) Interfacing
  stringstreams with string_view

  @sa `<sstream>`
*/
#ifndef LBAL_LIBCPP26_SSTREAM_FROM_STRING_VIEW
  #define LBAL_LIBCPP26_SSTREAM_FROM_STRING_VIEW 0
#endif

/**
  @def LBAL_LIBCPP26_START_LIFETIME
  @brief Adjustments to `union` Lifetime Rules
  @details

  SD-6 equivalent: `__cpp_lib_start_lifetime >= 202603L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `202603L` [P3726R2](https://wg21.link/P3726R2) Adjustments to `union`
  Lifetime Rules

  @sa `freestanding` `<memory>`
*/
#ifndef LBAL_LIBCPP26_START_LIFETIME
  #define LBAL_LIBCPP26_START_LIFETIME 0
#endif

/**
  @def LBAL_LIBCPP26_STDBIT_H
  @brief Add new library headers from C23
  @details

  SD-6 equivalent: `__cpp_lib_stdbit_h >= 202603L`. This token will have a value
  of `0` if the proposal described here is not supported.
  - `202603L` [P3370R1](https://wg21.link/P3370R1) Add new library headers from
  C23

  @sa `<stdbit.h>`
*/
#ifndef LBAL_LIBCPP26_STDBIT_H
  #define LBAL_LIBCPP26_STDBIT_H 0
#endif

/**
  @def LBAL_LIBCPP26_STDCKDINT_H
  @brief Add new library headers from C23
  @details

  SD-6 equivalent: `__cpp_lib_stdckdint_h >= 202603L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `202603L` [P3370R1](https://wg21.link/P3370R1) Add new library headers from
  C23

  @sa `<stdckdint.h>`
*/
#ifndef LBAL_LIBCPP26_STDCKDINT_H
  #define LBAL_LIBCPP26_STDCKDINT_H 0
#endif

/**
  @def LBAL_LIBCPP26_STRING_SUBVIEW
  @brief sub-string_view from string
  @details SD-6 equivalent: `__cpp_lib_string_subview >= 202506L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202506L` [P3044R2 __PDF__](https://wg21.link/P3044R2) sub-`string_view`
  from `string`

  @sa `<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP26_STRING_SUBVIEW
  #define LBAL_LIBCPP26_STRING_SUBVIEW 0
#endif

/**
  @def LBAL_LIBCPP26_STRING_VIEW_CONCAT
  @brief Allow concatenation of `std::string` and `std::string_view`
  @details SD-6 equivalent: `__cpp_lib_string_view >= 202403L`. Note that
  `__cpp_lib_string_view` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202403L` [P2591R5](https://wg21.link/P2591R5) Concatenation of strings and
  string views

  @sa `<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP26_STRING_VIEW_CONCAT
  #define LBAL_LIBCPP26_STRING_VIEW_CONCAT 0
#endif

/**
  @def LBAL_LIBCPP26_SUBMDSPAN
  @brief `submdspan`
  @details SD-6 equivalent: `__cpp_lib_submdspan >= 202306L`. Note that
  `__cpp_lib_submdspan` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P2630R4](https://wg21.link/P2630R4) `Submdspan`

  @sa `freestanding` `<mdspan>`
*/
#ifndef LBAL_LIBCPP26_SUBMDSPAN
  #define LBAL_LIBCPP26_SUBMDSPAN 0
#endif

/**
  @def LBAL_LIBCPP26_SUBMDSPAN_FIX
  @brief Fix `submdspan` for C++26
  @details SD-6 equivalent: `__cpp_lib_submdspan >= 202411L`. Note that
  `__cpp_lib_submdspan` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202411L` [P3355R1](https://wg21.link/P3355R1) Fix submdspan for C++26

  @sa `freestanding` `<mdspan>`
*/
#ifndef LBAL_LIBCPP26_SUBMDSPAN_FIX
  #define LBAL_LIBCPP26_SUBMDSPAN_FIX 0
#endif

/**
  @def LBAL_LIBCPP26_SUBMDSPAN_FUTURE_PROOF
  @brief Future-proof `submdspan`-mapping
  @details SD-6 equivalent: `__cpp_lib_submdspan >= 202511L`. Note that
  `__cpp_lib_submdspan` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202511L` [P3663R3](https://wg21.link/P3663R3) Future-proof
  submdspan-mapping

  @sa `freestanding` `<mdspan>`
*/
#ifndef LBAL_LIBCPP26_SUBMDSPAN_FUTURE_PROOF
  #define LBAL_LIBCPP26_SUBMDSPAN_FUTURE_PROOF 0
#endif

/**
  @def LBAL_LIBCPP26_SUBMDSPAN_PADDED
  @brief Padded `mdspan` layouts
  @details SD-6 equivalent: `__cpp_lib_submdspan >= 202403L`. Note that
  `__cpp_lib_submdspan` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202403L` [P2642R6 __PDF__](https://wg21.link/P2642R6) Padded mdspan layouts

  @sa `freestanding` `<mdspan>`
*/
#ifndef LBAL_LIBCPP26_SUBMDSPAN_PADDED
  #define LBAL_LIBCPP26_SUBMDSPAN_PADDED 0
#endif

/**
  @def LBAL_LIBCPP26_SUBMDSPAN_UPDATE
  @brief Working Draft: Programming Languages—C++
  @details

  SD-6 equivalent: `__cpp_lib_submdspan >= 202603L`. Note that
  `__cpp_lib_submdspan` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202603L` [N5050](https://wg21.link/N5050) Working Draft: Programming
  Languages—C++

  @sa `freestanding` `<mdspan>`
*/
#ifndef LBAL_LIBCPP26_SUBMDSPAN_UPDATE
  #define LBAL_LIBCPP26_SUBMDSPAN_UPDATE 0
#endif

/**
  @def LBAL_LIBCPP26_TASK
  @brief Add a Coroutine Task Type
  @details SD-6 equivalent: `__cpp_lib_task >= 202506L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `202506L` [P3552R3](https://wg21.link/P3552R3) Add a Coroutine Task Type
  - `202506L` [P3927R2](https://wg21.link/P3927R2) `task_scheduler` support for
  parallel `bulk` execution
  - `202506L` [P3941R4](https://wg21.link/P3941R4) Scheduler Affinity
  - `202506L` [P3980R1](https://wg21.link/P3980R1) Task's Allocator Use
  - `202506L` [P4151R1 __PDF__](https://wg21.link/P4151R1) Rename `affine_on`

  @sa `<execution>`
*/
#ifndef LBAL_LIBCPP26_TASK
  #define LBAL_LIBCPP26_TASK 0
#endif

/**
  @def LBAL_LIBCPP26_TEXT_ENCODING
  @brief Naming Text Encodings to Demystify Them
  @details SD-6 equivalent: `__cpp_lib_text_encoding >= 202306L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202306L` [P1885R12 __PDF__](https://wg21.link/P1885R12) Naming Text
  Encodings to Demystify Them

  @sa `<text_encoding>`
*/
#ifndef LBAL_LIBCPP26_TEXT_ENCODING
  #define LBAL_LIBCPP26_TEXT_ENCODING 0
#endif

/**
  @def LBAL_LIBCPP26_TO_CHARS_BOOL_TEST
  @brief Test for success or failure of `<charconv>` functions
  @details SD-6 equivalent: `__cpp_lib_to_chars >= 202306L`. Note that
  `__cpp_lib_to_chars` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P2497R0](https://wg21.link/P2497R0) Testing for success or
  failure of `<charconv>` functions

  @sa `<charconv>`
*/
#ifndef LBAL_LIBCPP26_TO_CHARS_BOOL_TEST
  #define LBAL_LIBCPP26_TO_CHARS_BOOL_TEST 0
#endif

/**
  @def LBAL_LIBCPP26_TO_STRING
  @brief to_string or not to_string
  @details SD-6 equivalent: `__cpp_lib_to_string >= 202306L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202306L` [P2587R3](https://wg21.link/P2587R3) `to_string` or not
  `to_string`

  @sa `<string>`
*/
#ifndef LBAL_LIBCPP26_TO_STRING
  #define LBAL_LIBCPP26_TO_STRING 0
#endif

/**
  @def LBAL_LIBCPP26_TUPLE_LIKE_COMPLEX
  @brief Add tuple protocol to complex
  @details SD-6 equivalent: `__cpp_lib_tuple_like >= 202311L`. Note that
  `__cpp_lib_tuple_like` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202311L` [P2819R2 __PDF__](https://wg21.link/P2819R2) Add tuple protocol
  to complex

  @sa `<map>` `<tuple>` `<unordered_map>` `<utility>`
*/
#ifndef LBAL_LIBCPP26_TUPLE_LIKE_COMPLEX
  #define LBAL_LIBCPP26_TUPLE_LIKE_COMPLEX 0
#endif

/**
  @def LBAL_LIBCPP26_TYPE_ORDER
  @brief Standardized Constexpr Type Ordering
  @details SD-6 equivalent: `__cpp_lib_type_order >= 202506L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202506L` [P2830R10](https://wg21.link/P2830R10) Standardized Constexpr
  Type Ordering
  - `202506L` [P3778R0](https://wg21.link/P3778R0) Fix for `type_order` template
  definition
  - `202506L` [P4140R0](https://wg21.link/P4140R0) Proposed resolution for
  US70-126: allow incomplete types in type_order

  @sa `<compare>`
*/
#ifndef LBAL_LIBCPP26_TYPE_ORDER
  #define LBAL_LIBCPP26_TYPE_ORDER 0
#endif

/**
  @def LBAL_LIBCPP26_VALARRAY
  @brief Resolve inconsistencies in begin/end for valarray and braced
  initializer lists
  @details SD-6 equivalent: `__cpp_lib_valarray >= 202511L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202511L` [P3016R6](https://wg21.link/P3016R6) Resolve inconsistencies in
  begin/end for `valarray` and braced initializer lists

  @sa `<valarray>`
*/
#ifndef LBAL_LIBCPP26_VALARRAY
  #define LBAL_LIBCPP26_VALARRAY 0
#endif

/**
  @def LBAL_LIBCPP26_VARIANT_VISITOR
  @brief Member visit for `std::variant`
  @details SD-6 equivalent: `__cpp_lib_variant >= 202306L`. Note that
  `__cpp_lib_variant` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P2637R3](https://wg21.link/P2637R3) Member `visit`

  @sa `<variant>`
*/
#ifndef LBAL_LIBCPP26_VARIANT_VISITOR
  #define LBAL_LIBCPP26_VARIANT_VISITOR 0
#endif

///	@}	LBAL_LIBCPP26

///	@}	lbal_library
