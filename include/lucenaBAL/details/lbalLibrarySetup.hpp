/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“LibrarySetup.hpp”
	Copyright © 2018-2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See lbalFeatureSetup.hpp for descriptions of the various macros and flags.

------------------------------------------------------------------------------*/


#pragma once


//	std
#if defined (_MSC_VER) && defined (_WIN32)
	/*
		We guard inclusion of system headers when using MSVS due to its
		noisiness at high warning levels.
	*/
	#pragma warning (push, 0)
#endif

#if __has_include (<version>)
	/*
		Once this header is universally available, it will take the place
		of <ciso646> abuse, providing the same functionality as well as
		(eventually) acting as a clearinghouse for SD-6 macros related to
		library features.

		__SEEME__ This must not be lbalVersion.hpp, as that header depends on
		this one.
	*/
	#include <version>
#else
	/*
		In C++, this is a do-nothing header we include just for the side
		effects: the Standard Library implementation will be configured
		and many assorted compiler-dependent feature detection macros will
		be defined.
	*/
	#include <ciso646>
#endif

#if defined (_MSC_VER) && defined (_WIN32)
	#pragma warning (pop)
#endif


//	lbal
#include <lucenaBAL/lbalConfig.hpp>


/*------------------------------------------------------------------------------
	Definition Tests

	Macros that we set are our responsiblity; they should not be set outside of
	this header. Since none of the LBAL_XXX macros we’re responsible for are
	set until after the library tests, it’s sufficient to simply test them for
	existence to see if they’ve been improperly defined, with the following
	exceptions:

	-	LBAL_LIBCPPxx_xxx macros are only set here if it would not be
		possible otherwise to set them properly in lbalVersion.hpp (a small
		subset are potentially defined in lbalPlatformSetup.hpp, but that’s
		very uncommon). See the notes in the documentation for the affected
		macros and in lbalVersion.hpp.
*/

#if defined (LBAL_NAME_STANDARD_LIBRARY)
	#error "Don’t define LBAL_NAME_STANDARD_LIBRARY outside of this file."
#endif	//	LBAL_NAME_STANDARD_LIBRARY

#if defined (LBAL_TARGET_STANDARD_LIBRARY_LIBCPP) \
	|| defined (LBAL_TARGET_STANDARD_LIBRARY_MSVC) \
	|| defined (LBAL_TARGET_STANDARD_LIBRARY_LIBSTDCPP) \
	|| defined (LBAL_TARGET_STANDARD_LIBRARY_STDLIBCPP)

	#error "Don’t define LBAL_TARGET_STANDARD_LIBRARY_xxx outside of this file."
#endif	//	LBAL_TARGET_STANDARD_LIBRARY check


/*------------------------------------------------------------------------------
	Library Macros

	__SEEME__ Arguably, it would be more desirable to give each Standard Library
	implementation its own #include file and include them here conditionally
	rather than go the monolithic route. We trade off potential unnecessary
	recompilation of unaffected projects for simplified maintenance at this
	time.
*/

#if defined (_LIBCPP_VERSION)
	#if defined (__apple_build_version__)
		/*
			__SEEME__ We use this as a proxy for detecting Apple’s hacked-up
			version of libc++; there doesn’t appear to be a reliable way to
			actually determine this.

			__SEEME__ Speculating about future availability in Apple’s libc++ is
			fraught, as features fail to be adopted from vanilla clang for any
			number of reasons (e.g., std::any, std::filesystem), and oddities
			persist for years (e.g., std::is_callable vs std::is_invocable). We
			assume nothing, and wait.
		*/
		#if (_LIBCPP_VERSION >= 6000)
//			#if !__cpp_lib_launder
//				#define LBAL_LIBCPP17_LAUNDER 201606L
//			#endif
//
//			#define LBAL_LIBCPP2A_STD_REMOVE_CVREF 1L
//			#define LBAL_LIBCPP2A_STRING_PREFIX_AND_SUFFIX_CHECKING 1L
//			#define LBAL_LIBCPP2A_UTILITY_TO_CONVERT_A_POINTER_TO_A_RAW_POINTER 1L
		#endif

		#if (_LIBCPP_VERSION >= 7000)
//			#define LBAL_LIBCPP2A_STD_ENDIAN 1L
		#endif
	#else
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
//			#define LBAL_LIBCPP2A_CONSTEXPR_FOR_ALGORITHM_AND_UTILITY 1L
//			#define LBAL_LIBCPP2A_MORE_CONSTEXPR_FOR_COMPLEX 1L

			//	__SEEME__ This appears to be in, though we await confirmation.
			#define LBAL_LIBCPP2A_CALENDAR_AND_TIMEZONE 1L
		#endif

		#if (_LIBCPP_VERSION >= 8000)
			#define LBAL_LIBCPP2A_TYPE_IDENTITY 1L
		#endif
	#endif


	//	Set up identifiers
	#define LBAL_NAME_STANDARD_LIBRARY u8"libc++ version " LBAL_Stringify_ (_LIBCPP_VERSION)
	#define LBAL_TARGET_STANDARD_LIBRARY_LIBCPP 1
#elif defined (__GLIBCXX__)
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
#elif defined (_MSC_VER)
	//	__SEEME__ Not exactly an equivalent test, but I don’t know of a documented
	//	way to reliably identify the MSVC Standard Library.

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
	#define LBAL_NAME_STANDARD_LIBRARY u8"MSVC Standard Library version" LBAL_Stringify_ (_MSC_VER)
	#define LBAL_TARGET_STANDARD_LIBRARY_MSVC 1
#else
	#define LBAL_NAME_STANDARD_LIBRARY u8"Unknown Standard Library implementation"
#endif
