/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFeatureSetup-overview-cpp14.inc”
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
  @name LBAL_CPP14
  All supported compilers support all features of C++14, but some of them may
  require that @ref LBAL_CPP14_SIZED_DEALLOCATION "sized deallocation" be
  explicitly enabled.

  @{
*/

/**
  @def LBAL_CPP14_AGGREGATE_NSDMI
  @brief Relax the requirements on aggregates and specify aggregate member
  initialization
  @details SD-6 equivalent: `__cpp_aggregate_nsdmi >= 201304L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3653](https://wg21.link/N3653) Member initializers and
  aggregates
*/
#ifndef LBAL_CPP14_AGGREGATE_NSDMI
  #define LBAL_CPP14_AGGREGATE_NSDMI 0
#endif

/**
  @def LBAL_CPP14_ATTRIBUTE_DEPRECATED
  @brief Support for marking symbols as deprecated
  @details SD-6 equivalent: `__has_cpp_attribute(deprecated) >= 201309L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201309L` [N3760](https://wg21.link/N3760) [[deprecated]] attribute
*/
#ifndef LBAL_CPP14_ATTRIBUTE_DEPRECATED
  #define LBAL_CPP14_ATTRIBUTE_DEPRECATED 0
#endif

/**
  @def LBAL_CPP14_BINARY_LITERALS
  @brief Add binary literal support.
  @details SD-6 equivalent: `__cpp_binary_literals >= 201304L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3472 __PDF__](https://wg21.link/N3472) Binary Literals in the C+
  + Core Language
*/
#ifndef LBAL_CPP14_BINARY_LITERALS
  #define LBAL_CPP14_BINARY_LITERALS 0
#endif

/**
  @def LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS
  @brief Relax constraints on `constexpr` functions, `constexpr` member
  functions and implicit `const`
  @details SD-6 equivalent: `__cpp_constexpr >= 201304L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201304L` [N3652](https://wg21.link/N3652) Relaxing constraints on constexpr
  functions / constexpr member functions and implicit const
*/
#ifndef LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS
  #define LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS 0
#endif

/**
  @def LBAL_CPP14_DECLTYPE_AUTO
  @brief Allow deduced return types and `decltype (auto)`
  @details SD-6 equivalent: `__cpp_decltype_auto >= 201304L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3638](https://wg21.link/N3638) Return type deduction for normal
  functions
*/
#ifndef LBAL_CPP14_DECLTYPE_AUTO
  #define LBAL_CPP14_DECLTYPE_AUTO 0
#endif

/**
  @def LBAL_CPP14_GENERIC_LAMBDAS
  @brief Generic (Polymorphic) Lambda Expressions
  @details SD-6 equivalent: `__cpp_generic_lambdas >= 201304L`. Note that
  `__cpp_generic_lambdas` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201304L` [N3649](https://wg21.link/N3649) Generic (Polymorphic) Lambda
  Expressions (Revision 3)
*/
#ifndef LBAL_CPP14_GENERIC_LAMBDAS
  #define LBAL_CPP14_GENERIC_LAMBDAS 0
#endif

/**
  @def LBAL_CPP14_INIT_CAPTURES
  @brief Generalized Lambda-capture changes
  @details SD-6 equivalent: `__cpp_init_captures >= 201304L`. Note that
  `__cpp_init_captures` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201304L` [N3648](https://wg21.link/N3648) Wording Changes for Generalized
  Lambda-capture
*/
#ifndef LBAL_CPP14_INIT_CAPTURES
  #define LBAL_CPP14_INIT_CAPTURES 0
#endif

/**
  @def LBAL_CPP14_RETURN_TYPE_DEDUCTION
  @brief Support for return type deduction for normal functions
  @details SD-6 equivalent: `__cpp_return_type_deduction >= 201304L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3638](https://wg21.link/N3638) Return type deduction for normal
  functions
*/
#ifndef LBAL_CPP14_RETURN_TYPE_DEDUCTION
  #define LBAL_CPP14_RETURN_TYPE_DEDUCTION 0
#endif

/**
  @def LBAL_CPP14_SIZED_DEALLOCATION
  @brief Make available a global `operator delete` that takes a size argument
  @details SD-6 equivalent: `__cpp_sized_deallocation >= 201309L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201309L` [N3778](https://wg21.link/N3778) C++ Sized Deallocation

  @remark Some compilers disable this by default since it’s an ABI-breaking
  change; clang, in particular, does this.
*/
#ifndef LBAL_CPP14_SIZED_DEALLOCATION
  #define LBAL_CPP14_SIZED_DEALLOCATION 0
#endif

/**
  @def LBAL_CPP14_VARIABLE_TEMPLATES
  @brief Support for variable templates
  @details SD-6 equivalent: `__cpp_variable_templates >= 201304L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3651 __PDF__](https://wg21.link/N3651) Variable Templates
  (Revision 1)
*/
#ifndef LBAL_CPP14_VARIABLE_TEMPLATES
  #define LBAL_CPP14_VARIABLE_TEMPLATES 0
#endif

///	@}	LBAL_CPP14

///	@}	lbal_compiler
