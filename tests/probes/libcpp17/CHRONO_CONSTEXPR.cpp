/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CHRONO_CONSTEXPR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP17_CHRONO_CONSTEXPR`, from
  P0505R0. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP17_CHRONO_CONSTEXPR
  //	std
  #include <chrono>

namespace lbal_fp {

constexpr long long
tick() {
  std::chrono::seconds s{1};
  ++s;
  std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> t{s};
  t += std::chrono::seconds{1};
  return t.time_since_epoch().count();
}

static_assert(tick() == 3);

}  // namespace lbal_fp
#endif
