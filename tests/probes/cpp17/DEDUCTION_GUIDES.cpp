/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “DEDUCTION_GUIDES.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP17_DEDUCTION_GUIDES`, from P0091R3.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP17_DEDUCTION_GUIDES
  //	std
  #include <type_traits>

namespace lbal_fp {

template <class T>
struct Wrap {
  Wrap(T x)
    : value(x) { }

  T value;
};

template <class T>
struct Box {
  T value;
};

template <class T>
Box(T) -> Box<T>;

static_assert(std::is_same_v<decltype(Wrap(1)), Wrap<int>>);
static_assert(std::is_same_v<decltype(Box{1}), Box<int>>);

}  // namespace lbal_fp
#endif
