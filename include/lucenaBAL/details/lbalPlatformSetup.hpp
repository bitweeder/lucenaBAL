/*------------------------------------------------------------------------------

	Lucena Build Abstraction Library
	“PlatformSetup.hpp”
	Copyright © 2018-2019 Lucena
	All Rights Reserved

	This file is distributed under the University of Illinois Open Source
	License. See license/License.txt for details.

	See lbalFeatureSetup.hpp for descriptions of the various macros and flags.

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
	Platform Macros

	__SEEME__ Arguably, it would be more desirable to give each platform its own
	#include file and include them here conditionally rather than go the
	monolithic route. We trade off potential unnecessary recompilation of
	unaffected projects for simplified maintenance at this time.
*/

#if (LBAL_TARGET_OS_MACOS || LBAL_TARGET_OS_IOS || LBAL_TARGET_OS_IOS_SIM)
	#if __has_include (<Availability.h>)
		//	__SEEME__ If we get here, we assume we’re also using Apple’s Standard
		//	Library runtime; a more precise test may be necessary if this turns
		//	out to be an overly broad assumption.

		#include <Availability.h>
			//	Special Apple header required for compile-time detection of the
			//	SDK version and the targeted platform. Note that there’s no
			//	magic here; historically the values are all dependent on which
			//	platform SDK is being used, so if the user botches that,
			//	everything else will be wrong.

		#if LBAL_TARGET_OS_MACOS
			#define LBAL_TARGET_API_COCOA 1
			#define LBAL_TARGET_API_POSIX 1
		#elif LBAL_TARGET_OS_IOS || LBAL_TARGET_OS_IOS_SIM
			#define LBAL_TARGET_API_COCOA_TOUCH 1

			//	__FIXME__ We should do some verification of this; there seems to be
			//	enough drift in iOS that it might fail many of the prgmatic
			//	litmus tests for POSIX-compatibility.
			#define LBAL_TARGET_API_POSIX 1
		#else
			#error "Unsupported LBAL_TARGET_OS_xxx option"
		#endif

		//	Note that although shared_mutex and friends have been declared in
		//	the libc++ headers for a long time, it was many OS releases before
		//	Apple got around to including the necessary object code in their
		//	runtimes, effectively leaving little bombs to surprise the unwary.
		//	We warn if the minimum supported OS, as specified by the user, is
		//	not up to the task of providing shared locks.
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

		//	Until Xcode 10.0, <experimental/any> is provided, but there is no
		//	support for it in the runtime library (in particular, there is no
		//	implementation of bad_any_cast, among other things). Xcode 10+
		//	includes <any>, but the necessary object code is only available
		//	under macOS 10.14+ and iOS 12+ (and equivalent-generation OS’s), so
		//	we force std::any detection to fail if the minimum-targeted OS is
		//	not new enough, otherwise setting LBAL_LIBCPP17_ANY in
		//	lbalAnyWrapper.hpp. Note that the same situation and solution
		//	applies to <optional> and <variant>, as well.
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
		#if LBAL_TARGET_OS_MACOS
			#define LBAL_NAME_TARGET_OS u8"macOS"
			#define LBAL_TARGET_API_POSIX 1
		#elif LBAL_TARGET_OS_IOS
			#define LBAL_NAME_TARGET_OS u8"iOS"
			#define LBAL_TARGET_API_POSIX 1
		#elif LBAL_TARGET_OS_IOS_SIM
			#define LBAL_NAME_TARGET_OS u8"iOS Simulator"
			#define LBAL_TARGET_API_POSIX 1
		#else
			#error "Unknown Apple platform"
		#endif
	#endif	//	Availability.h
#elif LBAL_TARGET_OS_X11
	#ifndef LBAL_TARGET_API_POSIX
		#define LBAL_TARGET_API_POSIX 1
	#endif

	#ifndef LBAL_TARGET_API_X11
		#define LBAL_TARGET_API_X11 1
	#endif

	#if defined (__linux__)
		#define LBAL_NAME_TARGET_OS u8"Linux"
	#elif defined (__FreeBSD__)
		#define LBAL_NAME_TARGET_OS u8"FreeBSD version " LBAL_Stringify_ (__FreeBSD__)
	#elif defined (__NetBSD__)
		#define LBAL_NAME_TARGET_OS u8"NetBSD version " LBAL_Stringify_ (__NetBSD__)
	#elif defined (__OpenBSD__)
		#define LBAL_NAME_TARGET_OS u8"OpenBSD version " LBAL_Stringify_ (__OpenBSD__)
	#elif defined (__DragonFly__)
		#define LBAL_NAME_TARGET_OS u8"DragonFly version " LBAL_Stringify_ (__DragonFly__)
	#else
		#error "Unknown LBAL_TARGET_OS_X11 variant; update details/lbalPlatformSetup.hpp"
	#endif
#elif LBAL_TARGET_OS_WINAPI
	//	We make no assumptions about the addressing model based on processor,
	//	instead relying on intrinsics.
	#if defined (_WIN64)
		#define LBAL_TARGET_RT_64_BIT 1

		#ifndef LBAL_TARGET_API_WIN64
			#define LBAL_TARGET_API_WIN64 1
		#endif

		#define LBAL_TYPE_DOUBLE_GT_FLOAT 1
		#define LBAL_TYPE_LONG_DOUBLE_GT_DOUBLE 1
	#elif defined (_WIN32)
		#define LBAL_TARGET_RT_32_BIT 1

		#ifndef LBAL_TARGET_API_WIN32
			#define LBAL_TARGET_API_WIN32 1
		#endif

		//	unverified
		#define LBAL_TYPE_DOUBLE_GT_FLOAT 1
		#define LBAL_TYPE_LONG_DOUBLE_GT_DOUBLE 1
	#else
		#error "Unsupported addressing model"
	#endif


	#define LBAL_FEATURE_UTF16_FILE_SYSTEM 1


	//	WinAPI configuration; these are set up to avoid stomping on any
	//	prefix header-originated definitions that might be in use.
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
			//	__FIXME__ Maybe not super-smart to set this up globally
	#endif

	#ifndef NOMINMAX
		#define NOMINMAX
	#endif


	#define LBAL_NAME_TARGET_OS u8"Windows"
#endif
