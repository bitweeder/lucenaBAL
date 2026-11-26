/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_INPLACE_VECTOR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP26_CONSTEXPR_INPLACE_VECTOR`, from
  P3074R7. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  P3074R7 makes `inplace_vector` usable in constant evaluation for element
  types that aren’t trivial, so this uses `std::string`.

  SEEME: written from the paper; not yet compiled against a library that
  reports this feature.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_CONSTEXPR_INPLACE_VECTOR
  //	std
  #include <inplace_vector>
  #include <string>

namespace lbal_fp {

constexpr std::size_t
use() {
  std::inplace_vector<std::string, 2> v;
  v.emplace_back("a");
  v.push_back(std::string("bc"));
  return v[1].size() * 10 + v.size();
}

static_assert(use() == 22);

}  // namespace lbal_fp
#endif
