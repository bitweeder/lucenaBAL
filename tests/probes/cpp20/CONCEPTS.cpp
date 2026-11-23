/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONCEPTS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_CONCEPTS`, from P0734R0. It only
  needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_CONCEPTS
  //	std
  #include <type_traits>

namespace lbal_fp {

template <class T>
concept Integral = std::is_integral_v<T>;

template <class T>
concept SignedIntegral = Integral<T> && std::is_signed_v<T>;

template <class T>
concept Addable = requires (T t) { t + t; };

//	The more constrained overload wins by subsumption.
template <Integral T>
constexpr int
pick(T) {
  return 1;
}

template <SignedIntegral T>
constexpr int
pick(T) {
  return 2;
}

static_assert(pick(1u) == 1 && pick(1) == 2);
static_assert(Addable<int> && !Addable<void*>);

}  // namespace lbal_fp
#endif
