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
#include <lucenaBAL/details/lbalKnownVersions.hpp>


/*------------------------------------------------------------------------------
	Implementation-specific Initialization

	Make sure any SD-6 macros that are available are defined. As part of this,
	each of the following headers will attempt to load `<version>` if it is
	available, otherwise falling back to simply de facto initializing the
	Standard Library implementation if it is not.

	Additionally, these headers address false positives, taking advantage of
	specific implementation knowledge to prevent features from being marked as
	“available” when they really shouldn’t be.
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
	//	found, but otherewise make no special attempt to initialize the actual
	//	SD-6 macros.
	#include <lucenaBAL/details/lbalVersionSetup.hpp>
#endif


/*------------------------------------------------------------------------------
	SD-6 Macro Tests

	These tests are platform-agnostic, relying almost exclusively on SD-6
	macros. Checks that would have generated a false positive should have been
	handled previously, effectively overriding any assignments we would
	otherwise have made here. As a general rule, if an SD-6 macro is defined,
	unless we have a very specific reason to do otherwise, we assume the
	feature is available. In particular, even if the current C++ dialect might
	suggest the feature isn’t available (e.g., a C++20 feature being made
	available in C++17), we assume that whatever mechanism handled macro
	initialization was written by someone who knew what they were doing.

	__SEEME__ It’s possible that an implementation of a pre-C++20 Standard will
	define SD-6 macros in the relevant Standard Library headers themselves, but
	this would be arguably self-defeating. We don’t bother dealing with that
	particular pathology here; instead reying on the post-initialization
	headers to catch false negatives.

	__APIME__ Generally, we explicitly disallow the use of the experimental
	version of a given feature if the final version is also available. This is
	partly authoritarian, and partly because some implementations have been
	known to keep broken experimental headers around after a feature is
	finalized rather than update them or simply retire them. This behavior can
	be overridden in the implementation headers.
*/

//	C++14 features.

#if !defined (LBAL_LIBCPP14_CHRONO_UDLS)
	#if __cpp_lib_chrono_udls >= 201304L
		#define LBAL_LIBCPP14_CHRONO_UDLS __cpp_lib_chrono_udls
	#endif
#endif	//	LBAL_LIBCPP14_CHRONO_UDLS

#if !defined (LBAL_LIBCPP14_COMPLEX_UDLS)
	#if __cpp_lib_complex_udls >= 201309L
		#define LBAL_LIBCPP14_COMPLEX_UDLS __cpp_lib_complex_udls
	#endif
#endif	//	LBAL_LIBCPP14_COMPLEX_UDLS

#if !defined (LBAL_LIBCPP14_EXCHANGE_FUNCTION)
	#if __cpp_lib_exchange_function >= 201304L
		#define LBAL_LIBCPP14_EXCHANGE_FUNCTION __cpp_lib_exchange_function
	#endif
#endif	//	LBAL_LIBCPP14_EXCHANGE_FUNCTION

#if !defined (LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP)
	#if __cpp_lib_generic_associative_lookup >= 201304L
		#define LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP \
				__cpp_lib_generic_associative_lookup
	#endif
#endif	//	LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP

#if !defined (LBAL_LIBCPP14_INTEGER_SEQUENCE)
	#if __cpp_lib_integer_sequence >= 201304L
		#define LBAL_LIBCPP14_INTEGER_SEQUENCE __cpp_lib_integer_sequence
	#endif
#endif	//	LBAL_LIBCPP14_INTEGER_SEQUENCE

#if !defined (LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE)
	#if __cpp_lib_integral_constant_callable >= 201304L
		#define LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE \
				__cpp_lib_integral_constant_callable
	#endif
#endif	//	LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE

#if !defined (LBAL_LIBCPP14_IS_FINAL)
	#if __cpp_lib_is_final >= 201402L
		#define LBAL_LIBCPP14_IS_FINAL __cpp_lib_is_final
	#endif
#endif	//	LBAL_LIBCPP14_IS_FINAL

#if !defined (LBAL_LIBCPP14_IS_NULL_POINTER)
	#if __cpp_lib_is_null_pointer >= 201309L
		#define LBAL_LIBCPP14_IS_NULL_POINTER __cpp_lib_is_null_pointer
	#endif
#endif	//	LBAL_LIBCPP14_IS_NULL_POINTER

#if !defined (LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR)
	#if __cpp_lib_make_reverse_iterator >= [201402L
		#define LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR \
				__cpp_lib_make_reverse_iterator
	#endif
#endif	//	LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR

#if !defined (LBAL_LIBCPP14_MAKE_UNIQUE)
	#if __cpp_lib_make_unique >= 201304L
		#define LBAL_LIBCPP14_MAKE_UNIQUE __cpp_lib_make_unique
	#endif
#endif	//	LBAL_LIBCPP14_MAKE_UNIQUE

#if !defined (LBAL_LIBCPP14_NULL_ITERATORS)
	#if __cpp_lib_null_iterators >= 201304L
		#define LBAL_LIBCPP14_NULL_ITERATORS __cpp_lib_null_iterators
	#endif
#endif	//	LBAL_LIBCPP14_NULL_ITERATORS

#if !defined (LBAL_LIBCPP14_QUOTED_STRING_IO)
	#if __cpp_lib_quoted_string_io >= 201304L
		#define LBAL_LIBCPP14_QUOTED_STRING_IO __cpp_lib_quoted_string_io
	#endif
#endif	//	LBAL_LIBCPP14_QUOTED_STRING_IO

#if !defined (LBAL_LIBCPP14_RESULT_OF_SFINAE)
	#if __cpp_lib_result_of_sfinae >= 201210L
		#define LBAL_LIBCPP14_RESULT_OF_SFINAE __cpp_lib_result_of_sfinae
	#endif
#endif	//	LBAL_LIBCPP14_RESULT_OF_SFINAE

#if !defined (LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS)
	#if __cpp_lib_robust_nonmodifying_seq_ops >= 201304L
		#define LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS \
				__cpp_lib_robust_nonmodifying_seq_ops
	#endif
#endif	//	LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS

#if !defined (LBAL_LIBCPP14_SHARED_TIMED_MUTEX)
	#if __cpp_lib_shared_timed_mutex >= 201402L
		#define LBAL_LIBCPP14_SHARED_TIMED_MUTEX __cpp_lib_shared_timed_mutex
	#endif
#endif	//	LBAL_LIBCPP14_SHARED_TIMED_MUTEX

#if !defined (LBAL_LIBCPP14_STRING_UDLS)
	#if __cpp_lib_string_udls >= 201304L
		#define LBAL_LIBCPP14_STRING_UDLS __cpp_lib_string_udls
	#endif
#endif	//	LBAL_LIBCPP14_STRING_UDLS

#if !defined (LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES)
	#if __cpp_lib_transformation_trait_aliases >= 201304L
		#define LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES \
				__cpp_lib_transformation_trait_aliases
	#endif
#endif	//	LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES

#if !defined (LBAL_LIBCPP14_TRANSPARENT_OPERATORS)
	#if __cpp_lib_transparent_operators >= 201210L
		#define LBAL_LIBCPP14_TRANSPARENT_OPERATORS \
				__cpp_lib_transparent_operators
	#endif
#endif	//	LBAL_LIBCPP14_TRANSPARENT_OPERATORS

#if !defined (LBAL_LIBCPP14_TUPLE_ELEMENT_T)
	#if __cpp_lib_tuple_element_t >= 201402L
		#define LBAL_LIBCPP14_TUPLE_ELEMENT_T __cpp_lib_tuple_element_t
	#endif
#endif	//	LBAL_LIBCPP14_TUPLE_ELEMENT_T

#if !defined (LBAL_LIBCPP14_TUPLES_BY_TYPE)
	#if __cpp_lib_tuples_by_type >= 201304L
		#define LBAL_LIBCPP14_TUPLES_BY_TYPE __cpp_lib_tuples_by_type
	#endif
#endif	//	LBAL_LIBCPP14_TUPLES_BY_TYPE


//	C++17 features.

#if !defined (LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR)
	#if __cpp_lib_addressof_constexpr >= 201603L
		#define LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR __cpp_lib_addressof_constexpr
	#endif
#endif	//	LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR

#if !defined (LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL)
	#if __cpp_lib_allocator_traits_is_always_equal >= 201411L
		#define LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL \
				__cpp_lib_allocator_traits_is_always_equal
	#endif
#endif	//	LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL

//	Note that we do not track experimental versions of this.
#if !defined (LBAL_LIBCPP17_ANY)
	#if __cpp_lib_any >= 201603L
		#define LBAL_LIBCPP17_ANY __cpp_lib_any
	#endif
#endif	//	LBAL_LIBCPP17_ANY

#if !defined (LBAL_LIBCPP17_ANY_INTERFACE)
	#if __cpp_lib_any >= 201606L
		#define LBAL_LIBCPP17_ANY_INTERFACE __cpp_lib_any
	#endif
#endif	//	LBAL_LIBCPP17_ANY_INTERFACE

#if !defined (LBAL_LIBCPP17_APPLY)
	#if __cpp_lib_apply >= 201603L
		#define LBAL_LIBCPP17_APPLY __cpp_lib_apply
	#endif
#endif	//	LBAL_LIBCPP17_APPLY

#if !defined (LBAL_LIBCPP17_ARRAY_CONSTEXPR)
	#if __cpp_lib_array_constexpr >= 201603L
		#define LBAL_LIBCPP17_ARRAY_CONSTEXPR __cpp_lib_array_constexpr
	#endif
#endif	//	LBAL_LIBCPP17_ARRAY_CONSTEXPR

#if !defined (LBAL_LIBCPP17_AS_CONST)
	#if __cpp_lib_as_const >= 201510L
		#define LBAL_LIBCPP17_AS_CONST __cpp_lib_as_const
	#endif
#endif	//	LBAL_LIBCPP17_AS_CONST

#if !defined (LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE)
	#if __cpp_lib_atomic_is_always_lock_free >= 201603L
		#define LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE \
				__cpp_lib_atomic_is_always_lock_free
	#endif
#endif	//	LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE

#if !defined (LBAL_LIBCPP17_BOOL_CONSTANT)
	#if __cpp_lib_bool_constant >= 201505L
		#define LBAL_LIBCPP17_BOOL_CONSTANT __cpp_lib_bool_constant
	#endif
#endif	//	LBAL_LIBCPP17_BOOL_CONSTANT

#if !defined (LBAL_LIBCPP17_BOYER_MOORE_SEARCHER)
	#if __cpp_lib_boyer_moore_searcher >= 201603L
		#define LBAL_LIBCPP17_BOYER_MOORE_SEARCHER \
				__cpp_lib_boyer_moore_searcher
	#endif
#endif	//	LBAL_LIBCPP17_BOYER_MOORE_SEARCHER

#if !defined (LBAL_LIBCPP17_BYTE)
	#if __cpp_lib_byte >= 201603L
		#define LBAL_LIBCPP17_BYTE __cpp_lib_byte
	#endif
#endif	//	LBAL_LIBCPP17_BYTE

#if !defined (LBAL_LIBCPP17_CHRONO)
	#if __cpp_lib_chrono >= 201510L
		#define LBAL_LIBCPP17_CHRONO __cpp_lib_chrono
	#endif
#endif	//	LBAL_LIBCPP17_CHRONO

#if !defined (LBAL_LIBCPP17_CHRONO_CONSTEXPR)
	#if __cpp_lib_chrono >= 201611L
		#define LBAL_LIBCPP17_CHRONO_CONSTEXPR __cpp_lib_chrono
	#endif
#endif	//	LBAL_LIBCPP17_CHRONO_CONSTEXPR

#if !defined (LBAL_LIBCPP17_CLAMP)
	#if __cpp_lib_clamp >= 201603L
		#define LBAL_LIBCPP17_CLAMP __cpp_lib_clamp
	#endif
#endif	//	LBAL_LIBCPP17_CLAMP

#if !defined (LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS)
	#if __cpp_lib_enable_shared_from_this >= 201603L
		#define LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS \
				__cpp_lib_enable_shared_from_this
	#endif
#endif	//	LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS

//	Use LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS to detect full
//	compliance with the feature; this only detects whether a key header is
//	implemented. Note that we do not track experimental versions of this.
#if !defined (LBAL_LIBCPP17_EXECUTION)
	#if __cpp_lib_execution >= 201603L
		#define LBAL_LIBCPP17_EXECUTION __cpp_lib_execution
	#endif
#endif	//	LBAL_LIBCPP17_EXECUTION

#if !defined (LBAL_LIBCPP17_FILESYSTEM)
	#if __cpp_lib_filesystem >= 201603L
		#define LBAL_LIBCPP17_FILESYSTEM __cpp_lib_filesystem
		#define LBAL_LIBCPP17_FILESYSTEM_EXP 0
	#endif
#endif	//	LBAL_LIBCPP17_FILESYSTEM

#if !defined (LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED)
	#if __cpp_lib_filesystem >= 201606L
		#define LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED __cpp_lib_filesystem
	#endif
#endif	//	LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED

#if !defined (LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING)
	#if __cpp_lib_filesystem >= 201703L
		#define LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING \
				__cpp_lib_filesystem
	#endif
#endif	//	LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING

#if !defined (LBAL_LIBCPP17_FILESYSTEM_EXP)
	#if __cpp_lib_filesystem_exp >= 201603L
		#define LBAL_LIBCPP17_FILESYSTEM_EXP __cpp_lib_filesystem_exp
	#endif
#endif	//	LBAL_LIBCPP17_FILESYSTEM_EXP

#if !defined (LBAL_LIBCPP17_GCD_LCM)
	#if __cpp_lib_gcd_lcm >= 201606L
		#define LBAL_LIBCPP17_GCD_LCM __cpp_lib_gcd_lcm
	#endif
#endif	//	LBAL_LIBCPP17_GCD_LCM

#if !defined (LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE)
	#if __cpp_lib_hardware_interference_size >= 201703L
		#define LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE \
				__cpp_lib_hardware_interference_size
	#endif
#endif	//	LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE

#if !defined (LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS)
	#if __cpp_lib_has_unique_object_representations >= 201606L
		#define LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS \
				__cpp_lib_has_unique_object_representations
	#endif
#endif	//	LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS

#if !defined (LBAL_LIBCPP17_HYPOT)
	#if __cpp_lib_hypot >= 201603L
		#define LBAL_LIBCPP17_HYPOT __cpp_lib_hypot
	#endif
#endif	//	LBAL_LIBCPP17_HYPOT

#if !defined (LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS)
	#if __cpp_lib_incomplete_container_elements >= 201505L
		#define LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS \
				__cpp_lib_incomplete_container_elements
	#endif
#endif	//	LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS

#if !defined (LBAL_LIBCPP17_INVOKE)
	#if __cpp_lib_invoke >= 201411L
		#define LBAL_LIBCPP17_INVOKE __cpp_lib_invoke
	#endif
#endif	//	LBAL_LIBCPP17_INVOKE

#if !defined (LBAL_LIBCPP17_IS_AGGREGATE)
	#if __cpp_lib_is_aggregate >= 201703L
		#define LBAL_LIBCPP17_IS_AGGREGATE __cpp_lib_is_aggregate
	#endif
#endif	//	LBAL_LIBCPP17_IS_AGGREGATE

#if !defined (LBAL_LIBCPP17_IS_INVOCABLE)
	#if __cpp_lib_is_invocable >= 201703L
		#define LBAL_LIBCPP17_IS_INVOCABLE __cpp_lib_is_invocable
	#endif
#endif	//	LBAL_LIBCPP17_IS_INVOCABLE

#if !defined (LBAL_LIBCPP17_IS_SWAPPABLE)
	#if __cpp_lib_is_swappable >= 201603L
		#define LBAL_LIBCPP17_IS_SWAPPABLE __cpp_lib_is_swappable
	#endif
#endif	//	LBAL_LIBCPP17_IS_SWAPPABLE

#if !defined (LBAL_LIBCPP17_LAUNDER)
	#if __cpp_lib_launder >= 201606L
		#define LBAL_LIBCPP17_LAUNDER __cpp_lib_launder
	#endif
#endif	//	LBAL_LIBCPP17_LAUNDER

#if !defined (LBAL_LIBCPP17_LOGICAL_TRAITS)
	#if __cpp_lib_logical_traits >= 201510L
		#define LBAL_LIBCPP17_LOGICAL_TRAITS __cpp_lib_logical_traits
	#endif
#endif	//	LBAL_LIBCPP17_LOGICAL_TRAITS

#if !defined (LBAL_LIBCPP17_MAKE_FROM_TUPLE)
	#if __cpp_lib_make_from_tuple >= 201606L
		#define LBAL_LIBCPP17_MAKE_FROM_TUPLE __cpp_lib_make_from_tuple
	#endif
#endif	//	LBAL_LIBCPP17_MAKE_FROM_TUPLE

#if !defined (LBAL_LIBCPP17_MAP_TRY_EMPLACE)
	#if __cpp_lib_map_try_emplace >= 201411L
		#define LBAL_LIBCPP17_MAP_TRY_EMPLACE __cpp_lib_map_try_emplace
	#endif
#endif	//	LBAL_LIBCPP17_MAP_TRY_EMPLACE

#if !defined (LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS)
	#if __cpp_lib_math_special_functions >= 201603L
		#define LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS \
				__cpp_lib_math_special_functions
	#endif
#endif	//	LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS

#if !defined (LBAL_LIBCPP17_MEMORY_RESOURCE)
	#if __cpp_lib_memory_resource >= 201603L
		#define LBAL_LIBCPP17_MEMORY_RESOURCE __cpp_lib_memory_resource
	#endif
#endif	//	LBAL_LIBCPP17_MEMORY_RESOURCE

#if !defined (LBAL_LIBCPP17_NODE_EXTRACT)
	#if __cpp_lib_node_extract >= 201606L
		#define LBAL_LIBCPP17_NODE_EXTRACT __cpp_lib_node_extract
	#endif
#endif	//	LBAL_LIBCPP17_NODE_EXTRACT

#if !defined (LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS)
	#if __cpp_lib_nonmember_container_access >= 201411L
		#define LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS \
				__cpp_lib_nonmember_container_access
	#endif
#endif	//	LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS

#if !defined (LBAL_LIBCPP17_NOT_FN)
	#if __cpp_lib_not_fn >= 201603L
		#define LBAL_LIBCPP17_NOT_FN __cpp_lib_not_fn
	#endif
#endif	//	LBAL_LIBCPP17_NOT_FN

//	Note that we do not track experimental versions of this.
#if !defined (LBAL_LIBCPP17_OPTIONAL)
	#if __cpp_lib_optional >= 201603L
		#define LBAL_LIBCPP17_OPTIONAL __cpp_lib_optional
	#endif
#endif	//	LBAL_LIBCPP17_OPTIONAL

#if !defined (LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL)
	#if __cpp_lib_optional >= 201606L
		#define LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL __cpp_lib_optional
	#endif
#endif	//	LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL

#if !defined (LBAL_LIBCPP17_OPTIONAL_INTERFACE)
	#if __cpp_lib_optional >= 201606L
		#define LBAL_LIBCPP17_OPTIONAL_INTERFACE __cpp_lib_optional
	#endif
#endif	//	LBAL_LIBCPP17_OPTIONAL_INTERFACE

//	Use LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS to detect full
//	compliance with the feature; this only detects whether the requisite
//	algorithms have been implemented. Note that as this functionality lives in
//	multiple pre-existing std headers, so we have to rely on either the SD-6
//	macro or an override to detect it; without these, we default to 0. Note
//	that we do not track experimental versions of this.
#if !defined (LBAL_LIBCPP17_PARALLEL_ALGORITHM)
	#if __cpp_lib_parallel_algorithm >= 201603L
		#define LBAL_LIBCPP17_PARALLEL_ALGORITHM __cpp_lib_parallel_algorithm
	#endif
#endif	//	LBAL_LIBCPP17_PARALLEL_ALGORITHM

#if !defined (LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS)
	#if __cpp_lib_raw_memory_algorithms >= 201606L
		#define LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS \
				__cpp_lib_raw_memory_algorithms
	#endif
#endif	//	LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS

#if !defined (LBAL_LIBCPP17_SAMPLE)
	#if __cpp_lib_sample >= 201603L
		#define LBAL_LIBCPP17_SAMPLE __cpp_lib_sample
	#endif
#endif	//	LBAL_LIBCPP17_SAMPLE

#if !defined (LBAL_LIBCPP17_SCOPED_LOCK)
	#if __cpp_lib_scoped_lock >= 201703L
		#define LBAL_LIBCPP17_SCOPED_LOCK __cpp_lib_scoped_lock
	#endif
#endif	//	LBAL_LIBCPP17_SCOPED_LOCK

#if !defined (LBAL_LIBCPP17_SHARED_MUTEX)
	#if __cpp_lib_shared_mutex >= 201505L
		#define LBAL_LIBCPP17_SHARED_MUTEX __cpp_lib_shared_mutex
	#endif
#endif	//	LBAL_LIBCPP17_SHARED_MUTEX

#if !defined (LBAL_LIBCPP17_SHARED_PTR_ARRAYS)
	#if __cpp_lib_shared_ptr_arrays >= 201611L
		#define LBAL_LIBCPP17_SHARED_PTR_ARRAYS __cpp_lib_shared_ptr_arrays
	#endif
#endif	//	LBAL_LIBCPP17_SHARED_PTR_ARRAYS

#if !defined (LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE)
	#if __cpp_lib_shared_ptr_weak_type >= 201606L
		#define LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE \
				__cpp_lib_shared_ptr_weak_type
	#endif
#endif	//	LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE

#if !defined (LBAL_LIBCPP17_STRING_VIEW)
	#if __cpp_lib_string_view >= 201603L
		#define LBAL_LIBCPP17_STRING_VIEW __cpp_lib_string_view
	#endif
#endif	//	LBAL_LIBCPP17_STRING_VIEW

#if !defined (LBAL_LIBCPP17_STRING_VIEW_INTERFACE)
	#if __cpp_lib_string_view_interface >= 201606L
		#define LBAL_LIBCPP17_STRING_VIEW_INTERFACE \
				__cpp_lib_string_view_interface
	#endif
#endif	//	LBAL_LIBCPP17_STRING_VIEW_INTERFACE

#if !defined (LBAL_LIBCPP17_TO_CHARS)
	#if __cpp_lib_to_chars >= 201611L
		#define LBAL_LIBCPP17_TO_CHARS __cpp_lib_to_chars
	#endif
#endif	//	LBAL_LIBCPP17_TO_CHARS

#if !defined (LBAL_LIBCPP17_TO_CHARS_FP)
	#if __cpp_lib_to_chars >= 201611L
		#define LBAL_LIBCPP17_TO_CHARS_FP __cpp_lib_to_chars
	#endif
#endif	//	LBAL_LIBCPP17_TO_CHARS_FP

#if !defined (LBAL_LIBCPP17_TO_CHARS_INTEGER)
	#if __cpp_lib_to_chars >= 201611L
		#define LBAL_LIBCPP17_TO_CHARS_INTEGER __cpp_lib_to_chars
	#endif
#endif	//	LBAL_LIBCPP17_TO_CHARS_INTEGER

#if !defined (LBAL_LIBCPP17_TRANSPARENT_OPERATORS)
	#if __cpp_lib_transparent_operators >= 201510L
		#define LBAL_LIBCPP17_TRANSPARENT_OPERATORS \
				__cpp_lib_transparent_operators
	#endif
#endif	//	LBAL_LIBCPP17_TRANSPARENT_OPERATORS

#if !defined (LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES)
	#if __cpp_lib_type_trait_variable_templates >= 201510L
		#define LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES \
				__cpp_lib_type_trait_variable_templates
	#endif
#endif	//	LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES

#if !defined (LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS)
	#if __cpp_lib_uncaught_exceptions >= 201411L
		#define LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS __cpp_lib_uncaught_exceptions
	#endif
#endif	//	LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS

#if !defined (LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE)
	#if __cpp_lib_unordered_map_try_emplace >= 201411L
		#define LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE \
				__cpp_lib_unordered_map_try_emplace
	#endif
#endif	//	LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE

//	Note that we do not track experimental versions of this.
#if !defined (LBAL_LIBCPP17_VARIANT)
	#if __cpp_lib_variant >= 201606L
		#define LBAL_LIBCPP17_VARIANT __cpp_lib_variant
	#endif
#endif	//	LBAL_LIBCPP17_VARIANT

#if !defined (LBAL_LIBCPP17_VOID_T)
	#if __cpp_lib_void_t >= 201411L
		#define LBAL_LIBCPP17_VOID_T __cpp_lib_void_t
	#endif
#endif	//	LBAL_LIBCPP17_VOID_T


//	C++20 features.

#if !defined (LBAL_LIBCPP2A_ARRAY_CONSTEXPR_ITERATOR)
	#if __cpp_lib_array_constexpr >= 201603L
		#define LBAL_LIBCPP2A_ARRAY_CONSTEXPR_ITERATOR \
				__cpp_lib_array_constexpr
	#endif
#endif	//	LBAL_LIBCPP2A_ARRAY_CONSTEXPR_ITERATOR

#if !defined (LBAL_LIBCPP2A_ARRAY_CONSTEXPR_COMPARISONS)
	#if __cpp_lib_array_constexpr >= 201806L
		#define LBAL_LIBCPP2A_ARRAY_CONSTEXPR_COMPARISONS \
				__cpp_lib_array_constexpr
	#endif
#endif	//	LBAL_LIBCPP2A_ARRAY_CONSTEXPR_COMPARISONS

#if !defined (LBAL_LIBCPP2A_ARRAY_CONSTEXPR_UTILITIES)
	#if __cpp_lib_array_constexpr >= 201811L
		#define LBAL_LIBCPP2A_ARRAY_CONSTEXPR_UTILITIES \
				__cpp_lib_array_constexpr
	#endif
#endif	//	LBAL_LIBCPP2A_ARRAY_CONSTEXPR_UTILITIES

#if !defined (LBAL_LIBCPP2A_ASSUME_ALIGNED)
	#if __cpp_lib_assume_aligned >= 201811L
		#define LBAL_LIBCPP2A_ASSUME_ALIGNED __cpp_lib_assume_aligned
	#endif
#endif	//	LBAL_LIBCPP2A_ASSUME_ALIGNED

#if !defined (LBAL_LIBCPP2A_ATOMIC_FLAG_TEST)
	#if __cpp_lib_atomic_flag_test >= 201907L
		#define LBAL_LIBCPP2A_ATOMIC_FLAG_TEST __cpp_lib_atomic_flag_test
	#endif
#endif	//	LBAL_LIBCPP2A_ATOMIC_FLAG_TEST

#if !defined (LBAL_LIBCPP2A_ATOMIC_FLOAT)
	#if __cpp_lib_atomic_float >= 201711L
		#define LBAL_LIBCPP2A_ATOMIC_FLOAT __cpp_lib_atomic_float
	#endif
#endif	//	LBAL_LIBCPP2A_ATOMIC_FLOAT

#if !defined (LBAL_LIBCPP2A_ATOMIC_LOCK_FREE_TYPE_ALIASES)
	#if __cpp_lib_atomic_lock_free_type_aliases >= 201907L
		#define LBAL_LIBCPP2A_ATOMIC_LOCK_FREE_TYPE_ALIASES \
				__cpp_lib_atomic_lock_free_type_aliases
	#endif
#endif	//	LBAL_LIBCPP2A_ATOMIC_LOCK_FREE_TYPE_ALIASES

#if !defined (LBAL_LIBCPP2A_ATOMIC_REF)
	#if __cpp_lib_atomic_ref >= 201806L
		#define LBAL_LIBCPP2A_ATOMIC_REF __cpp_lib_atomic_ref
	#endif
#endif	//	LBAL_LIBCPP2A_ATOMIC_REF

#if !defined (LBAL_LIBCPP2A_ATOMIC_SHARED_PTR)
	#if __cpp_lib_atomic_shared_ptr >= 201711L
		#define LBAL_LIBCPP2A_ATOMIC_SHARED_PTR __cpp_lib_atomic_shared_ptr
	#endif
#endif	//	LBAL_LIBCPP2A_ATOMIC_SHARED_PTR

#if !defined (LBAL_LIBCPP2A_ATOMIC_VALUE_INITIALIZATION)
	#if __cpp_lib_atomic_value_initialization >= 201911L
		#define LBAL_LIBCPP2A_ATOMIC_VALUE_INITIALIZATION \
				__cpp_lib_atomic_value_initialization
	#endif
#endif	//	LBAL_LIBCPP2A_ATOMIC_VALUE_INITIALIZATION

#if !defined (LBAL_LIBCPP2A_ATOMIC_WAIT)
	#if __cpp_lib_atomic_wait >= 201907L
		#define LBAL_LIBCPP2A_ATOMIC_WAIT __cpp_lib_atomic_wait
	#endif
#endif	//	LBAL_LIBCPP2A_ATOMIC_WAIT

#if !defined (LBAL_LIBCPP2A_BARRIER)
	#if __cpp_lib_barrier >= 201907L
		#define LBAL_LIBCPP2A_BARRIER __cpp_lib_barrier
	#endif
#endif	//	LBAL_LIBCPP2A_BARRIER

#if !defined (LBAL_LIBCPP2A_BIND_FRONT)
	#if __cpp_lib_bind_front >= 201811L
		#define LBAL_LIBCPP2A_BIND_FRONT __cpp_lib_bind_front
	#endif
#endif	//	LBAL_LIBCPP2A_BIND_FRONT

#if !defined (LBAL_LIBCPP2A_BIND_FRONT_NO_UNWRAP)
	#if __cpp_lib_bind_front >= 201907L
		#define LBAL_LIBCPP2A_BIND_FRONT_NO_UNWRAP __cpp_lib_bind_front
	#endif
#endif	//	LBAL_LIBCPP2A_BIND_FRONT_NO_UNWRAP

#if !defined (LBAL_LIBCPP2A_BIT_CAST)
	#if __cpp_lib_bit_cast >= 201806L
		#define LBAL_LIBCPP2A_BIT_CAST __cpp_lib_bit_cast
	#endif
#endif	//	LBAL_LIBCPP2A_BIT_CAST

#if !defined (LBAL_LIBCPP2A_BITOPS)
	#if __cpp_lib_bitops >= 201907L
		#define LBAL_LIBCPP2A_BITOPS __cpp_lib_bitops
	#endif
#endif	//	LBAL_LIBCPP2A_BITOPS

#if !defined (LBAL_LIBCPP2A_BOUNDED_ARRAY_TRAITS)
	#if __cpp_lib_bounded_array_traits >= 201902L
		#define LBAL_LIBCPP2A_BOUNDED_ARRAY_TRAITS \
				__cpp_lib_bounded_array_traits
	#endif
#endif	//	LBAL_LIBCPP2A_BOUNDED_ARRAY_TRAITS

#if !defined (LBAL_LIBCPP2A_CHAR8_T)
	#if __cpp_lib_char8_t >= 201811L
		#define LBAL_LIBCPP2A_CHAR8_T __cpp_lib_char8_t
	#endif
#endif	//	LBAL_LIBCPP2A_CHAR8_T

#if !defined (LBAL_LIBCPP2A_CHAR8_T_COMPAT)
	#if __cpp_lib_char8_t >= 201907L
		#define LBAL_LIBCPP2A_CHAR8_T_COMPAT __cpp_lib_char8_t
	#endif
#endif	//	LBAL_LIBCPP2A_CHAR8_T_COMPAT

#if !defined (LBAL_LIBCPP2A_CHRONO_CALENDAR)
	#if __cpp_lib_chrono >= 201803L
		#define LBAL_LIBCPP2A_CHRONO_CALENDAR __cpp_lib_chrono
	#endif
#endif	//	LBAL_LIBCPP2A_CHRONO_CALENDAR

#if !defined (LBAL_LIBCPP2A_CHRONO_FIXES)
	#if __cpp_lib_chrono >= 201907L
		#define LBAL_LIBCPP2A_CHRONO_FIXES __cpp_lib_chrono
	#endif
#endif	//	LBAL_LIBCPP2A_CHRONO_FIXES

//	Note that this for the Concepts support library; the language feature is
//	handled separately.
#if !defined (LBAL_LIBCPP2A_CONCEPTS)
	#if __cpp_lib_concepts >= 201806L
		#define LBAL_LIBCPP2A_CONCEPTS __cpp_lib_concepts
		#define LBAL_LIBCPP2A_CONCEPTS_EXP 0
	#endif
#endif	//	LBAL_LIBCPP2A_CONCEPTS

#if !defined (LBAL_LIBCPP2A_CONCEPTS_EXP)
	#if __cpp_lib_concepts_exp >= 201806L
		#define LBAL_LIBCPP2A_CONCEPTS_EXP __cpp_lib_concepts_exp
	#endif
#endif	//	LBAL_LIBCPP2A_CONCEPTS_EXP

#if !defined (LBAL_LIBCPP2A_CONCEPTS_STANDARD_CASE)
	#if __cpp_lib_concepts >= 201907L
		#define LBAL_LIBCPP2A_CONCEPTS_STANDARD_CASE __cpp_lib_concepts
	#endif
#endif	//	LBAL_LIBCPP2A_CONCEPTS_STANDARD_CASE

#if !defined (LBAL_LIBCPP2A_CONSTEXPR_ALGORITHMS)
	#if __cpp_lib_constexpr_algorithms >= 201703L
		#define LBAL_LIBCPP2A_CONSTEXPR_ALGORITHMS \
				__cpp_lib_constexpr_algorithms
	#endif
#endif	//	LBAL_LIBCPP2A_CONSTEXPR_ALGORITHMS

#if !defined (LBAL_LIBCPP2A_CONSTEXPR_ALGORITHMS_SWAP)
	#if __cpp_lib_constexpr_algorithms >= 201806L
		#define LBAL_LIBCPP2A_CONSTEXPR_ALGORITHMS_SWAP \
				__cpp_lib_constexpr_algorithms
	#endif
#endif	//	LBAL_LIBCPP2A_CONSTEXPR_ALGORITHMS_SWAP

#if !defined (LBAL_LIBCPP2A_CONSTEXPR_COMPLEX)
	#if __cpp_lib_constexpr_complex >= 201711L
		#define LBAL_LIBCPP2A_CONSTEXPR_COMPLEX __cpp_lib_constexpr_complex
	#endif
#endif	//	LBAL_LIBCPP2A_CONSTEXPR_COMPLEX

#if !defined (LBAL_LIBCPP2A_CONSTEXPR_DYNAMIC_ALLOC)
	#if __cpp_lib_constexpr_dynamic_alloc >= 201907L
		#define LBAL_LIBCPP2A_CONSTEXPR_DYNAMIC_ALLOC \
				__cpp_lib_constexpr_dynamic_alloc
	#endif
#endif	//	LBAL_LIBCPP2A_CONSTEXPR_DYNAMIC_ALLOC

#if !defined (LBAL_LIBCPP2A_CONSTEXPR_FUNCTIONAL)
	#if __cpp_lib_constexpr_functional >= 201811L
		#define LBAL_LIBCPP2A_CONSTEXPR_FUNCTIONAL \
				__cpp_lib_constexpr_functional
	#endif
#endif	//	LBAL_LIBCPP2A_CONSTEXPR_FUNCTIONAL

#if !defined (LBAL_LIBCPP2A_CONSTEXPR_FUNCTIONAL_INVOKE)
	#if __cpp_lib_constexpr_functional >= 201907L
		#define LBAL_LIBCPP2A_CONSTEXPR_FUNCTIONAL_INVOKE \
				__cpp_lib_constexpr_functional
	#endif
#endif	//	LBAL_LIBCPP2A_CONSTEXPR_FUNCTIONAL_INVOKE

#if !defined (LBAL_LIBCPP2A_CONSTEXPR_ITERATOR)
	#if __cpp_lib_constexpr_iterator >= 201811L
		#define LBAL_LIBCPP2A_CONSTEXPR_ITERATOR __cpp_lib_constexpr_iterator
	#endif
#endif	//	LBAL_LIBCPP2A_CONSTEXPR_ITERATOR

#if !defined (LBAL_LIBCPP2A_CONSTEXPR_MEMORY)
	#if __cpp_lib_constexpr_memory >= 201811L
		#define LBAL_LIBCPP2A_CONSTEXPR_MEMORY __cpp_lib_constexpr_memory
	#endif
#endif	//	LBAL_LIBCPP2A_CONSTEXPR_MEMORY

#if !defined (LBAL_LIBCPP2A_CONSTEXPR_NUMERIC)
	#if __cpp_lib_constexpr_numeric >= 201911L
		#define LBAL_LIBCPP2A_CONSTEXPR_NUMERIC __cpp_lib_constexpr_numeric
	#endif
#endif	//	LBAL_LIBCPP2A_CONSTEXPR_NUMERIC

#if !defined (LBAL_LIBCPP2A_CONSTEXPR_STRING)
	#if __cpp_lib_constexpr_string >= 201907L
		#define LBAL_LIBCPP2A_CONSTEXPR_STRING __cpp_lib_constexpr_string
	#endif
#endif	//	LBAL_LIBCPP2A_CONSTEXPR_STRING

#if !defined (LBAL_LIBCPP2A_CONSTEXPR_STRING_VIEW)
	#if __cpp_lib_constexpr_string_view >= 201811L
		#define LBAL_LIBCPP2A_CONSTEXPR_STRING_VIEW \
				__cpp_lib_constexpr_string_view
	#endif
#endif	//	LBAL_LIBCPP2A_CONSTEXPR_STRING_VIEW

#if !defined (LBAL_LIBCPP2A_CONSTEXPR_TUPLE)
	#if __cpp_lib_constexpr_tuple >= 201811L
		#define LBAL_LIBCPP2A_CONSTEXPR_TUPLE __cpp_lib_constexpr_tuple
	#endif
#endif	//	LBAL_LIBCPP2A_CONSTEXPR_TUPLE

#if !defined (LBAL_LIBCPP2A_CONSTEXPR_UTILITY)
	#if __cpp_lib_constexpr_utility >= 201811L
		#define LBAL_LIBCPP2A_CONSTEXPR_UTILITY __cpp_lib_constexpr_utility
	#endif
#endif	//	LBAL_LIBCPP2A_CONSTEXPR_UTILITY

#if !defined (LBAL_LIBCPP2A_CONSTEXPR_VECTOR)
	#if __cpp_lib_constexpr_vector >= 201907L
		#define LBAL_LIBCPP2A_CONSTEXPR_VECTOR __cpp_lib_constexpr_vector
	#endif
#endif	//	LBAL_LIBCPP2A_CONSTEXPR_VECTOR

//	__SEEME__ The `<coroutine>` library feature does not currently have its own
//	SD-6 macro. We use the value of the language feature macro as a proxy for
//	library support.
#if !defined (LBAL_LIBCPP2A_COROUTINES)
	#if __cpp_coroutines >= 201902L
		#define LBAL_LIBCPP2A_COROUTINES __cpp_coroutines
		#define LBAL_LIBCPP2A_COROUTINES_EXP 0
	#endif
#endif	//	LBAL_LIBCPP2A_COROUTINES

#if !defined (LBAL_LIBCPP2A_COROUTINES_EXP)
	#if __cpp_experimental_coroutines >= 201902L
		#define LBAL_LIBCPP2A_COROUTINES_EXP __cpp_experimental_coroutines
	#endif
#endif	//	LBAL_LIBCPP2A_COROUTINES_EXP

#if !defined (LBAL_LIBCPP2A_DESTROYING_DELETE)
	#if __cpp_lib_destroying_delete >= 201806L
		#define LBAL_LIBCPP2A_DESTROYING_DELETE __cpp_lib_destroying_delete
	#endif
#endif	//	LBAL_LIBCPP2A_DESTROYING_DELETE

#if !defined (LBAL_LIBCPP2A_ENDIAN)
	#if __cpp_lib_endian >= 201907L
		#define LBAL_LIBCPP2A_ENDIAN __cpp_lib_endian
	#endif
#endif	//	LBAL_LIBCPP2A_ENDIAN

#if !defined (LBAL_LIBCPP2A_ENDIAN_BIT)
	#if __cpp_lib_endian >= 201907L
		#define LBAL_LIBCPP2A_ENDIAN_BIT __cpp_lib_endian
	#endif
#endif	//	LBAL_LIBCPP2A_ENDIAN_BIT

#if !defined (LBAL_LIBCPP2A_ERASE_IF)
	#if __cpp_lib_erase_if >= 201811L
		#define LBAL_LIBCPP2A_ERASE_IF __cpp_lib_erase_if
	#endif
#endif	//	LBAL_LIBCPP2A_ERASE_IF

#if !defined (LBAL_LIBCPP2A_EXECUTION_VECTORIZATION)
	#if __cpp_lib_execution >= 201902L
		#define LBAL_LIBCPP2A_EXECUTION_VECTORIZATION __cpp_lib_execution
	#endif
#endif	//	LBAL_LIBCPP2A_EXECUTION_VECTORIZATION

#if !defined (LBAL_LIBCPP2A_FORMAT)
	#if __cpp_lib_format >= 201907L
		#define LBAL_LIBCPP2A_FORMAT __cpp_lib_format
	#endif
#endif	//	LBAL_LIBCPP2A_FORMAT

#if !defined (LBAL_LIBCPP2A_INT_POW2)
	#if __cpp_lib_int_pow2 >= 201806L
		#define LBAL_LIBCPP2A_INT_POW2 __cpp_lib_int_pow2
	#endif
#endif	//	LBAL_LIBCPP2A_INT_POW2

#if !defined (LBAL_LIBCPP2A_INTERPOLATE)
	#if __cpp_lib_interpolate >= 201902L
		#define LBAL_LIBCPP2A_INTERPOLATE __cpp_lib_interpolate
	#endif
#endif	//	LBAL_LIBCPP2A_INTERPOLATE

#if !defined (LBAL_LIBCPP2A_IS_CONSTANT_EVALUATED)
	#if __cpp_lib_is_constant_evaluated >= 201811L
		#define LBAL_LIBCPP2A_IS_CONSTANT_EVALUATED \
				__cpp_lib_is_constant_evaluated
	#endif
#endif	//	LBAL_LIBCPP2A_IS_CONSTANT_EVALUATED

#if !defined (LBAL_LIBCPP2A_IS_LAYOUT_COMPATIBLE)
	#if __cpp_lib_is_layout_compatible >= 201907L
		#define LBAL_LIBCPP2A_IS_LAYOUT_COMPATIBLE \
				__cpp_lib_is_layout_compatible
	#endif
#endif	//	LBAL_LIBCPP2A_IS_LAYOUT_COMPATIBLE

#if !defined (LBAL_LIBCPP2A_IS_POINTER_INTERCONVERTIBLE)
	#if __cpp_lib_is_pointer_interconvertible >= 201907L
		#define LBAL_LIBCPP2A_IS_POINTER_INTERCONVERTIBLE \
				__cpp_lib_is_pointer_interconvertible
	#endif
#endif	//	LBAL_LIBCPP2A_IS_POINTER_INTERCONVERTIBLE

#if !defined (LBAL_LIBCPP2A_JTHREAD)
	#if __cpp_lib_jthread >= 201907L
		#define LBAL_LIBCPP2A_JTHREAD __cpp_lib_jthread
	#endif
#endif	//	LBAL_LIBCPP2A_JTHREAD

#if !defined (LBAL_LIBCPP2A_JTHREAD_CV)
	#if __cpp_lib_jthread >= 201911L
		#define LBAL_LIBCPP2A_JTHREAD_CV __cpp_lib_jthread
	#endif
#endif	//	LBAL_LIBCPP2A_JTHREAD_CV

#if !defined (LBAL_LIBCPP2A_LATCH)
	#if __cpp_lib_latch >= 201907L
		#define LBAL_LIBCPP2A_LATCH __cpp_lib_latch
	#endif
#endif	//	LBAL_LIBCPP2A_LATCH

#if !defined (LBAL_LIBCPP2A_LIST_REMOVE_RETURN_TYPE)
	#if __cpp_lib_list_remove_return_type >= 201806L
		#define LBAL_LIBCPP2A_LIST_REMOVE_RETURN_TYPE \
				__cpp_lib_list_remove_return_type
	#endif
#endif	//	LBAL_LIBCPP2A_LIST_REMOVE_RETURN_TYPE

#if !defined (LBAL_LIBCPP2A_MATH_CONSTANTS)
	#if __cpp_lib_math_constants >= 201907L
		#define LBAL_LIBCPP2A_MATH_CONSTANTS __cpp_lib_math_constants
	#endif
#endif	//	LBAL_LIBCPP2A_MATH_CONSTANTS

#if !defined (LBAL_LIBCPP2A_NOTHROW_CONVERTIBLE)
	#if __cpp_lib_nothrow_convertible >= 201806L
		#define LBAL_LIBCPP2A_NOTHROW_CONVERTIBLE __cpp_lib_nothrow_convertible
	#endif
#endif	//	LBAL_LIBCPP2A_NOTHROW_CONVERTIBLE

#if !defined (LBAL_LIBCPP2A_POLYMORPHIC_ALLOCATOR)
	#if __cpp_lib_polymorphic_allocator >= 201902L
		#define LBAL_LIBCPP2A_POLYMORPHIC_ALLOCATOR \
				__cpp_lib_polymorphic_allocator
	#endif
#endif	//	LBAL_LIBCPP2A_POLYMORPHIC_ALLOCATOR

#if !defined (LBAL_LIBCPP2A_RANGES)
	#if __cpp_lib_ranges >= 201811L
		#define LBAL_LIBCPP2A_RANGES __cpp_lib_ranges
	#endif
#endif	//	LBAL_LIBCPP2A_RANGES

#if !defined (LBAL_LIBCPP2A_RANGES_INPUT_ADAPTORS)
	#if __cpp_lib_ranges >= 201907L
		#define LBAL_LIBCPP2A_RANGES_INPUT_ADAPTORS __cpp_lib_ranges
	#endif
#endif	//	LBAL_LIBCPP2A_RANGES_INPUT_ADAPTORS

#if !defined (LBAL_LIBCPP2A_RANGES_LOOSENED_COMPARE)
	#if __cpp_lib_ranges >= 201911L
		#define LBAL_LIBCPP2A_RANGES_LOOSENED_COMPARE __cpp_lib_ranges
	#endif
#endif	//	LBAL_LIBCPP2A_RANGES_LOOSENED_COMPARE

#if !defined (LBAL_LIBCPP2A_REMOVE_CVREF)
	#if __cpp_lib_remove_cvref >= 201711L
		#define LBAL_LIBCPP2A_REMOVE_CVREF __cpp_lib_remove_cvref
	#endif
#endif	//	LBAL_LIBCPP2A_REMOVE_CVREF

#if !defined (LBAL_LIBCPP2A_SEMAPHORE)
	#if __cpp_lib_semaphore >= 201907L
		#define LBAL_LIBCPP2A_SEMAPHORE __cpp_lib_semaphore
	#endif
#endif	//	LBAL_LIBCPP2A_SEMAPHORE

#if !defined (LBAL_LIBCPP2A_SHARED_PTR_ARRAYS)
	#if __cpp_lib_shared_ptr_arrays >= 201707L
		#define LBAL_LIBCPP2A_SHARED_PTR_ARRAYS __cpp_lib_shared_ptr_arrays
	#endif
#endif	//	LBAL_LIBCPP2A_SHARED_PTR_ARRAYS

#if !defined (LBAL_LIBCPP2A_SHIFT)
	#if __cpp_lib_shift >= 201806L
		#define LBAL_LIBCPP2A_SHIFT __cpp_lib_shift
	#endif
#endif	//	LBAL_LIBCPP2A_SHIFT

#if !defined (LBAL_LIBCPP2A_SMART_PTR_DEFAULT_INIT)
	#if __cpp_lib_smart_ptr_default_init >= 201811L
		#define LBAL_LIBCPP2A_SMART_PTR_DEFAULT_INIT \
				__cpp_lib_smart_ptr_default_init
	#endif
#endif	//	LBAL_LIBCPP2A_SMART_PTR_DEFAULT_INIT

#if !defined (LBAL_LIBCPP2A_SOURCE_LOCATION)
	#if __cpp_lib_source_location >= 201907L
		#define LBAL_LIBCPP2A_SOURCE_LOCATION __cpp_lib_source_location
	#endif
#endif	//	LBAL_LIBCPP2A_SOURCE_LOCATION

#if !defined (LBAL_LIBCPP2A_SPAN)
	#if __cpp_lib_span >= 201803L
		#define LBAL_LIBCPP2A_SPAN __cpp_lib_span
	#endif
#endif	//	LBAL_LIBCPP2A_SPAN

#if !defined (LBAL_LIBCPP2A_SPAN_USABILITY)
	#if __cpp_lib_span >= 201803L
		#define LBAL_LIBCPP2A_SPAN_USABILITY __cpp_lib_span
	#endif
#endif	//	LBAL_LIBCPP2A_SPAN_USABILITY

#if !defined (LBAL_LIBCPP2A_SSIZE)
	#if __cpp_lib_ssize >= __cpp_lib_ssize
		#define LBAL_LIBCPP2A_SSIZE 201902L
	#endif
#endif	//	LBAL_LIBCPP2A_SSIZE

#if !defined (LBAL_LIBCPP2A_STARTS_ENDS_WITH)
	#if __cpp_lib_starts_ends_with >= 201711L
		#define LBAL_LIBCPP2A_STARTS_ENDS_WITH __cpp_lib_starts_ends_with
	#endif
#endif	//	LBAL_LIBCPP2A_STARTS_ENDS_WITH

#if !defined (LBAL_LIBCPP2A_STRING_VIEW_CONSTEXPR_ITERATOR)
	#if __cpp_lib_string_view >= 201803L
		#define LBAL_LIBCPP2A_STRING_VIEW_CONSTEXPR_ITERATOR \
				__cpp_lib_string_view
	#endif
#endif	//	LBAL_LIBCPP2A_STRING_VIEW_CONSTEXPR_ITERATOR

#if !defined (LBAL_LIBCPP2A_SYNCBUF)
	#if __cpp_lib_syncbuf >= 201711L
		#define LBAL_LIBCPP2A_SYNCBUF __cpp_lib_syncbuf
	#endif
#endif	//	LBAL_LIBCPP2A_SYNCBUF

#if !defined (LBAL_LIBCPP2A_SYNCBUF_MANIPULATORS)
	#if __cpp_lib_syncbuf >= 201803L
		#define LBAL_LIBCPP2A_SYNCBUF_MANIPULATORS __cpp_lib_syncbuf
	#endif
#endif	//	LBAL_LIBCPP2A_SYNCBUF_MANIPULATORS

#if !defined (LBAL_LIBCPP2A_THREE_WAY_COMPARISON)
	#if __cpp_lib_three_way_comparison >= 201711L
		#define LBAL_LIBCPP2A_THREE_WAY_COMPARISON \
				__cpp_lib_three_way_comparison
	#endif
#endif	//	LBAL_LIBCPP2A_THREE_WAY_COMPARISON

#if !defined (LBAL_LIBCPP2A_THREE_WAY_COMPARISON_LIBRARY)
	#if __cpp_lib_three_way_comparison >= 201907L
		#define LBAL_LIBCPP2A_THREE_WAY_COMPARISON_LIBRARY \
				__cpp_lib_three_way_comparison
	#endif
#endif	//	LBAL_LIBCPP2A_THREE_WAY_COMPARISON_LIBRARY

#if !defined (LBAL_LIBCPP2A_TO_ADDRESS)
	#if __cpp_lib_to_address >= 201711L
		#define LBAL_LIBCPP2A_TO_ADDRESS __cpp_lib_to_address
	#endif
#endif	//	LBAL_LIBCPP2A_TO_ADDRESS

#if !defined (LBAL_LIBCPP2A_TO_ARRAY)
	#if __cpp_lib_to_array >= 201907L
		#define LBAL_LIBCPP2A_TO_ARRAY __cpp_lib_to_array
	#endif
#endif	//	LBAL_LIBCPP2A_TO_ARRAY

#if !defined (LBAL_LIBCPP2A_TYPE_IDENTITY)
	#if __cpp_lib_type_identity >= 201806L
		#define LBAL_LIBCPP2A_TYPE_IDENTITY __cpp_lib_type_identity
	#endif
#endif	//	LBAL_LIBCPP2A_TYPE_IDENTITY

#if !defined (LBAL_LIBCPP2A_UNWRAP_REF)
	#if __cpp_lib_unwrap_ref >= 201811L
		#define LBAL_LIBCPP2A_UNWRAP_REF __cpp_lib_unwrap_ref
	#endif
#endif	//	LBAL_LIBCPP2A_UNWRAP_REF


//	Technical Specifications

//	Networking functionality spans an array of new headers; we only check for
//	the presence of the convenience header, <net>.
#if !defined (LBAL_LIBCPPTS_NETWORKING)
	#if __cpp_lib_net >= 1
		#define LBAL_LIBCPPTS_NETWORKING __cpp_lib_net
		#define LBAL_LIBCPPTS_NETWORKING_EXP 0
	#endif
#endif	//	LBAL_LIBCPPTS_NETWORKING

#if !defined (LBAL_LIBCPPTS_NETWORKING_EXP)
	#if __cpp_lib_experimental_net >= 1
		#define LBAL_LIBCPPTS_NETWORKING_EXP __cpp_lib_experimental_net
	#endif
#endif	//	LBAL_LIBCPPTS_NETWORKING_EXP

#if !defined (LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE)
	#if __cpp_lib_net_extensible >= 1
		#define LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE __cpp_lib_net_extensible
		#define LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP 0
	#endif
#endif	//	LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE

#if !defined (LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP)
	#if __cpp_lib_experimental_net_extensible >= 1
		#define LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP \
				__cpp_lib_experimental_net_extensible
	#endif
#endif	//	LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP

#if !defined (LBAL_LIBCPPTS_OBSERVER_PTR)
	#if __cpp_lib_observer_ptr >= 1
		#define LBAL_LIBCPPTS_OBSERVER_PTR __cpp_lib_observer_ptr
	#endif
#endif	//	LBAL_LIBCPPTS_OBSERVER_PTR

#if !defined (LBAL_LIBCPPTS_OBSERVER_PTR_EXP)
	#if __cpp_lib_experimental_observer_ptr >= 1
		#define LBAL_LIBCPPTS_OBSERVER_PTR_EXP \
				__cpp_lib_experimental_observer_ptr
	#endif
#endif	//	LBAL_LIBCPPTS_OBSERVER_PTR_EXP


/*------------------------------------------------------------------------------
	Implementation-specific Overrides

	Broadly, there are tokens that can’t be adequately defined without some
	extrinsic knowledge of the library implementation involved, usually
	based on the known capabilities of specific versions. The implementation-
	specific headers below take care of this.

	Note that any tokens left unset here will be explicitly set to `0` in
	`lbalFeatureSetup.hpp`.
*/

#if LBAL_TARGET_STANDARD_LIBRARY_APPLE_LIBCPP
	#include <lucenaBAL/details/libraries/lbalStandardLibraryAppleLibCppPostInitialization.hpp>
#elif LBAL_TARGET_STANDARD_LIBRARY_LIBCPP
	#include <lucenaBAL/details/libraries/lbalStandardLibraryLibCppPostInitialization.hpp>
#elif LBAL_TARGET_STANDARD_LIBRARY_LIBSTDCPP
	#include <lucenaBAL/details/libraries/lbalStandardLibraryLibStdCppPostInitialization.hpp>
#elif LBAL_TARGET_STANDARD_LIBRARY_MSVC
	#include <lucenaBAL/details/libraries/lbalStandardLibraryMSVCPostInitialization.hpp>
#else
	//	In the generic case, we do nothing here.
#endif


/*------------------------------------------------------------------------------
	Aggregates

	These are convenience macros that combine multiple other macros.
*/

//	This is an aggregate that tracks two different SD-6 macros for the purpose
//	of establishing Standard compliance. There is no single corresponding SD-6
//	macro. Note that we do not track experimental versions of the components.
#if !defined (LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS)
	#if LBAL_LIBCPP17_EXECUTION && LBAL_LIBCPP17_PARALLEL_ALGORITHM
		#define LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS 1L
	#endif
#endif	//	LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS


/*------------------------------------------------------------------------------
	Header Checks

	Make sure that the headers needed to support supposedly available features
	are actually present, if possible.
*/

