/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalVersionSetup.hpp”
	Copyright © 2019-2020 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/


#pragma once


//	__SEEME__ We load this first, for once, since some of its macros are needed
//	for the following evaluation. This will have no impact on how any
//	subsequently-included std headers are evaluated.
#include <lucenaBAL/details/lbalConfig.hpp>


/*------------------------------------------------------------------------------
	This handles loading the `<version>` header, if it’s available. We proceed
	carefully in stages in order to avoid loading unnecessary headers while
	also avoiding compilation errors if we try to load a header that does not
	exist. Where we lack confidence in availability, we act conservatively.

	We may not be able to make a full determination of that, however, so
	`LBAL_LIBCPP2A_VERSION` may still be undefined on exit, in which case the
	implementation-specific Standard Library setup header will figure it out.
*/

#if !defined (LBAL_LIBCPP2A_VERSION)
	#if defined (__has_include) && __has_include (<version>)
		#define LBAL_LIBCPP2A_VERSION 1L
	#else
		#define LBAL_LIBCPP2A_VERSION 0L
	#endif
#endif

//	Pedantic test in case LBAL_LIBCPP2A_VERSION was previously defined.
#if LBAL_LIBCPP2A_VERSION
	#if defined (__has_include)
		#if !__has_include (<version>)
			//	The client claims `<version>` exists, but it doesn’t. We
			//	override.
			#undef LBAL_LIBCPP2A_VERSION
			#define LBAL_LIBCPP2A_VERSION 0L
			#warning "<version> not found; resetting LBAL_LIBCPP2A_VERSION"
		#endif
	#else
		//	We don’t block on this, as the header may have been back-ported,
		//	even if the means to test for the header is not available, and the
		//	client somehow accommodated this.
		#if LBAL_CONFIG_enable_pedantic_warnings
			#warning "Unable to validate user-set LBAL_LIBCPP2A_VERSION; attempting to include <version>"
		#endif	//	LBAL_CONFIG_enable_pedantic_warnings
	#endif
#endif	//	LBAL_LIBCPP2A_VERSION

#if LBAL_LIBCPP2A_VERSION
	#include <version>
#else
	//	In C++, this is a do-nothing header we include just for the side
	//	effects: by convention, the Standard Library implementation will be
	//	configured.
	#include <ciso646>
#endif
