/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “REFLECTION_RENAME_TO_IS_VARARG_FUNCTION.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for
  `LBAL_LIBCPP26_REFLECTION_RENAME_TO_IS_VARARG_FUNCTION`, from P4156R0. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: written from the paper; not yet compiled against a library that
  reports this feature.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_REFLECTION_RENAME_TO_IS_VARARG_FUNCTION
  //	std
  #include <meta>

namespace lbal_fp {

void plain(int);
void varargs(int, ...);

static_assert(std::meta::is_vararg_function(^^varargs));
static_assert(!std::meta::is_vararg_function(^^plain));

}  // namespace lbal_fp
#endif
