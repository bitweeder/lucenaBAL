#[[#############################################################################

  Lucena Build Abstraction Library
  “lbalTest/lbalTokenCoverage.cmake”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

	Check that every feature token declared in an overview fragment has the
	supporting pieces that are easy to forget:
		- a `LBAL_DIAGNOSTIC_TEST(...)` line in the matching
	  	`tests/fragments/lbalFeatureTest-<std>.inc`
		- for language (`cpp*`) tokens, a `defined(...)` guard in the matching
	  	`fragments/lbalDefinitionTests-<std>.inc`; library tokens are exempt by
	  	design, as they may legitimately be set by platform or compiler code

	SD-6 mappings are not checked, as some tokens legitimately have none.

	Usage: cmake -DLBAL_SOURCE_DIR=<project root> -P lbalTokenCoverage.cmake

##############################################################################]]

cmake_minimum_required (VERSION 3.30...4.3.2)

if (NOT LBAL_SOURCE_DIR)
	message (FATAL_ERROR "LBAL_SOURCE_DIR must be set to the project root.")
endif ()

set (FRAGMENTS_DIR "${LBAL_SOURCE_DIR}/include/lucenaBAL/details/fragments")
set (TEST_FRAGMENTS_DIR "${LBAL_SOURCE_DIR}/tests/fragments")

file (
	GLOB OVERVIEW_FILES
		"${FRAGMENTS_DIR}/lbalFeatureSetup-overview-*.inc"
)

if (NOT OVERVIEW_FILES)
	message (FATAL_ERROR "No overview fragments found in ${FRAGMENTS_DIR}.")
endif ()

set (MISSING_COUNT 0)
set (TOKEN_COUNT 0)

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

foreach (OVERVIEW IN LISTS OVERVIEW_FILES)
	get_filename_component (NAME "${OVERVIEW}" NAME_WE)
	string (REGEX REPLACE "^lbalFeatureSetup-overview-" "" STD "${NAME}")
	string (TOUPPER "${STD}" STD_UPPER)

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

	foreach (DECLARATION IN LISTS DECLARATIONS)
		string (REGEX REPLACE "^#define ([A-Z0-9_]+) 0$" "\\1" TOKEN "${DECLARATION}")
		math (EXPR TOKEN_COUNT "${TOKEN_COUNT} + 1")

		string (FIND "${TEST_CONTENT}" "LBAL_DIAGNOSTIC_TEST(${TOKEN})" POS)
		if (POS EQUAL -1)
			message (SEND_ERROR "${TOKEN}: no LBAL_DIAGNOSTIC_TEST in ${TEST_FILE}")
			math (EXPR MISSING_COUNT "${MISSING_COUNT} + 1")
		endif ()

		if (CHECK_GUARDS)
			string (FIND "${GUARD_CONTENT}" "defined(${TOKEN})" POS)
			if (POS EQUAL -1)
				message (SEND_ERROR "${TOKEN}: no external-definition guard in ${GUARD_FILE}")
				math (EXPR MISSING_COUNT "${MISSING_COUNT} + 1")
			endif ()
		endif ()
	endforeach ()
endforeach ()

if (MISSING_COUNT GREATER 0)
	message (FATAL_ERROR "${MISSING_COUNT} missing item(s) across ${TOKEN_COUNT} tokens.")
endif ()

message (STATUS "All ${TOKEN_COUNT} overview tokens have their test lines and guards.")
