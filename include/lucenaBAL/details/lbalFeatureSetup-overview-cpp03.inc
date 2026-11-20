/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFeatureSetup-overview-cpp03.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

/**
  @addtogroup lbal_compiler
  @{
*/

/**
  @name LBAL_CPP03
  These are here only because compilers can be made to disable specific
  features for various reasons and we want to have a universal way of
  determining whether that’s happened.

  @{
*/

/**
  @def LBAL_CPP03_EXCEPTIONS
  @brief Language-level support for C++ Exceptions
  @details This can be conditionally disabled at build-time, so we can’t rely on
  a language version test to detect it.

  SD-6 equivalent: `__cpp_exceptions >= 199711L`. This token will have a value
  of `0` if the proposal described here is not supported.
  - `199711L` [N1146](https://wg21.link/N1146) C++98 Final Working Draft

  @remark This is based on the non-existent `__cpp_exceptions` SD-6 token, which
  does not appear in any Standard document but which everyone agrees exists.
  Despite being a de facto language extension, it’s safe to rely on since all
  compilers appear to support it.
*/
#ifndef LBAL_CPP03_EXCEPTIONS
  #define LBAL_CPP03_EXCEPTIONS 0
#endif

/**
  @def LBAL_CPP03_RTTI
  @brief Language-level support for run-time type identification (RTTI)
  @details This can be conditionally disabled at build-time, so we can’t rely on
  a language version test to detect it.

  SD-6 equivalent: `__cpp_rtti >= 199711L`. This token will have a value of `0`
  if the proposal described here is not supported.
  - `199711L` [N1146](https://wg21.link/N1146) C++98 Final Working Draft

  @remark This is based on the non-existent `__cpp_rtti` SD-6 token, which does
  not appear in any Standard document but which everyone agrees exists. Despite
  being a de facto language extension, it’s safe to rely on since all compilers
  appear to support it.
*/
#ifndef LBAL_CPP03_RTTI
  #define LBAL_CPP03_RTTI 0
#endif

///	@}	LBAL_CPP03

///	@}	lbal_compiler
