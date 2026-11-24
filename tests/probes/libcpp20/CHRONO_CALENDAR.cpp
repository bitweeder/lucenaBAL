/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CHRONO_CALENDAR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP20_CHRONO_CALENDAR`, from
  P0355R7. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  The calendar types alone are `LBAL_LIBCPP20_CHRONO_CALENDAR_TYPES`. This
  checks the rest of the paper: time zones, the extra clocks with
  `clock_cast`, and parsing. libc++ lacks `parse` and `clock_cast`, and a
  missing name is a hard error, which is why this isn’t a gtest probe.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP20_CHRONO_CALENDAR
  //	std
  #include <chrono>
  #include <istream>
  #include <string_view>
  #include <type_traits>

namespace lbal_fp {

using namespace std::chrono;

//	Time zones
static_assert(
    std::is_same_v<decltype(locate_zone(std::string_view{})), const time_zone*>
);
static_assert(std::is_same_v<decltype(get_tzdb()), const tzdb&>);

using Zoned = zoned_time<seconds>;

//	Clocks
static_assert(
    std::is_same_v<decltype(clock_cast<utc_clock>(sys_seconds{})), utc_seconds>
);
static_assert(
    std::is_same_v<decltype(clock_cast<tai_clock>(sys_seconds{})), tai_seconds>
);
static_assert(
    std::is_same_v<decltype(clock_cast<gps_clock>(sys_seconds{})), gps_seconds>
);

//	Parsing
inline void
read(std::istream& in) {
  sys_seconds when;
  in >> parse("%F %T", when);
}

}  // namespace lbal_fp
#endif
