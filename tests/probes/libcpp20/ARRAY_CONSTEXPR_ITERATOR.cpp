/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “ARRAY_CONSTEXPR_ITERATOR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR`, from
  LWG3257 and P0858R0. It only needs to compile; see
  `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP20_ARRAY_CONSTEXPR_ITERATOR
  //	std
  #include <array>

namespace lbal_fp {

constexpr int
sum() {
  std::array<int, 3> a{1, 2, 3};
  int s = 0;
  for (auto it = a.begin(); it != a.end(); ++it)
    s += *it;
  for (auto it = a.rbegin(); it != a.rend(); ++it)
    s += *it;
  return s;
}

static_assert(sum() == 12);

}  // namespace lbal_fp
#endif
