/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “GUARANTEED_COPY_ELISION.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_GUARANTEED_COPY_ELISION`, from
  P0135R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_GUARANTEED_COPY_ELISION
namespace lbal_fp {

struct Immovable {
  Immovable() = default;
  Immovable(const Immovable&) = delete;
  Immovable(Immovable&&) = delete;
};

inline Immovable
make() {
  return Immovable{};
}

inline void
use() {
  Immovable i = make();
  (void)i;
}

}  // namespace lbal_fp
#endif
