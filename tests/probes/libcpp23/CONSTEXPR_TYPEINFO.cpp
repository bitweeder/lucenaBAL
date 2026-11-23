/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_TYPEINFO.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP23_CONSTEXPR_TYPEINFO`, from
  P1328R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP23_CONSTEXPR_TYPEINFO && LBAL_CPP03_RTTI
  //	std
  #include <typeinfo>

namespace lbal_fp {

static_assert(typeid(int) == typeid(int));
static_assert(typeid(int) != typeid(long));

}  // namespace lbal_fp
#endif
