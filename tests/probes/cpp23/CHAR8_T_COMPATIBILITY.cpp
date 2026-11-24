/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CHAR8_T_COMPATIBILITY.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP23_CHAR8_T_COMPATIBILITY`, from
  P2513R4. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP23_CHAR8_T_COMPATIBILITY
  //	std
  #include <type_traits>

namespace lbal_fp {

//	Only meaningful where `u8` literals are `char8_t` (P0482R6); before that,
//	initializing a `char` array from one always worked.
static_assert(std::is_same_v<
    std::remove_const_t<std::remove_reference_t<decltype(u8"a"[0])>>,
    char8_t
>);

constexpr char narrow[] = u8"abc";
constexpr unsigned char bytes[] = u8"abc";

static_assert(narrow[0] == 'a' && bytes[2] == 'c');

}  // namespace lbal_fp
#endif
