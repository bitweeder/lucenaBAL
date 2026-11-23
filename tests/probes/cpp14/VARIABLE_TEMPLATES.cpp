/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “VARIABLE_TEMPLATES.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP14_VARIABLE_TEMPLATES`, from N3651.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP14_VARIABLE_TEMPLATES
namespace lbal_fp {

template <class T>
constexpr T pi = T(3.1415926535897932385L);

static_assert(pi<int> == 3, "");

}  // namespace lbal_fp
#endif
