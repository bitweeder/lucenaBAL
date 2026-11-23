/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “USING_ENUM.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_USING_ENUM`, from P1099R5. It only
  needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_USING_ENUM
namespace lbal_fp {

enum class Color {
  red,
  green,
};

constexpr int
code(Color c) {
  switch (c) {
    using enum Color;
    case red:
      return 1;
    case green:
      return 2;
  }
  return 0;
}

static_assert(code(Color::green) == 2);

}  // namespace lbal_fp
#endif
