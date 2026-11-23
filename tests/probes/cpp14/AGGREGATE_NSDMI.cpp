/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “AGGREGATE_NSDMI.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP14_AGGREGATE_NSDMI`, from N3653. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP14_AGGREGATE_NSDMI
namespace lbal_fp {

struct A {
  int x;
  int y = 2;
};

constexpr A a{1};
static_assert(a.y == 2, "");

}  // namespace lbal_fp
#endif
