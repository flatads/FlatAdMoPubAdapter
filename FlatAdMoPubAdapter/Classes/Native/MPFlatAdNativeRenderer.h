//
//  MPFlatAdMobNativeRenderer.h
//  FlatAdsSDKDemo
//
//  Created by chenwenhao on 2021/5/26.
//  Copyright © 2021 FlatAds. All rights reserved.
//

#if __has_include(<MoPub/MoPub.h>)
    #import <MoPub/MoPub.h>
#elif __has_include(<MoPubSDK/MoPub.h>)
    #import <MoPubSDK/MoPub.h>
#else
    #import "MPNativeAdRenderer.h"
    #import "MPNativeAdRendererSettings.h"
#endif

@class MPNativeAdRendererConfiguration;
@class MPStaticNativeAdRendererSettings;

NS_ASSUME_NONNULL_BEGIN

@interface MPFlatAdNativeRenderer : NSObject<MPNativeAdRendererSettings>

/// Constructs and returns an MPNativeAdRendererConfiguration object specific for the
/// MPFlatAdMobNativeRenderer. You must set all the properties on the configuration object.
/// @param rendererSettings Application defined settings.
/// @return A configuration object for MPFlatAdMobNativeRenderer.
+ (MPNativeAdRendererConfiguration *)rendererConfigurationWithRendererSettings:(id<MPNativeAdRendererSettings>)rendererSettings;

@end

NS_ASSUME_NONNULL_END
