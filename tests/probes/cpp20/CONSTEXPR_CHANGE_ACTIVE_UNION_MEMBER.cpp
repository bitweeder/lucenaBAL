/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_CHANGE_ACTIVE_UNION_MEMBER.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for
  `LBAL_CPP20_CONSTEXPR_CHANGE_ACTIVE_UNION_MEMBER`, from P1330R0. It only
  needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_CONSTEXPR_CHANGE_ACTIVE_UNION_MEMBER
namespace lbal_fp {

union U {
  int i;
  float f;
};

constexpr int
change() {
  U u{1};
  u.f = 2.0f;
  u.i = 3;
  return u.i;
}

static_assert(change() == 3);

}  // namespace lbal_fp
#endif
