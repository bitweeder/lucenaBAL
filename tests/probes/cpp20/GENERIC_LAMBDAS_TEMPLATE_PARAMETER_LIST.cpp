/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for
  `LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST`, from P0428R2. It only
  needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST
namespace lbal_fp {

constexpr auto size_of = []<class T>(T) {
  return sizeof(T);
};

static_assert(size_of(1) == sizeof(int));

}  // namespace lbal_fp
#endif
