/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalDefinitionTests-headers-cpp17.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if defined(LBAL_HAS_HEADER_ANY)                                               \
    || defined(LBAL_HAS_HEADER_CHARCONV)                                       \
    || defined(LBAL_HAS_HEADER_EXECUTION)                                      \
    || defined(LBAL_HAS_HEADER_FILESYSTEM)                                     \
    || defined(LBAL_HAS_HEADER_EXPERIMENTAL_FILESYSTEM)                        \
    || defined(LBAL_HAS_HEADER_MEMORY_RESOURCE)                                \
    || defined(LBAL_HAS_HEADER_OPTIONAL)                                       \
    || defined(LBAL_HAS_HEADER_STRING_VIEW)                                    \
    || defined(LBAL_HAS_HEADER_VARIANT)
  #error "Don’t define LBAL_HAS_HEADER_xxx externally."
#endif  //	LBAL_HAS_HEADER_xxx C++17 check
