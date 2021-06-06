//
//  MPFlatAdMobRewardedVideoCustomEvent.h
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
#import "MPFullscreenAdAdapter.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@interface MPFlatAdMobRewardedVideoCustomEvent: MPFullscreenAdAdapter <MPThirdPartyFullscreenAdAdapter>

@end

NS_ASSUME_NONNULL_END
