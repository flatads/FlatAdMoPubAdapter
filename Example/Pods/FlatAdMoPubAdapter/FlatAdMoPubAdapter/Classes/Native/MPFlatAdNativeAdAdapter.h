//
//  MPFlatAdNativeAdAdapter.h
//  FlatAdsSDKDemo
//
//  Created by chenwenhao on 2021/5/26.
//  Copyright © 2021 FlatAds. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<MoPub/MoPub.h>)
#import <MoPub/MoPub.h>
#elif __has_include(<MoPubSDK/MoPub.h>)
#import <MoPubSDK/MoPub.h>
#else
#import "MPNativeAdAdapter.h"
#endif

#import <FlatAds_sdk/FlatAds_sdk.h>

NS_ASSUME_NONNULL_BEGIN

@interface MPFlatAdNativeAdAdapter : NSObject<MPNativeAdAdapter, FANativeAdViewDelegate>

/// MoPub native ad adapter delegate instance.
@property(nonatomic, weak) id<MPNativeAdAdapterDelegate> delegate;

/// Flat Ads Native ad instance.
@property(nonatomic, strong) FANativeAd *nativeAd;

/// Flat Ads adView to hold the native ad view.
@property(nonatomic, strong) FAAdNativeView *nativeAdView;


/// Returns an MPFlatAdNativeAdAdapter with FANativeAd.
- (instancetype)initWithFlatNativeAd:(FANativeAd *)nativeAd
                        nativeAdView:(FAAdNativeView *)nativeAdView;

- (void)nativeAdImpression;

@end

NS_ASSUME_NONNULL_END
