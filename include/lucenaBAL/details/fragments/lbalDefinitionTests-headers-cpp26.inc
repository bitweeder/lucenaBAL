/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalDefinitionTests-headers-cpp26.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if defined(LBAL_HAS_HEADER_CONTRACTS)                                         \
    || defined(LBAL_HAS_HEADER_DEBUGGING)                                      \
    || defined(LBAL_HAS_HEADER_HAZARD_POINTER)                                 \
    || defined(LBAL_HAS_HEADER_HIVE)                                           \
    || defined(LBAL_HAS_HEADER_INPLACE_VECTOR)                                 \
    || defined(LBAL_HAS_HEADER_LINALG)                                         \
    || defined(LBAL_HAS_HEADER_META)                                           \
    || defined(LBAL_HAS_HEADER_RCU)                                            \
    || defined(LBAL_HAS_HEADER_SIMD)                                           \
    || defined(LBAL_HAS_HEADER_STDBIT_H)                                       \
    || defined(LBAL_HAS_HEADER_STDCKDINT_H)                                    \
    || defined(LBAL_HAS_HEADER_TEXT_ENCODING)
  #error "Don’t define LBAL_HAS_HEADER_xxx externally."
#endif  //	LBAL_HAS_HEADER_xxx C++26 check
