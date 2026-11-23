/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “HEX_FLOAT.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_HEX_FLOAT`, from P0245R1. It only
  needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_HEX_FLOAT
namespace lbal_fp {

static_assert(0x1.8p1 == 3.0);

}  // namespace lbal_fp
#endif
