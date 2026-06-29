/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalKnownVersions.hpp”
  Copyright © 2019-2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Named C++ standard releases so we can make semantic comparisons. Note that
  while these values usually correlate with `__cplusplus`, some compilers,
  such as MSVC, have separate variables (e.g., `_MSVC_LANG`) we must reference
  to figure out exactly what dialect is in use. The consistent intent with
  these values is that any value greater than an earlier value indicates
  support for _at least_ the previous standard.

------------------------------------------------------------------------------*/

#pragma once

//	C++ Standards
#define LBAL_CPP11_VERSION 201103L
#define LBAL_CPP14_VERSION 201402L
#define LBAL_CPP17_VERSION 201703L
#define LBAL_CPP20_VERSION 202002L
#define LBAL_CPP23_VERSION 202302L
#define LBAL_CPP26_VERSION 202603L
