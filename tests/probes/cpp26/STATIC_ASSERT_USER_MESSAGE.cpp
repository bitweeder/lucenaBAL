/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “STATIC_ASSERT_USER_MESSAGE.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP26_STATIC_ASSERT_USER_MESSAGE`, from
  P2741R3. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP26_STATIC_ASSERT_USER_MESSAGE
  //	std
  #include <cstddef>

namespace lbal_fp {

struct Message {
  constexpr std::size_t
  size() const {
    return 2;
  }

  constexpr const char*
  data() const {
    return "ok";
  }
};

static_assert(true, Message{});

}  // namespace lbal_fp
#endif
