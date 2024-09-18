/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalStandardLibraryLibCppPostInitialization.hpp”
	Copyright © 2019-2024 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/


#pragma once


//	lbal
#include <lucenaBAL/lbalConfig.hpp>
#include <lucenaBAL/details/lbalDetectStandardLibrary.hpp>
#include <lucenaBAL/details/lbalKnownVersions.hpp>


/*------------------------------------------------------------------------------
	libc++ Standard Library
*/

#if LBAL_TARGET_STANDARD_LIBRARY_LIBCPP
	//	C++14 Library Features (these are all supported in all Apple clangs)
	#if LBAL_cpp_version > LBAL_CPP11_VERSION
		#if !defined (LBAL_LIBCPP14_CHRONO_UDLS)
			#define LBAL_LIBCPP14_CHRONO_UDLS 201304L
		#endif	//	LBAL_LIBCPP14_CHRONO_UDLS

		#if !defined (LBAL_LIBCPP14_COMPLEX_UDLS)
			#define LBAL_LIBCPP14_COMPLEX_UDLS 201309L
		#endif	//	LBAL_LIBCPP14_COMPLEX_UDLS

		#if !defined (LBAL_LIBCPP14_EXCHANGE_FUNCTION)
			#define LBAL_LIBCPP14_EXCHANGE_FUNCTION 201304L
		#endif	//	LBAL_LIBCPP14_EXCHANGE_FUNCTION

		#if !defined (LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP)
			#define LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP 201304L
		#endif	//	LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP

		#if !defined (LBAL_LIBCPP14_INTEGER_SEQUENCE)
			#define LBAL_LIBCPP14_INTEGER_SEQUENCE 201304L
		#endif	//	LBAL_LIBCPP14_INTEGER_SEQUENCE

		#if !defined (LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE)
			#define LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE 201304L
		#endif	//	LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE

		#if !defined (LBAL_LIBCPP14_IS_FINAL)
			#define LBAL_LIBCPP14_IS_FINAL 201402L
		#endif	//	LBAL_LIBCPP14_IS_FINAL

		#if !defined (LBAL_LIBCPP14_IS_NULL_POINTER)
			#define LBAL_LIBCPP14_IS_NULL_POINTER 201309L
		#endif	//	LBAL_LIBCPP14_IS_NULL_POINTER

		#if !defined (LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR)
			#define LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR 201402L
		#endif	//	LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR

		#if !defined (LBAL_LIBCPP14_MAKE_UNIQUE)
			#define LBAL_LIBCPP14_MAKE_UNIQUE 201304L
		#endif	//	LBAL_LIBCPP14_MAKE_UNIQUE

		#if !defined (LBAL_LIBCPP14_NULL_ITERATORS)
			#define LBAL_LIBCPP14_NULL_ITERATORS 201304L
		#endif	//	LBAL_LIBCPP14_NULL_ITERATORS

		#if !defined (LBAL_LIBCPP14_QUOTED_STRING_IO)
			#define LBAL_LIBCPP14_QUOTED_STRING_IO 201304L
		#endif	//	LBAL_LIBCPP14_QUOTED_STRING_IO

		#if !defined (LBAL_LIBCPP14_RESULT_OF_SFINAE)
			#define LBAL_LIBCPP14_RESULT_OF_SFINAE 201210L
		#endif	//	LBAL_LIBCPP14_RESULT_OF_SFINAE

		#if !defined (LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS)
			#define LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS 201304L
		#endif	//	LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS

		#if !defined (LBAL_LIBCPP14_SHARED_TIMED_MUTEX)
			#define LBAL_LIBCPP14_SHARED_TIMED_MUTEX 201402L
		#endif	//	LBAL_LIBCPP14_SHARED_TIMED_MUTEX

		#if !defined (LBAL_LIBCPP14_STRING_UDLS)
			#define LBAL_LIBCPP14_STRING_UDLS 201304L
		#endif	//	LBAL_LIBCPP14_STRING_UDLS

		#if !defined (LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES)
			#define LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES 201304L
		#endif	//	LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES

		#if !defined (LBAL_LIBCPP14_TRANSPARENT_OPERATORS)
			#define LBAL_LIBCPP14_TRANSPARENT_OPERATORS 201210L
		#endif	//	LBAL_LIBCPP14_TRANSPARENT_OPERATORS

		#if !defined (LBAL_LIBCPP14_TUPLE_ELEMENT_T)
			#define LBAL_LIBCPP14_TUPLE_ELEMENT_T 201402L
		#endif	//	LBAL_LIBCPP14_TUPLE_ELEMENT_T

		#if !defined (LBAL_LIBCPP14_TUPLES_BY_TYPE)
			#define LBAL_LIBCPP14_TUPLES_BY_TYPE 201304L
		#endif	//	LBAL_LIBCPP14_TUPLES_BY_TYPE
	#endif	//	LBAL_CPP14_VERSION


	//	C++17 Library Features
	//	__SEEME__ Many of the features that only recently received SD-6 macros
	//	have not been fully validated, yet. However, features we know not to be
	//	available have been stripped out; similarly, we don’t contradict
	//	`<version>` when it explicitly says a feature is unsupported, though we
	//	occasionally contradict it when it claims support that isn’t there
	//	(e.g., for `__cpp_lib_hardware_interference_size`). If there are
	//	inaccuracies, they most likely affect clangs older than version 8.
	#if LBAL_cpp_version > LBAL_CPP14_VERSION
		#if !defined (LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR)
			#define LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR 201603L
		#endif	//	LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR

		#if !defined (LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL)
			#define LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL 201411L
		#endif	//	LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL

		#if !defined (LBAL_LIBCPP17_ANY)
			#define LBAL_LIBCPP17_ANY 201603L
		#endif	//	LBAL_LIBCPP17_ANY

		#if !defined (LBAL_LIBCPP17_ANY_INTERFACE)
			#define LBAL_LIBCPP17_ANY_INTERFACE 201606L
		#endif	//	LBAL_LIBCPP17_ANY_INTERFACE

		#if !defined (LBAL_LIBCPP17_APPLY)
			#define LBAL_LIBCPP17_APPLY 201603L
		#endif	//	LBAL_LIBCPP17_APPLY

		#if !defined (LBAL_LIBCPP17_ARRAY_CONSTEXPR)
			#define LBAL_LIBCPP17_ARRAY_CONSTEXPR 201603L
		#endif	//	LBAL_LIBCPP17_ARRAY_CONSTEXPR

		#if !defined (LBAL_LIBCPP17_AS_CONST)
			#define LBAL_LIBCPP17_AS_CONST 201510L
		#endif	//	LBAL_LIBCPP17_AS_CONST

		#if !defined (LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE)
			#define LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE 201603L
		#endif	//	LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE

		#if !defined (LBAL_LIBCPP17_BOOL_CONSTANT)
			#define LBAL_LIBCPP17_BOOL_CONSTANT 201505L
		#endif	//	LBAL_LIBCPP17_BOOL_CONSTANT

		#if !defined (LBAL_LIBCPP17_BYTE)
			#define LBAL_LIBCPP17_BYTE 201603L
		#endif	//	LBAL_LIBCPP17_BYTE

		#if !defined (LBAL_LIBCPP17_CHRONO)
			#define LBAL_LIBCPP17_CHRONO 201510L
		#endif	//	LBAL_LIBCPP17_CHRONO

		#if !defined (LBAL_LIBCPP17_CHRONO_CONSTEXPR)
			#define LBAL_LIBCPP17_CHRONO_CONSTEXPR 201611L
		#endif	//	LBAL_LIBCPP17_CHRONO_CONSTEXPR

		#if !defined (LBAL_LIBCPP17_CLAMP)
			#define LBAL_LIBCPP17_CLAMP 201603L
		#endif	//	LBAL_LIBCPP17_CLAMP

		#if !defined (LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS)
			#define LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS 201603L
		#endif	//	LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS

		#if !defined (LBAL_LIBCPP17_GCD_LCM)
			#define LBAL_LIBCPP17_GCD_LCM 201606L
		#endif	//	LBAL_LIBCPP17_GCD_LCM

		#if !defined (LBAL_LIBCPP17_HYPOT)
			#define LBAL_LIBCPP17_HYPOT 201603L
		#endif	//	LBAL_LIBCPP17_HYPOT

		#if !defined (LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS)
			#define LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS 201505L
		#endif	//	LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS

		#if !defined (LBAL_LIBCPP17_INVOKE)
			#define LBAL_LIBCPP17_INVOKE 201411L
		#endif	//	LBAL_LIBCPP17_INVOKE

		#if !defined (LBAL_LIBCPP17_IS_AGGREGATE)
			#define LBAL_LIBCPP17_IS_AGGREGATE 201703L
		#endif	//	LBAL_LIBCPP17_IS_AGGREGATE

		#if !defined (LBAL_LIBCPP17_IS_INVOCABLE)
			#define LBAL_LIBCPP17_IS_INVOCABLE 201703L
		#endif	//	LBAL_LIBCPP17_IS_INVOCABLE

		#if !defined (LBAL_LIBCPP17_IS_SWAPPABLE)
			#define LBAL_LIBCPP17_IS_SWAPPABLE 201603L
		#endif	//	LBAL_LIBCPP17_IS_SWAPPABLE

		#if !defined (LBAL_LIBCPP17_LOGICAL_TRAITS)
			#define LBAL_LIBCPP17_LOGICAL_TRAITS 201510L
		#endif	//	LBAL_LIBCPP17_LOGICAL_TRAITS

		#if !defined (LBAL_LIBCPP17_MAKE_FROM_TUPLE)
			#define LBAL_LIBCPP17_MAKE_FROM_TUPLE 201606L
		#endif	//	LBAL_LIBCPP17_MAKE_FROM_TUPLE

		#if !defined (LBAL_LIBCPP17_MAP_TRY_EMPLACE)
			#define LBAL_LIBCPP17_MAP_TRY_EMPLACE 201411L
		#endif	//	LBAL_LIBCPP17_MAP_TRY_EMPLACE

		#if !defined (LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS)
			#define LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS 201411L
		#endif	//	LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS

		#if !defined (LBAL_LIBCPP17_NOT_FN)
			#define LBAL_LIBCPP17_NOT_FN 201603L
		#endif	//	LBAL_LIBCPP17_NOT_FN

		#if !defined (LBAL_LIBCPP17_OPTIONAL)
			#define LBAL_LIBCPP17_OPTIONAL 201603L
		#endif	//	LBAL_LIBCPP17_OPTIONAL

		#if !defined (LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL)
			#define LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL 201606L
		#endif	//	LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL

		#if !defined (LBAL_LIBCPP17_OPTIONAL_INTERFACE)
			#define LBAL_LIBCPP17_OPTIONAL_INTERFACE 201606L
		#endif	//	LBAL_LIBCPP17_OPTIONAL_INTERFACE

		#if !defined (LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS)
			#define LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS 201606L
		#endif	//	LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS

		#if !defined (LBAL_LIBCPP17_SAMPLE)
			#define LBAL_LIBCPP17_SAMPLE 201603L
		#endif	//	LBAL_LIBCPP17_SAMPLE

		#if !defined (LBAL_LIBCPP17_SCOPED_LOCK)
			#define LBAL_LIBCPP17_SCOPED_LOCK 201703L
		#endif	//	LBAL_LIBCPP17_SCOPED_LOCK

		#if !defined (LBAL_LIBCPP17_SHARED_MUTEX)
			#define LBAL_LIBCPP17_SHARED_MUTEX 201505L
		#endif	//	LBAL_LIBCPP17_SHARED_MUTEX

		#if !defined (LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE)
			#define LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE 201606L
		#endif	//	LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE

		#if !defined (LBAL_LIBCPP17_STRING_VIEW)
			#define LBAL_LIBCPP17_STRING_VIEW 201603L
		#endif	//	LBAL_LIBCPP17_STRING_VIEW

		#if !defined (LBAL_LIBCPP17_STRING_VIEW_INTERFACE)
			#define LBAL_LIBCPP17_STRING_VIEW_INTERFACE 201606L
		#endif	//	LBAL_LIBCPP17_STRING_VIEW_INTERFACE

		#if !defined (LBAL_LIBCPP17_TRANSPARENT_OPERATORS)
			#define LBAL_LIBCPP17_TRANSPARENT_OPERATORS 201510L
		#endif	//	LBAL_LIBCPP17_TRANSPARENT_OPERATORS

		#if !defined (LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES)
			#define LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES 201510L
		#endif	//	LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES

		#if !defined (LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS)
			#define LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS 201411L
		#endif	//	LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS

		#if !defined (LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE)
			#define LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE 201411L
		#endif	//	LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE

		#if !defined (LBAL_LIBCPP17_VARIANT)
			#define LBAL_LIBCPP17_VARIANT 201606L
		#endif	//	LBAL_LIBCPP17_VARIANT

		#if !defined (LBAL_LIBCPP17_VOID_T)
			#define LBAL_LIBCPP17_VOID_T 201411L
		#endif	//	LBAL_LIBCPP17_VOID_T

		#if (_LIBCPP_VERSION >= 6000)
			#if !defined (LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS)
				#define LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS 201606L
			#endif	//	LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS

			#if !defined(LBAL_LIBCPP17_LAUNDER)
				#define LBAL_LIBCPP17_LAUNDER 201606L
			#endif	//	LBAL_LIBCPP17_LAUNDER
		#endif	//	6000

		#if (_LIBCPP_VERSION >= 7000)
			#if !defined (LBAL_LIBCPP17_FILESYSTEM)
				#define LBAL_LIBCPP17_FILESYSTEM 201603L

				#if LBAL_LIBCPP17_FILESYSTEM_EXP
					#undef LBAL_LIBCPP17_FILESYSTEM_EXP
					#define LBAL_LIBCPP17_FILESYSTEM_EXP 0
				#endif
			#endif	//	LBAL_LIBCPP17_FILESYSTEM

			#if !defined (LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED)
				#define LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED 201606L
			#endif	//	LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED

			#if !defined (LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING)
				#define LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING 201703L
			#endif	//	LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING
		#endif	//	76000

		#if (_LIBCPP_VERSION >= 8000)
			#if !defined (LBAL_LIBCPP17_NODE_EXTRACT)
				#define LBAL_LIBCPP17_NODE_EXTRACT 201606L
			#endif	//	LBAL_LIBCPP17_NODE_EXTRACT
		#endif	//	76000
	#endif	//	LBAL_CPP17_VERSION


	//	C++20 Library Features
	//	These overrides are not exhaustive; we focus specifically on features
	//	which are known to have valid implementations, but missing or incorrect
	//	SD-6 values in `<version>` for at least some iterations of libc++.
	#if LBAL_cpp_version > LBAL_CPP17_VERSION
		#if (_LIBCPP_VERSION >= 6000)
			#if !defined(LBAL_LIBCPP20_REMOVE_CVREF)
				#define LBAL_LIBCPP20_REMOVE_CVREF 201711
			#endif	//	LBAL_LIBCPP20_REMOVE_CVREF

			#if !defined(LBAL_LIBCPP20_STARTS_ENDS_WITH)
				#define LBAL_LIBCPP20_STARTS_ENDS_WITH 201711L
			#endif	//	LBAL_LIBCPP20_STARTS_ENDS_WITH

			#if !defined(LBAL_LIBCPP20_TO_ADDRESS)
				#define LBAL_LIBCPP20_TO_ADDRESS 201711L
			#endif	//	LBAL_LIBCPP20_TO_ADDRESS
		#endif	//	6000

		#if (_LIBCPP_VERSION >= 7000)
			#if !defined(LBAL_LIBCPP20_STD_ENDIAN)
				#define LBAL_LIBCPP20_STD_ENDIAN 201907L
			#endif	//	LBAL_LIBCPP20_STD_ENDIAN

			#if !defined(LBAL_LIBCPP20_CHRONO_CALENDAR)
				#define LBAL_LIBCPP20_CHRONO_CALENDAR 201803L
			#endif	//	LBAL_LIBCPP20_CHRONO_CALENDAR
		#endif	//	7000

		#if (_LIBCPP_VERSION >= 8000)
			#if !defined(LBAL_LIBCPP20_TYPE_IDENTITY)
				#define LBAL_LIBCPP20_TYPE_IDENTITY 201806L
			#endif	//	LBAL_LIBCPP20_TYPE_IDENTITY
		#endif	//	8000
	#endif	//	LBAL_CPP20_VERSION


	#if !defined(LBAL_LIBCPP17_TO_CHARS) \
			&& LBAL_LIBCPP17_TO_CHARS_INTEGER \
			&& LBAL_LIBCPP17_TO_CHARS_FP
		#define LBAL_LIBCPP17_TO_CHARS LBAL_LIBCPP17_TO_CHARS_FP
	#endif
#else
	#error "lbalStandardLibraryLibCppPostInitialization.hpp was directly included with the incorrect Standard Library implementation"
#endif
