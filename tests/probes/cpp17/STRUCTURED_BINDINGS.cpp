/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “STRUCTURED_BINDINGS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_STRUCTURED_BINDINGS`, from
  P0217R3. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_STRUCTURED_BINDINGS
namespace lbal_fp {

struct Pair {
  int a;
  int b;
};

constexpr int
sum() {
  auto [x, y] = Pair{1, 2};
  return x + y;
}

static_assert(sum() == 3);

}  // namespace lbal_fp
#endif
