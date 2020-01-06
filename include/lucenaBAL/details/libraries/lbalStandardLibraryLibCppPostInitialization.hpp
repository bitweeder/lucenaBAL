/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalStandardLibraryLibCppPostInitialization.hpp”
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
	libc++ Standard Library
*/

#if LBAL_TARGET_STANDARD_LIBRARY_LIBCPP
	#if (_LIBCPP_VERSION >= 6000)
		#if (LBAL_cpp_version > LBAL_CPP14_VERSION)
			#if !defined(LBAL_LIBCPP17_LAUNDER)
				#define LBAL_LIBCPP17_LAUNDER 201606L
			#endif
		#endif	//	LBAL_CPP17_VERSION

		#if (LBAL_cpp_version > LBAL_CPP17_VERSION)
			#if !defined(LBAL_LIBCPP2A_REMOVE_CVREF)
				#define LBAL_LIBCPP2A_REMOVE_CVREF 201711
			#endif

			#if !defined(LBAL_LIBCPP2A_STARTS_ENDS_WITH)
				#define LBAL_LIBCPP2A_STARTS_ENDS_WITH 201711L
			#endif

			#if !defined(LBAL_LIBCPP2A_TO_ADDRESS)
				#define LBAL_LIBCPP2A_TO_ADDRESS 201711L
			#endif
		#endif
	#endif	//	LBAL_CPP20_VERSION

	#if (_LIBCPP_VERSION >= 7000)
		#if (LBAL_cpp_version > LBAL_CPP17_VERSION)
			#if !defined(LBAL_LIBCPP2A_STD_ENDIAN)
				#define LBAL_LIBCPP2A_STD_ENDIAN 201907L
			#endif

			#if !defined(LBAL_LIBCPP2A_CHRONO_CALENDAR)
				#define LBAL_LIBCPP2A_CHRONO_CALENDAR 201803L
			#endif
		#endif	//	LBAL_CPP20_VERSION
	#endif

	#if (_LIBCPP_VERSION >= 8000)
		#if (LBAL_cpp_version > LBAL_CPP17_VERSION)
			#if !defined(LBAL_LIBCPP2A_TYPE_IDENTITY)
				#define LBAL_LIBCPP2A_TYPE_IDENTITY 201806L
			#endif
		#endif	//	LBAL_CPP20_VERSION
	#endif

	#if !defined(LBAL_LIBCPP17_TO_CHARS) \
			&& LBAL_LIBCPP17_TO_CHARS_INTEGER \
			&& LBAL_LIBCPP17_TO_CHARS_FP
		#define LBAL_LIBCPP17_TO_CHARS LBAL_LIBCPP17_TO_CHARS_FP
	#endif
#else
	#error "lbalStandardLibraryLibCppPostInitialization.hpp was directly included with the incorrect Standard Library implementation"
#endif
