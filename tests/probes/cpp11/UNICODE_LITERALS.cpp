/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “UNICODE_LITERALS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP11_UNICODE_LITERALS`, from N2442. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP11_UNICODE_LITERALS
namespace lbal_fp {

static_assert(u"é"[0] == 0xE9, "");
static_assert(U"\U0001F600"[0] == 0x1'F600, "");
static_assert(sizeof(u8"é") == 3, "");

}  // namespace lbal_fp
#endif
