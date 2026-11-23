/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEVAL_ONLY.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP2D_CONSTEVAL_ONLY`, from P4101R1. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: smoke test only; it doesn’t isolate the P4101R1 changes.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP2D_CONSTEVAL_ONLY && __has_include(<meta>)
  //	std
  #include <meta>

namespace lbal_fp {

static_assert(std::meta::is_type(^^int));

}  // namespace lbal_fp
#endif
