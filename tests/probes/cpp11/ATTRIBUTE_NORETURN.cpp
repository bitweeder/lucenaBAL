/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “ATTRIBUTE_NORETURN.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP11_ATTRIBUTE_NORETURN`, from N2761.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP11_ATTRIBUTE_NORETURN
  //	std
  #include <cstdlib>

namespace lbal_fp {

[[noreturn]]
inline void
stop() {
  std::abort();
}

inline int
checked(bool b) {
  if (b)
    return 1;
  stop();
}

}  // namespace lbal_fp
#endif
