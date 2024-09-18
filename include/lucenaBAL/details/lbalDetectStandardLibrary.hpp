/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalDetectStandardLibrary.hpp”
	Copyright © 2020-2024 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/


#pragma once


//	lbal
#include <lucenaBAL/lbalConfig.hpp>
#include <lucenaBAL/details/lbalCompilerSetup.hpp>


//	std
#include <ciso646>
	//	In C++, this is a do-nothing header we include just for the side
	//	effects: by convention, the Standard Library implementation will be
	//	configured. We need this for the library implementation detection
	//	below. Note that in an all-C++20 world, we would use <version> for
	//	this purpose.


/*------------------------------------------------------------------------------
	Detect the Standard Library being used and set up some basic identifiers.
*/

#if defined (_LIBCPP_VERSION)
	#if defined (__apple_build_version__)
		//	__SEEME__ We use `__apple_build_version__` as a proxy for detecting
		//	Apple’s hacked-up version of libc++; I’m unaware of more reliable
		//	way to determine this. Thankfully, Apple doesn’t bastardize
		//	`_LIBCPP_VERSION` the same way it does with `__clang__`, etc.

		#define LBAL_NAME_STANDARD_LIBRARY \
				u8"Apple libc++ version " LBAL_Stringify_ (_LIBCPP_VERSION)

		#define LBAL_TARGET_STANDARD_LIBRARY_APPLE_LIBCPP 1
	#else
		#define LBAL_NAME_STANDARD_LIBRARY \
				u8"libc++ version " LBAL_Stringify_ (_LIBCPP_VERSION)

		#define LBAL_TARGET_STANDARD_LIBRARY_LIBCPP 1
	#endif
#elif defined (__GLIBCXX__)
	//	__SEEME__ Note that older iterations of libstdc++ used __GLIBCPP__.
	#define LBAL_NAME_STANDARD_LIBRARY \
			u8"GNU libstdc++ version " LBAL_Stringify_ (__GLIBCXX__)

	#define LBAL_TARGET_STANDARD_LIBRARY_LIBSTDCPP 1
#elif defined (_MSC_VER)
	//	__SEEME__ Not exactly an equivalent test, but I don’t know of a way to
	//	reliably identify the MSVC Standard Library: we simply check to see if
	//	we’re running MSVC and and whether no other Standard Library detection
	//	test has passed. Necessarily, this test must be performed last among
	//	the Library detection tests.
	#define LBAL_NAME_STANDARD_LIBRARY u8"MSVC Standard Library version " \
			LBAL_Stringify_ (_MSC_VER)

	#define LBAL_TARGET_STANDARD_LIBRARY_MSVC 1
#else
	//	__APIME__ If we can’t determine the Standard Library implementation
	//	being used, we work under the happy assumption that we can rely
	//	exclusively on generic tests for feature detection; this is almost
	//	certainly doomed to failure.
	#define LBAL_NAME_STANDARD_LIBRARY u8"Unknown Standard Library implementation"

	#if LBAL_CONFIG_enable_pedantic_warnings
		LBAL_CPP_WARNING ("Unable to identify the Standard Library implementation is use; attempting to go fully generic")
	#endif	//	LBAL_CONFIG_enable_pedantic_warnings
#endif
