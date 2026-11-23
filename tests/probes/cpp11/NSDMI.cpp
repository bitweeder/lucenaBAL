/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “NSDMI.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP11_NSDMI`, from N2756. It only needs
  to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP11_NSDMI
namespace lbal_fp {

struct S {
  int value = 42;
};

static_assert(S().value == 42, "");

}  // namespace lbal_fp
#endif
