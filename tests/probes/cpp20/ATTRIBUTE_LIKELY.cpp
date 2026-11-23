/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “ATTRIBUTE_LIKELY.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_ATTRIBUTE_LIKELY`, from P0479R5.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_ATTRIBUTE_LIKELY
namespace lbal_fp {

inline int
classify(int n) {
  switch (n) {
    [[likely]]
    case 0:
      return 1;
    default:
      return 0;
  }
}

}  // namespace lbal_fp
#endif
