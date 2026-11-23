/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “DELEGATING_CONSTRUCTORS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP11_DELEGATING_CONSTRUCTORS`, from
  N1986. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP11_DELEGATING_CONSTRUCTORS
namespace lbal_fp {

struct S {
  constexpr S(int x)
    : value(x) { }

  constexpr S()
    : S(42) { }

  int value;
};

static_assert(S().value == 42, "");

}  // namespace lbal_fp
#endif
