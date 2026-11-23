/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_CAST_FROM_VOID_STAR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP26_CONSTEXPR_CAST_FROM_VOID_STAR`,
  from P2738R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP26_CONSTEXPR_CAST_FROM_VOID_STAR
namespace lbal_fp {

constexpr int
round_trip() {
  int i = 42;
  void* p = &i;
  return *static_cast<int*>(p);
}

static_assert(round_trip() == 42);

}  // namespace lbal_fp
#endif
