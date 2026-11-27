/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalVisibilityLib.hpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Interface of the shared library used by the visibility tests. It checks the
  `LBAL_VIS_OVERLOADABLE_FUNC_*` scheme: a function the library exports that
  a client may replace with its own definition. On Windows, the import side
  is left undecorated, as libc++ does, because defining a function declared
  `__declspec(dllimport)` is an error. `lbal_vis_default()` is an ordinary
  export, for comparison.

------------------------------------------------------------------------------*/

#pragma once

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBALVIS_BUILDING_LIB
  #define LBALVIS_FUNC LBAL_VIS_FUNC_EXPORT
  #define LBALVIS_OVERLOADABLE_FUNC LBAL_VIS_OVERLOADABLE_FUNC_EXPORT
#else
  #define LBALVIS_FUNC LBAL_VIS_FUNC_IMPORT
  #define LBALVIS_OVERLOADABLE_FUNC LBAL_VIS_OVERLOADABLE_FUNC_IMPORT
#endif

//	Returns `1` unless the client replaces it.
LBALVIS_OVERLOADABLE_FUNC int lbal_vis_replaceable();

//	Returns `1`.
LBALVIS_FUNC int lbal_vis_default();
