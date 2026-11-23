/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “START_LIFETIME.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP26_START_LIFETIME`, from P3726R2.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: written from the paper; not yet compiled against a library that
  reports this feature.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_START_LIFETIME
  //	std
  #include <memory>

namespace lbal_fp {

union Storage {
  int values[2];
};

constexpr int
fill() {
  Storage s;
  std::start_lifetime(s.values);
  s.values[0] = 1;
  s.values[1] = 2;
  return s.values[0] + s.values[1];
}

static_assert(fill() == 3);

}  // namespace lbal_fp
#endif
