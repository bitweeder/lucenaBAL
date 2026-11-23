/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “ATTRIBUTE_NO_UNIQUE_ADDRESS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_ATTRIBUTE_NO_UNIQUE_ADDRESS`, from
  P0840R2. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  The layout effect is checked by the soft probe.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_ATTRIBUTE_NO_UNIQUE_ADDRESS
namespace lbal_fp {

struct Empty { };

struct S {
  int i;
  [[no_unique_address]]
  Empty e;
};

}  // namespace lbal_fp
#endif
