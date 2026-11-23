/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “DEDUCTION_GUIDES_FROM_INHERITED_CONSTRUCTORS.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for
  `LBAL_CPP23_DEDUCTION_GUIDES_FROM_INHERITED_CONSTRUCTORS`, from P2582R1. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP23_DEDUCTION_GUIDES_FROM_INHERITED_CONSTRUCTORS
  //	std
  #include <type_traits>

namespace lbal_fp {

template <class T>
struct Base {
  Base(T) { }
};

template <class T>
struct Derived : Base<T> {
  using Base<T>::Base;
};

static_assert(std::is_same_v<decltype(Derived(1)), Derived<int>>);

}  // namespace lbal_fp
#endif
