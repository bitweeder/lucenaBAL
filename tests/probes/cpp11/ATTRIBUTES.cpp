/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “ATTRIBUTES.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP11_ATTRIBUTES`, from N2761. It only
  needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP11_ATTRIBUTES
  //	std
  #include <cstdlib>

namespace lbal_fp {

[[noreturn]]
inline void
stop() {
  std::abort();
}

struct[[]] S {
  [[]] int value;
};

}  // namespace lbal_fp
#endif
