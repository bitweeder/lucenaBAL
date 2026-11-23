/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_FUNCTIONAL.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL`, from
  P1032R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL
  //	std
  #include <functional>

namespace lbal_fp {

constexpr int
call() {
  int x = 1;
  auto r = std::ref(x);
  r.get() = 2;
  return std::not_fn([](int v) {
    return v == 0;
  })(x)
           ? x
           : 0;
}

static_assert(call() == 2);

}  // namespace lbal_fp
#endif
