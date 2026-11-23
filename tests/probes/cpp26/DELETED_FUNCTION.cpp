/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “DELETED_FUNCTION.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP26_DELETED_FUNCTION`, from P2573R2.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP26_DELETED_FUNCTION
namespace lbal_fp {

void legacy(int) = delete ("use modern(int) instead");

}  // namespace lbal_fp
#endif
