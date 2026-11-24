/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “IS_LAYOUT_COMPATIBLE.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE`, from
  P0466R5. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  The paper adds both `is_layout_compatible` and `is_corresponding_member`.
  libstdc++ only claims the feature when the compiler has the builtins for
  both, and clang only has the first, so this checks both; a missing name is
  a hard error, which is why this isn’t a gtest probe.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP20_IS_LAYOUT_COMPATIBLE
  //	std
  #include <type_traits>

namespace lbal_fp {

struct A {
  int x;
  int y;
};

struct B {
  int x;
  int y;
};

static_assert(std::is_layout_compatible_v<A, B>);
static_assert(!std::is_layout_compatible_v<int, long long>);
static_assert(std::is_corresponding_member(&A::y, &B::y));
static_assert(!std::is_corresponding_member(&A::x, &B::y));

}  // namespace lbal_fp
#endif
