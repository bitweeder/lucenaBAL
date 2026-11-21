/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalLibrarySetup-headers-cpp17.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if defined(__has_include) && __has_include(<any>)
  #define LBAL_HAS_HEADER_ANY 1
#else
  #define LBAL_HAS_HEADER_ANY 0
#endif

#if defined(__has_include) && __has_include(<charconv>)
  #define LBAL_HAS_HEADER_CHARCONV 1
#else
  #define LBAL_HAS_HEADER_CHARCONV 0
#endif

#if defined(__has_include) && __has_include(<execution>)
  #define LBAL_HAS_HEADER_EXECUTION 1
#else
  #define LBAL_HAS_HEADER_EXECUTION 0
#endif

//  This was technically removed in C++17, but the file may still be there for
//  backwards compatibility.
#if defined(__has_include) && __has_include(<experimental/filesystem>)
  #define LBAL_HAS_HEADER_EXPERIMENTAL_FILESYSTEM 1
#else
  #define LBAL_HAS_HEADER_EXPERIMENTAL_FILESYSTEM 0
#endif

#if defined(__has_include) && __has_include(<filesystem>)
  #define LBAL_HAS_HEADER_FILESYSTEM 1
#else
  #define LBAL_HAS_HEADER_FILESYSTEM 0
#endif

#if defined(__has_include) && __has_include(<memory_resource>)
  #define LBAL_HAS_HEADER_MEMORY_RESOURCE 1
#else
  #define LBAL_HAS_HEADER_MEMORY_RESOURCE 0
#endif

#if defined(__has_include) && __has_include(<optional>)
  #define LBAL_HAS_HEADER_OPTIONAL 1
#else
  #define LBAL_HAS_HEADER_OPTIONAL 0
#endif

#if defined(__has_include) && __has_include(<string_view>)
  #define LBAL_HAS_HEADER_STRING_VIEW 1
#else
  #define LBAL_HAS_HEADER_STRING_VIEW 0
#endif

#if defined(__has_include) && __has_include(<variant>)
  #define LBAL_HAS_HEADER_VARIANT 1
#else
  #define LBAL_HAS_HEADER_VARIANT 0
#endif
