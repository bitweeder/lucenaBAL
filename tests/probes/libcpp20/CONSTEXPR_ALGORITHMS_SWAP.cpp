/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_ALGORITHMS_SWAP.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP`,
  from LWG3256 and LWG3792 and P0879R0. It only needs to compile; see
  `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS_SWAP
  //	std
  #include <algorithm>
  #include <iterator>
  #include <utility>

namespace lbal_fp {

constexpr int
swapped() {
  int a = 1;
  int b = 2;
  std::swap(a, b);
  int x[] = {1, 2};
  int y[] = {3, 4};
  std::swap_ranges(std::begin(x), std::end(x), std::begin(y));
  std::iter_swap(&a, &b);
  return a * 1000 + b * 100 + x[0] * 10 + y[0];
}

static_assert(swapped() == 1231);

}  // namespace lbal_fp
#endif
