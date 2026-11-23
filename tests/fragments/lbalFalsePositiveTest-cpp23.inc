/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFalsePositiveTest-cpp23.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Soft false-positive probes for C++23 language tokens. Every other C++23
  token has a hard probe in `probes/cpp23/`.

------------------------------------------------------------------------------*/

#if LBAL_CPP23_RANGE_BASED_FOR_TEMPORARIES
namespace lbal_fp_cpp23 {

struct Tracker {
  bool* alive;
  int data[3]{1, 2, 3};

  ~Tracker() { *alive = false; }

  const int (&items() const &)[3] { return data; }
};

}  // namespace lbal_fp_cpp23
#endif

LBAL_FP_TEST(CPP23, RANGE_BASED_FOR_TEMPORARIES) {
  LBAL_FP_REQUIRE(LBAL_CPP23_RANGE_BASED_FOR_TEMPORARIES);
#if LBAL_CPP23_RANGE_BASED_FOR_TEMPORARIES
  using namespace lbal_fp_cpp23;

  //	The temporary `Tracker` must live until the end of the loop (P2718R0).
  //	If it doesn’t, the loop reads a dead object, but `alive` still reports
  //	the failure.
  bool alive = true;
  bool alive_throughout = true;
  int sum = 0;

  for (int x : Tracker{&alive}.items()) {
    alive_throughout = alive_throughout && alive;
    sum += x;
  }

  EXPECT_TRUE(alive_throughout);
  EXPECT_FALSE(alive);
  EXPECT_EQ(sum, 6);
#endif
}
