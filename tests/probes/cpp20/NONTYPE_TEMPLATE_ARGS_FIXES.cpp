/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “NONTYPE_TEMPLATE_ARGS_FIXES.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FIXES`, from
  P1907R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FIXES
namespace lbal_fp {

struct Structural {
  int value;
};

template <Structural S>
constexpr int
get() {
  return S.value;
}

static_assert(get<Structural{3}>() == 3);

}  // namespace lbal_fp
#endif
