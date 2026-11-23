/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “DEDUCTION_GUIDES_NB.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_DEDUCTION_GUIDES_NB`, from
  P0512R0. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_DEDUCTION_GUIDES_NB
  //	std
  #include <type_traits>

namespace lbal_fp {

template <class T>
struct Wrap {
  Wrap(T x)
    : value(x) { }

  T value;
};

//	The copy deduction candidate wins (P0512R0).
static_assert(std::is_same_v<decltype(Wrap{Wrap{1}}), Wrap<int>>);

}  // namespace lbal_fp
#endif
