//
//  MPFlatAdMobRewardedVideoCustomEvent.m
//  FlatAdsSDKDemo
//
//  Created by chenwenhao on 2021/5/26.
//  Copyright © 2021 FlatAds. All rights reserved.
//

#import "MPFlatAdMobRewardedVideoCustomEvent.h"

#import "FAFlatAdapterConfiguration.h"

#import <FlatAds_sdk/FlatAds_sdk.h>

#if __has_include("MoPub.h")
#import "MPLogging.h"
#import "MPReward.h"
#endif

@interface MPFlatAdMobRewardedVideoCustomEvent()<FARewardedAdDelegate>

@property(nonatomic, strong) FARewardedAd *rewardedAd;

@property(nonatomic, copy) NSString *unitId;

@end

@implementation MPFlatAdMobRewardedVideoCustomEvent

@dynamic delegate;
@dynamic localExtras;
@dynamic hasAdAvailable;


- (NSString *)getAdNetworkId
{
    return self.unitId;
}

#pragma mark - MPFullscreenAdAdapter

- (BOOL)isRewardExpected {
    return YES;
}

- (BOOL)hasAdAvailable
{
    return self.rewardedAd != nil;
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

    MPLogAdEvent([MPLogEvent adLoadAttemptForAdapter:NSStringFromClass(self.class) dspCreativeId:nil dspName:nil], [self getAdNetworkId]);
    
    FAAdRewardUnitModel *model = [[FAAdRewardUnitModel alloc] init];
    model.unitId = self.unitId;
    
    NSMutableDictionary* appendInfo = @{}.mutableCopy;
    appendInfo[@"customer_id"] = info[@"customer_id"];
    appendInfo[@"unique_id"] = info[@"unique_id"];
    appendInfo[@"reward_type"] = info[@"reward_type"];
    appendInfo[@"reward_value"] = info[@"reward_value"];
    appendInfo[@"verifier"] = info[@"verifier"];
    appendInfo[@"extinfo"] = info[@"extinfo"];
    model.appendInfo = appendInfo;
    
    UIWindow *window = [UIApplication sharedApplication].keyWindow;
    UIViewController *rootViewController = window.rootViewController;
    while (rootViewController.presentedViewController) {
        rootViewController = rootViewController.presentedViewController;
    }
    model.viewController = rootViewController;
    
    __weak typeof(self) weakSelf = self;
    [FARewardedAd loadWithAdUnitModel:model
                    completionHandler:^(FARewardedAd * _Nullable rewardedAd, NSError * _Nullable error) {
        if (error) {
            MPLogAdEvent([MPLogEvent adLoadFailedForAdapter:NSStringFromClass(weakSelf.class) error:error], [weakSelf getAdNetworkId]);
            [weakSelf.delegate fullscreenAdAdapter:self didFailToLoadAdWithError:error];
            return;
        }
        weakSelf.rewardedAd = rewardedAd;
        weakSelf.rewardedAd.delegate = weakSelf;
        
        MPLogAdEvent([MPLogEvent adLoadSuccessForAdapter:NSStringFromClass(weakSelf.class)], [weakSelf getAdNetworkId]);
        
        [weakSelf.delegate fullscreenAdAdapterDidLoadAd:weakSelf];
    }];
}

- (void)presentAdFromViewController:(UIViewController *)viewController
{
    MPLogAdEvent([MPLogEvent adShowAttemptForAdapter:NSStringFromClass(self.class)], [self getAdNetworkId]);
    
    if (self.rewardedAd) {
        [self.delegate fullscreenAdAdapterAdWillPresent:self];
        
        [self.delegate fullscreenAdAdapterAdWillAppear:self];
        
        [self.rewardedAd presentAdFromRootViewController:viewController];
        
        [self.delegate fullscreenAdAdapterAdDidPresent:self];
    
        [self.delegate fullscreenAdAdapterAdDidAppear:self];
    } else {
        NSError *error = [NSError
                          errorWithDomain:MoPubRewardedAdsSDKDomain
                          code:MPRewardedAdErrorNoAdReady
                          userInfo:@{NSLocalizedDescriptionKey : @"Rewarded ad is not ready to be presented."}];
        MPLogAdEvent([MPLogEvent adShowFailedForAdapter:NSStringFromClass(self.class) error:error], [self getAdNetworkId]);
        [self.delegate fullscreenAdAdapter:self didFailToShowAdWithError:error];
    }
}

- (BOOL)enableAutomaticImpressionAndClickTracking
{
    return NO;
}

- (void)handleDidPlayAd
{
    if (!self.rewardedAd) {
        [self.delegate fullscreenAdAdapterDidExpire:self];
    }
}

#pragma mark - FARewardedAdDelegate

/// This method is called when adView ad slot failed to load.
- (void)rewardedAd:(FARewardedAd *)rewardedAd didFailWithError:(NSError * _Nullable)error
{
    [self.delegate fullscreenAdAdapter:self didFailToShowAdWithError:error];
}

/// This method is called when ad is clicked.
- (void)rewardedAdDidClicked:(nonnull FARewardedAd *)rewardedAd
{
    [self.delegate fullscreenAdAdapterDidReceiveTap:self];
    
    [self.delegate fullscreenAdAdapterWillLeaveApplication:self];
    
    [self.delegate fullscreenAdAdapterDidTrackClick:self];
}

/// Tells the delegate that an impression has been recorded for an ad.
- (void)rewardedAdDidRecordImpression:(nonnull FARewardedAd *)rewardedAd
{
    [self.delegate fullscreenAdAdapterDidTrackImpression:self];
}

/// This method is called when ad is Closed.
- (void)rewardedAdDidClosed:(nonnull FARewardedAd *)rewardedAd
{
    self.rewardedAd = nil;

    MPLogAdEvent([MPLogEvent adWillDisappearForAdapter:NSStringFromClass(self.class)], [self getAdNetworkId]);
    [self.delegate fullscreenAdAdapterAdWillDisappear:self];
    
    MPLogAdEvent([MPLogEvent adDidDisappearForAdapter:NSStringFromClass(self.class)], [self getAdNetworkId]);
    [self.delegate fullscreenAdAdapterAdDidDisappear:self];
    
    [self.delegate fullscreenAdAdapterAdWillDismiss:self];
    [self.delegate fullscreenAdAdapterAdDidDismiss:self];
}

/// This method is called when the user earns a reward.
/// @param rewardedAd self
/// @param rewarded rewarded info
- (void)rewardedAd:(nonnull FARewardedAd *)rewardedAd didRewardEffective:(FAAdRewardUnitModel *)rewarded
{
    MPReward *moPubReward = [[MPReward alloc] initWithCurrencyType:rewarded.type
                                                            amount:rewarded.amount];
    [self.delegate fullscreenAdAdapter:self willRewardUser:moPubReward];
}

@end
