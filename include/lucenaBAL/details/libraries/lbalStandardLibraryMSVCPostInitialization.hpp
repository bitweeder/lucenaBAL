/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalStandardLibraryMSVCPostInitialization.hpp”
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
	MSVC Standard Library
*/

#if LBAL_TARGET_STANDARD_LIBRARY_MSVC
	#if (_MSC_VER >= 1911) && (LBAL_cpp_version > LBAL_CPP14_VERSION)
		#if !defined(LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE)
			#define LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE 201703L
		#endif
	#endif

	#if (_MSC_VER >= 1912) && (LBAL_cpp_version > LBAL_CPP14_VERSION)
		#if !defined(LBAL_LIBCPP17_NODE_EXTRACT)
			#define LBAL_LIBCPP17_NODE_EXTRACT 201606L
		#endif
	#endif

	#if (_MSC_VER >= 1914) && (LBAL_cpp_version > LBAL_CPP14_VERSION)
		#if !defined(LBAL_LIBCPP17_LAUNDER)
			#define LBAL_LIBCPP17_LAUNDER 201606L
		#endif

		#if !defined(LBAL_LIBCPP17_PARALLEL_ALGORITHM)
			#define LBAL_LIBCPP17_PARALLEL_ALGORITHM 201603L
		#endif
	#endif

	#if !defined(LBAL_LIBCPP17_TO_CHARS) \
			&& LBAL_LIBCPP17_TO_CHARS_INTEGER \
			&& LBAL_LIBCPP17_TO_CHARS_FP
		#define LBAL_LIBCPP17_TO_CHARS LBAL_LIBCPP17_TO_CHARS_FP
	#endif
#else
	#error "lbalStandardLibraryMSVCPostInitialization.hpp was directly included with the incorrect Standard Library implementation"
#endif
