/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “STATIC_CALL_OPERATOR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP23_STATIC_CALL_OPERATOR`, from
  P1169R4. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP23_STATIC_CALL_OPERATOR
namespace lbal_fp {

struct Increment {
  static constexpr int
  operator() (int x) {
    return x + 1;
  }
};

static_assert(Increment{}(1) == 2);
static_assert(Increment::operator() (1) == 2);

}  // namespace lbal_fp
#endif
