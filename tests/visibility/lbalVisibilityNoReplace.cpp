/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalVisibilityNoReplace.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Calls `lbal_vis_replaceable()` without replacing it. This shows that the
  undecorated `LBAL_VIS_OVERLOADABLE_FUNC_IMPORT` declaration still links to
  the library’s definition (on Windows, through the import library’s thunk).

------------------------------------------------------------------------------*/

//	test
#include "lbalVisibilityLib.hpp"

//	std
#include <cstdio>

int
main() {
  int failures = 0;

  if (lbal_vis_replaceable() != 1) {
    std::fputs("lbal_vis_replaceable() did not reach the library\n", stderr);
    ++failures;
  }

  if (lbal_vis_default() != 1) {
    std::fputs("lbal_vis_default() did not reach the library\n", stderr);
    ++failures;
  }

  return failures == 0 ? 0 : 1;
}
