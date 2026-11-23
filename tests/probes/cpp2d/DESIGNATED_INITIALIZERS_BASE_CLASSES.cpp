/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “DESIGNATED_INITIALIZERS_BASE_CLASSES.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for
  `LBAL_CPP2D_DESIGNATED_INITIALIZERS_BASE_CLASSES`, from P2287R6. It only
  needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: syntax written from P2287R6; not yet compiled by any compiler
  available here.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP2D_DESIGNATED_INITIALIZERS_BASE_CLASSES
namespace lbal_fp {

struct A {
  int a;
};

struct B : A {
  int b;
};

constexpr B x{: A{.a = 1}, .b = 2};
static_assert(x.a == 1 && x.b == 2);

}  // namespace lbal_fp
#endif
