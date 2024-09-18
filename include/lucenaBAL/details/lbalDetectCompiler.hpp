/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalDetectCompiler.hpp”
	Copyright © 2019-2024 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/


#pragma once


//	lbal
#include <lucenaBAL/lbalConfig.hpp>
#include <lucenaBAL/details/lbalKnownVersions.hpp>


/*------------------------------------------------------------------------------
	Detect the compiler being used and set up some basic identifiers.
*/

#if defined (__clang__) && defined (__llvm__) && defined (__APPLE_CC__)
	//	llvm/clang compiler targeting Apple platforms
	//
	//	Note that Apple has repurposed the __clang_major__, __clang_minor__,
	//	and __clang_patchlevel__ macros, so they are no longer in line with
	//	other clang distributions. We can test whether we’re in Apple clang by
	//	looking for __APPLE_CC__, __apple_build_version__, or some other macro.
	//
	//	__SEEME__ Apple LLVM 9.1 is the first release that actually advertises
	//	C++17 support (as per __cplusplus); previously, it only had C++14 with
	//	almost all C++17 extensions. Note that libc++ is still broken due to
	//	runtime issues, as described below, as well as other things.
	#if (__clang_major__ < 10)
		#error "Xcode 10.0 is th earliest supported version"
	#else
		//	Tested with a minimum of Xcode 10.0; the bundled compiler and
		//	Standard Library are roughly compatible with clang 6 and libc++,
		//	while adding some Apple-proprietary stuff. The most recently tested
		//	version is from Xcode 11.3.

		//	__SEEME__ Technically, we should be able to function perfectly well
		//	with older versions of Apple LLVM, but Apple deprecates anything
		//	more than about 3 years old, so it would be somewhat masochistic to
		//	fight it and undertake all that testing ourselves. Note that
		//	iterations of the current lucenaBAL design were previously tested
		//	with versions as far back as  LLVM 9.4+, and the largely-compatible
		//	older design was tested with much older versions going all the way
		//	back to the Apple gcc days. However, support for CFM, Carbon, etc,
		//	all got dropped long ago, so this is academic.
	#endif

	#if LBAL_cpp_version < LBAL_CPP11_VERSION
		#error "std=c++11 or higher is required"
	#endif

	//	Set up identifiers
	#define LBAL_NAME_COMPILER u8"Apple clang version " __clang_version__
	#define LBAL_TARGET_COMPILER_CLANG 1
	#define LBAL_TARGET_COMPILER_APPLE_CLANG 1
#elif defined (__clang__) && defined (__llvm__)
	//	Vanilla llvm/clang compiler
	//
	//	__FIXME__ Separate support should be added for c2/clang.
	#if (__clang_major__ < 6)
		#error "clang 6.0 is the earliest supported version"
	#endif

	#if LBAL_cpp_version < LBAL_CPP11_VERSION
		#error "std=c++11 or higher is required"
	#endif

	//	Set up identifiers
	#define LBAL_NAME_COMPILER u8"clang version " __clang_version__
	#define LBAL_TARGET_COMPILER_CLANG 1
	#define LBAL_TARGET_COMPILER_VANILLA_CLANG 1
#elif defined (__GNUC__)
	//	generic gcc-based compiler
	//
	//	Note that gcc guarantees that all system-specific predefined macros in
	//	the reserved namespace (i.e., __xxx__) will never resolve to 0 if they
	//	are actually defined.
	//
	//	__SEEME__ This must appear after clang, as the llvm derivatives have a
	//	tendency to define gcc’s macros; Apple LLVM, in particular, likes to
	//	pretend to be a crufty, ancient version of gcc.

	//	Convenience macro
	#if defined (LBAL_GCC_VERSION)
		#error "Don’t define LBAL_GCC_VERSION outside of this header"
	#endif

	#define LBAL_GCC_VERSION ( \
		__GNUC__ * 10000 + \
		__GNUC_MINOR__ * 100 +\
		__GNUC_PATCHLEVEL__ )

	#if (LBAL_GCC_VERSION < 40801)
		#error "gcc 4.8.1+ is required for C++11 support"
			//	For reference, 6.3 supports all C++11 and C++14 features except
			//	garbage collection, while the 4.8 series is the earliest with
			//	full C++11 support. gcc 7 is required for most C++17 language
			//	features with the exceptions of `std::filesystem` and the
			//	Parallelism TS.
	#endif

	#if LBAL_cpp_version < LBAL_CPP11_VERSION
		#error "std=c++11 or higher is required"
	#endif

	//	Set up identifiers
	#define LBAL_NAME_COMPILER u8"gcc version " __VERSION__
	#define LBAL_TARGET_COMPILER_GCC 1
	#define LBAL_TARGET_COMPILER_VANILLA_GCC 1


	//	We get rid of this since it isn’t an officially supported feature.
	#undef LBAL_GCC_VERSION
#elif defined (_MSC_VER) && defined (_WIN32)
	//	MSVC compiler as shipped Microsoft Visual Studio
	//
	//	__SEEME__ This must always appear last, as other compilers have a
	//	tendency to emulate MSVC by defining its macros.
	//
	//	__SEEME__ Our version requirement is arguably conservative, but
	//	supporting earlier versions would require significantly more work.
	#if (_MSC_FULL_VER < 190024210)
		#error "MSVS 2015 Update 3 is the earliest supported version"
	#endif

	#if LBAL_cpp_version < LBAL_CPP11_VERSION
		#error "std=c++11 or higher is required"
	#endif


	//	Set up identifiers
	#define LBAL_NAME_COMPILER u8"MSVC version " LBAL_Stringify_ (_MSC_VER)
	#define LBAL_TARGET_COMPILER_MSVC 1
	#define LBAL_TARGET_COMPILER_VANILLA_MSVC 1
#else
	//	Unsupported compiler; we don’t bother guessing.
	#error "Unsupported compiler"
#endif
