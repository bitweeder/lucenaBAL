/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “AGGREGATE_PAREN_INIT.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_AGGREGATE_PAREN_INIT`, from
  P0960R3. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_AGGREGATE_PAREN_INIT
namespace lbal_fp {

struct A {
  int a;
  int b;
};

constexpr A a(1, 2);
static_assert(a.b == 2);

}  // namespace lbal_fp
#endif
