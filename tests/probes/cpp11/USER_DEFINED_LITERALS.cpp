/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “USER_DEFINED_LITERALS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP11_USER_DEFINED_LITERALS`, from
  N2765. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP11_USER_DEFINED_LITERALS
namespace lbal_fp {

constexpr unsigned long long
operator""_twice (unsigned long long v) {
  return v * 2;
}

static_assert(21_twice == 42, "");

}  // namespace lbal_fp
#endif
