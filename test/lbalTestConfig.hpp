/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalTestConfig.hpp”
	Copyright © 2015-2024 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

------------------------------------------------------------------------------*/


#pragma once


//	lbal
#include <lucenaBAL/lbalConfig.hpp>
	//	This file MUST be included first.


//	If LBAL_CONFIG_test is defined and set to a non-zero value, it is assumed
//	that the current build target is a unit test application.
#define LBAL_CONFIG_test 1


#define LBAL_CONFIG_use_prefix_std 1
