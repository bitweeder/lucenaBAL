/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lucenaBAL.h”
	Copyright © 2015-2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

------------------------------------------------------------------------------*/

/**
	@file lucenaBAL/lucenaBAL.hpp

	@brief Metaheader providing full access to the entire library

	@details This master header file includes all of the Lucena Build
	Abstraction Library public interface headers. It is compatible with usage
	as a prefix header, and it is also safe for use in precompiled headers.
	Library clients should simply include this header rather than the
	component headers.
*/


#pragma once


/**
	@mainpage Lucena Build Abstraction Library

	@section lbal_intro Introduction

	The Lucena Build Abstraction Library (**lucenaBAL**) is a tool for
	identifying the characteristics of the environment used to build your code
	and for describing the capabilities of the C++ compiler and Standard
	Library implementation being used. Additionally, it provides uniform
	abstractions for certain compiler- and linker-dependent decorators used for
	things like branch prediction and symbol visibility that would otherwise
	require testing and knowledge of the toolchain to expose, and even then
	would require proprietary constructs to use.

	The primary objective of this  library is to facilitate cross-platform
	interoperability between triples of mostly-conforming modern compilers,
	Standard Libraries implementations, and build environments. In particular,
	rather than being forced to use a least-common denominator set of features,
	lucenaBAL provides the tools to determine maximally-available feature sets.
	Glue code libraries may then be provided on top of this to make certain
	otherwise-limited-availability features generally available, or the
	decision could be made to provide multiple paths of execution.


	@section lbal_usage Usage Instructions

	All that’s needed to make use of lucenaBAL is to issue
	`#include <lucenaBAL/lucenaBAL.hpp>` in each participating file. As a
	header-only library with no dependencies beyond a nominal inclusion of
	`<ciso646>` from the C++ Standard Library, there’s nothing else to link or
	install. Additionally, there’s not much to configure, though you can see
	[Configuration](@ref lbal_config) for options.

	The library itself comprises a large collection of preprocessor macros,
	grouped loosely into [build-time descriptors](@ref lbal_build_env),
	[feature identifiers](@ref lbal_features), and
	[linker decorators](@ref lbal_decorators). See the relevant sections for
	more information.


	@section lbal_structure Header Organization

	lucenaBAL comprises a small number of public headers and some number of
	private headers. Generally, only the public `<lucenaBAL/lucenaBAL.hpp>`
	header needs to be directly referenced. Additionally, there are:

	- `<lucenaBAL/lbalConfig.hpp>`, which is used to configure the library as
	described in [Configuration](@ref lbal_config)

	- `<lucenaBAL/lbalFeatureSetup.hpp>`, which describes most
	[platform](@ref lbal_platform) and [compiler](@ref lbal_compiler) features,
	[build-time descriptors](@ref lbal_build_env), and the
	[linker decorators](@ref lbal_decorators)

	- `<lucenaBAL/lbalVersion.hpp>`, which sets up
	[Standard Library feature detection](@ref lbal_library) macros.
	These supplement whatever may have been set up by
	`<lucenaBAL/lbalFeatureSetup.hpp>`; the two sets are not fully orthogonal,
	as the build environment may influence the availability of certain Standard
	Library features.

	The private headers are included by these as necessary, and should never be
	invoked directly.


	@section lbal_notes Header Notes

	Labels can appear in the source comments to indicate areas that require
	special attention; we document those here:

	- __FIXME__: something that is a known bug, incomplete, or a likely trouble
	area targeted for a future rewrite. These tags typically decorate
	in-development code, but may persist across multiple releases depending on
	triage outcomes.

	- __APIME__: a likely API problem. These tags make note of surprising behavior
	that may pose a future maintenance problem, and are typically the result of
	poor design in the library or its dependencies.

	- __OPTME__: something that could be made more efficient with a high probable
	performance return. This notation is generally reserved for speed-critical
	sections that would benefit from further attention.

	- __VERME__: a place where an assumption has been made about performance,
	stability, usefulness, etc. These tags document areas that would benefit
	from future testing.

	- __SEEME__: something noteworthy that requires care to use correctly.
	These tags demarcate a counterintuitive flow or algorithmic approach that
	can be tricky to understand or that involves non-obvious tradeoffs.


	@defgroup lbal_config Configuration
	@defgroup lbal_build_env Build-time Environment
	@defgroup lbal_features Feature Detection Macros
	@{
		@defgroup lbal_platform Platform Features
		@defgroup lbal_compiler Compiler Features
		@defgroup lbal_library Standard Library Features
	@}
	@defgroup lbal_decorators Linker Decorators
*/

#include <lucenaBAL/lbalConfig.hpp>
#include <lucenaBAL/lbalFeatureSetup.hpp>
#include <lucenaBAL/lbalVersion.hpp>
