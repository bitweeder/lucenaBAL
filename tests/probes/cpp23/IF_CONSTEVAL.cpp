/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “IF_CONSTEVAL.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP23_IF_CONSTEVAL`, from P1938R3. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP23_IF_CONSTEVAL
namespace lbal_fp {

constexpr int
where() {
  if consteval {
    return 1;
  } else {
    return 2;
  }
}

static_assert(where() == 1);

}  // namespace lbal_fp
#endif
