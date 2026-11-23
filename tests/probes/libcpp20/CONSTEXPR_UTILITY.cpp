/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_UTILITY.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP20_CONSTEXPR_UTILITY`, from
  P1032R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP20_CONSTEXPR_UTILITY
  //	std
  #include <utility>

namespace lbal_fp {

constexpr int
swapped() {
  std::pair<int, int> a{1, 2};
  std::pair<int, int> b{3, 4};
  a.swap(b);
  a = b;
  return a.first * 10 + b.second;
}

static_assert(swapped() == 12);

}  // namespace lbal_fp
#endif
