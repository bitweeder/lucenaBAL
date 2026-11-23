/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “RAW_MEMORY_ALGORITHMS_CONSTEXPR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for
  `LBAL_LIBCPP26_RAW_MEMORY_ALGORITHMS_CONSTEXPR`, from P3369R0 and P3508R0.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_RAW_MEMORY_ALGORITHMS_CONSTEXPR
  //	std
  #include <memory>

namespace lbal_fp {

constexpr int
raw() {
  std::allocator<int> a;
  int* p = a.allocate(3);
  std::uninitialized_value_construct_n(p, 3);
  std::uninitialized_fill(p + 1, p + 3, 4);
  int v = p[0] + p[1] + p[2];
  std::destroy_n(p, 3);
  a.deallocate(p, 3);
  return v;
}

static_assert(raw() == 8);

}  // namespace lbal_fp
#endif
