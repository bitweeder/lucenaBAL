/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalCompilerSetup-definitions-cpp17.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if !defined(LBAL_CPP17_AGGREGATE_BASES) && (__cpp_aggregate_bases >= 201603L)
  #define LBAL_CPP17_AGGREGATE_BASES __cpp_aggregate_bases
#endif

#if !defined(LBAL_CPP17_ALIGNED_NEW) && (__cpp_aligned_new >= 201603L)
  #define LBAL_CPP17_ALIGNED_NEW __cpp_aligned_new
#endif

#if !defined(LBAL_CPP17_CAPTURE_STAR_THIS)                                     \
    && (__cpp_capture_star_this >= 201603L)
  #define LBAL_CPP17_CAPTURE_STAR_THIS __cpp_capture_star_this
#endif

#if !defined(LBAL_CPP17_CONSTEXPR_LAMBDA) && (__cpp_constexpr >= 201603L)
  #define LBAL_CPP17_CONSTEXPR_LAMBDA __cpp_constexpr
#endif

#if !defined(LBAL_CPP17_DEDUCTION_GUIDES) && (__cpp_deduction_guides >= 201606L)
  #define LBAL_CPP17_DEDUCTION_GUIDES __cpp_deduction_guides
#endif

#if !defined(LBAL_CPP17_DEDUCTION_GUIDES_NB)                                   \
    && (__cpp_deduction_guides >= 201611L)
  #define LBAL_CPP17_DEDUCTION_GUIDES_NB __cpp_deduction_guides
#endif

#if !defined(LBAL_CPP17_DEDUCTION_GUIDES_DR)                                   \
    && (__cpp_deduction_guides >= 201703L)
  #define LBAL_CPP17_DEDUCTION_GUIDES_DR __cpp_deduction_guides
#endif

#if !defined(LBAL_CPP17_ENUMERATOR_ATTRIBUTES)                                 \
    && (__cpp_enumerator_attributes >= 201411L)
  #define LBAL_CPP17_ENUMERATOR_ATTRIBUTES __cpp_enumerator_attributes
#endif

#if !defined(LBAL_CPP17_FOLD_EXPRESSIONS) && (__cpp_fold_expressions >= 201411L)
  #define LBAL_CPP17_FOLD_EXPRESSIONS __cpp_fold_expressions
#endif

#if !defined(LBAL_CPP17_FOLD_EXPRESSIONS_REVISED)                              \
    && (__cpp_fold_expressions >= 201603L)
  #define LBAL_CPP17_FOLD_EXPRESSIONS_REVISED __cpp_fold_expressions
#endif

#if !defined(LBAL_CPP17_GUARANTEED_COPY_ELISION)                               \
    && (__cpp_guaranteed_copy_elision >= 201606L)
  #define LBAL_CPP17_GUARANTEED_COPY_ELISION __cpp_guaranteed_copy_elision
#endif

#if !defined(LBAL_CPP17_HEX_FLOAT) && (__cpp_hex_float >= 201603L)
  #define LBAL_CPP17_HEX_FLOAT __cpp_hex_float
#endif

#if !defined(LBAL_CPP17_IF_CONSTEXPR) && (__cpp_if_constexpr >= 201606L)
  #define LBAL_CPP17_IF_CONSTEXPR __cpp_if_constexpr
#endif

#if !defined(LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED)                       \
    && (__cpp_inheriting_constructors >= 201511L)
  #define LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED                           \
    __cpp_inheriting_constructors
#endif

#if !defined(LBAL_CPP17_INLINE_VARIABLES) && (__cpp_inline_variables >= 201606L)
  #define LBAL_CPP17_INLINE_VARIABLES __cpp_inline_variables
#endif

#if !defined(LBAL_CPP17_NAMESPACE_ATTRIBUTES)                                  \
    && (__cpp_namespace_attributes >= 201411L)
  #define LBAL_CPP17_NAMESPACE_ATTRIBUTES __cpp_namespace_attributes
#endif

#if !defined(LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE)                                \
    && (__cpp_noexcept_function_type >= 201510L)
  #define LBAL_CPP17_NOEXCEPT_FUNCTION_TYPE __cpp_noexcept_function_type
#endif

#if !defined(LBAL_CPP17_NONTYPE_TEMPLATE_ARGS)                                 \
    && (__cpp_nontype_template_args >= 201411L)
  #define LBAL_CPP17_NONTYPE_TEMPLATE_ARGS __cpp_nontype_template_args
#endif

#if !defined(LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO)                       \
    && (__cpp_nontype_template_parameter_auto >= 201606L)
  #define LBAL_CPP17_NONTYPE_TEMPLATE_PARAMETER_AUTO                           \
    __cpp_nontype_template_parameter_auto
#endif

#if !defined(LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED)                           \
    && (__cpp_range_based_for >= 201603L)
  #define LBAL_CPP17_RANGE_BASED_FOR_GENERALIZED __cpp_range_based_for
#endif

#if !defined(LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE)                              \
    && (__cpp_static_assert >= 201411L)
  #define LBAL_CPP17_STATIC_ASSERT_NO_MESSAGE __cpp_static_assert
#endif

#if !defined(LBAL_CPP17_STRUCTURED_BINDINGS)                                   \
    && (__cpp_structured_bindings >= 201606L)
  #define LBAL_CPP17_STRUCTURED_BINDINGS __cpp_structured_bindings
#endif

#if !defined(LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS)                                \
    && (__cpp_template_template_args >= 201611L)
  #define LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS __cpp_template_template_args
#endif

#if !defined(LBAL_CPP17_VARIADIC_USING) && (__cpp_variadic_using >= 201611L)
  #define LBAL_CPP17_VARIADIC_USING __cpp_variadic_using
#endif

//	C++17 Attributes

#if !defined(LBAL_CPP17_ATTRIBUTE_FALLTHROUGH)                                 \
    && defined(__has_cpp_attribute)                                            \
    && (__has_cpp_attribute(fallthrough) >= 201603L)
  #define LBAL_CPP17_ATTRIBUTE_FALLTHROUGH 201603L
#endif

#if !defined(LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED)                                \
    && defined(__has_cpp_attribute)                                            \
    && (__has_cpp_attribute(maybe_unused) >= 201603L)
  #define LBAL_CPP17_ATTRIBUTE_MAYBE_UNUSED 201603L
#endif

#if !defined(LBAL_CPP17_ATTRIBUTE_NODISCARD)                                   \
    && defined(__has_cpp_attribute)                                            \
    && (__has_cpp_attribute(nodiscard) >= 201603L)
  #define LBAL_CPP17_ATTRIBUTE_NODISCARD 201603L
#endif
