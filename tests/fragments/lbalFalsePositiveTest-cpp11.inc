/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFalsePositiveTest-cpp11.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Soft false-positive probes for C++11 language tokens. Every other C++11
  token has a hard probe in `probes/cpp11/`.

------------------------------------------------------------------------------*/

#if LBAL_CPP11_THREADSAFE_STATIC_INIT
  //	std
  #include <atomic>
  #include <chrono>
  #include <thread>
  #include <vector>

namespace lbal_fp_cpp11 {

inline std::atomic<int> constructions{0};

struct Slow {
  Slow() {
    ++constructions;
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    ready = true;
  }

  bool ready = false;
};

inline bool
touch() {
  static Slow s;
  return s.ready;
}

}  // namespace lbal_fp_cpp11
#endif

LBAL_FP_TEST(CPP11, THREADSAFE_STATIC_INIT) {
  LBAL_FP_REQUIRE(LBAL_CPP11_THREADSAFE_STATIC_INIT);
#if LBAL_CPP11_THREADSAFE_STATIC_INIT
  using namespace lbal_fp_cpp11;

  std::atomic<int> not_ready{0};
  std::vector<std::thread> threads;

  for (int i = 0; i < 8; ++i) {
    threads.emplace_back([&not_ready] {
      if (!touch())
        ++not_ready;
    });
  }

  for (auto& t : threads)
    t.join();

  EXPECT_EQ(constructions.load(), 1);
  EXPECT_EQ(not_ready.load(), 0);
#endif
}
