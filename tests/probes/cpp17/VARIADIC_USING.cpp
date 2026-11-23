/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “VARIADIC_USING.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_VARIADIC_USING`, from P0195R2. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_VARIADIC_USING
namespace lbal_fp {

template <class... Fs>
struct overload : Fs... {
  using Fs::operator()...;
};

template <class... Fs>
overload(Fs...) -> overload<Fs...>;

constexpr overload pick{
  [](int) {
    return 1;
  },
  [](double) {
    return 2;
  }
};

static_assert(pick(1) == 1 && pick(1.0) == 2);

}  // namespace lbal_fp
#endif
