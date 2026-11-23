/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_IN_DECLTYPE.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_CONSTEXPR_IN_DECLTYPE`, from
  P0859R0. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_CONSTEXPR_IN_DECLTYPE
namespace lbal_fp {

//	From P0859R0: `f<T>` must not be instantiated in an unevaluated operand
//	when it isn’t needed for constant evaluation.
template <class T>
constexpr int
f() {
  return T::value;
}

template <bool B, class T>
void g(decltype(B ? f<T>() : 0));

template <bool B, class T>
void g(...);

inline void
call() {
  g<false, int>(0);
}

}  // namespace lbal_fp
#endif
