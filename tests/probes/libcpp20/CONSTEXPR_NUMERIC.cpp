/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_NUMERIC.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP20_CONSTEXPR_NUMERIC`, from
  P1645R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP20_CONSTEXPR_NUMERIC
  //	std
  #include <iterator>
  #include <numeric>

namespace lbal_fp {

constexpr int
total() {
  int a[] = {1, 2, 3};
  int b[3] = {};
  std::partial_sum(std::begin(a), std::end(a), std::begin(b));
  return std::accumulate(std::begin(a), std::end(a), 0) * 10 + b[2];
}

static_assert(total() == 66);

}  // namespace lbal_fp
#endif
