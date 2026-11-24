/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “DEDUCTION_GUIDES_DR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_DEDUCTION_GUIDES_DR`, from
  P0620R0. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: checks P0702R1-style copy deduction; P0620R0 is mostly wording.

  LBAL_FP_SMOKE: it also passes with the C++17 deduction rules, so it can’t
  detect a false negative.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_DEDUCTION_GUIDES_DR
  //	std
  #include <type_traits>
  #include <vector>

namespace lbal_fp {

//	Copy deduction is preferred for a single element of a specialization.
inline std::vector v{std::vector<int>{1, 2}};

static_assert(std::is_same_v<decltype(v), std::vector<int>>);

}  // namespace lbal_fp
#endif
