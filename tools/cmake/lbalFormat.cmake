#[[#############################################################################

  Lucena Build Abstraction Library
  “lbalFormat.cmake”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Runs clang-format over the lintable files for the `format` and `format-dry`
  targets. Invoked with `cmake -P`, so it doesn’t need a shell, and fails with
  a clear message instead of silently doing nothing.

  Inputs (`-D`):
  - `LBAL_CLANG_FORMAT`: the clang-format executable
  - `LBAL_CLANG_FORMAT_CONFIG`: the `.clang-format` file to use
  - `LBAL_FORMAT_FILE_LIST`: a file holding the files to format, one per line
  - `LBAL_FORMAT_MODE`: `format` reformats in place; `check` prints a diff
    for each file that isn’t formatted and fails if there are any
  - `LBAL_FORMAT_WORK_DIR`: scratch directory for `check`
  - `LBAL_DIFF`: optional `diff` executable, used by `check` to show changes

#]]

cmake_minimum_required (VERSION 3.30)

foreach (var
		LBAL_CLANG_FORMAT LBAL_CLANG_FORMAT_CONFIG LBAL_FORMAT_FILE_LIST
		LBAL_FORMAT_MODE)
	if ("${${var}}" STREQUAL "")
		message (FATAL_ERROR "lbalFormat.cmake: ${var} is not set")
	endif()
endforeach()

if (NOT EXISTS "${LBAL_CLANG_FORMAT}")
	message (FATAL_ERROR "clang-format not found at “${LBAL_CLANG_FORMAT}”")
endif()

if (NOT EXISTS "${LBAL_CLANG_FORMAT_CONFIG}")
	message (FATAL_ERROR
		"clang-format config not found at “${LBAL_CLANG_FORMAT_CONFIG}”; "
		"set CLANG_FORMAT_CONFIG")
endif()

if (NOT EXISTS "${LBAL_FORMAT_FILE_LIST}")
	message (FATAL_ERROR "File list not found at “${LBAL_FORMAT_FILE_LIST}”")
endif()

execute_process (
	COMMAND "${LBAL_CLANG_FORMAT}" --version
	OUTPUT_VARIABLE version
	OUTPUT_STRIP_TRAILING_WHITESPACE
	RESULT_VARIABLE result
)

if (NOT result EQUAL 0)
	message (FATAL_ERROR "“${LBAL_CLANG_FORMAT} --version” failed: ${result}")
endif()

message (STATUS "Using ${version}")

file (STRINGS "${LBAL_FORMAT_FILE_LIST}" files)
list (LENGTH files count)

if (count EQUAL 0)
	message (FATAL_ERROR "No files to format")
endif()

set (style "--style=file:${LBAL_CLANG_FORMAT_CONFIG}")

if (LBAL_FORMAT_MODE STREQUAL "format")
	set (failed 0)

	foreach (file IN LISTS files)
		execute_process (
			COMMAND "${LBAL_CLANG_FORMAT}" "${style}" -i "${file}"
			RESULT_VARIABLE result
		)

		if (NOT result EQUAL 0)
			message (SEND_ERROR "clang-format failed on ${file}: ${result}")
			math (EXPR failed "${failed} + 1")
		endif()
	endforeach()

	if (failed GREATER 0)
		message (FATAL_ERROR "clang-format failed on ${failed} of ${count} files")
	endif()

	message (STATUS "Formatted ${count} files")
elseif (LBAL_FORMAT_MODE STREQUAL "check")
	if ("${LBAL_FORMAT_WORK_DIR}" STREQUAL "")
		message (FATAL_ERROR "lbalFormat.cmake: LBAL_FORMAT_WORK_DIR is not set")
	endif()

	file (MAKE_DIRECTORY "${LBAL_FORMAT_WORK_DIR}")
	set (formatted "${LBAL_FORMAT_WORK_DIR}/formatted")
	set (unformatted)

	foreach (file IN LISTS files)
		execute_process (
			COMMAND "${LBAL_CLANG_FORMAT}" "${style}" "${file}"
			OUTPUT_FILE "${formatted}"
			RESULT_VARIABLE result
		)

		if (NOT result EQUAL 0)
			message (FATAL_ERROR "clang-format failed on ${file}: ${result}")
		endif()

		execute_process (
			COMMAND "${CMAKE_COMMAND}" -E compare_files "${file}" "${formatted}"
			RESULT_VARIABLE result
			OUTPUT_QUIET
			ERROR_QUIET
		)

		if (NOT result EQUAL 0)
			list (APPEND unformatted "${file}")

			if (LBAL_DIFF)
				execute_process (
					COMMAND "${LBAL_DIFF}" -u
						--label "${file}" --label "${file} (formatted)"
						"${file}" "${formatted}"
				)
			endif()
		endif()
	endforeach()

	file (REMOVE "${formatted}")
	list (LENGTH unformatted unformatted_count)

	if (unformatted_count GREATER 0)
		list (JOIN unformatted "\n  " unformatted_list)
		message (FATAL_ERROR
			"${unformatted_count} of ${count} files need formatting:\n"
			"  ${unformatted_list}")
	endif()

	message (STATUS "All ${count} files are formatted")
else()
	message (FATAL_ERROR
		"lbalFormat.cmake: unknown LBAL_FORMAT_MODE “${LBAL_FORMAT_MODE}”")
endif()
