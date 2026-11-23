/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “NAMESPACE_ATTRIBUTES.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_NAMESPACE_ATTRIBUTES`, from N4266.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_NAMESPACE_ATTRIBUTES
namespace lbal_fp {

namespace [[deprecated]] old_ns {

inline int
f() {
  return 0;
}

}  // namespace old_ns

}  // namespace lbal_fp
#endif
