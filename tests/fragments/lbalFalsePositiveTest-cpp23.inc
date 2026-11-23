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

//	The range lives outside the temporary, so iterating stays valid even if
//	the temporary is destroyed early; only the destructor’s timing is measured.
inline constexpr int values[3] = {1, 2, 3};

struct Tracker {
  bool* alive;

  ~Tracker() { *alive = false; }

  const int (&items() const &)[3] { return values; }
};

}  // namespace lbal_fp_cpp23
#endif

LBAL_FP_TEST(CPP23, RANGE_BASED_FOR_TEMPORARIES) {
  LBAL_FP_REQUIRE(LBAL_CPP23_RANGE_BASED_FOR_TEMPORARIES);
#if LBAL_CPP23_RANGE_BASED_FOR_TEMPORARIES
  using namespace lbal_fp_cpp23;

  //	The temporary `Tracker` must live until the end of the loop (P2718R0);
  //	`alive` turns false as soon as it is destroyed.
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
