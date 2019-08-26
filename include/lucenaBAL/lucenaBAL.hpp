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


//	Configure our public and private build options. These must be consistent
//	between an executable and any libraries it uses.
#include <lucenaBAL/lbalConfig.hpp>

//	Handle feature detection and set up build environment macros.
#include <lucenaBAL/lbalFeatureSetup.hpp>

//	Set up Standard Library feature detection macros. These supplement whatever
//	may have been set up by lbalFeatureSetup.hpp; the two sets are not
//	orthogonal, as the build environment may influence the availability of
//	certain Standard Library features. See lbalVersion.hpp for details.
#include <lucenaBAL/lbalVersion.hpp>
