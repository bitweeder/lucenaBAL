/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_CHARCONV.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP23_CONSTEXPR_CHARCONV`, from
  P2291R3. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP23_CONSTEXPR_CHARCONV
  //	std
  #include <charconv>
  #include <system_error>

namespace lbal_fp {

constexpr int
round_trip() {
  char buffer[8] = {};
  auto [end, ec] = std::to_chars(buffer, buffer + 8, 255, 16);
  int value = 0;
  std::from_chars(buffer, end, value, 16);
  return ec == std::errc{} && buffer[0] == 'f' ? value : -1;
}

static_assert(round_trip() == 255);

}  // namespace lbal_fp
#endif
