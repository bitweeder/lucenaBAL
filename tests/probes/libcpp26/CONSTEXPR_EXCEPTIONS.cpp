/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_EXCEPTIONS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP26_CONSTEXPR_EXCEPTIONS`, from
  P3378R2. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: written from the paper; not yet compiled against a library that
  reports this feature.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_CONSTEXPR_EXCEPTIONS && LBAL_CPP03_EXCEPTIONS
  //	std
  #include <stdexcept>

namespace lbal_fp {

constexpr bool
caught() {
  try {
    throw std::out_of_range("x");
  } catch (const std::logic_error& e) {
    return e.what()[0] == 'x';
  }
  return false;
}

static_assert(caught());

}  // namespace lbal_fp
#endif
