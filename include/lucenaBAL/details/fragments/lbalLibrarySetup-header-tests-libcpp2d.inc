/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalLibrarySetup-header-tests-libcpp2d.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if LBAL_LIBCPP2D_BITOPS_BETTER_SHIFTING
  #if LBAL_HAS_HEADER_BIT != 1
    #undef LBAL_LIBCPP2D_BITOPS_BETTER_SHIFTING
    #define LBAL_LIBCPP2D_BITOPS_BETTER_SHIFTING 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP2D_BITOPS_BETTER_SHIFTING: <bit> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP2D_BITOPS_BETTER_SHIFTING

#if LBAL_LIBCPP2D_BITOPS_PERMUTATIONS
  #if LBAL_HAS_HEADER_BIT != 1
    #undef LBAL_LIBCPP2D_BITOPS_PERMUTATIONS
    #define LBAL_LIBCPP2D_BITOPS_PERMUTATIONS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP2D_BITOPS_PERMUTATIONS: <bit> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP2D_BITOPS_PERMUTATIONS

#if LBAL_LIBCPP2D_CONSTANT_WRAPPER_REVERT_STRING
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1 || LBAL_HAS_HEADER_UTILITY != 1
    #undef LBAL_LIBCPP2D_CONSTANT_WRAPPER_REVERT_STRING
    #define LBAL_LIBCPP2D_CONSTANT_WRAPPER_REVERT_STRING 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP2D_CONSTANT_WRAPPER_REVERT_STRING: at least "
    "one of {<type_traits>, <utility>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP2D_CONSTANT_WRAPPER_REVERT_STRING

#if LBAL_LIBCPP2D_EXPECTED_UEXPECTED
  #if LBAL_HAS_HEADER_EXPECTED != 1
    #undef LBAL_LIBCPP2D_EXPECTED_UEXPECTED
    #define LBAL_LIBCPP2D_EXPECTED_UEXPECTED 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP2D_EXPECTED_UEXPECTED: <expected> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP2D_EXPECTED_UEXPECTED

#if LBAL_LIBCPP2D_HAZARD_POINTER_BATCHES
  #if LBAL_HAS_HEADER_HAZARD_POINTER != 1
    #undef LBAL_LIBCPP2D_HAZARD_POINTER_BATCHES
    #define LBAL_LIBCPP2D_HAZARD_POINTER_BATCHES 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP2D_HAZARD_POINTER_BATCHES: <hazard_pointer> "
    "not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP2D_HAZARD_POINTER_BATCHES

#if LBAL_LIBCPP2D_SIMD_IOTA
  #if LBAL_HAS_HEADER_SIMD != 1
    #undef LBAL_LIBCPP2D_SIMD_IOTA
    #define LBAL_LIBCPP2D_SIMD_IOTA 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP2D_SIMD_IOTA: <simd> not found")
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP2D_SIMD_IOTA

#if LBAL_LIBCPP2D_TO_CHARS_FIX_FLOAT
  #if LBAL_HAS_HEADER_CHARCONV != 1
    #undef LBAL_LIBCPP2D_TO_CHARS_FIX_FLOAT
    #define LBAL_LIBCPP2D_TO_CHARS_FIX_FLOAT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP2D_TO_CHARS_FIX_FLOAT: <charconv> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP2D_TO_CHARS_FIX_FLOAT
