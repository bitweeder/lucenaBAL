/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “STATIC_ASSERT_NO_MESSAGE.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE`, from
  N3928. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE
namespace lbal_fp {

static_assert(true);

}  // namespace lbal_fp
#endif
