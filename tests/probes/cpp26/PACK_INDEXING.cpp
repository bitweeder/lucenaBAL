/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “PACK_INDEXING.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP26_PACK_INDEXING`, from P2662R3. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP26_PACK_INDEXING
  //	std
  #include <type_traits>

namespace lbal_fp {

template <class... Ts>
using first = Ts...[0];

template <auto... Vs>
constexpr auto second = Vs...[1];

static_assert(std::is_same_v<first<int, char>, int>);
static_assert(second<1, 2, 3> == 2);

}  // namespace lbal_fp
#endif
