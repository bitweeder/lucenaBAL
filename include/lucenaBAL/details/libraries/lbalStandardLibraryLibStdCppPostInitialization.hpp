/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalStandardLibraryLibStdCppPostInitialization.hpp”
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
	#if (__GNUC__ >= 7) && (LBAL_cpp_version > LBAL_CPP14_VERSION)
		#if !defined(LBAL_LIBCPP17_LAUNDER)
			#define LBAL_LIBCPP17_LAUNDER 201606L
		#endif

		#if !defined(LBAL_LIBCPP17_NODE_EXTRACT)
			#define LBAL_LIBCPP17_NODE_EXTRACT 201606L
		#endif
	#endif

	#if (__GNUC__ >= 8) && (LBAL_cpp_version > LBAL_CPP17_VERSION)
		#if !defined(LBAL_LIBCPP2A_STD_ENDIAN)
			#define LBAL_LIBCPP2A_STD_ENDIAN 201907L
		#endif

		#if !defined(LBAL_LIBCPP2A_TO_ADDRESS)
			#define LBAL_LIBCPP2A_TO_ADDRESS 201711L
		#endif
	#endif

	#if (__GNUC__ >= 9) && (LBAL_cpp_version > LBAL_CPP17_VERSION)
		#if !defined(LBAL_LIBCPP2A_REMOVE_CVREF)
			#define LBAL_LIBCPP2A_REMOVE_CVREF 201711
		#endif
	#endif

	#if !defined(LBAL_LIBCPP17_TO_CHARS) \
			&& LBAL_LIBCPP17_TO_CHARS_INTEGER \
			&& LBAL_LIBCPP17_TO_CHARS_FP
		#define LBAL_LIBCPP17_TO_CHARS LBAL_LIBCPP17_TO_CHARS_FP
	#endif
#else
	#error "lbalStandardLibraryLibStdCppPostInitialization.hpp was directly included with the incorrect Standard Library implementation"
#endif
