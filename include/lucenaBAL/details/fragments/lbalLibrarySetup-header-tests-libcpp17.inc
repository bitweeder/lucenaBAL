/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalLibrarySetup-header-tests-libcpp17.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

------------------------------------------------------------------------------*/

#if LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR
    #define LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR: <memory> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_ADDRESSOF_CONSTEXPR

#if LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL
  #if LBAL_HAS_HEADER_DEQUE != 1                                               \
      || LBAL_HAS_HEADER_FORWARD_LIST != 1                                     \
      || LBAL_HAS_HEADER_LIST != 1                                             \
      || LBAL_HAS_HEADER_MAP != 1                                              \
      || LBAL_HAS_HEADER_MEMORY != 1                                           \
      || LBAL_HAS_HEADER_SCOPED_ALLOCATOR != 1                                 \
      || LBAL_HAS_HEADER_SET != 1                                              \
      || LBAL_HAS_HEADER_STRING != 1                                           \
      || LBAL_HAS_HEADER_UNORDERED_MAP != 1                                    \
      || LBAL_HAS_HEADER_UNORDERED_SET != 1                                    \
      || LBAL_HAS_HEADER_VECTOR != 1
    #undef LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL
    #define LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL: at "
    "least one of {<deque>, <forward_list>, <list>, <map>, <memory>, "
    "<scoped_allocator>, <set>, <string>, <unordered_map>, <unordered_set>, "
    "<vector>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_ALLOCATOR_TRAITS_IS_ALWAYS_EQUAL

#if LBAL_LIBCPP17_ANY
  #if LBAL_HAS_HEADER_ANY != 1
    #undef LBAL_LIBCPP17_ANY
    #define LBAL_LIBCPP17_ANY 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP17_ANY: <any> not found")
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_ANY

#if LBAL_LIBCPP17_ANY_INTERFACE
  #if LBAL_HAS_HEADER_ANY != 1
    #undef LBAL_LIBCPP17_ANY_INTERFACE
    #define LBAL_LIBCPP17_ANY_INTERFACE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_ANY_INTERFACE: <any> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_ANY_INTERFACE

#if LBAL_LIBCPP17_APPLY
  #if LBAL_HAS_HEADER_TUPLE != 1 || LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP17_APPLY
    #define LBAL_LIBCPP17_APPLY 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_APPLY: at least one of {<tuple>, "
    "<type_traits>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_APPLY

#if LBAL_LIBCPP17_ARRAY_CONSTEXPR
  #if LBAL_HAS_HEADER_ARRAY != 1 || LBAL_HAS_HEADER_ITERATOR != 1
    #undef LBAL_LIBCPP17_ARRAY_CONSTEXPR
    #define LBAL_LIBCPP17_ARRAY_CONSTEXPR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_ARRAY_CONSTEXPR: at least one of "
    "{<array>, <iterator>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_ARRAY_CONSTEXPR

#if LBAL_LIBCPP17_AS_CONST
  #if LBAL_HAS_HEADER_UTILITY != 1
    #undef LBAL_LIBCPP17_AS_CONST
    #define LBAL_LIBCPP17_AS_CONST 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_AS_CONST: <utility> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_AS_CONST

#if LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE
  #if LBAL_HAS_HEADER_ATOMIC != 1
    #undef LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE
    #define LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE: <atomic> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_ATOMIC_IS_ALWAYS_LOCK_FREE

#if LBAL_LIBCPP17_BOOL_CONSTANT
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP17_BOOL_CONSTANT
    #define LBAL_LIBCPP17_BOOL_CONSTANT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_BOOL_CONSTANT: <type_traits> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_BOOL_CONSTANT

#if LBAL_LIBCPP17_BOYER_MOORE_SEARCHER
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1
    #undef LBAL_LIBCPP17_BOYER_MOORE_SEARCHER
    #define LBAL_LIBCPP17_BOYER_MOORE_SEARCHER 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_BOYER_MOORE_SEARCHER: <functional> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_BOYER_MOORE_SEARCHER

#if LBAL_LIBCPP17_BYTE
  #if LBAL_HAS_HEADER_CSTDDEF != 1
    #undef LBAL_LIBCPP17_BYTE
    #define LBAL_LIBCPP17_BYTE 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP17_BYTE: <cstddef> not found")
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_BYTE

#if LBAL_LIBCPP17_CHRONO
  #if LBAL_HAS_HEADER_CHRONO != 1
    #undef LBAL_LIBCPP17_CHRONO
    #define LBAL_LIBCPP17_CHRONO 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP17_CHRONO: <chrono> not found")
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_CHRONO

#if LBAL_LIBCPP17_CHRONO_CONSTEXPR
  #if LBAL_HAS_HEADER_CHRONO != 1
    #undef LBAL_LIBCPP17_CHRONO_CONSTEXPR
    #define LBAL_LIBCPP17_CHRONO_CONSTEXPR 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_CHRONO_CONSTEXPR: <chrono> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_CHRONO_CONSTEXPR

#if LBAL_LIBCPP17_CLAMP
  #if LBAL_HAS_HEADER_ALGORITHM != 1
    #undef LBAL_LIBCPP17_CLAMP
    #define LBAL_LIBCPP17_CLAMP 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_CLAMP: <algorithm> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_CLAMP

#if LBAL_LIBCPP17_CONSTEXPR_STRING
  #if LBAL_HAS_HEADER_STRING != 1
    #undef LBAL_LIBCPP17_CONSTEXPR_STRING
    #define LBAL_LIBCPP17_CONSTEXPR_STRING 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_CONSTEXPR_STRING: <string> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_CONSTEXPR_STRING

#if LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW
  #if LBAL_HAS_HEADER_STRING_VIEW != 1
    #undef LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW
    #define LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW: <string_view> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_CONSTEXPR_STRING_VIEW

#if LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS
    #define LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS: <memory> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_ENABLE_SHARED_FROM_THIS

#if LBAL_LIBCPP17_EXECUTION
  #if LBAL_HAS_HEADER_EXECUTION != 1
    #undef LBAL_LIBCPP17_EXECUTION
    #define LBAL_LIBCPP17_EXECUTION 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_EXECUTION: <execution> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_EXECUTION

#if LBAL_LIBCPP17_FILESYSTEM
  #if LBAL_HAS_HEADER_FILESYSTEM != 1
    #undef LBAL_LIBCPP17_FILESYSTEM
    #define LBAL_LIBCPP17_FILESYSTEM 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_FILESYSTEM: <filesystem> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_FILESYSTEM

#if LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING
  #if LBAL_HAS_HEADER_FILESYSTEM != 1
    #undef LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING
    #define LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING: "
    "<filesystem> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_FILESYSTEM_DIRECTORY_ENTRY_CACHING

#if LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED
  #if LBAL_HAS_HEADER_FILESYSTEM != 1
    #undef LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED
    #define LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED: <filesystem> "
    "not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_FILESYSTEM_PATHS_EXPANDED

#if LBAL_LIBCPP17_FILESYSTEM_RELATIVE_PATHS
  #if LBAL_HAS_HEADER_FILESYSTEM != 1
    #undef LBAL_LIBCPP17_FILESYSTEM_RELATIVE_PATHS
    #define LBAL_LIBCPP17_FILESYSTEM_RELATIVE_PATHS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_FILESYSTEM_RELATIVE_PATHS: <filesystem> "
    "not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_FILESYSTEM_RELATIVE_PATHS

#if LBAL_LIBCPP17_GCD_LCM
  #if LBAL_HAS_HEADER_NUMERIC != 1
    #undef LBAL_LIBCPP17_GCD_LCM
    #define LBAL_LIBCPP17_GCD_LCM 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_GCD_LCM: <numeric> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_GCD_LCM

#if LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE
  #if LBAL_HAS_HEADER_NEW != 1
    #undef LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE
    #define LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE: <new> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE

#if LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS
    #define LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS: "
    "<type_traits> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_HAS_UNIQUE_OBJECT_REPRESENTATIONS

#if LBAL_LIBCPP17_HYPOT
  #if LBAL_HAS_HEADER_CMATH != 1
    #undef LBAL_LIBCPP17_HYPOT
    #define LBAL_LIBCPP17_HYPOT 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP17_HYPOT: <cmath> not found")
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_HYPOT

#if LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS
  #if LBAL_HAS_HEADER_FORWARD_LIST != 1                                        \
      || LBAL_HAS_HEADER_LIST != 1                                             \
      || LBAL_HAS_HEADER_VECTOR != 1
    #undef LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS
    #define LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS: at least "
    "one of {<forward_list>, <list>, <vector>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_INCOMPLETE_CONTAINER_ELEMENTS

#if LBAL_LIBCPP17_INVOKE
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1
    #undef LBAL_LIBCPP17_INVOKE
    #define LBAL_LIBCPP17_INVOKE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_INVOKE: <functional> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_INVOKE

#if LBAL_LIBCPP17_IS_AGGREGATE
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP17_IS_AGGREGATE
    #define LBAL_LIBCPP17_IS_AGGREGATE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_IS_AGGREGATE: <type_traits> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_IS_AGGREGATE

#if LBAL_LIBCPP17_IS_INVOCABLE
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP17_IS_INVOCABLE
    #define LBAL_LIBCPP17_IS_INVOCABLE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_IS_INVOCABLE: <type_traits> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_IS_INVOCABLE

#if LBAL_LIBCPP17_IS_SWAPPABLE
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP17_IS_SWAPPABLE
    #define LBAL_LIBCPP17_IS_SWAPPABLE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_IS_SWAPPABLE: <type_traits> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_IS_SWAPPABLE

#if LBAL_LIBCPP17_LAUNDER
  #if LBAL_HAS_HEADER_NEW != 1
    #undef LBAL_LIBCPP17_LAUNDER
    #define LBAL_LIBCPP17_LAUNDER 0
LBAL_CPP_WARNING("Unable to validate LBAL_LIBCPP17_LAUNDER: <new> not found")
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_LAUNDER

#if LBAL_LIBCPP17_LOGICAL_TRAITS
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP17_LOGICAL_TRAITS
    #define LBAL_LIBCPP17_LOGICAL_TRAITS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_LOGICAL_TRAITS: <type_traits> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_LOGICAL_TRAITS

#if LBAL_LIBCPP17_MAKE_FROM_TUPLE
  #if LBAL_HAS_HEADER_TUPLE != 1
    #undef LBAL_LIBCPP17_MAKE_FROM_TUPLE
    #define LBAL_LIBCPP17_MAKE_FROM_TUPLE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_MAKE_FROM_TUPLE: <tuple> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_MAKE_FROM_TUPLE

#if LBAL_LIBCPP17_MAP_TRY_EMPLACE
  #if LBAL_HAS_HEADER_MAP != 1
    #undef LBAL_LIBCPP17_MAP_TRY_EMPLACE
    #define LBAL_LIBCPP17_MAP_TRY_EMPLACE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_MAP_TRY_EMPLACE: <map> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_MAP_TRY_EMPLACE

#if LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS
  #if LBAL_HAS_HEADER_CMATH != 1
    #undef LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS
    #define LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS: <cmath> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_MATH_SPECIAL_FUNCTIONS

#if LBAL_LIBCPP17_MEMORY_RESOURCE
  #if LBAL_HAS_HEADER_MEMORY_RESOURCE != 1
    #undef LBAL_LIBCPP17_MEMORY_RESOURCE
    #define LBAL_LIBCPP17_MEMORY_RESOURCE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_MEMORY_RESOURCE: <memory_resource> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_MEMORY_RESOURCE

#if LBAL_LIBCPP17_NODE_EXTRACT
  #if LBAL_HAS_HEADER_MAP != 1                                                 \
      || LBAL_HAS_HEADER_SET != 1                                              \
      || LBAL_HAS_HEADER_UNORDERED_MAP != 1                                    \
      || LBAL_HAS_HEADER_UNORDERED_SET != 1
    #undef LBAL_LIBCPP17_NODE_EXTRACT
    #define LBAL_LIBCPP17_NODE_EXTRACT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_NODE_EXTRACT: at least one of {<map>, "
    "<set>, <unordered_map>, <unordered_set>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_NODE_EXTRACT

#if LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS
  #if LBAL_HAS_HEADER_ARRAY != 1                                               \
      || LBAL_HAS_HEADER_DEQUE != 1                                            \
      || LBAL_HAS_HEADER_FORWARD_LIST != 1                                     \
      || LBAL_HAS_HEADER_ITERATOR != 1                                         \
      || LBAL_HAS_HEADER_LIST != 1                                             \
      || LBAL_HAS_HEADER_MAP != 1                                              \
      || LBAL_HAS_HEADER_REGEX != 1                                            \
      || LBAL_HAS_HEADER_SET != 1                                              \
      || LBAL_HAS_HEADER_STRING != 1                                           \
      || LBAL_HAS_HEADER_UNORDERED_MAP != 1                                    \
      || LBAL_HAS_HEADER_UNORDERED_SET != 1                                    \
      || LBAL_HAS_HEADER_VECTOR != 1
    #undef LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS
    #define LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS: at least one "
    "of {<array>, <deque>, <forward_list>, <iterator>, <list>, <map>, <regex>, "
    "<set>, <string>, <unordered_map>, <unordered_set>, <vector>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_NONMEMBER_CONTAINER_ACCESS

#if LBAL_LIBCPP17_NOT_FN
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1
    #undef LBAL_LIBCPP17_NOT_FN
    #define LBAL_LIBCPP17_NOT_FN 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_NOT_FN: <functional> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_NOT_FN

#if LBAL_LIBCPP17_OPTIONAL
  #if LBAL_HAS_HEADER_OPTIONAL != 1
    #undef LBAL_LIBCPP17_OPTIONAL
    #define LBAL_LIBCPP17_OPTIONAL 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_OPTIONAL: <optional> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_OPTIONAL

#if LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL
  #if LBAL_HAS_HEADER_OPTIONAL != 1
    #undef LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL
    #define LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL: <optional> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_OPTIONAL_GREATER_EQUAL

#if LBAL_LIBCPP17_OPTIONAL_INTERFACE
  #if LBAL_HAS_HEADER_OPTIONAL != 1
    #undef LBAL_LIBCPP17_OPTIONAL_INTERFACE
    #define LBAL_LIBCPP17_OPTIONAL_INTERFACE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_OPTIONAL_INTERFACE: <optional> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_OPTIONAL_INTERFACE

#if LBAL_LIBCPP17_PARALLEL_ALGORITHM
  #if LBAL_HAS_HEADER_ALGORITHM != 1                                           \
      || LBAL_HAS_HEADER_MEMORY != 1                                           \
      || LBAL_HAS_HEADER_NUMERIC != 1
    #undef LBAL_LIBCPP17_PARALLEL_ALGORITHM
    #define LBAL_LIBCPP17_PARALLEL_ALGORITHM 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_PARALLEL_ALGORITHM: at least one of "
    "{<algorithm>, <memory>, <numeric>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_PARALLEL_ALGORITHM

#if LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS
    #define LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS: <memory> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_RAW_MEMORY_ALGORITHMS

#if LBAL_LIBCPP17_SAMPLE
  #if LBAL_HAS_HEADER_ALGORITHM != 1
    #undef LBAL_LIBCPP17_SAMPLE
    #define LBAL_LIBCPP17_SAMPLE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_SAMPLE: <algorithm> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_SAMPLE

#if LBAL_LIBCPP17_SCOPED_LOCK
  #if LBAL_HAS_HEADER_MUTEX != 1
    #undef LBAL_LIBCPP17_SCOPED_LOCK
    #define LBAL_LIBCPP17_SCOPED_LOCK 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_SCOPED_LOCK: <mutex> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_SCOPED_LOCK

#if LBAL_LIBCPP17_SHARED_MUTEX
  #if LBAL_HAS_HEADER_SHARED_MUTEX != 1
    #undef LBAL_LIBCPP17_SHARED_MUTEX
    #define LBAL_LIBCPP17_SHARED_MUTEX 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_SHARED_MUTEX: <shared_mutex> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_SHARED_MUTEX

#if LBAL_LIBCPP17_SHARED_PTR_ARRAYS
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP17_SHARED_PTR_ARRAYS
    #define LBAL_LIBCPP17_SHARED_PTR_ARRAYS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_SHARED_PTR_ARRAYS: <memory> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_SHARED_PTR_ARRAYS

#if LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE
  #if LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE
    #define LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE: <memory> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_SHARED_PTR_WEAK_TYPE

#if LBAL_LIBCPP17_STRING_VIEW
  #if LBAL_HAS_HEADER_STRING != 1 || LBAL_HAS_HEADER_STRING_VIEW != 1
    #undef LBAL_LIBCPP17_STRING_VIEW
    #define LBAL_LIBCPP17_STRING_VIEW 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_STRING_VIEW: at least one of {<string>, "
    "<string_view>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_STRING_VIEW

#if LBAL_LIBCPP17_STRING_VIEW_INTERFACE
  #if LBAL_HAS_HEADER_STRING != 1 || LBAL_HAS_HEADER_STRING_VIEW != 1
    #undef LBAL_LIBCPP17_STRING_VIEW_INTERFACE
    #define LBAL_LIBCPP17_STRING_VIEW_INTERFACE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_STRING_VIEW_INTERFACE: at least one of "
    "{<string>, <string_view>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_STRING_VIEW_INTERFACE

#if LBAL_LIBCPP17_TO_CHARS
  #if LBAL_HAS_HEADER_CHARCONV != 1
    #undef LBAL_LIBCPP17_TO_CHARS
    #define LBAL_LIBCPP17_TO_CHARS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_TO_CHARS: <charconv> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_TO_CHARS

#if LBAL_LIBCPP17_TO_CHARS_FP
  #if LBAL_HAS_HEADER_CHARCONV != 1
    #undef LBAL_LIBCPP17_TO_CHARS_FP
    #define LBAL_LIBCPP17_TO_CHARS_FP 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_TO_CHARS_FP: <charconv> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_TO_CHARS_FP

#if LBAL_LIBCPP17_TO_CHARS_INTEGER
  #if LBAL_HAS_HEADER_CHARCONV != 1
    #undef LBAL_LIBCPP17_TO_CHARS_INTEGER
    #define LBAL_LIBCPP17_TO_CHARS_INTEGER 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_TO_CHARS_INTEGER: <charconv> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_TO_CHARS_INTEGER

#if LBAL_LIBCPP17_TRANSPARENT_OPERATORS
  #if LBAL_HAS_HEADER_FUNCTIONAL != 1 || LBAL_HAS_HEADER_MEMORY != 1
    #undef LBAL_LIBCPP17_TRANSPARENT_OPERATORS
    #define LBAL_LIBCPP17_TRANSPARENT_OPERATORS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_TRANSPARENT_OPERATORS: at least one of "
    "{<functional>, <memory>} not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_TRANSPARENT_OPERATORS

#if LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES
    #define LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES: "
    "<type_traits> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_TYPE_TRAIT_VARIABLE_TEMPLATES

#if LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS
  #if LBAL_HAS_HEADER_EXCEPTION != 1
    #undef LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS
    #define LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS: <exception> not "
    "found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_UNCAUGHT_EXCEPTIONS

#if LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE
  #if LBAL_HAS_HEADER_UNORDERED_MAP != 1
    #undef LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE
    #define LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE: "
    "<unordered_map> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_UNORDERED_MAP_TRY_EMPLACE

#if LBAL_LIBCPP17_VARIANT
  #if LBAL_HAS_HEADER_VARIANT != 1
    #undef LBAL_LIBCPP17_VARIANT
    #define LBAL_LIBCPP17_VARIANT 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_VARIANT: <variant> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_VARIANT

#if LBAL_LIBCPP17_VOID_T
  #if LBAL_HAS_HEADER_TYPE_TRAITS != 1
    #undef LBAL_LIBCPP17_VOID_T
    #define LBAL_LIBCPP17_VOID_T 0
LBAL_CPP_WARNING(
    "Unable to validate LBAL_LIBCPP17_VOID_T: <type_traits> not found"
)
  #endif  //  LBAL_HAS_HEADER_ test
#endif    //  LBAL_LIBCPP17_VOID_T
