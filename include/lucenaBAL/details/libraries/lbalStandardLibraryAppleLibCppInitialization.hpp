/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalStandardLibraryAppleLibCppInitialization.hpp”
	Copyright © 2020 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/


#pragma once


//	lbal
#include <lucenaBAL/details/lbalConfig.hpp>
#include <lucenaBAL/details/lbalDetectStandardLibrary.hpp>
#include <lucenaBAL/details/lbalVersionSetup.hpp>


/*------------------------------------------------------------------------------
	Apple libc++ Standard Library

	Speculating about feature availability in Apple’s libc++ is fraught, as
	features fail to be adopted from vanilla clang for any number of reasons
	(e.g., `std::any`, `std::filesystem`), and oddities persist for years
	(e.g., `std::is_callable` vs `std::is_invocable`). We assume nothing.
*/

#if LBAL_TARGET_STANDARD_LIBRARY_APPLE_LIBCPP
	#if !LBAL_LIBCPP2A_VERSION
		/*
			If we get here, then we were not initially able to determine
			whether to set `LBAL_LIBCPP2A_VERSION`. We know that Apple’s
			libc++ 7 or later always has an implementation of `<version>`, so
			we include it. Note that _LIBCPP_VERSION will have been initialized
			correctly by the earlier inclusion of `lbalVersionSetup.hpp`.

			__SEEME__ Apple LLVM inherited a token `<version>` from libc++ 7;
			the first meaningful iteration appeared in libc++ 8, which ships—
			somewhat intact—with Xcode 11. That iteration was out of sync with
			the SD-6 doc, however, and has gotten even more out-of-sync. One of
			the upshots is that we can’t fully trust the `<version>` bundled
			with any shipping Xcode.
		*/
		#if (_LIBCPP_VERSION >= 7000)
			#define LBAL_LIBCPP2A_VERSION 1L

			#include <version>
		#else
			#define LBAL_LIBCPP2A_VERSION 0L
		#endif
	#endif
#else
	#error "lbalStandardLibraryAppleLibCppInitialization.hpp was directly included with the incorrect Standard Library implementation"
#endif	//	LBAL_TARGET_STANDARD_LIBRARY_APPLE_LIBCPP
