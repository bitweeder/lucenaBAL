/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalLibrarySetup-headers-cpp20.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if defined(__has_include) && __has_include(<barrier>)
  #define LBAL_HAS_HEADER_BARRIER 1
#else
  #define LBAL_HAS_HEADER_BARRIER 0
#endif

#if defined(__has_include) && __has_include(<bit>)
  #define LBAL_HAS_HEADER_BIT 1
#else
  #define LBAL_HAS_HEADER_BIT 0
#endif

#if defined(__has_include) && __has_include(<compare>)
  #define LBAL_HAS_HEADER_COMPARE 1
#else
  #define LBAL_HAS_HEADER_COMPARE 0
#endif

#if defined(__has_include) && __has_include(<concepts>)
  #define LBAL_HAS_HEADER_CONCEPTS 1
#else
  #define LBAL_HAS_HEADER_CONCEPTS 0
#endif

#if defined(__has_include) && __has_include(<coroutine>)
  #define LBAL_HAS_HEADER_COROUTINE 1
#else
  #define LBAL_HAS_HEADER_COROUTINE 0
#endif

//  This was technically removed in C++20, but the file may still be there for
//  backwards compatibility.
#if defined(__has_include) && __has_include(<experimental/concepts>)
  #define LBAL_HAS_HEADER_EXPERIMENTAL_CONCEPTS 1
#else
  #define LBAL_HAS_HEADER_EXPERIMENTAL_CONCEPTS 0
#endif

//  This was technically removed in C++20, but the file may still be there for
//  backwards compatibility.
#if defined(__has_include) && __has_include(<experimental/coroutine>)
  #define LBAL_HAS_HEADER_EXPERIMENTAL_COROUTINE 1
#else
  #define LBAL_HAS_HEADER_EXPERIMENTAL_COROUTINE 0
#endif

#if defined(__has_include) && __has_include(<format>)
  #define LBAL_HAS_HEADER_FORMAT 1
#else
  #define LBAL_HAS_HEADER_FORMAT 0
#endif

#if defined(__has_include) && __has_include(<latch>)
  #define LBAL_HAS_HEADER_LATCH 1
#else
  #define LBAL_HAS_HEADER_LATCH 0
#endif

#if defined(__has_include) && __has_include(<numbers>)
  #define LBAL_HAS_HEADER_NUMBERS 1
#else
  #define LBAL_HAS_HEADER_NUMBERS 0
#endif

#if defined(__has_include) && __has_include(<ranges>)
  #define LBAL_HAS_HEADER_RANGES 1
#else
  #define LBAL_HAS_HEADER_RANGES 0
#endif

#if defined(__has_include) && __has_include(<semaphore>)
  #define LBAL_HAS_HEADER_SEMAPHORE 1
#else
  #define LBAL_HAS_HEADER_SEMAPHORE 0
#endif

#if defined(__has_include) && __has_include(<source_location>)
  #define LBAL_HAS_HEADER_SOURCE_LOCATION 1
#else
  #define LBAL_HAS_HEADER_SOURCE_LOCATION 0
#endif

#if defined(__has_include) && __has_include(<span>)
  #define LBAL_HAS_HEADER_SPAN 1
#else
  #define LBAL_HAS_HEADER_SPAN 0
#endif

#if defined(__has_include) && __has_include(<stop_token>)
  #define LBAL_HAS_HEADER_STOP_TOKEN 1
#else
  #define LBAL_HAS_HEADER_STOP_TOKEN 0
#endif

#if defined(__has_include) && __has_include(<syncstream>)
  #define LBAL_HAS_HEADER_SYNCSTREAM 1
#else
  #define LBAL_HAS_HEADER_SYNCSTREAM 0
#endif

#if defined(__has_include) && __has_include(<version>)
  #define LBAL_HAS_HEADER_VERSION 1
#else
  #define LBAL_HAS_HEADER_VERSION 0
#endif
