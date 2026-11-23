/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “INIT_STATEMENTS_FOR_RANGE_BASED_FOR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for
  `LBAL_CPP20_INIT_STATEMENTS_FOR_RANGE_BASED_FOR`. It only needs to compile;
  see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_INIT_STATEMENTS_FOR_RANGE_BASED_FOR
namespace lbal_fp {

constexpr int
sum() {
  int s = 0;
  for (int a[] = {1, 2, 3}; int x : a)
    s += x;
  return s;
}

static_assert(sum() == 6);

}  // namespace lbal_fp
#endif
