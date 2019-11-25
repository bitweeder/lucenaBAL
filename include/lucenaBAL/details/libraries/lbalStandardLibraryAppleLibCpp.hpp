/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“StandardLibraryAppleLibCpp.hpp”
	Copyright © 2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/


#pragma once


//	std
#include <ciso646>
	//	In C++, this is a do-nothing header we include just for the side
	//	effects: the Standard Library implementation will be configured
	//	and many assorted compiler-dependent feature detection macros will
	//	be defined.


//	lbal
#include <lucenaBAL/lbalConfig.hpp>


/*------------------------------------------------------------------------------
	Apple libc++ Standard Library
*/

//	This duplicates the test performed to include this file in the first place.
#if defined (_LIBCPP_VERSION) && defined (__apple_build_version__)
	/*
		__SEEME__ We use `__apple_build_version__` as a proxy for detecting
		Apple’s hacked-up version of libc++; there doesn’t appear to be a
		reliable way to actually determine this.

		__SEEME__ Speculating about future availability in Apple’s libc++
		is fraught, as features fail to be adopted from vanilla clang for
		any number of reasons (e.g., `std::any`, `std::filesystem`), and
		oddities persist for years (e.g., `std::is_callable` vs
		`std::is_invocable`). We assume nothing, and wait.
	*/
	#if (_LIBCPP_VERSION >= 6000)
//		#if !__cpp_lib_launder
//			#define LBAL_LIBCPP17_LAUNDER 201606L
//		#endif
//
//		#define LBAL_LIBCPP2A_STD_REMOVE_CVREF 1L
//		#define LBAL_LIBCPP2A_STRING_PREFIX_AND_SUFFIX_CHECKING 1L
//		#define LBAL_LIBCPP2A_UTILITY_TO_CONVERT_A_POINTER_TO_A_RAW_POINTER 1L
	#endif

	#if (_LIBCPP_VERSION >= 7000)
//		#define LBAL_LIBCPP2A_STD_ENDIAN 1L
	#endif

	//	Set up identifiers
	#define LBAL_NAME_STANDARD_LIBRARY u8"Apple libc++ version " LBAL_Stringify_ (_LIBCPP_VERSION)
	#define LBAL_TARGET_STANDARD_LIBRARY_APPLE_LIBCPP 1
#else
	#error "lbalStandardLibraryAppleLibCpp.hpp was directly included with the incorrect Standard Library implementation"
#endif
