/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFeatureSetup-overview-libcpp17.inc”
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
  @name LBAL_LIBCPP17
  A large number of C++17 Standard Library features are not available in
  the implementations bundled with otherwise-conforming C++17 compilers.
  Additionally, sometimes support is simply broken or has surprising
  limitations, presenting further challenges. Here we track and document all
  such situations we’re aware of.

  @{
*/

/**
  @def LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR
  @brief Make `std::addressof` `constexpr`, as per defect report
  @details SD-6 equivalent: `__cpp_lib_addressof_constexpr >= 201603L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201603L` [LWG2296](https://wg21.link/LWG2296) `std::addressof` should be
  `constexpr`

  @sa `freestanding` `<memory>`
*/
#ifndef LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR
  #define LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR 0
#endif

/**
  @def LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL
  @brief Clean up `noexcept` usage (Rev 3)
  @details SD-6 equivalent: `__cpp_lib_allocator_traits_is_always_equal >=
  201411L`. This token will have a value of `0` if the proposal described here
  is not supported.
  - `201411L` [N4258](https://wg21.link/N4258) *PDF* Cleaning up noexcept in the
  Library (Rev 3)

  @sa `<deque>` `<forward_list>` `freestanding` `<list>` `<map>` `<memory>`
  `<scoped_allocator>` `<set>` `<string>` `<unordered_map>` `<unordered_set>`
  `<vector>`
*/
#ifndef LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL
  #define LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL 0
#endif

/**
  @def LBAL_LIBCPP17_ANY
  @brief `<any>` components from Library Fundamentals V1 TS
  @details SD-6 equivalent: `__cpp_lib_any >= 201603L`. Note that
  `__cpp_lib_any` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201603L` [P0220R1](https://wg21.link/P0220R1) Adopt Library Fundamentals V1
  TS Components for C++17 (R1)

  @remark (APIME) We do not track experimental versions of this.

  @sa `<any>`
*/
#ifndef LBAL_LIBCPP17_ANY
  #define LBAL_LIBCPP17_ANY 0
#endif

/**
  @def LBAL_LIBCPP17_ANY_INTERFACE
  @brief Impose homogeneous interface for `std::variant`, `std::any` and
  `std::optional` (Rev 3)
  @details SD-6 equivalent: `__cpp_lib_any >= 201606L`. Note that
  `__cpp_lib_any` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201606L` [P0032R3](https://wg21.link/P0032R3) *PDF* Homogeneous interface
  for `variant`, `any` and `optional` (Revision 3)

  @remark (APIME) We do not track experimental versions of this.

  @sa `<any>`
*/
#ifndef LBAL_LIBCPP17_ANY_INTERFACE
  #define LBAL_LIBCPP17_ANY_INTERFACE 0
#endif

/**
  @def LBAL_LIBCPP17_APPLY
  @brief `std::apply` component from Library Fundamentals V1 TS
  @details SD-6 equivalent: `__cpp_lib_apply >= 201603L`. Note that
  `__cpp_lib_apply` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201603L` [P0220R1](https://wg21.link/P0220R1) Adopt Library Fundamentals V1
  TS Components for C++17 (R1)

  @sa `freestanding` `<tuple>` `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_APPLY
  #define LBAL_LIBCPP17_APPLY 0
#endif

/**
  @def LBAL_LIBCPP17_ARRAY_CONSTEXPR
  @brief Add `constexpr` modifiers to `std::reverse_iterator`,
  `std::move_iterator`, `<array>` and Range Access types
  @details SD-6 equivalent: `__cpp_lib_array_constexpr >= 201603L`. Note that
  `__cpp_lib_array_constexpr` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201603L` [P0031R0](https://wg21.link/P0031R0) A Proposal to Add Constexpr
  Modifiers to reverse_iterator, move_iterator, array and Range Access

  @sa `<array>` `freestanding` `<iterator>`
*/
#ifndef LBAL_LIBCPP17_ARRAY_CONSTEXPR
  #define LBAL_LIBCPP17_ARRAY_CONSTEXPR 0
#endif

/**
  @def LBAL_LIBCPP17_AS_CONST
  @brief Add `std::as_const` helper function template
  @details SD-6 equivalent: `__cpp_lib_as_const >= 201510L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201510L` [P0007R1](https://wg21.link/P0007R1) Constant View: A proposal for
  a `std::as_const` helper function template

  @sa `freestanding` `<utility>`
*/
#ifndef LBAL_LIBCPP17_AS_CONST
  #define LBAL_LIBCPP17_AS_CONST 0
#endif

/**
  @def LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE
  @brief Add `constexpr` `atomic<T>::is_always_lock_free`
  @details SD-6 equivalent: `__cpp_lib_atomic_is_always_lock_free >= 201603L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201603L` [P0152R1](https://wg21.link/P0152R1) `constexpr
  atomic<T>::is_always_lock_free`

  @sa `<atomic>` `freestanding`
*/
#ifndef LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE
  #define LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE 0
#endif

/**
  @def LBAL_LIBCPP17_BOOL_CONSTANT
  @brief Introduce `std::bool_constant`
  @details SD-6 equivalent: `__cpp_lib_bool_constant >= 201505L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201505L` [N4389](https://wg21.link/N4389) Wording for bool_constant,
  revision 1

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_BOOL_CONSTANT
  #define LBAL_LIBCPP17_BOOL_CONSTANT 0
#endif

/**
  @def LBAL_LIBCPP17_BOYER_MOORE_SEARCHER
  @brief Add text search components from Library Fundamentals V1 TS
  @details SD-6 equivalent: `__cpp_lib_boyer_moore_searcher >= 201603L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201603L` [P0220R1](https://wg21.link/P0220R1) Adopt Library Fundamentals V1
  TS Components for C++17 (R1)

  @sa `<functional>`
*/
#ifndef LBAL_LIBCPP17_BOYER_MOORE_SEARCHER
  #define LBAL_LIBCPP17_BOYER_MOORE_SEARCHER 0
#endif

/**
  @def LBAL_LIBCPP17_BYTE
  @brief Define `std::byte` type
  @details SD-6 equivalent: `__cpp_lib_byte >= 201603L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `201603L` [P0298R3](https://wg21.link/P0298R3) *PDF* A byte type definition

  @sa `<cstddef>` `freestanding`
*/
#ifndef LBAL_LIBCPP17_BYTE
  #define LBAL_LIBCPP17_BYTE 0
#endif

/**
  @def LBAL_LIBCPP17_CHRONO
  @brief Rounding and `abs` fixes for `<chrono>`
  @details SD-6 equivalent: `__cpp_lib_chrono >= 201510L`. Note that
  `__cpp_lib_chrono` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201510L` [P0092R1](https://wg21.link/P0092R1) Polishing `<chrono>`

  @sa `<chrono>`
*/
#ifndef LBAL_LIBCPP17_CHRONO
  #define LBAL_LIBCPP17_CHRONO 0
#endif

/**
  @def LBAL_LIBCPP17_CHRONO_CONSTEXPR
  @brief Add `constexpr` to certain `<chrono>` functions
  @details SD-6 equivalent: `__cpp_lib_chrono >= 201611L`. Note that
  `__cpp_lib_chrono` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201611L` [P0505R0](https://wg21.link/P0505R0) Wording for GB 50

  @sa `<chrono>`
*/
#ifndef LBAL_LIBCPP17_CHRONO_CONSTEXPR
  #define LBAL_LIBCPP17_CHRONO_CONSTEXPR 0
#endif

/**
  @def LBAL_LIBCPP17_CLAMP
  @brief Standard clamping algorithm
  @details SD-6 equivalent: `__cpp_lib_clamp >= 201603L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `201603L` [P0025R1](https://wg21.link/P0025R1) An algorithm to "clamp" a
  value between a pair of boundary values (revision 2)

  @sa `<algorithm>` `freestanding`
*/
#ifndef LBAL_LIBCPP17_CLAMP
  #define LBAL_LIBCPP17_CLAMP 0
#endif

/**
  @def LBAL_LIBCPP17_CONSTEXPR_STRING
  @brief Make `std::char_traits` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_string >= 201611L`. Note that
  `__cpp_lib_constexpr_string` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201611L` [P0426R1](https://wg21.link/P0426R1) Constexpr for
  std::char_traits

  @sa `<string>`
*/
#ifndef LBAL_LIBCPP17_CONSTEXPR_STRING
  #define LBAL_LIBCPP17_CONSTEXPR_STRING 0
#endif

/**
  @def LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW
  @brief Make `std::char_traits` `constexpr`
  @details SD-6 equivalent: `__cpp_lib_constexpr_string_view >= 201611L`. Note
  that `__cpp_lib_constexpr_string_view` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `201611L` [P0426R1](https://wg21.link/P0426R1) Constexpr for
  std::char_traits

  @sa `<string_view>`
*/
#ifndef LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW
  #define LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW 0
#endif

/**
  @def LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS
  @brief Re-enable `std::shared_from_this`
  @details SD-6 equivalent: `__cpp_lib_enable_shared_from_this >= 201603L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201603L` [P0033R1](https://wg21.link/P0033R1) Re-enabling
  `shared_from_this` (revision 1)

  @remark (SEEME - bitweeder) Prior to the December 2019 release, the
  official SD-6 doc contains an error wherein this token is mistakenly tied
  to [P0074R0](https://wg21.link/P0074R0), a different proposal dealing
  with `std::owner_less`. We reflect the correct proposal here, but the date
  associated with this token may be incorrect.

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS
  #define LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS 0
#endif

/**
  @def LBAL_LIBCPP17_EXECUTION
  @brief Add Library components of the Parallelism TS
  @details SD-6 equivalent: `__cpp_lib_execution >= 201603L`. Note that
  `__cpp_lib_execution` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201603L` [P0024R2](https://wg21.link/P0024R2) The Parallelism TS Should
  be Standardized

  @remark (APIME) We do not track experimental versions of this.

  @remark By itself, this token does not measure compliance with the referenced
  Working Group paper; use LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS.

  @sa `<execution>`
*/
#ifndef LBAL_LIBCPP17_EXECUTION
  #define LBAL_LIBCPP17_EXECUTION 0
#endif

/**
  @def LBAL_LIBCPP17_FILESYSTEM
  @brief Adopt File System TS
  @details SD-6 equivalent: `__cpp_lib_filesystem >= 201603L`. Note that
  `__cpp_lib_filesystem` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201603L` [P0218R1](https://wg21.link/P0218R1) Adopt File System TS for
  C++17

  @remark (SEEME - bitweeder) Full implementation missing on Apple platforms
  prior to macOS 10.15.

  @sa `<filesystem>`
*/
#ifndef LBAL_LIBCPP17_FILESYSTEM
  #define LBAL_LIBCPP17_FILESYSTEM 0
#endif

/**
  @def LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING
  @brief Add directory entry caching to `<filesystem>`
  @details SD-6 equivalent: `__cpp_lib_filesystem >= 201703L`. Note that
  `__cpp_lib_filesystem` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201703L` [P0317R1](https://wg21.link/P0317R1) Directory Entry Caching for
  Filesystem

  @remark (SEEME - bitweeder) Full implementation missing on Apple platforms
  prior to macOS 10.15.

  @sa `<filesystem>`
*/
#ifndef LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING
  #define LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING 0
#endif

/**
  @def LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED
  @brief Add relative path and `std::string_view` support to `<filesystem>`
  @details SD-6 equivalent: `__cpp_lib_filesystem >= 201606L`. Note that
  `__cpp_lib_filesystem` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201606L` [P0392R0](https://wg21.link/P0392R0) *PDF* Adapting string_view by
  filesystem paths

  @remark (SEEME - bitweeder) Full implementation missing on Apple platforms
  prior to macOS 10.15.

  @sa `<filesystem>`
*/
#ifndef LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED
  #define LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED 0
#endif

/**
  @def LBAL_LIBCPP17_FILESYSTEM_RELATIVE_PATHS
  @brief Relative Paths for Filesystem
  @details SD-6 equivalent: `__cpp_lib_filesystem >= 201606L`. Note that
  `__cpp_lib_filesystem` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201606L` [P0219R1](https://wg21.link/P0219R1) Relative Paths for Filesystem

  @sa `<filesystem>`
*/
#ifndef LBAL_LIBCPP17_FILESYSTEM_RELATIVE_PATHS
  #define LBAL_LIBCPP17_FILESYSTEM_RELATIVE_PATHS 0
#endif

/**
  @def LBAL_LIBCPP17_GCD_LCM
  @brief Add `std::gcd` and `std::lcm`
  @details SD-6 equivalent: `__cpp_lib_gcd_lcm >= 201606L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `201606L` [P0295R0](https://wg21.link/P0295R0) *PDF* Adopt Selected Library
  Fundamentals V2 Components for C++17

  @sa `freestanding` `<numeric>`
*/
#ifndef LBAL_LIBCPP17_GCD_LCM
  #define LBAL_LIBCPP17_GCD_LCM 0
#endif

/**
  @def LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE
  @brief Provide relevant cache line sizes for construction and destruction.
  @details SD-6 equivalent: `__cpp_lib_hardware_interference_size >= 201703L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201703L` [P0154R1](https://wg21.link/P0154R1) constexpr
  std::thread::hardware_{true,false}_sharing_size

  @remark Note that you may have ABI instability if you rely on this since its
  value is affected by the target and `-mtune`/`-mcpu` (or equivalent flags,
  depending on the compiler).

  @sa `freestanding` `<new>`
*/
#ifndef LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE
  #define LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE 0
#endif

/**
  @def LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS
  @brief Add `std::has_unique_object_representations`
  @details This obliquely-named trait indicates whether a given type can be
  trivially hashed (e.g., it has no padding bits that would require special
  handling).

  SD-6 equivalent: `__cpp_lib_has_unique_object_representations >= 201606L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201606L` [P0258R2](https://wg21.link/P0258R2)
  has_unique_object_representations - wording

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS
  #define LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS 0
#endif

/**
  @def LBAL_LIBCPP17_HYPOT
  @brief Introduce a 3-argument overload to `std::hypot`
  @details This standardizes finding 3-dimensional distance as well as
  2-dimensional distance.

  SD-6 equivalent: `__cpp_lib_hypot >= 201603L`. This token will have a value of
  `0` if the proposal described here is not supported.
  - `201603L` [P0030R1](https://wg21.link/P0030R1) *PDF* Proposal to Introduce a
  3-Argument Overload to `std::hypot`

  @sa `<cmath>`
*/
#ifndef LBAL_LIBCPP17_HYPOT
  #define LBAL_LIBCPP17_HYPOT 0
#endif

/**
  @def LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS
  @brief Introduce minimal incomplete type support for Standard containers
  @details SD-6 equivalent: `__cpp_lib_incomplete_container_elements >=
  201505L`. This token will have a value of `0` if the proposal described here
  is not supported.
  - `201505L` [N4510](https://wg21.link/N4510) Minimal incomplete type support
  for standard containers, revision 4

  @sa `<forward_list>` `<list>` `<vector>`
*/
#ifndef LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS
  #define LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS 0
#endif

/**
  @def LBAL_LIBCPP17_INVOKE
  @brief Add `std::invoke` function template
  @details SD-6 equivalent: `__cpp_lib_invoke >= 201411L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `201411L` [N4169](https://wg21.link/N4169) A proposal to add invoke function
  template (Revision 1)

  @sa `freestanding` `<functional>`
*/
#ifndef LBAL_LIBCPP17_INVOKE
  #define LBAL_LIBCPP17_INVOKE 0
#endif

/**
  @def LBAL_LIBCPP17_IS_AGGREGATE
  @brief Add `std::is_aggregate` type trait
  @details SD-6 equivalent: `__cpp_lib_is_aggregate >= 201703L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201703L` [LWG2911](https://wg21.link/LWG2911) An `is_aggregate` type trait
  is needed

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_IS_AGGREGATE
  #define LBAL_LIBCPP17_IS_AGGREGATE 0
#endif

/**
  @def LBAL_LIBCPP17_IS_INVOCABLE
  @brief Add `std::is_invocable` type trait to replace `is_callable`
  @details SD-6 equivalent: `__cpp_lib_is_invocable >= 201703L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201703L` [P0604R0](https://wg21.link/P0604R0) Resolving GB 55, US 84, US
  85, US 86

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_IS_INVOCABLE
  #define LBAL_LIBCPP17_IS_INVOCABLE 0
#endif

/**
  @def LBAL_LIBCPP17_IS_SWAPPABLE
  @brief Add `std::is_swappable` type trait family
  @details SD-6 equivalent: `__cpp_lib_is_swappable >= 201603L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201603L` [P0185R1](https://wg21.link/P0185R1) Adding [nothrow-]swappable
  traits, revision 3

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_IS_SWAPPABLE
  #define LBAL_LIBCPP17_IS_SWAPPABLE 0
#endif

/**
  @def LBAL_LIBCPP17_LAUNDER
  @brief Replacement of class objects containing reference members
  @details SD-6 equivalent: `__cpp_lib_launder >= 201606L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `201606L` [P0137R1](https://wg21.link/P0137R1) Core Issue 1776: Replacement
  of class objects containing reference members

  @sa `freestanding` `<new>`
*/
#ifndef LBAL_LIBCPP17_LAUNDER
  #define LBAL_LIBCPP17_LAUNDER 0
#endif

/**
  @def LBAL_LIBCPP17_LOGICAL_TRAITS
  @brief Provide type traits for performing logical operations
  @details SD-6 equivalent: `__cpp_lib_logical_traits >= 201510L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201510L` [P0013R1](https://wg21.link/P0013R1) Logical Operator Type Traits
  (revison 1)

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_LOGICAL_TRAITS
  #define LBAL_LIBCPP17_LOGICAL_TRAITS 0
#endif

/**
  @def LBAL_LIBCPP17_MAKE_FROM_TUPLE
  @brief Introduce `std::make_from_tuple` to unpack a tuple into arguments
  @details SD-6 equivalent: `__cpp_lib_make_from_tuple >= 201606L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201606L` [P0209R2](https://wg21.link/P0209R2) *PDF* `make_from_tuple`:
  `apply` for construction

  @sa `freestanding` `<tuple>`
*/
#ifndef LBAL_LIBCPP17_MAKE_FROM_TUPLE
  #define LBAL_LIBCPP17_MAKE_FROM_TUPLE 0
#endif

/**
  @def LBAL_LIBCPP17_MAP_TRY_EMPLACE
  @brief Improve insertion into `std::map`
  @details SD-6 equivalent: `__cpp_lib_map_try_emplace >= 201411L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201411L` [N4279](https://wg21.link/N4279) Improved insertion interface for
  unique-key maps (Revision 2.3)

  @sa `<map>`
*/
#ifndef LBAL_LIBCPP17_MAP_TRY_EMPLACE
  #define LBAL_LIBCPP17_MAP_TRY_EMPLACE 0
#endif

/**
  @def LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS
  @brief Incorporate math functions specified in IS 29124:2010
  @details SD-6 equivalent: `__cpp_lib_math_special_functions >= 201603L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201603L` [P0226R1](https://wg21.link/P0226R1) *PDF* Mathematical Special
  Functions for C++17, v5

  @sa `<cmath>`
*/
#ifndef LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS
  #define LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS 0
#endif

/**
  @def LBAL_LIBCPP17_MEMORY_RESOURCE
  @brief Incorporate memory management components from Library Fundamentals
  V1 TS
  @details SD-6 equivalent: `__cpp_lib_memory_resource >= 201603L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201603L` [P0220R1](https://wg21.link/P0220R1) Adopt Library Fundamentals V1
  TS Components for C++17 (R1)

  @sa `<memory_resource>`
*/
#ifndef LBAL_LIBCPP17_MEMORY_RESOURCE
  #define LBAL_LIBCPP17_MEMORY_RESOURCE 0
#endif

/**
  @def LBAL_LIBCPP17_NODE_EXTRACT
  @brief Add splicing to associative containers
  @details SD-6 equivalent: `__cpp_lib_node_extract >= 201606L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201606L` [P0083R3](https://wg21.link/P0083R3) *PDF* Splicing Maps and Sets
  (Revision 5)

  @sa `<map>` `<set>` `<unordered_map>` `<unordered_set>`
*/
#ifndef LBAL_LIBCPP17_NODE_EXTRACT
  #define LBAL_LIBCPP17_NODE_EXTRACT 0
#endif

/**
  @def LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS
  @brief Incorporate non-member functions into Standard container class
  interfaces
  @details SD-6 equivalent: `__cpp_lib_nonmember_container_access >= 201411L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201411L` [N4280](https://wg21.link/N4280) *PDF* Non-member size() and more
  (Revison 2)

  @sa `<array>` `<deque>` `<forward_list>` `freestanding` `<iterator>` `<list>`
  `<map>` `<regex>` `<set>` `<string>` `<unordered_map>` `<unordered_set>`
  `<vector>`
*/
#ifndef LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS
  #define LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS 0
#endif

/**
  @def LBAL_LIBCPP17_NOT_FN
  @brief Add `std::not_fn`
  @details SD-6 equivalent: `__cpp_lib_not_fn >= 201603L`. Note that
  `__cpp_lib_not_fn` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201603L` [P0005R4](https://wg21.link/P0005R4) Adopt `not_fn` from Library
  Fundamentals 2 for C++17

  @sa `freestanding` `<functional>`
*/
#ifndef LBAL_LIBCPP17_NOT_FN
  #define LBAL_LIBCPP17_NOT_FN 0
#endif

/**
  @def LBAL_LIBCPP17_OPTIONAL
  @brief Add `std::optional`
  @details SD-6 equivalent: `__cpp_lib_optional >= 201603L`. Note that
  `__cpp_lib_optional` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201603L` [P0220R1](https://wg21.link/P0220R1) Adopt Library Fundamentals V1
  TS Components for C++17 (R1)

  @sa `<optional>`
*/
#ifndef LBAL_LIBCPP17_OPTIONAL
  #define LBAL_LIBCPP17_OPTIONAL 0
#endif

/**
  @def LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL
  @brief Homogenize `std::optional` interface with `std::any` and `std::variant`
  @details SD-6 equivalent: `__cpp_lib_optional >= 201606L`. Note that
  `__cpp_lib_optional` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201606L` [P0032R3](https://wg21.link/P0032R3) *PDF* Homogeneous interface
  for `variant`, `any` and `optional` (Revision 3)

  @remark Note that the [`P0032R3`](https://wg21.link/P0032R3) and
  [`P0307R2`](https://wg21.link/P0307R2) proposals were approved at the same
  time, and hence shared a token value. While we provide separate features for
  `LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL` and `LBAL_LIBCPP17_OPTIONAL_INTERFACE`,
  they’re not actually differentiated by the SD-6 rules (though they might be at
  the platform level).

  @sa `<optional>`
*/
#ifndef LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL
  #define LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL 0
#endif

/**
  @def LBAL_LIBCPP17_OPTIONAL_INTERFACE
  @brief Homogenize `std::optional` interface with `std::any` and `std::variant`
  @details SD-6 equivalent: `__cpp_lib_optional >= 201606L`. Note that
  `__cpp_lib_optional` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201606L` [P0307R2](https://wg21.link/P0307R2) *PDF* Making Optional Greater
  Equal Again

  @remark Note that the [`P0032R3`](https://wg21.link/P0032R3) and
  [`P0307R2`](https://wg21.link/P0307R2) proposals were approved at the same
  time, and hence shared a token value. While we provide separate features for
  `LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL` and `LBAL_LIBCPP17_OPTIONAL_INTERFACE`,
  they’re not actually differentiated by the SD-6 rules (though they might be at
  the platform level).

  @sa `<optional>`
*/
#ifndef LBAL_LIBCPP17_OPTIONAL_INTERFACE
  #define LBAL_LIBCPP17_OPTIONAL_INTERFACE 0
#endif

/**
  @def LBAL_LIBCPP17_PARALLEL_ALGORITHM
  @brief Standardize the Parallelism TS
  @details SD-6 equivalent: `__cpp_lib_parallel_algorithm >= 201603L`. Note that
  `__cpp_lib_parallel_algorithm` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201603L` [P0024R2](https://wg21.link/P0024R2) The Parallelism TS Should
  be Standardized

  @remark (APIME) We do not track experimental versions of this.

  @remark By itself, this macro does not measure compliance
  with the original Working Group paper; for that, use
  LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS.

  @sa `<algorithm>` `<memory>` `<numeric>`
*/
#ifndef LBAL_LIBCPP17_PARALLEL_ALGORITHM
  #define LBAL_LIBCPP17_PARALLEL_ALGORITHM 0
#endif

/**
  @def LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS
  @brief Supply tools for raw memory management
  @details SD-6 equivalent: `__cpp_lib_raw_memory_algorithms >= 201606L`. Note
  that `__cpp_lib_raw_memory_algorithms` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `201606L` [P0040R3](https://wg21.link/P0040R3) Extending memory management
  tools

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS
  #define LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS 0
#endif

/**
  @def LBAL_LIBCPP17_SAMPLE
  @brief Adopt `std::sample` from the Library Fundamentals V1 TS
  @details SD-6 equivalent: `__cpp_lib_sample >= 201603L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `201603L` [P0220R1](https://wg21.link/P0220R1) Adopt Library Fundamentals V1
  TS Components for C++17 (R1)

  @sa `<algorithm>` `freestanding`
*/
#ifndef LBAL_LIBCPP17_SAMPLE
  #define LBAL_LIBCPP17_SAMPLE 0
#endif

/**
  @def LBAL_LIBCPP17_SCOPED_LOCK
  @brief Add a variadic variant of `std::lock_guard` under a new name
  @details SD-6 equivalent: `__cpp_lib_scoped_lock >= 201703L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201703L` [P0156R2](https://wg21.link/P0156R2) Variadic lock_guard (Rev. 4)

  @remark It was determined that simply making `std::lock_guard` variadic would
  break ABI, hence the name change.

  @sa `<mutex>`
*/
#ifndef LBAL_LIBCPP17_SCOPED_LOCK
  #define LBAL_LIBCPP17_SCOPED_LOCK 0
#endif

/**
  @def LBAL_LIBCPP17_SHARED_MUTEX
  @brief Officially change `std::shared_mutex` to an untimed mutex
  @details This change was corresponds to the addition of an explicit
  `std::shared_timed_mutex`.

  SD-6 equivalent: `__cpp_lib_shared_mutex >= 201505L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `201505L` [N4508](https://wg21.link/N4508) A proposal to add shared_mutex
  (untimed) (Revision 4)

  @sa `<shared_mutex>`
*/
#ifndef LBAL_LIBCPP17_SHARED_MUTEX
  #define LBAL_LIBCPP17_SHARED_MUTEX 0
#endif

/**
  @def LBAL_LIBCPP17_SHARED_PTR_ARRAYS
  @brief Fix `std::shared_ptr` support for arrays
  @details SD-6 equivalent: `__cpp_lib_shared_ptr_arrays >= 201611L`. Note that
  `__cpp_lib_shared_ptr_arrays` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201611L` [P0497R0](https://wg21.link/P0497R0) Fixes to shared_ptr support
  for arrays

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP17_SHARED_PTR_ARRAYS
  #define LBAL_LIBCPP17_SHARED_PTR_ARRAYS 0
#endif

/**
  @def LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE
  @brief Add `shared_ptr::weak_type`
  @details SD-6 equivalent: `__cpp_lib_shared_ptr_weak_type >= 201606L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201606L` [P0163R0](https://wg21.link/P0163R0) shared_ptr::weak_type

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE
  #define LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE 0
#endif

/**
  @def LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS
  @brief Track full compliance with the Parallelism Standard
  @details This token tracks compliance with the Standard as it relates to
  implementing the referenced Working Group paper; there is no correspoding
  SD-6 macro, or rather, there are _two_ relevant macros which each track
  the different features required for compliance. We actually track both
  of those, as well as this meta-feature, separately. As such, this token
  represents an aggregate condition: if both `LBAL_LIBCPP17_EXECUTION` and
  `LBAL_LIBCPP17_PARALLEL_ALGORITHM` indicate compliance, this gets set to `1`;
  otherwise, it’s set to `0`.

  @remark (APIME) We do not track experimental versions of this, partly because
  the Draft versions tracked a different set of features, in different places,
  which were refactored/replaced.

  @remark (SEEME - bitweeder) We do not check compliance with iterations on the
  constituent components (e.g., `LBAL_LIBCPP20_EXECUTION_VECTORIZATION`), only
  that we have met the base requirements for supporting Parallelism. Extending
  tracking is one option; another is to eliminate this meta-token to avoid
  over-complicating things.
*/
#ifndef LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS
  #define LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS 0
#endif

/**
  @def LBAL_LIBCPP17_STRING_VIEW
  @brief Adopt `std::string_view` from the Library Fundamentals V1 TS
  @details SD-6 equivalent: `__cpp_lib_string_view >= 201603L`. Note that
  `__cpp_lib_string_view` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201603L` [P0220R1](https://wg21.link/P0220R1) Adopt Library Fundamentals V1
  TS Components for C++17 (R1)

  @sa `<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP17_STRING_VIEW
  #define LBAL_LIBCPP17_STRING_VIEW 0
#endif

/**
  @def LBAL_LIBCPP17_STRING_VIEW_INTERFACE
  @brief Address interface inversion between `<string>` and `<string_view>`
  @details SD-6 equivalent: `__cpp_lib_string_view >= 201606L`. Note that
  `__cpp_lib_string_view` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201606L` [P0254R2](https://wg21.link/P0254R2) *PDF* Integrating
  `std::string_view` and `std::string`

  @sa `<string>` `<string_view>`
*/
#ifndef LBAL_LIBCPP17_STRING_VIEW_INTERFACE
  #define LBAL_LIBCPP17_STRING_VIEW_INTERFACE 0
#endif

/**
  @def LBAL_LIBCPP17_TO_CHARS
  @brief Elementary string conversions, revision 5
  @details This token tracks compliance with both the integer and floating-point
  tokens for `to_chars` and `from_chars`.

  SD-6 equivalent: `__cpp_lib_to_chars >= 201611L`. Note that
  `__cpp_lib_to_chars` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201611L` [LWG3137](https://wg21.link/LWG3137) Header for
  `__cpp_lib_to_chars`
  - `201611L` [P0067R5](https://wg21.link/P0067R5) Elementary string
  conversions, revision 5
  - `201611L` [P0682R1](https://wg21.link/P0682R1) Repairing elementary string
  conversions

  @remark (SEEME - bitweeder) This got weird since the functions were moved to
  their own header and their signatures were altered, post-Standardization, all
  as part of a Defect Report resolution.

  @remark (SEEME - bitweeder) This got weirder since multiple major
  implementations falsely set their SD-6 macros as if they are in full
  compliance, when they actually only support integer conversions. This is
  reflected by the creation of two tokens that feed into this one, despite there
  only being one underlying SD-6 macro.

  @remark Effectively, this is a superset of `LBAL_LIBCPP17_TO_CHARS_INTEGER`,
  `LBAL_LIBCPP17_TO_CHARS_FP`, and support for outputting `long double`s.

  @sa `<charconv>`
*/
#ifndef LBAL_LIBCPP17_TO_CHARS
  #define LBAL_LIBCPP17_TO_CHARS 0
#endif

/**
  @def LBAL_LIBCPP17_TO_CHARS_FP
  @brief Floating-point compliance with Elementary string conversions
  @details This tracks the floating-point conversion portion of
  `LBAL_LIBCPP17_TO_CHARS`.

  SD-6 equivalent: `__cpp_lib_to_chars >= 201611L`. Note that
  `__cpp_lib_to_chars` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201611L` [LWG3137](https://wg21.link/LWG3137) Header for
  `__cpp_lib_to_chars`
  - `201611L` [P0067R5](https://wg21.link/P0067R5) Elementary string
  conversions, revision 5
  - `201611L` [P0682R1](https://wg21.link/P0682R1) Repairing elementary string
  conversions

  @remark (SEEME - bitweeder) This got weird since the functions were moved to
  their own header and their signatures were altered, post-Standardization, all
  as part of a Defect Report resolution.

  @remark (SEEME - bitweeder) This got weirder since multiple major
  implementations falsely set their SD-6 macros as if they are in full
  compliance, when they actually only support integer conversions. This is
  reflected by the creation of two tokens that feed into this one, despite there
  only being one underlying SD-6 macro.

  @remark This specifically does not imply support for outputting `long
  double`s.

  @sa `<charconv>`
*/
#ifndef LBAL_LIBCPP17_TO_CHARS_FP
  #define LBAL_LIBCPP17_TO_CHARS_FP 0
#endif

/**
  @def LBAL_LIBCPP17_TO_CHARS_INTEGER
  @brief Integer compliance with Elementary string conversions
  @details This tracks the integer conversion portion of
  `LBAL_LIBCPP17_TO_CHARS`.

  SD-6 equivalent: `__cpp_lib_to_chars >= 201611L`. Note that
  `__cpp_lib_to_chars` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201611L` [LWG3137](https://wg21.link/LWG3137) Header for
  `__cpp_lib_to_chars`
  - `201611L` [P0067R5](https://wg21.link/P0067R5) Elementary string
  conversions, revision 5
  - `201611L` [P0682R1](https://wg21.link/P0682R1) Repairing elementary string
  conversions

  @remark (SEEME - bitweeder) This got weird since the functions were moved to
  their own header and their signatures were altered, post-Standardization, all
  as part of a Defect Report resolution.

  @remark (SEEME - bitweeder) This got weirder since multiple major
  implementations falsely set their SD-6 macros as if they are in full
  compliance, when they actually only support integer conversions. This is
  reflected by the creation of two tokens that feed into this one, despite there
  only being one underlying SD-6 macro.

  @sa `<charconv>`
*/
#ifndef LBAL_LIBCPP17_TO_CHARS_INTEGER
  #define LBAL_LIBCPP17_TO_CHARS_INTEGER 0
#endif

/**
  @def LBAL_LIBCPP17_TRANSPARENT_OPERATORS
  @brief Make `std::owner_less` more flexible
  @details SD-6 equivalent: `__cpp_lib_transparent_operators >= 201510L`. Note
  that `__cpp_lib_transparent_operators` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `201510L` [P0074R0](https://wg21.link/P0074R0) Making std::owner_less more
  flexible

  @remark (SEEME - bitweeder) The official SD-6 doc prior to December 2019
  contains an error wherein this proposal and functionality are mistakenly tied
  to `__cpp_lib_enable_shared_from_this`.

  @sa `freestanding` `<functional>` `<memory>`
*/
#ifndef LBAL_LIBCPP17_TRANSPARENT_OPERATORS
  #define LBAL_LIBCPP17_TRANSPARENT_OPERATORS 0
#endif

/**
  @def LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES
  @brief Adopt variable templates for type traits from the Library Fundamentals
  V1 TS
  @details SD-6 equivalent: `__cpp_lib_type_trait_variable_templates >=
  201510L`. This token will have a value of `0` if the proposal described here
  is not supported.
  - `201510L` [P0006R0](https://wg21.link/P0006R0) Adopt Type Traits Variable
  Templates from Library Fundamentals TS for C++17

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES
  #define LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES 0
#endif

/**
  @def LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS
  @brief Add `std::uncaught_exceptions`
  @details SD-6 equivalent: `__cpp_lib_uncaught_exceptions >= 201411L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201411L` [N4259](https://wg21.link/N4259) *PDF* Wording for
  std::uncaught_exceptions

  @sa `<exception>` `freestanding`
*/
#ifndef LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS
  #define LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS 0
#endif

/**
  @def LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE
  @brief Improve insertion into `std::unordered_map`
  @details SD-6 equivalent: `__cpp_lib_unordered_map_try_emplace >= 201411L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201411L` [N4279](https://wg21.link/N4279) Improved insertion interface for
  unique-key maps (Revision 2.3)

  @sa `<unordered_map>`
*/
#ifndef LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE
  #define LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE 0
#endif

/**
  @def LBAL_LIBCPP17_VARIANT
  @brief Add `std::variant`
  @details SD-6 equivalent: `__cpp_lib_variant >= 201606L`. Note that
  `__cpp_lib_variant` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201606L` [P0032R3](https://wg21.link/P0032R3) *PDF* Homogeneous interface
  for `variant`, `any` and `optional` (Revision 3)
  - `201606L` [P0088R3](https://wg21.link/P0088R3) Variant: a type-safe union
  for C++17 (v8)
  - `201606L` [P0393R3](https://wg21.link/P0393R3) Making Variant Greater Equal

  @remark We track all three `202106L` proposals with one token, as they
  were all voted in at the same time, and no implementation we’re aware of
  implemented them piecemeal.

  @sa `<variant>`
*/
#ifndef LBAL_LIBCPP17_VARIANT
  #define LBAL_LIBCPP17_VARIANT 0
#endif

/**
  @def LBAL_LIBCPP17_VOID_T
  @brief Add `std::void_t` as a transformation type trait
  @details SD-6 equivalent: `__cpp_lib_void_t >= 201411L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `201411L` [N3911](https://wg21.link/N3911) *PDF* TransformationTrait Alias
  void_t

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP17_VOID_T
  #define LBAL_LIBCPP17_VOID_T 0
#endif

///	@}	LBAL_LIBCPP17

///	@}	lbal_library
