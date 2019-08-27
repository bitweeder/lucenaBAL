/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“FeatureSetup.hpp”
	Copyright © 2018-2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	lbalFeatureSetup.hpp is a metaheader which includes various detail headers
	to handle feature detection and macro configuration for the compiler, the
	Standard Library implementation, and platform details that impact the build
	environment. Users should include <lucenaBAL/lucenaBAL.hpp>, which includes
	this, in favor of attempting to cherry-pick headers.

	The goal of this header is to safeguard a functionality baseline for the
	build environment in terms of compiler and Standard Library features. We
	currently require C++17 compiler support - or at least close emulation
	thereof. Note that the detail headers may evolve in compatibility-breaking
	ways in the future as we track compliance with newer language features,
	but such changes should be documented and restricted to point releases.

	Note that we set all preprocessor conditionals unless we explicitly state
	otherwise in the conditional description; those whose requirements are not
	met get set to 0. By default, we set conditionals that are met to 1, but
	they could conceivably be set to any non-0 number, and tests need to
	reflect that.

	Generally, we don’t bother testing for things that are guaranteed by our
	minimum-supported compilers. For example, all supported compilers have C99-
	style ints, so we don’t test for the presence of support. This may change
	in the future if a compiler we’d like to support violates this standard.

	As a general rule, if a feature is available and stable, it is assumed to
	be used. This is not boost, and we do not seek to incent or support
	thousands of micro-variants on the Standard. The sole objective of this
	library is to facilitate interoperability between otherwise-conforming
	modern compilers and their libraries.


	LBAL_NAME
	These macros resolve to human-readable strings that identify the specified
	entities. If the entity has a version value associated with it, such as a
	compiler does, the string -may- include that version, but it is not
	required to do so. It is important to understand that since these values
	are generated in a header at compile time, and so they will change; if it
	is desired to cache the value, e.g., to report the compiler a library was
	built with in an executable that links to it, it will be necessary to cache
	it yourself, e.g., by storing the character array in a string with external
	storage in a source file in the library and providing an accessor to it.

	Note that it is not safe to use these for comparisons, either directly or
	in parsed form, as their format is not guaranteed; they are intended
	strictly for reporting.

		LBAL_NAME_TARGET_CPU
			At a minimum, this will identify the CPU family that the code was
			compiled for, but it may contain a much more detailed descriptor.

		LBAL_NAME_TARGET_OS
			This may identify the minimum supported version of the target OS,
			as well as the OS itself, but is not required to do so.

		LBAL_NAME_COMPILER
			This identifies the compiler used to build the code.

		LBAL_NAME_STANDARD_LIBRARY
			This identifies the implementation of the C++ Standard Library used
			to build the code.


	LBAL_TARGET_COMPILER
	Report 1 or 0 depending on which mutually exclusive macro matches the
	compiler used to build the code. This takes the place of direct querying,
	as some compilers are in the habit of self-identifying as something else.
	These are not generally useful, as there’s typically another, better
	mechanism for solving whatever this is meant to solve, but they’re here for
	when nothing else will do. Note that if you also need version information,
	you’ll have to resort to drect querying, though it may still sensible to
	filter first on these for the aforementioned reason.

	SEEME These are blunt instruments. In particular, there‘s no
	differentiation between frontened (e.g., c1xx or clang) and backend
	(e.g., c2 or llvm). In practice, this mattered more when c2/clang was a
	thing, but is moot now. We’ll consider revisiting if the extra granularity
	turns out to be useful

		LBAL_TARGET_COMPILER_CLANG
		LBAL_TARGET_COMPILER_GCC
		LBAL_TARGET_COMPILER_MSVC


	LBAL_TARGET_STANDARD_LIBRARY
	Report 1 or 0 depending on which mutually exclusive macro matches the C++
	Standard Library used to build the code. This takes the place of direct
	querying, as this may not even be an option in some cases. These are not
	generally useful, as there’s typically another, better mechanism for
	solving whatever this is meant to solve, but they’re here for when nothing
	else will do. Note that if you also need version information, you’ll have
	to resort to drect querying.

		LBAL_TARGET_STANDARD_LIBRARY_LIBCPP
		LBAL_TARGET_STANDARD_LIBRARY_MSVC
		LBAL_TARGET_STANDARD_LIBRARY_STDLIBCPP

	LBAL_TARGET_CPU
	These conditionals specify which microprocessor instruction set is being
	generated.	At most one of these is 1, the rest are 0.

	SEEME There used to be more of these, but they’ve been largely mooted.
	Candidates for additions include console-specific processors/families, and
	explicit differentiation for AMD processors/families.

		LBAL_TARGET_CPU_X86							generic 32-bit x86
		LBAL_TARGET_CPU_X86_64						generic 64-bit x86
		LBAL_TARGET_CPU_IA64							generic 64-bit Itanium
		LBAL_TARGET_CPU_ARM							generic 32-bit ARM
		LBAL_TARGET_CPU_ARM_64						generic 64-bit ARM

		LBAL_TARGET_CPU_ARM_FAMILY
		LBAL_TARGET_CPU_X86_FAMILY


	LBAL_TARGET_VEC
	These conditionals specify which vector instruction set is being generated,
	if any. Multiple conditionals may be true, but some are mutually exclusive.

		LBAL_TARGET_VEC_SSE
		LBAL_TARGET_VEC_SSE2
		LBAL_TARGET_VEC_SSE3
		LBAL_TARGET_VEC_SSE41
		LBAL_TARGET_VEC_SSE42
		LBAL_TARGET_VEC_AVX
		LBAL_TARGET_VEC_AVX2

	Note that there is no corresponding test for AVX-512, as it’s not a
	monolithic instruction set, and we don’t have the operational experience
	needed to evaluate a meaningful breakdown beyond just mirroring any
	predfined macros the compiler may happen to have.

		//	LBAL_TARGET_VEC_AVX512

	SEEME We don’t currently independently check for SSE-Math and similar
	instruction splits; this may be a defect.
	SEEME There used to be more of these, but they’ve been largely mooted.
	Candidates for additions include console-specific vector instruction sets,
	and explicit differentiation for AMD instruction sets.


	LBAL_TARGET_OS
	These conditionals specify in which Operating System the generated code
	will run. At most one of the these is 1, the rest are 0 (except for
	LBAL_TARGET_OS_IOS, which is set whenever LBAL_TARGET_OS_IOS_SIM is set, but
	can also be set alone).

	SEEME Candidates for additions include console-specific operating systems,
	Android, tvOS, and watchOS. BSD could conceivably have its own flag, but we
	currently roll it in under LBAL_TARGET_OS_X11.

	SEEME These focus primarily on UI characteristics, as opposed to system
	internals, which is why we have LBAL_TARGET_OS_X11 and not
	LBAL_TARGET_OS_POSIX. A case could be made that we realistically need to
	track both, but in practice - during the implementation of Lucena PAL - no
	practical need was found. It’s possible that once additional platform
	support is added to that library, we’ll find we need to revisit this design
	decision.

		LBAL_TARGET_OS_X11
		LBAL_TARGET_OS_MACOS
		LBAL_TARGET_OS_WIN
		LBAL_TARGET_OS_IOS
		LBAL_TARGET_OS_IOS_SIM


	LBAL_TARGET_RT
	These conditionals specify the runtime environment which the generated code
	is being compled for. This is needed when the OS and/or CPU supports more
	than one runtime (e.g. macOS on PPC supports CFM and Mach-O). Note that
	values are descriptive; if the condition is met, the value will be 1,
	otherwise 0.

		LBAL_TARGET_RT_LITTLE_ENDIAN
		LBAL_TARGET_RT_BIG_ENDIAN
			We don’t call out processors that can do either; all the processors
			we support operate in one mode or the other for the duration of
			execution, which is all we care about. Note that this is only used
			to determine the “native” format.

		LBAL_TARGET_RT_32_BIT
		LBAL_TARGET_RT_64_BIT
			This identifies whether the binary is being generated for 32-bit
			or 64-bit execution.

		LBAL_TARGET_RT_COFF
		LBAL_TARGET_RT_ELF
		LBAL_TARGET_RT_MACHO
		LBAL_TARGET_RT_WASM
			These identify the executable format. They are somewhat arbitrary,
			but we’ve only bothered to define them for cases we’ve encountered
			in practice. Additional operations experience (and supported
			platforms) will probably lead to some additions.


	LBAL_TARGET_API
	These conditionals are used to differentiate between sets of core System
	API’s on the same processor under the same OS. Unlike LBAL_TARGET_OS and
	LBAL_TARGET_CPU, these conditionals are not mutally exclusive. This header
	will attempt to auto-configure all LBAL_TARGET_API values, but will often
	need a LBAL_TARGET_API value predefined, e.g., in a .prop or .xcconfig file,
	in order to disambiguate.  Note that values are descriptive; if the
	condition is met, the value will be 1, otherwise 0.

	SEEME This is not intended to be an exhaustive list of APIs. Originally,
	it was useful for differentiating between possible supported and available
	Apple APIs (e.g., QuickDraw, Carbon, Cocoa, and whatever other flavor of
	the week floats in), but it’s academic on platforms that don’t deprecate
	their APIs with abandon. Further operational experience might find us
	wanting to differentiate between other available OS-level APIs.

		LBAL_TARGET_API_COCOA
		LBAL_TARGET_API_COCOA_TOUCH

		LBAL_TARGET_API_WIN32
		LBAL_TARGET_API_WIN64

		LBAL_TARGET_API_POSIX
		LBAL_TARGET_API_X11


	LBAL_PRAGMA
	These conditionals specify whether the compiler supports particular
	#pragma’s. Arguably, these are gratuitous since compilers should ignore
	unrecongnized #pragmas, but besides preventing noisy warnings, these could
	be useful to indicate, for example, the NON-availability of some requisite
	feature, such as tight struct packing.

	SEEME Previously, this section contained #pragmas related to alignment
	within structs. They’ve been mooted thanks to standardized ways of handling
	this and widespread support. This section is being kept in as a placeholder
	should we add more #pragma detection in the future.


	LBAL_TYPE
	These identify characteristics of certain POD types for a given compiler;
	preprocessor definitions are used since sizeof can’t be used by the
	preprocessor (reliably). These can be defined since we have special
	knowledge of the compile/build flags that wouldn’t necessarily be
	available to conforming portable code.

		LBAL_TYPE_HAS_INT64
			native 64-bit ints - including usigned ints - as int64_t and
			uint64_t (and possibly also long long and unsigned long long,
			depending)

		LBAL_TYPE_HAS_INT128
			native 128-bit ints - including usigned ints - as __int128_t and
			__uint128_t

		LBAL_TYPE_EXACT_WIDTH_INTEGERS
			availability of C99 exact width int types

		LBAL_TYPE_DOUBLE_GT_FLOAT
			double is distinct from float

		LBAL_TYPE_LONG_DOUBLE_GT_DOUBLE
			long double is distinct from double

		LBAL_TYPE_WCHAR_T_IS_16_BITS
			if this is 0, wchar_t is assumed to be a 32-bit integer type


	LBAL_FEATURE
	Some compilers and platforms do things in a peculiar way that we may need
	to work around or otherwise deal with. Those features are noted here.

		LBAL_FEATURE_UTF16_FILE_SYSTEM
			It is assumed that the file system uses UTF-8 unless this
			feature conditional is set. Really only necessary for Windows.

			FIXME We can probably retire this after updating the code to
			always use the relevant std::filesystem path types instead of
			doing our own conversions.

		LBAL_FEATURE_CONSTEXPR_INTRINSICS
			Indicate whether the current compilers intrinsics are constant
			expressions in the C++ sense. In the absence of a means to identify
			whether a given function is constexpr at compile-time, we rely on
			tools like this to aid us in determining, expression-by-expression,
			whether a given function is -probably- able to be declared
			constexpr.

			SEEME This is probably insufficiently granular, but it’s academic
			for now: none of the supportedcompilers advertise constexpr
			intrinsics, and to the extent that they have any, it’s pure
			happenstance and dangerous to rely on.


	LBAL_CPPxx
	LBAL_Cxx
	Language feature availability flags to indicate whether a given C++ feature
	is supported by the current compiler. Each one is set to a non-zero value
	if available and 0 otherwise; every macro is always set to some value after
	this header has been preprocessed.

	Note that these flags are neither exhaustive nor bounded:

		* Features that are available in all supported compilers do not have
		flags. Currently, features that could conceivably be manually disabled
		in a given compiler (e.g., exception handling) are not tracked, though
		they could be, if necessary.

		* Features that have become universally supported since the inception
		of their feature flag will eventually have their flag removed. This
		library is not intended to be backwards-compatible for all time, only
		to smooth out cross-platform interoperability between current compiler
		versions. This is unlikely to change, but sane user policies regarding
		freezes for libraries and supported compilers for project milestones -
		or even lifetimes - should mitigate this.

		* Features we (the developers) have not had cause to use or care about
		are often not represented right away. Eventually, all language features
		accepted into the Standard are likely to appear here, assuming
		universal support doesn’t come so quickly that a feature flag becomes
		mooted, as per the above criteria.

		* Features from proposals to the Standard may have flags here; in some
		cases, this may occur for proposed features that have not been accepted
		into the standard, even as part of a Technical Specification. This
		typically happens with de facto standards (e.g., variants on symbol
		visibility handling) when it relates to language features. This sort of
		thing is much more common for proposed library features (e.g., <span>
		support was made available long before it was formally voted in).

	Note that the macro names mimic those of the equivalent SD-6 macros, where
	available; similarly, the macro values will either be:

		- 0, to indicate no availability, or
		- the SD-6 value equivalent to the available feature support, or
		- 1, if there is no equivalent SD-6 macro

	SEEME Note that this leaves an ambiguous case where a feature may have been
	updated, e.g., as a result of a Defect Report, but a new SD-6 value has not
	been assigned; this can be further complicated if the DR resolution is not
	finalized, meaning that the available feature is in an intermediate state.
	Currently, we have no policy for dealing with this situation, as it has not
	arisen yet in practice. Most likely it would be addressed by assigning an
	arbitrary value (e.g., “last known good value +1”). This comes with its own
	problems, namely that there is no formal policy regarding bumping SD-6
	macro values vs. creating new macros, for example in the case where
	backwards compatibility is affected by a breaking change, which would
	complicate a simple greater-than test against a macro value.

	APIME Previous iterations of this header also attempted to determine
	whether various C99 and C11 features were available. This turned out to be
	impractical and a bit pointless. As a result, such features are only
	tracked - if they are tracked at all - in the context of their
	applicability to a given C++ Standard, e.g., support for the C99
	preprocessor as required by C++11.

	C++98
	These are here only because compilers can be made to disable specific
	features for various reasons and we want to have a universal way of
	determining whether that’s happened.

		LBAL_CPP98_EXCEPTIONS
			There -was- an SD-6 macro for this, but it’s been removed for
			standardization. Set to 1 if exceptions are enabled, 0 otherwise.

		LBAL_CPP98_RTTI
			There -was- an SD-6 macro for this, but it’s been removed for
			standardization. Set to 1 if RTTI is enabled, 0 otherwise.

	C++11
	Note that all supported compilers support all required features of C++11.

		LBAL_CPP11_MINIMAL_GARBAGE_COLLECTION
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2670.htm>
			There is currently no SD-6 macro for this.

		LBAL_CPP11_THREADSAFE_STATIC_INIT
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2660.htm>
		__cpp_threadsafe_static_init
			Some compilers can disable this feature if asked; will be set to 0
			if that has happened.

	C++14
	All supported compilers support all features of C++14, but some of them may
	require that certain features be explicitly enabled.

		LBAL_CPP14_SIZED_DEALLOCATION
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3778.html>
		__cpp_sized_deallocation
			Some compilers disable this by default since it’s an ABI-breaking
			change; clang, in particular, does this.

	C++17
	All supported compilers support all features of C++17, but some of them may
	require that certain features be explicitly enabled.

		LBAL_CPP17_TEMPLATE_TEMPLATE_ARGS
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0522r0.html>
		__cpp_template_template_args
			The proposal this is from is intended to resolve a Defect Report,
			but unfortunately introduces a defect of its own. Some compilers
			are disabling this until a revised patch is in.

	C++2a
	These are often difficult or impossible to emulate correctly, so the norm
	is to not bother. However, when it -has- been done, we note it, as well as
	how to make use of the emulated feature.

	SEEME Somewhat awkwardly, a lot of proposed new language and library
	features and fixes don’t include SD-6 macros (yet?); this makes identifying
	availability more challenging than it needs to be. Note that a proposal to
	standardize SD-6 macros was accepted for C++2a, but the current SD-6 itself
	is pretty out-of-date, and it’s unclear whether there will be a fix-up
	prior to FDIS. As a result, most of these are either placeholders awaiting
	testing or depend on compiler version-differentiated activation.

		LBAL_CPP2A_ALLOW_LAMBDA_CAPTURE_EQUALS_THIS
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0409r2.html>
			There is currently no SD-6 macro for this.

		LBAL_CPP2A_ATTRIBUTE_NO_UNIQUE_ADDRESS
		<http://open-std.org/JTC1/SC22/WG21/docs/papers/2018/p0840r2.html>
		__has_cpp_attribute(no_unique_address)

		LBAL_CPP2A_ATTRIBUTE_LIKELY
		LBAL_CPP2A_ATTRIBUTE_UNLIKELY
		LBAL_CPP2A_ATTRIBUTES_LIKELY_AND_UNLIKELY
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0479r5.html>
		__has_cpp_attribute(likely)
		__has_cpp_attribute(unlikely)
			We track the availability of each attribute separately, as well as
			provide an aggregate to test for compliance. The aggregate’s value
			will be 0 if either attribute is unavailable, or 1 otherwise.

		LBAL_CPP2A_CLASS_TYPES_AS_NON_TYPE_TEMPLATE_PARAMETERS
		<http://open-std.org/JTC1/SC22/WG21/docs/papers/2018/p0732r2.pdf>
		__cpp_nontype_template_parameter_class

		LBAL_CPP2A_CONCEPTS
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0734r0.pdf>
		__cpp_concepts

		LBAL_CPP2A_CONDITIONAL_EXPLICIT
		<http://open-std.org/JTC1/SC22/WG21/docs/papers/2018/p0892r2.html>
		__cpp_conditional_explicit

		LBAL_CPP2A_CONST_REF_QUALIFIED_POINTERS_TO_MEMBERS
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0704r1.html>
			There is currently no SD-6 macro for this.

		LBAL_CPP2A_CONSTEXPR_VIRTUAL_FUNCTION
		<http://open-std.org/JTC1/SC22/WG21/docs/papers/2018/p1064r0.html>
			There is currently no SD-6 macro for this.

		LBAL_CPP2A_COROUTINES
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0912r1.html>
		__cpp_coroutines
			Note that this is just language support for the <coroutine> header.

		LBAL_CPP2A_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDAS
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0624r2.pdf>
			There is currently no SD-6 macro for this.

		LBAL_CPP2A_DEFAULT_MEMBER_INITIALIZERS_FOR_BIT_FIELDS
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0683r1.html>
			There is currently no SD-6 macro for this.

		LBAL_CPP2A_DESIGNATED_INITIALIZERS
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0329r4.pdf>
			There is currently no SD-6 macro for this.

		LBAL_CPP2A_DESTROYING_DELETE
		<http://open-std.org/JTC1/SC22/WG21/docs/papers/2018/p0722r3.html>
		__cpp_impl_destroying_delete

		LBAL_CPP2A_INIT_STATEMENTS_FOR_RANGE_BASED_FOR
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0614r1.html>
			There is currently no SD-6 macro for this.

		LBAL_CPP2A_INITIALIZER_LIST_CONSTRUCTORS_IN_CLASS_TEMPLATE_ARGUMENT_DEDUCTION
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0702r1.html>
			There is currently no SD-6 macro for this.

		LBAL_CPP2A_INTEGRATING_OUR_FEATURE_TEST_MACROS
		<http://open-std.org/JTC1/SC22/WG21/docs/papers/2018/p0941r2.html>
			There is currently no SD-6 macro for this (ironically). It appears
			this is only here to get Microsoft to support SD-6, as the other
			major compilers de facto meet the requirement.

		LBAL_CPP2A_PACK_EXPANSION_IN_LAMBDA_INIT_CAPTURE
		<http://open-std.org/JTC1/SC22/WG21/docs/papers/2018/p0780r2.html>
			There is currently no SD-6 macro for this.

		LBAL_CPP2A_THREE_WAY_COMPARISON_OPERATOR
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0515r0.pdf>
		__cpp_impl_three_way_comparison

		LBAL_CPP2A_TEMPLATE_PARAMETER_LIST_FOR_GENERIC_LAMBDAS
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0428r2.pdf>
			There is currently no SD-6 macro for this.

		LBAL_CPP2A_TYPENAME_OPTIONAL
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0634r2.html>
			There is currently no SD-6 macro for this.

		LBAL_CPP2A_VA_OPT
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0306r4.html>
			There is currently no SD-6 macro for this.

	On Hold
	These are features that got yoinked for various reasons and are currently
	back in the oven, but expected to pop in C++23.
		LBAL_CPP2A_ATTRIBUTE_ASSERT
		LBAL_CPP2A_ATTRIBUTE_ENSURES
		LBAL_CPP2A_ATTRIBUTE_EXPECTS
		LBAL_CPP2A_CONTRACTS
		__has_cpp_attribute(assert)
		__has_cpp_attribute(ensures)
		__has_cpp_attribute(expects)
		<http://open-std.org/JTC1/SC22/WG21/docs/papers/2018/p0542r5.html>
			This is actually a bundle of attributes using a new syntax; the
			syntax has no SD-6 macro, so we rely on the presence of the
			attributes to determine support. We track the availability of each
			attribute separately, as well as provide an aggregate to test for
			compliance. The aggregate’s value will be 0 if any attribute is
			unavailable, or 1 otherwise.

	Technical Specifications and Proposals
	Most of these will eventually migrate to one of the above sections, at
	which time the associated macro will be renamed (and possibly aliased).

	LBAL_C99
	Feature availability macros to indicate whether a given C99 feature is
	supported by the current compiler. Each one is set to 1 if available and 0
	otherwise.

		LBAL_C99_PREPROCESSOR
		SEEME Only MSVS is known to have problems with this, and it appears
		progress is finally being made to fully address it, at which point this
		flag will be retired. Note that if support requires having a particular
		compiler switch set to get compatibility, setting the switch will
		likely be mandated.

	LBAL_LIBCPPxx_xxx
	LBAL_LIBCPPxx_xxx_EXP
	These relate to library features. They’re mostly set in lbalVersion.hpp, but
	they’re documented here since they may be overridden depending on the build
	environment. Note that features that are unambiguously available (e.g.,
	almost the entirety of the C++11 STL) don’t have macros. Generally, a
	Library feature detection macro is only set to 0 here if we know that a
	feature is broken or unavailable, and that it would otherwise be falsely
	recognized as available. A macro is only set to a non-zero value if we
	know that a feature -should- be available, but normal feature detection
	would fail to assign the correct SD-6 macro value; note that in this case,
	the macro may be reset to 0 later if header detection fails. See the notes
	above for LBAL_CPPxx as well as in lbalVersion.hpp for additional
	information.

	Note that some of these -also- require language support, or have some other
	dependencies. We try to note such cases when the dependencies exist outside
	of the current Standard baseline, e.g., a C++2a library feature that
	depends on C++2a language support, when the baseline is C++17.

	There is some ambiguity in whether we track the experimental version of a
	feature. Generally, we don’t bother if:

		- no major compiler ever shipped an experimental version
		- the experimental version is/was completely broken
		- we’re transitioning to a new baseline and looking to eliminate cruft

	SEEME Note that regardless of how these macros are set, a feature may be
	available, anyway, if there is a reference implementation for it; see the
	lbalConfig.hpp header for details of how this works, and see the relevant
	Wrapper header, if there is one.

	C++17
		LBAL_LIBCPP17_ANY
		__cpp_lib_any
			Only needed because of older Apple platforms.  Note that we neither
			track nor use experimental versions of this.

		LBAL_LIBCPP17_ELEMENTARY_STRING_CONVERSIONS
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0067r5.html>
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0682r1.html>
		__cpp_lib_to_chars
			No wrapper is provided, though a <charconv> wrapper would be a
			reasonable thing to add. Note that this got weird since the
			functions got moved to their own header and their signatures were
			altered, post-Standardization, all as part of a Defect Report
			resolution.

		LBAL_LIBCPP17_EXECUTION
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0024r2.html>
		__cpp_lib_execution
			No wrapper is provided; the functionality would be good to have,
			but challenging to implement effectively. Note that by itself, this
			macro does not measure compliance with the referenced Working Group
			paper; use LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS. Note
			that we neither track nor use experimental versions of this.

		LBAL_LIBCPP17_FILESYSTEM
		LBAL_LIBCPP17_FILESYSTEM_EXP
		__cpp_lib_filesystem
		__cpp_lib_experimental_filesystem
			Only missing on Apple platforms. Unfortunately, we fall back to
			boost for a reference implementation, and the boost version differs
			substantially from the Standard. Also, note that the experimental
			version differs in many ways from the final version, but it’s all
			that is offered until gcc 8 and clang 7.

		LBAL_LIBCPP17_HARDWARE_INTERFERENCE_SIZE
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0154r1.html>
		__cpp_lib_thread_hardware_interference_size
			This is set in this header; no wrapper is provided, though the
			functionality would be a reasonable thing to add. Note that we
			neither track nor use experimental versions of this.

		LBAL_LIBCPP17_LAUNDER
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0137r1.html>
		__cpp_lib_launder
			AKA, “Replacement of class objects containing reference members.”
			No wrapper is provided, though the functionality would be a
			reasonable thing to add. Note that we neither track nor use
			experimental versions of this.

		LBAL_LIBCPP17_OPTIONAL
		__cpp_lib_optional
			Only needed because of older Apple platforms.  Note that we neither
			track nor use experimental versions of this.

		LBAL_LIBCPP17_PARALLEL_ALGORITHM
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0024r2.html>
		__cpp_lib_parallel_algorithm
			This is set in this header. No wrapper is provided; the
			functionality would be good to have, but challenging and messy to
			implement effectively. Note that by itself, this macro does not
			measure compliance with the Working Group paper; for that, use
			LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS. Note that we
			neither track nor use experimental versions of this.

		LBAL_LIBCPP17_SPLICING_MAPS_AND_SETS
		<http://wg21.link/p0083r3>
		__cpp_lib_node_extract
			This is set in this header; no wrapper is provided, as we’re
			just testing for the presense of member functions in pre-existing
			standard headers. Note that we neither track nor use experimental
			versions of this.

		LBAL_LIBCPP17_STANDARDIZATION_OF_PARALLELISM_TS
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0024r2.html>
			Note that this macro tracks compliance with the Standard as it
			relates to implementing the referenced Working Group paper; there
			is no correspoding SD-6 macro, or rather, there are -two- relevant
			macros which each track the different features required for
			compliance. We actually track both of those, as well as this,
			separately. As such, this macro is an aggregate: if both
			LBAL_LIBCPP17_EXECUTION and LBAL_LIBCPP17_PARALLEL_ALGORITHM indicate
			compliance, this gets set to 1; otherwise, it’s set to 0. Note that
			we neither track nor use experimental versions of this, partly
			because the Draft versions tracked a different set of features, in
			different places, which were refactored/replaced.

		LBAL_LIBCPP17_VARIANT
		__cpp_lib_variant
			Only needed because of older Apple platforms. Note that we neither
			track nor use experimental versions of this.

	C++2a
	These are all taken from features that have been incorporated into the
	draft Standard currently called C++2a and likely to become C++20.

		LBAL_LIBCPP2A_BIT_CAST
		<http://open-std.org/JTC1/SC22/WG21/docs/papers/2018/p0476r2.html>
		__cpp_lib_bit_cast
			A reference implementation is available, and is mostly compatible
			(lack of constepxr memcpy or equivalent makes full compliance
			challenging).

		LBAL_LIBCPP2A_CALENDAR_AND_TIMEZONE
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0355r7.html>
			This is set in this header; no wrapper is provided, though the
			functionality would be nice to add if we didn’t have to write the
			reference implementation ourselves.

		LBAL_LIBCPP2A_CONCEPT_LIBRARY
		LBAL_LIBCPP2A_CONCEPT_LIBRARY_EXP
		<http://open-std.org/JTC1/SC22/WG21/docs/papers/2018/p0898r3.pdf>
		__cpp_lib_concepts
		__cpp_lib_experimental_concepts
			No wrapper is provided, though the functionality would be a
			reasonable thing to add.

		LBAL_LIBCPP2A_CONSTEXPR_FOR_ALGORITHM_AND_UTILITY
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0202r3.html>
			This is set in this header; no wrapper is provided, as we would
			have to reimplement both headers and work around the potential
			lack of cstring-equivalent compiler intrinsics.

		LBAL_LIBCPP2A_COROUTINES
		LBAL_LIBCPP2A_COROUTINES_EXP
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/n4736.pdf>
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/n4760.pdf>
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0912r2.html>
		__cpp_coroutines (SEEME proxy)
			This does not currently have its own SD-6 macro. No wrapper is
			provided. Note that <coroutine> requires language support.
			SEEME Confusingly, n4736 was voted into the Standard, but n4760 is
			the fixed version of it.

		LBAL_LIBCPP2A_DESTROYING_DELETE
		<http://open-std.org/JTC1/SC22/WG21/docs/papers/2018/p0722r3.html>
		__cpp_lib_destroying_delete

		LBAL_LIBCPP2A_EXTENDING_MAKE_SHARED_TO_SUPPORT_ARRAYS
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0674r1.html>
			This is set in this header; no wrapper is provided, though the
			functionality would be a reasonable thing to add.

		LBAL_LIBCPP2A_FLOATING_POINT_ATOMIC
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0020r6.html>
			This is set in this header; no wrapper is provided, though the
			functionality would be a reasonable thing to add.

		LBAL_LIBCPP2A_LIST_REMOVE_RETURN_TYPE
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0646r1.pdf>
		__cpp_lib_list_remove_return_type
		__cpp_lib_experimental_list_remove_return_type
			No wrapper is provided, as we would have to fully reimplement
			<list> and <forward_list> just to tweak a few member functions.

		LBAL_LIBCPP2A_MORE_CONSTEXPR_FOR_COMPLEX
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0415r1.html>
		__cpp_lib_constexpr_complex
		__cpp_lib_experimental_constexpr_complex
			No wrapper is provided, as we would have to reimplement <complex>.

		LBAL_LIBCPP2A_SPAN
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0122r7.pdf>
			There is no SD-6 macro, yet. A reference implementation is
			provided and accessible through lbalSpanWrapper.hpp.

		LBAL_LIBCPP2A_STD_ATOMIC_REF
		<http://open-std.org/JTC1/SC22/WG21/docs/papers/2018/p0019r8.html>
		__cpp_lib_atomic_ref
			No wrapper is provided, as a correct reference implementation will
			require significant expertise in the problem domain.

		LBAL_LIBCPP2A_STD_ENDIAN
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0463r1.html>
			This is set in this header; no wrapper is provided, though the
			functionality would be a reasonable thing to add; however a general
			implementation may be impossible without compiler/language support
			(because middle-endian, amirite?).

		LBAL_LIBCPP2A_STD_REMOVE_CVREF
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0550r2.pdf>
			This is set in this header; a reference implementation is provided
			and accessible through lbalTypeTraitsWrapper.hpp.

		LBAL_LIBCPP2A_STRING_PREFIX_AND_SUFFIX_CHECKING
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0457r2.html>
			This is set in this header. No wrapper is provided, as we would
			have to reimplement two headers; these should have been free
			functions anyway, rationale in the proposal notwithstanding.

		LBAL_LIBCPP2A_SYNCHRONIZED_BUFFERED_OSTREAM
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0053r7.pdf>
		__cpp_lib_syncstream
			No wrapper is provided.

		LBAL_LIBCPP2A_THREE_WAY_COMPARISON_OPERATOR_SUPPORT_COMPARE
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0515r3.pdf>
		__cpp_lib_three_way_comparison
			This is set in this header; no wrapper will be provided, as
			<compare> is interdependent with the operator <=> language feature.

		LBAL_LIBCPP2A_TYPE_IDENTITY
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0887r1.pdf>
			This is set in this header; no wrapper is provided, though an
			implementation would be trivial (cf., std::remove_cvref).

		LBAL_LIBCPP2A_UTILITY_TO_CONVERT_A_POINTER_TO_A_RAW_POINTER
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0653r2.html>
			This is set in this header; no wrapper is provided, though the
			functionality would be a reasonable thing to add.

		LBAL_LIBCPP2A_VERSION
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0754r2.pdf>
			This is effectively provided by lbalVersion.hpp, which works in
			conjunction with this header to identify all of the available
			Standard Library functionality. Note that unlike <version>, the
			wrapper actually tracks “correct” implementations only (so, for
			example, Xcode’s false positives for <any> and friends won’t be
			reported as support for the library feature); this behavior will be
			carried forward, and so, unlike other wrappers, it is recommended
			to -always- include lbalVersion.hpp, even when including <version>
			directly, and rely on the LBAL_LIBCPP_xxx macros where they are
			available. See lbalVersion.hpp for details.

	C++ Technical Specifications
	These are all taken from Technical Specifications that have not (yet?) been
	Standardized. Generally, they are either very far along and likely to clear
	the bar, or very useful and simple enough to implement trivially.
	Generally, these will eventually be aliased (and then moved) into
	LBAL_LIBCPP2A_xxx, LBAL_LIBCPP20_xxx, LBAL_LIBCPP23_xxx, and the like.

	SEEME The TSs can be highly mutable, and support should be considered very
	experimental. No effort at all will be expended to maintain backwards-
	compatibility with a TS once a feature has been voted in.

		LBAL_LIBCPPTS_NETWORKING
		LBAL_LIBCPPTS_NETWORKING_EXP
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/n4734.pdf>
		__cpp_lib_net
		__cpp_lib_experimental_net
			Unfortunately, we use boost for a reference implementation, so
			compatibility with the Standard is not guaranteed. Note that the
			wrapper for this feature is lbalNetworkingWrapper.hpp.

		LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE
		LBAL_LIBCPPTS_NETWORKING_EXTENSIBLE_EXP
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/n4734.pdf>
		__cpp_lib_net_extensible
		__cpp_lib_experimental_net_extensible
			Unfortunately, we use boost for a reference implementation, so
			compatibility with the Standard is not guaranteed. Note that the
			wrapper for this feature is lbalNetworkingWrapper.hpp.

		LBAL_LIBCPPTS_OBSERVER_PTR
		LBAL_LIBCPPTS_OBSERVER_PTR_EXP
		<http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2014/n4282.pdf>
		<http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/n4758.html>
		__cpp_lib_observer_ptr
		__cpp_lib_experimental_observer_ptr
			A reference implementation is available.


	LBAL_VIS_xxx
	These describe different levels of symbol visibility as it pertains to the
	ABI, allowing explicit control over what gets exported - and subsequently
	imported - by the linker. This task is somewhat complicated by different
	approaches on each platform towards what constitutes the contents of a
	library, e.g., whether inline functions are header-only constructs or
	whether they contribute object code to the library itself. We’ve noted
	usage issues to be aware of, as well as some relevant historical oddities.
	Note that some of these macros should be used conditionally; they should
	not be used to decorate symbols directly, but should instead be used to
	define decorators specific to a given project. Such decorators’ values
	should be dependent upon whether the project is being built or used; when
	building, set the decorator to the _EXPORT version of a given macro, but
	when using the build product, set it to the _IMPORT version. Macros that do
	not have multiple versions are not context-dependent and can be used
	directly - or used to define a library-specific macro unconditionally.

	If there are multiple declarations of a given symbol, all declarations
	should have the same decorators; in particular, do not leave some
	declarations undecorated. Failing to adhere to this policy will give
	warnings and possibly unpredictable behavior with some compilers.

	Establishing visibility rules for templates is fraught; read all the notes
	carefully before attempting to decorate templates of any kind, including
	classes containing member templates.

	Usage example:

		#if MY_LIB_CONFIG_buiding
			#define MY_LIB_VIS_CLASS						LBAL_VIS_CLASS_EXPORT
			#define MY_LIB_VIS_EXTERN_CLASS_TEMPLATE		LBAL_VIS_EXTERN_CLASS_TEMPLATE_EXPORT
			#define MY_LIB_VIS_CLASS_TEMPLATE_INSTANTIATION	LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_EXPORT
			#define MY_LIB_VIS_FUNC							LBAL_VIS_FUNC_EXPORT
			#define MY_LIB_VIS_OVERLOADABLE_FUNC			LBAL_VIS_OVERLOADABLE_FUNC_EXPORT
			#define MY_LIB_VIS_EXCEPTION					LBAL_VIS_EXCEPTION_EXPORT
			#define MY_LIB_VIS_EXTERN						LBAL_VIS_EXTERN_EXPORT
		#else	//	We’re just consuming the API, not building the binary
			#define MY_LIB_VIS_CLASS						LBAL_VIS_CLASS_IMPORT
			#define MY_LIB_VIS_EXTERN_CLASS_TEMPLATE		LBAL_VIS_EXTERN_CLASS_TEMPLATE_IMPORT
			#define MY_LIB_VIS_CLASS_TEMPLATE_INSTANTIATION	LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_IMPORT
			#define MY_LIB_VIS_FUNC							LBAL_VIS_FUNC_IMPORT
			#define MY_LIB_VIS_OVERLOADABLE_FUNC			LBAL_VIS_OVERLOADABLE_FUNC_IMPORT
			#define MY_LIB_VIS_EXCEPTION					LBAL_VIS_EXCEPTION_IMPORT
			#define MY_LIB_VIS_EXTERN						LBAL_VIS_EXTERN_IMPORT
		#endif	//	MY_LIB_CONFIG_buiding

	In this example, MY_LIB_CONFIG_buiding is only defined when building the
	binary, and left undefined otherwise. Symbols should be decorated with
	the appropriate MY_LIB_VIS_XXX classifier, and the compiler will do the
	right thing. Note that it’s only necessary to define macros for decorators
	that have IMPORT/EXPORT variants; for others (e.g., LBAL_VIS_ENUM) the
	unaliased macro can be used - or those may be aliased uniformly aliased as
	well, for API consistency.

	SEEME These have been changed to more closely approximate libc++’s usage,
	mostly because it’s thoughfully designed for use with modules and the
	emerging C++ ABI proposals. Note, however, that many of these designations
	are currently only meaningful as annotations, in particular when running
	compilers that aren’t clang; we’ve tried to note those cases. Additionally,
	some compilers impose unexpected limitations, e.g., MSVC will not allow
	member functions to have different explicitly declared visibility than that
	of the class if the class itself was given an explicit visibility
	decorator.

	SEEME Without support from a static analyzer, there’s no way to know if a
	decorator has been misused, e.g., applying LBAL_VIS_FUNC_EXPORT to a class.
	Such misuses may not be immediately obvious with a given implementation;
	additionally, misuses that are not problematic now may become problematic
	in the future when compilers gain new capabilities. For this reason, it’s
	strongly advised to test code periodically with a good static analyzer - as
	if you needed another reason.

		LBAL_VIS_HIDDEN
			Do not export the symbol. If symbols are hidden by default, this
			does not need to be explicitly applied, but will not cause problems
			if it is.

		LBAL_VIS_ENUM
			Apply this to [class] enum declarations to mark the symbols for
			the type’s typeinfo as visible.

			SEEME gcc makes enum typeinfo visible by default, and then throws
			up warnings if a visiility attribute conflicts with this; for this
			reason, this macro is a NOP under gcc.

		LBAL_VIS_CLASS_EXPORT
		LBAL_VIS_CLASS_IMPORT
			Apply these to class, struct, and union declarations to mark the
			symbols for the type’s typeinfo, vtable, and members as visible. Do
			not use this with the various flavors of class template, and do not
			use it if a class contains member template classes; instead, use
			LBAL_VIS_CLASS_TEMPLATE_xxx.

		LBAL_VIS_CLASS_TEMPLATE
			Apply this to class template declarations to mark the symbols for
			the type’s typeinfo and vtable as visible; members are unaffected.
			Do not use this with classes that are not templates; instead, use
			LBAL_VIS_CLASS_EXPORT_xxx.

			SEEME This only works as described under clang. Under gcc, there
			is currently no __type_visibility__ attribute, so we fall back to
			using __visibility__, which means members inherit the class
			visibility. For this reason, class template members should have
			explicit decorators, in particular if visibility is supposed to
			differ from that of the class itself. MSVC has a similar issue,
			except that since class templates can’t have visibility decorators,
			the macro is a NOP; once again, members require explicit visibility
			decorators, but now they’re required for every member with
			visibility different from the translation unit default. Failing to
			adhere to this policy may result in exposing too many symbols or
			not enough symbols, depending on the compiler and the compiler
			options.

		LBAL_VIS_EXTERN_CLASS_TEMPLATE_EXPORT
		LBAL_VIS_EXTERN_CLASS_TEMPLATE_IMPORT
			Apply these to all extern class template declarations to mark the
			symbols for the type’s typeinfo, vtable, and member functions as
			visible. Do not use this with regular class template declarations;
			use LBAL_VIS_CLASS_TEMPLATE for those. This is intended specifically
			to override a LBAL_VIS_CLASS_TEMPLATE decorator on the primary
			template and explicitly export the member functions of its explicit
			instantiations. Note that there is a complementary decorator,
			LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_xxx, which must be used on the
			actual template instantiations.

		LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_EXPORT
		LBAL_VIS_CLASS_TEMPLATE_INSTANTIATION_IMPORT
			Apply these to all explicit instantiations of class templates to
			mark the symbols for the type’s typeinfo, vtable, and member
			functions as visible. While LBAL_VIS_EXTERN_CLASS_TEMPLATE_xxx is
			intended for use in headers, this complementary decorator is
			primarily used in source files; LBAL_VIS_EXTERN_CLASS_TEMPLATE_xxx
			can be seen as providing export support while this provides import
			support.

		LBAL_VIS_MEMBER_CLASS_TEMPLATE
			Apply this to all member class templates of all:
				- classes decorated with LBAL_VIS_CLASS_xxx
				- class templates decorated with
					LBAL_VIS_EXTERN_CLASS_TEMPLATE_xxx

			This will hide symbols generated by implicit instantiations of the
			member class template, preventing spurious symbol exports should
			such instantiations occur in some other library which links to this
			one. Explicit instantiations should be handled normally via
			LBAL_VIS_EXTERN_CLASS_TEMPLATE_xxx.

		LBAL_VIS_MEMBER_FUNCTION_TEMPLATE
			Apply this to member function templates of:
				- classes decorated with LBAL_VIS_CLASS_xxx
				- class templates decorated with
					LBAL_VIS_EXTERN_CLASS_TEMPLATE_xxx

			This will hide symbols generated by implicit instantiations of the
			member function template, preventing spurious symbol exports should
			such instantiations occur in some other library which links to this
			one. Note that if a function template is already decorated with
			LBAL_VIS_INLINE_FUNC or LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC, this
			decorator should not be applied. Similarly, explicit instantiations
			should be decorated normally with either LBAL_VIS_INLINE_FUNC or
			LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC, as appropriate.

		LBAL_VIS_FUNC_EXPORT
		LBAL_VIS_FUNC_IMPORT
			Apply these to declarations of visible functions that are defined
			in the library binary, i.e., not inline functions, function
			templates, or (usually) class template member functions.

		LBAL_VIS_INLINE_FUNC
			Do not export the symbol, and guarantee that it will not be subject
			to incorrect de-duping when two incompatible functions with the
			same symbol are linked into the same binary, e.g., in a situation
			where two different versions of the same library end up linked into
			one app. This can occur with inline functions when the linker
			writes a fallback copy to a library and the fallback is used
			instead of generating new object code from the header. This
			decorator can be used with all inline functions, except inline
			member functions of extern templates.

			SEEME “inline” in this context means, literally, “defined in the
			header”, and not necessarily just “functions explicitly declared
			inline”. libc++ names their equivalent macro _LIBCPP_HIDE_FROM_ABI,
			describing what it does, insted of how it’s used. In this case,
			though, the “how it’s used” may be confusing because of the
			“INLINE” part of the name, which may cause users to apply it to
			narrowly. On the other hand, “HIDE_FROM_ABI” is basically what
			LBAL_VIS_HIDDEN does, so going the other way would also be
			confusing. We’re currently going this route and relying on
			documentation for clarity.

			SEEME Because of the brittle usage requirements,
			LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC may just end up
			getting removed, with LBAL_VIS_INLINE_FUNC inheriting its
			implementation.

		LBAL_VIS_INLINE_TEMPLATE_MEMBER_FUNC
			This functions identically to LBAL_VIS_INLINE_FUNC except that it’s
			for member functions of extern templates that have been declared
			“inline” but are defined out-of-line. This unfortunately specific
			decorator is needed because of differences in how different
			compilers handle visibility in this situation.

			SEEME Note that we could eliminate this macro entirely by folding
			its extra handling into LBAL_VIS_INLINE_FUNC, but this would be at
			the cost of some symbol table bloat on certain compilers. This
			means that a given project could choose to alias their own general-
			purpose inline visibility decorator macro to this and just use it
			for all inline function decorations.

		LBAL_VIS_OVERLOADABLE_FUNC_EXPORT
		LBAL_VIS_OVERLOADABLE_FUNC_IMPORT
			Apply these to declarations of visible free functions that are
			defined in the library binary but that allow user-supplied
			overloads.

			SEEME Pragmatically, this sort of customization point is a bad
			idea. That aside, in practice, this separate designation for
			LBAL_VIS_FUNC_xxx is only needed by Windows due to how DLLs are
			handled, namely, a function marked with dllimport cannot be
			overloaded locally.

			FIXME Our method for handling this derives from how libc++ does it:
			they simply don’t decorate the function declaration for import. The
			method has not been tested, and I haven’t seen examples in the
			wild of other people using it.

		LBAL_VIS_EXTERN_EXPORT
		LBAL_VIS_EXTERN_IMPORT
			Apply these to symbols marked “extern” that are required to be
			visible. Objects that are not explicitly extern do not need this.
			Note that this does not take the place of the “extern” decorator,
			but rather supplements it.

		LBAL_VIS_EXCEPTION_EXPORT
		LBAL_VIS_EXCEPTION_IMPORT
			Apply these to exception declarations to mark the symbols for the
			type’s typeinfo, vtable, and members as visible. In practice, this
			behaves identically to LBAL_VIS_CLASS_xxx, but different annotations
			may apply for static analysis purposes.


	LBAL_CLASS_xxx
	These macros describe class decorators whose details are implementation-
	specific.

		LBAL_CLASS_FORCE_EBCO
			Force the use of the Empty Base (Class) Optimization. The
			decorator should precede the class name in its declaration.
			Note that the decorator is used specifically to indicate that
			the bases of a given class are empty, not that a given class is
			an Empty Base Class; this means it must be applied by the end
			user in a large number of practical use cases. Also note that
			the decorator must be applied in the most direct descendant to
			have effect. For example:

				struct Empty1 { };
				struct Empty2 { };
				struct Derived1 : Empty1, Empty2 { };
				struct LBAL_CLASS_FORCE_EBCO Derived2 : Derived 1 { };

			In this example, neither Derived1 -nor- Derived2 will
			necessarily benefit from the EBCO; we can’t guarantee the
			behavior. However, if Derived1 -also- has the
			LBAL_CLASS_FORCE_EBCO applied, then any compiler that supports
			the EBCO will apply it to both Derived1 -and- Derived2.

			SEEME This is really only necessary when using multiple
			inheritance and targeting MSVS; at least VS2015 Update 3 is
			required (note that Update 2, which actually introduced the
			feature, had a bug which caused it to violate the Standard).
			APIME How aggravating is it that you can’t decorate the empty
			base class itself instead of having to force a weird
			requirement on derived classes? Sadly, we’re at the mercy of
			the built-in compiler decorators, here.


	LBAL_FUNC_xxx
	These macros describe function calling conventions whose details are
	implementation-specific.

		LBAL_FUNC_CALL_C(LBAL_func_name_)
			C calling convention; default

		LBAL_FUNC_CALL_STD(LBAL_func_name_)
			Std calling convention

		LBAL_FUNC_CALLBACK_C(LBAL_func_name_)
			C-style function pointer

		LBAL_FUNC_CALLBACK_STD(LBAL_func_name_)
			Std-style function pointer


	LBAL_BUILTIN_xxx
	These are wrappers for intrinsic functions that may not be available on
	every platform. Where a given function is not available, it may be
	emulated, or simply replaced with a no-op.

		LBAL_BUILTIN_likely(LBAL_expr_)
			branch prediction hinting that something is most likely true;
			LBAL_expr_ must resolve to a boolean

		LBAL_BUILTIN_unlikely(LBAL_expr_)
			branch prediction hinting that something is most likely false;
			LBAL_expr_ must resolve to a boolean

------------------------------------------------------------------------------*/


#pragma once


//	std
#if defined (_MSC_VER) && defined (_WIN32)
	//	We guard inclusion of system headers when using MSVS due to its
	//	noisiness at high warning levels.
	#pragma warning (push, 0)
#endif

#if __has_include (<version>)
	#include <version>
		//	Once this header is universally available, it will take the place
		//	of <ciso646> abuse, providing the same functionality as well as
		//	(eventually) acting as a clearinghouse for SD-6 macros related to
		//	library features.
		//	SEEME This must not be lbalVersion.hpp, as that header depends on
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

#include <lucenaBAL/details/lbalPlatformSetup.hpp>
#include <lucenaBAL/details/lbalCompilerSetup.hpp>
#include <lucenaBAL/details/lbalLibrarySetup.hpp>
