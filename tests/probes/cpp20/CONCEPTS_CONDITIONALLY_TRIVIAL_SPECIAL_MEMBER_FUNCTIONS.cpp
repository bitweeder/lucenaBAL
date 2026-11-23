/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONCEPTS_CONDITIONALLY_TRIVIAL_SPECIAL_MEMBER_FUNCTIONS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for
  `LBAL_CPP20_CONCEPTS_CONDITIONALLY_TRIVIAL_SPECIAL_MEMBER_FUNCTIONS`, from
  P0848R3. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_CONCEPTS_CONDITIONALLY_TRIVIAL_SPECIAL_MEMBER_FUNCTIONS
  //	std
  #include <type_traits>

namespace lbal_fp {

struct NonTrivial {
  NonTrivial() = default;

  NonTrivial(const NonTrivial&) { }
};

template <class T>
struct Wrap {
  Wrap() = default;
  Wrap(const Wrap&)
    requires std::is_trivially_copy_constructible_v<T>
  = default;

  Wrap(const Wrap&) { }
};

static_assert(std::is_trivially_copy_constructible_v<Wrap<int>>);
static_assert(!std::is_trivially_copy_constructible_v<Wrap<NonTrivial>>);

}  // namespace lbal_fp
#endif
