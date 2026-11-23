/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONCEPTS_CONDITIONAL_NOEXCEPT.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP2D_CONCEPTS_CONDITIONAL_NOEXCEPT`,
  from P3822R2. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: written from P3822R2; not yet compiled by any compiler available
  here.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP2D_CONCEPTS_CONDITIONAL_NOEXCEPT
namespace lbal_fp {

template <class T>
concept NoThrowCallable = requires (T t) {
  { t() } noexcept
  (true);
};

struct Safe {
  void
  operator() () noexcept { }
};

static_assert(NoThrowCallable<Safe>);

}  // namespace lbal_fp
#endif
