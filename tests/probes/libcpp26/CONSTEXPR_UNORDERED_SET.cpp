/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_UNORDERED_SET.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP26_CONSTEXPR_UNORDERED_SET`, from
  P3372R3. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: written from the paper; not yet compiled against a library that
  reports this feature.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_CONSTEXPR_UNORDERED_SET
  //	std
  #include <unordered_set>

namespace lbal_fp {

constexpr int
use() {
  std::unordered_set<int> c{1, 2, 2};
  return static_cast<int>(c.size()) + (c.contains(2) ? 10 : 0);
}

static_assert(use() == 12);

}  // namespace lbal_fp
#endif
