/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “AGGREGATE_BASES.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_AGGREGATE_BASES`, from P0017R1. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_AGGREGATE_BASES
namespace lbal_fp {

struct Base {
  int b;
};

struct Derived : Base {
  int d;
};

constexpr Derived x{{1}, 2};
static_assert(x.b == 1 && x.d == 2, "");

}  // namespace lbal_fp
#endif
