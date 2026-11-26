/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFeatureSetup-overview-cpp17.inc”
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
  @name LBAL_CPP17
  All supported compilers support all language features of C++17, but some of
  them may require that
  @ref LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS "template template arguments" be
  explicitly enabled.

  @{
*/

/**
  @def LBAL_CPP17_AGGREGATE_BASES
  @brief Relax the restrictions on aggregate initialization.
  @details SD-6 equivalent: `__cpp_aggregate_bases >= 201603L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201603L` [P0017R1](https://wg21.link/P0017R1) Extension to aggregate
  initialization
*/
#ifndef LBAL_CPP17_AGGREGATE_BASES
  #define LBAL_CPP17_AGGREGATE_BASES 0
#endif

/**
  @def LBAL_CPP17_ALIGNED_NEW
  @brief Specify handling of dynamic memory allocation for over-aligned data.
  @details SD-6 equivalent: `__cpp_aligned_new >= 201606L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `201606L` [P0035R4](https://wg21.link/P0035R4) Dynamic memory allocation for
  over-aligned data
*/
#ifndef LBAL_CPP17_ALIGNED_NEW
  #define LBAL_CPP17_ALIGNED_NEW 0
#endif

/**
  @def LBAL_CPP17_ATTRIBUTE_FALLTHROUGH
  @brief Indicate that a case within a switch statements falls through
  @details SD-6 equivalent: `__has_cpp_attribute(fallthrough) >= 201603L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201603L` [P0188R1](https://wg21.link/P0188R1) **PDF** Wording for
  [[fallthrough]] attribute
*/
#ifndef LBAL_CPP17_ATTRIBUTE_FALLTHROUGH
  #define LBAL_CPP17_ATTRIBUTE_FALLTHROUGH 0
#endif

/**
  @def LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED
  @brief Indicate that a name or entity is possibly intentionally unused
  @details SD-6 equivalent: `__has_cpp_attribute(maybe_unused) >= 201603L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201603L` [P0212R1](https://wg21.link/P0212R1) **PDF** Wording for
  [[maybe_unused]] attribute
*/
#ifndef LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED
  #define LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED 0
#endif

/**
  @def LBAL_CPP17_ATTRIBUTE_NODISCARD
  @brief Indicate that a function return, class, or enum should not be ignored
  @details SD-6 equivalent: `__has_cpp_attribute(nodiscard) >= 201603L`. Note
  that `__has_cpp_attribute(nodiscard)` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `201603L` [P0189R1](https://wg21.link/P0189R1) **PDF** Wording for
  [[nodiscard]] attribute
*/
#ifndef LBAL_CPP17_ATTRIBUTE_NODISCARD
  #define LBAL_CPP17_ATTRIBUTE_NODISCARD 0
#endif

/**
  @def LBAL_CPP17_CAPTURE_STAR_THIS
  @brief Allow lambda capture of `*this` by value as `as [=,*this]`.
  @details SD-6 equivalent: `__cpp_capture_star_this >= 201603L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201603L` [P0018R3](https://wg21.link/P0018R3) Lambda Capture of `*this` by
  Value as `[=,*this]`
*/
#ifndef LBAL_CPP17_CAPTURE_STAR_THIS
  #define LBAL_CPP17_CAPTURE_STAR_THIS 0
#endif

/**
  @def LBAL_CPP17_CONSTEXPR_LAMBDA
  @brief Allow lambdas to be constexpr explicitly or implicitly
  @details SD-6 equivalent: `__cpp_constexpr >= 201603L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201603L` [P0170R1](https://wg21.link/P0170R1) **PDF** Wording for Constexpr
  Lambda
*/
#ifndef LBAL_CPP17_CONSTEXPR_LAMBDA
  #define LBAL_CPP17_CONSTEXPR_LAMBDA 0
#endif

/**
  @def LBAL_CPP17_DEDUCTION_GUIDES
  @brief Template argument deduction for class templates
  @details SD-6 equivalent: `__cpp_deduction_guides >= 201606L`. Note that
  `__cpp_deduction_guides` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201606L` [P0091R3](https://wg21.link/P0091R3) Template argument deduction
  for class templates (Rev. 6)
*/
#ifndef LBAL_CPP17_DEDUCTION_GUIDES
  #define LBAL_CPP17_DEDUCTION_GUIDES 0
#endif

/**
  @def LBAL_CPP17_DEDUCTION_GUIDES_DR
  @brief Address additional class template argument deduction issues
  @details SD-6 equivalent: `__cpp_deduction_guides >= 201703L`. Note that
  `__cpp_deduction_guides` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201703L` [P0620R0](https://wg21.link/P0620R0) Drafting for class template
  argument deduction issues
*/
#ifndef LBAL_CPP17_DEDUCTION_GUIDES_DR
  #define LBAL_CPP17_DEDUCTION_GUIDES_DR 0
#endif

/**
  @def LBAL_CPP17_DEDUCTION_GUIDES_NB
  @brief Address issues that came up during C++17 balloting regarding class
  template argument deduction
  @details SD-6 equivalent: `__cpp_deduction_guides >= 201611L`. Note that
  `__cpp_deduction_guides` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201611L` [P0512R0](https://wg21.link/P0512R0) **PDF** Class Template
  Argument Deduction Assorted NB resolution and issues
*/
#ifndef LBAL_CPP17_DEDUCTION_GUIDES_NB
  #define LBAL_CPP17_DEDUCTION_GUIDES_NB 0
#endif

/**
  @def LBAL_CPP17_ENUMERATOR_ATTRIBUTES
  @brief Attributes for enumerators
  @details SD-6 equivalent: `__cpp_enumerator_attributes >= 201411L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201411L` [N4266](https://wg21.link/N4266) Attributes for namespaces and
  enumerators
*/
#ifndef LBAL_CPP17_ENUMERATOR_ATTRIBUTES
  #define LBAL_CPP17_ENUMERATOR_ATTRIBUTES 0
#endif

/**
  @def LBAL_CPP17_FOLD_EXPRESSIONS
  @brief Allow folding a template parameter pack over a binary operator
  @details SD-6 equivalent: `__cpp_fold_expressions >= 201411L`. Note that
  `__cpp_fold_expressions` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201411L` [N4295](https://wg21.link/N4295) Folding Expressions
*/
#ifndef LBAL_CPP17_FOLD_EXPRESSIONS
  #define LBAL_CPP17_FOLD_EXPRESSIONS 0
#endif

/**
  @def LBAL_CPP17_FOLD_EXPRESSIONS_REVISED
  @brief Add support for unary folds and empty parameter packs to fold
  expressions
  @details SD-6 equivalent: `__cpp_fold_expressions >= 201603L`. Note that
  `__cpp_fold_expressions` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201603L` [P0036R0](https://wg21.link/P0036R0) **PDF** Unary Folds and Empty
  Parameter Packs (Revision 1)
*/
#ifndef LBAL_CPP17_FOLD_EXPRESSIONS_REVISED
  #define LBAL_CPP17_FOLD_EXPRESSIONS_REVISED 0
#endif

/**
  @def LBAL_CPP17_GUARANTEED_COPY_ELISION
  @brief Guarantee copy and move elision in well-defined situations
  @details SD-6 equivalent: `__cpp_guaranteed_copy_elision >= 201606L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201606L` [P0135R1](https://wg21.link/P0135R1) Wording for guaranteed copy
  elision through simplified value categories
*/
#ifndef LBAL_CPP17_GUARANTEED_COPY_ELISION
  #define LBAL_CPP17_GUARANTEED_COPY_ELISION 0
#endif

/**
  @def LBAL_CPP17_HEX_FLOAT
  @brief Specify Hexadecimal float literals
  @details SD-6 equivalent: `__cpp_hex_float >= 201603L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `201603L` [P0245R1](https://wg21.link/P0245R1) Hexadecimal float literals
  for C++
*/
#ifndef LBAL_CPP17_HEX_FLOAT
  #define LBAL_CPP17_HEX_FLOAT 0
#endif

/**
  @def LBAL_CPP17_IF_CONSTEXPR
  @brief Allow constant expressions as if statements
  @details SD-6 equivalent: `__cpp_if_constexpr >= 201606L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201606L` [P0292R2](https://wg21.link/P0292R2) constexpr if: A slightly
  different syntax
*/
#ifndef LBAL_CPP17_IF_CONSTEXPR
  #define LBAL_CPP17_IF_CONSTEXPR 0
#endif

/**
  @def LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED
  @brief Address core issues raised by Inheriting Constructors
  @details SD-6 equivalent: `__cpp_inheriting_constructors >= 201511L`. Note
  that `__cpp_inheriting_constructors` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `201511L` [P0136R1](https://wg21.link/P0136R1) Rewording inheriting
  constructors (core issue 1941 et al)
*/
#ifndef LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED
  #define LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED 0
#endif

/**
  @def LBAL_CPP17_INLINE_VARIABLES
  @brief `inline` variables
  @details SD-6 equivalent: `__cpp_inline_variables >= 201606L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201606L` [P0386R2](https://wg21.link/P0386R2) **PDF** Inline Variables
*/
#ifndef LBAL_CPP17_INLINE_VARIABLES
  #define LBAL_CPP17_INLINE_VARIABLES 0
#endif

/**
  @def LBAL_CPP17_NAMESPACE_ATTRIBUTES
  @brief Attributes for namespaces
  @details SD-6 equivalent: `__cpp_namespace_attributes >= 201411L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201411L` [N4266](https://wg21.link/N4266) Attributes for namespaces and
  enumerators
*/
#ifndef LBAL_CPP17_NAMESPACE_ATTRIBUTES
  #define LBAL_CPP17_NAMESPACE_ATTRIBUTES 0
#endif

/**
  @def LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE
  @brief Make exception specifications be part of the type system
  @details SD-6 equivalent: `__cpp_noexcept_function_type >= 201510L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201510L` [P0012R1](https://wg21.link/P0012R1) Make exception specifications
  be part of the type system, version 5
*/
#ifndef LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE
  #define LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE 0
#endif

/**
  @def LBAL_CPP17_NONTYPE_TEMPLATE_ARGS
  @brief Allow constant evaluation for all non-type template arguments
  @details SD-6 equivalent: `__cpp_nontype_template_args >= 201411L`. Note that
  `__cpp_nontype_template_args` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201411L` [N4268](https://wg21.link/N4268) Allow constant evaluation for all
  non-type template arguments
*/
#ifndef LBAL_CPP17_NONTYPE_TEMPLATE_ARGS
  #define LBAL_CPP17_NONTYPE_TEMPLATE_ARGS 0
#endif

/**
  @def LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO
  @brief Allow declaring non-type template arguments with auto
  @details SD-6 equivalent: `__cpp_nontype_template_parameter_auto >= 201606L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201606L` [P0127R2](https://wg21.link/P0127R2) Declaring non-type template
  arguments with auto
*/
#ifndef LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO
  #define LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO 0
#endif

/**
  @def LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED
  @brief Generalize range-based for-loops
  @details SD-6 equivalent: `__cpp_range_based_for >= 201603L`. Note that
  `__cpp_range_based_for` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201603L` [P0184R0](https://wg21.link/P0184R0) Generalizing the Range-Based
  For Loop
*/
#ifndef LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED
  #define LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED 0
#endif

/**
  @def LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE
  @brief Allow static assertions with no messages
  @details SD-6 equivalent: `__cpp_static_assert >= 201411L`. Note that
  `__cpp_static_assert` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201411L` [N3928](https://wg21.link/N3928) **PDF** Extending static_assert,
  v2
*/
#ifndef LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE
  #define LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE 0
#endif

/**
  @def LBAL_CPP17_STRUCTURED_BINDINGS
  @brief Add support for multiple function return values and more
  @details SD-6 equivalent: `__cpp_structured_bindings >= 201606L`. Note that
  `__cpp_structured_bindings` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201606L` [P0217R3](https://wg21.link/P0217R3) Proposed wording for
  structured bindings
*/
#ifndef LBAL_CPP17_STRUCTURED_BINDINGS
  #define LBAL_CPP17_STRUCTURED_BINDINGS 0
#endif

/**
  @def LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS
  @brief Resolve a defect in the matching of template arguments with template
  parameters
  @details SD-6 equivalent: `__cpp_template_template_args >= 201611L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201611L` [P0522R0](https://wg21.link/P0522R0) DR: Matching of template
  template-arguments excludes compatible templates

  @remark The proposal this is from is intended to resolve a Defect Report, but
  unfortunately introduces a defect of its own. Some compilers are disabling
  this until a revised patch is in.
*/
#ifndef LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS
  #define LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS 0
#endif

/**
  @def LBAL_CPP17_VARIADIC_USING
  @brief Add support for pack expansions in using-declarations
  @details SD-6 equivalent: `__cpp_variadic_using >= 201611L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201611L` [P0195R2](https://wg21.link/P0195R2) Pack expansions in
  using-declarations
*/
#ifndef LBAL_CPP17_VARIADIC_USING
  #define LBAL_CPP17_VARIADIC_USING 0
#endif

///	@}	LBAL_CPP17

///	@}	lbal_compiler
