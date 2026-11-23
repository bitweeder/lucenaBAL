/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_DYNAMIC_POLYMORPHISM.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM`,
  from P1002R1 and P1327R1. It only needs to compile; see
  `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM && LBAL_CPP03_RTTI
  //	std
  #include <typeinfo>

namespace lbal_fp {

struct Base {
  virtual ~Base() = default;
};

struct Derived : Base { };

constexpr bool
check() {
  Derived d;
  Base& b = d;
  (void)typeid(b);
  return dynamic_cast<Derived*>(&b) != nullptr;
}

static_assert(check());

}  // namespace lbal_fp
#endif
