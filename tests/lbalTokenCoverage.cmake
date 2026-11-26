#[[#############################################################################

  Lucena Build Abstraction Library
  “lbalTest/lbalTokenCoverage.cmake”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

	Check that every feature token declared in an overview fragment has the
	supporting pieces that are easy to forget, and that the false-positive and
	false-negative tests cover it:
		- a `LBAL_DIAGNOSTIC_TEST(...)` line in the matching
	  	`tests/fragments/lbalFeatureTest-<std>.inc`
		- for language (`cpp*`) tokens, a `defined(...)` guard in the matching
	  	`fragments/lbalDefinitionTests-<std>.inc`; library tokens are exempt by
	  	design, as they may legitimately be set by platform or compiler code
		- a false-positive probe: a compile-only probe
	  	`tests/probes/<std>/<NAME>.cpp`, or a gtest probe
	  	`LBAL_FP_TEST(<STD>, <NAME>)` in
	  	`tests/fragments/lbalFalsePositiveTest-<std>.inc`, unless the token is
	  	in `LBAL_COVERAGE_NO_PROBE`
		- a probe whose body is guarded by `#if LBAL_<STD>_<NAME>`
		- a probe tagged `LBAL_FP_SMOKE` only if the token is in
	  	`LBAL_COVERAGE_SMOKE`, since the false-negative tests skip those tokens

	It also checks that:
		- every probe names a declared token of its own Standard, so renamed or
	  	retired tokens don’t leave probes behind
		- every `LBAL_(LIB)CPP<nn>_*` name used in `include/lucenaBAL` or in
	  	`tests/lbalFalseNegativeKnown.hpp` is declared in an overview (the
	  	`LBAL_CPP<nn>_VERSION` constants aside), so no fixup sets a token that
	  	nothing documents or tests
		- `tests/lbalFalsePositiveTest.cpp` includes exactly one
	  	`fragments/lbalFalsePositiveTest-<std>.inc` per overview Standard; the
	  	false-negative tests find their Standards from the overviews themselves

	SD-6 mappings are not checked, as some tokens legitimately have none.

	Usage: cmake -DLBAL_SOURCE_DIR=<project root> -P lbalTokenCoverage.cmake

##############################################################################]]

cmake_minimum_required (VERSION 3.30...4.3.2)

if (NOT LBAL_SOURCE_DIR)
	message (FATAL_ERROR "LBAL_SOURCE_DIR must be set to the project root.")
endif ()

#	Tokens with no false-positive probe, on purpose.
set (
	LBAL_COVERAGE_NO_PROBE
		#	Need a module-aware build.
		LBAL_CPP20_MODULES
		LBAL_LIBCPP23_MODULES
)

#	Tokens whose probe is tagged `LBAL_FP_SMOKE`: it would also pass without its
#	feature, so the false-negative tests skip the token. Prefer tightening the
#	probe; remove a token from this list once its probe can fail.
set (
	LBAL_COVERAGE_SMOKE
		#	No implementation offers real garbage collection; always `0`.
		LBAL_CPP11_MINIMAL_GARBAGE_COLLECTION
		LBAL_CPP17_DEDUCTION_GUIDES_DR
		LBAL_CPP26_IMPL_REFLECTION_CLEANUP
		LBAL_CPP2D_CONSTEVAL_ONLY
		LBAL_LIBCPP23_ALGORITHM_ITERATOR_REQUIREMENTS
		LBAL_LIBCPP23_BARRIER_RELAXED_COMPLETION
		LBAL_LIBCPP23_FORMAT_ENCODINGS
		LBAL_LIBCPP26_FLAT_MAP_FIXES
		LBAL_LIBCPP26_FLAT_SET_FIXES
		LBAL_LIBCPP26_IS_WITHIN_LIFETIME_EXTEND
		LBAL_LIBCPP26_PRINT_EFFICIENT
		LBAL_LIBCPP26_PRINT_MORE_EFFICIENT
		LBAL_LIBCPP26_RANGES_FILTER
		LBAL_LIBCPP26_RANGES_REMOVE_COMMON_REF_REQ
		#	Needs a wider `intmax_t` than 64-bit implementations have.
		LBAL_LIBCPP26_RATIO
		#	Replacing the contract-violation handler can’t be observed in-process.
		LBAL_LIBCPP26_REPLACEABLE_CONTRACT_VIOLATION_HANDLER
		LBAL_LIBCPP2D_EXPECTED_UEXPECTED
		#	Freestanding requirements: a hosted library always has these.
		LBAL_LIBCPP26_FREESTANDING_ALGORITHM
		LBAL_LIBCPP26_FREESTANDING_ALGORITHM_MORE
		LBAL_LIBCPP26_FREESTANDING_ARRAY
		LBAL_LIBCPP26_FREESTANDING_CHARCONV
		LBAL_LIBCPP26_FREESTANDING_CHAR_TRAITS
		LBAL_LIBCPP26_FREESTANDING_CSTDLIB
		LBAL_LIBCPP26_FREESTANDING_CSTRING
		LBAL_LIBCPP26_FREESTANDING_CSTRING_REMOVE_STRTOK
		LBAL_LIBCPP26_FREESTANDING_CWCHAR
		LBAL_LIBCPP26_FREESTANDING_ERRC
		LBAL_LIBCPP26_FREESTANDING_EXECUTION
		LBAL_LIBCPP26_FREESTANDING_EXPECTED
		LBAL_LIBCPP26_FREESTANDING_FUNCTIONAL
		LBAL_LIBCPP26_FREESTANDING_ITERATOR
		LBAL_LIBCPP26_FREESTANDING_MDSPAN
		LBAL_LIBCPP26_FREESTANDING_MEMORY
		LBAL_LIBCPP26_FREESTANDING_MEMORY_MORE
		LBAL_LIBCPP26_FREESTANDING_NUMERIC
		LBAL_LIBCPP26_FREESTANDING_OPERATOR_NEW
		LBAL_LIBCPP26_FREESTANDING_OPTIONAL
		LBAL_LIBCPP26_FREESTANDING_RANDOM
		LBAL_LIBCPP26_FREESTANDING_RANGES
		LBAL_LIBCPP26_FREESTANDING_RATIO
		LBAL_LIBCPP26_FREESTANDING_STRING_VIEW
		LBAL_LIBCPP26_FREESTANDING_TUPLE
		LBAL_LIBCPP26_FREESTANDING_UTILITY
		LBAL_LIBCPP26_FREESTANDING_VARIANT
		LBAL_LIBCPP26_OUT_PTR_MORE
		LBAL_LIBCPP26_SPAN_MORE
)

set (FRAGMENTS_DIR "${LBAL_SOURCE_DIR}/include/lucenaBAL/details/fragments")
set (TESTS_DIR "${LBAL_SOURCE_DIR}/tests")
set (TEST_FRAGMENTS_DIR "${TESTS_DIR}/fragments")
set (PROBES_DIR "${TESTS_DIR}/probes")

file (
	GLOB OVERVIEW_FILES
		"${FRAGMENTS_DIR}/lbalFeatureSetup-overview-*.inc"
)

if (NOT OVERVIEW_FILES)
	message (FATAL_ERROR "No overview fragments found in ${FRAGMENTS_DIR}.")
endif ()

set (MISSING_COUNT 0)
set (TOKEN_COUNT 0)
set (HARD_COUNT 0)
set (SOFT_COUNT 0)
set (ALL_TOKENS)
set (SMOKE_TOKENS)
set (NO_PROBE_TOKENS)
set (OVERVIEW_TAGS)

#	Report a problem; the script fails at the end if there were any.
macro (lbal_coverage_error MESSAGE)
	message (SEND_ERROR "${MESSAGE}")
	math (EXPR MISSING_COUNT "${MISSING_COUNT} + 1")
endmacro ()

# Read a file with all whitespace removed, so that wrapped lines such as
# `LBAL_DIAGNOSTIC_TEST(\n    TOKEN\n);` can be matched literally.
function (lbal_read_collapsed PATH OUT_VAR)
	if (EXISTS "${PATH}")
		file (READ "${PATH}" CONTENT)
		string (REGEX REPLACE "[ \t\r\n\\\\]+" "" CONTENT "${CONTENT}")
	else ()
		set (CONTENT "")
	endif ()
	set (${OUT_VAR} "${CONTENT}" PARENT_SCOPE)
endfunction ()

#	Split a false-positive fragment into one list element per gtest probe,
#	each running up to the next `LBAL_FP_TEST(`, as `lbalFalseNegative.cmake`
#	does. List separators and brackets are masked first so C++ code survives
#	as list elements; the masks don’t affect the checks made on them.
function (lbal_split_soft_tests PATH OUT_VAR)
	set (SEGMENTS)

	if (EXISTS "${PATH}")
		file (READ "${PATH}" CONTENT)
		string (REPLACE ";" "<semicolon>" CONTENT "${CONTENT}")
		string (REPLACE "[" "<lbracket>" CONTENT "${CONTENT}")
		string (REPLACE "]" "<rbracket>" CONTENT "${CONTENT}")
		string (REPLACE "\\" "<backslash>" CONTENT "${CONTENT}")
		string (REPLACE "LBAL_FP_TEST(" ";LBAL_FP_TEST(" SEGMENTS "${CONTENT}")
		#	Drop the preamble before the first test.
		list (POP_FRONT SEGMENTS)
	endif ()

	set (${OUT_VAR} "${SEGMENTS}" PARENT_SCOPE)
endfunction ()

foreach (OVERVIEW IN LISTS OVERVIEW_FILES)
	get_filename_component (NAME "${OVERVIEW}" NAME_WE)
	string (REGEX REPLACE "^lbalFeatureSetup-overview-" "" STD "${NAME}")
	string (TOUPPER "${STD}" STD_UPPER)

	list (APPEND OVERVIEW_TAGS ${STD})

	file (READ "${OVERVIEW}" OVERVIEW_CONTENT)
	string (
		REGEX MATCHALL "#define LBAL_${STD_UPPER}_[A-Z0-9_]+ 0"
		DECLARATIONS "${OVERVIEW_CONTENT}"
	)
	list (REMOVE_DUPLICATES DECLARATIONS)

	set (TEST_FILE "${TEST_FRAGMENTS_DIR}/lbalFeatureTest-${STD}.inc")
	lbal_read_collapsed ("${TEST_FILE}" TEST_CONTENT)

	set (CHECK_GUARDS FALSE)
	if (STD MATCHES "^cpp")
		set (CHECK_GUARDS TRUE)
		set (GUARD_FILE "${FRAGMENTS_DIR}/lbalDefinitionTests-${STD}.inc")
		lbal_read_collapsed ("${GUARD_FILE}" GUARD_CONTENT)
	endif ()

	#	This Standard’s declared token names, without the prefix.
	set (STD_NAMES)

	foreach (DECLARATION IN LISTS DECLARATIONS)
		string (REGEX REPLACE "^#define LBAL_${STD_UPPER}_([A-Z0-9_]+) 0$" "\\1" TOKEN_NAME "${DECLARATION}")
		list (APPEND STD_NAMES ${TOKEN_NAME})
		list (APPEND ALL_TOKENS LBAL_${STD_UPPER}_${TOKEN_NAME})
	endforeach ()

	#	Index this Standard’s gtest probes by name: the text of each, and
	#	whether it’s written the exact way the false-negative tests look for.
	set (FP_FRAGMENT "${TEST_FRAGMENTS_DIR}/lbalFalsePositiveTest-${STD}.inc")
	lbal_split_soft_tests ("${FP_FRAGMENT}" SOFT_SEGMENTS)
	set (SOFT_NAMES)

	foreach (SEGMENT IN LISTS SOFT_SEGMENTS)
		if (NOT SEGMENT MATCHES "^LBAL_FP_TEST\\([ \t\r\n]*([A-Z0-9_]+)[ \t\r\n]*,[ \t\r\n]*([A-Z0-9_]+)[ \t\r\n]*\\)")
			string (SUBSTRING "${SEGMENT}" 0 60 START)
			lbal_coverage_error ("${FP_FRAGMENT}: can’t parse the test starting `${START}`")
			continue ()
		endif ()

		set (SOFT_STD ${CMAKE_MATCH_1})
		set (SOFT_NAME ${CMAKE_MATCH_2})

		if (NOT SOFT_STD STREQUAL STD_UPPER OR NOT SOFT_NAME IN_LIST STD_NAMES)
			lbal_coverage_error ("LBAL_FP_TEST(${SOFT_STD}, ${SOFT_NAME}) in ${FP_FRAGMENT}: no token LBAL_${SOFT_STD}_${SOFT_NAME} is declared for ${STD}")
			continue ()
		endif ()

		if (NOT SEGMENT MATCHES "^LBAL_FP_TEST\\(${STD_UPPER}, ${SOFT_NAME}\\)")
			lbal_coverage_error ("LBAL_${STD_UPPER}_${SOFT_NAME}: write its test as `LBAL_FP_TEST(${STD_UPPER}, ${SOFT_NAME})` in ${FP_FRAGMENT}; the false-negative tests look for that exact text")
		endif ()

		if (SOFT_NAME IN_LIST SOFT_NAMES)
			lbal_coverage_error ("LBAL_${STD_UPPER}_${SOFT_NAME}: more than one LBAL_FP_TEST in ${FP_FRAGMENT}")
		endif ()

		list (APPEND SOFT_NAMES ${SOFT_NAME})
		set (SOFT_TEXT_${SOFT_NAME} "${SEGMENT}")
	endforeach ()

	#	Compile-only probes must name a declared token of this Standard.
	file (GLOB HARD_PROBES "${PROBES_DIR}/${STD}/*.cpp")

	foreach (PROBE IN LISTS HARD_PROBES)
		get_filename_component (PROBE_NAME "${PROBE}" NAME_WE)

		if (NOT PROBE_NAME IN_LIST STD_NAMES)
			lbal_coverage_error ("${PROBE}: no token LBAL_${STD_UPPER}_${PROBE_NAME} is declared for ${STD}")
		endif ()
	endforeach ()

	foreach (TOKEN_NAME IN LISTS STD_NAMES)
		set (TOKEN LBAL_${STD_UPPER}_${TOKEN_NAME})
		math (EXPR TOKEN_COUNT "${TOKEN_COUNT} + 1")

		string (FIND "${TEST_CONTENT}" "LBAL_DIAGNOSTIC_TEST(${TOKEN})" POS)
		if (POS EQUAL -1)
			lbal_coverage_error ("${TOKEN}: no LBAL_DIAGNOSTIC_TEST in ${TEST_FILE}")
		endif ()

		if (CHECK_GUARDS)
			string (FIND "${GUARD_CONTENT}" "defined(${TOKEN})" POS)
			if (POS EQUAL -1)
				lbal_coverage_error ("${TOKEN}: no external-definition guard in ${GUARD_FILE}")
			endif ()
		endif ()

		#	The probe the false-negative tests use: a compile-only probe wins
		#	over a gtest probe, as in `lbalFalseNegative.cmake`.
		set (HARD_PROBE "${PROBES_DIR}/${STD}/${TOKEN_NAME}.cpp")
		set (PROBE_TEXT)
		set (HAS_PROBE FALSE)

		if (EXISTS "${HARD_PROBE}")
			file (READ "${HARD_PROBE}" PROBE_TEXT)
			set (HAS_PROBE TRUE)
			math (EXPR HARD_COUNT "${HARD_COUNT} + 1")

			if (NOT PROBE_TEXT MATCHES "#[ \t]*if[ \t]+${TOKEN}([^A-Z0-9_]|$)")
				lbal_coverage_error ("${TOKEN}: ${HARD_PROBE} isn’t guarded by `#if ${TOKEN}`")
			endif ()
		endif ()

		if (TOKEN_NAME IN_LIST SOFT_NAMES)
			set (SOFT_TEXT "${SOFT_TEXT_${TOKEN_NAME}}")
			math (EXPR SOFT_COUNT "${SOFT_COUNT} + 1")

			if (NOT SOFT_TEXT MATCHES "#[ \t]*if[ \t]+${TOKEN}([^A-Z0-9_]|$)")
				lbal_coverage_error ("${TOKEN}: its LBAL_FP_TEST in ${FP_FRAGMENT} isn’t guarded by `#if ${TOKEN}`")
			endif ()

			if (NOT HAS_PROBE)
				set (PROBE_TEXT "${SOFT_TEXT}")
				set (HAS_PROBE TRUE)
			endif ()
		endif ()

		if (TOKEN IN_LIST LBAL_COVERAGE_NO_PROBE)
			list (APPEND NO_PROBE_TOKENS ${TOKEN})

			if (HAS_PROBE)
				lbal_coverage_error ("${TOKEN}: has a probe now; remove it from LBAL_COVERAGE_NO_PROBE")
			endif ()
		elseif (NOT HAS_PROBE)
			lbal_coverage_error ("${TOKEN}: no false-positive probe; add ${HARD_PROBE} or an LBAL_FP_TEST(${STD_UPPER}, ${TOKEN_NAME}) in ${FP_FRAGMENT}")
		endif ()

		if (PROBE_TEXT MATCHES "LBAL_FP_SMOKE")
			list (APPEND SMOKE_TOKENS ${TOKEN})

			if (NOT TOKEN IN_LIST LBAL_COVERAGE_SMOKE)
				lbal_coverage_error ("${TOKEN}: its probe is tagged LBAL_FP_SMOKE, so the false-negative tests skip it; tighten the probe, or add the token to LBAL_COVERAGE_SMOKE")
			endif ()
		endif ()
	endforeach ()
endforeach ()

foreach (TOKEN IN LISTS LBAL_COVERAGE_SMOKE)
	if (NOT TOKEN IN_LIST SMOKE_TOKENS)
		lbal_coverage_error ("${TOKEN}: listed in LBAL_COVERAGE_SMOKE, but its probe isn’t tagged LBAL_FP_SMOKE (or the token isn’t declared); remove it from the list")
	endif ()
endforeach ()

foreach (TOKEN IN LISTS LBAL_COVERAGE_NO_PROBE)
	if (NOT TOKEN IN_LIST ALL_TOKENS)
		lbal_coverage_error ("${TOKEN}: listed in LBAL_COVERAGE_NO_PROBE, but not declared in any overview")
	endif ()
endforeach ()

#	Every feature-token name the headers use must be declared, so that no
#	fixup sets a token that nothing documents or tests.
file (
	GLOB_RECURSE SCANNED_FILES
		"${LBAL_SOURCE_DIR}/include/lucenaBAL/*.hpp"
		"${LBAL_SOURCE_DIR}/include/lucenaBAL/*.inc"
)
list (APPEND SCANNED_FILES "${TESTS_DIR}/lbalFalseNegativeKnown.hpp")

foreach (SCANNED IN LISTS SCANNED_FILES)
	file (READ "${SCANNED}" CONTENT)
	string (REGEX MATCHALL "LBAL_(LIB)?CPP([0-9][0-9]|2D)_[A-Z0-9_]+" USED "${CONTENT}")

	if (NOT USED)
		continue ()
	endif ()

	list (REMOVE_DUPLICATES USED)

	foreach (TOKEN IN LISTS USED)
		if (NOT TOKEN MATCHES "^LBAL_CPP[0-9A-Z]+_VERSION$" AND NOT TOKEN IN_LIST ALL_TOKENS)
			lbal_coverage_error ("${TOKEN}: used in ${SCANNED}, but not declared in any overview")
		endif ()
	endforeach ()
endforeach ()

#	The false-positive executable lists its fragments by hand, so check that it
#	includes each overview Standard’s fragment exactly once, and nothing else.
#	(The false-negative tests find their Standards from the overviews.)
set (FP_SOURCE "${TESTS_DIR}/lbalFalsePositiveTest.cpp")
file (READ "${FP_SOURCE}" FP_CONTENT)
string (REGEX MATCHALL "#[ \t]*include[ \t]+\"fragments/lbalFalsePositiveTest-[a-z0-9]+\\.inc\"" FP_INCLUDES "${FP_CONTENT}")
set (FP_TAGS)

foreach (FP_INCLUDE IN LISTS FP_INCLUDES)
	string (REGEX REPLACE ".*lbalFalsePositiveTest-([a-z0-9]+)\\.inc.*" "\\1" FP_TAG "${FP_INCLUDE}")

	if (FP_TAG IN_LIST FP_TAGS)
		lbal_coverage_error ("${FP_SOURCE} includes fragments/lbalFalsePositiveTest-${FP_TAG}.inc more than once")
	elseif (NOT FP_TAG IN_LIST OVERVIEW_TAGS)
		lbal_coverage_error ("${FP_SOURCE} includes fragments/lbalFalsePositiveTest-${FP_TAG}.inc, but there’s no overview for ${FP_TAG}")
	endif ()

	list (APPEND FP_TAGS ${FP_TAG})
endforeach ()

foreach (STD IN LISTS OVERVIEW_TAGS)
	if (NOT STD IN_LIST FP_TAGS)
		lbal_coverage_error ("${FP_SOURCE} doesn’t include fragments/lbalFalsePositiveTest-${STD}.inc")
	endif ()
endforeach ()

if (MISSING_COUNT GREATER 0)
	message (FATAL_ERROR "${MISSING_COUNT} problem(s) across ${TOKEN_COUNT} tokens.")
endif ()

list (LENGTH SMOKE_TOKENS SMOKE_COUNT)
list (LENGTH NO_PROBE_TOKENS NO_PROBE_COUNT)
message (
	STATUS
	"All ${TOKEN_COUNT} overview tokens have their test lines, guards and probes "
	"(${HARD_COUNT} compile-only, ${SOFT_COUNT} gtest; ${SMOKE_COUNT} smoke, "
	"${NO_PROBE_COUNT} exempt)."
)
