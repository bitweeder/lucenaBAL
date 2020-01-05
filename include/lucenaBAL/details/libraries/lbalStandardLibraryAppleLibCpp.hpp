/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalStandardLibraryAppleLibCpp.hpp”
	Copyright © 2019-2020 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/


#pragma once


//	lbal
#include <lucenaBAL/details/lbalConfig.hpp>
#include <lucenaBAL/details/lbalVersionSetup.hpp>


/*------------------------------------------------------------------------------
	Apple libc++ Standard Library
*/

/*
	This duplicates the test performed to include this file in the first place.

	__SEEME__ We use `__apple_build_version__` as a proxy for detecting Apple’s
	hacked-up version of libc++; there doesn’t appear to be a reliable way to
	actually determine this.

	__SEEME__ Thankfully, Apple doesn’t bastardize `_LIBCPP_VERSION` the same
	way it does with `__clang__` and friends. However, speculating about
	feature availability in Apple’s libc++ is fraught, as features fail to be
	adopted from vanilla clang for any number of reasons (e.g., `std::any`,
	`std::filesystem`), and oddities persist for years (e.g.,
	`std::is_callable` vs `std::is_invocable`). We assume nothing,.
*/

#if defined (_LIBCPP_VERSION) && defined (__apple_build_version__)
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

	#if (_LIBCPP_VERSION >= 6000)
//		#if !__cpp_lib_launder
//			#define LBAL_LIBCPP17_LAUNDER 201606L
//		#endif
//
//		#define LBAL_LIBCPP2A_REMOVE_CVREF 1L
//		#define LBAL_LIBCPP2A_STARTS_ENDS_WITH 1L
//		#define LBAL_LIBCPP2A_TO_ADDRESS 1L
	#endif

	#if (_LIBCPP_VERSION >= 7000)
//		#define LBAL_LIBCPP2A_STD_ENDIAN 1L
	#endif

	//	Set up identifiers
	#define LBAL_NAME_STANDARD_LIBRARY \
		u8"Apple libc++ version " LBAL_Stringify_ (_LIBCPP_VERSION)

	#define LBAL_TARGET_STANDARD_LIBRARY_APPLE_LIBCPP 1
#else
	#error "lbalStandardLibraryAppleLibCpp.hpp was directly included with the incorrect Standard Library implementation"
#endif
