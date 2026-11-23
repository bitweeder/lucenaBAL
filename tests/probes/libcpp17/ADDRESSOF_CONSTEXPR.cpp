/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “ADDRESSOF_CONSTEXPR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR`, from
  LWG2296. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR
  //	std
  #include <memory>

namespace lbal_fp {

inline constexpr int value = 0;

static_assert(std::addressof(value) == &value);

}  // namespace lbal_fp
#endif
