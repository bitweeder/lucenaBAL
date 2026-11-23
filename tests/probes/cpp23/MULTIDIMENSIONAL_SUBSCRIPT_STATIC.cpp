/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “MULTIDIMENSIONAL_SUBSCRIPT_STATIC.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for
  `LBAL_CPP23_MULTIDIMENSIONAL_SUBSCRIPT_STATIC`, from P2589R1. It only needs
  to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP23_MULTIDIMENSIONAL_SUBSCRIPT_STATIC
namespace lbal_fp {

struct Grid {
  static constexpr int
  operator[] (int i, int j) {
    return i * 10 + j;
  }
};

static_assert(Grid{}[1, 2] == 12);

}  // namespace lbal_fp
#endif
