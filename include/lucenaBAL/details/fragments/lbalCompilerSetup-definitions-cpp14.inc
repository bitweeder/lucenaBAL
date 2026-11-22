/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalCompilerSetup-definitions-cpp14.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

//	C++14 Language

#if !defined(LBAL_CPP14_AGGREGATE_NSDMI) && (__cpp_aggregate_nsdmi >= 201304L)
  #define LBAL_CPP14_AGGREGATE_NSDMI __cpp_aggregate_nsdmi
#endif

#if !defined(LBAL_CPP14_BINARY_LITERALS) && (__cpp_binary_literals >= 201304L)
  #define LBAL_CPP14_BINARY_LITERALS __cpp_binary_literals
#endif

#if !defined(LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS)                         \
    && (__cpp_constexpr >= 201304L)
  #define LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS __cpp_constexpr
#endif

#if !defined(LBAL_CPP14_DECLTYPE_AUTO) && (__cpp_decltype_auto >= 201304L)
  #define LBAL_CPP14_DECLTYPE_AUTO __cpp_decltype_auto
#endif

#if !defined(LBAL_CPP14_GENERIC_LAMBDAS) && (__cpp_generic_lambdas >= 201304L)
  #define LBAL_CPP14_GENERIC_LAMBDAS __cpp_generic_lambdas
#endif

#if !defined(LBAL_CPP14_INIT_CAPTURES) && (__cpp_init_captures >= 201304L)
  #define LBAL_CPP14_INIT_CAPTURES __cpp_init_captures
#endif

#if !defined(LBAL_CPP14_RETURN_TYPE_DEDUCTION)                                 \
    && (__cpp_return_type_deduction >= 201304L)
  #define LBAL_CPP14_RETURN_TYPE_DEDUCTION __cpp_return_type_deduction
#endif

#if !defined(LBAL_CPP14_SIZED_DEALLOCATION)                                    \
    && (__cpp_sized_deallocation >= 201309L)
  #define LBAL_CPP14_SIZED_DEALLOCATION __cpp_sized_deallocation
#endif

#if !defined(LBAL_CPP14_VARIABLE_TEMPLATES)                                    \
    && (__cpp_variable_templates >= 201304L)
  #define LBAL_CPP14_VARIABLE_TEMPLATES __cpp_variable_templates
#endif

//	C++14 Attributes

#if !defined(LBAL_CPP14_ATTRIBUTE_DEPRECATED)                                  \
    && defined(__has_cpp_attribute)                                            \
    && (__has_cpp_attribute(deprecated) >= 201309L)
  #define LBAL_CPP14_ATTRIBUTE_DEPRECATED 201309L
#endif
