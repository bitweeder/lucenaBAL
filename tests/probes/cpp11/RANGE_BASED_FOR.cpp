/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “RANGE_BASED_FOR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP11_RANGE_BASED_FOR`, from N2930. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP11_RANGE_BASED_FOR
namespace lbal_fp {

inline int
sum() {
  int a[] = {1, 2, 3};
  int s = 0;
  for (int x : a)
    s += x;
  return s;
}

}  // namespace lbal_fp
#endif
