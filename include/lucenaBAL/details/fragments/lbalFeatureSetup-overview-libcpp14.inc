/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFeatureSetup-overview-libcpp14.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

/**
  @addtogroup lbal_library
  @{
*/

/**
  @name LBAL_LIBCPP14
  C++14 features described here track the corresponding SD-6 macros, which
  are not as comprehensive as those for more recent Standards. More C++14
  Library features can be tracked as needed.

  @{
*/

/**
  @def LBAL_LIBCPP14_CHRONO_UDLS
  @brief User-defined Literals for `<chrono>` types
  @details SD-6 equivalent: `__cpp_lib_chrono_udls >= 201304L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3642 __PDF__](https://wg21.link/N3642) User-defined Literals for
  Standard Library Types (part 1 - version 4)

  @sa `<chrono>`
*/
#ifndef LBAL_LIBCPP14_CHRONO_UDLS
  #define LBAL_LIBCPP14_CHRONO_UDLS 0
#endif

/**
  @def LBAL_LIBCPP14_COMPLEX_UDLS
  @brief User-defined Literals for `<complex>`
  @details SD-6 equivalent: `__cpp_lib_complex_udls >= 201309L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201309L` [N3779 __PDF__](https://wg21.link/N3779) User-defined Literals
  for std::complex

  @sa `<complex>`
*/
#ifndef LBAL_LIBCPP14_COMPLEX_UDLS
  #define LBAL_LIBCPP14_COMPLEX_UDLS 0
#endif

/**
  @def LBAL_LIBCPP14_EXCHANGE_FUNCTION
  @brief Add `std::exchange` utility function
  @details SD-6 equivalent: `__cpp_lib_exchange_function >= 201304L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3668](https://wg21.link/N3668) `exchange()` utility function,
  revision 3

  @sa `freestanding` `<utility>`
*/
#ifndef LBAL_LIBCPP14_EXCHANGE_FUNCTION
  #define LBAL_LIBCPP14_EXCHANGE_FUNCTION 0
#endif

/**
  @def LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP
  @brief Add heterogeneous comparison lookup to associative containers
  @details SD-6 equivalent: `__cpp_lib_generic_associative_lookup >= 201304L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201304L` [N3657](https://wg21.link/N3657) Adding heterogeneous comparison
  lookup to associative containers (rev 4)

  @sa `<map>` `<set>`
*/
#ifndef LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP
  #define LBAL_LIBCPP14_GENERIC_ASSOCIATIVE_LOOKUP 0
#endif

/**
  @def LBAL_LIBCPP14_INTEGER_SEQUENCE
  @brief Add template-based integer sequences
  @details SD-6 equivalent: `__cpp_lib_integer_sequence >= 201304L`. Note that
  `__cpp_lib_integer_sequence` has multiple values associated with it from a
  number of different proposals, so this token will have the value of the latest
  supported proposal, or `0` if the proposal described here is not supported.
  - `201304L` [N3658](https://wg21.link/N3658) Compile-time integer sequences

  @sa `freestanding` `<utility>`
*/
#ifndef LBAL_LIBCPP14_INTEGER_SEQUENCE
  #define LBAL_LIBCPP14_INTEGER_SEQUENCE 0
#endif

/**
  @def LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE
  @brief Add `constexpr` operator-() to `std::integral_constant`
  @details SD-6 equivalent: `__cpp_lib_integral_constant_callable >= 201304L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201304L` [N3545 __PDF__](https://wg21.link/N3545) An Incremental
  Improvement to integral_constant

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE
  #define LBAL_LIBCPP14_INTEGRAL_CONSTANT_CALLABLE 0
#endif

/**
  @def LBAL_LIBCPP14_IS_FINAL
  @brief Detect finalized classes
  @details SD-6 equivalent: `__cpp_lib_is_final >= 201402L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201402L` [LWG2112](https://wg21.link/LWG2112) User-defined classes that
  cannot be derived from

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP14_IS_FINAL
  #define LBAL_LIBCPP14_IS_FINAL 0
#endif

/**
  @def LBAL_LIBCPP14_IS_NULL_POINTER
  @brief Detect null pointers
  @details SD-6 equivalent: `__cpp_lib_is_null_pointer >= 201309L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201309L` [LWG2247](https://wg21.link/LWG2247) Type traits and
  `std::nullptr_t`

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP14_IS_NULL_POINTER
  #define LBAL_LIBCPP14_IS_NULL_POINTER 0
#endif

/**
  @def LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR
  @brief `std::make_reverse_iterator`
  @details SD-6 equivalent: `__cpp_lib_make_reverse_iterator >= 201402L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201402L` [LWG2285](https://wg21.link/LWG2285) `make_reverse_iterator`

  @sa `freestanding` `<iterator>`
*/
#ifndef LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR
  #define LBAL_LIBCPP14_MAKE_REVERSE_ITERATOR 0
#endif

/**
  @def LBAL_LIBCPP14_MAKE_UNIQUE
  @brief `std::make_unique`
  @details SD-6 equivalent: `__cpp_lib_make_unique >= 201304L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3656](https://wg21.link/N3656) make_unique (Revision 1)

  @sa `<memory>`
*/
#ifndef LBAL_LIBCPP14_MAKE_UNIQUE
  #define LBAL_LIBCPP14_MAKE_UNIQUE 0
#endif

/**
  @def LBAL_LIBCPP14_NULL_ITERATORS
  @brief Allow value-initialized forward iterators to be compared
  @details SD-6 equivalent: `__cpp_lib_null_iterators >= 201304L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3644 __PDF__](https://wg21.link/N3644) Null Forward Iterators

  @sa `freestanding` `<iterator>`
*/
#ifndef LBAL_LIBCPP14_NULL_ITERATORS
  #define LBAL_LIBCPP14_NULL_ITERATORS 0
#endif

/**
  @def LBAL_LIBCPP14_QUOTED_STRING_IO
  @brief Add quoted-string sream i/o manipulator
  @details SD-6 equivalent: `__cpp_lib_quoted_string_io >= 201304L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3654](https://wg21.link/N3654) Quoted Strings Library Proposal
  (Revision 2)

  @sa `<iomanip>`
*/
#ifndef LBAL_LIBCPP14_QUOTED_STRING_IO
  #define LBAL_LIBCPP14_QUOTED_STRING_IO 0
#endif

/**
  @def LBAL_LIBCPP14_RESULT_OF_SFINAE
  @brief Make `std::result_of` SFINAE-friendly
  @details SD-6 equivalent: `__cpp_lib_result_of_sfinae >= 201210L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201210L` [N3462](https://wg21.link/N3462) std::result_of and SFINAE

  @sa `freestanding` `<functional>` `<type_traits>`
*/
#ifndef LBAL_LIBCPP14_RESULT_OF_SFINAE
  #define LBAL_LIBCPP14_RESULT_OF_SFINAE 0
#endif

/**
  @def LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS
  @brief Make non-modifying sequence operations more robust
  @details SD-6 equivalent: `__cpp_lib_robust_nonmodifying_seq_ops >= 201304L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201304L` [N3671](https://wg21.link/N3671) Making non-modifying sequence
  operations more robust: Revision 2

  @sa `<algorithm>` `freestanding`
*/
#ifndef LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS
  #define LBAL_LIBCPP14_ROBUST_NONMODIFYING_SEQ_OPS 0
#endif

/**
  @def LBAL_LIBCPP14_SHARED_TIMED_MUTEX
  @brief Rename `std::shared_mutex` to `std::shared_timed_mutex`
  @details SD-6 equivalent: `__cpp_lib_shared_timed_mutex >= 201402L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201402L` [N3891](https://wg21.link/N3891) A proposal to rename shared_mutex
  to shared_timed_mutex

  @sa `<shared_mutex>`
*/
#ifndef LBAL_LIBCPP14_SHARED_TIMED_MUTEX
  #define LBAL_LIBCPP14_SHARED_TIMED_MUTEX 0
#endif

/**
  @def LBAL_LIBCPP14_STRING_UDLS
  @brief Predefine UDLs for strings
  @details SD-6 equivalent: `__cpp_lib_string_udls >= 201304L`. This token will
  have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3642 __PDF__](https://wg21.link/N3642) User-defined Literals for
  Standard Library Types (part 1 - version 4)

  @sa `<string>`
*/
#ifndef LBAL_LIBCPP14_STRING_UDLS
  #define LBAL_LIBCPP14_STRING_UDLS 0
#endif

/**
  @def LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES
  @brief Provide type aliases for transformation traits
  @details SD-6 equivalent: `__cpp_lib_transformation_trait_aliases >= 201304L`.
  This token will have a value of `0` if the proposal described here is not
  supported.
  - `201304L` [N3655 __PDF__](https://wg21.link/N3655) TransformationTraits
  Redux, v2

  @sa `freestanding` `<type_traits>`
*/
#ifndef LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES
  #define LBAL_LIBCPP14_TRANSFORMATION_TRAIT_ALIASES 0
#endif

/**
  @def LBAL_LIBCPP14_TRANSPARENT_OPERATORS
  @brief Allow heterogeneous arguments to operator functors and template their
  function call operators
  @details SD-6 equivalent: `__cpp_lib_transparent_operators >= 201210L`. Note
  that `__cpp_lib_transparent_operators` has multiple values associated with
  it from a number of different proposals, so this token will have the value
  of the latest supported proposal, or `0` if the proposal described here is
  not supported.
  - `201210L` [N3421](https://wg21.link/N3421) Making Operator Functors
  greater<>

  @sa `freestanding` `<functional>` `<memory>`
*/
#ifndef LBAL_LIBCPP14_TRANSPARENT_OPERATORS
  #define LBAL_LIBCPP14_TRANSPARENT_OPERATORS 0
#endif

/**
  @def LBAL_LIBCPP14_TUPLES_BY_TYPE
  @brief Allow addressing `std::tuple`s by type
  @details SD-6 equivalent: `__cpp_lib_tuples_by_type >= 201304L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201304L` [N3670](https://wg21.link/N3670) Wording for Addressing Tuples by
  Type: Revision 2

  @sa `freestanding` `<tuple>` `<utility>`
*/
#ifndef LBAL_LIBCPP14_TUPLES_BY_TYPE
  #define LBAL_LIBCPP14_TUPLES_BY_TYPE 0
#endif

/**
  @def LBAL_LIBCPP14_TUPLE_ELEMENT_T
  @brief Add `std::tuple` `element_t` type alias
  @details SD-6 equivalent: `__cpp_lib_tuple_element_t >= 201402L`. This token
  will have a value of `0` if the proposal described here is not supported.
  - `201402L` [N3887 __PDF__](https://wg21.link/N3887) Consistent Metafunction
  Aliases

  @sa `freestanding` `<tuple>`
*/
#ifndef LBAL_LIBCPP14_TUPLE_ELEMENT_T
  #define LBAL_LIBCPP14_TUPLE_ELEMENT_T 0
#endif

///	@}	LBAL_LIBCPP14

///	@}	lbal_library
