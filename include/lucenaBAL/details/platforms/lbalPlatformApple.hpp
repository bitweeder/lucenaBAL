/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“PlatformApple.hpp”
	Copyright © 2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See `lbalFeatureSetup.hpp` for descriptions of the various tokens.

------------------------------------------------------------------------------*/


#pragma once


//	std
#include <ciso646>
	//	In C++, this is a do-nothing header we include just for the side
	//	effects: the Standard Library implementation will be configured
	//	and many assorted compiler-dependent feature detection macros will
	//	be defined.


//	lbal
#include <lucenaBAL/details/lbalConfig.hpp>


/*------------------------------------------------------------------------------
	Apple Platforms
*/

//	This duplicates the test peformed to include this file in the first place.
#if LBAL_TARGET_OS_MACOS || LBAL_TARGET_OS_IOS || LBAL_TARGET_OS_IOS_SIM
	/*
		__SEEME__ Assume we’re also using Apple’s Standard Library runtime; a
		more precise test may be necessary if this turns out to be an overly
		broad assumption.

		__FIXME__ Currently, we don’t break out support for bridgeOS, the
		watchOS variant running on the T-series system-on-a-chip secure
		enclaves, or for iPadOS, the iOS variant that split from iOS in version
		13. More research is needed to determine how to support these properly.
	*/

	/*
		This is a special Apple header required for compile-time detection of
		the SDK version and the targeted platform. Note that there’s no magic
		here; historically the values are all dependent on which platform SDK
		is being used, so if the client botches that, everything else will be
		wrong. The assumption encoded here is that and “Apple” platform will be
		using an Apple SDK, and all Apple SDKs include a variant of
		`<Availability.h>`.
	*/
	#include <Availability.h>


	#if LBAL_TARGET_OS_MACOS
		#define LBAL_TARGET_API_COCOA 1
		#define LBAL_TARGET_API_POSIX 1
	#elif LBAL_TARGET_OS_IOS || LBAL_TARGET_OS_IOS_SIM
		#define LBAL_TARGET_API_COCOA_TOUCH 1

		/*
			__FIXME__ We should do some verification of this; there seems to be
			enough drift in iOS the related OS’s that it might fail some of the
			practical litmus tests for POSIX-compatibility.
		*/
		#define LBAL_TARGET_API_POSIX 1
	#else
		#error "Unsupported LBAL_TARGET_OS_xxx option"
	#endif


	/*
		Note that although `std::shared_mutex` and many other Library features
		have been declared in the libc++ headers for a long time, it was many
		OS releases before Apple got around to including the necessary object
		code in their runtimes, effectively leaving little bombs to surprise
		the unwary. We generate an error if the minimum supported OS—as
		specified by the client, is not up to the task of providing such
		features.

		Relatedly, until Xcode 10.0, `<experimental/any>` is provided, but
		there is no support for it in the runtime library (in particular, there
		is no implementation of `std::bad_any_cast`, among other things).
		Xcode 10+ includes `<any>`, but the necessary object code is only
		available under macOS 10.14+ and iOS 12+ (and equivalent-generation
		OSes), so we force `std::any` detection to fail if the minimum-targeted
		OS is not new enough, otherwise setting `LBAL_LIBCPP17_ANY` in
		`lbalLibrarySetup.hpp` normally. Note that the same situation and
		solution applies to `<optional>` and `<variant>`, as well.
	*/

	//	shared locks
	#if _LIBCPP_VERSION &&													\
		((defined (__MAC_OS_X_VERSION_MIN_REQUIRED) &&						\
				(__MAC_OS_X_VERSION_MIN_REQUIRED < 101200)) ||				\
			(defined (__IPHONE_OS_VERSION_MIN_REQUIRED) &&					\
				(__IPHONE_OS_VERSION_MIN_REQUIRED < 100000)) ||				\
			(defined (__TV_OS_VERSION_MIN_REQUIRED) &&						\
				(__TV_OS_VERSION_MIN_REQUIRED < 100000)) ||					\
			(defined (__WATCH_OS_VERSION_MIN_REQUIRED) &&					\
				(__WATCH_OS_VERSION_MIN_REQUIRED < 30000)))
		#error "The minimum OS requirement for std::shared_lock has not been met."
	#endif

	//	any, optional, variant
	#if defined (_LIBCPP_VERSION) &&										\
		((_LIBCPP_VERSION < 6000) ||										\
		((defined (__MAC_OS_X_VERSION_MIN_REQUIRED) &&						\
				(__MAC_OS_X_VERSION_MIN_REQUIRED < 101400)) ||				\
			(defined (__IPHONE_OS_VERSION_MIN_REQUIRED) &&					\
				(__IPHONE_OS_VERSION_MIN_REQUIRED < 120000)) ||				\
			(defined (__TV_OS_VERSION_MIN_REQUIRED) &&						\
				(__TV_OS_VERSION_MIN_REQUIRED < 120000)) ||					\
			(defined (__WATCH_OS_VERSION_MIN_REQUIRED) &&					\
				(__WATCH_OS_VERSION_MIN_REQUIRED < 50000))))
		#define LBAL_LIBCPP17_ANY 0L
		#define LBAL_LIBCPP17_OPTIONAL 0L
		#define LBAL_LIBCPP17_VARIANT 0L
	#endif

	//	filesystem
	#if defined (_LIBCPP_VERSION) &&										\
		((_LIBCPP_VERSION < 8000) ||										\
		((defined (__MAC_OS_X_VERSION_MIN_REQUIRED) &&						\
				(__MAC_OS_X_VERSION_MIN_REQUIRED < 101500)) ||				\
			(defined (__IPHONE_OS_VERSION_MIN_REQUIRED) &&					\
				(__IPHONE_OS_VERSION_MIN_REQUIRED < 130000)) ||				\
			(defined (__TV_OS_VERSION_MIN_REQUIRED) &&						\
				(__TV_OS_VERSION_MIN_REQUIRED < 130000)) ||					\
			(defined (__WATCH_OS_VERSION_MIN_REQUIRED) &&					\
				(__WATCH_OS_VERSION_MIN_REQUIRED < 60000))))
		#define LBAL_LIBCPP17_FILESYSTEM 0L
	#endif

	//	Set up identifiers
	#if defined (__MAC_OS_X_VERSION_MIN_REQUIRED)
		#define LBAL_NAME_TARGET_OS u8"Min macOS version " LBAL_Stringify_ (__MAC_OS_X_VERSION_MIN_REQUIRED)
	#elif defined (__IPHONE_OS_VERSION_MIN_REQUIRED)
		#define LBAL_NAME_TARGET_OS u8"Min iOS version " LBAL_Stringify_ (__IPHONE_OS_VERSION_MIN_REQUIRED)
	#elif defined (__TV_OS_VERSION_MIN_REQUIRED)
		#define LBAL_NAME_TARGET_OS u8"Min tvOS version " LBAL_Stringify_ (__TV_OS_VERSION_MIN_REQUIRED)
	#elif defined (__WATCH_OS_VERSION_MIN_REQUIRED)
		#define LBAL_NAME_TARGET_OS u8"Min watchOS version " LBAL_Stringify_ (__WATCH_OS_VERSION_MIN_REQUIRED)
	#else
		#error "Unknown Apple platform"
	#endif
#else
	#error "lbalPlatformApple.hpp was directly included by a non-Apple platform"
#endif
