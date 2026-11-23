/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CAPTURE_STAR_THIS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_CAPTURE_STAR_THIS`, from P0018R3.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_CAPTURE_STAR_THIS
namespace lbal_fp {

struct S {
  int value = 42;

  constexpr int
  get() const {
    return [*this] {
      return value;
    }();
  }
};

static_assert(S{}.get() == 42);

}  // namespace lbal_fp
#endif
