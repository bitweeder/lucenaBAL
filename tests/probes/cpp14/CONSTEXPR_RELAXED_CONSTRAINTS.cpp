/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_RELAXED_CONSTRAINTS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS`,
  from N3652. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS
namespace lbal_fp {

constexpr int
triangle(int n) {
  int r = 0;
  for (int i = 0; i < n; ++i) {
    r += i;
  }
  return r;
}

static_assert(triangle(4) == 6, "");

}  // namespace lbal_fp
#endif
