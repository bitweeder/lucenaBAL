/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “INHERITING_CONSTRUCTORS_REVISED.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED`,
  from P0136R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: exercises the P0136R1 model, but doesn’t isolate every change it
  made.

  LBAL_FP_SMOKE: it also compiles with the original inheriting-constructor
  rules, so it can’t detect a false negative.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED
namespace lbal_fp {

struct Base {
  template <class T>
  constexpr Base(T x, int y = 1)
    : value(static_cast<int>(x) + y) { }

  int value;
};

struct Derived : Base {
  using Base::Base;
  int extra = 2;
};

//	The inherited constructor template is found by lookup, with its default
//	argument, and the derived class’s members are still initialized.
static_assert(Derived(1.0).value == 2 && Derived(1.0).extra == 2);

}  // namespace lbal_fp
#endif
