/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “IMPL_COROUTINE.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_IMPL_COROUTINE`, from LWG3393 and
  P0912R5. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_IMPL_COROUTINE && __has_include(<coroutine>)
  //	std
  #include <coroutine>

namespace lbal_fp {

struct Task {
  struct promise_type {
    Task
    get_return_object() {
      return {};
    }

    std::suspend_never
    initial_suspend() noexcept {
      return {};
    }

    std::suspend_never
    final_suspend() noexcept {
      return {};
    }

    void
    return_void() { }

    void
    unhandled_exception() { }
  };
};

inline Task
run() {
  co_return;
}

}  // namespace lbal_fp
#endif
