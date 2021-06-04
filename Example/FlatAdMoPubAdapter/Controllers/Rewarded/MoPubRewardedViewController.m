//
//  MoPubRewardedViewController.m
//  ADAdapterDemo
//
//  Created by chenwenhao on 2021/5/31.
//

#import "MoPubRewardedViewController.h"

#if __has_include(<MoPub/MoPub.h>)
#import <MoPub/MoPub.h>
#elif __has_include(<MoPubSDK/MoPub.h>)
#import <MoPubSDK/MoPub.h>
#else
#import "MoPub.h"
#import "MPRewardedAds.h"
#endif

@interface MoPubRewardedViewController ()<MPRewardedAdsDelegate>

@end

@implementation MoPubRewardedViewController

- (void)viewDidLoad {
    [super viewDidLoad];
//    5083ff89717047aabced45d8f19e64de

    [MPRewardedAds loadRewardedAdWithAdUnitID:@"5083ff89717047aabced45d8f19e64de"
                        withMediationSettings:nil];
    
    [MPRewardedAds setDelegate:self forAdUnitId:@"5083ff89717047aabced45d8f19e64de"];


    // Do any additional setup after loading the view.
}

- (IBAction)showAd:(id)sender
{
    BOOL isReady = [MPRewardedAds hasAdAvailableForAdUnitID:@"5083ff89717047aabced45d8f19e64de"];
    
    if (isReady) {
//        MPReward* reward = [[MPReward alloc] initWithCurrencyType:@"falt" amount:@20];
        
        [MPRewardedAds presentRewardedAdForAdUnitID:@"5083ff89717047aabced45d8f19e64de"
                                fromViewController:self
                                         withReward:nil
                                         customData:@"https://www.baidu.com"];
    
    }
}

- (void)rewardedAdDidLoadForAdUnitID:(NSString *)adUnitID
{
    
}

- (void)rewardedAdDidFailToLoadForAdUnitID:(NSString *)adUnitID error:(NSError *)error
{
    
}

- (void)rewardedAdDidFailToShowForAdUnitID:(NSString *)adUnitID error:(NSError *)error
{
    
}

- (void)rewardedAdWillPresentForAdUnitID:(NSString *)adUnitID
{
    
}

- (void)rewardedAdDidPresentForAdUnitID:(NSString *)adUnitID
{
    
}

- (void)rewardedAdWillDismissForAdUnitID:(NSString *)adUnitID
{
    
}

- (void)rewardedAdDidDismissForAdUnitID:(NSString *)adUnitID
{
    [MPRewardedAds loadRewardedAdWithAdUnitID:@"5083ff89717047aabced45d8f19e64de"
                        withMediationSettings:nil];
}

- (void)rewardedAdShouldRewardForAdUnitID:(NSString *)adUnitID reward:(MPReward *)reward
{
    
}

- (void)rewardedAdDidExpireForAdUnitID:(NSString *)adUnitID
{
    
}

- (void)rewardedAdDidReceiveTapEventForAdUnitID:(NSString *)adUnitID
{
    
}

- (void)rewardedAdWillLeaveApplicationForAdUnitID:(NSString *)adUnitID
{
    
}
/**
Called when an impression is fired on a Rewarded Ad. Includes information about the impression if applicable.

@param adUnitID The ad unit ID of the rewarded ad that fired the impression.
@param impressionData Information about the impression, or @c nil if the server didn't return any information.
*/
- (void)didTrackImpressionWithAdUnitID:(NSString *)adUnitID impressionData:(MPImpressionData *)impressionData
{
    
}


@end
