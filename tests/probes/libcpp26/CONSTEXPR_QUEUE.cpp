/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_QUEUE.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP26_CONSTEXPR_QUEUE`, from P3372R3.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: written from the paper; not yet compiled against a library that
  reports this feature.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_CONSTEXPR_QUEUE
  //	std
  #include <queue>

namespace lbal_fp {

constexpr int
use() {
  std::queue<int> c;
  c.push(1);
  c.push(2);
  std::priority_queue<int> p;
  p.push(1);
  p.push(5);
  return c.front() * 10 + p.top();
}

static_assert(use() == 15);

}  // namespace lbal_fp
#endif
