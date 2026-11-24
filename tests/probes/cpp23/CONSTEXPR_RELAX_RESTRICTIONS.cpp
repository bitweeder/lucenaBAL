/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_RELAX_RESTRICTIONS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP23_CONSTEXPR_RELAX_RESTRICTIONS`,
  from P2448R2. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP23_CONSTEXPR_RELAX_RESTRICTIONS
namespace lbal_fp {

inline int
runtime_only() {
  return 0;
}

//	A `constexpr` function that can never be constant-evaluated is no longer
//	ill-formed (P2448R2).
constexpr int
never_constant() {
  return runtime_only();
}

//	That rule needed no diagnostic in C++20, so compilers accept it either
//	way. P2448R2 also lifts the requirement that a `constexpr` function’s
//	parameter and return types be literal, which C++20 does diagnose.
struct NonLiteral {
  NonLiteral() { }

  ~NonLiteral() { }
};

constexpr void
take(NonLiteral) { }

constexpr NonLiteral
make() {
  return {};
}

}  // namespace lbal_fp
#endif
