/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_STACK.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP26_CONSTEXPR_STACK`, from P3372R3.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: written from the paper; not yet compiled against a library that
  reports this feature.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_CONSTEXPR_STACK
  //	std
  #include <stack>

namespace lbal_fp {

constexpr int
use() {
  std::stack<int> c;
  c.push(1);
  c.push(2);
  return c.top() * 10 + static_cast<int>(c.size());
}

static_assert(use() == 22);

}  // namespace lbal_fp
#endif
