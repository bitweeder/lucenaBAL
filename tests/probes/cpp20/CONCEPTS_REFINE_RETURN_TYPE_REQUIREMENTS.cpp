/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONCEPTS_REFINE_RETURN_TYPE_REQUIREMENTS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for
  `LBAL_CPP20_CONCEPTS_REFINE_RETURN_TYPE_REQUIREMENTS`, from P1452R2. It only
  needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_CONCEPTS_REFINE_RETURN_TYPE_REQUIREMENTS
  //	std
  #include <concepts>

namespace lbal_fp {

template <class T>
concept Doubling = requires (T t) {
  { t + t } -> std::same_as<T>;
};

static_assert(Doubling<int>);
static_assert(!Doubling<char>);

}  // namespace lbal_fp
#endif
