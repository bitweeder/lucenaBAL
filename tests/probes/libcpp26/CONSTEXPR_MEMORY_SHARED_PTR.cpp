/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_MEMORY_SHARED_PTR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP26_CONSTEXPR_MEMORY_SHARED_PTR`,
  from P3037R6. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: written from the paper; not yet compiled against a library that
  reports this feature.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_CONSTEXPR_MEMORY_SHARED_PTR
  //	std
  #include <memory>

namespace lbal_fp {

constexpr long
shared() {
  auto p = std::make_shared<int>(3);
  std::shared_ptr<int> q = p;
  std::weak_ptr<int> w = q;
  long owners = p.use_count();
  return *w.lock() * 10 + owners;
}

static_assert(shared() == 32);

}  // namespace lbal_fp
#endif
