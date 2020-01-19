#[[#############################################################################

    Lucena Build Abstraction Library
    “lbalTest/CMakeLists.txt”
    Copyright © 2018-2020 Lucena
    All Rights Reserved

    This file is distributed under the University of Illinois Open Source
    License. See license/License.txt for details.

    This script expects to be called by the lucenaBAL root script; in
    particular, default values for various properties are assumed to have been
    previously set.

##############################################################################]]


#[[#############################################################################
    initialization
#]]

# This minimum is for
#   - FetchContent (3.11)
#   - CONFIGURE_DEPENDS for usable globs (3.12),
#   - correct Xcode project generation (3.15)
cmake_minimum_required (VERSION 3.15)


#[[#############################################################################
    configuration
#]]

include (FetchContent)

FetchContent_Declare (
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.8.1
)

FetchContent_GetProperties (googletest)

if (NOT googletest_POPULATED)
    FetchContent_Populate (googletest)

    set (CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1 CACHE BOOL "")
    add_subdirectory (
        ${googletest_SOURCE_DIR}
        ${googletest_BINARY_DIR}
        EXCLUDE_FROM_ALL
    )
    unset (CMAKE_SUPPRESS_DEVELOPER_WARNINGS)
endif()


#[[#############################################################################
    set up targets
#]]

include (GoogleTest)

add_executable (lbalTest)

target_sources (
	lbalTest
    PRIVATE
        lbalTest.cpp
)

target_include_directories (
	lbalTest
    PRIVATE
		$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
)

# target_compile_features (
# 	lbalTest
#     PRIVATE
#         cxx_std_17
# )

# __FIXME__ Needs refinement. Or elimination.
target_compile_options (
  lbalTest
  PRIVATE
  	$<$<CXX_COMPILER_ID:MSVC>:/std:c++17>
  	$<$<CXX_COMPILER_ID:MSVC>:/Zc:__cplusplus>
	$<$<CXX_COMPILER_ID:MSVC>:/W4>
	$<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall>
	$<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-pedantic>
)

target_compile_definitions (
	lbalTest
    PRIVATE
        LBAL_CONFIG_unit=1
)

target_link_libraries (
	lbalTest
    PUBLIC
        lucenaBAL
        gtest
        gtest_main
)

gtest_discover_tests (lbalTest)


#[[#############################################################################
    clean up
#]]

# Keep the cache and GUI clean.
mark_as_advanced (
    BUILD_GTEST
    gtest_build_samples
    gtest_build_tests
    gtest_disable_pthreads
    gtest_force_shared_crt
    gtest_hide_internal_symbols
)

# Prettify generated IDE projects
set_target_properties (
	gtest
	gtest_main
    PROPERTIES
        FOLDER "extern"
)
