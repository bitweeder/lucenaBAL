/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_EXCEPTIONS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP26_CONSTEXPR_EXCEPTIONS`, from
  P3068R6. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP26_CONSTEXPR_EXCEPTIONS && LBAL_CPP03_EXCEPTIONS
namespace lbal_fp {

constexpr int
thrown() {
  try {
    throw 42;
  } catch (int e) {
    return e;
  }
  return 0;
}

static_assert(thrown() == 42);

}  // namespace lbal_fp
#endif
