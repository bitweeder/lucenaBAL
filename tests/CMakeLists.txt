#[[#############################################################################

  Lucena Build Abstraction Library
  “lbalTest/CMakeLists.txt”
  Copyright © 2018-2026 Lucena
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
#   - minimum for `cxx_std_26` support in MSVC (3.30)
cmake_minimum_required (VERSION 3.30...4.3.2)


#[[#############################################################################
  configuration
#]]

include (FetchContent)

FetchContent_Declare (
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.17.0
)

# For Windows: Prevent overriding the parent project’s compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# For macOS: build fat binaries; this is only done for re-usability with non-
# CMake project tooling.
# set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64" CACHE INTERNAL "" FORCE)

FetchContent_MakeAvailable(googletest)


#[[#############################################################################
  set up targets
#]]

include (GoogleTest)

add_executable (lbalTest)

target_sources (
	lbalTest
    PRIVATE
      lbalFeatureTest.cpp
      lbalFormattingTest.cpp
)

target_include_directories (
	lbalTest
    PRIVATE
		$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
)

# FIXME - bitweeder
# Needs refinement. Or elimination.
if(MSVC)
  target_compile_options (
    lbalTest
    PRIVATE
      $<$<CXX_COMPILER_ID:MSVC>:/std:c++latest>
      $<$<CXX_COMPILER_ID:MSVC>:/Zc:__cplusplus>
      $<$<CXX_COMPILER_ID:MSVC>:/W4>
      # Sources are UTF-8; without this, MSVC reads them in the system code page.
      $<$<CXX_COMPILER_ID:MSVC>:/utf-8>
  )
else()
  target_compile_features (
    lbalTest
      PRIVATE
          cxx_std_26
  )

  target_compile_options (
    lbalTest
    PRIVATE
      $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall>
      $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-pedantic>
  )
endif()

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

# Make sure every documented feature token has its test line and, for language
# tokens, its external-definition guard.
add_test (
	NAME lbalTokenCoverage
	COMMAND
		${CMAKE_COMMAND}
			-DLBAL_SOURCE_DIR=${PROJECT_SOURCE_DIR}
			-P ${CMAKE_CURRENT_LIST_DIR}/lbalTokenCoverage.cmake
)


#[[#############################################################################
  optional feature-detection tests

  Two kinds of optional test check that feature tokens tell the truth:
    - false-positive tests (`LBAL_BUILD_FALSE_POSITIVE_TESTS`): a nonzero token
      must be backed by a working feature
    - false-negative tests (`LBAL_BUILD_FALSE_NEGATIVE_TESTS`): a token that is
      `0` must not be backed by a working feature; see
      `lbalFalseNegative.cmake`
  `LBAL_BUILD_ALL_FEATURE_TESTS` turns both on. Both reuse the same per-token
  probes: the gtest snippets in `fragments/lbalFalsePositiveTest-*.inc` and the
  compile-only probes in `probes/`.

  Each kind takes a list of Standard modes (numbers of 17 or later and/or
  `latest`, the newest Standard the compiler supports). For each mode, the
  false-positive tests build
    - `lbalFalsePositiveTest-cxx<NN>`: gtest soft probes, registered with the
      prefix `cxx<NN>.`
    - `lbalFalsePositiveProbes-cxx<NN>`: an object library of hard probes, one
      token per file; it’s never linked, so it only needs to compile. It’s
      excluded from the default build, so a hard false positive can’t stop the
      tests from building; build the `lbalFalsePositiveProbes` target instead.

  None of these targets link `lucenaBAL`, as its interface requires C++26; they
  take its include directories and definitions instead.
#]]

if (LBAL_BUILD_ALL_FEATURE_TESTS OR LBAL_BUILD_FALSE_POSITIVE_TESTS)
	set (LBAL_RUN_FALSE_POSITIVE_TESTS ON)
endif ()

if (LBAL_BUILD_ALL_FEATURE_TESTS OR LBAL_BUILD_FALSE_NEGATIVE_TESTS)
	set (LBAL_RUN_FALSE_NEGATIVE_TESTS ON)
endif ()

if (LBAL_RUN_FALSE_POSITIVE_TESTS OR LBAL_RUN_FALSE_NEGATIVE_TESTS)
	if (CMAKE_CROSSCOMPILING AND NOT CMAKE_CROSSCOMPILING_EMULATOR)
		message (WARNING "The feature-detection tests are enabled while cross-compiling without CMAKE_CROSSCOMPILING_EMULATOR, so their test executables can’t run here. Turn them off, or set an emulator.")
	endif ()

	# Resolve a list of Standard modes from the cache variable named by
	# `LBAL_list_var`: `latest` becomes the newest Standard the compiler is
	# known to support. Add new Standards to the front of the candidate list as
	# CMake learns them.
	function (lbal_resolve_standards LBAL_out_var LBAL_list_var)
		set (LBAL_resolved)

		foreach (LBAL_STD IN LISTS ${LBAL_list_var})
			if (LBAL_STD STREQUAL "latest")
				set (LBAL_STD)

				foreach (LBAL_CANDIDATE IN ITEMS 26 23 20 17)
					if ("cxx_std_${LBAL_CANDIDATE}" IN_LIST CMAKE_CXX_COMPILE_FEATURES)
						set (LBAL_STD ${LBAL_CANDIDATE})
						break ()
					endif ()
				endforeach ()

				if (NOT LBAL_STD)
					message (FATAL_ERROR "${LBAL_list_var}: the compiler doesn’t support C++17, the minimum for GoogleTest")
				endif ()
			elseif (NOT LBAL_STD MATCHES "^[0-9]+$" OR LBAL_STD LESS 17)
				message (FATAL_ERROR "${LBAL_list_var}: `${LBAL_STD}` must be `latest` or a Standard of at least 17, the minimum for GoogleTest")
			endif ()

			list (APPEND LBAL_resolved ${LBAL_STD})
		endforeach ()

		list (REMOVE_DUPLICATES LBAL_resolved)
		set (${LBAL_out_var} ${LBAL_resolved} PARENT_SCOPE)
	endfunction ()

	# Strict options for code that must fail when a feature is only an
	# extension or an attribute is ignored. They’re plain lists, rather than
	# generator expressions, so `try_compile` can use them too.
	set (LBAL_PROBE_STRICT_OPTIONS)
	set (LBAL_PROBE_STRICT_DEFINITIONS LBAL_CONFIG_enable_pedantic_warnings=0)

	if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		set (LBAL_PROBE_STRICT_OPTIONS -pedantic-errors -Werror=attributes)
	elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
		set (LBAL_PROBE_STRICT_OPTIONS -pedantic-errors -Werror=unknown-attributes -Werror=ignored-attributes)
	elseif (MSVC)
		set (LBAL_PROBE_STRICT_OPTIONS /we5030 /permissive-)
	endif ()

	# Extra options for the compile-only probes: a feature the compiler warns
	# about by default doesn’t count as available. gcc, for one, accepts some
	# later-Standard features in older modes with a warning that no narrower
	# option turns into an error. Deprecation warnings stay warnings, since a
	# deprecated facility is still there. The gtest fragments don’t get these,
	# as GoogleTest’s own headers can warn. MSVC isn’t covered: `/WX` with its
	# default warning level hasn’t been tried.
	set (LBAL_PROBE_WERROR_OPTIONS)

	if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
		set (LBAL_PROBE_WERROR_OPTIONS -Werror -Wno-error=deprecated-declarations -Wno-error=deprecated)
	endif ()

	# Per-mode compile options that every probe target needs.
	function (lbal_probe_options LBAL_out_var LBAL_std)
		set (LBAL_options)

		if (MSVC)
			if (LBAL_std GREATER 20)
				list (APPEND LBAL_options /std:c++latest)
			endif ()

			# Sources are UTF-8; without `/utf-8`, MSVC reads them in the system
			# code page, which breaks probes with non-ASCII literals.
			list (APPEND LBAL_options /Zc:__cplusplus /utf-8)
		endif ()

		set (${LBAL_out_var} ${LBAL_options} PARENT_SCOPE)
	endfunction ()

	# Set up a target that compiles probes in the given Standard mode.
	function (lbal_configure_probe_target LBAL_target LBAL_std LBAL_folder)
		target_include_directories (
			${LBAL_target}
				PRIVATE
					${PROJECT_SOURCE_DIR}/include
					${CMAKE_CURRENT_FUNCTION_LIST_DIR}
					$<TARGET_PROPERTY:lucenaBAL,INTERFACE_INCLUDE_DIRECTORIES>
		)

		target_compile_definitions (
			${LBAL_target}
				PRIVATE
					$<TARGET_PROPERTY:lucenaBAL,INTERFACE_COMPILE_DEFINITIONS>
					LBAL_CONFIG_unit=1
		)

		set_target_properties (
			${LBAL_target}
				PROPERTIES
					CXX_STANDARD ${LBAL_std}
					CXX_STANDARD_REQUIRED ON
					CXX_EXTENSIONS OFF
					FOLDER "${LBAL_folder}"
		)

		lbal_probe_options (LBAL_options ${LBAL_std})
		target_compile_options (${LBAL_target} PRIVATE ${LBAL_options})
	endfunction ()

	# libstdc++ keeps some facilities, such as `<stacktrace>`, in a separate
	# `stdc++exp` library; link it when it’s there.
	include (CheckCXXSourceCompiles)
	set (CMAKE_REQUIRED_LIBRARIES stdc++exp)
	check_cxx_source_compiles ("int main() { return 0; }" LBAL_HAVE_STDCXXEXP)
	unset (CMAKE_REQUIRED_LIBRARIES)
endif ()

if (LBAL_RUN_FALSE_POSITIVE_TESTS)
	file (
		GLOB_RECURSE LBAL_FALSE_POSITIVE_PROBES
		CONFIGURE_DEPENDS
			${CMAKE_CURRENT_LIST_DIR}/probes/*.cpp
	)

	lbal_resolve_standards (LBAL_FP_STANDARDS LBAL_FALSE_POSITIVE_TEST_STANDARDS)
	list (JOIN LBAL_FP_STANDARDS ", C++" LBAL_FP_STANDARDS_TEXT)
	message (STATUS "False-positive tests: C++${LBAL_FP_STANDARDS_TEXT}")

	add_custom_target (lbalFalsePositiveProbes)

	foreach (LBAL_STD IN LISTS LBAL_FP_STANDARDS)
		set (LBAL_FP_TEST lbalFalsePositiveTest-cxx${LBAL_STD})
		set (LBAL_FP_PROBES lbalFalsePositiveProbes-cxx${LBAL_STD})

		add_executable (${LBAL_FP_TEST} lbalFalsePositiveTest.cpp)
		add_library (
			${LBAL_FP_PROBES}
			OBJECT
			EXCLUDE_FROM_ALL
				${LBAL_FALSE_POSITIVE_PROBES}
		)
		add_dependencies (lbalFalsePositiveProbes ${LBAL_FP_PROBES})

		lbal_configure_probe_target (${LBAL_FP_TEST} ${LBAL_STD} "false-positive")
		lbal_configure_probe_target (${LBAL_FP_PROBES} ${LBAL_STD} "false-positive")

		target_link_libraries (${LBAL_FP_TEST} PRIVATE gtest_main)

		if (LBAL_HAVE_STDCXXEXP)
			target_link_libraries (${LBAL_FP_TEST} PRIVATE stdc++exp)
		endif ()

		# Make ignored attributes and extensions errors, so they count as false
		# positives; lucenaBAL’s own diagnostics are turned off so they don’t.
		target_compile_definitions (
			${LBAL_FP_PROBES} PRIVATE ${LBAL_PROBE_STRICT_DEFINITIONS}
		)
		target_compile_options (
			${LBAL_FP_PROBES}
				PRIVATE ${LBAL_PROBE_STRICT_OPTIONS} ${LBAL_PROBE_WERROR_OPTIONS}
		)

		gtest_discover_tests (${LBAL_FP_TEST} TEST_PREFIX "cxx${LBAL_STD}.")
	endforeach ()
endif ()

if (LBAL_RUN_FALSE_NEGATIVE_TESTS)
	include (${CMAKE_CURRENT_LIST_DIR}/lbalFalseNegative.cmake)
endif ()


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
