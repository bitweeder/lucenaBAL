/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “REFERENCE_FROM_TEMPORARY.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY`, from
  P2255R2. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  The traits alone are `LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY_TRAITS`. The
  full feature also deletes the `pair` and `tuple` constructors that would
  bind a reference member to a temporary, and makes `INVOKE<R>` reject a
  reference result that would. libc++ has only the traits, and libstdc++ 13
  lacked the `tuple` changes. The traits are names older libraries lack, so a
  false claim is a hard error, which is why this isn’t a gtest probe.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP23_REFERENCE_FROM_TEMPORARY
  //	std
  #include <functional>
  #include <tuple>
  #include <type_traits>
  #include <utility>

namespace lbal_fp {

//	The traits
static_assert(std::reference_constructs_from_temporary_v<const int&, long>);
static_assert(!std::reference_constructs_from_temporary_v<const int&, int&>);
static_assert(std::reference_converts_from_temporary_v<const int&, long>);

//	`pair` and `tuple`
static_assert(!std::is_constructible_v<std::pair<const int&, int>, long, int>);
static_assert(
    std::is_constructible_v<std::pair<const int&, int>, const int&, int>
);
static_assert(!std::is_constructible_v<std::tuple<const int&>, long>);
static_assert(std::is_constructible_v<std::tuple<const int&>, const int&>);

//	`INVOKE<R>`
static_assert(!std::is_invocable_r_v<const int&, long (*)()>);
static_assert(std::is_invocable_r_v<const int&, const int& (*)()>);

}  // namespace lbal_fp
#endif
