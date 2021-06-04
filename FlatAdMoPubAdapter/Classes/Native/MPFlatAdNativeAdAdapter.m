//
//  MPFlatAdNativeAdAdapter.m
//  FlatAdsSDKDemo
//
//  Created by chenwenhao on 2021/5/26.
//  Copyright © 2021 FlatAds. All rights reserved.
//

#import "MPFlatAdNativeAdAdapter.h"

#if __has_include("MoPub.h")
    #import "MPLogging.h"
    #import "MPNativeAdConstants.h"
    #import "MPNativeAdError.h"
#endif

@implementation MPFlatAdNativeAdAdapter

@synthesize properties = _properties;

- (instancetype)initWithFlatNativeAd:(FANativeAd *)nativeAd
                        nativeAdView:(FAAdNativeView *)nativeAdView;
{
    if (self = [super init]) {
        self.nativeAd = nativeAd;
        
        self.nativeAdView = nativeAdView;
        self.nativeAdView.delegate = self;
        
        NSMutableDictionary *properties = [NSMutableDictionary dictionary];
        if (nativeAd.headline) {
            properties[kAdTitleKey] = nativeAd.headline;
        }
        
        if (nativeAd.icon.url) {
            properties[kAdIconImageKey] = nativeAd.icon.url;
        }
        
        if (nativeAd.body) {
            properties[kAdTextKey] = nativeAd.body;
        }
        
        //      if (flatNativeAdView.nativeAd.starRating) {
        //        properties[kAdStarRatingKey] = flatNativeAdView.nativeAd.starRating;
        //      }
        
        if (nativeAd.callToAction) {
            properties[kAdCTATextKey] = nativeAd.callToAction;
        }
        
        //      if (flatNativeAdView.nativeAd.price) {
        //        properties[] = flatNativeAdView.nativeAd.price;
        //      }
        
        //      if (adMobNativeAd.store) {
        //        properties[] = adMobNativeAd.store;
        //      }

        if (nativeAd.images.count > 0) {
            properties[kAdMainImageKey] = nativeAd.images.firstObject.url;
        }
        
        if (nativeAdView.mediaView) {
            properties[kAdMainMediaViewKey] = nativeAdView.mediaView;
        }
        
        _properties = properties;
    }
    
    return self;
}

#pragma mark - Public

- (void)nativeAdImpression
{
    [self.delegate nativeAdWillLogImpression:self];
}


#pragma mark - FANativeAdViewDelegate

/// This method is called when adView ad slot failed to load.
- (void)nativeAdView:(nonnull FAAdNativeView *)nativeView didLoadFailWithError:(nonnull NSError *)error
{
}

/// This method is called when ad is clicked.
- (void)nativeAdViewDidClick:(nonnull FAAdNativeView *)nativeView
{
    [self.delegate nativeAdDidClick:self];
    MPLogAdEvent([MPLogEvent adTappedForAdapter:NSStringFromClass(self.class)], nil);
}

/// This method is called when ad is Closed.
- (void)nativeAdViewDidClosed:(nonnull FAAdNativeView *)nativeView
{
    
}

#pragma mark - <MPNativeAdAdapter>

- (UIView *)privacyInformationIconView
{
    return self.nativeAdView.infoIconView;
}

- (UIView *)mainMediaView
{
    return self.nativeAdView.mediaView;
}

- (NSURL *)defaultActionURL
{
    return nil;
}

- (BOOL)enableThirdPartyClickTracking
{
    return YES;
}

@end
