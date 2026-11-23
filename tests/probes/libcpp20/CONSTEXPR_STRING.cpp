/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_STRING.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP20_CONSTEXPR_STRING`, from
  P0980R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP20_CONSTEXPR_STRING
  //	std
  #include <cstddef>
  #include <string>

namespace lbal_fp {

constexpr std::size_t
grow() {
  std::string s = "abc";
  s += "def";
  s.push_back('g');
  return s.size() + (s.find("de") == 3 ? 100 : 0);
}

static_assert(grow() == 107);

}  // namespace lbal_fp
#endif
