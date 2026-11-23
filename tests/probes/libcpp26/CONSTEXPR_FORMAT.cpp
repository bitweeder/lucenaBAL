/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_FORMAT.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP26_CONSTEXPR_FORMAT`, from
  P3391R2. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: written from the paper; not yet compiled against a library that
  reports this feature.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_CONSTEXPR_FORMAT
  //	std
  #include <format>
  #include <string>

namespace lbal_fp {

constexpr bool
formatted() {
  return std::format("{}-{}", 1, "a") == "1-a";
}

static_assert(formatted());

}  // namespace lbal_fp
#endif
