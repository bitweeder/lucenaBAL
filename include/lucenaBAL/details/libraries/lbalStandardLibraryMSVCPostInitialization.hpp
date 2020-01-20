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
	//	C++14 Library Features
	#if LBAL_cpp_version > LBAL_CPP11_VERSION
		#if (_MSC_VER >= 1900)
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

			//	Technically, MSVS 2015.2, but the extended version numbers are
			//	inconsistent internationally, so we rely on our 2015.3+
			//	requirement.
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
		#endif	//	1900
	#endif	//	LBAL_CPP14_VERSION


	//	C++17 Library Features
	#if LBAL_cpp_version > LBAL_CPP14_VERSION
		#if (_MSC_VER >= 1911)
			#if !defined(LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE)
				#define LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE 201703L
			#endif	//	LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE
		#endif	//	1911

		#if (_MSC_VER >= 1912)
			#if !defined(LBAL_LIBCPP17_NODE_EXTRACT)
				#define LBAL_LIBCPP17_NODE_EXTRACT 201606L
			#endif	//	LBAL_LIBCPP17_NODE_EXTRACT
		#endif	//	1912

		#if (_MSC_VER >= 1914)
			#if !defined(LBAL_LIBCPP17_LAUNDER)
				#define LBAL_LIBCPP17_LAUNDER 201606L
			#endif	//	LBAL_LIBCPP17_LAUNDER

			#if !defined(LBAL_LIBCPP17_PARALLEL_ALGORITHM)
				#define LBAL_LIBCPP17_PARALLEL_ALGORITHM 201603L
			#endif	//	1914
		#endif	//	LBAL_LIBCPP17_PARALLEL_ALGORITHM
	#endif	//	LBAL_CPP17_VERSION


	//	C++20 Library Features
	#if LBAL_cpp_version > LBAL_CPP17_VERSION
	#endif	//	LBAL_CPP20_VERSION


	#if !defined(LBAL_LIBCPP17_TO_CHARS) \
			&& LBAL_LIBCPP17_TO_CHARS_INTEGER \
			&& LBAL_LIBCPP17_TO_CHARS_FP
		#define LBAL_LIBCPP17_TO_CHARS LBAL_LIBCPP17_TO_CHARS_FP
	#endif
#else
	#error "lbalStandardLibraryMSVCPostInitialization.hpp was directly included with the incorrect Standard Library implementation"
#endif
