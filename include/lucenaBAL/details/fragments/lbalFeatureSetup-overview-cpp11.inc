/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFeatureSetup-overview-cpp11.inc”
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
  @name LBAL_CPP11
  All supported compilers support all required features of C++11. However,
  @ref LBAL_CPP11_THREADSAFE_STATIC_INIT "thread-safe static initialization"
  can be explicitly disabled in some implementations, and
  @ref LBAL_CPP11_MINIMAL_GARBAGE_COLLECTION "garbage collection" was an
  optional feature from C++11 until C++23, when it was removed. The rest of
  these are supplied to allow testing for specific features when using older
  language dialects, unsupported compilers, or when general language version
  detection is unavailable.

  @remarks This is not an exhaustive list of C++11 language features. Rather,
  it is currently mostly a collection of those with SD-6 macros. The feature
  checks themselves are not necessarily tested on the minimal-supported
  compiler versions, as we will often rely on external reporting or make
  assumptions based on what `__cplusplus` returns, which is not the case for
  more recent features.

  @{
*/

/**
  @def LBAL_CPP11_ALIAS_TEMPLATES
  @brief Allow type aliases to be templated.
  @details SD-6 equivalent: `__cpp_alias_templates >= 200704L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `200704L` [N2258 __PDF__](https://wg21.link/N2258) Templates Aliases
*/
#ifndef LBAL_CPP11_ALIAS_TEMPLATES
  #define LBAL_CPP11_ALIAS_TEMPLATES 0
#endif

/**
  @def LBAL_CPP11_ATTRIBUTES
  @brief Formalize attributes as a language feature.
  @details SD-6 equivalent: `__cpp_attributes >= 200809L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `200809L` [N2761 __PDF__](https://wg21.link/N2761) Towards support for
  attributes in C++ (Revision 6)
*/
#ifndef LBAL_CPP11_ATTRIBUTES
  #define LBAL_CPP11_ATTRIBUTES 0
#endif

/**
  @def LBAL_CPP11_ATTRIBUTE_CARRIES_DEPENDENCY
  @brief Optimization hint when compiling with certain memory models
  @details SD-6 equivalent: `__has_cpp_attribute(carries_dependency) >=
  200809L`. This token will have a value of `0` if the proposal described here
  is not supported.
  - `200809L` [N2556](https://wg21.link/N2556) C++ Data-Dependency Ordering:
  Atomics and Memory Model
  - `200809L` [N2643](https://wg21.link/N2643) C++ Data-Dependency Ordering:
  Function Annotation
  - `200809L` [N2782](https://wg21.link/N2782) C++ Data-Dependency Ordering:
  Function Annotation
  - `200809L` [P3475R2 __PDF__](https://wg21.link/P3475R2) Defang and deprecate
  memory_order::consume
*/
#ifndef LBAL_CPP11_ATTRIBUTE_CARRIES_DEPENDENCY
  #define LBAL_CPP11_ATTRIBUTE_CARRIES_DEPENDENCY 0
#endif

/**
  @def LBAL_CPP11_ATTRIBUTE_NORETURN
  @brief Indicate that a function does not return
  @details SD-6 equivalent: `__has_cpp_attribute(noreturn) >= 200809L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `200809L` [N2761 __PDF__](https://wg21.link/N2761) Towards support for
  attributes in C++ (Revision 6)
*/
#ifndef LBAL_CPP11_ATTRIBUTE_NORETURN
  #define LBAL_CPP11_ATTRIBUTE_NORETURN 0
#endif

/**
  @def LBAL_CPP11_CONSTEXPR
  @brief Specify generalized constant expressions
  @details SD-6 equivalent: `__cpp_constexpr >= 200704L`. Note that
  `__cpp_constexpr` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `200704L` [N2235 __PDF__](https://wg21.link/N2235) Generalized Constant
  Expressions—Revision 5
*/
#ifndef LBAL_CPP11_CONSTEXPR
  #define LBAL_CPP11_CONSTEXPR 0
#endif

/**
  @def LBAL_CPP11_DECLTYPE
  @brief Query the type of an expression
  @details SD-6 equivalent: `__cpp_decltype >= 200707L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `200707L` [N2343 __PDF__](https://wg21.link/N2343) Decltype (revision 7):
  proposed wording
*/
#ifndef LBAL_CPP11_DECLTYPE
  #define LBAL_CPP11_DECLTYPE 0
#endif

/**
  @def LBAL_CPP11_DELEGATING_CONSTRUCTORS
  @brief Delegating constructors
  @details SD-6 equivalent: `__cpp_delegating_constructors >= 200604L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `200604L` [N1986 __PDF__](https://wg21.link/N1986) Delegating Constructors
  (revision 3)
*/
#ifndef LBAL_CPP11_DELEGATING_CONSTRUCTORS
  #define LBAL_CPP11_DELEGATING_CONSTRUCTORS 0
#endif

/**
  @def LBAL_CPP11_INHERITING_CONSTRUCTORS
  @brief Inheriting Constructors
  @details SD-6 equivalent: `__cpp_inheriting_constructors >= 200802L`. Note
  that `__cpp_inheriting_constructors` has multiple values associated with it
  from a number of different proposals, so this token will have the value of
  the latest supported proposal, or `0` if the proposal described here is not
  supported.
  - `200802L` [N2540](https://wg21.link/N2540) Inheriting Constructors
  (revision 5)
*/
#ifndef LBAL_CPP11_INHERITING_CONSTRUCTORS
  #define LBAL_CPP11_INHERITING_CONSTRUCTORS 0
#endif

/**
  @def LBAL_CPP11_INITIALIZER_LISTS
  @brief Initializer lists
  @details SD-6 equivalent: `__cpp_initializer_lists >= 200806L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `200806L` [N2672](https://wg21.link/N2672) Initializer List proposed wording
*/
#ifndef LBAL_CPP11_INITIALIZER_LISTS
  #define LBAL_CPP11_INITIALIZER_LISTS 0
#endif

/**
  @def LBAL_CPP11_LAMBDAS
  @brief Support for Lambda functions
  @details SD-6 equivalent: `__cpp_lambdas >= 200907L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `200907L` [N2927 __PDF__](https://wg21.link/N2927) New wording for C++0x
  Lambdas (rev. 2)
*/
#ifndef LBAL_CPP11_LAMBDAS
  #define LBAL_CPP11_LAMBDAS 0
#endif

/**
  @def LBAL_CPP11_MINIMAL_GARBAGE_COLLECTION
  @brief Support for optional C++ garbage collection.
*/
#ifndef LBAL_CPP11_MINIMAL_GARBAGE_COLLECTION
  #define LBAL_CPP11_MINIMAL_GARBAGE_COLLECTION 0
#endif

/**
  @def LBAL_CPP11_NSDMI
  @brief Support for non-static data member initializers.
  @details SD-6 equivalent: `__cpp_nsdmi >= 200809L`. This token will have a
  value of `0` if the proposal described here is not supported.
  - `200809L` [N2756](https://wg21.link/N2756) Non-static data member
  initializers
*/
#ifndef LBAL_CPP11_NSDMI
  #define LBAL_CPP11_NSDMI 0
#endif

/**
  @def LBAL_CPP11_RANGE_BASED_FOR
  @brief Range-based for-loops
  @details SD-6 equivalent: `__cpp_range_based_for >= 200907L`. Note that
  `__cpp_range_based_for` has multiple values associated with it from a number
  of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `200907L` [N2930](https://wg21.link/N2930) Range-Based For Loop Wording
  (Without Concepts)
*/
#ifndef LBAL_CPP11_RANGE_BASED_FOR
  #define LBAL_CPP11_RANGE_BASED_FOR 0
#endif

/**
  @def LBAL_CPP11_RAW_STRINGS
  @brief Support for raw string literals
  @details SD-6 equivalent: `__cpp_raw_strings >= 200710L`. This token will have
  a value of `0` if the proposal described here is not supported.
  - `200710L` [N2442](https://wg21.link/N2442) Raw and Unicode String Literals;
  Unified Proposal (Rev. 2)
*/
#ifndef LBAL_CPP11_RAW_STRINGS
  #define LBAL_CPP11_RAW_STRINGS 0
#endif

/**
  @def LBAL_CPP11_REF_QUALIFIERS
  @brief Extend move semantics to *this
  @details SD-6 equivalent: `__cpp_ref_qualifiers >= 200710L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `200710L` [N2439](https://wg21.link/N2439) Extending move semantics to *this
  (revised wording)
*/
#ifndef LBAL_CPP11_REF_QUALIFIERS
  #define LBAL_CPP11_REF_QUALIFIERS 0
#endif

/**
  @def LBAL_CPP11_RVALUE_REFERENCES
  @brief Add rvalue references
  @details SD-6 equivalent: `__cpp_rvalue_references >= 200610L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `200610L` [N2118](https://wg21.link/N2118) A Proposal to Add an Rvalue
  Reference to the C++ Language: Proposed Wording: Revision 3
*/
#ifndef LBAL_CPP11_RVALUE_REFERENCES
  #define LBAL_CPP11_RVALUE_REFERENCES 0
#endif

/**
  @def LBAL_CPP11_STATIC_ASSERT
  @brief Add static assertions
  @details SD-6 equivalent: `__cpp_static_assert >= 200410L`. Note that
  `__cpp_static_assert` has multiple values associated with it from a number of
  different proposals, so this token will have the value of the latest supported
  proposal, or `0` if the proposal described here is not supported.
  - `200410L` [N1720](https://wg21.link/N1720) Proposal to Add Static Assertions
  to the Core Language (Revision 3)
*/
#ifndef LBAL_CPP11_STATIC_ASSERT
  #define LBAL_CPP11_STATIC_ASSERT 0
#endif

/**
  @def LBAL_CPP11_THREADSAFE_STATIC_INIT
  @brief Support for thread-safe static initialization.
  @details Some compilers can disable this feature if asked; the token will be
  set to `0` if that has happened.

  SD-6 equivalent: `__cpp_threadsafe_static_init >= 200806L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `200806L` [N2660](https://wg21.link/N2660) Dynamic Initialization and
  Destruction with Concurrency
*/
#ifndef LBAL_CPP11_THREADSAFE_STATIC_INIT
  #define LBAL_CPP11_THREADSAFE_STATIC_INIT 0
#endif

/**
  @def LBAL_CPP11_UNICODE_CHARACTERS
  @brief Add `char16_t` and `char32_t` with requisite Unicode encoding
  @details SD-6 equivalent: `__cpp_unicode_characters >= 200704L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `200704L` [N2249](https://wg21.link/N2249) New Character Types in C++
*/
#ifndef LBAL_CPP11_UNICODE_CHARACTERS
  #define LBAL_CPP11_UNICODE_CHARACTERS 0
#endif

/**
  @def LBAL_CPP11_UNICODE_LITERALS
  @brief Support for Unicode string literals
  @details SD-6 equivalent: `__cpp_unicode_literals >= 200710L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `200710L` [N2442](https://wg21.link/N2442) Raw and Unicode String Literals;
  Unified Proposal (Rev. 2)
*/
#ifndef LBAL_CPP11_UNICODE_LITERALS
  #define LBAL_CPP11_UNICODE_LITERALS 0
#endif

/**
  @def LBAL_CPP11_USER_DEFINED_LITERALS
  @brief Support for user-defined literals
  @details SD-6 equivalent: `__cpp_user_defined_literals >= 200809L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `200809L` [N2765 __PDF__](https://wg21.link/N2765) User-defined Literals
  (aka. Extensible Literals (revision 5))
*/
#ifndef LBAL_CPP11_USER_DEFINED_LITERALS
  #define LBAL_CPP11_USER_DEFINED_LITERALS 0
#endif

/**
  @def LBAL_CPP11_VARIADIC_TEMPLATES
  @brief Support for templates with variable numbers of arguments
  @details SD-6 equivalent: `__cpp_variadic_templates >= 200704L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `200704L` [N2242 __PDF__](https://wg21.link/N2242) Proposed Wording for
  Variadic Templates (Revision 2)
*/
#ifndef LBAL_CPP11_VARIADIC_TEMPLATES
  #define LBAL_CPP11_VARIADIC_TEMPLATES 0
#endif

///	@}	LBAL_CPP11

///	@}	lbal_compiler
