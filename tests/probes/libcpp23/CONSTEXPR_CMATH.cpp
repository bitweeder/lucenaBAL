/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_CMATH.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP23_CONSTEXPR_CMATH`, from P0533R9.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: not yet compiled against a library that reports this feature.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP23_CONSTEXPR_CMATH
  //	std
  #include <cmath>
  #include <cstdlib>

namespace lbal_fp {

static_assert(std::fabs(-1.5) == 1.5);
static_assert(std::fmax(1.0, 2.0) == 2.0);
static_assert(std::fmin(1.0, 2.0) == 1.0);
static_assert(std::copysign(1.0, -2.0) == -1.0);
static_assert(!std::isnan(1.0));
static_assert(std::abs(-3) == 3);

}  // namespace lbal_fp
#endif
