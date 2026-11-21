/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFeatureSetup-overview-libcpp2d.inc”
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
  @name LBAL_LIBCPP2D

  @brief These are all taken from features that have been incorporated into
  the C++2d Draft Standard.

  @remarks (FIXME - bitweeder) These are on hold till the associated proposals
  are published publicly.

  @{
*/

/**
  @def LBAL_LIBCPP2D_BITOPS_BETTER_SHIFTING
  @brief Better Shifting
  @details

  SD-6 equivalent: `__cpp_lib_bitops >= 202607L`. Note that `__cpp_lib_bitops`
  has multiple values associated with it from a number of different proposals,
  so this token will have the value of the latest supported proposal, or `0` if
  the proposal described here is not supported.
  - `202607L` [P3793R2](https://wg21.link/P3793R2) Better Shifting

  @sa `<bit>` `freestanding`
*/
#ifndef LBAL_LIBCPP2D_BITOPS_BETTER_SHIFTING
  #define LBAL_LIBCPP2D_BITOPS_BETTER_SHIFTING 0
#endif

/**
  @def LBAL_LIBCPP2D_BITOPS_PERMUTATIONS
  @brief Bit permutations
  @details

  SD-6 equivalent: `__cpp_lib_bitops >= 202607L`. Note that `__cpp_lib_bitops`
  has multiple values associated with it from a number of different proposals,
  so this token will have the value of the latest supported proposal, or `0` if
  the proposal described here is not supported.
  - `202607L` [P3104R6](https://wg21.link/P3104R6) Bit permutations

  @sa `<bit>` `freestanding`
*/
#ifndef LBAL_LIBCPP2D_BITOPS_PERMUTATIONS
  #define LBAL_LIBCPP2D_BITOPS_PERMUTATIONS 0
#endif

/**
  @def LBAL_LIBCPP2D_CONSTANT_WRAPPER_REVERT_STRING
  @brief Revert string support in `std::constant_wrapper`
  @details

  SD-6 equivalent: `__cpp_lib_constant_wrapper >= 202606L`. Note that
  `__cpp_lib_constant_wrapper` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202606L` [P4206R0](https://wg21.link/P4206R0) Revert string support in
  `std::constant_wrapper`

  @sa `freestanding` `<type_traits>` `<utility>`
*/
#ifndef LBAL_LIBCPP2D_CONSTANT_WRAPPER_REVERT_STRING
  #define LBAL_LIBCPP2D_CONSTANT_WRAPPER_REVERT_STRING 0
#endif

/**
  @def LBAL_LIBCPP2D_EXPECTED_UEXPECTED
  @brief The unexpected in `std::expected`
  @details

  SD-6 equivalent: `__cpp_lib_expected >= 202606L`. Note that
  `__cpp_lib_expected` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202606L` [P3798R1](https://wg21.link/P3798R1) The unexpected in
  `std::expected`

  @sa `<expected>`
*/
#ifndef LBAL_LIBCPP2D_EXPECTED_UEXPECTED
  #define LBAL_LIBCPP2D_EXPECTED_UEXPECTED 0
#endif

/**
  @def LBAL_LIBCPP2D_HAZARD_POINTER_BATCHES
  @brief Hazard Pointer Batches
  @details

  SD-6 equivalent: `__cpp_lib_hazard_pointer >= 202606L`. Note that
  `__cpp_lib_hazard_pointer` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202606L` [P3428R4 __PDF__](https://wg21.link/P3428R4) Hazard Pointer
  Batches

  @sa `<hazard_pointer>`
*/
#ifndef LBAL_LIBCPP2D_HAZARD_POINTER_BATCHES
  #define LBAL_LIBCPP2D_HAZARD_POINTER_BATCHES 0
#endif

/**
  @def LBAL_LIBCPP2D_MAP_LOOKUP
  @brief Better Lookups for `map`, `unordered_map`, and `flat_map`
  @details

  SD-6 equivalent: `__cpp_lib_map_lookup >= 202606L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `202606L` [P3091R6](https://wg21.link/P3091R6) Better Lookups for `map`,
  `unordered_map`, and `flat_map`
*/
#ifndef LBAL_LIBCPP2D_MAP_LOOKUP
  #define LBAL_LIBCPP2D_MAP_LOOKUP 0
#endif

/**
  @def LBAL_LIBCPP2D_MDSPAN_COPY
  @brief Copy and fill for `mdspan`
  @details

  SD-6 equivalent: `__cpp_lib_mdspan_copy >= 202606L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `202606L` [P3242R4](https://wg21.link/P3242R4) Copy and fill for `mdspan`
*/
#ifndef LBAL_LIBCPP2D_MDSPAN_COPY
  #define LBAL_LIBCPP2D_MDSPAN_COPY 0
#endif

/**
  @def LBAL_LIBCPP2D_POINTER_TAG_PAIR
  @brief `constexpr` pointer tagging
  @details

  SD-6 equivalent: `__cpp_lib_pointer_tag_pair >= 202606L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `202606L` [P3125R6](https://wg21.link/P3125R6) `constexpr` pointer tagging
*/
#ifndef LBAL_LIBCPP2D_POINTER_TAG_PAIR
  #define LBAL_LIBCPP2D_POINTER_TAG_PAIR 0
#endif

/**
  @def LBAL_LIBCPP2D_SIMD_BITOPS
  @brief `std::simd` overloads for `bit` permutations
  @details

  SD-6 equivalent: `__cpp_lib_simd_bitops >= 202607L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `202607L` [P3772R2](https://wg21.link/P3772R2) `std::simd` overloads for
  `bit` permutations
*/
#ifndef LBAL_LIBCPP2D_SIMD_BITOPS
  #define LBAL_LIBCPP2D_SIMD_BITOPS 0
#endif

/**
  @def LBAL_LIBCPP2D_SIMD_BITOPS_BETTER_SHIFTING
  @brief Better Shifting
  @details

  SD-6 equivalent: `__cpp_lib_simd_bitops >= 202607L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `202607L` [P3793R2](https://wg21.link/P3793R2) Better Shifting
*/
#ifndef LBAL_LIBCPP2D_SIMD_BITOPS_BETTER_SHIFTING
  #define LBAL_LIBCPP2D_SIMD_BITOPS_BETTER_SHIFTING 0
#endif

/**
  @def LBAL_LIBCPP2D_THREAD_ATTRIBUTES
  @brief Thread attributes
  @details

  SD-6 equivalent: `__cpp_lib_thread_attributes >= 202606L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202606L` [P2019R9 __PDF__](https://wg21.link/P2019R9) Thread attributes
*/
#ifndef LBAL_LIBCPP2D_THREAD_ATTRIBUTES
  #define LBAL_LIBCPP2D_THREAD_ATTRIBUTES 0
#endif

/**
  @def LBAL_LIBCPP2D_TO_CHARS_FIX_FLOAT
  @brief Fix the default floating-point representation in `std::format`
  @details

  SD-6 equivalent: `__cpp_lib_to_chars >= 202606L`. Note that
  `__cpp_lib_to_chars` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202606L` [P3505R4](https://wg21.link/P3505R4) Fix the default
  floating-point representation in `std::format`

  @sa `<charconv>`
*/
#ifndef LBAL_LIBCPP2D_TO_CHARS_FIX_FLOAT
  #define LBAL_LIBCPP2D_TO_CHARS_FIX_FLOAT 0
#endif

/**
  @def LBAL_LIBCPP2D_VIEW_INTERFACE
  @brief `view_interface::at()`
  @details

  SD-6 equivalent: `__cpp_lib_view_interface >= 202606L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `202606L` [P3052R2](https://wg21.link/P3052R2) `view_interface::at()`
*/
#ifndef LBAL_LIBCPP2D_VIEW_INTERFACE
  #define LBAL_LIBCPP2D_VIEW_INTERFACE 0
#endif

///	@}	LBAL_LIBCPP2D

///	@}	lbal_library
