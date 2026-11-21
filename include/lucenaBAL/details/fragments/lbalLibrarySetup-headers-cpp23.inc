/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalLibrarySetup-headers-cpp23.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if defined(__has_include) && __has_include(<expected>)
  #define LBAL_HAS_HEADER_EXPECTED 1
#else
  #define LBAL_HAS_HEADER_EXPECTED 0
#endif

#if defined(__has_include) && __has_include(<flat_map>)
  #define LBAL_HAS_HEADER_FLAT_MAP 1
#else
  #define LBAL_HAS_HEADER_FLAT_MAP 0
#endif

#if defined(__has_include) && __has_include(<flat_set>)
  #define LBAL_HAS_HEADER_FLAT_SET 1
#else
  #define LBAL_HAS_HEADER_FLAT_SET 0
#endif

#if defined(__has_include) && __has_include(<generator>)
  #define LBAL_HAS_HEADER_GENERATOR 1
#else
  #define LBAL_HAS_HEADER_GENERATOR 0
#endif

#if defined(__has_include) && __has_include(<mdspan>)
  #define LBAL_HAS_HEADER_MDSPAN 1
#else
  #define LBAL_HAS_HEADER_MDSPAN 0
#endif

#if defined(__has_include) && __has_include(<print>)
  #define LBAL_HAS_HEADER_PRINT 1
#else
  #define LBAL_HAS_HEADER_PRINT 0
#endif

#if defined(__has_include) && __has_include(<spanstream>)
  #define LBAL_HAS_HEADER_SPANSTREAM 1
#else
  #define LBAL_HAS_HEADER_SPANSTREAM 0
#endif

#if defined(__has_include) && __has_include(<stacktrace>)
  #define LBAL_HAS_HEADER_STACKTRACE 1
#else
  #define LBAL_HAS_HEADER_STACKTRACE 0
#endif

#if defined(__has_include) && __has_include(<stdatomic.h>)
  #define LBAL_HAS_HEADER_STDATOMIC_H 1
#else
  #define LBAL_HAS_HEADER_STDATOMIC_H 0
#endif

#if defined(__has_include) && __has_include(<stdfloat>)
  #define LBAL_HAS_HEADER_STDFLOAT 1
#else
  #define LBAL_HAS_HEADER_STDFLOAT 0
#endif
