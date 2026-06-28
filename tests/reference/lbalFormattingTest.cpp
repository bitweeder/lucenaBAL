/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFormattingTest”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  This is a do-nothing source file intended only to test `clang-format` output.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

//	std
#include <iostream>
#include <string>

#include "lbalFormattingTest.hpp"

#if _LIBCPP_VERSION                                                            \
    && ((defined(__MAC_OS_X_VERSION_MIN_REQUIRED)                              \
            && (__MAC_OS_X_VERSION_MIN_REQUIRED < 101200))                     \
        || (defined(__IPHONE_OS_VERSION_MIN_REQUIRED)                          \
            && (__IPHONE_OS_VERSION_MIN_REQUIRED < 100000))                    \
        || (defined(__TV_OS_VERSION_MIN_REQUIRED)                              \
            && (__TV_OS_VERSION_MIN_REQUIRED < 100000))                        \
        || (defined(__WATCH_OS_VERSION_MIN_REQUIRED)                           \
            && (__WATCH_OS_VERSION_MIN_REQUIRED < 30000)))
  #error "The minimum OS requirement for std::shared_lock has not been met."
#endif

//  declarations
void ifFunction();

//  definitions
int
someFunction1(
    std::string input_1,
    double input_2,
    int input_3,
    int input_4,
    int input_5,
    int input_6,
    int input_7
) {
  int local_1{3};

  std::cout << input_1;
  local_1 += static_cast<int>(input_2)
           + input_3
           + input_4
           + input_5
           + input_6
           + input_7;
  return local_1;
}

void
ifFunction() {
  int const a{37};
  int const b{35};
  int const c{34};
  int const d{33};

  if constexpr (
      _LIBCPP_VERSION
      && (((a) && (a < 37))
          || ((b) && (b < 100000))
          || ((c) && (c < 100000))
          || ((d) && (d < 30000)))
  )
  {
    static_assert(
        true,
        "The minimum OS requirement for std::shared_lock has not been met."
    );
  }
}
