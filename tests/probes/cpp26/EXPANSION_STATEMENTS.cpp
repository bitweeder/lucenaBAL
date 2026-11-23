/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “EXPANSION_STATEMENTS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP26_EXPANSION_STATEMENTS`, from
  P1306R5. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: written from P1306R5; not yet compiled by any compiler available
  here.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP26_EXPANSION_STATEMENTS
namespace lbal_fp {

constexpr int
sum() {
  int s = 0;
  template for (constexpr int i : {1, 2, 3}) {
    s += i;
  }
  return s;
}

static_assert(sum() == 6);

}  // namespace lbal_fp
#endif
