/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFalsePositiveTest.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Optional tests for false-positive feature tokens; built only when the CMake
  option `LBAL_BUILD_FALSE_POSITIVE_TESTS` is `ON`.

  A false positive is a token that claims a feature is available when it isn’t,
  or isn’t usable as specified. The probes come in two kinds:

  - Soft probes live in `fragments/lbalFalsePositiveTest-*.inc` and are
    included here. They check values and behavior at run time, or detect
    members and overloads with `LBAL_FP_DETECT`, so a false positive is reported
    as a failed test and every probe is reported in a single run.
  - Hard probes live in `probes/<std>/`, one token per file. They exercise
    syntax that can only fail to compile, and are built as a separate object
    library that isn’t linked into this test, so a hard false positive doesn’t
    stop these tests from building. Build with keep-going (e.g., `-k 0` with
    Ninja) to see every hard false positive at once.

------------------------------------------------------------------------------*/

#include "lbalFalsePositiveTest.hpp"

#include "fragments/lbalFalsePositiveTest-cpp03.inc"
#include "fragments/lbalFalsePositiveTest-cpp11.inc"
#include "fragments/lbalFalsePositiveTest-cpp14.inc"
#include "fragments/lbalFalsePositiveTest-cpp17.inc"
#include "fragments/lbalFalsePositiveTest-cpp20.inc"
#include "fragments/lbalFalsePositiveTest-cpp23.inc"
#include "fragments/lbalFalsePositiveTest-cpp26.inc"
#include "fragments/lbalFalsePositiveTest-cpp2d.inc"
#include "fragments/lbalFalsePositiveTest-libcpp14.inc"
#include "fragments/lbalFalsePositiveTest-libcpp17.inc"
#include "fragments/lbalFalsePositiveTest-libcpp20.inc"
#include "fragments/lbalFalsePositiveTest-libcpp23.inc"
#include "fragments/lbalFalsePositiveTest-libcpp26.inc"
#include "fragments/lbalFalsePositiveTest-libcpp2d.inc"
