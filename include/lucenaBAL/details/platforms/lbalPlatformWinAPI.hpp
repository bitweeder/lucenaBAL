/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalPlatformWinAPI.hpp”
	Copyright © 2019-2024 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/


#pragma once


//	lbal
#include <lucenaBAL/lbalConfig.hpp>


/*------------------------------------------------------------------------------
	WinAPI Platforms
*/

//	This duplicates the test peformed to include this file in the first place.
#if LBAL_TARGET_OS_WINAPI
	//	We make no assumptions about the addressing model based on processor,
	//	instead relying on intrinsics.
	#if defined (_WIN64)
		#define LBAL_TARGET_RT_64_BIT 1

		#ifndef LBAL_TARGET_API_WIN64
			#define LBAL_TARGET_API_WIN64 1
		#endif

		#define LBAL_TYPE_DOUBLE_GT_FLOAT 1
		#define LBAL_TYPE_LONG_DOUBLE_GT_DOUBLE 1
	#elif defined (_WIN32)
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


	//	WinAPI configuration; these are set up to avoid stomping on any
	//	prefix header-originated definitions that might be in use.
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
			//	__FIXME__ Maybe not super-smart to set this up globally
	#endif

	#ifndef NOMINMAX
		#define NOMINMAX
	#endif


	#define LBAL_NAME_TARGET_OS u8"Windows"
#else
	#error "lbalPlatformWinAPI.hpp was directly included by a non-WinAPI platform"
#endif
