/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “IMPL_REFLECTION_CLEANUP.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP26_IMPL_REFLECTION_CLEANUP`, from
  P3795R2. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: smoke test only; it doesn’t isolate the P3795R2 changes.

  LBAL_FP_SMOKE: it also passes with only P2996R13, so it can’t detect a false
  negative.

  It uses only the core language (`^^`, splicing and comparing reflections),
  so it doesn’t depend on the library’s `<meta>`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP26_IMPL_REFLECTION_CLEANUP
namespace lbal_fp {

static_assert(^^int != ^^long);

}  // namespace lbal_fp
#endif
