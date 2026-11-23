/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONTRACTS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP26_CONTRACTS`, from P2900R14. It only
  needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: no compiler available here implements contracts, so this hasn’t been
  compiled.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP26_CONTRACTS
namespace lbal_fp {

inline int
positive(int x) pre(x > 0) post(r : r > 0) {
  contract_assert(x > 0);
  return x;
}

}  // namespace lbal_fp
#endif
