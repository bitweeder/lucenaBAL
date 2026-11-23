/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_VECTOR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP20_CONSTEXPR_VECTOR`, from
  P1004R2. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP20_CONSTEXPR_VECTOR
  //	std
  #include <vector>

namespace lbal_fp {

constexpr int
grow() {
  std::vector<int> v;
  for (int i = 0; i < 10; ++i)
    v.push_back(i);
  v.erase(v.begin());
  return v.front() + static_cast<int>(v.size());
}

static_assert(grow() == 10);

}  // namespace lbal_fp
#endif
