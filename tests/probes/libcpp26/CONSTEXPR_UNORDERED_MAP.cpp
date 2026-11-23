/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_UNORDERED_MAP.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP26_CONSTEXPR_UNORDERED_MAP`, from
  P3372R3. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: written from the paper; not yet compiled against a library that
  reports this feature.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_CONSTEXPR_UNORDERED_MAP
  //	std
  #include <unordered_map>

namespace lbal_fp {

constexpr int
use() {
  std::unordered_map<int, int> c;
  c[1] = 10;
  c.emplace(2, 20);
  return c.at(1) + c.at(2);
}

static_assert(use() == 30);

}  // namespace lbal_fp
#endif
