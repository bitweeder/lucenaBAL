/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “ATTRIBUTE_NO_UNIQUE_ADDRESS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_ATTRIBUTE_NO_UNIQUE_ADDRESS`, from
  P0840R2. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  The attribute must have its effect, not just be accepted: MSVC (and
  clang-cl) accept `[[no_unique_address]]` but ignore it to keep their ABI
  stable, and use `[[msvc::no_unique_address]]` instead (see
  `LBAL_NO_UNIQUE_ADDRESS`). The false-negative tests use only this probe, so
  the layout check is here as well as in the soft probe.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_ATTRIBUTE_NO_UNIQUE_ADDRESS
namespace lbal_fp {

struct Empty { };

struct S {
  int i;
  [[no_unique_address]]
  Empty e;
};

static_assert(sizeof(S) == sizeof(int));

}  // namespace lbal_fp
#endif
