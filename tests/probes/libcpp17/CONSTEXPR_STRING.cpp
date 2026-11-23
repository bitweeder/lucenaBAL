/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_STRING.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP17_CONSTEXPR_STRING`, from
  P0426R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP17_CONSTEXPR_STRING
  //	std
  #include <string>

namespace lbal_fp {

static_assert(std::char_traits<char>::length("abc") == 3);
static_assert(std::char_traits<char>::compare("ab", "ac", 2) < 0);
static_assert(*std::char_traits<char>::find("abc", 3, 'c') == 'c');

}  // namespace lbal_fp
#endif
