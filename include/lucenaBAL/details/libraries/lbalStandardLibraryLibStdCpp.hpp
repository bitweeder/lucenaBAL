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
	libstdc++ Standard Library
*/

//	This duplicates the test peformed to include this file in the first place.
#if defined (__GLIBCXX__)
	//	__SEEME__ Note that older iterations of libstdc++ used __GLIBCPP__

	#if (__GNUC__ >= 7)
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

	#if (__GNUC__ >= 8)
		//	__SEEME__ Only ints are supported; floats are forthcoming.
//		#if __cpp_lib_to_chars
//			#define LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS __cpp_lib_to_chars
//		#else
//			#define LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS 201611L
//		#endif
		#define LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS	 0L

		#define LBAL_LIBCPP2A_STD_ENDIAN 1L
		#define LBAL_LIBCPP2A_UTILITY_TO_CONVERT_A_POINTER_TO_A_RAW_POINTER 1L
	#endif

	#if (__GNUC__ >= 9)
		#define LBAL_LIBCPP2A_STD_REMOVE_CVREF 1L
	#endif


	//	Set up identifiers
	#define LBAL_NAME_STANDARD_LIBRARY u8"GNU libstdc++ version " LBAL_Stringify_ (__GLIBCXX__)
	#define LBAL_TARGET_STANDARD_LIBRARY_LIBSTDCPP 1
#else
	#error "lbalStandardLibraryLibStdCpp.hpp was directly included with the incorrect Standard Library implementation"
#endif
