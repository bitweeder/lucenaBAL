/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “STATIC_ASSERT.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP11_STATIC_ASSERT`, from N1720. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP11_STATIC_ASSERT
namespace lbal_fp {

static_assert(true, "message");

}  // namespace lbal_fp
#endif
