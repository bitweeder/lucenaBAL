/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for
  `LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS`. It only
  needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS
  //	std
  #include <type_traits>

namespace lbal_fp {

inline constexpr auto stateless = [](int x) {
  return x;
};

using Lambda = std::remove_cv_t<decltype(stateless)>;

static_assert(std::is_default_constructible_v<Lambda>);
static_assert(std::is_copy_assignable_v<Lambda>);

}  // namespace lbal_fp
#endif
