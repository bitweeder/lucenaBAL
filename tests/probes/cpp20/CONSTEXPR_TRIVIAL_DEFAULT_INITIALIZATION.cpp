/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for
  `LBAL_CPP20_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION`, from P1331R2. It only
  needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION
namespace lbal_fp {

constexpr int
assign() {
  int x;
  x = 3;
  return x;
}

static_assert(assign() == 3);

}  // namespace lbal_fp
#endif
