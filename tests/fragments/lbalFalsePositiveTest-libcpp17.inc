/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFalsePositiveTest-libcpp17.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Soft false-positive probes for `LBAL_LIBCPP17_*` tokens. Tokens that are only
  about `constexpr` support have hard probes in `probes/libcpp17/`.

  Headers that aren’t guaranteed to exist are included only when a token says
  they’re usable.

------------------------------------------------------------------------------*/

//	std
#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <exception>
#include <forward_list>
#include <functional>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <random>
#include <string>
#include <string_view>
#include <thread>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

#if LBAL_LIBCPP17_ANY || LBAL_LIBCPP17_ANY_INTERFACE
  #include <any>
#endif

#if LBAL_LIBCPP17_BYTE
  #include <cstddef>
#endif

#if LBAL_LIBCPP17_TO_CHARS                                                     \
    || LBAL_LIBCPP17_TO_CHARS_FP                                               \
    || LBAL_LIBCPP17_TO_CHARS_INTEGER
  #include <charconv>
#endif

#if LBAL_LIBCPP17_EXECUTION                                                    \
    || LBAL_LIBCPP17_PARALLEL_ALGORITHM                                        \
    || LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS
  #include <execution>
#endif

#if LBAL_LIBCPP17_FILESYSTEM                                                   \
    || LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING                        \
    || LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED                                 \
    || LBAL_LIBCPP17_FILESYSTEM_RELATIVE_PATHS
  #include <filesystem>
#endif

#if LBAL_LIBCPP17_MEMORY_RESOURCE
  #include <memory_resource>
#endif

#if LBAL_LIBCPP17_OPTIONAL                                                     \
    || LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL                                    \
    || LBAL_LIBCPP17_OPTIONAL_INTERFACE
  #include <optional>
#endif

#if LBAL_LIBCPP17_SHARED_MUTEX
  #include <shared_mutex>
#endif

#if LBAL_LIBCPP17_VARIANT
  #include <variant>
#endif

namespace lbal_fp_libcpp17 {

struct Aggregate {
  int a;
  double b;
};

struct Padded {
  char c;
  int i;
};

struct Immovable {
  Immovable() = default;
  Immovable(Immovable&&) = delete;
  Immovable& operator= (Immovable&&) = delete;
};

LBAL_FP_DETECT(
    has_is_always_equal,
    T,
    std::allocator_traits<std::allocator<T>>::is_always_equal::value
)

LBAL_FP_DETECT(
    has_weak_type, T, std::declval<typename std::shared_ptr<T>::weak_type>()
)

}  // namespace lbal_fp_libcpp17

LBAL_FP_TEST(LIBCPP17, ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL);
#if LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL
  using namespace lbal_fp_libcpp17;

  EXPECT_TRUE(has_is_always_equal<int>::value);

  if constexpr (has_is_always_equal<int>::value) {
    EXPECT_TRUE(
        std::allocator_traits<std::allocator<int>>::is_always_equal::value
    );
  }
#endif
}

LBAL_FP_TEST(LIBCPP17, ANY) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_ANY);
#if LBAL_LIBCPP17_ANY
  std::any a = 1;

  ASSERT_NE(std::any_cast<int>(&a), nullptr);
  EXPECT_EQ(*std::any_cast<int>(&a), 1);
  EXPECT_EQ(std::any_cast<double>(&a), nullptr);
#endif
}

#if LBAL_LIBCPP17_ANY_INTERFACE
namespace lbal_fp_libcpp17 {

LBAL_FP_DETECT(any_has_value, T, std::declval<T&>().has_value())

LBAL_FP_DETECT(
    any_emplace_returns_ref,
    T,
    std::enable_if_t<std::is_same_v<
        decltype(std::declval<T&>().template emplace<int>(1)),
        int&
    >>()
)

}  // namespace lbal_fp_libcpp17
#endif

LBAL_FP_TEST(LIBCPP17, ANY_INTERFACE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_ANY_INTERFACE);
#if LBAL_LIBCPP17_ANY_INTERFACE
  using namespace lbal_fp_libcpp17;

  EXPECT_TRUE(any_has_value<std::any>::value);
  EXPECT_TRUE(any_emplace_returns_ref<std::any>::value);

  std::any a(std::in_place_type<int>, 3);
  EXPECT_EQ(*std::any_cast<int>(&a), 3);
#endif
}

LBAL_FP_TEST(LIBCPP17, APPLY) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_APPLY);
#if LBAL_LIBCPP17_APPLY
  EXPECT_EQ(
      std::apply(
          [](int a, int b) {
            return a + b;
          },
          std::make_tuple(1, 2)
      ),
      3
  );
#endif
}

LBAL_FP_TEST(LIBCPP17, AS_CONST) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_AS_CONST);
#if LBAL_LIBCPP17_AS_CONST
  int x = 1;

  EXPECT_TRUE((std::is_same_v<decltype(std::as_const(x)), const int&>));
  EXPECT_EQ(&std::as_const(x), &x);
#endif
}

LBAL_FP_TEST(LIBCPP17, ATOMIC_IS_ALWAYS_LOCK_FREE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE);
#if LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE
  constexpr bool always = std::atomic<int>::is_always_lock_free;

  if (always) {
    EXPECT_TRUE(std::atomic<int>{}.is_lock_free());
  }
#endif
}

LBAL_FP_TEST(LIBCPP17, BOOL_CONSTANT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_BOOL_CONSTANT);
#if LBAL_LIBCPP17_BOOL_CONSTANT
  EXPECT_TRUE((std::is_same_v<std::bool_constant<true>, std::true_type>));
#endif
}

LBAL_FP_TEST(LIBCPP17, BOYER_MOORE_SEARCHER) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_BOYER_MOORE_SEARCHER);
#if LBAL_LIBCPP17_BOYER_MOORE_SEARCHER
  std::string haystack = "hello world";
  std::string needle = "world";

  auto bm = std::search(
      haystack.begin(),
      haystack.end(),
      std::boyer_moore_searcher(needle.begin(), needle.end())
  );
  auto bmh = std::search(
      haystack.begin(),
      haystack.end(),
      std::boyer_moore_horspool_searcher(needle.begin(), needle.end())
  );

  EXPECT_EQ(bm - haystack.begin(), 6);
  EXPECT_EQ(bmh - haystack.begin(), 6);
#endif
}

LBAL_FP_TEST(LIBCPP17, BYTE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_BYTE);
#if LBAL_LIBCPP17_BYTE
  std::byte b{0x0F};

  EXPECT_EQ(std::to_integer<int>(b << 1), 0x1E);
  EXPECT_EQ(std::to_integer<int>(b | std::byte{0xF0}), 0xFF);
#endif
}

LBAL_FP_TEST(LIBCPP17, CHRONO) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_CHRONO);
#if LBAL_LIBCPP17_CHRONO
  using namespace std::chrono;

  EXPECT_EQ(floor<seconds>(milliseconds(1500)).count(), 1);
  EXPECT_EQ(ceil<seconds>(milliseconds(1500)).count(), 2);
  EXPECT_EQ(round<seconds>(milliseconds(1500)).count(), 2);
  EXPECT_EQ(round<seconds>(milliseconds(2500)).count(), 2);
  EXPECT_EQ(abs(seconds(-1)).count(), 1);
#endif
}

LBAL_FP_TEST(LIBCPP17, CLAMP) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_CLAMP);
#if LBAL_LIBCPP17_CLAMP
  EXPECT_EQ(std::clamp(5, 0, 3), 3);
  EXPECT_EQ(std::clamp(-1, 0, 3), 0);
#endif
}

#if LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS
namespace lbal_fp_libcpp17 {

struct Shared : std::enable_shared_from_this<Shared> { };

LBAL_FP_DETECT(has_weak_from_this, T, std::declval<T&>().weak_from_this())

}  // namespace lbal_fp_libcpp17
#endif

LBAL_FP_TEST(LIBCPP17, ENABLE_SHARED_FROM_THIS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS);
#if LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS
  using namespace lbal_fp_libcpp17;

  EXPECT_TRUE(has_weak_from_this<Shared>::value);

  if constexpr (has_weak_from_this<Shared>::value) {
    auto p = std::make_shared<Shared>();
    Shared unowned;

    EXPECT_EQ(p->weak_from_this().lock(), p);
    EXPECT_TRUE(unowned.weak_from_this().expired());
  }
#endif
}

LBAL_FP_TEST(LIBCPP17, EXECUTION) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_EXECUTION);
#if LBAL_LIBCPP17_EXECUTION
  std::vector<int> v{3, 1, 2};

  std::sort(std::execution::seq, v.begin(), v.end());
  EXPECT_EQ(v, (std::vector<int>{1, 2, 3}));

  EXPECT_TRUE(std::is_execution_policy_v<std::execution::parallel_policy>);
#endif
}

LBAL_FP_TEST(LIBCPP17, FILESYSTEM) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_FILESYSTEM);
#if LBAL_LIBCPP17_FILESYSTEM
  namespace fs = std::filesystem;

  fs::path p = fs::path("a") / "b.txt";

  EXPECT_EQ(p.filename(), fs::path("b.txt"));
  EXPECT_EQ(p.extension(), fs::path(".txt"));
  EXPECT_TRUE(fs::is_directory(fs::current_path()));
#endif
}

#if LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING
namespace lbal_fp_libcpp17 {

LBAL_FP_DETECT(entry_has_exists, T, std::declval<T&>().exists())

}  // namespace lbal_fp_libcpp17
#endif

LBAL_FP_TEST(LIBCPP17, FILESYSTEM_DIRECTORY_ENTRY_CACHING) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING);
#if LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING
  using namespace lbal_fp_libcpp17;
  namespace fs = std::filesystem;

  EXPECT_TRUE(entry_has_exists<fs::directory_entry>::value);

  if constexpr (entry_has_exists<fs::directory_entry>::value) {
    fs::directory_entry e(fs::current_path());

    EXPECT_TRUE(e.exists());
    EXPECT_TRUE(e.is_directory());
    e.refresh();
    EXPECT_TRUE(e.exists());
  }
#endif
}

LBAL_FP_TEST(LIBCPP17, FILESYSTEM_PATHS_EXPANDED) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED);
#if LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED
  namespace fs = std::filesystem;

  //	`path` accepts `std::string_view` (P0392R0).
  EXPECT_TRUE((std::is_constructible_v<fs::path, std::string_view>));
#endif
}

LBAL_FP_TEST(LIBCPP17, FILESYSTEM_RELATIVE_PATHS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_FILESYSTEM_RELATIVE_PATHS);
#if LBAL_LIBCPP17_FILESYSTEM_RELATIVE_PATHS
  namespace fs = std::filesystem;

  EXPECT_EQ(
      fs::path("/a/b/c").lexically_relative("/a").generic_string(), "b/c"
  );
  EXPECT_EQ(fs::path("a/./b/../c").lexically_normal().generic_string(), "a/c");
  EXPECT_EQ(
      fs::path("/a/b").lexically_proximate("/x").generic_string(), "../a/b"
  );
#endif
}

LBAL_FP_TEST(LIBCPP17, GCD_LCM) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_GCD_LCM);
#if LBAL_LIBCPP17_GCD_LCM
  EXPECT_EQ(std::gcd(12, 18), 6);
  EXPECT_EQ(std::lcm(4, 6), 12);
#endif
}

LBAL_FP_TEST(LIBCPP17, HAS_UNIQUE_OBJECT_REPRESENTATIONS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS);
#if LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS
  using namespace lbal_fp_libcpp17;

  EXPECT_TRUE(std::has_unique_object_representations_v<int>);
  EXPECT_FALSE(std::has_unique_object_representations_v<Padded>);
#endif
}

LBAL_FP_TEST(LIBCPP17, HYPOT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_HYPOT);
#if LBAL_LIBCPP17_HYPOT
  EXPECT_DOUBLE_EQ(std::hypot(2.0, 3.0, 6.0), 7.0);
#endif
}

#if LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS
namespace lbal_fp_libcpp17 {

//	Each container is instantiated while `Node` is still incomplete.
struct Node {
  std::vector<Node> children;
  std::list<Node> siblings;
  std::forward_list<Node> cousins;
};

}  // namespace lbal_fp_libcpp17
#endif

LBAL_FP_TEST(LIBCPP17, INCOMPLETE_CONTAINER_ELEMENTS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS);
#if LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS
  lbal_fp_libcpp17::Node n;

  n.children.emplace_back();
  n.siblings.emplace_back();

  EXPECT_EQ(n.children.size(), 1u);
  EXPECT_EQ(n.siblings.size(), 1u);
#endif
}

LBAL_FP_TEST(LIBCPP17, INVOKE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_INVOKE);
#if LBAL_LIBCPP17_INVOKE
  struct S {
    int value = 3;

    int
    get() const {
      return value;
    }
  };

  S s;

  EXPECT_EQ(std::invoke(&S::get, s), 3);
  EXPECT_EQ(std::invoke(&S::value, s), 3);
  EXPECT_EQ(
      std::invoke(
          [](int x) {
            return x + 1;
          },
          1
      ),
      2
  );
#endif
}

LBAL_FP_TEST(LIBCPP17, IS_AGGREGATE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_IS_AGGREGATE);
#if LBAL_LIBCPP17_IS_AGGREGATE
  EXPECT_TRUE(std::is_aggregate_v<lbal_fp_libcpp17::Aggregate>);
  EXPECT_FALSE(std::is_aggregate_v<std::string>);
#endif
}

LBAL_FP_TEST(LIBCPP17, IS_INVOCABLE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_IS_INVOCABLE);
#if LBAL_LIBCPP17_IS_INVOCABLE
  EXPECT_TRUE((std::is_invocable_r_v<long, int (*)(int), int>));
  EXPECT_FALSE((std::is_invocable_v<int, int>));
  EXPECT_TRUE((std::is_nothrow_invocable_v<void (*)() noexcept>));
#endif
}

LBAL_FP_TEST(LIBCPP17, IS_SWAPPABLE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_IS_SWAPPABLE);
#if LBAL_LIBCPP17_IS_SWAPPABLE
  EXPECT_TRUE(std::is_swappable_v<int>);
  EXPECT_TRUE(std::is_nothrow_swappable_v<int>);
  EXPECT_FALSE(std::is_swappable_v<lbal_fp_libcpp17::Immovable>);
#endif
}

LBAL_FP_TEST(LIBCPP17, LAUNDER) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_LAUNDER);
#if LBAL_LIBCPP17_LAUNDER
  struct X {
    const int n;
  };

  alignas(X) unsigned char storage[sizeof(X)];
  X* first = ::new (storage) X{1};
  first->~X();
  ::new (storage) X{2};

  //	The new object can only be reached through a laundered pointer.
  EXPECT_EQ(std::launder(reinterpret_cast<X*>(storage))->n, 2);
#endif
}

LBAL_FP_TEST(LIBCPP17, LOGICAL_TRAITS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_LOGICAL_TRAITS);
#if LBAL_LIBCPP17_LOGICAL_TRAITS
  EXPECT_TRUE((std::conjunction_v<std::true_type, std::true_type>));
  EXPECT_TRUE((std::disjunction_v<std::false_type, std::true_type>));
  EXPECT_TRUE(std::negation_v<std::false_type>);
#endif
}

LBAL_FP_TEST(LIBCPP17, MAKE_FROM_TUPLE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_MAKE_FROM_TUPLE);
#if LBAL_LIBCPP17_MAKE_FROM_TUPLE
  struct P {
    P(int a_, double b_)
      : a(a_), b(b_) { }

    int a;
    double b;
  };

  auto p = std::make_from_tuple<P>(std::make_tuple(1, 2.0));

  EXPECT_EQ(p.a, 1);
  EXPECT_EQ(p.b, 2.0);
#endif
}

LBAL_FP_TEST(LIBCPP17, MAP_TRY_EMPLACE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_MAP_TRY_EMPLACE);
#if LBAL_LIBCPP17_MAP_TRY_EMPLACE
  std::map<int, std::string> m;

  EXPECT_TRUE(m.try_emplace(1, "a").second);
  EXPECT_FALSE(m.try_emplace(1, "b").second);
  EXPECT_EQ(m[1], "a");

  EXPECT_FALSE(m.insert_or_assign(1, "c").second);
  EXPECT_EQ(m[1], "c");
#endif
}

LBAL_FP_TEST(LIBCPP17, MATH_SPECIAL_FUNCTIONS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS);
#if LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS
  EXPECT_NEAR(std::legendre(2, 0.5), -0.125, 1e-12);
  EXPECT_NEAR(std::beta(1.0, 1.0), 1.0, 1e-12);
  EXPECT_NEAR(std::riemann_zeta(2.0), 1.6449340668482264, 1e-12);
#endif
}

LBAL_FP_TEST(LIBCPP17, MEMORY_RESOURCE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_MEMORY_RESOURCE);
#if LBAL_LIBCPP17_MEMORY_RESOURCE
  std::array<std::byte, 256> buffer;
  std::pmr::monotonic_buffer_resource resource(buffer.data(), buffer.size());
  std::pmr::vector<int> v(&resource);

  v.push_back(1);

  EXPECT_EQ(v.get_allocator().resource(), &resource);
  EXPECT_NE(std::pmr::get_default_resource(), nullptr);
#endif
}

LBAL_FP_TEST(LIBCPP17, NODE_EXTRACT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_NODE_EXTRACT);
#if LBAL_LIBCPP17_NODE_EXTRACT
  std::map<int, int> a{{1, 1}};
  std::map<int, int> b;

  auto node = a.extract(1);
  ASSERT_FALSE(node.empty());
  node.key() = 2;
  b.insert(std::move(node));

  EXPECT_EQ(a.size(), 0u);
  EXPECT_EQ(b.count(2), 1u);

  a.merge(b);
  EXPECT_EQ(a.count(2), 1u);
#endif
}

LBAL_FP_TEST(LIBCPP17, NONMEMBER_CONTAINER_ACCESS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS);
#if LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS
  int a[3] = {};
  std::vector<int> v;

  EXPECT_EQ(std::size(a), 3u);
  EXPECT_FALSE(std::empty(a));
  EXPECT_TRUE(std::empty(v));
  EXPECT_EQ(std::data(a), a);
#endif
}

LBAL_FP_TEST(LIBCPP17, NOT_FN) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_NOT_FN);
#if LBAL_LIBCPP17_NOT_FN
  auto is_odd = [](int x) {
    return x % 2 != 0;
  };

  EXPECT_TRUE(std::not_fn(is_odd)(2));
  EXPECT_FALSE(std::not_fn(is_odd)(3));
#endif
}

LBAL_FP_TEST(LIBCPP17, OPTIONAL) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_OPTIONAL);
#if LBAL_LIBCPP17_OPTIONAL
  std::optional<int> o;

  EXPECT_FALSE(o);
  EXPECT_EQ(o.value_or(7), 7);

  o = 3;
  EXPECT_EQ(*o, 3);
  EXPECT_EQ(o, std::optional<int>{3});
  EXPECT_EQ(std::nullopt, std::optional<int>{});
#endif
}

#if LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL
namespace lbal_fp_libcpp17 {

LBAL_FP_DETECT(optional_has_value, T, std::declval<T&>().has_value())

LBAL_FP_DETECT(
    optional_emplace_returns_ref,
    T,
    std::enable_if_t<
        std::is_same_v<decltype(std::declval<T&>().emplace(1)), int&>
    >()
)

}  // namespace lbal_fp_libcpp17
#endif

LBAL_FP_TEST(LIBCPP17, OPTIONAL_GREATER_EQUAL) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL);
#if LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL
  using namespace lbal_fp_libcpp17;

  //	The interface shared with `std::any` and `std::variant` (P0032R3).
  EXPECT_TRUE(optional_has_value<std::optional<int>>::value);
  EXPECT_TRUE(optional_emplace_returns_ref<std::optional<int>>::value);

  std::optional<int> o(std::in_place, 2);
  EXPECT_EQ(*o, 2);
#endif
}

#if LBAL_LIBCPP17_OPTIONAL_INTERFACE
namespace lbal_fp_libcpp17 {

LBAL_FP_DETECT(
    optional_mixed_compare,
    T,
    std::declval<const std::optional<T>&>()
        >= std::declval<const std::optional<long>&>()
)

}  // namespace lbal_fp_libcpp17
#endif

LBAL_FP_TEST(LIBCPP17, OPTIONAL_INTERFACE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_OPTIONAL_INTERFACE);
#if LBAL_LIBCPP17_OPTIONAL_INTERFACE
  using namespace lbal_fp_libcpp17;

  //	Comparisons between different `optional` specializations (P0307R2).
  EXPECT_TRUE(optional_mixed_compare<int>::value);

  if constexpr (optional_mixed_compare<int>::value) {
    EXPECT_TRUE(std::optional<int>{2} >= std::optional<long>{1L});
    EXPECT_TRUE(std::optional<int>{1} == 1L);
  }
#endif
}

LBAL_FP_TEST(LIBCPP17, PARALLEL_ALGORITHM) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_PARALLEL_ALGORITHM);
#if LBAL_LIBCPP17_PARALLEL_ALGORITHM
  std::vector<int> v(1000, 1);

  EXPECT_EQ(std::reduce(std::execution::par, v.begin(), v.end()), 1000);
  EXPECT_EQ(std::count(std::execution::par_unseq, v.begin(), v.end(), 1), 1000);
#endif
}

LBAL_FP_TEST(LIBCPP17, RAW_MEMORY_ALGORITHMS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS);
#if LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS
  alignas(int) unsigned char storage[sizeof(int) * 2];
  int* p = reinterpret_cast<int*>(storage);

  std::uninitialized_value_construct_n(p, 2);
  EXPECT_EQ(p[0], 0);
  EXPECT_EQ(p[1], 0);
  std::destroy_n(p, 2);

  std::uninitialized_fill_n(p, 2, 5);
  EXPECT_EQ(p[1], 5);
  std::destroy(p, p + 2);
#endif
}

LBAL_FP_TEST(LIBCPP17, SAMPLE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_SAMPLE);
#if LBAL_LIBCPP17_SAMPLE
  std::vector<int> in{1, 2, 3, 4};
  std::vector<int> out;

  std::sample(
      in.begin(), in.end(), std::back_inserter(out), 2, std::mt19937{42}
  );

  EXPECT_EQ(out.size(), 2u);
  EXPECT_TRUE(std::is_sorted(out.begin(), out.end()));
#endif
}

LBAL_FP_TEST(LIBCPP17, SCOPED_LOCK) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_SCOPED_LOCK);
#if LBAL_LIBCPP17_SCOPED_LOCK
  std::mutex a;
  std::mutex b;
  bool other_got_a = true;

  {
    std::scoped_lock lock(a, b);
    std::thread([&] {
      other_got_a = a.try_lock();
      if (other_got_a)
        a.unlock();
    }).join();
  }

  EXPECT_FALSE(other_got_a);
  EXPECT_TRUE(b.try_lock());
  b.unlock();
#endif
}

LBAL_FP_TEST(LIBCPP17, SHARED_MUTEX) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_SHARED_MUTEX);
#if LBAL_LIBCPP17_SHARED_MUTEX
  std::shared_mutex m;
  bool other_shared = false;
  bool other_exclusive = true;

  m.lock_shared();
  std::thread([&] {
    other_shared = m.try_lock_shared();
    if (other_shared)
      m.unlock_shared();
    other_exclusive = m.try_lock();
    if (other_exclusive)
      m.unlock();
  }).join();
  m.unlock_shared();

  EXPECT_TRUE(other_shared);
  EXPECT_FALSE(other_exclusive);
#endif
}

LBAL_FP_TEST(LIBCPP17, SHARED_PTR_ARRAYS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_SHARED_PTR_ARRAYS);
#if LBAL_LIBCPP17_SHARED_PTR_ARRAYS
  std::shared_ptr<int[]> p(new int[3]{1, 2, 3});

  EXPECT_EQ(p[1], 2);
#endif
}

LBAL_FP_TEST(LIBCPP17, SHARED_PTR_WEAK_TYPE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE);
#if LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE
  using namespace lbal_fp_libcpp17;

  EXPECT_TRUE(has_weak_type<int>::value);

  if constexpr (has_weak_type<int>::value) {
    EXPECT_TRUE((
        std::is_same_v<std::shared_ptr<int>::weak_type, std::weak_ptr<int>>
    ));
  }
#endif
}

LBAL_FP_TEST(LIBCPP17, STANDARDIZATION_OF_PARALLELISM_TS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS);
#if LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS
  std::vector<int> v{1, 2, 3, 4};
  std::vector<int> scan(4);

  EXPECT_EQ(
      std::transform_reduce(
          std::execution::par_unseq,
          v.begin(),
          v.end(),
          0,
          std::plus<>{},
          [](int x) {
            return x * x;
          }
      ),
      30
  );

  std::exclusive_scan(std::execution::par, v.begin(), v.end(), scan.begin(), 0);
  EXPECT_EQ(scan, (std::vector<int>{0, 1, 3, 6}));

  int visited = 0;
  std::for_each_n(std::execution::seq, v.begin(), 2, [&](int) {
    ++visited;
  });
  EXPECT_EQ(visited, 2);
#endif
}

LBAL_FP_TEST(LIBCPP17, STRING_VIEW) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_STRING_VIEW);
#if LBAL_LIBCPP17_STRING_VIEW
  std::string_view sv = "hello";

  EXPECT_EQ(sv.substr(1, 3), "ell");
  EXPECT_EQ(sv.find('l'), 2u);
  EXPECT_EQ(sv.rfind('l'), 3u);
#endif
}

LBAL_FP_TEST(LIBCPP17, STRING_VIEW_INTERFACE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_STRING_VIEW_INTERFACE);
#if LBAL_LIBCPP17_STRING_VIEW_INTERFACE
  //	`std::string` converts to and accepts `std::string_view` (P0254R2).
  std::string s = "abc";
  std::string_view sv = s;
  std::string copy(sv);

  copy += sv;

  EXPECT_EQ(copy, "abcabc");
  EXPECT_EQ(s.compare(sv), 0);
  EXPECT_EQ(s.find(std::string_view("c")), 2u);
#endif
}

#if LBAL_LIBCPP17_TO_CHARS || LBAL_LIBCPP17_TO_CHARS_FP
namespace lbal_fp_libcpp17 {

//	Without floating-point overloads, a `double` argument is ambiguous among
//	the integer overloads rather than a hard error.
LBAL_FP_DETECT(
    to_chars_accepts,
    T,
    std::to_chars(
        std::declval<char*>(), std::declval<char*>(), std::declval<T>()
    )
)

LBAL_FP_DETECT(
    from_chars_accepts,
    T,
    std::from_chars(
        std::declval<const char*>(),
        std::declval<const char*>(),
        std::declval<T&>()
    )
)

}  // namespace lbal_fp_libcpp17
#endif

LBAL_FP_TEST(LIBCPP17, TO_CHARS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_TO_CHARS);
#if LBAL_LIBCPP17_TO_CHARS
  using namespace lbal_fp_libcpp17;

  //	The full feature includes floating-point support, long double included.
  EXPECT_TRUE(to_chars_accepts<int>::value);
  EXPECT_TRUE(to_chars_accepts<double>::value);
  EXPECT_TRUE(from_chars_accepts<double>::value);
  EXPECT_TRUE(to_chars_accepts<long double>::value);
  EXPECT_TRUE(from_chars_accepts<long double>::value);
#endif
}

LBAL_FP_TEST(LIBCPP17, TO_CHARS_FP) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_TO_CHARS_FP);
#if LBAL_LIBCPP17_TO_CHARS_FP
  using namespace lbal_fp_libcpp17;

  EXPECT_TRUE(to_chars_accepts<double>::value);
  EXPECT_TRUE(from_chars_accepts<double>::value);

  if constexpr (
      to_chars_accepts<double>::value && from_chars_accepts<double>::value
  )
  {
    char buffer[32];
    auto [end, ec] = std::to_chars(buffer, buffer + sizeof(buffer), 1.5);
    ASSERT_EQ(ec, std::errc{});
    EXPECT_EQ(std::string(buffer, end), "1.5");

    double parsed = 0.0;
    std::from_chars(buffer, end, parsed);
    EXPECT_EQ(parsed, 1.5);
  }
#endif
}

LBAL_FP_TEST(LIBCPP17, TO_CHARS_INTEGER) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_TO_CHARS_INTEGER);
#if LBAL_LIBCPP17_TO_CHARS_INTEGER
  char buffer[16];
  auto [end, ec] = std::to_chars(buffer, buffer + sizeof(buffer), 255, 16);
  ASSERT_EQ(ec, std::errc{});
  EXPECT_EQ(std::string(buffer, end), "ff");

  int parsed = 0;
  std::from_chars(buffer, end, parsed, 16);
  EXPECT_EQ(parsed, 255);
#endif
}

LBAL_FP_TEST(LIBCPP17, TRANSPARENT_OPERATORS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_TRANSPARENT_OPERATORS);
#if LBAL_LIBCPP17_TRANSPARENT_OPERATORS
  //	`std::owner_less<>` compares `shared_ptr` and `weak_ptr` (P0074R0).
  auto sp = std::make_shared<int>(1);
  std::weak_ptr<int> wp = sp;
  std::owner_less<> less;

  EXPECT_FALSE(less(sp, wp));
  EXPECT_FALSE(less(wp, sp));
#endif
}

LBAL_FP_TEST(LIBCPP17, TYPE_TRAIT_VARIABLE_TEMPLATES) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES);
#if LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES
  EXPECT_TRUE(std::is_integral_v<int>);
  EXPECT_EQ(std::extent_v<int[3]>, 3u);
  EXPECT_TRUE((std::is_same_v<int, int>));
#endif
}

#if LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS && LBAL_CPP03_EXCEPTIONS
namespace lbal_fp_libcpp17 {

struct CountOnUnwind {
  int* seen;

  ~CountOnUnwind() { *seen = std::uncaught_exceptions(); }
};

}  // namespace lbal_fp_libcpp17
#endif

LBAL_FP_TEST(LIBCPP17, UNCAUGHT_EXCEPTIONS) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS);
#if LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS
  EXPECT_EQ(std::uncaught_exceptions(), 0);

  #if LBAL_CPP03_EXCEPTIONS
  int seen = -1;

  try {
    lbal_fp_libcpp17::CountOnUnwind guard{&seen};
    throw 1;
  } catch (int) {
  }

  EXPECT_EQ(seen, 1);
  #endif
#endif
}

LBAL_FP_TEST(LIBCPP17, UNORDERED_MAP_TRY_EMPLACE) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE);
#if LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE
  std::unordered_map<int, std::string> m;

  EXPECT_TRUE(m.try_emplace(1, "a").second);
  EXPECT_FALSE(m.try_emplace(1, "b").second);
  EXPECT_EQ(m[1], "a");

  EXPECT_FALSE(m.insert_or_assign(1, "c").second);
  EXPECT_EQ(m[1], "c");
#endif
}

LBAL_FP_TEST(LIBCPP17, VARIANT) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_VARIANT);
#if LBAL_LIBCPP17_VARIANT
  std::variant<int, std::string> v = 1;

  ASSERT_NE(std::get_if<int>(&v), nullptr);
  EXPECT_EQ(*std::get_if<int>(&v), 1);

  v = std::string("x");
  EXPECT_EQ(v.index(), 1u);
  EXPECT_EQ(
      std::visit(
          [](const auto& x) {
            return sizeof(x) > 0;
          },
          v
      ),
      true
  );
#endif
}

LBAL_FP_TEST(LIBCPP17, VOID_T) {
  LBAL_FP_REQUIRE(LBAL_LIBCPP17_VOID_T);
#if LBAL_LIBCPP17_VOID_T
  EXPECT_TRUE((std::is_same_v<std::void_t<int, char>, void>));
#endif
}
