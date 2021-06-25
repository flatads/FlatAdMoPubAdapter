//
//  FAAdBannerView.h
//  FlatAds_sdk
//
//  Created by EkoHu on 2021/4/20.
//  Copyright © 2021 FlatAds. All rights reserved.
//

/**
 * Banner Ad View
 * @note Support HTML / Image
 */

#import "FAAdBaseView.h"

#import "FAAdBannerUnitModel.h"

NS_ASSUME_NONNULL_BEGIN

@class FAAdBannerView;

@protocol FABannerAdViewDelegate <NSObject>

@optional

/// This method is called when adView ad slot loaded successfully.
- (void)bannerAdViewLoadSuccess:(nonnull FAAdBannerView *)bannerAdView;

/// This method is called when adView ad slot failed to load.
- (void)bannerAdView:(nonnull FAAdBannerView *)bannerAdView didLoadFailWithError:(nonnull NSError *)error;

/// Tells the delegate that an impression has been recorded for an ad.
- (void)bannerAdViewDidRecordImpression:(nonnull FAAdBannerView *)bannerView;

/// This method is called when ad is clicked.
- (void)bannerAdViewDidClick:(nonnull FAAdBannerView *)bannerAdView;

/// This method is called when ad is Closed.
- (void)bannerAdViewDidClosed:(nonnull FAAdBannerView *)bannerAdView;

@end

@interface FAAdBannerView : FAAdBaseView

/// unit model
@property (nonatomic, readonly, strong) FAAdBannerUnitModel *unitModel;

/// Reference to the object that implements FABannerAdViewDelegate protocol; will receive load events for the given unitId.
@property (nonatomic, weak, nullable) id<FABannerAdViewDelegate> delegate;

/// initialize a FAAdBaseView with the FAAdBannerUnitModel.
/// @param model FAAdBannerUnitModel
- (instancetype)initWithUnitModel:(FAAdBannerUnitModel *)model;

@end

NS_ASSUME_NONNULL_END
