/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “THREE_WAY_COMPARISON_OPERATOR_TUNEUP.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for
  `LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_TUNEUP`, from P1630R1. It only
  needs to compile; see `lbalFalsePositiveTest.cpp`.

  It checks the paper’s Annex C change: `x != y` is rewritten from `x == y`
  only if that has type `bool`. Before, a result contextually convertible to
  `bool` was enough.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_TUNEUP
namespace lbal_fp {

struct NotBool {
  explicit
  operator bool() const {
    return true;
  }
};

struct X {
  friend NotBool
  operator== (X, int) {
    return {};
  }
};

template <class T>
concept has_not_equal = requires (T t) { t != 4; };

static_assert(!has_not_equal<X>);

}  // namespace lbal_fp
#endif
