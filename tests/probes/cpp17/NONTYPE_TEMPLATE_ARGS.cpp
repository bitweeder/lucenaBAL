/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “NONTYPE_TEMPLATE_ARGS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_NONTYPE_TEMPLATE_ARGS`, from
  N4268. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_NONTYPE_TEMPLATE_ARGS
namespace lbal_fp {

template <int* p>
struct A { };

inline int n;

constexpr int*
address() {
  return &n;
}

//	Any converted constant expression is allowed (N4268).
using B = A<address()>;

}  // namespace lbal_fp
#endif
