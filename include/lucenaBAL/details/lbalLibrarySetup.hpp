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
#include <lucenaBAL/details/lbalCompilerSetup.hpp>
#include <lucenaBAL/details/lbalDetectStandardLibrary.hpp>
#include <lucenaBAL/details/lbalKnownVersions.hpp>
#include <lucenaBAL/details/lbalPlatformSetup.hpp>


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
	#if __cpp_lib_make_reverse_iterator >= 201402L
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

#if !defined (LBAL_LIBCPP17_CONSTEXPR_STRING)
	#if __cpp_lib_constexpr_string >= 201611L
		#define LBAL_LIBCPP17_CONSTEXPR_STRING __cpp_lib_constexpr_string
	#endif
#endif	//	LBAL_LIBCPP17_CONSTEXPR_STRING

#if !defined (LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW)
	#if __cpp_lib_constexpr_string_view >= 201611L
		#define LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW __cpp_lib_constexpr_string_view
	#endif
#endif	//	LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW

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

#if !defined (LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR)
	#if __cpp_lib_array_constexpr >= 201603L
		#define LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR \
				__cpp_lib_array_constexpr
	#endif
#endif	//	LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR

#if !defined (LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS)
	#if __cpp_lib_array_constexpr >= 201806L
		#define LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS \
				__cpp_lib_array_constexpr
	#endif
#endif	//	LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS

#if !defined (LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES)
	#if __cpp_lib_array_constexpr >= 201811L
		#define LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES \
				__cpp_lib_array_constexpr
	#endif
#endif	//	LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES

#if !defined (LBAL_LIBCPP20_ASSUME_ALIGNED)
	#if __cpp_lib_assume_aligned >= 201811L
		#define LBAL_LIBCPP20_ASSUME_ALIGNED __cpp_lib_assume_aligned
	#endif
#endif	//	LBAL_LIBCPP20_ASSUME_ALIGNED

#if !defined (LBAL_LIBCPP20_ATOMIC_FLAG_TEST)
	#if __cpp_lib_atomic_flag_test >= 201907L
		#define LBAL_LIBCPP20_ATOMIC_FLAG_TEST __cpp_lib_atomic_flag_test
	#endif
#endif	//	LBAL_LIBCPP20_ATOMIC_FLAG_TEST

#if !defined (LBAL_LIBCPP20_ATOMIC_FLOAT)
	#if __cpp_lib_atomic_float >= 201711L
		#define LBAL_LIBCPP20_ATOMIC_FLOAT __cpp_lib_atomic_float
	#endif
#endif	//	LBAL_LIBCPP20_ATOMIC_FLOAT

#if !defined (LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES)
	#if __cpp_lib_atomic_lock_free_type_aliases >= 201907L
		#define LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES \
				__cpp_lib_atomic_lock_free_type_aliases
	#endif
#endif	//	LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES

#if !defined (LBAL_LIBCPP20_ATOMIC_REF)
	#if __cpp_lib_atomic_ref >= 201806L
		#define LBAL_LIBCPP20_ATOMIC_REF __cpp_lib_atomic_ref
	#endif
#endif	//	LBAL_LIBCPP20_ATOMIC_REF

#if !defined (LBAL_LIBCPP20_ATOMIC_SHARED_PTR)
	#if __cpp_lib_atomic_shared_ptr >= 201711L
		#define LBAL_LIBCPP20_ATOMIC_SHARED_PTR __cpp_lib_atomic_shared_ptr
	#endif
#endif	//	LBAL_LIBCPP20_ATOMIC_SHARED_PTR

#if !defined (LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION)
	#if __cpp_lib_atomic_value_initialization >= 201911L
		#define LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION \
				__cpp_lib_atomic_value_initialization
	#endif
#endif	//	LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION

#if !defined (LBAL_LIBCPP20_ATOMIC_WAIT)
	#if __cpp_lib_atomic_wait >= 201907L
		#define LBAL_LIBCPP20_ATOMIC_WAIT __cpp_lib_atomic_wait
	#endif
#endif	//	LBAL_LIBCPP20_ATOMIC_WAIT

#if !defined (LBAL_LIBCPP20_BARRIER)
	#if __cpp_lib_barrier >= 201907L
		#define LBAL_LIBCPP20_BARRIER __cpp_lib_barrier
	#endif
#endif	//	LBAL_LIBCPP20_BARRIER

#if !defined (LBAL_LIBCPP20_BIND_FRONT)
	#if __cpp_lib_bind_front >= 201811L
		#define LBAL_LIBCPP20_BIND_FRONT __cpp_lib_bind_front
	#endif
#endif	//	LBAL_LIBCPP20_BIND_FRONT

#if !defined (LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP)
	#if __cpp_lib_bind_front >= 201907L
		#define LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP __cpp_lib_bind_front
	#endif
#endif	//	LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP

#if !defined (LBAL_LIBCPP20_BIT_CAST)
	#if __cpp_lib_bit_cast >= 201806L
		#define LBAL_LIBCPP20_BIT_CAST __cpp_lib_bit_cast
	#endif
#endif	//	LBAL_LIBCPP20_BIT_CAST

#if !defined (LBAL_LIBCPP20_BITOPS)
	#if __cpp_lib_bitops >= 201907L
		#define LBAL_LIBCPP20_BITOPS __cpp_lib_bitops
	#endif
#endif	//	LBAL_LIBCPP20_BITOPS

#if !defined (LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS)
	#if __cpp_lib_bounded_array_traits >= 201902L
		#define LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS \
				__cpp_lib_bounded_array_traits
	#endif
#endif	//	LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS

#if !defined (LBAL_LIBCPP20_CHAR8_T)
	#if __cpp_lib_char8_t >= 201811L
		#define LBAL_LIBCPP20_CHAR8_T __cpp_lib_char8_t
	#endif
#endif	//	LBAL_LIBCPP20_CHAR8_T

#if !defined (LBAL_LIBCPP20_CHAR8_T_COMPAT)
	#if __cpp_lib_char8_t >= 201907L
		#define LBAL_LIBCPP20_CHAR8_T_COMPAT __cpp_lib_char8_t
	#endif
#endif	//	LBAL_LIBCPP20_CHAR8_T_COMPAT

#if !defined (LBAL_LIBCPP20_CHRONO_CALENDAR)
	#if __cpp_lib_chrono >= 201803L
		#define LBAL_LIBCPP20_CHRONO_CALENDAR __cpp_lib_chrono
	#endif
#endif	//	LBAL_LIBCPP20_CHRONO_CALENDAR

#if !defined (LBAL_LIBCPP20_CHRONO_FIXES)
	#if __cpp_lib_chrono >= 201907L
		#define LBAL_LIBCPP20_CHRONO_FIXES __cpp_lib_chrono
	#endif
#endif	//	LBAL_LIBCPP20_CHRONO_FIXES

//	Note that this for the Concepts support library; the language feature is
//	handled separately.
#if !defined (LBAL_LIBCPP20_CONCEPTS)
	#if __cpp_lib_concepts >= 201806L
		#define LBAL_LIBCPP20_CONCEPTS __cpp_lib_concepts
		#define LBAL_LIBCPP20_CONCEPTS_EXP 0
	#endif
#endif	//	LBAL_LIBCPP20_CONCEPTS

#if !defined (LBAL_LIBCPP20_CONCEPTS_EXP)
	#if __cpp_lib_concepts_exp >= 201806L
		#define LBAL_LIBCPP20_CONCEPTS_EXP __cpp_lib_concepts_exp
	#endif
#endif	//	LBAL_LIBCPP20_CONCEPTS_EXP

#if !defined (LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE)
	#if __cpp_lib_concepts >= 201907L
		#define LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE __cpp_lib_concepts
	#endif
#endif	//	LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE

#if !defined (LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE)
	#if __cpp_lib_concepts >= 202002L
		#define LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE __cpp_lib_concepts
	#endif
#endif	//	LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE

#if !defined (LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS)
	#if __cpp_lib_constexpr_algorithms >= 201703L
		#define LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS \
				__cpp_lib_constexpr_algorithms
	#endif
#endif	//	LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS

#if !defined (LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP)
	#if __cpp_lib_constexpr_algorithms >= 201806L
		#define LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP \
				__cpp_lib_constexpr_algorithms
	#endif
#endif	//	LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP

#if !defined (LBAL_LIBCPP20_CONSTEXPR_COMPLEX)
	#if __cpp_lib_constexpr_complex >= 201711L
		#define LBAL_LIBCPP20_CONSTEXPR_COMPLEX __cpp_lib_constexpr_complex
	#endif
#endif	//	LBAL_LIBCPP20_CONSTEXPR_COMPLEX

#if !defined (LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC)
	#if __cpp_lib_constexpr_dynamic_alloc >= 201907L
		#define LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC \
				__cpp_lib_constexpr_dynamic_alloc
	#endif
#endif	//	LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC

#if !defined (LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL)
	#if __cpp_lib_constexpr_functional >= 201811L
		#define LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL \
				__cpp_lib_constexpr_functional
	#endif
#endif	//	LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL

#if !defined (LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE)
	#if __cpp_lib_constexpr_functional >= 201907L
		#define LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE \
				__cpp_lib_constexpr_functional
	#endif
#endif	//	LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE

#if !defined (LBAL_LIBCPP20_CONSTEXPR_ITERATOR)
	#if __cpp_lib_constexpr_iterator >= 201811L
		#define LBAL_LIBCPP20_CONSTEXPR_ITERATOR __cpp_lib_constexpr_iterator
	#endif
#endif	//	LBAL_LIBCPP20_CONSTEXPR_ITERATOR

#if !defined (LBAL_LIBCPP20_CONSTEXPR_MEMORY)
	#if __cpp_lib_constexpr_memory >= 201811L
		#define LBAL_LIBCPP20_CONSTEXPR_MEMORY __cpp_lib_constexpr_memory
	#endif
#endif	//	LBAL_LIBCPP20_CONSTEXPR_MEMORY

#if !defined (LBAL_LIBCPP20_CONSTEXPR_NUMERIC)
	#if __cpp_lib_constexpr_numeric >= 201911L
		#define LBAL_LIBCPP20_CONSTEXPR_NUMERIC __cpp_lib_constexpr_numeric
	#endif
#endif	//	LBAL_LIBCPP20_CONSTEXPR_NUMERIC

#if !defined (LBAL_LIBCPP20_CONSTEXPR_STRING)
	#if __cpp_lib_constexpr_string >= 201811L
		#define LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL __cpp_lib_constexpr_string
	#endif

	#if __cpp_lib_constexpr_string >= 201907L
		#define LBAL_LIBCPP20_CONSTEXPR_STRING __cpp_lib_constexpr_string
	#endif
#endif	//	LBAL_LIBCPP20_CONSTEXPR_STRING

#if !defined (LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW)
	#if __cpp_lib_constexpr_string_view >= 201811L
		#define LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW \
				__cpp_lib_constexpr_string_view
	#endif
#endif	//	LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW

#if !defined (LBAL_LIBCPP20_CONSTEXPR_TUPLE)
	#if __cpp_lib_constexpr_tuple >= 201811L
		#define LBAL_LIBCPP20_CONSTEXPR_TUPLE __cpp_lib_constexpr_tuple
	#endif
#endif	//	LBAL_LIBCPP20_CONSTEXPR_TUPLE

#if !defined (LBAL_LIBCPP20_CONSTEXPR_UTILITY)
	#if __cpp_lib_constexpr_utility >= 201811L
		#define LBAL_LIBCPP20_CONSTEXPR_UTILITY __cpp_lib_constexpr_utility
	#endif
#endif	//	LBAL_LIBCPP20_CONSTEXPR_UTILITY

#if !defined (LBAL_LIBCPP20_CONSTEXPR_VECTOR)
	#if __cpp_lib_constexpr_vector >= 201907L
		#define LBAL_LIBCPP20_CONSTEXPR_VECTOR __cpp_lib_constexpr_vector
	#endif
#endif	//	LBAL_LIBCPP20_CONSTEXPR_VECTOR

#if !defined (LBAL_LIBCPP20_COROUTINE)
	#if __cpp_lib_coroutine >= 201902L
		#define LBAL_LIBCPP20_COROUTINE __cpp_lib_coroutine
		#define LBAL_LIBCPP20_COROUTINE_EXP 0
	#endif
#endif	//	LBAL_LIBCPP20_COROUTINE

#if !defined (LBAL_LIBCPP20_COROUTINE_EXP)
	#if __cpp_lib_experimental_coroutine >= 201902L
		#define LBAL_LIBCPP20_COROUTINE_EXP __cpp_lib_experimental_coroutine
	#endif
#endif	//	LBAL_LIBCPP20_COROUTINE_EXP

#if !defined (LBAL_LIBCPP20_DESTROYING_DELETE)
	#if __cpp_lib_destroying_delete >= 201806L
		#define LBAL_LIBCPP20_DESTROYING_DELETE __cpp_lib_destroying_delete
	#endif
#endif	//	LBAL_LIBCPP20_DESTROYING_DELETE

#if !defined (LBAL_LIBCPP20_ENDIAN)
	#if __cpp_lib_endian >= 201907L
		#define LBAL_LIBCPP20_ENDIAN __cpp_lib_endian
	#endif
#endif	//	LBAL_LIBCPP20_ENDIAN

#if !defined (LBAL_LIBCPP20_ENDIAN_BIT)
	#if __cpp_lib_endian >= 201907L
		#define LBAL_LIBCPP20_ENDIAN_BIT __cpp_lib_endian
	#endif
#endif	//	LBAL_LIBCPP20_ENDIAN_BIT

#if !defined (LBAL_LIBCPP20_ERASE_IF)
	#if __cpp_lib_erase_if >= 201811L
		#define LBAL_LIBCPP20_ERASE_IF __cpp_lib_erase_if
	#endif
#endif	//	LBAL_LIBCPP20_ERASE_IF

#if !defined (LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS)
	#if __cpp_lib_erase_if >= 202002L
		#define LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS __cpp_lib_erase_if
	#endif
#endif	//	LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS

#if !defined (LBAL_LIBCPP20_EXECUTION_VECTORIZATION)
	#if __cpp_lib_execution >= 201902L
		#define LBAL_LIBCPP20_EXECUTION_VECTORIZATION __cpp_lib_execution
	#endif
#endif	//	LBAL_LIBCPP20_EXECUTION_VECTORIZATION

#if !defined (LBAL_LIBCPP20_FORMAT)
	#if __cpp_lib_format >= 201907L
		#define LBAL_LIBCPP20_FORMAT __cpp_lib_format
	#endif
#endif	//	LBAL_LIBCPP20_FORMAT

#if !defined (LBAL_LIBCPP20_INT_POW2)
	#if __cpp_lib_int_pow2 >= 201806L
		#define LBAL_LIBCPP20_INT_POW2 __cpp_lib_int_pow2
	#endif
#endif	//	LBAL_LIBCPP20_INT_POW2

#if !defined (LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME)
	#if __cpp_lib_int_pow2 >= 202002L
		#define LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME __cpp_lib_int_pow2
	#endif
#endif	//	LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME

#if !defined (LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS)
	#if __cpp_lib_integer_comparison_functions >= 202002L
		#define LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS \
				__cpp_lib_integer_comparison_functions
	#endif
#endif	//	LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS

#if !defined (LBAL_LIBCPP20_INTERPOLATE)
	#if __cpp_lib_interpolate >= 201902L
		#define LBAL_LIBCPP20_INTERPOLATE __cpp_lib_interpolate
	#endif
#endif	//	LBAL_LIBCPP20_INTERPOLATE

#if !defined (LBAL_LIBCPP20_IS_CONSTANT_EVALUATED)
	#if __cpp_lib_is_constant_evaluated >= 201811L
		#define LBAL_LIBCPP20_IS_CONSTANT_EVALUATED \
				__cpp_lib_is_constant_evaluated
	#endif
#endif	//	LBAL_LIBCPP20_IS_CONSTANT_EVALUATED

#if !defined (LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE)
	#if __cpp_lib_is_layout_compatible >= 201907L
		#define LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE \
				__cpp_lib_is_layout_compatible
	#endif
#endif	//	LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE

#if !defined (LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE)
	#if __cpp_lib_is_pointer_interconvertible >= 201907L
		#define LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE \
				__cpp_lib_is_pointer_interconvertible
	#endif
#endif	//	LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE

#if !defined (LBAL_LIBCPP20_JTHREAD)
	#if __cpp_lib_jthread >= 201907L
		#define LBAL_LIBCPP20_JTHREAD __cpp_lib_jthread
	#endif
#endif	//	LBAL_LIBCPP20_JTHREAD

#if !defined (LBAL_LIBCPP20_JTHREAD_CV)
	#if __cpp_lib_jthread >= 201911L
		#define LBAL_LIBCPP20_JTHREAD_CV __cpp_lib_jthread
	#endif
#endif	//	LBAL_LIBCPP20_JTHREAD_CV

#if !defined (LBAL_LIBCPP20_LATCH)
	#if __cpp_lib_latch >= 201907L
		#define LBAL_LIBCPP20_LATCH __cpp_lib_latch
	#endif
#endif	//	LBAL_LIBCPP20_LATCH

#if !defined (LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE)
	#if __cpp_lib_list_remove_return_type >= 201806L
		#define LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE \
				__cpp_lib_list_remove_return_type
	#endif
#endif	//	LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE

#if !defined (LBAL_LIBCPP20_MATH_CONSTANTS)
	#if __cpp_lib_math_constants >= 201907L
		#define LBAL_LIBCPP20_MATH_CONSTANTS __cpp_lib_math_constants
	#endif
#endif	//	LBAL_LIBCPP20_MATH_CONSTANTS

#if !defined (LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE)
	#if __cpp_lib_is_nothrow_convertible >= 201806L
		#define LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE __cpp_lib_is_nothrow_convertible
	#endif
#endif	//	LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE

#if !defined (LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR)
	#if __cpp_lib_polymorphic_allocator >= 201902L
		#define LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR \
				__cpp_lib_polymorphic_allocator
	#endif
#endif	//	LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR

#if !defined (LBAL_LIBCPP20_RANGES)
	#if __cpp_lib_ranges >= 201811L
		#define LBAL_LIBCPP20_RANGES __cpp_lib_ranges
	#endif
#endif	//	LBAL_LIBCPP20_RANGES

#if !defined (LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS)
	#if __cpp_lib_ranges >= 201907L
		#define LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS __cpp_lib_ranges
	#endif
#endif	//	LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS

#if !defined (LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE)
	#if __cpp_lib_ranges >= 201911L
		#define LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE __cpp_lib_ranges
	#endif
#endif	//	LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE

#if !defined (LBAL_LIBCPP20_REMOVE_CVREF)
	#if __cpp_lib_remove_cvref >= 201711L
		#define LBAL_LIBCPP20_REMOVE_CVREF __cpp_lib_remove_cvref
	#endif
#endif	//	LBAL_LIBCPP20_REMOVE_CVREF

#if !defined (LBAL_LIBCPP20_SEMAPHORE)
	#if __cpp_lib_semaphore >= 201907L
		#define LBAL_LIBCPP20_SEMAPHORE __cpp_lib_semaphore
	#endif
#endif	//	LBAL_LIBCPP20_SEMAPHORE

#if !defined (LBAL_LIBCPP20_SHARED_PTR_ARRAYS)
	#if __cpp_lib_shared_ptr_arrays >= 201707L
		#define LBAL_LIBCPP20_SHARED_PTR_ARRAYS __cpp_lib_shared_ptr_arrays
	#endif
#endif	//	LBAL_LIBCPP20_SHARED_PTR_ARRAYS

#if !defined (LBAL_LIBCPP20_SHIFT)
	#if __cpp_lib_shift >= 201806L
		#define LBAL_LIBCPP20_SHIFT __cpp_lib_shift
	#endif
#endif	//	LBAL_LIBCPP20_SHIFT

#if !defined (LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE)
	#if __cpp_lib_smart_ptr_for_overwrite >= 202002L
		#define LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE \
				__cpp_lib_smart_ptr_for_overwrite
	#endif
#endif	//	LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE

#if !defined (LBAL_LIBCPP20_SOURCE_LOCATION)
	#if __cpp_lib_source_location >= 201907L
		#define LBAL_LIBCPP20_SOURCE_LOCATION __cpp_lib_source_location
	#endif
#endif	//	LBAL_LIBCPP20_SOURCE_LOCATION

#if !defined (LBAL_LIBCPP20_SPAN)
	#if __cpp_lib_span >= 201803L
		#define LBAL_LIBCPP20_SPAN __cpp_lib_span
	#endif
#endif	//	LBAL_LIBCPP20_SPAN

#if !defined (LBAL_LIBCPP20_SPAN_USABILITY)
	#if __cpp_lib_span >= 201803L
		#define LBAL_LIBCPP20_SPAN_USABILITY __cpp_lib_span
	#endif
#endif	//	LBAL_LIBCPP20_SPAN_USABILITY

#if !defined (LBAL_LIBCPP20_SPAN_FIXED_SIZE)
	#if __cpp_lib_span >= 202002L
		#define LBAL_LIBCPP20_SPAN_FIXED_SIZE __cpp_lib_span
	#endif
#endif	//	LBAL_LIBCPP20_SPAN_FIXED_SIZE

#if !defined (LBAL_LIBCPP20_SSIZE)
	#if __cpp_lib_ssize >= 201902L
		#define LBAL_LIBCPP20_SSIZE __cpp_lib_ssize
	#endif
#endif	//	LBAL_LIBCPP20_SSIZE

#if !defined (LBAL_LIBCPP20_STARTS_ENDS_WITH)
	#if __cpp_lib_starts_ends_with >= 201711L
		#define LBAL_LIBCPP20_STARTS_ENDS_WITH __cpp_lib_starts_ends_with
	#endif
#endif	//	LBAL_LIBCPP20_STARTS_ENDS_WITH

#if !defined (LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR)
	#if __cpp_lib_string_view >= 201803L
		#define LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR \
				__cpp_lib_string_view
	#endif
#endif	//	LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR

#if !defined (LBAL_LIBCPP20_SYNCBUF)
	#if __cpp_lib_syncbuf >= 201711L
		#define LBAL_LIBCPP20_SYNCBUF __cpp_lib_syncbuf
	#endif
#endif	//	LBAL_LIBCPP20_SYNCBUF

#if !defined (LBAL_LIBCPP20_SYNCBUF_MANIPULATORS)
	#if __cpp_lib_syncbuf >= 201803L
		#define LBAL_LIBCPP20_SYNCBUF_MANIPULATORS __cpp_lib_syncbuf
	#endif
#endif	//	LBAL_LIBCPP20_SYNCBUF_MANIPULATORS

#if !defined (LBAL_LIBCPP20_THREE_WAY_COMPARISON)
	#if __cpp_lib_three_way_comparison >= 201711L
		#define LBAL_LIBCPP20_THREE_WAY_COMPARISON \
				__cpp_lib_three_way_comparison
	#endif
#endif	//	LBAL_LIBCPP20_THREE_WAY_COMPARISON

#if !defined (LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY)
	#if __cpp_lib_three_way_comparison >= 201907L
		#define LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY \
				__cpp_lib_three_way_comparison
	#endif
#endif	//	LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY

#if !defined (LBAL_LIBCPP20_TO_ADDRESS)
	#if __cpp_lib_to_address >= 201711L
		#define LBAL_LIBCPP20_TO_ADDRESS __cpp_lib_to_address
	#endif
#endif	//	LBAL_LIBCPP20_TO_ADDRESS

#if !defined (LBAL_LIBCPP20_TO_ARRAY)
	#if __cpp_lib_to_array >= 201907L
		#define LBAL_LIBCPP20_TO_ARRAY __cpp_lib_to_array
	#endif
#endif	//	LBAL_LIBCPP20_TO_ARRAY

#if !defined (LBAL_LIBCPP20_TYPE_IDENTITY)
	#if __cpp_lib_type_identity >= 201806L
		#define LBAL_LIBCPP20_TYPE_IDENTITY __cpp_lib_type_identity
	#endif
#endif	//	LBAL_LIBCPP20_TYPE_IDENTITY

#if !defined (LBAL_LIBCPP20_UNWRAP_REF)
	#if __cpp_lib_unwrap_ref >= 201811L
		#define LBAL_LIBCPP20_UNWRAP_REF __cpp_lib_unwrap_ref
	#endif
#endif	//	LBAL_LIBCPP20_UNWRAP_REF


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

	__SEEME__ There are quite a few of these checks, but it’s unclear how
	expensive they actually are. We could optimize by checking for the presence
	of each header of interest once and caching the results, but that seems
	like the sort of trivial thing the compiler is already doing. For that
	matter, we could offer an option to skip header checks entirely and avoid
	the disk hits, if any; but that seems heavy-handed in the absence of
	evidence of a negative impact.
*/

#if LBAL_LIBCPP14_CHRONO_UDLS
	#if defined (__has_include)
		#if !__has_include (<chrono>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_CHRONO_UDLS
			LBAL_CPP_WARNING ("<chrono> not found")
		#endif	//	<chrono> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP14_CHRONO_UDLS
			#define LBAL_LIBCPP14_CHRONO_UDLS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP14_CHRONO_UDLS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP14_CHRONO_UDLS


#if LBAL_LIBCPP14_COMPLEX_UDLS
	#if defined (__has_include)
		#if !__has_include (<complex>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_COMPLEX_UDLS
			LBAL_CPP_WARNING ("<complex> not found")
		#endif	//	<complex> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP14_COMPLEX_UDLS
			#define LBAL_LIBCPP14_COMPLEX_UDLS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP14_COMPLEX_UDLS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP14_COMPLEX_UDLS


#if LBAL_LIBCPP14_EXCHANGE_FUNCTION
	#if defined (__has_include)
		#if !__has_include (<utility>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_EXCHANGE_FUNCTION
			LBAL_CPP_WARNING ("<utility> not found")
		#endif	//	<utility> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP14_EXCHANGE_FUNCTION
			#define LBAL_LIBCPP14_EXCHANGE_FUNCTION 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP14_EXCHANGE_FUNCTION")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP14_EXCHANGE_FUNCTION


#if LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP
	#if defined (__has_include)
		#if !__has_include (<map>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP
			LBAL_CPP_WARNING ("<map> not found")
		#endif	//	<map> test

		#if !__has_include (<set>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP
			LBAL_CPP_WARNING ("<set> not found")
		#endif	//	<set> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP
			#define LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP


#if LBAL_LIBCPP14_INTEGER_SEQUENCE
	#if defined (__has_include)
		#if !__has_include (<utility>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_INTEGER_SEQUENCE
			LBAL_CPP_WARNING ("<utility> not found")
		#endif	//	<utility> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP14_INTEGER_SEQUENCE
			#define LBAL_LIBCPP14_INTEGER_SEQUENCE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP14_INTEGER_SEQUENCE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP14_INTEGER_SEQUENCE


#if LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE
	#if defined (__has_include)
		#if !__has_include (<type_traits>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE
			LBAL_CPP_WARNING ("<type_traits> not found")
		#endif	//	<type_traits> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE
			#define LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE


#if LBAL_LIBCPP14_IS_FINAL
	#if defined (__has_include)
		#if !__has_include (<type_traits>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_IS_FINAL
			LBAL_CPP_WARNING ("<type_traits> not found")
		#endif	//	<type_traits> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP14_IS_FINAL
			#define LBAL_LIBCPP14_IS_FINAL 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP14_IS_FINAL")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP14_IS_FINAL


#if LBAL_LIBCPP14_IS_NULL_POINTER
	#if defined (__has_include)
		#if !__has_include (<type_traits>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_IS_NULL_POINTER
			LBAL_CPP_WARNING ("<type_traits> not found")
		#endif	//	<type_traits> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP14_IS_NULL_POINTER
			#define LBAL_LIBCPP14_IS_NULL_POINTER 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP14_IS_NULL_POINTER")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP14_IS_NULL_POINTER


#if LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR
	#if defined (__has_include)
		#if !__has_include (<iterator>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR
			LBAL_CPP_WARNING ("<iterator> not found")
		#endif	//	<iterator> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR
			#define LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR


#if LBAL_LIBCPP14_MAKE_UNIQUE
	#if defined (__has_include)
		#if !__has_include (<memory>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_MAKE_UNIQUE
			LBAL_CPP_WARNING ("<memory> not found")
		#endif	//	<memory> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP14_MAKE_UNIQUE
			#define LBAL_LIBCPP14_MAKE_UNIQUE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP14_MAKE_UNIQUE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP14_MAKE_UNIQUE


#if LBAL_LIBCPP14_NULL_ITERATORS
	#if defined (__has_include)
		#if !__has_include (<iterator>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_NULL_ITERATORS
			LBAL_CPP_WARNING ("<iterator> not found")
		#endif	//	<iterator> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP14_NULL_ITERATORS
			#define LBAL_LIBCPP14_NULL_ITERATORS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP14_NULL_ITERATORS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP14_NULL_ITERATORS


#if LBAL_LIBCPP14_QUOTED_STRING_IO
	#if defined (__has_include)
		#if !__has_include (<iomanip>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_QUOTED_STRING_IO
			LBAL_CPP_WARNING ("<iomanip> not found")
		#endif	//	<iomanip> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP14_QUOTED_STRING_IO
			#define LBAL_LIBCPP14_QUOTED_STRING_IO 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP14_QUOTED_STRING_IO")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP14_QUOTED_STRING_IO


#if LBAL_LIBCPP14_RESULT_OF_SFINAE
	#if defined (__has_include)
		#if !__has_include (<functional>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_RESULT_OF_SFINAE
			LBAL_CPP_WARNING ("<functional> not found")
		#endif	//	<functional> test

		#if !__has_include (<type_traits>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_RESULT_OF_SFINAE
			LBAL_CPP_WARNING ("<type_traits> not found")
		#endif	//	<type_traits> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP14_RESULT_OF_SFINAE
			#define LBAL_LIBCPP14_RESULT_OF_SFINAE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP14_RESULT_OF_SFINAE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP14_RESULT_OF_SFINAE


#if LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS
	#if defined (__has_include)
		#if !__has_include (<algorithm>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS
			LBAL_CPP_WARNING ("<algorithm> not found")
		#endif	//	<algorithm> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS
			#define LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS


#if LBAL_LIBCPP14_SHARED_TIMED_MUTEX
	#if defined (__has_include)
		#if !__has_include (<shared_mutex>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_SHARED_TIMED_MUTEX
			LBAL_CPP_WARNING ("<shared_mutex> not found")
		#endif	//	<shared_mutex> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP14_SHARED_TIMED_MUTEX
			#define LBAL_LIBCPP14_SHARED_TIMED_MUTEX 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP14_SHARED_TIMED_MUTEX")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP14_SHARED_TIMED_MUTEX


#if LBAL_LIBCPP14_STRING_UDLS
	#if defined (__has_include)
		#if !__has_include (<string>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_STRING_UDLS
			LBAL_CPP_WARNING ("<string> not found")
		#endif	//	<string> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP14_STRING_UDLS
			#define LBAL_LIBCPP14_STRING_UDLS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP14_STRING_UDLS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP14_STRING_UDLS


#if LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES
	#if defined (__has_include)
		#if !__has_include (<type_traits>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES
			LBAL_CPP_WARNING ("<type_traits> not found")
		#endif	//	<type_traits> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES
			#define LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES


#if LBAL_LIBCPP14_TRANSPARENT_OPERATORS
	#if defined (__has_include)
		#if !__has_include (<functional>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_TRANSPARENT_OPERATORS
			LBAL_CPP_WARNING ("<functional> not found")
		#endif	//	<functional> test

		#if !__has_include (<memory>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_TRANSPARENT_OPERATORS
			LBAL_CPP_WARNING ("<memory> not found")
		#endif	//	<memory> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP14_TRANSPARENT_OPERATORS
			#define LBAL_LIBCPP14_TRANSPARENT_OPERATORS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP14_TRANSPARENT_OPERATORS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP14_TRANSPARENT_OPERATORS


#if LBAL_LIBCPP14_TUPLE_ELEMENT_T
	#if defined (__has_include)
		#if !__has_include (<tuple>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_TUPLE_ELEMENT_T
			LBAL_CPP_WARNING ("<tuple> not found")
		#endif	//	<tuple> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP14_TUPLE_ELEMENT_T
			#define LBAL_LIBCPP14_TUPLE_ELEMENT_T 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP14_TUPLE_ELEMENT_T")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP14_TUPLE_ELEMENT_T


#if LBAL_LIBCPP14_TUPLES_BY_TYPE
	#if defined (__has_include)
		#if !__has_include (<tuple>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_TUPLES_BY_TYPE
			LBAL_CPP_WARNING ("<tuple> not found")
		#endif	//	<tuple> test

		#if !__has_include (<utility>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP14_TUPLES_BY_TYPE
			LBAL_CPP_WARNING ("<utility> not found")
		#endif	//	<utility> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP14_TUPLES_BY_TYPE
			#define LBAL_LIBCPP14_TUPLES_BY_TYPE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP14_TUPLES_BY_TYPE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP14_TUPLES_BY_TYPE


#if LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR
	#if defined (__has_include)
		#if !__has_include (<memory>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR
			LBAL_CPP_WARNING ("<memory> not found")
		#endif	//	<memory> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR
			#define LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR


#if LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL
	#if defined (__has_include)
		#if !__has_include (<deque>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL
			LBAL_CPP_WARNING ("<deque> not found")
		#endif	//	<deque> test

		#if !__has_include (<forward_list>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL
			LBAL_CPP_WARNING ("<forward_list> not found")
		#endif	//	<forward_list> test

		#if !__has_include (<list>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL
			LBAL_CPP_WARNING ("<list> not found")
		#endif	//	<list> test

		#if !__has_include (<map>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL
			LBAL_CPP_WARNING ("<map> not found")
		#endif	//	<map> test

		#if !__has_include (<memory>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL
			LBAL_CPP_WARNING ("<memory> not found")
		#endif	//	<memory> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL
			#define LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL


#if LBAL_LIBCPP17_ANY
	#if defined (__has_include)
		#if !__has_include (<any>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_ANY
			LBAL_CPP_WARNING ("<any> not found")
		#endif	//	<any> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_ANY
			#define LBAL_LIBCPP17_ANY 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_ANY")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_ANY


#if LBAL_LIBCPP17_ANY_INTERFACE
	#if defined (__has_include)
		#if !__has_include (<any>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_ANY_INTERFACE
			LBAL_CPP_WARNING ("<any> not found")
		#endif	//	<any> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_ANY_INTERFACE
			#define LBAL_LIBCPP17_ANY_INTERFACE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_ANY_INTERFACE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_ANY_INTERFACE


#if LBAL_LIBCPP17_APPLY
	#if defined (__has_include)
		#if !__has_include (<tuple>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_APPLY
			LBAL_CPP_WARNING ("<tuple> not found")
		#endif	//	<tuple> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_APPLY
			#define LBAL_LIBCPP17_APPLY 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_APPLY")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_APPLY


#if LBAL_LIBCPP17_ARRAY_CONSTEXPR
	#if defined (__has_include)
		#if !__has_include (<array>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_ARRAY_CONSTEXPR
			LBAL_CPP_WARNING ("<array> not found")
		#endif	//	<array> test

		#if !__has_include (<iterator>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_ARRAY_CONSTEXPR
			LBAL_CPP_WARNING ("<iterator> not found")
		#endif	//	<iterator> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_ARRAY_CONSTEXPR
			#define LBAL_LIBCPP17_ARRAY_CONSTEXPR 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_ARRAY_CONSTEXPR")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_ARRAY_CONSTEXPR


#if LBAL_LIBCPP17_AS_CONST
	#if defined (__has_include)
		#if !__has_include (<utility>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_AS_CONST
			LBAL_CPP_WARNING ("<utility> not found")
		#endif	//	<utility> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_AS_CONST
			#define LBAL_LIBCPP17_AS_CONST 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_AS_CONST")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_AS_CONST


#if LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE
	#if defined (__has_include)
		#if !__has_include (<atomic>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE
			LBAL_CPP_WARNING ("<atomic> not found")
		#endif	//	<atomic> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE
			#define LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE


#if LBAL_LIBCPP17_BOOL_CONSTANT
	#if defined (__has_include)
		#if !__has_include (<type_traits>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_BOOL_CONSTANT
			LBAL_CPP_WARNING ("<type_traits> not found")
		#endif	//	<type_traits> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_BOOL_CONSTANT
			#define LBAL_LIBCPP17_BOOL_CONSTANT 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_BOOL_CONSTANT")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_BOOL_CONSTANT


#if LBAL_LIBCPP17_BOYER_MOORE_SEARCHER
	#if defined (__has_include)
		#if !__has_include (<functional>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_BOYER_MOORE_SEARCHER
			LBAL_CPP_WARNING ("<functional> not found")
		#endif	//	<functional> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_BOYER_MOORE_SEARCHER
			#define LBAL_LIBCPP17_BOYER_MOORE_SEARCHER 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_BOYER_MOORE_SEARCHER")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_BOYER_MOORE_SEARCHER


#if LBAL_LIBCPP17_BYTE
	#if defined (__has_include)
		#if !__has_include (<cstddef>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_BYTE
			LBAL_CPP_WARNING ("<cstddef> not found")
		#endif	//	<cstddef> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_BYTE
			#define LBAL_LIBCPP17_BYTE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_BYTE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_BYTE


#if LBAL_LIBCPP17_CHRONO
	#if defined (__has_include)
		#if !__has_include (<chrono>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_CHRONO
			LBAL_CPP_WARNING ("<chrono> not found")
		#endif	//	<chrono> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_CHRONO
			#define LBAL_LIBCPP17_CHRONO 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_CHRONO")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_CHRONO


#if LBAL_LIBCPP17_CHRONO_CONSTEXPR
	#if defined (__has_include)
		#if !__has_include (<chrono>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_CHRONO_CONSTEXPR
			LBAL_CPP_WARNING ("<chrono> not found")
		#endif	//	<chrono> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_CHRONO_CONSTEXPR
			#define LBAL_LIBCPP17_CHRONO_CONSTEXPR 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_CHRONO_CONSTEXPR")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_CHRONO_CONSTEXPR


#if LBAL_LIBCPP17_CLAMP
	#if defined (__has_include)
		#if !__has_include (<algorithm>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_CLAMP
			LBAL_CPP_WARNING ("<algorithm> not found")
		#endif	//	<algorithm> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_CLAMP
			#define LBAL_LIBCPP17_CLAMP 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_CLAMP")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_CLAMP


#if LBAL_LIBCPP17_CONSTEXPR_STRING
	#if defined (__has_include)
		#if !__has_include (<string>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_CONSTEXPR_STRING
			LBAL_CPP_WARNING ("<string> not found")
		#endif	//	<string> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_CONSTEXPR_STRING
			#define LBAL_LIBCPP17_CONSTEXPR_STRING 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_CONSTEXPR_STRING")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_CONSTEXPR_STRING


#if LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW
	#if defined (__has_include)
		#if !__has_include (<string_view>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW
			LBAL_CPP_WARNING ("<string_view> not found")
		#endif	//	<string_view> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW
			#define LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW


#if LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS
	#if defined (__has_include)
		#if !__has_include (<memory>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS
			LBAL_CPP_WARNING ("<memory> not found")
		#endif	//	<memory> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS
			#define LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS


#if LBAL_LIBCPP17_EXECUTION
	#if defined (__has_include)
		#if !__has_include (<execution>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_EXECUTION
			LBAL_CPP_WARNING ("<execution> not found")
		#endif	//	<execution> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_EXECUTION
			#define LBAL_LIBCPP17_EXECUTION 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_EXECUTION")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_EXECUTION


#if LBAL_LIBCPP17_FILESYSTEM
	#if defined (__has_include)
		#if !__has_include (<filesystem>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_FILESYSTEM
			LBAL_CPP_WARNING ("<filesystem> not found")
		#endif	//	<filesystem> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_FILESYSTEM
			#define LBAL_LIBCPP17_FILESYSTEM 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_FILESYSTEM")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_FILESYSTEM


#if LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED
	#if defined (__has_include)
		#if !__has_include (<filesystem>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED
			LBAL_CPP_WARNING ("<filesystem> not found")
		#endif	//	<filesystem> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED
			#define LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED


#if LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING
	#if defined (__has_include)
		#if !__has_include (<filesystem>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING
			LBAL_CPP_WARNING ("<filesystem> not found")
		#endif	//	<filesystem> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING
			#define LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING


#if LBAL_LIBCPP17_FILESYSTEM_EXP
	#if defined (__has_include)
		#if !__has_include (<filesystem>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_FILESYSTEM_EXP
			LBAL_CPP_WARNING ("<filesystem> not found")
		#endif	//	<filesystem> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_FILESYSTEM_EXP
			#define LBAL_LIBCPP17_FILESYSTEM_EXP 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_FILESYSTEM_EXP")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_FILESYSTEM_EXP


#if LBAL_LIBCPP17_GCD_LCM
	#if defined (__has_include)
		#if !__has_include (<numeric>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_GCD_LCM
			LBAL_CPP_WARNING ("<numeric> not found")
		#endif	//	<numeric> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_GCD_LCM
			#define LBAL_LIBCPP17_GCD_LCM 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_GCD_LCM")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_GCD_LCM


#if LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE
	#if defined (__has_include)
		#if !__has_include (<new>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE
			LBAL_CPP_WARNING ("<new> not found")
		#endif	//	<new> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE
			#define LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE


#if LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS
	#if defined (__has_include)
		#if !__has_include (<type_traits>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS
			LBAL_CPP_WARNING ("<type_traits> not found")
		#endif	//	<type_traits> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS
			#define LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS


#if LBAL_LIBCPP17_HYPOT
	#if defined (__has_include)
		#if !__has_include (<cmath>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_HYPOT
			LBAL_CPP_WARNING ("<cmath> not found")
		#endif	//	<cmath> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_HYPOT
			#define LBAL_LIBCPP17_HYPOT 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_HYPOT")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_HYPOT


#if LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS
	#if defined (__has_include)
		#if !__has_include (<forward_list>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS
			LBAL_CPP_WARNING ("<forward_list> not found")
		#endif	//	<forward_list> test

		#if !__has_include (<list>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS
			LBAL_CPP_WARNING ("<list> not found")
		#endif	//	<list> test

		#if !__has_include (<vector>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS
			LBAL_CPP_WARNING ("<vector> not found")
		#endif	//	<vector> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS
			#define LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS


#if LBAL_LIBCPP17_INVOKE
	#if defined (__has_include)
		#if !__has_include (<functional>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_INVOKE
			LBAL_CPP_WARNING ("<functional> not found")
		#endif	//	<functional> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_INVOKE
			#define LBAL_LIBCPP17_INVOKE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_INVOKE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_INVOKE


#if LBAL_LIBCPP17_IS_AGGREGATE
	#if defined (__has_include)
		#if !__has_include (<type_traits>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_IS_AGGREGATE
			LBAL_CPP_WARNING ("<type_traits> not found")
		#endif	//	<type_traits> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_IS_AGGREGATE
			#define LBAL_LIBCPP17_IS_AGGREGATE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_IS_AGGREGATE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_IS_AGGREGATE


#if LBAL_LIBCPP17_IS_INVOCABLE
	#if defined (__has_include)
		#if !__has_include (<type_traits>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_IS_INVOCABLE
			LBAL_CPP_WARNING ("<type_traits> not found")
		#endif	//	<type_traits> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_IS_INVOCABLE
			#define LBAL_LIBCPP17_IS_INVOCABLE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_IS_INVOCABLE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_IS_INVOCABLE


#if LBAL_LIBCPP17_IS_SWAPPABLE
	#if defined (__has_include)
		#if !__has_include (<type_traits>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_IS_SWAPPABLE
			LBAL_CPP_WARNING ("<type_traits> not found")
		#endif	//	<type_traits> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_IS_SWAPPABLE
			#define LBAL_LIBCPP17_IS_SWAPPABLE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_IS_SWAPPABLE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_IS_SWAPPABLE


#if LBAL_LIBCPP17_LAUNDER
	#if defined (__has_include)
		#if !__has_include (<new>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_LAUNDER
			LBAL_CPP_WARNING ("<new> not found")
		#endif	//	<new> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_LAUNDER
			#define LBAL_LIBCPP17_LAUNDER 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_LAUNDER")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_LAUNDER


#if LBAL_LIBCPP17_LOGICAL_TRAITS
	#if defined (__has_include)
		#if !__has_include (<type_traits>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_LOGICAL_TRAITS
			LBAL_CPP_WARNING ("<type_traits> not found")
		#endif	//	<type_traits> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_LOGICAL_TRAITS
			#define LBAL_LIBCPP17_LOGICAL_TRAITS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_LOGICAL_TRAITS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_LOGICAL_TRAITS


#if LBAL_LIBCPP17_MAKE_FROM_TUPLE
	#if defined (__has_include)
		#if !__has_include (<tuple>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_MAKE_FROM_TUPLE
			LBAL_CPP_WARNING ("<tuple> not found")
		#endif	//	<tuple> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_MAKE_FROM_TUPLE
			#define LBAL_LIBCPP17_MAKE_FROM_TUPLE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_MAKE_FROM_TUPLE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_MAKE_FROM_TUPLE


#if LBAL_LIBCPP17_MAP_TRY_EMPLACE
	#if defined (__has_include)
		#if !__has_include (<map>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_MAP_TRY_EMPLACE
			LBAL_CPP_WARNING ("<map> not found")
		#endif	//	<map> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_MAP_TRY_EMPLACE
			#define LBAL_LIBCPP17_MAP_TRY_EMPLACE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_MAP_TRY_EMPLACE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_MAP_TRY_EMPLACE


#if LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS
	#if defined (__has_include)
		#if !__has_include (<cmath>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS
			LBAL_CPP_WARNING ("<cmath> not found")
		#endif	//	<cmath> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS
			#define LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS


#if LBAL_LIBCPP17_MEMORY_RESOURCE
	#if defined (__has_include)
		#if !__has_include (<memory_resource>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_MEMORY_RESOURCE
			LBAL_CPP_WARNING ("<memory_resource> not found")
		#endif	//	<memory_resource> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_MEMORY_RESOURCE
			#define LBAL_LIBCPP17_MEMORY_RESOURCE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_MEMORY_RESOURCE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_MEMORY_RESOURCE


#if LBAL_LIBCPP17_NODE_EXTRACT
	#if defined (__has_include)
		#if !__has_include (<map>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_NODE_EXTRACT
			LBAL_CPP_WARNING ("<map> not found")
		#endif	//	<map> test

		#if !__has_include (<set>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_NODE_EXTRACT
			LBAL_CPP_WARNING ("<set> not found")
		#endif	//	<set> test

		#if !__has_include (<unordered_map>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_NODE_EXTRACT
			LBAL_CPP_WARNING ("<unordered_map> not found")
		#endif	//	<unordered_map> test

		#if !__has_include (<unordered_set>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_NODE_EXTRACT
			LBAL_CPP_WARNING ("<unordered_set> not found")
		#endif	//	<unordered_set> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_NODE_EXTRACT
			#define LBAL_LIBCPP17_NODE_EXTRACT 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_NODE_EXTRACT")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_NODE_EXTRACT


#if LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS
	#if defined (__has_include)
		#if !__has_include (<array>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS
			LBAL_CPP_WARNING ("<array> not found")
		#endif	//	<array> test

		#if !__has_include (<deque>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS
			LBAL_CPP_WARNING ("<deque> not found")
		#endif	//	<deque> test

		#if !__has_include (<forward_list>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS
			LBAL_CPP_WARNING ("<forward_list> not found")
		#endif	//	<forward_list> test

		#if !__has_include (<iterator>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS
			LBAL_CPP_WARNING ("<iterator> not found")
		#endif	//	<iterator> test

		#if !__has_include (<list>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS
			LBAL_CPP_WARNING ("<list> not found")
		#endif	//	<list> test

		#if !__has_include (<map>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS
			LBAL_CPP_WARNING ("<map> not found")
		#endif	//	<map> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS
			#define LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS


#if LBAL_LIBCPP17_NOT_FN
	#if defined (__has_include)
		#if !__has_include (<functional>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_NOT_FN
			LBAL_CPP_WARNING ("<functional> not found")
		#endif	//	<functional> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_NOT_FN
			#define LBAL_LIBCPP17_NOT_FN 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_NOT_FN")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_NOT_FN


#if LBAL_LIBCPP17_OPTIONAL
	#if defined (__has_include)
		#if !__has_include (<optional>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_OPTIONAL
			LBAL_CPP_WARNING ("<optional> not found")
		#endif	//	<optional> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_OPTIONAL
			#define LBAL_LIBCPP17_OPTIONAL 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_OPTIONAL")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_OPTIONAL


#if LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL
	#if defined (__has_include)
		#if !__has_include (<optional>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL
			LBAL_CPP_WARNING ("<optional> not found")
		#endif	//	<optional> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL
			#define LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL


#if LBAL_LIBCPP17_OPTIONAL_INTERFACE
	#if defined (__has_include)
		#if !__has_include (<optional>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_OPTIONAL_INTERFACE
			LBAL_CPP_WARNING ("<optional> not found")
		#endif	//	<optional> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_OPTIONAL_INTERFACE
			#define LBAL_LIBCPP17_OPTIONAL_INTERFACE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_OPTIONAL_INTERFACE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_OPTIONAL_INTERFACE


#if LBAL_LIBCPP17_PARALLEL_ALGORITHM
	#if defined (__has_include)
		#if !__has_include (<algorithm>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_PARALLEL_ALGORITHM
			LBAL_CPP_WARNING ("<algorithm> not found")
		#endif	//	<algorithm> test

		#if !__has_include (<numeric>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_PARALLEL_ALGORITHM
			LBAL_CPP_WARNING ("<numeric> not found")
		#endif	//	<numeric> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_PARALLEL_ALGORITHM
			#define LBAL_LIBCPP17_PARALLEL_ALGORITHM 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_PARALLEL_ALGORITHM")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_PARALLEL_ALGORITHM


#if LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS
	#if defined (__has_include)
		#if !__has_include (<memory>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS
			LBAL_CPP_WARNING ("<memory> not found")
		#endif	//	<memory> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS
			#define LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS


#if LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS
	#if defined (__has_include)
		#if !__has_include (<algorithm>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS
			LBAL_CPP_WARNING ("<algorithm> not found")
		#endif	//	<algorithm> test

		#if !__has_include (<execution>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS
			LBAL_CPP_WARNING ("<execution> not found")
		#endif	//	<execution> test

		#if !__has_include (<numeric>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS
			LBAL_CPP_WARNING ("<numeric> not found")
		#endif	//	<numeric> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS
			#define LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS


#if LBAL_LIBCPP17_SAMPLE
	#if defined (__has_include)
		#if !__has_include (<algorithm>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_SAMPLE
			LBAL_CPP_WARNING ("<algorithm> not found")
		#endif	//	<algorithm> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_SAMPLE
			#define LBAL_LIBCPP17_SAMPLE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_SAMPLE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_SAMPLE


#if LBAL_LIBCPP17_SCOPED_LOCK
	#if defined (__has_include)
		#if !__has_include (<mutex>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_SCOPED_LOCK
			LBAL_CPP_WARNING ("<mutex> not found")
		#endif	//	<mutex> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_SCOPED_LOCK
			#define LBAL_LIBCPP17_SCOPED_LOCK 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_SCOPED_LOCK")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_SCOPED_LOCK


#if LBAL_LIBCPP17_SHARED_MUTEX
	#if defined (__has_include)
		#if !__has_include (<shared_mutex>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_SHARED_MUTEX
			LBAL_CPP_WARNING ("<shared_mutex> not found")
		#endif	//	<shared_mutex> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_SHARED_MUTEX
			#define LBAL_LIBCPP17_SHARED_MUTEX 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_SHARED_MUTEX")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_SHARED_MUTEX


#if LBAL_LIBCPP17_SHARED_PTR_ARRAYS
	#if defined (__has_include)
		#if !__has_include (<memory>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_SHARED_PTR_ARRAYS
			LBAL_CPP_WARNING ("<memory> not found")
		#endif	//	<memory> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_SHARED_PTR_ARRAYS
			#define LBAL_LIBCPP17_SHARED_PTR_ARRAYS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_SHARED_PTR_ARRAYS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_SHARED_PTR_ARRAYS


#if LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE
	#if defined (__has_include)
		#if !__has_include (<memory>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE
			LBAL_CPP_WARNING ("<memory> not found")
		#endif	//	<memory> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE
			#define LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE


#if LBAL_LIBCPP17_STRING_VIEW
	#if defined (__has_include)
		#if !__has_include (<string>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_STRING_VIEW
			LBAL_CPP_WARNING ("<string> not found")
		#endif	//	<string> test

		#if !__has_include (<string_view>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_STRING_VIEW
			LBAL_CPP_WARNING ("<string_view> not found")
		#endif	//	<string_view> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_STRING_VIEW
			#define LBAL_LIBCPP17_STRING_VIEW 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_STRING_VIEW")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_STRING_VIEW


#if LBAL_LIBCPP17_STRING_VIEW_INTERFACE
	#if defined (__has_include)
		#if !__has_include (<string>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_STRING_VIEW_INTERFACE
			LBAL_CPP_WARNING ("<string> not found")
		#endif	//	<string> test

		#if !__has_include (<string_view>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_STRING_VIEW_INTERFACE
			LBAL_CPP_WARNING ("<string_view> not found")
		#endif	//	<string_view> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_STRING_VIEW_INTERFACE
			#define LBAL_LIBCPP17_STRING_VIEW_INTERFACE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_STRING_VIEW_INTERFACE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_STRING_VIEW_INTERFACE


#if LBAL_LIBCPP17_TO_CHARS
	#if defined (__has_include)
		#if !__has_include (<charconv>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_TO_CHARS
			LBAL_CPP_WARNING ("<charconv> not found")
		#endif	//	<charconv> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_TO_CHARS
			#define LBAL_LIBCPP17_TO_CHARS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_TO_CHARS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_TO_CHARS


#if LBAL_LIBCPP17_TO_CHARS_FP
	#if defined (__has_include)
		#if !__has_include (<charconv>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_TO_CHARS_FP
			LBAL_CPP_WARNING ("<charconv> not found")
		#endif	//	<charconv> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_TO_CHARS_FP
			#define LBAL_LIBCPP17_TO_CHARS_FP 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_TO_CHARS_FP")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_TO_CHARS_FP


#if LBAL_LIBCPP17_TO_CHARS_INTEGER
	#if defined (__has_include)
		#if !__has_include (<charconv>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_TO_CHARS_INTEGER
			LBAL_CPP_WARNING ("<charconv> not found")
		#endif	//	<charconv> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_TO_CHARS_INTEGER
			#define LBAL_LIBCPP17_TO_CHARS_INTEGER 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_TO_CHARS_INTEGER")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_TO_CHARS_INTEGER


#if LBAL_LIBCPP17_TRANSPARENT_OPERATORS
	#if defined (__has_include)
		#if !__has_include (<functional>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_TRANSPARENT_OPERATORS
			LBAL_CPP_WARNING ("<functional> not found")
		#endif	//	<functional> test

		#if !__has_include (<memory>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_TRANSPARENT_OPERATORS
			LBAL_CPP_WARNING ("<memory> not found")
		#endif	//	<memory> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_TRANSPARENT_OPERATORS
			#define LBAL_LIBCPP17_TRANSPARENT_OPERATORS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_TRANSPARENT_OPERATORS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_TRANSPARENT_OPERATORS


#if LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES
	#if defined (__has_include)
		#if !__has_include (<type_traits>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES
			LBAL_CPP_WARNING ("<type_traits> not found")
		#endif	//	<type_traits> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES
			#define LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES


#if LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS
	#if defined (__has_include)
		#if !__has_include (<exception>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS
			LBAL_CPP_WARNING ("<exception> not found")
		#endif	//	<exception> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS
			#define LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS


#if LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE
	#if defined (__has_include)
		#if !__has_include (<unordered_map>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE
			LBAL_CPP_WARNING ("<unordered_map> not found")
		#endif	//	<unordered_map> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE
			#define LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE


#if LBAL_LIBCPP17_VARIANT
	#if defined (__has_include)
		#if !__has_include (<variant>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_VARIANT
			LBAL_CPP_WARNING ("<variant> not found")
		#endif	//	<variant> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_VARIANT
			#define LBAL_LIBCPP17_VARIANT 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_VARIANT")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_VARIANT


#if LBAL_LIBCPP17_VOID_T
	#if defined (__has_include)
		#if !__has_include (<type_traits>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP17_VOID_T
			LBAL_CPP_WARNING ("<type_traits> not found")
		#endif	//	<type_traits> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP17_VOID_T
			#define LBAL_LIBCPP17_VOID_T 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP17_VOID_T")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP17_VOID_T


#if LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR
	#if defined (__has_include)
		#if !__has_include (<array>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR
			LBAL_CPP_WARNING ("<array> not found")
		#endif	//	<array> test

		#if !__has_include (<iterator>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR
			LBAL_CPP_WARNING ("<iterator> not found")
		#endif	//	<iterator> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR
			#define LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR


#if LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS
	#if defined (__has_include)
		#if !__has_include (<array>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS
			LBAL_CPP_WARNING ("<array> not found")
		#endif	//	<array> test

		#if !__has_include (<iterator>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS
			LBAL_CPP_WARNING ("<iterator> not found")
		#endif	//	<iterator> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS
			#define LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS


#if LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES
	#if defined (__has_include)
		#if !__has_include (<array>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES
			LBAL_CPP_WARNING ("<array> not found")
		#endif	//	<array> test

		#if !__has_include (<iterator>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES
			LBAL_CPP_WARNING ("<iterator> not found")
		#endif	//	<iterator> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES
			#define LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES


#if LBAL_LIBCPP20_ASSUME_ALIGNED
	#if defined (__has_include)
		#if !__has_include (<memory>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ASSUME_ALIGNED
			LBAL_CPP_WARNING ("<memory> not found")
		#endif	//	<memory> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_ASSUME_ALIGNED
			#define LBAL_LIBCPP20_ASSUME_ALIGNED 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_ASSUME_ALIGNED")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_ASSUME_ALIGNED


#if LBAL_LIBCPP20_ATOMIC_FLAG_TEST
	#if defined (__has_include)
		#if !__has_include (<atomic>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ATOMIC_FLAG_TEST
			LBAL_CPP_WARNING ("<atomic> not found")
		#endif	//	<atomic> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_ATOMIC_FLAG_TEST
			#define LBAL_LIBCPP20_ATOMIC_FLAG_TEST 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_ATOMIC_FLAG_TEST")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_ATOMIC_FLAG_test
#if LBAL_LIBCPP20_ATOMIC_FLOAT
	#if defined (__has_include)
		#if !__has_include (<atomic>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ATOMIC_FLOAT
			LBAL_CPP_WARNING ("<atomic> not found")
		#endif	//	<atomic> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_ATOMIC_FLOAT
			#define LBAL_LIBCPP20_ATOMIC_FLOAT 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_ATOMIC_FLOAT")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_ATOMIC_FLOAT


#if LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES
	#if defined (__has_include)
		#if !__has_include (<atomic>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES
			LBAL_CPP_WARNING ("<atomic> not found")
		#endif	//	<atomic> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES
			#define LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES


#if LBAL_LIBCPP20_ATOMIC_REF
	#if defined (__has_include)
		#if !__has_include (<atomic>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ATOMIC_REF
			LBAL_CPP_WARNING ("<atomic> not found")
		#endif	//	<atomic> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_ATOMIC_REF
			#define LBAL_LIBCPP20_ATOMIC_REF 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_ATOMIC_REF")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_ATOMIC_REF


#if LBAL_LIBCPP20_ATOMIC_SHARED_PTR
	#if defined (__has_include)
		#if !__has_include (<memory>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ATOMIC_SHARED_PTR
			LBAL_CPP_WARNING ("<memory> not found")
		#endif	//	<memory> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_ATOMIC_SHARED_PTR
			#define LBAL_LIBCPP20_ATOMIC_SHARED_PTR 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_ATOMIC_SHARED_PTR")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_ATOMIC_SHARED_PTR


#if LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION
	#if defined (__has_include)
		#if !__has_include (<atomic>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION
			LBAL_CPP_WARNING ("<atomic> not found")
		#endif	//	<atomic> test

		#if !__has_include (<memory>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION
			LBAL_CPP_WARNING ("<memory> not found")
		#endif	//	<memory> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION
			#define LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION


#if LBAL_LIBCPP20_ATOMIC_WAIT
	#if defined (__has_include)
		#if !__has_include (<atomic>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ATOMIC_WAIT
			LBAL_CPP_WARNING ("<atomic> not found")
		#endif	//	<atomic> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_ATOMIC_WAIT
			#define LBAL_LIBCPP20_ATOMIC_WAIT 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_ATOMIC_WAIT")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_ATOMIC_WAIT


#if LBAL_LIBCPP20_BARRIER
	#if defined (__has_include)
		#if !__has_include (<barrier>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_BARRIER
			LBAL_CPP_WARNING ("<barrier> not found")
		#endif	//	<barrier> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_BARRIER
			#define LBAL_LIBCPP20_BARRIER 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_BARRIER")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_BARRIER


#if LBAL_LIBCPP20_BIND_FRONT
	#if defined (__has_include)
		#if !__has_include (<functional>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_BIND_FRONT
			LBAL_CPP_WARNING ("<functional> not found")
		#endif	//	<functional> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_BIND_FRONT
			#define LBAL_LIBCPP20_BIND_FRONT 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_BIND_FRONT")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_BIND_FRONT


#if LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP
	#if defined (__has_include)
		#if !__has_include (<functional>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP
			LBAL_CPP_WARNING ("<functional> not found")
		#endif	//	<functional> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP
			#define LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP


#if LBAL_LIBCPP20_BIT_CAST
	#if defined (__has_include)
		#if !__has_include (<bit>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_BIT_CAST
			LBAL_CPP_WARNING ("<bit> not found")
		#endif	//	<bit> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_BIT_CAST
			#define LBAL_LIBCPP20_BIT_CAST 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_BIT_CAST")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_BIT_CAST


#if LBAL_LIBCPP20_BITOPS
	#if defined (__has_include)
		#if !__has_include (<bit>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_BITOPS
			LBAL_CPP_WARNING ("<bit> not found")
		#endif	//	<bit> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_BITOPS
			#define LBAL_LIBCPP20_BITOPS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_BITOPS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_BITOPS


#if LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS
	#if defined (__has_include)
		#if !__has_include (<type_traits>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS
			LBAL_CPP_WARNING ("<type_traits> not found")
		#endif	//	<type_traits> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS
			#define LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS


#if LBAL_LIBCPP20_CHAR8_T
	#if defined (__has_include)
		#if !__has_include (<atomic>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CHAR8_T
			LBAL_CPP_WARNING ("<atomic> not found")
		#endif	//	<atomic> test

		#if !__has_include (<filesystem>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CHAR8_T
			LBAL_CPP_WARNING ("<filesystem> not found")
		#endif	//	<filesystem> test

		#if !__has_include (<istream>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CHAR8_T
			LBAL_CPP_WARNING ("<istream> not found")
		#endif	//	<istream> test

		#if !__has_include (<limits>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CHAR8_T
			LBAL_CPP_WARNING ("<limits> not found")
		#endif	//	<limits> test

		#if !__has_include (<locale>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CHAR8_T
			LBAL_CPP_WARNING ("<locale> not found")
		#endif	//	<locale> test

		#if !__has_include (<ostream>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CHAR8_T
			LBAL_CPP_WARNING ("<ostream> not found")
		#endif	//	<ostream> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_CHAR8_T
			#define LBAL_LIBCPP20_CHAR8_T 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_CHAR8_T")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_CHAR8_T


#if LBAL_LIBCPP20_CHAR8_T_COMPAT
	#if defined (__has_include)
		#if !__has_include (<atomic>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CHAR8_T_COMPAT
			LBAL_CPP_WARNING ("<atomic> not found")
		#endif	//	<atomic> test

		#if !__has_include (<filesystem>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CHAR8_T_COMPAT
			LBAL_CPP_WARNING ("<filesystem> not found")
		#endif	//	<filesystem> test

		#if !__has_include (<istream>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CHAR8_T_COMPAT
			LBAL_CPP_WARNING ("<istream> not found")
		#endif	//	<istream> test

		#if !__has_include (<limits>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CHAR8_T_COMPAT
			LBAL_CPP_WARNING ("<limits> not found")
		#endif	//	<limits> test

		#if !__has_include (<locale>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CHAR8_T_COMPAT
			LBAL_CPP_WARNING ("<locale> not found")
		#endif	//	<locale> test

		#if !__has_include (<ostream>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CHAR8_T_COMPAT
			LBAL_CPP_WARNING ("<ostream> not found")
		#endif	//	<ostream> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_CHAR8_T_COMPAT
			#define LBAL_LIBCPP20_CHAR8_T_COMPAT 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_CHAR8_T_COMPAT")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_CHAR8_T_COMPAT


#if LBAL_LIBCPP20_CHRONO_CALENDAR
	#if defined (__has_include)
		#if !__has_include (<chrono>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CHRONO_CALENDAR
			LBAL_CPP_WARNING ("<chrono> not found")
		#endif	//	<chrono> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_CHRONO_CALENDAR
			#define LBAL_LIBCPP20_CHRONO_CALENDAR 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_CHRONO_CALENDAR")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_CHRONO_CALENDAR


#if LBAL_LIBCPP20_CHRONO_FIXES
	#if defined (__has_include)
		#if !__has_include (<chrono>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CHRONO_FIXES
			LBAL_CPP_WARNING ("<chrono> not found")
		#endif	//	<chrono> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_CHRONO_FIXES
			#define LBAL_LIBCPP20_CHRONO_FIXES 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_CHRONO_FIXES")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_CHRONO_FIXES


#if LBAL_LIBCPP20_CONCEPTS
	#if defined (__has_include)
		#if !__has_include (<concepts>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CONCEPTS
			LBAL_CPP_WARNING ("<concepts> not found")
		#endif	//	<concepts> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_CONCEPTS
			#define LBAL_LIBCPP20_CONCEPTS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_CONCEPTS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_CONCEPTS


#if LBAL_LIBCPP20_CONCEPTS_EXP
	#if defined (__has_include)
		#if !__has_include (<experimental/concepts>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CONCEPTS_EXP
			LBAL_CPP_WARNING ("<experimental/concepts> not found")
		#endif	//	<experimental/concepts> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_CONCEPTS_EXP
			#define LBAL_LIBCPP20_CONCEPTS_EXP 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_CONCEPTS_EXP")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_CONCEPTS_EXP


#if LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE
	#if defined (__has_include)
		#if !__has_include (<concepts>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE
			LBAL_CPP_WARNING ("<concepts> not found")
		#endif	//	<concepts> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE
			#define LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE


#if LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE
	#if defined (__has_include)
		#if !__has_include (<concepts>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE
			LBAL_CPP_WARNING ("<concepts> not found")
		#endif	//	<concepts> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE
			#define LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE


#if LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS
	#if defined (__has_include)
		#if !__has_include (<algorithm>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS
			LBAL_CPP_WARNING ("<algorithm> not found")
		#endif	//	<algorithm> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS
			#define LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS


#if LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP
	#if defined (__has_include)
		#if !__has_include (<algorithm>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP
			LBAL_CPP_WARNING ("<algorithm> not found")
		#endif	//	<algorithm> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP
			#define LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP


#if LBAL_LIBCPP20_CONSTEXPR_COMPLEX
	#if defined (__has_include)
		#if !__has_include (<complex>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CONSTEXPR_COMPLEX
			LBAL_CPP_WARNING ("<complex> not found")
		#endif	//	<complex> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_CONSTEXPR_COMPLEX
			#define LBAL_LIBCPP20_CONSTEXPR_COMPLEX 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_CONSTEXPR_COMPLEX")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_CONSTEXPR_COMPLEX


#if LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC
	#if defined (__has_include)
		#if !__has_include (<memory>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC
			LBAL_CPP_WARNING ("<memory> not found")
		#endif	//	<memory> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC
			#define LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC


#if LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL
	#if defined (__has_include)
		#if !__has_include (<functional>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL
			LBAL_CPP_WARNING ("<functional> not found")
		#endif	//	<functional> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL
			#define LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL


#if LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE
	#if defined (__has_include)
		#if !__has_include (<functional>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE
			LBAL_CPP_WARNING ("<functional> not found")
		#endif	//	<functional> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE
			#define LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE


#if LBAL_LIBCPP20_CONSTEXPR_ITERATOR
	#if defined (__has_include)
		#if !__has_include (<iterator>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CONSTEXPR_ITERATOR
			LBAL_CPP_WARNING ("<iterator> not found")
		#endif	//	<iterator> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_CONSTEXPR_ITERATOR
			#define LBAL_LIBCPP20_CONSTEXPR_ITERATOR 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_CONSTEXPR_ITERATOR")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_CONSTEXPR_ITERATOR


#if LBAL_LIBCPP20_CONSTEXPR_MEMORY
	#if defined (__has_include)
		#if !__has_include (<memory>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CONSTEXPR_MEMORY
			LBAL_CPP_WARNING ("<memory> not found")
		#endif	//	<memory> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_CONSTEXPR_MEMORY
			#define LBAL_LIBCPP20_CONSTEXPR_MEMORY 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_CONSTEXPR_MEMORY")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_CONSTEXPR_MEMORY


#if LBAL_LIBCPP20_CONSTEXPR_NUMERIC
	#if defined (__has_include)
		#if !__has_include (<numeric>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CONSTEXPR_NUMERIC
			LBAL_CPP_WARNING ("<numeric> not found")
		#endif	//	<numeric> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_CONSTEXPR_NUMERIC
			#define LBAL_LIBCPP20_CONSTEXPR_NUMERIC 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_CONSTEXPR_NUMERIC")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_CONSTEXPR_NUMERIC


#if LBAL_LIBCPP20_CONSTEXPR_STRING
	#if defined (__has_include)
		#if !__has_include (<string>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CONSTEXPR_STRING
			LBAL_CPP_WARNING ("<string> not found")
		#endif	//	<string> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_CONSTEXPR_STRING
			#define LBAL_LIBCPP20_CONSTEXPR_STRING 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_CONSTEXPR_STRING")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_CONSTEXPR_STRING


#if LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL
	#if defined (__has_include)
		#if !__has_include (<string>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL
			LBAL_CPP_WARNING ("<string> not found")
		#endif	//	<string> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL
			#define LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL


#if LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW
	#if defined (__has_include)
		#if !__has_include (<string_view>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW
			LBAL_CPP_WARNING ("<string_view> not found")
		#endif	//	<string_view> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW
			#define LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW


#if LBAL_LIBCPP20_CONSTEXPR_TUPLE
	#if defined (__has_include)
		#if !__has_include (<tuple>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CONSTEXPR_TUPLE
			LBAL_CPP_WARNING ("<tuple> not found")
		#endif	//	<tuple> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_CONSTEXPR_TUPLE
			#define LBAL_LIBCPP20_CONSTEXPR_TUPLE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_CONSTEXPR_TUPLE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_CONSTEXPR_TUPLE


#if LBAL_LIBCPP20_CONSTEXPR_UTILITY
	#if defined (__has_include)
		#if !__has_include (<utility>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CONSTEXPR_UTILITY
			LBAL_CPP_WARNING ("<utility> not found")
		#endif	//	<utility> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_CONSTEXPR_UTILITY
			#define LBAL_LIBCPP20_CONSTEXPR_UTILITY 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_CONSTEXPR_UTILITY")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_CONSTEXPR_UTILITY


#if LBAL_LIBCPP20_CONSTEXPR_VECTOR
	#if defined (__has_include)
		#if !__has_include (<vector>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_CONSTEXPR_VECTOR
			LBAL_CPP_WARNING ("<vector> not found")
		#endif	//	<vector> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_CONSTEXPR_VECTOR
			#define LBAL_LIBCPP20_CONSTEXPR_VECTOR 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_CONSTEXPR_VECTOR")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_CONSTEXPR_VECTOR


#if LBAL_LIBCPP20_COROUTINE
	#if defined (__has_include)
		#if !__has_include (<coroutine>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_COROUTINE
			LBAL_CPP_WARNING ("<coroutine> not found")
		#endif	//	<coroutine> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_COROUTINE
			#define LBAL_LIBCPP20_COROUTINE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_COROUTINE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_COROUTINE


#if LBAL_LIBCPP20_COROUTINE_EXP
	#if defined (__has_include)
		#if !__has_include (<experimental/coroutine>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_COROUTINE_EXP
			LBAL_CPP_WARNING ("<experimental/coroutine> not found")
		#endif	//	<experimental/coroutine> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_COROUTINE_EXP
			#define LBAL_LIBCPP20_COROUTINE_EXP 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_COROUTINE_EXP")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_COROUTINE_EXP


#if LBAL_LIBCPP20_DESTROYING_DELETE
	#if defined (__has_include)
		#if !__has_include (<new>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_DESTROYING_DELETE
			LBAL_CPP_WARNING ("<new> not found")
		#endif	//	<new> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_DESTROYING_DELETE
			#define LBAL_LIBCPP20_DESTROYING_DELETE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_DESTROYING_DELETE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_DESTROYING_DELETE


#if LBAL_LIBCPP20_ENDIAN
	#if defined (__has_include)
		#if !__has_include (<bit>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ENDIAN
			LBAL_CPP_WARNING ("<bit> not found")
		#endif	//	<bit> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_ENDIAN
			#define LBAL_LIBCPP20_ENDIAN 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_ENDIAN")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_ENDIAN


#if LBAL_LIBCPP20_ENDIAN_BIT
	#if defined (__has_include)
		#if !__has_include (<bit>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ENDIAN_BIT
			LBAL_CPP_WARNING ("<bit> not found")
		#endif	//	<bit> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_ENDIAN_BIT
			#define LBAL_LIBCPP20_ENDIAN_BIT 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_ENDIAN_BIT")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_ENDIAN_BIT


#if LBAL_LIBCPP20_ERASE_IF
	#if defined (__has_include)
		#if !__has_include (<deque>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ERASE_IF
			LBAL_CPP_WARNING ("<deque> not found")
		#endif	//	<deque> test

		#if !__has_include (<forward_list>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ERASE_IF
			LBAL_CPP_WARNING ("<forward_list> not found")
		#endif	//	<forward_list> test

		#if !__has_include (<list>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ERASE_IF
			LBAL_CPP_WARNING ("<list> not found")
		#endif	//	<list> test

		#if !__has_include (<map>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ERASE_IF
			LBAL_CPP_WARNING ("<map> not found")
		#endif	//	<map> test

		#if !__has_include (<set>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ERASE_IF
			LBAL_CPP_WARNING ("<set> not found")
		#endif	//	<set> test

		#if !__has_include (<string>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ERASE_IF
			LBAL_CPP_WARNING ("<string> not found")
		#endif	//	<string> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_ERASE_IF
			#define LBAL_LIBCPP20_ERASE_IF 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_ERASE_IF")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_ERASE_IF


#if LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS
	#if defined (__has_include)
		#if !__has_include (<deque>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS
			LBAL_CPP_WARNING ("<deque> not found")
		#endif	//	<deque> test

		#if !__has_include (<forward_list>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS
			LBAL_CPP_WARNING ("<forward_list> not found")
		#endif	//	<forward_list> test

		#if !__has_include (<list>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS
			LBAL_CPP_WARNING ("<list> not found")
		#endif	//	<list> test

		#if !__has_include (<map>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS
			LBAL_CPP_WARNING ("<map> not found")
		#endif	//	<map> test

		#if !__has_include (<set>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS
			LBAL_CPP_WARNING ("<set> not found")
		#endif	//	<set> test

		#if !__has_include (<string>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS
			LBAL_CPP_WARNING ("<string> not found")
		#endif	//	<string> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS
			#define LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS


#if LBAL_LIBCPP20_EXECUTION_VECTORIZATION
	#if defined (__has_include)
		#if !__has_include (<execution>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_EXECUTION_VECTORIZATION
			LBAL_CPP_WARNING ("<execution> not found")
		#endif	//	<execution> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_EXECUTION_VECTORIZATION
			#define LBAL_LIBCPP20_EXECUTION_VECTORIZATION 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_EXECUTION_VECTORIZATION")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_EXECUTION_VECTORIZATION


#if LBAL_LIBCPP20_FORMAT
	#if defined (__has_include)
		#if !__has_include (<format>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_FORMAT
			LBAL_CPP_WARNING ("<format> not found")
		#endif	//	<format> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_FORMAT
			#define LBAL_LIBCPP20_FORMAT 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_FORMAT")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_FORMAT


#if LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP
	#if defined (__has_include)
		#if !__has_include (<unordered_map>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP
			LBAL_CPP_WARNING ("<unordered_map> not found")
		#endif	//	<unordered_map> test

		#if !__has_include (<unordered_set>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP
			LBAL_CPP_WARNING ("<unordered_set> not found")
		#endif	//	<unordered_set> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP
			#define LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP


#if LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP
	#if defined (__has_include)
		#if !__has_include (<unordered_map>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP
			LBAL_CPP_WARNING ("<unordered_map> not found")
		#endif	//	<unordered_map> test

		#if !__has_include (<unordered_set>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP
			LBAL_CPP_WARNING ("<unordered_set> not found")
		#endif	//	<unordered_set> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP
			#define LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP


#if LBAL_LIBCPP20_INT_POW2
	#if defined (__has_include)
		#if !__has_include (<bit>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_INT_POW2
			LBAL_CPP_WARNING ("<bit> not found")
		#endif	//	<bit> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_INT_POW2
			#define LBAL_LIBCPP20_INT_POW2 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_INT_POW2")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_INT_POW2


#if LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME
	#if defined (__has_include)
		#if !__has_include (<bit>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME
			LBAL_CPP_WARNING ("<bit> not found")
		#endif	//	<bit> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME
			#define LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME


#if LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS
	#if defined (__has_include)
		#if !__has_include (<utility>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS
			LBAL_CPP_WARNING ("<cmath> not found")
		#endif	//	<cmath> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS
			#define LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS


#if LBAL_LIBCPP20_INTERPOLATE
	#if defined (__has_include)
		#if !__has_include (<cmath>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_INTERPOLATE
			LBAL_CPP_WARNING ("<cmath> not found")
		#endif	//	<cmath> test

		#if !__has_include (<numeric>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_INTERPOLATE
			LBAL_CPP_WARNING ("<numeric> not found")
		#endif	//	<numeric> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_INTERPOLATE
			#define LBAL_LIBCPP20_INTERPOLATE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_INTERPOLATE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_INTERPOLATE


#if LBAL_LIBCPP20_IS_CONSTANT_EVALUATED
	#if defined (__has_include)
		#if !__has_include (<type_traits>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_IS_CONSTANT_EVALUATED
			LBAL_CPP_WARNING ("<type_traits> not found")
		#endif	//	<type_traits> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_IS_CONSTANT_EVALUATED
			#define LBAL_LIBCPP20_IS_CONSTANT_EVALUATED 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_IS_CONSTANT_EVALUATED")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_IS_CONSTANT_EVALUATED


#if LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE
	#if defined (__has_include)
		#if !__has_include (<type_traits>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE
			LBAL_CPP_WARNING ("<type_traits> not found")
		#endif	//	<type_traits> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE
			#define LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE


#if LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE
	#if defined (__has_include)
		#if !__has_include (<type_traits>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE
			LBAL_CPP_WARNING ("<type_traits> not found")
		#endif	//	<type_traits> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE
			#define LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE


#if LBAL_LIBCPP20_JTHREAD
	#if defined (__has_include)
		#if !__has_include (<stop_token>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_JTHREAD
			LBAL_CPP_WARNING ("<stop_token> not found")
		#endif	//	<stop_token> test

		#if !__has_include (<thread>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_JTHREAD
			LBAL_CPP_WARNING ("<thread> not found")
		#endif	//	<thread> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_JTHREAD
			#define LBAL_LIBCPP20_JTHREAD 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_JTHREAD")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_JTHREAD


#if LBAL_LIBCPP20_JTHREAD_CV
	#if defined (__has_include)
		#if !__has_include (<stop_token>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_JTHREAD_CV
			LBAL_CPP_WARNING ("<stop_token> not found")
		#endif	//	<stop_token> test

		#if !__has_include (<thread>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_JTHREAD_CV
			LBAL_CPP_WARNING ("<thread> not found")
		#endif	//	<thread> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_JTHREAD_CV
			#define LBAL_LIBCPP20_JTHREAD_CV 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_JTHREAD_CV")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_JTHREAD_CV


#if LBAL_LIBCPP20_LATCH
	#if defined (__has_include)
		#if !__has_include (<latch>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_LATCH
			LBAL_CPP_WARNING ("<latch> not found")
		#endif	//	<latch> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_LATCH
			#define LBAL_LIBCPP20_LATCH 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_LATCH")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_LATCH


#if LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE
	#if defined (__has_include)
		#if !__has_include (<forward_list>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE
			LBAL_CPP_WARNING ("<forward_list> not found")
		#endif	//	<forward_list> test

		#if !__has_include (<list>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE
			LBAL_CPP_WARNING ("<list> not found")
		#endif	//	<list> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE
			#define LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE


#if LBAL_LIBCPP20_MATH_CONSTANTS
	#if defined (__has_include)
		#if !__has_include (<numbers>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_MATH_CONSTANTS
			LBAL_CPP_WARNING ("<numbers> not found")
		#endif	//	<numbers> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_MATH_CONSTANTS
			#define LBAL_LIBCPP20_MATH_CONSTANTS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_MATH_CONSTANTS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_MATH_CONSTANTS


#if LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE
	#if defined (__has_include)
		#if !__has_include (<type_traits>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE
			LBAL_CPP_WARNING ("<type_traits> not found")
		#endif	//	<type_traits> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE
			#define LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE


#if LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR
	#if defined (__has_include)
		#if !__has_include (<memory>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR
			LBAL_CPP_WARNING ("<memory> not found")
		#endif	//	<memory> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR
			#define LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR


#if LBAL_LIBCPP20_RANGES
	#if defined (__has_include)
		#if !__has_include (<algorithm>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_RANGES
			LBAL_CPP_WARNING ("<algorithm> not found")
		#endif	//	<algorithm> test

		#if !__has_include (<functional>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_RANGES
			LBAL_CPP_WARNING ("<functional> not found")
		#endif	//	<functional> test

		#if !__has_include (<iterator>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_RANGES
			LBAL_CPP_WARNING ("<iterator> not found")
		#endif	//	<iterator> test

		#if !__has_include (<memory>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_RANGES
			LBAL_CPP_WARNING ("<memory> not found")
		#endif	//	<memory> test

		#if !__has_include (<ranges>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_RANGES
			LBAL_CPP_WARNING ("<ranges> not found")
		#endif	//	<ranges> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_RANGES
			#define LBAL_LIBCPP20_RANGES 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_RANGES")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_RANGES


#if LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS
	#if defined (__has_include)
		#if !__has_include (<algorithm>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS
			LBAL_CPP_WARNING ("<algorithm> not found")
		#endif	//	<algorithm> test

		#if !__has_include (<functional>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS
			LBAL_CPP_WARNING ("<functional> not found")
		#endif	//	<functional> test

		#if !__has_include (<iterator>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS
			LBAL_CPP_WARNING ("<iterator> not found")
		#endif	//	<iterator> test

		#if !__has_include (<memory>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS
			LBAL_CPP_WARNING ("<memory> not found")
		#endif	//	<memory> test

		#if !__has_include (<ranges>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS
			LBAL_CPP_WARNING ("<ranges> not found")
		#endif	//	<ranges> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS
			#define LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS


#if LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE
	#if defined (__has_include)
		#if !__has_include (<algorithm>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE
			LBAL_CPP_WARNING ("<algorithm> not found")
		#endif	//	<algorithm> test

		#if !__has_include (<functional>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE
			LBAL_CPP_WARNING ("<functional> not found")
		#endif	//	<functional> test

		#if !__has_include (<iterator>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE
			LBAL_CPP_WARNING ("<iterator> not found")
		#endif	//	<iterator> test

		#if !__has_include (<memory>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE
			LBAL_CPP_WARNING ("<memory> not found")
		#endif	//	<memory> test

		#if !__has_include (<ranges>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE
			LBAL_CPP_WARNING ("<ranges> not found")
		#endif	//	<ranges> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE
			#define LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE


#if LBAL_LIBCPP20_REMOVE_CVREF
	#if defined (__has_include)
		#if !__has_include (<type_traits>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_REMOVE_CVREF
			LBAL_CPP_WARNING ("<type_traits> not found")
		#endif	//	<type_traits> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_REMOVE_CVREF
			#define LBAL_LIBCPP20_REMOVE_CVREF 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_REMOVE_CVREF")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_REMOVE_CVREF


#if LBAL_LIBCPP20_SEMAPHORE
	#if defined (__has_include)
		#if !__has_include (<semaphore>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_SEMAPHORE
			LBAL_CPP_WARNING ("<semaphore> not found")
		#endif	//	<semaphore> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_SEMAPHORE
			#define LBAL_LIBCPP20_SEMAPHORE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_SEMAPHORE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_SEMAPHORE


#if LBAL_LIBCPP20_SHARED_PTR_ARRAYS
	#if defined (__has_include)
		#if !__has_include (<memory>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_SHARED_PTR_ARRAYS
			LBAL_CPP_WARNING ("<memory> not found")
		#endif	//	<memory> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_SHARED_PTR_ARRAYS
			#define LBAL_LIBCPP20_SHARED_PTR_ARRAYS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_SHARED_PTR_ARRAYS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_SHARED_PTR_ARRAYS


#if LBAL_LIBCPP20_SHIFT
	#if defined (__has_include)
		#if !__has_include (<algorithm>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_SHIFT
			LBAL_CPP_WARNING ("<algorithm> not found")
		#endif	//	<algorithm> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_SHIFT
			#define LBAL_LIBCPP20_SHIFT 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_SHIFT")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_SHIFT


#if LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE
	#if defined (__has_include)
		#if !__has_include (<memory>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE
			LBAL_CPP_WARNING ("<memory> not found")
		#endif	//	<memory> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE
			#define LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE


#if LBAL_LIBCPP20_SOURCE_LOCATION
	#if defined (__has_include)
		#if !__has_include (<source_location>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_SOURCE_LOCATION
			LBAL_CPP_WARNING ("<source_location> not found")
		#endif	//	<source_location> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_SOURCE_LOCATION
			#define LBAL_LIBCPP20_SOURCE_LOCATION 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_SOURCE_LOCATION")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_SOURCE_LOCATION


#if LBAL_LIBCPP20_SPAN
	#if defined (__has_include)
		#if !__has_include (<span>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_SPAN
			LBAL_CPP_WARNING ("<span> not found")
		#endif	//	<span> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_SPAN
			#define LBAL_LIBCPP20_SPAN 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_SPAN")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_SPAN


#if LBAL_LIBCPP20_SPAN_USABILITY
	#if defined (__has_include)
		#if !__has_include (<span>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_SPAN_USABILITY
			LBAL_CPP_WARNING ("<span> not found")
		#endif	//	<span> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_SPAN_USABILITY
			#define LBAL_LIBCPP20_SPAN_USABILITY 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_SPAN_USABILITY")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_SPAN_USABILITY


#if LBAL_LIBCPP20_SPAN_FIXED_SIZE
	#if defined (__has_include)
		#if !__has_include (<span>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_SPAN_FIXED_SIZE
			LBAL_CPP_WARNING ("<span> not found")
		#endif	//	<span> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_SPAN_FIXED_SIZE
			#define LBAL_LIBCPP20_SPAN_FIXED_SIZE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_SPAN_FIXED_SIZE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_SPAN_FIXED_SIZE


#if LBAL_LIBCPP20_SSIZE
	#if defined (__has_include)
		#if !__has_include (<iterator>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_SSIZE
			LBAL_CPP_WARNING ("<iterator> not found")
		#endif	//	<iterator> test

		#if !__has_include (<span>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_SSIZE
			LBAL_CPP_WARNING ("<span> not found")
		#endif	//	<span> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_SSIZE
			#define LBAL_LIBCPP20_SSIZE 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_SSIZE")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_SSIZE


#if LBAL_LIBCPP20_STARTS_ENDS_WITH
	#if defined (__has_include)
		#if !__has_include (<string>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_STARTS_ENDS_WITH
			LBAL_CPP_WARNING ("<string> not found")
		#endif	//	<string> test

		#if !__has_include (<string_view>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_STARTS_ENDS_WITH
			LBAL_CPP_WARNING ("<string_view> not found")
		#endif	//	<string_view> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_STARTS_ENDS_WITH
			#define LBAL_LIBCPP20_STARTS_ENDS_WITH 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_STARTS_ENDS_WITH")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_STARTS_ENDS_WITH


#if LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR
	#if defined (__has_include)
		#if !__has_include (<string>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR
			LBAL_CPP_WARNING ("<string> not found")
		#endif	//	<string> test

		#if !__has_include (<string_view>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR
			LBAL_CPP_WARNING ("<string_view> not found")
		#endif	//	<string_view> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR
			#define LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR


#if LBAL_LIBCPP20_SYNCBUF
	#if defined (__has_include)
		#if !__has_include (<syncstream>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_SYNCBUF
			LBAL_CPP_WARNING ("<syncstream> not found")
		#endif	//	<syncstream> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_SYNCBUF
			#define LBAL_LIBCPP20_SYNCBUF 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_SYNCBUF")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_SYNCBUF


#if LBAL_LIBCPP20_SYNCBUF_MANIPULATORS
	#if defined (__has_include)
		#if !__has_include (<syncstream>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_SYNCBUF_MANIPULATORS
			LBAL_CPP_WARNING ("<syncstream> not found")
		#endif	//	<syncstream> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_SYNCBUF_MANIPULATORS
			#define LBAL_LIBCPP20_SYNCBUF_MANIPULATORS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_SYNCBUF_MANIPULATORS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_SYNCBUF_MANIPULATORS


#if LBAL_LIBCPP20_THREE_WAY_COMPARISON
	#if defined (__has_include)
		#if !__has_include (<compare>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_THREE_WAY_COMPARISON
			LBAL_CPP_WARNING ("<compare> not found")
		#endif	//	<compare> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_THREE_WAY_COMPARISON
			#define LBAL_LIBCPP20_THREE_WAY_COMPARISON 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_THREE_WAY_COMPARISON")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_THREE_WAY_COMPARISON


#if LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY
	#if defined (__has_include)
		#if !__has_include (<compare>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY
			LBAL_CPP_WARNING ("<compare> not found")
		#endif	//	<compare> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY
			#define LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY


#if LBAL_LIBCPP20_TO_ADDRESS
	#if defined (__has_include)
		#if !__has_include (<memory>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_TO_ADDRESS
			LBAL_CPP_WARNING ("<memory> not found")
		#endif	//	<memory> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_TO_ADDRESS
			#define LBAL_LIBCPP20_TO_ADDRESS 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_TO_ADDRESS")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_TO_ADDRESS


#if LBAL_LIBCPP20_TO_ARRAY
	#if defined (__has_include)
		#if !__has_include (<array>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_TO_ARRAY
			LBAL_CPP_WARNING ("<array> not found")
		#endif	//	<array> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_TO_ARRAY
			#define LBAL_LIBCPP20_TO_ARRAY 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_TO_ARRAY")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_TO_ARRAY


#if LBAL_LIBCPP20_TYPE_IDENTITY
	#if defined (__has_include)
		#if !__has_include (<type_traits>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_TYPE_IDENTITY
			LBAL_CPP_WARNING ("<type_traits> not found")
		#endif	//	<type_traits> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_TYPE_IDENTITY
			#define LBAL_LIBCPP20_TYPE_IDENTITY 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_TYPE_IDENTITY")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_TYPE_IDENTITY


#if LBAL_LIBCPP20_UNWRAP_REF
	#if defined (__has_include)
		#if !__has_include (<type_traits>)
			//	Always warn if this happens.
			#undef LBAL_LIBCPP20_UNWRAP_REF
			LBAL_CPP_WARNING ("<type_traits> not found")
		#endif	//	<type_traits> test
	#else
		#if LBAL_CONFIG_treat_uncertainty_as_failure
			#undef LBAL_LIBCPP20_UNWRAP_REF
			#define LBAL_LIBCPP20_UNWRAP_REF 0
		#endif	//	LBAL_CONFIG_treat_uncertainty_as_failure

		#if LBAL_CONFIG_enable_pedantic_warnings
			LBAL_CPP_WARNING ("Unable to validate LBAL_LIBCPP20_UNWRAP_REF")
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif	//	__has_include
#endif	//	LBAL_LIBCPP20_UNWRAP_REF
