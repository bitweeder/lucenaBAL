/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “PP_EMBED.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP26_PP_EMBED`, from P1967R14. It only
  needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP26_PP_EMBED
namespace lbal_fp {

//	The first bytes of this file are the start of its header comment.
constexpr unsigned char data[] = {
  #embed __FILE__ limit(2)
};

static_assert(sizeof(data) == 2 && data[0] == '/' && data[1] == '*');

}  // namespace lbal_fp
#endif
