/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFeatureSetup-overview-cpp26.inc”
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
  @name LBAL_CPP26

  @brief Identify language features specific to the C++26 Standard

  @details Support across compilers for C++26 features is currently
  inconsistent, and is one of the fundamental reasons why lucenaBAL exists.
  These will be updated regularly as the Standard develops. Note that a some
  features do not have formal SD-6 tokens, so we often provide our own. Should
  an official token be created, we will synchronize with it and deprecate the
  proprietary one.

  @{
*/

/**
  @def LBAL_CPP26_ATTRIBUTE_INDETERMINATE
  @brief Erroneous behaviour for uninitialized reads
  @details

  SD-6 equivalent: `__has_cpp_attribute(indeterminate) >= 202403L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202403L` [P2795R5](https://wg21.link/P2795R5) Erroneous behaviour for
  uninitialized reads
*/
#ifndef LBAL_CPP26_ATTRIBUTE_INDETERMINATE
  #define LBAL_CPP26_ATTRIBUTE_INDETERMINATE 0
#endif

/**
  @def LBAL_CPP26_CONSTEXPR_CAST_FROM_VOID_STAR
  @brief All `constexpr` cast from `void *`
  @details SD-6 equivalent: `__cpp_constexpr >= 202306L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P2738R1 __PDF__](https://wg21.link/P2738R1) constexpr cast from
  void*: towards constexpr type-erasure
*/
#ifndef LBAL_CPP26_CONSTEXPR_CAST_FROM_VOID_STAR
  #define LBAL_CPP26_CONSTEXPR_CAST_FROM_VOID_STAR 0
#endif

/**
  @def LBAL_CPP26_CONSTEXPR_EXCEPTIONS
  @brief Allow exception throwing in _constant-evaluation_
  @details SD-6 equivalent: `__cpp_constexpr_exceptions >= 202411L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202411L` [P3068R6](https://wg21.link/P3068R6) Allowing exception throwing
  in constant-evaluation
*/
#ifndef LBAL_CPP26_CONSTEXPR_EXCEPTIONS
  #define LBAL_CPP26_CONSTEXPR_EXCEPTIONS 0
#endif

/**
  @def LBAL_CPP26_CONSTEXPR_PLACEMENT_NEW
  @brief Add `constexpr` placement `new`
  @details SD-6 equivalent: `__cpp_constexpr >= 202406L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202406L` [P2747R2](https://wg21.link/P2747R2) constexpr placement new
*/
#ifndef LBAL_CPP26_CONSTEXPR_PLACEMENT_NEW
  #define LBAL_CPP26_CONSTEXPR_PLACEMENT_NEW 0
#endif

/**
  @def LBAL_CPP26_CONSTEXPR_VIRTUAL_INHERITANCE
  @brief Allow exception throwing in _constant-evaluation_
  @details SD-6 equivalent: `__cpp_constexpr_virtual_inheritance >= 202506L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `202506L` [P3533R2](https://wg21.link/P3533R2) constexpr virtual inheritance
*/
#ifndef LBAL_CPP26_CONSTEXPR_VIRTUAL_INHERITANCE
  #define LBAL_CPP26_CONSTEXPR_VIRTUAL_INHERITANCE 0
#endif

/**
  @def LBAL_CPP26_CONTRACTS
  @brief Contracts for C++
  @details SD-6 equivalent: `__cpp_contracts >= 202502L`. Note that
  `__cpp_contracts` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202502L` [P2900R14 __PDF__](https://wg21.link/P2900R14) Contracts for C++
*/
#ifndef LBAL_CPP26_CONTRACTS
  #define LBAL_CPP26_CONTRACTS 0
#endif

/**
  @def LBAL_CPP26_DELETED_FUNCTION
  @brief `= delete(\should have a reason\)`.
  @details SD-6 equivalent: `__cpp_deleted_function >= 202403L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202403L` [P2573R2](https://wg21.link/P2573R2) = delete(“should have a
  reason”);
*/
#ifndef LBAL_CPP26_DELETED_FUNCTION
  #define LBAL_CPP26_DELETED_FUNCTION 0
#endif

/**
  @def LBAL_CPP26_EXPANSION_STATEMENTS
  @brief Expansion statements
  @details SD-6 equivalent: `__cpp_expansion_statements >= 202506L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202506L` [P1306R5](https://wg21.link/P1306R5) Expansion statements
*/
#ifndef LBAL_CPP26_EXPANSION_STATEMENTS
  #define LBAL_CPP26_EXPANSION_STATEMENTS 0
#endif

/**
  @def LBAL_CPP26_IMPL_REFLECTION
  @brief Reflection for C++26
  @details SD-6 equivalent: `__cpp_impl_reflection >= 202506L`. Note that
  `__cpp_impl_reflection` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202506L` [P2996R13](https://wg21.link/P2996R13) Reflection for C++26
  - `202506L` [P3096R12 __PDF__](https://wg21.link/P3096R12) Function Parameter
  Reflection in Reflection for C++26
  - `202506L` [P3293R3](https://wg21.link/P3293R3) Splicing a base class
  subobject
  - `202506L` [P3394R4](https://wg21.link/P3394R4) Annotations for Reflection
*/
#ifndef LBAL_CPP26_IMPL_REFLECTION
  #define LBAL_CPP26_IMPL_REFLECTION 0
#endif

/**
  @def LBAL_CPP26_IMPL_REFLECTION_CLEANUP
  @brief Miscellaneous Reflection Cleanup
  @details

  SD-6 equivalent: `__cpp_impl_reflection >= 202603L`. Note that
  `__cpp_impl_reflection` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202603L` [P3795R2](https://wg21.link/P3795R2) Miscellaneous Reflection
  Cleanup
*/
#ifndef LBAL_CPP26_IMPL_REFLECTION_CLEANUP
  #define LBAL_CPP26_IMPL_REFLECTION_CLEANUP 0
#endif

/**
  @def LBAL_CPP26_PACK_INDEXING
  @brief Pack Indexing
  @details SD-6 equivalent: `__cpp_pack_indexing >= 202311L`. Note that
  `__cpp_pack_indexing` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202311L` [P2662R3 __PDF__](https://wg21.link/P2662R3) Pack Indexing
*/
#ifndef LBAL_CPP26_PACK_INDEXING
  #define LBAL_CPP26_PACK_INDEXING 0
#endif

/**
  @def LBAL_CPP26_PLACEHOLDER_VARIABLES
  @brief Add placeholder variables (aka underscore, underbar, low line)
  @details SD-6 equivalent: `__cpp_placeholder_variables >= 202306L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202306L` [P2169R4 __PDF__](https://wg21.link/P2169R4) A Nice Placeholder
  With No Name
*/
#ifndef LBAL_CPP26_PLACEHOLDER_VARIABLES
  #define LBAL_CPP26_PLACEHOLDER_VARIABLES 0
#endif

/**
  @def LBAL_CPP26_PP_EMBED
  @brief `#embed` - a scannable, tooling-friendly binary resource inclusion
  mechanism
  @details

  SD-6 equivalent: `__cpp_pp_embed >= 202502L`. Note that `__cpp_pp_embed` has
  multiple values associated with it from a number of different proposals, so
  this token will have the value of the latest supported proposal, or `0` if the
  proposal described here is not supported.
  - `202502L` [P1967R14](https://wg21.link/P1967R14) `#embed` - a scannable,
  tooling-friendly binary resource inclusion mechanism
*/
#ifndef LBAL_CPP26_PP_EMBED
  #define LBAL_CPP26_PP_EMBED 0
#endif

/**
  @def LBAL_CPP26_STATIC_ASSERT_USER_MESSAGE
  @brief Allow static assertions with user-generated messages
  @details SD-6 equivalent: `__cpp_static_assert >= 202306L`. Note that
  `__cpp_static_assert` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202306L` [P2741R3 __PDF__](https://wg21.link/P2741R3) user-generated
  static_assert messages
*/
#ifndef LBAL_CPP26_STATIC_ASSERT_USER_MESSAGE
  #define LBAL_CPP26_STATIC_ASSERT_USER_MESSAGE 0
#endif

/**
  @def LBAL_CPP26_STRUCTURED_BINDINGS_ATTRIBUTES
  @brief Allow attributes for Structured Bindings
  @details SD-6 equivalent: `__cpp_structured_bindings >= 202403L`. Note that
  `__cpp_structured_bindings` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202411L` [P1061R10](https://wg21.link/P1061R10) Structured Bindings can
  introduce a Pack
*/
#ifndef LBAL_CPP26_STRUCTURED_BINDINGS_ATTRIBUTES
  #define LBAL_CPP26_STRUCTURED_BINDINGS_ATTRIBUTES 0
#endif

/**
  @def LBAL_CPP26_STRUCTURED_BINDINGS_PACK
  @brief Structured Bindings can introduce a Pack
  @details SD-6 equivalent: `__cpp_structured_bindings >= 202403L`. Note that
  `__cpp_structured_bindings` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202403L` [P0609R3 __PDF__](https://wg21.link/P0609R3) Attributes for
  Structured Bindings
*/
#ifndef LBAL_CPP26_STRUCTURED_BINDINGS_PACK
  #define LBAL_CPP26_STRUCTURED_BINDINGS_PACK 0
#endif

/**
  @def LBAL_CPP26_TEMPLATE_PARAMETERS
  @brief Allow _concept_ and _variable-template_ _template-parameters_
  @details SD-6 equivalent: `__cpp_template_parameters >= 202502L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `202502L` [P2841R7 __PDF__](https://wg21.link/P2841R7) Concept and variable-
  template template-parameters
*/
#ifndef LBAL_CPP26_TEMPLATE_PARAMETERS
  #define LBAL_CPP26_TEMPLATE_PARAMETERS 0
#endif

/**
  @def LBAL_CPP26_TRIVIAL_UNION
  @brief Allow trivial `unions`
  @details SD-6 equivalent: `__cpp_trivial_union >= 202502L`. Note that
  `__cpp_trivial_union` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202502L` [P3074R7](https://wg21.link/P3074R7) trivial unions (was
  std::uninitialized<T>)
  - `202603L` [P3074R7](https://wg21.link/P3074R7) trivial unions (was
  std::uninitialized<T>)
*/
#ifndef LBAL_CPP26_TRIVIAL_UNION
  #define LBAL_CPP26_TRIVIAL_UNION 0
#endif

/**
  @def LBAL_CPP26_TRIVIAL_UNION_LIFETIME
  @brief Adjustments to `union` Lifetime Rules
  @details

  SD-6 equivalent: `__cpp_trivial_union >= 202603L`. Note that
  `__cpp_trivial_union` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202603L` [P3726R2](https://wg21.link/P3726R2) Adjustments to `union`
  Lifetime Rules
*/
#ifndef LBAL_CPP26_TRIVIAL_UNION_LIFETIME
  #define LBAL_CPP26_TRIVIAL_UNION_LIFETIME 0
#endif

/**
  @def LBAL_CPP26_VARIADIC_FRIEND
  @brief Support variadic friends
  @details SD-6 equivalent: `__cpp_variadic_friend >= 202403L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `202403L` [P2893R3](https://wg21.link/P2893R3) Variadic Friends
*/
#ifndef LBAL_CPP26_VARIADIC_FRIEND
  #define LBAL_CPP26_VARIADIC_FRIEND 0
#endif

///	@}	LBAL_CPP26

///	@}	lbal_compiler
