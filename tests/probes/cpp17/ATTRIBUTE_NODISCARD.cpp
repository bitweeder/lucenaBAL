/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “ATTRIBUTE_NODISCARD.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_ATTRIBUTE_NODISCARD`, from
  P0189R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_ATTRIBUTE_NODISCARD
namespace lbal_fp {

struct [[nodiscard]] Result { };

[[nodiscard]]
inline int
compute() {
  return 1;
}

}  // namespace lbal_fp
#endif
