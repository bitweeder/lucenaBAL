/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for
  `LBAL_CPP20_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS`. It only needs to
  compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS
namespace lbal_fp {

struct S {
  int a : 4 = 3;
};

static_assert(S{}.a == 3);

}  // namespace lbal_fp
#endif
