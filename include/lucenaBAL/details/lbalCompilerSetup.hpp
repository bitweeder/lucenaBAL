/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalCompilerSetup.hpp”
  Copyright © 2007-2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#pragma once

//	lbal
#include <lucenaBAL/lbalConfig.hpp>

#include <lucenaBAL/details/lbalDetectCompiler.hpp>
#include <lucenaBAL/details/lbalKnownVersions.hpp>

/*------------------------------------------------------------------------------
  Compiler-specific Pre-initialization
*/

#if LBAL_TARGET_COMPILER_APPLE_CLANG
  #include <lucenaBAL/details/compilers/lbalAppleClangInitialization.hpp>
#elif LBAL_TARGET_COMPILER_VANILLA_CLANG
  #include <lucenaBAL/details/compilers/lbalClangInitialization.hpp>
#elif LBAL_TARGET_COMPILER_VANILLA_GCC
  #include <lucenaBAL/details/compilers/lbalGCCInitialization.hpp>
#elif LBAL_TARGET_COMPILER_VANILLA_MSVC
  #include <lucenaBAL/details/compilers/lbalMSVCInitialization.hpp>
#else
  #error "Unsupported compiler"
#endif

/*------------------------------------------------------------------------------
  Common Compiler Initialization

  Perform feature tests based on SD-6 macro definitions. Note that token
  values may be overridden during initialization by the compiler, so we
  explicitly check that the tokens are undefined before we set them, as we
  otherwise can’t know if a given token was set during the initialization
  phase.

  SEEME - bitweeder
  Implicit in these tests is that if an SD-6 macro is defined, it is assumed
  the feature is and should be available. Specifically, we don’t perform
  Standard version tests here to ensure that features are constrained to their
  associated C++ dialects. In a situation where a compiler is known to
  incorrectly define a macro when a feature is actually unavailable—even as a
  back-port—we’ll set our own tokens correctly during compiler initialization
  before we ever get here. This approach allows features to be made available
  as extensions or as previews in earlier Standard implementations.

  SEEME - bitweeder
  Note that tokens may not necessarily be initialized after these tests
  complete; they may subsequently be assigned a value during the compiler’s
  post-initialization phase, or will otherwise be explicitly `0`-initialized at
  the end of feature setup.

  SEEME - bitweeder
  The letter of the C++ attributes proposal disallows the use of
  __has_cpp_attribute in contexts other than preprocessor conditionals; MSVC
  honors this, though other compilers generally do not. We adhere to the
  proposal, even though it will make tracking future iterations on existing
  attributes more convoluted.
*/

#include <lucenaBAL/details/fragments/lbalCompilerSetup-definitions-cpp03.inc>
#include <lucenaBAL/details/fragments/lbalCompilerSetup-definitions-cpp11.inc>
#include <lucenaBAL/details/fragments/lbalCompilerSetup-definitions-cpp14.inc>
#include <lucenaBAL/details/fragments/lbalCompilerSetup-definitions-cpp17.inc>
#include <lucenaBAL/details/fragments/lbalCompilerSetup-definitions-cpp20.inc>
#include <lucenaBAL/details/fragments/lbalCompilerSetup-definitions-cpp23.inc>
#include <lucenaBAL/details/fragments/lbalCompilerSetup-definitions-cpp26.inc>
#include <lucenaBAL/details/fragments/lbalCompilerSetup-definitions-cpp2d.inc>

/*------------------------------------------------------------------------------
  Compiler-specific Post-initialization
*/

#if LBAL_TARGET_COMPILER_APPLE_CLANG
  #include <lucenaBAL/details/compilers/lbalAppleClangPostInitialization.hpp>
#elif LBAL_TARGET_COMPILER_VANILLA_CLANG
  #include <lucenaBAL/details/compilers/lbalClangPostInitialization.hpp>
#elif LBAL_TARGET_COMPILER_VANILLA_GCC
  #include <lucenaBAL/details/compilers/lbalGCCPostInitialization.hpp>
#elif LBAL_TARGET_COMPILER_VANILLA_MSVC
  #include <lucenaBAL/details/compilers/lbalMSVCPostInitialization.hpp>
#else
  #error "Unsupported compiler"
#endif

/*------------------------------------------------------------------------------
  Set up the CPU name.
*/

#if LBAL_TARGET_CPU_ARM_64
  #define LBAL_NAME_TARGET_CPU u8"ARM64"
#elif LBAL_TARGET_CPU_ARM
  #define LBAL_NAME_TARGET_CPU u8"ARM"
#elif LBAL_TARGET_CPU_IA64
  #define LBAL_NAME_TARGET_CPU u8"ia64"
#elif LBAL_TARGET_CPU_X86_64
  #define LBAL_NAME_TARGET_CPU u8"x86_64"
#elif LBAL_TARGET_CPU_X86
  #define LBAL_NAME_TARGET_CPU u8"i386"
#endif

/*------------------------------------------------------------------------------
  Aggregates

  These are convenience macros that combine multiple other macros. They must be
  validated after all their constituent parts have been fully validated.
*/

#if !defined(LBAL_CPP20_ATTRIBUTES_LIKELY_AND_UNLIKELY)
  #if LBAL_CPP20_ATTRIBUTE_LIKELY && LBAL_CPP20_ATTRIBUTE_UNLIKELY
    #define LBAL_CPP20_ATTRIBUTES_LIKELY_AND_UNLIKELY 1L
  #endif
#endif  //	LBAL_CPP20_ATTRIBUTES_LIKELY_AND_UNLIKELY
