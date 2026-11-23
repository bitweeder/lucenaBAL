/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “VARIADIC_TEMPLATES.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP11_VARIADIC_TEMPLATES`, from N2242.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP11_VARIADIC_TEMPLATES
  //	std
  #include <cstddef>

namespace lbal_fp {

template <class... Ts>
constexpr std::size_t
count() {
  return sizeof...(Ts);
}

static_assert(count<int, char, long>() == 3, "");

}  // namespace lbal_fp
#endif
