/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “VARIANT_CONSTEXPR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP23_VARIANT_CONSTEXPR`, from
  P2231R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP23_VARIANT_CONSTEXPR
  //	std
  #include <variant>

namespace lbal_fp {

constexpr int
reassign() {
  std::variant<int, double> v;
  v = 2.0;
  v.emplace<int>(3);
  std::variant<int, double> other = 4;
  v.swap(other);
  return std::get<int>(v) * 10 + std::get<int>(other);
}

static_assert(reassign() == 43);

}  // namespace lbal_fp
#endif
