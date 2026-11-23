/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “ATTRIBUTES_LIKELY_AND_UNLIKELY.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_ATTRIBUTES_LIKELY_AND_UNLIKELY`.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_ATTRIBUTES_LIKELY_AND_UNLIKELY
namespace lbal_fp {

inline int
classify(int n) {
  if (n > 0) [[likely]] {
    return 1;
  } else [[unlikely]] {
    return 0;
  }
}

}  // namespace lbal_fp
#endif
