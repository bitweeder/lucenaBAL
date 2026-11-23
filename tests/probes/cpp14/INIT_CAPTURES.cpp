/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “INIT_CAPTURES.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP14_INIT_CAPTURES`, from N3648. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP14_INIT_CAPTURES
namespace lbal_fp {

inline int
call() {
  auto f = [v = 41]() {
    return v + 1;
  };
  return f();
}

}  // namespace lbal_fp
#endif
