/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFalsePositiveTest-cpp14.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Soft false-positive probes for C++14 language tokens. Every other C++14
  token has a hard probe in `probes/cpp14/`.

------------------------------------------------------------------------------*/

#if LBAL_CPP14_SIZED_DEALLOCATION
  //	std
  #include <atomic>
  #include <cstddef>
  #include <cstdlib>
  #include <new>

namespace lbal_fp_cpp14 {

inline std::atomic<bool> armed{false};
inline std::atomic<std::size_t> sized_size{0};

struct Payload {
  char bytes[24];
};

}  // namespace lbal_fp_cpp14

//	SEEME
//	Replacing the global allocation functions affects the whole test binary,
//	so all of them are replaced together and only the sized form records
//	anything, and only while armed.
void*
operator new (std::size_t size) {
  if (void* p = std::malloc(size ? size : 1))
    return p;
  #if LBAL_CPP03_EXCEPTIONS
  throw std::bad_alloc();
  #else
  std::abort();
  #endif
}

void
operator delete (void* p) noexcept {
  std::free(p);
}

void
operator delete (void* p, std::size_t size) noexcept {
  if (lbal_fp_cpp14::armed)
    lbal_fp_cpp14::sized_size = size;
  std::free(p);
}
#endif

LBAL_FP_TEST(CPP14, SIZED_DEALLOCATION) {
  LBAL_FP_REQUIRE(LBAL_CPP14_SIZED_DEALLOCATION);
#if LBAL_CPP14_SIZED_DEALLOCATION
  using namespace lbal_fp_cpp14;

  //	`volatile` stops the optimizer from eliding the allocation pair.
  Payload* volatile p = new Payload;
  armed = true;
  delete p;
  armed = false;

  //	The compiler must call the sized `operator delete` for a complete type.
  EXPECT_EQ(sized_size.load(), sizeof(Payload));
#endif
}
