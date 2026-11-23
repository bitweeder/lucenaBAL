/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “TRIVIAL_UNION.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP26_TRIVIAL_UNION`, from P3074R7. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: written from P3074R7; not yet compiled by any compiler available
  here.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP26_TRIVIAL_UNION
  //	std
  #include <type_traits>

namespace lbal_fp {

struct NonTrivial {
  NonTrivial() { }

  ~NonTrivial() { }
};

//	A union’s default constructor and destructor are trivial even with a
//	non-trivial member (P3074R7).
union U {
  NonTrivial n;
};

static_assert(std::is_trivially_default_constructible_v<U>);
static_assert(std::is_trivially_destructible_v<U>);

}  // namespace lbal_fp
#endif
