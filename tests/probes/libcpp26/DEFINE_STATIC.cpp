/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “DEFINE_STATIC.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP26_DEFINE_STATIC`, from P3491R3.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: written from the paper; not yet compiled against a library that
  reports this feature.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_DEFINE_STATIC && __has_include(<meta>)
  //	std
  #include <array>
  #include <meta>
  #include <span>

namespace lbal_fp {

constexpr const char* hello = std::define_static_string("hi");
constexpr std::span<const int> numbers
    = std::define_static_array(std::array{1, 2, 3});

static_assert(hello[1] == 'i' && hello[2] == '\0');
static_assert(numbers.size() == 3 && numbers[2] == 3);

}  // namespace lbal_fp
#endif
