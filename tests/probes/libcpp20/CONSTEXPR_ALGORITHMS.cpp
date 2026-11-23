/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_ALGORITHMS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS`, from
  P0202R3. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP20_CONSTEXPR_ALGORITHMS
  //	std
  #include <algorithm>
  #include <iterator>

namespace lbal_fp {

constexpr bool
sorted() {
  int a[] = {3, 1, 2};
  std::sort(std::begin(a), std::end(a));
  return std::is_sorted(std::begin(a), std::end(a))
      && *std::find(std::begin(a), std::end(a), 2) == 2;
}

static_assert(sorted());

}  // namespace lbal_fp
#endif
