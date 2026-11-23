/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “INTEGRATING_OUR_FEATURE_TEST_MACROS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for
  `LBAL_CPP20_INTEGRATING_OUR_FEATURE_TEST_MACROS`. It only needs to compile;
  see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_INTEGRATING_OUR_FEATURE_TEST_MACROS
namespace lbal_fp {

  #if !defined(__cpp_constexpr) || !defined(__cpp_static_assert)
    #error "SD-6 language feature-test macros are missing"
  #endif

  #if !__has_include(<version>)
    #error "<version> is missing"
  #endif

}  // namespace lbal_fp
#endif
