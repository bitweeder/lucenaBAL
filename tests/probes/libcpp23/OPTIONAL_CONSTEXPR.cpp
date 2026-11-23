/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “OPTIONAL_CONSTEXPR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP23_OPTIONAL_CONSTEXPR`, from
  P2231R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP23_OPTIONAL_CONSTEXPR
  //	std
  #include <optional>

namespace lbal_fp {

constexpr int
reassign() {
  std::optional<int> o;
  o.emplace(1);
  o = 2;
  std::optional<int> other = 3;
  o.swap(other);
  o.reset();
  o = other;
  return *o;
}

static_assert(reassign() == 2);

}  // namespace lbal_fp
#endif
