/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “THREE_WAY_COMPARISON_OPERATOR_EQUALITY_FIX.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for
  `LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_EQUALITY_FIX`, from P1185R2. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_EQUALITY_FIX
  //	std
  #include <compare>

namespace lbal_fp {

struct S {
  int value;
  auto operator<=> (const S&) const = default;
};

//	A defaulted `<=>` implicitly declares a defaulted `==` (P1185R2).
static_assert(S{1} == S{1});
static_assert(S{1} != S{2});

}  // namespace lbal_fp
#endif
