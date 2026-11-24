/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFalsePositiveTest-libcpp20.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Soft false-positive probes for `LBAL_LIBCPP20_*` tokens. Tokens that are only
  about `constexpr` support have hard probes in `probes/libcpp20/`.

  Headers that aren’t guaranteed to exist are included only when a token says
  they’re usable.

------------------------------------------------------------------------------*/

//	std
#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <thread>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#if LBAL_LIBCPP20_BARRIER
  #include <barrier>
#endif

#if LBAL_LIBCPP20_BITOPS                                                       \
    || LBAL_LIBCPP20_BIT_CAST                                                  \
    || LBAL_LIBCPP20_ENDIAN_BIT                                                \
    || LBAL_LIBCPP20_INT_POW2                                                  \
    || LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME
  #include <bit>
#endif

#if LBAL_LIBCPP20_CONCEPTS                                                     \
    || LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE                                 \
    || LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE
  #include <concepts>
#endif

#if LBAL_LIBCPP20_COROUTINE
  #include <coroutine>
#endif

#if LBAL_LIBCPP20_EXECUTION_VECTORIZATION
  #include <execution>
#endif

#if LBAL_LIBCPP20_FORMAT
  #include <format>
#endif

#if LBAL_LIBCPP20_INTERPOLATE
  #include <cmath>
  #include <numeric>
#endif

#if LBAL_LIBCPP20_JTHREAD || LBAL_LIBCPP20_JTHREAD_CV
  #include <condition_variable>
  #include <stop_token>
#endif

#if LBAL_LIBCPP20_LATCH
  #include <latch>
#endif

#if LBAL_LIBCPP20_MATH_CONSTANTS
  #include <numbers>
#endif

#if LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR
  #include <memory_resource>
#endif

#if LBAL_LIBCPP20_RANGES                                                       \
    || LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS                                     \
    || LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE
  #include <ranges>
#endif

#if LBAL_LIBCPP20_SEMAPHORE
  #include <semaphore>
#endif

#if LBAL_LIBCPP20_SOURCE_LOCATION
  #include <source_location>
#endif

#if LBAL_LIBCPP20_SPAN                                                         \
    || LBAL_LIBCPP20_SPAN_FIXED_SIZE                                           \
    || LBAL_LIBCPP20_SPAN_USABILITY                                            \
    || LBAL_LIBCPP20_SSIZE
  #include <span>
#endif

#if LBAL_LIBCPP20_SYNCBUF || LBAL_LIBCPP20_SYNCBUF_MANIPULATORS
  #include <syncstream>
#endif

#if LBAL_LIBCPP20_THREE_WAY_COMPARISON                                         \
    || LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY
  #include <compare>
#endif

#if LBAL_LIBCPP20_VERSION
  #include <version>
#endif

namespace lbal_fp_libcpp20 {

struct Standard {
  int a;
  int b;
};

}  // namespace lbal_fp_libcpp20

LBAL_FP_TEST(LIBCPP20, ASSUME_ALIGNED) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_ASSUME_ALIGNED);
#if LBAL_LIBCPP20_ASSUME_ALIGNED
  alignas(64) int storage[16] = {7};

  EXPECT_EQ(*std::assume_aligned<64>(storage), 7);
#endif
}

LBAL_FP_TEST(LIBCPP20, ATOMIC_FLAG_TEST) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_ATOMIC_FLAG_TEST);
#if LBAL_LIBCPP20_ATOMIC_FLAG_TEST
  std::atomic_flag flag;

  EXPECT_FALSE(flag.test());
  flag.test_and_set();
  EXPECT_TRUE(flag.test());
  EXPECT_TRUE(std::atomic_flag_test(&flag));
#endif
}

LBAL_FP_TEST(LIBCPP20, ATOMIC_FLOAT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_ATOMIC_FLOAT);
#if LBAL_LIBCPP20_ATOMIC_FLOAT
  std::atomic<double> d{1.5};

  EXPECT_EQ(d.fetch_add(1.0), 1.5);
  EXPECT_EQ(d.fetch_sub(0.5), 2.5);
  EXPECT_EQ(d.load(), 2.0);
#endif
}

LBAL_FP_TEST(LIBCPP20, ATOMIC_LOCK_FREE_TYPE_ALIASES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES);
#if LBAL_LIBCPP20_ATOMIC_LOCK_FREE_TYPE_ALIASES
  EXPECT_TRUE(std::atomic_signed_lock_free::is_always_lock_free);
  EXPECT_TRUE(std::atomic_unsigned_lock_free::is_always_lock_free);
#endif
}

LBAL_FP_TEST(LIBCPP20, ATOMIC_REF) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_ATOMIC_REF);
#if LBAL_LIBCPP20_ATOMIC_REF
  alignas(std::atomic_ref<int>::required_alignment) int value = 1;
  std::atomic_ref<int> ref(value);

  ref.fetch_add(2);
  EXPECT_EQ(value, 3);
#endif
}

LBAL_FP_TEST(LIBCPP20, ATOMIC_SHARED_PTR) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_ATOMIC_SHARED_PTR);
#if LBAL_LIBCPP20_ATOMIC_SHARED_PTR
  std::atomic<std::shared_ptr<int>> a{std::make_shared<int>(1)};
  std::atomic<std::weak_ptr<int>> w;

  a.store(std::make_shared<int>(2));
  EXPECT_EQ(*a.load(), 2);
  EXPECT_TRUE(w.load().expired());
#endif
}

LBAL_FP_TEST(LIBCPP20, ATOMIC_VALUE_INITIALIZATION) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION);
#if LBAL_LIBCPP20_ATOMIC_VALUE_INITIALIZATION
  //	The default constructor value-initializes the contained object
  //	(P0883R2). Constructing over storage that isn’t zero makes the old
  //	behavior visible.
  alignas(std::atomic<int>) unsigned char storage[sizeof(std::atomic<int>)];
  std::memset(storage, 0xFF, sizeof(storage));
  auto* a = ::new (static_cast<void*>(storage)) std::atomic<int>;

  alignas(
      std::atomic_flag
  ) unsigned char flag_storage[sizeof(std::atomic_flag)];
  std::memset(flag_storage, 0xFF, sizeof(flag_storage));
  auto* f = ::new (static_cast<void*>(flag_storage)) std::atomic_flag;

  EXPECT_EQ(a->load(), 0);
  EXPECT_FALSE(f->test_and_set());
#endif
}

LBAL_FP_TEST(LIBCPP20, ATOMIC_WAIT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_ATOMIC_WAIT);
#if LBAL_LIBCPP20_ATOMIC_WAIT
  std::atomic<int> value{0};

  std::thread waker([&] {
    value.store(1);
    value.notify_one();
  });

  value.wait(0);
  waker.join();
  EXPECT_EQ(value.load(), 1);
#endif
}

LBAL_FP_TEST(LIBCPP20, BARRIER) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_BARRIER);
#if LBAL_LIBCPP20_BARRIER
  std::atomic<int> completions{0};
  std::barrier sync(2, [&]() noexcept {
    ++completions;
  });

  std::thread other([&] {
    sync.arrive_and_wait();
  });
  sync.arrive_and_wait();
  other.join();

  EXPECT_EQ(completions.load(), 1);
#endif
}

LBAL_FP_TEST(LIBCPP20, BIND_FRONT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_BIND_FRONT);
#if LBAL_LIBCPP20_BIND_FRONT
  auto minus_from_ten = std::bind_front(std::minus<>{}, 10);

  EXPECT_EQ(minus_from_ten(3), 7);
#endif
}

LBAL_FP_TEST(LIBCPP20, BIND_FRONT_NO_UNWRAP) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP);
#if LBAL_LIBCPP20_BIND_FRONT_NO_UNWRAP
  //	A bound `reference_wrapper` is passed as-is, not unwrapped (P1651R0).
  int x = 1;
  auto bound = std::bind_front(
      [](auto arg) {
        return std::is_same_v<decltype(arg), std::reference_wrapper<int>>;
      },
      std::ref(x)
  );

  EXPECT_TRUE(bound());
#endif
}

LBAL_FP_TEST(LIBCPP20, BITOPS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_BITOPS);
#if LBAL_LIBCPP20_BITOPS
  EXPECT_EQ(std::popcount(0b1011u), 3);
  EXPECT_EQ(std::countl_zero(std::uint8_t{1}), 7);
  EXPECT_EQ(std::countr_zero(8u), 3);
  EXPECT_EQ(std::rotl(std::uint8_t{0b1000'0001}, 1), 0b0000'0011);
#endif
}

LBAL_FP_TEST(LIBCPP20, BIT_CAST) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_BIT_CAST);
#if LBAL_LIBCPP20_BIT_CAST
  EXPECT_EQ(std::bit_cast<std::uint32_t>(1.0f), 0x3F80'0000u);
#endif
}

LBAL_FP_TEST(LIBCPP20, BOUNDED_ARRAY_TRAITS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS);
#if LBAL_LIBCPP20_BOUNDED_ARRAY_TRAITS
  EXPECT_TRUE(std::is_bounded_array_v<int[3]>);
  EXPECT_FALSE(std::is_bounded_array_v<int[]>);
  EXPECT_TRUE(std::is_unbounded_array_v<int[]>);
#endif
}

LBAL_FP_TEST(LIBCPP20, CHAR8_T) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_CHAR8_T);
#if LBAL_LIBCPP20_CHAR8_T
  std::u8string s = u8"abc";

  EXPECT_EQ(s.size(), 3u);
  EXPECT_TRUE((std::is_same_v<std::u8string_view::value_type, char8_t>));
#endif
}

LBAL_FP_TEST(LIBCPP20, CHAR8_T_COMPAT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_CHAR8_T_COMPAT);
#if LBAL_LIBCPP20_CHAR8_T_COMPAT
  //	`std::char_traits<char8_t>` and the `u8string` hash exist (P1423R3).
  EXPECT_EQ(std::char_traits<char8_t>::length(u8"ab"), 2u);
  EXPECT_EQ(
      std::hash<std::u8string>{}(u8"a"), std::hash<std::u8string>{}(u8"a")
  );
#endif
}

//	`LBAL_LIBCPP20_CHRONO_CALENDAR` and `LBAL_LIBCPP20_CHRONO_FIXES` have
//	compile-only probes in `probes/libcpp20/`: what sets them apart from the
//	calendar types is names that libc++ lacks.

LBAL_FP_TEST(LIBCPP20, CHRONO_CALENDAR_TYPES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_CHRONO_CALENDAR_TYPES);
#if LBAL_LIBCPP20_CHRONO_CALENDAR_TYPES
  using namespace std::chrono;

  //	The calendar types from P0355R7, without time zones or parsing.
  constexpr year_month_day ymd{year{2024}, month{2}, day{29}};
  EXPECT_TRUE(ymd.ok());
  EXPECT_EQ(weekday{sys_days{ymd}}, Thursday);
  EXPECT_FALSE((year_month_day{year{2023}, month{2}, day{29}}.ok()));

  EXPECT_EQ(duration_cast<hours>(days{1}).count(), 24);
  EXPECT_EQ(duration_cast<days>(weeks{1}).count(), 7);
  EXPECT_EQ(static_cast<int>(2024y), 2024);
#endif
}

LBAL_FP_TEST(LIBCPP20, CONCEPTS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_CONCEPTS);
#if LBAL_LIBCPP20_CONCEPTS
  EXPECT_TRUE(std::integral<int>);
  EXPECT_FALSE(std::integral<double>);
  EXPECT_TRUE((std::convertible_to<int, long>));
  EXPECT_TRUE(std::regular<int>);
#endif
}

LBAL_FP_TEST(LIBCPP20, CONCEPTS_BOOLEAN_TESTABLE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE);
#if LBAL_LIBCPP20_CONCEPTS_BOOLEAN_TESTABLE
  //	Comparison concepts use the exposition-only boolean-testable (P1964R2).
  EXPECT_TRUE(std::equality_comparable<int>);
  EXPECT_TRUE(std::totally_ordered<std::string>);
#endif
}

LBAL_FP_TEST(LIBCPP20, CONCEPTS_STANDARD_CASE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE);
#if LBAL_LIBCPP20_CONCEPTS_STANDARD_CASE
  //	The `standard_case` names (P1754R1).
  EXPECT_TRUE((std::same_as<int, int>));
  EXPECT_TRUE(std::default_initializable<int>);
  EXPECT_TRUE(std::copy_constructible<std::string>);
#endif
}

#if LBAL_LIBCPP20_COROUTINE
namespace lbal_fp_libcpp20 {

struct Generator {
  struct promise_type {
    int current = 0;

    Generator
    get_return_object() {
      return Generator{
        std::coroutine_handle<promise_type>::from_promise(*this)
      };
    }

    std::suspend_always
    initial_suspend() noexcept {
      return {};
    }

    std::suspend_always
    final_suspend() noexcept {
      return {};
    }

    std::suspend_always
    yield_value(int v) {
      current = v;
      return {};
    }

    void
    return_void() { }

    void
    unhandled_exception() { }
  };

  explicit Generator(std::coroutine_handle<promise_type> h)
    : handle(h) { }

  Generator(Generator&& other) noexcept
    : handle(std::exchange(other.handle, {})) { }

  ~Generator() {
    if (handle)
      handle.destroy();
  }

  std::coroutine_handle<promise_type> handle;
};

inline Generator
count_to(int n) {
  for (int i = 1; i <= n; ++i)
    co_yield i;
}

}  // namespace lbal_fp_libcpp20
#endif

LBAL_FP_TEST(LIBCPP20, COROUTINE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_COROUTINE);
#if LBAL_LIBCPP20_COROUTINE
  auto gen = lbal_fp_libcpp20::count_to(3);
  int sum = 0;

  while (true) {
    gen.handle.resume();
    if (gen.handle.done())
      break;
    sum += gen.handle.promise().current;
  }

  EXPECT_EQ(sum, 6);
#endif
}

LBAL_FP_TEST(LIBCPP20, DESTROYING_DELETE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_DESTROYING_DELETE);
#if LBAL_LIBCPP20_DESTROYING_DELETE
  EXPECT_TRUE(std::is_empty_v<std::destroying_delete_t>);
  (void)std::destroying_delete;
#endif
}

LBAL_FP_TEST(LIBCPP20, ENDIAN) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_ENDIAN);
#if LBAL_LIBCPP20_ENDIAN
  EXPECT_TRUE(
      std::endian::native == std::endian::little
      || std::endian::native == std::endian::big
  );
#endif
}

LBAL_FP_TEST(LIBCPP20, ENDIAN_BIT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_ENDIAN_BIT);
#if LBAL_LIBCPP20_ENDIAN_BIT
  //	`std::endian` is reachable through `<bit>` (P1612R1).
  std::uint16_t one = 1;
  bool little = *reinterpret_cast<unsigned char*>(&one) == 1;

  EXPECT_EQ(std::endian::native == std::endian::little, little);
#endif
}

LBAL_FP_TEST(LIBCPP20, ERASE_IF) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_ERASE_IF);
#if LBAL_LIBCPP20_ERASE_IF
  std::vector<int> v{1, 2, 3, 4};
  std::map<int, int> m{{1, 1}, {2, 2}};

  std::erase_if(v, [](int x) {
    return x % 2 == 0;
  });
  std::erase(v, 3);
  std::erase_if(m, [](const auto& p) {
    return p.first == 1;
  });

  EXPECT_EQ(v, (std::vector<int>{1}));
  EXPECT_EQ(m.size(), 1u);
#endif
}

LBAL_FP_TEST(LIBCPP20, ERASE_IF_FREE_FUNCTIONS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS);
#if LBAL_LIBCPP20_ERASE_IF_FREE_FUNCTIONS
  //	The free functions return the number of erased elements (P1115R3).
  std::vector<int> v{1, 2, 2, 3};
  std::list<int> l{1, 1, 2};

  EXPECT_EQ(std::erase(v, 2), 2u);
  EXPECT_EQ(
      std::erase_if(
          l,
          [](int x) {
            return x == 1;
          }
      ),
      2u
  );
#endif
}

LBAL_FP_TEST(LIBCPP20, EXECUTION_VECTORIZATION) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_EXECUTION_VECTORIZATION);
#if LBAL_LIBCPP20_EXECUTION_VECTORIZATION
  std::vector<int> v{3, 1, 2};

  std::sort(std::execution::unseq, v.begin(), v.end());
  EXPECT_EQ(v, (std::vector<int>{1, 2, 3}));
  EXPECT_TRUE(std::is_execution_policy_v<std::execution::unsequenced_policy>);
#endif
}

LBAL_FP_TEST(LIBCPP20, FORMAT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_FORMAT);
#if LBAL_LIBCPP20_FORMAT
  EXPECT_EQ(std::format("{} {:>4} {:.2f}", 1, "ab", 1.5), "1   ab 1.50");
  EXPECT_EQ(std::formatted_size("{:x}", 255), 2u);
#endif
}

#if LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP
namespace lbal_fp_libcpp20 {

struct StringHash {
  using is_transparent = void;

  std::size_t
  operator() (std::string_view sv) const {
    return std::hash<std::string_view>{}(sv);
  }
};

}  // namespace lbal_fp_libcpp20
#endif

LBAL_FP_TEST(LIBCPP20, GENERIC_UNORDERED_LOOKUP) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP);
#if LBAL_LIBCPP20_GENERIC_UNORDERED_LOOKUP
  std::unordered_set<std::string, lbal_fp_libcpp20::StringHash, std::equal_to<>>
      s{"abc"};

  //	Looked up by `string_view`, without constructing a `std::string`.
  EXPECT_NE(s.find(std::string_view("abc")), s.end());
  EXPECT_TRUE(s.contains(std::string_view("abc")));
#endif
}

LBAL_FP_TEST(LIBCPP20, INTEGER_COMPARISON_FUNCTIONS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS);
#if LBAL_LIBCPP20_INTEGER_COMPARISON_FUNCTIONS
  EXPECT_TRUE(std::cmp_less(-1, 0u));
  EXPECT_FALSE(std::cmp_equal(-1, static_cast<unsigned>(-1)));
  EXPECT_TRUE(std::in_range<std::uint8_t>(255));
  EXPECT_FALSE(std::in_range<std::uint8_t>(256));
#endif
}

LBAL_FP_TEST(LIBCPP20, INTERPOLATE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_INTERPOLATE);
#if LBAL_LIBCPP20_INTERPOLATE
  int a[] = {0, 10};

  EXPECT_EQ(std::midpoint(2, 8), 5);
  EXPECT_EQ(std::midpoint(a, a + 2), a + 1);
  EXPECT_DOUBLE_EQ(std::lerp(0.0, 10.0, 0.25), 2.5);
#endif
}

LBAL_FP_TEST(LIBCPP20, INT_POW2) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_INT_POW2);
#if LBAL_LIBCPP20_INT_POW2
  EXPECT_TRUE(std::has_single_bit(8u));
  EXPECT_EQ(std::bit_ceil(5u), 8u);
  EXPECT_EQ(std::bit_floor(5u), 4u);
  EXPECT_EQ(std::bit_width(5u), 3);
#endif
}

#if LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME
namespace lbal_fp_libcpp20 {

LBAL_FP_DETECT(has_bit_width, T, std::bit_width(std::declval<T>()))

}  // namespace lbal_fp_libcpp20
#endif

LBAL_FP_TEST(LIBCPP20, INT_POW2_FUNCTION_RENAME) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME);
#if LBAL_LIBCPP20_INT_POW2_FUNCTION_RENAME
  //	The final names from P1956R1, with `bit_width` returning `int`.
  EXPECT_TRUE(lbal_fp_libcpp20::has_bit_width<unsigned>::value);
  EXPECT_TRUE((std::is_same_v<decltype(std::bit_width(1u)), int>));
#endif
}

LBAL_FP_TEST(LIBCPP20, IS_CONSTANT_EVALUATED) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_IS_CONSTANT_EVALUATED);
#if LBAL_LIBCPP20_IS_CONSTANT_EVALUATED
  constexpr auto where = [] {
    return std::is_constant_evaluated();
  };
  constexpr bool at_compile_time = where();
  bool (*at_run_time)() = where;

  EXPECT_TRUE(at_compile_time);
  EXPECT_FALSE(at_run_time());
#endif
}

LBAL_FP_TEST(LIBCPP20, IS_NOTHROW_CONVERTIBLE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE);
#if LBAL_LIBCPP20_IS_NOTHROW_CONVERTIBLE
  struct Throwing {
    Throwing(int) noexcept(false) { }
  };

  EXPECT_TRUE((std::is_nothrow_convertible_v<int, long>));
  EXPECT_FALSE((std::is_nothrow_convertible_v<int, Throwing>));
#endif
}

LBAL_FP_TEST(LIBCPP20, IS_POINTER_INTERCONVERTIBLE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE);
#if LBAL_LIBCPP20_IS_POINTER_INTERCONVERTIBLE
  using lbal_fp_libcpp20::Standard;

  EXPECT_TRUE(std::is_pointer_interconvertible_with_class(&Standard::a));
  EXPECT_FALSE(std::is_pointer_interconvertible_with_class(&Standard::b));
#endif
}

LBAL_FP_TEST(LIBCPP20, JTHREAD) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_JTHREAD);
#if LBAL_LIBCPP20_JTHREAD
  std::atomic<bool> stopped{false};

  {
    std::jthread worker([&](std::stop_token token) {
      while (!token.stop_requested())
        std::this_thread::yield();
      stopped = true;
    });
  }  //	The destructor requests a stop and joins.

  EXPECT_TRUE(stopped.load());
#endif
}

LBAL_FP_TEST(LIBCPP20, JTHREAD_CV) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_JTHREAD_CV);
#if LBAL_LIBCPP20_JTHREAD_CV
  //	`condition_variable_any::wait` takes a `stop_token` (P1869R1).
  std::mutex m;
  std::condition_variable_any cv;
  bool woke_without_predicate = true;

  std::jthread worker([&](std::stop_token token) {
    std::unique_lock lock(m);
    woke_without_predicate = cv.wait(lock, token, [] {
      return false;
    });
  });

  worker.request_stop();
  worker.join();
  EXPECT_FALSE(woke_without_predicate);
#endif
}

LBAL_FP_TEST(LIBCPP20, LATCH) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_LATCH);
#if LBAL_LIBCPP20_LATCH
  std::latch done(2);

  std::thread other([&] {
    done.count_down();
  });
  done.count_down();
  done.wait();
  other.join();

  EXPECT_TRUE(done.try_wait());
#endif
}

LBAL_FP_TEST(LIBCPP20, LIST_REMOVE_RETURN_TYPE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE);
#if LBAL_LIBCPP20_LIST_REMOVE_RETURN_TYPE
  std::list<int> l{1, 2, 2, 3, 3};

  EXPECT_EQ(l.remove(2), 2u);
  EXPECT_EQ(l.unique(), 1u);
  EXPECT_EQ(
      l.remove_if([](int x) {
        return x == 1;
      }),
      1u
  );
#endif
}

LBAL_FP_TEST(LIBCPP20, MATH_CONSTANTS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_MATH_CONSTANTS);
#if LBAL_LIBCPP20_MATH_CONSTANTS
  EXPECT_DOUBLE_EQ(std::numbers::pi, 3.141592653589793);
  EXPECT_FLOAT_EQ(std::numbers::sqrt2_v<float>, 1.41421356f);
#endif
}

LBAL_FP_TEST(LIBCPP20, POLYMORPHIC_ALLOCATOR) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR);
#if LBAL_LIBCPP20_POLYMORPHIC_ALLOCATOR
  //	`polymorphic_allocator<>` defaults to `std::byte` and gains
  //	`new_object` and friends (P0339R6).
  std::pmr::polymorphic_allocator<> alloc;
  int* p = alloc.new_object<int>(5);

  EXPECT_TRUE((std::is_same_v<decltype(alloc)::value_type, std::byte>));
  EXPECT_EQ(*p, 5);
  alloc.delete_object(p);
#endif
}

LBAL_FP_TEST(LIBCPP20, RANGES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_RANGES);
#if LBAL_LIBCPP20_RANGES
  std::vector<int> v{3, 1, 2};

  std::ranges::sort(v);
  EXPECT_EQ(v, (std::vector<int>{1, 2, 3}));

  int total = 0;
  for (int x : v | std::views::filter([](int x) {
         return x != 2;
       }) | std::views::transform([](int x) {
         return x * 10;
       }))
  {
    total += x;
  }
  EXPECT_EQ(total, 40);
#endif
}

LBAL_FP_TEST(LIBCPP20, RANGES_INPUT_ADAPTORS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS);
#if LBAL_LIBCPP20_RANGES_INPUT_ADAPTORS
  //	Views over input ranges, such as `istream_view` (P1035R7).
  std::istringstream in("1 2 3");
  int total = 0;

  for (int x : std::views::istream<int>(in) | std::views::take(2))
    total += x;
  EXPECT_EQ(total, 3);
#endif
}

LBAL_FP_TEST(LIBCPP20, RANGES_LOOSENED_COMPARE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE);
#if LBAL_LIBCPP20_RANGES_LOOSENED_COMPARE
  //	Range algorithms accept comparisons between unrelated types
  //	(P1716R3).
  std::vector<int> ints{1, 2, 3};
  std::vector<long> longs{1, 2, 3};

  EXPECT_TRUE(std::ranges::equal(ints, longs));
  EXPECT_NE(std::ranges::find(ints, 2L), ints.end());
#endif
}

LBAL_FP_TEST(LIBCPP20, REMOVE_CVREF) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_REMOVE_CVREF);
#if LBAL_LIBCPP20_REMOVE_CVREF
  EXPECT_TRUE((std::is_same_v<std::remove_cvref_t<const int&>, int>));
#endif
}

LBAL_FP_TEST(LIBCPP20, SEMAPHORE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_SEMAPHORE);
#if LBAL_LIBCPP20_SEMAPHORE
  std::counting_semaphore<2> sem(2);
  std::binary_semaphore bin(0);

  EXPECT_TRUE(sem.try_acquire());
  EXPECT_TRUE(sem.try_acquire());
  EXPECT_FALSE(sem.try_acquire());
  bin.release();
  EXPECT_TRUE(bin.try_acquire());
#endif
}

LBAL_FP_TEST(LIBCPP20, SHARED_PTR_ARRAYS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_SHARED_PTR_ARRAYS);
#if LBAL_LIBCPP20_SHARED_PTR_ARRAYS
  auto bounded = std::make_shared<int[3]>(7);
  auto unbounded = std::make_shared<int[]>(2);

  EXPECT_EQ(bounded[2], 7);
  EXPECT_EQ(unbounded[1], 0);
#endif
}

LBAL_FP_TEST(LIBCPP20, SHIFT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_SHIFT);
#if LBAL_LIBCPP20_SHIFT
  std::vector<int> v{1, 2, 3, 4};

  auto end = std::shift_left(v.begin(), v.end(), 1);
  EXPECT_EQ(end - v.begin(), 3);
  EXPECT_EQ(v[0], 2);

  auto begin = std::shift_right(v.begin(), v.end(), 2);
  EXPECT_EQ(begin - v.begin(), 2);
  EXPECT_EQ(v[2], 2);
#endif
}

LBAL_FP_TEST(LIBCPP20, SMART_PTR_FOR_OVERWRITE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE);
#if LBAL_LIBCPP20_SMART_PTR_FOR_OVERWRITE
  auto unique = std::make_unique_for_overwrite<int[]>(4);
  auto shared = std::make_shared_for_overwrite<int>();

  unique[3] = 1;
  *shared = 2;
  EXPECT_EQ(unique[3] + *shared, 3);
#endif
}

LBAL_FP_TEST(LIBCPP20, SOURCE_LOCATION) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_SOURCE_LOCATION);
#if LBAL_LIBCPP20_SOURCE_LOCATION
  auto here = std::source_location::current();

  EXPECT_EQ(here.line(), static_cast<std::uint_least32_t>(__LINE__ - 2));
  EXPECT_NE(
      std::string_view(here.file_name()).find("libcpp20"),
      std::string_view::npos
  );
#endif
}

LBAL_FP_TEST(LIBCPP20, SPAN) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_SPAN);
#if LBAL_LIBCPP20_SPAN
  int a[] = {1, 2, 3, 4};
  std::span<int> s(a);

  EXPECT_EQ(s.size(), 4u);
  EXPECT_EQ(s.subspan(1, 2)[1], 3);
  EXPECT_EQ(s.last<1>()[0], 4);
#endif
}

LBAL_FP_TEST(LIBCPP20, SPAN_FIXED_SIZE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_SPAN_FIXED_SIZE);
#if LBAL_LIBCPP20_SPAN_FIXED_SIZE
  //	A fixed-size span can't be implicitly built from a dynamic range
  //	(P1976R2).
  EXPECT_FALSE((std::is_convertible_v<std::vector<int>&, std::span<int, 2>>));
  EXPECT_TRUE((std::is_constructible_v<std::span<int, 2>, std::vector<int>&>));
#endif
}

LBAL_FP_TEST(LIBCPP20, SPAN_USABILITY) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_SPAN_USABILITY);
#if LBAL_LIBCPP20_SPAN_USABILITY
  //	Deduction guides and construction from containers (P1024R3).
  std::vector<int> v{1, 2, 3};
  std::span s = v;

  EXPECT_TRUE((std::is_same_v<decltype(s), std::span<int>>));
  EXPECT_EQ(s.front(), 1);
  EXPECT_EQ(s.back(), 3);
#endif
}

LBAL_FP_TEST(LIBCPP20, SSIZE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_SSIZE);
#if LBAL_LIBCPP20_SSIZE
  std::vector<int> v{1, 2, 3};

  EXPECT_EQ(std::ssize(v), 3);
  EXPECT_TRUE(std::is_signed_v<decltype(std::ssize(v))>);
#endif
}

LBAL_FP_TEST(LIBCPP20, STARTS_ENDS_WITH) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_STARTS_ENDS_WITH);
#if LBAL_LIBCPP20_STARTS_ENDS_WITH
  std::string s = "hello";

  EXPECT_TRUE(s.starts_with("he"));
  EXPECT_TRUE(s.ends_with('o'));
  EXPECT_FALSE(std::string_view(s).starts_with("lo"));
#endif
}

LBAL_FP_TEST(LIBCPP20, SYNCBUF) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_SYNCBUF);
#if LBAL_LIBCPP20_SYNCBUF
  std::ostringstream out;

  {
    std::osyncstream sync(out);
    sync << "abc";
    EXPECT_EQ(out.str(), "");
  }  //	Emitted when the stream is destroyed.

  EXPECT_EQ(out.str(), "abc");
#endif
}

LBAL_FP_TEST(LIBCPP20, SYNCBUF_MANIPULATORS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_SYNCBUF_MANIPULATORS);
#if LBAL_LIBCPP20_SYNCBUF_MANIPULATORS
  std::ostringstream out;
  std::osyncstream sync(out);

  sync << "a" << std::emit_on_flush << std::flush;
  EXPECT_EQ(out.str(), "a");
  sync << std::noemit_on_flush << std::flush_emit;
#endif
}

LBAL_FP_TEST(LIBCPP20, THREE_WAY_COMPARISON) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_THREE_WAY_COMPARISON);
#if LBAL_LIBCPP20_THREE_WAY_COMPARISON
  EXPECT_TRUE((1 <=> 2) == std::strong_ordering::less);
  EXPECT_TRUE(std::is_lt(1 <=> 2));
  EXPECT_TRUE((
      std::is_same_v<std::compare_three_way_result_t<int>, std::strong_ordering>
  ));
#endif
}

LBAL_FP_TEST(LIBCPP20, THREE_WAY_COMPARISON_LIBRARY) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY);
#if LBAL_LIBCPP20_THREE_WAY_COMPARISON_LIBRARY
  //	Library types support `<=>` (P1614R2).
  EXPECT_TRUE(std::is_lt(std::string("a") <=> std::string("b")));
  EXPECT_TRUE(std::is_gt(std::vector<int>{2} <=> std::vector<int>{1}));
  EXPECT_TRUE(std::is_eq(std::pair{1, 2} <=> std::pair{1, 2}));
#endif
}

LBAL_FP_TEST(LIBCPP20, TO_ADDRESS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_TO_ADDRESS);
#if LBAL_LIBCPP20_TO_ADDRESS
  auto p = std::make_unique<int>(1);
  std::vector<int> v{1};

  EXPECT_EQ(std::to_address(p.get()), p.get());
  EXPECT_EQ(std::to_address(v.begin()), v.data());
#endif
}

LBAL_FP_TEST(LIBCPP20, TO_ARRAY) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_TO_ARRAY);
#if LBAL_LIBCPP20_TO_ARRAY
  auto a = std::to_array({1, 2, 3});
  auto chars = std::to_array("ab");

  EXPECT_TRUE((std::is_same_v<decltype(a), std::array<int, 3>>));
  EXPECT_EQ(chars.size(), 3u);
#endif
}

LBAL_FP_TEST(LIBCPP20, TYPE_IDENTITY) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_TYPE_IDENTITY);
#if LBAL_LIBCPP20_TYPE_IDENTITY
  EXPECT_TRUE((std::is_same_v<std::type_identity_t<int>, int>));
#endif
}

LBAL_FP_TEST(LIBCPP20, UNWRAP_REF) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_UNWRAP_REF);
#if LBAL_LIBCPP20_UNWRAP_REF
  EXPECT_TRUE((
      std::is_same_v<std::unwrap_reference_t<std::reference_wrapper<int>>, int&>
  ));
  EXPECT_TRUE((std::is_same_v<
      std::unwrap_ref_decay_t<const std::reference_wrapper<int>&>,
      int&
  >));
#endif
}

LBAL_FP_TEST(LIBCPP20, VERSION) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP20_VERSION);
#if LBAL_LIBCPP20_VERSION
  //	`<version>` exists and defines the library feature-test macros.
  #if defined(__cpp_lib_optional)
  EXPECT_GE(__cpp_lib_optional, 201606L);
  #else
  ADD_FAILURE() << "<version> doesn’t define __cpp_lib_optional";
  #endif
#endif
}
