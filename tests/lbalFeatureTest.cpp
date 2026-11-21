/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFeatureTest”
  Copyright © 2015-2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

//  gtest
#include <gtest/gtest.h>

//	std
#include <iostream>

/*------------------------------------------------------------------------------
  Declarations
*/

#define LBAL_DIAGNOSTIC_LOG_ALL_STATUS false
#define LBAL_DIAGNOSTIC_LOG_ALL_UNSUPPORTED true

#if LBAL_DIAGNOSTIC_LOG_ALL_STATUS
  #define LBAL_DIAGNOSTIC_LOG_SUPPORTED(LBAL_DIAGNOSTIC_feature_)              \
    std::cerr << LBAL_DIAGNOSTIC_feature_ " is supported" << std::endl;
#else
  #define LBAL_DIAGNOSTIC_LOG_SUPPORTED(LBAL_DIAGNOSTIC_feature_)
#endif

#if LBAL_DIAGNOSTIC_LOG_ALL_STATUS || LBAL_DIAGNOSTIC_LOG_ALL_UNSUPPORTED
  #define LBAL_DIAGNOSTIC_LOG_UNSUPPORTED(LBAL_DIAGNOSTIC_feature_)            \
    std::cerr << LBAL_DIAGNOSTIC_feature_ " is UNSUPPORTED" << std::endl;
#elif
  #define LBAL_DIAGNOSTIC_LOG_UNSUPPORTED(LBAL_DIAGNOSTIC_feature_)
#endif

#if LBAL_CPP17_IF_CONSTEXPR
  #define LBAL_IF_CONSTEXPR if constexpr
#else
  #define LBAL_IF_CONSTEXPR if
#endif

#define LBAL_DIAGNOSTIC_TEST(LBAL_DIAGNOSTIC_feature_)                         \
  do {                                                                         \
    LBAL_IF_CONSTEXPR (0 == LBAL_DIAGNOSTIC_feature_) {                        \
      LBAL_DIAGNOSTIC_LOG_UNSUPPORTED(#LBAL_DIAGNOSTIC_feature_)               \
    } else {                                                                   \
      LBAL_DIAGNOSTIC_LOG_SUPPORTED(#LBAL_DIAGNOSTIC_feature_)                 \
    }                                                                          \
  } while (false)

using namespace LBAL_;

/*------------------------------------------------------------------------------
 */

GTEST_TEST(lbalTest, Validation) {
  /*
    Report the results of the various feature tests; depending on your IDE, you
    may not even need to explicitly compile to see the test results.
  */

#include "fragments/lbalFeatureTest-cpp03.inc"
#include "fragments/lbalFeatureTest-cpp11.inc"
#include "fragments/lbalFeatureTest-cpp14.inc"
#include "fragments/lbalFeatureTest-cpp17.inc"
#include "fragments/lbalFeatureTest-cpp20.inc"
#include "fragments/lbalFeatureTest-cpp23.inc"
#include "fragments/lbalFeatureTest-cpp26.inc"
#include "fragments/lbalFeatureTest-cpp2d.inc"
#include "fragments/lbalFeatureTest-libcpp14.inc"
#include "fragments/lbalFeatureTest-libcpp17.inc"
#include "fragments/lbalFeatureTest-libcpp20.inc"
#include "fragments/lbalFeatureTest-libcpp23.inc"
#include "fragments/lbalFeatureTest-libcpp26.inc"
#include "fragments/lbalFeatureTest-libcpp2d.inc"

  EXPECT_TRUE(true);
}

#undef LBAL_IF_CONSTEXPR
