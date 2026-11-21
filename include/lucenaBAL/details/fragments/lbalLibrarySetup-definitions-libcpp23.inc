/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalLibrarySetup-definitions-libcpp23.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

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

#if !defined(LBAL_LIBCPP23_MONADIC_OPTIONAL)
  #if __cpp_lib_monadic_optional >= 202110L
    #define LBAL_LIBCPP23_MONADIC_OPTIONAL __cpp_lib_monadic_optional
  #endif
#endif  //  LBAL_LIBCPP23_MONADIC_OPTIONAL

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
