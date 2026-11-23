/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “THREE_WAY_COMPARISON_OPERATOR_TUNEUP.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for
  `LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_TUNEUP`, from P1630R1. It only
  needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: checks P1186R3 synthesis, one of the C++20 refinements tracked by
  this value; P1630R1 itself is mostly wording.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_TUNEUP
  //	std
  #include <compare>

namespace lbal_fp {

struct Legacy {
  int value;

  constexpr bool
  operator== (const Legacy& o) const {
    return value == o.value;
  }

  constexpr bool
  operator< (const Legacy& o) const {
    return value < o.value;
  }
};

//	The comparison category is given explicitly, so `<=>` is synthesized from
//	`==` and `<` for the member that lacks it.
struct S {
  Legacy l;
  std::strong_ordering operator<=> (const S&) const = default;
};

static_assert(S{{1}} < S{{2}});

}  // namespace lbal_fp
#endif
