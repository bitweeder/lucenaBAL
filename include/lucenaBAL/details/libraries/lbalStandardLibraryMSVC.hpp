/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“StandardLibraryMSVC.hpp”
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
	MSVC Standard Library
*/

//	This duplicates the test peformed to include this file in the first place.
#if defined (_MSC_VER)
	/*
		__SEEME__ Not exactly an equivalent test, but I don’t know of a way to
		reliably identify the MSVC Standard Library: we simply check to see if
		we’re running MSVC and and whether no other Standard Library detection
		test has passed.
	*/

	#if !LBAL_LIBCPP2A_VERSION
		/*
			If we get here, then we were not initially able to determine
			whether to set `LBAL_LIBCPP2A_VERSION`. We know that the Standard
			Library bundled with MSVS 2019 16.2 or later always has an
			implementation of `<version>`, so we include it. Practically
			speaking, though, this step should never happen since we should
			have been able to detect its availability using other means at an
			earlier stage.
		*/
		#if (_MSC_VER >= 1922)
			#define LBAL_LIBCPP2A_VERSION 1L

			#include <version>
		#else
			#define LBAL_LIBCPP2A_VERSION 0L
		#endif
	#endif

	#if (_MSC_VER >= 1911)
		#if __cpp_lib_thread_hardware_interference_size
			#define LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE __cpp_lib_thread_hardware_interference_size
		#else
			#define LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE 201703L
		#endif
	#endif

	#if (_MSC_VER >= 1912)
		#if __cpp_lib_node_extract
			#define LBAL_LIBCPP17_SPLICING_MAPS_AND_SETS __cpp_lib_node_extract
		#else
			#define LBAL_LIBCPP17_SPLICING_MAPS_AND_SETS 201606L
		#endif
	#endif

	#if (_MSC_VER >= 1914)
		#if __cpp_lib_launder
			#define LBAL_LIBCPP17_LAUNDER __cpp_lib_launder
		#else
			#define LBAL_LIBCPP17_LAUNDER 201606L
		#endif

		#if __cpp_lib_parallel_algorithm
			#define LBAL_LIBCPP17_PARALLEL_ALGORITHM __cpp_lib_parallel_algorithm
		#else
			#define LBAL_LIBCPP17_PARALLEL_ALGORITHM 201603L
		#endif

		//	__SEEME__ There is partial support for this, but only for ints; floats
		//	are being actively worked on.
//		#if __cpp_lib_to_chars
//			#define LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS __cpp_lib_to_chars
//		#else
//			#define LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS 201611L
//		#endif
		#define LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS 0L
	#endif

	//	Set up identifiers
	#define LBAL_NAME_STANDARD_LIBRARY u8"MSVC Standard Library version " LBAL_Stringify_ (_MSC_VER)
	#define LBAL_TARGET_STANDARD_LIBRARY_MSVC 1
#else
	#error "lbalStandardLibraryMSVC.hpp was directly included with the incorrect Standard Library implementation"
#endif
