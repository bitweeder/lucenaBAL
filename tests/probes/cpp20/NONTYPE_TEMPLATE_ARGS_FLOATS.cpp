/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “NONTYPE_TEMPLATE_ARGS_FLOATS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FLOATS`,
  from P1907R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FLOATS
namespace lbal_fp {

template <double D>
constexpr double
identity() {
  return D;
}

static_assert(identity<1.5>() == 1.5);

}  // namespace lbal_fp
#endif
