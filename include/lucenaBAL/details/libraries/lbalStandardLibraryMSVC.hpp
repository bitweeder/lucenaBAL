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
#include <lucenaBAL/details/lbalConfig.hpp>


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
