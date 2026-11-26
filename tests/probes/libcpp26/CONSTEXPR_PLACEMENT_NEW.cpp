/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_PLACEMENT_NEW.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP26_CONSTEXPR_PLACEMENT_NEW`, from
  P2747R2. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  This is the library side, `<new>`’s placement `operator new`; the language
  side is `LBAL_CPP26_CONSTEXPR_PLACEMENT_NEW`.

  Checked against libstdc++ 15 with GCC 15 and libc++ 23 with Clang 23
  (C++26).

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_CONSTEXPR_PLACEMENT_NEW
  //	std
  #include <memory>
  #include <new>

namespace lbal_fp {

constexpr int
construct() {
  std::allocator<int> a;
  int* p = a.allocate(1);
  ::new (static_cast<void*>(p)) int(42);
  int v = *p;
  std::destroy_at(p);
  a.deallocate(p, 1);
  return v;
}

static_assert(construct() == 42);

}  // namespace lbal_fp
#endif
