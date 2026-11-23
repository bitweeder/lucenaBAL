/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONCEPTS_RESPECIFY_RETURN_TYPE_REQUIREMENTS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for
  `LBAL_CPP20_CONCEPTS_RESPECIFY_RETURN_TYPE_REQUIREMENTS`, from P1084R2. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_CONCEPTS_RESPECIFY_RETURN_TYPE_REQUIREMENTS
  //	std
  #include <concepts>
  #include <cstddef>

namespace lbal_fp {

template <class T>
concept Sizable = requires (T t) {
  { t.size() } -> std::convertible_to<std::size_t>;
};

struct HasSize {
  int
  size() const {
    return 0;
  }
};

static_assert(Sizable<HasSize>);
static_assert(!Sizable<int>);

}  // namespace lbal_fp
#endif
