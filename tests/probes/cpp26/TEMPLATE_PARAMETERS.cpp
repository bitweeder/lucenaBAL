/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “TEMPLATE_PARAMETERS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP26_TEMPLATE_PARAMETERS`, from
  P2841R7. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP26_TEMPLATE_PARAMETERS
  //	std
  #include <concepts>

namespace lbal_fp {

template <template <class> concept C, class T>
constexpr bool satisfies = C<T>;

template <template <class> auto V>
constexpr bool first_of = V<int>;

template <class T>
constexpr bool always = true;

static_assert(satisfies<std::integral, int>);
static_assert(first_of<always>);

}  // namespace lbal_fp
#endif
