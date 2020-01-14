/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalStandardLibraryMSVCInitialization.hpp”
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
#include <lucenaBAL/details/lbalKnownVersions.hpp>
#include <lucenaBAL/details/lbalVersionSetup.hpp>


/*------------------------------------------------------------------------------
	MSVC Standard Library
*/

#if LBAL_TARGET_STANDARD_LIBRARY_MSVC
	/*
		The Standard Library bundled with MSVS 2019 16.2 or later always has an
		implementation of `<version>`. MSVC has had support for `__has_include`
		since MSVC 2017 15.3. Pragmatically speaking, we’ll be able to detect
		the presence of `<version>` directly if it’s there to detect.
	*/

	#if (_MSC_VER >= 1914)
		//	__SEEME__ Only ints are supported until `1924`
		#if !defined(LBAL_LIBCPP17_TO_CHARS_INTEGER)
			#if __has_include (<charconv>)
				#if __cpp_lib_to_chars
					#define LBAL_LIBCPP17_TO_CHARS_INTEGER __cpp_lib_to_chars
				#elif (LBAL_cpp_version > LBAL_CPP14_VERSION)
					#define LBAL_LIBCPP17_TO_CHARS_INTEGER 201611L
				#else
					#define LBAL_LIBCPP17_TO_CHARS_INTEGER 0
				#endif
			#else
				#define LBAL_LIBCPP17_TO_CHARS_INTEGER 0
			#endif
		#endif
	#endif

	#if (_MSC_VER >= 1924)
		#if !defined(LBAL_LIBCPP17_TO_CHARS_FP)
			#if __has_include (<charconv>)
				#if __cpp_lib_to_chars
					#define LBAL_LIBCPP17_TO_CHARS_FP __cpp_lib_to_chars
				#elif (LBAL_cpp_version > LBAL_CPP14_VERSION)
					#define LBAL_LIBCPP17_TO_CHARS_FP 201611L
				#else
					#define LBAL_LIBCPP17_TO_CHARS_FP 0
				#endif
			#else
				#define LBAL_LIBCPP17_TO_CHARS_FP 0
			#endif
		#endif
	#endif
#else
	#error "lbalStandardLibraryMSVCInitialization.hpp was directly included with the incorrect Standard Library implementation"
#endif
