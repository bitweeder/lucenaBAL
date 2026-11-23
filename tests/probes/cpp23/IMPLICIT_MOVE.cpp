/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “IMPLICIT_MOVE.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP23_IMPLICIT_MOVE`, from P2266R3. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP23_IMPLICIT_MOVE
namespace lbal_fp {

struct MoveOnly {
  MoveOnly() = default;
  MoveOnly(MoveOnly&&) = default;
  MoveOnly(const MoveOnly&) = delete;
};

//	`x` is an xvalue in the return statement (P2266R3).
inline MoveOnly&&
forward_it(MoveOnly&& x) {
  return x;
}

}  // namespace lbal_fp
#endif
