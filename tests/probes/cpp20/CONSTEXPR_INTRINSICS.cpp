/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_INTRINSICS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_CONSTEXPR_INTRINSICS`, from
  P1668R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  MSVC has no inline assembly on x64 or ARM64, so this probe is GCC/Clang
  only.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_CONSTEXPR_INTRINSICS && !defined(_MSC_VER)
  //	std
  #include <type_traits>

namespace lbal_fp {

constexpr int
pass(int x) {
  if (std::is_constant_evaluated()) {
    return x;
  } else {
    asm("");
    return x;
  }
}

static_assert(pass(1) == 1);

}  // namespace lbal_fp
#endif
