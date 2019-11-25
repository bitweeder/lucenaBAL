/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“PlatformWinAPI.hpp”
	Copyright © 2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/


#pragma once


//	std
//	__SEEME__ We always guard inclusion of system headers when using MSVS due
//	its noisiness at high warning levels.
#if defined (_MSC_VER) && defined (_WIN32)
	#pragma warning (push, 0)
#endif

#include <ciso646>
	//	In C++, this is a do-nothing header we include just for the side
	//	effects: the Standard Library implementation will be configured
	//	and many assorted compiler-dependent feature detection macros will
	//	be defined.

#if defined (_MSC_VER) && defined (_WIN32)
	#pragma warning (pop)
#endif


//	lbal
#include <lucenaBAL/details/lbalConfig.hpp>


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
