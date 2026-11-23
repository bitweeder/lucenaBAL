/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “BINARY_LITERALS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP14_BINARY_LITERALS`, from N3472. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP14_BINARY_LITERALS
namespace lbal_fp {

static_assert(0b1010 == 10, "");

}  // namespace lbal_fp
#endif
