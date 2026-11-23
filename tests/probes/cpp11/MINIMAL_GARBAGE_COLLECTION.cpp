/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “MINIMAL_GARBAGE_COLLECTION.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP11_MINIMAL_GARBAGE_COLLECTION`. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

  The garbage collection API was removed in C++23 (P2186R2).

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP11_MINIMAL_GARBAGE_COLLECTION
  //	std
  #include <memory>

namespace lbal_fp {

inline void
reach(int* p) {
  std::declare_reachable(p);
  (void)std::undeclare_reachable(p);
  (void)std::get_pointer_safety();
}

}  // namespace lbal_fp
#endif
