/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalLibrarySetup-definitions-libcpp2d.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if !defined(LBAL_LIBCPP2D_BITOPS_BETTER_SHIFTING)
  #if __cpp_lib_bitops >= 202606L
    #define LBAL_LIBCPP2D_BITOPS_BETTER_SHIFTING __cpp_lib_bitops
  #endif
#endif  //  LBAL_LIBCPP2D_BITOPS_BETTER_SHIFTING

#if !defined(LBAL_LIBCPP2D_BITOPS_PERMUTATIONS)
  #if __cpp_lib_bitops >= 202607L
    #define LBAL_LIBCPP2D_BITOPS_PERMUTATIONS __cpp_lib_bitops
  #endif
#endif  //  LBAL_LIBCPP2D_BITOPS_PERMUTATIONS

#if !defined(LBAL_LIBCPP2D_CONSTANT_WRAPPER_REVERT_STRING)
  #if __cpp_lib_constant_wrapper >= 202606L
    #define LBAL_LIBCPP2D_CONSTANT_WRAPPER_REVERT_STRING                       \
      __cpp_lib_constant_wrapper
  #endif
#endif  //  LBAL_LIBCPP2D_CONSTANT_WRAPPER_REVERT_STRING

#if !defined(LBAL_LIBCPP2D_EXPECTED_UEXPECTED)
  #if __cpp_lib_expected >= 202606L
    #define LBAL_LIBCPP2D_EXPECTED_UEXPECTED __cpp_lib_expected
  #endif
#endif  //  LBAL_LIBCPP2D_EXPECTED_UEXPECTED

#if !defined(LBAL_LIBCPP2D_HAZARD_POINTER_BATCHES)
  #if __cpp_lib_hazard_pointer >= 202606L
    #define LBAL_LIBCPP2D_HAZARD_POINTER_BATCHES __cpp_lib_hazard_pointer
  #endif
#endif  //  LBAL_LIBCPP2D_HAZARD_POINTER_BATCHES

#if !defined(LBAL_LIBCPP2D_MAP_LOOKUP)
  #if __cpp_lib_map_lookup >= 202606L
    #define LBAL_LIBCPP2D_MAP_LOOKUP __cpp_lib_map_lookup
  #endif
#endif  //  LBAL_LIBCPP2D_MAP_LOOKUP

#if !defined(LBAL_LIBCPP2D_MDSPAN_COPY)
  #if __cpp_lib_mdspan_copy >= 202606L
    #define LBAL_LIBCPP2D_MDSPAN_COPY __cpp_lib_mdspan_copy
  #endif
#endif  //  LBAL_LIBCPP2D_MDSPAN_COPY

#if !defined(LBAL_LIBCPP2D_POINTER_TAG_PAIR)
  #if __cpp_lib_pointer_tag_pair >= 202606L
    #define LBAL_LIBCPP2D_POINTER_TAG_PAIR __cpp_lib_pointer_tag_pair
  #endif
#endif  //  LBAL_LIBCPP2D_POINTER_TAG_PAIR

#if !defined(LBAL_LIBCPP2D_SIMD_BITOPS)
  #if __cpp_lib_simd_bitops >= 202607L
    #define LBAL_LIBCPP2D_SIMD_BITOPS __cpp_lib_simd_bitops
  #endif
#endif  //  LBAL_LIBCPP2D_SIMD_BITOPS

#if !defined(LBAL_LIBCPP2D_SIMD_BITOPS_BETTER_SHIFTING)
  #if __cpp_lib_simd_bitops >= 202606L
    #define LBAL_LIBCPP2D_SIMD_BITOPS_BETTER_SHIFTING __cpp_lib_simd_bitops
  #endif
#endif  //  LBAL_LIBCPP2D_SIMD_BITOPS_BETTER_SHIFTING

#if !defined(LBAL_LIBCPP2D_SIMD_IOTA)
  #if __cpp_lib_simd >= 202606L
    #define LBAL_LIBCPP2D_SIMD_IOTA __cpp_lib_simd
  #endif
#endif  //  LBAL_LIBCPP2D_SIMD_IOTA

#if !defined(LBAL_LIBCPP2D_THREAD_ATTRIBUTES)
  #if __cpp_lib_thread_attributes >= 202606L
    #define LBAL_LIBCPP2D_THREAD_ATTRIBUTES __cpp_lib_thread_attributes
  #endif
#endif  //  LBAL_LIBCPP2D_THREAD_ATTRIBUTES

#if !defined(LBAL_LIBCPP2D_TO_CHARS_FIX_FLOAT)
  #if __cpp_lib_to_chars >= 202606L
    #define LBAL_LIBCPP2D_TO_CHARS_FIX_FLOAT __cpp_lib_to_chars
  #endif
#endif  //  LBAL_LIBCPP2D_TO_CHARS_FIX_FLOAT

#if !defined(LBAL_LIBCPP2D_VIEW_INTERFACE)
  #if __cpp_lib_view_interface >= 202606L
    #define LBAL_LIBCPP2D_VIEW_INTERFACE __cpp_lib_view_interface
  #endif
#endif  //  LBAL_LIBCPP2D_VIEW_INTERFACE
