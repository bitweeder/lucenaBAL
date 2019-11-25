/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“LibrarySetup.hpp”
	Copyright © 2018-2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/


#pragma once


/*------------------------------------------------------------------------------
	Header Inclusion

	Load in any dependencies we’ll need to perform our library tests.
*/

//	__SEEME__ We load this first, for once, since some of its macros are needed
//	for the following evaluation. This will have no impact on how any
//	subsequently-included std headers are evaluated.
#include <lucenaBAL/details/lbalConfig.hpp>


/*
	First, make sure any SD-6 macros that are available are defined. This is
	done carefully in stages in order to avoid loading unnecessary headers
	while also avoiding compilation errors if we try to load a header that does
	not exist. Where we lack confidence in availability, we act conservatively.

	__SEEME__ It’s possible that an implementation of a pre-C++20 Standard will
	define these macros in the relevant headers themselves, which would be
	arguably self-defeating. We don’t bother dealing with that particular
	pathology directly, instead we just assign default macro values based on
	whatever we can glean without loading every imaginable header.
*/
#if !defined (LBAL_LIBCPP2A_VERSION)
	#if defined (__has_include)
		#if __has_include (<version>)
			#define LBAL_LIBCPP2A_VERSION 1L
		#else
			#define LBAL_LIBCPP2A_VERSION 0L
		#endif
	#else
		/*
			In this case, we don’t have `__has_include`, and can’t safely
			determine whether `<version>` exists. We leave
			`LBAL_LIBCPP2A_VERSION` undefined for now, and come back to it
			after acquiring sufficient metadata to make a better guess.
		*/
	#endif
#elif LBAL_LIBCPP2A_VERSION
	#ifdef (__has_include)
		#if !__has_include (<version>)
			/*
				The client claims `<version>` exists, but it doesn’t. We
				override.
			*/
			#undef LBAL_LIBCPP2A_VERSION
			#define LBAL_LIBCPP2A_VERSION 0L
			#warning "<version> not found; resetting LBAL_LIBCPP2A_VERSION"
		#endif
	#else
		/*
			We don’t block on this, as the header may have been back-ported,
			even if the means to test for the header is not available, and the
			client somehow accommodated this.
		*/
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPP2A_VERSION; attempting to include <version>"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#endif	//	LBAL_LIBCPP2A_VERSION

#if LBAL_LIBCPP2A_VERSION
	#include <version>
#else
	/*
		In C++, this is a do-nothing header we include just for the side
		effects: by convention, the Standard Library implementation will be
		configured and many assorted compiler-dependent feature detection
		macros will be defined.
	*/
	#include <ciso646>
#endif


/*------------------------------------------------------------------------------
	Library Version Checks

	These are tokens that can’t be adequately defined without some extrinsic
	knowledge of the library involved, usually requiring knowledge of the
	capabilities of specific versions. We handle these first before attempting
	the more generalized tests.
*/

#if defined (_LIBCPP_VERSION)
	#if defined (__apple_build_version__)
		#include <lucenaBAL/details/libraries/lbalStandardLibraryAppleLibCpp.hpp>
	#else
		#include <lucenaBAL/details/libraries/lbalStandardLibraryLibCpp.hpp>
	#endif
#elif defined (__GLIBCXX__)
	//	__SEEME__ Note that older iterations of libstdc++ used __GLIBCPP__
	#include <lucenaBAL/details/libraries/lbalStandardLibraryLibStdCpp.hpp>
#elif defined (_MSC_VER)
	/*
		__SEEME__ Not exactly an equivalent test, but I don’t know of a way to
		reliably identify the MSVC Standard Library: we simply check to see if
		we’re running MSVC and and whether no other Standard Library detection
		test has passed.
	*/
	#include <lucenaBAL/details/libraries/lbalStandardLibraryMSVC.hpp>
#else
	/*
		__APIME__ We work under the happy assumption that we can rely
		exclusively on generic tests for feature detection; this is almost
		certainly doomed to failure.
	*/
	#define LBAL_NAME_STANDARD_LIBRARY u8"Unknown Standard Library implementation"

	#if LBAL_CONFIG_enable_pedantic_warnings
		#warning "Unable to identify the Standard Library implementation is use; attempting to go fully generic"
	#endif	//	LBAL_CONFIG_enable_pedantic_warnings
#endif


#if !LBAL_LIBCPP2A_VERSION
	/*
		If we get here, then we were not initially able to determine whether to
		set `LBAL_LIBCPP2A_VERSION`, so we collected additional information and
		gave ourselves more opportunities to make a determination, and were
		still ultimately unable to determine whether `<version` is available.
		We choose conservatively.
	*/
	#define LBAL_LIBCPP2A_VERSION 0L
#endif


/*------------------------------------------------------------------------------
	Definition Tests

	These are intended to be platform-agnostic. Platform-aware and
	compiler-aware checks should have been handled in the previous section or
	earlier.
*/

//	Note that we do not track experimental versions of this.
#if !defined (LBAL_LIBCPP17_ANY)
	#if defined (__has_include) && __has_include (<any>) \
			&& (__cpp_lib_any || !defined (__cpp_lib_any))
		#if __cpp_lib_any
			#define LBAL_LIBCPP17_ANY __cpp_lib_any
		#else
			#define LBAL_LIBCPP17_ANY 201606L
		#endif
	#else
		#define LBAL_LIBCPP17_ANY 0L
	#endif
#elif LBAL_LIBCPP17_ANY
	#if defined (__has_include)
		#if !__has_include (<any>)
			#undef LBAL_LIBCPP17_ANY
			#define LBAL_LIBCPP17_ANY 0L
			#warning "<any> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPP17_ANY"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#endif	//	LBAL_LIBCPP17_ANY


//	This functionality was originally going to be stuffed into <utility>, but
//	ended up getting its own header. Happily, this doesn’t end up impeding our
//	ability to detect the feature.
#if !defined (LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS)
	#if defined (__has_include) && __has_include (<charconv>) \
			&& (__cpp_lib_to_chars || !defined (__cpp_lib_to_chars))
		#if __cpp_lib_to_chars
			#define LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS __cpp_lib_to_chars
		#else
			#define LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS 201611L
		#endif
	#else
		#define LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS 0L
	#endif
#elif LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS
	#if defined (__has_include)
		#if !__has_include (<charconv>)
			#undef LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS
			#define LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS 0L
			#warning "<charconv> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#endif	//	LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS


//	Use LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS to detect full
//	compliance with the feature; this only detects whether a key header is
//	implemented. Note that we do not track experimental versions of this.
#if !defined (LBAL_LIBCPP17_EXECUTION)
	#if defined (__has_include) && __has_include (<execution>) \
			&& (__cpp_lib_execution || !defined (__cpp_lib_execution))
		#if __cpp_lib_execution
			#define LBAL_LIBCPP17_EXECUTION __cpp_lib_execution
		#else
			#define LBAL_LIBCPP17_EXECUTION 201603L
		#endif
	#else
		#define LBAL_LIBCPP17_EXECUTION 0L
	#endif
#elif LBAL_LIBCPP17_EXECUTION
	#if defined (__has_include)
		#if !__has_include (<execution>)
			#undef LBAL_LIBCPP17_EXECUTION
			#define LBAL_LIBCPP17_EXECUTION 0L
			#warning "<execution> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPP17_EXECUTION"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#endif	//	LBAL_LIBCPP17_EXECUTION


#if !defined (LBAL_LIBCPP17_FILESYSTEM)
	#if defined (__has_include) && __has_include (<filesystem>) \
			&& !LBAL_LIBCPP17_FILESYSTEM_EXP \
			&& (__cpp_lib_filesystem || !defined (__cpp_lib_filesystem))
		#if __cpp_lib_filesystem
			#define LBAL_LIBCPP17_FILESYSTEM __cpp_lib_filesystem
		#else
			#define LBAL_LIBCPP17_FILESYSTEM 201703L
		#endif

		#ifndef LBAL_LIBCPP17_FILESYSTEM_EXP
			#define LBAL_LIBCPP17_FILESYSTEM_EXP 0L
		#endif
	#else
		#define LBAL_LIBCPP17_FILESYSTEM 0L
	#endif
#elif LBAL_LIBCPP17_FILESYSTEM
	#if defined (__has_include)
		#if !__has_include (<filesystem>)
			#undef LBAL_LIBCPP17_FILESYSTEM
			#define LBAL_LIBCPP17_FILESYSTEM 0L
			#warning "<filesystem> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPP17_FILESYSTEM"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#elif !defined (LBAL_LIBCPP17_FILESYSTEM_EXP)
	#define LBAL_LIBCPP17_FILESYSTEM_EXP 0L
#endif	//	LBAL_LIBCPP17_FILESYSTEM

#if !defined (LBAL_LIBCPP17_FILESYSTEM_EXP)
	#if defined (__has_include) && __has_include (<experimental/filesystem>) \
			&& (__cpp_lib_experimental_filesystem || !defined (__cpp_lib_experimental_filesystem))
		#if __cpp_lib_experimental_filesystem
			#define LBAL_LIBCPP17_FILESYSTEM_EXP __cpp_lib_experimental_filesystem
		#else
			#define LBAL_LIBCPP17_FILESYSTEM_EXP 201406L
		#endif
	#else
		#define LBAL_LIBCPP17_FILESYSTEM_EXP 0L
	#endif
#elif LBAL_LIBCPP17_FILESYSTEM_EXP
	#if LBAL_LIBCPP17_FILESYSTEM
		#undef LBAL_LIBCPP17_FILESYSTEM_EXP
		#define LBAL_LIBCPP17_FILESYSTEM_EXP 0L
		#warning "LBAL_LIBCPP17_FILESYSTEM && LBAL_LIBCPP17_FILESYSTEM_EXP"
	#elif defined (__has_include)
		#if !__has_include (<experimental/filesystem>)
			#undef LBAL_LIBCPP17_FILESYSTEM_EXP
			#define LBAL_LIBCPP17_FILESYSTEM_EXP 0L
			#warning "<experimental/filesystem> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPP17_FILESYSTEM_EXP"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#endif	//	LBAL_LIBCPP17_FILESYSTEM_EXP


//	This functionality lives in <new>, so we have to rely on either the SD-6
//	macro or an override to detect it; if no explicit override is set and
//	the SD-6 macro is unavailable, we default to 0. Note that we do not track
//	experimental versions of this.
#if !defined (LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE)
	#if __cpp_lib_thread_hardware_interference_size
		#define LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE __cpp_lib_thread_hardware_interference_size
	#else
		#define LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE 0L
	#endif
#endif	//	LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE


//	This functionality lives in <new>, so we have to rely on either the SD-6
//	macro or an override to detect it; if no explicit override is set and
//	the SD-6 macro is unavailable, we default to 0. Note that we do not track
//	experimental versions of this.
#if !defined (LBAL_LIBCPP17_LAUNDER)
	#if __cpp_lib_launder
		#define LBAL_LIBCPP17_LAUNDER __cpp_lib_launder
	#else
		#define LBAL_LIBCPP17_LAUNDER 0L
	#endif
#endif	//	LBAL_LIBCPP17_LAUNDER


//	Note that we do not track experimental versions of this.
#if !defined (LBAL_LIBCPP17_OPTIONAL)
	#if defined (__has_include) && __has_include (<optional>) \
			&& (__cpp_lib_optional || !defined (__cpp_lib_optional))
		#if __cpp_lib_optional
			#define LBAL_LIBCPP17_OPTIONAL __cpp_lib_optional
		#else
			#define LBAL_LIBCPP17_OPTIONAL 201606L
		#endif
	#else
		#define LBAL_LIBCPP17_OPTIONAL 0L
	#endif
#elif LBAL_LIBCPP17_OPTIONAL
	#if defined (__has_include)
		#if !__has_include (<optional>)
			#undef LBAL_LIBCPP17_OPTIONAL
			#define LBAL_LIBCPP17_OPTIONAL 0L
			#warning "<optional> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPP17_OPTIONAL"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#endif	//	LBAL_LIBCPP17_OPTIONAL


//	Use LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS to detect full
//	compliance with the feature; this only detects whether the requisite
//	algorithms have been implemented. Note that as this functionality lives in
//	multiple pre-existing std headers, so we have to rely on either the SD-6
//	macro or an override to detect it; without these, we default to 0. Note
//	that we do not track experimental versions of this.
#if !defined (LBAL_LIBCPP17_PARALLEL_ALGORITHM)
	#if __cpp_lib_parallel_algorithm
		#define LBAL_LIBCPP17_PARALLEL_ALGORITHM __cpp_lib_parallel_algorithm
	#else
		#define LBAL_LIBCPP17_PARALLEL_ALGORITHM 0L
	#endif
#endif	//	LBAL_LIBCPP17_PARALLEL_ALGORITHM


//	This functionality lives in multiple pre-existing std headers, so we have
//	to rely on either the SD-6 macro or an override to detect it; without
//	these, we default to 0. Note that we do not track experimental versions of
//	this.
#if !defined (LBAL_LIBCPP17_SPLICING_MAPS_AND_SETS)
	#if __cpp_lib_node_extract
		#define LBAL_LIBCPP17_SPLICING_MAPS_AND_SETS __cpp_lib_node_extract
	#else
		#define LBAL_LIBCPP17_SPLICING_MAPS_AND_SETS 0L
	#endif
#endif	//	LBAL_LIBCPP17_SPLICING_MAPS_AND_SETS


//	This is an aggregate that tracks two different SD-6 macros for the purpose
//	of establishing Standard compliance. There is no single corresponding SD-6
//	macro. Note that we do not track experimental versions of this.
#if !defined (LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS)
	#if LBAL_LIBCPP17_EXECUTION && LBAL_LIBCPP17_PARALLEL_ALGORITHM
		#define LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS 1L
	#else
		#define LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS 0L
	#endif
#endif	//	LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS


//	Note that we do not track experimental versions of this.
#if !defined (LBAL_LIBCPP17_VARIANT)
	#if defined (__has_include) && __has_include (<variant>) \
			&& (__cpp_lib_variant || !defined (__cpp_lib_variant))
		#if __cpp_lib_variant
			#define LBAL_LIBCPP17_VARIANT __cpp_lib_variant
		#else
			#define LBAL_LIBCPP17_VARIANT 201606L
		#endif
	#else
		#define LBAL_LIBCPP17_VARIANT 0L
	#endif
#elif LBAL_LIBCPP17_VARIANT
	#if defined (__has_include)
		#if !__has_include (<variant>)
			#undef LBAL_LIBCPP17_VARIANT
			#define LBAL_LIBCPP17_VARIANT 0L
			#warning "<variant> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPP17_VARIANT"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#endif	//	LBAL_LIBCPP17_VARIANT


//	This functionality lives in <bit>, but requires either the SD-6 macro or an
//	override to detect it; if no explicit override is set and the SD-6 macro is
//	unavailable, we default to 0.
#if !defined (LBAL_LIBCPP2A_BIT_CAST)
	#if defined (__has_include) && __has_include (<bit>) \
			&& __cpp_lib_bit_cast
		#define LBAL_LIBCPP2A_BIT_CAST __cpp_lib_bit_cast
	#else
		#define LBAL_LIBCPP2A_BIT_CAST 0L
	#endif
#elif LBAL_LIBCPP2A_BIT_CAST
	#if defined (__has_include)
		#if !__has_include (<bit>)
			#undef LBAL_LIBCPP2A_BIT_CAST
			#define LBAL_LIBCPP2A_BIT_CAST 0L
			#warning "<bit> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPP2A_BIT_CAST"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#endif	//	LBAL_LIBCPP2A_BIT_CAST


//	This functionality lives in <chrono>, but it currently has no SD-6 macro
//	and requires an override to detect it; if no explicit override is set, we
//	default to 0.
#if !defined (LBAL_LIBCPP2A_CALENDAR_AND_TIMEZONE)
	#define LBAL_LIBCPP2A_CALENDAR_AND_TIMEZONE 0L
#endif	//	LBAL_LIBCPP2A_CALENDAR_AND_TIMEZONE


//	Note that this for the Concepts support library; the language feature is
//	handled separately.
#if !defined (LBAL_LIBCPP2A_CONCEPT_LIBRARY)
	#if defined (__has_include) && __has_include (<concepts>) \
			&& !LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP \
			&& (__cpp_lib_concepts || !defined (__cpp_lib_concepts))
		#if __cpp_lib_concepts
			#define LBAL_LIBCPP2A_CONCEPT_LIBRARY __cpp_lib_concepts
		#else
			#define LBAL_LIBCPP2A_CONCEPT_LIBRARY 201806L
		#endif

		#ifndef LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP
			#define LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP 0L
		#endif
	#else
		#define LBAL_LIBCPP2A_CONCEPT_LIBRARY 0L
	#endif
#elif LBAL_LIBCPP2A_CONCEPT_LIBRARY
	#if defined (__has_include)
		#if !__has_include (<concepts>)
			#undef LBAL_LIBCPP2A_CONCEPT_LIBRARY
			#define LBAL_LIBCPP2A_CONCEPT_LIBRARY 0L
			#warning "<concepts> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPP2A_CONCEPT_LIBRARY"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#elif !defined (LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP)
	#define LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP 0L
#endif	//	LBAL_LIBCPP2A_CONCEPT_LIBRARY

#if !defined (LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP)
	#if defined (__has_include) && __has_include (<experimental/concepts>) \
			&& (__cpp_lib_experimental_concepts || !defined (__cpp_lib_experimental_concepts))
		#if __cpp_lib_experimental_concepts
			#define LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP __cpp_lib_experimental_concepts
		#else
			#define LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP 201507L
		#endif
	#else
		#define LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP 0L
	#endif
#elif LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP
	#if LBAL_LIBCPP2A_CONCEPT_LIBRARY
		#undef LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP
		#define LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP 0L
		#warning "LBAL_LIBCPP2A_CONCEPT_LIBRARY && LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP"
	#elif defined (__has_include)
		#if !__has_include (<experimental/concepts>)
			#undef LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP
			#define LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP 0L
			#warning "<experimental/concepts> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#endif	//	LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP


//	This functionality lives in multiple pre-existing headers, and requires
//	either the SD-6 macro or an override to detect it; if no explicit override
//	is set and the SD-6 macro is unavailable, we default to 0.
#if !defined (LBAL_LIBCPP2A_CONSTEXPR_FOR_ALGORITHM_AND_UTILITY)
	#if __cpp_lib_constexpr_algorithms
		#define LBAL_LIBCPP2A_CONSTEXPR_FOR_ALGORITHM_AND_UTILITY __cpp_lib_constexpr_algorithms
	#else
		#define LBAL_LIBCPP2A_CONSTEXPR_FOR_ALGORITHM_AND_UTILITY 0L
	#endif
#endif	//	LBAL_LIBCPP2A_CONSTEXPR_FOR_ALGORITHM_AND_UTILITY


//	__SEEME__ This was originally a TS (with competing versions), and so has
//	experimental implementations we track.
//	__SEEME__ Note that there is no separate SD-6 macro for the library header
//	vs. the language feature, so we just use language feature macro; this will
//	almost definitely change to __cpp_lib_coroutine in the future, but until it
//	does, we’re following the approved proposal.
#if !defined (LBAL_LIBCPP2A_COROUTINES)
	#if defined (__has_include) && __has_include (<coroutine>) \
			&& !LBAL_LIBCPP2A_COROUTINES_EXP \
			&& (__cpp_coroutines || !defined (__cpp_coroutines))
		#if __cpp_coroutines
			#define LBAL_LIBCPP2A_COROUTINES __cpp_coroutines
		#else
			#define LBAL_LIBCPP2A_COROUTINES 201803L
		#endif

		#ifndef LBAL_LIBCPP2A_COROUTINES_EXP
			#define LBAL_LIBCPP2A_COROUTINES_EXP 0L
		#endif
	#else
		#define LBAL_LIBCPP2A_COROUTINES 0L
	#endif
#elif LBAL_LIBCPP2A_COROUTINES
	#if defined (__has_include)
		#if !__has_include (<coroutine>)
			#undef LBAL_LIBCPP2A_COROUTINES
			#define LBAL_LIBCPP2A_COROUTINES 0L
			#warning "<coroutine> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPP2A_COROUTINES"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#else
	#if !defined (LBAL_LIBCPP2A_COROUTINES_EXP)
		#define LBAL_LIBCPP2A_COROUTINES_EXP 0L
	#endif
#endif	//	LBAL_LIBCPP2A_COROUTINES

#if !defined (LBAL_LIBCPP2A_COROUTINES_EXP)
	#if defined (__has_include) && __has_include (<experimental/coroutine>) \
			&& (__cpp_coroutines || !defined (__cpp_coroutines))
		#if __cpp_coroutines
			#define LBAL_LIBCPP2A_COROUTINES_EXP __cpp_coroutines
		#else
			#define LBAL_LIBCPP2A_COROUTINES_EXP 201803L
		#endif
	#else
		#define LBAL_LIBCPP2A_COROUTINES_EXP 0L
	#endif
#elif LBAL_LIBCPP2A_COROUTINES_EXP
	#if LBAL_LIBCPP2A_COROUTINES
		#undef LBAL_LIBCPP2A_COROUTINES_EXP
		#define LBAL_LIBCPP2A_COROUTINES_EXP 0L
		#warning "LBAL_LIBCPP2A_COROUTINES && LBAL_LIBCPP2A_COROUTINES_EXP"
	#elif defined (__has_include)
		#if !__has_include (<experimental/coroutine>)
			#undef LBAL_LIBCPP2A_COROUTINES_EXP
			#define LBAL_LIBCPP2A_COROUTINES_EXP 0L
			#warning "<experimental/coroutine> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPP2A_COROUTINES_EXP"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#endif	//	LBAL_LIBCPP2A_COROUTINES_EXP


//	This functionality lives in <new>, so we have to rely on either the SD-6
//	macro or an override to detect it; if no explicit override is set and
//	the SD-6 macro is unavailable, we default to 0. Note that we do not track
//	experimental versions of this.

#if !defined (LBAL_LIBCPP2A_DESTROYING_DELETE)
	#if __cpp_lib_destroying_delete
		#define LBAL_LIBCPP2A_DESTROYING_DELETE __cpp_lib_destroying_delete
	#else
		#define LBAL_LIBCPP2A_DESTROYING_DELETE 0L
	#endif
#endif	//	LBAL_LIBCPP2A_DESTROYING_DELETE


//	This functionality lives in <memory>, but it currently has no SD-6 macro
//	and requires an override to detect it; if no explicit override is set, we
//	default to 0.
#if !defined (LBAL_LIBCPP2A_EXTENDING_MAKE_SHARED_TO_SUPPORT_ARRAYS)
	#define LBAL_LIBCPP2A_EXTENDING_MAKE_SHARED_TO_SUPPORT_ARRAYS 0L
#endif	//	LBAL_LIBCPP2A_EXTENDING_MAKE_SHARED_TO_SUPPORT_ARRAYS


//	This functionality lives in <atomic>, but it currently has no SD-6 macro
//	and requires an override to detect it; if no explicit override is set, we
//	default to 0.
#if !defined (LBAL_LIBCPP2A_FLOATING_POINT_ATOMIC)
	#define LBAL_LIBCPP2A_FLOATING_POINT_ATOMIC 0L
#endif	//	LBAL_LIBCPP2A_FLOATING_POINT_ATOMIC


//	This functionality lives in multiple pre-existing headers, and requires
//	either the SD-6 macro or an override to detect it; if no explicit override
//	is set and the SD-6 macro is unavailable, we default to 0.
#if !defined (LBAL_LIBCPP2A_LIST_REMOVE_RETURN_TYPE)
	#if __cpp_lib_list_remove_return_type
		#define LBAL_LIBCPP2A_LIST_REMOVE_RETURN_TYPE __cpp_lib_list_remove_return_type
	#else
		#define LBAL_LIBCPP2A_LIST_REMOVE_RETURN_TYPE 0L
	#endif
#endif	//	LBAL_LIBCPP2A_LIST_REMOVE_RETURN_TYPE


//	This functionality lives in <complex>, and requires either the SD-6 macro
//	or an override to detect it; if no explicit override is set and the SD-6
//	macro is unavailable, we default to 0.
#if !defined (LBAL_LIBCPP2A_MORE_CONSTEXPR_FOR_COMPLEX)
	#if __cpp_lib_constexpr_complex
		#define LBAL_LIBCPP2A_MORE_CONSTEXPR_FOR_COMPLEX __cpp_lib_constexpr_complex
	#else
		#define LBAL_LIBCPP2A_MORE_CONSTEXPR_FOR_COMPLEX 0L
	#endif
#endif	//	LBAL_LIBCPP2A_MORE_CONSTEXPR_FOR_COMPLEX


//	There is no SD-6 macro, yet.
#if !defined (LBAL_LIBCPP2A_SPAN)
	#if defined (__has_include) && __has_include (<span>)
		//	__SEEME__ Value not yet assigned.
		#define LBAL_LIBCPP2A_SPAN 1L
	#else
		#define LBAL_LIBCPP2A_SPAN 0L
	#endif
#elif LBAL_LIBCPP2A_SPAN
	#if defined (__has_include)
		#if !__has_include (<span>)
			#undef LBAL_LIBCPP2A_SPAN
			#define LBAL_LIBCPP2A_SPAN 0L
			#warning "<span> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPP2A_SPAN"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#endif	//	LBAL_LIBCPP2A_SPAN


//	This functionality lives in <atomic>, and requires either the SD-6 macro
//	or an override to detect it; if no explicit override is set and the SD-6
//	macro is unavailable, we default to 0.
#if !defined (LBAL_LIBCPP2A_STD_ATOMIC_REF)
	#if __cpp_lib_atomic_ref
		#define LBAL_LIBCPP2A_STD_ATOMIC_REF __cpp_lib_atomic_ref
	#else
		#define LBAL_LIBCPP2A_STD_ATOMIC_REF 0L
	#endif
#endif	//	LBAL_LIBCPP2A_STD_ATOMIC_REF


//	This functionality lives in <type_traits>, but it currently has no SD-6
//	macro and requires an override to detect it; if no explicit override is
//	set, we default to 0.
#if !defined (LBAL_LIBCPP2A_STD_ENDIAN)
	#define LBAL_LIBCPP2A_STD_ENDIAN 0L
#endif	//	LBAL_LIBCPP2A_STD_ENDIAN


//	This functionality lives in <type_traits>, but it currently has no SD-6
//	macro and requires an override to detect it; if no explicit override is
//	set, we default to 0.
#if !defined (LBAL_LIBCPP2A_STD_REMOVE_CVREF)
	#define LBAL_LIBCPP2A_STD_REMOVE_CVREF 0L
#endif	//	LBAL_LIBCPP2A_STD_REMOVE_CVREF


//	This functionality lives in <string> and <string_view>, but it currently
//	has no SD-6 macro and requires an override to detect it; if no explicit
//	override is set, we default to 0.
#if !defined (LBAL_LIBCPP2A_STRING_PREFIX_AND_SUFFIX_CHECKING)
	#define LBAL_LIBCPP2A_STRING_PREFIX_AND_SUFFIX_CHECKING 0L
#endif	//	LBAL_LIBCPP2A_STRING_PREFIX_AND_SUFFIX_CHECKING


#if !defined (LBAL_LIBCPP2A_SYNCHRONIZED_BUFFERED_OSTREAM)
	#if defined (__has_include) && __has_include (<syncstream>) \
			&& (__cpp_lib_syncstream || !defined (__cpp_lib_syncstream))
		#if __cpp_lib_syncstream
			#define LBAL_LIBCPP2A_SYNCHRONIZED_BUFFERED_OSTREAM __cpp_lib_syncstream
		#else
			//	__SEEME__ Value not yet assigned.
			#define LBAL_LIBCPP2A_SYNCHRONIZED_BUFFERED_OSTREAM 1L
		#endif
	#else
		#define LBAL_LIBCPP2A_SYNCHRONIZED_BUFFERED_OSTREAM 0L
	#endif
#elif LBAL_LIBCPP2A_SYNCHRONIZED_BUFFERED_OSTREAM
	#if defined (__has_include)
		#if !__has_include (<syncstream>)
			#undef LBAL_LIBCPP2A_SYNCHRONIZED_BUFFERED_OSTREAM
			#define LBAL_LIBCPP2A_SYNCHRONIZED_BUFFERED_OSTREAM 0L
			#warning "<syncstream> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPP2A_SYNCHRONIZED_BUFFERED_OSTREAM"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#endif	//	LBAL_LIBCPP2A_SYNCHRONIZED_BUFFERED_OSTREAM


#if !defined (LBAL_LIBCPP2A_THREE_WAY_COMPARISON_OPERATOR_SUPPORT_COMPARE)
	#if defined (__has_include) && __has_include (<compare>) \
			&& (__cpp_lib_three_way_comparison || !defined (__cpp_lib_three_way_comparison))
		#if __cpp_lib_three_way_comparison
			#define LBAL_LIBCPP2A_THREE_WAY_COMPARISON_OPERATOR_SUPPORT_COMPARE __cpp_lib_three_way_comparison
		#else
			//	__SEEME__ Value not yet assigned.
			#define LBAL_LIBCPP2A_THREE_WAY_COMPARISON_OPERATOR_SUPPORT_COMPARE 201711L
		#endif
	#else
		#define LBAL_LIBCPP2A_THREE_WAY_COMPARISON_OPERATOR_SUPPORT_COMPARE 0L
	#endif
#elif LBAL_LIBCPP2A_THREE_WAY_COMPARISON_OPERATOR_SUPPORT_COMPARE
	#if defined (__has_include)
		#if !__has_include (<compare>)
			#undef LBAL_LIBCPP2A_THREE_WAY_COMPARISON_OPERATOR_SUPPORT_COMPARE
			#define LBAL_LIBCPP2A_THREE_WAY_COMPARISON_OPERATOR_SUPPORT_COMPARE 0L
			#warning "<compare> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPP2A_THREE_WAY_COMPARISON_OPERATOR_SUPPORT_COMPARE"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#endif	//	LBAL_LIBCPP2A_THREE_WAY_COMPARISON_OPERATOR_SUPPORT_COMPARE


//	This functionality lives in <type_traits>, but it currently has no SD-6
//	macro and requires an override to detect it; if no explicit override is
//	set, we default to 0.
#if !defined (LBAL_LIBCPP2A_TYPE_IDENTITY)
	#define LBAL_LIBCPP2A_TYPE_IDENTITY 0L
#endif	//	LBAL_LIBCPP2A_TYPE_IDENTITY


//	This functionality lives in <memory>, but it currently has no SD-6 macro
//	and requires an override to detect it; if no explicit override is set, we
//	default to 0.
#if !defined (LBAL_LIBCPP2A_UTILITY_TO_CONVERT_A_POINTER_TO_A_RAW_POINTER)
	#define LBAL_LIBCPP2A_UTILITY_TO_CONVERT_A_POINTER_TO_A_RAW_POINTER 0L
#endif	//	LBAL_LIBCPP2A_UTILITY_TO_CONVERT_A_POINTER_TO_A_RAW_POINTER


//	Networking functionality spans an array of new headers; we only check for
//	the presence of the convenience header, <net>.
#if !defined (LBAL_LIBCPPTS_NETWORKING)
	#if defined (__has_include) && __has_include (<net>) \
			&& !LBAL_LIBCPPTS_NETWORKING_EXP \
			&& (__cpp_lib_net || !defined (__cpp_lib_net))
		#if __cpp_lib_net
			#define LBAL_LIBCPPTS_NETWORKING __cpp_lib_net
		#else
			//	__SEEME__ This value is a proxy; the Networking TS has not yet been
			//	approved.
			#define LBAL_LIBCPPTS_NETWORKING 201803L
		#endif

		#ifndef LBAL_LIBCPPTS_NETWORKING_EXP
			#define LBAL_LIBCPPTS_NETWORKING_EXP 0L
		#endif
	#else
		#define LBAL_LIBCPPTS_NETWORKING 0L
	#endif
#elif LBAL_LIBCPPTS_NETWORKING
	#if defined (__has_include)
		#if !__has_include (<net>)
			#undef LBAL_LIBCPPTS_NETWORKING
			#define LBAL_LIBCPPTS_NETWORKING 0L
			#warning "<net> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPPTS_NETWORKING"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#else
	#if !defined (LBAL_LIBCPPTS_NETWORKING_EXP)
		#define LBAL_LIBCPPTS_NETWORKING_EXP 0L
	#endif
#endif	//	LBAL_LIBCPPTS_NETWORKING

#if !defined (LBAL_LIBCPPTS_NETWORKING_EXP)
	#if defined (__has_include) && __has_include (<experimental/net>) \
			&& (__cpp_lib_experimental_net || !defined (__cpp_lib_experimental_net))
		#if __cpp_lib_experimental_net
			#define LBAL_LIBCPPTS_NETWORKING_EXP __cpp_lib_experimental_net
		#else
			#define LBAL_LIBCPPTS_NETWORKING_EXP 201803L
		#endif
	#else
		#define LBAL_LIBCPPTS_NETWORKING_EXP 0L
	#endif
#elif LBAL_LIBCPPTS_NETWORKING_EXP
	#if LBAL_LIBCPPTS_NETWORKING
		#undef LBAL_LIBCPPTS_NETWORKING_EXP
		#define LBAL_LIBCPPTS_NETWORKING_EXP 0L
		#warning "LBAL_LIBCPPTS_NETWORKING && LBAL_LIBCPPTS_NETWORKING_EXP"
	#elif defined (__has_include)
		#if !__has_include (<experimental/net>)
			#undef LBAL_LIBCPPTS_NETWORKING_EXP
			#define LBAL_LIBCPPTS_NETWORKING_EXP 0L
			#warning "<experimental/net> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPPTS_NETWORKING_EXP"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#endif	//	LBAL_LIBCPPTS_NETWORKING_EXP


//	Networking functionality spans an array of new headers; we only check for
//	the presence of the convenience header, <net>.
//	__FIXME__ this may be incorrect for networking extensions; check the TS.
#if !defined (LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE)
	#if defined (__has_include) && __has_include (<net>) \
			&& !LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP \
			&& (__cpp_lib_net_extensible || !defined (__cpp_lib_net_extensible))
		#if __cpp_lib_net_extensible
			#define LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE __cpp_lib_net_extensible
		#else
			//	__SEEME__ This value is a proxy; the Networking TS has not yet been
			//	approved.
			#define LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE 201803L
		#endif

		#ifndef LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP
			#define LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP 0L
		#endif
	#else
		#define LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE 0L
	#endif
#elif LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE
	#if defined (__has_include)
		#if !__has_include (<net>)
			#undef LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE
			#define LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE 0L
			#warning "<net> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#else
	#if !defined (LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP)
		#define LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP 0L
	#endif
#endif	//	LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE

#if !defined (LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP)
	#if defined (__has_include) && __has_include (<experimental/net>) \
			&& (__cpp_lib_experimental_net_extensible || !defined (__cpp_lib_experimental_net_extensible))
		#if __cpp_lib_experimental_net_extensible
			#define LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP __cpp_lib_experimental_net_extensible
		#else
			#define LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP 201803L
		#endif
	#else
		#define LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP 0L
	#endif
#elif LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP
	#if LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE
		#undef LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP
		#define LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP 0L
		#warning "LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE && LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP"
	#elif defined (__has_include)
		#if !__has_include (<experimental/net>)
			#undef LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP
			#define LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP 0L
			#warning "<experimental/net> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#endif	//	LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP


/*
	This functionality lives in <memory>, and requires either the SD-6 macro
	or an override to detect it; if no explicit override is set and the SD-6
	macro is unavailable, we default to 0.

	__SEEME__ It might make sense to check for the existence of an experimental
	version of <memory> when using __cpp_lib_experimental_observer_ptr. For
	now, we don’t over-think it since there are no examples in the wild to
	consider.
*/
#if !defined (LBAL_LIBCPPTS_OBSERVER_PTR)
	#if !LBAL_LIBCPPTS_OBSERVER_PTR_EXP && __cpp_lib_observer_ptr
		#define LBAL_LIBCPPTS_OBSERVER_PTR __cpp_lib_observer_ptr

		#ifndef LBAL_LIBCPPTS_OBSERVER_PTR_EXP
			#define LBAL_LIBCPPTS_OBSERVER_PTR_EXP 0L
		#endif
	#else
		#define LBAL_LIBCPPTS_OBSERVER_PTR 0L
	#endif
#elif !LBAL_LIBCPPTS_OBSERVER_PTR
	#if !defined (LBAL_LIBCPPTS_OBSERVER_PTR_EXP)
		#define LBAL_LIBCPPTS_OBSERVER_PTR_EXP 0L
	#endif
#endif	//	LBAL_LIBCPPTS_OBSERVER_PTR

#if !defined (LBAL_LIBCPPTS_OBSERVER_PTR_EXP)
	#if __cpp_lib_experimental_observer_ptr
		#define LBAL_LIBCPPTS_OBSERVER_PTR_EXP __cpp_lib_experimental_observer_ptr
	#else
		#define LBAL_LIBCPPTS_OBSERVER_PTR_EXP 0L
	#endif
#elif LBAL_LIBCPPTS_OBSERVER_PTR_EXP
	#if LBAL_LIBCPPTS_OBSERVER_PTR
		#undef LBAL_LIBCPPTS_OBSERVER_PTR_EXP
		#define LBAL_LIBCPPTS_OBSERVER_PTR_EXP 0L
		#warning "LBAL_LIBCPPTS_OBSERVER_PTR && LBAL_LIBCPPTS_OBSERVER_PTR_EXP"
	#endif
#endif	//	LBAL_LIBCPPTS_OBSERVER_PTR_EXP


