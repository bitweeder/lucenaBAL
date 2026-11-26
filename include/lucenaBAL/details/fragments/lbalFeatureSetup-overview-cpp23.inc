/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFeatureSetup-overview-cpp23.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

/**
  @addtogroup lbal_compiler
  @{
*/

/**
  @name LBAL_CPP23

  @brief Identify language features specific to the C++23 Standard

  @details Support across compilers for C++23 features is currently
  inconsistent, and is one of the fundamental reasons why lucenaBAL exists.
  These will be updated regularly as the Standard develops. Note that a some
  features do not have formal SD-6 tokens, so we often provide our own. Should
  an official token be created, we will synchronize with it and deprecate the
  proprietary one.

  @{
*/

/**
  @def LBAL_CPP23_ATTRIBUTE_ASSUME
  @brief Optimization hint to indicate an expression is true
  @details SD-6 equivalent: `__has_cpp_attribute(assume) >= 202207L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202207L` [CWG2615](https://wg21.link/CWG2615) Missing
  `__has_cpp_attribute(assume)`
  - `202207L` [P1774R8](https://wg21.link/P1774R8) *PDF* Portable assumptions
*/
#ifndef LBAL_CPP23_ATTRIBUTE_ASSUME
  #define LBAL_CPP23_ATTRIBUTE_ASSUME 0
#endif

/**
  @def LBAL_CPP23_AUTO_CAST
  @brief `auto(x)`: `decay-copy` in the language
  @details SD-6 equivalent: `__cpp_auto_cast >= 202110L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `202110L` [P0849R8](https://wg21.link/P0849R8) auto(x): decay-copy in the
  language
*/
#ifndef LBAL_CPP23_AUTO_CAST
  #define LBAL_CPP23_AUTO_CAST 0
#endif

/**
  @def LBAL_CPP23_CHAR8_T_COMPATIBILITY
  @brief `char8_t` Compatibility and Portability Fix
  @details SD-6 equivalent: `__cpp_char8_t >= 202207L`. Note that
  `__cpp_char8_t` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P2513R4](https://wg21.link/P2513R4) `char8_t` Compatibility and
  Portability Fix
*/
#ifndef LBAL_CPP23_CHAR8_T_COMPATIBILITY
  #define LBAL_CPP23_CHAR8_T_COMPATIBILITY 0
#endif

/**
  @def LBAL_CPP23_CONSTEVAL_PROPAGATE_UP
  @brief `consteval` needs to propagate up
  @details SD-6 equivalent: `__cpp_consteval >= 202211L`. Note that
  `__cpp_consteval` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202211L` [P2564R3](https://wg21.link/P2564R3) `consteval` needs to
  propagate up
*/
#ifndef LBAL_CPP23_CONSTEVAL_PROPAGATE_UP
  #define LBAL_CPP23_CONSTEVAL_PROPAGATE_UP 0
#endif

/**
  @def LBAL_CPP23_CONSTEXPR_NON_LITERAL_VARIABLES
  @brief Allow non-literal variables, labels, and gotos in `constexpr` functions
  @details SD-6 equivalent: `__cpp_constexpr >= 202110L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202110L` [P2242R3](https://wg21.link/P2242R3) Non-literal variables (and
  labels and gotos) in constexpr functions
*/
#ifndef LBAL_CPP23_CONSTEXPR_NON_LITERAL_VARIABLES
  #define LBAL_CPP23_CONSTEXPR_NON_LITERAL_VARIABLES 0
#endif

/**
  @def LBAL_CPP23_CONSTEXPR_PERMIT_STATIC_CONSTEXPR
  @brief Permit `static constexpr` variables in `constexpr` functions
  @details SD-6 equivalent: `__cpp_constexpr >= 202211L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202211L` [P2647R1](https://wg21.link/P2647R1) Permitting `static constexpr`
  variables in `constexpr` functions
*/
#ifndef LBAL_CPP23_CONSTEXPR_PERMIT_STATIC_CONSTEXPR
  #define LBAL_CPP23_CONSTEXPR_PERMIT_STATIC_CONSTEXPR 0
#endif

/**
  @def LBAL_CPP23_CONSTEXPR_RELAX_RESTRICTIONS
  @brief Relax some constexpr restrictions
  @details SD-6 equivalent: `__cpp_constexpr >= 202207L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P2448R2](https://wg21.link/P2448R2) Relaxing some `constexpr`
  restrictions
*/
#ifndef LBAL_CPP23_CONSTEXPR_RELAX_RESTRICTIONS
  #define LBAL_CPP23_CONSTEXPR_RELAX_RESTRICTIONS 0
#endif

/**
  @def LBAL_CPP23_DEDUCTION_GUIDES_FROM_INHERITED_CONSTRUCTORS
  @brief Allow class template argument deduction from inherited constructors
  @details SD-6 equivalent: `__cpp_deduction_guides >= 202207L`. Note that
  `__cpp_deduction_guides` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202207L` [P2582R1](https://wg21.link/P2582R1) *PDF* Wording for class
  template argument deduction from inherited constructors
*/
#ifndef LBAL_CPP23_DEDUCTION_GUIDES_FROM_INHERITED_CONSTRUCTORS
  #define LBAL_CPP23_DEDUCTION_GUIDES_FROM_INHERITED_CONSTRUCTORS 0
#endif

/**
  @def LBAL_CPP23_EXPLICIT_THIS_PARAMETER
  @brief Deduce `this`
  @details SD-6 equivalent: `__cpp_explicit_this_parameter >= 202110L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202110L` [P0847R7](https://wg21.link/P0847R7) Deducing this
*/
#ifndef LBAL_CPP23_EXPLICIT_THIS_PARAMETER
  #define LBAL_CPP23_EXPLICIT_THIS_PARAMETER 0
#endif

/**
  @def LBAL_CPP23_IF_CONSTEVAL
  @brief `if consteval`
  @details SD-6 equivalent: `__cpp_if_consteval >= 202106L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202106L` [P1938R3](https://wg21.link/P1938R3) `if consteval`
*/
#ifndef LBAL_CPP23_IF_CONSTEVAL
  #define LBAL_CPP23_IF_CONSTEVAL 0
#endif

/**
  @def LBAL_CPP23_IMPLICIT_MOVE
  @brief Simpler implicit move
  @details SD-6 equivalent: `__cpp_implicit_move >= 202207L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202207L` [P2266R3](https://wg21.link/P2266R3) Simpler implicit move
*/
#ifndef LBAL_CPP23_IMPLICIT_MOVE
  #define LBAL_CPP23_IMPLICIT_MOVE 0
#endif

/**
  @def LBAL_CPP23_MULTIDIMENSIONAL_SUBSCRIPT
  @brief Add a multidimensional subscript operator
  @details SD-6 equivalent: `__cpp_multidimensional_subscript >= 202110L`. Note
  that `__cpp_multidimensional_subscript` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `202110L` [P2128R6](https://wg21.link/P2128R6) *PDF* Multidimensional
  subscript operator
*/
#ifndef LBAL_CPP23_MULTIDIMENSIONAL_SUBSCRIPT
  #define LBAL_CPP23_MULTIDIMENSIONAL_SUBSCRIPT 0
#endif

/**
  @def LBAL_CPP23_MULTIDIMENSIONAL_SUBSCRIPT_STATIC
  @brief `static` `operator []`
  @details SD-6 equivalent: `__cpp_multidimensional_subscript >= 202211L`. Note
  that `__cpp_multidimensional_subscript` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `202211L` [P2589R1](https://wg21.link/P2589R1) *PDF* `static operator[]`
*/
#ifndef LBAL_CPP23_MULTIDIMENSIONAL_SUBSCRIPT_STATIC
  #define LBAL_CPP23_MULTIDIMENSIONAL_SUBSCRIPT_STATIC 0
#endif

/**
  @def LBAL_CPP23_NAMED_CHARACTER_ESCAPES
  @brief Add named universal character escapes
  @details SD-6 equivalent: `__cpp_named_character_escapes >= 202207L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202207L` [P2071R2](https://wg21.link/P2071R2) Named universal character
  escapes
*/
#ifndef LBAL_CPP23_NAMED_CHARACTER_ESCAPES
  #define LBAL_CPP23_NAMED_CHARACTER_ESCAPES 0
#endif

/**
  @def LBAL_CPP23_RANGE_BASED_FOR_TEMPORARIES
  @brief Allow some temporaries in range-based for-loops
  @details SD-6 equivalent: `__cpp_range_based_for >= 202211L`. Note that
  `__cpp_range_based_for` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202211L` [CWG2659](https://wg21.link/CWG2659) Missing feature-test macro
  for lifetime extension in range-for loop
  - `202211L` [P2644R1](https://wg21.link/P2644R1) *PDF* Final Fix of Broken
  Range based for Loop Rev 1
  - `202211L` [P2718R0](https://wg21.link/P2718R0) Wording for P2644R1 Fix for
  Range-based for Loop
*/
#ifndef LBAL_CPP23_RANGE_BASED_FOR_TEMPORARIES
  #define LBAL_CPP23_RANGE_BASED_FOR_TEMPORARIES 0
#endif

/**
  @def LBAL_CPP23_SIZE_T_SUFFIX
  @brief Add literal suffixes for (signed) `size_t`
  @details SD-6 equivalent: `__cpp_size_t_suffix >= 202011L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202011L` [P0330R8](https://wg21.link/P0330R8) Literal Suffixes for (signed)
  size_t
*/
#ifndef LBAL_CPP23_SIZE_T_SUFFIX
  #define LBAL_CPP23_SIZE_T_SUFFIX 0
#endif

/**
  @def LBAL_CPP23_STATIC_CALL_OPERATOR
  @brief Static `operator ()`
  @details SD-6 equivalent: `__cpp_static_call_operator >= 202207L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202207L` [P1169R4](https://wg21.link/P1169R4) static `operator()`
*/
#ifndef LBAL_CPP23_STATIC_CALL_OPERATOR
  #define LBAL_CPP23_STATIC_CALL_OPERATOR 0
#endif

///	@}	LBAL_CPP23

///	@}	lbal_compiler
