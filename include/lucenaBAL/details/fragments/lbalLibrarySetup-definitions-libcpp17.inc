/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalLibrarySetup-definitions-libcpp17.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

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
