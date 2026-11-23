/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “STRUCTURED_BINDINGS_PACK.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP26_STRUCTURED_BINDINGS_PACK`, from
  P1061R10. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP26_STRUCTURED_BINDINGS_PACK
namespace lbal_fp {

struct Triple {
  int a;
  int b;
  int c;
};

template <class T>
constexpr int
sum(T t) {
  auto [... xs] = t;
  return (xs + ... + 0);
}

static_assert(sum(Triple{1, 2, 3}) == 6);

}  // namespace lbal_fp
#endif
