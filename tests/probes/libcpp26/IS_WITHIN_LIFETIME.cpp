/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “IS_WITHIN_LIFETIME.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP26_IS_WITHIN_LIFETIME`, from
  P2641R4. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: written from the paper; not yet compiled against a library that
  reports this feature.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_IS_WITHIN_LIFETIME
  //	std
  #include <type_traits>

namespace lbal_fp {

union U {
  int a;
  float b;
};

consteval bool
active() {
  U u{.a = 1};
  return std::is_within_lifetime(&u.a) && !std::is_within_lifetime(&u.b);
}

static_assert(active());

}  // namespace lbal_fp
#endif
