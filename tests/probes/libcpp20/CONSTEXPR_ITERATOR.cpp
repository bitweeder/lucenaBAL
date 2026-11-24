/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_ITERATOR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP20_CONSTEXPR_ITERATOR`, from
  P1032R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP20_CONSTEXPR_ITERATOR
  //	std
  #include <iterator>

namespace lbal_fp {

//	P1032R1 made the insert iterators `constexpr`; a minimal container keeps
//	this independent of `constexpr` `std::vector`.
struct Sink {
  using value_type = int;
  int total = 0;

  constexpr void
  push_back(int v) {
    total += v;
  }
};

constexpr int
insert() {
  Sink sink;
  auto it = std::back_inserter(sink);
  *it = 2;
  ++it;
  *it = 3;
  return sink.total;
}

static_assert(insert() == 5);

}  // namespace lbal_fp
#endif
