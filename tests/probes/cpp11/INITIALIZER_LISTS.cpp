/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “INITIALIZER_LISTS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP11_INITIALIZER_LISTS`, from N2672. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP11_INITIALIZER_LISTS
  //	std
  #include <cstddef>
  #include <initializer_list>

namespace lbal_fp {

constexpr std::size_t
count(std::initializer_list<int> l) {
  return l.size();
}

static_assert(count({1, 2, 3}) == 3, "");

}  // namespace lbal_fp
#endif
