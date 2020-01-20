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
#include <lucenaBAL/details/lbalKnownVersions.hpp>
#include <lucenaBAL/details/lbalVersionSetup.hpp>


/*------------------------------------------------------------------------------
	Apple libc++ Standard Library

	Speculating about feature availability in Apple’s libc++ is fraught, as
	features fail to be adopted from vanilla clang for any number of reasons
	(e.g., `std::any`, `std::filesystem`), and oddities persist for years
	(e.g., `std::is_callable` vs `std::is_invocable`). We assume nothing.
*/

#if LBAL_TARGET_STANDARD_LIBRARY_APPLE_LIBCPP
	/*
		Note that `<version>` is available if we’re using libc++ 7+, but this
		also means we have access to `__has_include` given the accompanying
		Xcode revision, so we can detect it generically rather than relying on
		a version check.

		__SEEME__ Apple LLVM inherited a token `<version>` from libc++ 7;
		the first meaningful iteration appeared in libc++ 8, which ships—
		somewhat intact—with Xcode 11. That iteration was out of sync with
		the SD-6 doc, however, and has gotten even more out-of-sync. One of
		the upshots is that we can’t fully trust the `<version>` bundled
		with any shipping Xcode, e.g., some of the token names have drifted
		from the official ones, and some of the token values have changed (and
		not just been updated).
	*/

	//	__SEEME__ The clangs all have this set incorrectly in `<version>`, so
	//	we preemptively disable it. Eventually, this will need a version guard.
	#if !defined (LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE)
		#define LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE 0
	#endif	//	LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE
#else
	#error "lbalStandardLibraryAppleLibCppInitialization.hpp was directly included with the incorrect Standard Library implementation"
#endif	//	LBAL_TARGET_STANDARD_LIBRARY_APPLE_LIBCPP
