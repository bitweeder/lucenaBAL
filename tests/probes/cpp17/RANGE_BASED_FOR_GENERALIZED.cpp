/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “RANGE_BASED_FOR_GENERALIZED.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED`, from
  P0184R0. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED
namespace lbal_fp {

struct Sentinel { };

struct Iterator {
  int i;

  constexpr int
  operator* () const {
    return i;
  }

  constexpr Iterator&
  operator++ () {
    ++i;
    return *this;
  }

  constexpr bool
  operator!= (Sentinel) const {
    return i < 3;
  }
};

struct Range {
  constexpr Iterator
  begin() const {
    return {0};
  }

  constexpr Sentinel
  end() const {
    return {};
  }
};

constexpr int
sum() {
  int s = 0;
  for (int x : Range{})
    s += x;
  return s;
}

static_assert(sum() == 3);

}  // namespace lbal_fp
#endif
