/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_FLAT_SET.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP26_CONSTEXPR_FLAT_SET`, from
  P3372R3. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  Checked against libc++ 23 with Clang 23 (C++26).

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_CONSTEXPR_FLAT_SET
  //	std
  #include <flat_set>

namespace lbal_fp {

constexpr int
use() {
  //	The macro covers `flat_multiset` too; libc++ 21 made only `flat_set`
  //	constexpr.
  std::flat_set<int> c{3, 1, 2, 1};
  std::flat_multiset<int> d{3, 1, 1};
  return *c.begin() * 10
       + static_cast<int>(c.size())
       + static_cast<int>(d.count(1)) * 100;
}

static_assert(use() == 213);

}  // namespace lbal_fp
#endif
