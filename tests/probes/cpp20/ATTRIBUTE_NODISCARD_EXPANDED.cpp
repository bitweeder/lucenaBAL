/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “ATTRIBUTE_NODISCARD_EXPANDED.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_ATTRIBUTE_NODISCARD_EXPANDED`,
  from P1301R4 and P1771R1. It only needs to compile; see
  `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_ATTRIBUTE_NODISCARD_EXPANDED
namespace lbal_fp {

[[nodiscard("check the result")]]
inline int
compute() {
  return 1;
}

struct S {
  [[nodiscard]]
  S() { }
};

}  // namespace lbal_fp
#endif
