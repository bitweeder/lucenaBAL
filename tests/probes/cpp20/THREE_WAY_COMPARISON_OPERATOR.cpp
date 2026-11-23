/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “THREE_WAY_COMPARISON_OPERATOR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR`,
  from P0515R3 and P0768R1. It only needs to compile; see
  `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR
  //	std
  #include <compare>

namespace lbal_fp {

struct S {
  int value;
  auto operator<=> (const S&) const = default;
};

static_assert((S{1} <=> S{2}) < 0);
static_assert(S{1} < S{2});

}  // namespace lbal_fp
#endif
