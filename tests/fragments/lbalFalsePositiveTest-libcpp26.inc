/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFalsePositiveTest-libcpp26.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Soft false-positive probes for `LBAL_LIBCPP26_*` tokens. Tokens that are only
  about `constexpr` or `consteval` support have hard probes in
  `probes/libcpp26/`.

  Most of these features aren’t implemented by any library available when
  they were written. Probes marked SEEME were written from the paper and
  haven’t yet been run against a library that reports the feature; a failure
  there may be a mistake in the probe rather than a false positive.

  The `HARDENED_*` probes are death tests: a hardened implementation must stop
  the program when a precondition is violated.

  The `FREESTANDING_*` tokens say a facility is available in a freestanding
  implementation; in a hosted build, their probes only check that the facility
  is usable.

------------------------------------------------------------------------------*/

//	std
#include <algorithm>
#include <array>
#include <atomic>
#include <bitset>
#include <cerrno>
#include <charconv>
#include <chrono>
#include <climits>
#include <complex>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cwchar>
#include <deque>
#include <exception>
#include <forward_list>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <random>
#include <ratio>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <variant>
#include <vector>

#if LBAL_LIBCPP26_CONSTRAINED_EQUALITY                                         \
    || LBAL_LIBCPP26_CONSTRAINED_EQUALITY_EXPECTED
  #include <concepts>
#endif

#if LBAL_LIBCPP26_CONSTRAINED_EQUALITY_EXPECTED                                \
    || LBAL_LIBCPP26_FREESTANDING_EXPECTED                                     \
    || LBAL_LIBCPP26_HARDENED_EXPECTED
  #include <expected>
#endif

#if LBAL_LIBCPP26_ALIGNED_ACCESSOR                                             \
    || LBAL_LIBCPP26_FREESTANDING_MDSPAN                                       \
    || LBAL_LIBCPP26_HARDENED_MDSPAN                                           \
    || LBAL_LIBCPP26_LINALG                                                    \
    || LBAL_LIBCPP26_LINALG_BLAS_RANK                                          \
    || LBAL_LIBCPP26_LINALG_FIX_TRANSPOSED                                     \
    || LBAL_LIBCPP26_LINALG_OPTIMIZE_CONJUGATED                                \
    || LBAL_LIBCPP26_MDSPAN_DEXTENTS                                           \
    || LBAL_LIBCPP26_SUBMDSPAN                                                 \
    || LBAL_LIBCPP26_SUBMDSPAN_FIX                                             \
    || LBAL_LIBCPP26_SUBMDSPAN_FUTURE_PROOF                                    \
    || LBAL_LIBCPP26_SUBMDSPAN_PADDED                                          \
    || LBAL_LIBCPP26_SUBMDSPAN_UPDATE
  #include <mdspan>
#endif

#if LBAL_LIBCPP26_LINALG                                                       \
    || LBAL_LIBCPP26_LINALG_BLAS_RANK                                          \
    || LBAL_LIBCPP26_LINALG_FIX_TRANSPOSED                                     \
    || LBAL_LIBCPP26_LINALG_OPTIMIZE_CONJUGATED
  #include <linalg>
#endif

#if LBAL_LIBCPP26_COUNTING_SCOPE                                               \
    || LBAL_LIBCPP26_PARALLEL_SCHEDULER                                        \
    || LBAL_LIBCPP26_SENDERS                                                   \
    || LBAL_LIBCPP26_SENDERS_OPTIONAL                                          \
    || LBAL_LIBCPP26_TASK                                                      \
    || LBAL_LIBCPP26_PARALLEL_ALGORITHM_RANGE                                  \
    || LBAL_LIBCPP26_FREESTANDING_EXECUTION
  #include <execution>
#endif

#if LBAL_LIBCPP26_DEBUGGING || LBAL_LIBCPP26_DEBUGGING_UTILITIES
  #include <debugging>
#endif

#if LBAL_LIBCPP26_FLAT_MAP_FIXES
  #include <flat_map>
#endif

#if LBAL_LIBCPP26_FLAT_SET_FIXES
  #include <flat_set>
#endif

#if LBAL_LIBCPP26_FORMAT_MEMBER_VISIT                                          \
    || LBAL_LIBCPP26_FORMAT_PATH                                               \
    || LBAL_LIBCPP26_FORMAT_PATH_FIXES                                         \
    || LBAL_LIBCPP26_FORMAT_POINTERS                                           \
    || LBAL_LIBCPP26_FORMAT_RUNTIME                                            \
    || LBAL_LIBCPP26_FORMAT_RUNTIME_RENAMING                                   \
    || LBAL_LIBCPP26_FORMAT_TYPE_CHECK                                         \
    || LBAL_LIBCPP26_FORMAT_UCHAR
  #include <format>
#endif

#if LBAL_LIBCPP26_FORMAT_PATH                                                  \
    || LBAL_LIBCPP26_FORMAT_PATH_FIXES                                         \
    || LBAL_LIBCPP26_FSTREAM_NATIVE_HANDLE
  #include <filesystem>
  #include <fstream>
#endif

#if LBAL_LIBCPP26_FUNCTION_REF                                                 \
    || LBAL_LIBCPP26_FUNCTION_REF_LESS_DOUBLE_INDIRECTION                      \
    || LBAL_LIBCPP26_FUNCTION_REF_RENAME_NONTYPE
  #include <functional>
#endif

#if LBAL_LIBCPP26_HAZARD_POINTER
  #include <hazard_pointer>
#endif

#if LBAL_LIBCPP26_HIVE
  #include <hive>
#endif

#if LBAL_LIBCPP26_INPLACE_VECTOR                                               \
    || LBAL_LIBCPP26_HARDENED_INPLACE_VECTOR                                   \
    || LBAL_LIBCPP26_INPLACE_VECTOR_BETTER_RETURN_TYPES                        \
    || LBAL_LIBCPP26_INPLACE_VECTOR_REMOVE_TRY_APPEND_RANGE
  #include <inplace_vector>
#endif

#if LBAL_LIBCPP26_PRINT_EFFICIENT || LBAL_LIBCPP26_PRINT_MORE_EFFICIENT
  #include <print>
#endif

#if LBAL_LIBCPP26_RANGES_AS_CONST_FIX_CONVERTIBILITY                           \
    || LBAL_LIBCPP26_RANGES_AS_INPUT                                           \
    || LBAL_LIBCPP26_RANGES_AS_INPUT_RENAME                                    \
    || LBAL_LIBCPP26_RANGES_CACHE_LATEST                                       \
    || LBAL_LIBCPP26_RANGES_CONCAT                                             \
    || LBAL_LIBCPP26_RANGES_FILTER                                             \
    || LBAL_LIBCPP26_RANGES_GENERATE_RANDOM                                    \
    || LBAL_LIBCPP26_RANGES_INDICES                                            \
    || LBAL_LIBCPP26_RANGES_REMOVE_COMMON_REF_REQ                              \
    || LBAL_LIBCPP26_RANGES_RESERVE_HINT                                       \
    || LBAL_LIBCPP26_OPTIONAL_RANGE_SUPPORT                                    \
    || LBAL_LIBCPP26_HARDENED_COMMON_ITERATOR                                  \
    || LBAL_LIBCPP26_HARDENED_COUNTED_ITERATOR                                 \
    || LBAL_LIBCPP26_HARDENED_VIEW_INTERFACE                                   \
    || LBAL_LIBCPP26_FREESTANDING_RANGES
  #include <ranges>
#endif

#if LBAL_LIBCPP26_RCU
  #include <rcu>
#endif

#if LBAL_LIBCPP26_REPLACEABLE_CONTRACT_VIOLATION_HANDLER
  #include <contracts>
#endif

#if LBAL_LIBCPP26_SIMD                                                         \
    || LBAL_LIBCPP26_SIMD_BIT                                                  \
    || LBAL_LIBCPP26_SIMD_CHUNK                                                \
    || LBAL_LIBCPP26_SIMD_COMPLEX                                              \
    || LBAL_LIBCPP26_SIMD_DEDUCTION_GUIDES                                     \
    || LBAL_LIBCPP26_SIMD_EXTEND                                               \
    || LBAL_LIBCPP26_SIMD_NAMESPACES                                           \
    || LBAL_LIBCPP26_SIMD_PERMUTATIONS                                         \
    || LBAL_LIBCPP26_SIMD_RANGE
  #include <bit>
  #include <simd>
#endif

#if LBAL_LIBCPP26_SATURATION_ARITHMETIC                                        \
    || LBAL_LIBCPP26_SATURATION_ARITHMETIC_RENAMING
  #include <numeric>
#endif

#if LBAL_LIBCPP26_SPAN_AT                                                      \
    || LBAL_LIBCPP26_SPAN_MORE                                                 \
    || LBAL_LIBCPP26_HARDENED_SPAN                                             \
    || LBAL_LIBCPP26_ALIGNED_ACCESSOR
  #include <span>
#endif

#if LBAL_LIBCPP26_SSTREAM_FROM_STRING_VIEW
  #include <sstream>
#endif

#if LBAL_LIBCPP26_STDBIT_H
  #include <stdbit.h>
#endif

#if LBAL_LIBCPP26_STDCKDINT_H
  #include <stdckdint.h>
#endif

#if LBAL_LIBCPP26_HARDENED_BASIC_STACKTRACE
  #include <stacktrace>
#endif

#if LBAL_LIBCPP26_TEXT_ENCODING
  #include <text_encoding>
#endif

#if LBAL_LIBCPP26_TYPE_ORDER                                                   \
    || LBAL_LIBCPP26_CONSTANT_WRAPPER                                          \
    || LBAL_LIBCPP26_CONSTANT_WRAPPER_UNWRAP_ON_CALL
  #include <compare>
  #include <type_traits>
  #include <utility>
#endif

namespace lbal_fp_libcpp26 {

struct NotComparable { };

//	An index that the optimizer can’t prove is out of range, so a hardened
//	precondition check can’t be elided.
inline std::size_t
out_of_range_index() {
  static volatile std::size_t index = 10;
  return index;
}

#if GTEST_HAS_DEATH_TEST
//	The statement is compiled in a lambda at the call site and run here, so a
//	diagnostic in it isn’t followed by a chain of notes through gtest’s
//	death-test macros. `LBAL_FP_EXPECT_HARDENED` adds a trace that points at
//	the call site, since a failure is reported against this line.
template <typename F>
void
expect_hardened(F statement) {
  EXPECT_DEATH(statement(), "");
}
#endif

}  // namespace lbal_fp_libcpp26

//	The statement is variadic, since it may contain commas that aren’t inside
//	parentheses (e.g. `m[std::array{i, j}]`). Without death tests, it’s still
//	compiled and uses the probe’s variables, so the probe builds the same way
//	either way.
#if GTEST_HAS_DEATH_TEST
  #define LBAL_FP_EXPECT_HARDENED(...)                                         \
    do {                                                                       \
      SCOPED_TRACE(#__VA_ARGS__);                                              \
      ::lbal_fp_libcpp26::expect_hardened([&] {                                \
        __VA_ARGS__;                                                           \
      });                                                                      \
    } while (false)
#else
  #define LBAL_FP_EXPECT_HARDENED(...)                                         \
    do {                                                                       \
      (void)[&] {                                                              \
        __VA_ARGS__;                                                           \
      };                                                                       \
      GTEST_SKIP() << "Death tests aren’t available";                          \
    } while (false)
#endif

LBAL_FP_TEST(LIBCPP26, ALGORITHM_DEFAULT_VALUE_TYPE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_ALGORITHM_DEFAULT_VALUE_TYPE);
#if LBAL_LIBCPP26_ALGORITHM_DEFAULT_VALUE_TYPE
  //	The value parameter defaults to the value type, so a braced list works
  //	(P2248R8); P3217R0, which this token reports, extends that to
  //	`ranges::find_last`.
  std::vector<std::pair<int, int>> v{{1, 2}, {3, 4}};

  EXPECT_EQ(std::find(v.begin(), v.end(), {3, 4}) - v.begin(), 1);
  EXPECT_EQ(std::ranges::count(v, {1, 2}), 1);
  EXPECT_EQ(std::ranges::find_last(v, {3, 4}).begin() - v.begin(), 1);
#endif
}

LBAL_FP_TEST(LIBCPP26, ALIGNED_ACCESSOR) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_ALIGNED_ACCESSOR);
#if LBAL_LIBCPP26_ALIGNED_ACCESSOR
  alignas(64) float data[4] = {1.0f, 2.0f, 3.0f, 4.0f};
  std::mdspan<
      float,
      std::dextents<std::size_t, 1>,
      std::layout_right,
      std::aligned_accessor<float, 64>
  >
      m(data, 4);

  EXPECT_EQ(m[std::array{std::size_t{3}}], 4.0f);
#endif
}

LBAL_FP_TEST(LIBCPP26, APPLY_RESULT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_APPLY_RESULT);
#if LBAL_LIBCPP26_APPLY_RESULT
  //	SEEME
  using Plus = std::plus<>;

  EXPECT_TRUE((
      std::is_same_v<std::apply_result_t<Plus, std::tuple<int, int>>, int>
  ));
  EXPECT_TRUE((std::is_applicable_v<Plus, std::tuple<int, int>>));
  EXPECT_FALSE((std::is_applicable_v<Plus, std::tuple<int>>));
#endif
}

LBAL_FP_TEST(LIBCPP26, ASSOCIATIVE_HETEROGENEOUS_INSERTION) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_ASSOCIATIVE_HETEROGENEOUS_INSERTION);
#if LBAL_LIBCPP26_ASSOCIATIVE_HETEROGENEOUS_INSERTION
  //	SEEME
  std::map<std::string, int, std::less<>> m;
  std::string_view key = "a";

  m.try_emplace(key, 1);
  m.insert_or_assign(key, 2);
  m[key] += 1;

  EXPECT_EQ(m.at(key), 3);
#endif
}

LBAL_FP_TEST(LIBCPP26, ATOMIC_MIN_MAX) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_ATOMIC_MIN_MAX);
#if LBAL_LIBCPP26_ATOMIC_MIN_MAX
  //	SEEME
  std::atomic<int> a{5};

  EXPECT_EQ(a.fetch_max(9), 5);
  EXPECT_EQ(a.fetch_min(2), 9);
  EXPECT_EQ(a.load(), 2);
#endif
}

LBAL_FP_TEST(LIBCPP26, ATOMIC_MIN_MAX_FLOAT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_ATOMIC_MIN_MAX_FLOAT);
#if LBAL_LIBCPP26_ATOMIC_MIN_MAX_FLOAT
  //	SEEME
  std::atomic<double> a{1.5};

  EXPECT_EQ(a.fetch_max(2.5), 1.5);
  EXPECT_EQ(a.load(), 2.5);
#endif
}

LBAL_FP_TEST(LIBCPP26, ATOMIC_REDUCTIONS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_ATOMIC_REDUCTIONS);
#if LBAL_LIBCPP26_ATOMIC_REDUCTIONS
  //	SEEME
  //	Reductions return nothing, so they can be cheaper than fetch operations
  //	(P3111R8).
  std::atomic<int> a{1};

  a.store_add(2);
  a.store_max(10);
  EXPECT_EQ(a.load(), 10);
#endif
}

LBAL_FP_TEST(LIBCPP26, ATOMIC_REF_ADDRESS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_ATOMIC_REF_ADDRESS);
#if LBAL_LIBCPP26_ATOMIC_REF_ADDRESS
  int value = 0;
  std::atomic_ref<int> ref(value);

  EXPECT_EQ(
      static_cast<const void*>(ref.address()), static_cast<const void*>(&value)
  );
#endif
}

#if LBAL_LIBCPP26_ATOMIC_REF_SAFER_ADDRESS
namespace lbal_fp_libcpp26 {

LBAL_FP_DETECT(
    has_void_address,
    T,
    std::enable_if_t<
        std::is_same_v<decltype(std::declval<const T&>().address()), void*>
    >()
)

}  // namespace lbal_fp_libcpp26
#endif

LBAL_FP_TEST(LIBCPP26, ATOMIC_REF_SAFER_ADDRESS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_ATOMIC_REF_SAFER_ADDRESS);
#if LBAL_LIBCPP26_ATOMIC_REF_SAFER_ADDRESS
  //	P2835R7’s `address()` returns `T*`; P3936R1 makes it return `cv void*`.
  //	Checked against libc++ 23 with Clang 23 (C++26).
  EXPECT_TRUE(lbal_fp_libcpp26::has_void_address<std::atomic_ref<int>>::value);
#endif
}

LBAL_FP_TEST(LIBCPP26, BIND_BACK_NTTP_CALLABLES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_BIND_BACK_NTTP_CALLABLES);
#if LBAL_LIBCPP26_BIND_BACK_NTTP_CALLABLES
  //	SEEME
  //	The `bind_back` part of P2714R1; the bound argument goes last.
  auto minus_ten = std::bind_back<std::minus<>{}>(10);

  EXPECT_EQ(minus_ten(3), -7);
#endif
}

LBAL_FP_TEST(LIBCPP26, BIND_FRONT_NTTP_CALLABLES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_BIND_FRONT_NTTP_CALLABLES);
#if LBAL_LIBCPP26_BIND_FRONT_NTTP_CALLABLES
  //	The token follows `__cpp_lib_bind_front`, so only `bind_front` is checked.
  //	P2714R1's `bind_back` and `not_fn` parts have their own tokens; libc++ 23,
  //	for one, has the `bind_front` and `not_fn` overloads but not `bind_back`.
  auto from_ten = std::bind_front<std::minus<>{}>(10);

  EXPECT_EQ(from_ten(3), 7);
#endif
}

LBAL_FP_TEST(LIBCPP26, BITSET) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_BITSET);
#if LBAL_LIBCPP26_BITSET
  std::bitset<4> b(std::string_view("1010"));

  EXPECT_EQ(b.to_ulong(), 10u);
#endif
}

LBAL_FP_TEST(LIBCPP26, CHRONO_HASHING) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_CHRONO_HASHING);
#if LBAL_LIBCPP26_CHRONO_HASHING
  using namespace std::chrono;

  std::unordered_set<seconds> s{seconds(1), seconds(1), seconds(2)};
  EXPECT_EQ(s.size(), 2u);
  EXPECT_EQ(std::hash<year>{}(year{2024}), std::hash<year>{}(year{2024}));
#endif
}

LBAL_FP_TEST(LIBCPP26, CONSTANT_WRAPPER) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_CONSTANT_WRAPPER);
#if LBAL_LIBCPP26_CONSTANT_WRAPPER
  auto sum = std::cw<2> + std::cw<3>;

  EXPECT_EQ(decltype(sum)::value, 5);
  EXPECT_EQ(std::cw<4>.value, 4);
#endif
}

#if LBAL_LIBCPP26_CONSTANT_WRAPPER_UNWRAP_ON_CALL
namespace lbal_fp_libcpp26 {

constexpr int
add_one(int x) {
  return x + 1;
}

}  // namespace lbal_fp_libcpp26
#endif

LBAL_FP_TEST(LIBCPP26, CONSTANT_WRAPPER_UNWRAP_ON_CALL) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_CONSTANT_WRAPPER_UNWRAP_ON_CALL);
#if LBAL_LIBCPP26_CONSTANT_WRAPPER_UNWRAP_ON_CALL
  //	Calling a wrapped callable with runtime arguments calls it (P3978R3).
  int x = 1;

  EXPECT_EQ(std::cw<lbal_fp_libcpp26::add_one>(x), 2);
#endif
}

LBAL_FP_TEST(LIBCPP26, CONSTRAINED_EQUALITY) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_CONSTRAINED_EQUALITY);
#if LBAL_LIBCPP26_CONSTRAINED_EQUALITY
  //	`==` is only available when the elements support it (P2944R3).
  using lbal_fp_libcpp26::NotComparable;

  EXPECT_FALSE((std::equality_comparable<std::pair<NotComparable, int>>));
  EXPECT_FALSE((std::equality_comparable<std::tuple<NotComparable>>));
  EXPECT_FALSE((std::equality_comparable<std::optional<NotComparable>>));
  EXPECT_TRUE((std::equality_comparable<std::pair<int, int>>));
#endif
}

LBAL_FP_TEST(LIBCPP26, CONSTRAINED_EQUALITY_EXPECTED) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_CONSTRAINED_EQUALITY_EXPECTED);
#if LBAL_LIBCPP26_CONSTRAINED_EQUALITY_EXPECTED
  using lbal_fp_libcpp26::NotComparable;

  EXPECT_FALSE((std::equality_comparable<std::expected<NotComparable, int>>));
  EXPECT_TRUE((std::equality_comparable<std::expected<int, int>>));
#endif
}

LBAL_FP_TEST(LIBCPP26, COPYABLE_FUNCTION) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_COPYABLE_FUNCTION);
#if LBAL_LIBCPP26_COPYABLE_FUNCTION
  //	SEEME
  std::copyable_function<int(int)> f = [](int x) {
    return x * 2;
  };
  auto g = f;

  EXPECT_EQ(g(3), 6);
#endif
}

LBAL_FP_TEST(LIBCPP26, COUNTING_SCOPE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_COUNTING_SCOPE);
#if LBAL_LIBCPP26_COUNTING_SCOPE
  //	SEEME
  std::execution::counting_scope scope;
  int ran = 0;

  std::execution::spawn(
      std::execution::just() | std::execution::then([&] {
        ++ran;
      }),
      scope.get_token()
  );
  std::this_thread::sync_wait(scope.join());

  EXPECT_EQ(ran, 1);
#endif
}

LBAL_FP_TEST(LIBCPP26, DEBUGGING) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_DEBUGGING);
#if LBAL_LIBCPP26_DEBUGGING
  //	SEEME
  //	Only checks that these are callable; whether a debugger is attached
  //	depends on how the test is run.
  (void)std::is_debugger_present();
  std::breakpoint_if_debugging();
  SUCCEED();
#endif
}

LBAL_FP_TEST(LIBCPP26, DEBUGGING_UTILITIES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_DEBUGGING_UTILITIES);
#if LBAL_LIBCPP26_DEBUGGING_UTILITIES
  //	SEEME
  //	P2810R4 makes `is_debugger_present` replaceable, which can’t be
  //	exercised without replacing it for the whole test program.
  EXPECT_TRUE((std::is_same_v<decltype(std::is_debugger_present()), bool>));
#endif
}

LBAL_FP_TEST(LIBCPP26, EXCEPTION_PTR_CAST) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_EXCEPTION_PTR_CAST);
#if LBAL_LIBCPP26_EXCEPTION_PTR_CAST && LBAL_CPP03_EXCEPTIONS
  //	SEEME
  auto p = std::make_exception_ptr(std::runtime_error("x"));

  EXPECT_NE(std::exception_ptr_cast<std::runtime_error>(p), nullptr);
  EXPECT_NE(std::exception_ptr_cast<std::exception>(p), nullptr);
  EXPECT_EQ(std::exception_ptr_cast<std::logic_error>(p), nullptr);
#endif
}

LBAL_FP_TEST(LIBCPP26, EXCEPTION_PTR_CAST_BETTER_RETURN_TYPES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_EXCEPTION_PTR_CAST_BETTER_RETURN_TYPES);
#if LBAL_LIBCPP26_EXCEPTION_PTR_CAST_BETTER_RETURN_TYPES                       \
    && LBAL_CPP03_EXCEPTIONS
  //	SEEME
  //	Smoke test; it doesn’t isolate the P3981R2 changes.
  auto p = std::make_exception_ptr(std::runtime_error("x"));

  EXPECT_TRUE(
      static_cast<bool>(std::exception_ptr_cast<std::runtime_error>(p))
  );
#endif
}

LBAL_FP_TEST(LIBCPP26, FLAT_MAP_FIXES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FLAT_MAP_FIXES);
#if LBAL_LIBCPP26_FLAT_MAP_FIXES
  //	LBAL_FP_SMOKE: it doesn’t isolate the paper’s changes, so it can’t detect
  //	a false negative.
  //	SEEME
  //	Smoke test; it doesn’t isolate the P3567R2 changes.
  std::flat_map<int, int> m{{2, 20}, {1, 10}};

  EXPECT_EQ(m.begin()->second, 10);
#endif
}

LBAL_FP_TEST(LIBCPP26, FLAT_SET_FIXES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FLAT_SET_FIXES);
#if LBAL_LIBCPP26_FLAT_SET_FIXES
  //	LBAL_FP_SMOKE: it doesn’t isolate the paper’s changes, so it can’t detect
  //	a false negative.
  //	SEEME
  //	Smoke test; it doesn’t isolate the P3567R2 changes.
  std::flat_set<int> s{2, 1, 2};

  EXPECT_EQ(s.size(), 2u);
#endif
}

LBAL_FP_TEST(LIBCPP26, FORMAT_MEMBER_VISIT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FORMAT_MEMBER_VISIT);
#if LBAL_LIBCPP26_FORMAT_MEMBER_VISIT
  int value = 42;
  auto store = std::make_format_args(value);
  std::format_args args = store;

  int seen = args.get(0).visit([](auto v) {
    if constexpr (std::is_same_v<decltype(v), int>) {
      return v;
    } else {
      return -1;
    }
  });
  EXPECT_EQ(seen, 42);
#endif
}

LBAL_FP_TEST(LIBCPP26, FORMAT_PATH) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FORMAT_PATH);
#if LBAL_LIBCPP26_FORMAT_PATH
  //	SEEME
  EXPECT_EQ(std::format("{}", std::filesystem::path("a")), "a");
#endif
}

LBAL_FP_TEST(LIBCPP26, FORMAT_PATH_FIXES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FORMAT_PATH_FIXES);
#if LBAL_LIBCPP26_FORMAT_PATH_FIXES
  //	SEEME
  //	The `g` option formats the generic form (P2319R5).
  EXPECT_EQ(std::format("{:g}", std::filesystem::path("a/b")), "a/b");
#endif
}

LBAL_FP_TEST(LIBCPP26, FORMAT_POINTERS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FORMAT_POINTERS);
#if LBAL_LIBCPP26_FORMAT_POINTERS
  //	Uppercase and zero-padded pointers (P2510R3).
  const void* p = reinterpret_cast<const void*>(std::uintptr_t{0xAB});

  EXPECT_EQ(std::format("{:P}", p), "0XAB");
  EXPECT_EQ(std::format("{:06}", p), "0x00ab");
#endif
}

LBAL_FP_TEST(LIBCPP26, FORMAT_RUNTIME) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FORMAT_RUNTIME);
#if LBAL_LIBCPP26_FORMAT_RUNTIME
  //	P3953R3 renamed `runtime_format`, so a library that reports it only has
  //	the new name (libc++ 23, for one).
  std::string fmt = "{}+{}";

  #if LBAL_LIBCPP26_FORMAT_RUNTIME_RENAMING
  EXPECT_EQ(std::format(std::dynamic_format(fmt), 1, 2), "1+2");
  #else
  EXPECT_EQ(std::format(std::runtime_format(fmt), 1, 2), "1+2");
  #endif
#endif
}

LBAL_FP_TEST(LIBCPP26, FORMAT_RUNTIME_RENAMING) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FORMAT_RUNTIME_RENAMING);
#if LBAL_LIBCPP26_FORMAT_RUNTIME_RENAMING
  //	P3953R3 renamed `std::runtime_format` to `std::dynamic_format`.
  //	Checked against libc++ 23 with Clang 23 (C++26).
  std::string fmt = "{}+{}";

  EXPECT_EQ(std::format(std::dynamic_format(fmt), 1, 2), "1+2");
#endif
}

#if LBAL_LIBCPP26_FORMAT_TYPE_CHECK
namespace lbal_fp_libcpp26 {

LBAL_FP_DETECT(
    has_check_dynamic_spec,
    T,
    std::declval<T&>().template check_dynamic_spec<int>(std::size_t{0})
)

}  // namespace lbal_fp_libcpp26
#endif

LBAL_FP_TEST(LIBCPP26, FORMAT_TYPE_CHECK) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FORMAT_TYPE_CHECK);
#if LBAL_LIBCPP26_FORMAT_TYPE_CHECK
  //	`basic_format_parse_context` can check dynamic arguments (P2757R3).
  EXPECT_TRUE(
      lbal_fp_libcpp26::has_check_dynamic_spec<std::format_parse_context>::value
  );
  EXPECT_EQ(std::format("{:{}}", 1, 3), "  1");
#endif
}

LBAL_FP_TEST(LIBCPP26, FORMAT_UCHAR) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FORMAT_UCHAR);
#if LBAL_LIBCPP26_FORMAT_UCHAR
  //	Code units formatted as integers are treated as unsigned (P2909R4).
  EXPECT_EQ(std::format("{:x}", static_cast<char>(-1)), "ff");
  EXPECT_EQ(std::format("{:d}", 'a'), "97");
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_ALGORITHM) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_ALGORITHM);
#if LBAL_LIBCPP26_FREESTANDING_ALGORITHM
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  int a[] = {3, 1, 2};

  std::sort(std::begin(a), std::end(a));
  EXPECT_EQ(a[0], 1);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_ALGORITHM_MORE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_ALGORITHM_MORE);
#if LBAL_LIBCPP26_FREESTANDING_ALGORITHM_MORE
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  //	SEEME
  int a[] = {1, 2, 3};

  EXPECT_EQ(std::ranges::fold_left(a, 0, std::plus<>{}), 6);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_ARRAY) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_ARRAY);
#if LBAL_LIBCPP26_FREESTANDING_ARRAY
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  std::array<int, 2> a{1, 2};

  EXPECT_EQ(a.back(), 2);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_CHARCONV) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_CHARCONV);
#if LBAL_LIBCPP26_FREESTANDING_CHARCONV
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  //	SEEME
  char buffer[4] = {};

  EXPECT_EQ(*std::to_chars(buffer, buffer + 4, 7).ptr, '\0');
  EXPECT_EQ(buffer[0], '7');
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_CHAR_TRAITS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_CHAR_TRAITS);
#if LBAL_LIBCPP26_FREESTANDING_CHAR_TRAITS
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  //	SEEME
  EXPECT_EQ(std::char_traits<char>::length("abc"), 3u);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_CSTDLIB) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_CSTDLIB);
#if LBAL_LIBCPP26_FREESTANDING_CSTDLIB
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  //	SEEME
  EXPECT_EQ(std::abs(-2), 2);
  EXPECT_EQ(std::div(7, 2).rem, 1);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_CSTRING) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_CSTRING);
#if LBAL_LIBCPP26_FREESTANDING_CSTRING
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  EXPECT_EQ(std::strlen("abc"), 3u);
  EXPECT_EQ(std::memcmp("ab", "ab", 2), 0);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_CSTRING_REMOVE_STRTOK) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_CSTRING_REMOVE_STRTOK);
#if LBAL_LIBCPP26_FREESTANDING_CSTRING_REMOVE_STRTOK
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  //	`strtok` is no longer required in freestanding (P2937R0); in a hosted
  //	build the rest of `<cstring>` is still there.
  EXPECT_NE(std::strchr("abc", 'b'), nullptr);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_CWCHAR) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_CWCHAR);
#if LBAL_LIBCPP26_FREESTANDING_CWCHAR
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  //	SEEME
  EXPECT_EQ(std::wcslen(L"ab"), 2u);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_ERRC) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_ERRC);
#if LBAL_LIBCPP26_FREESTANDING_ERRC
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  //	SEEME
  EXPECT_EQ(static_cast<int>(std::errc::invalid_argument), EINVAL);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_EXECUTION) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_EXECUTION);
#if LBAL_LIBCPP26_FREESTANDING_EXECUTION
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  //	SEEME
  EXPECT_TRUE(std::is_execution_policy_v<std::execution::sequenced_policy>);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_EXPECTED) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_EXPECTED);
#if LBAL_LIBCPP26_FREESTANDING_EXPECTED
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  std::expected<int, int> e = 1;

  EXPECT_EQ(*e, 1);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_FEATURE_TEST_MACROS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_FEATURE_TEST_MACROS);
#if LBAL_LIBCPP26_FREESTANDING_FEATURE_TEST_MACROS
  //	SEEME
  #if defined(__cpp_lib_freestanding_feature_test_macros)
  SUCCEED();
  #else
  ADD_FAILURE() << "__cpp_lib_freestanding_feature_test_macros isn’t defined";
  #endif
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_FUNCTIONAL) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_FUNCTIONAL);
#if LBAL_LIBCPP26_FREESTANDING_FUNCTIONAL
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  //	SEEME
  EXPECT_EQ(std::invoke(std::plus<>{}, 1, 2), 3);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_ITERATOR) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_ITERATOR);
#if LBAL_LIBCPP26_FREESTANDING_ITERATOR
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  //	SEEME
  int a[] = {1, 2};

  EXPECT_EQ(std::distance(std::begin(a), std::end(a)), 2);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_MDSPAN) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_MDSPAN);
#if LBAL_LIBCPP26_FREESTANDING_MDSPAN
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  //	SEEME
  int data[4] = {};
  std::mdspan m(data, 2, 2);

  EXPECT_EQ(m.size(), 4u);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_MEMORY) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_MEMORY);
#if LBAL_LIBCPP26_FREESTANDING_MEMORY
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  //	SEEME
  int x = 0;

  EXPECT_EQ(std::addressof(x), &x);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_MEMORY_MORE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_MEMORY_MORE);
#if LBAL_LIBCPP26_FREESTANDING_MEMORY_MORE
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  //	SEEME
  alignas(int) unsigned char storage[sizeof(int)];
  int* p = std::construct_at(reinterpret_cast<int*>(storage), 3);

  EXPECT_EQ(*p, 3);
  std::destroy_at(p);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_NUMERIC) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_NUMERIC);
#if LBAL_LIBCPP26_FREESTANDING_NUMERIC
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  //	SEEME
  int a[] = {1, 2, 3};

  EXPECT_EQ(std::accumulate(std::begin(a), std::end(a), 0), 6);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_OPERATOR_NEW) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_OPERATOR_NEW);
#if LBAL_LIBCPP26_FREESTANDING_OPERATOR_NEW
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  //	SEEME
  auto p = std::make_unique<int>(1);

  EXPECT_EQ(*p, 1);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_OPTIONAL) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_OPTIONAL);
#if LBAL_LIBCPP26_FREESTANDING_OPTIONAL
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  std::optional<int> o = 1;

  EXPECT_EQ(*o, 1);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_RANDOM) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_RANDOM);
#if LBAL_LIBCPP26_FREESTANDING_RANDOM
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  //	SEEME
  std::minstd_rand engine;

  EXPECT_EQ(engine(), 48271u);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_RANGES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_RANGES);
#if LBAL_LIBCPP26_FREESTANDING_RANGES
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  //	SEEME
  EXPECT_EQ(std::ranges::distance(std::views::iota(0, 3)), 3);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_RATIO) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_RATIO);
#if LBAL_LIBCPP26_FREESTANDING_RATIO
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  //	SEEME
  EXPECT_EQ((std::ratio_add<std::ratio<1, 2>, std::ratio<1, 2>>::num), 1);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_STRING_VIEW) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_STRING_VIEW);
#if LBAL_LIBCPP26_FREESTANDING_STRING_VIEW
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  EXPECT_EQ(std::string_view("abc").substr(1), "bc");
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_TUPLE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_TUPLE);
#if LBAL_LIBCPP26_FREESTANDING_TUPLE
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  //	SEEME
  EXPECT_EQ(std::get<1>(std::tuple<int, int>(1, 2)), 2);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_UTILITY) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_UTILITY);
#if LBAL_LIBCPP26_FREESTANDING_UTILITY
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  //	SEEME
  int a = 1;
  int b = 2;
  std::swap(a, b);

  EXPECT_EQ(a, 2);
#endif
}

LBAL_FP_TEST(LIBCPP26, FREESTANDING_VARIANT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FREESTANDING_VARIANT);
#if LBAL_LIBCPP26_FREESTANDING_VARIANT
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  std::variant<int, char> v = 'a';

  EXPECT_EQ(v.index(), 1u);
#endif
}

LBAL_FP_TEST(LIBCPP26, FSTREAM_NATIVE_HANDLE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FSTREAM_NATIVE_HANDLE);
#if LBAL_LIBCPP26_FSTREAM_NATIVE_HANDLE
  namespace fs = std::filesystem;

  auto path = fs::temp_directory_path() / "lbalFalsePositive-native-handle.tmp";

  {
    std::ofstream out(path);
    ASSERT_TRUE(out.is_open());

    auto handle = out.native_handle();
    EXPECT_TRUE((
        std::is_same_v<decltype(handle), std::ofstream::native_handle_type>
    ));
  }

  fs::remove(path);
#endif
}

LBAL_FP_TEST(LIBCPP26, FUNCTION_REF) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FUNCTION_REF);
#if LBAL_LIBCPP26_FUNCTION_REF
  //	SEEME
  auto twice = [](int x) {
    return x * 2;
  };
  std::function_ref<int(int)> f = twice;

  EXPECT_EQ(f(3), 6);
#endif
}

LBAL_FP_TEST(LIBCPP26, FUNCTION_REF_LESS_DOUBLE_INDIRECTION) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FUNCTION_REF_LESS_DOUBLE_INDIRECTION);
#if LBAL_LIBCPP26_FUNCTION_REF_LESS_DOUBLE_INDIRECTION
  //	SEEME
  //	Smoke test; it doesn’t isolate the P3961R1 changes.
  auto twice = [](int x) {
    return x * 2;
  };
  std::function_ref<int(int)> f = twice;
  std::function_ref<int(int)> g = f;

  EXPECT_EQ(g(3), 6);
#endif
}

#if LBAL_LIBCPP26_FUNCTION_REF_RENAME_NONTYPE
namespace lbal_fp_libcpp26 {

inline int
twice(int x) {
  return x * 2;
}

}  // namespace lbal_fp_libcpp26
#endif

LBAL_FP_TEST(LIBCPP26, FUNCTION_REF_RENAME_NONTYPE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_FUNCTION_REF_RENAME_NONTYPE);
#if LBAL_LIBCPP26_FUNCTION_REF_RENAME_NONTYPE
  //	SEEME
  //	`std::nontype` became `std::constant_arg` (P3774R1); the name is from
  //	the paper and unverified.
  std::function_ref<int(int)> f(std::constant_arg<&lbal_fp_libcpp26::twice>);

  EXPECT_EQ(f(3), 6);
#endif
}

LBAL_FP_TEST(LIBCPP26, HARDENED_ARRAY) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_HARDENED_ARRAY);
#if LBAL_LIBCPP26_HARDENED_ARRAY
  //	SEEME
  std::array<int, 2> a{};
  [[maybe_unused]]
  std::size_t i = lbal_fp_libcpp26::out_of_range_index();

  LBAL_FP_EXPECT_HARDENED((void)a[i]);
#endif
}

LBAL_FP_TEST(LIBCPP26, HARDENED_BASIC_STACKTRACE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_HARDENED_BASIC_STACKTRACE);
#if LBAL_LIBCPP26_HARDENED_BASIC_STACKTRACE
  //	SEEME
  auto st = std::stacktrace::current();
  [[maybe_unused]]
  std::size_t i = lbal_fp_libcpp26::out_of_range_index();

  LBAL_FP_EXPECT_HARDENED((void)st[st.size() + i]);
#endif
}

LBAL_FP_TEST(LIBCPP26, HARDENED_BASIC_STRING) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_HARDENED_BASIC_STRING);
#if LBAL_LIBCPP26_HARDENED_BASIC_STRING
  //	SEEME
  std::string s = "ab";
  [[maybe_unused]]
  std::size_t i = lbal_fp_libcpp26::out_of_range_index();

  LBAL_FP_EXPECT_HARDENED((void)s[s.size() + i]);
#endif
}

LBAL_FP_TEST(LIBCPP26, HARDENED_BASIC_STRING_VIEW) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_HARDENED_BASIC_STRING_VIEW);
#if LBAL_LIBCPP26_HARDENED_BASIC_STRING_VIEW
  //	SEEME
  std::string_view sv = "ab";
  [[maybe_unused]]
  std::size_t i = lbal_fp_libcpp26::out_of_range_index();

  LBAL_FP_EXPECT_HARDENED((void)sv[i]);
#endif
}

LBAL_FP_TEST(LIBCPP26, HARDENED_BITSET) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_HARDENED_BITSET);
#if LBAL_LIBCPP26_HARDENED_BITSET
  //	SEEME
  std::bitset<4> b;
  [[maybe_unused]]
  std::size_t i = lbal_fp_libcpp26::out_of_range_index();

  LBAL_FP_EXPECT_HARDENED((void)b[i]);
#endif
}

LBAL_FP_TEST(LIBCPP26, HARDENED_COMMON_ITERATOR) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_HARDENED_COMMON_ITERATOR);
#if LBAL_LIBCPP26_HARDENED_COMMON_ITERATOR
  //	SEEME
  std::vector<int> v{1};
  using It = std::common_iterator<
      std::counted_iterator<std::vector<int>::iterator>,
      std::default_sentinel_t
  >;
  It end_it(std::default_sentinel);

  LBAL_FP_EXPECT_HARDENED((void)*end_it);
#endif
}

LBAL_FP_TEST(LIBCPP26, HARDENED_COUNTED_ITERATOR) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_HARDENED_COUNTED_ITERATOR);
#if LBAL_LIBCPP26_HARDENED_COUNTED_ITERATOR
  //	SEEME
  std::vector<int> v{1};
  std::counted_iterator<std::vector<int>::iterator> it(v.begin(), 0);

  LBAL_FP_EXPECT_HARDENED((void)*it);
#endif
}

LBAL_FP_TEST(LIBCPP26, HARDENED_DEQUE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_HARDENED_DEQUE);
#if LBAL_LIBCPP26_HARDENED_DEQUE
  //	SEEME
  std::deque<int> d{1};
  [[maybe_unused]]
  std::size_t i = lbal_fp_libcpp26::out_of_range_index();

  LBAL_FP_EXPECT_HARDENED((void)d[i]);
#endif
}

LBAL_FP_TEST(LIBCPP26, HARDENED_EXPECTED) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_HARDENED_EXPECTED);
#if LBAL_LIBCPP26_HARDENED_EXPECTED
  //	SEEME
  std::expected<int, int> e = 1;

  LBAL_FP_EXPECT_HARDENED((void)e.error());
#endif
}

LBAL_FP_TEST(LIBCPP26, HARDENED_FORWARD_LIST) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_HARDENED_FORWARD_LIST);
#if LBAL_LIBCPP26_HARDENED_FORWARD_LIST
  //	SEEME
  std::forward_list<int> l;

  LBAL_FP_EXPECT_HARDENED((void)l.front());
#endif
}

LBAL_FP_TEST(LIBCPP26, HARDENED_INPLACE_VECTOR) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_HARDENED_INPLACE_VECTOR);
#if LBAL_LIBCPP26_HARDENED_INPLACE_VECTOR
  //	SEEME
  std::inplace_vector<int, 4> v{1};
  [[maybe_unused]]
  std::size_t i = lbal_fp_libcpp26::out_of_range_index();

  LBAL_FP_EXPECT_HARDENED((void)v[i]);
#endif
}

LBAL_FP_TEST(LIBCPP26, HARDENED_LIST) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_HARDENED_LIST);
#if LBAL_LIBCPP26_HARDENED_LIST
  //	SEEME
  std::list<int> l;

  LBAL_FP_EXPECT_HARDENED((void)l.front());
#endif
}

LBAL_FP_TEST(LIBCPP26, HARDENED_MDSPAN) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_HARDENED_MDSPAN);
#if LBAL_LIBCPP26_HARDENED_MDSPAN
  //	SEEME
  int data[4] = {};
  std::mdspan m(data, 2, 2);
  [[maybe_unused]]
  std::size_t i = lbal_fp_libcpp26::out_of_range_index();

  LBAL_FP_EXPECT_HARDENED((void)m[std::array{i, std::size_t{0}}]);
#endif
}

LBAL_FP_TEST(LIBCPP26, HARDENED_OPTIONAL) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_HARDENED_OPTIONAL);
#if LBAL_LIBCPP26_HARDENED_OPTIONAL
  //	SEEME
  std::optional<int> o;

  LBAL_FP_EXPECT_HARDENED((void)*o);
#endif
}

LBAL_FP_TEST(LIBCPP26, HARDENED_SHARED_PTR_ARRAY) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_HARDENED_SHARED_PTR_ARRAY);
#if LBAL_LIBCPP26_HARDENED_SHARED_PTR_ARRAY
  //	SEEME
  auto p = std::make_shared<int[2]>();
  [[maybe_unused]]
  std::size_t i = lbal_fp_libcpp26::out_of_range_index();

  LBAL_FP_EXPECT_HARDENED((void)p[i]);
#endif
}

LBAL_FP_TEST(LIBCPP26, HARDENED_SPAN) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_HARDENED_SPAN);
#if LBAL_LIBCPP26_HARDENED_SPAN
  //	SEEME
  int data[2] = {};
  std::span<int> s(data);
  [[maybe_unused]]
  std::size_t i = lbal_fp_libcpp26::out_of_range_index();

  LBAL_FP_EXPECT_HARDENED((void)s[i]);
#endif
}

LBAL_FP_TEST(LIBCPP26, HARDENED_VALARRAY) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_HARDENED_VALARRAY);
#if LBAL_LIBCPP26_HARDENED_VALARRAY
  //	SEEME
  std::valarray<int> va(2);
  [[maybe_unused]]
  std::size_t i = lbal_fp_libcpp26::out_of_range_index();

  LBAL_FP_EXPECT_HARDENED((void)va[i]);
#endif
}

LBAL_FP_TEST(LIBCPP26, HARDENED_VECTOR) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_HARDENED_VECTOR);
#if LBAL_LIBCPP26_HARDENED_VECTOR
  //	SEEME
  std::vector<int> v{1};
  [[maybe_unused]]
  std::size_t i = lbal_fp_libcpp26::out_of_range_index();

  LBAL_FP_EXPECT_HARDENED((void)v[i]);
#endif
}

LBAL_FP_TEST(LIBCPP26, HARDENED_VIEW_INTERFACE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_HARDENED_VIEW_INTERFACE);
#if LBAL_LIBCPP26_HARDENED_VIEW_INTERFACE
  //	SEEME
  std::vector<int> v;
  auto view = std::views::all(v);

  LBAL_FP_EXPECT_HARDENED((void)view.front());
#endif
}

#if LBAL_LIBCPP26_HAZARD_POINTER
namespace lbal_fp_libcpp26 {

struct Guarded : std::hazard_pointer_obj_base<Guarded> {
  int value = 1;
};

}  // namespace lbal_fp_libcpp26
#endif

LBAL_FP_TEST(LIBCPP26, HAZARD_POINTER) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_HAZARD_POINTER);
#if LBAL_LIBCPP26_HAZARD_POINTER
  //	SEEME
  using lbal_fp_libcpp26::Guarded;

  std::atomic<Guarded*> shared{new Guarded};
  std::hazard_pointer hp = std::make_hazard_pointer();
  Guarded* p = hp.protect(shared);

  EXPECT_EQ(p->value, 1);
  hp.reset_protection();
  shared.exchange(nullptr)->retire();
#endif
}

LBAL_FP_TEST(LIBCPP26, HIVE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_HIVE);
#if LBAL_LIBCPP26_HIVE
  //	SEEME
  std::hive<int> h;
  auto it = h.insert(1);
  h.insert(2);
  h.erase(it);

  EXPECT_EQ(h.size(), 1u);
  EXPECT_EQ(*h.begin(), 2);
#endif
}

LBAL_FP_TEST(LIBCPP26, INDIRECT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_INDIRECT);
#if LBAL_LIBCPP26_INDIRECT
  //	SEEME
  std::indirect<int> a(5);
  std::indirect<int> b = a;
  *b = 6;

  EXPECT_EQ(*a, 5);
  EXPECT_EQ(*b, 6);
#endif
}

LBAL_FP_TEST(LIBCPP26, INITIALIZER_LIST) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_INITIALIZER_LIST);
#if LBAL_LIBCPP26_INITIALIZER_LIST
  //	SEEME
  //	`initializer_list` has `data` and `empty` (P3016R6).
  std::initializer_list<int> il = {1, 2};

  EXPECT_EQ(*il.data(), 1);
  EXPECT_FALSE(il.empty());
#endif
}

LBAL_FP_TEST(LIBCPP26, INPLACE_VECTOR) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_INPLACE_VECTOR);
#if LBAL_LIBCPP26_INPLACE_VECTOR
  //	SEEME
  std::inplace_vector<int, 2> v{1};
  v.push_back(2);

  EXPECT_EQ(v.size(), 2u);
  EXPECT_EQ(v.capacity(), 2u);
  EXPECT_FALSE(v.try_push_back(3));
#endif
}

LBAL_FP_TEST(LIBCPP26, INPLACE_VECTOR_BETTER_RETURN_TYPES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_INPLACE_VECTOR_BETTER_RETURN_TYPES);
#if LBAL_LIBCPP26_INPLACE_VECTOR_BETTER_RETURN_TYPES
  //	SEEME
  //	Smoke test; it doesn’t isolate the P3981R2 changes.
  std::inplace_vector<int, 1> v;

  EXPECT_TRUE(static_cast<bool>(v.try_push_back(1)));
  EXPECT_FALSE(static_cast<bool>(v.try_push_back(2)));
#endif
}

#if LBAL_LIBCPP26_INPLACE_VECTOR_REMOVE_TRY_APPEND_RANGE
namespace lbal_fp_libcpp26 {

LBAL_FP_DETECT(
    has_try_append_range,
    T,
    std::declval<T&>().try_append_range(std::declval<std::vector<int>&>())
)

}  // namespace lbal_fp_libcpp26
#endif

LBAL_FP_TEST(LIBCPP26, INPLACE_VECTOR_REMOVE_TRY_APPEND_RANGE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_INPLACE_VECTOR_REMOVE_TRY_APPEND_RANGE);
#if LBAL_LIBCPP26_INPLACE_VECTOR_REMOVE_TRY_APPEND_RANGE
  //	SEEME
  EXPECT_FALSE((
      lbal_fp_libcpp26::has_try_append_range<std::inplace_vector<int, 2>>::value
  ));
#endif
}

LBAL_FP_TEST(LIBCPP26, INTEGER_SEQUENCE_EXPANSION_STATEMENTS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_INTEGER_SEQUENCE_EXPANSION_STATEMENTS);
#if LBAL_LIBCPP26_INTEGER_SEQUENCE_EXPANSION_STATEMENTS
  //	`integer_sequence` supports the tuple protocol (P1789R3).
  using Seq = std::index_sequence<4, 5>;

  EXPECT_EQ(std::tuple_size_v<Seq>, 2u);
  EXPECT_EQ(std::get<1>(Seq{}), 5u);
#endif
}

LBAL_FP_TEST(LIBCPP26, IS_STRUCTURAL) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_IS_STRUCTURAL);
#if LBAL_LIBCPP26_IS_STRUCTURAL
  //	SEEME
  EXPECT_TRUE(std::is_structural_v<int>);
  EXPECT_FALSE(std::is_structural_v<std::string>);
#endif
}

LBAL_FP_TEST(LIBCPP26, IS_VIRTUAL_BASE_OF) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_IS_VIRTUAL_BASE_OF);
#if LBAL_LIBCPP26_IS_VIRTUAL_BASE_OF
  struct Base { };

  struct Virtual : virtual Base { };

  struct Plain : Base { };

  EXPECT_TRUE((std::is_virtual_base_of_v<Base, Virtual>));
  EXPECT_FALSE((std::is_virtual_base_of_v<Base, Plain>));
#endif
}

LBAL_FP_TEST(LIBCPP26, LINALG) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_LINALG);
#if LBAL_LIBCPP26_LINALG
  //	SEEME
  double a[] = {1.0, 2.0, 3.0};
  double b[] = {4.0, 5.0, 6.0};
  std::mdspan x(a, 3);
  std::mdspan y(b, 3);

  EXPECT_DOUBLE_EQ(std::linalg::dot(x, y), 32.0);
#endif
}

LBAL_FP_TEST(LIBCPP26, LINALG_BLAS_RANK) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_LINALG_BLAS_RANK);
#if LBAL_LIBCPP26_LINALG_BLAS_RANK
  //	SEEME
  //	Rank-1 updates take separate input and output matrices (P3371R5).
  double xs[] = {1.0, 2.0};
  double ys[] = {3.0, 4.0};
  double in[4] = {};
  double out[4] = {};
  std::mdspan x(xs, 2);
  std::mdspan y(ys, 2);
  std::mdspan e(in, 2, 2);
  std::mdspan a(out, 2, 2);

  std::linalg::matrix_rank_1_update(x, y, e, a);
  EXPECT_DOUBLE_EQ(out[3], 8.0);
#endif
}

LBAL_FP_TEST(LIBCPP26, LINALG_FIX_TRANSPOSED) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_LINALG_FIX_TRANSPOSED);
#if LBAL_LIBCPP26_LINALG_FIX_TRANSPOSED
  //	SEEME
  double data[6] = {};
  std::mdspan m(data, 2, 3);
  auto t = std::linalg::transposed(m);

  EXPECT_EQ(t.extent(0), 3u);
  EXPECT_EQ(t.extent(1), 2u);
#endif
}

LBAL_FP_TEST(LIBCPP26, LINALG_OPTIMIZE_CONJUGATED) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_LINALG_OPTIMIZE_CONJUGATED);
#if LBAL_LIBCPP26_LINALG_OPTIMIZE_CONJUGATED
  //	SEEME
  //	Conjugating a real-valued mdspan returns it unchanged (P3050R2).
  double data[2] = {1.0, 2.0};
  std::mdspan x(data, 2);

  EXPECT_TRUE((
      std::is_same_v<decltype(std::linalg::conjugated(x)), decltype(x)>
  ));
#endif
}

LBAL_FP_TEST(LIBCPP26, MDSPAN_DEXTENTS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_MDSPAN_DEXTENTS);
#if LBAL_LIBCPP26_MDSPAN_DEXTENTS
  EXPECT_TRUE((std::is_same_v<std::dims<2>, std::dextents<std::size_t, 2>>));
  EXPECT_TRUE((std::is_same_v<std::dims<1, int>, std::dextents<int, 1>>));
#endif
}

#if LBAL_LIBCPP26_NOT_FN_NTTP_CALLABLES
namespace lbal_fp_libcpp26 {

constexpr bool
is_odd(int x) {
  return x % 2 != 0;
}

}  // namespace lbal_fp_libcpp26
#endif

LBAL_FP_TEST(LIBCPP26, NOT_FN_NTTP_CALLABLES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_NOT_FN_NTTP_CALLABLES);
#if LBAL_LIBCPP26_NOT_FN_NTTP_CALLABLES
  auto is_even = std::not_fn<lbal_fp_libcpp26::is_odd>();

  EXPECT_TRUE(is_even(2));
  EXPECT_FALSE(is_even(3));
#endif
}

LBAL_FP_TEST(LIBCPP26, OBSERVABLE_CHECKPOINT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_OBSERVABLE_CHECKPOINT);
#if LBAL_LIBCPP26_OBSERVABLE_CHECKPOINT
  //	SEEME
  std::observable_checkpoint();
  SUCCEED();
#endif
}

LBAL_FP_TEST(LIBCPP26, OPTIONAL_RANGE_SUPPORT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_OPTIONAL_RANGE_SUPPORT);
#if LBAL_LIBCPP26_OPTIONAL_RANGE_SUPPORT
  //	SEEME
  int sum = 0;

  for (int x : std::optional<int>(3))
    sum += x;
  for (int x : std::optional<int>())
    sum += x;
  EXPECT_EQ(sum, 3);
#endif
}

LBAL_FP_TEST(LIBCPP26, OPTIONAL_REFERENCE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_OPTIONAL_REFERENCE);
#if LBAL_LIBCPP26_OPTIONAL_REFERENCE
  int x = 1;
  std::optional<int&> r = x;
  *r = 2;

  EXPECT_EQ(x, 2);
  EXPECT_EQ(&*r, &x);
#endif
}

LBAL_FP_TEST(LIBCPP26, OUT_PTR_MORE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_OUT_PTR_MORE);
#if LBAL_LIBCPP26_OUT_PTR_MORE
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  //	`out_ptr` and `inout_ptr` are freestanding (P2833R2).
  std::unique_ptr<int> p;
  auto make = [](int** out) {
    *out = new int(4);
  };

  make(std::out_ptr(p));
  EXPECT_EQ(*p, 4);
#endif
}

LBAL_FP_TEST(LIBCPP26, PARALLEL_ALGORITHM_RANGE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_PARALLEL_ALGORITHM_RANGE);
#if LBAL_LIBCPP26_PARALLEL_ALGORITHM_RANGE
  //	SEEME
  std::vector<int> v{3, 1, 2};

  std::ranges::sort(std::execution::par, v);
  EXPECT_EQ(v, (std::vector<int>{1, 2, 3}));
#endif
}

LBAL_FP_TEST(LIBCPP26, PARALLEL_SCHEDULER) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_PARALLEL_SCHEDULER);
#if LBAL_LIBCPP26_PARALLEL_SCHEDULER
  //	SEEME
  auto sched = std::execution::get_parallel_scheduler();
  auto result = std::this_thread::sync_wait(
      std::execution::schedule(sched) | std::execution::then([] {
        return 7;
      })
  );

  ASSERT_TRUE(result.has_value());
  EXPECT_EQ(std::get<0>(*result), 7);
#endif
}

LBAL_FP_TEST(LIBCPP26, PHILOX_ENGINE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_PHILOX_ENGINE);
#if LBAL_LIBCPP26_PHILOX_ENGINE
  //	SEEME
  //	The 10000th output of a default-constructed engine (P2075R6).
  std::philox4x32 e32;
  e32.discard(9999);
  std::philox4x64 e64;
  e64.discard(9999);

  EXPECT_EQ(e32(), 1'955'073'260u);
  EXPECT_EQ(e64(), 3'409'172'418'970'261'260u);
#endif
}

#if LBAL_LIBCPP26_POLYMORPHIC
namespace lbal_fp_libcpp26 {

struct Shape {
  virtual ~Shape() = default;
  virtual int sides() const = 0;
};

struct Square : Shape {
  int
  sides() const override {
    return 4;
  }
};

}  // namespace lbal_fp_libcpp26
#endif

LBAL_FP_TEST(LIBCPP26, POLYMORPHIC) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_POLYMORPHIC);
#if LBAL_LIBCPP26_POLYMORPHIC
  //	SEEME
  using namespace lbal_fp_libcpp26;

  std::polymorphic<Shape> p(std::in_place_type<Square>);
  std::polymorphic<Shape> copy = p;

  EXPECT_EQ(copy->sides(), 4);
#endif
}

LBAL_FP_TEST(LIBCPP26, PRINT_EFFICIENT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_PRINT_EFFICIENT);
#if LBAL_LIBCPP26_PRINT_EFFICIENT
  //	LBAL_FP_SMOKE: the output is the same with or without P3107R5, so it
  //	can’t detect a false negative.
  //	SEEME
  //	P3107R5 allows printing without an intermediate string; the output is
  //	unchanged.
  std::FILE* f = std::tmpfile();
  ASSERT_NE(f, nullptr);

  std::print(f, "{}", 5);
  std::rewind(f);

  char buffer[4] = {};
  ASSERT_NE(std::fgets(buffer, sizeof(buffer), f), nullptr);
  std::fclose(f);
  EXPECT_STREQ(buffer, "5");
#endif
}

LBAL_FP_TEST(LIBCPP26, PRINT_MORE_EFFICIENT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_PRINT_MORE_EFFICIENT);
#if LBAL_LIBCPP26_PRINT_MORE_EFFICIENT
  //	LBAL_FP_SMOKE: `enable_nonlocking_formatter_optimization` comes from
  //	P3107R5; the types P3235R3 adds aren’t checked, so it can’t detect a
  //	false negative.
  //	SEEME
  EXPECT_TRUE(std::enable_nonlocking_formatter_optimization<int>);
#endif
}

LBAL_FP_TEST(LIBCPP26, RANGES_AS_CONST_FIX_CONVERTIBILITY) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_RANGES_AS_CONST_FIX_CONVERTIBILITY);
#if LBAL_LIBCPP26_RANGES_AS_CONST_FIX_CONVERTIBILITY
  //	`basic_const_iterator` converts to anything its underlying iterator
  //	converts to (P2836R1).
  using It = std::vector<int>::iterator;

  EXPECT_TRUE((std::is_convertible_v<
      std::basic_const_iterator<It>,
      std::vector<int>::const_iterator
  >));
#endif
}

LBAL_FP_TEST(LIBCPP26, RANGES_AS_INPUT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_RANGES_AS_INPUT);
#if LBAL_LIBCPP26_RANGES_AS_INPUT
  //	SEEME
  //	The view was renamed from `to_input` to `as_input` (P3828R1) without a
  //	new feature-test value, so the current name is used here too.
  std::vector<int> v{1, 2};
  auto in = v | std::views::as_input;

  EXPECT_FALSE(std::ranges::forward_range<decltype(in)>);
  EXPECT_TRUE(std::ranges::input_range<decltype(in)>);
#endif
}

LBAL_FP_TEST(LIBCPP26, RANGES_AS_INPUT_RENAME) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_RANGES_AS_INPUT_RENAME);
#if LBAL_LIBCPP26_RANGES_AS_INPUT_RENAME
  //	SEEME
  std::vector<int> v{1, 2};
  int sum = 0;

  for (int x : v | std::views::as_input)
    sum += x;
  EXPECT_EQ(sum, 3);
#endif
}

LBAL_FP_TEST(LIBCPP26, RANGES_CACHE_LATEST) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_RANGES_CACHE_LATEST);
#if LBAL_LIBCPP26_RANGES_CACHE_LATEST
  //	The transform runs once per element even though the filter and the loop
  //	both dereference.
  int calls = 0;
  std::vector<int> v{1, 2, 3};
  auto view = v
            | std::views::transform([&](int x) {
                ++calls;
                return x * 2;
              })
            | std::views::cache_latest
            | std::views::filter([](int x) {
                return x > 2;
              });
  int sum = 0;

  for (int x : view)
    sum += x;
  EXPECT_EQ(sum, 10);
  EXPECT_EQ(calls, 3);
#endif
}

LBAL_FP_TEST(LIBCPP26, RANGES_CONCAT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_RANGES_CONCAT);
#if LBAL_LIBCPP26_RANGES_CONCAT
  std::vector<int> a{1, 2};
  std::array<int, 1> b{3};
  int sum = 0;

  for (int x : std::views::concat(a, b))
    sum += x;
  EXPECT_EQ(sum, 6);
#endif
}

LBAL_FP_TEST(LIBCPP26, RANGES_FILTER) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_RANGES_FILTER);
#if LBAL_LIBCPP26_RANGES_FILTER
  //	LBAL_FP_SMOKE: it doesn’t isolate the paper’s changes, so it can’t detect
  //	a false negative.
  //	SEEME
  //	Smoke test; it doesn’t isolate the P3725R3 changes.
  std::vector<int> v{1, 2, 3, 4};

  EXPECT_EQ(
      std::ranges::distance(v | std::views::filter([](int x) {
        return x % 2 == 0;
      })),
      2
  );
#endif
}

LBAL_FP_TEST(LIBCPP26, RANGES_GENERATE_RANDOM) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_RANGES_GENERATE_RANDOM);
#if LBAL_LIBCPP26_RANGES_GENERATE_RANDOM
  //	SEEME
  std::minstd_rand engine;
  std::uniform_int_distribution<int> dist(1, 6);
  std::vector<int> v(8);

  std::ranges::generate_random(v, engine, dist);
  EXPECT_TRUE(std::ranges::all_of(v, [](int x) {
    return x >= 1 && x <= 6;
  }));
#endif
}

LBAL_FP_TEST(LIBCPP26, RANGES_INDICES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_RANGES_INDICES);
#if LBAL_LIBCPP26_RANGES_INDICES
  int sum = 0;

  for (auto i : std::views::indices(4))
    sum += static_cast<int>(i);
  EXPECT_EQ(sum, 6);
#endif
}

LBAL_FP_TEST(LIBCPP26, RANGES_REMOVE_COMMON_REF_REQ) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_RANGES_REMOVE_COMMON_REF_REQ);
#if LBAL_LIBCPP26_RANGES_REMOVE_COMMON_REF_REQ
  //	LBAL_FP_SMOKE: it doesn’t isolate the paper’s changes, so it can’t detect
  //	a false negative.
  //	Indirect callables no longer need a common reference between the
  //	iterator’s reference and value types (P2997R1); smoke test.
  std::vector<int> a{1, 2};
  std::vector<int> b{3, 4};
  int sum = 0;

  std::ranges::for_each(std::views::zip(a, b), [&](auto&& p) {
    sum += std::get<0>(p) * std::get<1>(p);
  });
  EXPECT_EQ(sum, 11);
#endif
}

LBAL_FP_TEST(LIBCPP26, RANGES_RESERVE_HINT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_RANGES_RESERVE_HINT);
#if LBAL_LIBCPP26_RANGES_RESERVE_HINT
  //	SEEME
  std::vector<int> v{1, 2, 3};

  EXPECT_EQ(std::ranges::reserve_hint(v), 3u);
#endif
}

LBAL_FP_TEST(LIBCPP26, RATIO) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_RATIO);
#if LBAL_LIBCPP26_RATIO
  //	LBAL_FP_SMOKE: the new SI prefixes need a wider `intmax_t` than 64-bit
  //	implementations have, so it can’t detect a false negative.
  //	The 2022 SI prefixes (P2734R0) don’t fit in a 64-bit `intmax_t`, so they
  //	only exist on wider implementations; this checks the existing ones.
  EXPECT_EQ(std::exa::num, 1'000'000'000'000'000'000);
  EXPECT_EQ(std::atto::den, 1'000'000'000'000'000'000);
#endif
}

LBAL_FP_TEST(LIBCPP26, RCU) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_RCU);
#if LBAL_LIBCPP26_RCU
  //	SEEME
  {
    std::scoped_lock reader(std::rcu_default_domain());
  }
  std::rcu_synchronize();
  std::rcu_barrier();
  SUCCEED();
#endif
}

LBAL_FP_TEST(LIBCPP26, REFERENCE_WRAPPER) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_REFERENCE_WRAPPER);
#if LBAL_LIBCPP26_REFERENCE_WRAPPER
  //	`std::string`’s comparisons are templates, so before P2944R3 they can’t
  //	see through a `reference_wrapper`; `int`s would compare after an implicit
  //	conversion in any mode.
  std::string a = "a";
  std::string b = "a";
  std::string c = "c";

  EXPECT_TRUE(std::ref(a) == std::ref(b));
  EXPECT_TRUE(std::ref(a) == a);
  EXPECT_TRUE(std::ref(a) < std::ref(c));
#endif
}

LBAL_FP_TEST(LIBCPP26, REPLACEABLE_CONTRACT_VIOLATION_HANDLER) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_REPLACEABLE_CONTRACT_VIOLATION_HANDLER);
#if LBAL_LIBCPP26_REPLACEABLE_CONTRACT_VIOLATION_HANDLER
  //	SEEME
  //	LBAL_FP_SMOKE: replacing the handler would affect the whole test program,
  //	and any translation unit may define `handle_contract_violation` whether
  //	or not P3886R0 makes it replaceable, so this only checks that the
  //	P2900 types it uses are available.
  EXPECT_FALSE(
      std::is_copy_constructible_v<std::contracts::contract_violation>
  );
#endif
}

LBAL_FP_TEST(LIBCPP26, SATURATION_ARITHMETIC) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_SATURATION_ARITHMETIC);
#if LBAL_LIBCPP26_SATURATION_ARITHMETIC
  //	P4052R0 renamed these functions, so a library that reports it only has
  //	the new names (libc++ 23, for one).
  #if LBAL_LIBCPP26_SATURATION_ARITHMETIC_RENAMING
  EXPECT_EQ(std::saturating_add<std::uint8_t>(250, 10), 255);
  EXPECT_EQ(std::saturating_sub<std::uint8_t>(5, 10), 0);
  EXPECT_EQ(std::saturating_mul<std::int8_t>(100, 2), 127);
  EXPECT_EQ(std::saturating_cast<std::int8_t>(1000), 127);
  #else
  EXPECT_EQ(std::add_sat<std::uint8_t>(250, 10), 255);
  EXPECT_EQ(std::sub_sat<std::uint8_t>(5, 10), 0);
  EXPECT_EQ(std::mul_sat<std::int8_t>(100, 2), 127);
  EXPECT_EQ(std::saturate_cast<std::int8_t>(1000), 127);
  #endif
#endif
}

LBAL_FP_TEST(LIBCPP26, SATURATION_ARITHMETIC_RENAMING) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_SATURATION_ARITHMETIC_RENAMING);
#if LBAL_LIBCPP26_SATURATION_ARITHMETIC_RENAMING
  //	The new names are from P4052R0.
  EXPECT_EQ(std::saturating_add<std::uint8_t>(250, 10), 255);
  EXPECT_EQ(std::saturating_cast<std::int8_t>(1000), 127);
#endif
}

LBAL_FP_TEST(LIBCPP26, SENDERS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_SENDERS);
#if LBAL_LIBCPP26_SENDERS
  //	SEEME
  auto result = std::this_thread::sync_wait(
      std::execution::just(1) | std::execution::then([](int x) {
        return x + 1;
      })
  );

  ASSERT_TRUE(result.has_value());
  EXPECT_EQ(std::get<0>(*result), 2);
#endif
}

LBAL_FP_TEST(LIBCPP26, SENDERS_OPTIONAL) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_SENDERS_OPTIONAL);
#if LBAL_LIBCPP26_SENDERS_OPTIONAL
  //	SEEME
  //	Smoke test; it doesn’t isolate the P3570R2 changes.
  auto result = std::this_thread::sync_wait(std::execution::just(3));

  ASSERT_TRUE(result.has_value());
  EXPECT_EQ(std::get<0>(*result), 3);
#endif
}

LBAL_FP_TEST(LIBCPP26, SIMD) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_SIMD);
#if LBAL_LIBCPP26_SIMD
  //	SEEME
  std::simd::vec<int, 4> v(2);
  auto doubled = v + v;

  EXPECT_EQ(doubled[3], 4);
  EXPECT_EQ(std::simd::reduce(v), 8);
#endif
}

LBAL_FP_TEST(LIBCPP26, SIMD_BIT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_SIMD_BIT);
#if LBAL_LIBCPP26_SIMD_BIT
  //	SEEME
  std::simd::vec<unsigned, 4> v(0b1011u);

  EXPECT_EQ(std::popcount(v)[0], 3);
#endif
}

LBAL_FP_TEST(LIBCPP26, SIMD_CHUNK) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_SIMD_CHUNK);
#if LBAL_LIBCPP26_SIMD_CHUNK
  //	SEEME
  std::simd::vec<int, 4> v(1);
  auto parts = std::simd::chunk<std::simd::vec<int, 2>>(v);

  EXPECT_EQ(std::get<1>(parts)[1], 1);
#endif
}

LBAL_FP_TEST(LIBCPP26, SIMD_COMPLEX) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_SIMD_COMPLEX);
#if LBAL_LIBCPP26_SIMD_COMPLEX
  //	SEEME
  std::simd::vec<std::complex<float>, 2> v(std::complex<float>(1.0f, 2.0f));

  EXPECT_EQ(v[1].imag(), 2.0f);
#endif
}

LBAL_FP_TEST(LIBCPP26, SIMD_DEDUCTION_GUIDES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_SIMD_DEDUCTION_GUIDES);
#if LBAL_LIBCPP26_SIMD_DEDUCTION_GUIDES
  //	SEEME
  //	Smoke test; it doesn’t isolate the P3922R1 changes.
  std::simd::vec<int, 4> v(1);
  auto m = v == v;

  EXPECT_TRUE(std::simd::all_of(m));
#endif
}

LBAL_FP_TEST(LIBCPP26, SIMD_EXTEND) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_SIMD_EXTEND);
#if LBAL_LIBCPP26_SIMD_EXTEND
  //	SEEME
  //	Smoke test; it doesn’t isolate the P2876R3 changes.
  std::simd::vec<int, 4> v([](int i) {
    return i;
  });

  EXPECT_EQ(v[3], 3);
#endif
}

LBAL_FP_TEST(LIBCPP26, SIMD_NAMESPACES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_SIMD_NAMESPACES);
#if LBAL_LIBCPP26_SIMD_NAMESPACES
  //	SEEME
  EXPECT_EQ((std::simd::vec<int, 4>::size()), 4);
  EXPECT_EQ((std::simd::mask<int, 4>::size()), 4);
#endif
}

LBAL_FP_TEST(LIBCPP26, SIMD_PERMUTATIONS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_SIMD_PERMUTATIONS);
#if LBAL_LIBCPP26_SIMD_PERMUTATIONS
  //	SEEME
  std::simd::vec<int, 4> v([](int i) {
    return i;
  });
  auto reversed = std::simd::permute(v, [](int i) {
    return 3 - i;
  });

  EXPECT_EQ(reversed[0], 3);
#endif
}

LBAL_FP_TEST(LIBCPP26, SIMD_RANGE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_SIMD_RANGE);
#if LBAL_LIBCPP26_SIMD_RANGE
  //	SEEME
  std::simd::vec<int, 4> v(2);
  int sum = 0;

  for (int x : v)
    sum += x;
  EXPECT_EQ(sum, 8);
#endif
}

LBAL_FP_TEST(LIBCPP26, SMART_POINTER_OWNER_EQUALITY) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_SMART_POINTER_OWNER_EQUALITY);
#if LBAL_LIBCPP26_SMART_POINTER_OWNER_EQUALITY
  //	SEEME
  auto sp = std::make_shared<int>(1);
  std::weak_ptr<int> wp = sp;
  std::unordered_set<std::weak_ptr<int>, std::owner_hash, std::owner_equal> s{
    wp
  };

  EXPECT_TRUE(sp.owner_equal(wp));
  EXPECT_EQ(sp.owner_hash(), wp.owner_hash());
  EXPECT_EQ(s.count(sp), 1u);
#endif
}

LBAL_FP_TEST(LIBCPP26, SMART_PTR_OWNER_EQUALITY) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_SMART_PTR_OWNER_EQUALITY);
#if LBAL_LIBCPP26_SMART_PTR_OWNER_EQUALITY
  //	SEEME
  auto sp = std::make_shared<int>(1);
  std::weak_ptr<int> wp = sp;

  EXPECT_TRUE(std::owner_equal{}(sp, wp));
  EXPECT_EQ(std::owner_hash{}(sp), std::owner_hash{}(wp));
#endif
}

LBAL_FP_TEST(LIBCPP26, SPAN_AT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_SPAN_AT);
#if LBAL_LIBCPP26_SPAN_AT
  int data[] = {1, 2};
  std::span<int> s(data);

  EXPECT_EQ(s.at(1), 2);
  #if LBAL_CPP03_EXCEPTIONS
  EXPECT_THROW((void)s.at(2), std::out_of_range);
  #endif
#endif
}

LBAL_FP_TEST(LIBCPP26, SPAN_MORE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_SPAN_MORE);
#if LBAL_LIBCPP26_SPAN_MORE
  //	LBAL_FP_SMOKE: hosted libraries have this whether or not they meet the
  //	freestanding requirements, so it can’t detect a false negative.
  //	`span` is freestanding (P2833R2).
  int data[] = {1, 2, 3};

  EXPECT_EQ(std::span<int>(data).last(2)[0], 2);
#endif
}

LBAL_FP_TEST(LIBCPP26, SSTREAM_FROM_STRING_VIEW) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_SSTREAM_FROM_STRING_VIEW);
#if LBAL_LIBCPP26_SSTREAM_FROM_STRING_VIEW
  std::istringstream in(std::string_view("1 2"));
  int a = 0;
  int b = 0;
  in >> a >> b;

  std::ostringstream out;
  out.str(std::string_view("ab"));

  EXPECT_EQ(a + b, 3);
  EXPECT_EQ(out.str(), "ab");
#endif
}

LBAL_FP_TEST(LIBCPP26, STDBIT_H) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_STDBIT_H);
#if LBAL_LIBCPP26_STDBIT_H
  EXPECT_EQ(stdc_count_ones(0b1011u), 3u);
  EXPECT_TRUE(stdc_has_single_bit(8u));
#endif
}

LBAL_FP_TEST(LIBCPP26, STDCKDINT_H) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_STDCKDINT_H);
#if LBAL_LIBCPP26_STDCKDINT_H
  int result = 0;

  EXPECT_TRUE(ckd_add(&result, INT_MAX, 1));
  EXPECT_FALSE(ckd_add(&result, 1, 2));
  EXPECT_EQ(result, 3);
#endif
}

LBAL_FP_TEST(LIBCPP26, STRING_SUBVIEW) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_STRING_SUBVIEW);
#if LBAL_LIBCPP26_STRING_SUBVIEW
  std::string s = "hello";

  EXPECT_EQ(s.subview(1, 3), "ell");
  EXPECT_TRUE((std::is_same_v<decltype(s.subview(1)), std::string_view>));
#endif
}

LBAL_FP_TEST(LIBCPP26, STRING_VIEW_CONCAT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_STRING_VIEW_CONCAT);
#if LBAL_LIBCPP26_STRING_VIEW_CONCAT
  std::string s = "a";

  EXPECT_EQ(s + std::string_view("b"), "ab");
  EXPECT_EQ(std::string_view("c") + s, "ca");
#endif
}

LBAL_FP_TEST(LIBCPP26, SUBMDSPAN) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_SUBMDSPAN);
#if LBAL_LIBCPP26_SUBMDSPAN
  //	SEEME
  int data[6] = {0, 1, 2, 3, 4, 5};
  std::mdspan m(data, 2, 3);
  auto row = std::submdspan(m, 1, std::full_extent);

  EXPECT_EQ(row.extent(0), 3u);
  EXPECT_EQ(row[std::array{std::size_t{2}}], 5);
#endif
}

LBAL_FP_TEST(LIBCPP26, SUBMDSPAN_FIX) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_SUBMDSPAN_FIX);
#if LBAL_LIBCPP26_SUBMDSPAN_FIX
  //	SEEME
  //	Smoke test; it doesn’t isolate the P3355R1 changes.
  int data[4] = {0, 1, 2, 3};
  std::mdspan m(data, 2, 2);

  EXPECT_EQ(std::submdspan(m, std::full_extent, 0).extent(0), 2u);
#endif
}

LBAL_FP_TEST(LIBCPP26, SUBMDSPAN_FUTURE_PROOF) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_SUBMDSPAN_FUTURE_PROOF);
#if LBAL_LIBCPP26_SUBMDSPAN_FUTURE_PROOF
  //	SEEME
  //	Smoke test; it doesn’t isolate the P3663R3 changes.
  int data[4] = {0, 1, 2, 3};
  std::mdspan m(data, 2, 2);

  EXPECT_EQ((std::submdspan(m, 1, 1)[std::array<std::size_t, 0>{}]), 3);
#endif
}

LBAL_FP_TEST(LIBCPP26, SUBMDSPAN_PADDED) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_SUBMDSPAN_PADDED);
#if LBAL_LIBCPP26_SUBMDSPAN_PADDED
  //	SEEME
  using Mapping
      = std::layout_right_padded<4>::mapping<std::dextents<std::size_t, 2>>;
  Mapping mapping(std::dextents<std::size_t, 2>(2, 3));

  EXPECT_EQ(mapping.stride(0), 4u);
  EXPECT_EQ(mapping.required_span_size(), 7u);
#endif
}

LBAL_FP_TEST(LIBCPP26, SUBMDSPAN_UPDATE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_SUBMDSPAN_UPDATE);
#if LBAL_LIBCPP26_SUBMDSPAN_UPDATE
  //	SEEME
  //	Tracks later working-draft changes; smoke test.
  int data[4] = {0, 1, 2, 3};
  std::mdspan m(data, 2, 2);

  EXPECT_EQ(std::submdspan(m, 1, std::full_extent).extent(0), 2u);
#endif
}

#if LBAL_LIBCPP26_TASK
namespace lbal_fp_libcpp26 {

inline std::execution::task<int>
answer() {
  co_return 42;
}

}  // namespace lbal_fp_libcpp26
#endif

LBAL_FP_TEST(LIBCPP26, TASK) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_TASK);
#if LBAL_LIBCPP26_TASK
  //	SEEME
  auto result = std::this_thread::sync_wait(lbal_fp_libcpp26::answer());

  ASSERT_TRUE(result.has_value());
  EXPECT_EQ(std::get<0>(*result), 42);
#endif
}

LBAL_FP_TEST(LIBCPP26, TEXT_ENCODING) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_TEXT_ENCODING);
#if LBAL_LIBCPP26_TEXT_ENCODING
  std::text_encoding utf8("UTF-8");

  EXPECT_EQ(utf8.mib(), std::text_encoding::UTF8);
  EXPECT_TRUE(utf8 == std::text_encoding::UTF8);
  EXPECT_NE(std::text_encoding::literal().mib(), std::text_encoding::unknown);
#endif
}

LBAL_FP_TEST(LIBCPP26, TO_CHARS_BOOL_TEST) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_TO_CHARS_BOOL_TEST);
#if LBAL_LIBCPP26_TO_CHARS_BOOL_TEST
  char buffer[2] = {};
  int value = 0;

  EXPECT_TRUE(static_cast<bool>(std::to_chars(buffer, buffer + 2, 7)));
  EXPECT_FALSE(static_cast<bool>(std::to_chars(buffer, buffer + 1, 100)));
  EXPECT_FALSE(static_cast<bool>(std::from_chars(buffer, buffer, value)));
#endif
}

LBAL_FP_TEST(LIBCPP26, TO_STRING) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_TO_STRING);
#if LBAL_LIBCPP26_TO_STRING
  //	Floating-point values use the shortest representation (P2587R3).
  EXPECT_EQ(std::to_string(1.5), "1.5");
  EXPECT_EQ(std::to_string(1e100), "1e+100");
#endif
}

LBAL_FP_TEST(LIBCPP26, TUPLE_LIKE_COMPLEX) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_TUPLE_LIKE_COMPLEX);
#if LBAL_LIBCPP26_TUPLE_LIKE_COMPLEX
  std::complex<double> c(1.0, 2.0);
  auto [re, im] = c;

  EXPECT_EQ(re, 1.0);
  EXPECT_EQ(im, 2.0);
  EXPECT_EQ(std::get<1>(c), 2.0);
#endif
}

LBAL_FP_TEST(LIBCPP26, TYPE_ORDER) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_TYPE_ORDER);
#if LBAL_LIBCPP26_TYPE_ORDER
  //	SEEME
  EXPECT_TRUE((std::type_order_v<int, int> == std::strong_ordering::equal));
  EXPECT_TRUE(
      (std::type_order_v<int, long> == std::strong_ordering::equal) == false
  );
  EXPECT_TRUE((std::type_order_v<int, long> == 0) == false);
#endif
}

LBAL_FP_TEST(LIBCPP26, VALARRAY) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_VALARRAY);
#if LBAL_LIBCPP26_VALARRAY
  //	SEEME
  //	`valarray` has member `begin` and `end` (P3016R6).
  std::valarray<int> va{1, 2, 3};

  EXPECT_EQ(*va.begin(), 1);
  EXPECT_EQ(va.end() - va.begin(), 3);
#endif
}

LBAL_FP_TEST(LIBCPP26, VARIANT_VISITOR) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP26_VARIANT_VISITOR);
#if LBAL_LIBCPP26_VARIANT_VISITOR
  std::variant<int, double> v = 2;

  EXPECT_EQ(
      v.visit([](auto x) {
        return static_cast<int>(x) * 2;
      }),
      4
  );
  EXPECT_EQ(
      v.visit<long>([](auto x) {
        return x;
      }),
      2L
  );
#endif
}
