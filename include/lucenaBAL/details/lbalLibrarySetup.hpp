/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalLibrarySetup.hpp”
  Copyright © 2018-2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/

#pragma once

//	lbal
#include <lucenaBAL/lbalConfig.hpp>

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
  Feature Macro Definitions

  Features are documented in `lbalFeatureSetup.hpp`; this only provides
  macro definitions.

  These tests are platform-agnostic, relying almost exclusively on SD-6
  macros. Checks that would have generated a false positive should have been
  handled previously, effectively overriding any assignments we would
  otherwise have made here. As a general rule, if an SD-6 macro is defined,
  unless we have a very specific reason to do otherwise, we assume the
  feature is available. In particular, even if the current C++ dialect might
  suggest the feature isn’t available (e.g., a C++20 feature being made
  available in C++17), we assume that whatever mechanism handled macro
  initialization was written by someone who knew what they were doing.

  SEEME - bitweeder
  It’s possible that an implementation of a pre-C++20 Standard will define SD-6
  macros in the relevant Standard Library headers themselves, but this would be
  arguably self-defeating. We don’t bother dealing with that particular
  pathology here; instead reying on the post-initialization headers to catch
  false negatives.

  APIME Generally, we explicitly disallow the use of the experimental
  version of a given feature if the final version is also available. This is
  partly authoritarian, and partly because some implementations have been
  known to keep broken experimental headers around after a feature is
  finalized rather than update them or simply retire them. This behavior can
  be overridden in the implementation headers.
*/

// C++14

#if !defined(LBAL_LIBCPP14_CHRONO_UDLS)
  #if __cpp_lib_chrono_udls >= 201304L
    #define LBAL_LIBCPP14_CHRONO_UDLS __cpp_lib_chrono_udls
  #endif
#endif  //  LBAL_LIBCPP14_CHRONO_UDLS

#if !defined(LBAL_LIBCPP14_COMPLEX_UDLS)
  #if __cpp_lib_complex_udls >= 201309L
    #define LBAL_LIBCPP14_COMPLEX_UDLS __cpp_lib_complex_udls
  #endif
#endif  //  LBAL_LIBCPP14_COMPLEX_UDLS

#if !defined(LBAL_LIBCPP14_EXCHANGE_FUNCTION)
  #if __cpp_lib_exchange_function >= 201304L
    #define LBAL_LIBCPP14_EXCHANGE_FUNCTION __cpp_lib_exchange_function
  #endif
#endif  //  LBAL_LIBCPP14_EXCHANGE_FUNCTION

#if !defined(LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP)
  #if __cpp_lib_generic_associative_lookup >= 201304L
    #define LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP                           \
      __cpp_lib_generic_associative_lookup
  #endif
#endif  //  LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP

#if !defined(LBAL_LIBCPP14_INTEGER_SEQUENCE)
  #if __cpp_lib_integer_sequence >= 201304L
    #define LBAL_LIBCPP14_INTEGER_SEQUENCE __cpp_lib_integer_sequence
  #endif
#endif  //  LBAL_LIBCPP14_INTEGER_SEQUENCE

#if !defined(LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE)
  #if __cpp_lib_integral_constant_callable >= 201304L
    #define LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE                           \
      __cpp_lib_integral_constant_callable
  #endif
#endif  //  LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE

#if !defined(LBAL_LIBCPP14_IS_FINAL)
  #if __cpp_lib_is_final >= 201402L
    #define LBAL_LIBCPP14_IS_FINAL __cpp_lib_is_final
  #endif
#endif  //  LBAL_LIBCPP14_IS_FINAL

#if !defined(LBAL_LIBCPP14_IS_NULL_POINTER)
  #if __cpp_lib_is_null_pointer >= 201309L
    #define LBAL_LIBCPP14_IS_NULL_POINTER __cpp_lib_is_null_pointer
  #endif
#endif  //  LBAL_LIBCPP14_IS_NULL_POINTER

#if !defined(LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR)
  #if __cpp_lib_make_reverse_iterator >= 201402L
    #define LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR __cpp_lib_make_reverse_iterator
  #endif
#endif  //  LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR

#if !defined(LBAL_LIBCPP14_MAKE_UNIQUE)
  #if __cpp_lib_make_unique >= 201304L
    #define LBAL_LIBCPP14_MAKE_UNIQUE __cpp_lib_make_unique
  #endif
#endif  //  LBAL_LIBCPP14_MAKE_UNIQUE

#if !defined(LBAL_LIBCPP14_NULL_ITERATORS)
  #if __cpp_lib_null_iterators >= 201304L
    #define LBAL_LIBCPP14_NULL_ITERATORS __cpp_lib_null_iterators
  #endif
#endif  //  LBAL_LIBCPP14_NULL_ITERATORS

#if !defined(LBAL_LIBCPP14_QUOTED_STRING_IO)
  #if __cpp_lib_quoted_string_io >= 201304L
    #define LBAL_LIBCPP14_QUOTED_STRING_IO __cpp_lib_quoted_string_io
  #endif
#endif  //  LBAL_LIBCPP14_QUOTED_STRING_IO

#if !defined(LBAL_LIBCPP14_RESULT_OF_SFINAE)
  #if __cpp_lib_result_of_sfinae >= 201210L
    #define LBAL_LIBCPP14_RESULT_OF_SFINAE __cpp_lib_result_of_sfinae
  #endif
#endif  //  LBAL_LIBCPP14_RESULT_OF_SFINAE

#if !defined(LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS)
  #if __cpp_lib_robust_nonmodifying_seq_ops >= 201304L
    #define LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS                          \
      __cpp_lib_robust_nonmodifying_seq_ops
  #endif
#endif  //  LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS

#if !defined(LBAL_LIBCPP14_SHARED_TIMED_MUTEX)
  #if __cpp_lib_shared_timed_mutex >= 201402L
    #define LBAL_LIBCPP14_SHARED_TIMED_MUTEX __cpp_lib_shared_timed_mutex
  #endif
#endif  //  LBAL_LIBCPP14_SHARED_TIMED_MUTEX

#if !defined(LBAL_LIBCPP14_STRING_UDLS)
  #if __cpp_lib_string_udls >= 201304L
    #define LBAL_LIBCPP14_STRING_UDLS __cpp_lib_string_udls
  #endif
#endif  //  LBAL_LIBCPP14_STRING_UDLS

#if !defined(LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES)
  #if __cpp_lib_transformation_trait_aliases >= 201304L
    #define LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES                         \
      __cpp_lib_transformation_trait_aliases
  #endif
#endif  //  LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES

#if !defined(LBAL_LIBCPP14_TRANSPARENT_OPERATORS)
  #if __cpp_lib_transparent_operators >= 201210L
    #define LBAL_LIBCPP14_TRANSPARENT_OPERATORS __cpp_lib_transparent_operators
  #endif
#endif  //  LBAL_LIBCPP14_TRANSPARENT_OPERATORS

#if !defined(LBAL_LIBCPP14_TUPLES_BY_TYPE)
  #if __cpp_lib_tuples_by_type >= 201304L
    #define LBAL_LIBCPP14_TUPLES_BY_TYPE __cpp_lib_tuples_by_type
  #endif
#endif  //  LBAL_LIBCPP14_TUPLES_BY_TYPE

#if !defined(LBAL_LIBCPP14_TUPLE_ELEMENT_T)
  #if __cpp_lib_tuple_element_t >= 201402L
    #define LBAL_LIBCPP14_TUPLE_ELEMENT_T __cpp_lib_tuple_element_t
  #endif
#endif  //  LBAL_LIBCPP14_TUPLE_ELEMENT_T

// C++17

#if !defined(LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR)
  #if __cpp_lib_addressof_constexpr >= 201603L
    #define LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR __cpp_lib_addressof_constexpr
  #endif
#endif  //  LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR

#if !defined(LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL)
  #if __cpp_lib_allocator_traits_is_always_equal >= 201411L
    #define LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL                     \
      __cpp_lib_allocator_traits_is_always_equal
  #endif
#endif  //  LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL

#if !defined(LBAL_LIBCPP17_ANY)
  #if __cpp_lib_any >= 201603L
    #define LBAL_LIBCPP17_ANY __cpp_lib_any
  #endif
#endif  //  LBAL_LIBCPP17_ANY

#if !defined(LBAL_LIBCPP17_ANY_INTERFACE)
  #if __cpp_lib_any >= 201606L
    #define LBAL_LIBCPP17_ANY_INTERFACE __cpp_lib_any
  #endif
#endif  //  LBAL_LIBCPP17_ANY_INTERFACE

#if !defined(LBAL_LIBCPP17_APPLY)
  #if __cpp_lib_apply >= 201603L
    #define LBAL_LIBCPP17_APPLY __cpp_lib_apply
  #endif
#endif  //  LBAL_LIBCPP17_APPLY

#if !defined(LBAL_LIBCPP17_ARRAY_CONSTEXPR)
  #if __cpp_lib_array_constexpr >= 201603L
    #define LBAL_LIBCPP17_ARRAY_CONSTEXPR __cpp_lib_array_constexpr
  #endif
#endif  //  LBAL_LIBCPP17_ARRAY_CONSTEXPR

#if !defined(LBAL_LIBCPP17_AS_CONST)
  #if __cpp_lib_as_const >= 201510L
    #define LBAL_LIBCPP17_AS_CONST __cpp_lib_as_const
  #endif
#endif  //  LBAL_LIBCPP17_AS_CONST

#if !defined(LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE)
  #if __cpp_lib_atomic_is_always_lock_free >= 201603L
    #define LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE                           \
      __cpp_lib_atomic_is_always_lock_free
  #endif
#endif  //  LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE

#if !defined(LBAL_LIBCPP17_BOOL_CONSTANT)
  #if __cpp_lib_bool_constant >= 201505L
    #define LBAL_LIBCPP17_BOOL_CONSTANT __cpp_lib_bool_constant
  #endif
#endif  //  LBAL_LIBCPP17_BOOL_CONSTANT

#if !defined(LBAL_LIBCPP17_BOYER_MOORE_SEARCHER)
  #if __cpp_lib_boyer_moore_searcher >= 201603L
    #define LBAL_LIBCPP17_BOYER_MOORE_SEARCHER __cpp_lib_boyer_moore_searcher
  #endif
#endif  //  LBAL_LIBCPP17_BOYER_MOORE_SEARCHER

#if !defined(LBAL_LIBCPP17_BYTE)
  #if __cpp_lib_byte >= 201603L
    #define LBAL_LIBCPP17_BYTE __cpp_lib_byte
  #endif
#endif  //  LBAL_LIBCPP17_BYTE

#if !defined(LBAL_LIBCPP17_CHRONO)
  #if __cpp_lib_chrono >= 201510L
    #define LBAL_LIBCPP17_CHRONO __cpp_lib_chrono
  #endif
#endif  //  LBAL_LIBCPP17_CHRONO

#if !defined(LBAL_LIBCPP17_CHRONO_CONSTEXPR)
  #if __cpp_lib_chrono >= 201611L
    #define LBAL_LIBCPP17_CHRONO_CONSTEXPR __cpp_lib_chrono
  #endif
#endif  //  LBAL_LIBCPP17_CHRONO_CONSTEXPR

#if !defined(LBAL_LIBCPP17_CLAMP)
  #if __cpp_lib_clamp >= 201603L
    #define LBAL_LIBCPP17_CLAMP __cpp_lib_clamp
  #endif
#endif  //  LBAL_LIBCPP17_CLAMP

#if !defined(LBAL_LIBCPP17_CONSTEXPR_STRING)
  #if __cpp_lib_constexpr_string >= 201611L
    #define LBAL_LIBCPP17_CONSTEXPR_STRING __cpp_lib_constexpr_string
  #endif
#endif  //  LBAL_LIBCPP17_CONSTEXPR_STRING

#if !defined(LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW)
  #if __cpp_lib_constexpr_string_view >= 201611L
    #define LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW __cpp_lib_constexpr_string_view
  #endif
#endif  //  LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW

#if !defined(LBAL_LIBCPP17_DEDUCTION_GUIDES)
  #if __cpp_lib_deduction_guides >= 201703L
    #define LBAL_LIBCPP17_DEDUCTION_GUIDES __cpp_lib_deduction_guides
  #endif
#endif  //  LBAL_LIBCPP17_DEDUCTION_GUIDES

#if !defined(LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS)
  #if __cpp_lib_enable_shared_from_this >= 201603L
    #define LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS                              \
      __cpp_lib_enable_shared_from_this
  #endif
#endif  //  LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS

#if !defined(LBAL_LIBCPP17_EXECUTION)
  #if __cpp_lib_execution >= 201603L
    #define LBAL_LIBCPP17_EXECUTION __cpp_lib_execution
  #endif
#endif  //  LBAL_LIBCPP17_EXECUTION

#if !defined(LBAL_LIBCPP17_FILESYSTEM)
  #if __cpp_lib_filesystem >= 201603L
    #define LBAL_LIBCPP17_FILESYSTEM __cpp_lib_filesystem
  #endif
#endif  //  LBAL_LIBCPP17_FILESYSTEM

#if !defined(LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING)
  #if __cpp_lib_filesystem >= 201703L
    #define LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING                   \
      __cpp_lib_filesystem
  #endif
#endif  //  LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING

#if !defined(LBAL_LIBCPP17_FILESYSTEM_EXP)
  #if __cpp_lib_experimental_filesystem >= 201603L
    #define LBAL_LIBCPP17_FILESYSTEM_EXP __cpp_lib_experimental_filesystem
  #endif
#endif  //  LBAL_LIBCPP17_FILESYSTEM_EXP

#if !defined(LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED)
  #if __cpp_lib_filesystem >= 201606L
    #define LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED __cpp_lib_filesystem
  #endif
#endif  //  LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED

#if !defined(LBAL_LIBCPP17_FILESYSTEM_RELATIVE_PATHS)
  #if __cpp_lib_filesystem >= 201606L
    #define LBAL_LIBCPP17_FILESYSTEM_RELATIVE_PATHS __cpp_lib_filesystem
  #endif
#endif  //  LBAL_LIBCPP17_FILESYSTEM_RELATIVE_PATHS

#if !defined(LBAL_LIBCPP17_GCD_LCM)
  #if __cpp_lib_gcd_lcm >= 201606L
    #define LBAL_LIBCPP17_GCD_LCM __cpp_lib_gcd_lcm
  #endif
#endif  //  LBAL_LIBCPP17_GCD_LCM

#if !defined(LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE)
  #if __cpp_lib_hardware_interference_size >= 201703L
    #define LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE                           \
      __cpp_lib_hardware_interference_size
  #endif
#endif  //  LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE

#if !defined(LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS)
  #if __cpp_lib_has_unique_object_representations >= 201606L
    #define LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS                    \
      __cpp_lib_has_unique_object_representations
  #endif
#endif  //  LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS

#if !defined(LBAL_LIBCPP17_HYPOT)
  #if __cpp_lib_hypot >= 201603L
    #define LBAL_LIBCPP17_HYPOT __cpp_lib_hypot
  #endif
#endif  //  LBAL_LIBCPP17_HYPOT

#if !defined(LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS)
  #if __cpp_lib_incomplete_container_elements >= 201505L
    #define LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS                        \
      __cpp_lib_incomplete_container_elements
  #endif
#endif  //  LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS

#if !defined(LBAL_LIBCPP17_INVOKE)
  #if __cpp_lib_invoke >= 201411L
    #define LBAL_LIBCPP17_INVOKE __cpp_lib_invoke
  #endif
#endif  //  LBAL_LIBCPP17_INVOKE

#if !defined(LBAL_LIBCPP17_IS_AGGREGATE)
  #if __cpp_lib_is_aggregate >= 201703L
    #define LBAL_LIBCPP17_IS_AGGREGATE __cpp_lib_is_aggregate
  #endif
#endif  //  LBAL_LIBCPP17_IS_AGGREGATE

#if !defined(LBAL_LIBCPP17_IS_INVOCABLE)
  #if __cpp_lib_is_invocable >= 201703L
    #define LBAL_LIBCPP17_IS_INVOCABLE __cpp_lib_is_invocable
  #endif
#endif  //  LBAL_LIBCPP17_IS_INVOCABLE

#if !defined(LBAL_LIBCPP17_IS_SWAPPABLE)
  #if __cpp_lib_is_swappable >= 201603L
    #define LBAL_LIBCPP17_IS_SWAPPABLE __cpp_lib_is_swappable
  #endif
#endif  //  LBAL_LIBCPP17_IS_SWAPPABLE

#if !defined(LBAL_LIBCPP17_LAUNDER)
  #if __cpp_lib_launder >= 201606L
    #define LBAL_LIBCPP17_LAUNDER __cpp_lib_launder
  #endif
#endif  //  LBAL_LIBCPP17_LAUNDER

#if !defined(LBAL_LIBCPP17_LOGICAL_TRAITS)
  #if __cpp_lib_logical_traits >= 201510L
    #define LBAL_LIBCPP17_LOGICAL_TRAITS __cpp_lib_logical_traits
  #endif
#endif  //  LBAL_LIBCPP17_LOGICAL_TRAITS

#if !defined(LBAL_LIBCPP17_MAKE_FROM_TUPLE)
  #if __cpp_lib_make_from_tuple >= 201606L
    #define LBAL_LIBCPP17_MAKE_FROM_TUPLE __cpp_lib_make_from_tuple
  #endif
#endif  //  LBAL_LIBCPP17_MAKE_FROM_TUPLE

#if !defined(LBAL_LIBCPP17_MAP_TRY_EMPLACE)
  #if __cpp_lib_map_try_emplace >= 201411L
    #define LBAL_LIBCPP17_MAP_TRY_EMPLACE __cpp_lib_map_try_emplace
  #endif
#endif  //  LBAL_LIBCPP17_MAP_TRY_EMPLACE

#if !defined(LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS)
  #if __cpp_lib_math_special_functions >= 201603L
    #define LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS                               \
      __cpp_lib_math_special_functions
  #endif
#endif  //  LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS

#if !defined(LBAL_LIBCPP17_MEMORY_RESOURCE)
  #if __cpp_lib_memory_resource >= 201603L
    #define LBAL_LIBCPP17_MEMORY_RESOURCE __cpp_lib_memory_resource
  #endif
#endif  //  LBAL_LIBCPP17_MEMORY_RESOURCE

#if !defined(LBAL_LIBCPP17_NODE_EXTRACT)
  #if __cpp_lib_node_extract >= 201606L
    #define LBAL_LIBCPP17_NODE_EXTRACT __cpp_lib_node_extract
  #endif
#endif  //  LBAL_LIBCPP17_NODE_EXTRACT

#if !defined(LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS)
  #if __cpp_lib_nonmember_container_access >= 201411L
    #define LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS                           \
      __cpp_lib_nonmember_container_access
  #endif
#endif  //  LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS

#if !defined(LBAL_LIBCPP17_NOT_FN)
  #if __cpp_lib_not_fn >= 201603L
    #define LBAL_LIBCPP17_NOT_FN __cpp_lib_not_fn
  #endif
#endif  //  LBAL_LIBCPP17_NOT_FN

#if !defined(LBAL_LIBCPP17_OPTIONAL)
  #if __cpp_lib_optional >= 201603L
    #define LBAL_LIBCPP17_OPTIONAL __cpp_lib_optional
  #endif
#endif  //  LBAL_LIBCPP17_OPTIONAL

#if !defined(LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL)
  #if __cpp_lib_optional >= 201606L
    #define LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL __cpp_lib_optional
  #endif
#endif  //  LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL

#if !defined(LBAL_LIBCPP17_OPTIONAL_INTERFACE)
  #if __cpp_lib_optional >= 201606L
    #define LBAL_LIBCPP17_OPTIONAL_INTERFACE __cpp_lib_optional
  #endif
#endif  //  LBAL_LIBCPP17_OPTIONAL_INTERFACE

#if !defined(LBAL_LIBCPP17_PARALLEL_ALGORITHM)
  #if __cpp_lib_parallel_algorithm >= 201603L
    #define LBAL_LIBCPP17_PARALLEL_ALGORITHM __cpp_lib_parallel_algorithm
  #endif
#endif  //  LBAL_LIBCPP17_PARALLEL_ALGORITHM

#if !defined(LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS)
  #if __cpp_lib_raw_memory_algorithms >= 201606L
    #define LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS __cpp_lib_raw_memory_algorithms
  #endif
#endif  //  LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS

#if !defined(LBAL_LIBCPP17_SAMPLE)
  #if __cpp_lib_sample >= 201603L
    #define LBAL_LIBCPP17_SAMPLE __cpp_lib_sample
  #endif
#endif  //  LBAL_LIBCPP17_SAMPLE

#if !defined(LBAL_LIBCPP17_SCOPED_LOCK)
  #if __cpp_lib_scoped_lock >= 201703L
    #define LBAL_LIBCPP17_SCOPED_LOCK __cpp_lib_scoped_lock
  #endif
#endif  //  LBAL_LIBCPP17_SCOPED_LOCK

#if !defined(LBAL_LIBCPP17_SHARED_MUTEX)
  #if __cpp_lib_shared_mutex >= 201505L
    #define LBAL_LIBCPP17_SHARED_MUTEX __cpp_lib_shared_mutex
  #endif
#endif  //  LBAL_LIBCPP17_SHARED_MUTEX

#if !defined(LBAL_LIBCPP17_SHARED_PTR_ARRAYS)
  #if __cpp_lib_shared_ptr_arrays >= 201611L
    #define LBAL_LIBCPP17_SHARED_PTR_ARRAYS __cpp_lib_shared_ptr_arrays
  #endif
#endif  //  LBAL_LIBCPP17_SHARED_PTR_ARRAYS

#if !defined(LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE)
  #if __cpp_lib_shared_ptr_weak_type >= 201606L
    #define LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE __cpp_lib_shared_ptr_weak_type
  #endif
#endif  //  LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE

#if !defined(LBAL_LIBCPP17_STRING_VIEW)
  #if __cpp_lib_string_view >= 201603L
    #define LBAL_LIBCPP17_STRING_VIEW __cpp_lib_string_view
  #endif
#endif  //  LBAL_LIBCPP17_STRING_VIEW

#if !defined(LBAL_LIBCPP17_STRING_VIEW_INTERFACE)
  #if __cpp_lib_string_view >= 201606L
    #define LBAL_LIBCPP17_STRING_VIEW_INTERFACE __cpp_lib_string_view
  #endif
#endif  //  LBAL_LIBCPP17_STRING_VIEW_INTERFACE

#if !defined(LBAL_LIBCPP17_TO_CHARS)
  #if __cpp_lib_to_chars >= 201611L
    #define LBAL_LIBCPP17_TO_CHARS __cpp_lib_to_chars
  #endif
#endif  //  LBAL_LIBCPP17_TO_CHARS

#if !defined(LBAL_LIBCPP17_TO_CHARS_FP)
  #if __cpp_lib_to_chars >= 201611L
    #define LBAL_LIBCPP17_TO_CHARS_FP __cpp_lib_to_chars
  #endif
#endif  //  LBAL_LIBCPP17_TO_CHARS_FP

#if !defined(LBAL_LIBCPP17_TO_CHARS_INTEGER)
  #if __cpp_lib_to_chars >= 201611L
    #define LBAL_LIBCPP17_TO_CHARS_INTEGER __cpp_lib_to_chars
  #endif
#endif  //  LBAL_LIBCPP17_TO_CHARS_INTEGER

#if !defined(LBAL_LIBCPP17_TRANSPARENT_OPERATORS)
  #if __cpp_lib_transparent_operators >= 201510L
    #define LBAL_LIBCPP17_TRANSPARENT_OPERATORS __cpp_lib_transparent_operators
  #endif
#endif  //  LBAL_LIBCPP17_TRANSPARENT_OPERATORS

#if !defined(LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES)
  #if __cpp_lib_type_trait_variable_templates >= 201510L
    #define LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES                        \
      __cpp_lib_type_trait_variable_templates
  #endif
#endif  //  LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES

#if !defined(LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS)
  #if __cpp_lib_uncaught_exceptions >= 201411L
    #define LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS __cpp_lib_uncaught_exceptions
  #endif
#endif  //  LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS

#if !defined(LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE)
  #if __cpp_lib_unordered_map_try_emplace >= 201411L
    #define LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE                            \
      __cpp_lib_unordered_map_try_emplace
  #endif
#endif  //  LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE

#if !defined(LBAL_LIBCPP17_VARIANT)
  #if __cpp_lib_variant >= 201606L
    #define LBAL_LIBCPP17_VARIANT __cpp_lib_variant
  #endif
#endif  //  LBAL_LIBCPP17_VARIANT

#if !defined(LBAL_LIBCPP17_VOID_T)
  #if __cpp_lib_void_t >= 201411L
    #define LBAL_LIBCPP17_VOID_T __cpp_lib_void_t
  #endif
#endif  //  LBAL_LIBCPP17_VOID_T

// C++20

#if !defined(LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS)
  #if __cpp_lib_array_constexpr >= 201806L
    #define LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS __cpp_lib_array_constexpr
  #endif
#endif  //  LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS

#if !defined(LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR)
  #if __cpp_lib_array_constexpr >= 201803L
    #define LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR __cpp_lib_array_constexpr
  #endif
#endif  //  LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR

#if !defined(LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES)
  #if __cpp_lib_array_constexpr >= 201811L
    #define LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES __cpp_lib_array_constexpr
  #endif
#endif  //  LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES

#if !defined(LBAL_LIBCPP20_ASSUME_ALIGNED)
  #if __cpp_lib_assume_aligned >= 201811L
    #define LBAL_LIBCPP20_ASSUME_ALIGNED __cpp_lib_assume_aligned
  #endif
#endif  //  LBAL_LIBCPP20_ASSUME_ALIGNED

#if !defined(LBAL_LIBCPP20_ATOMIC_FLAG_TEST)
  #if __cpp_lib_atomic_flag_test >= 201907L
    #define LBAL_LIBCPP20_ATOMIC_FLAG_TEST __cpp_lib_atomic_flag_test
  #endif
#endif  //  LBAL_LIBCPP20_ATOMIC_FLAG_TEST

#if !defined(LBAL_LIBCPP20_ATOMIC_FLOAT)
  #if __cpp_lib_atomic_float >= 201711L
    #define LBAL_LIBCPP20_ATOMIC_FLOAT __cpp_lib_atomic_float
  #endif
#endif  //  LBAL_LIBCPP20_ATOMIC_FLOAT

#if !defined(LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES)
  #if __cpp_lib_atomic_lock_free_type_aliases >= 201907L
    #define LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES                        \
      __cpp_lib_atomic_lock_free_type_aliases
  #endif
#endif  //  LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES

#if !defined(LBAL_LIBCPP20_ATOMIC_REF)
  #if __cpp_lib_atomic_ref >= 201806L
    #define LBAL_LIBCPP20_ATOMIC_REF __cpp_lib_atomic_ref
  #endif
#endif  //  LBAL_LIBCPP20_ATOMIC_REF

#if !defined(LBAL_LIBCPP20_ATOMIC_SHARED_PTR)
  #if __cpp_lib_atomic_shared_ptr >= 201711L
    #define LBAL_LIBCPP20_ATOMIC_SHARED_PTR __cpp_lib_atomic_shared_ptr
  #endif
#endif  //  LBAL_LIBCPP20_ATOMIC_SHARED_PTR

#if !defined(LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION)
  #if __cpp_lib_atomic_value_initialization >= 201911L
    #define LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION                          \
      __cpp_lib_atomic_value_initialization
  #endif
#endif  //  LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION

#if !defined(LBAL_LIBCPP20_ATOMIC_WAIT)
  #if __cpp_lib_atomic_wait >= 201907L
    #define LBAL_LIBCPP20_ATOMIC_WAIT __cpp_lib_atomic_wait
  #endif
#endif  //  LBAL_LIBCPP20_ATOMIC_WAIT

#if !defined(LBAL_LIBCPP20_BARRIER)
  #if __cpp_lib_barrier >= 201907L
    #define LBAL_LIBCPP20_BARRIER __cpp_lib_barrier
  #endif
#endif  //  LBAL_LIBCPP20_BARRIER

#if !defined(LBAL_LIBCPP20_BIND_FRONT)
  #if __cpp_lib_bind_front >= 201811L
    #define LBAL_LIBCPP20_BIND_FRONT __cpp_lib_bind_front
  #endif
#endif  //  LBAL_LIBCPP20_BIND_FRONT

#if !defined(LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP)
  #if __cpp_lib_bind_front >= 201907L
    #define LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP __cpp_lib_bind_front
  #endif
#endif  //  LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP

#if !defined(LBAL_LIBCPP20_BITOPS)
  #if __cpp_lib_bitops >= 201907L
    #define LBAL_LIBCPP20_BITOPS __cpp_lib_bitops
  #endif
#endif  //  LBAL_LIBCPP20_BITOPS

#if !defined(LBAL_LIBCPP20_BIT_CAST)
  #if __cpp_lib_bit_cast >= 201806L
    #define LBAL_LIBCPP20_BIT_CAST __cpp_lib_bit_cast
  #endif
#endif  //  LBAL_LIBCPP20_BIT_CAST

#if !defined(LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS)
  #if __cpp_lib_bounded_array_traits >= 201902L
    #define LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS __cpp_lib_bounded_array_traits
  #endif
#endif  //  LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS

#if !defined(LBAL_LIBCPP20_CHAR8_T)
  #if __cpp_lib_char8_t >= 201811L
    #define LBAL_LIBCPP20_CHAR8_T __cpp_lib_char8_t
  #endif
#endif  //  LBAL_LIBCPP20_CHAR8_T

#if !defined(LBAL_LIBCPP20_CHAR8_T_COMPAT)
  #if __cpp_lib_char8_t >= 201907L
    #define LBAL_LIBCPP20_CHAR8_T_COMPAT __cpp_lib_char8_t
  #endif
#endif  //  LBAL_LIBCPP20_CHAR8_T_COMPAT

#if !defined(LBAL_LIBCPP20_CHRONO_CALENDAR)
  #if __cpp_lib_chrono >= 201803L
    #define LBAL_LIBCPP20_CHRONO_CALENDAR __cpp_lib_chrono
  #endif
#endif  //  LBAL_LIBCPP20_CHRONO_CALENDAR

#if !defined(LBAL_LIBCPP20_CHRONO_FIXES)
  #if __cpp_lib_chrono >= 201907L
    #define LBAL_LIBCPP20_CHRONO_FIXES __cpp_lib_chrono
  #endif
#endif  //  LBAL_LIBCPP20_CHRONO_FIXES

#if !defined(LBAL_LIBCPP20_CONCEPTS)
  #if __cpp_lib_concepts >= 201806L
    #define LBAL_LIBCPP20_CONCEPTS __cpp_lib_concepts
  #endif
#endif  //  LBAL_LIBCPP20_CONCEPTS

#if !defined(LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE)
  #if __cpp_lib_concepts >= 202002L
    #define LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE __cpp_lib_concepts
  #endif
#endif  //  LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE

#if !defined(LBAL_LIBCPP20_CONCEPTS_EXP)
  #if __cpp_lib_experimental_concepts >= 201806L
    #define LBAL_LIBCPP20_CONCEPTS_EXP __cpp_lib_experimental_concepts
  #endif
#endif  //  LBAL_LIBCPP20_CONCEPTS_EXP

#if !defined(LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE)
  #if __cpp_lib_concepts >= 201907L
    #define LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE __cpp_lib_concepts
  #endif
#endif  //  LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE

#if !defined(LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS)
  #if __cpp_lib_constexpr_algorithms >= 201703L
    #define LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS __cpp_lib_constexpr_algorithms
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS

#if !defined(LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP)
  #if __cpp_lib_constexpr_algorithms >= 201806L
    #define LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP                            \
      __cpp_lib_constexpr_algorithms
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP

#if !defined(LBAL_LIBCPP20_CONSTEXPR_COMPLEX)
  #if __cpp_lib_constexpr_complex >= 201711L
    #define LBAL_LIBCPP20_CONSTEXPR_COMPLEX __cpp_lib_constexpr_complex
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_COMPLEX

#if !defined(LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC)
  #if __cpp_lib_constexpr_dynamic_alloc >= 201907L
    #define LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC                              \
      __cpp_lib_constexpr_dynamic_alloc
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC

#if !defined(LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL)
  #if __cpp_lib_constexpr_functional >= 201811L
    #define LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL __cpp_lib_constexpr_functional
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL

#if !defined(LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE)
  #if __cpp_lib_constexpr_functional >= 201907L
    #define LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE                          \
      __cpp_lib_constexpr_functional
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE

#if !defined(LBAL_LIBCPP20_CONSTEXPR_ITERATOR)
  #if __cpp_lib_constexpr_iterator >= 201811L
    #define LBAL_LIBCPP20_CONSTEXPR_ITERATOR __cpp_lib_constexpr_iterator
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_ITERATOR

#if !defined(LBAL_LIBCPP20_CONSTEXPR_MEMORY)
  #if __cpp_lib_constexpr_memory >= 201811L
    #define LBAL_LIBCPP20_CONSTEXPR_MEMORY __cpp_lib_constexpr_memory
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_MEMORY

#if !defined(LBAL_LIBCPP20_CONSTEXPR_NUMERIC)
  #if __cpp_lib_constexpr_numeric >= 201911L
    #define LBAL_LIBCPP20_CONSTEXPR_NUMERIC __cpp_lib_constexpr_numeric
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_NUMERIC

#if !defined(LBAL_LIBCPP20_CONSTEXPR_STRING)
  #if __cpp_lib_constexpr_string >= 201907L
    #define LBAL_LIBCPP20_CONSTEXPR_STRING __cpp_lib_constexpr_string
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_STRING

#if !defined(LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL)
  #if __cpp_lib_constexpr_string >= 201811L
    #define LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL __cpp_lib_constexpr_string
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL

#if !defined(LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW)
  #if __cpp_lib_constexpr_string_view >= 201811L
    #define LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW __cpp_lib_constexpr_string_view
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW

#if !defined(LBAL_LIBCPP20_CONSTEXPR_TUPLE)
  #if __cpp_lib_constexpr_tuple >= 201811L
    #define LBAL_LIBCPP20_CONSTEXPR_TUPLE __cpp_lib_constexpr_tuple
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_TUPLE

#if !defined(LBAL_LIBCPP20_CONSTEXPR_UTILITY)
  #if __cpp_lib_constexpr_utility >= 201811L
    #define LBAL_LIBCPP20_CONSTEXPR_UTILITY __cpp_lib_constexpr_utility
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_UTILITY

#if !defined(LBAL_LIBCPP20_CONSTEXPR_VECTOR)
  #if __cpp_lib_constexpr_vector >= 201907L
    #define LBAL_LIBCPP20_CONSTEXPR_VECTOR __cpp_lib_constexpr_vector
  #endif
#endif  //  LBAL_LIBCPP20_CONSTEXPR_VECTOR

#if !defined(LBAL_LIBCPP20_COROUTINE)
  #if __cpp_lib_coroutine >= 201902L
    #define LBAL_LIBCPP20_COROUTINE __cpp_lib_coroutine
  #endif
#endif  //  LBAL_LIBCPP20_COROUTINE

#if !defined(LBAL_LIBCPP20_COROUTINE_EXP)
  #if __cpp_lib_experimental_coroutine >= 201902L
    #define LBAL_LIBCPP20_COROUTINE_EXP __cpp_lib_experimental_coroutine
  #endif
#endif  //  LBAL_LIBCPP20_COROUTINE_EXP

#if !defined(LBAL_LIBCPP20_DESTROYING_DELETE)
  #if __cpp_lib_destroying_delete >= 201806L
    #define LBAL_LIBCPP20_DESTROYING_DELETE __cpp_lib_destroying_delete
  #endif
#endif  //  LBAL_LIBCPP20_DESTROYING_DELETE

#if !defined(LBAL_LIBCPP20_ENDIAN)
  #if __cpp_lib_endian >= 201907L
    #define LBAL_LIBCPP20_ENDIAN __cpp_lib_endian
  #endif
#endif  //  LBAL_LIBCPP20_ENDIAN

#if !defined(LBAL_LIBCPP20_ENDIAN_BIT)
  #if __cpp_lib_endian >= 201907L
    #define LBAL_LIBCPP20_ENDIAN_BIT __cpp_lib_endian
  #endif
#endif  //  LBAL_LIBCPP20_ENDIAN_BIT

#if !defined(LBAL_LIBCPP20_ERASE_IF)
  #if __cpp_lib_erase_if >= 201811L
    #define LBAL_LIBCPP20_ERASE_IF __cpp_lib_erase_if
  #endif
#endif  //  LBAL_LIBCPP20_ERASE_IF

#if !defined(LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS)
  #if __cpp_lib_erase_if >= 202002L
    #define LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS __cpp_lib_erase_if
  #endif
#endif  //  LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS

#if !defined(LBAL_LIBCPP20_EXECUTION_VECTORIZATION)
  #if __cpp_lib_execution >= 201902L
    #define LBAL_LIBCPP20_EXECUTION_VECTORIZATION __cpp_lib_execution
  #endif
#endif  //  LBAL_LIBCPP20_EXECUTION_VECTORIZATION

#if !defined(LBAL_LIBCPP20_FORMAT)
  #if __cpp_lib_format >= 201907L
    #define LBAL_LIBCPP20_FORMAT __cpp_lib_format
  #endif
#endif  //  LBAL_LIBCPP20_FORMAT

#if !defined(LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP)
  #if __cpp_lib_generic_unordered_hash_lookup >= 201902L
    #define LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP                        \
      __cpp_lib_generic_unordered_hash_lookup
  #endif
#endif  //  LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP

#if !defined(LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP)
  #if __cpp_lib_generic_unordered_lookup >= 201811L
    #define LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP                             \
      __cpp_lib_generic_unordered_lookup
  #endif
#endif  //  LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP

#if !defined(LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS)
  #if __cpp_lib_integer_comparison_functions >= 202002L
    #define LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS                         \
      __cpp_lib_integer_comparison_functions
  #endif
#endif  //  LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS

#if !defined(LBAL_LIBCPP20_INTERPOLATE)
  #if __cpp_lib_interpolate >= 201902L
    #define LBAL_LIBCPP20_INTERPOLATE __cpp_lib_interpolate
  #endif
#endif  //  LBAL_LIBCPP20_INTERPOLATE

#if !defined(LBAL_LIBCPP20_INT_POW2)
  #if __cpp_lib_int_pow2 >= 201806L
    #define LBAL_LIBCPP20_INT_POW2 __cpp_lib_int_pow2
  #endif
#endif  //  LBAL_LIBCPP20_INT_POW2

#if !defined(LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME)
  #if __cpp_lib_int_pow2 >= 202002L
    #define LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME __cpp_lib_int_pow2
  #endif
#endif  //  LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME

#if !defined(LBAL_LIBCPP20_IS_CONSTANT_EVALUATED)
  #if __cpp_lib_is_constant_evaluated >= 201811L
    #define LBAL_LIBCPP20_IS_CONSTANT_EVALUATED __cpp_lib_is_constant_evaluated
  #endif
#endif  //  LBAL_LIBCPP20_IS_CONSTANT_EVALUATED

#if !defined(LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE)
  #if __cpp_lib_is_layout_compatible >= 201907L
    #define LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE __cpp_lib_is_layout_compatible
  #endif
#endif  //  LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE

#if !defined(LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE)
  #if __cpp_lib_is_nothrow_convertible >= 201806L
    #define LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE                               \
      __cpp_lib_is_nothrow_convertible
  #endif
#endif  //  LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE

#if !defined(LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE)
  #if __cpp_lib_is_pointer_interconvertible >= 201907L
    #define LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE                          \
      __cpp_lib_is_pointer_interconvertible
  #endif
#endif  //  LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE

#if !defined(LBAL_LIBCPP20_JTHREAD)
  #if __cpp_lib_jthread >= 201907L
    #define LBAL_LIBCPP20_JTHREAD __cpp_lib_jthread
  #endif
#endif  //  LBAL_LIBCPP20_JTHREAD

#if !defined(LBAL_LIBCPP20_JTHREAD_CV)
  #if __cpp_lib_jthread >= 201911L
    #define LBAL_LIBCPP20_JTHREAD_CV __cpp_lib_jthread
  #endif
#endif  //  LBAL_LIBCPP20_JTHREAD_CV

#if !defined(LBAL_LIBCPP20_LATCH)
  #if __cpp_lib_latch >= 201907L
    #define LBAL_LIBCPP20_LATCH __cpp_lib_latch
  #endif
#endif  //  LBAL_LIBCPP20_LATCH

#if !defined(LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE)
  #if __cpp_lib_list_remove_return_type >= 201806L
    #define LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE                              \
      __cpp_lib_list_remove_return_type
  #endif
#endif  //  LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE

#if !defined(LBAL_LIBCPP20_MATH_CONSTANTS)
  #if __cpp_lib_math_constants >= 201907L
    #define LBAL_LIBCPP20_MATH_CONSTANTS __cpp_lib_math_constants
  #endif
#endif  //  LBAL_LIBCPP20_MATH_CONSTANTS

#if !defined(LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR)
  #if __cpp_lib_polymorphic_allocator >= 201902L
    #define LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR __cpp_lib_polymorphic_allocator
  #endif
#endif  //  LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR

#if !defined(LBAL_LIBCPP20_RANGES)
  #if __cpp_lib_ranges >= 201811L
    #define LBAL_LIBCPP20_RANGES __cpp_lib_ranges
  #endif
#endif  //  LBAL_LIBCPP20_RANGES

#if !defined(LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS)
  #if __cpp_lib_ranges >= 201907L
    #define LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS __cpp_lib_ranges
  #endif
#endif  //  LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS

#if !defined(LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE)
  #if __cpp_lib_ranges >= 201911L
    #define LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE __cpp_lib_ranges
  #endif
#endif  //  LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE

#if !defined(LBAL_LIBCPP20_REMOVE_CVREF)
  #if __cpp_lib_remove_cvref >= 201711L
    #define LBAL_LIBCPP20_REMOVE_CVREF __cpp_lib_remove_cvref
  #endif
#endif  //  LBAL_LIBCPP20_REMOVE_CVREF

#if !defined(LBAL_LIBCPP20_SEMAPHORE)
  #if __cpp_lib_semaphore >= 201907L
    #define LBAL_LIBCPP20_SEMAPHORE __cpp_lib_semaphore
  #endif
#endif  //  LBAL_LIBCPP20_SEMAPHORE

#if !defined(LBAL_LIBCPP20_SHARED_PTR_ARRAYS)
  #if __cpp_lib_shared_ptr_arrays >= 201707L
    #define LBAL_LIBCPP20_SHARED_PTR_ARRAYS __cpp_lib_shared_ptr_arrays
  #endif
#endif  //  LBAL_LIBCPP20_SHARED_PTR_ARRAYS

#if !defined(LBAL_LIBCPP20_SHIFT)
  #if __cpp_lib_shift >= 201806L
    #define LBAL_LIBCPP20_SHIFT __cpp_lib_shift
  #endif
#endif  //  LBAL_LIBCPP20_SHIFT

#if !defined(LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE)
  #if __cpp_lib_smart_ptr_for_overwrite >= 202002L
    #define LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE                              \
      __cpp_lib_smart_ptr_for_overwrite
  #endif
#endif  //  LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE

#if !defined(LBAL_LIBCPP20_SOURCE_LOCATION)
  #if __cpp_lib_source_location >= 201907L
    #define LBAL_LIBCPP20_SOURCE_LOCATION __cpp_lib_source_location
  #endif
#endif  //  LBAL_LIBCPP20_SOURCE_LOCATION

#if !defined(LBAL_LIBCPP20_SPAN)
  #if __cpp_lib_span >= 201803L
    #define LBAL_LIBCPP20_SPAN __cpp_lib_span
  #endif
#endif  //  LBAL_LIBCPP20_SPAN

#if !defined(LBAL_LIBCPP20_SPAN_FIXED_SIZE)
  #if __cpp_lib_span >= 202002L
    #define LBAL_LIBCPP20_SPAN_FIXED_SIZE __cpp_lib_span
  #endif
#endif  //  LBAL_LIBCPP20_SPAN_FIXED_SIZE

#if !defined(LBAL_LIBCPP20_SPAN_USABILITY)
  #if __cpp_lib_span >= 201902L
    #define LBAL_LIBCPP20_SPAN_USABILITY __cpp_lib_span
  #endif
#endif  //  LBAL_LIBCPP20_SPAN_USABILITY

#if !defined(LBAL_LIBCPP20_SSIZE)
  #if __cpp_lib_ssize >= 201902L
    #define LBAL_LIBCPP20_SSIZE __cpp_lib_ssize
  #endif
#endif  //  LBAL_LIBCPP20_SSIZE

#if !defined(LBAL_LIBCPP20_STARTS_ENDS_WITH)
  #if __cpp_lib_starts_ends_with >= 201711L
    #define LBAL_LIBCPP20_STARTS_ENDS_WITH __cpp_lib_starts_ends_with
  #endif
#endif  //  LBAL_LIBCPP20_STARTS_ENDS_WITH

#if !defined(LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR)
  #if __cpp_lib_string_view >= 201803L
    #define LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR __cpp_lib_string_view
  #endif
#endif  //  LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR

#if !defined(LBAL_LIBCPP20_SYNCBUF)
  #if __cpp_lib_syncbuf >= 201711L
    #define LBAL_LIBCPP20_SYNCBUF __cpp_lib_syncbuf
  #endif
#endif  //  LBAL_LIBCPP20_SYNCBUF

#if !defined(LBAL_LIBCPP20_SYNCBUF_MANIPULATORS)
  #if __cpp_lib_syncbuf >= 201803L
    #define LBAL_LIBCPP20_SYNCBUF_MANIPULATORS __cpp_lib_syncbuf
  #endif
#endif  //  LBAL_LIBCPP20_SYNCBUF_MANIPULATORS

#if !defined(LBAL_LIBCPP20_THREE_WAY_COMPARISON)
  #if __cpp_lib_three_way_comparison >= 201711L
    #define LBAL_LIBCPP20_THREE_WAY_COMPARISON __cpp_lib_three_way_comparison
  #endif
#endif  //  LBAL_LIBCPP20_THREE_WAY_COMPARISON

#if !defined(LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY)
  #if __cpp_lib_three_way_comparison >= 201907L
    #define LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY                         \
      __cpp_lib_three_way_comparison
  #endif
#endif  //  LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY

#if !defined(LBAL_LIBCPP20_TO_ADDRESS)
  #if __cpp_lib_to_address >= 201711L
    #define LBAL_LIBCPP20_TO_ADDRESS __cpp_lib_to_address
  #endif
#endif  //  LBAL_LIBCPP20_TO_ADDRESS

#if !defined(LBAL_LIBCPP20_TO_ARRAY)
  #if __cpp_lib_to_array >= 201907L
    #define LBAL_LIBCPP20_TO_ARRAY __cpp_lib_to_array
  #endif
#endif  //  LBAL_LIBCPP20_TO_ARRAY

#if !defined(LBAL_LIBCPP20_TYPE_IDENTITY)
  #if __cpp_lib_type_identity >= 201806L
    #define LBAL_LIBCPP20_TYPE_IDENTITY __cpp_lib_type_identity
  #endif
#endif  //  LBAL_LIBCPP20_TYPE_IDENTITY

#if !defined(LBAL_LIBCPP20_UNWRAP_REF)
  #if __cpp_lib_unwrap_ref >= 201811L
    #define LBAL_LIBCPP20_UNWRAP_REF __cpp_lib_unwrap_ref
  #endif
#endif  //  LBAL_LIBCPP20_UNWRAP_REF

// C++23

#if !defined(LBAL_LIBCPP23_ADAPTOR_ITERATOR_PAIR_CONSTRUCTOR)
  #if __cpp_lib_adaptor_iterator_pair_constructor >= 202106L
    #define LBAL_LIBCPP23_ADAPTOR_ITERATOR_PAIR_CONSTRUCTOR                    \
      __cpp_lib_adaptor_iterator_pair_constructor
  #endif
#endif  //  LBAL_LIBCPP23_ADAPTOR_ITERATOR_PAIR_CONSTRUCTOR

#if !defined(LBAL_LIBCPP23_ALGORITHM_ITERATOR_REQUIREMENTS)
  #if __cpp_lib_algorithm_iterator_requirements >= 202207L
    #define LBAL_LIBCPP23_ALGORITHM_ITERATOR_REQUIREMENTS                      \
      __cpp_lib_algorithm_iterator_requirements
  #endif
#endif  //  LBAL_LIBCPP23_ALGORITHM_ITERATOR_REQUIREMENTS

#if !defined(LBAL_LIBCPP23_ALLOCATE_AT_LEAST)
  #if __cpp_lib_allocate_at_least >= 202106L
    #define LBAL_LIBCPP23_ALLOCATE_AT_LEAST __cpp_lib_allocate_at_least
  #endif
#endif  //  LBAL_LIBCPP23_ALLOCATE_AT_LEAST

#if !defined(LBAL_LIBCPP23_ALLOCATE_AT_LEAST_DISALLOW_USER_SPEC)
  #if __cpp_lib_allocate_at_least >= 202302L
    #define LBAL_LIBCPP23_ALLOCATE_AT_LEAST_DISALLOW_USER_SPEC                 \
      __cpp_lib_allocate_at_least
  #endif
#endif  //  LBAL_LIBCPP23_ALLOCATE_AT_LEAST_DISALLOW_USER_SPEC

#if !defined(LBAL_LIBCPP23_ASSOCIATIVE_HETEROGENEOUS_ERASURE)
  #if __cpp_lib_associative_heterogeneous_erasure >= 202110L
    #define LBAL_LIBCPP23_ASSOCIATIVE_HETEROGENEOUS_ERASURE                    \
      __cpp_lib_associative_heterogeneous_erasure
  #endif
#endif  //  LBAL_LIBCPP23_ASSOCIATIVE_HETEROGENEOUS_ERASURE

#if !defined(LBAL_LIBCPP23_BARRIER_RELAXED_COMPLETION)
  #if __cpp_lib_barrier >= 202302L
    #define LBAL_LIBCPP23_BARRIER_RELAXED_COMPLETION __cpp_lib_barrier
  #endif
#endif  //  LBAL_LIBCPP23_BARRIER_RELAXED_COMPLETION

#if !defined(LBAL_LIBCPP23_BIND_BACK)
  #if __cpp_lib_bind_back >= 202202L
    #define LBAL_LIBCPP23_BIND_BACK __cpp_lib_bind_back
  #endif
#endif  //  LBAL_LIBCPP23_BIND_BACK

#if !defined(LBAL_LIBCPP23_BYTESWAP)
  #if __cpp_lib_byteswap >= 202110L
    #define LBAL_LIBCPP23_BYTESWAP __cpp_lib_byteswap
  #endif
#endif  //  LBAL_LIBCPP23_BYTESWAP

#if !defined(LBAL_LIBCPP23_COMMON_REFERENCE)
  #if __cpp_lib_common_reference >= 202302L
    #define LBAL_LIBCPP23_COMMON_REFERENCE __cpp_lib_common_reference
  #endif
#endif  //  LBAL_LIBCPP23_COMMON_REFERENCE

#if !defined(LBAL_LIBCPP23_COMMON_REFERENCE_WRAPPER)
  #if __cpp_lib_common_reference_wrapper >= 202302L
    #define LBAL_LIBCPP23_COMMON_REFERENCE_WRAPPER                             \
      __cpp_lib_common_reference_wrapper
  #endif
#endif  //  LBAL_LIBCPP23_COMMON_REFERENCE_WRAPPER

#if !defined(LBAL_LIBCPP23_CONCEPTS_MOVE_ONLY)
  #if __cpp_lib_concepts >= 202207L
    #define LBAL_LIBCPP23_CONCEPTS_MOVE_ONLY __cpp_lib_concepts
  #endif
#endif  //  LBAL_LIBCPP23_CONCEPTS_MOVE_ONLY

#if !defined(LBAL_LIBCPP23_CONSTEXPR_BITSET)
  #if __cpp_lib_constexpr_bitset >= 202207L
    #define LBAL_LIBCPP23_CONSTEXPR_BITSET __cpp_lib_constexpr_bitset
  #endif
#endif  //  LBAL_LIBCPP23_CONSTEXPR_BITSET

#if !defined(LBAL_LIBCPP23_CONSTEXPR_CHARCONV)
  #if __cpp_lib_constexpr_charconv >= 202207L
    #define LBAL_LIBCPP23_CONSTEXPR_CHARCONV __cpp_lib_constexpr_charconv
  #endif
#endif  //  LBAL_LIBCPP23_CONSTEXPR_CHARCONV

#if !defined(LBAL_LIBCPP23_CONSTEXPR_CMATH)
  #if __cpp_lib_constexpr_cmath >= 202202L
    #define LBAL_LIBCPP23_CONSTEXPR_CMATH __cpp_lib_constexpr_cmath
  #endif
#endif  //  LBAL_LIBCPP23_CONSTEXPR_CMATH

#if !defined(LBAL_LIBCPP23_CONSTEXPR_MEMORY_UNIQUE_PTR)
  #if __cpp_lib_constexpr_memory >= 202202L
    #define LBAL_LIBCPP23_CONSTEXPR_MEMORY_UNIQUE_PTR __cpp_lib_constexpr_memory
  #endif
#endif  //  LBAL_LIBCPP23_CONSTEXPR_MEMORY_UNIQUE_PTR

#if !defined(LBAL_LIBCPP23_CONSTEXPR_TYPEINFO)
  #if __cpp_lib_constexpr_typeinfo >= 202106L
    #define LBAL_LIBCPP23_CONSTEXPR_TYPEINFO __cpp_lib_constexpr_typeinfo
  #endif
#endif  //  LBAL_LIBCPP23_CONSTEXPR_TYPEINFO

#if !defined(LBAL_LIBCPP23_CONTAINERS_RANGES)
  #if __cpp_lib_containers_ranges >= 202202L
    #define LBAL_LIBCPP23_CONTAINERS_RANGES __cpp_lib_containers_ranges
  #endif
#endif  //  LBAL_LIBCPP23_CONTAINERS_RANGES

#if !defined(LBAL_LIBCPP23_EXPECTED)
  #if __cpp_lib_expected >= 202202L
    #define LBAL_LIBCPP23_EXPECTED __cpp_lib_expected
  #endif
#endif  //  LBAL_LIBCPP23_EXPECTED

#if !defined(LBAL_LIBCPP23_EXPECTED_MONADIC)
  #if __cpp_lib_expected >= 202211L
    #define LBAL_LIBCPP23_EXPECTED_MONADIC __cpp_lib_expected
  #endif
#endif  //  LBAL_LIBCPP23_EXPECTED_MONADIC

#if !defined(LBAL_LIBCPP23_FLAT_MAP)
  #if __cpp_lib_flat_map >= 202207L
    #define LBAL_LIBCPP23_FLAT_MAP __cpp_lib_flat_map
  #endif
#endif  //  LBAL_LIBCPP23_FLAT_MAP

#if !defined(LBAL_LIBCPP23_FLAT_SET)
  #if __cpp_lib_flat_set >= 202207L
    #define LBAL_LIBCPP23_FLAT_SET __cpp_lib_flat_set
  #endif
#endif  //  LBAL_LIBCPP23_FLAT_SET

#if !defined(LBAL_LIBCPP23_FORMAT)
  #if __cpp_lib_format >= 202106L
    #define LBAL_LIBCPP23_FORMAT __cpp_lib_format
  #endif
#endif  //  LBAL_LIBCPP23_FORMAT

#if !defined(LBAL_LIBCPP23_FORMATTERS)
  #if __cpp_lib_formatters >= 202302L
    #define LBAL_LIBCPP23_FORMATTERS __cpp_lib_formatters
  #endif
#endif  //  LBAL_LIBCPP23_FORMATTERS

#if !defined(LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING)
  #if __cpp_lib_format >= 202207L
    #define LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING __cpp_lib_format
  #endif
#endif  //  LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING

#if !defined(LBAL_LIBCPP23_FORMAT_ENCODINGS)
  #if __cpp_lib_format >= 202207L
    #define LBAL_LIBCPP23_FORMAT_ENCODINGS __cpp_lib_format
  #endif
#endif  //  LBAL_LIBCPP23_FORMAT_ENCODINGS

#if !defined(LBAL_LIBCPP23_FORMAT_GENERATOR)
  #if __cpp_lib_format >= 202110L
    #define LBAL_LIBCPP23_FORMAT_GENERATOR __cpp_lib_format
  #endif
#endif  //  LBAL_LIBCPP23_FORMAT_GENERATOR

#if !defined(LBAL_LIBCPP23_FORMAT_LOCALE)
  #if __cpp_lib_format >= 202110L
    #define LBAL_LIBCPP23_FORMAT_LOCALE __cpp_lib_format
  #endif
#endif  //  LBAL_LIBCPP23_FORMAT_LOCALE

#if !defined(LBAL_LIBCPP23_FORMAT_RANGES)
  #if __cpp_lib_format_ranges >= 202207L
    #define LBAL_LIBCPP23_FORMAT_RANGES __cpp_lib_format_ranges
  #endif
#endif  //  LBAL_LIBCPP23_FORMAT_RANGES

#if !defined(LBAL_LIBCPP23_FORWARD_LIKE)
  #if __cpp_lib_forward_like >= 202207L
    #define LBAL_LIBCPP23_FORWARD_LIKE __cpp_lib_forward_like
  #endif
#endif  //  LBAL_LIBCPP23_FORWARD_LIKE

#if !defined(LBAL_LIBCPP23_GENERATOR)
  #if __cpp_lib_generator >= 202207L
    #define LBAL_LIBCPP23_GENERATOR __cpp_lib_generator
  #endif
#endif  //  LBAL_LIBCPP23_GENERATOR

#if !defined(LBAL_LIBCPP23_INVOKE_R)
  #if __cpp_lib_invoke_r >= 202106L
    #define LBAL_LIBCPP23_INVOKE_R __cpp_lib_invoke_r
  #endif
#endif  //  LBAL_LIBCPP23_INVOKE_R

#if !defined(LBAL_LIBCPP23_IOS_NOREPLACE)
  #if __cpp_lib_ios_noreplace >= 202207L
    #define LBAL_LIBCPP23_IOS_NOREPLACE __cpp_lib_ios_noreplace
  #endif
#endif  //  LBAL_LIBCPP23_IOS_NOREPLACE

#if !defined(LBAL_LIBCPP23_IS_IMPLICIT_LIFETIME)
  #if __cpp_lib_is_implicit_lifetime >= 202302L
    #define LBAL_LIBCPP23_IS_IMPLICIT_LIFETIME __cpp_lib_is_implicit_lifetime
  #endif
#endif  //  LBAL_LIBCPP23_IS_IMPLICIT_LIFETIME

#if !defined(LBAL_LIBCPP23_IS_SCOPED_ENUM)
  #if __cpp_lib_is_scoped_enum >= 202011L
    #define LBAL_LIBCPP23_IS_SCOPED_ENUM __cpp_lib_is_scoped_enum
  #endif
#endif  //  LBAL_LIBCPP23_IS_SCOPED_ENUM

#if !defined(LBAL_LIBCPP23_MDSPAN)
  #if __cpp_lib_mdspan >= 202207L
    #define LBAL_LIBCPP23_MDSPAN __cpp_lib_mdspan
  #endif
#endif  //  LBAL_LIBCPP23_MDSPAN

#if !defined(LBAL_LIBCPP23_MODULES)
  #if __cpp_lib_modules >= 202207L
    #define LBAL_LIBCPP23_MODULES __cpp_lib_modules
  #endif
#endif  //  LBAL_LIBCPP23_MODULES

#if !defined(LBAL_LIBCPP23_MOVE_ITERATOR_CONCEPT)
  #if __cpp_lib_move_iterator_concept >= 202207L
    #define LBAL_LIBCPP23_MOVE_ITERATOR_CONCEPT __cpp_lib_move_iterator_concept
  #endif
#endif  //  LBAL_LIBCPP23_MOVE_ITERATOR_CONCEPT

#if !defined(LBAL_LIBCPP23_MOVE_ONLY_FUNCTION)
  #if __cpp_lib_move_only_function >= 202110L
    #define LBAL_LIBCPP23_MOVE_ONLY_FUNCTION __cpp_lib_move_only_function
  #endif
#endif  //  LBAL_LIBCPP23_MOVE_ONLY_FUNCTION

#if !defined(LBAL_LIBCPP23_OPTIONAL_CONSTEXPR)
  #if __cpp_lib_optional >= 202106L
    #define LBAL_LIBCPP23_OPTIONAL_CONSTEXPR __cpp_lib_optional
  #endif
#endif  //  LBAL_LIBCPP23_OPTIONAL_CONSTEXPR

#if !defined(LBAL_LIBCPP23_OPTIONAL_MONADIC)
  #if __cpp_lib_optional >= 202110L
    #define LBAL_LIBCPP23_OPTIONAL_MONADIC __cpp_lib_optional
  #endif
#endif  //  LBAL_LIBCPP23_OPTIONAL_MONADIC

#if !defined(LBAL_LIBCPP23_OUT_PTR)
  #if __cpp_lib_out_ptr >= 202106L
    #define LBAL_LIBCPP23_OUT_PTR __cpp_lib_out_ptr
  #endif
#endif  //  LBAL_LIBCPP23_OUT_PTR

#if !defined(LBAL_LIBCPP23_PRINT)
  #if __cpp_lib_print >= 202207L
    #define LBAL_LIBCPP23_PRINT __cpp_lib_print
  #endif
#endif  //  LBAL_LIBCPP23_PRINT

#if !defined(LBAL_LIBCPP23_RANGES_AS_CONST)
  #if __cpp_lib_ranges_as_const >= 202207L
    #define LBAL_LIBCPP23_RANGES_AS_CONST __cpp_lib_ranges_as_const
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_AS_CONST

#if !defined(LBAL_LIBCPP23_RANGES_AS_RVALUE)
  #if __cpp_lib_ranges_as_rvalue >= 202207L
    #define LBAL_LIBCPP23_RANGES_AS_RVALUE __cpp_lib_ranges_as_rvalue
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_AS_RVALUE

#if !defined(LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT)
  #if __cpp_lib_ranges_cartesian_product >= 202207L
    #define LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT                             \
      __cpp_lib_ranges_cartesian_product
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT

#if !defined(LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT_EMPTY)
  #if __cpp_lib_ranges_cartesian_product >= 202207L
    #define LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT_EMPTY                       \
      __cpp_lib_ranges_cartesian_product
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT_EMPTY

#if !defined(LBAL_LIBCPP23_RANGES_CHUNK)
  #if __cpp_lib_ranges_chunk >= 202202L
    #define LBAL_LIBCPP23_RANGES_CHUNK __cpp_lib_ranges_chunk
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_CHUNK

#if !defined(LBAL_LIBCPP23_RANGES_CHUNK_BY)
  #if __cpp_lib_ranges_chunk_by >= 202202L
    #define LBAL_LIBCPP23_RANGES_CHUNK_BY __cpp_lib_ranges_chunk_by
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_CHUNK_BY

#if !defined(LBAL_LIBCPP23_RANGES_CONTAINS)
  #if __cpp_lib_ranges_contains >= 202207L
    #define LBAL_LIBCPP23_RANGES_CONTAINS __cpp_lib_ranges_contains
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_CONTAINS

#if !defined(LBAL_LIBCPP23_RANGES_ENUMERATE)
  #if __cpp_lib_ranges_enumerate >= 202302L
    #define LBAL_LIBCPP23_RANGES_ENUMERATE __cpp_lib_ranges_enumerate
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_ENUMERATE

#if !defined(LBAL_LIBCPP23_RANGES_FIND_LAST)
  #if __cpp_lib_ranges_find_last >= 202207L
    #define LBAL_LIBCPP23_RANGES_FIND_LAST __cpp_lib_ranges_find_last
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_FIND_LAST

#if !defined(LBAL_LIBCPP23_RANGES_FOLD)
  #if __cpp_lib_ranges_fold >= 202207L
    #define LBAL_LIBCPP23_RANGES_FOLD __cpp_lib_ranges_fold
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_FOLD

#if !defined(LBAL_LIBCPP23_RANGES_FORMALIZED_VIEW)
  #if __cpp_lib_ranges >= 202110L
    #define LBAL_LIBCPP23_RANGES_FORMALIZED_VIEW __cpp_lib_ranges
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_FORMALIZED_VIEW

#if !defined(LBAL_LIBCPP23_RANGES_IOTA)
  #if __cpp_lib_ranges_iota >= 202202L
    #define LBAL_LIBCPP23_RANGES_IOTA __cpp_lib_ranges_iota
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_IOTA

#if !defined(LBAL_LIBCPP23_RANGES_JOIN_WITH)
  #if __cpp_lib_ranges_join_with >= 202202L
    #define LBAL_LIBCPP23_RANGES_JOIN_WITH __cpp_lib_ranges_join_with
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_JOIN_WITH

#if !defined(LBAL_LIBCPP23_RANGES_NON_DEFAULT_CONSTRUCTIBLE)
  #if __cpp_lib_ranges >= 202106L
    #define LBAL_LIBCPP23_RANGES_NON_DEFAULT_CONSTRUCTIBLE __cpp_lib_ranges
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_NON_DEFAULT_CONSTRUCTIBLE

#if !defined(LBAL_LIBCPP23_RANGES_RELAXED)
  #if __cpp_lib_ranges >= 202302L
    #define LBAL_LIBCPP23_RANGES_RELAXED __cpp_lib_ranges
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_RELAXED

#if !defined(LBAL_LIBCPP23_RANGES_REMOVE_POISON_PILLS)
  #if __cpp_lib_ranges >= 202211L
    #define LBAL_LIBCPP23_RANGES_REMOVE_POISON_PILLS __cpp_lib_ranges
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_REMOVE_POISON_PILLS

#if !defined(LBAL_LIBCPP23_RANGES_REPEAT)
  #if __cpp_lib_ranges_repeat >= 202207L
    #define LBAL_LIBCPP23_RANGES_REPEAT __cpp_lib_ranges_repeat
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_REPEAT

#if !defined(LBAL_LIBCPP23_RANGES_SLIDE)
  #if __cpp_lib_ranges_slide >= 202202L
    #define LBAL_LIBCPP23_RANGES_SLIDE __cpp_lib_ranges_slide
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_SLIDE

#if !defined(LBAL_LIBCPP23_RANGES_STARTS_ENDS_WITH)
  #if __cpp_lib_ranges_starts_ends_with >= 202106L
    #define LBAL_LIBCPP23_RANGES_STARTS_ENDS_WITH                              \
      __cpp_lib_ranges_starts_ends_with
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_STARTS_ENDS_WITH

#if !defined(LBAL_LIBCPP23_RANGES_STRIDE)
  #if __cpp_lib_ranges_stride >= 202207L
    #define LBAL_LIBCPP23_RANGES_STRIDE __cpp_lib_ranges_stride
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_STRIDE

#if !defined(LBAL_LIBCPP23_RANGES_SUPPORT_MOVE_ONLY_TYPES)
  #if __cpp_lib_ranges >= 202207L
    #define LBAL_LIBCPP23_RANGES_SUPPORT_MOVE_ONLY_TYPES __cpp_lib_ranges
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_SUPPORT_MOVE_ONLY_TYPES

#if !defined(LBAL_LIBCPP23_RANGES_TO_CONTAINER)
  #if __cpp_lib_ranges_to_container >= 202202L
    #define LBAL_LIBCPP23_RANGES_TO_CONTAINER __cpp_lib_ranges_to_container
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_TO_CONTAINER

#if !defined(LBAL_LIBCPP23_RANGES_USER_ADAPTOR_PIPES)
  #if __cpp_lib_ranges >= 202202L
    #define LBAL_LIBCPP23_RANGES_USER_ADAPTOR_PIPES __cpp_lib_ranges
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_USER_ADAPTOR_PIPES

#if !defined(LBAL_LIBCPP23_RANGES_ZIP)
  #if __cpp_lib_ranges_zip >= 202110L
    #define LBAL_LIBCPP23_RANGES_ZIP __cpp_lib_ranges_zip
  #endif
#endif  //  LBAL_LIBCPP23_RANGES_ZIP

#if !defined(LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY)
  #if __cpp_lib_reference_from_temporary >= 202202L
    #define LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY                             \
      __cpp_lib_reference_from_temporary
  #endif
#endif  //  LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY

#if !defined(LBAL_LIBCPP23_SHIFT_RANGES)
  #if __cpp_lib_shift >= 202202L
    #define LBAL_LIBCPP23_SHIFT_RANGES __cpp_lib_shift
  #endif
#endif  //  LBAL_LIBCPP23_SHIFT_RANGES

#if !defined(LBAL_LIBCPP23_SPANSTREAM)
  #if __cpp_lib_spanstream >= 202106L
    #define LBAL_LIBCPP23_SPANSTREAM __cpp_lib_spanstream
  #endif
#endif  //  LBAL_LIBCPP23_SPANSTREAM

#if !defined(LBAL_LIBCPP23_STACKTRACE)
  #if __cpp_lib_stacktrace >= 202011L
    #define LBAL_LIBCPP23_STACKTRACE __cpp_lib_stacktrace
  #endif
#endif  //  LBAL_LIBCPP23_STACKTRACE

#if !defined(LBAL_LIBCPP23_START_LIFETIME_AS)
  #if __cpp_lib_start_lifetime_as >= 202207L
    #define LBAL_LIBCPP23_START_LIFETIME_AS __cpp_lib_start_lifetime_as
  #endif
#endif  //  LBAL_LIBCPP23_START_LIFETIME_AS

#if !defined(LBAL_LIBCPP23_STDATOMIC_H)
  #if __cpp_lib_stdatomic_h >= 202011L
    #define LBAL_LIBCPP23_STDATOMIC_H __cpp_lib_stdatomic_h
  #endif
#endif  //  LBAL_LIBCPP23_STDATOMIC_H

#if !defined(LBAL_LIBCPP23_STRING_CONTAINS)
  #if __cpp_lib_string_contains >= 202011L
    #define LBAL_LIBCPP23_STRING_CONTAINS __cpp_lib_string_contains
  #endif
#endif  //  LBAL_LIBCPP23_STRING_CONTAINS

#if !defined(LBAL_LIBCPP23_STRING_RESIZE_AND_OVERWRITE)
  #if __cpp_lib_string_resize_and_overwrite >= 202110L
    #define LBAL_LIBCPP23_STRING_RESIZE_AND_OVERWRITE                          \
      __cpp_lib_string_resize_and_overwrite
  #endif
#endif  //  LBAL_LIBCPP23_STRING_RESIZE_AND_OVERWRITE

#if !defined(LBAL_LIBCPP23_TO_UNDERLYING)
  #if __cpp_lib_to_underlying >= 202102L
    #define LBAL_LIBCPP23_TO_UNDERLYING __cpp_lib_to_underlying
  #endif
#endif  //  LBAL_LIBCPP23_TO_UNDERLYING

#if !defined(LBAL_LIBCPP23_TUPLE_LIKE)
  #if __cpp_lib_tuple_like >= 202207L
    #define LBAL_LIBCPP23_TUPLE_LIKE __cpp_lib_tuple_like
  #endif
#endif  //  LBAL_LIBCPP23_TUPLE_LIKE

#if !defined(LBAL_LIBCPP23_UNREACHABLE)
  #if __cpp_lib_unreachable >= 202202L
    #define LBAL_LIBCPP23_UNREACHABLE __cpp_lib_unreachable
  #endif
#endif  //  LBAL_LIBCPP23_UNREACHABLE

#if !defined(LBAL_LIBCPP23_VARIANT_CONSTEXPR)
  #if __cpp_lib_variant >= 202106L
    #define LBAL_LIBCPP23_VARIANT_CONSTEXPR __cpp_lib_variant
  #endif
#endif  //  LBAL_LIBCPP23_VARIANT_CONSTEXPR

#if !defined(LBAL_LIBCPP23_VARIANT_INHERITANCE)
  #if __cpp_lib_variant >= 202102L
    #define LBAL_LIBCPP23_VARIANT_INHERITANCE __cpp_lib_variant
  #endif
#endif  //  LBAL_LIBCPP23_VARIANT_INHERITANCE

// C++26

#if !defined(LBAL_LIBCPP26_ALIGNED_ACCESSOR)
  #if __cpp_lib_aligned_accessor >= 202411L
    #define LBAL_LIBCPP26_ALIGNED_ACCESSOR __cpp_lib_aligned_accessor
  #endif
#endif  //  LBAL_LIBCPP26_ALIGNED_ACCESSOR

#if !defined(LBAL_LIBCPP26_ASSOCIATIVE_HETEROGENEOUS_INSERTION)
  #if __cpp_lib_associative_heterogeneous_insertion >= 202306L
    #define LBAL_LIBCPP26_ASSOCIATIVE_HETEROGENEOUS_INSERTION                  \
      __cpp_lib_associative_heterogeneous_insertion
  #endif
#endif  //  LBAL_LIBCPP26_ASSOCIATIVE_HETEROGENEOUS_INSERTION

#if !defined(LBAL_LIBCPP26_ATOMIC_MIN_MAX)
  #if __cpp_lib_atomic_min_max >= 202403L
    #define LBAL_LIBCPP26_ATOMIC_MIN_MAX __cpp_lib_atomic_min_max
  #endif
#endif  //  LBAL_LIBCPP26_ATOMIC_MIN_MAX

#if !defined(LBAL_LIBCPP26_ATOMIC_MIN_MAX_FLOAT)
  #if __cpp_lib_atomic_min_max >= 202506L
    #define LBAL_LIBCPP26_ATOMIC_MIN_MAX_FLOAT __cpp_lib_atomic_min_max
  #endif
#endif  //  LBAL_LIBCPP26_ATOMIC_MIN_MAX_FLOAT

#if !defined(LBAL_LIBCPP26_ATOMIC_REDUCTIONS)
  #if __cpp_lib_atomic_reductions >= 202506L
    #define LBAL_LIBCPP26_ATOMIC_REDUCTIONS __cpp_lib_atomic_reductions
  #endif
#endif  //  LBAL_LIBCPP26_ATOMIC_REDUCTIONS

#if !defined(LBAL_LIBCPP26_ATOMIC_REF_ADDRESS)
  #if __cpp_lib_atomic_ref >= 202411L
    #define LBAL_LIBCPP26_ATOMIC_REF_ADDRESS __cpp_lib_atomic_ref
  #endif
#endif  //  LBAL_LIBCPP26_ATOMIC_REF_ADDRESS

#if !defined(LBAL_LIBCPP26_BIND_FRONT_NTTP_CALLABLES)
  #if __cpp_lib_bind_front >= 202306L
    #define LBAL_LIBCPP26_BIND_FRONT_NTTP_CALLABLES __cpp_lib_bind_front
  #endif
#endif  //  LBAL_LIBCPP26_BIND_FRONT_NTTP_CALLABLES

#if !defined(LBAL_LIBCPP26_BITSET)
  #if __cpp_lib_bitset >= 202306L
    #define LBAL_LIBCPP26_BITSET __cpp_lib_bitset
  #endif
#endif  //  LBAL_LIBCPP26_BITSET

#if !defined(LBAL_LIBCPP26_CHRONO_HASHING)
  #if __cpp_lib_chrono >= 202306L
    #define LBAL_LIBCPP26_CHRONO_HASHING __cpp_lib_chrono
  #endif
#endif  //  LBAL_LIBCPP26_CHRONO_HASHING

#if !defined(LBAL_LIBCPP26_CONSTANT_WRAPPER)
  #if __cpp_lib_constant_wrapper >= 202506L
    #define LBAL_LIBCPP26_CONSTANT_WRAPPER __cpp_lib_constant_wrapper
  #endif
#endif  //  LBAL_LIBCPP26_CONSTANT_WRAPPER

#if !defined(LBAL_LIBCPP26_CONSTEXPR_ALGORITHMS_STABLE_SORT)
  #if __cpp_lib_constexpr_algorithms >= 202306L
    #define LBAL_LIBCPP26_CONSTEXPR_ALGORITHMS_STABLE_SORT                     \
      __cpp_lib_constexpr_algorithms
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_ALGORITHMS_STABLE_SORT

#if !defined(LBAL_LIBCPP26_CONSTEXPR_ATOMIC)
  #if __cpp_lib_constexpr_atomic >= 202411L
    #define LBAL_LIBCPP26_CONSTEXPR_ATOMIC __cpp_lib_constexpr_atomic
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_ATOMIC

#if !defined(LBAL_LIBCPP26_CONSTEXPR_COMPLEX)
  #if __cpp_lib_constexpr_complex >= 202306L
    #define LBAL_LIBCPP26_CONSTEXPR_COMPLEX __cpp_lib_constexpr_complex
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_COMPLEX

#if !defined(LBAL_LIBCPP26_CONSTEXPR_DEQUE)
  #if __cpp_lib_constexpr_deque >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_DEQUE __cpp_lib_constexpr_deque
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_DEQUE

#if !defined(LBAL_LIBCPP26_CONSTEXPR_EXCEPTIONS)
  #if __cpp_lib_constexpr_exceptions >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_EXCEPTIONS __cpp_lib_constexpr_exceptions
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_EXCEPTIONS

#if !defined(LBAL_LIBCPP26_CONSTEXPR_FLAT_MAP)
  #if __cpp_lib_constexpr_flat_map >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_FLAT_MAP __cpp_lib_constexpr_flat_map
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_FLAT_MAP

#if !defined(LBAL_LIBCPP26_CONSTEXPR_FLAT_SET)
  #if __cpp_lib_constexpr_flat_set >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_FLAT_SET __cpp_lib_constexpr_flat_set
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_FLAT_SET

#if !defined(LBAL_LIBCPP26_CONSTEXPR_FORMAT)
  #if __cpp_lib_constexpr_format >= 202511L
    #define LBAL_LIBCPP26_CONSTEXPR_FORMAT __cpp_lib_constexpr_format
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_FORMAT

#if !defined(LBAL_LIBCPP26_CONSTEXPR_FORWARD_LIST)
  #if __cpp_lib_constexpr_forward_list >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_FORWARD_LIST                               \
      __cpp_lib_constexpr_forward_list
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_FORWARD_LIST

#if !defined(LBAL_LIBCPP26_CONSTEXPR_LIST)
  #if __cpp_lib_constexpr_list >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_LIST __cpp_lib_constexpr_list
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_LIST

#if !defined(LBAL_LIBCPP26_CONSTEXPR_MAP)
  #if __cpp_lib_constexpr_map >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_MAP __cpp_lib_constexpr_map
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_MAP

#if !defined(LBAL_LIBCPP26_CONSTEXPR_MEMORY_SHARED_PTR)
  #if __cpp_lib_constexpr_memory >= 202506L
    #define LBAL_LIBCPP26_CONSTEXPR_MEMORY_SHARED_PTR __cpp_lib_constexpr_memory
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_MEMORY_SHARED_PTR

#if !defined(LBAL_LIBCPP26_CONSTEXPR_QUEUE)
  #if __cpp_lib_constexpr_queue >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_QUEUE __cpp_lib_constexpr_queue
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_QUEUE

#if !defined(LBAL_LIBCPP26_CONSTEXPR_SET)
  #if __cpp_lib_constexpr_set >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_SET __cpp_lib_constexpr_set
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_SET

#if !defined(LBAL_LIBCPP26_CONSTEXPR_STACK)
  #if __cpp_lib_constexpr_stack >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_STACK __cpp_lib_constexpr_stack
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_STACK

#if !defined(LBAL_LIBCPP26_CONSTEXPR_UNORDERED_MAP)
  #if __cpp_lib_constexpr_unordered_map >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_UNORDERED_MAP                              \
      __cpp_lib_constexpr_unordered_map
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_UNORDERED_MAP

#if !defined(LBAL_LIBCPP26_CONSTEXPR_UNORDERED_SET)
  #if __cpp_lib_constexpr_unordered_set >= 202502L
    #define LBAL_LIBCPP26_CONSTEXPR_UNORDERED_SET                              \
      __cpp_lib_constexpr_unordered_set
  #endif
#endif  //  LBAL_LIBCPP26_CONSTEXPR_UNORDERED_SET

#if !defined(LBAL_LIBCPP26_CONSTRAINED_EQUALITY)
  #if __cpp_lib_constrained_equality >= 202403L
    #define LBAL_LIBCPP26_CONSTRAINED_EQUALITY __cpp_lib_constrained_equality
  #endif
#endif  //  LBAL_LIBCPP26_CONSTRAINED_EQUALITY

#if !defined(LBAL_LIBCPP26_CONSTRAINED_EQUALITY_EXPECTED)
  #if __cpp_lib_constrained_equality >= 202411L
    #define LBAL_LIBCPP26_CONSTRAINED_EQUALITY_EXPECTED                        \
      __cpp_lib_constrained_equality
  #endif
#endif  //  LBAL_LIBCPP26_CONSTRAINED_EQUALITY_EXPECTED

#if !defined(LBAL_LIBCPP26_COPYABLE_FUNCTION)
  #if __cpp_lib_copyable_function >= 202306L
    #define LBAL_LIBCPP26_COPYABLE_FUNCTION __cpp_lib_copyable_function
  #endif
#endif  //  LBAL_LIBCPP26_COPYABLE_FUNCTION

#if !defined(LBAL_LIBCPP26_COUNTING_SCOPE)
  #if __cpp_lib_counting_scope >= 202506L
    #define LBAL_LIBCPP26_COUNTING_SCOPE __cpp_lib_counting_scope
  #endif
#endif  //  LBAL_LIBCPP26_COUNTING_SCOPE

#if !defined(LBAL_LIBCPP26_DEBUGGING)
  #if __cpp_lib_debugging >= 202311L
    #define LBAL_LIBCPP26_DEBUGGING __cpp_lib_debugging
  #endif
#endif  //  LBAL_LIBCPP26_DEBUGGING

#if !defined(LBAL_LIBCPP26_DEBUGGING_UTILITIES)
  #if __cpp_lib_debugging >= 202403L
    #define LBAL_LIBCPP26_DEBUGGING_UTILITIES __cpp_lib_debugging
  #endif
#endif  //  LBAL_LIBCPP26_DEBUGGING_UTILITIES

#if !defined(LBAL_LIBCPP26_DEFAULT_TEMPLATE_TYPE_FOR_ALGORITHM_VALUES)
  #if __cpp_lib_default_template_type_for_algorithm_values >= 202403L
    #define LBAL_LIBCPP26_DEFAULT_TEMPLATE_TYPE_FOR_ALGORITHM_VALUES           \
      __cpp_lib_default_template_type_for_algorithm_values
  #endif
#endif  //  LBAL_LIBCPP26_DEFAULT_TEMPLATE_TYPE_FOR_ALGORITHM_VALUES

#if !defined(LBAL_LIBCPP26_DEFINE_STATIC)
  #if __cpp_lib_define_static >= 202506L
    #define LBAL_LIBCPP26_DEFINE_STATIC __cpp_lib_define_static
  #endif
#endif  //  LBAL_LIBCPP26_DEFINE_STATIC

#if !defined(LBAL_LIBCPP26_EXCEPTION_PTR_CAST)
  #if __cpp_lib_exception_ptr_cast >= 202506L
    #define LBAL_LIBCPP26_EXCEPTION_PTR_CAST __cpp_lib_exception_ptr_cast
  #endif
#endif  //  LBAL_LIBCPP26_EXCEPTION_PTR_CAST

#if !defined(LBAL_LIBCPP26_EXCEPTION_PTR_CAST_CONSTEXPR)
  #if __cpp_lib_exception_ptr_cast >= 202506L
    #define LBAL_LIBCPP26_EXCEPTION_PTR_CAST_CONSTEXPR                         \
      __cpp_lib_exception_ptr_cast
  #endif
#endif  //  LBAL_LIBCPP26_EXCEPTION_PTR_CAST_CONSTEXPR

#if !defined(LBAL_LIBCPP26_FLAT_MAP_FIXES)
  #if __cpp_lib_flat_map >= 202511L
    #define LBAL_LIBCPP26_FLAT_MAP_FIXES __cpp_lib_flat_map
  #endif
#endif  //  LBAL_LIBCPP26_FLAT_MAP_FIXES

#if !defined(LBAL_LIBCPP26_FLAT_SET_FIXES)
  #if __cpp_lib_flat_set >= 202511L
    #define LBAL_LIBCPP26_FLAT_SET_FIXES __cpp_lib_flat_set
  #endif
#endif  //  LBAL_LIBCPP26_FLAT_SET_FIXES

#if !defined(LBAL_LIBCPP26_FORMAT_MEMBER_VISIT)
  #if __cpp_lib_format >= 202306L
    #define LBAL_LIBCPP26_FORMAT_MEMBER_VISIT __cpp_lib_format
  #endif
#endif  //  LBAL_LIBCPP26_FORMAT_MEMBER_VISIT

#if !defined(LBAL_LIBCPP26_FORMAT_PATH)
  #if __cpp_lib_format_path >= 202403L
    #define LBAL_LIBCPP26_FORMAT_PATH __cpp_lib_format_path
  #endif
#endif  //  LBAL_LIBCPP26_FORMAT_PATH

#if !defined(LBAL_LIBCPP26_FORMAT_PATH_FIXES)
  #if __cpp_lib_format_path >= 202506L
    #define LBAL_LIBCPP26_FORMAT_PATH_FIXES __cpp_lib_format_path
  #endif
#endif  //  LBAL_LIBCPP26_FORMAT_PATH_FIXES

#if !defined(LBAL_LIBCPP26_FORMAT_POINTERS)
  #if __cpp_lib_format >= 202304L
    #define LBAL_LIBCPP26_FORMAT_POINTERS __cpp_lib_format
  #endif
#endif  //  LBAL_LIBCPP26_FORMAT_POINTERS

#if !defined(LBAL_LIBCPP26_FORMAT_RUNTIME)
  #if __cpp_lib_format >= 202311L
    #define LBAL_LIBCPP26_FORMAT_RUNTIME __cpp_lib_format
  #endif
#endif  //  LBAL_LIBCPP26_FORMAT_RUNTIME

#if !defined(LBAL_LIBCPP26_FORMAT_TYPE_CHECK)
  #if __cpp_lib_format >= 202305L
    #define LBAL_LIBCPP26_FORMAT_TYPE_CHECK __cpp_lib_format
  #endif
#endif  //  LBAL_LIBCPP26_FORMAT_TYPE_CHECK

#if !defined(LBAL_LIBCPP26_FORMAT_UCHAR)
  #if __cpp_lib_format_uchar >= 202311L
    #define LBAL_LIBCPP26_FORMAT_UCHAR __cpp_lib_format_uchar
  #endif
#endif  //  LBAL_LIBCPP26_FORMAT_UCHAR

#if !defined(LBAL_LIBCPP26_FREESTANDING_ALGORITHM)
  #if __cpp_lib_freestanding_algorithm >= 202311L
    #define LBAL_LIBCPP26_FREESTANDING_ALGORITHM                               \
      __cpp_lib_freestanding_algorithm
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_ALGORITHM

#if !defined(LBAL_LIBCPP26_FREESTANDING_ALGORITHM_MORE)
  #if __cpp_lib_freestanding_algorithm >= 202502L
    #define LBAL_LIBCPP26_FREESTANDING_ALGORITHM_MORE                          \
      __cpp_lib_freestanding_algorithm
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_ALGORITHM_MORE

#if !defined(LBAL_LIBCPP26_FREESTANDING_ARRAY)
  #if __cpp_lib_freestanding_array >= 202311L
    #define LBAL_LIBCPP26_FREESTANDING_ARRAY __cpp_lib_freestanding_array
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_ARRAY

#if !defined(LBAL_LIBCPP26_FREESTANDING_CHARCONV)
  #if __cpp_lib_freestanding_charconv >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_CHARCONV __cpp_lib_freestanding_charconv
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_CHARCONV

#if !defined(LBAL_LIBCPP26_FREESTANDING_CHAR_TRAITS)
  #if __cpp_lib_freestanding_char_traits >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_CHAR_TRAITS                             \
      __cpp_lib_freestanding_char_traits
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_CHAR_TRAITS

#if !defined(LBAL_LIBCPP26_FREESTANDING_CSTDLIB)
  #if __cpp_lib_freestanding_cstdlib >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_CSTDLIB __cpp_lib_freestanding_cstdlib
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_CSTDLIB

#if !defined(LBAL_LIBCPP26_FREESTANDING_CSTRING)
  #if __cpp_lib_freestanding_cstring >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_CSTRING __cpp_lib_freestanding_cstring
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_CSTRING

#if !defined(LBAL_LIBCPP26_FREESTANDING_CSTRING_REMOVE_STRTOK)
  #if __cpp_lib_freestanding_cstring >= 202311L
    #define LBAL_LIBCPP26_FREESTANDING_CSTRING_REMOVE_STRTOK                   \
      __cpp_lib_freestanding_cstring
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_CSTRING_REMOVE_STRTOK

#if !defined(LBAL_LIBCPP26_FREESTANDING_CWCHAR)
  #if __cpp_lib_freestanding_cwchar >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_CWCHAR __cpp_lib_freestanding_cwchar
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_CWCHAR

#if !defined(LBAL_LIBCPP26_FREESTANDING_ERRC)
  #if __cpp_lib_freestanding_errc >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_ERRC __cpp_lib_freestanding_errc
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_ERRC

#if !defined(LBAL_LIBCPP26_FREESTANDING_EXECUTION)
  #if __cpp_lib_freestanding_execution >= 202502L
    #define LBAL_LIBCPP26_FREESTANDING_EXECUTION                               \
      __cpp_lib_freestanding_execution
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_EXECUTION

#if !defined(LBAL_LIBCPP26_FREESTANDING_EXPECTED)
  #if __cpp_lib_freestanding_expected >= 202311L
    #define LBAL_LIBCPP26_FREESTANDING_EXPECTED __cpp_lib_freestanding_expected
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_EXPECTED

#if !defined(LBAL_LIBCPP26_FREESTANDING_FEATURE_TEST_MACROS)
  #if __cpp_lib_freestanding_feature_test_macros >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_FEATURE_TEST_MACROS                     \
      __cpp_lib_freestanding_feature_test_macros
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_FEATURE_TEST_MACROS

#if !defined(LBAL_LIBCPP26_FREESTANDING_FUNCTIONAL)
  #if __cpp_lib_freestanding_functional >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_FUNCTIONAL                              \
      __cpp_lib_freestanding_functional
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_FUNCTIONAL

#if !defined(LBAL_LIBCPP26_FREESTANDING_ITERATOR)
  #if __cpp_lib_freestanding_iterator >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_ITERATOR __cpp_lib_freestanding_iterator
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_ITERATOR

#if !defined(LBAL_LIBCPP26_FREESTANDING_MDSPAN)
  #if __cpp_lib_freestanding_mdspan >= 202311L
    #define LBAL_LIBCPP26_FREESTANDING_MDSPAN __cpp_lib_freestanding_mdspan
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_MDSPAN

#if !defined(LBAL_LIBCPP26_FREESTANDING_MEMORY)
  #if __cpp_lib_freestanding_memory >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_MEMORY __cpp_lib_freestanding_memory
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_MEMORY

#if !defined(LBAL_LIBCPP26_FREESTANDING_MEMORY_MORE)
  #if __cpp_lib_freestanding_memory >= 202502L
    #define LBAL_LIBCPP26_FREESTANDING_MEMORY_MORE __cpp_lib_freestanding_memory
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_MEMORY_MORE

#if !defined(LBAL_LIBCPP26_FREESTANDING_NUMERIC)
  #if __cpp_lib_freestanding_numeric >= 202502L
    #define LBAL_LIBCPP26_FREESTANDING_NUMERIC __cpp_lib_freestanding_numeric
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_NUMERIC

#if !defined(LBAL_LIBCPP26_FREESTANDING_OPERATOR_NEW)
  #if __cpp_lib_freestanding_operator_new >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_OPERATOR_NEW                            \
      __cpp_lib_freestanding_operator_new
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_OPERATOR_NEW

#if !defined(LBAL_LIBCPP26_FREESTANDING_OPTIONAL)
  #if __cpp_lib_freestanding_optional >= 202311L
    #define LBAL_LIBCPP26_FREESTANDING_OPTIONAL __cpp_lib_freestanding_optional
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_OPTIONAL

#if !defined(LBAL_LIBCPP26_FREESTANDING_RANDOM)
  #if __cpp_lib_freestanding_random >= 202502L
    #define LBAL_LIBCPP26_FREESTANDING_RANDOM __cpp_lib_freestanding_random
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_RANDOM

#if !defined(LBAL_LIBCPP26_FREESTANDING_RANGES)
  #if __cpp_lib_freestanding_ranges >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_RANGES __cpp_lib_freestanding_ranges
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_RANGES

#if !defined(LBAL_LIBCPP26_FREESTANDING_RATIO)
  #if __cpp_lib_freestanding_ratio >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_RATIO __cpp_lib_freestanding_ratio
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_RATIO

#if !defined(LBAL_LIBCPP26_FREESTANDING_STRING_VIEW)
  #if __cpp_lib_freestanding_string_view >= 202311L
    #define LBAL_LIBCPP26_FREESTANDING_STRING_VIEW                             \
      __cpp_lib_freestanding_string_view
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_STRING_VIEW

#if !defined(LBAL_LIBCPP26_FREESTANDING_TUPLE)
  #if __cpp_lib_freestanding_tuple >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_TUPLE __cpp_lib_freestanding_tuple
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_TUPLE

#if !defined(LBAL_LIBCPP26_FREESTANDING_UTILITY)
  #if __cpp_lib_freestanding_utility >= 202306L
    #define LBAL_LIBCPP26_FREESTANDING_UTILITY __cpp_lib_freestanding_utility
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_UTILITY

#if !defined(LBAL_LIBCPP26_FREESTANDING_VARIANT)
  #if __cpp_lib_freestanding_variant >= 202311L
    #define LBAL_LIBCPP26_FREESTANDING_VARIANT __cpp_lib_freestanding_variant
  #endif
#endif  //  LBAL_LIBCPP26_FREESTANDING_VARIANT

#if !defined(LBAL_LIBCPP26_FSTREAM_NATIVE_HANDLE)
  #if __cpp_lib_fstream_native_handle >= 202306L
    #define LBAL_LIBCPP26_FSTREAM_NATIVE_HANDLE __cpp_lib_fstream_native_handle
  #endif
#endif  //  LBAL_LIBCPP26_FSTREAM_NATIVE_HANDLE

#if !defined(LBAL_LIBCPP26_FUNCTION_REF)
  #if __cpp_lib_function_ref >= 202306L
    #define LBAL_LIBCPP26_FUNCTION_REF __cpp_lib_function_ref
  #endif
#endif  //  LBAL_LIBCPP26_FUNCTION_REF

#if !defined(LBAL_LIBCPP26_FUNCTION_REF_RENAME_NONTYPE)
  #if __cpp_lib_function_ref >= 202511L
    #define LBAL_LIBCPP26_FUNCTION_REF_RENAME_NONTYPE __cpp_lib_function_ref
  #endif
#endif  //  LBAL_LIBCPP26_FUNCTION_REF_RENAME_NONTYPE

#if !defined(LBAL_LIBCPP26_GENERATE_RANDOM)
  #if __cpp_lib_generate_random >= 202403L
    #define LBAL_LIBCPP26_GENERATE_RANDOM __cpp_lib_generate_random
  #endif
#endif  //  LBAL_LIBCPP26_GENERATE_RANDOM

#if !defined(LBAL_LIBCPP26_HARDENED_ARRAY)
  #if __cpp_lib_hardened_array >= 202502L
    #define LBAL_LIBCPP26_HARDENED_ARRAY __cpp_lib_hardened_array
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_ARRAY

#if !defined(LBAL_LIBCPP26_HARDENED_BASIC_STACKTRACE)
  #if __cpp_lib_hardened_basic_stacktrace >= 202506L
    #define LBAL_LIBCPP26_HARDENED_BASIC_STACKTRACE                            \
      __cpp_lib_hardened_basic_stacktrace
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_BASIC_STACKTRACE

#if !defined(LBAL_LIBCPP26_HARDENED_BASIC_STRING)
  #if __cpp_lib_hardened_basic_string >= 202502L
    #define LBAL_LIBCPP26_HARDENED_BASIC_STRING __cpp_lib_hardened_basic_string
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_BASIC_STRING

#if !defined(LBAL_LIBCPP26_HARDENED_BASIC_STRING_VIEW)
  #if __cpp_lib_hardened_basic_string_view >= 202502L
    #define LBAL_LIBCPP26_HARDENED_BASIC_STRING_VIEW                           \
      __cpp_lib_hardened_basic_string_view
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_BASIC_STRING_VIEW

#if !defined(LBAL_LIBCPP26_HARDENED_BITSET)
  #if __cpp_lib_hardened_bitset >= 202502L
    #define LBAL_LIBCPP26_HARDENED_BITSET __cpp_lib_hardened_bitset
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_BITSET

#if !defined(LBAL_LIBCPP26_HARDENED_COMMON_ITERATOR)
  #if __cpp_lib_hardened_common_iterator >= 202506L
    #define LBAL_LIBCPP26_HARDENED_COMMON_ITERATOR                             \
      __cpp_lib_hardened_common_iterator
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_COMMON_ITERATOR

#if !defined(LBAL_LIBCPP26_HARDENED_COUNTED_ITERATOR)
  #if __cpp_lib_hardened_counted_iterator >= 202506L
    #define LBAL_LIBCPP26_HARDENED_COUNTED_ITERATOR                            \
      __cpp_lib_hardened_counted_iterator
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_COUNTED_ITERATOR

#if !defined(LBAL_LIBCPP26_HARDENED_DEQUE)
  #if __cpp_lib_hardened_deque >= 202502L
    #define LBAL_LIBCPP26_HARDENED_DEQUE __cpp_lib_hardened_deque
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_DEQUE

#if !defined(LBAL_LIBCPP26_HARDENED_EXPECTED)
  #if __cpp_lib_hardened_expected >= 202502L
    #define LBAL_LIBCPP26_HARDENED_EXPECTED __cpp_lib_hardened_expected
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_EXPECTED

#if !defined(LBAL_LIBCPP26_HARDENED_FORWARD_LIST)
  #if __cpp_lib_hardened_forward_list >= 202502L
    #define LBAL_LIBCPP26_HARDENED_FORWARD_LIST __cpp_lib_hardened_forward_list
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_FORWARD_LIST

#if !defined(LBAL_LIBCPP26_HARDENED_INPLACE_VECTOR)
  #if __cpp_lib_hardened_inplace_vector >= 202502L
    #define LBAL_LIBCPP26_HARDENED_INPLACE_VECTOR                              \
      __cpp_lib_hardened_inplace_vector
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_INPLACE_VECTOR

#if !defined(LBAL_LIBCPP26_HARDENED_LIST)
  #if __cpp_lib_hardened_list >= 202502L
    #define LBAL_LIBCPP26_HARDENED_LIST __cpp_lib_hardened_list
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_LIST

#if !defined(LBAL_LIBCPP26_HARDENED_MDSPAN)
  #if __cpp_lib_hardened_mdspan >= 202502L
    #define LBAL_LIBCPP26_HARDENED_MDSPAN __cpp_lib_hardened_mdspan
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_MDSPAN

#if !defined(LBAL_LIBCPP26_HARDENED_OPTIONAL)
  #if __cpp_lib_hardened_optional >= 202502L
    #define LBAL_LIBCPP26_HARDENED_OPTIONAL __cpp_lib_hardened_optional
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_OPTIONAL

#if !defined(LBAL_LIBCPP26_HARDENED_SHARED_PTR_ARRAY)
  #if __cpp_lib_hardened_shared_ptr_array >= 202506L
    #define LBAL_LIBCPP26_HARDENED_SHARED_PTR_ARRAY                            \
      __cpp_lib_hardened_shared_ptr_array
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_SHARED_PTR_ARRAY

#if !defined(LBAL_LIBCPP26_HARDENED_SPAN)
  #if __cpp_lib_hardened_span >= 202502L
    #define LBAL_LIBCPP26_HARDENED_SPAN __cpp_lib_hardened_span
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_SPAN

#if !defined(LBAL_LIBCPP26_HARDENED_VALARRAY)
  #if __cpp_lib_hardened_valarray >= 202502L
    #define LBAL_LIBCPP26_HARDENED_VALARRAY __cpp_lib_hardened_valarray
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_VALARRAY

#if !defined(LBAL_LIBCPP26_HARDENED_VECTOR)
  #if __cpp_lib_hardened_vector >= 202502L
    #define LBAL_LIBCPP26_HARDENED_VECTOR __cpp_lib_hardened_vector
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_VECTOR

#if !defined(LBAL_LIBCPP26_HARDENED_VIEW_INTERFACE)
  #if __cpp_lib_hardened_view_interface >= 202506L
    #define LBAL_LIBCPP26_HARDENED_VIEW_INTERFACE                              \
      __cpp_lib_hardened_view_interface
  #endif
#endif  //  LBAL_LIBCPP26_HARDENED_VIEW_INTERFACE

#if !defined(LBAL_LIBCPP26_HAZARD_POINTER)
  #if __cpp_lib_hazard_pointer >= 202306L
    #define LBAL_LIBCPP26_HAZARD_POINTER __cpp_lib_hazard_pointer
  #endif
#endif  //  LBAL_LIBCPP26_HAZARD_POINTER

#if !defined(LBAL_LIBCPP26_HIVE)
  #if __cpp_lib_hive >= 202502L
    #define LBAL_LIBCPP26_HIVE __cpp_lib_hive
  #endif
#endif  //  LBAL_LIBCPP26_HIVE

#if !defined(LBAL_LIBCPP26_INDIRECT)
  #if __cpp_lib_indirect >= 202502L
    #define LBAL_LIBCPP26_INDIRECT __cpp_lib_indirect
  #endif
#endif  //  LBAL_LIBCPP26_INDIRECT

#if !defined(LBAL_LIBCPP26_INITIALIZER_LIST)
  #if __cpp_lib_initializer_list >= 202511L
    #define LBAL_LIBCPP26_INITIALIZER_LIST __cpp_lib_initializer_list
  #endif
#endif  //  LBAL_LIBCPP26_INITIALIZER_LIST

#if !defined(LBAL_LIBCPP26_INPLACE_VECTOR)
  #if __cpp_lib_inplace_vector >= 202406L
    #define LBAL_LIBCPP26_INPLACE_VECTOR __cpp_lib_inplace_vector
  #endif
#endif  //  LBAL_LIBCPP26_INPLACE_VECTOR

#if !defined(LBAL_LIBCPP26_INTEGER_SEQUENCE_EXPANSION_STATEMENTS)
  #if __cpp_lib_integer_sequence >= 202511L
    #define LBAL_LIBCPP26_INTEGER_SEQUENCE_EXPANSION_STATEMENTS                \
      __cpp_lib_integer_sequence
  #endif
#endif  //  LBAL_LIBCPP26_INTEGER_SEQUENCE_EXPANSION_STATEMENTS

#if !defined(LBAL_LIBCPP26_IS_VIRTUAL_BASE_OF)
  #if __cpp_lib_is_virtual_base_of >= 202406L
    #define LBAL_LIBCPP26_IS_VIRTUAL_BASE_OF __cpp_lib_is_virtual_base_of
  #endif
#endif  //  LBAL_LIBCPP26_IS_VIRTUAL_BASE_OF

#if !defined(LBAL_LIBCPP26_IS_WITHIN_LIFETIME)
  #if __cpp_lib_is_within_lifetime >= 202306L
    #define LBAL_LIBCPP26_IS_WITHIN_LIFETIME __cpp_lib_is_within_lifetime
  #endif
#endif  //  LBAL_LIBCPP26_IS_WITHIN_LIFETIME

#if !defined(LBAL_LIBCPP26_LINALG)
  #if __cpp_lib_linalg >= 202311L
    #define LBAL_LIBCPP26_LINALG __cpp_lib_linalg
  #endif
#endif  //  LBAL_LIBCPP26_LINALG

#if !defined(LBAL_LIBCPP26_LINALG_BLAS_RANK)
  #if __cpp_lib_linalg >= 202511L
    #define LBAL_LIBCPP26_LINALG_BLAS_RANK __cpp_lib_linalg
  #endif
#endif  //  LBAL_LIBCPP26_LINALG_BLAS_RANK

#if !defined(LBAL_LIBCPP26_LINALG_FIX_TRANSPOSED)
  #if __cpp_lib_linalg >= 202411L
    #define LBAL_LIBCPP26_LINALG_FIX_TRANSPOSED __cpp_lib_linalg
  #endif
#endif  //  LBAL_LIBCPP26_LINALG_FIX_TRANSPOSED

#if !defined(LBAL_LIBCPP26_LINALG_OPTIMIZE_CONJUGATED)
  #if __cpp_lib_linalg >= 202411L
    #define LBAL_LIBCPP26_LINALG_OPTIMIZE_CONJUGATED __cpp_lib_linalg
  #endif
#endif  //  LBAL_LIBCPP26_LINALG_OPTIMIZE_CONJUGATED

#if !defined(LBAL_LIBCPP26_MDSPAN_DEXTENTS)
  #if __cpp_lib_mdspan >= 202406L
    #define LBAL_LIBCPP26_MDSPAN_DEXTENTS __cpp_lib_mdspan
  #endif
#endif  //  LBAL_LIBCPP26_MDSPAN_DEXTENTS

#if !defined(LBAL_LIBCPP26_NOT_FN_NTTP_CALLABLES)
  #if __cpp_lib_not_fn >= 202306L
    #define LBAL_LIBCPP26_NOT_FN_NTTP_CALLABLES __cpp_lib_not_fn
  #endif
#endif  //  LBAL_LIBCPP26_NOT_FN_NTTP_CALLABLES

#if !defined(LBAL_LIBCPP26_OBSERVABLE_CHECKPOINT)
  #if __cpp_lib_observable_checkpoint >= 202506L
    #define LBAL_LIBCPP26_OBSERVABLE_CHECKPOINT __cpp_lib_observable_checkpoint
  #endif
#endif  //  LBAL_LIBCPP26_OBSERVABLE_CHECKPOINT

#if !defined(LBAL_LIBCPP26_OPTIONAL_RANGE_SUPPORT)
  #if __cpp_lib_optional_range_support >= 202406L
    #define LBAL_LIBCPP26_OPTIONAL_RANGE_SUPPORT                               \
      __cpp_lib_optional_range_support
  #endif
#endif  //  LBAL_LIBCPP26_OPTIONAL_RANGE_SUPPORT

#if !defined(LBAL_LIBCPP26_OPTIONAL_REFERENCE)
  #if __cpp_lib_optional >= 202506L
    #define LBAL_LIBCPP26_OPTIONAL_REFERENCE __cpp_lib_optional
  #endif
#endif  //  LBAL_LIBCPP26_OPTIONAL_REFERENCE

#if !defined(LBAL_LIBCPP26_OUT_PTR_MORE)
  #if __cpp_lib_out_ptr >= 202311L
    #define LBAL_LIBCPP26_OUT_PTR_MORE __cpp_lib_out_ptr
  #endif
#endif  //  LBAL_LIBCPP26_OUT_PTR_MORE

#if !defined(LBAL_LIBCPP26_PARALLEL_ALGORITHM_RANGE)
  #if __cpp_lib_parallel_algorithm >= 202506L
    #define LBAL_LIBCPP26_PARALLEL_ALGORITHM_RANGE __cpp_lib_parallel_algorithm
  #endif
#endif  //  LBAL_LIBCPP26_PARALLEL_ALGORITHM_RANGE

#if !defined(LBAL_LIBCPP26_PARALLEL_SCHEDULER)
  #if __cpp_lib_parallel_scheduler >= 202506L
    #define LBAL_LIBCPP26_PARALLEL_SCHEDULER __cpp_lib_parallel_scheduler
  #endif
#endif  //  LBAL_LIBCPP26_PARALLEL_SCHEDULER

#if !defined(LBAL_LIBCPP26_PHILOX_ENGINE)
  #if __cpp_lib_philox_engine >= 202406L
    #define LBAL_LIBCPP26_PHILOX_ENGINE __cpp_lib_philox_engine
  #endif
#endif  //  LBAL_LIBCPP26_PHILOX_ENGINE

#if !defined(LBAL_LIBCPP26_POLYMORPHIC)
  #if __cpp_lib_polymorphic >= 202502L
    #define LBAL_LIBCPP26_POLYMORPHIC __cpp_lib_polymorphic
  #endif
#endif  //  LBAL_LIBCPP26_POLYMORPHIC

#if !defined(LBAL_LIBCPP26_PRINT_EFFICIENT)
  #if __cpp_lib_print >= 202403L
    #define LBAL_LIBCPP26_PRINT_EFFICIENT __cpp_lib_print
  #endif
#endif  //  LBAL_LIBCPP26_PRINT_EFFICIENT

#if !defined(LBAL_LIBCPP26_PRINT_MORE_EFFICIENT)
  #if __cpp_lib_print >= 202406L
    #define LBAL_LIBCPP26_PRINT_MORE_EFFICIENT __cpp_lib_print
  #endif
#endif  //  LBAL_LIBCPP26_PRINT_MORE_EFFICIENT

#if !defined(LBAL_LIBCPP26_RANGES_AS_CONST_FIX_CONVERTIBILITY)
  #if __cpp_lib_ranges_as_const >= 202311L
    #define LBAL_LIBCPP26_RANGES_AS_CONST_FIX_CONVERTIBILITY                   \
      __cpp_lib_ranges_as_const
  #endif
#endif  //  LBAL_LIBCPP26_RANGES_AS_CONST_FIX_CONVERTIBILITY

#if !defined(LBAL_LIBCPP26_RANGES_CACHE_LATEST)
  #if __cpp_lib_ranges_cache_latest >= 202411L
    #define LBAL_LIBCPP26_RANGES_CACHE_LATEST __cpp_lib_ranges_cache_latest
  #endif
#endif  //  LBAL_LIBCPP26_RANGES_CACHE_LATEST

#if !defined(LBAL_LIBCPP26_RANGES_CONCAT)
  #if __cpp_lib_ranges_concat >= 202403L
    #define LBAL_LIBCPP26_RANGES_CONCAT __cpp_lib_ranges_concat
  #endif
#endif  //  LBAL_LIBCPP26_RANGES_CONCAT

#if !defined(LBAL_LIBCPP26_RANGES_INDICES)
  #if __cpp_lib_ranges_indices >= 202506L
    #define LBAL_LIBCPP26_RANGES_INDICES __cpp_lib_ranges_indices
  #endif
#endif  //  LBAL_LIBCPP26_RANGES_INDICES

#if !defined(LBAL_LIBCPP26_RANGES_REMOVE_COMMON_REF_REQ)
  #if __cpp_lib_ranges >= 202406L
    #define LBAL_LIBCPP26_RANGES_REMOVE_COMMON_REF_REQ __cpp_lib_ranges
  #endif
#endif  //  LBAL_LIBCPP26_RANGES_REMOVE_COMMON_REF_REQ

#if !defined(LBAL_LIBCPP26_RANGES_RESERVE_HINT)
  #if __cpp_lib_ranges_reserve_hint >= 202502L
    #define LBAL_LIBCPP26_RANGES_RESERVE_HINT __cpp_lib_ranges_reserve_hint
  #endif
#endif  //  LBAL_LIBCPP26_RANGES_RESERVE_HINT

#if !defined(LBAL_LIBCPP26_RANGES_TO_INPUT)
  #if __cpp_lib_ranges_to_input >= 202502L
    #define LBAL_LIBCPP26_RANGES_TO_INPUT __cpp_lib_ranges_to_input
  #endif
#endif  //  LBAL_LIBCPP26_RANGES_TO_INPUT

#if !defined(LBAL_LIBCPP26_RATIO)
  #if __cpp_lib_ratio >= 202306L
    #define LBAL_LIBCPP26_RATIO __cpp_lib_ratio
  #endif
#endif  //  LBAL_LIBCPP26_RATIO

#if !defined(LBAL_LIBCPP26_RAW_MEMORY_ALGORITHMS_CONSTEXPR)
  #if __cpp_lib_raw_memory_algorithms >= 202411L
    #define LBAL_LIBCPP26_RAW_MEMORY_ALGORITHMS_CONSTEXPR                      \
      __cpp_lib_raw_memory_algorithms
  #endif
#endif  //  LBAL_LIBCPP26_RAW_MEMORY_ALGORITHMS_CONSTEXPR

#if !defined(LBAL_LIBCPP26_RCU)
  #if __cpp_lib_rcu >= 202306L
    #define LBAL_LIBCPP26_RCU __cpp_lib_rcu
  #endif
#endif  //  LBAL_LIBCPP26_RCU

#if !defined(LBAL_LIBCPP26_REFERENCE_WRAPPER)
  #if __cpp_lib_reference_wrapper >= 202403L
    #define LBAL_LIBCPP26_REFERENCE_WRAPPER __cpp_lib_reference_wrapper
  #endif
#endif  //  LBAL_LIBCPP26_REFERENCE_WRAPPER

#if !defined(LBAL_LIBCPP26_REFLECTION)
  #if __cpp_lib_reflection >= 202506L
    #define LBAL_LIBCPP26_REFLECTION __cpp_lib_reflection
  #endif
#endif  //  LBAL_LIBCPP26_REFLECTION

#if !defined(LBAL_LIBCPP26_SATURATION_ARITHMETIC)
  #if __cpp_lib_saturation_arithmetic >= 202311L
    #define LBAL_LIBCPP26_SATURATION_ARITHMETIC __cpp_lib_saturation_arithmetic
  #endif
#endif  //  LBAL_LIBCPP26_SATURATION_ARITHMETIC

#if !defined(LBAL_LIBCPP26_SENDERS)
  #if __cpp_lib_senders >= 202406L
    #define LBAL_LIBCPP26_SENDERS __cpp_lib_senders
  #endif
#endif  //  LBAL_LIBCPP26_SENDERS

#if !defined(LBAL_LIBCPP26_SENDERS_OPTIONAL)
  #if __cpp_lib_senders >= 202506L
    #define LBAL_LIBCPP26_SENDERS_OPTIONAL __cpp_lib_senders
  #endif
#endif  //  LBAL_LIBCPP26_SENDERS_OPTIONAL

#if !defined(LBAL_LIBCPP26_SIMD)
  #if __cpp_lib_simd >= 202411L
    #define LBAL_LIBCPP26_SIMD __cpp_lib_simd
  #endif
#endif  //  LBAL_LIBCPP26_SIMD

#if !defined(LBAL_LIBCPP26_SIMD_BIT)
  #if __cpp_lib_simd >= 202502L
    #define LBAL_LIBCPP26_SIMD_BIT __cpp_lib_simd
  #endif
#endif  //  LBAL_LIBCPP26_SIMD_BIT

#if !defined(LBAL_LIBCPP26_SIMD_CHUNK)
  #if __cpp_lib_simd >= 202502L
    #define LBAL_LIBCPP26_SIMD_CHUNK __cpp_lib_simd
  #endif
#endif  //  LBAL_LIBCPP26_SIMD_CHUNK

#if !defined(LBAL_LIBCPP26_SIMD_COMPLEX)
  #if __cpp_lib_simd_complex >= 202502L
    #define LBAL_LIBCPP26_SIMD_COMPLEX __cpp_lib_simd_complex
  #endif
#endif  //  LBAL_LIBCPP26_SIMD_COMPLEX

#if !defined(LBAL_LIBCPP26_SIMD_DEDUCTION_GUIDES)
  #if __cpp_lib_simd >= 202511L
    #define LBAL_LIBCPP26_SIMD_DEDUCTION_GUIDES __cpp_lib_simd
  #endif
#endif  //  LBAL_LIBCPP26_SIMD_DEDUCTION_GUIDES

#if !defined(LBAL_LIBCPP26_SIMD_EXTEND)
  #if __cpp_lib_simd >= 202506L
    #define LBAL_LIBCPP26_SIMD_EXTEND __cpp_lib_simd
  #endif
#endif  //  LBAL_LIBCPP26_SIMD_EXTEND

#if !defined(LBAL_LIBCPP26_SIMD_NAMESPACES)
  #if __cpp_lib_simd >= 202502L
    #define LBAL_LIBCPP26_SIMD_NAMESPACES __cpp_lib_simd
  #endif
#endif  //  LBAL_LIBCPP26_SIMD_NAMESPACES

#if !defined(LBAL_LIBCPP26_SIMD_PERMUTATIONS)
  #if __cpp_lib_simd_permutations >= 202506L
    #define LBAL_LIBCPP26_SIMD_PERMUTATIONS __cpp_lib_simd_permutations
  #endif
#endif  //  LBAL_LIBCPP26_SIMD_PERMUTATIONS

#if !defined(LBAL_LIBCPP26_SIMD_RANGE)
  #if __cpp_lib_simd >= 202506L
    #define LBAL_LIBCPP26_SIMD_RANGE __cpp_lib_simd
  #endif
#endif  //  LBAL_LIBCPP26_SIMD_RANGE

#if !defined(LBAL_LIBCPP26_SMART_POINTER_OWNER_EQUALITY)
  #if __cpp_lib_smart_pointer_owner_equality >= 202306L
    #define LBAL_LIBCPP26_SMART_POINTER_OWNER_EQUALITY                         \
      __cpp_lib_smart_pointer_owner_equality
  #endif
#endif  //  LBAL_LIBCPP26_SMART_POINTER_OWNER_EQUALITY

#if !defined(LBAL_LIBCPP26_SMART_PTR_OWNER_EQUALITY)
  #if __cpp_lib_smart_ptr_owner_equality >= 202306L
    #define LBAL_LIBCPP26_SMART_PTR_OWNER_EQUALITY                             \
      __cpp_lib_smart_ptr_owner_equality
  #endif
#endif  //  LBAL_LIBCPP26_SMART_PTR_OWNER_EQUALITY

#if !defined(LBAL_LIBCPP26_SPAN_AT)
  #if __cpp_lib_span >= 202311L
    #define LBAL_LIBCPP26_SPAN_AT __cpp_lib_span
  #endif
#endif  //  LBAL_LIBCPP26_SPAN_AT

#if !defined(LBAL_LIBCPP26_SPAN_INITIALIZER_LIST)
  #if __cpp_lib_span_initializer_list >= 202311L
    #define LBAL_LIBCPP26_SPAN_INITIALIZER_LIST __cpp_lib_span_initializer_list
  #endif
#endif  //  LBAL_LIBCPP26_SPAN_INITIALIZER_LIST

#if !defined(LBAL_LIBCPP26_SPAN_MORE)
  #if __cpp_lib_span >= 202311L
    #define LBAL_LIBCPP26_SPAN_MORE __cpp_lib_span
  #endif
#endif  //  LBAL_LIBCPP26_SPAN_MORE

#if !defined(LBAL_LIBCPP26_SSTREAM_FROM_STRING_VIEW)
  #if __cpp_lib_sstream_from_string_view >= 202306L
    #define LBAL_LIBCPP26_SSTREAM_FROM_STRING_VIEW                             \
      __cpp_lib_sstream_from_string_view
  #endif
#endif  //  LBAL_LIBCPP26_SSTREAM_FROM_STRING_VIEW

#if !defined(LBAL_LIBCPP26_STRING_SUBVIEW)
  #if __cpp_lib_string_subview >= 202506L
    #define LBAL_LIBCPP26_STRING_SUBVIEW __cpp_lib_string_subview
  #endif
#endif  //  LBAL_LIBCPP26_STRING_SUBVIEW

#if !defined(LBAL_LIBCPP26_STRING_VIEW_CONCAT)
  #if __cpp_lib_string_view >= 202403L
    #define LBAL_LIBCPP26_STRING_VIEW_CONCAT __cpp_lib_string_view
  #endif
#endif  //  LBAL_LIBCPP26_STRING_VIEW_CONCAT

#if !defined(LBAL_LIBCPP26_SUBMDSPAN)
  #if __cpp_lib_submdspan >= 202306L
    #define LBAL_LIBCPP26_SUBMDSPAN __cpp_lib_submdspan
  #endif
#endif  //  LBAL_LIBCPP26_SUBMDSPAN

#if !defined(LBAL_LIBCPP26_SUBMDSPAN_FIX)
  #if __cpp_lib_submdspan >= 202411L
    #define LBAL_LIBCPP26_SUBMDSPAN_FIX __cpp_lib_submdspan
  #endif
#endif  //  LBAL_LIBCPP26_SUBMDSPAN_FIX

#if !defined(LBAL_LIBCPP26_SUBMDSPAN_FUTURE_PROOF)
  #if __cpp_lib_submdspan >= 202511L
    #define LBAL_LIBCPP26_SUBMDSPAN_FUTURE_PROOF __cpp_lib_submdspan
  #endif
#endif  //  LBAL_LIBCPP26_SUBMDSPAN_FUTURE_PROOF

#if !defined(LBAL_LIBCPP26_SUBMDSPAN_PADDED)
  #if __cpp_lib_submdspan >= 202403L
    #define LBAL_LIBCPP26_SUBMDSPAN_PADDED __cpp_lib_submdspan
  #endif
#endif  //  LBAL_LIBCPP26_SUBMDSPAN_PADDED

#if !defined(LBAL_LIBCPP26_TASK)
  #if __cpp_lib_task >= 202506L
    #define LBAL_LIBCPP26_TASK __cpp_lib_task
  #endif
#endif  //  LBAL_LIBCPP26_TASK

#if !defined(LBAL_LIBCPP26_TEXT_ENCODING)
  #if __cpp_lib_text_encoding >= 202306L
    #define LBAL_LIBCPP26_TEXT_ENCODING __cpp_lib_text_encoding
  #endif
#endif  //  LBAL_LIBCPP26_TEXT_ENCODING

#if !defined(LBAL_LIBCPP26_TO_CHARS_BOOL_TEST)
  #if __cpp_lib_to_chars >= 202306L
    #define LBAL_LIBCPP26_TO_CHARS_BOOL_TEST __cpp_lib_to_chars
  #endif
#endif  //  LBAL_LIBCPP26_TO_CHARS_BOOL_TEST

#if !defined(LBAL_LIBCPP26_TO_STRING)
  #if __cpp_lib_to_string >= 202306L
    #define LBAL_LIBCPP26_TO_STRING __cpp_lib_to_string
  #endif
#endif  //  LBAL_LIBCPP26_TO_STRING

#if !defined(LBAL_LIBCPP26_TUPLE_LIKE_COMPLEX)
  #if __cpp_lib_tuple_like >= 202311L
    #define LBAL_LIBCPP26_TUPLE_LIKE_COMPLEX __cpp_lib_tuple_like
  #endif
#endif  //  LBAL_LIBCPP26_TUPLE_LIKE_COMPLEX

#if !defined(LBAL_LIBCPP26_TYPE_ORDER)
  #if __cpp_lib_type_order >= 202506L
    #define LBAL_LIBCPP26_TYPE_ORDER __cpp_lib_type_order
  #endif
#endif  //  LBAL_LIBCPP26_TYPE_ORDER

#if !defined(LBAL_LIBCPP26_VALARRAY)
  #if __cpp_lib_valarray >= 202511L
    #define LBAL_LIBCPP26_VALARRAY __cpp_lib_valarray
  #endif
#endif  //  LBAL_LIBCPP26_VALARRAY

#if !defined(LBAL_LIBCPP26_VARIANT_VISITOR)
  #if __cpp_lib_variant >= 202306L
    #define LBAL_LIBCPP26_VARIANT_VISITOR __cpp_lib_variant
  #endif
#endif  //  LBAL_LIBCPP26_VARIANT_VISITOR

//	Technical Specifications

//  None currently supported.

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
#if !defined(LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS)
  #if LBAL_LIBCPP17_EXECUTION && LBAL_LIBCPP17_PARALLEL_ALGORITHM
    #define LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS 1L
  #endif
#endif  //	LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS

/*------------------------------------------------------------------------------
  Header Checks

  Make sure that the headers needed to support supposedly available features
  are actually present, if possible.

  SEEME - bitweeder
  There are quite a few of these checks, but it’s unclear how expensive they
  actually are. We could be less pedantic - or offer a switch - to cut down on
  compile-time checking. Modules would moot these concerns.
*/

#if !defined(__has_include)
  #if LBAL_CONFIG_enable_pedantic_warnings
LBAL_CPP_WARNING(
    "'__has_include' is undefined; we cannot verify library headers"
)
  #endif  //	LBAL_CONFIG_enable_pedantic_warnings
#endif    //	__has_include

/*
  Core STL Headers

  These have been standard since C++98. Realistically, if there’s any C++
  library at all, these will be there, so if we don’t have `__has_include` at
  all, we default to assuming they’re there.
*/
#if !defined(__has_include) || __has_include(<algorithm>)
  #define LBAL_HAS_HEADER_ALGORITHM 1
#else
  #define LBAL_HAS_HEADER_ALGORITHM 0
#endif

#if !defined(__has_include) || __has_include(<bitset>)
  #define LBAL_HAS_HEADER_BITSET 1
#else
  #define LBAL_HAS_HEADER_BITSET 0
#endif

#if !defined(__has_include) || __has_include(<cassert>)
  #define LBAL_HAS_HEADER_CASSERT 1
#else
  #define LBAL_HAS_HEADER_CASSERT 0
#endif

#if !defined(__has_include) || __has_include(<cctype>)
  #define LBAL_HAS_HEADER_CCTYPE 1
#else
  #define LBAL_HAS_HEADER_CCTYPE 0
#endif

#if !defined(__has_include) || __has_include(<cfloat>)
  #define LBAL_HAS_HEADER_CFLOAT 1
#else
  #define LBAL_HAS_HEADER_CFLOAT 0
#endif

#if !defined(__has_include) || __has_include(<climits>)
  #define LBAL_HAS_HEADER_CLIMITS 1
#else
  #define LBAL_HAS_HEADER_CLIMITS 0
#endif

#if !defined(__has_include) || __has_include(<clocale>)
  #define LBAL_HAS_HEADER_CLOCALE 1
#else
  #define LBAL_HAS_HEADER_CLOCALE 0
#endif

#if !defined(__has_include) || __has_include(<cmath>)
  #define LBAL_HAS_HEADER_CMATH 1
#else
  #define LBAL_HAS_HEADER_CMATH 0
#endif

#if !defined(__has_include) || __has_include(<complex>)
  #define LBAL_HAS_HEADER_COMPLEX 1
#else
  #define LBAL_HAS_HEADER_COMPLEX 0
#endif

#if !defined(__has_include) || __has_include(<csetjmp>)
  #define LBAL_HAS_HEADER_CSETJMP 1
#else
  #define LBAL_HAS_HEADER_CSETJMP 0
#endif

#if !defined(__has_include) || __has_include(<csignal>)
  #define LBAL_HAS_HEADER_CSIGNAL 1
#else
  #define LBAL_HAS_HEADER_CSIGNAL 0
#endif

#if !defined(__has_include) || __has_include(<cstdarg>)
  #define LBAL_HAS_HEADER_CSTDARG 1
#else
  #define LBAL_HAS_HEADER_CSTDARG 0
#endif

#if !defined(__has_include) || __has_include(<cstddef>)
  #define LBAL_HAS_HEADER_CSTDDEF 1
#else
  #define LBAL_HAS_HEADER_CSTDDEF 0
#endif

#if !defined(__has_include) || __has_include(<cstdio>)
  #define LBAL_HAS_HEADER_CSTDIO 1
#else
  #define LBAL_HAS_HEADER_CSTDIO 0
#endif

#if !defined(__has_include) || __has_include(<cstdlib>)
  #define LBAL_HAS_HEADER_CSTDLIB 1
#else
  #define LBAL_HAS_HEADER_CSTDLIB 0
#endif

#if !defined(__has_include) || __has_include(<cstring>)
  #define LBAL_HAS_HEADER_CSTRING 1
#else
  #define LBAL_HAS_HEADER_CSTRING 0
#endif

#if !defined(__has_include) || __has_include(<ctime>)
  #define LBAL_HAS_HEADER_CTIME 1
#else
  #define LBAL_HAS_HEADER_CTIME 0
#endif

#if !defined(__has_include) || __has_include(<deque>)
  #define LBAL_HAS_HEADER_DEQUE 1
#else
  #define LBAL_HAS_HEADER_DEQUE 0
#endif

#if !defined(__has_include) || __has_include(<exception>)
  #define LBAL_HAS_HEADER_EXCEPTION 1
#else
  #define LBAL_HAS_HEADER_EXCEPTION 0
#endif

#if !defined(__has_include) || __has_include(<fstream>)
  #define LBAL_HAS_HEADER_FSTREAM 1
#else
  #define LBAL_HAS_HEADER_FSTREAM 0
#endif

#if !defined(__has_include) || __has_include(<functional>)
  #define LBAL_HAS_HEADER_FUNCTIONAL 1
#else
  #define LBAL_HAS_HEADER_FUNCTIONAL 0
#endif

#if !defined(__has_include) || __has_include(<iomanip>)
  #define LBAL_HAS_HEADER_IOMANIP 1
#else
  #define LBAL_HAS_HEADER_IOMANIP 0
#endif

#if !defined(__has_include) || __has_include(<ios>)
  #define LBAL_HAS_HEADER_IOS 1
#else
  #define LBAL_HAS_HEADER_IOS 0
#endif

#if !defined(__has_include) || __has_include(<iosfwd>)
  #define LBAL_HAS_HEADER_IOSFWD 1
#else
  #define LBAL_HAS_HEADER_IOSFWD 0
#endif

#if !defined(__has_include) || __has_include(<iostream>)
  #define LBAL_HAS_HEADER_IOSTREAM 1
#else
  #define LBAL_HAS_HEADER_IOSTREAM 0
#endif

#if !defined(__has_include) || __has_include(<istream>)
  #define LBAL_HAS_HEADER_ISTREAM 1
#else
  #define LBAL_HAS_HEADER_ISTREAM 0
#endif

#if !defined(__has_include) || __has_include(<iterator>)
  #define LBAL_HAS_HEADER_ITERATOR 1
#else
  #define LBAL_HAS_HEADER_ITERATOR 0
#endif

#if !defined(__has_include) || __has_include(<limits>)
  #define LBAL_HAS_HEADER_LIMITS 1
#else
  #define LBAL_HAS_HEADER_LIMITS 0
#endif

#if !defined(__has_include) || __has_include(<list>)
  #define LBAL_HAS_HEADER_LIST 1
#else
  #define LBAL_HAS_HEADER_LIST 0
#endif

#if !defined(__has_include) || __has_include(<locale>)
  #define LBAL_HAS_HEADER_LOCALE 1
#else
  #define LBAL_HAS_HEADER_LOCALE 0
#endif

#if !defined(__has_include) || __has_include(<map>)
  #define LBAL_HAS_HEADER_MAP 1
#else
  #define LBAL_HAS_HEADER_MAP 0
#endif

#if !defined(__has_include) || __has_include(<memory>)
  #define LBAL_HAS_HEADER_MEMORY 1
#else
  #define LBAL_HAS_HEADER_MEMORY 0
#endif

#if !defined(__has_include) || __has_include(<new>)
  #define LBAL_HAS_HEADER_NEW 1
#else
  #define LBAL_HAS_HEADER_NEW 0
#endif

#if !defined(__has_include) || __has_include(<numeric>)
  #define LBAL_HAS_HEADER_NUMERIC 1
#else
  #define LBAL_HAS_HEADER_NUMERIC 0
#endif

#if !defined(__has_include) || __has_include(<ostream>)
  #define LBAL_HAS_HEADER_OSTREAM 1
#else
  #define LBAL_HAS_HEADER_OSTREAM 0
#endif

#if !defined(__has_include) || __has_include(<queue>)
  #define LBAL_HAS_HEADER_QUEUE 1
#else
  #define LBAL_HAS_HEADER_QUEUE 0
#endif

#if !defined(__has_include) || __has_include(<set>)
  #define LBAL_HAS_HEADER_SET 1
#else
  #define LBAL_HAS_HEADER_SET 0
#endif

#if !defined(__has_include) || __has_include(<sstream>)
  #define LBAL_HAS_HEADER_SSTREAM 1
#else
  #define LBAL_HAS_HEADER_SSTREAM 0
#endif

#if !defined(__has_include) || __has_include(<stack>)
  #define LBAL_HAS_HEADER_STACK 1
#else
  #define LBAL_HAS_HEADER_STACK 0
#endif

#if !defined(__has_include) || __has_include(<stdexcept>)
  #define LBAL_HAS_HEADER_STDEXCEPT 1
#else
  #define LBAL_HAS_HEADER_STDEXCEPT 0
#endif

#if !defined(__has_include) || __has_include(<streambuf>)
  #define LBAL_HAS_HEADER_STREAMBUF 1
#else
  #define LBAL_HAS_HEADER_STREAMBUF 0
#endif

#if !defined(__has_include) || __has_include(<string>)
  #define LBAL_HAS_HEADER_STRING 1
#else
  #define LBAL_HAS_HEADER_STRING 0
#endif

#if !defined(__has_include) || __has_include(<utility>)
  #define LBAL_HAS_HEADER_UTILITY 1
#else
  #define LBAL_HAS_HEADER_UTILITY 0
#endif

#if !defined(__has_include) || __has_include(<valarray>)
  #define LBAL_HAS_HEADER_VALARRAY 1
#else
  #define LBAL_HAS_HEADER_VALARRAY 0
#endif

#if !defined(__has_include) || __has_include(<vector>)
  #define LBAL_HAS_HEADER_VECTOR 1
#else
  #define LBAL_HAS_HEADER_VECTOR 0
#endif

/*
  C++11 Headers

  Generally, these will always be available, but they will not necessarily be
  used by the target Standard, so we “fail on” if `__has_include` is not
  available.
*/

#if !defined(__has_include) || __has_include(<array>)
  #define LBAL_HAS_HEADER_ARRAY 1
#else
  #define LBAL_HAS_HEADER_ARRAY 0
#endif

#if !defined(__has_include) || __has_include(<atomic>)
  #define LBAL_HAS_HEADER_ATOMIC 1
#else
  #define LBAL_HAS_HEADER_ATOMIC 0
#endif

#if !defined(__has_include) || __has_include(<cfenv>)
  #define LBAL_HAS_HEADER_CFENV 1
#else
  #define LBAL_HAS_HEADER_CFENV 0
#endif

#if !defined(__has_include) || __has_include(<chrono>)
  #define LBAL_HAS_HEADER_CHRONO 1
#else
  #define LBAL_HAS_HEADER_CHRONO 0
#endif

#if !defined(__has_include) || __has_include(<cinttypes>)
  #define LBAL_HAS_HEADER_CINTTYPES 1
#else
  #define LBAL_HAS_HEADER_CINTTYPES 0
#endif

#if !defined(__has_include) || __has_include(<condition_variable>)
  #define LBAL_HAS_HEADER_CONDITION_VARIABLE 1
#else
  #define LBAL_HAS_HEADER_CONDITION_VARIABLE 0
#endif

#if !defined(__has_include) || __has_include(<cstdint>)
  #define LBAL_HAS_HEADER_CSTDINT 1
#else
  #define LBAL_HAS_HEADER_CSTDINT 0
#endif

#if !defined(__has_include) || __has_include(<cuchar>)
  #define LBAL_HAS_HEADER_CUCHAR 1
#else
  #define LBAL_HAS_HEADER_CUCHAR 0
#endif

#if !defined(__has_include) || __has_include(<forward_list>)
  #define LBAL_HAS_HEADER_FORWARD_LIST 1
#else
  #define LBAL_HAS_HEADER_FORWARD_LIST 0
#endif

#if !defined(__has_include) || __has_include(<future>)
  #define LBAL_HAS_HEADER_FUTURE 1
#else
  #define LBAL_HAS_HEADER_FUTURE 0
#endif

#if !defined(__has_include) || __has_include(<initializer_list>)
  #define LBAL_HAS_HEADER_INITIALIZER_LIST 1
#else
  #define LBAL_HAS_HEADER_INITIALIZER_LIST 0
#endif

#if !defined(__has_include) || __has_include(<mutex>)
  #define LBAL_HAS_HEADER_MUTEX 1
#else
  #define LBAL_HAS_HEADER_MUTEX 0
#endif

#if !defined(__has_include) || __has_include(<random>)
  #define LBAL_HAS_HEADER_RANDOM 1
#else
  #define LBAL_HAS_HEADER_RANDOM 0
#endif

#if !defined(__has_include) || __has_include(<ratio>)
  #define LBAL_HAS_HEADER_RATIO 1
#else
  #define LBAL_HAS_HEADER_RATIO 0
#endif

#if !defined(__has_include) || __has_include(<regex>)
  #define LBAL_HAS_HEADER_REGEX 1
#else
  #define LBAL_HAS_HEADER_REGEX 0
#endif

#if !defined(__has_include) || __has_include(<scoped_allocator>)
  #define LBAL_HAS_HEADER_SCOPED_ALLOCATOR 1
#else
  #define LBAL_HAS_HEADER_SCOPED_ALLOCATOR 0
#endif

#if !defined(__has_include) || __has_include(<system_error>)
  #define LBAL_HAS_HEADER_SYSTEM_ERROR 1
#else
  #define LBAL_HAS_HEADER_SYSTEM_ERROR 0
#endif

#if !defined(__has_include) || __has_include(<thread>)
  #define LBAL_HAS_HEADER_THREAD 1
#else
  #define LBAL_HAS_HEADER_THREAD 0
#endif

#if !defined(__has_include) || __has_include(<tuple>)
  #define LBAL_HAS_HEADER_TUPLE 1
#else
  #define LBAL_HAS_HEADER_TUPLE 0
#endif

#if !defined(__has_include) || __has_include(<type_traits>)
  #define LBAL_HAS_HEADER_TYPE_TRAITS 1
#else
  #define LBAL_HAS_HEADER_TYPE_TRAITS 0
#endif

#if !defined(__has_include) || __has_include(<typeindex>)
  #define LBAL_HAS_HEADER_TYPEINDEX 1
#else
  #define LBAL_HAS_HEADER_TYPEINDEX 0
#endif

#if !defined(__has_include) || __has_include(<unordered_map>)
  #define LBAL_HAS_HEADER_UNORDERED_MAP 1
#else
  #define LBAL_HAS_HEADER_UNORDERED_MAP 0
#endif

#if !defined(__has_include) || __has_include(<unordered_set>)
  #define LBAL_HAS_HEADER_UNORDERED_SET 1
#else
  #define LBAL_HAS_HEADER_UNORDERED_SET 0
#endif

//  This was technically removed in C++20, but the file may still be there for
//  backwards compatibility.
#if !defined(__has_include) || __has_include(<cstdalign>)
  #define LBAL_HAS_HEADER_CSTDALIGN 1
#else
  #define LBAL_HAS_HEADER_CSTDALIGN 0
#endif

//  This was technically removed in C++20, but the file may still be there for
//  backwards compatibility.
#if !defined(__has_include) || __has_include(<cstdbool>)
  #define LBAL_HAS_HEADER_CSTDBOOL 1
#else
  #define LBAL_HAS_HEADER_CSTDBOOL 0
#endif

/*
  C++14 Headers

  Generally, these will always be available, but they will not necessarily be
  used by the target Standard, so we “fail on” if `__has_include` is not
  available.
*/

#if !defined(__has_include) || __has_include(<shared_mutex>)
  #define LBAL_HAS_HEADER_SHARED_MUTEX 1
#else
  #define LBAL_HAS_HEADER_SHARED_MUTEX 0
#endif

/*
  C++17 Headers

  Things start to get tricky here, as headers won’t necessarily be available
  with older library implementations, which will typically be bundled with
  compilers that do not have `__has_include`, so from here we start to “fail
  off” if we have no header detection method available.
*/

#if defined(__has_include) && __has_include(<any>)
  #define LBAL_HAS_HEADER_ANY 1
#else
  #define LBAL_HAS_HEADER_ANY 0
#endif

#if defined(__has_include) && __has_include(<charconv>)
  #define LBAL_HAS_HEADER_CHARCONV 1
#else
  #define LBAL_HAS_HEADER_CHARCONV 0
#endif

#if defined(__has_include) && __has_include(<execution>)
  #define LBAL_HAS_HEADER_EXECUTION 1
#else
  #define LBAL_HAS_HEADER_EXECUTION 0
#endif

#if defined(__has_include) && __has_include(<filesystem>)
  #define LBAL_HAS_HEADER_FILESYSTEM 1
#else
  #define LBAL_HAS_HEADER_FILESYSTEM 0
#endif

#if defined(__has_include) && __has_include(<experimental/filesystem>)
  #define LBAL_HAS_HEADER_EXPERIMENTAL_FILESYSTEM 1
#else
  #define LBAL_HAS_HEADER_EXPERIMENTAL_FILESYSTEM 0
#endif

#if defined(__has_include) && __has_include(<memory_resource>)
  #define LBAL_HAS_HEADER_MEMORY_RESOURCE 1
#else
  #define LBAL_HAS_HEADER_MEMORY_RESOURCE 0
#endif

#if defined(__has_include) && __has_include(<optional>)
  #define LBAL_HAS_HEADER_OPTIONAL 1
#else
  #define LBAL_HAS_HEADER_OPTIONAL 0
#endif

#if defined(__has_include) && __has_include(<string_view>)
  #define LBAL_HAS_HEADER_STRING_VIEW 1
#else
  #define LBAL_HAS_HEADER_STRING_VIEW 0
#endif

#if defined(__has_include) && __has_include(<variant>)
  #define LBAL_HAS_HEADER_VARIANT 1
#else
  #define LBAL_HAS_HEADER_VARIANT 0
#endif

/*
  C++20 Headers

  We “fail off” if we have no header detection method available.
*/

#if defined(__has_include) && __has_include(<barrier>)
  #define LBAL_HAS_HEADER_BARRIER 1
#else
  #define LBAL_HAS_HEADER_BARRIER 0
#endif

#if defined(__has_include) && __has_include(<bit>)
  #define LBAL_HAS_HEADER_BIT 1
#else
  #define LBAL_HAS_HEADER_BIT 0
#endif

#if defined(__has_include) && __has_include(<compare>)
  #define LBAL_HAS_HEADER_COMPARE 1
#else
  #define LBAL_HAS_HEADER_COMPARE 0
#endif

#if defined(__has_include) && __has_include(<concepts>)
  #define LBAL_HAS_HEADER_CONCEPTS 1
#else
  #define LBAL_HAS_HEADER_CONCEPTS 0
#endif

#if defined(__has_include) && __has_include(<experimental/concepts>)
  #define LBAL_HAS_HEADER_EXPERIMENTAL_CONCEPTS 1
#else
  #define LBAL_HAS_HEADER_EXPERIMENTAL_CONCEPTS 0
#endif

#if defined(__has_include) && __has_include(<coroutine>)
  #define LBAL_HAS_HEADER_COROUTINE 1
#else
  #define LBAL_HAS_HEADER_COROUTINE 0
#endif

#if defined(__has_include) && __has_include(<experimental/coroutine>)
  #define LBAL_HAS_HEADER_EXPERIMENTAL_COROUTINE 1
#else
  #define LBAL_HAS_HEADER_EXPERIMENTAL_COROUTINE 0
#endif

#if defined(__has_include) && __has_include(<format>)
  #define LBAL_HAS_HEADER_FORMAT 1
#else
  #define LBAL_HAS_HEADER_FORMAT 0
#endif

#if defined(__has_include) && __has_include(<latch>)
  #define LBAL_HAS_HEADER_LATCH 1
#else
  #define LBAL_HAS_HEADER_LATCH 0
#endif

#if defined(__has_include) && __has_include(<numbers>)
  #define LBAL_HAS_HEADER_NUMBERS 1
#else
  #define LBAL_HAS_HEADER_NUMBERS 0
#endif

#if defined(__has_include) && __has_include(<ranges>)
  #define LBAL_HAS_HEADER_RANGES 1
#else
  #define LBAL_HAS_HEADER_RANGES 0
#endif

#if defined(__has_include) && __has_include(<semaphore>)
  #define LBAL_HAS_HEADER_SEMAPHORE 1
#else
  #define LBAL_HAS_HEADER_SEMAPHORE 0
#endif

#if defined(__has_include) && __has_include(<source_location>)
  #define LBAL_HAS_HEADER_SOURCE_LOCATION 1
#else
  #define LBAL_HAS_HEADER_SOURCE_LOCATION 0
#endif

#if defined(__has_include) && __has_include(<span>)
  #define LBAL_HAS_HEADER_SPAN 1
#else
  #define LBAL_HAS_HEADER_SPAN 0
#endif

#if defined(__has_include) && __has_include(<stop_token>)
  #define LBAL_HAS_HEADER_STOP_TOKEN 1
#else
  #define LBAL_HAS_HEADER_STOP_TOKEN 0
#endif

#if defined(__has_include) && __has_include(<syncstream>)
  #define LBAL_HAS_HEADER_SYNCSTREAM 1
#else
  #define LBAL_HAS_HEADER_SYNCSTREAM 0
#endif

#if defined(__has_include) && __has_include(<version>)
  #define LBAL_HAS_HEADER_VERSION 1
#else
  #define LBAL_HAS_HEADER_VERSION 0
#endif

/*
  C++23 Headers

  We “fail off” if we have no header detection method available.
*/

#if defined(__has_include) && __has_include(<expected>)
  #define LBAL_HAS_HEADER_EXPECTED 1
#else
  #define LBAL_HAS_HEADER_EXPECTED 0
#endif

#if defined(__has_include) && __has_include(<flat_map>)
  #define LBAL_HAS_HEADER_FLAT_MAP 1
#else
  #define LBAL_HAS_HEADER_FLAT_MAP 0
#endif

#if defined(__has_include) && __has_include(<flat_set>)
  #define LBAL_HAS_HEADER_FLAT_SET 1
#else
  #define LBAL_HAS_HEADER_FLAT_SET 0
#endif

#if defined(__has_include) && __has_include(<generator>)
  #define LBAL_HAS_HEADER_GENERATOR 1
#else
  #define LBAL_HAS_HEADER_GENERATOR 0
#endif

#if defined(__has_include) && __has_include(<mdspan>)
  #define LBAL_HAS_HEADER_MDSPAN 1
#else
  #define LBAL_HAS_HEADER_MDSPAN 0
#endif

#if defined(__has_include) && __has_include(<print>)
  #define LBAL_HAS_HEADER_PRINT 1
#else
  #define LBAL_HAS_HEADER_PRINT 0
#endif

#if defined(__has_include) && __has_include(<spanstream>)
  #define LBAL_HAS_HEADER_SPANSTREAM 1
#else
  #define LBAL_HAS_HEADER_SPANSTREAM 0
#endif

#if defined(__has_include) && __has_include(<stacktrace>)
  #define LBAL_HAS_HEADER_STACKTRACE 1
#else
  #define LBAL_HAS_HEADER_STACKTRACE 0
#endif

#if defined(__has_include) && __has_include(<stdatomic.h>)
  #define LBAL_HAS_HEADER_STDATOMIC_H 1
#else
  #define LBAL_HAS_HEADER_STDATOMIC_H 0
#endif

#if defined(__has_include) && __has_include(<stdfloat>)
  #define LBAL_HAS_HEADER_STDFLOAT 1
#else
  #define LBAL_HAS_HEADER_STDFLOAT 0
#endif

/*
  C++26 Headers

  We “fail off” if we have no header detection method available.
*/

#if defined(__has_include) && __has_include(<debugging>)
  #define LBAL_HAS_HEADER_DEBUGGING 1
#else
  #define LBAL_HAS_HEADER_DEBUGGING 0
#endif

#if defined(__has_include) && __has_include(<hazard_pointer>)
  #define LBAL_HAS_HEADER_HAZARD_POINTER 1
#else
  #define LBAL_HAS_HEADER_HAZARD_POINTER 0
#endif

#if defined(__has_include) && __has_include(<hive>)
  #define LBAL_HAS_HEADER_HIVE 1
#else
  #define LBAL_HAS_HEADER_HIVE 0
#endif

#if defined(__has_include) && __has_include(<inplace_vector>)
  #define LBAL_HAS_HEADER_INPLACE_VECTOR 1
#else
  #define LBAL_HAS_HEADER_INPLACE_VECTOR 0
#endif

#if defined(__has_include) && __has_include(<linalg>)
  #define LBAL_HAS_HEADER_LINALG 1
#else
  #define LBAL_HAS_HEADER_LINALG 0
#endif

#if defined(__has_include) && __has_include(<rcu>)
  #define LBAL_HAS_HEADER_RCU 1
#else
  #define LBAL_HAS_HEADER_RCU 0
#endif

#if defined(__has_include) && __has_include(<simd>)
  #define LBAL_HAS_HEADER_SIMD 1
#else
  #define LBAL_HAS_HEADER_SIMD 0
#endif
#if defined(__has_include) && __has_include(<contracts>)
  #define LBAL_HAS_HEADER_CONTRACTS 1
#else
  #define LBAL_HAS_HEADER_CONTRACTS 0
#endif

#if defined(__has_include) && __has_include(<text_encoding>)
  #define LBAL_HAS_HEADER_TEXT_ENCODING 1
#else
  #define LBAL_HAS_HEADER_TEXT_ENCODING 0
#endif

/*
  C++2d Headers

  We “fail off” if we have no header detection method available.
*/

//  (FIXME - bitweeder) These are on hold till the associated proposals
//  are published publicly.

/*
  Token Tests
*/

#if LBAL_LIBCPP14_CHRONO_UDLS
  #if LBAL_HAS_HEADER_CHRONO != 1
    #undef LBAL_LIBCPP14_CHRONO_UDLS
    #define LBAL_LIBCPP14_CHRONO_UDLS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP14_CHRONO_UDLS: <chrono> not found"
)
  #endif  // LBAL_HAS_HEADER_CHRONO
#endif    // LBAL_LIBCPP14_CHRONO_UDLS

#if LBAL_LIBCPP14_COMPLEX_UDLS
  #if LBAL_HAS_HEADER_COMPLEX != 1
    #undef LBAL_LIBCPP14_COMPLEX_UDLS
    #define LBAL_LIBCPP14_COMPLEX_UDLS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP14_COMPLEX_UDLS: <complex> not found"
)
  #endif  // LBAL_HAS_HEADER_COMPLEX
#endif    // LBAL_LIBCPP14_COMPLEX_UDLS

#if LBAL_LIBCPP14_EXCHANGE_FUNCTION
  #if LBAL_HAS_HEADER_UTILITY != 1
    #undef LBAL_LIBCPP14_EXCHANGE_FUNCTION
    #define LBAL_LIBCPP14_EXCHANGE_FUNCTION 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP14_EXCHANGE_FUNCTION: <utility> not found"
)
  #endif  // LBAL_HAS_HEADER_UTILITY
#endif    // LBAL_LIBCPP14_EXCHANGE_FUNCTION

#if LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP
  #if LBAL_HAS_HEADER_MAP != 1 || LBAL_HAS_HEADER_SET != 1
    #undef LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP
    #define LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP: at least one "
    "of {<map>,<set>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP

#if LBAL_LIBCPP14_INTEGER_SEQUENCE
  #if LBAL_HAS_HEADER_UTILITY != 1
    #undef LBAL_LIBCPP14_INTEGER_SEQUENCE
    #define LBAL_LIBCPP14_INTEGER_SEQUENCE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP14_INTEGER_SEQUENCE: <utility> not found"
)
  #endif  // LBAL_HAS_HEADER_UTILITY
#endif    // LBAL_LIBCPP14_INTEGER_SEQUENCE

#if LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE
    #define LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE: "
    "<type_traits> not found"
)
  #endif  // LBAL_HAS_HEADER_TYPE_TRAITS
#endif    // LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE

#if LBAL_LIBCPP14_IS_FINAL
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP14_IS_FINAL
    #define LBAL_LIBCPP14_IS_FINAL 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP14_IS_FINAL: <type_traits> not found"
)
  #endif  // LBAL_HAS_HEADER_TYPE_TRAITS
#endif    // LBAL_LIBCPP14_IS_FINAL

#if LBAL_LIBCPP14_IS_NULL_POINTER
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP14_IS_NULL_POINTER
    #define LBAL_LIBCPP14_IS_NULL_POINTER 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP14_IS_NULL_POINTER: <type_traits> not found"
)
  #endif  // LBAL_HAS_HEADER_TYPE_TRAITS
#endif    // LBAL_LIBCPP14_IS_NULL_POINTER

#if LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR
  #if LBAL_HAS_HEADER_ITERATOR != 1
    #undef LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR
    #define LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR: <iterator> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_ITERATOR
#endif    // LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR

#if LBAL_LIBCPP14_MAKE_UNIQUE
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP14_MAKE_UNIQUE
    #define LBAL_LIBCPP14_MAKE_UNIQUE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP14_MAKE_UNIQUE: <memory> not found"
)
  #endif  // LBAL_HAS_HEADER_MEMORY
#endif    // LBAL_LIBCPP14_MAKE_UNIQUE

#if LBAL_LIBCPP14_NULL_ITERATORS
  #if LBAL_HAS_HEADER_ITERATOR != 1
    #undef LBAL_LIBCPP14_NULL_ITERATORS
    #define LBAL_LIBCPP14_NULL_ITERATORS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP14_NULL_ITERATORS: <iterator> not found"
)
  #endif  // LBAL_HAS_HEADER_ITERATOR
#endif    // LBAL_LIBCPP14_NULL_ITERATORS

#if LBAL_LIBCPP14_QUOTED_STRING_IO
  #if LBAL_HAS_HEADER_IOMANIP != 1
    #undef LBAL_LIBCPP14_QUOTED_STRING_IO
    #define LBAL_LIBCPP14_QUOTED_STRING_IO 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP14_QUOTED_STRING_IO: <iomanip> not found"
)
  #endif  // LBAL_HAS_HEADER_IOMANIP
#endif    // LBAL_LIBCPP14_QUOTED_STRING_IO

#if LBAL_LIBCPP14_RESULT_OF_SFINAE
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1 || LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP14_RESULT_OF_SFINAE
    #define LBAL_LIBCPP14_RESULT_OF_SFINAE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP14_RESULT_OF_SFINAE: at least one of "
    "{<functional>,<type_traits>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP14_RESULT_OF_SFINAE

#if LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS
  #if LBAL_HAS_HEADER_ALGORITHM != 1
    #undef LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS
    #define LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS: <algorithm> "
    "not found"
)
  #endif  // LBAL_HAS_HEADER_ALGORITHM
#endif    // LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS

#if LBAL_LIBCPP14_SHARED_TIMED_MUTEX
  #if LBAL_HAS_HEADER_SHARED_MUTEX != 1
    #undef LBAL_LIBCPP14_SHARED_TIMED_MUTEX
    #define LBAL_LIBCPP14_SHARED_TIMED_MUTEX 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP14_SHARED_TIMED_MUTEX: <shared_mutex> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_SHARED_MUTEX
#endif    // LBAL_LIBCPP14_SHARED_TIMED_MUTEX

#if LBAL_LIBCPP14_STRING_UDLS
  #if LBAL_HAS_HEADER_STRING != 1
    #undef LBAL_LIBCPP14_STRING_UDLS
    #define LBAL_LIBCPP14_STRING_UDLS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP14_STRING_UDLS: <string> not found"
)
  #endif  // LBAL_HAS_HEADER_STRING
#endif    // LBAL_LIBCPP14_STRING_UDLS

#if LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES
    #define LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES: "
    "<type_traits> not found"
)
  #endif  // LBAL_HAS_HEADER_TYPE_TRAITS
#endif    // LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES

#if LBAL_LIBCPP14_TRANSPARENT_OPERATORS
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1 || LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP14_TRANSPARENT_OPERATORS
    #define LBAL_LIBCPP14_TRANSPARENT_OPERATORS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP14_TRANSPARENT_OPERATORS: at least one of "
    "{<functional>,<memory>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP14_TRANSPARENT_OPERATORS

#if LBAL_LIBCPP14_TUPLE_ELEMENT_T
  #if LBAL_HAS_HEADER_TUPLE != 1
    #undef LBAL_LIBCPP14_TUPLE_ELEMENT_T
    #define LBAL_LIBCPP14_TUPLE_ELEMENT_T 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP14_TUPLE_ELEMENT_T: <tuple> not found"
)
  #endif  // LBAL_HAS_HEADER_TUPLE
#endif    // LBAL_LIBCPP14_TUPLE_ELEMENT_T

#if LBAL_LIBCPP14_TUPLES_BY_TYPE
  #if LBAL_HAS_HEADER_TUPLE != 1 || LBAL_HAS_HEADER_UTILITY != 1
    #undef LBAL_LIBCPP14_TUPLES_BY_TYPE
    #define LBAL_LIBCPP14_TUPLES_BY_TYPE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP14_TUPLES_BY_TYPE: at least one of "
    "{<tuple>,<utility>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP14_TUPLES_BY_TYPE

#if LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR
    #define LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR: <memory> not found"
)
  #endif  // LBAL_HAS_HEADER_MEMORY
#endif    // LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR

#if LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL
  #if LBAL_HAS_HEADER_DEQUE != 1                                               \
      || LBAL_HAS_HEADER_FORWARD_LIST != 1                                     \
      || LBAL_HAS_HEADER_LIST != 1                                             \
      || LBAL_HAS_HEADER_MAP != 1                                              \
      || LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL
    #define LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL: at "
    "least one of {<deque>,<forward_list>,<list>,<map>,<memory>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL

#if LBAL_LIBCPP17_ANY
  #if LBAL_HAS_HEADER_ANY != 1
    #undef LBAL_LIBCPP17_ANY
    #define LBAL_LIBCPP17_ANY 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP17_ANY: <any> not found")
  #endif  // LBAL_HAS_HEADER_ANY
#endif    // LBAL_LIBCPP17_ANY

#if LBAL_LIBCPP17_ANY_INTERFACE
  #if LBAL_HAS_HEADER_ANY != 1
    #undef LBAL_LIBCPP17_ANY_INTERFACE
    #define LBAL_LIBCPP17_ANY_INTERFACE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_ANY_INTERFACE: <any> not found"
)
  #endif  // LBAL_HAS_HEADER_ANY
#endif    // LBAL_LIBCPP17_ANY_INTERFACE

#if LBAL_LIBCPP17_APPLY
  #if LBAL_HAS_HEADER_TUPLE != 1
    #undef LBAL_LIBCPP17_APPLY
    #define LBAL_LIBCPP17_APPLY 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP17_APPLY: <tuple> not found")
  #endif  // LBAL_HAS_HEADER_TUPLE
#endif    // LBAL_LIBCPP17_APPLY

#if LBAL_LIBCPP17_ARRAY_CONSTEXPR
  #if LBAL_HAS_HEADER_ARRAY != 1 || LBAL_HAS_HEADER_ITERATOR != 1
    #undef LBAL_LIBCPP17_ARRAY_CONSTEXPR
    #define LBAL_LIBCPP17_ARRAY_CONSTEXPR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_ARRAY_CONSTEXPR: at least one of "
    "{<array>,<iterator>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP17_ARRAY_CONSTEXPR

#if LBAL_LIBCPP17_AS_CONST
  #if LBAL_HAS_HEADER_UTILITY != 1
    #undef LBAL_LIBCPP17_AS_CONST
    #define LBAL_LIBCPP17_AS_CONST 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_AS_CONST: <utility> not found"
)
  #endif  // LBAL_HAS_HEADER_UTILITY
#endif    // LBAL_LIBCPP17_AS_CONST

#if LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE
  #if LBAL_HAS_HEADER_ATOMIC != 1
    #undef LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE
    #define LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE: <atomic> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_ATOMIC
#endif    // LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE

#if LBAL_LIBCPP17_BOOL_CONSTANT
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP17_BOOL_CONSTANT
    #define LBAL_LIBCPP17_BOOL_CONSTANT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_BOOL_CONSTANT: <type_traits> not found"
)
  #endif  // LBAL_HAS_HEADER_TYPE_TRAITS
#endif    // LBAL_LIBCPP17_BOOL_CONSTANT

#if LBAL_LIBCPP17_BOYER_MOORE_SEARCHER
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1
    #undef LBAL_LIBCPP17_BOYER_MOORE_SEARCHER
    #define LBAL_LIBCPP17_BOYER_MOORE_SEARCHER 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_BOYER_MOORE_SEARCHER: <functional> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_FUNCTIONAL
#endif    // LBAL_LIBCPP17_BOYER_MOORE_SEARCHER

#if LBAL_LIBCPP17_BYTE
  #if LBAL_HAS_HEADER_CSTDDEF != 1
    #undef LBAL_LIBCPP17_BYTE
    #define LBAL_LIBCPP17_BYTE 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP17_BYTE: <cstddef> not found")
  #endif  // LBAL_HAS_HEADER_CSTDDEF
#endif    // LBAL_LIBCPP17_BYTE

#if LBAL_LIBCPP17_CHRONO
  #if LBAL_HAS_HEADER_CHRONO != 1
    #undef LBAL_LIBCPP17_CHRONO
    #define LBAL_LIBCPP17_CHRONO 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP17_CHRONO: <chrono> not found")
  #endif  // LBAL_HAS_HEADER_CHRONO
#endif    // LBAL_LIBCPP17_CHRONO

#if LBAL_LIBCPP17_CHRONO_CONSTEXPR
  #if LBAL_HAS_HEADER_CHRONO != 1
    #undef LBAL_LIBCPP17_CHRONO_CONSTEXPR
    #define LBAL_LIBCPP17_CHRONO_CONSTEXPR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_CHRONO_CONSTEXPR: <chrono> not found"
)
  #endif  // LBAL_HAS_HEADER_CHRONO
#endif    // LBAL_LIBCPP17_CHRONO_CONSTEXPR

#if LBAL_LIBCPP17_CLAMP
  #if LBAL_HAS_HEADER_ALGORITHM != 1
    #undef LBAL_LIBCPP17_CLAMP
    #define LBAL_LIBCPP17_CLAMP 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_CLAMP: <algorithm> not found"
)
  #endif  // LBAL_HAS_HEADER_ALGORITHM
#endif    // LBAL_LIBCPP17_CLAMP

#if LBAL_LIBCPP17_CONSTEXPR_STRING
  #if LBAL_HAS_HEADER_STRING != 1
    #undef LBAL_LIBCPP17_CONSTEXPR_STRING
    #define LBAL_LIBCPP17_CONSTEXPR_STRING 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_CONSTEXPR_STRING: <string> not found"
)
  #endif  // LBAL_HAS_HEADER_STRING
#endif    // LBAL_LIBCPP17_CONSTEXPR_STRING

#if LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW
  #if LBAL_HAS_HEADER_STRING_VIEW != 1
    #undef LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW
    #define LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW: <string_view> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_STRING_VIEW
#endif    // LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW

#if LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS
    #define LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS: <memory> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_MEMORY
#endif    // LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS

#if LBAL_LIBCPP17_EXECUTION
  #if LBAL_HAS_HEADER_EXECUTION != 1
    #undef LBAL_LIBCPP17_EXECUTION
    #define LBAL_LIBCPP17_EXECUTION 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_EXECUTION: <execution> not found"
)
  #endif  // LBAL_HAS_HEADER_EXECUTION
#endif    // LBAL_LIBCPP17_EXECUTION

#if LBAL_LIBCPP17_FILESYSTEM
  #if LBAL_HAS_HEADER_FILESYSTEM != 1
    #undef LBAL_LIBCPP17_FILESYSTEM
    #define LBAL_LIBCPP17_FILESYSTEM 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_FILESYSTEM: <filesystem> not found"
)
  #endif  // LBAL_HAS_HEADER_FILESYSTEM
#endif    // LBAL_LIBCPP17_FILESYSTEM

#if LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED
  #if LBAL_HAS_HEADER_FILESYSTEM != 1
    #undef LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED
    #define LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED: <filesystem> "
    "not found"
)
  #endif  // LBAL_HAS_HEADER_FILESYSTEM
#endif    // LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED

#if LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING
  #if LBAL_HAS_HEADER_FILESYSTEM != 1
    #undef LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING
    #define LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING: "
    "<filesystem> not found"
)
  #endif  // LBAL_HAS_HEADER_FILESYSTEM
#endif    // LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING

#if LBAL_LIBCPP17_FILESYSTEM_EXP
  #if LBAL_HAS_HEADER_FILESYSTEM != 1
    #undef LBAL_LIBCPP17_FILESYSTEM_EXP
    #define LBAL_LIBCPP17_FILESYSTEM_EXP 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_FILESYSTEM_EXP: "
    "<experimental/filesystem> not found"
)
  #endif  // LBAL_HAS_HEADER_FILESYSTEM
#endif    // LBAL_LIBCPP17_FILESYSTEM_EXP

#if LBAL_LIBCPP17_GCD_LCM
  #if LBAL_HAS_HEADER_NUMERIC != 1
    #undef LBAL_LIBCPP17_GCD_LCM
    #define LBAL_LIBCPP17_GCD_LCM 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_GCD_LCM: <numeric> not found"
)
  #endif  // LBAL_HAS_HEADER_NUMERIC
#endif    // LBAL_LIBCPP17_GCD_LCM

#if LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE
  #if LBAL_HAS_HEADER_NEW != 1
    #undef LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE
    #define LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE: <new> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_NEW
#endif    // LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE

#if LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS
    #define LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS: "
    "<type_traits> not found"
)
  #endif  // LBAL_HAS_HEADER_TYPE_TRAITS
#endif    // LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS

#if LBAL_LIBCPP17_HYPOT
  #if LBAL_HAS_HEADER_CMATH != 1
    #undef LBAL_LIBCPP17_HYPOT
    #define LBAL_LIBCPP17_HYPOT 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP17_HYPOT: <cmath> not found")
  #endif  // LBAL_HAS_HEADER_CMATH
#endif    // LBAL_LIBCPP17_HYPOT

#if LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS
  #if LBAL_HAS_HEADER_FORWARD_LIST != 1                                        \
      || LBAL_HAS_HEADER_LIST != 1                                             \
      || LBAL_HAS_HEADER_VECTOR != 1
    #undef LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS
    #define LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS: at least "
    "one of {<forward_list>,<list>,<vector>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS

#if LBAL_LIBCPP17_INVOKE
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1
    #undef LBAL_LIBCPP17_INVOKE
    #define LBAL_LIBCPP17_INVOKE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_INVOKE: <functional> not found"
)
  #endif  // LBAL_HAS_HEADER_FUNCTIONAL
#endif    // LBAL_LIBCPP17_INVOKE

#if LBAL_LIBCPP17_IS_AGGREGATE
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP17_IS_AGGREGATE
    #define LBAL_LIBCPP17_IS_AGGREGATE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_IS_AGGREGATE: <type_traits> not found"
)
  #endif  // LBAL_HAS_HEADER_TYPE_TRAITS
#endif    // LBAL_LIBCPP17_IS_AGGREGATE

#if LBAL_LIBCPP17_IS_INVOCABLE
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP17_IS_INVOCABLE
    #define LBAL_LIBCPP17_IS_INVOCABLE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_IS_INVOCABLE: <type_traits> not found"
)
  #endif  // LBAL_HAS_HEADER_TYPE_TRAITS
#endif    // LBAL_LIBCPP17_IS_INVOCABLE

#if LBAL_LIBCPP17_IS_SWAPPABLE
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP17_IS_SWAPPABLE
    #define LBAL_LIBCPP17_IS_SWAPPABLE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_IS_SWAPPABLE: <type_traits> not found"
)
  #endif  // LBAL_HAS_HEADER_TYPE_TRAITS
#endif    // LBAL_LIBCPP17_IS_SWAPPABLE

#if LBAL_LIBCPP17_LAUNDER
  #if LBAL_HAS_HEADER_NEW != 1
    #undef LBAL_LIBCPP17_LAUNDER
    #define LBAL_LIBCPP17_LAUNDER 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP17_LAUNDER: <new> not found")
  #endif  // LBAL_HAS_HEADER_NEW
#endif    // LBAL_LIBCPP17_LAUNDER

#if LBAL_LIBCPP17_LOGICAL_TRAITS
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP17_LOGICAL_TRAITS
    #define LBAL_LIBCPP17_LOGICAL_TRAITS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_LOGICAL_TRAITS: <type_traits> not found"
)
  #endif  // LBAL_HAS_HEADER_TYPE_TRAITS
#endif    // LBAL_LIBCPP17_LOGICAL_TRAITS

#if LBAL_LIBCPP17_MAKE_FROM_TUPLE
  #if LBAL_HAS_HEADER_TUPLE != 1
    #undef LBAL_LIBCPP17_MAKE_FROM_TUPLE
    #define LBAL_LIBCPP17_MAKE_FROM_TUPLE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_MAKE_FROM_TUPLE: <tuple> not found"
)
  #endif  // LBAL_HAS_HEADER_TUPLE
#endif    // LBAL_LIBCPP17_MAKE_FROM_TUPLE

#if LBAL_LIBCPP17_MAP_TRY_EMPLACE
  #if LBAL_HAS_HEADER_MAP != 1
    #undef LBAL_LIBCPP17_MAP_TRY_EMPLACE
    #define LBAL_LIBCPP17_MAP_TRY_EMPLACE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_MAP_TRY_EMPLACE: <map> not found"
)
  #endif  // LBAL_HAS_HEADER_MAP
#endif    // LBAL_LIBCPP17_MAP_TRY_EMPLACE

#if LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS
  #if LBAL_HAS_HEADER_CMATH != 1
    #undef LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS
    #define LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS: <cmath> not found"
)
  #endif  // LBAL_HAS_HEADER_CMATH
#endif    // LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS

#if LBAL_LIBCPP17_MEMORY_RESOURCE
  #if LBAL_HAS_HEADER_MEMORY_RESOURCE != 1
    #undef LBAL_LIBCPP17_MEMORY_RESOURCE
    #define LBAL_LIBCPP17_MEMORY_RESOURCE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_MEMORY_RESOURCE: <memory_resource> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_MEMORY_RESOURCE
#endif    // LBAL_LIBCPP17_MEMORY_RESOURCE

#if LBAL_LIBCPP17_NODE_EXTRACT
  #if LBAL_HAS_HEADER_MAP != 1                                                 \
      || LBAL_HAS_HEADER_SET != 1                                              \
      || LBAL_HAS_HEADER_UNORDERED_MAP != 1                                    \
      || LBAL_HAS_HEADER_UNORDERED_SET != 1
    #undef LBAL_LIBCPP17_NODE_EXTRACT
    #define LBAL_LIBCPP17_NODE_EXTRACT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_NODE_EXTRACT: at least one of "
    "{<map>,<set>,<unordered_map>,<unordered_set>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP17_NODE_EXTRACT

#if LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS
  #if LBAL_HAS_HEADER_ARRAY != 1                                               \
      || LBAL_HAS_HEADER_DEQUE != 1                                            \
      || LBAL_HAS_HEADER_FORWARD_LIST != 1                                     \
      || LBAL_HAS_HEADER_ITERATOR != 1                                         \
      || LBAL_HAS_HEADER_LIST != 1                                             \
      || LBAL_HAS_HEADER_MAP != 1
    #undef LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS
    #define LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS: at least one "
    "of {<array>,<deque>,<forward_list>,<iterator>,<list>,<map>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS

#if LBAL_LIBCPP17_NOT_FN
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1
    #undef LBAL_LIBCPP17_NOT_FN
    #define LBAL_LIBCPP17_NOT_FN 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_NOT_FN: <functional> not found"
)
  #endif  // LBAL_HAS_HEADER_FUNCTIONAL
#endif    // LBAL_LIBCPP17_NOT_FN

#if LBAL_LIBCPP17_OPTIONAL
  #if LBAL_HAS_HEADER_OPTIONAL != 1
    #undef LBAL_LIBCPP17_OPTIONAL
    #define LBAL_LIBCPP17_OPTIONAL 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_OPTIONAL: <optional> not found"
)
  #endif  // LBAL_HAS_HEADER_OPTIONAL
#endif    // LBAL_LIBCPP17_OPTIONAL

#if LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL
  #if LBAL_HAS_HEADER_OPTIONAL != 1
    #undef LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL
    #define LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL: <optional> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_OPTIONAL
#endif    // LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL

#if LBAL_LIBCPP17_OPTIONAL_INTERFACE
  #if LBAL_HAS_HEADER_OPTIONAL != 1
    #undef LBAL_LIBCPP17_OPTIONAL_INTERFACE
    #define LBAL_LIBCPP17_OPTIONAL_INTERFACE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_OPTIONAL_INTERFACE: <optional> not found"
)
  #endif  // LBAL_HAS_HEADER_OPTIONAL
#endif    // LBAL_LIBCPP17_OPTIONAL_INTERFACE

#if LBAL_LIBCPP17_PARALLEL_ALGORITHM
  #if LBAL_HAS_HEADER_ALGORITHM != 1 || LBAL_HAS_HEADER_NUMERIC != 1
    #undef LBAL_LIBCPP17_PARALLEL_ALGORITHM
    #define LBAL_LIBCPP17_PARALLEL_ALGORITHM 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_PARALLEL_ALGORITHM: at least one of "
    "{<algorithm>,<numeric>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP17_PARALLEL_ALGORITHM

#if LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS
    #define LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS: <memory> not found"
)
  #endif  // LBAL_HAS_HEADER_MEMORY
#endif    // LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS

#if LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS
  #if LBAL_HAS_HEADER_ALGORITHM != 1                                           \
      || LBAL_HAS_HEADER_EXECUTION != 1                                        \
      || LBAL_HAS_HEADER_NUMERIC != 1
    #undef LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS
    #define LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS: at "
    "least one of {<algorithm>,<execution>,<numeric>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS

#if LBAL_LIBCPP17_SAMPLE
  #if LBAL_HAS_HEADER_ALGORITHM != 1
    #undef LBAL_LIBCPP17_SAMPLE
    #define LBAL_LIBCPP17_SAMPLE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_SAMPLE: <algorithm> not found"
)
  #endif  // LBAL_HAS_HEADER_ALGORITHM
#endif    // LBAL_LIBCPP17_SAMPLE

#if LBAL_LIBCPP17_SCOPED_LOCK
  #if LBAL_HAS_HEADER_MUTEX != 1
    #undef LBAL_LIBCPP17_SCOPED_LOCK
    #define LBAL_LIBCPP17_SCOPED_LOCK 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_SCOPED_LOCK: <mutex> not found"
)
  #endif  // LBAL_HAS_HEADER_MUTEX
#endif    // LBAL_LIBCPP17_SCOPED_LOCK

#if LBAL_LIBCPP17_SHARED_MUTEX
  #if LBAL_HAS_HEADER_SHARED_MUTEX != 1
    #undef LBAL_LIBCPP17_SHARED_MUTEX
    #define LBAL_LIBCPP17_SHARED_MUTEX 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_SHARED_MUTEX: <shared_mutex> not found"
)
  #endif  // LBAL_HAS_HEADER_SHARED_MUTEX
#endif    // LBAL_LIBCPP17_SHARED_MUTEX

#if LBAL_LIBCPP17_SHARED_PTR_ARRAYS
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP17_SHARED_PTR_ARRAYS
    #define LBAL_LIBCPP17_SHARED_PTR_ARRAYS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_SHARED_PTR_ARRAYS: <memory> not found"
)
  #endif  // LBAL_HAS_HEADER_MEMORY
#endif    // LBAL_LIBCPP17_SHARED_PTR_ARRAYS

#if LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE
    #define LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE: <memory> not found"
)
  #endif  // LBAL_HAS_HEADER_MEMORY
#endif    // LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE

#if LBAL_LIBCPP17_STRING_VIEW
  #if LBAL_HAS_HEADER_STRING != 1 || LBAL_HAS_HEADER_STRING_VIEW != 1
    #undef LBAL_LIBCPP17_STRING_VIEW
    #define LBAL_LIBCPP17_STRING_VIEW 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_STRING_VIEW: at least one of "
    "{<string>,<string_view>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP17_STRING_VIEW

#if LBAL_LIBCPP17_STRING_VIEW_INTERFACE
  #if LBAL_HAS_HEADER_STRING != 1 || LBAL_HAS_HEADER_STRING_VIEW != 1
    #undef LBAL_LIBCPP17_STRING_VIEW_INTERFACE
    #define LBAL_LIBCPP17_STRING_VIEW_INTERFACE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_STRING_VIEW_INTERFACE: at least one of "
    "{<string>,<string_view>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP17_STRING_VIEW_INTERFACE

#if LBAL_LIBCPP17_TO_CHARS
  #if LBAL_HAS_HEADER_CHARCONV != 1
    #undef LBAL_LIBCPP17_TO_CHARS
    #define LBAL_LIBCPP17_TO_CHARS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_TO_CHARS: <charconv> not found"
)
  #endif  // LBAL_HAS_HEADER_CHARCONV
#endif    // LBAL_LIBCPP17_TO_CHARS

#if LBAL_LIBCPP17_TO_CHARS_FP
  #if LBAL_HAS_HEADER_CHARCONV != 1
    #undef LBAL_LIBCPP17_TO_CHARS_FP
    #define LBAL_LIBCPP17_TO_CHARS_FP 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_TO_CHARS_FP: <charconv> not found"
)
  #endif  // LBAL_HAS_HEADER_CHARCONV
#endif    // LBAL_LIBCPP17_TO_CHARS_FP

#if LBAL_LIBCPP17_TO_CHARS_INTEGER
  #if LBAL_HAS_HEADER_CHARCONV != 1
    #undef LBAL_LIBCPP17_TO_CHARS_INTEGER
    #define LBAL_LIBCPP17_TO_CHARS_INTEGER 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_TO_CHARS_INTEGER: <charconv> not found"
)
  #endif  // LBAL_HAS_HEADER_CHARCONV
#endif    // LBAL_LIBCPP17_TO_CHARS_INTEGER

#if LBAL_LIBCPP17_TRANSPARENT_OPERATORS
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1 || LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP17_TRANSPARENT_OPERATORS
    #define LBAL_LIBCPP17_TRANSPARENT_OPERATORS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_TRANSPARENT_OPERATORS: at least one of "
    "{<functional>,<memory>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP17_TRANSPARENT_OPERATORS

#if LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES
    #define LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES: "
    "<type_traits> not found"
)
  #endif  // LBAL_HAS_HEADER_TYPE_TRAITS
#endif    // LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES

#if LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS
  #if LBAL_HAS_HEADER_EXCEPTION != 1
    #undef LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS
    #define LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS: <exception> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_EXCEPTION
#endif    // LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS

#if LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE
  #if LBAL_HAS_HEADER_UNORDERED_MAP != 1
    #undef LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE
    #define LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE: "
    "<unordered_map> not found"
)
  #endif  // LBAL_HAS_HEADER_UNORDERED_MAP
#endif    // LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE

#if LBAL_LIBCPP17_VARIANT
  #if LBAL_HAS_HEADER_VARIANT != 1
    #undef LBAL_LIBCPP17_VARIANT
    #define LBAL_LIBCPP17_VARIANT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_VARIANT: <variant> not found"
)
  #endif  // LBAL_HAS_HEADER_VARIANT
#endif    // LBAL_LIBCPP17_VARIANT

#if LBAL_LIBCPP17_VOID_T
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP17_VOID_T
    #define LBAL_LIBCPP17_VOID_T 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_VOID_T: <type_traits> not found"
)
  #endif  // LBAL_HAS_HEADER_TYPE_TRAITS
#endif    // LBAL_LIBCPP17_VOID_T

#if LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR
  #if LBAL_HAS_HEADER_ARRAY != 1 || LBAL_HAS_HEADER_ITERATOR != 1
    #undef LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR
    #define LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR: at least one "
    "of {<array>,<iterator>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR

#if LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS
  #if LBAL_HAS_HEADER_ARRAY != 1 || LBAL_HAS_HEADER_ITERATOR != 1
    #undef LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS
    #define LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS: at least "
    "one of {<array>,<iterator>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS

#if LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES
  #if LBAL_HAS_HEADER_ARRAY != 1 || LBAL_HAS_HEADER_ITERATOR != 1
    #undef LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES
    #define LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES: at least one "
    "of {<array>,<iterator>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES

#if LBAL_LIBCPP20_ASSUME_ALIGNED
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP20_ASSUME_ALIGNED
    #define LBAL_LIBCPP20_ASSUME_ALIGNED 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ASSUME_ALIGNED: <memory> not found"
)
  #endif  // LBAL_HAS_HEADER_MEMORY
#endif    // LBAL_LIBCPP20_ASSUME_ALIGNED

#if LBAL_LIBCPP20_ATOMIC_FLAG_TEST
  #if LBAL_HAS_HEADER_ATOMIC != 1
    #undef LBAL_LIBCPP20_ATOMIC_FLAG_TEST
    #define LBAL_LIBCPP20_ATOMIC_FLAG_TEST 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ATOMIC_FLAG_TEST: <atomic> not found"
)
  #endif  // LBAL_HAS_HEADER_ATOMIC
#endif    // LBAL_LIBCPP20_ATOMIC_FLAG_TEST
#if LBAL_LIBCPP20_ATOMIC_FLOAT
  #if LBAL_HAS_HEADER_ATOMIC != 1
    #undef LBAL_LIBCPP20_ATOMIC_FLOAT
    #define LBAL_LIBCPP20_ATOMIC_FLOAT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ATOMIC_FLOAT: <atomic> not found"
)
  #endif  // LBAL_HAS_HEADER_ATOMIC
#endif    // LBAL_LIBCPP20_ATOMIC_FLOAT

#if LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES
  #if LBAL_HAS_HEADER_ATOMIC != 1
    #undef LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES
    #define LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES: <atomic> "
    "not found"
)
  #endif  // LBAL_HAS_HEADER_ATOMIC
#endif    // LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES

#if LBAL_LIBCPP20_ATOMIC_REF
  #if LBAL_HAS_HEADER_ATOMIC != 1
    #undef LBAL_LIBCPP20_ATOMIC_REF
    #define LBAL_LIBCPP20_ATOMIC_REF 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ATOMIC_REF: <atomic> not found"
)
  #endif  // LBAL_HAS_HEADER_ATOMIC
#endif    // LBAL_LIBCPP20_ATOMIC_REF

#if LBAL_LIBCPP20_ATOMIC_SHARED_PTR
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP20_ATOMIC_SHARED_PTR
    #define LBAL_LIBCPP20_ATOMIC_SHARED_PTR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ATOMIC_SHARED_PTR: <memory> not found"
)
  #endif  // LBAL_HAS_HEADER_MEMORY
#endif    // LBAL_LIBCPP20_ATOMIC_SHARED_PTR

#if LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION
  #if LBAL_HAS_HEADER_ATOMIC != 1 || LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION
    #define LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION: at least "
    "one of {<atomic>,<memory>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION

#if LBAL_LIBCPP20_ATOMIC_WAIT
  #if LBAL_HAS_HEADER_ATOMIC != 1
    #undef LBAL_LIBCPP20_ATOMIC_WAIT
    #define LBAL_LIBCPP20_ATOMIC_WAIT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ATOMIC_WAIT: <atomic> not found"
)
  #endif  // LBAL_HAS_HEADER_ATOMIC
#endif    // LBAL_LIBCPP20_ATOMIC_WAIT

#if LBAL_LIBCPP20_BARRIER
  #if LBAL_HAS_HEADER_BARRIER != 1
    #undef LBAL_LIBCPP20_BARRIER
    #define LBAL_LIBCPP20_BARRIER 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_BARRIER: <barrier> not found"
)
  #endif  // LBAL_HAS_HEADER_BARRIER
#endif    // LBAL_LIBCPP20_BARRIER

#if LBAL_LIBCPP20_BIND_FRONT
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1
    #undef LBAL_LIBCPP20_BIND_FRONT
    #define LBAL_LIBCPP20_BIND_FRONT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_BIND_FRONT: <functional> not found"
)
  #endif  // LBAL_HAS_HEADER_FUNCTIONAL
#endif    // LBAL_LIBCPP20_BIND_FRONT

#if LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1
    #undef LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP
    #define LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP: <functional> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_FUNCTIONAL
#endif    // LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP

#if LBAL_LIBCPP20_BIT_CAST
  #if LBAL_HAS_HEADER_BIT != 1
    #undef LBAL_LIBCPP20_BIT_CAST
    #define LBAL_LIBCPP20_BIT_CAST 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP20_BIT_CAST: <bit> not found")
  #endif  // LBAL_HAS_HEADER_BIT
#endif    // LBAL_LIBCPP20_BIT_CAST

#if LBAL_LIBCPP20_BITOPS
  #if LBAL_HAS_HEADER_BIT != 1
    #undef LBAL_LIBCPP20_BITOPS
    #define LBAL_LIBCPP20_BITOPS 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP20_BITOPS: <bit> not found")
  #endif  // LBAL_HAS_HEADER_BIT
#endif    // LBAL_LIBCPP20_BITOPS

#if LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS
    #define LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS: <type_traits> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_TYPE_TRAITS
#endif    // LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS

#if LBAL_LIBCPP20_CHAR8_T
  #if LBAL_HAS_HEADER_ATOMIC != 1                                              \
      || LBAL_HAS_HEADER_FILESYSTEM != 1                                       \
      || LBAL_HAS_HEADER_ISTREAM != 1                                          \
      || LBAL_HAS_HEADER_LIMITS != 1                                           \
      || LBAL_HAS_HEADER_LOCALE != 1                                           \
      || LBAL_HAS_HEADER_OSTREAM != 1
    #undef LBAL_LIBCPP20_CHAR8_T
    #define LBAL_LIBCPP20_CHAR8_T 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CHAR8_T: at least one of "
    "{<atomic>,<filesystem>,<istream>,<limits>,<locale>,<ostream>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP20_CHAR8_T

#if LBAL_LIBCPP20_CHAR8_T_COMPAT
  #if LBAL_HAS_HEADER_ATOMIC != 1                                              \
      || LBAL_HAS_HEADER_FILESYSTEM != 1                                       \
      || LBAL_HAS_HEADER_ISTREAM != 1                                          \
      || LBAL_HAS_HEADER_LIMITS != 1                                           \
      || LBAL_HAS_HEADER_LOCALE != 1                                           \
      || LBAL_HAS_HEADER_OSTREAM != 1
    #undef LBAL_LIBCPP20_CHAR8_T_COMPAT
    #define LBAL_LIBCPP20_CHAR8_T_COMPAT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CHAR8_T_COMPAT: at least one of "
    "{<atomic>,<filesystem>,<istream>,<limits>,<locale>,<ostream>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP20_CHAR8_T_COMPAT

#if LBAL_LIBCPP20_CHRONO_CALENDAR
  #if LBAL_HAS_HEADER_CHRONO != 1
    #undef LBAL_LIBCPP20_CHRONO_CALENDAR
    #define LBAL_LIBCPP20_CHRONO_CALENDAR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CHRONO_CALENDAR: <chrono> not found"
)
  #endif  // LBAL_HAS_HEADER_CHRONO
#endif    // LBAL_LIBCPP20_CHRONO_CALENDAR

#if LBAL_LIBCPP20_CHRONO_FIXES
  #if LBAL_HAS_HEADER_CHRONO != 1
    #undef LBAL_LIBCPP20_CHRONO_FIXES
    #define LBAL_LIBCPP20_CHRONO_FIXES 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CHRONO_FIXES: <chrono> not found"
)
  #endif  // LBAL_HAS_HEADER_CHRONO
#endif    // LBAL_LIBCPP20_CHRONO_FIXES

#if LBAL_LIBCPP20_CONCEPTS
  #if LBAL_HAS_HEADER_CONCEPTS != 1
    #undef LBAL_LIBCPP20_CONCEPTS
    #define LBAL_LIBCPP20_CONCEPTS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONCEPTS: <concepts> not found"
)
  #endif  // LBAL_HAS_HEADER_CONCEPTS
#endif    // LBAL_LIBCPP20_CONCEPTS

#if LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE
  #if LBAL_HAS_HEADER_CONCEPTS != 1
    #undef LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE
    #define LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE: <concepts> "
    "not found"
)
  #endif  // LBAL_HAS_HEADER_CONCEPTS
#endif    // LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE

#if LBAL_LIBCPP20_CONCEPTS_EXP
  #if LBAL_HAS_HEADER_EXPERIMENTAL_CONCEPTS != 1
    #undef LBAL_LIBCPP20_CONCEPTS_EXP
    #define LBAL_LIBCPP20_CONCEPTS_EXP 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONCEPTS_EXP: <experimental/concepts> "
    "not found"
)
  #endif  // LBAL_HAS_HEADER_EXPERIMENTAL_CONCEPTS
#endif    // LBAL_LIBCPP20_CONCEPTS_EXP

#if LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE
  #if LBAL_HAS_HEADER_CONCEPTS != 1
    #undef LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE
    #define LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE: <concepts> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_CONCEPTS
#endif    // LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE

#if LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS
  #if LBAL_HAS_HEADER_ALGORITHM != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS
    #define LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS: <algorithm> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_ALGORITHM
#endif    // LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS

#if LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP
  #if LBAL_HAS_HEADER_ALGORITHM != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP
    #define LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP: <algorithm> "
    "not found"
)
  #endif  // LBAL_HAS_HEADER_ALGORITHM
#endif    // LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP

#if LBAL_LIBCPP20_CONSTEXPR_COMPLEX
  #if LBAL_HAS_HEADER_COMPLEX != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_COMPLEX
    #define LBAL_LIBCPP20_CONSTEXPR_COMPLEX 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_COMPLEX: <complex> not found"
)
  #endif  // LBAL_HAS_HEADER_COMPLEX
#endif    // LBAL_LIBCPP20_CONSTEXPR_COMPLEX

#if LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC
    #define LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC: <memory> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_MEMORY
#endif    // LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC

#if LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL
    #define LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL: <functional> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_FUNCTIONAL
#endif    // LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL

#if LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE
    #define LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE: "
    "<functional> not found"
)
  #endif  // LBAL_HAS_HEADER_FUNCTIONAL
#endif    // LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE

#if LBAL_LIBCPP20_CONSTEXPR_ITERATOR
  #if LBAL_HAS_HEADER_ITERATOR != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_ITERATOR
    #define LBAL_LIBCPP20_CONSTEXPR_ITERATOR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_ITERATOR: <iterator> not found"
)
  #endif  // LBAL_HAS_HEADER_ITERATOR
#endif    // LBAL_LIBCPP20_CONSTEXPR_ITERATOR

#if LBAL_LIBCPP20_CONSTEXPR_MEMORY
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_MEMORY
    #define LBAL_LIBCPP20_CONSTEXPR_MEMORY 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_MEMORY: <memory> not found"
)
  #endif  // LBAL_HAS_HEADER_MEMORY
#endif    // LBAL_LIBCPP20_CONSTEXPR_MEMORY

#if LBAL_LIBCPP20_CONSTEXPR_NUMERIC
  #if LBAL_HAS_HEADER_NUMERIC != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_NUMERIC
    #define LBAL_LIBCPP20_CONSTEXPR_NUMERIC 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_NUMERIC: <numeric> not found"
)
  #endif  // LBAL_HAS_HEADER_NUMERIC
#endif    // LBAL_LIBCPP20_CONSTEXPR_NUMERIC

#if LBAL_LIBCPP20_CONSTEXPR_STRING
  #if LBAL_HAS_HEADER_STRING != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_STRING
    #define LBAL_LIBCPP20_CONSTEXPR_STRING 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_STRING: <string> not found"
)
  #endif  // LBAL_HAS_HEADER_STRING
#endif    // LBAL_LIBCPP20_CONSTEXPR_STRING

#if LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL
  #if LBAL_HAS_HEADER_STRING != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL
    #define LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL: <string> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_STRING
#endif    // LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL

#if LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW
  #if LBAL_HAS_HEADER_STRING_VIEW != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW
    #define LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW: <string_view> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_STRING_VIEW
#endif    // LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW

#if LBAL_LIBCPP20_CONSTEXPR_TUPLE
  #if LBAL_HAS_HEADER_TUPLE != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_TUPLE
    #define LBAL_LIBCPP20_CONSTEXPR_TUPLE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_TUPLE: <tuple> not found"
)
  #endif  // LBAL_HAS_HEADER_TUPLE
#endif    // LBAL_LIBCPP20_CONSTEXPR_TUPLE

#if LBAL_LIBCPP20_CONSTEXPR_UTILITY
  #if LBAL_HAS_HEADER_UTILITY != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_UTILITY
    #define LBAL_LIBCPP20_CONSTEXPR_UTILITY 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_UTILITY: <utility> not found"
)
  #endif  // LBAL_HAS_HEADER_UTILITY
#endif    // LBAL_LIBCPP20_CONSTEXPR_UTILITY

#if LBAL_LIBCPP20_CONSTEXPR_VECTOR
  #if LBAL_HAS_HEADER_VECTOR != 1
    #undef LBAL_LIBCPP20_CONSTEXPR_VECTOR
    #define LBAL_LIBCPP20_CONSTEXPR_VECTOR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_CONSTEXPR_VECTOR: <vector> not found"
)
  #endif  // LBAL_HAS_HEADER_VECTOR
#endif    // LBAL_LIBCPP20_CONSTEXPR_VECTOR

#if LBAL_LIBCPP20_COROUTINE
  #if LBAL_HAS_HEADER_COROUTINE != 1
    #undef LBAL_LIBCPP20_COROUTINE
    #define LBAL_LIBCPP20_COROUTINE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_COROUTINE: <coroutine> not found"
)
  #endif  // LBAL_HAS_HEADER_COROUTINE
#endif    // LBAL_LIBCPP20_COROUTINE

#if LBAL_LIBCPP20_COROUTINE_EXP
  #if LBAL_HAS_HEADER_EXPERIMENTAL_COROUTINE != 1
    #undef LBAL_LIBCPP20_COROUTINE_EXP
    #define LBAL_LIBCPP20_COROUTINE_EXP 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_COROUTINE_EXP: <experimental/coroutine> "
    "not found"
)
  #endif  // LBAL_HAS_HEADER_EXPERIMENTAL_COROUTINE
#endif    // LBAL_LIBCPP20_COROUTINE_EXP

#if LBAL_LIBCPP20_DESTROYING_DELETE
  #if LBAL_HAS_HEADER_NEW != 1
    #undef LBAL_LIBCPP20_DESTROYING_DELETE
    #define LBAL_LIBCPP20_DESTROYING_DELETE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_DESTROYING_DELETE: <new> not found"
)
  #endif  // LBAL_HAS_HEADER_NEW
#endif    // LBAL_LIBCPP20_DESTROYING_DELETE

#if LBAL_LIBCPP20_ENDIAN
  #if LBAL_HAS_HEADER_BIT != 1
    #undef LBAL_LIBCPP20_ENDIAN
    #define LBAL_LIBCPP20_ENDIAN 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP20_ENDIAN: <bit> not found")
  #endif  // LBAL_HAS_HEADER_BIT
#endif    // LBAL_LIBCPP20_ENDIAN

#if LBAL_LIBCPP20_ENDIAN_BIT
  #if LBAL_HAS_HEADER_BIT != 1
    #undef LBAL_LIBCPP20_ENDIAN_BIT
    #define LBAL_LIBCPP20_ENDIAN_BIT 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP20_ENDIAN_BIT: <bit> not found")
  #endif  // LBAL_HAS_HEADER_BIT
#endif    // LBAL_LIBCPP20_ENDIAN_BIT

#if LBAL_LIBCPP20_ERASE_IF
  #if LBAL_HAS_HEADER_DEQUE != 1                                               \
      || LBAL_HAS_HEADER_FORWARD_LIST != 1                                     \
      || LBAL_HAS_HEADER_LIST != 1                                             \
      || LBAL_HAS_HEADER_MAP != 1                                              \
      || LBAL_HAS_HEADER_SET != 1                                              \
      || LBAL_HAS_HEADER_STRING != 1
    #undef LBAL_LIBCPP20_ERASE_IF
    #define LBAL_LIBCPP20_ERASE_IF 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ERASE_IF: at least one of "
    "{<deque>,<forward_list>,<list>,<map>,<set>,<string>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP20_ERASE_IF

#if LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS
  #if LBAL_HAS_HEADER_DEQUE != 1                                               \
      || LBAL_HAS_HEADER_FORWARD_LIST != 1                                     \
      || LBAL_HAS_HEADER_LIST != 1                                             \
      || LBAL_HAS_HEADER_MAP != 1                                              \
      || LBAL_HAS_HEADER_SET != 1                                              \
      || LBAL_HAS_HEADER_STRING != 1
    #undef LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS
    #define LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS: at least one of "
    "{<deque>,<forward_list>,<list>,<map>,<set>,<string>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS

#if LBAL_LIBCPP20_EXECUTION_VECTORIZATION
  #if LBAL_HAS_HEADER_EXECUTION != 1
    #undef LBAL_LIBCPP20_EXECUTION_VECTORIZATION
    #define LBAL_LIBCPP20_EXECUTION_VECTORIZATION 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_EXECUTION_VECTORIZATION: <execution> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_EXECUTION
#endif    // LBAL_LIBCPP20_EXECUTION_VECTORIZATION

#if LBAL_LIBCPP20_FORMAT
  #if LBAL_HAS_HEADER_FORMAT != 1
    #undef LBAL_LIBCPP20_FORMAT
    #define LBAL_LIBCPP20_FORMAT 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP20_FORMAT: <format> not found")
  #endif  // LBAL_HAS_HEADER_FORMAT
#endif    // LBAL_LIBCPP20_FORMAT

#if LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP
  #if LBAL_HAS_HEADER_UNORDERED_MAP != 1 || LBAL_HAS_HEADER_UNORDERED_SET != 1
    #undef LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP
    #define LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP: at least "
    "one of {<unordered_map>,<unordered_set>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP20_GENERIC_UNORDERED_HASH_LOOKUP

#if LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP
  #if LBAL_HAS_HEADER_UNORDERED_MAP != 1 || LBAL_HAS_HEADER_UNORDERED_SET != 1
    #undef LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP
    #define LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP: at least one "
    "of {<unordered_map>,<unordered_set>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP

#if LBAL_LIBCPP20_INT_POW2
  #if LBAL_HAS_HEADER_BIT != 1
    #undef LBAL_LIBCPP20_INT_POW2
    #define LBAL_LIBCPP20_INT_POW2 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP20_INT_POW2: <bit> not found")
  #endif  // LBAL_HAS_HEADER_BIT
#endif    // LBAL_LIBCPP20_INT_POW2

#if LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME
  #if LBAL_HAS_HEADER_BIT != 1
    #undef LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME
    #define LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME: <bit> not found"
)
  #endif  // LBAL_HAS_HEADER_BIT
#endif    // LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME

#if LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS
  #if LBAL_HAS_HEADER_UTILITY != 1
    #undef LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS
    #define LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS: <utility> "
    "not found"
)
  #endif  // LBAL_HAS_HEADER_UTILITY
#endif    // LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS

#if LBAL_LIBCPP20_INTERPOLATE
  #if LBAL_HAS_HEADER_CMATH != 1 || LBAL_HAS_HEADER_NUMERIC != 1
    #undef LBAL_LIBCPP20_INTERPOLATE
    #define LBAL_LIBCPP20_INTERPOLATE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_INTERPOLATE: at least one of "
    "{<cmath>,<numeric>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP20_INTERPOLATE

#if LBAL_LIBCPP20_IS_CONSTANT_EVALUATED
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP20_IS_CONSTANT_EVALUATED
    #define LBAL_LIBCPP20_IS_CONSTANT_EVALUATED 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_IS_CONSTANT_EVALUATED: <type_traits> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_TYPE_TRAITS
#endif    // LBAL_LIBCPP20_IS_CONSTANT_EVALUATED

#if LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE
    #define LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE: <type_traits> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_TYPE_TRAITS
#endif    // LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE

#if LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE
    #define LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE: "
    "<type_traits> not found"
)
  #endif  // LBAL_HAS_HEADER_TYPE_TRAITS
#endif    // LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE

#if LBAL_LIBCPP20_JTHREAD
  #if LBAL_HAS_HEADER_STOP_TOKEN != 1 || LBAL_HAS_HEADER_THREAD != 1
    #undef LBAL_LIBCPP20_JTHREAD
    #define LBAL_LIBCPP20_JTHREAD 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_JTHREAD: at least one of "
    "{<stop_token>,<thread>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP20_JTHREAD

#if LBAL_LIBCPP20_JTHREAD_CV
  #if LBAL_HAS_HEADER_STOP_TOKEN != 1 || LBAL_HAS_HEADER_THREAD != 1
    #undef LBAL_LIBCPP20_JTHREAD_CV
    #define LBAL_LIBCPP20_JTHREAD_CV 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_JTHREAD_CV: at least one of "
    "{<stop_token>,<thread>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP20_JTHREAD_CV

#if LBAL_LIBCPP20_LATCH
  #if LBAL_HAS_HEADER_LATCH != 1
    #undef LBAL_LIBCPP20_LATCH
    #define LBAL_LIBCPP20_LATCH 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP20_LATCH: <latch> not found")
  #endif  // LBAL_HAS_HEADER_LATCH
#endif    // LBAL_LIBCPP20_LATCH

#if LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE
  #if LBAL_HAS_HEADER_FORWARD_LIST != 1 || LBAL_HAS_HEADER_LIST != 1
    #undef LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE
    #define LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE: at least one of "
    "{<forward_list>,<list>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE

#if LBAL_LIBCPP20_MATH_CONSTANTS
  #if LBAL_HAS_HEADER_NUMBERS != 1
    #undef LBAL_LIBCPP20_MATH_CONSTANTS
    #define LBAL_LIBCPP20_MATH_CONSTANTS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_MATH_CONSTANTS: <numbers> not found"
)
  #endif  // LBAL_HAS_HEADER_NUMBERS
#endif    // LBAL_LIBCPP20_MATH_CONSTANTS

#if LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE
    #define LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE: <type_traits> "
    "not found"
)
  #endif  // LBAL_HAS_HEADER_TYPE_TRAITS
#endif    // LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE

#if LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR
  #if LBAL_HAS_HEADER_MEMORY_RESOURCE != 1
    #undef LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR
    #define LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR: <memory_resource> "
    "not found"
)
  #endif  // LBAL_HAS_HEADER_MEMORY_RESOURCE
#endif    // LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR

#if LBAL_LIBCPP20_RANGES
  #if LBAL_HAS_HEADER_ALGORITHM != 1                                           \
      || LBAL_HAS_HEADER_FUNCTIONAL != 1                                       \
      || LBAL_HAS_HEADER_ITERATOR != 1                                         \
      || LBAL_HAS_HEADER_MEMORY != 1                                           \
      || LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP20_RANGES
    #define LBAL_LIBCPP20_RANGES 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_RANGES: at least one of "
    "{<algorithm>,<functional>,<iterator>,<memory>,<ranges>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP20_RANGES

#if LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS
  #if LBAL_HAS_HEADER_ALGORITHM != 1                                           \
      || LBAL_HAS_HEADER_FUNCTIONAL != 1                                       \
      || LBAL_HAS_HEADER_ITERATOR != 1                                         \
      || LBAL_HAS_HEADER_MEMORY != 1                                           \
      || LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS
    #define LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS: at least one of "
    "{<algorithm>,<functional>,<iterator>,<memory>,<ranges>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS

#if LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE
  #if LBAL_HAS_HEADER_ALGORITHM != 1                                           \
      || LBAL_HAS_HEADER_FUNCTIONAL != 1                                       \
      || LBAL_HAS_HEADER_ITERATOR != 1                                         \
      || LBAL_HAS_HEADER_MEMORY != 1                                           \
      || LBAL_HAS_HEADER_RANGES != 1
    #undef LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE
    #define LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE: at least one of "
    "{<algorithm>,<functional>,<iterator>,<memory>,<ranges>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE

#if LBAL_LIBCPP20_REMOVE_CVREF
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP20_REMOVE_CVREF
    #define LBAL_LIBCPP20_REMOVE_CVREF 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_REMOVE_CVREF: <type_traits> not found"
)
  #endif  // LBAL_HAS_HEADER_TYPE_TRAITS
#endif    // LBAL_LIBCPP20_REMOVE_CVREF

#if LBAL_LIBCPP20_SEMAPHORE
  #if LBAL_HAS_HEADER_SEMAPHORE != 1
    #undef LBAL_LIBCPP20_SEMAPHORE
    #define LBAL_LIBCPP20_SEMAPHORE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_SEMAPHORE: <semaphore> not found"
)
  #endif  // LBAL_HAS_HEADER_SEMAPHORE
#endif    // LBAL_LIBCPP20_SEMAPHORE

#if LBAL_LIBCPP20_SHARED_PTR_ARRAYS
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP20_SHARED_PTR_ARRAYS
    #define LBAL_LIBCPP20_SHARED_PTR_ARRAYS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_SHARED_PTR_ARRAYS: <memory> not found"
)
  #endif  // LBAL_HAS_HEADER_MEMORY
#endif    // LBAL_LIBCPP20_SHARED_PTR_ARRAYS

#if LBAL_LIBCPP20_SHIFT
  #if LBAL_HAS_HEADER_ALGORITHM != 1
    #undef LBAL_LIBCPP20_SHIFT
    #define LBAL_LIBCPP20_SHIFT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_SHIFT: <algorithm> not found"
)
  #endif  // LBAL_HAS_HEADER_ALGORITHM
#endif    // LBAL_LIBCPP20_SHIFT

#if LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE
    #define LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE: <memory> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_MEMORY
#endif    // LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE

#if LBAL_LIBCPP20_SOURCE_LOCATION
  #if LBAL_HAS_HEADER_SOURCE_LOCATION != 1
    #undef LBAL_LIBCPP20_SOURCE_LOCATION
    #define LBAL_LIBCPP20_SOURCE_LOCATION 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_SOURCE_LOCATION: <source_location> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_SOURCE_LOCATION
#endif    // LBAL_LIBCPP20_SOURCE_LOCATION

#if LBAL_LIBCPP20_SPAN
  #if LBAL_HAS_HEADER_SPAN != 1
    #undef LBAL_LIBCPP20_SPAN
    #define LBAL_LIBCPP20_SPAN 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP20_SPAN: <span> not found")
  #endif  // LBAL_HAS_HEADER_SPAN
#endif    // LBAL_LIBCPP20_SPAN

#if LBAL_LIBCPP20_SPAN_USABILITY
  #if LBAL_HAS_HEADER_SPAN != 1
    #undef LBAL_LIBCPP20_SPAN_USABILITY
    #define LBAL_LIBCPP20_SPAN_USABILITY 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_SPAN_USABILITY: <span> not found"
)
  #endif  // LBAL_HAS_HEADER_SPAN
#endif    // LBAL_LIBCPP20_SPAN_USABILITY

#if LBAL_LIBCPP20_SPAN_FIXED_SIZE
  #if LBAL_HAS_HEADER_SPAN != 1
    #undef LBAL_LIBCPP20_SPAN_FIXED_SIZE
    #define LBAL_LIBCPP20_SPAN_FIXED_SIZE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_SPAN_FIXED_SIZE: <span> not found"
)
  #endif  // LBAL_HAS_HEADER_SPAN
#endif    // LBAL_LIBCPP20_SPAN_FIXED_SIZE

#if LBAL_LIBCPP20_SSIZE
  #if LBAL_HAS_HEADER_ITERATOR != 1 || LBAL_HAS_HEADER_SPAN != 1
    #undef LBAL_LIBCPP20_SSIZE
    #define LBAL_LIBCPP20_SSIZE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_SSIZE: at least one of "
    "{<iterator>,<span>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP20_SSIZE

#if LBAL_LIBCPP20_STARTS_ENDS_WITH
  #if LBAL_HAS_HEADER_STRING != 1 || LBAL_HAS_HEADER_STRING_VIEW != 1
    #undef LBAL_LIBCPP20_STARTS_ENDS_WITH
    #define LBAL_LIBCPP20_STARTS_ENDS_WITH 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_STARTS_ENDS_WITH: at least one of "
    "{<string>,<string_view>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP20_STARTS_ENDS_WITH

#if LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR
  #if LBAL_HAS_HEADER_STRING != 1 || LBAL_HAS_HEADER_STRING_VIEW != 1
    #undef LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR
    #define LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR: at least "
    "one of {<string>,<string_view>} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR

#if LBAL_LIBCPP20_SYNCBUF
  #if LBAL_HAS_HEADER_SYNCSTREAM != 1
    #undef LBAL_LIBCPP20_SYNCBUF
    #define LBAL_LIBCPP20_SYNCBUF 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_SYNCBUF: <syncstream> not found"
)
  #endif  // LBAL_HAS_HEADER_SYNCSTREAM
#endif    // LBAL_LIBCPP20_SYNCBUF

#if LBAL_LIBCPP20_SYNCBUF_MANIPULATORS
  #if LBAL_HAS_HEADER_SYNCSTREAM != 1
    #undef LBAL_LIBCPP20_SYNCBUF_MANIPULATORS
    #define LBAL_LIBCPP20_SYNCBUF_MANIPULATORS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_SYNCBUF_MANIPULATORS: <syncstream> not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_SYNCSTREAM
#endif    // LBAL_LIBCPP20_SYNCBUF_MANIPULATORS

#if LBAL_LIBCPP20_THREE_WAY_COMPARISON
  #if LBAL_HAS_HEADER_COMPARE != 1
    #undef LBAL_LIBCPP20_THREE_WAY_COMPARISON
    #define LBAL_LIBCPP20_THREE_WAY_COMPARISON 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_THREE_WAY_COMPARISON: <compare> not found"
)
  #endif  // LBAL_HAS_HEADER_COMPARE
#endif    // LBAL_LIBCPP20_THREE_WAY_COMPARISON

#if LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY
  #if LBAL_HAS_HEADER_COMPARE != 1
    #undef LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY
    #define LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY: <compare> "
    "not found"
)
  #endif  // LBAL_HAS_HEADER_COMPARE
#endif    // LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY

#if LBAL_LIBCPP20_TO_ADDRESS
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP20_TO_ADDRESS
    #define LBAL_LIBCPP20_TO_ADDRESS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_TO_ADDRESS: <memory> not found"
)
  #endif  // LBAL_HAS_HEADER_MEMORY
#endif    // LBAL_LIBCPP20_TO_ADDRESS

#if LBAL_LIBCPP20_TO_ARRAY
  #if LBAL_HAS_HEADER_ARRAY != 1
    #undef LBAL_LIBCPP20_TO_ARRAY
    #define LBAL_LIBCPP20_TO_ARRAY 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP20_TO_ARRAY: <array> not found")
  #endif  // LBAL_HAS_HEADER_ARRAY
#endif    // LBAL_LIBCPP20_TO_ARRAY

#if LBAL_LIBCPP20_TYPE_IDENTITY
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP20_TYPE_IDENTITY
    #define LBAL_LIBCPP20_TYPE_IDENTITY 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_TYPE_IDENTITY: <type_traits> not found"
)
  #endif  // LBAL_HAS_HEADER_TYPE_TRAITS
#endif    // LBAL_LIBCPP20_TYPE_IDENTITY

#if LBAL_LIBCPP20_UNWRAP_REF
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP20_UNWRAP_REF
    #define LBAL_LIBCPP20_UNWRAP_REF 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP20_UNWRAP_REF: `<type_traits>` not found"
)
  #endif  // LBAL_HAS_HEADER_TYPE_TRAITS
#endif    // LBAL_LIBCPP20_UNWRAP_REF

#if LBAL_LIBCPP23_ADAPTOR_ITERATOR_PAIR_CONSTRUCTOR
  #if LBAL_HAS_HEADER_QUEUE != 1 || LBAL_HAS_HEADER_STACK != 1
    #undef LBAL_LIBCPP23_ADAPTOR_ITERATOR_PAIR_CONSTRUCTOR
    #define LBAL_LIBCPP23_ADAPTOR_ITERATOR_PAIR_CONSTRUCTOR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_ADAPTOR_ITERATOR_PAIR_CONSTRUCTOR: at "
    "least one of {`<queue>`,`<stack>`} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP23_ADAPTOR_ITERATOR_PAIR_CONSTRUCTOR

#if LBAL_LIBCPP23_ALGORITHM_ITERATOR_REQUIREMENTS
  #if LBAL_HAS_HEADER_ALGORITHM != 1                                           \
      || LBAL_HAS_HEADER_MEMORY != 1                                           \
      || LBAL_HAS_HEADER_NUMERIC != 1
    #undef LBAL_LIBCPP23_ALGORITHM_ITERATOR_REQUIREMENTS
    #define LBAL_LIBCPP23_ALGORITHM_ITERATOR_REQUIREMENTS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_ALGORITHM_ITERATOR_REQUIREMENTS: at "
    "least one of {`<algorithm>`,`<memory>`,`<numeric>`} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP23_ALGORITHM_ITERATOR_REQUIREMENTS

#if LBAL_LIBCPP23_BARRIER_RELAXED_COMPLETION
  #if LBAL_HAS_HEADER_BARRIER != 1
    #undef LBAL_LIBCPP23_BARRIER_RELAXED_COMPLETION
    #define LBAL_LIBCPP23_BARRIER_RELAXED_COMPLETION 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_BARRIER_RELAXED_COMPLETION: `<barrier>` "
    "not found"
)
  #endif  // LBAL_HAS_HEADER_BARRIER test
#endif    // LBAL_LIBCPP23_BARRIER_RELAXED_COMPLETION

#if LBAL_LIBCPP23_CONCEPTS_MOVE_ONLY
  #if LBAL_HAS_HEADER_COMPARE != 1 || LBAL_HAS_HEADER_CONCEPTS != 1
    #undef LBAL_LIBCPP23_CONCEPTS_MOVE_ONLY
    #define LBAL_LIBCPP23_CONCEPTS_MOVE_ONLY 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_CONCEPTS_MOVE_ONLY: at "
    "least one of {`<compare>`,`<concepts>`} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP23_CONCEPTS_MOVE_ONLY

#if LBAL_LIBCPP23_CONSTEXPR_MEMORY_UNIQUE_PTR
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP23_CONSTEXPR_MEMORY_UNIQUE_PTR
    #define LBAL_LIBCPP23_CONSTEXPR_MEMORY_UNIQUE_PTR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_CONSTEXPR_MEMORY_UNIQUE_PTR: `<memory>` "
    "not found"
)
  #endif  // LBAL_HAS_HEADER_MEMORY test
#endif    // LBAL_LIBCPP23_CONSTEXPR_MEMORY_UNIQUE_PTR

#if LBAL_LIBCPP23_FORMAT
  #if LBAL_HAS_HEADER_FORMAT != 1
    #undef LBAL_LIBCPP23_FORMAT
    #define LBAL_LIBCPP23_FORMAT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_FORMAT: `<format>` not found"
)
  #endif  // LBAL_HAS_HEADER_FORMAT test
#endif    // LBAL_LIBCPP23_FORMAT

#if LBAL_LIBCPP23_FORMAT_LOCALE
  #if LBAL_HAS_HEADER_FORMAT != 1
    #undef LBAL_LIBCPP23_FORMAT_LOCALE
    #define LBAL_LIBCPP23_FORMAT_LOCALE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_FORMAT_LOCALE: `<format>` not found"
)
  #endif  // LBAL_HAS_HEADER_FORMAT test
#endif    // LBAL_LIBCPP23_FORMAT_LOCALE

#if LBAL_LIBCPP23_FORMAT_GENERATOR
  #if LBAL_HAS_HEADER_FORMAT != 1
    #undef LBAL_LIBCPP23_FORMAT_GENERATOR
    #define LBAL_LIBCPP23_FORMAT_GENERATOR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_FORMAT_GENERATOR: `<format>` not found"
)
  #endif  // LBAL_HAS_HEADER_FORMAT test
#endif    // LBAL_LIBCPP23_FORMAT_GENERATOR

#if LBAL_LIBCPP23_FORMAT_ENCODINGS
  #if LBAL_HAS_HEADER_FORMAT != 1
    #undef LBAL_LIBCPP23_FORMAT_ENCODINGS
    #define LBAL_LIBCPP23_FORMAT_ENCODINGS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_FORMAT_ENCODINGS: `<format>` not found"
)
  #endif  // LBAL_HAS_HEADER_FORMAT test
#endif    // LBAL_LIBCPP23_FORMAT_ENCODINGS

#if LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING
  #if LBAL_HAS_HEADER_FORMAT != 1
    #undef LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING
    #define LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING: `<format>` "
    "not found"
)
  #endif  // LBAL_HAS_HEADER_FORMAT test
#endif    // LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING

#if LBAL_LIBCPP23_OPTIONAL_CONSTEXPR
  #if LBAL_HAS_HEADER_OPTIONAL != 1
    #undef LBAL_LIBCPP23_OPTIONAL_CONSTEXPR
    #define LBAL_LIBCPP23_OPTIONAL_CONSTEXPR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_OPTIONAL_CONSTEXPR: `<optional>` not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP23_OPTIONAL_CONSTEXPR

#if LBAL_LIBCPP23_OPTIONAL_MONADIC
  #if LBAL_HAS_HEADER_OPTIONAL != 1
    #undef LBAL_LIBCPP23_OPTIONAL_MONADIC
    #define LBAL_LIBCPP23_OPTIONAL_MONADIC 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_OPTIONAL_MONADIC: `<optional>` not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP23_OPTIONAL_MONADIC

#if LBAL_LIBCPP23_VARIANT_INHERITANCE
  #if LBAL_HAS_HEADER_VARIANT != 1
    #undef LBAL_LIBCPP23_VARIANT_INHERITANCE
    #define LBAL_LIBCPP23_VARIANT_INHERITANCE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_VARIANT_INHERITANCE: `<variant>` not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_VARIANT test
#endif    // LBAL_LIBCPP23_VARIANT_INHERITANCE

#if LBAL_LIBCPP23_VARIANT_CONSTEXPR
  #if LBAL_HAS_HEADER_VARIANT != 1
    #undef LBAL_LIBCPP23_VARIANT_CONSTEXPR
    #define LBAL_LIBCPP23_VARIANT_CONSTEXPR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP23_VARIANT_CONSTEXPR: `<variant>` not found"
)
  #endif  // LBAL_HAS_HEADER_VARIANT test
#endif    // LBAL_LIBCPP23_VARIANT_CONSTEXPR

#if LBAL_LIBCPP26_ALIGNED_ACCESSOR
  #if LBAL_HAS_HEADER_MDSPAN != 1
    #undef LBAL_LIBCPP26_ALIGNED_ACCESSOR
    #define LBAL_LIBCPP26_ALIGNED_ACCESSOR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP26_ALIGNED_ACCESSOR: `<mdspan>` not found"
)
  #endif  // LBAL_HAS_HEADER_MDSPAN
#endif    // LBAL_LIBCPP26_ALIGNED_ACCESSOR

#if LBAL_LIBCPP26_ATOMIC_REF_ADDRESS
  #if LBAL_HAS_HEADER_ATOMIC != 1
    #undef LBAL_LIBCPP26_ATOMIC_REF_ADDRESS
    #define LBAL_LIBCPP26_ATOMIC_REF_ADDRESS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP26_ATOMIC_REF_ADDRESS: `<atomic>` not found"
)
  #endif  // LBAL_HAS_HEADER_ATOMIC
#endif    // LBAL_LIBCPP26_ATOMIC_REF_ADDRESS

#if LBAL_LIBCPP26_BIND_FRONT_NTTP_CALLABLES
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1
    #undef LBAL_LIBCPP26_BIND_FRONT_NTTP_CALLABLES
    #define LBAL_LIBCPP26_BIND_FRONT_NTTP_CALLABLES 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP26_BIND_FRONT_NTTP_CALLABLES: "
    "`<functional>` not found"
)
  #endif  // LBAL_HAS_HEADER_FUNCTIONAL
#endif    // LBAL_LIBCPP26_BIND_FRONT_NTTP_CALLABLES

#if LBAL_LIBCPP26_CHRONO_HASHING
  #if LBAL_HAS_HEADER_CHRONO != 1
    #undef LBAL_LIBCPP26_CHRONO_HASHING
    #define LBAL_LIBCPP26_CHRONO_HASHING 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP26_CHRONO_HASHING: `<chrono>` not found"
)
  #endif  // LBAL_HAS_HEADER_CHRONO
#endif    // LBAL_LIBCPP26_CHRONO_HASHING

#if LBAL_LIBCPP26_CONSTEXPR_ALGORITHMS_STABLE_SORT
  #if LBAL_HAS_HEADER_ALGORITHM != 1 || LBAL_HAS_HEADER_UTILITY != 1
    #undef LBAL_LIBCPP26_CONSTEXPR_ALGORITHMS_STABLE_SORT
    #define LBAL_LIBCPP26_CONSTEXPR_ALGORITHMS_STABLE_SORT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP26_CONSTEXPR_ALGORITHMS_STABLE_SORT: at "
    "least one of {`<algorithm>`,`<utility>`} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP26_CONSTEXPR_ALGORITHMS_STABLE_SORT

#if LBAL_LIBCPP26_CONSTEXPR_COMPLEX
  #if LBAL_HAS_HEADER_COMPLEX != 1
    #undef LBAL_LIBCPP26_CONSTEXPR_COMPLEX
    #define LBAL_LIBCPP26_CONSTEXPR_COMPLEX 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP26_CONSTEXPR_COMPLEX: `<complex>` not found"
)
  #endif  // LBAL_HAS_HEADER_COMPLEX
#endif    // LBAL_LIBCPP26_CONSTEXPR_COMPLEX

#if LBAL_LIBCPP26_CONSTEXPR_MEMORY_SHARED_PTR
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP26_CONSTEXPR_MEMORY_SHARED_PTR
    #define LBAL_LIBCPP26_CONSTEXPR_MEMORY_SHARED_PTR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP26_CONSTEXPR_MEMORY_SHARED_PTR: `<memory>` "
    "not found"
)
  #endif  // LBAL_HAS_HEADER_MEMORY
#endif    // LBAL_LIBCPP26_CONSTEXPR_MEMORY_SHARED_PTR

#if LBAL_LIBCPP26_FORMAT_POINTERS
  #if LBAL_HAS_HEADER_FORMAT != 1
    #undef LBAL_LIBCPP26_FORMAT_POINTERS
    #define LBAL_LIBCPP26_FORMAT_POINTERS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP26_FORMAT_POINTERS: `<format>` not found"
)
  #endif  // LBAL_HAS_HEADER_FORMAT
#endif    // LBAL_LIBCPP26_FORMAT_POINTERS

#if LBAL_LIBCPP26_FORMAT_TYPE_CHECK
  #if LBAL_HAS_HEADER_FORMAT != 1
    #undef LBAL_LIBCPP26_FORMAT_TYPE_CHECK
    #define LBAL_LIBCPP26_FORMAT_TYPE_CHECK 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP26_FORMAT_TYPE_CHECK: `<format>` not found"
)
  #endif  // LBAL_HAS_HEADER_FORMAT
#endif    // LBAL_LIBCPP26_FORMAT_TYPE_CHECK

#if LBAL_LIBCPP26_FORMAT_MEMBER_VISIT
  #if LBAL_HAS_HEADER_FORMAT != 1
    #undef LBAL_LIBCPP26_FORMAT_MEMBER_VISIT
    #define LBAL_LIBCPP26_FORMAT_MEMBER_VISIT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP26_FORMAT_MEMBER_VISIT: `<format>` not found"
)
  #endif  // LBAL_HAS_HEADER_FORMAT
#endif    // LBAL_LIBCPP26_FORMAT_MEMBER_VISIT

#if LBAL_LIBCPP26_FORMAT_RUNTIME
  #if LBAL_HAS_HEADER_FORMAT != 1
    #undef LBAL_LIBCPP26_FORMAT_RUNTIME
    #define LBAL_LIBCPP26_FORMAT_RUNTIME 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP26_FORMAT_RUNTIME: `<format>` not found"
)
  #endif  // LBAL_HAS_HEADER_FORMAT
#endif    // LBAL_LIBCPP26_FORMAT_RUNTIME

#if LBAL_LIBCPP26_INTEGER_SEQUENCE_EXPANSION_STATEMENTS
  #if LBAL_HAS_HEADER_UTILITY != 1
    #undef LBAL_LIBCPP26_INTEGER_SEQUENCE_EXPANSION_STATEMENTS
    #define LBAL_LIBCPP26_INTEGER_SEQUENCE_EXPANSION_STATEMENTS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP26_INTEGER_SEQUENCE_EXPANSION_STATEMENTS: "
    "`<utility>` not found"
)
  #endif  // LBAL_HAS_HEADER_UTILITY
#endif    // LBAL_LIBCPP26_INTEGER_SEQUENCE_EXPANSION_STATEMENTS

#if LBAL_LIBCPP26_NOT_FN_NTTP_CALLABLES
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1
    #undef LBAL_LIBCPP26_NOT_FN_NTTP_CALLABLES
    #define LBAL_LIBCPP26_NOT_FN_NTTP_CALLABLES 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP26_NOT_FN_NTTP_CALLABLES: `<functional>` "
    "not found"
)
  #endif  // LBAL_HAS_HEADER_FUNCTIONAL
#endif    // LBAL_LIBCPP26_NOT_FN_NTTP_CALLABLES

#if LBAL_LIBCPP26_OPTIONAL_REFERENCE
  #if LBAL_HAS_HEADER_OPTIONAL != 1
    #undef LBAL_LIBCPP26_OPTIONAL_REFERENCE
    #define LBAL_LIBCPP26_OPTIONAL_REFERENCE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP26_OPTIONAL_REFERENCE: `<optional>` not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_OPTIONAL
#endif    // LBAL_LIBCPP26_OPTIONAL_REFERENCE

#if LBAL_LIBCPP26_PARALLEL_ALGORITHM_RANGE
  #if LBAL_HAS_HEADER_ALGORITHM != 1 || LBAL_HAS_HEADER_NUMERIC != 1
    #undef LBAL_LIBCPP26_PARALLEL_ALGORITHM_RANGE
    #define LBAL_LIBCPP26_PARALLEL_ALGORITHM_RANGE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP26_PARALLEL_ALGORITHM_RANGE: at "
    "least one of {`<algorithm>`,`<numeric>`} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP26_PARALLEL_ALGORITHM_RANGE

#if LBAL_LIBCPP26_RAW_MEMORY_ALGORITHMS_CONSTEXPR
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP26_RAW_MEMORY_ALGORITHMS_CONSTEXPR
    #define LBAL_LIBCPP26_RAW_MEMORY_ALGORITHMS_CONSTEXPR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP26_RAW_MEMORY_ALGORITHMS_CONSTEXPR: "
    "`<memory>` not found"
)
  #endif  // LBAL_HAS_HEADER_ LBAL_HAS_HEADER_MEMORY
#endif    // LBAL_LIBCPP26_RAW_MEMORY_ALGORITHMS_CONSTEXPR

#if LBAL_LIBCPP26_STRING_VIEW_CONCAT
  #if LBAL_HAS_HEADER_STRING != 1 || LBAL_HAS_HEADER_STRING_VIEW != 1
    #undef LBAL_LIBCPP26_STRING_VIEW_CONCAT
    #define LBAL_LIBCPP26_STRING_VIEW_CONCAT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP26_STRING_VIEW_CONCAT: at "
    "least one of {`<string>`,`<string_view>`} not found"
)
  #endif  // LBAL_HAS_HEADER_ test
#endif    // LBAL_LIBCPP26_STRING_VIEW_CONCAT

#if LBAL_LIBCPP26_TO_CHARS_BOOL_TEST
  #if LBAL_HAS_HEADER_CHARCONV != 1
    #undef LBAL_LIBCPP26_TO_CHARS_BOOL_TEST
    #define LBAL_LIBCPP26_TO_CHARS_BOOL_TEST 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP26_TO_CHARS_BOOL_TEST: `<charconv>` not "
    "found"
)
  #endif  // LBAL_HAS_HEADER_CHARCONV test
#endif    // LBAL_LIBCPP26_TO_CHARS_BOOL_TEST

#if LBAL_LIBCPP26_VARIANT_VISITOR
  #if LBAL_HAS_HEADER_VARIANT != 1
    #undef LBAL_LIBCPP26_VARIANT_VISITOR
    #define LBAL_LIBCPP26_VARIANT_VISITOR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP26_VARIANT_VISITOR: `<variant>` not found"
)
  #endif  // LBAL_HAS_HEADER_VARIANT test
#endif    // LBAL_LIBCPP26_VARIANT_VISITOR
