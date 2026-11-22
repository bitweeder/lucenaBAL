/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalCompilerSetup-definitions-cpp23.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

//	C++23 Language

#if !defined(LBAL_CPP23_AUTO_CAST) && (__cpp_auto_cast >= 202110L)
  #define LBAL_CPP23_AUTO_CAST __cpp_auto_cast
#endif

#if !defined(LBAL_CPP23_CHAR8_T_COMPATIBILITY) && (__cpp_char8_t >= 202207L)
  #define LBAL_CPP23_CHAR8_T_COMPATIBILITY __cpp_char8_t
#endif

#if !defined(LBAL_CPP23_CONSTEVAL_PROPAGATE_UP) && (__cpp_consteval >= 202211L)
  #define LBAL_CPP23_CONSTEVAL_PROPAGATE_UP __cpp_consteval
#endif

#if !defined(LBAL_CPP23_CONSTEXPR_NON_LITERAL_VARIABLES)                       \
    && (__cpp_constexpr >= 202110L)
  #define LBAL_CPP23_CONSTEXPR_NON_LITERAL_VARIABLES __cpp_constexpr
#endif

#if !defined(LBAL_CPP23_CONSTEXPR_PERMIT_STATIC_CONSTEXPR)                     \
    && (__cpp_constexpr >= 202211L)
  #define LBAL_CPP23_CONSTEXPR_PERMIT_STATIC_CONSTEXPR __cpp_constexpr
#endif

#if !defined(LBAL_CPP23_CONSTEXPR_RELAX_RESTRICTIONS)                          \
    && (__cpp_constexpr >= 202207L)
  #define LBAL_CPP23_CONSTEXPR_RELAX_RESTRICTIONS __cpp_constexpr
#endif

#if !defined(LBAL_CPP23_DEDUCTION_GUIDES_FROM_INHERITED_CONSTRUCTORS)          \
    && (__cpp_deduction_guides >= 202207L)
  #define LBAL_CPP23_DEDUCTION_GUIDES_FROM_INHERITED_CONSTRUCTORS              \
    __cpp_deduction_guides
#endif

#if !defined(LBAL_CPP23_EXPLICIT_THIS_PARAMETER)                               \
    && (__cpp_explicit_this_parameter >= 202110L)
  #define LBAL_CPP23_EXPLICIT_THIS_PARAMETER __cpp_explicit_this_parameter
#endif

#if !defined(LBAL_CPP23_IF_CONSTEVAL) && (__cpp_if_consteval >= 202106L)
  #define LBAL_CPP23_IF_CONSTEVAL __cpp_if_consteval
#endif

#if !defined(LBAL_CPP23_IMPLICIT_MOVE) && (__cpp_implicit_move >= 202207L)
  #define LBAL_CPP23_IMPLICIT_MOVE __cpp_implicit_move
#endif

#if !defined(LBAL_CPP23_MULTIDIMENSIONAL_SUBSCRIPT)                            \
    && (__cpp_multidimensional_subscript >= 202110L)
  #define LBAL_CPP23_MULTIDIMENSIONAL_SUBSCRIPT __cpp_multidimensional_subscript
#endif

#if !defined(LBAL_CPP23_MULTIDIMENSIONAL_SUBSCRIPT_STATIC)                     \
    && (__cpp_multidimensional_subscript >= 202211L)
  #define LBAL_CPP23_MULTIDIMENSIONAL_SUBSCRIPT_STATIC                         \
    __cpp_multidimensional_subscript
#endif

#if !defined(LBAL_CPP23_NAMED_CHARACTER_ESCAPES)                               \
    && (__cpp_named_character_escapes >= 202207L)
  #define LBAL_CPP23_NAMED_CHARACTER_ESCAPES __cpp_named_character_escapes
#endif

#if !defined(LBAL_CPP23_RANGE_BASED_FOR_TEMPORARIES)                           \
    && (__cpp_range_based_for >= 202211L)
  #define LBAL_CPP23_RANGE_BASED_FOR_TEMPORARIES __cpp_range_based_for
#endif

#if !defined(LBAL_CPP23_SIZE_T_SUFFIX) && (__cpp_size_t_suffix >= 202011L)
  #define LBAL_CPP23_SIZE_T_SUFFIX __cpp_size_t_suffix
#endif

#if !defined(LBAL_CPP23_STATIC_CALL_OPERATOR)                                  \
    && (__cpp_static_call_operator >= 202207L)
  #define LBAL_CPP23_STATIC_CALL_OPERATOR __cpp_static_call_operator
#endif

//	C++23 Attributes

#if !defined(LBAL_CPP23_ATTRIBUTE_ASSUME)                                      \
    && defined(__has_cpp_attribute)                                            \
    && (__has_cpp_attribute(assume) >= 202207L)
  #define LBAL_CPP23_ATTRIBUTE_ASSUME 202207L
#endif
