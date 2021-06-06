//
//  MPFlatAdMobNativeCustomEvent.m
//  FlatAdsSDKDemo
//
//  Created by chenwenhao on 2021/5/26.
//  Copyright © 2021 FlatAds. All rights reserved.
//

#import "MPFlatAdNativeCustomEvent.h"

#import "MPFlatAdNativeAdAdapter.h"
#import "FAFlatAdapterConfiguration.h"

#if __has_include("MoPub.h")
#import "MPLogging.h"
#import "MPNativeAd.h"
#import "MPNativeAdConstants.h"
#import "MPNativeAdError.h"
#import "MPNativeAdUtils.h"
#endif

static FAInfoIconButtonExpanPosition adInfoPosition;

@interface MPFlatAdNativeCustomEvent()

@property(nonatomic, copy) NSString *unitId;

@end

@implementation MPFlatAdNativeCustomEvent

+ (void)setAdInfoViewPosition:(FAInfoIconButtonExpanPosition)position
{
    @synchronized([self class]) {
        adInfoPosition = position;
    }
}

- (void)requestAdWithCustomEventInfo:(NSDictionary *)info adMarkup:(NSString *)adMarkup
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
        [self.delegate nativeCustomEvent:self didFailToLoadAdWithError:error];
        return;
    }
    
    UIWindow *window = [UIApplication sharedApplication].keyWindow;
    UIViewController *rootViewController = window.rootViewController;
    while (rootViewController.presentedViewController) {
        rootViewController = rootViewController.presentedViewController;
    }
    
    FAAdUnitModel* unitModel = [FAAdUnitModel new];
    unitModel.unitId = self.unitId;
    unitModel.viewController = rootViewController;
    
    __weak typeof(self) weakSelf = self;
    [FANativeAd loadWithAdUnitModel:unitModel completionHandler:^(FANativeAd * _Nullable nativeAd, NSError * _Nullable error) {
        if (error) {
            MPLogAdEvent([MPLogEvent adLoadFailedForAdapter:NSStringFromClass(weakSelf.class) error:error], weakSelf.unitId);
            [weakSelf.delegate nativeCustomEvent:weakSelf didFailToLoadAdWithError:error];
            return;
        }
        
        if (![weakSelf isValidNativeAd:nativeAd]) {
            MPLogInfo(@"Native ad is missing one or more required assets, failing the request");
            [weakSelf.delegate nativeCustomEvent:weakSelf
                        didFailToLoadAdWithError:MPNativeAdNSErrorForInvalidAdServerResponse(
                                                                                             @"Missing one or more required assets.")];
            return;
        }
        
        [weakSelf loadNativeAd:nativeAd];
    }];
    
    // Cache the network initialization parameters
    [FAFlatAdapterConfiguration updateInitializationParameters:info];
    MPLogAdEvent([MPLogEvent adLoadAttemptForAdapter:NSStringFromClass(self.class) dspCreativeId:nil dspName:nil], self.unitId);
}


- (void)loadNativeAd:(FANativeAd *)nativeAd
{
    FAAdNativeView *nativeAdView = [FAAdNativeView new];
    
    FAMediaView* mediaView = [FAMediaView new];
    [nativeAdView addSubview:mediaView];
    nativeAdView.mediaView = mediaView;
    
    UILabel *headlineView = [[UILabel alloc] initWithFrame:CGRectZero];
    headlineView.text = nativeAd.headline;
    headlineView.textColor = [UIColor clearColor];
    [nativeAdView addSubview:headlineView];
    nativeAdView.headlineView = headlineView;

    UILabel *bodyView = [[UILabel alloc] initWithFrame:CGRectZero];
    bodyView.text = nativeAd.body;
    bodyView.textColor = [UIColor clearColor];
    [nativeAdView addSubview:bodyView];
    nativeAdView.bodyView = bodyView;

    UILabel *callToActionView = [[UILabel alloc] initWithFrame:CGRectZero];
    callToActionView.text = nativeAd.callToAction;
    callToActionView.textColor = [UIColor clearColor];
    [nativeAdView addSubview:callToActionView];
    nativeAdView.callToActionView = callToActionView;

    UIImageView *iconView = [[UIImageView alloc] initWithFrame:CGRectZero];
//    iconView.image = nativeAd.images.firstObject;
    [nativeAdView addSubview:iconView];
    nativeAdView.iconView = iconView;
    
    
    nativeAdView.expanPosition = adInfoPosition;
    
    UIView* infoIconView = [UIView new];
    [nativeAdView addSubview:infoIconView];
    nativeAdView.infoIconView = infoIconView;

    nativeAdView.nativeAd = nativeAd;
    
    MPFlatAdNativeAdAdapter *adapter = [[MPFlatAdNativeAdAdapter alloc] initWithFlatNativeAd:nativeAd
                                                                                nativeAdView:nativeAdView];
    
    MPNativeAd *moPubNativeAd = [[MPNativeAd alloc] initWithAdAdapter:adapter];
    
    NSMutableArray *imageURLs = [NSMutableArray array];
    
    if ([moPubNativeAd.properties[kAdIconImageKey] length]) {
        if (![MPNativeAdUtils addURLString:moPubNativeAd.properties[kAdIconImageKey]
                                toURLArray:imageURLs]) {
            MPLogAdEvent([MPLogEvent adLoadFailedForAdapter:NSStringFromClass(self.class) error:MPNativeAdNSErrorForInvalidImageURL()], self.unitId);
            [self.delegate nativeCustomEvent:self
                    didFailToLoadAdWithError:MPNativeAdNSErrorForInvalidImageURL()];
        }
    }

    if ([moPubNativeAd.properties[kAdMainImageKey] length]) {
        if (![MPNativeAdUtils addURLString:moPubNativeAd.properties[kAdMainImageKey]
                                toURLArray:imageURLs]) {
            MPLogAdEvent([MPLogEvent adLoadFailedForAdapter:NSStringFromClass(self.class) error:MPNativeAdNSErrorForInvalidImageURL()], self.unitId);
            [self.delegate nativeCustomEvent:self
                    didFailToLoadAdWithError:MPNativeAdNSErrorForInvalidImageURL()];
        }
    }
    
    [super precacheImagesWithURLs:imageURLs
                  completionBlock:^(NSArray *errors) {
        if (errors) {
            MPLogAdEvent([MPLogEvent adLoadFailedForAdapter:NSStringFromClass(self.class) error:MPNativeAdNSErrorForImageDownloadFailure()], self.unitId);
            [self.delegate nativeCustomEvent:self
                    didFailToLoadAdWithError:MPNativeAdNSErrorForImageDownloadFailure()];
        } else {
            MPLogAdEvent([MPLogEvent adLoadSuccessForAdapter:NSStringFromClass(self.class)], self.unitId);
            [self.delegate nativeCustomEvent:self didLoadAd:moPubNativeAd];
        }
    }];

    
    // Sending impression to MoPub SDK.
    [adapter nativeAdImpression];;
}

#pragma mark - Private Methods

- (NSString *)getAdNetworkId
{
    return self.unitId;
}

/// Checks the native ad has required assets or not.
- (BOOL)isValidNativeAd:(FANativeAd *)nativeAd
{
    return (nativeAd.headline && nativeAd.body && nativeAd.icon && nativeAd.callToAction);
}

@end
