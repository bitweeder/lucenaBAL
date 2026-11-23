/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for
  `LBAL_CPP20_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS`. It only needs to
  compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS
namespace lbal_fp {

struct S {
  constexpr int
  f() const & {
    return 1;
  }
};

//	A `const&`-qualified member can be called on an rvalue through a pointer to
//	member (P0704R1).
static_assert((S{}.*&S::f)() == 1);

}  // namespace lbal_fp
#endif
