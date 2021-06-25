//
//  FAAdInterstitialView.h
//  FlatAds_sdk
//
//  Created by EkoHu on 2021/4/20.
//  Copyright © 2021 FlatAds. All rights reserved.
//

/**
 * Interstitial Ad View
 * @note Support Image / Video
 */

#import "FAAdViewProtocol.h"

@class FAInterstitialAd;

NS_ASSUME_NONNULL_BEGIN

typedef void(^FALoadInterstitialAdBlock)(FAInterstitialAd * _Nullable interstitialAd, NSError *_Nullable error);

@class FAInterstitialAd;

@protocol FAAdInterstitialDelegate <NSObject>

@optional

/// This method is called when adView ad slot failed to load.
- (void)interstitialAd:(FAInterstitialAd *)interstitialAd didFailWithError:(NSError * __nullable)error;

/// Tells the delegate that an impression has been recorded for an ad.
- (void)interstitialAdDidRecordImpression:(nonnull FAInterstitialAd *)interstitialAd;

/// This method is called when ad is clicked.
- (void)interstitialAdDidClicked:(nonnull FAInterstitialAd *)interstitialAd;

/// This method is called when ad is Closed.
- (void)interstitialAdDidClosed:(nonnull FAInterstitialAd *)interstitialAd;

@end

@interface FAInterstitialAd : NSObject<FAAdViewProtocol>

/// unit model
@property (nonatomic, readonly, strong) FAAdUnitModel * _Nullable unitModel;

/**
 * Reference to the object that implements FAAdInterstitialDelegate protocol; will receive load events for the given unitId.
 */
@property (nonatomic, weak, nullable) id<FAAdInterstitialDelegate> delegate;

/// Load ad data
/// @param unitModel unitModel
/// @param completion request completion
+ (void)loadWithAdUnitModel:(FAAdUnitModel *)unitModel completionHandler:(FALoadInterstitialAdBlock)completion;

/// Display interstitial ad.
/// @param rootViewController : root view controller for displaying ad.
/// @return : whether it is successfully displayed.
- (BOOL)presentAdFromRootViewController:(UIViewController *)rootViewController;

@end

NS_ASSUME_NONNULL_END
