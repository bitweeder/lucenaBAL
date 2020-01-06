/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalStandardLibraryLibCppInitialization.hpp”
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
	libc++ Standard Library
*/

#if LBAL_TARGET_STANDARD_LIBRARY_LIBCPP
	#if !LBAL_LIBCPP2A_VERSION
		/*
			If we get here, then we were not initially able to determine
			whether to set `LBAL_LIBCPP2A_VERSION`. We know that libc++ 7 or
			later always has an implementation of `<version>`, so we include
			it. Note that _LIBCPP_VERSION will have been initialized correctly
			by the earlier inclusion of `lbalVersionSetup.hpp`.

			__SEEME__ libc++ 7 only included a token `<version>`; the first
			meaningful iteration appeared in libc++ 8, but it was out of sync
			with the SD-6 doc at the time (e.g., `std::endian`).
		*/
		#if (_LIBCPP_VERSION >= 7000)
			#define LBAL_LIBCPP2A_VERSION 1L

			#include <version>
		#else
			#define LBAL_LIBCPP2A_VERSION 0L
		#endif
	#endif

	#if (_LIBCPP_VERSION >= 7000)
		//	__SEEME__ Only ints are supported; floats are forthcoming.
		//	libc++ might be a little too optimistic about its level of support.
		#if !defined(LBAL_LIBCPP17_TO_CHARS_INTEGER) \
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

	//	Explicitly disabled charconv support for floats to avoid it getting
	//	mistakenly set later.
	#if !defined(LBAL_LIBCPP17_TO_CHARS_FP)
		#define LBAL_LIBCPP17_TO_CHARS_FP 0
	#endif
#else
	#error "lbalStandardLibraryLibCppInitialization.hpp was directly included with the incorrect Standard Library implementation"
#endif
