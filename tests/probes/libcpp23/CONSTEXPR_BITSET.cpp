/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_BITSET.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP23_CONSTEXPR_BITSET`, from
  P2417R2. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: not yet compiled against a library that reports this feature.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP23_CONSTEXPR_BITSET
  //	std
  #include <bitset>
  #include <cstddef>

namespace lbal_fp {

constexpr std::size_t
flipped() {
  std::bitset<8> b;
  b.set(1).set(3);
  b.flip(0);
  return b.count() * 10 + (b.test(3) ? 1 : 0);
}

static_assert(flipped() == 31);

}  // namespace lbal_fp
#endif
