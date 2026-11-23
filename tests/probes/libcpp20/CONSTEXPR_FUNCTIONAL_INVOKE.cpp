/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_FUNCTIONAL_INVOKE.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE`,
  from P1065R2. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP20_CONSTEXPR_FUNCTIONAL_INVOKE
  //	std
  #include <functional>

namespace lbal_fp {

struct S {
  int value;

  constexpr int
  get() const {
    return value;
  }
};

static_assert(std::invoke(&S::get, S{3}) == 3);
static_assert(
    std::invoke(
        [](int x) {
          return x + 1;
        },
        1
    )
    == 2
);

}  // namespace lbal_fp
#endif
