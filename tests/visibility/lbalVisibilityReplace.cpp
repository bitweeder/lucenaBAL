/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalVisibilityReplace.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Replaces `lbal_vis_replaceable()` from the shared library. That this builds
  at all shows that `LBAL_VIS_OVERLOADABLE_FUNC_IMPORT` lets a client define
  the function (on MSVC, defining a `dllimport` function is error C2491).
  The client’s own calls must reach its replacement, while ordinary imports
  still reach the library.

  Calls from inside the library aren’t checked: whether they reach the
  replacement depends on the platform (yes with ELF symbol interposition, no
  with Apple’s two-level namespace or Windows DLLs).

------------------------------------------------------------------------------*/

//	test
#include "lbalVisibilityLib.hpp"

//	std
#include <cstdio>

int
lbal_vis_replaceable() {
  return 2;
}

int
main() {
  int failures = 0;

  if (lbal_vis_replaceable() != 2) {
    std::fputs(
        "lbal_vis_replaceable() did not reach the replacement\n", stderr
    );
    ++failures;
  }

  if (lbal_vis_default() != 1) {
    std::fputs("lbal_vis_default() did not reach the library\n", stderr);
    ++failures;
  }

  return failures == 0 ? 0 : 1;
}
