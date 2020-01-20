/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalStandardLibraryLibStdCppPostInitialization.hpp”
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
	libstdc++ Standard Library

	__SEEME__ One source of aggravation in libstdc++ is that there is no simple
	way to figure out what version of the library you are using. `__GLIBCXX__`
	is a release date, which can be interleaved across versions of the library
	depending on whether there are minor releases and bug fixes. We are forced
	to use `__GNUC__` as a proxy, which is not totally unreasonable, as long as
	the user hasn’t done something pathological like using an old libstdc++
	implementation with a new compiler.
*/

#if LBAL_TARGET_STANDARD_LIBRARY_LIBSTDCPP
	//	C++14 Library Features
	#if LBAL_cpp_version > LBAL_CPP11_VERSION
		#if (__GNUC__ >= 5)
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
		#endif	//	5
	#endif	//	LBAL_CPP14_VERSION


	//	C++17 Library Features
	#if LBAL_cpp_version > LBAL_CPP14_VERSION
		#if (__GNUC__ >= 7)
			#if !defined(LBAL_LIBCPP17_LAUNDER)
				#define LBAL_LIBCPP17_LAUNDER 201606L
			#endif	//	LBAL_LIBCPP17_LAUNDER

			#if !defined(LBAL_LIBCPP17_NODE_EXTRACT)
				#define LBAL_LIBCPP17_NODE_EXTRACT 201606L
			#endif	//	LBAL_LIBCPP17_NODE_EXTRACT
		#endif	//	7
	#endif	//	LBAL_CPP17_VERSION


	//	C++20 Library Features
	#if LBAL_cpp_version > LBAL_CPP17_VERSION
		#if (__GNUC__ >= 8)
			#if !defined(LBAL_LIBCPP2A_STD_ENDIAN)
				#define LBAL_LIBCPP2A_STD_ENDIAN 201907L
			#endif	//	LBAL_LIBCPP2A_STD_ENDIAN

			#if !defined(LBAL_LIBCPP2A_TO_ADDRESS)
				#define LBAL_LIBCPP2A_TO_ADDRESS 201711L
			#endif	//	LBAL_LIBCPP2A_TO_ADDRESS
		#endif	//	8

		#if (__GNUC__ >= 9)
			#if !defined(LBAL_LIBCPP2A_REMOVE_CVREF)
				#define LBAL_LIBCPP2A_REMOVE_CVREF 201711
			#endif	//	LBAL_LIBCPP2A_REMOVE_CVREF
		#endif	//	9
	#endif	//	LBAL_CPP20_VERSION


	#if !defined(LBAL_LIBCPP17_TO_CHARS) \
			&& LBAL_LIBCPP17_TO_CHARS_INTEGER \
			&& LBAL_LIBCPP17_TO_CHARS_FP
		#define LBAL_LIBCPP17_TO_CHARS LBAL_LIBCPP17_TO_CHARS_FP
	#endif
#else
	#error "lbalStandardLibraryLibStdCppPostInitialization.hpp was directly included with the incorrect Standard Library implementation"
#endif
