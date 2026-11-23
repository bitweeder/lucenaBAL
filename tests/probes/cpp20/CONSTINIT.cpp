/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTINIT.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_CONSTINIT`, from P1143R2. It only
  needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_CONSTINIT
namespace lbal_fp {

constinit int global = 42;
constinit thread_local int per_thread = 1;

}  // namespace lbal_fp
#endif
