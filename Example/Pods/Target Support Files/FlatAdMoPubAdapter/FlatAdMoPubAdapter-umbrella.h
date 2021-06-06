#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "MPFlatAdBannerCustomEvent.h"
#import "FAFlatAdapterConfiguration.h"
#import "FlatAdMoPubAdapter.h"
#import "MPFlatAdInterstitialCustomEvent.h"
#import "MPFlatAdNativeAdAdapter.h"
#import "MPFlatAdNativeCustomEvent.h"
#import "MPFlatAdNativeRenderer.h"
#import "MPFlatAdMobRewardedVideoCustomEvent.h"
#import "UIView+MPFlatAdAdditions.h"
#import "MPFlatAdBannerCustomEvent.h"

FOUNDATION_EXPORT double FlatAdMoPubAdapterVersionNumber;
FOUNDATION_EXPORT const unsigned char FlatAdMoPubAdapterVersionString[];

