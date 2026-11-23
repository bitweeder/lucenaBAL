/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_VIRTUAL_FUNCTION.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_CONSTEXPR_VIRTUAL_FUNCTION`, from
  P1064R0. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_CONSTEXPR_VIRTUAL_FUNCTION
namespace lbal_fp {

struct Base {
  constexpr virtual int
  f() const {
    return 1;
  }
};

struct Derived : Base {
  constexpr int
  f() const override {
    return 2;
  }
};

constexpr int
call(const Base& b) {
  return b.f();
}

static_assert(call(Derived{}) == 2);

}  // namespace lbal_fp
#endif
