/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_STRING_VIEW.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW`, from
  P0426R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW
  //	std
  #include <string_view>

namespace lbal_fp {

constexpr std::string_view hello = "hello";

static_assert(hello.size() == 5);
static_assert(hello.find('l') == 2);
static_assert(hello.substr(1, 2) == "el");

}  // namespace lbal_fp
#endif
