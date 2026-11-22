/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalCompilerSetup-definitions-cpp03.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

//	These can be conditionally disabled.

#if !defined(LBAL_CPP03_EXCEPTIONS) && (__cpp_exceptions >= 199711L)
  #define LBAL_CPP03_EXCEPTIONS __cpp_exceptions
#endif

#if !defined(LBAL_CPP03_RTTI) && (__cpp_rtti >= 199711L)
  #define LBAL_CPP03_RTTI __cpp_rtti
#endif
