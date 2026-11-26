/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFeatureSetup-overview-cpp2d.inc”
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
  @name LBAL_CPP2D

  @brief Identify language features specific to the proposed C++29 Standard

  @details C++29—which in draft form is referenced as C++2d—is undergoing
  active development. In order to allow testing, we track approved language
  features here. Since this is all non-final, we use `LBAL_CPP2D_xxx` tokens
  instead of `LBAL_CPP29_xxx` tokens; upon finalization, we’ll update the
  token names and deprecate the old forms. Designation of formal SD-6 tokens
  tends to lag approval of proposals, so we will used the proposed tokens and
  derive our own tokens from those; where there is not even a proposed token,
  we’ll make one up. Once official tokens are created, we will synchronize with
  them it and deprecate the speculative ones.

  @{
*/

/**
  @def LBAL_CPP2D_CONCEPTS_CONDITIONAL_NOEXCEPT
  @brief Conditional `noexcept` specifiers in compound requirements
  @details

  SD-6 equivalent: `__cpp_concepts >= 202606L`. Note that `__cpp_concepts` has
  multiple values associated with it from a number of different proposals, so
  this token will have the value of the latest supported proposal, or `0` if the
  proposal described here is not supported.
  - `202606L` [P3822R2](https://wg21.link/P3822R2) Conditional `noexcept`
  specifiers in compound requirements
*/
#ifndef LBAL_CPP2D_CONCEPTS_CONDITIONAL_NOEXCEPT
  #define LBAL_CPP2D_CONCEPTS_CONDITIONAL_NOEXCEPT 0
#endif

/**
  @def LBAL_CPP2D_CONSTEVAL_ONLY
  @brief `consteval`-only Values for C++26
  @details

  SD-6 equivalent: `__cpp_consteval >= 202606L`. Note that `__cpp_consteval` has
  multiple values associated with it from a number of different proposals, so
  this token will have the value of the latest supported proposal, or `0` if the
  proposal described here is not supported.
  - `202606L` [P4101R1](https://wg21.link/P4101R1) `consteval`-only Values for
  C++26
*/
#ifndef LBAL_CPP2D_CONSTEVAL_ONLY
  #define LBAL_CPP2D_CONSTEVAL_ONLY 0
#endif

/**
  @def LBAL_CPP2D_CONTRACTS_VIRTUAL
  @brief Contracts for C++: Virtual functions
  @details

  SD-6 equivalent: `__cpp_contracts >= 202606L`. Note that `__cpp_contracts` has
  multiple values associated with it from a number of different proposals, so
  this token will have the value of the latest supported proposal, or `0` if the
  proposal described here is not supported.
  - `202606L` [P3097R3](https://wg21.link/P3097R3) *PDF* Contracts for C++:
  Virtual functions
*/
#ifndef LBAL_CPP2D_CONTRACTS_VIRTUAL
  #define LBAL_CPP2D_CONTRACTS_VIRTUAL 0
#endif

/**
  @def LBAL_CPP2D_DESIGNATED_INITIALIZERS_BASE_CLASSES
  @brief Designated-initializers for Base Classes
  @details

  SD-6 equivalent: `__cpp_designated_initializers >= 202606L`. Note that
  `__cpp_designated_initializers` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `202606L` [P2287R6](https://wg21.link/P2287R6) Designated-initializers for
  Base Classes
*/
#ifndef LBAL_CPP2D_DESIGNATED_INITIALIZERS_BASE_CLASSES
  #define LBAL_CPP2D_DESIGNATED_INITIALIZERS_BASE_CLASSES 0
#endif

/**
  @def LBAL_CPP2D_IMPL_COROUTINE_RETURN
  @brief `return_value` & `return_void` Are Not Mutually Exclusive
  @details

  SD-6 equivalent: `__cpp_impl_coroutine >= 202606L`. Note that
  `__cpp_impl_coroutine` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202606L` [P3950R1](https://wg21.link/P3950R1) *PDF* `return_value` &
  `return_void` Are Not Mutually Exclusive
*/
#ifndef LBAL_CPP2D_IMPL_COROUTINE_RETURN
  #define LBAL_CPP2D_IMPL_COROUTINE_RETURN 0
#endif

/**
  @def LBAL_CPP2D_PACK_INDEXING_TEMPLATE_NAMES
  @brief Pack Indexing for Template Names
  @details

  SD-6 equivalent: `__cpp_pack_indexing >= 202606L`. Note that
  `__cpp_pack_indexing` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202606L` [P3670R4](https://wg21.link/P3670R4) *PDF* Pack Indexing for
  Template Names
*/
#ifndef LBAL_CPP2D_PACK_INDEXING_TEMPLATE_NAMES
  #define LBAL_CPP2D_PACK_INDEXING_TEMPLATE_NAMES 0
#endif

/**
  @def LBAL_CPP2D_PP_EMBED_OFFSET
  @brief `#embed` offset parameter
  @details

  SD-6 equivalent: `__cpp_pp_embed >= 202606L`. Note that `__cpp_pp_embed` has
  multiple values associated with it from a number of different proposals, so
  this token will have the value of the latest supported proposal, or `0` if the
  proposal described here is not supported.
  - `202606L` [P3540R3](https://wg21.link/P3540R3) `#embed` offset parameter
*/
#ifndef LBAL_CPP2D_PP_EMBED_OFFSET
  #define LBAL_CPP2D_PP_EMBED_OFFSET 0
#endif

///	@}	LBAL_CPP2D

///	@}	lbal_compiler
