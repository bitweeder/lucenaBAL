/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “EXCEPTION_PTR_CAST_CONSTEXPR.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP26_EXCEPTION_PTR_CAST_CONSTEXPR`,
  from P3748R0. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: written from the paper; not yet compiled against a library that
  reports this feature.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_EXCEPTION_PTR_CAST_CONSTEXPR && LBAL_CPP03_EXCEPTIONS
  //	std
  #include <exception>
  #include <stdexcept>

namespace lbal_fp {

constexpr bool
cast() {
  auto p = std::make_exception_ptr(std::runtime_error("x"));
  return std::exception_ptr_cast<std::runtime_error>(p) != nullptr;
}

static_assert(cast());

}  // namespace lbal_fp
#endif
