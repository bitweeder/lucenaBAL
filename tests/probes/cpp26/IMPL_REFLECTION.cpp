/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “IMPL_REFLECTION.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP26_IMPL_REFLECTION`, from P2996R13
  and P3096R12 and P3293R3 and P3394R4. It only needs to compile; see
  `lbalFalsePositiveTest.cpp`.

  SEEME: written from P2996R13; not yet compiled by any compiler available
  here.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP26_IMPL_REFLECTION && __has_include(<meta>)
  //	std
  #include <meta>
  #include <type_traits>

namespace lbal_fp {

constexpr auto r = ^^int;

static_assert(std::meta::is_type(r));
static_assert(std::is_same_v<[:r:], int>);

}  // namespace lbal_fp
#endif
