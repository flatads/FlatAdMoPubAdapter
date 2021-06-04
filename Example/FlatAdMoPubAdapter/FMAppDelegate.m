//
//  FMAppDelegate.m
//  FlatAdMoPubAdapter
//
//  Created by flatads on 06/04/2021.
//  Copyright (c) 2021 flatads. All rights reserved.
//

#import "FMAppDelegate.h"

#import <FlatAds_sdk/FlatAdsSDK.h>

#if __has_include(<MoPub/MoPub.h>)
#import <MoPub/MoPub.h>
#elif __has_include(<MoPubSDK/MoPub.h>)
#import <MoPubSDK/MoPub.h>
#else
#import "MoPub.h"
#import "MPRewardedAds.h"
#endif

#import <FlatAdMoPubAdapter/FAFlatAdapterConfiguration.h>
#import <AppTrackingTransparency/AppTrackingTransparency.h>

@implementation FMAppDelegate

- (void)_initMoPub
{
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
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Override point for customization after application launch
    [self _initMoPub];
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
