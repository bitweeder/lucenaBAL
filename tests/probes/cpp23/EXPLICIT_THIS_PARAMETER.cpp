/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “EXPLICIT_THIS_PARAMETER.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP23_EXPLICIT_THIS_PARAMETER`, from
  P0847R7. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP23_EXPLICIT_THIS_PARAMETER
namespace lbal_fp {

struct S {
  int value = 1;

  constexpr int
  get(this const S& self) {
    return self.value;
  }
};

static_assert(S{}.get() == 1);

}  // namespace lbal_fp
#endif
