/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “FOLD_EXPRESSIONS_CONSTRAINTS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP26_FOLD_EXPRESSIONS_CONSTRAINTS`,
  from P2963R3. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP26_FOLD_EXPRESSIONS_CONSTRAINTS
  //	std
  #include <type_traits>

namespace lbal_fp {

template <class T>
concept Integral = std::is_integral_v<T>;

template <class T>
concept SmallIntegral = Integral<T> && (sizeof(T) <= 4);

//	The second overload is more constrained only if fold expressions take part
//	in subsumption (P2963R3).
template <class... Ts>
  requires (Integral<Ts> && ...)
constexpr int
pick(Ts...) {
  return 1;
}

template <class... Ts>
  requires (SmallIntegral<Ts> && ...)
constexpr int
pick(Ts...) {
  return 2;
}

static_assert(pick(1, 2) == 2);

}  // namespace lbal_fp
#endif
