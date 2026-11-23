/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “ARRAY_CONSTEXPR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP17_ARRAY_CONSTEXPR`, from P0031R0.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP17_ARRAY_CONSTEXPR
  //	std
  #include <array>
  #include <iterator>

namespace lbal_fp {

constexpr int
touch() {
  std::array<int, 3> a{};
  a[0] = 1;
  *(a.begin() + 1) = 2;
  auto r = std::make_reverse_iterator(a.end());
  return *r + a.front() + a[1];
}

static_assert(touch() == 3);

}  // namespace lbal_fp
#endif
