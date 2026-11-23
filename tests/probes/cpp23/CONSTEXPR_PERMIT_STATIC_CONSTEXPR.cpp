/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_PERMIT_STATIC_CONSTEXPR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for
  `LBAL_CPP23_CONSTEXPR_PERMIT_STATIC_CONSTEXPR`, from P2647R1. It only needs
  to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP23_CONSTEXPR_PERMIT_STATIC_CONSTEXPR
namespace lbal_fp {

constexpr char
digit(int i) {
  static constexpr char digits[] = "0123456789";
  return digits[i];
}

static_assert(digit(3) == '3');

}  // namespace lbal_fp
#endif
