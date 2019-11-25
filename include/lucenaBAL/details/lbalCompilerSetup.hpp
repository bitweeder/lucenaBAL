/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“CompilerSetup.hpp”
	Copyright © 2007-2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

------------------------------------------------------------------------------*/


#pragma once


//	std
//	__SEEME__ We always guard inclusion of system headers when using MSVS due
//	its noisiness at high warning levels.
#if defined (_MSC_VER) && defined (_WIN32)
	#pragma warning (push, 0)
#endif

#include <ciso646>
	//	In C++, this is a do-nothing header we include just for the side
	//	effects: the Standard Library implementation will be configured
	//	and many assorted compiler-dependent feature detection macros will
	//	be defined.

#if defined (_MSC_VER) && defined (_WIN32)
	#pragma warning (pop)
#endif


//	lbal
#include <lucenaBAL/details/lbalConfig.hpp>


/*------------------------------------------------------------------------------
	Compiler Macros
*/

#if defined (__clang__) && defined (__llvm__) && defined (__APPLE_CC__)
	//	clang-llvm compiler targeting Apple platforms
	#include <lucenaBAL/details/compilers/lbalCompilerAppleClang.hpp>
#elif defined (__clang__) && defined (__llvm__)
	//	generic clang-llvm compiler
	#include <lucenaBAL/details/compilers/lbalCompilerClang.hpp>
#elif defined (__GNUC__)
	//	generic gcc-based compiler
	#include <lucenaBAL/details/compilers/lbalCompilerGCC.hpp>
#elif defined (_MSC_VER) && defined (_WIN32)
	//	Visual C++ targeting Windows; _WIN32 is also defined for 64-bit
	//	__SEEME__ This must always appear last, as other compilers have a tendency
	//	to emulate MSVC by defining its macros.
	#include <lucenaBAL/details/compilers/lbalCompilerMSVC.hpp>
#else
	//	Unsupported compiler; we don’t bother guessing.
	#error "Unsupported compiler"
#endif


/*------------------------------------------------------------------------------
	Set up the CPU name.
*/

#if LBAL_TARGET_CPU_ARM_64
	#define LBAL_NAME_TARGET_CPU u8"ARM64"
#elif LBAL_TARGET_CPU_ARM
	#define LBAL_NAME_TARGET_CPU u8"ARM"
#elif LBAL_TARGET_CPU_IA64
	#define LBAL_NAME_TARGET_CPU u8"ia64"
#elif LBAL_TARGET_CPU_X86_64
	#define LBAL_NAME_TARGET_CPU u8"x86_64"
#elif LBAL_TARGET_CPU_X86
	#define LBAL_NAME_TARGET_CPU u8"i386"
#endif
