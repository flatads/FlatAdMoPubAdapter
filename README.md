# FlatAdMoPubAdapter

[![CI Status](https://img.shields.io/travis/flatads/FlatAdMoPubAdapter.svg?style=flat)](https://travis-ci.org/flatads/FlatAdMoPubAdapter)
[![Version](https://img.shields.io/cocoapods/v/FlatAdMoPubAdapter.svg?style=flat)](https://cocoapods.org/pods/FlatAdMoPubAdapter)
[![License](https://img.shields.io/cocoapods/l/FlatAdMoPubAdapter.svg?style=flat)](https://cocoapods.org/pods/FlatAdMoPubAdapter)
[![Platform](https://img.shields.io/cocoapods/p/FlatAdMoPubAdapter.svg?style=flat)](https://cocoapods.org/pods/FlatAdMoPubAdapter)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements

## Installation

FlatAdMoPubAdapter is available through [CocoaPods](https://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'FlatAdMoPubAdapter'
```

## How To Use

请联系您的客户经理为您创建Flat Ads 开发者账号。文档见 [Flat Ads SDK 入门指南](https://github.com/flatads/document "Flat Ads SDK入门指南")。

```objc
#if __has_include(<MoPub/MoPub.h>)
#import <MoPub/MoPub.h>
#elif __has_include(<MoPubSDK/MoPub.h>)
#import <MoPubSDK/MoPub.h>
#else
#import "MoPub.h"
#import "MPRewardedAds.h"
#endif

#import <FlatAdMoPubAdapter/FAFlatAdapterConfiguration.h>


MPMoPubConfiguration *sdkConfig = [[MPMoPubConfiguration alloc] initWithAdUnitIdForAppInitialization:@""];

sdkConfig.globalMediationSettings = @[];
sdkConfig.loggingLevel = MPBLogLevelInfo;
sdkConfig.allowLegitimateInterest = YES;
sdkConfig.additionalNetworks = @[FAFlatAdapterConfiguration.class];

NSMutableDictionary *configurations = [NSMutableDictionary new];

NSMutableDictionary *flatConfig = [NSMutableDictionary new];
[flatConfig setObject:@"flat ad app id" forKey:@"appid"];
[flatConfig setObject:@"flat ad token" forKey:@"token"];

configurations[@"FAFlatAdapterConfiguration"] = flatConfig;

sdkConfig.mediatedNetworkConfigurations = configurations;

[[MoPub sharedInstance] initializeSdkWithConfiguration:sdkConfig
                                            completion:^{
    NSLog ( @"SDK initialization complete" );
    // SDK initialization complete. Ready to make ad requests.
    
    dispatch_async(dispatch_get_main_queue(), ^{
        // pre load
//            [MPRewardedAds loadRewardedAdWithAdUnitID:@"Rewarded Ad unitid"
//                                withMediationSettings:nil];
    });
    
}];
```

## Author

flatads, chenwh02@flatincbr.com

## License

FlatAdMoPubAdapter is available under the MIT license. See the LICENSE file for more info.
