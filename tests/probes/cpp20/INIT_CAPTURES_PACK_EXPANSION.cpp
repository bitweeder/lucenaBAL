/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “INIT_CAPTURES_PACK_EXPANSION.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION`,
  from P0780R2. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION
namespace lbal_fp {

template <class... Ts>
constexpr auto
sum(Ts... ts) {
  return [... xs = ts]() {
    return (xs + ... + 0);
  }();
}

static_assert(sum(1, 2, 3) == 6);

}  // namespace lbal_fp
#endif
