/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalDefinitionTests-headers-cpp20.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if defined(LBAL_HAS_HEADER_BARRIER)                                           \
    || defined(LBAL_HAS_HEADER_BIT)                                            \
    || defined(LBAL_HAS_HEADER_COMPARE)                                        \
    || defined(LBAL_HAS_HEADER_CONCEPTS)                                       \
    || defined(LBAL_HAS_HEADER_EXPERIMENTAL_CONCEPTS)                          \
    || defined(LBAL_HAS_HEADER_COROUTINE)                                      \
    || defined(LBAL_HAS_HEADER_EXPERIMENTAL_COROUTINE)                         \
    || defined(LBAL_HAS_HEADER_FORMAT)                                         \
    || defined(LBAL_HAS_HEADER_LATCH)                                          \
    || defined(LBAL_HAS_HEADER_NUMBERS)                                        \
    || defined(LBAL_HAS_HEADER_RANGES)                                         \
    || defined(LBAL_HAS_HEADER_SEMAPHORE)                                      \
    || defined(LBAL_HAS_HEADER_SOURCE_LOCATION)                                \
    || defined(LBAL_HAS_HEADER_SPAN)                                           \
    || defined(LBAL_HAS_HEADER_STOP_TOKEN)                                     \
    || defined(LBAL_HAS_HEADER_SYNCSTREAM)                                     \
    || defined(LBAL_HAS_HEADER_VERSION)
  #error "Don’t define LBAL_HAS_HEADER_xxx externally."
#endif  //	LBAL_HAS_HEADER_xxx C++20 check
