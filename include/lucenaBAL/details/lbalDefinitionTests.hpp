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

  //	Language feature tokens, by Standard
  #include <lucenaBAL/details/fragments/lbalDefinitionTests-cpp03.inc>
  #include <lucenaBAL/details/fragments/lbalDefinitionTests-cpp11.inc>
  #include <lucenaBAL/details/fragments/lbalDefinitionTests-cpp14.inc>
  #include <lucenaBAL/details/fragments/lbalDefinitionTests-cpp17.inc>
  #include <lucenaBAL/details/fragments/lbalDefinitionTests-cpp20.inc>
  #include <lucenaBAL/details/fragments/lbalDefinitionTests-cpp23.inc>
  #include <lucenaBAL/details/fragments/lbalDefinitionTests-cpp26.inc>
  #include <lucenaBAL/details/fragments/lbalDefinitionTests-cpp2d.inc>

  #if defined(LBAL_CPPTS_ATTRIBUTE_ASSERT)                                     \
      || defined(LBAL_CPPTS_ATTRIBUTE_ENSURES)                                 \
      || defined(LBAL_CPPTS_ATTRIBUTE_EXPECTS)                                 \
      || defined(LBAL_CPPTS_CONTRACTS)
    #error "Don’t define LBAL_CPPTS_xxx externally."
  #endif  //	LBAL_CPPTS check

  //	Header availability tokens, by Standard
  #include <lucenaBAL/details/fragments/lbalDefinitionTests-headers-cpp03.inc>
  #include <lucenaBAL/details/fragments/lbalDefinitionTests-headers-cpp11.inc>
  #include <lucenaBAL/details/fragments/lbalDefinitionTests-headers-cpp14.inc>
  #include <lucenaBAL/details/fragments/lbalDefinitionTests-headers-cpp17.inc>
  #include <lucenaBAL/details/fragments/lbalDefinitionTests-headers-cpp20.inc>
  #include <lucenaBAL/details/fragments/lbalDefinitionTests-headers-cpp23.inc>
  #include <lucenaBAL/details/fragments/lbalDefinitionTests-headers-cpp26.inc>

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
