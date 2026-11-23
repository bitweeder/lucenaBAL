/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “PP_EMBED_OFFSET.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP2D_PP_EMBED_OFFSET`, from P3540R3. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP2D_PP_EMBED_OFFSET
namespace lbal_fp {

constexpr unsigned char data[] = {
  #embed __FILE__ offset(1) limit(1)
};

static_assert(sizeof(data) == 1 && data[0] == '*');

}  // namespace lbal_fp
#endif
