/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_DYNAMIC_ALLOC.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC`, from
  P0784R7. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP20_CONSTEXPR_DYNAMIC_ALLOC
  //	std
  #include <memory>

namespace lbal_fp {

constexpr int
allocate() {
  std::allocator<int> a;
  int* p = a.allocate(2);
  std::construct_at(p, 4);
  std::construct_at(p + 1, 5);
  int v = p[0] + p[1];
  std::destroy(p, p + 2);
  a.deallocate(p, 2);
  return v;
}

static_assert(allocate() == 9);

}  // namespace lbal_fp
#endif
