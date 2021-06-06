//
//  MPFlatAdMobNativeCustomEvent.h
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
    #import "MPNativeCustomEvent.h"
#endif

#import <FlatAds_sdk/FlatAds_sdk.h>

NS_ASSUME_NONNULL_BEGIN

@interface MPFlatAdNativeCustomEvent : MPNativeCustomEvent

/// Sets the expan position of the Ad info icon.
+ (void)setAdInfoViewPosition:(FAInfoIconButtonExpanPosition)position;

@end

NS_ASSUME_NONNULL_END
