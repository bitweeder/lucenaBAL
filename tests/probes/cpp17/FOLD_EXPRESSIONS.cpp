/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “FOLD_EXPRESSIONS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_FOLD_EXPRESSIONS`, from N4295. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_FOLD_EXPRESSIONS
namespace lbal_fp {

template <class... Ts>
constexpr auto
sum(Ts... ts) {
  return (ts + ... + 0);
}

static_assert(sum(1, 2, 3) == 6);

}  // namespace lbal_fp
#endif
