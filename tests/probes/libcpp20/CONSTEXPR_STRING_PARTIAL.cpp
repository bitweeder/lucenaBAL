/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_STRING_PARTIAL.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL`, from
  P1032R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: checks the `char_traits` part of P1032R1.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP20_CONSTEXPR_STRING_PARTIAL
  //	std
  #include <string>

namespace lbal_fp {

//	P0980R1 made `std::string` usable in constant expressions; the earlier
//	partial step (P1032R1) covered `char_traits` copy and move.
constexpr char
copied() {
  char buffer[4] = {};
  std::char_traits<char>::copy(buffer, "abc", 3);
  std::char_traits<char>::move(buffer, buffer + 1, 2);
  return buffer[0];
}

static_assert(copied() == 'b');

}  // namespace lbal_fp
#endif
