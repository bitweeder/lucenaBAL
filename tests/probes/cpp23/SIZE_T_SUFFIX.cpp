/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “SIZE_T_SUFFIX.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP23_SIZE_T_SUFFIX`, from P0330R8. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP23_SIZE_T_SUFFIX
  //	std
  #include <cstddef>
  #include <type_traits>

namespace lbal_fp {

static_assert(std::is_same_v<decltype(1uz), std::size_t>);
static_assert(std::is_same_v<decltype(1z), std::make_signed_t<std::size_t>>);

}  // namespace lbal_fp
#endif
