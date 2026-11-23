/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEVAL.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_CONSTEVAL`, from P1073R3. It only
  needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_CONSTEVAL
namespace lbal_fp {

consteval int
square(int x) {
  return x * x;
}

constexpr int nine = square(3);
static_assert(nine == 9);

}  // namespace lbal_fp
#endif
