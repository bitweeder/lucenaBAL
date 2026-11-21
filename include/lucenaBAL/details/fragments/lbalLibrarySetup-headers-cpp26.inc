/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalLibrarySetup-headers-cpp26.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if defined(__has_include) && __has_include(<contracts>)
  #define LBAL_HAS_HEADER_CONTRACTS 1
#else
  #define LBAL_HAS_HEADER_CONTRACTS 0
#endif

#if defined(__has_include) && __has_include(<debugging>)
  #define LBAL_HAS_HEADER_DEBUGGING 1
#else
  #define LBAL_HAS_HEADER_DEBUGGING 0
#endif

#if defined(__has_include) && __has_include(<hazard_pointer>)
  #define LBAL_HAS_HEADER_HAZARD_POINTER 1
#else
  #define LBAL_HAS_HEADER_HAZARD_POINTER 0
#endif

#if defined(__has_include) && __has_include(<hive>)
  #define LBAL_HAS_HEADER_HIVE 1
#else
  #define LBAL_HAS_HEADER_HIVE 0
#endif

#if defined(__has_include) && __has_include(<inplace_vector>)
  #define LBAL_HAS_HEADER_INPLACE_VECTOR 1
#else
  #define LBAL_HAS_HEADER_INPLACE_VECTOR 0
#endif

#if defined(__has_include) && __has_include(<linalg>)
  #define LBAL_HAS_HEADER_LINALG 1
#else
  #define LBAL_HAS_HEADER_LINALG 0
#endif

#if defined(__has_include) && __has_include(<rcu>)
  #define LBAL_HAS_HEADER_RCU 1
#else
  #define LBAL_HAS_HEADER_RCU 0
#endif

#if defined(__has_include) && __has_include(<simd>)
  #define LBAL_HAS_HEADER_SIMD 1
#else
  #define LBAL_HAS_HEADER_SIMD 0
#endif

#if defined(__has_include) && __has_include(<stdbit.h>)
  #define LBAL_HAS_HEADER_STDBIT_H 1
#else
  #define LBAL_HAS_HEADER_STDBIT_H 0
#endif

#if defined(__has_include) && __has_include(<stdckdint.h>)
  #define LBAL_HAS_HEADER_STDCKDINT_H 1
#else
  #define LBAL_HAS_HEADER_STDCKDINT_H 0
#endif

#if defined(__has_include) && __has_include(<text_encoding>)
  #define LBAL_HAS_HEADER_TEXT_ENCODING 1
#else
  #define LBAL_HAS_HEADER_TEXT_ENCODING 0
#endif
