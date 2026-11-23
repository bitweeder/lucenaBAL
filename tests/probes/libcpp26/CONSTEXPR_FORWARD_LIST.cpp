/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_FORWARD_LIST.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP26_CONSTEXPR_FORWARD_LIST`, from
  P3372R3. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: written from the paper; not yet compiled against a library that
  reports this feature.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_CONSTEXPR_FORWARD_LIST
  //	std
  #include <forward_list>
  #include <iterator>

namespace lbal_fp {

constexpr int
use() {
  std::forward_list<int> c{2, 3};
  c.push_front(1);
  c.reverse();
  return c.front() * 10 + static_cast<int>(std::distance(c.begin(), c.end()));
}

static_assert(use() == 33);

}  // namespace lbal_fp
#endif
