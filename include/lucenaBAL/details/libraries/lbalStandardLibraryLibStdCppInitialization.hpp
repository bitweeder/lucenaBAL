/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalStandardLibraryLibStdCppInitialization.hpp”
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
#include <lucenaBAL/details/lbalVersionSetup.hpp>

/*------------------------------------------------------------------------------
  libstdc++ Standard Library

  SEEME - bitweeder
  One source of aggravation in libstdc++ is that there is no simple way to
  figure out what version of the library you are using. `__GLIBCXX__` is a
  release date, which can be interleaved across versions of the library
  depending on whether there are minor releases and bug fixes. We are forced to
  use `__GNUC__` as a proxy, which is not totally unreasonable, as long as the
  user hasn’t done something pathological like using an old libstdc++
  implementation with a new compiler.
*/

#if LBAL_TARGET_STANDARD_LIBRARY_LIBSTDCPP
/*
  libstdc++ has had a `<version> header since gcc 9; gcc has had support
  for `__has_include` since version 5. Therefor, we don’t worry about not
  being able to detect whether or not `<version>` exists in any iteration
  of libstdc++ that would actually have it.
*/

  #if (__GNUC__ >= 8)
    //	SEEME - bitweeder
    //	Only ints are supported; floats are forthcoming. libstdc++ might be a
    //	little too optimistic about its level of support.
    #if !defined(LBAL_LIBCPP17_TO_CHARS_INTEGER)
      #if __has_include(<charconv>)
        #if __cpp_lib_to_chars
          #define LBAL_LIBCPP17_TO_CHARS_INTEGER __cpp_lib_to_chars
        #elif (LBAL_cpp_version > LBAL_CPP14_VERSION)
          #define LBAL_LIBCPP17_TO_CHARS_INTEGER 201611L
        #else
          #define LBAL_LIBCPP17_TO_CHARS_INTEGER 0
        #endif
      #else
        #define LBAL_LIBCPP17_TO_CHARS_INTEGER 0
      #endif
    #endif
  #endif

  //	SEEME - bitweeder
  //	libstdc++ only defines `__cpp_lib_to_chars` once floating-point support
  //	is in place (gcc 11), so we let the common SD-6 test set
  //	`LBAL_LIBCPP17_TO_CHARS_FP` in that case. Earlier versions shipped
  //	integer-only `<charconv>` support, so we explicitly disable the
  //	floating-point token there to avoid it getting mistakenly set later.
  #if !defined(LBAL_LIBCPP17_TO_CHARS_FP) && !(__cpp_lib_to_chars >= 201611L)
    #define LBAL_LIBCPP17_TO_CHARS_FP 0
  #endif
#else
  #error                                                                       \
      "lbalStandardLibraryLibStdCppInitialization.hpp was directly included with the incorrect Standard Library implementation"
#endif
