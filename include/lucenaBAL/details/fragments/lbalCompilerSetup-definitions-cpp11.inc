/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalCompilerSetup-definitions-cpp11.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

//	C++11 Language
//
//	We check for “C++11 or greater” (as opposed to “greater than C++98”) since
//	our earliest supported dialect is C++11; these should (mostly) always be
//	available, though we still go through the formality of checking. Individual
//	compilers may still override, of course.

#if LBAL_cpp_version >= LBAL_CPP11_VERSION
  #if !defined(LBAL_CPP11_ALIAS_TEMPLATES)
    #if (__cpp_alias_templates >= 200704L)
      #define LBAL_CPP11_ALIAS_TEMPLATES __cpp_alias_templates
    #else
      #define LBAL_CPP11_ALIAS_TEMPLATES 200704L
    #endif
  #endif

  #if !defined(LBAL_CPP11_ATTRIBUTES)
    #if (__cpp_attributes >= 200809L)
      #define LBAL_CPP11_ATTRIBUTES __cpp_attributes
    #else
      #define LBAL_CPP11_ATTRIBUTES 200809L
    #endif
  #endif

  #if !defined(LBAL_CPP11_CONSTEXPR)
    #if (__cpp_constexpr >= 200704L)
      #define LBAL_CPP11_CONSTEXPR __cpp_constexpr
    #else
      #define LBAL_CPP11_CONSTEXPR 200704L
    #endif
  #endif

  #if !defined(LBAL_CPP11_DECLTYPE)
    #if (__cpp_decltype >= 200707L)
      #define LBAL_CPP11_DECLTYPE __cpp_decltype
    #else
      #define LBAL_CPP11_DECLTYPE 200707L
    #endif
  #endif

  #if !defined(LBAL_CPP11_DELEGATING_CONSTRUCTORS)
    #if (__cpp_delegating_constructors >= 200604L)
      #define LBAL_CPP11_DELEGATING_CONSTRUCTORS __cpp_delegating_constructors
    #else
      #define LBAL_CPP11_DELEGATING_CONSTRUCTORS 200604L
    #endif
  #endif

  #if !defined(LBAL_CPP11_INHERITING_CONSTRUCTORS)
    #if (__cpp_inheriting_constructors >= 200802L)
      #define LBAL_CPP11_INHERITING_CONSTRUCTORS __cpp_inheriting_constructors
    #else
      #define LBAL_CPP11_INHERITING_CONSTRUCTORS 200802L
    #endif
  #endif

  #if !defined(LBAL_CPP11_INITIALIZER_LISTS)
    #if (__cpp_initializer_lists >= 200806L)
      #define LBAL_CPP11_INITIALIZER_LISTS __cpp_initializer_lists
    #else
      #define LBAL_CPP11_INITIALIZER_LISTS 200806L
    #endif
  #endif

  #if !defined(LBAL_CPP11_LAMBDAS)
    #if (__cpp_lambdas >= 200907L)
      #define LBAL_CPP11_LAMBDAS __cpp_lambdas
    #else
      #define LBAL_CPP11_LAMBDAS 200907L
    #endif
  #endif

  #if !defined(LBAL_CPP11_NSDMI)
    #if (__cpp_nsdmi >= 200809L)
      #define LBAL_CPP11_NSDMI __cpp_nsdmi
    #else
      #define LBAL_CPP11_NSDMI 200809L
    #endif
  #endif

  #if !defined(LBAL_CPP11_RANGE_BASED_FOR)
    #if (__cpp_range_based_for >= 200907L)
      #define LBAL_CPP11_RANGE_BASED_FOR __cpp_range_based_for
    #else
      #define LBAL_CPP11_RANGE_BASED_FOR 200907L
    #endif
  #endif

  #if !defined(LBAL_CPP11_RAW_STRINGS)
    #if (__cpp_raw_strings >= 200710L)
      #define LBAL_CPP11_RAW_STRINGS __cpp_raw_strings
    #else
      #define LBAL_CPP11_RAW_STRINGS 200710L
    #endif
  #endif

  #if !defined(LBAL_CPP11_REF_QUALIFIERS)
    #if (__cpp_ref_qualifiers >= 200710L)
      #define LBAL_CPP11_REF_QUALIFIERS __cpp_ref_qualifiers
    #else
      #define LBAL_CPP11_REF_QUALIFIERS 200710L
    #endif
  #endif

  #if !defined(LBAL_CPP11_RVALUE_REFERENCES)
    #if (__cpp_rvalue_references >= 200610L)
      #define LBAL_CPP11_RVALUE_REFERENCES __cpp_rvalue_references
    #else
      #define LBAL_CPP11_RVALUE_REFERENCES 200610L
    #endif
  #endif

  #if !defined(LBAL_CPP11_STATIC_ASSERT)
    #if (__cpp_static_assert >= 200410L)
      #define LBAL_CPP11_STATIC_ASSERT __cpp_static_assert
    #else
      #define LBAL_CPP11_STATIC_ASSERT 200410L
    #endif
  #endif

  #if !defined(LBAL_CPP11_THREADSAFE_STATIC_INIT)
    #if (__cpp_threadsafe_static_init >= 200806L)
      #define LBAL_CPP11_THREADSAFE_STATIC_INIT __cpp_threadsafe_static_init
    #else
      #define LBAL_CPP11_THREADSAFE_STATIC_INIT 200806L
    #endif
  #endif

  #if !defined(LBAL_CPP11_UNICODE_CHARACTERS)
    #if (__cpp_unicode_characters >= 200704L)
      #define LBAL_CPP11_UNICODE_CHARACTERS __cpp_unicode_characters
    #else
      #define LBAL_CPP11_UNICODE_CHARACTERS 200704L
    #endif
  #endif

  #if !defined(LBAL_CPP11_UNICODE_LITERALS)
    #if (__cpp_unicode_literals >= 200710L)
      #define LBAL_CPP11_UNICODE_LITERALS __cpp_unicode_literals
    #else
      #define LBAL_CPP11_UNICODE_LITERALS 200710L
    #endif
  #endif

  #if !defined(LBAL_CPP11_USER_DEFINED_LITERALS)
    #if (__cpp_user_defined_literals >= 200809L)
      #define LBAL_CPP11_USER_DEFINED_LITERALS __cpp_user_defined_literals
    #else
      #define LBAL_CPP11_USER_DEFINED_LITERALS 200809L
    #endif
  #endif

  #if !defined(LBAL_CPP11_VARIADIC_TEMPLATES)
    #if (__cpp_variadic_templates >= 200704L)
      #define LBAL_CPP11_VARIADIC_TEMPLATES __cpp_variadic_templates
    #else
      #define LBAL_CPP11_VARIADIC_TEMPLATES 200704L
    #endif
  #endif
#endif  //	LBAL_CPP11_VERSION

//	C++11 Attributes
//
//	We check for “C++11 or greater” (as opposed to “greater than C++98”) since
//	our earliest supported dialect is C++11; these should (mostly) always be
//	available, though we still go through the formality of checking. We also go
//	through the motions of explicitly checking the SD-6 macro results as a
//	placeholder. Individual compilers may still override these, of course.

#if LBAL_cpp_version >= LBAL_CPP11_VERSION
  #if !defined(LBAL_CPP11_ATTRIBUTE_NORETURN)
    #if defined(__has_cpp_attribute)                                           \
        && (__has_cpp_attribute(noreturn) >= 200809L)
      #define LBAL_CPP11_ATTRIBUTE_NORETURN 200809L
    #else
      #define LBAL_CPP11_ATTRIBUTE_NORETURN 200809L
    #endif
  #endif
#endif  //	LBAL_CPP11_VERSION
