/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalPlatformSetup.hpp”
	Copyright © 2018-2020 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/


#pragma once


//	lbal
#include <lucenaBAL/lbalConfig.hpp>


/*------------------------------------------------------------------------------
	Platform Macros
*/

#if LBAL_TARGET_OS_MACOS || LBAL_TARGET_OS_IOS || LBAL_TARGET_OS_IOS_SIM
	#include <lucenaBAL/details/platforms/lbalPlatformApple.hpp>
#elif LBAL_TARGET_OS_X11
	#include <lucenaBAL/details/platforms/lbalPlatformPOSIX.hpp>
#elif LBAL_TARGET_OS_WINAPI
	#include <lucenaBAL/details/platforms/lbalPlatformWinAPI.hpp>
#else
	#error "Unknown platform; update lbalPlatformSetup.hpp or specify a recognized platform token"
#endif
