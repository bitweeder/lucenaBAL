#[[#############################################################################

  Lucena Build Abstraction Library
  “lbalTest/CMakeLists.txt”
  Copyright © 2018-2024 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

	This script expects to be called by the lucenaBAL root script; in particular, 
	values for various properties are assumed to have been previously set.

##############################################################################]]


#[[#############################################################################
  initialization
#]]

# This minimum is for
#   - FetchContent (3.11)
#   - CONFIGURE_DEPENDS for usable globs (3.12)
#   - improved FetchContent handling (3.14))
#   - correct Xcode project generation (3.15)
cmake_minimum_required (VERSION 3.15...3.30)


#[[#############################################################################
  configuration
#]]

include (FetchContent)

FetchContent_Declare (
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)

# For Windows: Prevent overriding the parent project’s compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# For macOS: build fat binaries; this is only done for re-usability with non-
# CMake project tooling.
set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64" CACHE INTERNAL "" FORCE)

FetchContent_MakeAvailable(googletest)

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
#         cxx_std_26
# )

# __FIXME__ Needs refinement. Or elimination.
target_compile_options (
  lbalTest
  PRIVATE
  	$<$<CXX_COMPILER_ID:MSVC>:/std:c++23>
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
