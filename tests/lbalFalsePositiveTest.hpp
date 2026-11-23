/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFalsePositiveTest.hpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Helpers for the optional false-positive tests. These check that a token which
  claims a feature is available is telling the truth. See
  `lbalFalsePositiveTest.cpp` for how the soft (gtest) and hard (compile-only)
  probes are split.

------------------------------------------------------------------------------*/

#pragma once

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

//  gtest
#include <gtest/gtest.h>

//	std
#include <type_traits>

/*------------------------------------------------------------------------------
  Macros

  A soft probe looks like this:

    LBAL_FP_TEST(CPP17, ALIGNED_NEW) {
      LBAL_FP_REQUIRE(LBAL_CPP17_ALIGNED_NEW);
    #if LBAL_CPP17_ALIGNED_NEW
      EXPECT_...;
    #endif
    }

  The test is named `lbalFalsePositive.CPP17_ALIGNED_NEW`, i.e., the token
  without its `LBAL_` prefix. `LBAL_FP_REQUIRE` reports the test as skipped
  when the token is `0`, so every probed token shows up in the results. The
  `#if` keeps feature-specific code out of the build where the token says the
  feature is unavailable.
*/

//	The test name is pasted rather than passed through, so token suffixes are
//	never macro-expanded.
#define LBAL_FP_TEST(LBAL_FP_std_, LBAL_FP_name_)                              \
  GTEST_TEST(lbalFalsePositive, LBAL_FP_std_##_##LBAL_FP_name_)

#define LBAL_FP_REQUIRE(LBAL_FP_token_)                                        \
  if constexpr (!(LBAL_FP_token_)) {                                           \
    GTEST_SKIP() << #LBAL_FP_token_ " is 0";                                   \
  }

/*
  Detection idiom, so that a missing member or overload produces `false`
  instead of a compile error. The expression must depend on the template
  parameter; a name missing from its namespace altogether is still a hard
  error, which is acceptable since the error points at the token’s probe.

    LBAL_FP_DETECT(has_reset, T, std::declval<std::optional<T>&>().reset())
    EXPECT_TRUE(has_reset<int>::value);
*/
#define LBAL_FP_DETECT(LBAL_FP_name_, LBAL_FP_T_, ...)                         \
  template <class LBAL_FP_T_, class = void>                                    \
  struct LBAL_FP_name_ : std::false_type { };                                  \
  template <class LBAL_FP_T_>                                                  \
  struct LBAL_FP_name_<LBAL_FP_T_, std::void_t<decltype(__VA_ARGS__)>>         \
    : std::true_type { };
