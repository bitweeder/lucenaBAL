#[[#############################################################################

  Lucena Build Abstraction Library
  “lbalTest/lbalFalseNegative.cmake”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

	Configure the optional false-negative tests; included from
	`tests/CMakeLists.txt`, which defines the shared helpers used here.

	A false negative is a token that is `0` although its feature works. These
	tests reuse the false-positive probes: for every token through C++23 that is
	`0`, its probe is compiled with the token forced on.
		- If it doesn’t compile, the token is right.
		- If it’s a compile-only probe and it compiles, that’s a false negative.
		- If it’s a gtest probe and it compiles, `lbalFalseNegativeTest.cpp` runs
			it; if it passes, that’s a false negative.

	Compile failure is the expected outcome, so the compiles happen here, at
	configure time, with `try_compile`, and the results are handed to the test
	executable in a generated header. Results are cached by content, so a
	reconfigure only retries tokens whose probe, or lucenaBAL itself, changed.

	Probes marked `LBAL_FP_SMOKE` can’t tell whether their feature is missing, so
	they’re never tried and their tokens are reported as skipped.

##############################################################################]]

set (LBAL_FN_STANDARD_TAGS cpp03 cpp11 cpp14 cpp17 cpp20 cpp23 libcpp14 libcpp17 libcpp20 libcpp23)
set (LBAL_FN_FRAGMENTS_DIR "${PROJECT_SOURCE_DIR}/include/lucenaBAL/details/fragments")
set (LBAL_FN_TESTS_DIR "${CMAKE_CURRENT_LIST_DIR}")

lbal_resolve_standards (LBAL_FN_STANDARDS LBAL_FALSE_NEGATIVE_TEST_STANDARDS)
list (JOIN LBAL_FN_STANDARDS ", C++" LBAL_FN_STANDARDS_TEXT)
message (STATUS "False-negative tests: C++${LBAL_FN_STANDARDS_TEXT}")

#	Everything a result depends on; editing any of it reruns CMake.
file (
	GLOB_RECURSE LBAL_FN_INPUTS
	CONFIGURE_DEPENDS
		${PROJECT_SOURCE_DIR}/include/lucenaBAL/*.hpp
		${PROJECT_SOURCE_DIR}/include/lucenaBAL/*.inc
		${LBAL_FN_TESTS_DIR}/probes/*.cpp
		${LBAL_FN_TESTS_DIR}/fragments/lbalFalsePositiveTest-*.inc
)
list (APPEND LBAL_FN_INPUTS ${LBAL_FN_TESTS_DIR}/lbalFalsePositiveTest.hpp)
set_property (DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS ${LBAL_FN_INPUTS})

#	The include directories and definitions the probe targets get, as plain
#	lists for `try_compile`.
set (LBAL_FN_INCLUDES
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include/lucenaBAL
	${LBAL_FN_TESTS_DIR}
	${googletest_SOURCE_DIR}/googletest/include
)

get_target_property (LBAL_FN_INTERFACE_DEFINITIONS lucenaBAL INTERFACE_COMPILE_DEFINITIONS)
get_directory_property (LBAL_FN_DIRECTORY_DEFINITIONS DIRECTORY ${PROJECT_SOURCE_DIR} COMPILE_DEFINITIONS)
set (LBAL_FN_DEFINITIONS)

foreach (LBAL_DEFINITION IN LISTS LBAL_FN_INTERFACE_DEFINITIONS LBAL_FN_DIRECTORY_DEFINITIONS)
	#	Only what can change a token matters; the packaging strings don’t.
	if (LBAL_DEFINITION MATCHES "^LBAL_(TARGET|CONFIG)_")
		list (APPEND LBAL_FN_DEFINITIONS "-D${LBAL_DEFINITION}")
	endif ()
endforeach ()

foreach (LBAL_DEFINITION IN ITEMS LBAL_CONFIG_unit=1 ${LBAL_PROBE_STRICT_DEFINITIONS})
	list (APPEND LBAL_FN_DEFINITIONS "-D${LBAL_DEFINITION}")
endforeach ()

#	The part of every cache key that every result depends on: the toolchain,
#	the options, lucenaBAL’s headers and the probe helpers. Each token’s key
#	adds its own probe or fragment, so editing one probe only retries its token.
set (LBAL_FN_KEY_BASE "${CMAKE_CXX_COMPILER_ID};${CMAKE_CXX_COMPILER_VERSION};${CMAKE_CXX_COMPILER};${LBAL_PROBE_STRICT_OPTIONS};${LBAL_FN_DEFINITIONS}")

foreach (LBAL_INPUT IN LISTS LBAL_FN_INPUTS)
	if (NOT LBAL_INPUT MATCHES "/tests/(probes|fragments)/")
		file (SHA1 ${LBAL_INPUT} LBAL_INPUT_HASH)
		string (APPEND LBAL_FN_KEY_BASE ";${LBAL_INPUT_HASH}")
	endif ()
endforeach ()

#	Compile `LBAL_content` as a static library in mode `LBAL_std`; the result
#	is `TRUE` or `FALSE`. With `COPY`, the library is kept there; `OPTIONS` adds
#	compile options.
function (lbal_fn_try LBAL_out_var LBAL_std LBAL_content)
	cmake_parse_arguments (LBAL "" "COPY" "OPTIONS" ${ARGN})
	lbal_probe_options (LBAL_options ${LBAL_std})
	set (CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
	set (LBAL_copy_args)

	if (LBAL_COPY)
		set (LBAL_copy_args COPY_FILE ${LBAL_COPY})
	endif ()

	try_compile (
		LBAL_result
		SOURCE_FROM_CONTENT lbalFalseNegative.cpp "${LBAL_content}"
		CMAKE_FLAGS "-DINCLUDE_DIRECTORIES=${LBAL_FN_INCLUDES}"
		COMPILE_DEFINITIONS ${LBAL_FN_DEFINITIONS} ${LBAL_PROBE_STRICT_OPTIONS} ${LBAL_options} ${LBAL_OPTIONS}
		CXX_STANDARD ${LBAL_std}
		CXX_STANDARD_REQUIRED ON
		CXX_EXTENSIONS OFF
		NO_CACHE
		${LBAL_copy_args}
	)

	set (${LBAL_out_var} ${LBAL_result} PARENT_SCOPE)
endfunction ()

#	Cached `lbal_fn_try`: the cache entry holds the key and the result, so a
#	changed input means a retry. Extra arguments go to `lbal_fn_try`; they
#	must be part of the key too.
function (lbal_fn_cached_try LBAL_out_var LBAL_name LBAL_key LBAL_std LBAL_content)
	string (SHA1 LBAL_hash "${LBAL_key}")
	set (LBAL_entry "LBAL_FN_CACHE_${LBAL_name}")

	if (DEFINED CACHE{${LBAL_entry}} AND "$CACHE{${LBAL_entry}}" MATCHES "^${LBAL_hash}\\|(.*)$")
		set (${LBAL_out_var} ${CMAKE_MATCH_1} PARENT_SCOPE)
		return ()
	endif ()

	lbal_fn_try (LBAL_result ${LBAL_std} "${LBAL_content}" ${ARGN})
	set (${LBAL_entry} "${LBAL_hash}|${LBAL_result}" CACHE INTERNAL "")
	set (${LBAL_out_var} ${LBAL_result} PARENT_SCOPE)
endfunction ()

#	List every in-scope token with its kind: HARD (a file in `probes/`), SOFT (an
#	`LBAL_FP_TEST` in its fragment) or NONE. Smoke probes are recorded too.
set (LBAL_FN_TOKENS)

foreach (LBAL_TAG IN LISTS LBAL_FN_STANDARD_TAGS)
	file (READ "${LBAL_FN_FRAGMENTS_DIR}/lbalFeatureSetup-overview-${LBAL_TAG}.inc" LBAL_OVERVIEW)
	string (REGEX MATCHALL "#define LBAL_[A-Z0-9_]+ 0" LBAL_DEFINES "${LBAL_OVERVIEW}")
	file (READ "${LBAL_FN_TESTS_DIR}/fragments/lbalFalsePositiveTest-${LBAL_TAG}.inc" LBAL_FRAGMENT)
	string (TOUPPER ${LBAL_TAG} LBAL_STD_TAG)

	foreach (LBAL_DEFINE IN LISTS LBAL_DEFINES)
		string (REGEX REPLACE "#define LBAL_${LBAL_STD_TAG}_([A-Z0-9_]+) 0" "\\1" LBAL_NAME "${LBAL_DEFINE}")
		set (LBAL_PROBE "${LBAL_FN_TESTS_DIR}/probes/${LBAL_TAG}/${LBAL_NAME}.cpp")
		set (LBAL_SMOKE 0)
		string (FIND "${LBAL_FRAGMENT}" "LBAL_FP_TEST(${LBAL_STD_TAG}, ${LBAL_NAME})" LBAL_AT)

		if (EXISTS ${LBAL_PROBE})
			set (LBAL_KIND HARD)
			file (READ ${LBAL_PROBE} LBAL_TEXT)

			if (LBAL_TEXT MATCHES "LBAL_FP_SMOKE")
				set (LBAL_SMOKE 1)
			endif ()
		elseif (NOT LBAL_AT EQUAL -1)
			set (LBAL_KIND SOFT)

			#	The test’s text runs up to the next test.
			string (SUBSTRING "${LBAL_FRAGMENT}" ${LBAL_AT} -1 LBAL_TEXT)
			string (LENGTH "LBAL_FP_TEST(" LBAL_SKIP)
			string (SUBSTRING "${LBAL_TEXT}" ${LBAL_SKIP} -1 LBAL_REST)
			string (FIND "${LBAL_REST}" "LBAL_FP_TEST(" LBAL_NEXT)

			if (NOT LBAL_NEXT EQUAL -1)
				string (SUBSTRING "${LBAL_REST}" 0 ${LBAL_NEXT} LBAL_REST)
			endif ()

			if (LBAL_REST MATCHES "LBAL_FP_SMOKE")
				set (LBAL_SMOKE 1)
			endif ()
		else ()
			set (LBAL_KIND NONE)
		endif ()

		list (APPEND LBAL_FN_TOKENS "${LBAL_STD_TAG}|${LBAL_NAME}|${LBAL_TAG}|${LBAL_KIND}|${LBAL_SMOKE}")
	endforeach ()
endforeach ()

foreach (LBAL_STD IN LISTS LBAL_FN_STANDARDS)
	set (LBAL_KEY_STD "${LBAL_FN_KEY_BASE};${LBAL_STD}")
	string (SHA1 LBAL_VALUES_KEY "${LBAL_KEY_STD};values")
	set (LBAL_VALUES_ENTRY "LBAL_FN_CACHE_cxx${LBAL_STD}_values")

	#	Find which tokens are `0` without running anything: each value is
	#	embedded as a string in a library, then read back.
	if (DEFINED CACHE{${LBAL_VALUES_ENTRY}} AND "$CACHE{${LBAL_VALUES_ENTRY}}" MATCHES "^${LBAL_VALUES_KEY}\\|(.*)$")
		set (LBAL_ZERO_TOKENS "${CMAKE_MATCH_1}")
	else ()
		set (LBAL_SOURCE "#include <lucenaBAL/lucenaBAL.hpp>\n#define LBAL_FN_STR2(x) #x\n#define LBAL_FN_STR(x) LBAL_FN_STR2(x)\n")

		foreach (LBAL_ENTRY IN LISTS LBAL_FN_TOKENS)
			string (REPLACE "|" ";" LBAL_FIELDS "${LBAL_ENTRY}")
			list (GET LBAL_FIELDS 0 LBAL_STD_TAG)
			list (GET LBAL_FIELDS 1 LBAL_NAME)
			set (LBAL_TOKEN "LBAL_${LBAL_STD_TAG}_${LBAL_NAME}")
			string (APPEND LBAL_SOURCE "extern const char lbal_fn_${LBAL_TOKEN}[] = \"LBAL_FN:${LBAL_TOKEN}=\" LBAL_FN_STR(${LBAL_TOKEN});\n")
		endforeach ()

		set (LBAL_LIBRARY "${CMAKE_CURRENT_BINARY_DIR}/lbalFalseNegative-cxx${LBAL_STD}/values.lib")
		lbal_fn_try (LBAL_OK ${LBAL_STD} "${LBAL_SOURCE}" COPY ${LBAL_LIBRARY})

		if (NOT LBAL_OK)
			message (FATAL_ERROR "False-negative tests: couldn’t read the token values for C++${LBAL_STD}")
		endif ()

		file (STRINGS ${LBAL_LIBRARY} LBAL_VALUES REGEX "LBAL_FN:LBAL_[A-Z0-9_]+=")
		set (LBAL_ZERO_TOKENS)

		foreach (LBAL_VALUE IN LISTS LBAL_VALUES)
			if (LBAL_VALUE MATCHES "LBAL_FN:(LBAL_[A-Z0-9_]+)=0$")
				list (APPEND LBAL_ZERO_TOKENS ${CMAKE_MATCH_1})
			endif ()
		endforeach ()

		set (${LBAL_VALUES_ENTRY} "${LBAL_VALUES_KEY}|${LBAL_ZERO_TOKENS}" CACHE INTERNAL "")
	endif ()

	#	A fragment that doesn’t compile under the strict options, with nothing
	#	forced, would make every forced try fail, so check that first.
	set (LBAL_BROKEN_TAGS)

	foreach (LBAL_TAG IN LISTS LBAL_FN_STANDARD_TAGS)
		file (SHA1 "${LBAL_FN_TESTS_DIR}/fragments/lbalFalsePositiveTest-${LBAL_TAG}.inc" LBAL_FRAGMENT_HASH)
		lbal_fn_cached_try (
			LBAL_OK
			"cxx${LBAL_STD}_baseline_${LBAL_TAG}"
			"${LBAL_KEY_STD};baseline;${LBAL_TAG};${LBAL_FRAGMENT_HASH}"
			${LBAL_STD}
			"#include \"lbalFalsePositiveTest.hpp\"\n#include \"fragments/lbalFalsePositiveTest-${LBAL_TAG}.inc\"\n"
		)

		if (NOT LBAL_OK)
			list (APPEND LBAL_BROKEN_TAGS ${LBAL_TAG})
			message (WARNING "False-negative tests: fragments/lbalFalsePositiveTest-${LBAL_TAG}.inc doesn’t compile in C++${LBAL_STD} with the strict options, so its gtest probes are reported as skipped")
		endif ()
	endforeach ()

	#	Try each zero-valued token’s probe with the token forced on.
	set (LBAL_SOFT_LIST)
	set (LBAL_HARD_LIST)
	set (LBAL_NONE_LIST)
	set (LBAL_FORCE)
	set (LBAL_TRIED 0)
	set (LBAL_COMPILED 0)

	foreach (LBAL_ENTRY IN LISTS LBAL_FN_TOKENS)
		string (REPLACE "|" ";" LBAL_FIELDS "${LBAL_ENTRY}")
		list (GET LBAL_FIELDS 0 LBAL_STD_TAG)
		list (GET LBAL_FIELDS 1 LBAL_NAME)
		list (GET LBAL_FIELDS 2 LBAL_TAG)
		list (GET LBAL_FIELDS 3 LBAL_KIND)
		list (GET LBAL_FIELDS 4 LBAL_SMOKE)
		set (LBAL_TOKEN "LBAL_${LBAL_STD_TAG}_${LBAL_NAME}")

		if (LBAL_KIND STREQUAL "NONE")
			string (APPEND LBAL_NONE_LIST " \\\n  X(${LBAL_STD_TAG}, ${LBAL_NAME})")
			continue ()
		endif ()

		#	0: doesn’t compile (or wasn’t tried); 1: compiles; 2: can’t tell
		set (LBAL_STATE 0)

		if (LBAL_TOKEN IN_LIST LBAL_ZERO_TOKENS AND NOT LBAL_SMOKE)
			if (LBAL_KIND STREQUAL "SOFT" AND LBAL_TAG IN_LIST LBAL_BROKEN_TAGS)
				set (LBAL_STATE 2)
			else ()
				#	Compile-only probes are built with warnings as errors, as
				#	they are for the false-positive tests.
				if (LBAL_KIND STREQUAL "HARD")
					set (LBAL_INCLUDE "<lucenaBAL/lucenaBAL.hpp>")
					set (LBAL_PROBE "probes/${LBAL_TAG}/${LBAL_NAME}.cpp")
					set (LBAL_EXTRA ${LBAL_PROBE_WERROR_OPTIONS})
				else ()
					set (LBAL_INCLUDE "\"lbalFalsePositiveTest.hpp\"")
					set (LBAL_PROBE "fragments/lbalFalsePositiveTest-${LBAL_TAG}.inc")
					set (LBAL_EXTRA)
				endif ()

				file (SHA1 "${LBAL_FN_TESTS_DIR}/${LBAL_PROBE}" LBAL_PROBE_HASH)
				lbal_fn_cached_try (
					LBAL_OK
					"cxx${LBAL_STD}_${LBAL_TOKEN}"
					"${LBAL_KEY_STD};${LBAL_TOKEN};${LBAL_PROBE_HASH};${LBAL_EXTRA}"
					${LBAL_STD}
					"#include ${LBAL_INCLUDE}\n#undef ${LBAL_TOKEN}\n#define ${LBAL_TOKEN} 1\n#include \"${LBAL_PROBE}\"\n"
					OPTIONS ${LBAL_EXTRA}
				)
				math (EXPR LBAL_TRIED "${LBAL_TRIED} + 1")

				if (LBAL_OK)
					set (LBAL_STATE 1)
					math (EXPR LBAL_COMPILED "${LBAL_COMPILED} + 1")

					if (LBAL_KIND STREQUAL "SOFT")
						string (APPEND LBAL_FORCE "#undef ${LBAL_TOKEN}\n#define ${LBAL_TOKEN} 1\n")
					endif ()
				endif ()
			endif ()
		endif ()

		string (APPEND LBAL_${LBAL_KIND}_LIST " \\\n  X(${LBAL_STD_TAG}, ${LBAL_NAME}, ${LBAL_STATE}, ${LBAL_SMOKE})")
	endforeach ()

	list (LENGTH LBAL_ZERO_TOKENS LBAL_ZEROS)
	message (STATUS "False-negative tests, C++${LBAL_STD}: ${LBAL_ZEROS} tokens are 0; ${LBAL_TRIED} probes tried, ${LBAL_COMPILED} compiled")

	#	The generated headers are only rewritten when they change.
	set (LBAL_GENERATED_DIR "${CMAKE_CURRENT_BINARY_DIR}/lbalFalseNegative-cxx${LBAL_STD}")
	file (
		CONFIGURE OUTPUT "${LBAL_GENERATED_DIR}/lbalFalseNegative.hpp"
		CONTENT "//	Generated by lbalFalseNegative.cmake; don’t edit.\n#pragma once\n\n//	X(std, name, state, smoke); state is 0 (doesn’t compile), 1 (compiles)\n//	or 2 (can’t tell).\n#define LBAL_FN_SOFT(X)${LBAL_SOFT_LIST}\n\n#define LBAL_FN_HARD(X)${LBAL_HARD_LIST}\n\n//	X(std, name)\n#define LBAL_FN_NONE(X)${LBAL_NONE_LIST}\n"
		@ONLY
	)
	file (
		CONFIGURE OUTPUT "${LBAL_GENERATED_DIR}/lbalFalseNegativeForce.hpp"
		CONTENT "//	Generated by lbalFalseNegative.cmake; don’t edit.\n//	Forces on the tokens whose gtest probes compiled while the token was 0.\n${LBAL_FORCE}"
		@ONLY
	)

	set (LBAL_FN_TEST lbalFalseNegativeTest-cxx${LBAL_STD})
	add_executable (${LBAL_FN_TEST} ${LBAL_FN_TESTS_DIR}/lbalFalseNegativeTest.cpp)
	lbal_configure_probe_target (${LBAL_FN_TEST} ${LBAL_STD} "false-negative")
	target_include_directories (${LBAL_FN_TEST} PRIVATE ${LBAL_GENERATED_DIR})
	target_compile_definitions (${LBAL_FN_TEST} PRIVATE ${LBAL_PROBE_STRICT_DEFINITIONS})
	target_compile_options (${LBAL_FN_TEST} PRIVATE ${LBAL_PROBE_STRICT_OPTIONS})
	target_link_libraries (${LBAL_FN_TEST} PRIVATE gtest_main)

	if (LBAL_HAVE_STDCXXEXP)
		target_link_libraries (${LBAL_FN_TEST} PRIVATE stdc++exp)
	endif ()

	gtest_discover_tests (${LBAL_FN_TEST} TEST_PREFIX "cxx${LBAL_STD}.")
endforeach ()
