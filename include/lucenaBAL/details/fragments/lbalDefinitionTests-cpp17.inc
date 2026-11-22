/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalDefinitionTests-cpp17.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if defined(LBAL_CPP17_AGGREGATE_BASES)                                        \
    || defined(LBAL_CPP17_ALIGNED_NEW)                                         \
    || defined(LBAL_CPP17_ATTRIBUTE_FALLTHROUGH)                               \
    || defined(LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED)                              \
    || defined(LBAL_CPP17_ATTRIBUTE_NODISCARD)                                 \
    || defined(LBAL_CPP17_CAPTURE_STAR_THIS)                                   \
    || defined(LBAL_CPP17_CONSTEXPR_LAMBDA)                                    \
    || defined(LBAL_CPP17_DEDUCTION_GUIDES)                                    \
    || defined(LBAL_CPP17_DEDUCTION_GUIDES_DR)                                 \
    || defined(LBAL_CPP17_DEDUCTION_GUIDES_NB)                                 \
    || defined(LBAL_CPP17_ENUMERATOR_ATTRIBUTES)                               \
    || defined(LBAL_CPP17_FOLD_EXPRESSIONS)                                    \
    || defined(LBAL_CPP17_FOLD_EXPRESSIONS_REVISED)                            \
    || defined(LBAL_CPP17_GUARANTEED_COPY_ELISION)                             \
    || defined(LBAL_CPP17_HEX_FLOAT)                                           \
    || defined(LBAL_CPP17_IF_CONSTEXPR)                                        \
    || defined(LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED)                     \
    || defined(LBAL_CPP17_INLINE_VARIABLES)                                    \
    || defined(LBAL_CPP17_NAMESPACE_ATTRIBUTES)                                \
    || defined(LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE)                              \
    || defined(LBAL_CPP17_NONTYPE_TEMPLATE_ARGS)                               \
    || defined(LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO)                     \
    || defined(LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED)                         \
    || defined(LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE)                            \
    || defined(LBAL_CPP17_STRUCTURED_BINDINGS)                                 \
    || defined(LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS)                              \
    || defined(LBAL_CPP17_VARIADIC_USING)

  #error "Don’t define LBAL_CPP17_xxx externally."
#endif  //	LBAL_CPP17 check
