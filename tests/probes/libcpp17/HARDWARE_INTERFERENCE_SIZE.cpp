/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “HARDWARE_INTERFERENCE_SIZE.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE`,
  from P0154R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  libc++ and libstdc++ only declare the constants when the compiler
  predefines `__GCC_DESTRUCTIVE_SIZE` and `__GCC_CONSTRUCTIVE_SIZE`, so a
  false claim is a missing name, which is why this isn’t a gtest probe.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE
  //	std
  #include <cstddef>
  #include <new>

  //	gcc warns (`-Winterference-size`) when the destructive size is used
  //	outside the main source file, which is how the false-negative tests
  //	compile this probe; the warning is about ABI stability, not support.
  #if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Winterference-size"
  #endif

namespace lbal_fp {

static_assert(
    std::hardware_destructive_interference_size >= alignof(std::max_align_t)
);
static_assert(
    std::hardware_constructive_interference_size >= alignof(std::max_align_t)
);

struct alignas(std::hardware_destructive_interference_size) Padded {
  int value;
};

static_assert(alignof(Padded) == std::hardware_destructive_interference_size);

}  // namespace lbal_fp

  #if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC diagnostic pop
  #endif
#endif
