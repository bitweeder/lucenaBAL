/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “ATTRIBUTE_DEPRECATED.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP14_ATTRIBUTE_DEPRECATED`, from N3760.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP14_ATTRIBUTE_DEPRECATED
namespace lbal_fp {

[[deprecated("use something else")]]
inline void
old_function() { }

struct [[deprecated]] OldType { };

}  // namespace lbal_fp
#endif
