/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalDefinitionTests-cpp11.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if defined(LBAL_CPP11_ALIAS_TEMPLATES)                                        \
    || defined(LBAL_CPP11_ATTRIBUTES)                                          \
    || defined(LBAL_CPP11_ATTRIBUTE_NORETURN)                                  \
    || defined(LBAL_CPP11_CONSTEXPR)                                           \
    || defined(LBAL_CPP11_DECLTYPE)                                            \
    || defined(LBAL_CPP11_DELEGATING_CONSTRUCTORS)                             \
    || defined(LBAL_CPP11_INHERITING_CONSTRUCTORS)                             \
    || defined(LBAL_CPP11_INITIALIZER_LISTS)                                   \
    || defined(LBAL_CPP11_LAMBDAS)                                             \
    || defined(LBAL_CPP11_MINIMAL_GARBAGE_COLLECTION)                          \
    || defined(LBAL_CPP11_NSDMI)                                               \
    || defined(LBAL_CPP11_RANGE_BASED_FOR)                                     \
    || defined(LBAL_CPP11_RAW_STRINGS)                                         \
    || defined(LBAL_CPP11_REF_QUALIFIERS)                                      \
    || defined(LBAL_CPP11_RVALUE_REFERENCES)                                   \
    || defined(LBAL_CPP11_STATIC_ASSERT)                                       \
    || defined(LBAL_CPP11_THREADSAFE_STATIC_INIT)                              \
    || defined(LBAL_CPP11_UNICODE_CHARACTERS)                                  \
    || defined(LBAL_CPP11_UNICODE_LITERALS)                                    \
    || defined(LBAL_CPP11_USER_DEFINED_LITERALS)                               \
    || defined(LBAL_CPP11_VARIADIC_TEMPLATES)
  #error "Don’t define LBAL_CPP11_xxx externally."
#endif  //	LBAL_CPP11 check
