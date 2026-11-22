/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalCompilerSetup-definitions-cpp26.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

//	C++26 Language

#if !defined(LBAL_CPP26_CONSTEXPR_CAST_FROM_VOID_STAR)                         \
    && (__cpp_constexpr >= 202306L)
  #define LBAL_CPP26_CONSTEXPR_CAST_FROM_VOID_STAR __cpp_constexpr
#endif

#if !defined(LBAL_CPP26_CONSTEXPR_EXCEPTIONS)                                  \
    && (__cpp_constexpr_exceptions >= 202411L)
  #define LBAL_CPP26_CONSTEXPR_EXCEPTIONS __cpp_constexpr_exceptions
#endif

#if !defined(LBAL_CPP26_CONSTEXPR_PLACEMENT_NEW) && (__cpp_constexpr >= 202406L)
  #define LBAL_CPP26_CONSTEXPR_PLACEMENT_NEW __cpp_constexpr
#endif

#if !defined(LBAL_CPP26_CONSTEXPR_VIRTUAL_INHERITANCE)                         \
    && (__cpp_constexpr_virtual_inheritance >= 202506L)
  #define LBAL_CPP26_CONSTEXPR_VIRTUAL_INHERITANCE                             \
    __cpp_constexpr_virtual_inheritance
#endif

#if !defined(LBAL_CPP26_CONTRACTS) && (__cpp_contracts >= 202502L)
  #define LBAL_CPP26_CONTRACTS __cpp_contracts
#endif

#if !defined(LBAL_CPP26_DELETED_FUNCTION) && (__cpp_deleted_function >= 202403L)
  #define LBAL_CPP26_DELETED_FUNCTION __cpp_deleted_function
#endif

#if !defined(LBAL_CPP26_EXPANSION_STATEMENTS)                                  \
    && (__cpp_expansion_statements >= 202506L)
  #define LBAL_CPP26_EXPANSION_STATEMENTS __cpp_expansion_statements
#endif

#if !defined(LBAL_CPP26_FOLD_EXPRESSIONS_CONSTRAINTS)                          \
    && (__cpp_fold_expressions >= 202406L)
  #define LBAL_CPP26_FOLD_EXPRESSIONS_CONSTRAINTS __cpp_fold_expressions
#endif

#if !defined(LBAL_CPP26_IMPL_REFLECTION) && (__cpp_impl_reflection >= 202506L)
  #define LBAL_CPP26_IMPL_REFLECTION __cpp_impl_reflection
#endif

#if !defined(LBAL_CPP26_IMPL_REFLECTION_CLEANUP)                               \
    && (__cpp_impl_reflection >= 202603L)
  #define LBAL_CPP26_IMPL_REFLECTION_CLEANUP __cpp_impl_reflection
#endif

#if !defined(LBAL_CPP26_PACK_INDEXING) && (__cpp_pack_indexing >= 202311L)
  #define LBAL_CPP26_PACK_INDEXING __cpp_pack_indexing
#endif

#if !defined(LBAL_CPP26_PLACEHOLDER_VARIABLES)                                 \
    && (__cpp_placeholder_variables >= 202306L)
  #define LBAL_CPP26_PLACEHOLDER_VARIABLES __cpp_placeholder_variables
#endif

#if !defined(LBAL_CPP26_PP_EMBED) && (__cpp_pp_embed >= 202502L)
  #define LBAL_CPP26_PP_EMBED __cpp_pp_embed
#endif

#if !defined(LBAL_CPP26_STATIC_ASSERT_USER_MESSAGE)                            \
    && (__cpp_static_assert >= 202306L)
  #define LBAL_CPP26_STATIC_ASSERT_USER_MESSAGE __cpp_static_assert
#endif

#if !defined(LBAL_CPP26_STRUCTURED_BINDINGS_ATTRIBUTES)                        \
    && (__cpp_structured_bindings >= 202403L)
  #define LBAL_CPP26_STRUCTURED_BINDINGS_ATTRIBUTES __cpp_structured_bindings
#endif

#if !defined(LBAL_CPP26_STRUCTURED_BINDINGS_PACK)                              \
    && (__cpp_structured_bindings >= 202411L)
  #define LBAL_CPP26_STRUCTURED_BINDINGS_PACK __cpp_structured_bindings
#endif

#if !defined(LBAL_CPP26_TEMPLATE_PARAMETERS)                                   \
    && (__cpp_template_parameters >= 202502L)
  #define LBAL_CPP26_TEMPLATE_PARAMETERS __cpp_template_parameters
#endif

#if !defined(LBAL_CPP26_TRIVIAL_UNION) && (__cpp_trivial_union >= 202502L)
  #define LBAL_CPP26_TRIVIAL_UNION __cpp_trivial_union
#endif

#if !defined(LBAL_CPP26_TRIVIAL_UNION_LIFETIME)                                \
    && (__cpp_trivial_union >= 202603L)
  #define LBAL_CPP26_TRIVIAL_UNION_LIFETIME __cpp_trivial_union
#endif

#if !defined(LBAL_CPP26_VARIADIC_FRIEND) && (__cpp_variadic_friend >= 202403L)
  #define LBAL_CPP26_VARIADIC_FRIEND __cpp_variadic_friend
#endif

//	C++26 Attributes

#if !defined(LBAL_CPP26_ATTRIBUTE_INDETERMINATE)                               \
    && defined(__has_cpp_attribute)                                            \
    && (__has_cpp_attribute(indeterminate) >= 202403L)
  #define LBAL_CPP26_ATTRIBUTE_INDETERMINATE 202403L
#endif
