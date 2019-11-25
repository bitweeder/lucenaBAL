/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“StandardLibraryLibCpp.hpp”
	Copyright © 2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/


#pragma once


//	std
//	__SEEME__ We always guard inclusion of system headers when using MSVS due
//	its noisiness at high warning levels.
#if defined (_MSC_VER) && defined (_WIN32)
	#pragma warning (push, 0)
#endif

#include <ciso646>
	//	In C++, this is a do-nothing header we include just for the side
	//	effects: the Standard Library implementation will be configured
	//	and many assorted compiler-dependent feature detection macros will
	//	be defined.

#if defined (_MSC_VER) && defined (_WIN32)
	#pragma warning (pop)
#endif


//	lbal
#include <lucenaBAL/lbalConfig.hpp>


/*------------------------------------------------------------------------------
	libc++ Standard Library
*/

//	This duplicates the test peformed to include this file in the first place.
#if defined (_LIBCPP_VERSION) && !defined (__apple_build_version__)
	#if (_LIBCPP_VERSION >= 6000)
		#if !__cpp_lib_launder
			#define LBAL_LIBCPP17_LAUNDER 201606L
		#endif

		#define LBAL_LIBCPP2A_STD_REMOVE_CVREF 1L
		#define LBAL_LIBCPP2A_STRING_PREFIX_AND_SUFFIX_CHECKING 1L
		#define LBAL_LIBCPP2A_UTILITY_TO_CONVERT_A_POINTER_TO_A_RAW_POINTER 1L
	#endif

	#if (_LIBCPP_VERSION >= 7000)
		#define LBAL_LIBCPP2A_STD_ENDIAN 1L

		//	__SEEME__ In-progress
//		#define LBAL_LIBCPP2A_CONSTEXPR_FOR_ALGORITHM_AND_UTILITY 1L
//		#define LBAL_LIBCPP2A_MORE_CONSTEXPR_FOR_COMPLEX 1L

		//	__SEEME__ This appears to be in, though we await confirmation.
		#define LBAL_LIBCPP2A_CALENDAR_AND_TIMEZONE 1L
	#endif

	#if (_LIBCPP_VERSION >= 8000)
		#define LBAL_LIBCPP2A_TYPE_IDENTITY 1L
	#endif


	//	Set up identifiers
	#define LBAL_NAME_STANDARD_LIBRARY u8"libc++ version " LBAL_Stringify_ (_LIBCPP_VERSION)
	#define LBAL_TARGET_STANDARD_LIBRARY_LIBCPP 1
#else
	#error "lbalStandardLibraryLibCpp.hpp was directly included with the incorrect Standard Library implementation"
#endif
