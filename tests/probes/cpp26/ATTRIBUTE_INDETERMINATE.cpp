/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “ATTRIBUTE_INDETERMINATE.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP26_ATTRIBUTE_INDETERMINATE`, from
  P2795R5. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP26_ATTRIBUTE_INDETERMINATE
namespace lbal_fp {

inline int
fill() {
  [[indeterminate]]
  int x;
  x = 1;
  return x;
}

}  // namespace lbal_fp
#endif
