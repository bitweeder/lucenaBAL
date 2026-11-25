/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_MAP.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP26_CONSTEXPR_MAP`, from P3372R3.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  Checked against libc++ 23 with Clang 23 (C++26).

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_CONSTEXPR_MAP
  //	std
  #include <map>

namespace lbal_fp {

constexpr int
use() {
  std::map<int, int> c;
  c[2] = 20;
  c.emplace(1, 10);
  return c.begin()->second + c.at(2);
}

static_assert(use() == 30);

}  // namespace lbal_fp
#endif
