/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFalsePositiveTest-libcpp23.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Soft false-positive probes for `LBAL_LIBCPP23_*` tokens. Tokens that are only
  about `constexpr` support have hard probes in `probes/libcpp23/`.
  `LBAL_LIBCPP23_MODULES` isn’t probed, as `import std;` needs a module-aware
  build.

  Probes marked SEEME were written from the paper and haven’t yet been run
  against a library that reports the feature.

------------------------------------------------------------------------------*/

//	std
#include <algorithm>
#include <array>
#include <atomic>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <functional>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string_view>
#include <thread>
#include <tuple>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>

#if LBAL_LIBCPP23_BARRIER_RELAXED_COMPLETION
  #include <barrier>
#endif

#if LBAL_LIBCPP23_BYTESWAP
  #include <bit>
#endif

#if LBAL_LIBCPP23_CONCEPTS_MOVE_ONLY
  #include <concepts>
#endif

#if LBAL_LIBCPP23_EXPECTED || LBAL_LIBCPP23_EXPECTED_MONADIC
  #include <expected>
#endif

#if LBAL_LIBCPP23_FLAT_MAP
  #include <flat_map>
#endif

#if LBAL_LIBCPP23_FLAT_SET
  #include <flat_set>
#endif

#if LBAL_LIBCPP23_FORMAT                                                       \
    || LBAL_LIBCPP23_FORMATTERS                                                \
    || LBAL_LIBCPP23_FORMATTERS_THREAD_ID                                      \
    || LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING                                \
    || LBAL_LIBCPP23_FORMAT_ENCODINGS                                          \
    || LBAL_LIBCPP23_FORMAT_GENERATOR                                          \
    || LBAL_LIBCPP23_FORMAT_LOCALE                                             \
    || LBAL_LIBCPP23_FORMAT_RANGES
  #include <chrono>
  #include <format>
#endif

#if LBAL_LIBCPP23_FORMATTERS_THREAD_ID
  #include <sstream>
#endif

#if LBAL_LIBCPP23_GENERATOR
  #include <generator>
#endif

#if LBAL_LIBCPP23_IOS_NOREPLACE
  #include <filesystem>
  #include <fstream>
#endif

#if LBAL_LIBCPP23_MDSPAN
  #include <mdspan>
#endif

#if LBAL_LIBCPP23_OPTIONAL_MONADIC
  #include <optional>
#endif

#if LBAL_LIBCPP23_PRINT
  #include <print>
#endif

#if LBAL_LIBCPP23_ALGORITHM_ITERATOR_REQUIREMENTS                              \
    || LBAL_LIBCPP23_CONTAINERS_RANGES                                         \
    || LBAL_LIBCPP23_RANGES_AS_CONST                                           \
    || LBAL_LIBCPP23_RANGES_AS_RVALUE                                          \
    || LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT                                  \
    || LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT_EMPTY                            \
    || LBAL_LIBCPP23_RANGES_CHUNK                                              \
    || LBAL_LIBCPP23_RANGES_CHUNK_BY                                           \
    || LBAL_LIBCPP23_RANGES_CONTAINS                                           \
    || LBAL_LIBCPP23_RANGES_ENUMERATE                                          \
    || LBAL_LIBCPP23_RANGES_FIND_LAST                                          \
    || LBAL_LIBCPP23_RANGES_FOLD                                               \
    || LBAL_LIBCPP23_RANGES_FORMALIZED_VIEW                                    \
    || LBAL_LIBCPP23_RANGES_IOTA                                               \
    || LBAL_LIBCPP23_RANGES_JOIN_WITH                                          \
    || LBAL_LIBCPP23_RANGES_NON_DEFAULT_CONSTRUCTIBLE                          \
    || LBAL_LIBCPP23_RANGES_RELAXED                                            \
    || LBAL_LIBCPP23_RANGES_REMOVE_POISON_PILLS                                \
    || LBAL_LIBCPP23_RANGES_REPEAT                                             \
    || LBAL_LIBCPP23_RANGES_SLIDE                                              \
    || LBAL_LIBCPP23_RANGES_STARTS_ENDS_WITH                                   \
    || LBAL_LIBCPP23_RANGES_STRIDE                                             \
    || LBAL_LIBCPP23_RANGES_SUPPORT_MOVE_ONLY_TYPES                            \
    || LBAL_LIBCPP23_RANGES_TO_CONTAINER                                       \
    || LBAL_LIBCPP23_RANGES_USER_ADAPTOR_PIPES                                 \
    || LBAL_LIBCPP23_RANGES_ZIP                                                \
    || LBAL_LIBCPP23_SHIFT_RANGES                                              \
    || LBAL_LIBCPP23_MOVE_ITERATOR_CONCEPT
  #include <iterator>
  #include <numeric>
  #include <ranges>
#endif

#if LBAL_LIBCPP23_SPANSTREAM
  #include <span>
  #include <spanstream>
#endif

#if LBAL_LIBCPP23_STACKTRACE
  #include <stacktrace>
#endif

#if LBAL_LIBCPP23_STDATOMIC_H
  #include <stdatomic.h>
#endif

namespace lbal_fp_libcpp23 {

//	Compares with `int` but doesn’t convert to it.
struct IntKey {
  int value;
};

inline bool
operator< (const IntKey& a, int b) {
  return a.value < b;
}

inline bool
operator< (int a, const IntKey& b) {
  return a < b.value;
}

}  // namespace lbal_fp_libcpp23

LBAL_FP_TEST(LIBCPP23, ADAPTOR_ITERATOR_PAIR_CONSTRUCTOR) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_ADAPTOR_ITERATOR_PAIR_CONSTRUCTOR);
#if LBAL_LIBCPP23_ADAPTOR_ITERATOR_PAIR_CONSTRUCTOR
  std::vector<int> v{1, 2, 3};
  std::stack<int> s(v.begin(), v.end());
  std::queue<int> q(v.begin(), v.end());

  EXPECT_EQ(s.top(), 3);
  EXPECT_EQ(q.front(), 1);
#endif
}

LBAL_FP_TEST(LIBCPP23, ALGORITHM_ITERATOR_REQUIREMENTS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_ALGORITHM_ITERATOR_REQUIREMENTS);
#if LBAL_LIBCPP23_ALGORITHM_ITERATOR_REQUIREMENTS
  //	LBAL_FP_SMOKE: libstdc++ and libc++ accepted these iterators before
  //	P2408R5 (only MSVC’s parallel algorithms rejected them), so it can’t
  //	detect a false negative.
  //	SEEME
  //	Classic algorithms accept C++20 iterators whose category understates
  //	what they model (P2408R5).
  auto r = std::views::iota(0, 6) | std::views::transform([](int x) {
    return x * 2;
  });

  EXPECT_EQ(
      std::count_if(
          r.begin(),
          r.end(),
          [](int x) {
            return x > 5;
          }
      ),
      3
  );
  EXPECT_EQ(*std::max_element(r.begin(), r.end()), 10);
#endif
}

LBAL_FP_TEST(LIBCPP23, ALLOCATE_AT_LEAST) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_ALLOCATE_AT_LEAST);
#if LBAL_LIBCPP23_ALLOCATE_AT_LEAST
  //	The member works in both revisions; the original free function was
  //	replaced in P2652R2.
  std::allocator<int> a;
  auto result = a.allocate_at_least(3);

  EXPECT_GE(result.count, 3u);
  a.deallocate(result.ptr, result.count);
#endif
}

LBAL_FP_TEST(LIBCPP23, ALLOCATE_AT_LEAST_DISALLOW_USER_SPEC) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_ALLOCATE_AT_LEAST_DISALLOW_USER_SPEC);
#if LBAL_LIBCPP23_ALLOCATE_AT_LEAST_DISALLOW_USER_SPEC
  //	`allocator_traits::allocate_at_least` replaces the free function
  //	(P2652R2).
  std::allocator<int> a;
  auto result
      = std::allocator_traits<std::allocator<int>>::allocate_at_least(a, 3);

  EXPECT_GE(result.count, 3u);
  a.deallocate(result.ptr, result.count);
#endif
}

#if LBAL_LIBCPP23_ASSOCIATIVE_HETEROGENEOUS_ERASURE
namespace lbal_fp_libcpp23 {

LBAL_FP_DETECT(
    has_heterogeneous_erase,
    T,
    std::declval<std::map<int, int, std::less<>>&>().erase(std::declval<T>())
)

}  // namespace lbal_fp_libcpp23
#endif

LBAL_FP_TEST(LIBCPP23, ASSOCIATIVE_HETEROGENEOUS_ERASURE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_ASSOCIATIVE_HETEROGENEOUS_ERASURE);
#if LBAL_LIBCPP23_ASSOCIATIVE_HETEROGENEOUS_ERASURE
  //	SEEME
  using namespace lbal_fp_libcpp23;

  EXPECT_TRUE(has_heterogeneous_erase<IntKey>::value);

  if constexpr (has_heterogeneous_erase<IntKey>::value) {
    std::map<int, int, std::less<>> m{{1, 1}, {2, 2}};
    EXPECT_EQ(m.erase(IntKey{1}), 1u);
    EXPECT_EQ(m.size(), 1u);
  }
#endif
}

LBAL_FP_TEST(LIBCPP23, BARRIER_RELAXED_COMPLETION) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_BARRIER_RELAXED_COMPLETION);
#if LBAL_LIBCPP23_BARRIER_RELAXED_COMPLETION
  //	LBAL_FP_SMOKE: where the completion step runs isn’t portably
  //	observable, so it can’t detect a false negative.
  //	SEEME
  //	P2588R3 relaxes where the completion step runs, which isn’t observable
  //	portably; this checks the completion still runs once per phase.
  std::atomic<int> completions{0};
  std::barrier sync(2, [&]() noexcept {
    ++completions;
  });

  std::thread other([&] {
    sync.arrive_and_wait();
    sync.arrive_and_wait();
  });
  sync.arrive_and_wait();
  sync.arrive_and_wait();
  other.join();

  EXPECT_EQ(completions.load(), 2);
#endif
}

LBAL_FP_TEST(LIBCPP23, BIND_BACK) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_BIND_BACK);
#if LBAL_LIBCPP23_BIND_BACK
  auto minus_three = std::bind_back(std::minus<>{}, 3);

  EXPECT_EQ(minus_three(10), 7);
#endif
}

LBAL_FP_TEST(LIBCPP23, BYTESWAP) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_BYTESWAP);
#if LBAL_LIBCPP23_BYTESWAP
  EXPECT_EQ(std::byteswap(std::uint16_t{0x1234}), 0x3412);
  EXPECT_EQ(std::byteswap(std::uint32_t{0x1234'5678}), 0x7856'3412u);
#endif
}

#if LBAL_LIBCPP23_COMMON_REFERENCE
namespace lbal_fp_libcpp23 {

struct RefTarget { };

struct RefSource {
  operator RefTarget&() const;
};

}  // namespace lbal_fp_libcpp23
#endif

LBAL_FP_TEST(LIBCPP23, COMMON_REFERENCE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_COMMON_REFERENCE);
#if LBAL_LIBCPP23_COMMON_REFERENCE
  //	P2655R3’s own example for plain references: `COMMON-REF` no longer
  //	accepts a user-defined conversion, so the result follows `?:` (`A&`)
  //	instead of `const A&`. The `reference_wrapper` part is
  //	`LBAL_LIBCPP23_COMMON_REFERENCE_WRAPPER`.
  EXPECT_TRUE((std::is_same_v<
      std::common_reference_t<
          lbal_fp_libcpp23::RefTarget&,
          const lbal_fp_libcpp23::RefSource&
      >,
      lbal_fp_libcpp23::RefTarget&
  >));
#endif
}

LBAL_FP_TEST(LIBCPP23, COMMON_REFERENCE_WRAPPER) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_COMMON_REFERENCE_WRAPPER);
#if LBAL_LIBCPP23_COMMON_REFERENCE_WRAPPER
  EXPECT_TRUE((std::is_same_v<
      std::common_reference_t<std::reference_wrapper<int>, int&>,
      int&
  >));
#endif
}

LBAL_FP_TEST(LIBCPP23, CONCEPTS_MOVE_ONLY) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_CONCEPTS_MOVE_ONLY);
#if LBAL_LIBCPP23_CONCEPTS_MOVE_ONLY
  //	Comparison concepts accept move-only types (P2404R3).
  EXPECT_TRUE((
      std::equality_comparable_with<std::unique_ptr<int>, std::nullptr_t>
  ));
#endif
}

LBAL_FP_TEST(LIBCPP23, CONTAINERS_RANGES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_CONTAINERS_RANGES);
#if LBAL_LIBCPP23_CONTAINERS_RANGES
  auto r = std::views::iota(1, 4);
  std::vector<int> v(std::from_range, r);

  v.append_range(r);
  v.insert_range(v.begin(), std::views::single(0));

  EXPECT_EQ(v, (std::vector<int>{0, 1, 2, 3, 1, 2, 3}));
#endif
}

LBAL_FP_TEST(LIBCPP23, EXPECTED) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_EXPECTED);
#if LBAL_LIBCPP23_EXPECTED
  std::expected<int, std::string> good = 1;
  std::expected<int, std::string> bad = std::unexpected(std::string("no"));

  EXPECT_TRUE(good.has_value());
  EXPECT_EQ(*good, 1);
  EXPECT_FALSE(bad.has_value());
  EXPECT_EQ(bad.error(), "no");
  EXPECT_EQ(bad.value_or(7), 7);
#endif
}

LBAL_FP_TEST(LIBCPP23, EXPECTED_MONADIC) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_EXPECTED_MONADIC);
#if LBAL_LIBCPP23_EXPECTED_MONADIC
  std::expected<int, int> good = 2;
  std::expected<int, int> bad = std::unexpected(1);

  auto doubled = good.transform([](int x) {
    return x * 2;
  });
  auto chained = good.and_then([](int x) -> std::expected<int, int> {
    return x + 1;
  });
  auto recovered = bad.or_else([](int e) -> std::expected<int, int> {
    return e * 10;
  });
  auto relabeled = bad.transform_error([](int e) {
    return e + 1;
  });

  EXPECT_EQ(*doubled, 4);
  EXPECT_EQ(*chained, 3);
  EXPECT_EQ(*recovered, 10);
  EXPECT_EQ(relabeled.error(), 2);
#endif
}

LBAL_FP_TEST(LIBCPP23, FLAT_MAP) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_FLAT_MAP);
#if LBAL_LIBCPP23_FLAT_MAP
  std::flat_map<int, int> m;

  m[2] = 20;
  m.emplace(1, 10);

  EXPECT_EQ(m.begin()->first, 1);
  EXPECT_EQ(m.at(2), 20);
  EXPECT_EQ(m.keys().size(), 2u);
#endif
}

LBAL_FP_TEST(LIBCPP23, FLAT_SET) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_FLAT_SET);
#if LBAL_LIBCPP23_FLAT_SET
  std::flat_set<int> s{3, 1, 2, 1};

  EXPECT_EQ(s.size(), 3u);
  EXPECT_EQ(*s.begin(), 1);
  EXPECT_TRUE(s.contains(2));
#endif
}

LBAL_FP_TEST(LIBCPP23, FORMAT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_FORMAT);
#if LBAL_LIBCPP23_FORMAT
  //	Format strings are checked at compile time, and `make_format_args`
  //	takes lvalues (P2216R3).
  int value = 42;

  EXPECT_EQ(std::format("{:>4}", value), "  42");
  EXPECT_EQ(std::vformat("{}", std::make_format_args(value)), "42");
#endif
}

//	`LBAL_LIBCPP23_FORMATTERS` has a compile-only probe in `probes/libcpp23/`:
//	what sets it apart from `thread::id` alone is `<stacktrace>`.

LBAL_FP_TEST(LIBCPP23, FORMATTERS_THREAD_ID) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_FORMATTERS_THREAD_ID);
#if LBAL_LIBCPP23_FORMATTERS_THREAD_ID
  //	P2693R1: the formatted form matches `operator<<`, and the standard
  //	fill, alignment and width are honoured.
  auto const id = std::this_thread::get_id();
  std::ostringstream stream;
  stream << id;
  auto const plain = std::format("{}", id);

  EXPECT_EQ(plain, stream.str());

  auto const padded = std::format("{:*>40}", id);

  ASSERT_EQ(padded.size(), 40u);
  EXPECT_TRUE(padded.ends_with(plain));
  EXPECT_EQ(padded.front(), '*');
#endif
}

LBAL_FP_TEST(LIBCPP23, FORMAT_BASIC_FORMAT_STRING) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING);
#if LBAL_LIBCPP23_FORMAT_BASIC_FORMAT_STRING
  //	P2508R1 exposes the class template itself, and its `get()`.
  std::basic_format_string<char, int> bfs = "{}?";
  std::format_string<int> fs = "{}!";

  EXPECT_EQ(bfs.get(), "{}?");
  EXPECT_EQ(fs.get(), "{}!");
  EXPECT_EQ(std::format(fs, 1), "1!");
#endif
}

LBAL_FP_TEST(LIBCPP23, FORMAT_ENCODINGS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_FORMAT_ENCODINGS);
#if LBAL_LIBCPP23_FORMAT_ENCODINGS
  //	LBAL_FP_SMOKE: the encoding of localized output isn’t portably
  //	observable, so it can’t detect a false negative.
  //	SEEME
  //	P2419R2 is about the encoding of localized output, which isn’t portably
  //	observable; this checks localized chrono formatting works.
  EXPECT_EQ(std::format("{:L}", std::chrono::seconds(3)), "3s");
#endif
}

#if LBAL_LIBCPP23_FORMAT_GENERATOR
namespace lbal_fp_libcpp23 {

//	Formatting needs a non-`const` object.
struct Counter {
  int calls = 0;
};

}  // namespace lbal_fp_libcpp23

template <>
struct std::formatter<lbal_fp_libcpp23::Counter> {
  constexpr auto
  parse(std::format_parse_context& ctx) {
    return ctx.begin();
  }

  auto
  format(lbal_fp_libcpp23::Counter& c, std::format_context& ctx) const {
    return std::format_to(ctx.out(), "{}", ++c.calls);
  }
};
#endif

LBAL_FP_TEST(LIBCPP23, FORMAT_GENERATOR) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_FORMAT_GENERATOR);
#if LBAL_LIBCPP23_FORMAT_GENERATOR
  //	Arguments are taken by forwarding reference, so a formatter can require
  //	a non-`const` object (P2418R2).
  lbal_fp_libcpp23::Counter counter;

  EXPECT_EQ(std::format("{}", counter), "1");
  EXPECT_EQ(counter.calls, 1);
#endif
}

LBAL_FP_TEST(LIBCPP23, FORMAT_LOCALE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_FORMAT_LOCALE);
#if LBAL_LIBCPP23_FORMAT_LOCALE
  //	Chrono formatting without `L` uses the C locale (P2372R3).
  EXPECT_EQ(std::format("{:%S}", std::chrono::milliseconds(1500)), "01.500");
#endif
}

LBAL_FP_TEST(LIBCPP23, FORMAT_RANGES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_FORMAT_RANGES);
#if LBAL_LIBCPP23_FORMAT_RANGES
  EXPECT_EQ(std::format("{}", std::vector<int>{1, 2}), "[1, 2]");
  EXPECT_EQ(std::format("{}", std::pair{1, 'a'}), "(1, 'a')");
  EXPECT_EQ(std::format("{::d}", std::set<int>{2, 1}), "{1, 2}");
#endif
}

LBAL_FP_TEST(LIBCPP23, FORWARD_LIKE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_FORWARD_LIKE);
#if LBAL_LIBCPP23_FORWARD_LIKE
  int x = 0;

  EXPECT_TRUE((std::is_same_v<decltype(std::forward_like<int>(x)), int&&>));
  EXPECT_TRUE((
      std::is_same_v<decltype(std::forward_like<const int&>(x)), const int&>
  ));
#endif
}

#if LBAL_LIBCPP23_GENERATOR
namespace lbal_fp_libcpp23 {

inline std::generator<int>
count_to(int n) {
  for (int i = 1; i <= n; ++i)
    co_yield i;
}

}  // namespace lbal_fp_libcpp23
#endif

LBAL_FP_TEST(LIBCPP23, GENERATOR) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_GENERATOR);
#if LBAL_LIBCPP23_GENERATOR
  int sum = 0;

  for (int x : lbal_fp_libcpp23::count_to(4))
    sum += x;
  EXPECT_EQ(sum, 10);
#endif
}

LBAL_FP_TEST(LIBCPP23, INVOKE_R) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_INVOKE_R);
#if LBAL_LIBCPP23_INVOKE_R
  auto r = std::invoke_r<long>([] {
    return 1;
  });

  EXPECT_TRUE((std::is_same_v<decltype(r), long>));
  EXPECT_EQ(r, 1L);
#endif
}

LBAL_FP_TEST(LIBCPP23, IOS_NOREPLACE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_IOS_NOREPLACE);
#if LBAL_LIBCPP23_IOS_NOREPLACE
  namespace fs = std::filesystem;

  auto path = fs::temp_directory_path() / "lbalFalsePositive-noreplace.tmp";
  fs::remove(path);

  {
    std::ofstream first(path, std::ios::out | std::ios::noreplace);
    EXPECT_TRUE(first.is_open());
  }

  std::ofstream second(path, std::ios::out | std::ios::noreplace);
  EXPECT_FALSE(second.is_open());

  second.close();
  fs::remove(path);
#endif
}

LBAL_FP_TEST(LIBCPP23, IS_IMPLICIT_LIFETIME) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_IS_IMPLICIT_LIFETIME);
#if LBAL_LIBCPP23_IS_IMPLICIT_LIFETIME
  struct Custom {
    Custom() { }

    ~Custom() { }
  };

  EXPECT_TRUE(std::is_implicit_lifetime_v<int>);
  EXPECT_TRUE(std::is_implicit_lifetime_v<int[2]>);
  EXPECT_FALSE(std::is_implicit_lifetime_v<Custom>);
#endif
}

LBAL_FP_TEST(LIBCPP23, IS_SCOPED_ENUM) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_IS_SCOPED_ENUM);
#if LBAL_LIBCPP23_IS_SCOPED_ENUM
  enum class Scoped {
    a,
  };

  enum Plain {
    b,
  };

  EXPECT_TRUE(std::is_scoped_enum_v<Scoped>);
  EXPECT_FALSE(std::is_scoped_enum_v<Plain>);
#endif
}

LBAL_FP_TEST(LIBCPP23, MDSPAN) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_MDSPAN);
#if LBAL_LIBCPP23_MDSPAN
  int data[6] = {0, 1, 2, 3, 4, 5};
  std::mdspan m(data, 2, 3);

  EXPECT_EQ(m.extent(0), 2u);
  EXPECT_EQ(m.extent(1), 3u);
  EXPECT_EQ((m[std::array{1, 2}]), 5);
#endif
}

LBAL_FP_TEST(LIBCPP23, MOVE_ITERATOR_CONCEPT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_MOVE_ITERATOR_CONCEPT);
#if LBAL_LIBCPP23_MOVE_ITERATOR_CONCEPT
  EXPECT_TRUE(std::random_access_iterator<std::move_iterator<int*>>);
#endif
}

LBAL_FP_TEST(LIBCPP23, MOVE_ONLY_FUNCTION) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_MOVE_ONLY_FUNCTION);
#if LBAL_LIBCPP23_MOVE_ONLY_FUNCTION
  std::move_only_function<int(int)> f = [p = std::make_unique<int>(2)](int x) {
    return x * *p;
  };

  EXPECT_EQ(f(3), 6);
#endif
}

LBAL_FP_TEST(LIBCPP23, OPTIONAL_MONADIC) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_OPTIONAL_MONADIC);
#if LBAL_LIBCPP23_OPTIONAL_MONADIC
  std::optional<int> some = 2;
  std::optional<int> none;

  EXPECT_EQ(
      *some.transform([](int x) {
        return x * 2;
      }),
      4
  );
  EXPECT_EQ(
      *some.and_then([](int x) {
        return std::optional<int>(x + 1);
      }),
      3
  );
  EXPECT_EQ(
      *none.or_else([] {
        return std::optional<int>(9);
      }),
      9
  );
#endif
}

#if LBAL_LIBCPP23_OUT_PTR
namespace lbal_fp_libcpp23 {

//	A C-style API that hands back a new object through an out parameter.
inline void
make_int(int** out) {
  *out = new int(5);
}

}  // namespace lbal_fp_libcpp23
#endif

LBAL_FP_TEST(LIBCPP23, OUT_PTR) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_OUT_PTR);
#if LBAL_LIBCPP23_OUT_PTR
  std::unique_ptr<int> p;

  lbal_fp_libcpp23::make_int(std::out_ptr(p));
  ASSERT_TRUE(p);
  EXPECT_EQ(*p, 5);
#endif
}

LBAL_FP_TEST(LIBCPP23, PRINT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_PRINT);
#if LBAL_LIBCPP23_PRINT
  std::FILE* f = std::tmpfile();
  ASSERT_NE(f, nullptr);

  std::print(f, "{}-", 4);
  std::println(f, "{}", 2);
  std::rewind(f);

  char buffer[8] = {};
  ASSERT_NE(std::fgets(buffer, sizeof(buffer), f), nullptr);
  std::fclose(f);

  EXPECT_STREQ(buffer, "4-2\n");
#endif
}

LBAL_FP_TEST(LIBCPP23, RANGES_AS_CONST) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_AS_CONST);
#if LBAL_LIBCPP23_RANGES_AS_CONST
  std::vector<int> v{1};

  EXPECT_TRUE((std::is_same_v<decltype(*std::ranges::cbegin(v)), const int&>));
  EXPECT_TRUE((std::is_same_v<
      std::ranges::range_reference_t<decltype(v | std::views::as_const)>,
      const int&
  >));
#endif
}

LBAL_FP_TEST(LIBCPP23, RANGES_AS_RVALUE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_AS_RVALUE);
#if LBAL_LIBCPP23_RANGES_AS_RVALUE
  std::vector<std::string> in{"a", "b"};
  std::vector<std::string> out;

  for (auto&& s : in | std::views::as_rvalue)
    out.push_back(std::move(s));

  EXPECT_EQ(out, (std::vector<std::string>{"a", "b"}));
  EXPECT_TRUE((std::is_same_v<
      std::ranges::range_reference_t<decltype(in | std::views::as_rvalue)>,
      std::string&&
  >));
#endif
}

LBAL_FP_TEST(LIBCPP23, RANGES_CARTESIAN_PRODUCT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT);
#if LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT
  std::vector<int> a{1, 2};
  std::vector<char> b{'x', 'y', 'z'};
  int count = 0;

  for ([[maybe_unused]] auto [x, y] : std::views::cartesian_product(a, b))
    ++count;
  EXPECT_EQ(count, 6);
#endif
}

LBAL_FP_TEST(LIBCPP23, RANGES_CARTESIAN_PRODUCT_EMPTY) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT_EMPTY);
#if LBAL_LIBCPP23_RANGES_CARTESIAN_PRODUCT_EMPTY
  //	The product of no ranges is a single empty tuple (P2540R1).
  EXPECT_EQ(std::ranges::distance(std::views::cartesian_product()), 1);
#endif
}

LBAL_FP_TEST(LIBCPP23, RANGES_CHUNK) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_CHUNK);
#if LBAL_LIBCPP23_RANGES_CHUNK
  std::vector<int> v{1, 2, 3, 4, 5};

  EXPECT_EQ(std::ranges::distance(v | std::views::chunk(2)), 3);
#endif
}

LBAL_FP_TEST(LIBCPP23, RANGES_CHUNK_BY) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_CHUNK_BY);
#if LBAL_LIBCPP23_RANGES_CHUNK_BY
  std::vector<int> v{1, 2, 1, 2, 3};

  EXPECT_EQ(
      std::ranges::distance(v | std::views::chunk_by(std::ranges::less{})), 2
  );
#endif
}

LBAL_FP_TEST(LIBCPP23, RANGES_CONTAINS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_CONTAINS);
#if LBAL_LIBCPP23_RANGES_CONTAINS
  std::vector<int> v{1, 2, 3};

  EXPECT_TRUE(std::ranges::contains(v, 2));
  EXPECT_TRUE(std::ranges::contains_subrange(v, std::vector<int>{2, 3}));
  EXPECT_FALSE(std::ranges::contains(v, 4));
#endif
}

LBAL_FP_TEST(LIBCPP23, RANGES_ENUMERATE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_ENUMERATE);
#if LBAL_LIBCPP23_RANGES_ENUMERATE
  std::vector<char> v{'a', 'b'};
  long index_sum = 0;

  for (auto [i, c] : v | std::views::enumerate)
    index_sum += i + (c - 'a');
  EXPECT_EQ(index_sum, 2);
#endif
}

LBAL_FP_TEST(LIBCPP23, RANGES_FIND_LAST) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_FIND_LAST);
#if LBAL_LIBCPP23_RANGES_FIND_LAST
  std::vector<int> v{1, 2, 1, 3};
  auto found = std::ranges::find_last(v, 1);

  EXPECT_EQ(found.begin() - v.begin(), 2);
  EXPECT_EQ(found.end(), v.end());
#endif
}

LBAL_FP_TEST(LIBCPP23, RANGES_FOLD) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_FOLD);
#if LBAL_LIBCPP23_RANGES_FOLD
  std::vector<int> v{1, 2, 3};

  EXPECT_EQ(std::ranges::fold_left(v, 0, std::plus<>{}), 6);
  EXPECT_EQ(std::ranges::fold_right(v, 10, std::minus<>{}), -8);
  EXPECT_EQ(std::ranges::fold_left_first(v, std::multiplies<>{}), 6);
#endif
}

LBAL_FP_TEST(LIBCPP23, RANGES_FORMALIZED_VIEW) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_FORMALIZED_VIEW);
#if LBAL_LIBCPP23_RANGES_FORMALIZED_VIEW
  //	`views::all` of an rvalue container makes an `owning_view` (P2415R2).
  auto all = std::views::all(std::vector<int>{1, 2});

  EXPECT_TRUE((
      std::is_same_v<decltype(all), std::ranges::owning_view<std::vector<int>>>
  ));
  EXPECT_EQ(all.size(), 2u);
#endif
}

LBAL_FP_TEST(LIBCPP23, RANGES_IOTA) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_IOTA);
#if LBAL_LIBCPP23_RANGES_IOTA
  std::vector<int> v(3);

  std::ranges::iota(v, 5);
  EXPECT_EQ(v, (std::vector<int>{5, 6, 7}));
#endif
}

LBAL_FP_TEST(LIBCPP23, RANGES_JOIN_WITH) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_JOIN_WITH);
#if LBAL_LIBCPP23_RANGES_JOIN_WITH
  std::vector<std::string> words{"ab", "c"};
  std::string joined;

  for (char c : words | std::views::join_with(','))
    joined += c;
  EXPECT_EQ(joined, "ab,c");
#endif
}

LBAL_FP_TEST(LIBCPP23, RANGES_NON_DEFAULT_CONSTRUCTIBLE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_NON_DEFAULT_CONSTRUCTIBLE);
#if LBAL_LIBCPP23_RANGES_NON_DEFAULT_CONSTRUCTIBLE
  //	A view over a capturing lambda isn’t default constructible, but is still
  //	a view (P2325R3).
  int offset = 1;
  std::vector<int> v{1, 2};
  auto view = v | std::views::transform([offset](int x) {
    return x + offset;
  });

  EXPECT_FALSE(std::default_initializable<decltype(view)>);
  EXPECT_TRUE(std::ranges::view<decltype(view)>);
#endif
}

LBAL_FP_TEST(LIBCPP23, RANGES_RELAXED) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_RELAXED);
#if LBAL_LIBCPP23_RANGES_RELAXED
  //	P2609R3’s own example: a projection returning a move-only prvalue, and a
  //	function that takes it by value. Before, the indirect callable concepts
  //	also required calling it with `iter_value_t<projected<…>>&`, which can’t
  //	bind to the by-value parameter.
  using I = std::ranges::iterator_t<std::ranges::iota_view<int, int>>;
  auto take = [](std::unique_ptr<int>) { };
  auto proj = [](int v) {
    return std::make_unique<int>(v);
  };

  EXPECT_TRUE((std::indirectly_unary_invocable<
      decltype(take),
      std::projected<I, decltype(proj)>
  >));
#endif
}

#if LBAL_LIBCPP23_RANGES_REMOVE_POISON_PILLS
namespace lbal_fp_libcpp23 {

//	Only declared: `ranges::range` checks the expressions, it doesn’t call them.
struct ConstOnlyRange {
  friend const int* begin(const ConstOnlyRange&);
  friend const int* end(const ConstOnlyRange&);
};

}  // namespace lbal_fp_libcpp23
#endif

LBAL_FP_TEST(LIBCPP23, RANGES_REMOVE_POISON_PILLS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_REMOVE_POISON_PILLS);
#if LBAL_LIBCPP23_RANGES_REMOVE_POISON_PILLS
  //	P2602R2’s own example: with the old poison pills, a type whose
  //	non-member `begin` and `end` take only a `const&` isn’t a range unless it
  //	is `const`.
  EXPECT_TRUE(std::ranges::range<lbal_fp_libcpp23::ConstOnlyRange>);
#endif
}

LBAL_FP_TEST(LIBCPP23, RANGES_REPEAT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_REPEAT);
#if LBAL_LIBCPP23_RANGES_REPEAT
  int sum = 0;

  for (int x : std::views::repeat(7, 3))
    sum += x;
  EXPECT_EQ(sum, 21);
#endif
}

LBAL_FP_TEST(LIBCPP23, RANGES_SLIDE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_SLIDE);
#if LBAL_LIBCPP23_RANGES_SLIDE
  std::vector<int> v{1, 2, 3, 4};

  EXPECT_EQ(std::ranges::distance(v | std::views::slide(2)), 3);
#endif
}

LBAL_FP_TEST(LIBCPP23, RANGES_STARTS_ENDS_WITH) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_STARTS_ENDS_WITH);
#if LBAL_LIBCPP23_RANGES_STARTS_ENDS_WITH
  std::vector<int> v{1, 2, 3};

  EXPECT_TRUE(std::ranges::starts_with(v, std::vector<int>{1, 2}));
  EXPECT_TRUE(std::ranges::ends_with(v, std::vector<int>{3}));
#endif
}

LBAL_FP_TEST(LIBCPP23, RANGES_STRIDE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_STRIDE);
#if LBAL_LIBCPP23_RANGES_STRIDE
  std::vector<int> v{1, 2, 3, 4, 5};
  int sum = 0;

  for (int x : v | std::views::stride(2))
    sum += x;
  EXPECT_EQ(sum, 9);
#endif
}

LBAL_FP_TEST(LIBCPP23, RANGES_SUPPORT_MOVE_ONLY_TYPES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_SUPPORT_MOVE_ONLY_TYPES);
#if LBAL_LIBCPP23_RANGES_SUPPORT_MOVE_ONLY_TYPES
  //	Range adaptors accept move-only callables (P2494R2).
  auto add = [p = std::make_unique<int>(1)](int x) {
    return x + *p;
  };
  int sum = 0;

  for (int x : std::views::iota(0, 2) | std::views::transform(std::move(add)))
    sum += x;
  EXPECT_EQ(sum, 3);
#endif
}

LBAL_FP_TEST(LIBCPP23, RANGES_TO_CONTAINER) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_TO_CONTAINER);
#if LBAL_LIBCPP23_RANGES_TO_CONTAINER
  auto v = std::views::iota(1, 4) | std::ranges::to<std::vector>();
  auto s = std::ranges::to<std::set<int>>(v);

  EXPECT_EQ(v, (std::vector<int>{1, 2, 3}));
  EXPECT_EQ(s.size(), 3u);
#endif
}

#if LBAL_LIBCPP23_RANGES_USER_ADAPTOR_PIPES
namespace lbal_fp_libcpp23 {

struct TakeOne : std::ranges::range_adaptor_closure<TakeOne> {
  template <std::ranges::viewable_range R>
  auto
  operator() (R&& r) const {
    return std::views::all(std::forward<R>(r)) | std::views::take(1);
  }
};

}  // namespace lbal_fp_libcpp23
#endif

LBAL_FP_TEST(LIBCPP23, RANGES_USER_ADAPTOR_PIPES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_USER_ADAPTOR_PIPES);
#if LBAL_LIBCPP23_RANGES_USER_ADAPTOR_PIPES
  std::vector<int> v{4, 5};

  EXPECT_EQ(std::ranges::distance(v | lbal_fp_libcpp23::TakeOne{}), 1);
#endif
}

LBAL_FP_TEST(LIBCPP23, RANGES_ZIP) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_RANGES_ZIP);
#if LBAL_LIBCPP23_RANGES_ZIP
  std::vector<int> a{1, 2, 3};
  std::vector<int> b{10, 20};
  int sum = 0;

  for (auto [x, y] : std::views::zip(a, b))
    sum += x * y;
  EXPECT_EQ(sum, 50);

  int products = 0;
  for (int p : std::views::zip_transform(std::multiplies<>{}, a, b))
    products += p;
  EXPECT_EQ(products, 50);

  EXPECT_EQ(std::ranges::distance(a | std::views::pairwise), 2);
#endif
}

//	`LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY` has a compile-only probe in
//	`probes/libcpp23/`: the full feature also changes `pair`, `tuple` and
//	`INVOKE<R>`.

LBAL_FP_TEST(LIBCPP23, REFERENCE_FROM_TEMPORARY_TRAITS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY_TRAITS);
#if LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY_TRAITS
  EXPECT_TRUE((std::reference_constructs_from_temporary_v<const int&, long>));
  EXPECT_FALSE((std::reference_constructs_from_temporary_v<const int&, int&>));
  EXPECT_TRUE((std::reference_converts_from_temporary_v<const int&, long>));
  EXPECT_FALSE((std::reference_converts_from_temporary_v<const int&, int&>));
#endif
}

LBAL_FP_TEST(LIBCPP23, SHIFT_RANGES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_SHIFT_RANGES);
#if LBAL_LIBCPP23_SHIFT_RANGES
  std::vector<int> v{1, 2, 3, 4};
  auto rest = std::ranges::shift_left(v, 1);

  EXPECT_EQ(rest.end() - v.begin(), 3);
  EXPECT_EQ(v[0], 2);
#endif
}

LBAL_FP_TEST(LIBCPP23, SPANSTREAM) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_SPANSTREAM);
#if LBAL_LIBCPP23_SPANSTREAM
  char input[] = "12 34";
  std::ispanstream in(std::span<char>(input, 5));
  int a = 0;
  int b = 0;
  in >> a >> b;
  EXPECT_EQ(a + b, 46);

  char output[8] = {};
  std::ospanstream out{std::span<char>(output)};
  out << "hi";
  EXPECT_EQ(std::string_view(out.span().data(), out.span().size()), "hi");
#endif
}

LBAL_FP_TEST(LIBCPP23, STACKTRACE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_STACKTRACE);
#if LBAL_LIBCPP23_STACKTRACE
  auto trace = std::stacktrace::current();

  EXPECT_FALSE(trace.empty());
  EXPECT_FALSE(std::to_string(trace).empty());
#endif
}

LBAL_FP_TEST(LIBCPP23, START_LIFETIME_AS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_START_LIFETIME_AS);
#if LBAL_LIBCPP23_START_LIFETIME_AS
  //	SEEME
  alignas(int) unsigned char storage[sizeof(int)];
  int value = 42;
  std::memcpy(storage, &value, sizeof(int));

  EXPECT_EQ(*std::start_lifetime_as<int>(storage), 42);
#endif
}

LBAL_FP_TEST(LIBCPP23, STDATOMIC_H) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_STDATOMIC_H);
#if LBAL_LIBCPP23_STDATOMIC_H
  //	The C names refer to the C++ atomics (P0943R6).
  atomic_int x;
  atomic_store(&x, 1);

  EXPECT_EQ(atomic_load(&x), 1);
  EXPECT_TRUE((std::is_same_v<atomic_int, std::atomic<int>>));
#endif
}

LBAL_FP_TEST(LIBCPP23, STRING_CONTAINS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_STRING_CONTAINS);
#if LBAL_LIBCPP23_STRING_CONTAINS
  std::string s = "hello";

  EXPECT_TRUE(s.contains("ell"));
  EXPECT_TRUE(std::string_view(s).contains('o'));
  EXPECT_FALSE(s.contains("x"));
#endif
}

LBAL_FP_TEST(LIBCPP23, STRING_RESIZE_AND_OVERWRITE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_STRING_RESIZE_AND_OVERWRITE);
#if LBAL_LIBCPP23_STRING_RESIZE_AND_OVERWRITE
  std::string s;

  s.resize_and_overwrite(8, [](char* p, std::size_t) {
    std::memcpy(p, "abc", 3);
    return std::size_t{3};
  });
  EXPECT_EQ(s, "abc");
#endif
}

LBAL_FP_TEST(LIBCPP23, TO_UNDERLYING) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_TO_UNDERLYING);
#if LBAL_LIBCPP23_TO_UNDERLYING
  enum class Small : std::uint8_t {
    value = 7,
  };

  EXPECT_EQ(std::to_underlying(Small::value), 7);
  EXPECT_TRUE((
      std::is_same_v<decltype(std::to_underlying(Small::value)), std::uint8_t>
  ));
#endif
}

LBAL_FP_TEST(LIBCPP23, TUPLE_LIKE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_TUPLE_LIKE);
#if LBAL_LIBCPP23_TUPLE_LIKE
  //	`pair` and `tuple` interoperate with other tuple-like types (P2165R4).
  std::pair<int, int> p = std::tuple<int, int>(1, 2);
  std::tuple<int, int> t = std::array<int, 2>{3, 4};

  EXPECT_EQ(p.second, 2);
  EXPECT_EQ(std::get<1>(t), 4);
#endif
}

#if LBAL_LIBCPP23_UNREACHABLE
namespace lbal_fp_libcpp23 {

inline int
only_one(int x) {
  if (x == 1)
    return 1;
  std::unreachable();
}

}  // namespace lbal_fp_libcpp23
#endif

LBAL_FP_TEST(LIBCPP23, UNREACHABLE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_UNREACHABLE);
#if LBAL_LIBCPP23_UNREACHABLE
  EXPECT_EQ(lbal_fp_libcpp23::only_one(1), 1);
#endif
}

LBAL_FP_TEST(LIBCPP23, VARIANT_INHERITANCE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP23_VARIANT_INHERITANCE);
#if LBAL_LIBCPP23_VARIANT_INHERITANCE
  //	`std::visit` accepts classes derived from `std::variant` (P2162R2).
  struct Derived : std::variant<int, double> {
    using variant::variant;
  };

  EXPECT_EQ(
      std::visit(
          [](auto x) {
            return sizeof(x);
          },
          Derived{1}
      ),
      sizeof(int)
  );
#endif
}
