/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “TRIVIAL_UNION_LIFETIME.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP26_TRIVIAL_UNION_LIFETIME`, from
  P3726R2. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: written from P3726R2; not yet compiled by any compiler available
  here.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP26_TRIVIAL_UNION_LIFETIME
  //	std
  #include <memory>

namespace lbal_fp {

//	Constructing an array member of a union starts the array’s lifetime, so
//	its elements can be set one at a time during constant evaluation.
union Storage {
  int values[2];
};

constexpr int
fill() {
  Storage s;
  std::construct_at(&s.values[0], 1);
  std::construct_at(&s.values[1], 2);
  return s.values[0] + s.values[1];
}

static_assert(fill() == 3);

}  // namespace lbal_fp
#endif
