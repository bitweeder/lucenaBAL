/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalDefinitionTests-cpp23.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if defined(LBAL_CPP23_ATTRIBUTE_ASSUME)                                       \
    || defined(LBAL_CPP23_AUTO_CAST)                                           \
    || defined(LBAL_CPP23_CHAR8_T_COMPATIBILITY)                               \
    || defined(LBAL_CPP23_CONSTEVAL_PROPAGATE_UP)                              \
    || defined(LBAL_CPP23_CONSTEXPR_NON_LITERAL_VARIABLES)                     \
    || defined(LBAL_CPP23_CONSTEXPR_PERMIT_STATIC_CONSTEXPR)                   \
    || defined(LBAL_CPP23_CONSTEXPR_RELAX_RESTRICTIONS)                        \
    || defined(LBAL_CPP23_DEDUCTION_GUIDES_FROM_INHERITED_CONSTRUCTORS)        \
    || defined(LBAL_CPP23_EXPLICIT_THIS_PARAMETER)                             \
    || defined(LBAL_CPP23_IF_CONSTEVAL)                                        \
    || defined(LBAL_CPP23_IMPLICIT_MOVE)                                       \
    || defined(LBAL_CPP23_MULTIDIMENSIONAL_SUBSCRIPT)                          \
    || defined(LBAL_CPP23_MULTIDIMENSIONAL_SUBSCRIPT_STATIC)                   \
    || defined(LBAL_CPP23_NAMED_CHARACTER_ESCAPES)                             \
    || defined(LBAL_CPP23_RANGE_BASED_FOR_TEMPORARIES)                         \
    || defined(LBAL_CPP23_SIZE_T_SUFFIX)                                       \
    || defined(LBAL_CPP23_STATIC_CALL_OPERATOR)

  #error "Don’t define LBAL_CPP23_xxx externally."
#endif  //	LBAL_CPP23 check
