/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “TYPENAME_OPTIONAL.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_TYPENAME_OPTIONAL`. It only needs
  to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_TYPENAME_OPTIONAL
  //	std
  #include <type_traits>

namespace lbal_fp {

template <class T>
struct X {
  using R = T::value_type;
};

struct V {
  using value_type = int;
};

static_assert(std::is_same_v<X<V>::R, int>);

}  // namespace lbal_fp
#endif
