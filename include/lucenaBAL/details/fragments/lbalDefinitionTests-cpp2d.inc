/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalDefinitionTests-cpp2d.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if defined(LBAL_CPP2D_CONCEPTS_CONDITIONAL_NOEXCEPT)                          \
    || defined(LBAL_CPP2D_CONSTEVAL_ONLY)                                      \
    || defined(LBAL_CPP2D_CONTRACTS_VIRTUAL)                                   \
    || defined(LBAL_CPP2D_DESIGNATED_INITIALIZERS_BASE_CLASSES)                \
    || defined(LBAL_CPP2D_IMPL_COROUTINE_RETURN)                               \
    || defined(LBAL_CPP2D_PACK_INDEXING_TEMPLATE_NAMES)                        \
    || defined(LBAL_CPP2D_PP_EMBED_OFFSET)
  #error "Don’t define LBAL_CPP2D_xxx externally."
#endif  //	LBAL_CPP2D check
