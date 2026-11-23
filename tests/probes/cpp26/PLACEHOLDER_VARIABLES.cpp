/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “PLACEHOLDER_VARIABLES.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP26_PLACEHOLDER_VARIABLES`, from
  P2169R4. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP26_PLACEHOLDER_VARIABLES
namespace lbal_fp {

struct Pair {
  int a;
  int b;
};

constexpr int
sum() {
  auto [_, b] = Pair{1, 2};
  auto [_, d] = Pair{3, 4};
  int _ = 5;
  return b + d;
}

static_assert(sum() == 6);

}  // namespace lbal_fp
#endif
