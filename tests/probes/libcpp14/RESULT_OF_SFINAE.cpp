/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “RESULT_OF_SFINAE.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP14_RESULT_OF_SFINAE`, from N3462.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  std::result_of was removed in C++20 (P0619R4), so this is a compile-only
  probe: if the token claims support where the name is gone, only this file
  fails.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP14_RESULT_OF_SFINAE
  //	std
  #include <type_traits>

namespace lbal_fp {

template <class F, class = void>
struct has_result_type : std::false_type { };

template <class F>
struct has_result_type<F, std::void_t<typename std::result_of<F>::type>>
  : std::true_type { };

static_assert(has_result_type<int (*(int))(int)>::value);
static_assert(std::is_same_v<std::result_of<int (*(int))(int)>::type, int>);

//	A non-callable type has no `type` member rather than causing a hard error.
static_assert(!has_result_type<int(int)>::value);

}  // namespace lbal_fp
#endif
