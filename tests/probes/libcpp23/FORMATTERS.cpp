/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “FORMATTERS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP23_FORMATTERS`, from P2693R1. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

  Formatting `thread::id` alone is `LBAL_LIBCPP23_FORMATTERS_THREAD_ID`. The
  full feature also formats `stacktrace` and `stacktrace_entry`; libc++ has
  no `<stacktrace>`, and a missing header is a hard error, which is why this
  isn’t a gtest probe.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP23_FORMATTERS
  //	std
  #include <format>
  #include <stacktrace>
  #include <thread>

namespace lbal_fp {

static_assert(std::formattable<std::thread::id, char>);
static_assert(std::formattable<std::stacktrace, char>);
static_assert(std::formattable<std::stacktrace_entry, char>);

}  // namespace lbal_fp
#endif
