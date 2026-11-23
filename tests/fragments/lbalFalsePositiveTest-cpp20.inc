/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFalsePositiveTest-cpp20.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Soft false-positive probes for C++20 language tokens. Every other C++20
  token has a hard probe in `probes/cpp20/`, except `LBAL_CPP20_MODULES`,
  which needs a module-aware build and isn’t probed.

------------------------------------------------------------------------------*/

#if LBAL_CPP20_ATTRIBUTE_NO_UNIQUE_ADDRESS
namespace lbal_fp_cpp20 {

struct Empty { };

struct WithEmpty {
  int i;
  [[no_unique_address]]
  Empty e;
};

}  // namespace lbal_fp_cpp20
#endif

LBAL_FP_TEST(CPP20, ATTRIBUTE_NO_UNIQUE_ADDRESS) {
  LBAL_FP_REQUIRE(LBAL_CPP20_ATTRIBUTE_NO_UNIQUE_ADDRESS);
#if LBAL_CPP20_ATTRIBUTE_NO_UNIQUE_ADDRESS
  using namespace lbal_fp_cpp20;

  //	The attribute is accepted but ignored if the empty member still takes up
  //	space.
  EXPECT_EQ(sizeof(WithEmpty), sizeof(int));
#endif
}
