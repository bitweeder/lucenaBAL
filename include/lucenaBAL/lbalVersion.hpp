/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“Version.hpp”
	Copyright © 2018-2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

------------------------------------------------------------------------------*/

/**
	@file lucenaBAL/lbalVersion.hpp

	@brief Include this instead of `<version>` or `<experimental/version>`.

	@details This proxy header will select the correct header based on
	availability. The real `<version>` defines
	[SD-6 macros](https://wg21.link/sd6), of the form `__cpp_lib_xxx`; we don’t
	do that here. Instead, we include `<version>`, if it’s available, and then
	define our own macros that extend the SD-6 offering. See the
	[Standard Library feature detection documentation](@ref lbal_platform) for
	more information regarding these macros, their names, and their values.
	Note that if `__cpp_lib_xxx` (or `__cpp_lib_experimental_xxx`) is set to 0—
	even if the corresponding header, if any, is found—we will ignore it and
	set the corresponding `LBAL_CPPxx_xxx` (or `LBAL_LIBCPPxx_xxx_EXP`) macro
	to 0. If the SD-6 macro is undefined, this caveat does not apply.

	Certain `LBAL_CPPxx_xxx` macros have corresponding `LBAL_LIBCPPxx_xxx_EXP`
	macros; these latter macros are only set to non-zero values if an
	experimental header is being used, typically as a result of a given feature
	having been part of a [Technical Specification](https://en.cppreference.com/w/cpp/experimental).
	Note that `LBAL_LIBCPPxx_xxx` and `LBAL_LIBCPPxx_xxx_EXP` are mutually
	exclusive:

	- If a Standard Library implementation ships with both regular and
	experimental versions of a given header, the experimental version will be
	ignored.
	- If both `LBAL_LIBCPPxx_xxx` and `LBAL_LIBCPPxx_xxx_EXP` are defined to
	non-zero values, and the Standard header exists, `LBAL_LIBCPPxx_xxx_EXP`
	will be set to 0 and a warning will be generated.
	- If `LBAL_LIBCPPxx_xxx` has been set to 0 and `LBAL_LIBCPPxx_xxx_EXP` left
	undefined, `LBAL_LIBCPPxx_xxx_EXP` will also be set to 0, even if the
	experimental feature in question is available; this is done to prevent
	surprises in the event that a feature was explicitly disabled, and then
	later an experimental version of the same feature is made available. The
	reverse, case, though, is not true; if left undefined, `LBAL_LIBCPPxx_xxx`
	will always be assigned a value based on actual feature detection.

	Finally, note that if either macro is predefined to 0, its value will not
	be changed, regardless of circumstances.

	Note that this header should _always_ be used instead of—or in addition
	to—including `<version>` directly, even once the time comes that
	`<version>` is ubiquitous. The reason is that ultimately, `<version>` can
	only document intent, but it may fail to reflect reality. For example,
	there is no SD-6 macro for “our internal policy precludes us from making
	changes to our C++ Standard Library runtime ABI between major OS releases,
	but our engineers forgot to remove the affected headers from our
	development tools releases for several years.”
*/


#pragma once


//	lbal
#include <lucenaBAL/lbalConfig.hpp>
#include <lucenaBAL/lbalFeatureSetup.hpp>
	//	Note that we need to do the full Feature setup here instead of just
	//	Library setup since some of our library feature availability may be
	//	dependent on Platform tests, among other things.
