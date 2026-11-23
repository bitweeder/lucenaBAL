/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONTRACTS_VIRTUAL.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP2D_CONTRACTS_VIRTUAL`, from P3097R3.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: written from P3097R3; not yet compiled by any compiler available
  here.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP2D_CONTRACTS_VIRTUAL
namespace lbal_fp {

struct Base {
  virtual int
  f(int x) pre(x > 0) {
    return x;
  }

  virtual ~Base() = default;
};

struct Derived : Base {
  int
  f(int x) pre(x > 1) override {
    return x;
  }
};

}  // namespace lbal_fp
#endif
