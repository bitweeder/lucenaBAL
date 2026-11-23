/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP11_CONSTEXPR`, from N2235. It only
  needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP11_CONSTEXPR
namespace lbal_fp {

constexpr int
square(int x) {
  return x * x;
}

static_assert(square(3) == 9, "");

}  // namespace lbal_fp
#endif
