/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_STRING_VIEW.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW`, from
  P1032R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP20_CONSTEXPR_STRING_VIEW
  //	std
  #include <cstddef>
  #include <string_view>

namespace lbal_fp {

constexpr std::size_t
copied() {
  std::string_view sv = "hello";
  char buffer[3] = {};
  return sv.copy(buffer, 3, 1) + (buffer[0] == 'e' ? 10 : 0);
}

static_assert(copied() == 13);

}  // namespace lbal_fp
#endif
