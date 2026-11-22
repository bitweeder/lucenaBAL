/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalDefinitionTests-headers-cpp23.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if defined(LBAL_HAS_HEADER_EXPECTED)                                          \
    || defined(LBAL_HAS_HEADER_FLAT_MAP)                                       \
    || defined(LBAL_HAS_HEADER_FLAT_SET)                                       \
    || defined(LBAL_HAS_HEADER_GENERATOR)                                      \
    || defined(LBAL_HAS_HEADER_MDSPAN)                                         \
    || defined(LBAL_HAS_HEADER_PRINT)                                          \
    || defined(LBAL_HAS_HEADER_SPANSTREAM)                                     \
    || defined(LBAL_HAS_HEADER_STACKTRACE)                                     \
    || defined(LBAL_HAS_HEADER_STDATOMIC_H)                                    \
    || defined(LBAL_HAS_HEADER_STDFLOAT)
  #error "Don’t define LBAL_HAS_HEADER_xxx externally."
#endif  //	LBAL_HAS_HEADER_xxx C++23 check
