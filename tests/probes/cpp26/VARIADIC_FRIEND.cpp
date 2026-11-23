/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “VARIADIC_FRIEND.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP26_VARIADIC_FRIEND`, from P2893R3. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP26_VARIADIC_FRIEND
namespace lbal_fp {

template <class... Ts>
class Passkey {
  friend Ts...;

  Passkey() { }
};

struct A;
struct B;

using Key = Passkey<A, B>;

}  // namespace lbal_fp
#endif
