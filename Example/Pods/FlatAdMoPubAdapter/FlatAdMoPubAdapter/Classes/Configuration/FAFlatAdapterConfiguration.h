//
//  FAFlatAdapterConfiguration.h
//  FlatAdsSDKDemo
//
//  Created by chenwenhao on 2021/5/26.
//  Copyright © 2021 FlatAds. All rights reserved.
//

#import <Foundation/Foundation.h>
#if __has_include(<MoPub/MoPub.h>)
#import <MoPub/MoPub.h>
#elif __has_include(<MoPubSDK/MoPub.h>)
#import <MoPubSDK/MoPub.h>
#else
#import "MPBaseAdapterConfiguration.h"
#import "MoPub.h"
#endif

NS_ASSUME_NONNULL_BEGIN

extern NSString * const kAdMobApplicationIdKey;
extern NSString * const kAdMobApplicationTokenKey;

@interface FAFlatAdapterConfiguration : MPBaseAdapterConfiguration

// MPAdapterConfiguration
@property (nonatomic, copy, readonly) NSString * adapterVersion;

@property (nonatomic, copy, readonly) NSString * biddingToken;

@property (nonatomic, copy, readonly) NSString * moPubNetworkName;

@property (nonatomic, copy, readonly) NSString * networkSdkVersion;

@property (class, nonatomic, copy, readonly) NSString * npaString;


// Caching
/**
 Extracts the parameters used for network SDK initialization and if all required
 parameters are present, updates the cache.
 @param parameters Ad response parameters
 */
+ (void)updateInitializationParameters:(NSDictionary *)parameters;

- (void)initializeNetworkWithConfiguration:(NSDictionary<NSString *, id> * _Nullable)configuration
                                  complete:(void(^ _Nullable)(NSError * _Nullable))complete;

// Set optional data for rewarded ad
+ (void)setUserId:(NSString *)userId;

+ (NSString *)userId;

+ (void)setRewardName:(NSString *)rewardName;

+ (NSString *)rewardName;

+ (void)setRewardAmount:(NSInteger)rewardAmount;

+ (NSInteger)rewardAmount;

+ (void)setMediaExtra:(NSString *)extra;

+ (NSString *)mediaExtra;

+ (void)flatAdSDKInitWithAppId:(NSString *)appId token:(NSString *)token;

@end

NS_ASSUME_NONNULL_END
