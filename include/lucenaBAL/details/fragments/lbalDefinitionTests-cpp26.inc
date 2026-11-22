/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalDefinitionTests-cpp26.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if defined(LBAL_CPP26_ATTRIBUTE_INDETERMINATE)                                \
    || defined(LBAL_CPP26_CONSTEXPR_CAST_FROM_VOID_STAR)                       \
    || defined(LBAL_CPP26_CONSTEXPR_EXCEPTIONS)                                \
    || defined(LBAL_CPP26_CONSTEXPR_PLACEMENT_NEW)                             \
    || defined(LBAL_CPP26_CONSTEXPR_VIRTUAL_INHERITANCE)                       \
    || defined(LBAL_CPP26_CONTRACTS)                                           \
    || defined(LBAL_CPP26_DELETED_FUNCTION)                                    \
    || defined(LBAL_CPP26_EXPANSION_STATEMENTS)                                \
    || defined(LBAL_CPP26_FOLD_EXPRESSIONS_CONSTRAINTS)                        \
    || defined(LBAL_CPP26_IMPL_REFLECTION)                                     \
    || defined(LBAL_CPP26_IMPL_REFLECTION_CLEANUP)                             \
    || defined(LBAL_CPP26_PACK_INDEXING)                                       \
    || defined(LBAL_CPP26_PLACEHOLDER_VARIABLES)                               \
    || defined(LBAL_CPP26_PP_EMBED)                                            \
    || defined(LBAL_CPP26_STATIC_ASSERT_USER_MESSAGE)                          \
    || defined(LBAL_CPP26_STRUCTURED_BINDINGS_ATTRIBUTES)                      \
    || defined(LBAL_CPP26_STRUCTURED_BINDINGS_PACK)                            \
    || defined(LBAL_CPP26_TEMPLATE_PARAMETERS)                                 \
    || defined(LBAL_CPP26_TRIVIAL_UNION)                                       \
    || defined(LBAL_CPP26_TRIVIAL_UNION_LIFETIME)                              \
    || defined(LBAL_CPP26_VARIADIC_FRIEND)

  #error "Don’t define LBAL_CPP26_xxx externally."
#endif  //	LBAL_CPP26 check
