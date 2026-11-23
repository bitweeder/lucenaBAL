/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “ARRAY_CONSTEXPR_UTILITIES.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES`,
  from P1032R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP20_ARRAY_CONSTEXPR_UTILITIES
  //	std
  #include <array>

namespace lbal_fp {

constexpr int
fill_and_swap() {
  std::array<int, 2> a{};
  std::array<int, 2> b{};
  a.fill(1);
  b.fill(2);
  a.swap(b);
  return a[0] * 10 + b[1];
}

static_assert(fill_and_swap() == 21);

}  // namespace lbal_fp
#endif
