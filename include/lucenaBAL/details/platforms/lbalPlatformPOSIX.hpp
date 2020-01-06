/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalPlatformPOSIX.hpp”
	Copyright © 2019-2020 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/


#pragma once


//	lbal
#include <lucenaBAL/details/lbalConfig.hpp>


/*------------------------------------------------------------------------------
	POSIX Platforms
*/

//	This duplicates the test peformed to include this file in the first place.
#if LBAL_TARGET_OS_X11
	#ifndef LBAL_TARGET_API_POSIX
		#define LBAL_TARGET_API_POSIX 1
	#endif

	#ifndef LBAL_TARGET_API_X11
		#define LBAL_TARGET_API_X11 1
	#endif

	#if defined (__linux__)
		#define LBAL_NAME_TARGET_OS u8"Linux"
	#elif defined (__FreeBSD__)
		#define LBAL_NAME_TARGET_OS u8"FreeBSD version " LBAL_Stringify_ (__FreeBSD__)
	#elif defined (__NetBSD__)
		#define LBAL_NAME_TARGET_OS u8"NetBSD version " LBAL_Stringify_ (__NetBSD__)
	#elif defined (__OpenBSD__)
		#define LBAL_NAME_TARGET_OS u8"OpenBSD version " LBAL_Stringify_ (__OpenBSD__)
	#elif defined (__DragonFly__)
		#define LBAL_NAME_TARGET_OS u8"DragonFly version " LBAL_Stringify_ (__DragonFly__)
	#else
		#error "Unknown LBAL_TARGET_OS_X11 variant; update details/lbalPlatformSetup.hpp"
	#endif
#else
	#error "lbalPlatformPOSIX.hpp was directly included by a non-POSIX platform"
#endif
