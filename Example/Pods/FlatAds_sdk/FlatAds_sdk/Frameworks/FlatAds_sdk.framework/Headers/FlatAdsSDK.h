//
//  FlatAdsSDK.h
//  FlatAds_sdk
//
//  Created by EkoHu on 2021/4/27.
//  Copyright © 2021 FlatAds. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppTrackingTransparency/AppTrackingTransparency.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, FALogLevel) {
    FALogLevelNone = 0,
    FALogLevelError,
    FALogLevelWarning,
    FALogLevelInfo,
    FALogLevelDebug,
    FALogLevelVerbose
};

@interface FlatAdsSDK : NSObject
/**
 * Config App Info
 * @param appID The unique identifier of the sdk
 * @param appToken Register the app token that’s already been applied
 */
+ (void)setAppID:(nonnull NSString *)appID appToken:(nonnull NSString *)appToken;

/// Get version of the sdk
+ (nonnull NSString *)sdkVersion;

/// Whether to open log. default is none.
+ (void)setLogLevel:(FALogLevel)level;

/// Tracking authorization completed. Start loading ads here.
+ (void)requestIDFAWithCompletionHandler:(void(^)(ATTrackingManagerAuthorizationStatus status))completion API_AVAILABLE(ios(14));

/// set additional user information.
+ (void)setUserExtData:(NSString *)data;

@end

NS_ASSUME_NONNULL_END
