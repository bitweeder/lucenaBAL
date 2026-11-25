/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “INHERITING_CONSTRUCTORS_REVISED.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED`,
  from P0136R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  This is the paper’s own Annex C example: under the C++14 model, `B b(42L)`
  used an injected `B<long>(long)`; now lookup finds the base constructor
  template, its substitution fails, and `B(int)` is called.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED
namespace lbal_fp {

struct A {
  template <typename T>
  constexpr A(T, typename T::type = 0)
    : value(1) { }

  constexpr A(int)
    : value(2) { }

  int value;
};

struct B : A {
  using A::A;

  constexpr B(int)
    : A(0), own(3) { }

  int own = 4;
};

constexpr B b(42L);

static_assert(b.own == 3);

}  // namespace lbal_fp
#endif
