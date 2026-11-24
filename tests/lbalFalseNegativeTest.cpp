/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFalseNegativeTest.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Optional tests for false-negative feature tokens, through C++23; built only
  when the CMake option `LBAL_BUILD_FALSE_NEGATIVE_TESTS` (or
  `LBAL_BUILD_ALL_FEATURE_TESTS`) is `ON`.

  A false negative is a token that is `0` although its feature works. These
  tests reuse the false-positive probes, so there’s nothing to write per token.
  `lbalFalseNegative.cmake` compiles each zero-valued token’s probe with the
  token forced on, at configure time, and generates `lbalFalseNegative.hpp`
  with the results. Each token’s test is then:

  - SKIPPED if the token is nonzero (the false-positive tests cover it), if
    it’s a known absence (`lbalFalseNegativeKnown.hpp`), if its probe is
    marked `LBAL_FP_SMOKE`, or if it has no probe
  - PASSED if its probe doesn’t compile
  - FAILED if it’s a compile-only probe that compiles
  - for a gtest probe that compiles: run here, with its failures collected
    rather than reported; FAILED if it passes, PASSED otherwise

------------------------------------------------------------------------------*/

#include "lbalFalsePositiveTest.hpp"

//  gtest
#include <gtest/gtest-spi.h>

#include "lbalFalseNegativeKnown.hpp"

//	generated
#include "lbalFalseNegative.hpp"

/*------------------------------------------------------------------------------
  The real token values, recorded before any token is forced on.
*/

namespace lbal_fn {

#define LBAL_FN_REAL(LBAL_FN_std_, LBAL_FN_name_, ...)                         \
  constexpr long real_##LBAL_FN_std_##_##LBAL_FN_name_                         \
      = LBAL_##LBAL_FN_std_##_##LBAL_FN_name_;

LBAL_FN_SOFT(LBAL_FN_REAL)
LBAL_FN_HARD(LBAL_FN_REAL)

#undef LBAL_FN_REAL

//	Decide one token’s result; `probe` is null for a compile-only probe.
inline void
check(long real, int state, int smoke, void (*probe)(), const char* token) {
  if (real != 0) {
    GTEST_SKIP() << token << " is nonzero; see the false-positive tests";
  }

  if (const char* reason = known_absent(token)) {
    GTEST_SKIP() << token << " is a known absence: " << reason;
  }

  if (smoke) {
    GTEST_SKIP()
        << token
        << "’s probe is marked LBAL_FP_SMOKE, so it can’t detect a "
           "false negative";
  }

  if (state == 2) {
    GTEST_SKIP()
        << token
        << "’s fragment doesn’t compile with the strict options; "
           "see the configure output";
  }

  if (state == 0) {
    SUCCEED() << token << " is 0 and its probe doesn’t compile";
    return;
  }

  if (!probe) {
    ADD_FAILURE() << token << " is 0, but its probe compiles";
    return;
  }

  testing::TestPartResultArray results;

  {
    testing::ScopedFakeTestPartResultReporter reporter(
        testing::ScopedFakeTestPartResultReporter::INTERCEPT_ALL_THREADS,
        &results
    );
    probe();
  }

  for (int i = 0; i < results.size(); ++i) {
    if (results.GetTestPartResult(i).failed()) {
      SUCCEED() << token << " is 0 and its probe fails";
      return;
    }
  }

  ADD_FAILURE() << token << " is 0, but its probe compiles and passes";
}

}  // namespace lbal_fn

/*------------------------------------------------------------------------------
  The gtest probes, as plain functions. Only the tokens whose probes compiled
  while they were 0 are forced on.
*/

//	generated
#include "lbalFalseNegativeForce.hpp"

#undef LBAL_FP_TEST
#undef LBAL_FP_REQUIRE

#define LBAL_FP_TEST(LBAL_FP_std_, LBAL_FP_name_)                              \
  void lbal_fn_probe_##LBAL_FP_std_##_##LBAL_FP_name_()

#define LBAL_FP_REQUIRE(LBAL_FP_token_) static_cast<void>(0)

#include "fragments/lbalFalsePositiveTest-cpp03.inc"
#include "fragments/lbalFalsePositiveTest-cpp11.inc"
#include "fragments/lbalFalsePositiveTest-cpp14.inc"
#include "fragments/lbalFalsePositiveTest-cpp17.inc"
#include "fragments/lbalFalsePositiveTest-cpp20.inc"
#include "fragments/lbalFalsePositiveTest-cpp23.inc"
#include "fragments/lbalFalsePositiveTest-libcpp14.inc"
#include "fragments/lbalFalsePositiveTest-libcpp17.inc"
#include "fragments/lbalFalsePositiveTest-libcpp20.inc"
#include "fragments/lbalFalsePositiveTest-libcpp23.inc"

/*------------------------------------------------------------------------------
  One test per token.
*/

#define LBAL_FN_SOFT_TEST(                                                     \
    LBAL_FN_std_, LBAL_FN_name_, LBAL_FN_state_, LBAL_FN_smoke_                \
)                                                                              \
  GTEST_TEST(lbalFalseNegative, LBAL_FN_std_##_##LBAL_FN_name_) {              \
    lbal_fn::check(                                                            \
        lbal_fn::real_##LBAL_FN_std_##_##LBAL_FN_name_,                        \
        LBAL_FN_state_,                                                        \
        LBAL_FN_smoke_,                                                        \
        &lbal_fn_probe_##LBAL_FN_std_##_##LBAL_FN_name_,                       \
        "LBAL_" #LBAL_FN_std_ "_" #LBAL_FN_name_                               \
    );                                                                         \
  }

#define LBAL_FN_HARD_TEST(                                                     \
    LBAL_FN_std_, LBAL_FN_name_, LBAL_FN_state_, LBAL_FN_smoke_                \
)                                                                              \
  GTEST_TEST(lbalFalseNegative, LBAL_FN_std_##_##LBAL_FN_name_) {              \
    lbal_fn::check(                                                            \
        lbal_fn::real_##LBAL_FN_std_##_##LBAL_FN_name_,                        \
        LBAL_FN_state_,                                                        \
        LBAL_FN_smoke_,                                                        \
        nullptr,                                                               \
        "LBAL_" #LBAL_FN_std_ "_" #LBAL_FN_name_                               \
    );                                                                         \
  }

#define LBAL_FN_NONE_TEST(LBAL_FN_std_, LBAL_FN_name_)                         \
  GTEST_TEST(lbalFalseNegative, LBAL_FN_std_##_##LBAL_FN_name_) {              \
    GTEST_SKIP()                                                               \
        << "LBAL_" #LBAL_FN_std_ "_" #LBAL_FN_name_                            \
        << " has no probe";                                                    \
  }

LBAL_FN_SOFT(LBAL_FN_SOFT_TEST)
LBAL_FN_HARD(LBAL_FN_HARD_TEST)
LBAL_FN_NONE(LBAL_FN_NONE_TEST)
