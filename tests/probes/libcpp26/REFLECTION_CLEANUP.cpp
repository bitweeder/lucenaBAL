/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “REFLECTION_CLEANUP.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP26_REFLECTION_CLEANUP`, from
  P3795R2. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: smoke test only; it doesn’t isolate the P3795R2 changes.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_REFLECTION_CLEANUP
  //	std
  #include <meta>

namespace lbal_fp {

static_assert(std::meta::is_type(^^int));

}  // namespace lbal_fp
#endif
