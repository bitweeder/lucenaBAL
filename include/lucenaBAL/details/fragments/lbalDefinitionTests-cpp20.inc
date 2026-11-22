/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalDefinitionTests-cpp20.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if defined(LBAL_CPP20_AGGREGATE_PAREN_INIT)                                          \
    || defined(LBAL_CPP20_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS)                           \
    || defined(LBAL_CPP20_ATTRIBUTE_LIKELY)                                           \
    || defined(LBAL_CPP20_ATTRIBUTE_NODISCARD_EXPANDED)                               \
    || defined(LBAL_CPP20_ATTRIBUTE_NO_UNIQUE_ADDRESS)                                \
    || defined(LBAL_CPP20_ATTRIBUTE_UNLIKELY)                                         \
    || defined(LBAL_CPP20_ATTRIBUTES_LIKELY_AND_UNLIKELY)                             \
    || defined(LBAL_CPP20_CHAR8_T)                                                    \
    || defined(LBAL_CPP20_CONCEPTS)                                                   \
    || defined(LBAL_CPP20_CONCEPTS_RESPECIFY_RETURN_TYPE_REQUIREMENTS)                \
    || defined(LBAL_CPP20_CONCEPTS_REFINE_RETURN_TYPE_REQUIREMENTS)                   \
    || defined(                                                                       \
        LBAL_CPP20_CONCEPTS_CONDITIONALLY_TRIVIAL_SPECIAL_MEMBER_FUNCTIONS            \
    )                                                                                 \
    || defined(LBAL_CPP20_CONDITIONAL_EXPLICIT)                                       \
    || defined(LBAL_CPP20_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS)                    \
    || defined(LBAL_CPP20_CONSTEVAL)                                                  \
    || defined(LBAL_CPP20_CONSTEXPR_CHANGE_ACTIVE_UNION_MEMBER)                       \
    || defined(LBAL_CPP20_CONSTEXPR_DYNAMIC_ALLOC)                                    \
    || defined(LBAL_CPP20_CONSTEXPR_DYNAMIC_POLYMORPHISM)                             \
    || defined(LBAL_CPP20_CONSTEXPR_IN_DECLTYPE)                                      \
    || defined(LBAL_CPP20_CONSTEXPR_INTRINSICS)                                       \
    || defined(LBAL_CPP20_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION)                   \
    || defined(LBAL_CPP20_CONSTEXPR_TRY_CATCH)                                        \
    || defined(LBAL_CPP20_CONSTEXPR_UNION_ALTERATION)                                 \
    || defined(LBAL_CPP20_CONSTEXPR_VIRTUAL_FUNCTION)                                 \
    || defined(LBAL_CPP20_CONSTINIT)                                                  \
    || defined(LBAL_CPP20_DEDUCTION_GUIDES_FOR_AGGREGATES)                            \
    || defined(                                                                       \
        LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS             \
    )                                                                                 \
    || defined(LBAL_CPP20_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS)                 \
    || defined(LBAL_CPP20_DESIGNATED_INITIALIZERS)                                    \
    || defined(LBAL_CPP20_DESTROYING_DELETE)                                          \
    || defined(LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST)                    \
    || defined(LBAL_CPP20_IMPL_COROUTINE)                                             \
    || defined(LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION)                               \
    || defined(LBAL_CPP20_INIT_STATEMENTS_FOR_RANGE_BASED_FOR)                        \
    || defined(                                                                       \
        LBAL_CPP20_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION \
    )                                                                                 \
    || defined(LBAL_CPP20_INTEGRATING_OUR_FEATURE_TEST_MACROS)                        \
    || defined(LBAL_CPP20_MODULES)                                                    \
    || defined(LBAL_CPP20_NONTYPE_TEMPLATE_ARGS_FIXES)                                \
    || defined(LBAL_CPP20_NONTYPE_TEMPLATE_PARAMETER_CLASS)                           \
    || defined(LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR)                              \
    || defined(LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_EQUALITY_FIX)                 \
    || defined(LBAL_CPP20_THREE_WAY_COMPARISON_OPERATOR_TUNEUP)                       \
    || defined(LBAL_CPP20_TYPENAME_OPTIONAL)                                          \
    || defined(LBAL_CPP20_USING_ENUM)                                                 \
    || defined(LBAL_CPP20_VA_OPT)

  #error "Don’t define LBAL_CPP20_xxx externally."
#endif  //	LBAL_CPP20 check
