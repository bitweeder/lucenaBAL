/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalCompilerSetup-definitions-cpp2d.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if !defined(LBAL_CPP2D_CONCEPTS_CONDITIONAL_NOEXCEPT)                         \
    && (__cpp_concepts >= 202606L)
  #define LBAL_CPP2D_CONCEPTS_CONDITIONAL_NOEXCEPT __cpp_concepts
#endif

#if !defined(LBAL_CPP2D_CONSTEVAL_ONLY) && (__cpp_consteval >= 202606L)
  #define LBAL_CPP2D_CONSTEVAL_ONLY __cpp_consteval
#endif

#if !defined(LBAL_CPP2D_CONTRACTS_VIRTUAL) && (__cpp_contracts >= 202606L)
  #define LBAL_CPP2D_CONTRACTS_VIRTUAL __cpp_contracts
#endif

#if !defined(LBAL_CPP2D_DESIGNATED_INITIALIZERS_BASE_CLASSES)                  \
    && (__cpp_designated_initializers >= 202606L)
  #define LBAL_CPP2D_DESIGNATED_INITIALIZERS_BASE_CLASSES                      \
    __cpp_designated_initializers
#endif

#if !defined(LBAL_CPP2D_IMPL_COROUTINE_RETURN)                                 \
    && (__cpp_impl_coroutine >= 202606L)
  #define LBAL_CPP2D_IMPL_COROUTINE_RETURN __cpp_impl_coroutine
#endif

#if !defined(LBAL_CPP2D_PACK_INDEXING_TEMPLATE_NAMES)                          \
    && (__cpp_pack_indexing >= 202606L)
  #define LBAL_CPP2D_PACK_INDEXING_TEMPLATE_NAMES __cpp_pack_indexing
#endif

#if !defined(LBAL_CPP2D_PP_EMBED_OFFSET) && (__cpp_pp_embed >= 202606L)
  #define LBAL_CPP2D_PP_EMBED_OFFSET __cpp_pp_embed
#endif
