#[[#############################################################################

	Lucena Build Abstraction Library
	“doc/CMakeLists.txt”
	Copyright © 2018-2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	This script expects to be called by the Lucena-Build-Abstraction root
	script; in particular, default values for various properties are assumed to
	have been previously set.

##############################################################################]]


find_package(Doxygen REQUIRED)

get_target_property (
	LBAL_PUBLIC_HEADER_DIR
		lucenaBAL
	INTERFACE_INCLUDE_DIRECTORIES
)

file (
	GLOB_RECURSE
		LBAL_PUBLIC_HEADERS
			"${LBAL_PUBLIC_HEADER_DIR}/*.h"
)

set (DOXYGEN_INPUT_PATHS "${PROJECT_SOURCE_DIR}/include")
set (DOXYGEN_EXCLUDE_PATHS "${PROJECT_SOURCE_DIR}/include/lucenaBAL/details")
set (DOXYGEN_PATH_STRIP_PREFIX "${PROJECT_SOURCE_DIR}")
set (DOXYGEN_OUTPUT_PATH "${CMAKE_CURRENT_BINARY_DIR}/docs/doxygen")
set (DOXYGEN_EXAMPLES_PATH "${PROJECT_SOURCE_DIR}/examples")
set (DOXYGEN_INDEX_FILE "${DOXYGEN_OUTPUT_PATH}/html/index.html")
set (DOXYFILE_IN "${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in")
set (DOXYFILE_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")

configure_file (
	"${DOXYFILE_IN}"
	"${DOXYFILE_OUT}"
	@ONLY)

# Doxygen won’t create this for us.
file (MAKE_DIRECTORY "${DOXYGEN_OUTPUT_PATH}")

add_custom_command (
	OUTPUT
		"${DOXYGEN_INDEX_FILE}"
	DEPENDS
		"${LBAL_PUBLIC_HEADERS}"
	COMMAND
		"${DOXYGEN_EXECUTABLE}" "${DOXYFILE_OUT}"
	MAIN_DEPENDENCY
		${DOXYFILE_OUT}
		${DOXYFILE_IN}
	COMMENT
		"Generating docs"
)

add_custom_target (
	Doxygen
		ALL DEPENDS "${DOXYGEN_INDEX_FILE}"
)
