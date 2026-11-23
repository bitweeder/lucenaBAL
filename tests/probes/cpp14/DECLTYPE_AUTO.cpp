/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “DECLTYPE_AUTO.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP14_DECLTYPE_AUTO`, from N3638. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP14_DECLTYPE_AUTO
  //	std
  #include <type_traits>

namespace lbal_fp {

extern int value;

inline decltype(auto)
ref() {
  return (value);
}

static_assert(std::is_same<decltype(ref()), int&>::value, "");

}  // namespace lbal_fp
#endif
