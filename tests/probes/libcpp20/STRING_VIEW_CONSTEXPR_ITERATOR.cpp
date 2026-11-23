/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “STRING_VIEW_CONSTEXPR_ITERATOR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for
  `LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR`, from LWG3257 and P0858R0. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP20_STRING_VIEW_CONSTEXPR_ITERATOR
  //	std
  #include <string_view>

namespace lbal_fp {

constexpr int
count_l() {
  constexpr std::string_view sv = "hello";
  int n = 0;
  for (auto it = sv.begin(); it != sv.end(); ++it)
    n += (*it == 'l');
  return n;
}

static_assert(count_l() == 2);

}  // namespace lbal_fp
#endif
