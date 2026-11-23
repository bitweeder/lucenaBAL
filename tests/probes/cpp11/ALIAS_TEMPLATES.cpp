/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “ALIAS_TEMPLATES.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP11_ALIAS_TEMPLATES`, from N2258. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP11_ALIAS_TEMPLATES
  //	std
  #include <type_traits>

namespace lbal_fp {

template <class T>
using pointer_to = T*;

static_assert(std::is_same<pointer_to<int>, int*>::value, "");

}  // namespace lbal_fp
#endif
