/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “IS_WITHIN_LIFETIME_EXTEND.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP26_IS_WITHIN_LIFETIME_EXTEND`,
  from P3450R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: smoke test only; it doesn’t isolate the P3450R1 changes.

  LBAL_FP_SMOKE: it also passes with only P2641R4, so it can’t detect a false
  negative.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_IS_WITHIN_LIFETIME_EXTEND
  //	std
  #include <type_traits>

namespace lbal_fp {

consteval bool
alive() {
  int x = 0;
  return std::is_within_lifetime(&x);
}

static_assert(alive());

}  // namespace lbal_fp
#endif
