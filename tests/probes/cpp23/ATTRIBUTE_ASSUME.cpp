/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “ATTRIBUTE_ASSUME.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP23_ATTRIBUTE_ASSUME`, from CWG2615
  and P1774R8. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP23_ATTRIBUTE_ASSUME
namespace lbal_fp {

inline int
halve(int x) {
  [[assume(x > 0)]];
  return x / 2;
}

}  // namespace lbal_fp
#endif
