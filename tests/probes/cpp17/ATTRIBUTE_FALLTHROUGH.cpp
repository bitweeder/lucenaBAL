/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “ATTRIBUTE_FALLTHROUGH.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_ATTRIBUTE_FALLTHROUGH`, from
  P0188R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_ATTRIBUTE_FALLTHROUGH
namespace lbal_fp {

inline int
count(int n) {
  int r = 0;
  switch (n) {
    case 0:
      r += 1;
      [[fallthrough]];
    case 1:
      r += 1;
      break;
    default:
      break;
  }
  return r;
}

}  // namespace lbal_fp
#endif
