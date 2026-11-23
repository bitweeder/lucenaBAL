/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFalsePositiveTest-libcpp14.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Soft false-positive probes for `LBAL_LIBCPP14_*` tokens.

------------------------------------------------------------------------------*/

//	std
#include <algorithm>
#include <chrono>
#include <complex>
#include <cstddef>
#include <functional>
#include <iomanip>
#include <memory>
#include <set>
#include <shared_mutex>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

namespace lbal_fp_libcpp14 {

//	Compares with `int` but doesn’t convert to it, so a lookup with it only
//	compiles through the heterogeneous overloads.
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

LBAL_FP_DETECT(
    has_heterogeneous_find,
    T,
    std::declval<std::set<int, std::less<>>&>().find(std::declval<T>())
)

struct Final final { };

}  // namespace lbal_fp_libcpp14

LBAL_FP_TEST(LIBCPP14, CHRONO_UDLS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP14_CHRONO_UDLS);
#if LBAL_LIBCPP14_CHRONO_UDLS
  using namespace std::chrono_literals;

  EXPECT_EQ(
      std::chrono::duration_cast<std::chrono::milliseconds>(1s).count(), 1000
  );
  EXPECT_EQ((5min).count(), 5);
#endif
}

LBAL_FP_TEST(LIBCPP14, COMPLEX_UDLS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP14_COMPLEX_UDLS);
#if LBAL_LIBCPP14_COMPLEX_UDLS
  using namespace std::complex_literals;

  std::complex<double> c = 2.0i;

  EXPECT_EQ(c.imag(), 2.0);
  EXPECT_EQ(c.real(), 0.0);
#endif
}

LBAL_FP_TEST(LIBCPP14, EXCHANGE_FUNCTION) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP14_EXCHANGE_FUNCTION);
#if LBAL_LIBCPP14_EXCHANGE_FUNCTION
  int x = 1;

  EXPECT_EQ(std::exchange(x, 2), 1);
  EXPECT_EQ(x, 2);
#endif
}

LBAL_FP_TEST(LIBCPP14, GENERIC_ASSOCIATIVE_LOOKUP) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP);
#if LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP
  using namespace lbal_fp_libcpp14;

  EXPECT_TRUE(has_heterogeneous_find<IntKey>::value);

  if constexpr (has_heterogeneous_find<IntKey>::value) {
    std::set<int, std::less<>> s{1, 2, 3};
    EXPECT_NE(s.find(IntKey{2}), s.end());
    EXPECT_EQ(s.count(IntKey{4}), 0u);
  }
#endif
}

LBAL_FP_TEST(LIBCPP14, INTEGER_SEQUENCE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP14_INTEGER_SEQUENCE);
#if LBAL_LIBCPP14_INTEGER_SEQUENCE
  EXPECT_EQ(std::make_index_sequence<3>::size(), 3u);
  EXPECT_TRUE((std::is_same<
      std::make_integer_sequence<int, 2>,
      std::integer_sequence<int, 0, 1>
  >::value));
#endif
}

LBAL_FP_TEST(LIBCPP14, INTEGRAL_CONSTANT_CALLABLE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE);
#if LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE
  EXPECT_EQ((std::integral_constant<int, 5>{}()), 5);
#endif
}

LBAL_FP_TEST(LIBCPP14, IS_FINAL) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP14_IS_FINAL);
#if LBAL_LIBCPP14_IS_FINAL
  EXPECT_TRUE(std::is_final<lbal_fp_libcpp14::Final>::value);
  EXPECT_FALSE(std::is_final<std::string>::value);
#endif
}

LBAL_FP_TEST(LIBCPP14, IS_NULL_POINTER) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP14_IS_NULL_POINTER);
#if LBAL_LIBCPP14_IS_NULL_POINTER
  EXPECT_TRUE(std::is_null_pointer<std::nullptr_t>::value);
  EXPECT_FALSE(std::is_null_pointer<int*>::value);
#endif
}

LBAL_FP_TEST(LIBCPP14, MAKE_REVERSE_ITERATOR) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR);
#if LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR
  int a[] = {1, 2, 3};

  EXPECT_EQ(*std::make_reverse_iterator(std::end(a)), 3);
#endif
}

LBAL_FP_TEST(LIBCPP14, MAKE_UNIQUE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP14_MAKE_UNIQUE);
#if LBAL_LIBCPP14_MAKE_UNIQUE
  auto one = std::make_unique<int>(4);
  auto many = std::make_unique<int[]>(3);

  EXPECT_EQ(*one, 4);
  EXPECT_EQ(many[2], 0);
#endif
}

LBAL_FP_TEST(LIBCPP14, NULL_ITERATORS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP14_NULL_ITERATORS);
#if LBAL_LIBCPP14_NULL_ITERATORS
  std::vector<int>::iterator a{}, b{};
  std::set<int>::iterator c{}, d{};

  EXPECT_TRUE(a == b);
  EXPECT_TRUE(c == d);
#endif
}

LBAL_FP_TEST(LIBCPP14, QUOTED_STRING_IO) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP14_QUOTED_STRING_IO);
#if LBAL_LIBCPP14_QUOTED_STRING_IO
  std::ostringstream out;
  out << std::quoted("a b");
  EXPECT_EQ(out.str(), "\"a b\"");

  std::istringstream in(out.str());
  std::string read;
  in >> std::quoted(read);
  EXPECT_EQ(read, "a b");
#endif
}

LBAL_FP_TEST(LIBCPP14, ROBUST_NONMODIFYING_SEQ_OPS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS);
#if LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS
  std::vector<int> a{1, 2, 3};
  std::vector<int> b{1, 2};

  //	The four-iterator overloads check both lengths.
  EXPECT_FALSE(std::equal(a.begin(), a.end(), b.begin(), b.end()));
  EXPECT_EQ(
      std::mismatch(a.begin(), a.end(), b.begin(), b.end()).second, b.end()
  );
  EXPECT_FALSE(std::is_permutation(a.begin(), a.end(), b.begin(), b.end()));
#endif
}

LBAL_FP_TEST(LIBCPP14, SHARED_TIMED_MUTEX) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP14_SHARED_TIMED_MUTEX);
#if LBAL_LIBCPP14_SHARED_TIMED_MUTEX
  std::shared_timed_mutex m;

  ASSERT_TRUE(m.try_lock_shared_for(std::chrono::milliseconds(1)));
  m.unlock_shared();
  ASSERT_TRUE(m.try_lock_for(std::chrono::milliseconds(1)));
  m.unlock();
#endif
}

LBAL_FP_TEST(LIBCPP14, STRING_UDLS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP14_STRING_UDLS);
#if LBAL_LIBCPP14_STRING_UDLS
  using namespace std::string_literals;

  auto s = "a\0b"s;

  EXPECT_TRUE((std::is_same<decltype(s), std::string>::value));
  EXPECT_EQ(s.size(), 3u);
#endif
}

LBAL_FP_TEST(LIBCPP14, TRANSFORMATION_TRAIT_ALIASES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES);
#if LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES
  EXPECT_TRUE((std::is_same<std::remove_const_t<const int>, int>::value));
  EXPECT_TRUE((std::is_same<std::enable_if_t<true, int>, int>::value));
#endif
}

LBAL_FP_TEST(LIBCPP14, TRANSPARENT_OPERATORS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP14_TRANSPARENT_OPERATORS);
#if LBAL_LIBCPP14_TRANSPARENT_OPERATORS
  //	`std::less<>` compares mixed types without converting either side.
  EXPECT_TRUE(std::less<>{}(1, 1.5));
  EXPECT_EQ(std::plus<>{}(1, 2.5), 3.5);
#endif
}

LBAL_FP_TEST(LIBCPP14, TUPLES_BY_TYPE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP14_TUPLES_BY_TYPE);
#if LBAL_LIBCPP14_TUPLES_BY_TYPE
  std::tuple<int, double> t{1, 2.0};

  EXPECT_EQ(std::get<double>(t), 2.0);
  EXPECT_EQ(std::get<int>(t), 1);
#endif
}

LBAL_FP_TEST(LIBCPP14, TUPLE_ELEMENT_T) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP14_TUPLE_ELEMENT_T);
#if LBAL_LIBCPP14_TUPLE_ELEMENT_T
  EXPECT_TRUE(
      (std::is_same<std::tuple_element_t<1, std::tuple<int, double>>, double>::
              value)
  );
#endif
}
