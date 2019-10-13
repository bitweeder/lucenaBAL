/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“CompilerSetup.hpp”
	Copyright © 2007-2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	We assume support for at least C++17. See lbalFeatureSetup.hpp for
	descriptions of the various macros and flags.

------------------------------------------------------------------------------*/


#pragma once


//	std
//	__SEEME__ We always guard inclusion of system headers when using MSVS due to
//	their noisiness at high warning levels.
#if defined (_MSC_VER) && defined (_WIN32)
	#pragma warning (push, 0)
#endif

#if __has_include (<version>)
	#include <version>
		//	Once this header is universally available, it will take the place
		//	of <ciso646> abuse, providing the same functionality as well as
		//	(eventually) acting as a clearinghouse for SD-6 macros related to
		//	library features.
		//	__SEEME__ This must not be lbalVersion.hpp, as that header depends on
		//	this one.
#else
	#include <ciso646>
		//	In C++, this is a do-nothing header we include just for the side
		//	effects: the Standard Library implementation will be configured
		//	and many assorted compiler-dependent feature detection macros will
		//	be defined.
#endif


#if defined (_MSC_VER) && defined (_WIN32)
	#pragma warning (pop)
#endif


//	lbal
#include <lucenaBAL/lbalConfig.hpp>


/*------------------------------------------------------------------------------
	Compiler Macros

	__SEEME__ Arguably, it would be more desirable to give each compiler its own
	#include file and include them here conditionally rather than go the
	monolithic route. We trade off potential unnecessary recompilation of
	unaffected projects for simplified maintenance at this time.
*/

#if defined (__clang__) && defined (__llvm__) && defined (__APPLE_CC__)
	//	clang-llvm compiler targeting Apple platforms

	//	Note that Apple has repurposed the __clang_major__, __clang_minor__,
	//	and __clang_patchlevel__ macros, so they are no longer in line with
	//	other clang distributions. We can test whether we’re in Apple clang by
	//	looking for __APPLE_CC__, __apple_build_version__, or some other macro.
	//	__SEEME__ Apple LLVM 9.1 is the first release that actually advertises
	//	C++17 support (as per __cplusplus); previously, it only had C++14 with
	//	almost all C++17 extensions. Note that libc++ is still broken due to
	//	runtime issues, as described below, as well as other things.
	#if (__clang_major__ < 10)
		#error "Settings are only valid for Apple LLVM 10.0+"
	#else
		//	Tested with a minimum of Xcode 10.0; the bundled compiler and
		//	Standard Library are roughly compatible with clang 6 and libc++,
		//	while adding some Apple-proprietary stuff. The most recently tested
		//	version is from Xcode 11.0.

		//	__SEEME__ We’re should actually be compatible with LLVM 9.4+, but
		//	we don’t test with it any more.
	#endif

	#if __cplusplus < 201703L
		#error "std=c++17 or higher is required"
	#endif

	//	Identify processor and characteristics.
	//	Note that AMD64 and x86_64 both trigger each other’s identifiers. We
	//	simply refer to all of them as LBAL_TARGET_CPU_X86_64.
	#if __x86_64__ or __amd64__
		#define LBAL_TARGET_CPU_X86_64 1
		#define LBAL_TARGET_CPU_FAMILY_X86 1
	#elif __i386__
		#define LBAL_TARGET_CPU_X86 1
		#define LBAL_TARGET_CPU_FAMILY_X86 1
	#elif __aarch64__
		#define LBAL_TARGET_CPU_ARM_64 1
		#define LBAL_TARGET_CPU_FAMILY_ARM 1
	#elif __arm__
		#define LBAL_TARGET_CPU_ARM 1
		#define LBAL_TARGET_CPU_FAMILY_ARM 1
	#else
		#error "Processor unknown. Update lbalCompilerSetup.hpp."
	#endif

	#if __LITTLE_ENDIAN__
		#define LBAL_TARGET_RT_LITTLE_ENDIAN 1
	#elif __BIG_ENDIAN__
		#define LBAL_TARGET_RT_BIG_ENDIAN 1
	#endif

	#if __LP64__
		#define LBAL_TARGET_RT_64_BIT 1
	#else
		#define LBAL_TARGET_RT_32_BIT 1
	#endif

	#if __SIZEOF_DOUBLE__ > __SIZEOF_FLOAT__
		#define LBAL_TYPE_DOUBLE_GT_FLOAT 1
	#endif

	#if __SIZEOF_LONG_DOUBLE__ > __SIZEOF_DOUBLE__
		#define LBAL_TYPE_LONG_DOUBLE_GT_DOUBLE 1
	#endif


	//	Identify vector instruction sets, if any.
	#ifdef __SSE__
		#define LBAL_TARGET_VEC_SSE 1
	#endif

	#ifdef __SSE2__
		#define LBAL_TARGET_VEC_SSE2 1
	#endif

	#ifdef __SSE3__
		#define LBAL_TARGET_VEC_SSE3 1
	#endif

	#ifdef __SSE4_1__
		#define LBAL_TARGET_VEC_SSE41 1
	#endif

	#ifdef __SSE4_2__
		#define LBAL_TARGET_VEC_SSE42 1
	#endif

	#ifdef __AVX__
		#define LBAL_TARGET_VEC_AVX 1
	#endif

	#ifdef __AVX2__
		#define LBAL_TARGET_VEC_AVX2 1
	#endif

	//	Currently unused
	#ifdef __AVX512BW__
	#endif

	#ifdef __AVX512CD__
	#endif

	#ifdef __AVX512DQ__
	#endif

	#ifdef __AVX512F__
	#endif

	#ifdef __AVX5124FMAPS__
	#endif

	#ifdef __AVX5124VNNIW__
	#endif

	#ifdef __AVX512IFMA__
	#endif

	#ifdef __AVX512VBMI__
	#endif

	#ifdef __AVX512VPOPCNTDQ__
	#endif

	#ifdef __AVX512VL__
	#endif


	//	Identify executable file fromat.
	#ifdef __MACH__
		#define LBAL_TARGET_RT_MACHO 1
	#else
		#error "No other executable file formats supported for Apple targets"
	#endif


	#if __SIZEOF_LONG_LONG__ == 8
		#define LBAL_TYPE_HAS_INT64 1
	#endif

	#if __SIZEOF_INT128__ == 16
		#define LBAL_TYPE_HAS_INT128 1
	#endif

	#define LBAL_TYPE_EXACT_WIDTH_INTEGERS 1


	//	__SEEME__ Apparently, __STDC_VERSION__ only gets set if we’re using the
	//	C compiler, so a test doesn’t work. Since we’re requiring C++17 or
	//	greater, we assume the following is available since it was a
	//	requirement of C++11.
	#define LBAL_C99_PREPROCESSOR 1


	//	Test for C++98 features.
	//	These can be conditionally disabled.
	#if (__cpp_exceptions >= 199711L)
		#define LBAL_CPP98_EXCEPTIONS __cpp_exceptions
	#elif __has_feature(cxx_exceptions)
		#define LBAL_CPP98_EXCEPTIONS 199711L
	#endif

	#if (__cpp_rtti >= 199711L)
		#define LBAL_CPP98_RTTI __cpp_rtti
	#elif __has_feature(cxx_rtti)
		#define LBAL_CPP98_RTTI 199711L
	#endif


	//	Test for C++11 features.

	#if (__cpp_alias_templates >= 200704L)
		#define LBAL_CPP11_ALIAS_TEMPLATES __cpp_alias_templates
	#elif (__cplusplus >= 201103L)
		#define LBAL_CPP11_ALIAS_TEMPLATES 200704L
	#endif

	#if (__cpp_attributes >= 200809L)
		#define LBAL_CPP11_ATTRIBUTES __cpp_attributes
	#elif (__cplusplus >= 201103L)
		#define LBAL_CPP11_ATTRIBUTES 200809L
	#endif

	#if (__cpp_constexpr >= 200704L)
		#define LBAL_CPP11_CONSTEXPR __cpp_constexpr
	#elif (__cplusplus >= 201103L)
		#define LBAL_CPP11_CONSTEXPR 200704L
	#endif

	#if (__cpp_decltype >= 200707L)
		#define LBAL_CPP11_DECLTYPE __cpp_decltype
	#elif (__cplusplus >= 201103L)
		#define LBAL_CPP11_DECLTYPE 200707L
	#endif

	#if (__cpp_delegating_constructors >= 200604L)
		#define LBAL_CPP11_DELEGATING_CONSTRUCTORS __cpp_delegating_constructors
	#elif (__cplusplus >= 201103L)
		#define LBAL_CPP11_DELEGATING_CONSTRUCTORS 200604L
	#endif

	#if (__cpp_inheriting_constructors >= 200802L)
		#define LBAL_CPP11_INHERITING_CONSTRUCTORS __cpp_inheriting_constructors
	#elif (__cplusplus >= 201103L)
		#define LBAL_CPP11_INHERITING_CONSTRUCTORS 200802L
	#endif

	//	__SEEME__ There is no `__cplusplus` check since this can be
	//	conditionally disabled.
	#if (__cpp_threadsafe_static_init >= 200806L)
		#define LBAL_CPP11_THREADSAFE_STATIC_INIT __cpp_threadsafe_static_init
	#endif


	//	C++14 features

	#if (__cpp_aggregate_nsdmi >= 201304L)
		#define LBAL_CPP14_AGGREGATE_NSDMI __cpp_aggregate_nsdmi
	#elif (__cplusplus >= 201402L)
		#define LBAL_CPP14_AGGREGATE_NSDMI 201304L
	#endif

	#if (__cpp_binary_literals >= 201304L)
		#define LBAL_CPP14_BINARY_LITERALS __cpp_binary_literals
	#elif (__cplusplus >= 201402L)
		#define LBAL_CPP14_BINARY_LITERALS 201304L
	#endif

	#if (__cpp_constexpr >= 201304L)
		#define LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS __cpp_constexpr
	#elif (__cplusplus >= 201402L)
		#define LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS 201304L
	#endif

	#if (__cpp_decltype_auto >= 201304L)
		#define LBAL_CPP14_DECLTYPE_AUTO __cpp_decltype_auto
	#elif (__cplusplus >= 201402L)
		#define LBAL_CPP14_DECLTYPE_AUTO 201304L
	#endif

	#if (__cpp_generic_lambdas >= 201304L)
		#define LBAL_CPP14_GENERIC_LAMBDAS __cpp_generic_lambdas
	#elif (__cplusplus >= 201402L)
		#define LBAL_CPP14_GENERIC_LAMBDAS 201304L
	#endif

	#if (__cpp_init_captures >= 201304L)
		#define LBAL_CPP14_INIT_CAPTURES __cpp_init_captures
	#elif (__cplusplus >= 201402L)
		#define LBAL_CPP14_INIT_CAPTURES 201304L
	#endif

	//	As of vanilla clang 8, this is disabled by default in order to avoid
	//	ABI-breaking changes. It’s unclear when it will be enabled by default.
	#if (__cpp_sized_deallocation >= 201304L)
		#define LBAL_CPP14_SIZED_DEALLOCATION __cpp_sized_deallocation
	#endif


	//	C++17 features
	//	__SEEME__ Apple continues to lag vanilla clang by over a year in odd
	//	ways. As of Apple LLVM 10.0, their clang compiler advertises full C++17
	//	compliance, but a number of feature test macros fail (and then there’s
	//	the real Standard Library deficiencies...):
	//
	//		- __cpp_guaranteed_copy_elision is undefined; testing suggests
	//			the feature is implemented; no tracking
	//		- __cpp_deduction_guides returns an outdated value; no tracking,
	//			as it’s unclear if this needs it
	//		- __cpp_nontype_template_parameter_auto is undefined; testing
	//			suggests the feature is implemented; no tracking
	//
	//	As for other potential issues, __cpp_threadsafe_static_init _can_ be
	//	set to 0 depending on compiler arguments, but defaults to being on.

	#if (__cpp_aggregate_bases >= 201603L)
		#define LBAL_CPP17_AGGREGATE_BASES __cpp_aggregate_bases
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_AGGREGATE_BASES 201603L
	#endif

	#if (__cpp_aligned_new >= 201606L)
		#define LBAL_CPP17_ALIGNED_NEW __cpp_aligned_new
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_ALIGNED_NEW 201606L
	#endif

	#if (__cpp_capture_star_this >= 201603L)
		#define LBAL_CPP17_CAPTURE_STAR_THIS __cpp_capture_star_this
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_CAPTURE_STAR_THIS 201603L
	#endif

	#if (__cpp_constexpr >= 201603L)
		#define LBAL_CPP17_CONSTEXPR_LAMBDA __cpp_constexpr
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_CONSTEXPR_LAMBDA 201603L
	#endif

	#if (__cpp_deduction_guides >= 201606L)
		#define LBAL_CPP17_DEDUCTION_GUIDES __cpp_deduction_guides
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_DEDUCTION_GUIDES 201606L
	#endif

	#if (__cpp_deduction_guides >= 201611L)
		#define LBAL_CPP17_DEDUCTION_GUIDES_NB __cpp_deduction_guides
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_DEDUCTION_GUIDES_NB 201611L
	#endif

	#if (__cpp_deduction_guides >= 201703L)
		#define LBAL_CPP17_DEDUCTION_GUIDES_DR __cpp_deduction_guides
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_DEDUCTION_GUIDES_DR 201703L
	#endif

	#if (__cpp_enumerator_attributes >+ 201411L)
		#define LBAL_CPP17_ENUMERATOR_ATTRIBUTES __cpp_enumerator_attributes
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_ENUMERATOR_ATTRIBUTES 201411L
	#endif

	#if (__cpp_fold_expressions >= 201411L)
		#define LBAL_CPP17_FOLD_EXPRESSIONS __cpp_fold_expressions
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_FOLD_EXPRESSIONS 201411L
	#endif

	#if (__cpp_fold_expressions >= 201603L)
		#define LBAL_CPP17_FOLD_EXPRESSIONS_REVISED __cpp_fold_expressions
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_FOLD_EXPRESSIONS_REVISED 201603L
	#endif

	#if (__cpp_guaranteed_copy_elision >= 201606L)
		#define LBAL_CPP17_GUARANTEED_COPY_ELISION __cpp_guaranteed_copy_elision
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_GUARANTEED_COPY_ELISION 201606L
	#endif

	#if (__cpp_hex_float >= 201603L)
		#define LBAL_CPP17_HEX_FLOAT __cpp_hex_float
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_HEX_FLOAT 201603L
	#endif

	#if (__cpp_if_constexpr >= 201606L)
		#define LBAL_CPP17_IF_CONSTEXPR __cpp_if_constexpr
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_IF_CONSTEXPR 201606L
	#endif

	#if (__cpp_inheriting_constructors >= 201511L)
		#define LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED __cpp_inheriting_constructors
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED 201511L
	#endif

	//	As of vanilla clang 8, this is disabled by default in order to avoid a
	//	defect introduced by the associated proposal (which was intended to
	//	resolve another defect).
	#if (__cpp_template_template_args >= 201611L)
		#define LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS __cpp_template_template_args
	#endif


	//	C++2a features

	//	__SEEME__ <https://en.cppreference.com/w/cpp/compiler_support> reports
	//	that this is non-compliant, but that’s not exactly correct. Rather,
	//	Apple selectively disables detection for features it doesn’t want to
	//	advertise support for, typically because they would break ABI and/or
	//	they’ve had the implementation stripped out. Additionally, Apple lags a
	//	bit in updating the token values to reflect updates; it’s not always
	//	clear if this is an oversight or if an update has been held back.
	#define LBAL_CPP2A_INTEGRATING_OUR_FEATURE_TEST_MACROS 1L

	//	__SEEME__ None of these have SD-6 macros, so we rely on a compiler
	//	version check and a language test.
	#if (__clang_major__ >= 10) && (__cplusplus > 201703L)
		#define LBAL_CPP2A_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS 1L
		#define LBAL_CPP2A_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS 1L
		#define LBAL_CPP2A_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS 1L
		#define LBAL_CPP2A_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION 1L
		#define LBAL_CPP2A_VA_OPT 1L
	#endif

	#if (__clang_major__ >= 11) && (__cplusplus > 201703L)
		#define LBAL_CPP2A_INIT_STATEMENTS_FOR_RANGE_BASED_FOR 1L
	#endif

	#if (__cpp_aggregate_paren_init >= 201902L)
		#define LBAL_CPP2A_AGGREGATE_PAREN_INIT __cpp_aggregate_paren_init
	#endif

	#if (__cpp_char8_t >= 201811L)
		#define LBAL_CPP2A_CHAR8_T __cpp_char8_t
	#endif

	#if (__cpp_concepts >= 201806L)
		#define LBAL_CPP2A_CONCEPTS __cpp_concepts
	#endif

	#if (__cpp_conditional_explicit >= 201806L)
		#define LBAL_CPP2A_CONDITIONAL_EXPLICIT __cpp_conditional_explicit
	#endif

	#if (__cpp_constexpr >= 201907L)
		#define LBAL_CPP2A_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION __cpp_constexpr
	#endif

	#if (__cpp_constexpr_dynamic_alloc >= 201907L)
		#define LBAL_CPP2A_CONSTEXPR_DYNAMIC_ALLOC __cpp_constexpr_dynamic_alloc
	#endif

	#if (__cpp_constinit >= 201907L)
		#define LBAL_CPP2A_CONSTINIT __cpp_constinit
	#endif

	#if (__cpp_coroutines >= 201902L)
		#define LBAL_CPP2A_COROUTINES __cpp_coroutines
	#endif

	#if (__cpp_deduction_guides >= 201907L)
		#define LBAL_CPP2A_DEDUCTION_GUIDES_FOR_AGGREGATES __cpp_deduction_guides
	#endif

	#if (__cpp_impl_destroying_delete >= 201806L)
		#define LBAL_CPP2A_DESTROYING_DELETE __cpp_impl_destroying_delete
	#endif

	#if (__cpp_nontype_template_parameter_class >= 201806L)
		#define LBAL_CPP2A_NONTYPE_TEMPLATE_PARAMETER_CLASS __cpp_nontype_template_parameter_class
	#endif

	#if (__cpp_impl_three_way_comparison >= 201711L)
		#define LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR __cpp_impl_three_way_comparison
	#endif

	#if (__cpp_impl_three_way_comparison > = 201907L)
		#define LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR_TUNEUP __cpp_impl_three_way_comparison
	#endif

	#ifdef __has_cpp_attribute
		#if (__has_cpp_attribute(likely) >= 201803L)
			#define LBAL_CPP2A_ATTRIBUTE_LIKELY __has_cpp_attribute(likely)
		#endif

		#if (__has_cpp_attribute(unlikely) >= 201803L)
			#define LBAL_CPP2A_ATTRIBUTE_UNLIKELY __has_cpp_attribute(unlikely)
		#endif

		#if (__has_cpp_attribute(no_unique_address) >= 201803L)
			#define LBAL_CPP2A_ATTRIBUTE_NO_UNIQUE_ADDRESS __has_cpp_attribute(no_unique_address)
		#endif
	#endif	//	__has_cpp_attribute


	//	intrinsic functions
	#define LBAL_HINT_likely(LBAL_expr_) __builtin_expect (LBAL_expr_, true)
	#define LBAL_HINT_unlikely(LBAL_expr_) __builtin_expect (LBAL_expr_, false)


	//	Symbol visibility macros
	#define LBAL_VIS_HIDDEN __attribute__ ((__visibility__("hidden")))

	#define LBAL_VIS_CLASS_EXPORT __attribute__ ((__visibility__("default")))
	#define LBAL_VIS_CLASS_IMPORT __attribute__ ((__visibility__("default")))

	#if __has_attribute (__type_visibility__)
		#define LBAL_VIS_ENUM __attribute__ ((__type_visibility__("default")))

		#define LBAL_VIS_CLASS_TEMPLATE __attribute__ ((__type_visibility__("default")))

		#define LBAL_VIS_EXTERN_CLASS_TEMPLATE_EXPORT __attribute__ ((__visibility__("default")))
		#define LBAL_VIS_EXTERN_CLASS_TEMPLATE_IMPORT __attribute__ ((__visibility__("default")))
	#else
		#define LBAL_VIS_ENUM

		#define LBAL_VIS_CLASS_TEMPLATE __attribute__ ((__visibility__("default")))

		#define LBAL_VIS_EXTERN_CLASS_TEMPLATE_EXPORT
		#define LBAL_VIS_EXTERN_CLASS_TEMPLATE_IMPORT
	#endif

	#define LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_EXPORT
	#define LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_IMPORT

	#define LBAL_VIS_MEMBER_CLASS_TEMPLATE __attribute__ ((__visibility__("hidden")))

	#define LBAL_VIS_MEMBER_FUNCTION_TEMPLATE inline __attribute__ ((__visibility__("hidden")))
		//	__SEEME__ The “inline” declaration is extraneous, but required due to
		//	 a currently unaddressed clang defect (cf., the elusive PR32114).

	#define LBAL_VIS_FUNC_EXPORT __attribute__ ((__visibility__("default")))
	#define LBAL_VIS_FUNC_IMPORT __attribute__ ((__visibility__("default")))

	//	__SEEME__ The first definition is a fallback if it turns out I’ve
	//	misunderstood the requirements on general inline functions.
//	#define LBAL_VIS_INLINE_FUNC LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC
	#define LBAL_VIS_INLINE_FUNC __attribute__ ((__visibility__("hidden")))

	//	__SEEME__ Using the internal_linkage attribute is equivalent to using the
	//	static keyword in C, and is semantically preferrable to inlining.
	//	However, what we -really- want is be able to strip this down to just
	//	LBAL_VIS_HIDDEN, but this requires linker support we don’t have, yet.
	//	See <http://lists.llvm.org/pipermail/cfe-dev/2018-July/058450.html> and
	//	<https://reviews.llvm.org/D49240?id=155185> for details.
	#if __has_attribute (internal_linkage)
		#define LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC __attribute__ ((__visibility__("hidden"), internal_linkage))
	#else
		#define LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC __attribute__ ((__visibility__("hidden"), __always_inline__))
	#endif

	#define LBAL_VIS_OVERLOADABLE_FUNC_EXPORT __attribute__ ((__visibility__("default")))
	#define LBAL_VIS_OVERLOADABLE_FUNC_IMPORT __attribute__ ((__visibility__("default")))

	#define LBAL_VIS_EXTERN_EXPORT
	#define LBAL_VIS_EXTERN_IMPORT

	#define LBAL_VIS_EXCEPTION_EXPORT __attribute__ ((__visibility__("default")))
	#define LBAL_VIS_EXCEPTION_IMPORT __attribute__ ((__visibility__("default")))

	#define LBAL_FUNC_CALL_C(LBAL_func_name_) LBAL_func_name_
	#define LBAL_FUNC_CALL_STD(LBAL_func_name_) LBAL_func_name_
	#define LBAL_FUNC_CALLBACK_C(LBAL_func_name_) (*LBAL_func_name_)
	#define LBAL_FUNC_CALLBACK_STD(LBAL_func_name_) (*LBAL_func_name_)


	//	Set up identifiers
	#define LBAL_NAME_COMPILER u8"clang version " __clang_version__
	#define LBAL_TARGET_COMPILER_CLANG 1

#elif defined (__clang__) && defined (__llvm__)
	//	generic clang-llvm compiler

	#if (__clang_major__ < 6)
		#error "Settings are only valid for clang 6.0+"
	#else
		//	__FIXME__ This is actually untested, as it’s just a fix-up of the
		//	Apple LLVM section.
	#endif

	#if __cplusplus < 201703L
		#error "std=c++17 or higher is required"
	#endif

	//	Identify processor and characteristics.
	//	Note that AMD64 and x86_64 both trigger each other’s identifiers. We
	//	simply refer to all of them as LBAL_TARGET_CPU_X86_64.
	#if __x86_64__ or __amd64__
		#define LBAL_TARGET_CPU_X86_64 1
		#define LBAL_TARGET_CPU_FAMILY_X86 1
	#elif __i386__
		#define LBAL_TARGET_CPU_X86 1
		#define LBAL_TARGET_CPU_FAMILY_X86 1
	#elif __aarch64__
		#define LBAL_TARGET_CPU_ARM_64 1
		#define LBAL_TARGET_CPU_FAMILY_ARM 1
	#elif __arm__
		#define LBAL_TARGET_CPU_ARM 1
		#define LBAL_TARGET_CPU_FAMILY_ARM 1
	#else
		#error "Processor unknown. Update lbalCompilerSetup.hpp."
	#endif

	#if __LITTLE_ENDIAN__
		#define LBAL_TARGET_RT_LITTLE_ENDIAN 1
	#elif __BIG_ENDIAN__
		#define LBAL_TARGET_RT_BIG_ENDIAN 1
	#endif

	#if __LP64__
		#define LBAL_TARGET_RT_64_BIT 1
	#else
		#define LBAL_TARGET_RT_32_BIT 1
	#endif

	#if __SIZEOF_DOUBLE__ > __SIZEOF_FLOAT__
		#define LBAL_TYPE_DOUBLE_GT_FLOAT 1
	#endif

	#if __SIZEOF_LONG_DOUBLE__ > __SIZEOF_DOUBLE__
		#define LBAL_TYPE_LONG_DOUBLE_GT_DOUBLE 1
	#endif


	//	Identify vector instruction sets, if any.
	#ifdef __SSE__
		#define LBAL_TARGET_VEC_SSE 1
	#endif

	#ifdef __SSE2__
		#define LBAL_TARGET_VEC_SSE2 1
	#endif

	#ifdef __SSE3__
		#define LBAL_TARGET_VEC_SSE3 1
	#endif

	#ifdef __SSE4_1__
		#define LBAL_TARGET_VEC_SSE41 1
	#endif

	#ifdef __SSE4_2__
		#define LBAL_TARGET_VEC_SSE42 1
	#endif

	#ifdef __AVX__
		#define LBAL_TARGET_VEC_AVX 1
	#endif

	#ifdef __AVX2__
		#define LBAL_TARGET_VEC_AVX2 1
	#endif


	//	Identify executable file fromat
	#if defined (__ELF__)
		#define LBAL_TARGET_RT_ELF 1
	#elif defined (_WIN32)
		#define LBAL_TARGET_RT_COFF 1
	#elif defined (__MACH__)
		#define LBAL_TARGET_RT_MACHO 1
	#elif defined (__wasm__)
		#define LBAL_TARGET_RT_WASM 1
	#else
		#error "Unknown executable file format"
	#endif


	#if __SIZEOF_LONG_LONG__ == 8
		#define LBAL_TYPE_HAS_INT64 1
	#endif

	#if __SIZEOF_INT128__ == 16
		#define LBAL_TYPE_HAS_INT128 1
	#endif

	#define LBAL_TYPE_EXACT_WIDTH_INTEGERS 1


	//	__SEEME__ Apparently, __STDC_VERSION__ only gets set if we’re using the C
	//	compiler, so this test doesn’t work. Since we’re requiring C++14 or
	//	greater, we assume the following C99 features are available.
	#if 1	//	__STDC_VERSION__ >= 199901L
		#define LBAL_C99_PREPROCESSOR 1
	#else
		#warning "D'oh!"
	#endif	//	__STDC_VERSION__


	//	C++98 features

	//	These can be conditionally disabled.
	#if (__cpp_exceptions >= 199711L)
		#define LBAL_CPP98_EXCEPTIONS __cpp_exceptions
	#elif __has_feature(cxx_exceptions)
		#define LBAL_CPP98_EXCEPTIONS 199711L
	#endif

	#if (__cpp_rtti >= 199711L)
		#define LBAL_CPP98_RTTI __cpp_rtti
	#elif __has_feature(cxx_rtti)
		#define LBAL_CPP98_RTTI 199711L
	#endif


	//	C++11 features

	#if (__cpp_alias_templates >= 200704L)
		#define LBAL_CPP11_ALIAS_TEMPLATES __cpp_alias_templates
	#elif (__cplusplus >= 201103L)
		#define LBAL_CPP11_ALIAS_TEMPLATES 200704L
	#endif

	#if (__cpp_attributes >= 200809L)
		#define LBAL_CPP11_ATTRIBUTES __cpp_attributes
	#elif (__cplusplus >= 201103L)
		#define LBAL_CPP11_ATTRIBUTES 200809L
	#endif

	#if (__cpp_constexpr >= 200704L)
		#define LBAL_CPP11_CONSTEXPR __cpp_constexpr
	#elif (__cplusplus >= 201103L)
		#define LBAL_CPP11_CONSTEXPR 200704L
	#endif

	#if (__cpp_decltype >= 200707L)
		#define LBAL_CPP11_DECLTYPE __cpp_decltype
	#elif (__cplusplus >= 201103L)
		#define LBAL_CPP11_DECLTYPE 200707L
	#endif

	#if (__cpp_delegating_constructors >= 200604L)
		#define LBAL_CPP11_DELEGATING_CONSTRUCTORS __cpp_delegating_constructors
	#elif (__cplusplus >= 201103L)
		#define LBAL_CPP11_DELEGATING_CONSTRUCTORS 200604L
	#endif

	#if (__cpp_inheriting_constructors >= 200802L)
		#define LBAL_CPP11_INHERITING_CONSTRUCTORS __cpp_inheriting_constructors
	#elif (__cplusplus >= 201103L)
		#define LBAL_CPP11_INHERITING_CONSTRUCTORS 200802L
	#endif

	//	__SEEME__ There is no `__cplusplus` check since this can be
	//	conditionally disabled.
	#if (__cpp_threadsafe_static_init >= 200806L)
		#define LBAL_CPP11_THREADSAFE_STATIC_INIT __cpp_threadsafe_static_init
	#endif


	//	C++14 features

	#if (__cpp_aggregate_nsdmi >= 201304L)
		#define LBAL_CPP14_AGGREGATE_NSDMI __cpp_aggregate_nsdmi
	#elif (__cplusplus >= 201402L)
		#define LBAL_CPP14_AGGREGATE_NSDMI 201304L
	#endif

	#if (__cpp_binary_literals >= 201304L)
		#define LBAL_CPP14_BINARY_LITERALS __cpp_binary_literals
	#elif (__cplusplus >= 201402L)
		#define LBAL_CPP14_BINARY_LITERALS 201304L
	#endif

	#if (__cpp_constexpr >= 201304L)
		#define LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS __cpp_constexpr
	#elif (__cplusplus >= 201402L)
		#define LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS 201304L
	#endif

	#if (__cpp_decltype_auto >= 201304L)
		#define LBAL_CPP14_DECLTYPE_AUTO __cpp_decltype_auto
	#elif (__cplusplus >= 201402L)
		#define LBAL_CPP14_DECLTYPE_AUTO 201304L
	#endif

	#if (__cpp_generic_lambdas >= 201304L)
		#define LBAL_CPP14_GENERIC_LAMBDAS __cpp_generic_lambdas
	#elif (__cplusplus >= 201402L)
		#define LBAL_CPP14_GENERIC_LAMBDAS 201304L
	#endif

	#if (__cpp_init_captures >= 201304L)
		#define LBAL_CPP14_INIT_CAPTURES __cpp_init_captures
	#elif (__cplusplus >= 201402L)
		#define LBAL_CPP14_INIT_CAPTURES 201304L
	#endif

	//	As of vanilla clang 8, this is disabled by default in order to avoid
	//	ABI-breaking changes. It’s unclear when it will be enabled by default.
	#if (__cpp_sized_deallocation >= 201304L)
		#define LBAL_CPP14_SIZED_DEALLOCATION __cpp_sized_deallocation
	#endif


	//	C++17 features

	#if (__cpp_aggregate_bases >= 201603L)
		#define LBAL_CPP17_AGGREGATE_BASES __cpp_aggregate_bases
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_AGGREGATE_BASES 201603L
	#endif

	#if (__cpp_aligned_new >= 201606L)
		#define LBAL_CPP17_ALIGNED_NEW __cpp_aligned_new
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_ALIGNED_NEW 201606L
	#endif

	#if (__cpp_capture_star_this >= 201603)
		#define LBAL_CPP17_CAPTURE_STAR_THIS __cpp_capture_star_this
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_CAPTURE_STAR_THIS 201603
	#endif

	#if (__cpp_constexpr >= 201603L)
		#define LBAL_CPP17_CONSTEXPR_LAMBDA __cpp_constexpr
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_CONSTEXPR_LAMBDA 201603L
	#endif

	#if (__cpp_deduction_guides >= 201606L)
		#define LBAL_CPP17_DEDUCTION_GUIDES __cpp_deduction_guides
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_DEDUCTION_GUIDES 201606L
	#endif

	#if (__cpp_deduction_guides >= 201611L)
		#define LBAL_CPP17_DEDUCTION_GUIDES_NB __cpp_deduction_guides
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_DEDUCTION_GUIDES_NB 201611L
	#endif

	#if (__cpp_deduction_guides >= 201703L)
		#define LBAL_CPP17_DEDUCTION_GUIDES_DR __cpp_deduction_guides
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_DEDUCTION_GUIDES_DR 201703L
	#endif

	#if (__cpp_enumerator_attributes >= 201411L)
		#define LBAL_CPP17_ENUMERATOR_ATTRIBUTES __cpp_enumerator_attributes
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_ENUMERATOR_ATTRIBUTES 201411L
	#endif

	#if (__cpp_fold_expressions >= 201411L)
		#define LBAL_CPP17_FOLD_EXPRESSIONS __cpp_fold_expressions
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_FOLD_EXPRESSIONS 201411L
	#endif

	#if (__cpp_fold_expressions >= 201603L)
		#define LBAL_CPP17_FOLD_EXPRESSIONS_REVISED __cpp_fold_expressions
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_FOLD_EXPRESSIONS_REVISED 201603L
	#endif

	#if (__cpp_guaranteed_copy_elision >= 201606L)
		#define LBAL_CPP17_GUARANTEED_COPY_ELISION __cpp_guaranteed_copy_elision
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_GUARANTEED_COPY_ELISION 201606L
	#endif

	#if (__cpp_hex_float >= 201603L)
		#define LBAL_CPP17_HEX_FLOAT __cpp_hex_float
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_HEX_FLOAT 201603L
	#endif

	#if (__cpp_if_constexpr >= 201606L)
		#define LBAL_CPP17_IF_CONSTEXPR __cpp_if_constexpr
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_IF_CONSTEXPR 201606L
	#endif

	#if (__cpp_inheriting_constructors >= 201511L)
		#define LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED __cpp_inheriting_constructors
	#elif (__cplusplus >= 201703L)
		#define LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED 201511L
	#endif

	//	As of clang 8, this is disabled by default in order to avoid a defect
	//	introduced by the associated proposal (which was intended to resolve
	//	another defect).
	#if (__cpp_template_template_args >= 201611L)
		#define LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS __cpp_template_template_args
	#endif


	//	C++2a features

	#define LBAL_CPP2A_INTEGRATING_OUR_FEATURE_TEST_MACROS 1L

	//	__SEEME__ None of these have SD-6 macros, so we rely on a compiler
	//	version check and a language test.
	#if (__clang_major__ >= 6) && (__cplusplus > 201703L)
		#define LBAL_CPP2A_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS 1L
		#define LBAL_CPP2A_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS 1L
		#define LBAL_CPP2A_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS 1L
		#define LBAL_CPP2A_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION	1L
	#endif

	#if (__clang_major__ >= 8) && (__cplusplus > 201703L)
		#define LBAL_CPP2A_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS 1L
		#define LBAL_CPP2A_INIT_STATEMENTS_FOR_RANGE_BASED_FOR 1L
	#endif

	#if (__clang_major__ >= 9) && (__cplusplus > 201703L)
		#define LBAL_CPP2A_CONSTEXPR_VIRTUAL_FUNCTION 1L
		#define LBAL_CPP2A_PACK_EXPANSION_IN_LAMBDA_INIT_CAPTURE 1L
		#define LBAL_CPP2A_TEMPLATE_PARAMETER_LIST_FOR_GENERIC_LAMBDAS 1L
		#define LBAL_CPP2A_VA_OPT 1L
	#endif

	#if (__clang_major__ >= 10) && (__cplusplus > 201703L)
		#define LBAL_CPP2A_DESIGNATED_INITIALIZERS 1L
	#endif

	#if (__cpp_aggregate_paren_init >= 201902L)
		#define LBAL_CPP2A_AGGREGATE_PAREN_INIT __cpp_aggregate_paren_init
	#endif

	#if (__cpp_char8_t >= 201811L)
		#define LBAL_CPP2A_CHAR8_T __cpp_char8_t
	#endif

	#if (__cpp_concepts >= 201806L)
		#define LBAL_CPP2A_CONCEPTS __cpp_concepts
	#endif

	#if (__cpp_conditional_explicit >= 201806L)
		#define LBAL_CPP2A_CONDITIONAL_EXPLICIT __cpp_conditional_explicit
	#endif

	#if (__cpp_constexpr >= 201907L)
		#define LBAL_CPP2A_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION __cpp_constexpr
	#endif

	#if (__cpp_constexpr_dynamic_alloc >= 201907L)
		#define LBAL_CPP2A_CONSTEXPR_DYNAMIC_ALLOC __cpp_constexpr_dynamic_alloc
	#endif

	#if (__cpp_constinit >= 201907L)
		#define LBAL_CPP2A_CONSTINIT __cpp_constinit
	#endif

	#if (__cpp_coroutines >= 201902L)
		#define LBAL_CPP2A_COROUTINES __cpp_coroutines
	#endif

	#if (__cpp_deduction_guides >= 201907L)
		#define LBAL_CPP2A_DEDUCTION_GUIDES_FOR_AGGREGATES __cpp_deduction_guides
	#endif

	#if (__cpp_impl_destroying_delete >= 201806L)
		#define LBAL_CPP2A_DESTROYING_DELETE __cpp_impl_destroying_delete
	#endif

	#if (__cpp_nontype_template_parameter_class >= 201806L)
		#define LBAL_CPP2A_NONTYPE_TEMPLATE_PARAMETER_CLASS __cpp_nontype_template_parameter_class
	#endif

	#if (__cpp_impl_three_way_comparison >= 201711L)
		#define LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR __cpp_impl_three_way_comparison
	#endif

	#if (__cpp_impl_three_way_comparison > = 201907L)
		#define LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR_TUNEUP __cpp_impl_three_way_comparison
	#endif

	#ifdef __has_cpp_attribute
		#if (__has_cpp_attribute(likely) >= 201803L)
			#define LBAL_CPP2A_ATTRIBUTE_LIKELY __has_cpp_attribute(likely)
		#endif

		#if (__has_cpp_attribute(unlikely) >= 201803L)
			#define LBAL_CPP2A_ATTRIBUTE_UNLIKELY __has_cpp_attribute(unlikely)
		#endif

		#if (__has_cpp_attribute(no_unique_address) >= 201803L)
			#define LBAL_CPP2A_ATTRIBUTE_NO_UNIQUE_ADDRESS __has_cpp_attribute(no_unique_address)
		#endif
	#endif	//	__has_cpp_attribute


	//	intrinsic functions
	#define LBAL_HINT_likely(LBAL_expr_)  __builtin_expect (LBAL_expr_, true)
	#define LBAL_HINT_unlikely(LBAL_expr_) __builtin_expect (LBAL_expr_, false)


	//	Symbol visibility macros
	#define LBAL_VIS_HIDDEN __attribute__ ((__visibility__("hidden")))

	#define LBAL_VIS_CLASS_EXPORT __attribute__ ((__visibility__("default")))
	#define LBAL_VIS_CLASS_IMPORT __attribute__ ((__visibility__("default")))

	#if __has_attribute (__type_visibility__)
		#define LBAL_VIS_ENUM __attribute__ ((__type_visibility__("default")))

		#define LBAL_VIS_CLASS_TEMPLATE __attribute__ ((__type_visibility__("default")))

		#define LBAL_VIS_EXTERN_CLASS_TEMPLATE_EXPORT __attribute__ ((__visibility__("default")))
		#define LBAL_VIS_EXTERN_CLASS_TEMPLATE_IMPORT __attribute__ ((__visibility__("default")))
	#else
		#define LBAL_VIS_ENUM

		#define LBAL_VIS_CLASS_TEMPLATE __attribute__ ((__visibility__("default")))

		#define LBAL_VIS_EXTERN_CLASS_TEMPLATE_EXPORT
		#define LBAL_VIS_EXTERN_CLASS_TEMPLATE_IMPORT
	#endif

	#define LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_EXPORT
	#define LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_IMPORT

	#define LBAL_VIS_MEMBER_CLASS_TEMPLATE __attribute__ ((__visibility__("hidden")))

	#define LBAL_VIS_MEMBER_FUNCTION_TEMPLATE inline __attribute__ ((__visibility__("hidden")))
		//	__SEEME__ The “inline” declaration is extraneous, but required due to
		//	 a currently unaddressed clang defect (cf., the elusive PR32114).

	#define LBAL_VIS_FUNC_EXPORT __attribute__ ((__visibility__("default")))
	#define LBAL_VIS_FUNC_IMPORT __attribute__ ((__visibility__("default")))

	//	__SEEME__ The first definition is a fallback if it turns out I’ve
	//	misunderstood the requirements on general inline functions.
//	#define LBAL_VIS_INLINE_FUNC LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC
	#define LBAL_VIS_INLINE_FUNC __attribute__ ((__visibility__("hidden")))

	//	__SEEME__ Using the internal_linkage attribute is equivalent to using the
	//	static keyword in C, and is semantically preferrable to inlining.
	//	However, what we -really- want is be able to strip this down to just
	//	LBAL_VIS_HIDDEN, but this requires linker support we don’t have, yet.
	//	See <http://lists.llvm.org/pipermail/cfe-dev/2018-July/058450.html> and
	//	<https://reviews.llvm.org/D49240?id=155185> for details.
	#if __has_attribute (internal_linkage)
		#define LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC __attribute__ ((__visibility__("hidden"), internal_linkage))
	#else
		#define LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC __attribute__ ((__visibility__("hidden"), __always_inline__))
	#endif

	#define LBAL_VIS_OVERLOADABLE_FUNC_EXPORT __attribute__ ((__visibility__("default")))
	#define LBAL_VIS_OVERLOADABLE_FUNC_IMPORT __attribute__ ((__visibility__("default")))

	#define LBAL_VIS_EXTERN_EXPORT
	#define LBAL_VIS_EXTERN_IMPORT

	#define LBAL_VIS_EXCEPTION_EXPORT __attribute__ ((__visibility__("default")))
	#define LBAL_VIS_EXCEPTION_IMPORT __attribute__ ((__visibility__("default")))

	#define LBAL_FUNC_CALL_C(LBAL_func_name_) LBAL_func_name_
	#define LBAL_FUNC_CALL_STD(LBAL_func_name_) LBAL_func_name_
	#define LBAL_FUNC_CALLBACK_C(LBAL_func_name_) (*LBAL_func_name_)
	#define LBAL_FUNC_CALLBACK_STD(LBAL_func_name_) (*LBAL_func_name_)


	//	Set up identifiers
	#define LBAL_NAME_COMPILER u8"clang version " __clang_version__
	#define LBAL_TARGET_COMPILER_CLANG 1

#elif defined (__GNUC__)
	//	generic gcc-based compiler
	//	Note that gcc guarantees that all system-specific predefined macros in
	//	the reserved namespace (i.e., __xxx__) will never resolve to 0 if they
	//	are actually defined.
	//	__SEEME__ This must appear after clang, as the llvm derivatives have a
	//	tendency to define gcc’s macros; Apple LLVM, in particular, likes to
	//	pretend to be a crufty, ancient version of gcc.
	#if (__GNUC__ < 7) || ((__GNUC__ == 7) && (__GNUC_MINOR__ < 3))
		#error "Settings are only known to be valid for gcc 7.3+."
			//	For reference, 6.3 supports all C++11 and C++14 features except
			//	garbage collection. gcc 7 is required for many C++17 language
			//	features; note, though, that it does not support
			//	std::filesystem or the Parallelism TS.
			//
			//	Any support we offer for gcc versions older than 7.3 is
			//	incidental and untested, though it could be made official with
			//	some validation.
	#endif

	#if __cplusplus < 201703L
		#error "std=c++17 or higher is required"
	#endif


	//	Identify processor.
	//	Note that AMD64 and x86_64 both trigger each other’s identifiers. We
	//	simply refer to all of them as LBAL_TARGET_CPU_X86_64.
	#if defined (__x86_64__) or defined (__amd64__)
		#define LBAL_TARGET_CPU_X86_64 1
		#define LBAL_TARGET_CPU_FAMILY_X86 1
	#elif defined (__i386__) //	 or defined (__i486__) or defined (__i586__) or defined (__i686__)
		#define LBAL_TARGET_CPU_X86 1
		#define LBAL_TARGET_CPU_FAMILY_X86 1
	#elif defined (__aarch64__)
		#define LBAL_TARGET_CPU_ARM_64 1
		#define LBAL_TARGET_CPU_FAMILY_ARM 1
	#elif defined (__arm__)
		#define LBAL_TARGET_CPU_ARM 1
		#define LBAL_TARGET_CPU_FAMILY_ARM 1
	#else
		#error "Processor unknown. Update lbalCompilerSetup.hpp."
	#endif

	#if __LITTLE_ENDIAN__
		#define LBAL_TARGET_RT_LITTLE_ENDIAN 1
	#elif __BIG_ENDIAN__
		#define LBAL_TARGET_RT_BIG_ENDIAN 1
	#endif

	#if __SIZEOF_DOUBLE__ > __SIZEOF_FLOAT__
		#define LBAL_TYPE_DOUBLE_GT_FLOAT 1
	#endif

	#if __SIZEOF_LONG_DOUBLE__ > __SIZEOF_DOUBLE__
		#define LBAL_TYPE_LONG_DOUBLE_GT_DOUBLE 1
	#endif


	//	Identify vector instruction sets, if any.
	#ifdef __SSE__
		#define LBAL_TARGET_VEC_SSE 1
	#endif

	#ifdef __SSE2__
		#define LBAL_TARGET_VEC_SSE2 1
	#endif

	#ifdef __SSE3__
		#define LBAL_TARGET_VEC_SSE3 1
	#endif

	#ifdef __SSE4_1__
		#define LBAL_TARGET_VEC_SSE41 1
	#endif

	#ifdef __SSE4_2__
		#define LBAL_TARGET_VEC_SSE42 1
	#endif

	#ifdef __AVX__
		#define LBAL_TARGET_VEC_AVX 1
	#endif

	#ifdef __AVX2__
		#define LBAL_TARGET_VEC_AVX2 1
	#endif


	//	Identify executable file fromat
	//	__SEEME__ Architecture is the same across Linux derivatives (ignoring old
	//	a.out), but binary compatibility is not guaranteed.
	#if defined (__ELF__)
		#define LBAL_TARGET_RT_ELF 1
	#elif defined (_WIN32)
		#define LBAL_TARGET_RT_COFF 1
	#elif defined (__MACH__)
		#define LBAL_TARGET_RT_MACHO 1
	#elif defined (__wasm__)
		#define LBAL_TARGET_RT_WASM 1
	#else
		#error "Unknown executable file format"
	#endif


	#if __SIZEOF_LONG_LONG__ == 8
		#define LBAL_TYPE_HAS_INT64 1
	#endif

	#if __SIZEOF_INT128__ == 16
		#define LBAL_TYPE_HAS_INT128 1
	#endif

	#define LBAL_TYPE_EXACT_WIDTH_INTEGERS 1

	#define LBAL_C99_PREPROCESSOR 1


	//	C++98 features

	//	It’s unclear whether we can count on `__cpp_exceptions` being unset if
	//	this is explicitly disabled, so we rely on the token that _is_
	//	guaranteed to have that behavior.
	//	__SEEME__ This will probably need to be conditionally handled in a
	//	later version of gcc if they deprecate `__EXCEPTIONS`.
	#if __EXCEPTIONS
		#if (__cpp_exceptions >= 199711L)
			#define LBAL_CPP98_EXCEPTIONS __cpp_exceptions
		#else
			#define LBAL_CPP98_EXCEPTIONS 199711L
		#endif
	#endif

	//	It’s unclear whether we can count on `__cpp_rtti` being unset if this
	//	is explicitly disabled, so we rely on the token that _is_ guaranteed to
	//	have that behavior.
	//	__SEEME__ This will probably need to be conditionally handled in a
	//	later version of gcc if they deprecate `__GXX_RTTI`.
	#if __GXX_RTTI
		#if (__cpp_rtti >= 199711L)
			#define LBAL_CPP98_RTTI __cpp_rtti
		#else
			#define LBAL_CPP98_RTTI 199711L
		#endif
	#endif


	//	C++11 features

	#if (__cpp_alias_templates >= 200704L)
		#define LBAL_CPP11_ALIAS_TEMPLATES __cpp_alias_templates
	#elif (__cplusplus >= 201103L)
		#define LBAL_CPP11_ALIAS_TEMPLATES 200704L
	#endif

	#if (__cpp_attributes >= 200809L)
		#define LBAL_CPP11_ATTRIBUTES __cpp_attributes
	#elif (__cplusplus >= 201103L)
		#define LBAL_CPP11_ATTRIBUTES 200809L
	#endif

	#if (__cpp_constexpr >= 200704L)
		#define LBAL_CPP11_CONSTEXPR __cpp_constexpr
	#elif (__cplusplus >= 201103L)
		#define LBAL_CPP11_CONSTEXPR 200704L
	#endif

	#if (__cpp_decltype >= 200707L)
		#define LBAL_CPP11_DECLTYPE __cpp_decltype
	#elif (__cplusplus >= 201103L)
		#define LBAL_CPP11_DECLTYPE 200707L
	#endif

	#if (__cpp_delegating_constructors >= 200604L)
		#define LBAL_CPP11_DELEGATING_CONSTRUCTORS __cpp_delegating_constructors
	#elif (__cplusplus >= 201103L)
		#define LBAL_CPP11_DELEGATING_CONSTRUCTORS 200604L
	#endif

	#if (__cpp_inheriting_constructors >= 200802L)
		#define LBAL_CPP11_INHERITING_CONSTRUCTORS __cpp_inheriting_constructors
	#elif (__cplusplus >= 201103L)
		#define LBAL_CPP11_INHERITING_CONSTRUCTORS 200802L
	#endif

	//	__SEEME__ There is no `__cplusplus` check since this can be
	//	conditionally disabled.
	#if (__cpp_threadsafe_static_init >= 200806L)
		#define LBAL_CPP11_THREADSAFE_STATIC_INIT __cpp_threadsafe_static_init
	#endif


	//	C++14 features

	#if (__cpp_aggregate_nsdmi >= 201304L)
		#define LBAL_CPP14_AGGREGATE_NSDMI __cpp_aggregate_nsdmi
	#elif (__cplusplus >= 201402L)
		#define LBAL_CPP14_AGGREGATE_NSDMI 201304L
	#endif

	#if (__cpp_binary_literals >= 201304L)
		#define LBAL_CPP14_BINARY_LITERALS __cpp_binary_literals
	#elif (__cplusplus >= 201402L)
		#define LBAL_CPP14_BINARY_LITERALS 201304L
	#endif

	#if (__cpp_constexpr >= 201304L)
		#define LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS __cpp_constexpr
	#elif (__cplusplus >= 201402L)
		#define LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS 201304L
	#endif

	#if (__cpp_decltype_auto >= 201304L)
		#define LBAL_CPP14_DECLTYPE_AUTO __cpp_decltype_auto
	#elif (__cplusplus >= 201402L)
		#define LBAL_CPP14_DECLTYPE_AUTO 201304L
	#endif

	#if (__cpp_generic_lambdas >= 201304L)
		#define LBAL_CPP14_GENERIC_LAMBDAS __cpp_generic_lambdas
	#elif (__cplusplus >= 201402L)
		#define LBAL_CPP14_GENERIC_LAMBDAS 201304L
	#endif

	#if (__cpp_init_captures >= 201304L)
		#define LBAL_CPP14_INIT_CAPTURES __cpp_init_captures
	#elif (__cplusplus >= 201402L)
		#define LBAL_CPP14_INIT_CAPTURES 201304L
	#endif

	//	__SEEME__ There is no `__cplusplus` check since this can be
	//	conditionally disabled.
	#if (__cpp_sized_deallocation >= 201304L)
		#define LBAL_CPP14_SIZED_DEALLOCATION __cpp_sized_deallocation
	#endif


	//	C++17 features
	//	__SEEME__ We rely on strict SD-6 macro availability testing for C++17
	//	features; macros should be defined for any gcc version which supports
	//	C++17 in any form.

	#if (__cpp_aggregate_bases >= 201603L)
		#define LBAL_CPP17_AGGREGATE_BASES __cpp_aggregate_bases
	#endif

	#if (__cpp_aligned_new >= 201606L)
		#define LBAL_CPP17_ALIGNED_NEW __cpp_aligned_new
	#endif

	#if (__cpp_capture_star_this >= [201603L)
		#define LBAL_CPP17_CAPTURE_STAR_THIS __cpp_capture_star_this
	#endif

	#if (__cpp_constexpr >= 201603L)
		#define LBAL_CPP17_CONSTEXPR_LAMBDA __cpp_constexpr
	#endif

	#if (__cpp_deduction_guides >= 201606L)
		#define LBAL_CPP17_DEDUCTION_GUIDES __cpp_deduction_guides
	#endif

	#if (__cpp_deduction_guides >= 201611L)
		#define LBAL_CPP17_DEDUCTION_GUIDES_NB __cpp_deduction_guides
	#endif

	#if (__cpp_deduction_guides >= 201703L)
		#define LBAL_CPP17_DEDUCTION_GUIDES_DR __cpp_deduction_guides
	#endif

	#if (__cpp_enumerator_attributes >= 201411L)
		#define LBAL_CPP17_ENUMERATOR_ATTRIBUTES __cpp_enumerator_attributes
	#endif

	#if (__cpp_fold_expressions >= 201411L)
		#define LBAL_CPP17_FOLD_EXPRESSIONS __cpp_fold_expressions
	#endif

	#if (__cpp_fold_expressions >= 201603L)
		#define LBAL_CPP17_FOLD_EXPRESSIONS_REVISED __cpp_fold_expressions
	#endif

	#if (__cpp_guaranteed_copy_elision >= 201606L)
		#define LBAL_CPP17_GUARANTEED_COPY_ELISION __cpp_guaranteed_copy_elision
	#endif

	#if (__cpp_hex_float >= 201603L)
		#define LBAL_CPP17_HEX_FLOAT __cpp_hex_float
	#endif

	#if (__cpp_if_constexpr >= 201606L)
		#define LBAL_CPP17_IF_CONSTEXPR __cpp_if_constexpr
	#endif

	#if (__cpp_inheriting_constructors >= 201511L)
		#define LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED __cpp_inheriting_constructors
	#endif

	#if (__cpp_template_template_args >= 201611L)
		#define LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS __cpp_template_template_args
	#endif


	//	C++2a features
	//	__SEEME__ These tests assume a minimum of gcc 7.3

	#define LBAL_CPP2A_INTEGRATING_OUR_FEATURE_TEST_MACROS 1L

	//	__SEEME__ None of these have SD-6 macros, so we rely on a compiler
	//	version check and a language test.
	#if (__GNUC__ >= 8) && (__cplusplus > 201703L)
		#define LBAL_CPP2A_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS 1L
		#define LBAL_CPP2A_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS 1L
		#define LBAL_CPP2A_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS 1L
		#define LBAL_CPP2A_DESIGNATED_INITIALIZERS 1L
		#define LBAL_CPP2A_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION	1L
		#define LBAL_CPP2A_TEMPLATE_PARAMETER_LIST_FOR_GENERIC_LAMBDAS 1L

		//	__FIXME__ gcc hasn’t yet shipped a fully functioning version of
		//	this feature. In particular, the latest one from gcc 8 fails when
		//	it encounters `#__VA_OPT__`. We treat this as unavailable, but it’s
		//	actually a good candidate for a new “partial implementation” value,
		//	or a special token (`LBAL_OOPS_xxx`?).
//		#define LBAL_CPP2A_VA_OPT 1L
	#endif

	#if (__GNUC__ >= 9) && (__cplusplus > 201703L)
		#define LBAL_CPP2A_CONSTEXPR_VIRTUAL_FUNCTION 1L
		#define LBAL_CPP2A_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS	1L
		#define LBAL_CPP2A_INIT_STATEMENTS_FOR_RANGE_BASED_FOR 1L
		#define LBAL_CPP2A_PACK_EXPANSION_IN_LAMBDA_INIT_CAPTURE 1L
		#define LBAL_CPP2A_TYPENAME_OPTIONAL 1L
	#endif

	#if (__cpp_aggregate_paren_init >= 201902L)
		#define LBAL_CPP2A_AGGREGATE_PAREN_INIT __cpp_aggregate_paren_init
	#endif

	#if (__cpp_char8_t >= 201811L)
		#define LBAL_CPP2A_CHAR8_T __cpp_char8_t
	#endif

	#if (__cpp_concepts >= 201806L)
		#define LBAL_CPP2A_CONCEPTS __cpp_concepts
	#endif

	#if (__cpp_conditional_explicit >= 201806L)
		#define LBAL_CPP2A_CONDITIONAL_EXPLICIT __cpp_conditional_explicit
	#endif

	#if (__cpp_constexpr >= 201907L)
		#define LBAL_CPP2A_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION __cpp_constexpr
	#endif

	#if (__cpp_constexpr_dynamic_alloc >= 201907L)
		#define LBAL_CPP2A_CONSTEXPR_DYNAMIC_ALLOC __cpp_constexpr_dynamic_alloc
	#endif

	#if (__cpp_constinit >= 201907L)
		#define LBAL_CPP2A_CONSTINIT __cpp_constinit
	#endif

	#if (__cpp_coroutines >= 201902L)
		#define LBAL_CPP2A_COROUTINES __cpp_coroutines
	#endif

	#if (__cpp_deduction_guides >= 201907L)
		#define LBAL_CPP2A_DEDUCTION_GUIDES_FOR_AGGREGATES __cpp_deduction_guides
	#endif

	#if (__cpp_impl_destroying_delete >= 201806L)
		#define LBAL_CPP2A_DESTROYING_DELETE __cpp_impl_destroying_delete
	#endif

	#if (__cpp_nontype_template_parameter_class >= 201806L)
		#define LBAL_CPP2A_NONTYPE_TEMPLATE_PARAMETER_CLASS __cpp_nontype_template_parameter_class
	#endif

	#if (__cpp_impl_three_way_comparison >= 201711L)
		#define LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR __cpp_impl_three_way_comparison
	#endif

	#if (__cpp_impl_three_way_comparison > = 201907L)
		#define LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR_TUNEUP __cpp_impl_three_way_comparison
	#endif

	#ifdef __has_cpp_attribute
		#if (__has_cpp_attribute(likely) >= 201803L)
			#define LBAL_CPP2A_ATTRIBUTE_LIKELY __has_cpp_attribute(likely)
		#endif

		#if (__has_cpp_attribute(unlikely) >= 201803L)
			#define LBAL_CPP2A_ATTRIBUTE_UNLIKELY __has_cpp_attribute(unlikely)
		#endif

		#if (__has_cpp_attribute(no_unique_address) >= 201803L)
			#define LBAL_CPP2A_ATTRIBUTE_NO_UNIQUE_ADDRESS __has_cpp_attribute(no_unique_address)
		#endif
	#endif	//	__has_cpp_attribute


	//	intrinsic functions
	#define LBAL_HINT_likely(LBAL_expr_) __builtin_expect (LBAL_expr_, true)
	#define LBAL_HINT_unlikely(LBAL_expr_) __builtin_expect (LBAL_expr_, false)


	//	Symbol visibility macros
	#define LBAL_VIS_HIDDEN __attribute__ ((__visibility__("hidden")))

	#define LBAL_VIS_CLASS_EXPORT __attribute__ ((__visibility__("default")))
	#define LBAL_VIS_CLASS_IMPORT __attribute__ ((__visibility__("default")))

	#if __has_attribute (__type_visibility__)
		#define LBAL_VIS_ENUM __attribute__ ((__type_visibility__("default")))

		#define LBAL_VIS_CLASS_TEMPLATE __attribute__ ((__type_visibility__("default")))

		#define LBAL_VIS_EXTERN_CLASS_TEMPLATE_EXPORT __attribute__ ((__visibility__("default")))
		#define LBAL_VIS_EXTERN_CLASS_TEMPLATE_IMPORT __attribute__ ((__visibility__("default")))
	#else
		#define LBAL_VIS_ENUM

		#define LBAL_VIS_CLASS_TEMPLATE __attribute__ ((__visibility__("default")))

		#define LBAL_VIS_EXTERN_CLASS_TEMPLATE_EXPORT
		#define LBAL_VIS_EXTERN_CLASS_TEMPLATE_IMPORT
	#endif

	#define LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_EXPORT
	#define LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_IMPORT

	#define LBAL_VIS_MEMBER_CLASS_TEMPLATE __attribute__ ((__visibility__("hidden")))

	#define LBAL_VIS_MEMBER_FUNCTION_TEMPLATE __attribute__ ((__visibility__("hidden")))
		//	__FIXME__ There is a clang defect which requires an extraneous “inline”
		//	declaration to be prepended here; it’s currently unknown if gcc is
		//	impacted by the same defect.

	#define LBAL_VIS_FUNC_EXPORT __attribute__ ((__visibility__("default")))
	#define LBAL_VIS_FUNC_IMPORT __attribute__ ((__visibility__("default")))

	//	__SEEME__ The first definition is a fallback if it turns out I’ve
	//	misunderstood the requirements on general inline functions.
//	#define LBAL_VIS_INLINE_FUNC LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC
	#define LBAL_VIS_INLINE_FUNC __attribute__ ((__visibility__("hidden")))

	//	__SEEME__ Using the internal_linkage attribute is equivalent to using the
	//	static keyword in C, and is semantically preferrable to inlining.
	//	However, what we -really- want is be able to strip this down to just
	//	LBAL_VIS_HIDDEN, but this requires linker support we don’t have, yet.
	//	See <http://lists.llvm.org/pipermail/cfe-dev/2018-July/058450.html> and
	//	<https://reviews.llvm.org/D49240?id=155185> for details.
	#if __has_attribute (internal_linkage)
		#define LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC __attribute__ ((__visibility__("hidden"), internal_linkage))
	#else
		#define LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC __attribute__ ((__visibility__("hidden"), __always_inline__))
	#endif

	#define LBAL_VIS_OVERLOADABLE_FUNC_EXPORT __attribute__ ((__visibility__("default")))
	#define LBAL_VIS_OVERLOADABLE_FUNC_IMPORT __attribute__ ((__visibility__("default")))

	#define LBAL_VIS_EXTERN_EXPORT
	#define LBAL_VIS_EXTERN_IMPORT

	#define LBAL_VIS_EXCEPTION_EXPORT __attribute__ ((__visibility__("default")))
	#define LBAL_VIS_EXCEPTION_IMPORT __attribute__ ((__visibility__("default")))

	#define LBAL_FUNC_CALL_C(LBAL_func_name_) LBAL_func_name_
	#define LBAL_FUNC_CALL_STD(LBAL_func_name_) LBAL_func_name_
	#define LBAL_FUNC_CALLBACK_C(LBAL_func_name_) (*LBAL_func_name_)
	#define LBAL_FUNC_CALLBACK_STD(LBAL_func_name_) (*LBAL_func_name_)


	//	Set up identifiers
	#define LBAL_NAME_COMPILER u8"gcc version " __VERSION__
	#define LBAL_TARGET_COMPILER_GCC 1

#elif defined (_MSC_VER) && defined (_WIN32)
	//	Visual C++ targeting Windows; _WIN32 is also defined for 64-bit
	//	__SEEME__ This must always appear last, as other compilers have a tendency
	//	to emulate MSVC by defining its macros.

	//	__FIXME__ This is unnecessarily conservative. In practice, things are
	//	unlikely to get squiffy until we go back before MSVS 2015 Update 3
	//	(`_MSC_FULL_VER` at least `190024210`).
	#if (_MSC_VER < 1914)
		#error "Settings are only known to be valid for MSVS 2017 15.7+."
	#endif

	//	__SEEME__ MSVS stopped setting __cplusplus in the expected manner, but
	//	replaced the utility of it with a proprietary macro, `_MSVC_LANG`. We
	//	use it as an analog. Note that `_MSVC_LANG` is not available prior to
	//	MSVS 2015 Update 3.
	#if _MSVC_LANG < 201703L
		#error "std=c++17 or higher is required"
	#endif


	//	Identify processor.
	//	Note that AMD64 and x86_64 have the same identifier.
	#if defined (_M_IX86)
		#define LBAL_TARGET_CPU_X86 1
		#define LBAL_TARGET_CPU_FAMILY_X86 1
		#define LBAL_TARGET_RT_LITTLE_ENDIAN 1
	#elif defined (_M_X64)
		#define LBAL_TARGET_CPU_X86_64 1
		#define LBAL_TARGET_CPU_FAMILY_X86 1
		#define LBAL_TARGET_RT_LITTLE_ENDIAN 1
	#elif defined (_M_IA64)
		#define LBAL_TARGET_CPU_IA64 1
		#define LBAL_TARGET_CPU_FAMILY_X86 1
		#define LBAL_TARGET_RT_LITTLE_ENDIAN 1
	#else
		#error "Processor unknown. Update lbalCompilerSetup.hpp."
	#endif


	//	Identify vector instruction sets, if any.
	#ifdef _M_IX86_FP
		#if (_M_IX86_FP == 1)
			//	32-bit processor
			#define LBAL_TARGET_VEC_SSE 1
		#elif (_M_IX86_FP == 2)
			//	32-bit processor
			#define LBAL_TARGET_VEC_SSE 1
			#define LBAL_TARGET_VEC_SSE2 1
		#else
			#pragma message ("Unknown value given by _M_IX86_FP: " #_M_IX86_FP)
		#endif
	#else
		#if (defined(_M_AMD64) || defined(_M_X64))
			//	64-bit processor
			#define LBAL_TARGET_VEC_SSE 1
			#define LBAL_TARGET_VEC_SSE2 1

			//	__SEEME__ There are no independent tests for these in MSVC, and
			//	it’s unclear if support for these particular instruction sets
			//	is implied for 64-bit architectures, as is the case for SSE1
			//	and SSE2; we make an assumption, as these should be available
			//	in any post-2011 Intel-class CPU.
			#define LBAL_TARGET_VEC_SSE3 1
			#define LBAL_TARGET_VEC_SSE41 1
			#define LBAL_TARGET_VEC_SSE42 1
		#else
			#error "Unsupported processor. Update lbalCompilerSetup.hpp."
		#endif

		#ifdef __AVX__
			#define LBAL_TARGET_VEC_AVX 1
		#endif

		#ifdef __AVX2__
			#define LBAL_TARGET_VEC_AVX2 1
		#endif

		//	__SEEME__ There appear to be no intrinsics for detecting AVX-512
		//	support in MSVC, yet, though support may be undocumented or
		//	under-reported. It’s currently moot, though, as we don’t support
		//	this instruction set family at this time.
	#endif


	//	__SEEME__ These are unverified for Win32
	#define LBAL_TYPE_DOUBLE_GT_FLOAT 1
	#define LBAL_TYPE_LONG_DOUBLE_GT_DOUBLE 1


	//	We ignore the possibility of other OS’s
	#define LBAL_TARGET_RT_COFF 1


	#define LBAL_TYPE_HAS_INT64 1
		//	__SEEME__ We assume the availability of 64-bit ints under supported
		//	versions of MSVC, and also assume the unavaibility of intrinsic
		//	128-bit ints.

	#define LBAL_TYPE_EXACT_WIDTH_INTEGERS 1

	#define LBAL_TYPE_WCHAR_T_IS_16_BITS 1


	//	Continuing the Windows tradition of security through annoyance...
	//	Of course, it gets better: in order for this to work, it actually
	//	has to be defined before any includes, even the ones that should
	//	pose no problem. In practice, this definition is probably not coming
	//	early enough, so there will still need to be another one, perhaps in a
	//	project-level property sheet. Consider this “documentation”.
	#define _CRT_SECURE_NO_WARNINGS 1

	//	Standardize on a gcc-ism.
	//	__SEEME__ This violates the rule about defining preprocessor macros
	//	with double-underscores (among other things). The usage should be
	//	safe.
	#ifndef __PRETTY_FUNCTION__
		#define __PRETTY_FUNCTION__ __FUNCSIG__
	#endif


	//	__SEEME__ Re: SD-6 macros: full support started getting rolled out as
	//	of MSVC 2019 16.0, but testing with that series didn’t start until
	//	16.3. As a result, it’s unclear exactly when the various macros started
	//	going live. For that reason, prior to 16.3, we rely on version checks,
	//	but after that, we use the SD-6 macros first. It’s possible some
	//	supported features will fallthrough the cracks with some versions, but
	//	it’s unlikely; all the same, this will be updated as new information
	//	becomes available.

	//	C++98 features
	//	These can be conditionally disabled.

	//	We can’t rely on `__cpp_exceptions` being set properly in older MSVCs,
	//	so we also test for a proprietary token, as well.
	//	__SEEME__ _CPPUNWIND is not an exact analog, but seems to serve.
	#if __cpp_exceptions || _CPPUNWIND
		#if __cpp_exceptions
			#define LBAL_CPP98_EXCEPTIONS __cpp_exceptions
		#else
			#define LBAL_CPP98_EXCEPTIONS 199711L
		#endif
	#endif

	//	We can’t rely on `__cpp_rtti` being set properly in older MSVCs, so we
	//	also test for a proprietary token, as well.
	#if __cpp_rtti || _CPPRTTI
		#if __cpp_rtti
			#define LBAL_CPP98_RTTI __cpp_rtti
		#else
			#define LBAL_CPP98_RTTI 199711L
		#endif
	#endif


	//	C++11 features

	//	__SEEME__ The `_MSVC_LANG` checks here are theoretical. `_MSVC_LANG`
	//	has never had a value lower than `201402L`, equivalent to C++14. We
	//	don’t bother getting too precise here, though, since we don‘t
	//	officially support a C++ Standard older than C++17.

	#if (__cpp_alias_templates >= 200704L)
		#define LBAL_CPP11_ALIAS_TEMPLATES __cpp_alias_templates
	#elif (_MSVC_LANG >= 201103L) && (_MSC_VER >= 1800)
		#define LBAL_CPP11_ALIAS_TEMPLATES 200704L
	#endif

	#if (__cpp_attributes >= 200809L)
		#define LBAL_CPP11_ATTRIBUTES __cpp_attributes
	#elif (_MSVC_LANG >= 201103L) && (_MSC_VER >= 1900)
		#define LBAL_CPP11_ATTRIBUTES 200809L
	#endif

	//	__SEEME__ Available in `_MSC_VER``1900` for partial, unsure of full
	#if (__cpp_constexpr >= 200704L)
		#define LBAL_CPP11_CONSTEXPR __cpp_constexpr
	#elif (_MSVC_LANG >= 201103L) && (_MSC_VER >= 1900)
		#define LBAL_CPP11_CONSTEXPR 200704L
	#endif

	#if (__cpp_decltype >= 200707L)
		#define LBAL_CPP11_DECLTYPE __cpp_decltype
	#elif (_MSVC_LANG >= 201103L)
		#define LBAL_CPP11_DECLTYPE 200707L
	#endif

	#if (__cpp_delegating_constructors >= 200604L)
		#define LBAL_CPP11_DELEGATING_CONSTRUCTORS __cpp_delegating_constructors
	#elif (_MSVC_LANG >= 201103L)
		#define LBAL_CPP11_DELEGATING_CONSTRUCTORS 200604L
	#endif

	#if (__cpp_inheriting_constructors >= 200802L)
		#define LBAL_CPP11_INHERITING_CONSTRUCTORS __cpp_inheriting_constructors
	#elif (_MSVC_LANG >= 201103L)
		#define LBAL_CPP11_INHERITING_CONSTRUCTORS 200802L
	#endif

	//	Available in `_MSC_VER`: `1900`
	//	This can be conditionally disabled.
	//	__SEEME__ In the absence of `__cpp_threadsafe_static_init` - i.e., in
	//	MSVS 2017 or earlier - there isn’t a way to determine whether this has
	//	been disabled, which can be done with `/Zc:threadSafeInit-`. We’ll just
	//	assume it _has_ been disabled, which is not ideal, but unavoidable
	//	without incorporating a test app into the build process.
	#if (__cpp_threadsafe_static_init >= 200806L)
		#define LBAL_CPP11_THREADSAFE_STATIC_INIT __cpp_threadsafe_static_init
	#endif


	//	C++14 features
	//	__SEEME__ The `_MSVC_LANG` checks here are gratuitous. `_MSVC_LANG`
	//	has never had a value lower than `201402L`, equivalent to C++14. We
	//	don’t bother getting too precise here, though, since we don‘t
	//	officially support a C++ Standard older than C++17.

	#if (__cpp_aggregate_nsdmi >= 201304L)
		#define LBAL_CPP14_AGGREGATE_NSDMI __cpp_aggregate_nsdmi
	#elif (_MSVC_LANG >= 201402L) && (_MSC_VER >= 1900)
		#define LBAL_CPP14_AGGREGATE_NSDMI 201304L
	#endif

	#if (__cpp_binary_literals >= 201304L)
		#define LBAL_CPP14_BINARY_LITERALS __cpp_binary_literals
	#elif (_MSVC_LANG >= 201402L) && (_MSC_VER >= 1900)
		#define LBAL_CPP14_BINARY_LITERALS 201304L
	#endif

	#if (__cpp_constexpr >= 201304L)
		#define LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS __cpp_constexpr
	#elif (_MSVC_LANG >= 201402L) && (_MSC_VER >= 1910)
		#define LBAL_CPP14_CONSTEXPR_RELAXED_CONSTRAINTS 201304L
	#endif

	#if (__cpp_decltype_auto >= 201304L)
		#define LBAL_CPP14_DECLTYPE_AUTO __cpp_decltype_auto
	#elif (_MSVC_LANG >= 201402L) && (_MSC_VER >= 1900)
		#define LBAL_CPP14_DECLTYPE_AUTO 201304L
	#endif

	#if (__cpp_generic_lambdas >= 201304L)
		#define LBAL_CPP14_GENERIC_LAMBDAS __cpp_generic_lambdas
	#elif (_MSVC_LANG >= 201402L) && (_MSC_VER >= 1900)
		#define LBAL_CPP14_GENERIC_LAMBDAS 201304L
	#endif

	#if (__cpp_init_captures >= 201304L)
		#define LBAL_CPP14_INIT_CAPTURES __cpp_init_captures
	#elif (_MSVC_LANG >= 201402L) && (_MSC_VER >= 1900)
		#define LBAL_CPP14_INIT_CAPTURES 201304L
	#endif

	//	This can be conditionally disabled.
	//	__SEEME__ In the absence of `__cpp_sized_deallocation` - i.e., in
	//	MSVS 2017 or earlier - there isn’t a way to determine whether this has
	//	been disabled, which can be done with `/Zc:sizedDealloc-`. We’ll just
	//	assume it _has_ been disabled, which is not ideal, but unavoidable
	//	without incorporating a test app into the build process.
	#if (__cpp_sized_deallocation >= 201304L)
		#define LBAL_CPP14_SIZED_DEALLOCATION __cpp_sized_deallocation
	#endif


	//	C++17 features

	#if (__cpp_aggregate_bases >= 201603L)
		#define LBAL_CPP17_AGGREGATE_BASES __cpp_aggregate_bases
	#elif (_MSVC_LANG >= 201703L) &&  (_MSC_VER >= 1914)
		#define LBAL_CPP17_AGGREGATE_BASES 201603L
	#endif

	#if (__cpp_aligned_new >= 201606L)
		#define LBAL_CPP17_ALIGNED_NEW __cpp_aligned_new
	#elif (_MSVC_LANG >= 201703L) && (_MSC_VER >= 1912)
		#define LBAL_CPP17_ALIGNED_NEW 201606L
	#endif

	#if (__cpp_capture_star_this >= 201603)
		#define LBAL_CPP17_CAPTURE_STAR_THIS __cpp_capture_star_this
	#elif (_MSVC_LANG >= 201703L) && (_MSC_VER >= 1911)
		#define LBAL_CPP17_CAPTURE_STAR_THIS 201603
	#endif

	#if (__cpp_constexpr >= 201603L)
		#define LBAL_CPP17_CONSTEXPR_LAMBDA __cpp_constexpr
	#elif (_MSVC_LANG >= 201703L) && (_MSC_VER >= 1911)
		#define LBAL_CPP17_CONSTEXPR_LAMBDA 201603L
	#endif

	#if (__cpp_deduction_guides >= 201606L)
		#define LBAL_CPP17_DEDUCTION_GUIDES __cpp_deduction_guides
	#elif (_MSVC_LANG >= 201703L) && (_MSC_VER >= 1914)
		#define LBAL_CPP17_DEDUCTION_GUIDES 201606L
	#endif

	#if (__cpp_deduction_guides >= 201611L)
		#define LBAL_CPP17_DEDUCTION_GUIDES_NB __cpp_deduction_guides
	#elif (_MSVC_LANG >= 201703L) && (_MSC_VER >= 1914)
		#define LBAL_CPP17_DEDUCTION_GUIDES_NB 201611L
	#endif

	#if (__cpp_deduction_guides >= 201703L)
		#define LBAL_CPP17_DEDUCTION_GUIDES_DR __cpp_deduction_guides
	#elif (_MSVC_LANG >= 201703L) && (_MSC_VER >= 1914)
		#define LBAL_CPP17_DEDUCTION_GUIDES_DR 201703L
	#endif

	#if (__cpp_enumerator_attributes >= 201411L)
		#define LBAL_CPP17_ENUMERATOR_ATTRIBUTES __cpp_enumerator_attributes
	#elif (_MSVC_LANG >= 201703L) && (_MSC_VER >= 1900)
		#define LBAL_CPP17_ENUMERATOR_ATTRIBUTES 201411L
	#endif

	#if (__cpp_fold_expressions >= 201411L)
		#define LBAL_CPP17_FOLD_EXPRESSIONS __cpp_fold_expressions
	#elif (_MSVC_LANG >= 201703L) && (_MSC_VER >= 1912)
		#define LBAL_CPP17_FOLD_EXPRESSIONS 201411L
	#endif

	#if (__cpp_fold_expressions >= 201603L)
		#define LBAL_CPP17_FOLD_EXPRESSIONS_REVISED __cpp_fold_expressions
	#elif (_MSVC_LANG >= 201703L) && (_MSC_VER >= 1912)
		#define LBAL_CPP17_FOLD_EXPRESSIONS_REVISED 201603L
	#endif

	#if (__cpp_guaranteed_copy_elision >= 201606L)
		#define LBAL_CPP17_GUARANTEED_COPY_ELISION __cpp_guaranteed_copy_elision
	#elif (_MSVC_LANG >= 201703L) && (_MSC_VER >= 1913)
		#define LBAL_CPP17_GUARANTEED_COPY_ELISION 201606L
	#endif

	#if (__cpp_hex_float >= 201603L)
		#define LBAL_CPP17_HEX_FLOAT __cpp_hex_float
	#elif (_MSVC_LANG >= 201703L) && (_MSC_VER >= 1911)
		#define LBAL_CPP17_HEX_FLOAT 201603L
	#endif

	#if (__cpp_if_constexpr >= 201606L)
		#define LBAL_CPP17_IF_CONSTEXPR __cpp_if_constexpr
	#elif (_MSVC_LANG >= 201703L) && (_MSC_VER >= 1911)
		#define LBAL_CPP17_IF_CONSTEXPR 201606L
	#endif

	#if (__cpp_inheriting_constructors >= 201511L)
		#define LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED __cpp_inheriting_constructors
	#elif (_MSVC_LANG >= 201703L) && (_MSC_VER >= 1914)
		#define LBAL_CPP17_INHERITING_CONSTRUCTORS_REVISED 201511L
	#endif

	//	__SEEME__ This is implemented, but it’s unclear if/when the DR that
	//	affected the proposal was addressed.
	#if (__cpp_template_template_args >= 201611L)
		#define LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS __cpp_template_template_args
	#elif (_MSVC_LANG >= 201703L) && (_MSC_VER >= 1912)
		#define LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS 201611L
	#endif


	//	C++2a features

	//	__SEEME__ None of these have SD-6 macros, so we rely on a compiler
	//	version check and a language test.
	#if (_MSC_VER >= 1900) && (_MSVC_LANG > 201703L)
		#define LBAL_CPP2A_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS 1L
	#endif

	#if (_MSC_VER >= 1914) && (_MSVC_LANG > 201703L)
		#define LBAL_CPP2A_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION 1L
	#endif

	#if (_MSC_VER >= 1920) && (_MSVC_LANG > 201703L)
		#define LBAL_CPP2A_INTEGRATING_OUR_FEATURE_TEST_MACROS 1L
	#endif

	#if (_MSC_VER >= 1921) && (_MSVC_LANG > 201703L)
		#define LBAL_CPP2A_DESIGNATED_INITIALIZERS 1L
	#endif

	#if (_MSC_VER >= 1922) && (_MSVC_LANG > 201703L)
		#define LBAL_CPP2A_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS 1L
		#define LBAL_CPP2A_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS 1L
		#define LBAL_CPP2A_PACK_EXPANSION_IN_LAMBDA_INIT_CAPTURE 1L
		#define LBAL_CPP2A_TEMPLATE_PARAMETER_LIST_FOR_GENERIC_LAMBDAS 1L
	#endif

	#if (__cpp_aggregate_paren_init >= 201902L)
		#define LBAL_CPP2A_AGGREGATE_PAREN_INIT __cpp_aggregate_paren_init
	#endif

	#if (__cpp_char8_t >= 201811L)
		#define LBAL_CPP2A_CHAR8_T __cpp_char8_t
	#endif

	#if (__cpp_concepts >= 201806L)
		#define LBAL_CPP2A_CONCEPTS __cpp_concepts
	#endif

	#if (__cpp_conditional_explicit >= 201806L)
		#define LBAL_CPP2A_CONDITIONAL_EXPLICIT __cpp_conditional_explicit
	#endif

	#if (__cpp_constexpr >= 201907L)
		#define LBAL_CPP2A_CONSTEXPR_TRIVIAL_DEFAULT_INITIALIZATION __cpp_constexpr
	#endif

	#if (__cpp_constexpr_dynamic_alloc >= 201907L)
		#define LBAL_CPP2A_CONSTEXPR_DYNAMIC_ALLOC __cpp_constexpr_dynamic_alloc
	#endif

	#if (__cpp_constinit >= 201907L)
		#define LBAL_CPP2A_CONSTINIT __cpp_constinit
	#endif

	#if (__cpp_coroutines >= 201902L)
		#define LBAL_CPP2A_COROUTINES __cpp_coroutines
	#endif

	#if (__cpp_deduction_guides >= 201907L)
		#define LBAL_CPP2A_DEDUCTION_GUIDES_FOR_AGGREGATES __cpp_deduction_guides
	#endif

	#if (__cpp_impl_destroying_delete >= 201806L)
		#define LBAL_CPP2A_DESTROYING_DELETE __cpp_impl_destroying_delete
	#endif

	#if (__cpp_nontype_template_parameter_class >= 201806L)
		#define LBAL_CPP2A_NONTYPE_TEMPLATE_PARAMETER_CLASS __cpp_nontype_template_parameter_class
	#endif

	#if (__cpp_impl_three_way_comparison >= 201711L)
		#define LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR __cpp_impl_three_way_comparison
	#endif

	#if (__cpp_impl_three_way_comparison > = 201907L)
		#define LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR_TUNEUP __cpp_impl_three_way_comparison
	#endif

	#ifdef __has_cpp_attribute
		#if (__has_cpp_attribute(likely) >= 201803L)
			#define LBAL_CPP2A_ATTRIBUTE_LIKELY __has_cpp_attribute(likely)
		#endif

		#if (__has_cpp_attribute(unlikely) >= 201803L)
			#define LBAL_CPP2A_ATTRIBUTE_UNLIKELY __has_cpp_attribute(unlikely)
		#endif

		#if (__has_cpp_attribute(no_unique_address) >= 201803L)
			#define LBAL_CPP2A_ATTRIBUTE_NO_UNIQUE_ADDRESS __has_cpp_attribute(no_unique_address)
		#endif
	#endif	//	__has_cpp_attribute

	//	C99 features

	//	__SEEME__ The key missing component for C99 compliance was correct
	//	variadic macro handling. This is in place as of MSVS 2019 16.0, and
	//	may have been available sooner with the use of the `/permissive-`
	//	switch. Note that as of at least MSVS 2019 16.3, the preprocessor
	//	is actually almost completely compliant with the C11 standard.
	//	__SEEME__ It’s unclear if there is a method for controlling
	//	preprocessor compliance.
	#if (_MSC_VER >= 1920)
		#define LBAL_C99_PREPROCESSOR 1
	#endif


	//	Symbol visibility macros
	#define LBAL_VIS_HIDDEN

	#define LBAL_VIS_ENUM

	#define LBAL_VIS_CLASS_TEMPLATE

	#define LBAL_VIS_CLASS_EXPORT __declspec(dllexport)
	#define LBAL_VIS_CLASS_IMPORT __declspec(dllimport)

	#define LBAL_VIS_EXTERN_CLASS_TEMPLATE_EXPORT
	#define LBAL_VIS_EXTERN_CLASS_TEMPLATE_IMPORT __declspec(dllimport)

	#define LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_EXPORT __declspec(dllexport)
	#define LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_IMPORT

	#define LBAL_VIS_MEMBER_CLASS_TEMPLATE

	#define LBAL_VIS_MEMBER_FUNCTION_TEMPLATE

	#define LBAL_VIS_FUNC_EXPORT __declspec(dllexport)
	#define LBAL_VIS_FUNC_IMPORT __declspec(dllimport)

	//	__SEEME__ These appear to be required by DLLs, as they like to save
	//	fallback versions of inline functions as object code in case the
	//	header version is unavailable for some reason; if not for this
	//	requirement, these would just be LBAL_VIS_HIDDEN.
	#define LBAL_VIS_INLINE_FUNC __forceinline
	#define LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC __forceinline

	#define LBAL_VIS_OVERLOADABLE_FUNC_EXPORT __declspec(dllexport)
	#define LBAL_VIS_OVERLOADABLE_FUNC_IMPORT

	#define LBAL_VIS_EXTERN_EXPORT __declspec(dllexport)
	#define LBAL_VIS_EXTERN_IMPORT __declspec(dllimport)

	#define LBAL_VIS_EXCEPTION_EXPORT __declspec(dllexport)
	#define LBAL_VIS_EXCEPTION_IMPORT __declspec(dllimport)


	//	Class decorators
	#define LBAL_CLASS_FORCE_EBCO __declspec(empty_bases)


	//	Function calling conventions
	#define LBAL_FUNC_CALL_C(LBAL_func_name_) __cdecl LBAL_func_name_
	#define LBAL_FUNC_CALL_STD(LBAL_func_name_) __stdcall LBAL_func_name_
	#define LBAL_FUNC_CALLBACK_C(LBAL_func_name_) (__cdecl *LBAL_func_name_)
	#define LBAL_FUNC_CALLBACK_STD(LBAL_func_name_) (__stdcall *LBAL_func_name_)


	//	Set up identifiers
	#define LBAL_NAME_COMPILER u8"MSVC version " LBAL_Stringify_ (_MSC_VER)
	#define LBAL_TARGET_COMPILER_MSVC 1

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
