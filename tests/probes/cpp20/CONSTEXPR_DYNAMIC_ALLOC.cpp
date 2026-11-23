/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_DYNAMIC_ALLOC.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_CONSTEXPR_DYNAMIC_ALLOC`, from
  P0784R7. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_CONSTEXPR_DYNAMIC_ALLOC
namespace lbal_fp {

constexpr int
allocate() {
  int* p = new int(42);
  int v = *p;
  delete p;
  return v;
}

static_assert(allocate() == 42);

}  // namespace lbal_fp
#endif
