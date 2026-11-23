/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “RAW_STRINGS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP11_RAW_STRINGS`, from N2442. It only
  needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP11_RAW_STRINGS
namespace lbal_fp {

static_assert(sizeof(R"x(a\b)x") == 4, "");

}  // namespace lbal_fp
#endif
