//
//  MPFlatAdInterstitialCustomEvent.m
//  FlatAdsSDKDemo
//
//  Created by chenwenhao on 2021/5/26.
//  Copyright © 2021 FlatAds. All rights reserved.
//

#import "MPFlatAdInterstitialCustomEvent.h"

#if __has_include("MoPub.h")
    #import "MPLogging.h"
#endif

#import "FAFlatAdapterConfiguration.h"

#import <FlatAds_sdk/FlatAds_sdk.h>

@interface MPFlatAdInterstitialCustomEvent()<FAAdInterstitialDelegate>

@property(nonatomic, strong) FAInterstitialAd *interstitial;

@property(nonatomic, copy) NSString *unitId;

@end

@implementation MPFlatAdInterstitialCustomEvent

@dynamic delegate;
@dynamic localExtras;
@dynamic hasAdAvailable;

@synthesize interstitial = _interstitial;

- (void)dealloc
{
    self.interstitial.delegate = nil;
}

#pragma mark - MPFullscreenAdAdapter Override

- (BOOL)isRewardExpected
{
    return NO;
}

- (BOOL)hasAdAvailable
{
    return self.interstitial != nil;
}

- (void)requestAdWithAdapterInfo:(NSDictionary *)info adMarkup:(NSString *)adMarkup
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
        [self.delegate fullscreenAdAdapter:self didFailToLoadAdWithError:error];
        return;
    }
    
    FAAdUnitModel *model = [FAAdUnitModel new];
    model.unitId = self.unitId;
    
    MPLogAdEvent([MPLogEvent adLoadAttemptForAdapter:NSStringFromClass(self.class) dspCreativeId:nil dspName:nil], [self getAdNetworkId]);
    
    __weak typeof(self) weakSelf = self;
    [FAInterstitialAd loadWithAdUnitModel:model completionHandler:^(FAInterstitialAd * _Nullable interstitialAd, NSError * _Nullable error) {
        if (error) {
            MPLogAdEvent([MPLogEvent adLoadFailedForAdapter:NSStringFromClass(weakSelf.class) error:error], [weakSelf getAdNetworkId]);
            [weakSelf.delegate fullscreenAdAdapter:self didFailToLoadAdWithError:error];
            return;
        }
        
        weakSelf.interstitial = interstitialAd;
        weakSelf.interstitial.delegate = weakSelf;
        
        MPLogAdEvent([MPLogEvent adLoadSuccessForAdapter:NSStringFromClass(weakSelf.class)], [weakSelf getAdNetworkId]);
        [weakSelf.delegate fullscreenAdAdapterDidLoadAd:weakSelf];
        
        [weakSelf.delegate fullscreenAdAdapterDidTrackImpression:weakSelf];
    }];
}

- (void)presentAdFromViewController:(UIViewController *)viewController
{
    MPLogAdEvent([MPLogEvent adShowAttemptForAdapter:NSStringFromClass(self.class)], [self getAdNetworkId]);
    
    if (self.interstitial) {
        [self.delegate fullscreenAdAdapterAdWillPresent:self];
        
        [self.delegate fullscreenAdAdapterAdWillAppear:self];
        
        [self.interstitial presentAdFromRootViewController:viewController];
        
        [self.delegate fullscreenAdAdapterAdDidPresent:self];
    
        [self.delegate fullscreenAdAdapterAdDidAppear:self];
    } else {
      NSError *mopubError = [NSError errorWithCode:MOPUBErrorAdapterInvalid localizedDescription:@"Failed to show Google interstitial. An ad wasn't ready"];
      [self.delegate fullscreenAdAdapter:self didFailToShowAdWithError:mopubError];
    }
}

- (BOOL)enableAutomaticImpressionAndClickTracking
{
    return NO;
}

#pragma mark - FAAdInterstitialDelegate

/// This method is called when adView ad slot failed to load.
- (void)interstitialAd:(FAInterstitialAd *)interstitialAd didFailWithError:(NSError * __nullable)error
{
    self.interstitial = nil;
    
    NSString *failureReason = [NSString stringWithFormat: @"Google interstitial failed to show with error: %@", error.localizedDescription];
    NSError *mopubError = [NSError errorWithCode:MOPUBErrorAdapterInvalid localizedDescription:failureReason];
    
    MPLogAdEvent([MPLogEvent adLoadFailedForAdapter:NSStringFromClass(self.class) error:mopubError], [self getAdNetworkId]);
    
    [self.delegate fullscreenAdAdapter:self didFailToLoadAdWithError:mopubError];
}

/// This method is called when ad is clicked.
- (void)interstitialAdDidClicked:(nonnull FAInterstitialAd *)interstitialAd
{
    [self.delegate fullscreenAdAdapterDidReceiveTap:self];
    
    [self.delegate fullscreenAdAdapterWillLeaveApplication:self];
    
    [self.delegate fullscreenAdAdapterDidTrackClick:self];
}

/// This method is called when ad is Closed.
- (void)interstitialAdDidClosed:(nonnull FAInterstitialAd *)interstitialAd
{
    self.interstitial = nil;
    
    MPLogAdEvent([MPLogEvent adWillDisappearForAdapter:NSStringFromClass(self.class)], [self getAdNetworkId]);
    [self.delegate fullscreenAdAdapterAdWillDisappear:self];
    [self.delegate fullscreenAdAdapterAdWillDismiss:self];
    
    MPLogAdEvent([MPLogEvent adDidDisappearForAdapter:NSStringFromClass(self.class)], [self getAdNetworkId]);
    
    [self.delegate fullscreenAdAdapterAdDidDisappear:self];
    [self.delegate fullscreenAdAdapterAdDidDismiss:self];
}

- (NSString *)getAdNetworkId
{
    return self.unitId;
}

@end
