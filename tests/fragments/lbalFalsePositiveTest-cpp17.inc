/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFalsePositiveTest-cpp17.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Soft false-positive probes for C++17 language tokens. Every other C++17
  token has a hard probe in `probes/cpp17/`.

------------------------------------------------------------------------------*/

#if LBAL_CPP17_ALIGNED_NEW
  //	std
  #include <cstdint>
  #include <memory>

namespace lbal_fp_cpp17 {

//	Larger than any fundamental alignment, so the allocation must go through
//	the `std::align_val_t` overloads.
struct alignas(256) OverAligned {
  char c;
};

}  // namespace lbal_fp_cpp17
#endif

LBAL_FP_TEST(CPP17, ALIGNED_NEW) {
  LBAL_FP_REQUIRE(LBAL_CPP17_ALIGNED_NEW);
#if LBAL_CPP17_ALIGNED_NEW
  using namespace lbal_fp_cpp17;

  auto one = std::make_unique<OverAligned>();
  auto many = std::make_unique<OverAligned[]>(3);

  EXPECT_EQ(reinterpret_cast<std::uintptr_t>(one.get()) % 256, 0u);
  EXPECT_EQ(reinterpret_cast<std::uintptr_t>(&many[1]) % 256, 0u);
#endif
}

#if LBAL_CPP17_GUARANTEED_COPY_ELISION
namespace lbal_fp_cpp17 {

struct SelfAware {
  SelfAware()
    : self(this) { }

  SelfAware(const SelfAware&)
    : self(nullptr) { }

  SelfAware* self;
};

inline SelfAware
make_self_aware() {
  return SelfAware{};
}

}  // namespace lbal_fp_cpp17
#endif

LBAL_FP_TEST(CPP17, GUARANTEED_COPY_ELISION) {
  LBAL_FP_REQUIRE(LBAL_CPP17_GUARANTEED_COPY_ELISION);
#if LBAL_CPP17_GUARANTEED_COPY_ELISION
  using namespace lbal_fp_cpp17;

  //	A prvalue initializes the object directly, so no copy is ever made.
  SelfAware s = make_self_aware();

  EXPECT_EQ(s.self, &s);
#endif
}
