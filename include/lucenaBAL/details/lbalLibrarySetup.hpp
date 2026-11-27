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

#include <lucenaBAL/details/fragments/lbalLibrarySetup-definitions-libcpp14.inc>
#include <lucenaBAL/details/fragments/lbalLibrarySetup-definitions-libcpp17.inc>
#include <lucenaBAL/details/fragments/lbalLibrarySetup-definitions-libcpp20.inc>
#include <lucenaBAL/details/fragments/lbalLibrarySetup-definitions-libcpp23.inc>
#include <lucenaBAL/details/fragments/lbalLibrarySetup-definitions-libcpp26.inc>
#include <lucenaBAL/details/fragments/lbalLibrarySetup-definitions-libcpp2d.inc>

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

#include <lucenaBAL/details/fragments/lbalLibrarySetup-headers-cpp03.inc>

/*
  C++11 Headers

  Generally, these will always be available, but they will not necessarily be
  used by the target Standard, so we “fail on” if `__has_include` is not
  available.
*/

#include <lucenaBAL/details/fragments/lbalLibrarySetup-headers-cpp11.inc>

/*
  C++14 Headers

  Generally, these will always be available, but they will not necessarily be
  used by the target Standard, so we “fail on” if `__has_include` is not
  available.
*/

#include <lucenaBAL/details/fragments/lbalLibrarySetup-headers-cpp14.inc>

/*
  C++17 Headers

  Things start to get tricky here, as headers won’t necessarily be available
  with older library implementations, which will typically be bundled with
  compilers that do not have `__has_include`, so from here we start to “fail
  off” if we have no header detection method available.
*/

#include <lucenaBAL/details/fragments/lbalLibrarySetup-headers-cpp17.inc>

/*
  C++20 Headers

  We “fail off” if we have no header detection method available.
*/

#include <lucenaBAL/details/fragments/lbalLibrarySetup-headers-cpp20.inc>

/*
  C++23 Headers

  We “fail off” if we have no header detection method available.
*/

#include <lucenaBAL/details/fragments/lbalLibrarySetup-headers-cpp23.inc>

/*
  C++26 Headers

  We “fail off” if we have no header detection method available.
*/

#include <lucenaBAL/details/fragments/lbalLibrarySetup-headers-cpp26.inc>

/*
  C++2d Headers

  We “fail off” if we have no header detection method available.
*/

//  SEEME - bitweeder
//  No C++2d proposal adds a header yet; the C++2d header tests only check
//  headers that already exist. Include the generated
//  `lbalLibrarySetup-headers-cpp2d.inc` here once one does.

/*
  Token Tests
*/

#include <lucenaBAL/details/fragments/lbalLibrarySetup-header-tests-libcpp14.inc>
#include <lucenaBAL/details/fragments/lbalLibrarySetup-header-tests-libcpp17.inc>
#include <lucenaBAL/details/fragments/lbalLibrarySetup-header-tests-libcpp20.inc>
#include <lucenaBAL/details/fragments/lbalLibrarySetup-header-tests-libcpp23.inc>
#include <lucenaBAL/details/fragments/lbalLibrarySetup-header-tests-libcpp26.inc>
#include <lucenaBAL/details/fragments/lbalLibrarySetup-header-tests-libcpp2d.inc>

/*------------------------------------------------------------------------------
  Aggregates

  These are convenience macros that combine multiple other macros. They must be
  validated after all their constituent parts have been fully validated.
*/

//	This is an aggregate that tracks two different SD-6 macros for the purpose
//	of establishing Standard compliance. There is no single corresponding SD-6
//	macro. Note that we do not track experimental versions of the components.
#if !defined(LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS)
  #if LBAL_LIBCPP17_EXECUTION && LBAL_LIBCPP17_PARALLEL_ALGORITHM
    #define LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS 1L
  #endif
#endif  //	LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS
