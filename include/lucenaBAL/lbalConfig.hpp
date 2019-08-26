/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“Config.hpp”
	Copyright © 2015-2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	Config documents the internal options used in a given build of the
	Lucena Build Abstraction Library. The contents of this file should not
	typically be changed unless the library is rebuilt at the same time; in
	particular, a client program that modifies this file risks crashing when
	built against a version of the library that is not using the same settings.

	Settings available in client code that can be set independently of those
	used to build the library are also documented here, as well as certain
	situational settings. Such settings should be set in the client code’s own
	master headers.

	Note that codes are littered through the source comments to indicate areas
	that require special attention; we document those here:

		FIXME - something that is a known bug, incomplete, or a likely trouble
				area; these should be addressed prior to shipping

		APIME - a likely API problem; these are not an impediment to shipping,
				but may pose a future maintenance problem

		OPTME - something that could be made more efficient with a high
				probable performance return; this notation is generally
				reserved for speed-critical sections

		VERME - a place where an assumption has been made about performance,
				stability, usefulness, etc.; these document areas that might
				benefit from future testing

		SEEME - something noteworthy that requires care to use properly;
				possibly counterintuitive, but not easily addressable

------------------------------------------------------------------------------*/


#pragma once


/*
	Set up versioned namespaces for lucenaBAL. This allows us to have
	non-disruptive ABI changes, should the need arise.

	APIME Note that there doesn’t appear to be a way to ensure that these
	macros are invoked correctly, e.g., guard values to keep from accidentally
	embedding std in our library namespace.
*/
#define LBAL_version_major 2
#define LBAL_version_minor 0
#define LBAL_version_patch 0

#define LBAL_version \
	( LBAL_version_major << 24 \
	| LBAL_version_minor << 16 \
	| LBAL_version_patch )

#define LBAL_abi_version 2

//	Turn the literal value param_ into a string literal
#define LBAL_Stringify1_(LBAL_param_) #LBAL_param_
#define LBAL_Stringify_(LBAL_param_) LBAL_Stringify1_(LBAL_param_)

/*
	LBAL_Concat_ concatenates any two preprocessor macro arguments to create a
	new token. The additional indirection is necessary to ensure that the
	values of the arguments, not the argument identifiers, are used. Note that
	these macros must exist here since this file gets included before anything
	else of ours.
*/
#define LBAL_Concat1_(LBAL_base_, LBAL_suffix_)	\
	LBAL_base_ ## LBAL_suffix_

#define LBAL_Concat_(LBAL_base_, LBAL_suffix_)	\
	LBAL_Concat1_ (LBAL_base_, LBAL_suffix_)


//	Anything contained in this namespace is versioned.
#define LBAL_abi_namespace \
	LBAL_Concat_(bal_, LBAL_abi_version)


/*
	Begin and end the unversioned library namespace. This must be done from the
	global namespace.
*/
#define LBAL_begin_namespace \
	namespace lucena { namespace bal {

#define LBAL_end_namespace \
	} }


/*
	Enter and exit the inline versioned library namespace. This must be done
	from within the unversioned library namespace.
*/
#define LBAL_enter_v_namespace \
	inline namespace LBAL_abi_namespace {

#define LBAL_exit_v_namespace \
	}

/*
	Begin and end the fully qualified versioned library namespace. This must be
	done from the global namespace.
*/
#define LBAL_begin_v_namespace \
	LBAL_begin_namespace LBAL_enter_v_namespace

#define LBAL_end_v_namespace \
	LBAL_exit_v_namespace LBAL_end_namespace


//	Versioned namespace qualifier
#define LBAL_v_ \
	lucena::bal::LBAL_abi_namespace

//	Unversioned namespace qualifier
#define LBAL_ \
	lucena::bal


//	Bring our namespace into existence.
LBAL_begin_v_namespace
LBAL_end_v_namespace


/*
	ABI decorators. These are used to identify which ABI a given chunk of code
	adheres to. The “normal” ABI is the default, and provided for completeness.
	The “cpp” ABI is the stable C++ ABI for a given platform. The “c” ABI is
	the C ABI; enter/exit macros are provided for completeness, though they are
	unnecessary in practice since all supported C++ compilers handle extern "C"
	correctly already.

	APIME  These are intended to track the emerging C++ ABI proposal(s). For
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


/*
	Begin and end the std library namespace; this is intended for implementing
	template specializations. This must be done from the global namespace.
*/
#ifndef LBAL_begin_std_namespace
	#define LBAL_begin_std_namespace namespace std {
#endif

#ifndef LBAL_end_std_namespace
	#define LBAL_end_std_namespace }
#endif


/*
	This is used to maintain ABI stability when using Standard Library
	constructs in our APIs. Use “LBAL_std_abi::” instead of just “std::” when
	qualifying the namespace of Standard Library objects to ensure that we’re
	using the ABI-stable interface for a given platform. For completeness, we
	also offer LBAL_std for usage that isn’t tied to a particular ABI.

	To be clear, LBAL_std_abi should be used in client APIs to indicate symbols
	from the std namespace that could be affected by ABI differences between
	between separate binaries that both include a given header.

	APIME  This is intended to track the emerging C++ ABI proposal. For now,
	it’s really just a placeholder; the only value is for documentation.
*/
#ifndef LBAL_std_abi
	#define LBAL_std_abi std
#endif

#ifndef LBAL_std
	#define LBAL_std std
#endif


/*
	The value of LBAL_CONFIG_debug is 1 for debug builds and 0 for other
	builds. It is set by the build system and passed in to the compiler. The
	value used by client code does not have to match the library build’s (or
	even exist). Debug builds include many static_asserts and other compile-
	time tests, add extra data to log entries, log more than release builds,
	perform runtime asserts, emit debugger symbol tables, disable most
	optimizations, and generally do things that should never ever happen in
	shipping code.

	SEEME This is unused as of lucenaBAL 2.
*/
//#define LBAL_CONFIG_debug 1

