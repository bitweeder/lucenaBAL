/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “IF_CONSTEXPR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_IF_CONSTEXPR`, from P0292R2. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_IF_CONSTEXPR
  //	std
  #include <type_traits>

namespace lbal_fp {

template <class T>
constexpr int
value_of(T t) {
  if constexpr (std::is_pointer_v<T>) {
    return *t;
  } else {
    return t;
  }
}

static_assert(value_of(3) == 3);

}  // namespace lbal_fp
#endif
