/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEVAL_PROPAGATE_UP.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP23_CONSTEVAL_PROPAGATE_UP`, from
  P2564R3. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP23_CONSTEVAL_PROPAGATE_UP
namespace lbal_fp {

consteval int
id(int x) {
  return x;
}

//	`g` becomes an immediate function because it calls `id` with a
//	non-constant argument (P2564R3).
template <class T>
constexpr int
g(T t) {
  return id(t);
}

static_assert(g(1) == 1);

}  // namespace lbal_fp
#endif
