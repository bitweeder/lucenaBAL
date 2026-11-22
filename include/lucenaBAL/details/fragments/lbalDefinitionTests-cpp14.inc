/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalDefinitionTests-cpp14.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if defined(LBAL_CPP14_AGGREGATE_NSDMI)                                        \
    || defined(LBAL_CPP14_ATTRIBUTE_DEPRECATED)                                \
    || defined(LBAL_CPP14_BINARY_LITERALS)                                     \
    || defined(LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS)                       \
    || defined(LBAL_CPP14_DECLTYPE_AUTO)                                       \
    || defined(LBAL_CPP14_GENERIC_LAMBDAS)                                     \
    || defined(LBAL_CPP14_INIT_CAPTURES)                                       \
    || defined(LBAL_CPP14_RETURN_TYPE_DEDUCTION)                               \
    || defined(LBAL_CPP14_SIZED_DEALLOCATION)                                  \
    || defined(LBAL_CPP14_VARIABLE_TEMPLATES)
  #error "Don’t define LBAL_CPP14_xxx externally."
#endif  //	LBAL_CPP14 check
