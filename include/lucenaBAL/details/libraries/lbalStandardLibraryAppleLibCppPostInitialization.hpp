/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalStandardLibraryAppleLibCppPostInitialization.hpp”
	Copyright © 2019-2020 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/


#pragma once


//	lbal
#include <lucenaBAL/details/lbalConfig.hpp>
#include <lucenaBAL/details/lbalDetectStandardLibrary.hpp>


/*------------------------------------------------------------------------------
	Apple libc++ Standard Library

	Speculating about feature availability in Apple’s libc++ is fraught, as
	features fail to be adopted from vanilla clang for any number of reasons
	(e.g., `std::any`, `std::filesystem`), and oddities persist for years
	(e.g., `std::is_callable` vs `std::is_invocable`). We assume nothing.
*/

#if LBAL_TARGET_STANDARD_LIBRARY_APPLE_LIBCPP
	//	Currently, we do nothing here.
#else
	#error "lbalStandardLibraryAppleLibCppPostInitialization.hpp was directly included with the incorrect Standard Library implementation"
#endif	//	LBAL_TARGET_STANDARD_LIBRARY_APPLE_LIBCPP
