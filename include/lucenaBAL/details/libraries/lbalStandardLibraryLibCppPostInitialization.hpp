/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalStandardLibraryLibCppPostInitialization.hpp”
  Copyright © 2019-2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

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
    #if !defined(LBAL_LIBCPP14_CHRONO_UDLS)
      #define LBAL_LIBCPP14_CHRONO_UDLS 201304L
    #endif  //	LBAL_LIBCPP14_CHRONO_UDLS

    #if !defined(LBAL_LIBCPP14_COMPLEX_UDLS)
      #define LBAL_LIBCPP14_COMPLEX_UDLS 201309L
    #endif  //	LBAL_LIBCPP14_COMPLEX_UDLS

    #if !defined(LBAL_LIBCPP14_EXCHANGE_FUNCTION)
      #define LBAL_LIBCPP14_EXCHANGE_FUNCTION 201304L
    #endif  //	LBAL_LIBCPP14_EXCHANGE_FUNCTION

    #if !defined(LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP)
      #define LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP 201304L
    #endif  //	LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP

    #if !defined(LBAL_LIBCPP14_INTEGER_SEQUENCE)
      #define LBAL_LIBCPP14_INTEGER_SEQUENCE 201304L
    #endif  //	LBAL_LIBCPP14_INTEGER_SEQUENCE

    #if !defined(LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE)
      #define LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE 201304L
    #endif  //	LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE

    #if !defined(LBAL_LIBCPP14_IS_FINAL)
      #define LBAL_LIBCPP14_IS_FINAL 201402L
    #endif  //	LBAL_LIBCPP14_IS_FINAL

    #if !defined(LBAL_LIBCPP14_IS_NULL_POINTER)
      #define LBAL_LIBCPP14_IS_NULL_POINTER 201309L
    #endif  //	LBAL_LIBCPP14_IS_NULL_POINTER

    #if !defined(LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR)
      #define LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR 201402L
    #endif  //	LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR

    #if !defined(LBAL_LIBCPP14_MAKE_UNIQUE)
      #define LBAL_LIBCPP14_MAKE_UNIQUE 201304L
    #endif  //	LBAL_LIBCPP14_MAKE_UNIQUE

    #if !defined(LBAL_LIBCPP14_NULL_ITERATORS)
      #define LBAL_LIBCPP14_NULL_ITERATORS 201304L
    #endif  //	LBAL_LIBCPP14_NULL_ITERATORS

    #if !defined(LBAL_LIBCPP14_QUOTED_STRING_IO)
      #define LBAL_LIBCPP14_QUOTED_STRING_IO 201304L
    #endif  //	LBAL_LIBCPP14_QUOTED_STRING_IO

    #if !defined(LBAL_LIBCPP14_RESULT_OF_SFINAE)
      #define LBAL_LIBCPP14_RESULT_OF_SFINAE 201210L
    #endif  //	LBAL_LIBCPP14_RESULT_OF_SFINAE

    #if !defined(LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS)
      #define LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS 201304L
    #endif  //	LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS

    #if !defined(LBAL_LIBCPP14_SHARED_TIMED_MUTEX)
      #define LBAL_LIBCPP14_SHARED_TIMED_MUTEX 201402L
    #endif  //	LBAL_LIBCPP14_SHARED_TIMED_MUTEX

    #if !defined(LBAL_LIBCPP14_STRING_UDLS)
      #define LBAL_LIBCPP14_STRING_UDLS 201304L
    #endif  //	LBAL_LIBCPP14_STRING_UDLS

    #if !defined(LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES)
      #define LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES 201304L
    #endif  //	LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES

    #if !defined(LBAL_LIBCPP14_TRANSPARENT_OPERATORS)
      #define LBAL_LIBCPP14_TRANSPARENT_OPERATORS 201210L
    #endif  //	LBAL_LIBCPP14_TRANSPARENT_OPERATORS

    #if !defined(LBAL_LIBCPP14_TUPLE_ELEMENT_T)
      #define LBAL_LIBCPP14_TUPLE_ELEMENT_T 201402L
    #endif  //	LBAL_LIBCPP14_TUPLE_ELEMENT_T

    #if !defined(LBAL_LIBCPP14_TUPLES_BY_TYPE)
      #define LBAL_LIBCPP14_TUPLES_BY_TYPE 201304L
    #endif  //	LBAL_LIBCPP14_TUPLES_BY_TYPE
  #endif    //	LBAL_CPP14_VERSION

  //	C++17 Library Features
  //
  //	SEEME - bitweeder
  //	Many of the features that only recently received SD-6 macros have not
  //	been fully validated, yet. However, features we know not to be available
  //	have been stripped out; similarly, we don’t contradict `<version>` when
  //	it explicitly says a feature is unsupported, though we occasionally
  //	contradict it when it claims support that isn’t there (e.g., for
  //	`__cpp_lib_hardware_interference_size`). If there are inaccuracies, they
  //	most likely affect clangs older than version 8.
  #if LBAL_cpp_version > LBAL_CPP14_VERSION
    #if !defined(LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR)
      #define LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR 201603L
    #endif  //	LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR

    #if !defined(LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL)
      #define LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL 201411L
    #endif  //	LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL

    #if !defined(LBAL_LIBCPP17_ANY)
      #define LBAL_LIBCPP17_ANY 201603L
    #endif  //	LBAL_LIBCPP17_ANY

    #if !defined(LBAL_LIBCPP17_ANY_INTERFACE)
      #define LBAL_LIBCPP17_ANY_INTERFACE 201606L
    #endif  //	LBAL_LIBCPP17_ANY_INTERFACE

    #if !defined(LBAL_LIBCPP17_APPLY)
      #define LBAL_LIBCPP17_APPLY 201603L
    #endif  //	LBAL_LIBCPP17_APPLY

    #if !defined(LBAL_LIBCPP17_ARRAY_CONSTEXPR)
      #define LBAL_LIBCPP17_ARRAY_CONSTEXPR 201603L
    #endif  //	LBAL_LIBCPP17_ARRAY_CONSTEXPR

    #if !defined(LBAL_LIBCPP17_AS_CONST)
      #define LBAL_LIBCPP17_AS_CONST 201510L
    #endif  //	LBAL_LIBCPP17_AS_CONST

    #if !defined(LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE)
      #define LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE 201603L
    #endif  //	LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE

    #if !defined(LBAL_LIBCPP17_BOOL_CONSTANT)
      #define LBAL_LIBCPP17_BOOL_CONSTANT 201505L
    #endif  //	LBAL_LIBCPP17_BOOL_CONSTANT

    #if !defined(LBAL_LIBCPP17_BYTE)
      #define LBAL_LIBCPP17_BYTE 201603L
    #endif  //	LBAL_LIBCPP17_BYTE

    #if !defined(LBAL_LIBCPP17_CHRONO)
      #define LBAL_LIBCPP17_CHRONO 201510L
    #endif  //	LBAL_LIBCPP17_CHRONO

    #if !defined(LBAL_LIBCPP17_CHRONO_CONSTEXPR)
      #define LBAL_LIBCPP17_CHRONO_CONSTEXPR 201611L
    #endif  //	LBAL_LIBCPP17_CHRONO_CONSTEXPR

    #if !defined(LBAL_LIBCPP17_CLAMP)
      #define LBAL_LIBCPP17_CLAMP 201603L
    #endif  //	LBAL_LIBCPP17_CLAMP

    #if !defined(LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS)
      #define LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS 201603L
    #endif  //	LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS

    #if !defined(LBAL_LIBCPP17_GCD_LCM)
      #define LBAL_LIBCPP17_GCD_LCM 201606L
    #endif  //	LBAL_LIBCPP17_GCD_LCM

    #if !defined(LBAL_LIBCPP17_HYPOT)
      #define LBAL_LIBCPP17_HYPOT 201603L
    #endif  //	LBAL_LIBCPP17_HYPOT

    #if !defined(LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS)
      #define LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS 201505L
    #endif  //	LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS

    #if !defined(LBAL_LIBCPP17_INVOKE)
      #define LBAL_LIBCPP17_INVOKE 201411L
    #endif  //	LBAL_LIBCPP17_INVOKE

    #if !defined(LBAL_LIBCPP17_IS_AGGREGATE)
      #define LBAL_LIBCPP17_IS_AGGREGATE 201703L
    #endif  //	LBAL_LIBCPP17_IS_AGGREGATE

    #if !defined(LBAL_LIBCPP17_IS_INVOCABLE)
      #define LBAL_LIBCPP17_IS_INVOCABLE 201703L
    #endif  //	LBAL_LIBCPP17_IS_INVOCABLE

    #if !defined(LBAL_LIBCPP17_IS_SWAPPABLE)
      #define LBAL_LIBCPP17_IS_SWAPPABLE 201603L
    #endif  //	LBAL_LIBCPP17_IS_SWAPPABLE

    #if !defined(LBAL_LIBCPP17_LOGICAL_TRAITS)
      #define LBAL_LIBCPP17_LOGICAL_TRAITS 201510L
    #endif  //	LBAL_LIBCPP17_LOGICAL_TRAITS

    #if !defined(LBAL_LIBCPP17_MAKE_FROM_TUPLE)
      #define LBAL_LIBCPP17_MAKE_FROM_TUPLE 201606L
    #endif  //	LBAL_LIBCPP17_MAKE_FROM_TUPLE

    #if !defined(LBAL_LIBCPP17_MAP_TRY_EMPLACE)
      #define LBAL_LIBCPP17_MAP_TRY_EMPLACE 201411L
    #endif  //	LBAL_LIBCPP17_MAP_TRY_EMPLACE

    #if !defined(LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS)
      #define LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS 201411L
    #endif  //	LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS

    #if !defined(LBAL_LIBCPP17_NOT_FN)
      #define LBAL_LIBCPP17_NOT_FN 201603L
    #endif  //	LBAL_LIBCPP17_NOT_FN

    #if !defined(LBAL_LIBCPP17_OPTIONAL)
      #define LBAL_LIBCPP17_OPTIONAL 201603L
    #endif  //	LBAL_LIBCPP17_OPTIONAL

    #if !defined(LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL)
      #define LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL 201606L
    #endif  //	LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL

    #if !defined(LBAL_LIBCPP17_OPTIONAL_INTERFACE)
      #define LBAL_LIBCPP17_OPTIONAL_INTERFACE 201606L
    #endif  //	LBAL_LIBCPP17_OPTIONAL_INTERFACE

    #if !defined(LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS)
      #define LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS 201606L
    #endif  //	LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS

    #if !defined(LBAL_LIBCPP17_SAMPLE)
      #define LBAL_LIBCPP17_SAMPLE 201603L
    #endif  //	LBAL_LIBCPP17_SAMPLE

    #if !defined(LBAL_LIBCPP17_SCOPED_LOCK)
      #define LBAL_LIBCPP17_SCOPED_LOCK 201703L
    #endif  //	LBAL_LIBCPP17_SCOPED_LOCK

    #if !defined(LBAL_LIBCPP17_SHARED_MUTEX)
      #define LBAL_LIBCPP17_SHARED_MUTEX 201505L
    #endif  //	LBAL_LIBCPP17_SHARED_MUTEX

    #if !defined(LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE)
      #define LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE 201606L
    #endif  //	LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE

    #if !defined(LBAL_LIBCPP17_STRING_VIEW)
      #define LBAL_LIBCPP17_STRING_VIEW 201603L
    #endif  //	LBAL_LIBCPP17_STRING_VIEW

    #if !defined(LBAL_LIBCPP17_STRING_VIEW_INTERFACE)
      #define LBAL_LIBCPP17_STRING_VIEW_INTERFACE 201606L
    #endif  //	LBAL_LIBCPP17_STRING_VIEW_INTERFACE

    #if !defined(LBAL_LIBCPP17_TRANSPARENT_OPERATORS)
      #define LBAL_LIBCPP17_TRANSPARENT_OPERATORS 201510L
    #endif  //	LBAL_LIBCPP17_TRANSPARENT_OPERATORS

    #if !defined(LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES)
      #define LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES 201510L
    #endif  //	LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES

    #if !defined(LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS)
      #define LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS 201411L
    #endif  //	LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS

    #if !defined(LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE)
      #define LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE 201411L
    #endif  //	LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE

    #if !defined(LBAL_LIBCPP17_VARIANT)
      #define LBAL_LIBCPP17_VARIANT 201606L
    #endif  //	LBAL_LIBCPP17_VARIANT

    #if !defined(LBAL_LIBCPP17_VOID_T)
      #define LBAL_LIBCPP17_VOID_T 201411L
    #endif  //	LBAL_LIBCPP17_VOID_T

    #if (_LIBCPP_VERSION >= 6000)
      #if !defined(LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS)
        #define LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS 201606L
      #endif  //	LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS

      #if !defined(LBAL_LIBCPP17_LAUNDER)
        #define LBAL_LIBCPP17_LAUNDER 201606L
      #endif  //	LBAL_LIBCPP17_LAUNDER
    #endif    //	6000

    #if (_LIBCPP_VERSION >= 7000)
      #if !defined(LBAL_LIBCPP17_FILESYSTEM)
        #define LBAL_LIBCPP17_FILESYSTEM 201603L
      #endif  //	LBAL_LIBCPP17_FILESYSTEM

      #if !defined(LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED)
        #define LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED 201606L
      #endif  //	LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED

      #if !defined(LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING)
        #define LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING 201703L
      #endif  //	LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING
    #endif    //	76000

    #if (_LIBCPP_VERSION >= 8000)
      #if !defined(LBAL_LIBCPP17_NODE_EXTRACT)
        #define LBAL_LIBCPP17_NODE_EXTRACT 201606L
      #endif  //	LBAL_LIBCPP17_NODE_EXTRACT
    #endif    //	76000
  #endif      //	LBAL_CPP17_VERSION

  //	C++20 Library Features
  //	These overrides are not exhaustive; we focus specifically on features
  //	which are known to have valid implementations, but missing or incorrect
  //	SD-6 values in `<version>` for at least some iterations of libc++.
  #if LBAL_cpp_version > LBAL_CPP17_VERSION
    #if (_LIBCPP_VERSION >= 6000)
      #if !defined(LBAL_LIBCPP20_REMOVE_CVREF)
        #define LBAL_LIBCPP20_REMOVE_CVREF 201711
      #endif  //	LBAL_LIBCPP20_REMOVE_CVREF

      #if !defined(LBAL_LIBCPP20_STARTS_ENDS_WITH)
        #define LBAL_LIBCPP20_STARTS_ENDS_WITH 201711L
      #endif  //	LBAL_LIBCPP20_STARTS_ENDS_WITH

      #if !defined(LBAL_LIBCPP20_TO_ADDRESS)
        #define LBAL_LIBCPP20_TO_ADDRESS 201711L
      #endif  //	LBAL_LIBCPP20_TO_ADDRESS
    #endif    //	6000

    #if (_LIBCPP_VERSION >= 7000)
      #if !defined(LBAL_LIBCPP20_ENDIAN)
        #define LBAL_LIBCPP20_ENDIAN 201907L
      #endif  //	LBAL_LIBCPP20_ENDIAN

      //	SEEME libc++ has had the P0355R7 calendar types since 7, but not
      //	the whole paper: as of LLVM 21 it has no `parse`/`from_stream` or
      //	`clock_cast`, and its time zone database is experimental. It
      //	reports `__cpp_lib_chrono` as `201611L`, so
      //	`LBAL_LIBCPP20_CHRONO_CALENDAR` and `LBAL_LIBCPP20_CHRONO_FIXES`
      //	stay `0`; the types get their own token.
      #if !defined(LBAL_LIBCPP20_CHRONO_CALENDAR_TYPES)
        #define LBAL_LIBCPP20_CHRONO_CALENDAR_TYPES 201611L
      #endif  //	LBAL_LIBCPP20_CHRONO_CALENDAR_TYPES
    #endif    //	7000

    #if (_LIBCPP_VERSION >= 8000)
      #if !defined(LBAL_LIBCPP20_TYPE_IDENTITY)
        #define LBAL_LIBCPP20_TYPE_IDENTITY 201806L
      #endif  //	LBAL_LIBCPP20_TYPE_IDENTITY
    #endif    //	8000
  #endif      //	LBAL_CPP20_VERSION

  //	SEEME libc++ has float and double `to_chars` from 14 and `from_chars`
  //	from 20, but never defines `__cpp_lib_to_chars`, as it has no long
  //	double `from_chars`. Its availability macros, which `<version>` pulls
  //	in, say whether both work for the deployment target: on Apple
  //	platforms they live in the OS’s dylib. The `from_chars` macro only
  //	exists from libc++ 20.
  #if !defined(LBAL_LIBCPP17_TO_CHARS_FP)                                      \
      && (LBAL_cpp_version > LBAL_CPP14_VERSION)                               \
      && defined(_LIBCPP_AVAILABILITY_HAS_FROM_CHARS_FLOATING_POINT)
    #if _LIBCPP_AVAILABILITY_HAS_TO_CHARS_FLOATING_POINT                       \
        && _LIBCPP_AVAILABILITY_HAS_FROM_CHARS_FLOATING_POINT
      #define LBAL_LIBCPP17_TO_CHARS_FP 201611L
    #endif
  #endif

  //	SEEME `LBAL_LIBCPP17_TO_CHARS` is the full feature, which includes long
  //	double. libc++ lacks long double `from_chars`, so the token is only set
  //	if libc++ defines `__cpp_lib_to_chars` itself.

  //	SEEME libc++ 17 and 18 ship a working `<format>` in C++20 and later
  //	(P0645R10 and the DRs P2216R3 and P2418R2, complete from 15), but their
  //	`<version>` leaves `__cpp_lib_format` commented out; libc++ 19 is the
  //	first to define it. We use `202106L`, the value libc++ left commented
  //	out, since P2372R3, which shares `202110L` with P2418R2, isn’t done
  //	until 21; P2418R2 itself is reported through
  //	`LBAL_LIBCPP23_FORMAT_GENERATOR`. Off Apple platforms, floating-point
  //	`to_chars` is always in the library, so there’s no availability check.
  //	See libc++’s `docs/Status/Cxx20Papers.csv`.
  #if (_LIBCPP_VERSION >= 170000)                                              \
      && (_LIBCPP_VERSION < 190000)                                            \
      && (LBAL_cpp_version > LBAL_CPP17_VERSION)
    #if __has_include(<format>)
      #if !defined(LBAL_LIBCPP20_FORMAT)
        #define LBAL_LIBCPP20_FORMAT 202106L
      #endif
      #if !defined(LBAL_LIBCPP23_FORMAT)
        #define LBAL_LIBCPP23_FORMAT 202106L
      #endif
      #if !defined(LBAL_LIBCPP23_FORMAT_GENERATOR)
        #define LBAL_LIBCPP23_FORMAT_GENERATOR 202110L
      #endif
    #endif
  #endif

  //	SEEME libc++ 19 and 20 report `__cpp_lib_format` as `202110L`, but
  //	P2372R3 (locale handling in chrono formatters), which shares that value,
  //	is only complete from libc++ 21.
  #if (_LIBCPP_VERSION < 210000) && LBAL_LIBCPP23_FORMAT_LOCALE
    #undef LBAL_LIBCPP23_FORMAT_LOCALE
    #define LBAL_LIBCPP23_FORMAT_LOCALE 0
  #endif

  //	SEEME libc++ only partly implements P2693R1: `thread::id` has a
  //	formatter from libc++ 17, but there is no `<stacktrace>`, so it never
  //	defines `__cpp_lib_formatters` and `LBAL_LIBCPP23_FORMATTERS` stays `0`.
  //	The `thread::id` part gets its own token. It needs a usable `<format>`,
  //	which `LBAL_LIBCPP20_FORMAT` reflects, and thread support. No generated
  //	SD-6 mapping or header check covers this token, so we check the headers
  //	here too.
  #if !defined(LBAL_LIBCPP23_FORMATTERS_THREAD_ID)                             \
      && (LBAL_cpp_version > LBAL_CPP20_VERSION)                               \
      && (_LIBCPP_VERSION >= 170000)                                           \
      && LBAL_LIBCPP20_FORMAT                                                  \
      && !defined(_LIBCPP_HAS_NO_THREADS)                                      \
      && (!defined(_LIBCPP_HAS_THREADS) || _LIBCPP_HAS_THREADS)
    #if __has_include(<format>) && __has_include(<thread>)
      #define LBAL_LIBCPP23_FORMATTERS_THREAD_ID 202302L
    #endif
  #endif

  //	SEEME libc++ implements P2508R1 (`basic_format_string`) from 15, in C++20
  //	and later, but holds `__cpp_lib_format` at `202110L` because P2419R2,
  //	which shares `202207L`, isn’t done. `LBAL_LIBCPP20_FORMAT` says
  //	`<format>` is usable: libc++ only reports it when floating-point
  //	`to_chars` is available, since `std::format` doesn’t compile otherwise.
  #if !defined(LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING) && LBAL_LIBCPP20_FORMAT
    #define LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING 202207L
  #endif

  //	SEEME libc++ implements only the type traits from P2255R2 (from 21, when
  //	the compiler has both builtins), not the `pair`, `tuple` and `INVOKE<R>`
  //	changes, so it never defines `__cpp_lib_reference_from_temporary` and
  //	`LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY` stays `0`.
  #if !defined(LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY_TRAITS)                  \
      && (LBAL_cpp_version > LBAL_CPP20_VERSION)                               \
      && (_LIBCPP_VERSION >= 210000)                                           \
      && __has_builtin(__reference_constructs_from_temporary)                  \
      && __has_builtin(__reference_converts_from_temporary)
    #define LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY_TRAITS 202202L
  #endif

  //	SEEME libc++ only provides `std::hardware_destructive_interference_size`
  //	and `std::hardware_constructive_interference_size` when the compiler
  //	predefines `__GCC_DESTRUCTIVE_SIZE` and `__GCC_CONSTRUCTIVE_SIZE` (gcc
  //	12+, clang 19+). libc++ 17–19 define the feature macro under the same
  //	condition; newer versions use the macros unconditionally, and versions
  //	before 15 could claim the feature without providing it. So the
  //	compiler’s macros, not the library version, decide; gcc 12+ with
  //	libc++ 17 or 18 does have the feature.
  #if (                                                                        \
      (_LIBCPP_VERSION < 15000)                                                \
      || !defined(__GCC_DESTRUCTIVE_SIZE)                                      \
      || !defined(__GCC_CONSTRUCTIVE_SIZE)                                     \
  ) && LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE
    #undef LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE
    #define LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE 0
  #endif

  //  This was erroneously reported as implemented in previous versions.
  #if (_LIBCPP_VERSION < 230000)
    #if defined(LBAL_LIBCPP26_BIND_FRONT_NTTP_CALLABLES)
      #undef LBAL_LIBCPP26_BIND_FRONT_NTTP_CALLABLES
      #define LBAL_LIBCPP26_BIND_FRONT_NTTP_CALLABLES 0
    #endif  //	LBAL_LIBCPP26_BIND_FRONT_NTTP_CALLABLES
  #endif    //  230000

  #if (_LIBCPP_VERSION < 240000)
    //  `libc++` actually splits this between `std::priority_queue` (via
    //  `std::vector`) and `std::queue` (via `std::deque`) implementations, and
    //  at least as of Clng 23, only supports the former, which is split out
    //  into a proxy value as `LBAL_LIBCPP26_CONSTEXPR_QUEUE_PRIORITY_QUEUE`.
    #if defined(LBAL_LIBCPP26_CONSTEXPR_QUEUE)
      #undef LBAL_LIBCPP26_CONSTEXPR_QUEUE
      #define LBAL_LIBCPP26_CONSTEXPR_QUEUE 0
    #endif  //  LBAL_LIBCPP26_CONSTEXPR_QUEUE
  #endif    //  240000

  //	`std::result_of` was removed in C++20 (P0619R4), but
  //	`__cpp_lib_result_of_sfinae` is still advertised. libc++ only keeps
  //	it when `_LIBCPP_ENABLE_CXX20_REMOVED_TYPE_TRAITS` is defined.
  #if (LBAL_cpp_version > LBAL_CPP17_VERSION)                                  \
      && !defined(_LIBCPP_ENABLE_CXX20_REMOVED_TYPE_TRAITS)
    #if LBAL_LIBCPP14_RESULT_OF_SFINAE
      #undef LBAL_LIBCPP14_RESULT_OF_SFINAE
      #define LBAL_LIBCPP14_RESULT_OF_SFINAE 0
    #endif
  #endif
#else
  #error                                                                       \
      "lbalStandardLibraryLibCppPostInitialization.hpp was directly included with the incorrect Standard Library implementation"
#endif
