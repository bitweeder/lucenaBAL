/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “RVALUE_REFERENCES.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP11_RVALUE_REFERENCES`, from N2118. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP11_RVALUE_REFERENCES
namespace lbal_fp {

constexpr int
bind(int&) {
  return 1;
}

constexpr int
bind(int&&) {
  return 2;
}

static_assert(bind(1) == 2, "");

}  // namespace lbal_fp
#endif
