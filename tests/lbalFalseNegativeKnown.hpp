/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFalseNegativeKnown.hpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Known absences for the false-negative tests: tokens that are `0` on purpose
  although their probe compiles, because the implementation itself says the
  feature is incomplete and the probe can’t reach the missing part. Their
  tests are skipped, with the reason given here.

  Add a token only when the implementer documents the gap (a status page or
  release notes); otherwise, tighten the probe or fix the token.

------------------------------------------------------------------------------*/

#pragma once

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

//	std
#include <string_view>

namespace lbal_fn {

//	The reason `token` is a known absence, or null.
inline const char*
known_absent(std::string_view token) {
#if LBAL_TARGET_COMPILER_CLANG
  //	Covers Apple clang too. clang 18+ has class-type and floating-point
  //	non-type template arguments, but lists P1907R1 as partial: references to
  //	instantiation-dependent objects and subobjects aren’t fully supported.
  //	`LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FLOATS` reports the usable part.
  if (token == "LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FIXES") {
    return "clang lists P1907R1 as only partly implemented; see "
           "LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FLOATS";
  }
#endif

  static_cast<void>(token);
  return nullptr;
}

}  // namespace lbal_fn
