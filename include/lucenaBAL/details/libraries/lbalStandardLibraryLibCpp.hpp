/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalStandardLibraryLibCpp.hpp”
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
	libc++ Standard Library
*/

//	This duplicates the test peformed to include this file in the first place.
#if defined (_LIBCPP_VERSION) && !defined (__apple_build_version__)
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

	#if (_LIBCPP_VERSION >= 6000)
		#if !defined(__cpp_lib_launder)
			#define LBAL_LIBCPP17_LAUNDER 201606L
		#endif

		#if !defined(__cpp_lib_remove_cvref)
			#define LBAL_LIBCPP2A_REMOVE_CVREF 201711
		#endif

		#if !defined(__cpp_lib_starts_ends_with)
			#define LBAL_LIBCPP2A_STARTS_ENDS_WITH 201711L
		#endif

		#if !defined(__cpp_lib_to_address)
			#define LBAL_LIBCPP2A_TO_ADDRESS 201711L
		#endif
	#endif

	#if (_LIBCPP_VERSION >= 7000)
		#if !defined(__cpp_lib_endian)
			#define LBAL_LIBCPP2A_STD_ENDIAN 201907L
		#endif

		#if !defined(__cpp_lib_chrono)
			#define LBAL_LIBCPP2A_CHRONO_CALENDAR 201803L
		#endif
	#endif

	#if (_LIBCPP_VERSION >= 8000)
		#if !defined(__cpp_lib_type_identity)
			#define LBAL_LIBCPP2A_TYPE_IDENTITY 201806L
		#endif
	#endif


	//	Set up identifiers
	#define LBAL_NAME_STANDARD_LIBRARY \
		u8"libc++ version " LBAL_Stringify_ (_LIBCPP_VERSION)

	#define LBAL_TARGET_STANDARD_LIBRARY_LIBCPP 1
#else
	#error "lbalStandardLibraryLibCpp.hpp was directly included with the incorrect Standard Library implementation"
#endif
