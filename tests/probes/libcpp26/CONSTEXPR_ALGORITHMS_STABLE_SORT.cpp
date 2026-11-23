/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_ALGORITHMS_STABLE_SORT.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for
  `LBAL_LIBCPP26_CONSTEXPR_ALGORITHMS_STABLE_SORT`, from P2562R1. It only
  needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_CONSTEXPR_ALGORITHMS_STABLE_SORT
  //	std
  #include <algorithm>
  #include <iterator>
  #include <utility>

namespace lbal_fp {

constexpr bool
stable() {
  std::pair<int, int> a[] = {{2, 0}, {1, 1}, {2, 2}, {1, 3}};
  std::stable_sort(
      std::begin(a), std::end(a), [](const auto& x, const auto& y) {
        return x.first < y.first;
      }
  );
  int b[] = {1, 2, 3, 4};
  std::stable_partition(std::begin(b), std::end(b), [](int x) {
    return x % 2 == 0;
  });
  return a[0].second == 1 && a[1].second == 3 && b[0] == 2 && b[1] == 4;
}

static_assert(stable());

}  // namespace lbal_fp
#endif
