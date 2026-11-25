/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFalsePositiveTest-libcpp2d.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Soft false-positive probes for `LBAL_LIBCPP2D_*` tokens.

  SEEME
  None of these features were implemented by any library available when they
  were written, so every probe here comes from its paper and hasn’t been run;
  a failure may be a mistake in the probe rather than a false positive.

------------------------------------------------------------------------------*/

//	std
#include <cstddef>
#include <cstdint>
#include <map>
#include <memory>
#include <string>
#include <thread>
#include <type_traits>
#include <vector>

#if LBAL_LIBCPP2D_BITOPS_BETTER_SHIFTING                                       \
    || LBAL_LIBCPP2D_BITOPS_PERMUTATIONS                                       \
    || LBAL_LIBCPP2D_SIMD_BITOPS                                               \
    || LBAL_LIBCPP2D_SIMD_BITOPS_BETTER_SHIFTING
  #include <bit>
#endif

#if LBAL_LIBCPP2D_CONSTANT_WRAPPER_REVERT_STRING
  #include <utility>
#endif

#if LBAL_LIBCPP2D_EXPECTED_UEXPECTED
  #include <expected>
#endif

#if LBAL_LIBCPP2D_HAZARD_POINTER_BATCHES
  #include <hazard_pointer>
#endif

#if LBAL_LIBCPP2D_MDSPAN_COPY
  #include <algorithm>
  #include <mdspan>
#endif

#if LBAL_LIBCPP2D_POINTER_TAG_PAIR
  #include <memory>
#endif

#if LBAL_LIBCPP2D_SIMD_BITOPS || LBAL_LIBCPP2D_SIMD_BITOPS_BETTER_SHIFTING
  #include <simd>
#endif

#if LBAL_LIBCPP2D_TO_CHARS_FIX_FLOAT
  #include <charconv>
  #include <format>
#endif

#if LBAL_LIBCPP2D_VIEW_INTERFACE
  #include <ranges>
  #include <stdexcept>
#endif

LBAL_FP_TEST(LIBCPP2D, BITOPS_BETTER_SHIFTING) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP2D_BITOPS_BETTER_SHIFTING);
#if LBAL_LIBCPP2D_BITOPS_BETTER_SHIFTING
  //	Shifts by the full width or more are defined (P3793R2); the names are
  //	from the paper and unverified.
  EXPECT_EQ(std::shl(1u, 40), 0u);
  EXPECT_EQ(std::shr(0x80u, 4), 0x8u);
#endif
}

LBAL_FP_TEST(LIBCPP2D, BITOPS_PERMUTATIONS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP2D_BITOPS_PERMUTATIONS);
#if LBAL_LIBCPP2D_BITOPS_PERMUTATIONS
  EXPECT_EQ(std::bit_reverse(std::uint8_t{1}), std::uint8_t{0x80});
  EXPECT_EQ(std::bit_compress(0b1010u, 0b1010u), 0b11u);
  EXPECT_EQ(std::bit_expand(0b11u, 0b1010u), 0b1010u);
#endif
}

LBAL_FP_TEST(LIBCPP2D, CONSTANT_WRAPPER_REVERT_STRING) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP2D_CONSTANT_WRAPPER_REVERT_STRING);
#if LBAL_LIBCPP2D_CONSTANT_WRAPPER_REVERT_STRING
  //	P4206R0 removes string support; the rest of `constant_wrapper` is
  //	unaffected, so this is a smoke test.
  EXPECT_EQ(std::cw<3>.value, 3);
#endif
}

LBAL_FP_TEST(LIBCPP2D, EXPECTED_UEXPECTED) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP2D_EXPECTED_UEXPECTED);
#if LBAL_LIBCPP2D_EXPECTED_UEXPECTED
  //	LBAL_FP_SMOKE: it doesn’t isolate the paper’s changes, so it can’t detect
  //	a false negative.
  //	Smoke test; it doesn’t isolate the P3798R1 changes.
  std::expected<int, int> e = std::unexpected(2);

  EXPECT_EQ(e.error(), 2);
#endif
}

LBAL_FP_TEST(LIBCPP2D, HAZARD_POINTER_BATCHES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP2D_HAZARD_POINTER_BATCHES);
#if LBAL_LIBCPP2D_HAZARD_POINTER_BATCHES
  //	Batched creation (P3428R4); the spelling is from the paper and
  //	unverified.
  auto batch = std::make_hazard_pointer_batch<2>();

  EXPECT_EQ(batch.size(), 2u);
#endif
}

LBAL_FP_TEST(LIBCPP2D, MAP_LOOKUP) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP2D_MAP_LOOKUP);
#if LBAL_LIBCPP2D_MAP_LOOKUP
  //	`get` returns an `optional` reference (P3091R6).
  std::map<int, int> m{{1, 10}};

  EXPECT_EQ(m.get(1).value(), 10);
  EXPECT_FALSE(m.get(2).has_value());
#endif
}

LBAL_FP_TEST(LIBCPP2D, MDSPAN_COPY) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP2D_MDSPAN_COPY);
#if LBAL_LIBCPP2D_MDSPAN_COPY
  //	The spelling is from P3242R4 and unverified.
  int from[4] = {1, 2, 3, 4};
  int to[4] = {};
  std::mdspan src(from, 2, 2);
  std::mdspan dst(to, 2, 2);

  std::copy(src, dst);
  EXPECT_EQ(to[3], 4);
#endif
}

LBAL_FP_TEST(LIBCPP2D, POINTER_TAG_PAIR) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP2D_POINTER_TAG_PAIR);
#if LBAL_LIBCPP2D_POINTER_TAG_PAIR
  alignas(8) int x = 0;
  std::pointer_tag_pair<int, unsigned, 2> p(&x, 3u);

  EXPECT_EQ(p.pointer(), &x);
  EXPECT_EQ(p.tag(), 3u);
#endif
}

LBAL_FP_TEST(LIBCPP2D, SIMD_BITOPS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP2D_SIMD_BITOPS);
#if LBAL_LIBCPP2D_SIMD_BITOPS
  std::simd::vec<std::uint8_t, 4> v(std::uint8_t{1});

  EXPECT_EQ(std::bit_reverse(v)[0], std::uint8_t{0x80});
#endif
}

LBAL_FP_TEST(LIBCPP2D, SIMD_BITOPS_BETTER_SHIFTING) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP2D_SIMD_BITOPS_BETTER_SHIFTING);
#if LBAL_LIBCPP2D_SIMD_BITOPS_BETTER_SHIFTING
  //	The names are from P3793R2 and unverified.
  std::simd::vec<unsigned, 4> v(1u);

  EXPECT_EQ(std::shl(v, 40)[0], 0u);
#endif
}

LBAL_FP_TEST(LIBCPP2D, THREAD_ATTRIBUTES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP2D_THREAD_ATTRIBUTES);
#if LBAL_LIBCPP2D_THREAD_ATTRIBUTES
  //	Attributes are hints, so only check the thread runs (P2019R9).
  bool ran = false;
  std::jthread t(
      std::thread::name_hint("lbal"),
      std::thread::stack_size_hint(1 << 20),
      [&] {
        ran = true;
      }
  );

  t.join();
  EXPECT_TRUE(ran);
#endif
}

LBAL_FP_TEST(LIBCPP2D, TO_CHARS_FIX_FLOAT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP2D_TO_CHARS_FIX_FLOAT);
#if LBAL_LIBCPP2D_TO_CHARS_FIX_FLOAT
  //	The default representation prefers fixed notation when it is no longer
  //	(P3505R4); the expected text is from the paper and unverified.
  EXPECT_EQ(std::format("{}", 100000.0), "100000");
#endif
}

LBAL_FP_TEST(LIBCPP2D, VIEW_INTERFACE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP2D_VIEW_INTERFACE);
#if LBAL_LIBCPP2D_VIEW_INTERFACE
  auto view = std::views::iota(0, 3);

  EXPECT_EQ(view.at(2), 2);
  #if LBAL_CPP03_EXCEPTIONS
  EXPECT_THROW((void)view.at(3), std::out_of_range);
  #endif
#endif
}
