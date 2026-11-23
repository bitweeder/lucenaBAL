/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “ARRAY_CONSTEXPR_COMPARISONS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS`,
  from P1023R0. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP20_ARRAY_CONSTEXPR_COMPARISONS
  //	std
  #include <array>

namespace lbal_fp {

constexpr std::array<int, 3> a{1, 2, 3};
constexpr std::array<int, 3> b{1, 2, 4};

static_assert(a == a && a != b && a < b);

}  // namespace lbal_fp
#endif
