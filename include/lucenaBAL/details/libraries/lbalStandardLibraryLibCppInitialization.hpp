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
	/*
		Note that `<version>` is available if we’re using libc++ 7+, but we
		won’t necessarily have access to `__has_include` unless we’re using
		clang; in particular, MSVS didn’t support `__has_include` until 15.3.
		We consider this sufficiently fringe-y to not warrant a workaround.

		__SEEME__ While `<version>` appeared in libc++ 7; the first meaningful
		iteration didn’t appear until libc++ 8. That iteration was out of sync
		with the SD-6 doc, however, and has gotten even more out-of-sync. One
		upshot is that we can’t fully trust the `<version>` bundled with any
		libc++ until version 10, or so, e.g., some of the token names have
		drifted from the official ones, and some of the token values have
		changed (and not just been updated).
	*/

	//	__SEEME__ The clangs all have this set incorrectly in `<version>`, so
	//	we preemptively disable it. Eventually, this will need a version guard.
	#if !defined (LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE)
		#define LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE 0
	#endif	//	LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE

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
