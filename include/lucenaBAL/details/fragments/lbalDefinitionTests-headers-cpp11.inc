/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalDefinitionTests-headers-cpp11.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if defined(LBAL_HAS_HEADER_ARRAY)                                             \
    || defined(LBAL_HAS_HEADER_ATOMIC)                                         \
    || defined(LBAL_HAS_HEADER_CFENV)                                          \
    || defined(LBAL_HAS_HEADER_CHRONO)                                         \
    || defined(LBAL_HAS_HEADER_CINTTYPES)                                      \
    || defined(LBAL_HAS_HEADER_CONDITION_VARIABLE)                             \
    || defined(LBAL_HAS_HEADER_CSTDALIGN)                                      \
    || defined(LBAL_HAS_HEADER_CSTDBOOL)                                       \
    || defined(LBAL_HAS_HEADER_CSTDINT)                                        \
    || defined(LBAL_HAS_HEADER_CUCHAR)                                         \
    || defined(LBAL_HAS_HEADER_FORWARD_LIST)                                   \
    || defined(LBAL_HAS_HEADER_FUTURE)                                         \
    || defined(LBAL_HAS_HEADER_INITIALIZER_LIST)                               \
    || defined(LBAL_HAS_HEADER_MUTEX)                                          \
    || defined(LBAL_HAS_HEADER_RANDOM)                                         \
    || defined(LBAL_HAS_HEADER_RATIO)                                          \
    || defined(LBAL_HAS_HEADER_REGEX)                                          \
    || defined(LBAL_HAS_HEADER_SCOPED_ALLOCATOR)                               \
    || defined(LBAL_HAS_HEADER_SYSTEM_ERROR)                                   \
    || defined(LBAL_HAS_HEADER_THREAD)                                         \
    || defined(LBAL_HAS_HEADER_TUPLE)                                          \
    || defined(LBAL_HAS_HEADER_TYPE_TRAITS)                                    \
    || defined(LBAL_HAS_HEADER_TYPEINDEX)                                      \
    || defined(LBAL_HAS_HEADER_UNORDERED_MAP)                                  \
    || defined(LBAL_HAS_HEADER_UNORDERED_SET)
  #error "Don’t define LBAL_HAS_HEADER_xxx externally."
#endif  //	LBAL_HAS_HEADER_xxx C++11 check
