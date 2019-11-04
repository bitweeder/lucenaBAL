/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“PlatformSetup.hpp”
	Copyright © 2018-2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See lbalFeatureSetup.hpp for descriptions of the various macros and flags.

------------------------------------------------------------------------------*/


#pragma once


//	std
#if defined (_MSC_VER) && defined (_WIN32)
	//	We guard inclusion of system headers when using MSVS due to its
	//	noisiness at high warning levels.
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
