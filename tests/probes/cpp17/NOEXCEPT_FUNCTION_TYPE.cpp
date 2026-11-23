/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “NOEXCEPT_FUNCTION_TYPE.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE`, from
  P0012R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE
  //	std
  #include <type_traits>

namespace lbal_fp {

void throwing();
void nonthrowing() noexcept;

static_assert(!std::is_same_v<decltype(throwing), decltype(nonthrowing)>);

}  // namespace lbal_fp
#endif
