/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “IMPL_COROUTINE_RETURN.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP2D_IMPL_COROUTINE_RETURN`, from
  P3950R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP2D_IMPL_COROUTINE_RETURN && __has_include(<coroutine>)
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
    return_value(int) { }

    void
    return_void() { }

    void
    unhandled_exception() { }
  };
};

//	A promise can declare both `return_value` and `return_void` (P3950R1).
inline Task
with_value() {
  co_return 1;
}

inline Task
without_value() {
  co_return;
}

}  // namespace lbal_fp
#endif
