/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalCompilerSetup-definitions-cpp20.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

//	C++20 Language

#if !defined(LBAL_CPP20_AGGREGATE_PAREN_INIT)                                  \
    && (__cpp_aggregate_paren_init >= 201902L)
  #define LBAL_CPP20_AGGREGATE_PAREN_INIT __cpp_aggregate_paren_init
#endif

#if !defined(LBAL_CPP20_CHAR8_T) && (__cpp_char8_t >= 201811L)
  #define LBAL_CPP20_CHAR8_T __cpp_char8_t
#endif

#if !defined(LBAL_CPP20_CONCEPTS) && (__cpp_concepts >= 201707L)
  #define LBAL_CPP20_CONCEPTS __cpp_concepts
#endif

#if !defined(                                                                  \
    LBAL_CPP20_CONCEPTS_CONDITIONALLY_TRIVIAL_SPECIAL_MEMBER_FUNCTIONS         \
) && (__cpp_concepts >= 202002L)
  #define LBAL_CPP20_CONCEPTS_CONDITIONALLY_TRIVIAL_SPECIAL_MEMBER_FUNCTIONS   \
    __cpp_concepts
#endif

#if !defined(LBAL_CPP20_CONCEPTS_REFINE_RETURN_TYPE_REQUIREMENTS)              \
    && (__cpp_concepts >= 201907L)
  #define LBAL_CPP20_CONCEPTS_REFINE_RETURN_TYPE_REQUIREMENTS __cpp_concepts
#endif

#if !defined(LBAL_CPP20_CONCEPTS_RESPECIFY_RETURN_TYPE_REQUIREMENTS)           \
    && (__cpp_concepts >= 201811L)
  #define LBAL_CPP20_CONCEPTS_RESPECIFY_RETURN_TYPE_REQUIREMENTS __cpp_concepts
#endif

#if !defined(LBAL_CPP20_CONDITIONAL_EXPLICIT)                                  \
    && (__cpp_conditional_explicit >= 201806L)
  #define LBAL_CPP20_CONDITIONAL_EXPLICIT __cpp_conditional_explicit
#endif

#if !defined(LBAL_CPP20_CONSTEVAL) && (__cpp_consteval >= 201811L)
  #define LBAL_CPP20_CONSTEVAL __cpp_consteval
#endif

#if !defined(LBAL_CPP20_CONSTEXPR_CHANGE_ACTIVE_UNION_MEMBER)                  \
    && (__cpp_constexpr >= 202002L)
  #define LBAL_CPP20_CONSTEXPR_CHANGE_ACTIVE_UNION_MEMBER __cpp_constexpr
#endif

#if !defined(LBAL_CPP20_CONSTEXPR_DYNAMIC_ALLOC)                               \
    && (__cpp_constexpr_dynamic_alloc >= 201907L)
  #define LBAL_CPP20_CONSTEXPR_DYNAMIC_ALLOC __cpp_constexpr_dynamic_alloc
#endif

#if !defined(LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM)                        \
    && (__cpp_constexpr >= 201811L)
  #define LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM __cpp_constexpr
#endif

#if !defined(LBAL_CPP20_CONSTEXPR_INTRINSICS) && (__cpp_constexpr >= 201907L)
  #define LBAL_CPP20_CONSTEXPR_INTRINSICS __cpp_constexpr
#endif

#if !defined(LBAL_CPP20_CONSTEXPR_IN_DECLTYPE)                                 \
    && (__cpp_constexpr_in_decltype >= 201711L)
  #define LBAL_CPP20_CONSTEXPR_IN_DECLTYPE __cpp_constexpr_in_decltype
#endif

#if !defined(LBAL_CPP20_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION)              \
    && (__cpp_constexpr >= 201907L)
  #define LBAL_CPP20_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION __cpp_constexpr
#endif

#if !defined(LBAL_CPP20_CONSTEXPR_TRY_CATCH) && (__cpp_constexpr >= 201811L)
  #define LBAL_CPP20_CONSTEXPR_TRY_CATCH __cpp_constexpr
#endif

#if !defined(LBAL_CPP20_CONSTEXPR_UNION_ALTERATION)                            \
    && (__cpp_constexpr >= 201811L)
  #define LBAL_CPP20_CONSTEXPR_UNION_ALTERATION __cpp_constexpr
#endif

#if !defined(LBAL_CPP20_CONSTEXPR_VIRTUAL_FUNCTION)                            \
    && (__cpp_constexpr >= 201806L)
  #define LBAL_CPP20_CONSTEXPR_VIRTUAL_FUNCTION __cpp_constexpr
#endif

#if !defined(LBAL_CPP20_CONSTINIT) && (__cpp_constinit >= 201907L)
  #define LBAL_CPP20_CONSTINIT __cpp_constinit
#endif

#if !defined(LBAL_CPP20_DEDUCTION_GUIDES_FOR_AGGREGATES)                       \
    && (__cpp_deduction_guides >= 201907L)
  #define LBAL_CPP20_DEDUCTION_GUIDES_FOR_AGGREGATES __cpp_deduction_guides
#endif

#if !defined(LBAL_CPP20_DESIGNATED_INITIALIZERS)                               \
    && (__cpp_designated_initializers >= 201707L)
  #define LBAL_CPP20_DESIGNATED_INITIALIZERS __cpp_designated_initializers
#endif

#if !defined(LBAL_CPP20_DESTROYING_DELETE)                                     \
    && (__cpp_impl_destroying_delete >= 201806L)
  #define LBAL_CPP20_DESTROYING_DELETE __cpp_impl_destroying_delete
#endif

#if !defined(LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST)               \
    && (__cpp_generic_lambdas >= 201707L)
  #define LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST                   \
    __cpp_generic_lambdas
#endif

#if !defined(LBAL_CPP20_IMPL_COROUTINE) && (__cpp_impl_coroutine >= 201902L)
  #define LBAL_CPP20_IMPL_COROUTINE __cpp_impl_coroutine
#endif

#if !defined(LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION)                          \
    && (__cpp_init_captures >= 201803L)
  #define LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION __cpp_init_captures
#endif

#if !defined(LBAL_CPP20_MODULES) && (__cpp_modules >= 201907L)
  #define LBAL_CPP20_MODULES __cpp_modules
#endif

#if !defined(LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FIXES)                           \
    && (__cpp_nontype_template_args >= 201911L)
  #define LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FIXES __cpp_nontype_template_args
#endif

#if !defined(LBAL_CPP20_NONTYPE_TEMPLATE_PARAMETER_CLASS)                      \
    && (__cpp_nontype_template_parameter_class >= 201806L)
  #define LBAL_CPP20_NONTYPE_TEMPLATE_PARAMETER_CLASS                          \
    __cpp_nontype_template_parameter_class
#endif

#if !defined(LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR)                         \
    && (__cpp_impl_three_way_comparison >= 201711L)
  #define LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR                             \
    __cpp_impl_three_way_comparison
#endif

#if !defined(LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_EQUALITY_FIX)            \
    && (__cpp_impl_three_way_comparison >= 201902L)
  #define LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_EQUALITY_FIX                \
    __cpp_impl_three_way_comparison
#endif

#if !defined(LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_TUNEUP)                  \
    && (__cpp_impl_three_way_comparison >= 201907L)
  #define LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_TUNEUP                      \
    __cpp_impl_three_way_comparison
#endif

#if !defined(LBAL_CPP20_USING_ENUM) && (__cpp_using_enum >= 201907L)
  #define LBAL_CPP20_USING_ENUM __cpp_using_enum
#endif

//	C++20 Attributes

#if !defined(LBAL_CPP20_ATTRIBUTE_LIKELY)                                      \
    && defined(__has_cpp_attribute)                                            \
    && (__has_cpp_attribute(likely) >= 201803L)
  #define LBAL_CPP20_ATTRIBUTE_LIKELY 201803L
#endif

#if !defined(LBAL_CPP20_ATTRIBUTE_NODISCARD_EXPANDED)                          \
    && defined(__has_cpp_attribute)                                            \
    && (__has_cpp_attribute(nodiscard) >= 201907L)
  #define LBAL_CPP20_ATTRIBUTE_NODISCARD_EXPANDED 201907L
#endif

#if !defined(LBAL_CPP20_ATTRIBUTE_NO_UNIQUE_ADDRESS)                           \
    && defined(__has_cpp_attribute)                                            \
    && (__has_cpp_attribute(no_unique_address) >= 201803L)
  #define LBAL_CPP20_ATTRIBUTE_NO_UNIQUE_ADDRESS 201803L
#endif

#if !defined(LBAL_CPP20_ATTRIBUTE_UNLIKELY)                                    \
    && defined(__has_cpp_attribute)                                            \
    && (__has_cpp_attribute(unlikely) >= 201803L)
  #define LBAL_CPP20_ATTRIBUTE_UNLIKELY 201803L
#endif
