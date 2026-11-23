/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_TRY_CATCH.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_CONSTEXPR_TRY_CATCH`, from
  P1002R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_CONSTEXPR_TRY_CATCH && LBAL_CPP03_EXCEPTIONS
namespace lbal_fp {

constexpr int
guarded() {
  try {
    return 1;
  } catch (...) {
    return 0;
  }
}

static_assert(guarded() == 1);

}  // namespace lbal_fp
#endif
