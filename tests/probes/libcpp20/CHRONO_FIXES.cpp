/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CHRONO_FIXES.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP20_CHRONO_FIXES`, from P1466R3.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  `__cpp_lib_chrono >= 201907L` includes P0355R7, so this repeats the time
  zone and parsing checks from `CHRONO_CALENDAR.cpp`, then adds P1466R3’s
  changes. libc++ lacks `parse`, and a missing name is a hard error, which is
  why this isn’t a gtest probe.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP20_CHRONO_FIXES
  //	std
  #include <chrono>
  #include <istream>
  #include <string_view>
  #include <type_traits>

namespace lbal_fp {

using namespace std::chrono;

//	P0355R7
static_assert(
    std::is_same_v<decltype(locate_zone(std::string_view{})), const time_zone*>
);

inline void
read(std::istream& in) {
  sys_seconds when;
  in >> parse("%F %T", when);
}

//	P1466R3: `is_clock`, `hh_mm_ss` (renamed from `time_of_day`), and
//	`zoned_traits` with the `zoned_time` deduction guides.
static_assert(is_clock_v<system_clock> && !is_clock_v<int>);
static_assert(hh_mm_ss<seconds>{seconds{3661}}.minutes() == minutes{1});
static_assert(std::is_same_v<
    decltype(zoned_traits<const time_zone*>::default_zone()),
    const time_zone*
>);

inline void
deduce() {
  zoned_time zoned{"UTC", sys_seconds{}};
  static_cast<void>(zoned);
}

}  // namespace lbal_fp
#endif
