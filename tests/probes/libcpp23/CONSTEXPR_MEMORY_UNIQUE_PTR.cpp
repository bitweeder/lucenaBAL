/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_MEMORY_UNIQUE_PTR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP23_CONSTEXPR_MEMORY_UNIQUE_PTR`,
  from P2273R3. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP23_CONSTEXPR_MEMORY_UNIQUE_PTR
  //	std
  #include <memory>
  #include <utility>

namespace lbal_fp {

constexpr int
owned() {
  auto p = std::make_unique<int>(4);
  std::unique_ptr<int> q = std::move(p);
  *q += 1;
  return p ? -1 : *q;
}

static_assert(owned() == 5);

}  // namespace lbal_fp
#endif
