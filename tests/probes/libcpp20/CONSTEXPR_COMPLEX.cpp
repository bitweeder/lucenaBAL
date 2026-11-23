/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “CONSTEXPR_COMPLEX.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP20_CONSTEXPR_COMPLEX`, from
  P0415R1. It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP20_CONSTEXPR_COMPLEX
  //	std
  #include <complex>

namespace lbal_fp {

constexpr std::complex<double>
product() {
  std::complex<double> c{1.0, 2.0};
  c *= std::complex<double>{3.0, 4.0};
  return c;
}

static_assert(product().real() == -5.0 && product().imag() == 10.0);
static_assert(std::norm(std::complex<double>{3.0, 4.0}) == 25.0);

}  // namespace lbal_fp
#endif
