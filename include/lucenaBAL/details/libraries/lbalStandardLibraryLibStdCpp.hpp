/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“StandardLibraryLibStdCpp.hpp”
	Copyright © 2019 Lucena
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
	libstdc++ Standard Library

	__SEEME__ One source of aggravation in libstdc++ is that there is no simple
	way to figure out what version of the library you are using. `__GLIBCXX__`
	is a release date, which can be interleaved across versions of the library
	depending on whether there are minor releases and bug fixes. We are forced
	to use `__GNUC__` as a proxy, which is not totally unreasonable, as long as
	the user hasn’t done something pathological like using an old libstdc++
	implementation with a new compiler.
*/

//	This duplicates the test peformed to include this file in the first place.
#if defined (__GLIBCXX__)
	//	__SEEME__ Note that older iterations of libstdc++ used __GLIBCPP__

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

	#if (__GNUC__ >= 7) && (LBAL_cpp_version > LBAL_CPP14_VERSION)
		#if __cpp_lib_launder
			#define LBAL_LIBCPP17_LAUNDER __cpp_lib_launder
		#else
			#define LBAL_LIBCPP17_LAUNDER 201606L
		#endif

		#if __cpp_lib_node_extract
			#define LBAL_LIBCPP17_SPLICING_MAPS_AND_SETS __cpp_lib_node_extract
		#else
			#define LBAL_LIBCPP17_SPLICING_MAPS_AND_SETS 201606L
		#endif
	#endif

	#if (__GNUC__ >= 8) && (LBAL_cpp_version > LBAL_CPP14_VERSION)
		//	__SEEME__ Only ints are supported; floats are forthcoming.
		#if __cpp_lib_to_chars
			#define LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS_INTEGER __cpp_lib_to_chars
		#endif

		#define LBAL_LIBCPP2A_STD_ENDIAN 1L
		#define LBAL_LIBCPP2A_UTILITY_TO_CONVERT_A_POINTER_TO_A_RAW_POINTER 1L
	#endif

	#if (__GNUC__ >= 9)
		#define LBAL_LIBCPP2A_STD_REMOVE_CVREF 1L
	#endif

	#if LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS_INTEGER && \
			LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS_FP
		#define LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS	 __cpp_lib_to_chars
	#endif


	//	Set up identifiers
	#define LBAL_NAME_STANDARD_LIBRARY \
		u8"GNU libstdc++ version " LBAL_Stringify_ (__GLIBCXX__)

	#define LBAL_TARGET_STANDARD_LIBRARY_LIBSTDCPP 1
#else
	#error "lbalStandardLibraryLibStdCpp.hpp was directly included with the incorrect Standard Library implementation"
#endif
