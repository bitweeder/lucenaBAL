/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “LAMBDAS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP11_LAMBDAS`, from N2927. It only
  needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP11_LAMBDAS
namespace lbal_fp {

inline int
add(int x) {
  auto f = [x](int y) {
    return x + y;
  };
  return f(3);
}

}  // namespace lbal_fp
#endif
