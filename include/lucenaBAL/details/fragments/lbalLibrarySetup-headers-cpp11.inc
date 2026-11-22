/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalLibrarySetup-headers-cpp11.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if !defined(__has_include) || __has_include(<array>)
  #define LBAL_HAS_HEADER_ARRAY 1
#else
  #define LBAL_HAS_HEADER_ARRAY 0
#endif

#if !defined(__has_include) || __has_include(<atomic>)
  #define LBAL_HAS_HEADER_ATOMIC 1
#else
  #define LBAL_HAS_HEADER_ATOMIC 0
#endif

#if !defined(__has_include) || __has_include(<cfenv>)
  #define LBAL_HAS_HEADER_CFENV 1
#else
  #define LBAL_HAS_HEADER_CFENV 0
#endif

#if !defined(__has_include) || __has_include(<chrono>)
  #define LBAL_HAS_HEADER_CHRONO 1
#else
  #define LBAL_HAS_HEADER_CHRONO 0
#endif

#if !defined(__has_include) || __has_include(<cinttypes>)
  #define LBAL_HAS_HEADER_CINTTYPES 1
#else
  #define LBAL_HAS_HEADER_CINTTYPES 0
#endif

#if !defined(__has_include) || __has_include(<condition_variable>)
  #define LBAL_HAS_HEADER_CONDITION_VARIABLE 1
#else
  #define LBAL_HAS_HEADER_CONDITION_VARIABLE 0
#endif

//  This was technically removed in C++20, but the file may still be there for
//  backwards compatibility.
#if !defined(__has_include) || __has_include(<cstdalign>)
  #define LBAL_HAS_HEADER_CSTDALIGN 1
#else
  #define LBAL_HAS_HEADER_CSTDALIGN 0
#endif

//  This was technically removed in C++20, but the file may still be there for
//  backwards compatibility.
#if !defined(__has_include) || __has_include(<cstdbool>)
  #define LBAL_HAS_HEADER_CSTDBOOL 1
#else
  #define LBAL_HAS_HEADER_CSTDBOOL 0
#endif

#if !defined(__has_include) || __has_include(<cstdint>)
  #define LBAL_HAS_HEADER_CSTDINT 1
#else
  #define LBAL_HAS_HEADER_CSTDINT 0
#endif

#if !defined(__has_include) || __has_include(<cuchar>)
  #define LBAL_HAS_HEADER_CUCHAR 1
#else
  #define LBAL_HAS_HEADER_CUCHAR 0
#endif

#if !defined(__has_include) || __has_include(<forward_list>)
  #define LBAL_HAS_HEADER_FORWARD_LIST 1
#else
  #define LBAL_HAS_HEADER_FORWARD_LIST 0
#endif

#if !defined(__has_include) || __has_include(<future>)
  #define LBAL_HAS_HEADER_FUTURE 1
#else
  #define LBAL_HAS_HEADER_FUTURE 0
#endif

#if !defined(__has_include) || __has_include(<initializer_list>)
  #define LBAL_HAS_HEADER_INITIALIZER_LIST 1
#else
  #define LBAL_HAS_HEADER_INITIALIZER_LIST 0
#endif

#if !defined(__has_include) || __has_include(<mutex>)
  #define LBAL_HAS_HEADER_MUTEX 1
#else
  #define LBAL_HAS_HEADER_MUTEX 0
#endif

#if !defined(__has_include) || __has_include(<random>)
  #define LBAL_HAS_HEADER_RANDOM 1
#else
  #define LBAL_HAS_HEADER_RANDOM 0
#endif

#if !defined(__has_include) || __has_include(<ratio>)
  #define LBAL_HAS_HEADER_RATIO 1
#else
  #define LBAL_HAS_HEADER_RATIO 0
#endif

#if !defined(__has_include) || __has_include(<regex>)
  #define LBAL_HAS_HEADER_REGEX 1
#else
  #define LBAL_HAS_HEADER_REGEX 0
#endif

#if !defined(__has_include) || __has_include(<scoped_allocator>)
  #define LBAL_HAS_HEADER_SCOPED_ALLOCATOR 1
#else
  #define LBAL_HAS_HEADER_SCOPED_ALLOCATOR 0
#endif

#if !defined(__has_include) || __has_include(<system_error>)
  #define LBAL_HAS_HEADER_SYSTEM_ERROR 1
#else
  #define LBAL_HAS_HEADER_SYSTEM_ERROR 0
#endif

#if !defined(__has_include) || __has_include(<thread>)
  #define LBAL_HAS_HEADER_THREAD 1
#else
  #define LBAL_HAS_HEADER_THREAD 0
#endif

#if !defined(__has_include) || __has_include(<tuple>)
  #define LBAL_HAS_HEADER_TUPLE 1
#else
  #define LBAL_HAS_HEADER_TUPLE 0
#endif

#if !defined(__has_include) || __has_include(<type_traits>)
  #define LBAL_HAS_HEADER_TYPE_TRAITS 1
#else
  #define LBAL_HAS_HEADER_TYPE_TRAITS 0
#endif

#if !defined(__has_include) || __has_include(<typeindex>)
  #define LBAL_HAS_HEADER_TYPEINDEX 1
#else
  #define LBAL_HAS_HEADER_TYPEINDEX 0
#endif

#if !defined(__has_include) || __has_include(<unordered_map>)
  #define LBAL_HAS_HEADER_UNORDERED_MAP 1
#else
  #define LBAL_HAS_HEADER_UNORDERED_MAP 0
#endif

#if !defined(__has_include) || __has_include(<unordered_set>)
  #define LBAL_HAS_HEADER_UNORDERED_SET 1
#else
  #define LBAL_HAS_HEADER_UNORDERED_SET 0
#endif
