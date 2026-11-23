/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “UNICODE_CHARACTERS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP11_UNICODE_CHARACTERS`, from N2249.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP11_UNICODE_CHARACTERS
  //	std
  #include <type_traits>

namespace lbal_fp {

static_assert(!std::is_same<char16_t, unsigned short>::value, "");
static_assert(!std::is_same<char32_t, unsigned int>::value, "");

}  // namespace lbal_fp
#endif
