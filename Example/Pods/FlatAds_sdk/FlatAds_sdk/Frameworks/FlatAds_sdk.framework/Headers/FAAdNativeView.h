//
//  FAAdNativeView.h
//  FlatAds_sdk
//
//  Created by EkoHu on 2021/4/20.
//  Copyright © 2021 FlatAds. All rights reserved.
//

#import "FAAdBaseView.h"

#import "FAImageInfoModel.h"
#import "FAMediaView.h"

@class FANativeAd;
@class FAAdNativeView;

typedef void(^FALoadNativeAdBlock)(FANativeAd * _Nullable nativeAd, NSError *_Nullable error);

typedef NS_ENUM(NSUInteger, FAInfoIconButtonExpanPosition) {
    FAInfoIconButtonExpanPositionLeft = 0,
    FAInfoIconButtonExpanPositionRight
};

NS_ASSUME_NONNULL_BEGIN

@interface FANativeAd : NSObject

/// Ad unit model
@property (nonatomic, readonly, strong, nullable) FAAdUnitModel *unitModel;

/// Icon image.
@property (nonatomic, readonly, strong, nullable) FAImageInfoModel *icon;

/// Headline.
@property(nonatomic, readonly, copy, nullable) NSString *headline;

/// Description.
@property(nonatomic, readonly, copy, nullable) NSString *body;

/// Array of FAImageInfoModel objects.
@property(nonatomic, readonly, copy, nullable) NSArray<FAImageInfoModel *> *images;

/// Text that encourages user to take some action with the ad. For example "Install".
@property(nonatomic, readonly, copy, nullable) NSString *callToAction;

/// Media content. Set the associated media view's mediaContent property to this object to display
/// this content.
@property(nonatomic, readonly, strong, nonnull) FAMediaContent *mediaContent;

+ (void)loadWithAdUnitModel:(FAAdUnitModel *)unitModel completionHandler:(FALoadNativeAdBlock)completion;

@end


@protocol FANativeAdViewDelegate <NSObject>

@optional

/// This method is called when adView ad slot failed to load.
- (void)nativeAdView:(nonnull FAAdNativeView *)nativeView didLoadFailWithError:(nonnull NSError *)error;

/// This method is called when ad is clicked.
- (void)nativeAdViewDidClick:(nonnull FAAdNativeView *)nativeView;

/// Tells the delegate that an impression has been recorded for an ad.
- (void)nativeAdViewDidRecordImpression:(nonnull FAAdNativeView *)nativeView;

/// This method is called when ad is Closed.
- (void)nativeAdViewDidClosed:(nonnull FAAdNativeView *)nativeView;

@end

@interface FAAdNativeView : FAAdBaseView

/// the native ad object
@property(nonatomic, strong, nullable) FANativeAd *nativeAd;

///Reference to the object that implements FANativeAdViewDelegate protocol; will receive load events for the given unitId.
@property (nonatomic, weak, nullable) id<FANativeAdViewDelegate> delegate;

/// media view
@property (nonatomic, strong) FAMediaView *mediaView;

/// logo image
@property (nonatomic, strong) UIView *iconView;

/// ad title
@property (nonatomic, strong) UIView *headlineView;

/// ad desc
@property (nonatomic, strong) UIView *bodyView;

/// info button
@property (nonatomic, strong) UIView *infoIconView;

/// call to action button
@property (nonatomic, strong) UIView *callToActionView;

/// the info Icon expan position
@property (nonatomic, assign) FAInfoIconButtonExpanPosition expanPosition;

/// Whether the InfoView needs to be expanded. Default is YES
@property (nonatomic, assign) BOOL isExpandInfoView;

/// Play the video, if nativeAd.hasVideoContent = YES
- (void)playVideo;

@end

NS_ASSUME_NONNULL_END
