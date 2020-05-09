/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“lbalAppleClangPostInitialization.hpp”
	Copyright © 2019-2020 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/


#pragma once


//	lbal
#include <lucenaBAL/details/lbalConfig.hpp>
#include <lucenaBAL/details/lbalDetectCompiler.hpp>
#include <lucenaBAL/details/lbalKnownVersions.hpp>


/*------------------------------------------------------------------------------
	llvm/clang compiler
*/

#if LBAL_TARGET_COMPILER_VANILLA_CLANG
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

	#if (__clang_major__ >= 6) && (LBAL_cpp_version > LBAL_CPP17_VERSION)
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
	#endif

	#if (__clang_major__ >= 8) && (LBAL_cpp_version > LBAL_CPP17_VERSION)
		//	__SEEME__ None of these have SD-6 macros, so we rely on a compiler
		//	version check and a language test. This will miss back-ported
		//	extensions, but will pick up preview implementations.

		#if !defined(LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS)
			#define LBAL_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS 1L
		#endif

		#if !defined(LBAL_CPP20_INIT_STATEMENTS_FOR_RANGE_BASED_FOR)
			#define LBAL_CPP20_INIT_STATEMENTS_FOR_RANGE_BASED_FOR 1L
		#endif
	#endif

	#if (__clang_major__ >= 9) && (LBAL_cpp_version > LBAL_CPP17_VERSION)
		//	__SEEME__ This did not have a proper SD-6 token value until
		//	Dec 2019.
		#if !defined(LBAL_CPP20_CONSTEXPR_VIRTUAL_FUNCTION)
			#if defined(__cpp_constexpr) && (__cpp_constexpr >= 201806L)
				#define LBAL_CPP20_CONSTEXPR_VIRTUAL_FUNCTION __cpp_constexpr
			#else
				#define LBAL_CPP20_CONSTEXPR_VIRTUAL_FUNCTION 201806L
			#endif
		#endif

		//	__SEEME__ This did not have a proper SD-6 token value until
		//	Dec 2019.
		#if !defined(LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION)
			#if defined(__cpp_init_captures) && (__cpp_init_captures >= 201803L)
				#define LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION __cpp_init_captures
			#else
				#define LBAL_CPP20_INIT_CAPTURES_PACK_EXPANSION 201803L
			#endif
		#endif

		//	__SEEME__ This did not have a proper SD-6 token value until
		//	Dec 2019.
		#if !defined(LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST)
			#if defined(__cpp_generic_lambdas) && (__cpp_generic_lambdas >= 201707L)
				#define LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST \
						__cpp_generic_lambdas
			#else
				#define LBAL_CPP20_GENERIC_LAMBDAS_TEMPLATE_PARAMETER_LIST 201707L
			#endif
		#endif

		#if !defined(LBAL_CPP20_VA_OPT)
			#define LBAL_CPP20_VA_OPT 1L
		#endif
	#endif

	#if (__clang_major__ >= 10) && (LBAL_cpp_version > LBAL_CPP17_VERSION)
		//	__SEEME__ This did not have a proper SD-6 token value until
		//	Dec 2019.
		#if !defined(LBAL_CPP20_DESIGNATED_INITIALIZERS)
			#if defined(__cpp_designated_initializers) \
					&& (__cpp_designated_initializers >= 201707L)
				#define LBAL_CPP20_DESIGNATED_INITIALIZERS \
						__cpp_designated_initializers
			#else
				#define LBAL_CPP20_DESIGNATED_INITIALIZERS 201707L
			#endif
		#endif
	#endif
#else
	#error "lbalClangPostInitialization.hpp was directly included while using the wrong compiler"
#endif
