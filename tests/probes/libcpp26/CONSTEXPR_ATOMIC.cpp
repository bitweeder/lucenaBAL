/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_ATOMIC.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP26_CONSTEXPR_ATOMIC`, from
  P3309R3. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: written from the paper; not yet compiled against a library that
  reports this feature.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_CONSTEXPR_ATOMIC
  //	std
  #include <atomic>

namespace lbal_fp {

constexpr int
counted() {
  std::atomic<int> a{1};
  a.fetch_add(2);
  int plain = 4;
  std::atomic_ref<int> r(plain);
  r.store(5);
  return a.load() * 10 + plain;
}

static_assert(counted() == 35);

}  // namespace lbal_fp
#endif
