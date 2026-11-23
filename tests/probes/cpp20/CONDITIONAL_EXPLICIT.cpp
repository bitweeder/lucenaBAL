/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONDITIONAL_EXPLICIT.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_CONDITIONAL_EXPLICIT`, from
  P0892R2. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_CONDITIONAL_EXPLICIT
  //	std
  #include <type_traits>

namespace lbal_fp {

struct S {
  template <class T>
  explicit(!std::is_same_v<T, int>) S(T) { }
};

static_assert(std::is_convertible_v<int, S>);
static_assert(!std::is_convertible_v<double, S>);

}  // namespace lbal_fp
#endif
