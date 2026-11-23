/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_NON_LITERAL_VARIABLES.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP23_CONSTEXPR_NON_LITERAL_VARIABLES`,
  from P2242R3. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP23_CONSTEXPR_NON_LITERAL_VARIABLES
namespace lbal_fp {

struct NonLiteral {
  NonLiteral() { }

  ~NonLiteral() { }
};

constexpr int
f(bool b) {
  if (b)
    return 1;
  NonLiteral n;
  goto done;
done:
  return 0;
}

static_assert(f(true) == 1);

}  // namespace lbal_fp
#endif
