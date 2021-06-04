//
//  FAFlatAdapterConfiguration.m
//  FlatAdsSDKDemo
//
//  Created by chenwenhao on 2021/5/26.
//  Copyright © 2021 FlatAds. All rights reserved.
//

#import "FAFlatAdapterConfiguration.h"

#if __has_include("MoPub.h")
    #import "MPLogging.h"
#endif

#import <FlatAds_sdk/FlatAds_sdk.h>

// Initialization configuration keys
NSString * const kAdMobApplicationIdKey = @"appid";
NSString * const kAdMobApplicationTokenKey = @"token";

static NSString *mUserId;
static NSString *mRewardName;
static NSInteger mRewardAmount;
static NSString *mMediaExtra;

// Errors
static NSString * const kAdapterErrorDomain = @"com.mopub.mopub-ios-sdk.mopub-flatad-adapters";

typedef NS_ENUM(NSInteger, FAFlatAdAdapterErrorCode) {
    FAFlatAdAdapterErrorCodeMissingAppIdOrToken
};

@implementation FAFlatAdapterConfiguration

#pragma mark - Caching

+ (void)updateInitializationParameters:(NSDictionary *)parameters
{
    // These should correspond to the required parameters checked in
    // `initializeNetworkWithConfiguration:complete:`
    NSString *appId = parameters[kAdMobApplicationIdKey];
    NSString *token = parameters[kAdMobApplicationTokenKey];
    
    NSMutableDictionary *configuration = @{}.mutableCopy;
    configuration[kAdMobApplicationIdKey] = appId;
    configuration[kAdMobApplicationTokenKey] = token;
    [self setCachedInitializationParameters:configuration];
}

#pragma mark - MPAdapterConfiguration

- (NSString *)adapterVersion
{
    return  [[FlatAdsSDK sdkVersion] stringByAppendingString:@".1"];
}

- (NSString *)biddingToken
{
    return nil;
}

- (NSString *)moPubNetworkName
{
    return @"flatads";
}

- (NSString *)networkSdkVersion
{
    return [FlatAdsSDK sdkVersion];
}

- (void)initializeNetworkWithConfiguration:(NSDictionary<NSString *, id> *)configuration
                                  complete:(void(^)(NSError *))complete {

    NSString *flatAppId = configuration[kAdMobApplicationIdKey];
    NSString *flatToken = configuration[kAdMobApplicationTokenKey];
    
    if (configuration.count == 0 ||
        !(flatAppId && [flatAppId isKindOfClass:[NSString class]] && flatAppId.length > 0) ||
        !(flatToken && [flatToken isKindOfClass:[NSString class]] && flatToken.length > 0)) {
        NSError *error = [NSError errorWithDomain:kAdapterErrorDomain
                                             code:FAFlatAdAdapterErrorCodeMissingAppIdOrToken
                                         userInfo:@{NSLocalizedDescriptionKey:
                                                        @"Invalid or missing Flat appId, please set networkConfig refer to method '-configCustomEvent' in 'AppDelegate' class"}];
        if (complete != nil) {
            complete(error);
        }
    } else {
        [FAFlatAdapterConfiguration flatAdSDKInitWithAppId:configuration[kAdMobApplicationIdKey] token:flatToken];
        if (complete != nil) {
            complete(nil);
        }
    }
}

+ (void)flatAdSDKInitWithAppId:(NSString *)appId token:(NSString *)token
{
    if (!(appId && [appId isKindOfClass:[NSString class]] && appId.length > 0) ||
        !(token && [token isKindOfClass:[NSString class]] && token.length > 0)) {
        NSError *error = [NSError errorWithDomain:NSStringFromClass([self class])
                                             code:FAFlatAdAdapterErrorCodeMissingAppIdOrToken
                                         userInfo:@{NSLocalizedDescriptionKey: @"Incorrect or missing Pangle appId. Failing to initialize. Ensure the appId and token is correct."}];
        MPLogEvent([MPLogEvent error:error message:nil]);
        return;
    }
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        dispatch_async(dispatch_get_main_queue(), ^{
            MPBLogLevel logLevel = [MPLogging consoleLogLevel];
            BOOL verboseLoggingEnabled = (logLevel == MPBLogLevelDebug);
            
            [FlatAdsSDK setLogLevel:(verboseLoggingEnabled == YES ? FALogLevelDebug : FALogLevelNone)];

//            BOOL canCollectPersonalInfo =  [[MoPub sharedInstance] canCollectPersonalInfo];
//            [FlatAdsSDK setGDPR:canCollectPersonalInfo ? 0 : 1];
            
            [FlatAdsSDK setUserExtData:@"[{\"name\":\"mediation\",\"value\":\"mopub\"},{\"name\":\"adapter_version\",\"value\":\"1.0.0\"}]"];

            [FlatAdsSDK setAppID:appId appToken:token];
            
            MPLogInfo(@"Pangle SDK initialized succesfully with appId: %@.", appId);
        });
    });
}

#pragma mark - Public

+ (void)setUserId:(NSString *)userId {
    mUserId = userId;
}

+ (NSString *)userId {
    return mUserId;
}

+ (void)setRewardName:(NSString *)rewardName {
    mRewardName = rewardName;
}

+ (NSString *)rewardName {
    return mRewardName;
}

+ (void)setRewardAmount:(NSInteger)rewardAmount {
    mRewardAmount = rewardAmount;
}

+ (NSInteger)rewardAmount {
    return mRewardAmount;
}

+ (void)setMediaExtra:(NSString *)mediaExtra {
    mMediaExtra = mediaExtra;
}

+ (NSString *)mediaExtra {
    return mMediaExtra;
}

// MoPub collects GDPR consent on behalf of Flat
+ (NSString *)npaString
{
    return !MoPub.sharedInstance.canCollectPersonalInfo ? @"1" : @"";
}

@end
