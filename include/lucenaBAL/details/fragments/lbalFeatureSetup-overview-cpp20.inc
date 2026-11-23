/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFeatureSetup-overview-cpp20.inc”
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
  @name LBAL_CPP20

  @brief Identify language features specific to the C++20 Standard

  @details Support across compilers for C++20 features is currently
  inconsistent, and is one of the fundamental reasons why lucenaBAL exists.
  These will be updated regularly as the Standard develops.

  Note that a very large number of features do not have SD-6 macros, so we
  often provide our own tokens. Should an official macro be created, we will
  synchronize with it and deprecate the proprietary one.

  @{
*/

/**
  @def LBAL_CPP20_AGGREGATE_PAREN_INIT
  @brief Allow aggregate initialization from parentheses as well as braces.
  @details SD-6 equivalent: `__cpp_aggregate_paren_init >= 201902L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201902L` [P0960R3](https://wg21.link/P0960R3) Allow initializing aggregates
  from a parenthesized list of values

  @remark Note that paren initialization allows narrowing conversions, as usual.
*/
#ifndef LBAL_CPP20_AGGREGATE_PAREN_INIT
  #define LBAL_CPP20_AGGREGATE_PAREN_INIT 0
#endif

/**
  @def LBAL_CPP20_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS
  @brief Allow lambda capture `[=, this]`
*/
#ifndef LBAL_CPP20_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS
  #define LBAL_CPP20_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS 0
#endif

/**
  @def LBAL_CPP20_ATTRIBUTES_LIKELY_AND_UNLIKELY
  @brief Aggregate tracking the availability of `likely` and `unlikely`
  attributes
  @details We track the availability of each attribute separately, as well as
  provide this aggregate to test for compliance. The aggregate’s value will be
  `0` if either attribute is unavailable, or `1` otherwise.
*/
#ifndef LBAL_CPP20_ATTRIBUTES_LIKELY_AND_UNLIKELY
  #define LBAL_CPP20_ATTRIBUTES_LIKELY_AND_UNLIKELY 0
#endif

/**
  @def LBAL_CPP20_ATTRIBUTE_LIKELY
  @brief Add `likely` attribute for labels and statements
  @details SD-6 equivalent: `__has_cpp_attribute(likely) >= 201803L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201803L` [P0479R5](https://wg21.link/P0479R5) Proposed wording for likely
  and unlikely attributes
*/
#ifndef LBAL_CPP20_ATTRIBUTE_LIKELY
  #define LBAL_CPP20_ATTRIBUTE_LIKELY 0
#endif

/**
  @def LBAL_CPP20_ATTRIBUTE_NODISCARD_EXPANDED
  @brief Add explanatory text to the `nodiscard` attribute and allow it on
  constructors
  @details SD-6 equivalent: `__has_cpp_attribute(nodiscard) >= 201907L`. Note
  that `__has_cpp_attribute(nodiscard)` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `201907L` [P1301R4](https://wg21.link/P1301R4) [[nodiscard(should have
  a reason)]]
  - `201907L` [P1771R1 __PDF__](https://wg21.link/P1771R1) [[nodiscard]] for
  constructors
*/
#ifndef LBAL_CPP20_ATTRIBUTE_NODISCARD_EXPANDED
  #define LBAL_CPP20_ATTRIBUTE_NODISCARD_EXPANDED 0
#endif

/**
  @def LBAL_CPP20_ATTRIBUTE_NO_UNIQUE_ADDRESS
  @brief Add language support for for empty objects
  @details SD-6 equivalent: `__has_cpp_attribute(no_unique_address) >= 201803L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201803L` [P0840R2](https://wg21.link/P0840R2) Language support for empty
  objects
*/
#ifndef LBAL_CPP20_ATTRIBUTE_NO_UNIQUE_ADDRESS
  #define LBAL_CPP20_ATTRIBUTE_NO_UNIQUE_ADDRESS 0
#endif

/**
  @def LBAL_CPP20_ATTRIBUTE_UNLIKELY
  @brief Add `unlikely` attribute for labels and statements
  @details SD-6 equivalent: `__has_cpp_attribute(unlikely) >= 201803L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201803L` [P0479R5](https://wg21.link/P0479R5) Proposed wording for likely
  and unlikely attributes
*/
#ifndef LBAL_CPP20_ATTRIBUTE_UNLIKELY
  #define LBAL_CPP20_ATTRIBUTE_UNLIKELY 0
#endif

/**
  @def LBAL_CPP20_CHAR8_T
  @brief Add `char8_t` as a UTF-8 equivalent for `char16_t` and `char32_t`.
  @details SD-6 equivalent: `__cpp_char8_t >= 201811L`. Note that
  `__cpp_char8_t` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P0482R6](https://wg21.link/P0482R6) char8_t: A type for UTF-8
  characters and strings (Revision 6)
*/
#ifndef LBAL_CPP20_CHAR8_T
  #define LBAL_CPP20_CHAR8_T 0
#endif

/**
  @def LBAL_CPP20_CONCEPTS
  @brief Incorporate the Concepts TS into the Standard
  @details SD-6 equivalent: `__cpp_concepts >= 201707L`. Note that
  `__cpp_concepts` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201707L` [P0734R0 __PDF__](https://wg21.link/P0734R0) Wording Paper, C++
  extensions for Concepts
*/
#ifndef LBAL_CPP20_CONCEPTS
  #define LBAL_CPP20_CONCEPTS 0
#endif

/**
  @def LBAL_CPP20_CONCEPTS_CONDITIONALLY_TRIVIAL_SPECIAL_MEMBER_FUNCTIONS
  @brief Make special member functions conditionally trivial
  @details SD-6 equivalent: `__cpp_concepts >= 202002L`. Note that
  `__cpp_concepts` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202002L` [P0848R3](https://wg21.link/P0848R3) Conditionally Trivial Special
  Member Functions
*/
#ifndef LBAL_CPP20_CONCEPTS_CONDITIONALLY_TRIVIAL_SPECIAL_MEMBER_FUNCTIONS
  #define LBAL_CPP20_CONCEPTS_CONDITIONALLY_TRIVIAL_SPECIAL_MEMBER_FUNCTIONS 0
#endif

/**
  @def LBAL_CPP20_CONCEPTS_REFINE_RETURN_TYPE_REQUIREMENTS
  @brief Refine definition of return-type-requirements
  @details SD-6 equivalent: `__cpp_concepts >= 201907L`. Note that
  `__cpp_concepts` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P1452R2](https://wg21.link/P1452R2) On the non-uniform semantics
  of return-type-requirements
*/
#ifndef LBAL_CPP20_CONCEPTS_REFINE_RETURN_TYPE_REQUIREMENTS
  #define LBAL_CPP20_CONCEPTS_REFINE_RETURN_TYPE_REQUIREMENTS 0
#endif

/**
  @def LBAL_CPP20_CONCEPTS_RESPECIFY_RETURN_TYPE_REQUIREMENTS
  @brief Refine definition of return-type-requirements
  @details SD-6 equivalent: `__cpp_concepts >= 201811L`. Note that
  `__cpp_concepts` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P1084R2 __PDF__](https://wg21.link/P1084R2) Today’s
  return-type-requirements Are Insufficient
*/
#ifndef LBAL_CPP20_CONCEPTS_RESPECIFY_RETURN_TYPE_REQUIREMENTS
  #define LBAL_CPP20_CONCEPTS_RESPECIFY_RETURN_TYPE_REQUIREMENTS 0
#endif

/**
  @def LBAL_CPP20_CONDITIONAL_EXPLICIT
  @brief Support `explicit (bool)`
  @details Allow simplification of templated constructors that have the
  potential to incorrectly convert their arguments.

  SD-6 equivalent: `__cpp_conditional_explicit >= 201806L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `201806L` [P0892R2](https://wg21.link/P0892R2) explicit(bool)
*/
#ifndef LBAL_CPP20_CONDITIONAL_EXPLICIT
  #define LBAL_CPP20_CONDITIONAL_EXPLICIT 0
#endif

/**
  @def LBAL_CPP20_CONSTEVAL
  @brief Immediate functions
  @details SD-6 equivalent: `__cpp_consteval >= 201811L`. Note that
  `__cpp_consteval` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P1073R3](https://wg21.link/P1073R3) Immediate functions
*/
#ifndef LBAL_CPP20_CONSTEVAL
  #define LBAL_CPP20_CONSTEVAL 0
#endif

/**
  @def LBAL_CPP20_CONSTEXPR_CHANGE_ACTIVE_UNION_MEMBER
  @brief Allow the active member of a `union` inside `constexpr` to change
  @details SD-6 equivalent: `__cpp_constexpr >= 202002L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202002L` [P1330R0 __PDF__](https://wg21.link/P1330R0) Changing the active
  member of a union inside constexpr
*/
#ifndef LBAL_CPP20_CONSTEXPR_CHANGE_ACTIVE_UNION_MEMBER
  #define LBAL_CPP20_CONSTEXPR_CHANGE_ACTIVE_UNION_MEMBER 0
#endif

/**
  @def LBAL_CPP20_CONSTEXPR_DYNAMIC_ALLOC
  @brief Language support for variable-sized containers suitable for use in
  constexpr computations.
  @details SD-6 equivalent: `__cpp_constexpr_dynamic_alloc >= 201907L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201907L` [P0784R7](https://wg21.link/P0784R7) More constexpr containers

  @remark AKA, “More constexpr containers”.
*/
#ifndef LBAL_CPP20_CONSTEXPR_DYNAMIC_ALLOC
  #define LBAL_CPP20_CONSTEXPR_DYNAMIC_ALLOC 0
#endif

/**
  @def LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM
  @brief Allow `dynamic_cast`, polymorphic `typeid` in `constexpr` functions
  @details SD-6 equivalent: `__cpp_constexpr >= 201811L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P1002R1 __PDF__](https://wg21.link/P1002R1) Try-catch blocks in
  constexpr functions
  - `201811L` [P1327R1](https://wg21.link/P1327R1) Allowing `dynamic_cast`,
  polymorphic `typeid` in Constant Expressions

  @remark This and the `LBAL_CPP20_CONSTEXPR_TRY_CATCH` and
  `LBAL_CPP20_CONSTEXPR_UNION_ALTERATION` tokens are aliases for each other.
*/
#ifndef LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM
  #define LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM 0
#endif

/**
  @def LBAL_CPP20_CONSTEXPR_INTRINSICS
  @brief Permit unevaluated inline assembly in `constexpr` functions
  @details SD-6 equivalent: `__cpp_constexpr >= 201907L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P1668R1](https://wg21.link/P1668R1) Enabling constexpr Intrinsics
  By Permitting Unevaluated inline-assembly in constexpr Functions

  @remark This and the `LBAL_CPP20_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION`
  token are aliases for each other.
*/
#ifndef LBAL_CPP20_CONSTEXPR_INTRINSICS
  #define LBAL_CPP20_CONSTEXPR_INTRINSICS 0
#endif

/**
  @def LBAL_CPP20_CONSTEXPR_IN_DECLTYPE
  @brief Address Core Issue regarding when `constexpr` functions are defined
  @details This has the effect of allowing constant expressions in `decltype`
  declarations.

  SD-6 equivalent: `__cpp_constexpr_in_decltype >= 201711L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201711L` [P0859R0](https://wg21.link/P0859R0) Core Issue 1581: When are
  constexpr member functions defined?
*/
#ifndef LBAL_CPP20_CONSTEXPR_IN_DECLTYPE
  #define LBAL_CPP20_CONSTEXPR_IN_DECLTYPE 0
#endif

/**
  @def LBAL_CPP20_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION
  @brief Address an inconsistency in the lambda specification
  @details SD-6 equivalent: `__cpp_constexpr >= 201907L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P1331R2 __PDF__](https://wg21.link/P1331R2) Permitting trivial
  default initialization in constexpr contexts

  @remark This and the `LBAL_CPP20_CONSTEXPR_INTRINSICS` token are aliases for
  each other.
*/
#ifndef LBAL_CPP20_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION
  #define LBAL_CPP20_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION 0
#endif

/**
  @def LBAL_CPP20_CONSTEXPR_TRY_CATCH
  @brief Permit unevaluated inline assembly in constexpr functions
  @details SD-6 equivalent: `__cpp_constexpr >= 201811L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201811L` [P1002R1 __PDF__](https://wg21.link/P1002R1) Try-catch blocks in
  constexpr functions

  @remark This and the `LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM` and
  `LBAL_CPP20_CONSTEXPR_UNION_ALTERATION` tokens are aliases for each other.
*/
#ifndef LBAL_CPP20_CONSTEXPR_TRY_CATCH
  #define LBAL_CPP20_CONSTEXPR_TRY_CATCH 0
#endif

/**
  @def LBAL_CPP20_CONSTEXPR_UNION_ALTERATION
  @brief Allow changing the active member of a `union` inside `constexpr`
  @details SD-6 equivalent: `__cpp_constexpr >= 201811L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `202002L` [P1330R0 __PDF__](https://wg21.link/P1330R0) Changing the active
  member of a union inside constexpr

  @remark This and the `LBAL_CPP20_CONSTEXPR_TRY_CATCH` and
  `LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM` tokens are aliases for each other.
*/
#ifndef LBAL_CPP20_CONSTEXPR_UNION_ALTERATION
  #define LBAL_CPP20_CONSTEXPR_UNION_ALTERATION 0
#endif

/**
  @def LBAL_CPP20_CONSTEXPR_VIRTUAL_FUNCTION
  @brief Allow virtual function calls in constexpr functions
  @details SD-6 equivalent: `__cpp_constexpr >= 201806L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201806L` [P1064R0](https://wg21.link/P1064R0) Allowing Virtual Function
  Calls in Constant Expressions
*/
#ifndef LBAL_CPP20_CONSTEXPR_VIRTUAL_FUNCTION
  #define LBAL_CPP20_CONSTEXPR_VIRTUAL_FUNCTION 0
#endif

/**
  @def LBAL_CPP20_CONSTINIT
  @brief Add the `constinit` keyword
  @details This keyword provides a decorator that can be used to ensure that
  initialization of a constant is actually occuring as expected, regardless of
  any changing (i.e., dialect-specific) rules that might be in play.

  SD-6 equivalent: `__cpp_constinit >= 201907L`. This token will have a value of
  `0` if the proposal described here is not supported.
  - `201907L` [P1143R2](https://wg21.link/P1143R2) Adding the `constinit`
  keyword

  @remark This feature is broadly intended to be back-portable to older C++
  dialects; in certain circumstances it’s conceivable that `__cpp_constinit`
  will be set even if the dialect is older than C++20.
*/
#ifndef LBAL_CPP20_CONSTINIT
  #define LBAL_CPP20_CONSTINIT 0
#endif

/**
  @def LBAL_CPP20_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS
  @brief Fix `const`-qualified pointers to members
*/
#ifndef LBAL_CPP20_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS
  #define LBAL_CPP20_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS 0
#endif

/**
  @def LBAL_CPP20_DEDUCTION_GUIDES_FOR_AGGREGATES
  @brief Class template argument deduction for aggregates
  @details SD-6 equivalent: `__cpp_deduction_guides >= 201907L`. Note that
  `__cpp_deduction_guides` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201907L` [P1814R0](https://wg21.link/P1814R0) Wording for Class Template
  Argument Deduction for Alias Templates
  - `201907L` [P1816R0 __PDF__](https://wg21.link/P1816R0) Wording for class
  template argument deduction for aggregates
*/
#ifndef LBAL_CPP20_DEDUCTION_GUIDES_FOR_AGGREGATES
  #define LBAL_CPP20_DEDUCTION_GUIDES_FOR_AGGREGATES 0
#endif

/**
  @def LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS
  @brief Support default-constructible and -assignable stateless lambdas
*/
#ifndef LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS
  #define LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS 0
#endif

/**
  @def LBAL_CPP20_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS
  @brief Default member initializers for bit-fields
*/
#ifndef LBAL_CPP20_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS
  #define LBAL_CPP20_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS 0
#endif

/**
  @def LBAL_CPP20_DESIGNATED_INITIALIZERS
  @brief Add designated initializers
  @details SD-6 equivalent: `__cpp_designated_initializers >= 201707L`. Note
  that `__cpp_designated_initializers` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `201707L` [P0329R4 __PDF__](https://wg21.link/P0329R4) Designated
  Initialization Wording
*/
#ifndef LBAL_CPP20_DESIGNATED_INITIALIZERS
  #define LBAL_CPP20_DESIGNATED_INITIALIZERS 0
#endif

/**
  @def LBAL_CPP20_DESTROYING_DELETE
  @brief Efficient sized delete for variable sized classes
  @details SD-6 equivalent: `__cpp_impl_destroying_delete >= 201806L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201806L` [P0722R3](https://wg21.link/P0722R3) Efficient sized delete for
  variable sized classes
*/
#ifndef LBAL_CPP20_DESTROYING_DELETE
  #define LBAL_CPP20_DESTROYING_DELETE 0
#endif

/**
  @def LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST
  @brief Generic (Polymorphic) Lambda Expressions
  @details SD-6 equivalent: `__cpp_generic_lambdas >= 201707L`. Note that
  `__cpp_generic_lambdas` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201707L` [P0428R2 __PDF__](https://wg21.link/P0428R2) Familiar template
  syntax for generic lambdas
*/
#ifndef LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST
  #define LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST 0
#endif

/**
  @def LBAL_CPP20_IMPL_COROUTINE
  @brief Add necessary language support for the `<coroutine>` library feature
  @details SD-6 equivalent: `__cpp_impl_coroutine >= 201902L`. Note that
  `__cpp_impl_coroutine` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201902L` [LWG3393](https://wg21.link/LWG3393) Missing/incorrect feature
  test macro for coroutines
  - `201902L` [P0912R5](https://wg21.link/P0912R5) Merge Coroutines TS into
  C++20 working draft

  @remark Technically, the proposal this is from only directs that the
  Coroutines TS be merged into the Standard.
*/
#ifndef LBAL_CPP20_IMPL_COROUTINE
  #define LBAL_CPP20_IMPL_COROUTINE 0
#endif

/**
  @def LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION
  @brief Allow pack-expansion in lambda init-capture
  @details SD-6 equivalent: `__cpp_init_captures >= 201803L`. Note that
  `__cpp_init_captures` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `201803L` [P0780R2](https://wg21.link/P0780R2) Allow pack expansion in
  lambda init-capture
*/
#ifndef LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION
  #define LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION 0
#endif

/**
  @def LBAL_CPP20_INIT_STATEMENTS_FOR_RANGE_BASED_FOR
  @brief Add range-based `for` statements with initializer
*/
#ifndef LBAL_CPP20_INIT_STATEMENTS_FOR_RANGE_BASED_FOR
  #define LBAL_CPP20_INIT_STATEMENTS_FOR_RANGE_BASED_FOR 0
#endif

/**
  @def LBAL_CPP20_INTEGRATING_OUR_FEATURE_TEST_MACROS
  @brief Integrate universal feature test macros into the Standard

  @remark It appears this is only here to get Microsoft to support SD-6, as the
  other major compilers de facto meet the requirement.
*/
#ifndef LBAL_CPP20_INTEGRATING_OUR_FEATURE_TEST_MACROS
  #define LBAL_CPP20_INTEGRATING_OUR_FEATURE_TEST_MACROS 0
#endif

/**
  @def LBAL_CPP20_MODULES
  @brief Incorporate modules
  @details SD-6 equivalent: `__cpp_modules >= 201907L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `201907L` [P1103R3 __PDF__](https://wg21.link/P1103R3) Merging Modules
  - `201907L` [P1811R0](https://wg21.link/P1811R0) Relaxing redefinition
  restrictions for re-exportation robustness
*/
#ifndef LBAL_CPP20_MODULES
  #define LBAL_CPP20_MODULES 0
#endif

/**
  @def LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FIXES
  @brief Address inconsistencies in handling of non-type template arguments
  @details SD-6 equivalent: `__cpp_nontype_template_args >= 201911L`. Note that
  `__cpp_nontype_template_args` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201911L` [P1907R1](https://wg21.link/P1907R1) Inconsistencies with non-type
  template parameters

  @remark Most mainstream compilers support this, except for `float`-type
  arguments, but there is no “partial support” value to qualify this. The latest
  versions of some compilers even support `floats` “experimentally”, but have
  not yet updated the macro value.

  @remark Newer `clang`s mostly support this, including for `float`-type
  arguments, but there is no “partial support” value to qualify their
  “experimental” support. Specifically, in the case of the `clang`s,
  reference-type template arguments referring to instantiation-dependent
  objects and subobjects (declared inside a template, but neither type- nor
  value-dependent) are not yet fully supported.
*/
#ifndef LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FIXES
  #define LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FIXES 0
#endif

/**
  @def LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FLOATS
  @brief Handle `float` types as non-type template arguments
  @details SD-6 equivalent: `__cpp_nontype_template_args >= 201911L`. Note that
  `__cpp_nontype_template_args` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201911L` [P1907R1](https://wg21.link/P1907R1) Inconsistencies with non-type
  template parameters

  @remark This is a proxy for support for everything in
  `LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FIXES` _except_ for certain types of
  references, as noted in the remakrs for that token.
*/
#ifndef LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FLOATS
  #define LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FLOATS 0
#endif

/**
  @def LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR
  @brief This is the original three-way comparison operator
  @details SD-6 equivalent: `__cpp_impl_three_way_comparison >= 201711L`. Note
  that `__cpp_impl_three_way_comparison` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `201711L` [P0515R3 __PDF__](https://wg21.link/P0515R3) Consistent comparison
  - `201711L` [P0768R1 __PDF__](https://wg21.link/P0768R1) Library Support for
  the Spaceship (Comparison) Operator
*/
#ifndef LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR
  #define LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR 0
#endif

/**
  @def LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_EQUALITY_FIX
  @brief This is the original three-way comparison operator
  @details SD-6 equivalent: `__cpp_impl_three_way_comparison >= 201902L`. Note
  that `__cpp_impl_three_way_comparison` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `201902L` [P1185R2](https://wg21.link/P1185R2) `<=> != ==`
*/
#ifndef LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_EQUALITY_FIX
  #define LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_EQUALITY_FIX 0
#endif

/**
  @def LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_TUNEUP
  @brief This is the updated three-way comparison operator
  @details SD-6 equivalent: `__cpp_impl_three_way_comparison >= 201907L`. Note
  that `__cpp_impl_three_way_comparison` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `201907L` [P1630R1](https://wg21.link/P1630R1) Spaceship needs a tune-up
*/
#ifndef LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_TUNEUP
  #define LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_TUNEUP 0
#endif

/**
  @def LBAL_CPP20_TYPENAME_OPTIONAL
  @brief Down with `typename`!
*/
#ifndef LBAL_CPP20_TYPENAME_OPTIONAL
  #define LBAL_CPP20_TYPENAME_OPTIONAL 0
#endif

/**
  @def LBAL_CPP20_USING_ENUM
  @brief Specify using aliases for enums
  @details SD-6 equivalent: `__cpp_using_enum >= 201907L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `201907L` [P1099R5](https://wg21.link/P1099R5) Using Enum
*/
#ifndef LBAL_CPP20_USING_ENUM
  #define LBAL_CPP20_USING_ENUM 0
#endif

/**
  @def LBAL_CPP20_VA_OPT
  @brief Provide a smarter predefined macro equivalent to __VA__ARGS__
  @details This behaves similarly to Microsoft’s old “broken” C preprocessor
  implementation in regards to variadic macro handling, in that [0..n] arguments
  are allowed rather than [1..n], with any extraneous comma being dropped.

  @remark Ironically, MSVC has no implementation of this.
*/
#ifndef LBAL_CPP20_VA_OPT
  #define LBAL_CPP20_VA_OPT 0
#endif

///	@}	LBAL_CPP20

///	@}	lbal_compiler
