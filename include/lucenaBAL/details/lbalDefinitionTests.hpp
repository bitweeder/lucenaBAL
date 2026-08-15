/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalDefinitionTests.hpp”
  Copyright © 2019-2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/

#pragma once

//	lbal
#include <lucenaBAL/lbalConfig.hpp>

#if !defined(LBAL_DETAILS_DEFINITIONS_TESTED)
  #define LBAL_DETAILS_DEFINITIONS_TESTED 1

/*------------------------------------------------------------------------------
  Definition Tests

  Note that none of the LBAL_XXX macros are set to 0 until after the
  definition tests, so it’s sufficient to simply test them for existence.
  Just to be sure, though, we make sure someone didn’t define one of these
  behind our backs, with the following exceptions:

    - LBAL_TARGET_OS_xxx should be set by the build system or in some
      similar fashion, as otherwise there may be no way to differentiate
      between certain platforms.

    - LBAL_TARGET_API_xxx can be set by the build system or in some
      similar fashion to avoid ambiguities (e.g., determine whether we’re
      targeting Carbon or Cocoa APIs deuner older MacOS X’s). It’s not
      generally necessary to do this any more.
*/

  #if !defined(LBAL_TARGET_OS_X11)                                             \
      && !defined(LBAL_TARGET_OS_MACOS)                                        \
      && !defined(LBAL_TARGET_OS_WINAPI)                                       \
      && !defined(LBAL_TARGET_OS_IOS)                                          \
      && !defined(LBAL_TARGET_OS_IOS_SIM)

    #error                                                                     \
        "A LBAL_TARGET_OS_xxx token must be defined externally at build time."
  #endif  //	LBAL_TARGET_OS check

  #if defined(LBAL_FEATURE_UTF16_FILE_SYSTEM)
    #error "Don’t define LBAL_FEATURE_UTF16_FILE_SYSTEM externally."
  #endif  //	LBAL_FEATURE_UTF16_FILE_SYSTEM

  #if defined(LBAL_NAME_COMPILER)
    #error "Don’t define LBAL_NAME_COMPILER externally."
  #endif  //	LBAL_NAME_COMPILER

  #if defined(LBAL_TARGET_COMPILER_CLANG)                                      \
      || defined(LBAL_TARGET_COMPILER_VANILLA_CLANG)                           \
      || defined(LBAL_TARGET_COMPILER_APPLE_CLANG)                             \
      || defined(LBAL_TARGET_COMPILER_GCC)                                     \
      || defined(LBAL_TARGET_COMPILER_VANILLA_GCC)                             \
      || defined(LBAL_TARGET_COMPILER_MSVC)                                    \
      || defined(LBAL_TARGET_COMPILER_VANILLA_MSVC)

    #error "Don’t define LBAL_TARGET_COMPILER_xxx externally."
  #endif  //	LBAL_TARGET_COMPILER check

  #if defined(LBAL_TARGET_CPU_X86)                                             \
      || defined(LBAL_TARGET_CPU_X86_64)                                       \
      || defined(LBAL_TARGET_CPU_IA64)                                         \
      || defined(LBAL_TARGET_CPU_ARM)                                          \
      || defined(LBAL_TARGET_CPU_ARM_64)

    #error "Don’t define LBAL_TARGET_CPU_xxx externally."
  #endif  //	LBAL_TARGET_CPU check

  #if defined(LBAL_TARGET_CPU_FAMILY_X86) || defined(LBAL_TARGET_CPU_FAMILY_ARM)

    #error "Don’t define LBAL_TARGET_CPU_xxx_FAMILY externally."
  #endif  //	LBAL_TARGET_CPU_FAMILY check

  #if defined(LBAL_TARGET_VEC_SSE)                                             \
      || defined(LBAL_TARGET_VEC_SSE2)                                         \
      || defined(LBAL_TARGET_VEC_SSE3)                                         \
      || defined(LBAL_TARGET_VEC_SSE41)                                        \
      || defined(LBAL_TARGET_VEC_SSE42)                                        \
      || defined(LBAL_TARGET_VEC_AVX)                                          \
      || defined(LBAL_TARGET_VEC_AVX2)

    #error "Don’t define LBAL_TARGET_VEC_xxx externally."
  #endif  //	LBAL_TARGET_VEC check

  #if defined(LBAL_TARGET_RT_LITTLE_ENDIAN)                                    \
      || defined(LBAL_TARGET_RT_BIG_ENDIAN)                                    \
      || defined(LBAL_TARGET_RT_32_BIT)                                        \
      || defined(LBAL_TARGET_RT_64_BIT)                                        \
      || defined(LBAL_TARGET_RT_COFF)                                          \
      || defined(LBAL_TARGET_RT_ELF)                                           \
      || defined(LBAL_TARGET_RT_MACHO)                                         \
      || defined(LBAL_TARGET_RT_WASM)

    #error "Don’t define LBAL_TARGET_RT_xxx externally."
  #endif  //	LBAL_TARGET_RT check

  #if defined(LBAL_TYPE_HAS_INT64)                                             \
      || defined(LBAL_TYPE_HAS_INT128)                                         \
      || defined(LBAL_TYPE_EXACT_WIDTH_INTEGERS)                               \
      || defined(LBAL_TYPE_DOUBLE_GT_FLOAT)                                    \
      || defined(LBAL_TYPE_LONG_DOUBLE_GT_DOUBLE)                              \
      || defined(LBAL_TYPE_WCHAR_T_IS_16_BITS)

    #error "Don’t define LBAL_TYPE_xxx externally."
  #endif  //	LBAL_TYPE check

  #if defined(LBAL_CPP03_EXCEPTIONS) || defined(LBAL_CPP03_RTTI)

    #error "Don’t define LBAL_CPP03_xxx externally."
  #endif  //	LBAL_CPP03 check

  #if defined(LBAL_CPP11_ALIAS_TEMPLATES)                                      \
      || defined(LBAL_CPP11_ATTRIBUTE_CARRIES_DEPENDENCY)                      \
      || defined(LBAL_CPP11_ATTRIBUTE_NORETURN)                                \
      || defined(LBAL_CPP11_ATTRIBUTES)                                        \
      || defined(LBAL_CPP11_CONSTEXPR)                                         \
      || defined(LBAL_CPP11_DECLTYPE)                                          \
      || defined(LBAL_CPP11_DELEGATING_CONSTRUCTORS)                           \
      || defined(LBAL_CPP11_INHERITING_CONSTRUCTORS)                           \
      || defined(LBAL_CPP11_INITIALIZER_LISTS)                                 \
      || defined(LBAL_CPP11_LAMBDAS)                                           \
      || defined(LBAL_CPP11_NSDMI)                                             \
      || defined(LBAL_CPP11_RANGE_BASED_FOR)                                   \
      || defined(LBAL_CPP11_RAW_STRINGS)                                       \
      || defined(LBAL_CPP11_REF_QUALIFIERS)                                    \
      || defined(LBAL_CPP11_RVALUE_REFERENCES)                                 \
      || defined(LBAL_CPP11_STATIC_ASSERT)                                     \
      || defined(LBAL_CPP11_THREADSAFE_STATIC_INIT)                            \
      || defined(LBAL_CPP11_UNICODE_CHARACTERS)                                \
      || defined(LBAL_CPP11_UNICODE_LITERALS)                                  \
      || defined(LBAL_CPP11_USER_DEFINED_LITERALS)                             \
      || defined(LBAL_CPP11_VARIADIC_TEMPLATES)

    #error "Don’t define LBAL_CPP11_xxx externally."
  #endif  //	LBAL_CPP11 check

  #if defined(LBAL_CPP14_AGGREGATE_NSDMI)                                      \
      || defined(LBAL_CPP14_ATTRIBUTE_DEPRECATED)                              \
      || defined(LBAL_CPP14_BINARY_LITERALS)                                   \
      || defined(LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS)                     \
      || defined(LBAL_CPP14_DECLTYPE_AUTO)                                     \
      || defined(LBAL_CPP14_GENERIC_LAMBDAS)                                   \
      || defined(LBAL_CPP14_INIT_CAPTURES)                                     \
      || defined(LBAL_CPP14_RETURN_TYPE_DEDUCTION)                             \
      || defined(LBAL_CPP14_SIZED_DEALLOCATION)                                \
      || defined(LBAL_CPP14_VARIABLE_TEMPLATES)
    #error "Don’t define LBAL_CPP14_xxx externally."
  #endif  //	LBAL_CPP14 check

  #if defined(LBAL_CPP17_AGGREGATE_BASES)                                      \
      || defined(LBAL_CPP17_ALIGNED_NEW)                                       \
      || defined(LBAL_CPP17_ATTRIBUTE_FALLTHROUGH)                             \
      || defined(LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED)                            \
      || defined(LBAL_CPP17_ATTRIBUTE_NODISCARD)                               \
      || defined(LBAL_CPP17_CAPTURE_STAR_THIS)                                 \
      || defined(LBAL_CPP17_CONSTEXPR_LAMBDA)                                  \
      || defined(LBAL_CPP17_DEDUCTION_GUIDES)                                  \
      || defined(LBAL_CPP17_DEDUCTION_GUIDES_DR)                               \
      || defined(LBAL_CPP17_DEDUCTION_GUIDES_NB)                               \
      || defined(LBAL_CPP17_ENUMERATOR_ATTRIBUTES)                             \
      || defined(LBAL_CPP17_FOLD_EXPRESSIONS)                                  \
      || defined(LBAL_CPP17_FOLD_EXPRESSIONS_REVISED)                          \
      || defined(LBAL_CPP17_GUARANTEED_COPY_ELISION)                           \
      || defined(LBAL_CPP17_HEX_FLOAT)                                         \
      || defined(LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED)                   \
      || defined(LBAL_CPP17_INLINE_VARIABLES)                                  \
      || defined(LBAL_CPP17_NAMESPACE_ATTRIBUTES)                              \
      || defined(LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE)                            \
      || defined(LBAL_CPP17_NONTYPE_TEMPLATE_ARGS)                             \
      || defined(LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO)                   \
      || defined(LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED)                       \
      || defined(LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE)                          \
      || defined(LBAL_CPP17_STRUCTURED_BINDINGS)                               \
      || defined(LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS)                            \
      || defined(LBAL_CPP17_VARIADIC_USING)
    #error "Don’t define LBAL_CPP17_xxx externally."
  #endif  //	LBAL_CPP17 check

  #if defined(LBAL_CPP20_AGGREGATE_PAREN_INIT)                                          \
      || defined(LBAL_CPP20_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS)                           \
      || defined(LBAL_CPP20_ATTRIBUTE_LIKELY)                                           \
      || defined(LBAL_CPP20_ATTRIBUTE_NODISCARD_EXPANDED)                               \
      || defined(LBAL_CPP20_ATTRIBUTE_NO_UNIQUE_ADDRESS)                                \
      || defined(LBAL_CPP20_ATTRIBUTE_UNLIKELY)                                         \
      || defined(LBAL_CPP20_ATTRIBUTES_LIKELY_AND_UNLIKELY)                             \
      || defined(LBAL_CPP20_CHAR8_T)                                                    \
      || defined(LBAL_CPP20_CONCEPTS)                                                   \
      || defined(LBAL_CPP20_CONCEPTS_RESPECIFY_RETURN_TYPE_REQUIREMENTS)                \
      || defined(LBAL_CPP20_CONCEPTS_REFINE_RETURN_TYPE_REQUIREMENTS)                   \
      || defined(                                                                       \
          LBAL_CPP20_CONCEPTS_CONDITIONALLY_TRIVIAL_SPECIAL_MEMBER_FUNCTIONS            \
      )                                                                                 \
      || defined(LBAL_CPP20_CONDITIONAL_EXPLICIT)                                       \
      || defined(LBAL_CPP20_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS)                    \
      || defined(LBAL_CPP20_CONSTEVAL)                                                  \
      || defined(LBAL_CPP20_CONSTEXPR_CHANGE_ACTIVE_UNION_MEMBER)                       \
      || defined(LBAL_CPP20_CONSTEXPR_DYNAMIC_ALLOC)                                    \
      || defined(LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM)                             \
      || defined(LBAL_CPP20_CONSTEXPR_IN_DECLTYPE)                                      \
      || defined(LBAL_CPP20_CONSTEXPR_INTRINSICS)                                       \
      || defined(LBAL_CPP20_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION)                   \
      || defined(LBAL_CPP20_CONSTEXPR_TRY_CATCH)                                        \
      || defined(LBAL_CPP20_CONSTEXPR_UNION_ALTERATION)                                 \
      || defined(LBAL_CPP20_CONSTEXPR_VIRTUAL_FUNCTION)                                 \
      || defined(LBAL_CPP20_CONSTINIT)                                                  \
      || defined(LBAL_CPP20_DEDUCTION_GUIDES_FOR_AGGREGATES)                            \
      || defined(                                                                       \
          LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS             \
      )                                                                                 \
      || defined(LBAL_CPP20_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS)                 \
      || defined(LBAL_CPP20_DESIGNATED_INITIALIZERS)                                    \
      || defined(LBAL_CPP20_DESTROYING_DELETE)                                          \
      || defined(LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST)                    \
      || defined(LBAL_CPP20_IMPL_COROUTINE)                                             \
      || defined(LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION)                               \
      || defined(LBAL_CPP20_INIT_STATEMENTS_FOR_RANGE_BASED_FOR)                        \
      || defined(                                                                       \
          LBAL_CPP20_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION \
      )                                                                                 \
      || defined(LBAL_CPP20_INTEGRATING_OUR_FEATURE_TEST_MACROS)                        \
      || defined(LBAL_CPP20_MODULES)                                                    \
      || defined(LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FIXES)                                \
      || defined(LBAL_CPP20_NONTYPE_TEMPLATE_PARAMETER_CLASS)                           \
      || defined(LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR)                              \
      || defined(LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_EQUALITY_FIX)                 \
      || defined(LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_TUNEUP)                       \
      || defined(LBAL_CPP20_TYPENAME_OPTIONAL)                                          \
      || defined(LBAL_CPP20_USING_ENUM)                                                 \
      || defined(LBAL_CPP20_VA_OPT)

    #error "Don’t define LBAL_CPP20_xxx externally."
  #endif  //	LBAL_CPP20 check

  #if defined(LBAL_CPP23_ATTRIBUTE_ASSUME)                                     \
      || defined(LBAL_CPP23_AUTO_CAST)                                         \
      || defined(LBAL_CPP23_CHAR8_T_COMPATIBILITY)                             \
      || defined(LBAL_CPP23_CONSTEVAL_PROPAGATE_UP)                            \
      || defined(LBAL_CPP23_CONSTEXPR_NON_LITERAL_VARIABLES)                   \
      || defined(LBAL_CPP23_CONSTEXPR_PERMIT_STATIC_CONSTEXPR)                 \
      || defined(LBAL_CPP23_CONSTEXPR_RELAX_RESTRICTIONS)                      \
      || defined(LBAL_CPP23_DEDUCTION_GUIDES_FROM_INHERITED_CONSTRUCTORS)      \
      || defined(LBAL_CPP23_EXPLICIT_THIS_PARAMETER)                           \
      || defined(LBAL_CPP23_IF_CONSTEVAL)                                      \
      || defined(LBAL_CPP23_IMPLICIT_MOVE)                                     \
      || defined(LBAL_CPP23_MULTIDIMENSIONAL_SUBSCRIPT)                        \
      || defined(LBAL_CPP23_MULTIDIMENSIONAL_SUBSCRIPT_STATIC)                 \
      || defined(LBAL_CPP23_NAMED_CHARACTER_ESCAPES)                           \
      || defined(LBAL_CPP23_RANGE_BASED_FOR_TEMPORARIES)                       \
      || defined(LBAL_CPP23_SIZE_T_SUFFIX)                                     \
      || defined(LBAL_CPP23_STATIC_CALL_OPERATOR)

    #error "Don’t define LBAL_CPP23_xxx externally."
  #endif  //	LBAL_CPP23 check

  #if defined(LBAL_CPP26_CONSTEXPR_CAST_FROM_VOID_STAR)                        \
      || defined(LBAL_CPP26_CONSTEXPR_EXCEPTIONS)                              \
      || defined(LBAL_CPP26_CONSTEXPR_PLACEMENT_NEW)                           \
      || defined(LBAL_CPP26_CONSTEXPR_VIRTUAL_INHERITANCE)                     \
      || defined(LBAL_CPP26_CONTRACTS)                                         \
      || defined(LBAL_CPP26_DELETED_FUNCTION)                                  \
      || defined(LBAL_CPP26_EXPANSION_STATEMENTS)                              \
      || defined(LBAL_CPP26_IMPL_REFLECTION)                                   \
      || defined(LBAL_CPP26_PACK_INDEXING)                                     \
      || defined(LBAL_CPP26_PLACEHOLDER_VARIABLES)                             \
      || defined(LBAL_CPP26_STATIC_ASSERT_USER_MESSAGE)                        \
      || defined(LBAL_CPP26_STRUCTURED_BINDINGS_ATTRIBUTES)                    \
      || defined(LBAL_CPP26_STRUCTURED_BINDINGS_PACK)                          \
      || defined(LBAL_CPP26_TEMPLATE_PARAMETERS)                               \
      || defined(LBAL_CPP26_TRIVIAL_UNION)                                     \
      || defined(LBAL_CPP26_VARIADIC_FRIEND)

    #error "Don’t define LBAL_CPP26_xxx externally."
  #endif  //	LBAL_CPP26 check

  #if defined(LBAL_CPPTS_ATTRIBUTE_ASSERT)                                     \
      || defined(LBAL_CPPTS_ATTRIBUTE_ENSURES)                                 \
      || defined(LBAL_CPPTS_ATTRIBUTE_EXPECTS)                                 \
      || defined(LBAL_CPPTS_CONTRACTS)
    #error "Don’t define LBAL_CPPTS_xxx externally."
  #endif  //	LBAL_CPPTS check

  #if defined(LBAL_CPP14_AGGREGATE_NSDMI)                                      \
      || defined(LBAL_CPP14_ATTRIBUTE_DEPRECATED)                              \
      || defined(LBAL_CPP14_BINARY_LITERALS)                                   \
      || defined(LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS)                     \
      || defined(LBAL_CPP14_DECLTYPE_AUTO)                                     \
      || defined(LBAL_CPP14_GENERIC_LAMBDAS)                                   \
      || defined(LBAL_CPP14_INIT_CAPTURES)                                     \
      || defined(LBAL_CPP14_RETURN_TYPE_DEDUCTION)                             \
      || defined(LBAL_CPP14_SIZED_DEALLOCATION)                                \
      || defined(LBAL_CPP14_VARIABLE_TEMPLATES)
    #error "Don’t define LBAL_CPP14_xxx externally."
  #endif  //	LBAL_CPP14 check

  #if defined(LBAL_HAS_HEADER_ALGORITHM)                                       \
      || defined(LBAL_HAS_HEADER_BITSET)                                       \
      || defined(LBAL_HAS_HEADER_CASSERT)                                      \
      || defined(LBAL_HAS_HEADER_CCTYPE)                                       \
      || defined(LBAL_HAS_HEADER_CFLOAT)                                       \
      || defined(LBAL_HAS_HEADER_CLIMITS)                                      \
      || defined(LBAL_HAS_HEADER_CLOCALE)                                      \
      || defined(LBAL_HAS_HEADER_CMATH)                                        \
      || defined(LBAL_HAS_HEADER_COMPLEX)                                      \
      || defined(LBAL_HAS_HEADER_CSETJMP)                                      \
      || defined(LBAL_HAS_HEADER_CSIGNAL)                                      \
      || defined(LBAL_HAS_HEADER_CSTDARG)                                      \
      || defined(LBAL_HAS_HEADER_CSTDDEF)                                      \
      || defined(LBAL_HAS_HEADER_CSTDIO)                                       \
      || defined(LBAL_HAS_HEADER_CSTDLIB)                                      \
      || defined(LBAL_HAS_HEADER_CSTRING)                                      \
      || defined(LBAL_HAS_HEADER_CTIME)                                        \
      || defined(LBAL_HAS_HEADER_DEQUE)                                        \
      || defined(LBAL_HAS_HEADER_EXCEPTION)                                    \
      || defined(LBAL_HAS_HEADER_FSTREAM)                                      \
      || defined(LBAL_HAS_HEADER_FUNCTIONAL)                                   \
      || defined(LBAL_HAS_HEADER_IOMANIP)                                      \
      || defined(LBAL_HAS_HEADER_IOS)                                          \
      || defined(LBAL_HAS_HEADER_IOSFWD)                                       \
      || defined(LBAL_HAS_HEADER_IOSTREAM)                                     \
      || defined(LBAL_HAS_HEADER_ISTREAM)                                      \
      || defined(LBAL_HAS_HEADER_ITERATOR)                                     \
      || defined(LBAL_HAS_HEADER_LIMITS)                                       \
      || defined(LBAL_HAS_HEADER_LIST)                                         \
      || defined(LBAL_HAS_HEADER_LOCALE)                                       \
      || defined(LBAL_HAS_HEADER_MAP)                                          \
      || defined(LBAL_HAS_HEADER_MEMORY)                                       \
      || defined(LBAL_HAS_HEADER_NEW)                                          \
      || defined(LBAL_HAS_HEADER_NUMERIC)                                      \
      || defined(LBAL_HAS_HEADER_OSTREAM)                                      \
      || defined(LBAL_HAS_HEADER_QUEUE)                                        \
      || defined(LBAL_HAS_HEADER_SET)                                          \
      || defined(LBAL_HAS_HEADER_SSTREAM)                                      \
      || defined(LBAL_HAS_HEADER_STACK)                                        \
      || defined(LBAL_HAS_HEADER_STDEXCEPT)                                    \
      || defined(LBAL_HAS_HEADER_STREAMBUF)                                    \
      || defined(LBAL_HAS_HEADER_STRING)                                       \
      || defined(LBAL_HAS_HEADER_UTILITY)                                      \
      || defined(LBAL_HAS_HEADER_VALARRAY)                                     \
      || defined(LBAL_HAS_HEADER_VECTOR)
    #error "Don’t define LBAL_HAS_HEADER_xxx externally."
  #endif  //	LBAL_HAS_HEADER_xxx C++98/03 check

  #if defined(LBAL_HAS_HEADER_ARRAY)                                           \
      || defined(LBAL_HAS_HEADER_ATOMIC)                                       \
      || defined(LBAL_HAS_HEADER_CFENV)                                        \
      || defined(LBAL_HAS_HEADER_CHRONO)                                       \
      || defined(LBAL_HAS_HEADER_CINTTYPES)                                    \
      || defined(LBAL_HAS_HEADER_CONDITION_VARIABLE)                           \
      || defined(LBAL_HAS_HEADER_CSTDINT)                                      \
      || defined(LBAL_HAS_HEADER_CUCHAR)                                       \
      || defined(LBAL_HAS_HEADER_FORWARD_LIST)                                 \
      || defined(LBAL_HAS_HEADER_FUTURE)                                       \
      || defined(LBAL_HAS_HEADER_INITIALIZER_LIST)                             \
      || defined(LBAL_HAS_HEADER_MUTEX)                                        \
      || defined(LBAL_HAS_HEADER_RANDOM)                                       \
      || defined(LBAL_HAS_HEADER_RATIO)                                        \
      || defined(LBAL_HAS_HEADER_REGEX)                                        \
      || defined(LBAL_HAS_HEADER_SCOPED_ALLOCATOR)                             \
      || defined(LBAL_HAS_HEADER_SYSTEM_ERROR)                                 \
      || defined(LBAL_HAS_HEADER_THREAD)                                       \
      || defined(LBAL_HAS_HEADER_TUPLE)                                        \
      || defined(LBAL_HAS_HEADER_TYPE_TRAITS)                                  \
      || defined(LBAL_HAS_HEADER_TYPEINDEX)                                    \
      || defined(LBAL_HAS_HEADER_UNORDERED_MAP)                                \
      || defined(LBAL_HAS_HEADER_UNORDERED_SET)                                \
      || defined(LBAL_HAS_HEADER_CSTDALIGN)                                    \
      || defined(LBAL_HAS_HEADER_CSTDBOOL)
    #error "Don’t define LBAL_HAS_HEADER_xxx externally."
  #endif  //	LBAL_HAS_HEADER_xxx C++11 check

  #if defined(LBAL_HAS_HEADER_SHARED_MUTEX)
    #error "Don’t define LBAL_HAS_HEADER_xxx externally."
  #endif  //	LBAL_HAS_HEADER_xxx C++14 check

  #if defined(LBAL_HAS_HEADER_ANY)                                             \
      || defined(LBAL_HAS_HEADER_CHARCONV)                                     \
      || defined(LBAL_HAS_HEADER_EXECUTION)                                    \
      || defined(LBAL_HAS_HEADER_FILESYSTEM)                                   \
      || defined(LBAL_HAS_HEADER_EXPERIMENTAL_FILESYSTEM)                      \
      || defined(LBAL_HAS_HEADER_MEMORY_RESOURCE)                              \
      || defined(LBAL_HAS_HEADER_OPTIONAL)                                     \
      || defined(LBAL_HAS_HEADER_STRING_VIEW)                                  \
      || defined(LBAL_HAS_HEADER_VARIANT)
    #error "Don’t define LBAL_HAS_HEADER_xxx externally."
  #endif  //	LBAL_HAS_HEADER_xxx C++17 check

  #if defined(LBAL_HAS_HEADER_BARRIER)                                         \
      || defined(LBAL_HAS_HEADER_BIT)                                          \
      || defined(LBAL_HAS_HEADER_COMPARE)                                      \
      || defined(LBAL_HAS_HEADER_CONCEPTS)                                     \
      || defined(LBAL_HAS_HEADER_EXPERIMENTAL_CONCEPTS)                        \
      || defined(LBAL_HAS_HEADER_COROUTINE)                                    \
      || defined(LBAL_HAS_HEADER_EXPERIMENTAL_COROUTINE)                       \
      || defined(LBAL_HAS_HEADER_FORMAT)                                       \
      || defined(LBAL_HAS_HEADER_LATCH)                                        \
      || defined(LBAL_HAS_HEADER_NUMBERS)                                      \
      || defined(LBAL_HAS_HEADER_RANGES)                                       \
      || defined(LBAL_HAS_HEADER_SEMAPHORE)                                    \
      || defined(LBAL_HAS_HEADER_SOURCE_LOCATION)                              \
      || defined(LBAL_HAS_HEADER_SPAN)                                         \
      || defined(LBAL_HAS_HEADER_STOP_TOKEN)                                   \
      || defined(LBAL_HAS_HEADER_SYNCSTREAM)                                   \
      || defined(LBAL_HAS_HEADER_VERSION)
    #error "Don’t define LBAL_HAS_HEADER_xxx externally."
  #endif  //	LBAL_HAS_HEADER_xxx C++20 check

  #if defined(LBAL_HAS_HEADER_EXPECTED)                                        \
      || defined(LBAL_HAS_HEADER_FLAT_MAP)                                     \
      || defined(LBAL_HAS_HEADER_FLAT_SET)                                     \
      || defined(LBAL_HAS_HEADER_GENERATOR)                                    \
      || defined(LBAL_HAS_HEADER_MDSPAN)                                       \
      || defined(LBAL_HAS_HEADER_PRINT)                                        \
      || defined(LBAL_HAS_HEADER_SPANSTREAM)                                   \
      || defined(LBAL_HAS_HEADER_STACKTRACE)                                   \
      || defined(LBAL_HAS_HEADER_STDATOMIC_H)                                  \
      || defined(LBAL_HAS_HEADER_STDFLOAT)
    #error "Don’t define LBAL_HAS_HEADER_xxx externally."
  #endif  //	LBAL_HAS_HEADER_xxx C++23 check

  #if defined(LBAL_HAS_HEADER_DEBUGGING)                                       \
      || defined(LBAL_HAS_HEADER_HAZARD_POINTER)                               \
      || defined(LBAL_HAS_HEADER_HIVE)                                         \
      || defined(LBAL_HAS_HEADER_INPLACE_VECTOR)                               \
      || defined(LBAL_HAS_HEADER_LINALG)                                       \
      || defined(LBAL_HAS_HEADER_RCU)                                          \
      || defined(LBAL_HAS_HEADER_SIMD)                                         \
      || defined(LBAL_HAS_HEADER_CONTRACTS)                                    \
      || defined(LBAL_HAS_HEADER_TEXT_ENCODING)
    #error "Don’t define LBAL_HAS_HEADER_xxx externally."
  #endif  //	LBAL_HAS_HEADER_xxx C++26 check

  #if defined(LBAL_C99_PREPROCESSOR)
    #error "Don’t define LBAL_C99_xxx externally."
  #endif  //	LBAL_C99 check

  #if defined(LBAL_CLASS_FORCE_EBCO)
    #error "Don’t define LBAL_CLASS_xxx externally."
  #endif  //	LBAL_CLASS_xxx check

  #if defined(LBAL_FUNC_CALL_C)                                                \
      || defined(LBAL_FUNC_CALL_STD)                                           \
      || defined(LBAL_FUNC_CALLBACK_C)                                         \
      || defined(LBAL_FUNC_CALLBACK_STD)

    #error "Don’t define LBAL_FUNC_xxx externally."
  #endif  //	LBAL_FUNC_xxx check

  #if defined(LBAL_DIAGNOSTIC_PUSH)                                            \
      || defined(LBAL_DIAGNOSTIC_POP)                                          \
      || defined(LBAL_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS)

    #error "Don’t define LBAL_DIAGNOSTIC_xxx externally."
  #endif  //	LBAL_DIAGNOSTIC_xxx checks

  #if defined(LBAL_PRAGMA)
    #error "Don’t define LBAL_PRAGMA_xxx externally."
  #endif  //	LBAL_PRAGMA check

  #if defined(LBAL_CPP_WARNING)
    #error "Don’t define LBAL_CPP_WARNING externally."
  #endif  //	LBAL_CPP_WARNING check

  #if defined(LBAL_HINT_likely) || defined(LBAL_HINT_unlikely)

    #error "Don’t define LBAL_BUILTIN_xxx externally."
  #endif  //	LBAL_BUILTIN_xxx check

/*
  SEEME - bitweeder
  This section is fairly limited since `LBAL_LIBCPP` tokens _can_ be
  legitimately set elsewhere, typically because of platform or compiler
  limitations.
*/

  #if defined(LBAL_NAME_STANDARD_LIBRARY)
    #error "Don’t define LBAL_NAME_STANDARD_LIBRARY externally."
  #endif  //	LBAL_NAME_STANDARD_LIBRARY

  #if defined(LBAL_TARGET_STANDARD_LIBRARY_APPLE_LIBCPP)                       \
      || defined(LBAL_TARGET_STANDARD_LIBRARY_LIBCPP)                          \
      || defined(LBAL_TARGET_STANDARD_LIBRARY_MSVC)                            \
      || defined(LBAL_TARGET_STANDARD_LIBRARY_LIBSTDCPP)                       \
      || defined(LBAL_TARGET_STANDARD_LIBRARY_STDLIBCPP)

    #error "Don’t define LBAL_TARGET_STANDARD_LIBRARY_xxx externally."
  #endif  //	LBAL_TARGET_STANDARD_LIBRARY check

#endif  //	LBAL_DETAILS_DEFINITIONS_TESTED
