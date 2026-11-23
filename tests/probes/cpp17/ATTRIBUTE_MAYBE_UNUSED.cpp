/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “ATTRIBUTE_MAYBE_UNUSED.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED`, from
  P0212R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED
namespace lbal_fp {

[[maybe_unused]]
inline void
f([[maybe_unused]] int x) {
  [[maybe_unused]]
  int y = 0;
}

}  // namespace lbal_fp
#endif
