/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “RETURN_TYPE_DEDUCTION.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP14_RETURN_TYPE_DEDUCTION`, from
  N3638. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP14_RETURN_TYPE_DEDUCTION
  //	std
  #include <type_traits>

namespace lbal_fp {

inline auto
answer() {
  return 42;
}

static_assert(std::is_same<decltype(answer()), int>::value, "");

}  // namespace lbal_fp
#endif
