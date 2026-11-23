/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “ENUMERATOR_ATTRIBUTES.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_ENUMERATOR_ATTRIBUTES`, from
  N4266. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_ENUMERATOR_ATTRIBUTES
namespace lbal_fp {

enum class E {
  a [[deprecated]],
  b,
};

}  // namespace lbal_fp
#endif
