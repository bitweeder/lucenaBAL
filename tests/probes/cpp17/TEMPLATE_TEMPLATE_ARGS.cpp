/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “TEMPLATE_TEMPLATE_ARGS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS`, from
  P0522R0. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS
namespace lbal_fp {

template <template <class> class TT>
struct X { };

template <class T, class U = T>
struct Y { };

//	`Y` matches `template <class> class` thanks to its default argument.
using Z = X<Y>;

}  // namespace lbal_fp
#endif
