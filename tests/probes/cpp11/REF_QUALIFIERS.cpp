/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “REF_QUALIFIERS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP11_REF_QUALIFIERS`, from N2439. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP11_REF_QUALIFIERS
namespace lbal_fp {

struct S {
  constexpr int
  which() const & {
    return 1;
  }

  constexpr int
  which() && {
    return 2;
  }
};

static_assert(S().which() == 2, "");

}  // namespace lbal_fp
#endif
