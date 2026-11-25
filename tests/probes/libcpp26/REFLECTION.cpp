/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “REFLECTION.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_LIBCPP26_REFLECTION`, from P3560R2. It
  only needs to compile; see `lbalFalsePositiveTest.cpp`.

  SEEME: written from the paper; not yet compiled against a library that
  reports this feature.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_LIBCPP26_REFLECTION
  //	std
  #include <meta>

namespace lbal_fp {

struct S {
  int a;
  int b;
};

static_assert(std::meta::is_type(^^int));
static_assert(
    std::meta::nonstatic_data_members_of(
        ^^S, std::meta::access_context::current()
    )
        .size()
    == 2
);

}  // namespace lbal_fp
#endif
