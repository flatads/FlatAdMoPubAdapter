//
//  MPFlatAdMobNativeRenderer.m
//  FlatAdsSDKDemo
//
//  Created by chenwenhao on 2021/5/26.
//  Copyright © 2021 FlatAds. All rights reserved.
//

#import "MPFlatAdNativeRenderer.h"

#if __has_include("MoPub.h")
    #import "MPLogging.h"
    #import "MPNativeAdAdapter.h"
    #import "MPNativeAdConstants.h"
    #import "MPNativeAdError.h"
    #import "MPNativeAdRendererConfiguration.h"
    #import "MPNativeAdRendererImageHandler.h"
    #import "MPNativeAdRendering.h"
    #import "MPNativeAdRenderingImageLoader.h"
    #import "MPNativeView.h"
    #import "MPStaticNativeAdRendererSettings.h"
#endif

#import "MPFlatAdNativeAdAdapter.h"
#import "UIView+MPFlatAdAdditions.h"

#import <FlatAds_sdk/UIImageView+TCUIKit.h>

@interface MPFlatAdNativeRenderer()<MPNativeAdRendererImageHandlerDelegate>

/// Publisher adView which is rendering.
@property(nonatomic, strong) UIView<MPNativeAdRendering> *adView;

/// MPFlatAdNativeAdAdapter instance.
@property(nonatomic, strong) MPFlatAdNativeAdAdapter *adapter;

/// YES if adView is in view hierarchy.
@property(nonatomic, assign) BOOL adViewInViewHierarchy;

/// MPNativeAdRendererImageHandler instance.
@property(nonatomic, strong) MPNativeAdRendererImageHandler *rendererImageHandler;

/// Class of renderingViewClass.
@property(nonatomic, strong) Class renderingViewClass;

/// FAAdNativeView instance.
@property(nonatomic, strong) FAAdNativeView *nativeAdView;

@end

@implementation MPFlatAdNativeRenderer

@synthesize viewSizeHandler;

/// Construct and return an MPNativeAdRendererConfiguration object, you must set all the properties
/// on the configuration object.
+ (MPNativeAdRendererConfiguration *)rendererConfigurationWithRendererSettings:(id<MPNativeAdRendererSettings>)rendererSettings
{
    MPNativeAdRendererConfiguration *config = [[MPNativeAdRendererConfiguration alloc] init];
    config.rendererClass = [self class];
    config.rendererSettings = rendererSettings;
    config.supportedCustomEvents = @[@"MPFlatAdNativeCustomEvent"];
    
    return config;
}

/// Renderer settings are objects that allow you to expose configurable properties to the
/// application. MPFlatAdNativeRenderer renderer will be initialized with these settings.
- (instancetype)initWithRendererSettings:(id<MPNativeAdRendererSettings>)rendererSettings
{
    if (self = [super init]) {
        MPStaticNativeAdRendererSettings *settings = (MPStaticNativeAdRendererSettings *)rendererSettings;
        _renderingViewClass = settings.renderingViewClass;
        viewSizeHandler = [settings.viewSizeHandler copy];
        _rendererImageHandler = [MPNativeAdRendererImageHandler new];
        _rendererImageHandler.delegate = self;
    }
    
    return self;
}

/// Returns an ad view rendered using provided |adapter|. Sets an |error| if any error is
/// encountered.
- (UIView *)retrieveViewWithAdapter:(id<MPNativeAdAdapter>)adapter error:(NSError **)error
{
    if (!adapter || ![adapter isKindOfClass:[MPFlatAdNativeAdAdapter class]]) {
        if (error) {
            *error = MPNativeAdNSErrorForRenderValueTypeError();
        }
        
        return nil;
    }
    
    self.adapter = (MPFlatAdNativeAdAdapter *)adapter;
    self.nativeAdView = self.adapter.nativeAdView;
    self.nativeAdView.autoresizingMask = UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth;
    
    MPLogAdEvent([MPLogEvent adShowAttemptForAdapter:NSStringFromClass(self.class)], nil);
    MPLogAdEvent([MPLogEvent adWillAppearForAdapter:NSStringFromClass(self.class)], nil);
    [self renderAdViewWithAdapter:self.adapter];
    return self.nativeAdView;
}

/// Creates Native AdView with adapter. We added FAAdNativeView assets on
/// top of MoPub's adView, to track impressions & clicks.
- (void)renderAdViewWithAdapter:(id<MPNativeAdAdapter>)adapter
{
    // We only load text here. We're creating the FAAdNativeView and preparing text
    // assets.
    if ([self.renderingViewClass respondsToSelector:@selector(nibForAd)]) {
        self.adView = (UIView<MPNativeAdRendering> *)[[[self.renderingViewClass nibForAd]
                                                       instantiateWithOwner:nil
                                                       options:nil] firstObject];
    } else {
        self.adView = [[self.renderingViewClass alloc] init];
    }
    
    self.adView.autoresizingMask = UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth;
    
    [self.nativeAdView addSubview:self.adView];
    [self.adView fa_fillSuperview];
    
    if ([self.adView respondsToSelector:@selector(nativeTitleTextLabel)]) {
        [self.adView.nativeTitleTextLabel addSubview:self.nativeAdView.headlineView];
        self.adView.nativeTitleTextLabel.text = adapter.properties[kAdTitleKey];
        [self.nativeAdView.headlineView fa_fillSuperview];
    }
    
    if ([self.adView respondsToSelector:@selector(nativeMainTextLabel)]) {
        [self.adView.nativeMainTextLabel addSubview:self.nativeAdView.bodyView];
        self.adView.nativeMainTextLabel.text = adapter.properties[kAdTextKey];
        [self.nativeAdView.bodyView fa_fillSuperview];
    }
    
    if ([self.adView respondsToSelector:@selector(nativeCallToActionTextLabel)] &&
        self.adView.nativeCallToActionTextLabel) {
        [self.adView.nativeCallToActionTextLabel addSubview:self.nativeAdView.callToActionView];
        [self.nativeAdView.callToActionView fa_fillSuperview];
        self.adView.nativeCallToActionTextLabel.text = adapter.properties[kAdCTATextKey];
    }
    
    if ([self.adView respondsToSelector:@selector(nativeIconImageView)]) {
        [self.adView.nativeIconImageView addSubview:self.nativeAdView.iconView];
        [self.nativeAdView.iconView fa_fillSuperview];
    }
    
    // as its subview if it does.
    if ([self.adView respondsToSelector:@selector(nativePrivacyInformationIconImageView)]) {
        self.adView.nativePrivacyInformationIconImageView.userInteractionEnabled = YES;
        [self.adView.nativePrivacyInformationIconImageView addSubview:self.nativeAdView.infoIconView];
        [self.nativeAdView.infoIconView fa_fillSuperview];
    }
    
    // See if the ad contains the nativeMainImageView and add FAMediaView as its subview if it does.
    if ([self.adView respondsToSelector:@selector(nativeMainImageView)]) {
        [self.adView.nativeMainImageView addSubview:self.nativeAdView.mediaView];
        [self.nativeAdView.mediaView fa_fillSuperview];
    }
    
    [self.nativeAdView.mediaView playVideo];
}

/// Check the ad view is superView or not, if not adView will move to superView.
- (void)adViewWillMoveToSuperview:(UIView *)superview {
    self.adViewInViewHierarchy = (superview != nil);
    
    if (superview) {
        // We'll start asychronously loading the native ad images now.
        if (self.adapter.properties[kAdIconImageKey] &&
            [self.adView respondsToSelector:@selector(nativeIconImageView)]) {
            [self.adView.nativeIconImageView setImageWithString:self.adapter.properties[kAdIconImageKey]];
//            [self.rendererImageHandler loadImageForURL:[NSURL URLWithString:self.adapter.properties[kAdIconImageKey]]
//                                         intoImageView:self.adView.nativeIconImageView];
        }
        
        // Lay out custom assets here as the custom assets may contain images that need to be loaded.
        if ([self.adView respondsToSelector:@selector(layoutCustomAssetsWithProperties:imageLoader:)]) {
            // Create a simplified image loader for the ad view to use.
            MPNativeAdRenderingImageLoader *imageLoader = [[MPNativeAdRenderingImageLoader alloc] initWithImageHandler:self.rendererImageHandler];
            [self.adView layoutCustomAssetsWithProperties:self.adapter.properties
                                              imageLoader:imageLoader];
        }
    }
}

#pragma mark - MPNativeAdRendererImageHandlerDelegate

- (BOOL)nativeAdViewInViewHierarchy
{
    return self.adViewInViewHierarchy;
}

@end
