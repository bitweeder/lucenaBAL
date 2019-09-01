/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lucenaBAL.h”
	Copyright © 2015-2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	This master header file includes all of the Lucena Build Abstraction public
	interface headers. It is intended for use as a prefix header, and it is
	also safe for use in precompiled headers. Most users should simply include
	this header and not worry about the component headers.

------------------------------------------------------------------------------*/


#pragma once


/**
	@defgroup lbal_usage Usage Instructions

	Generally, all that’s needed in order to make use of lucenaBAL is to
	issue `#include <lucenaBAL/lucenaBAL.hpp>` in each target file. As a
	header-only library with no dependencies beyond a nominal inclusion of
	`<ciso646>` from the C++ Standard Library, there’s nothing else to link or
	install. Additionally, there’s nothing much to configure, though you can
	see [Configuration](@ref lbal_config) for details.

	The library itself comprises a large collection of preprocessor macros,
	grouped loosely into [build-time descriptors](@ref lbal_build_env),
	[feature identifiers](@ref lbal_features), and
	[linker decorators](@ref lbal_decorators). See the relevant sections for
	more information.

	@{
		@defgroup lbal_structure Header Organization

		lucenaBAL comprises a small number of public headers and some number of
		private headers. Generally, only the public `<lucenaBAL/lucenaBAL.hpp>`
		header needs to be directly referenced. Additionally, there is:

			- `<lucenaBAL/lbalConfig.hpp>`, which is used to configure the
			library as described in [Configuration](@ref lbal_config)
			- `<lucenaBAL/lbalFeatureSetup.hpp>`, which describes most
			[platform](@ref lbal_platform) and [compiler](@ref lbal_compiler)
			features, [build-time descriptors](@ref lbal_build_env), and the
			[linker decorators](@ref lbal_decorators)
			- `<lucenaBAL/lbalVersion.hpp>`, which sets up
			[Standard Library feature detection](@ref lbal_platform) macros.
			These supplement whatever may have been set up by
			`lbalFeatureSetup.hpp`; the two sets are not fully orthogonal, as
			the build environment may influence the availability of certain
			Standard Library features.

		The private headers are included by these as necessary, and should
		never be invoked directly.
	@}
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
