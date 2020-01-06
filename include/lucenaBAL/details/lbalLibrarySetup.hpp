/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalLibrarySetup.hpp”
	Copyright © 2018-2020 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/


#pragma once


//	lbal
#include <lucenaBAL/details/lbalConfig.hpp>
#include <lucenaBAL/details/lbalDetectStandardLibrary.hpp>


/*------------------------------------------------------------------------------
	Implementation-specific SD-6 Macro Initialization

	Make sure any SD-6 macros that are available are defined. Note that there
	are tokens that can’t be adequately defined without some extrinsic
	knowledge of the library involved, usually requiring knowledge of the
	capabilities of its specific version. The implementation-specific headers
	take care of all of this initialization.
*/

#if LBAL_TARGET_STANDARD_LIBRARY_APPLE_LIBCPP
	#include <lucenaBAL/details/libraries/lbalStandardLibraryAppleLibCppInitialization.hpp>
#elif LBAL_TARGET_STANDARD_LIBRARY_LIBCPP
	#include <lucenaBAL/details/libraries/lbalStandardLibraryLibCppInitialization.hpp>
#elif LBAL_TARGET_STANDARD_LIBRARY_LIBSTDCPP
	#include <lucenaBAL/details/libraries/lbalStandardLibraryLibStdCppInitialization.hpp>
#elif LBAL_TARGET_STANDARD_LIBRARY_MSVC
	#include <lucenaBAL/details/libraries/lbalStandardLibraryMSVCInitialization.hpp>
#else
	//	In the generic case, we simply attempt to load `<version>` if it can be
	//	found, but otherewise make no special attempt to initialize the SD-6
	//	macros, if they are available.
	#include <lucenaBAL/details/lbalVersionSetup.hpp>
#endif


/*------------------------------------------------------------------------------
	Definition Tests

	These are platform-agnostic. Platform-aware and compiler-aware checks
	should have been handled in the previous section or earlier, which will
	effectively override any assignments we would otherwise have made here.

	__SEEME__ It’s possible that an implementation of a pre-C++20 Standard will
	define these macros in the relevant headers themselves, which would be
	arguably self-defeating. We don’t bother dealing with that particular
	pathology directly; instead we just assign default macro values based on
	whatever we can glean without loading every imaginable header.
*/

//	There isn’t a new header for this, so we rely strictly on the SD-6 macro
//	here, and expect the implementation-specific files to pick up the slack.
#if !defined (LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR)
	#if __cpp_lib_addressof_constexpr
		#define LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR __cpp_lib_addressof_constexpr
	#endif
#endif	//	LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR


//	Note that we do not track experimental versions of this.
#if !defined (LBAL_LIBCPP17_ANY)
	#if defined (__has_include) && __has_include (<any>) \
			&& (__cpp_lib_any || !defined (__cpp_lib_any))
		#if __cpp_lib_any
			#define LBAL_LIBCPP17_ANY __cpp_lib_any
		#elif (LBAL_cpp_version > LBAL_CPP14_VERSION)
			#define LBAL_LIBCPP17_ANY 201606L
		#endif
	#endif
#elif LBAL_LIBCPP17_ANY
	#if defined (__has_include)
		#if !__has_include (<any>)
			#undef LBAL_LIBCPP17_ANY
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
//	ability to detect the feature, except that the detection lies: only MSVS
//	currently offers a fully-conforming implementation, and the Libraries that
//	offer partial implementations can set their SD-6 macros as if they were
//	fully compliant. We’ve split this into two tokens to independently track
//	integer and floating point conversions.
//
//	With this in mind, this detection method is simplistic, and really relies
//	upon the implementation-specific versions for correctness.
#if !defined (LBAL_LIBCPP17_TO_CHARS)
	#if defined (__has_include) && __has_include (<charconv>) \
			&& (__cpp_lib_to_chars || !defined (__cpp_lib_to_chars))
		#if __cpp_lib_to_chars
			#define LBAL_LIBCPP17_TO_CHARS __cpp_lib_to_chars
		#elif (LBAL_cpp_version > LBAL_CPP14_VERSION)
			#define LBAL_LIBCPP17_TO_CHARS 201611L
		#endif
	#endif
#elif LBAL_LIBCPP17_TO_CHARS
	#if defined (__has_include)
		#if !__has_include (<charconv>)
			#undef LBAL_LIBCPP17_TO_CHARS
			#warning "<charconv> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPP17_TO_CHARS"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#endif	//	LBAL_LIBCPP17_TO_CHARS

#if !defined (LBAL_LIBCPP17_TO_CHARS_FP)
	#if defined (__has_include) && __has_include (<charconv>) \
			&& (__cpp_lib_to_chars || !defined (__cpp_lib_to_chars))
		#if __cpp_lib_to_chars
			#define LBAL_LIBCPP17_TO_CHARS_FP __cpp_lib_to_chars
		#elif (LBAL_cpp_version > LBAL_CPP14_VERSION)
			#define LBAL_LIBCPP17_TO_CHARS_FP 201611L
		#endif
	#endif
#elif LBAL_LIBCPP17_TO_CHARS_FP
	#if defined (__has_include)
		#if !__has_include (<charconv>)
			#undef LBAL_LIBCPP17_TO_CHARS_FP
			#warning "<charconv> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPP17_TO_CHARS_FP"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#endif	//	LBAL_LIBCPP17_TO_CHARS_FP

#if !defined (LBAL_LIBCPP17_TO_CHARS_INTEGER)
	#if defined (__has_include) && __has_include (<charconv>) \
			&& (__cpp_lib_to_chars || !defined (__cpp_lib_to_chars))
		#if __cpp_lib_to_chars
			#define LBAL_LIBCPP17_TO_CHARS_INTEGER __cpp_lib_to_chars
		#elif (LBAL_cpp_version > LBAL_CPP14_VERSION)
			#define LBAL_LIBCPP17_TO_CHARS_INTEGER 201611L
		#endif
	#endif
#elif LBAL_LIBCPP17_TO_CHARS_INTEGER
	#if defined (__has_include)
		#if !__has_include (<charconv>)
			#undef LBAL_LIBCPP17_TO_CHARS_INTEGER
			#warning "<charconv> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPP17_TO_CHARS_INTEGER"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#endif	//	LBAL_LIBCPP17_TO_CHARS_INTEGER


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
	#endif
#endif	//	LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE


//	This functionality lives in <new>, so we have to rely on either the SD-6
//	macro or an override to detect it; if no explicit override is set and
//	the SD-6 macro is unavailable, we default to 0. Note that we do not track
//	experimental versions of this.
#if !defined (LBAL_LIBCPP17_LAUNDER)
	#if __cpp_lib_launder
		#define LBAL_LIBCPP17_LAUNDER __cpp_lib_launder
	#endif
#endif	//	LBAL_LIBCPP17_LAUNDER


//	This functionality lives in multiple pre-existing std headers, so we have
//	to rely on either the SD-6 macro or an override to detect it; without
//	these, we default to 0. Note that we do not track experimental versions of
//	this.
#if !defined (LBAL_LIBCPP17_NODE_EXTRACT)
	#if __cpp_lib_node_extract
		#define LBAL_LIBCPP17_NODE_EXTRACT __cpp_lib_node_extract
	#endif
#endif	//	LBAL_LIBCPP17_NODE_EXTRACT


//	Note that we do not track experimental versions of this.
#if !defined (LBAL_LIBCPP17_OPTIONAL) \
		|| !defined (LBAL_LIBCPP17_OPTIONAL_INTERFACE) \
		|| !defined (LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL)
	#if defined (__has_include) && __has_include (<optional>) \
			&& (__cpp_lib_optional || !defined (__cpp_lib_optional))
		#if __cpp_lib_optional
			#if !defined (LBAL_LIBCPP17_OPTIONAL) \
					&& (__cpp_lib_optional >= 201603L)
				#define LBAL_LIBCPP17_OPTIONAL __cpp_lib_optional
			#endif

			#if !defined (LBAL_LIBCPP17_OPTIONAL_INTERFACE) \
					&& (__cpp_lib_optional >= 201606L)
				#define LBAL_LIBCPP17_OPTIONAL_INTERFACE __cpp_lib_optional
			#endif

			#if !defined (LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL) \
					&& (__cpp_lib_optional >= 201606L)
				#define LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL __cpp_lib_optional
			#endif
		#else
			#define LBAL_LIBCPP17_OPTIONAL 201603L
			#define LBAL_LIBCPP17_OPTIONAL_INTERFACE 201606L
			#define LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL 201606L
		#endif
	#endif
#elif LBAL_LIBCPP17_OPTIONAL || LBAL_LIBCPP17_OPTIONAL_INTERFACE \
		|| LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL
	#if defined (__has_include)
		#if !__has_include (<optional>)
			#undef LBAL_LIBCPP17_OPTIONAL
			#undef LBAL_LIBCPP17_OPTIONAL_INTERFACE
			#undef LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL
			#define LBAL_LIBCPP17_OPTIONAL 0L
			#define LBAL_LIBCPP17_OPTIONAL_INTERFACE 0L
			#define LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL 0L
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
	#endif
#endif	//	LBAL_LIBCPP17_PARALLEL_ALGORITHM


//	This is an aggregate that tracks two different SD-6 macros for the purpose
//	of establishing Standard compliance. There is no single corresponding SD-6
//	macro. Note that we do not track experimental versions of this.
#if !defined (LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS)
	#if LBAL_LIBCPP17_EXECUTION && LBAL_LIBCPP17_PARALLEL_ALGORITHM
		#define LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS 1L
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


#if !defined (LBAL_LIBCPP2A_CHRONO_CALENDAR)
	#if __cpp_lib_chrono >= 201803L
		#define LBAL_LIBCPP2A_CHRONO_CALENDAR __cpp_lib_launder
	#endif
#endif	//	LBAL_LIBCPP2A_CHRONO_CALENDAR


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


#if !defined (LBAL_LIBCPP2A_CONSTEXPR_ALGORITHMS)
	#if __cpp_lib_constexpr_algorithms
		#define LBAL_LIBCPP2A_CONSTEXPR_ALGORITHMS __cpp_lib_constexpr_algorithms
	#endif
#endif	//	LBAL_LIBCPP2A_CONSTEXPR_ALGORITHMS


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
	#endif
#endif	//	LBAL_LIBCPP2A_DESTROYING_DELETE


#if !defined (LBAL_LIBCPP2A_SHARED_PTR_ARRAYS)
	#if __cpp_lib_shared_ptr_arrays
		#define LBAL_LIBCPP2A_SHARED_PTR_ARRAYS __cpp_lib_shared_ptr_arrays
	#endif
#endif	//	LBAL_LIBCPP2A_SHARED_PTR_ARRAYS


#if !defined (LBAL_LIBCPP2A_ATOMIC_FLOAT)
	#if __cpp_lib_atomic_float
		#define LBAL_LIBCPP2A_ATOMIC_FLOAT __cpp_lib_atomic_float
	#endif
#endif	//	LBAL_LIBCPP2A_ATOMIC_FLOAT


//	This functionality lives in multiple pre-existing headers, and requires
//	either the SD-6 macro or an override to detect it; if no explicit override
//	is set and the SD-6 macro is unavailable, we default to 0.
#if !defined (LBAL_LIBCPP2A_LIST_REMOVE_RETURN_TYPE)
	#if __cpp_lib_list_remove_return_type
		#define LBAL_LIBCPP2A_LIST_REMOVE_RETURN_TYPE __cpp_lib_list_remove_return_type

	#endif
#endif	//	LBAL_LIBCPP2A_LIST_REMOVE_RETURN_TYPE


//	This functionality lives in <complex>, and requires either the SD-6 macro
//	or an override to detect it; if no explicit override is set and the SD-6
//	macro is unavailable, we default to 0.
#if !defined (LBAL_LIBCPP2A_MORE_CONSTEXPR_FOR_COMPLEX)
	#if __cpp_lib_constexpr_complex
		#define LBAL_LIBCPP2A_MORE_CONSTEXPR_FOR_COMPLEX __cpp_lib_constexpr_complex
	#endif
#endif	//	LBAL_LIBCPP2A_MORE_CONSTEXPR_FOR_COMPLEX


//	__FIXME__
//	This functionality lives in <bit>, but requires either the SD-6 macro or an
//	override to detect it; if no explicit override is set and the SD-6 macro is
//	unavailable, we default to 0.
#if !defined (LBAL_LIBCPP2A_BIT_CAST)
	#if defined (__has_include) && __has_include (<bit>) \
			&& __cpp_lib_bit_cast
		#define LBAL_LIBCPP2A_BIT_CAST __cpp_lib_bit_cast
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


#if !defined (LBAL_LIBCPP2A_CHRONO_CALENDAR)
	#if __cpp_lib_chrono >= 201803L
		#define LBAL_LIBCPP2A_CHRONO_CALENDAR __cpp_lib_launder
	#endif
#endif	//	LBAL_LIBCPP2A_CHRONO_CALENDAR


#if !defined (LBAL_LIBCPP2A_SPAN)
	#if defined (__has_include) && __has_include (<span>)
		#if __cpp_lib_span
			#define LBAL_LIBCPP2A_SPAN __cpp_lib_span
		#elif (LBAL_cpp_version > LBAL_CPP17_VERSION)
			//	__SEEME__ We only assume basic `std::span` suppport
			#define LBAL_LIBCPP2A_SPAN 201803L
		#endif
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
	#endif
#endif	//	LBAL_LIBCPP2A_STD_ATOMIC_REF


#if !defined (LBAL_LIBCPP2A_ENDIAN)
	#if __cpp_lib_endian
		#define LBAL_LIBCPP2A_ENDIAN __cpp_lib_endian
	#endif
#endif	//	LBAL_LIBCPP2A_ENDIAN


#if !defined (LBAL_LIBCPP2A_REMOVE_CVREF)
	#if __cpp_lib_remove_cvref
		#define LBAL_LIBCPP2A_REMOVE_CVREF __cpp_lib_remove_cvref
	#endif
#endif	//	LBAL_LIBCPP2A_REMOVE_CVREF


#if !defined (LBAL_LIBCPP2A_STARTS_ENDS_WITH)
	#if __cpp_lib_starts_ends_with
		#define LBAL_LIBCPP2A_STARTS_ENDS_WITH __cpp_lib_starts_ends_with
	#endif
#endif	//	LBAL_LIBCPP2A_STARTS_ENDS_WITH


#if !defined (LBAL_LIBCPP2A_SYNCBUF)
	#if defined (__has_include) && __has_include (<syncstream>) \
			&& (__cpp_lib_syncbuf || !defined (__cpp_lib_syncbuf))
		#if __cpp_lib_syncbuf
			#define LBAL_LIBCPP2A_SYNCBUF __cpp_lib_syncbuf
		#else
			#define LBAL_LIBCPP2A_SYNCBUF 201711L
		#endif
	#endif
#elif LBAL_LIBCPP2A_SYNCBUF
	#if defined (__has_include)
		#if !__has_include (<syncstream>)
			#undef LBAL_LIBCPP2A_SYNCBUF
			#define LBAL_LIBCPP2A_SYNCBUF 0L
			#warning "<syncstream> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPP2A_SYNCBUF"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#endif	//	LBAL_LIBCPP2A_SYNCBUF


#if !defined (LBAL_LIBCPP2A_THREE_WAY_COMPARISON)
	#if defined (__has_include) && __has_include (<compare>) \
			&& (__cpp_lib_three_way_comparison || !defined (__cpp_lib_three_way_comparison))
		#if __cpp_lib_three_way_comparison
			#define LBAL_LIBCPP2A_THREE_WAY_COMPARISON __cpp_lib_three_way_comparison
		#else
			//	__SEEME__ Value not yet assigned.
			#define LBAL_LIBCPP2A_THREE_WAY_COMPARISON 201711L
		#endif

	#endif
#elif LBAL_LIBCPP2A_THREE_WAY_COMPARISON
	#if defined (__has_include)
		#if !__has_include (<compare>)
			#undef LBAL_LIBCPP2A_THREE_WAY_COMPARISON
			#define LBAL_LIBCPP2A_THREE_WAY_COMPARISON 0L
			#warning "<compare> not found"
		#endif
	#else
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPP2A_THREE_WAY_COMPARISON"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#endif	//	LBAL_LIBCPP2A_THREE_WAY_COMPARISON


#if !defined (LBAL_LIBCPP2A_TYPE_IDENTITY)
	#if __cpp_lib_type_identity
		#define LBAL_LIBCPP2A_TYPE_IDENTITY __cpp_lib_type_identity
	#endif
#endif	//	LBAL_LIBCPP2A_TYPE_IDENTITY


#if !defined (LBAL_LIBCPP2A_TO_ADDRESS)
	#if __cpp_lib_to_address
		#define LBAL_LIBCPP2A_TO_ADDRESS __cpp_lib_to_address
	#endif
#endif	//	LBAL_LIBCPP2A_TO_ADDRESS


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
	#endif
#elif !LBAL_LIBCPPTS_OBSERVER_PTR
	#if !defined (LBAL_LIBCPPTS_OBSERVER_PTR_EXP)
		#define LBAL_LIBCPPTS_OBSERVER_PTR_EXP 0L
	#endif
#endif	//	LBAL_LIBCPPTS_OBSERVER_PTR

#if !defined (LBAL_LIBCPPTS_OBSERVER_PTR_EXP)
	#if __cpp_lib_experimental_observer_ptr
		#define LBAL_LIBCPPTS_OBSERVER_PTR_EXP __cpp_lib_experimental_observer_ptr
	#endif
#elif LBAL_LIBCPPTS_OBSERVER_PTR_EXP
	#if LBAL_LIBCPPTS_OBSERVER_PTR
		#undef LBAL_LIBCPPTS_OBSERVER_PTR_EXP
		#define LBAL_LIBCPPTS_OBSERVER_PTR_EXP 0L
		#warning "LBAL_LIBCPPTS_OBSERVER_PTR && LBAL_LIBCPPTS_OBSERVER_PTR_EXP"
	#endif
#endif	//	LBAL_LIBCPPTS_OBSERVER_PTR_EXP


/*------------------------------------------------------------------------------
	Implementation-specific Post-initialization
*/

#if LBAL_TARGET_STANDARD_LIBRARY_APPLE_LIBCPP
	#include <lucenaBAL/details/libraries/lbalStandardLibraryAppleLibCppPostInitialization.hpp>
#elif LBAL_TARGET_STANDARD_LIBRARY_LIBCPP
	#include <lucenaBAL/details/libraries/lbalStandardLibraryLibCppPostInitialization.hpp>
#elif LBAL_TARGET_STANDARD_LIBRARY_LIBSTDCPP
	#include <lucenaBAL/details/libraries/lbalStandardLibraryLibStdPostInitializationCpp.hpp>
#elif LBAL_TARGET_STANDARD_LIBRARY_MSVC
	#include <lucenaBAL/details/libraries/lbalStandardLibraryMSVCPostInitialization.hpp>
#else
	//	In the generic case, we do nothing here.
#endif
