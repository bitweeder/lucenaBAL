/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “INLINE_VARIABLES.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_INLINE_VARIABLES`, from P0386R2.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_INLINE_VARIABLES
namespace lbal_fp {

inline int counter = 0;

struct S {
  static inline int instances = 0;
  static constexpr int limit = 4;
};

static_assert(S::limit == 4);

}  // namespace lbal_fp
#endif
