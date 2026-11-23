/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “FOLD_EXPRESSIONS_REVISED.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_FOLD_EXPRESSIONS_REVISED`, from
  P0036R0. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_FOLD_EXPRESSIONS_REVISED
namespace lbal_fp {

//	Unary folds over `&&` accept an empty pack…
template <class... Ts>
constexpr bool
all(Ts... ts) {
  return (ts && ...);
}

static_assert(all());
static_assert(all(true, true));

//	…but an empty unary fold over `+` is ill-formed (P0036R0).
template <class... Ts>
constexpr auto
plus_fold(Ts... ts) -> decltype((ts + ...)) {
  return (ts + ...);
}

template <class... Ts>
constexpr auto
can_plus_fold(int) -> decltype(plus_fold(Ts{}...), true) {
  return true;
}

template <class... Ts>
constexpr bool
can_plus_fold(...) {
  return false;
}

static_assert(can_plus_fold<int>(0));
static_assert(!can_plus_fold<>(0));

}  // namespace lbal_fp
#endif
