/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “TRIVIAL_UNION_LIFETIME.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP26_TRIVIAL_UNION_LIFETIME`, from
  P3726R2. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  P3726R2 reverts P3074R7’s rule that a union’s default constructor starts its
  first member’s lifetime, adds `std::start_lifetime` to make an
  implicit-lifetime aggregate member active, and lets an array member of a
  union have elements outside their lifetime in a constant expression. This
  probe follows the paper’s example and needs both the library function and
  the language rule: without the paper, `std::start_lifetime` is missing and
  `v` isn’t a constant expression. There is no core-only form, since
  constructing an element no longer starts the array’s lifetime.

  `LBAL_LIBCPP26_START_LIFETIME` reports `std::start_lifetime`. A compiler with
  the language rule paired with a library that lacks the function fails this
  probe. The body isn’t gated on that token as well, because the false-negative
  test forces only this one, and an empty probe would compile.

  SEEME: written from P3726R2; not yet compiled by any compiler available
  here.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP26_TRIVIAL_UNION_LIFETIME
  //	std
  #include <memory>

namespace lbal_fp {

struct Holder {
  union {
    int values[4];
  };

  //	`values` becomes the active member; none of its elements is alive yet.
  constexpr Holder() { std::start_lifetime(values); }
};

constexpr Holder
make() {
  Holder h;
  std::construct_at(&h.values[1], 1);
  return h;
}

//	`values[0]`, `[2]` and `[3]` are outside their lifetime.
constexpr Holder v = make();

static_assert(v.values[1] == 1);

}  // namespace lbal_fp
#endif
