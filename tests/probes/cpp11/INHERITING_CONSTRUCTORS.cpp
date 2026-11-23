/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “INHERITING_CONSTRUCTORS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP11_INHERITING_CONSTRUCTORS`, from
  N2540. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP11_INHERITING_CONSTRUCTORS
namespace lbal_fp {

struct Base {
  constexpr Base(int x)
    : value(x) { }

  int value;
};

struct Derived : Base {
  using Base::Base;
};

static_assert(Derived(7).value == 7, "");

}  // namespace lbal_fp
#endif
