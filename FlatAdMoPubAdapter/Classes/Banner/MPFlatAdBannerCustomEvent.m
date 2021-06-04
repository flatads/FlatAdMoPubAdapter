//
//  MPFlatAdBannerCustomEvent.m
//  FlatAdsSDKDemo
//
//  Created by chenwenhao on 2021/5/26.
//  Copyright © 2021 FlatAds. All rights reserved.
//

#import "MPFlatAdBannerCustomEvent.h"

#if __has_include("MoPub.h")
    #import "MPLogging.h"
#endif

#import "FAFlatAdapterConfiguration.h"

#import <FlatAds_sdk/FlatAds_sdk.h>

@interface MPFlatAdBannerCustomEvent ()<FABannerAdViewDelegate>

@property(nonatomic, strong) FAAdBannerView *adBannerView;

@property(nonatomic) CGSize adSize;

@property(nonatomic, copy) NSString *unitId;

@end

@implementation MPFlatAdBannerCustomEvent

@dynamic delegate;

@dynamic localExtras;

- (id)init
{
  self = [super init];
  if (self) {
    self.adBannerView = [[FAAdBannerView alloc] initWithFrame:CGRectZero];
    self.adBannerView.delegate = self;
  }
  return self;
}

- (void)dealloc
{
  self.adBannerView.delegate = nil;
}

- (BOOL)enableAutomaticImpressionAndClickTracking
{
    return NO;
}


- (void)requestAdWithSize:(CGSize)size adapterInfo:(NSDictionary *)info adMarkup:(NSString *)adMarkup
{
    NSString *appid = info[kAdMobApplicationIdKey];
    NSString *token = info[kAdMobApplicationTokenKey];
    [FAFlatAdapterConfiguration flatAdSDKInitWithAppId:appid
                                                 token:token];
    
    // Cache the network initialization parameters
    [FAFlatAdapterConfiguration updateInitializationParameters:info];
    
    self.unitId = info[@"unitid"];
    
    if (!(self.unitId && [self.unitId isKindOfClass:[NSString class]] && self.unitId.length > 0) ) {
        NSError *error =
        [NSError errorWithDomain:MoPubRewardedAdsSDKDomain
                            code:MPRewardedAdErrorInvalidAdUnitID
                        userInfo:@{NSLocalizedDescriptionKey : @"Ad Unit ID cannot be nil."}];
        
        MPLogAdEvent([MPLogEvent adLoadFailedForAdapter:NSStringFromClass(self.class) error:error], [self getAdNetworkId]);
        [self.delegate inlineAdAdapter:self didFailToLoadAdWithError:error];
        return;
    }
    
    self.adSize = size;
    
    if (self.adSize.width <= 0.0 || self.adSize.height <= 0.0) {
        NSString *failureReason = @"Flat Ad banner failed to load due to invalid ad width and/or height.";
        NSError *mopubError = [NSError errorWithCode:MOPUBErrorAdapterInvalid localizedDescription:failureReason];
        
        MPLogAdEvent([MPLogEvent adLoadFailedForAdapter:NSStringFromClass(self.class) error:mopubError], [self getAdNetworkId]);
        [self.delegate inlineAdAdapter:self didFailToLoadAdWithError:mopubError];
        
        return;
    }
    
    FAAdBannerUnitModel* unitModel = [FAAdBannerUnitModel new];
    unitModel.sizeType = size.height > 50 ? FAAdBannerSizeType300x250 : FAAdBannerSizeType320x50;
    unitModel.unitId = self.unitId;
    unitModel.viewController = [self.delegate inlineAdAdapterViewControllerForPresentingModalView:self];
    
    self.adBannerView = [[FAAdBannerView alloc] initWithUnitModel:unitModel];
    self.adBannerView.frame = CGRectMake(0, 0, size.width, size.height);
    self.adBannerView.delegate = self;
    [self.adBannerView loadAds];
    
    MPLogAdEvent([MPLogEvent adLoadAttemptForAdapter:NSStringFromClass(self.class)
                                     dspCreativeId:nil
                                           dspName:nil], [self getAdNetworkId]);
}



#pragma mark FABannerAdViewDelegate methods

/// This method is called when adView ad slot loaded successfully.
- (void)bannerAdViewLoadSuccess:(nonnull FAAdBannerView *)bannerAdView
{
    [self.delegate inlineAdAdapter:self didLoadAdWithAdView:self.adBannerView];
    
    [self.delegate inlineAdAdapterDidTrackImpression:self];
}

/// This method is called when adView ad slot failed to load.
- (void)bannerAdView:(nonnull FAAdBannerView *)bannerAdView didLoadFailWithError:(nonnull NSError *)error
{
    [self.delegate inlineAdAdapter:self didFailToLoadAdWithError:error];
}

/// This method is called when ad is clicked.
- (void)bannerAdViewDidClick:(nonnull FAAdBannerView *)bannerAdView
{
    [self.delegate inlineAdAdapterDidTrackClick:self];
}

/// This method is called when ad is Closed.
- (void)bannerAdViewDidClosed:(nonnull FAAdBannerView *)bannerAdView
{
    [self.delegate inlineAdAdapterDidEndUserAction:self];
}


- (NSString *)getAdNetworkId
{
    return (self.adBannerView) ? self.adBannerView.unitModel.unitId : @"";
}


@end
