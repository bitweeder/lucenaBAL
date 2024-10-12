/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalAppleClangPostInitialization.hpp”
	Copyright © 2019-2024 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See LICENSE.md for details.

	See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/


#pragma once


//	lbal
#include <lucenaBAL/lbalConfig.hpp>
#include <lucenaBAL/details/lbalDetectCompiler.hpp>
#include <lucenaBAL/details/lbalKnownVersions.hpp>


/*------------------------------------------------------------------------------
	Apple clang compiler

	Note that if our tokens are undefined at this point, it means that the
	equivalent SD-6 tokens are undefined; this can happen because the
	implementation does not supply them, or because the feature in question is
	unavailable. We resolve this here, if needed. Note that any situation that
	would require us to pre-emptively disable a feature would have been handled
	previously in `lbalAppleClangInitialization.hpp`.
*/

#if LBAL_TARGET_COMPILER_APPLE_CLANG
	//	C++98 features
	//
	//	These can be conditionally disabled. The older-style feature tests are
	//	used in case the newer-style is unsupported, so they are checked after
	//	the SD-6 checks have been performed.

	#if !defined(LBAL_CPP98_EXCEPTIONS) && __has_feature(__cxx_exceptions__)
		#define LBAL_CPP98_EXCEPTIONS 199711L
	#endif

	#if !defined(LBAL_CPP98_RTTI) && __has_feature(__cxx_exceptions__)
		#define LBAL_CPP98_RTTI 199711L
	#endif


	//	C++20 features

	#if (__clang_major__ >= 10) && (LBAL_cpp_version > LBAL_CPP17_VERSION)
		//	__SEEME__ None of these have SD-6 macros, so we rely on a compiler
		//	version check and a language test. This will miss back-ported
		//	extensions, but will pick up preview implementations.

		#if !defined(LBAL_CPP20_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS)
			#define LBAL_CPP20_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS 1L
		#endif

		#if !defined(LBAL_CPP20_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS)
			#define LBAL_CPP20_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS 1L
		#endif

		#if !defined(LBAL_CPP20_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS)
			#define LBAL_CPP20_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS 1L
		#endif

		#if !defined(LBAL_CPP20_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION)
			#define LBAL_CPP20_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION 1L
		#endif

		#if !defined(LBAL_CPP20_VA_OPT)
			#define LBAL_CPP20_VA_OPT 1L
		#endif
	#endif

	#if (__clang_major__ >= 11) && (LBAL_cpp_version > LBAL_CPP17_VERSION)
		//	__SEEME__ None of these have SD-6 macros, so we rely on a compiler
		//	version check and a language test. This will miss back-ported
		//	extensions, but will pick up preview implementations.

		#if !defined(LBAL_CPP20_INIT_STATEMENTS_FOR_RANGE_BASED_FOR)
			#define LBAL_CPP20_INIT_STATEMENTS_FOR_RANGE_BASED_FOR 1L
		#endif
	#endif

	#if (__clang_major__ >= 12) && (LBAL_cpp_version > LBAL_CPP17_VERSION)
		//	__SEEME__ There is no SD-6 token for this. Apple clang started
    //  supporting it initially in a bug fix in the Xcode 10-series.
		#if !defined(LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS)
      #define LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS 1L
		#endif
	#endif
#else
	#error "lbalAppleClangPostInitialization.hpp was directly included while using the wrong compiler"
#endif
