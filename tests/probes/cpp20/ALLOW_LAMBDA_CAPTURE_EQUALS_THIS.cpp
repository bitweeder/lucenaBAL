/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “ALLOW_LAMBDA_CAPTURE_EQUALS_THIS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS`.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS
namespace lbal_fp {

struct S {
  int value = 1;

  constexpr int
  get() {
    return [=, this] {
      return value;
    }();
  }
};

static_assert(S{}.get() == 1);

}  // namespace lbal_fp
#endif
