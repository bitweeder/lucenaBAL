/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “NONTYPE_TEMPLATE_PARAMETER_AUTO.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO`,
  from P0127R2. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO
namespace lbal_fp {

template <auto V>
struct Constant {
  static constexpr auto value = V;
};

static_assert(Constant<'a'>::value == 'a');
static_assert(Constant<3>::value == 3);

}  // namespace lbal_fp
#endif
