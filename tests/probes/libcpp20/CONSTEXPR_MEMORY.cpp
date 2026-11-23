/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_MEMORY.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP20_CONSTEXPR_MEMORY`, from
  P1006R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP20_CONSTEXPR_MEMORY
  //	std
  #include <memory>

namespace lbal_fp {

constexpr bool
pointer() {
  int x = 0;
  return std::pointer_traits<int*>::pointer_to(x) == &x;
}

static_assert(pointer());

}  // namespace lbal_fp
#endif
