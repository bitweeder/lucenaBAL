/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “AUTO_CAST.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP23_AUTO_CAST`, from P0849R8. It only
  needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP23_AUTO_CAST
  //	std
  #include <type_traits>

namespace lbal_fp {

inline constexpr int k = 3;

static_assert(std::is_same_v<decltype(auto(k)), int>);
static_assert(auto(k) == 3);

}  // namespace lbal_fp
#endif
