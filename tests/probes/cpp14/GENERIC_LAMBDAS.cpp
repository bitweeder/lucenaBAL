/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “GENERIC_LAMBDAS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP14_GENERIC_LAMBDAS`, from N3649. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP14_GENERIC_LAMBDAS
namespace lbal_fp {

inline int
call() {
  auto id = [](auto x) {
    return x;
  };
  return id(1) + static_cast<int>(id(2.0));
}

}  // namespace lbal_fp
#endif
