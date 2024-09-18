/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalKnownVersions.hpp”
	Copyright © 2019-2024 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/


#pragma once


//	C++ Standards
#define LBAL_CPP11_VERSION 201103L
#define LBAL_CPP14_VERSION 201402L
#define LBAL_CPP17_VERSION 201703L
#define LBAL_CPP20_VERSION 202002L


//	__SEEME__ Ostensibly, we could track all the SD-6 macro values here so
//	we’re not just relying on magic numbers. Pragmatically speaking, though,
//	there are so many of them that it wouldn’t necessarily help with spotting
//	errors, besides which, the names would all be synthetic in one way or
//	another. Regardless, addressing this is a fairly low priority.
