/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_VIRTUAL_INHERITANCE.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP26_CONSTEXPR_VIRTUAL_INHERITANCE`,
  from P3533R2. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP26_CONSTEXPR_VIRTUAL_INHERITANCE
namespace lbal_fp {

struct Base {
  int value = 1;
};

struct Derived : virtual Base {
  constexpr Derived() { }
};

constexpr int
get() {
  Derived d;
  return d.value;
}

static_assert(get() == 1);

}  // namespace lbal_fp
#endif
