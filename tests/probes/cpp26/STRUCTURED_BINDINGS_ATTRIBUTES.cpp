/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “STRUCTURED_BINDINGS_ATTRIBUTES.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP26_STRUCTURED_BINDINGS_ATTRIBUTES`,
  from P0609R3. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP26_STRUCTURED_BINDINGS_ATTRIBUTES
namespace lbal_fp {

struct Pair {
  int a;
  int b;
};

constexpr int
second() {
  auto [a [[maybe_unused]], b] = Pair{1, 2};
  return b;
}

static_assert(second() == 2);

}  // namespace lbal_fp
#endif
