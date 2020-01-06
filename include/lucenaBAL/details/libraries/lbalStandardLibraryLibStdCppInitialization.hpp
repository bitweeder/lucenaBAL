/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalStandardLibraryLibStdCppInitialization.hpp”
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
	libstdc++ Standard Library

	__SEEME__ One source of aggravation in libstdc++ is that there is no simple
	way to figure out what version of the library you are using. `__GLIBCXX__`
	is a release date, which can be interleaved across versions of the library
	depending on whether there are minor releases and bug fixes. We are forced
	to use `__GNUC__` as a proxy, which is not totally unreasonable, as long as
	the user hasn’t done something pathological like using an old libstdc++
	implementation with a new compiler.
*/

#if LBAL_TARGET_STANDARD_LIBRARY_LIBSTDCPP
	#if !LBAL_LIBCPP2A_VERSION
		/*
			If we get here, then we were not initially able to determine
			whether to set `LBAL_LIBCPP2A_VERSION`. We know that the Standard
			Library bundled with gcc 9 or later always has an implementation of
			`<version>`, so we include it. Practically speaking, though, this
			step should never happen since we should have been able to detect
			its availability using other means at an earlier stage.
		*/
		#if (__GNUC__ >= 9)
			#define LBAL_LIBCPP2A_VERSION 1L

			#include <version>
		#else
			#define LBAL_LIBCPP2A_VERSION 0L
		#endif
	#endif

	#if (__GNUC__ >= 8)
		//	__SEEME__ Only ints are supported; floats are forthcoming.
		//	libstdc++ might be a little too optimistic about its level of
		//	support.
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
	#error "lbalStandardLibraryLibStdCppInitialization.hpp was directly included with the incorrect Standard Library implementation"
#endif
