/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “DESIGNATED_INITIALIZERS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_DESIGNATED_INITIALIZERS`, from
  P0329R4. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_DESIGNATED_INITIALIZERS
namespace lbal_fp {

struct Point {
  int x;
  int y;
};

constexpr Point p{.x = 1, .y = 2};
static_assert(p.y == 2);

}  // namespace lbal_fp
#endif
