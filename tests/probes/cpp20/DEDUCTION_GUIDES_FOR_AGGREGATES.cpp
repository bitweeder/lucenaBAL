/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “DEDUCTION_GUIDES_FOR_AGGREGATES.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_DEDUCTION_GUIDES_FOR_AGGREGATES`,
  from P1814R0 and P1816R0. It only needs to compile; see
  `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_DEDUCTION_GUIDES_FOR_AGGREGATES
  //	std
  #include <type_traits>

namespace lbal_fp {

template <class T>
struct Pair {
  T a;
  T b;
};

static_assert(std::is_same_v<decltype(Pair{1, 2}), Pair<int>>);

}  // namespace lbal_fp
#endif
