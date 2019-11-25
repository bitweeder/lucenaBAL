/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“Config.hpp”
	Copyright © 2015-2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

------------------------------------------------------------------------------*/

/**
	@file lucenaBAL/lbalConfig.hpp

	@brief Documents the internal options used in a given build of lucenaBAL.

	@details The contents of this file should not be changed unless all
	binaries that depend on it in the scope of a given project are rebuilt at
	the same time. In particular, a client that modifies this file risks
	crashing dependent code that is not using the same settings.

	Settings available to client code that can be set independently of the
	global settings are also documented here, as well as certain situational
	settings. Such settings should typically be set in the client code’s own
	headers.
*/


#pragma once


/**
	@addtogroup lbal_config

	@brief Handles library configuration.

	@details The library is controlled via preprocessor macros which define
	certain parameters it must operate under, both globally and locally.

	@{
*/

/**
	@name Version Info

	@brief Identifies the versions of various components of lucenaBAL

	@details lucenaBAL uses [semantic versioning](https://semver.org/) to keep
	track of API-level revisions. Additionally, there is an ABI version number
	which changes very infrequently and is tracked using a monotonically
	increasing integer value.

	@{

	@def LBAL_version_major
	@brief Corresponds to the MAJOR version number in the semantic versioning
	scheme

	@def LBAL_version_minor
	@brief Corresponds to the MINOR version number in the semantic versioning
	scheme

	@def LBAL_version_patch
	@brief Corresponds to the PATCH version number in the semantic versioning
	scheme
*/

// __SEEME__ It would be helpful to show the current version numbers in the
//	docs, but since they’re coming from a CMake-generated file, they don’t
//	appear to be accessible to Doxygen during preprocessing.
#include <lucenaBAL/details/lbalGenerated.hpp>

#ifndef LBAL_version_major
	#define LBAL_version_major 0
#endif

#ifndef LBAL_version_minor
	#define LBAL_version_minor 0
#endif

#ifndef LBAL_version_patch
	#define LBAL_version_patch 0
#endif

/**
	@def LBAL_version

	@brief Packed 32-bit unsigned integer representation of the full semantic
	version number.

	@details The high 8 bits encode MAJOR, followed by 8 bits for MINOR, and
	the 16 low bits represent PATCH.
*/
#define LBAL_version \
	( LBAL_version_major << 24 \
	| LBAL_version_minor << 16 \
	| LBAL_version_patch )

/**
	@def LBAL_abi_version

	@brief Monotonically increasing integer value identifying the current ABI
	revision.

	@details This changes very infrequently. Additionally, it is currently
	unused, as there is no binary component in the current rendition of
	lucenaBAL.
 */
#ifndef LBAL_abi_version
	#define LBAL_abi_version 0
#endif

///	@}	Version Info

/**
	@name Utilities

	@brief Miscellaneous tools used in the headers

	@details These are internal utilities that are publicly documented as they
	may be generally useful to library clients.

	@{

	@def LBAL_Concat_(LBAL_base_, LBAL_suffix_)

	@brief Concatenate any two preprocessor macro arguments to create a
	new token.

	@remarks This macro contains an additional indirection which is necessary
	to ensure that the values of the arguments—not the argument identifiers—are
	used.

	@param[in] LBAL_base_ The base token to be appended to. Must be a valid
	preprocessor token in its own right.

	@param[in] LBAL_suffix_ The suffix to be appended to LBAL_base_. Must be
	composed only of characters allowed in a preprocessor token.

	@returns A new token that is the exact concatentation of LBAL_suffix_ onto
	LBAL_base_
*/

///@cond LBAL_INTERNAL
#define LBAL_Concat1_(LBAL_base_, LBAL_suffix_)	\
	LBAL_base_ ## LBAL_suffix_
///@endcond

#define LBAL_Concat_(LBAL_base_, LBAL_suffix_)	\
	LBAL_Concat1_ (LBAL_base_, LBAL_suffix_)


/**
	@def LBAL_Stringify_(LBAL_param_)

	@brief Turn the literal value param_ into a string literal

	@remarks Due to limitations of the preprocessor, literal commas (“,”) will
	not be stringified. This macro contains an additional indirection which is
	necessary to ensure that the values of the arguments—not the argument
	identifiers—are used.

	@param LBAL_param_ An arbitrary term or expression, up to the limit of
	what the preprocessor will allow as a macro argument

	@returns A string literal, effectively a quoted C-style string
*/

///@cond LBAL_INTERNAL
#define LBAL_Stringify1_(LBAL_param_) \
	#LBAL_param_
///@endcond

#define LBAL_Stringify_(LBAL_param_) \
	LBAL_Stringify1_(LBAL_param_)

///	@}	Utilities


/**
	@name Environment

	@brief Identify characteristics of the build evironment

	@details These provide data identifying top-level characteristics of the
	build environment that are used elsewhere in the library, but that may also
	have value to clients. More specialized information is collected and
	exposed elsewhere.

	@{
*/

/**
	@def LBAL_cpp_version

	@brief Identify the Standard C++ dialect being used

	@details In a Standard-conforming world, `__cplusplus` would be all you
	need to do this. Unfortunately, we are not in a Standard-conforming world.

	It is strongly recommended to not rely on this value for feature testing,
	but rather use the appropriate feature token.

	@remarks __SEEME__ Microsoft Visual Studio stopped setting __cplusplus in
	the expected manner, but replaced the utility of it with a proprietary
	macro, `_MSVC_LANG`. We use it as an analog. Note that `_MSVC_LANG` is not
	available prior to MSVS 2015 Update 3.
*/
#ifndef LBAL_cpp_version
	#ifdef _MSVC_LANG
		#define LBAL_cpp_version _MSVC_LANG
	#else
		#define LBAL_cpp_version __cplusplus
	#endif
#else
	#error "Do not define LBAL_cpp_version outside of this header"
#endif

///	@}	Environment


/**
	@name Settings

	@brief Configure the library itself

	@details At this time, none of these will change any resulting binaries, but
	will instead provide different levels of feedback at build-time.

	@{
*/

/**
	@def LBAL_CONFIG_enable_pedantic_warnings

	@brief Issue compile-time warnings whenever anything unusual happens

	@details Generally, this should not be set to `0`, as “anything unusual” is
	almost definitely going to be something undesirable. If the client is in
	the rare situation of tripping these warnings and finding them spurious,
	however, this setting offers a blunt instrument to silence them.
*/
#ifndef LBAL_CONFIG_enable_pedantic_warnings
	#define LBAL_CONFIG_enable_pedantic_warnings 1
#endif

///	@}	Settings


/**
	@name Namespaces

	@brief Sets up the namespaces used by lucenaBAL

	@details lucenaBAL uses both versioned and unversioned namespaces,
	depending on context. The versioned namespaces live within the unversioned
	namespace, with the current versioned namespace being inline. All symbols
	are contained somewhere within our top-level namespace.

	Anything contained in the current versioned namespace can be qualified with
	just the regular namespace name, but its fully-qualified name will include
	a version identifier. This provides a mechanism by which we can have
	non-disruptive ABI changes, should the need arise.

	@remarks In the absence of modules—or at least certain features of certain
	module-related Standard proposals—preprocessor tokens cannot be
	namespace-qualified, so they all exist in a global soup. lucenaBAL uses the
	`LBAL_` prefix to qualify all of its preprocessor tokens for this reason,
	but there is no guarantee that these names are unique.

	@remarks __APIME__ Note that there doesn’t appear to be a way to ensure
	that the namespace scope macros are invoked correctly, e.g., guard values
	to keep from accidentally exiting the incorrect namespace.

	@example namespace_example.cpp

	This is an example of how the various namespace macros are used.

	@{
*/

///@cond LBAL_INTERNAL

/**
	Identify the versioned namespace for lucenaBAL
*/
#define LBAL_abi_namespace \
	LBAL_Concat_(bal_, LBAL_abi_version)

///@endcond

/**
	@def LBAL_begin_namespace

	@brief Enter the regular namespace

	@details This introduces a new namespace scope. It should only be invoked
	at global namespace scope.

	@remarks __SEEME__ Because of how C++ namespaces work, it may not be
	immediately obvious if this has been used incorrectly. Generally, this
	should be a non-issue since this token should not appear in client code.
*/
#define LBAL_begin_namespace \
	namespace lucena::bal {

/**
	@def LBAL_end_namespace

	@brief Exit the regular namespace and return to the global namespace

	@details This ends the regular namespace scope. It should only be invoked
	from within the regular lucenaBAL namespace.

	@remarks __SEEME__ Because of how C++ namespaces work, it may not be
	immediately obvious if this has been used incorrectly. Generally, this
	should be a non-issue since this token should not appear in client code.
*/
#define LBAL_end_namespace \
	}


/**
	@def LBAL_enter_v_namespace

	@brief Enter the versioned namespace from the unversioned namespace

	@details This introduces a new versioned namespace scope. It should only be
	invoked from within the regular lucenaBAL namespace.

	@remarks __SEEME__ Because of how C++ namespaces work, it may not be
	immediately obvious if this has been used incorrectly. Generally, this
	should be a non-issue since this token should not appear in client code.
*/
#define LBAL_enter_v_namespace \
	inline namespace LBAL_abi_namespace {

/**
	@def LBAL_exit_v_namespace

	@brief Exit the versioned namespace and return to the unversioned namespace

	@details This exits the versioned namespace scope, returning to the
	unversioned namespace scope. It should only be invoked from within the
	versioned lucenaBAL namespace.

	@remarks __SEEME__ Because of how C++ namespaces work, it may not be
	immediately obvious if this has been used incorrectly. Generally, this
	should be a non-issue since this token should not appear in client code.
*/
#define LBAL_exit_v_namespace \
	}

/**
	@def LBAL_begin_v_namespace

	@brief Enter the versioned namespace from the global namespace

	@details This introduces a new versioned namespace scope. It should only be
	invoked from the global namespace scope.
*/
#define LBAL_begin_v_namespace \
	LBAL_begin_namespace LBAL_enter_v_namespace

/**
	@def LBAL_end_v_namespace

	@brief Exit the versioned namespace and return to the global namespace

	@details This ends the versioned namespace scope, returning to the
	global namespace scope. It should only be invoked from within the versioned
	lucenaBAL namespace.

	@remarks __SEEME__ Because of how C++ namespaces work, it may not be
	immediately obvious if this has been used incorrectly. Generally, this
	should be a non-issue since this token should not appear in client code.
*/
#define LBAL_end_v_namespace \
	LBAL_exit_v_namespace LBAL_end_namespace

/**
	@def LBAL_

	@brief Unversioned namespace qualifier

	@details This is used to refer to a symbol if it is within the unversioned
	lucenaBAL namespace, including if it is within the versioned inline
	namespace.
*/

#define LBAL_ \
	::lucena::bal

/**
	@def LBAL_v_

	@brief Versioned namespace qualifier

	@details This is used to refer to a symbol using its fully qualified
	namespace if it is within the versioned lucenaBAL namespace.
*/
#define LBAL_v_ \
	::lucena::bal::LBAL_abi_namespace


//	Bring our namespace into existence.
LBAL_begin_v_namespace
LBAL_end_v_namespace


///@cond LBAL_EXPERIMENTAL

/**
	ABI decorators. These are used to identify which ABI a given chunk of code
	adheres to. The “normal” ABI is the default, and provided for completeness.
	The “cpp” ABI is the stable C++ ABI for a given platform. The “c” ABI is
	the C ABI; enter/exit macros are provided for completeness, though they are
	unnecessary in practice since all supported C++ compilers handle extern "C"
	correctly already.

	__APIME__  These are intended to track the emerging C++ ABI proposal(s). For
	now, they’re mostly placeholders - only the C ABI is generally supported.
*/
#ifndef LBAL_enter_normal_abi
	#define LBAL_enter_normal_abi
#endif

#ifndef LBAL_exit_normal_abi
	#define LBAL_exit_normal_abi
#endif

#ifndef LBAL_enter_cpp_abi
	#define LBAL_enter_cpp_abi
#endif

#ifndef LBAL_exit_cpp_abi
	#define LBAL_exit_cpp_abi
#endif

#ifndef LBAL_enter_c_abi
	#define LBAL_enter_c_abi extern "C" {
#endif

#ifndef LBAL_exit_c_abi
	#define LBAL_exit_c_abi }
#endif


/**
	These are used to maintain ABI stability when using Standard Library
	constructs in our APIs. Use “LBAL_std_abi::” instead of just “std::” when
	qualifying the namespace of Standard Library objects to ensure that we’re
	using the ABI-stable interface for a given platform. For completeness, we
	also offer LBAL_std for usage that isn’t tied to a particular ABI.

	To be clear, LBAL_std_abi should be used in client APIs to indicate symbols
	from the std namespace that could be affected by ABI differences between
	between separate binaries that both include a given header.

	__APIME__  This is intended to track the emerging C++ ABI proposal. For now,
	it’s really just a placeholder; the only value is for documentation.
*/
#ifndef LBAL_std_abi
	#define LBAL_std_abi std
#endif

#ifndef LBAL_std
	#define LBAL_std std
#endif

///@endcond

///	@}	Namespaces


///@cond LBAL_INTERNAL

/**
	The value of LBAL_CONFIG_debug is 1 for debug builds and 0 for other
	builds. It is set by the build system and passed in to the compiler. The
	value used by client code does not have to match the library build’s (or
	even exist). Debug builds include many static_asserts and other compile-
	time tests, add extra data to log entries, log more than release builds,
	perform runtime asserts, emit debugger symbol tables, disable most
	optimizations, and generally do things that should never ever happen in
	shipping code.

	__SEEME__ This is unused as of lucenaBAL 2.
*/
//#define LBAL_CONFIG_debug 1

///@endcond

///	@}	lbal_config
