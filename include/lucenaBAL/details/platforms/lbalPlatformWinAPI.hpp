/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalPlatformWinAPI.hpp”
  Copyright © 2019-2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/

#pragma once

//	lbal
#include <lucenaBAL/lbalConfig.hpp>

/*------------------------------------------------------------------------------
  WinAPI Platforms
*/

//	This duplicates the test performed to include this file in the first place.
#if LBAL_TARGET_OS_WINAPI
  //	We make no assumptions about the addressing model based on processor,
  //	instead relying on intrinsics.
  #if defined(_WIN64)
    #define LBAL_TARGET_RT_64_BIT 1

    #ifndef LBAL_TARGET_API_WIN64
      #define LBAL_TARGET_API_WIN64 1
    #endif

    #define LBAL_TYPE_DOUBLE_GT_FLOAT 1
    #define LBAL_TYPE_LONG_DOUBLE_GT_DOUBLE 1
  #elif defined(_WIN32)
    #define LBAL_TARGET_RT_32_BIT 1

    #ifndef LBAL_TARGET_API_WIN32
      #define LBAL_TARGET_API_WIN32 1
    #endif

    //	unverified
    #define LBAL_TYPE_DOUBLE_GT_FLOAT 1
    #define LBAL_TYPE_LONG_DOUBLE_GT_DOUBLE 1
  #else
    #error "Unsupported addressing model"
  #endif

  #define LBAL_FEATURE_UTF16_FILE_SYSTEM 1

//	SEEME - bitweeder
//	We deliberately leave `WIN32_LEAN_AND_MEAN`, `NOMINMAX` and similar
//	`<windows.h>` configuration macros to the client (removed in 3.0).
//	lucenaBAL never includes `<windows.h>`, so they only ever affected
//	client code, and only when `<windows.h>` happened to be included after
//	lucenaBAL; the same program could then see different `<windows.h>`
//	contents in different translation units. Clients that want them should
//	set them in their build flags so every translation unit agrees.

  #define LBAL_NAME_TARGET_OS u8"Windows"
#else
  #error "lbalPlatformWinAPI.hpp was directly included by a non-WinAPI platform"
#endif
