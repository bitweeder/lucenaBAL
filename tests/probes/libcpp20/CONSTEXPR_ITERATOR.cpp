/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_ITERATOR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP20_CONSTEXPR_ITERATOR`, from
  P1032R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP20_CONSTEXPR_ITERATOR
  //	std
  #include <iterator>

namespace lbal_fp {

constexpr int
walk() {
  int a[] = {1, 2, 3};
  auto it = std::begin(a);
  std::advance(it, 1);
  auto r = std::make_reverse_iterator(std::end(a));
  return *it * 10
       + *r
       + static_cast<int>(std::distance(std::begin(a), std::end(a)));
}

static_assert(walk() == 26);

}  // namespace lbal_fp
#endif
