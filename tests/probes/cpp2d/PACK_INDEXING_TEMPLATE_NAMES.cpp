/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “PACK_INDEXING_TEMPLATE_NAMES.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP2D_PACK_INDEXING_TEMPLATE_NAMES`,
  from P3670R4. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: written from P3670R4; not yet compiled by any compiler available
  here.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP2D_PACK_INDEXING_TEMPLATE_NAMES
  //	std
  #include <type_traits>

namespace lbal_fp {

template <class T>
struct One {
  using type = T;
};

template <template <class> class... TTs>
using first_of = TTs...[0]<int>;

static_assert(std::is_same_v<first_of<One>::type, int>);

}  // namespace lbal_fp
#endif
