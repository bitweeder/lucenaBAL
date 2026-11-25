/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalAppleClangPostInitialization.hpp”
  Copyright © 2019-2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/

#pragma once

//	lbal
#include <lucenaBAL/lbalConfig.hpp>

#include <lucenaBAL/details/lbalDetectCompiler.hpp>
#include <lucenaBAL/details/lbalKnownVersions.hpp>

/*------------------------------------------------------------------------------
  Apple clang compiler

  Note that if our tokens are undefined at this point, it means that the
  equivalent SD-6 tokens are undefined; this can happen because the
  implementation does not supply them, or because the feature in question is
  unavailable. We resolve this here, if needed. Note that any situation that
  would require us to pre-emptively disable a feature would have been handled
  previously in `lbalAppleClangInitialization.hpp`.
*/

#if LBAL_TARGET_COMPILER_APPLE_CLANG
//	C++98 features
//
//	These can be conditionally disabled. The older-style feature tests are
//	used in case the newer-style is unsupported, so they are checked after
//	the SD-6 checks have been performed.

  #if !defined(LBAL_CPP03_EXCEPTIONS) && __has_feature(__cxx_exceptions__)
    #define LBAL_CPP03_EXCEPTIONS 199711L
  #endif

  #if !defined(LBAL_CPP03_RTTI) && __has_feature(__cxx_exceptions__)
    #define LBAL_CPP03_RTTI 199711L
  #endif

//	C++20 features

  #if (__clang_major__ >= 10) && (LBAL_cpp_version > LBAL_CPP17_VERSION)
  //	SEEME - bitweeder
  //	None of these have SD-6 macros, so we rely on a compiler version check
  //	and a language test. This will miss back-ported extensions, but will
  //	pick up preview implementations.

    #if !defined(LBAL_CPP20_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS)
      #define LBAL_CPP20_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS 1L
    #endif

    #if !defined(LBAL_CPP20_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS)
      #define LBAL_CPP20_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS 1L
    #endif

    #if !defined(LBAL_CPP20_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS)
      #define LBAL_CPP20_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS 1L
    #endif

    #if !defined(LBAL_CPP20_VA_OPT)
      #define LBAL_CPP20_VA_OPT 1L
    #endif
  #endif

  #if (__clang_major__ >= 11) && (LBAL_cpp_version > LBAL_CPP17_VERSION)
  //	SEEME - bitweeder
  //	None of these have SD-6 macros, so we rely on a compiler version check
  //	and a language test. This will miss back-ported extensions, but will
  //	pick up preview implementations.

    #if !defined(LBAL_CPP20_INIT_STATEMENTS_FOR_RANGE_BASED_FOR)
      #define LBAL_CPP20_INIT_STATEMENTS_FOR_RANGE_BASED_FOR 1L
    #endif
  #endif

  #if (__clang_major__ >= 12) && (LBAL_cpp_version > LBAL_CPP17_VERSION)
    //	SEEME - bitweeder
    //	There is no SD-6 token for this. Apple clang started supporting it
    //  initially in a bug fix in the Xcode 10-series.
    #if !defined(                                                              \
        LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS      \
    )
      #define LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS \
        1L
    #endif
  #endif

  #if (__clang_major__ >= 16) && (LBAL_cpp_version > LBAL_CPP17_VERSION)
    //	SEEME (bitweeder) There is no SD-6 token for this.
    #if !defined(LBAL_CPP20_TYPENAME_OPTIONAL)
      #define LBAL_CPP20_TYPENAME_OPTIONAL 1L
    #endif
  #endif

//	SEEME These version checks map LLVM releases to Apple clang ones:
//	Apple clang 13 is based on LLVM 12, 16 on LLVM 17 and 17 on LLVM 19.
//	They haven’t been tested against Apple clang.

  #if (__clang_major__ >= 16) && (LBAL_cpp_version > LBAL_CPP17_VERSION)
    //	SEEME clang implements P1816R0 and P2082R1 (CTAD for aggregates) as of
    //	LLVM 17, but doesn’t raise `__cpp_deduction_guides` to `201907L`, since
    //	that value also covers P1814R0 (CTAD for alias templates).
    #if !defined(LBAL_CPP20_DEDUCTION_GUIDES_FOR_AGGREGATES)
      #define LBAL_CPP20_DEDUCTION_GUIDES_FOR_AGGREGATES 201907L
    #endif
  #endif

  #if (__clang_major__ >= 17) && (LBAL_cpp_version > LBAL_CPP17_VERSION)
    //	SEEME The `cxx_generalized_nttp` proxy in the Initialization header
    //	fails under `-pedantic-errors`, which makes `__has_extension` match
    //	`__has_feature`, and there is no matching feature check. See that
    //	header for why only the `float` part is reported (LLVM 18+).
    #if !LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FLOATS
      #undef LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FLOATS
      #define LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FLOATS 1
    #endif
  #endif

  #if (__clang_major__ >= 13)
    //	SEEME There is no SD-6 token for this. clang accepts `__VA_OPT__`,
    //	including `#__VA_OPT__` (P1042R1, LLVM 12), in every language mode
    //	without a diagnostic, even under `-pedantic-errors`.
    #if !defined(LBAL_CPP20_VA_OPT)
      #define LBAL_CPP20_VA_OPT 1L
    #endif
  #endif

  #if (LBAL_cpp_version <= LBAL_CPP17_VERSION)
    //  This can be erroneously defined for C++17. Preview modes such as
    //  `-std=c++2a` report a `__cplusplus` below the final C++20 value, so
    //  only C++17 and earlier are excluded.
    #if LBAL_CPP20_DESTROYING_DELETE
      #undef LBAL_CPP20_DESTROYING_DELETE
      #define LBAL_CPP20_DESTROYING_DELETE 0
    #endif
  #endif

//	SEEME
//	Clang accepts many later-Standard features in earlier modes as
//	extensions, and predefines their SD-6 macros and `__has_cpp_attribute`
//	values regardless of mode. When extensions are errors, those features
//	aren’t usable, so we turn the tokens off. `-pedantic-errors` is the only
//	such case the preprocessor can see: it makes `__has_extension` match
//	`__has_feature`, and `c_static_assert` is only ever an extension in C++.
//	Narrower flags such as `-Werror=c++26-extensions` can’t be detected.
//
//	The version checks use “at most the previous Standard” since a
//	preview mode reports a `__cplusplus` value below the final one.

  #if (LBAL_cpp_version <= LBAL_CPP17_VERSION)                                 \
      && !__has_extension(c_static_assert)
    //	C++20 features offered as extensions
    #if LBAL_CPP20_ATTRIBUTE_LIKELY
      #undef LBAL_CPP20_ATTRIBUTE_LIKELY
      #define LBAL_CPP20_ATTRIBUTE_LIKELY 0
    #endif

    #if LBAL_CPP20_ATTRIBUTE_UNLIKELY
      #undef LBAL_CPP20_ATTRIBUTE_UNLIKELY
      #define LBAL_CPP20_ATTRIBUTE_UNLIKELY 0
    #endif

    #if LBAL_CPP20_ATTRIBUTE_NODISCARD_EXPANDED
      #undef LBAL_CPP20_ATTRIBUTE_NODISCARD_EXPANDED
      #define LBAL_CPP20_ATTRIBUTE_NODISCARD_EXPANDED 0
    #endif
  #endif

  #if (LBAL_cpp_version <= LBAL_CPP20_VERSION)                                 \
      && !__has_extension(c_static_assert)
    //	C++23 features offered as extensions
    #if LBAL_CPP23_ATTRIBUTE_ASSUME
      #undef LBAL_CPP23_ATTRIBUTE_ASSUME
      #define LBAL_CPP23_ATTRIBUTE_ASSUME 0
    #endif

    #if LBAL_CPP23_NAMED_CHARACTER_ESCAPES
      #undef LBAL_CPP23_NAMED_CHARACTER_ESCAPES
      #define LBAL_CPP23_NAMED_CHARACTER_ESCAPES 0
    #endif

    #if LBAL_CPP23_STATIC_CALL_OPERATOR
      #undef LBAL_CPP23_STATIC_CALL_OPERATOR
      #define LBAL_CPP23_STATIC_CALL_OPERATOR 0
    #endif
  #endif

  #if (LBAL_cpp_version <= LBAL_CPP23_VERSION)                                 \
      && !__has_extension(c_static_assert)
    //	C++26 features offered as extensions
    #if LBAL_CPP26_DELETED_FUNCTION
      #undef LBAL_CPP26_DELETED_FUNCTION
      #define LBAL_CPP26_DELETED_FUNCTION 0
    #endif

    #if LBAL_CPP26_PACK_INDEXING
      #undef LBAL_CPP26_PACK_INDEXING
      #define LBAL_CPP26_PACK_INDEXING 0
    #endif

    #if LBAL_CPP26_PLACEHOLDER_VARIABLES
      #undef LBAL_CPP26_PLACEHOLDER_VARIABLES
      #define LBAL_CPP26_PLACEHOLDER_VARIABLES 0
    #endif

    #if LBAL_CPP26_STATIC_ASSERT_USER_MESSAGE
      #undef LBAL_CPP26_STATIC_ASSERT_USER_MESSAGE
      #define LBAL_CPP26_STATIC_ASSERT_USER_MESSAGE 0
    #endif

    #if LBAL_CPP26_STRUCTURED_BINDINGS_ATTRIBUTES
      #undef LBAL_CPP26_STRUCTURED_BINDINGS_ATTRIBUTES
      #define LBAL_CPP26_STRUCTURED_BINDINGS_ATTRIBUTES 0
    #endif

    #if LBAL_CPP26_STRUCTURED_BINDINGS_PACK
      #undef LBAL_CPP26_STRUCTURED_BINDINGS_PACK
      #define LBAL_CPP26_STRUCTURED_BINDINGS_PACK 0
    #endif

    #if LBAL_CPP26_VARIADIC_FRIEND
      #undef LBAL_CPP26_VARIADIC_FRIEND
      #define LBAL_CPP26_VARIADIC_FRIEND 0
    #endif
  #endif
#else
  #error                                                                       \
      "lbalAppleClangPostInitialization.hpp was directly included while using the wrong compiler"
#endif
