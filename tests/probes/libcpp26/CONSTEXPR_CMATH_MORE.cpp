/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_CMATH_MORE.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP26_CONSTEXPR_CMATH_MORE`, from
  P1383R2. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  GCC folds most `<cmath>` calls to constants in every mode, so this uses two
  of P1383R2’s functions it doesn’t fold: `lgamma` and the three-argument
  `hypot`.

  SEEME: written from the paper; not yet compiled against a library that
  reports this feature.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_CONSTEXPR_CMATH_MORE
  //	std
  #include <cmath>

namespace lbal_fp {

constexpr bool
near(double x, double y) {
  return (x - y < 1e-9) && (y - x < 1e-9);
}

static_assert(near(std::hypot(3.0, 4.0, 0.0), 5.0));
static_assert(near(std::lgamma(1.0), 0.0));

}  // namespace lbal_fp
#endif
