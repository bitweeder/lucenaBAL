/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_EXCEPTION_TYPES.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP26_CONSTEXPR_EXCEPTION_TYPES`, from
  P3068R6. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  It also needs the language part, `LBAL_CPP26_CONSTEXPR_EXCEPTIONS`; P3378R2’s
  `<stdexcept>` types are `LBAL_LIBCPP26_CONSTEXPR_EXCEPTIONS`.

  SEEME: written from the paper; not yet compiled against a library that
  reports this feature.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_CONSTEXPR_EXCEPTION_TYPES && LBAL_CPP03_EXCEPTIONS
  //	std
  #include <exception>
  #include <new>
  #include <typeinfo>

namespace lbal_fp {

constexpr bool
caught() {
  try {
    throw std::bad_alloc();
  } catch (const std::exception& e) {
    return e.what() != nullptr;
  }
  return false;
}

constexpr bool
rethrown() {
  std::exception_ptr p = std::make_exception_ptr(std::bad_cast());
  try {
    std::rethrow_exception(p);
  } catch (const std::bad_cast&) {
    return true;
  }
  return false;
}

static_assert(caught());
static_assert(rethrown());

}  // namespace lbal_fp
#endif
