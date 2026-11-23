/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “VA_OPT.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_VA_OPT`. It only needs to compile;
  see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_VA_OPT
namespace lbal_fp {

  #define LBAL_FP_COUNT(...) (0 __VA_OPT__(+1))

static_assert(LBAL_FP_COUNT() == 0);
static_assert(LBAL_FP_COUNT(x) == 1);

  #undef LBAL_FP_COUNT

}  // namespace lbal_fp
#endif
