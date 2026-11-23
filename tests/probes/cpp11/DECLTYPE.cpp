/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “DECLTYPE.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP11_DECLTYPE`, from N2343. It only
  needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP11_DECLTYPE
  //	std
  #include <type_traits>

namespace lbal_fp {

extern int i;

static_assert(std::is_same<decltype(i), int>::value, "");
static_assert(std::is_same<decltype((i)), int&>::value, "");

}  // namespace lbal_fp
#endif
