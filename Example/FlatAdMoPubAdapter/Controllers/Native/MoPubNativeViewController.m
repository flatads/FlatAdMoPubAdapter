//
//  MoPubNativeViewController.m
//  ADAdapterDemo
//
//  Created by chenwenhao on 2021/5/31.
//

#import "MoPubNativeViewController.h"

#if __has_include(<MoPub/MoPub.h>)
#import <MoPub/MoPub.h>
#elif __has_include(<MoPubSDK/MoPub.h>)
#import <MoPubSDK/MoPub.h>
#else
#import "MoPub.h"
#import "MPInterstitialAdController.h"
#endif

#import "MPCustomNativeAdView.h"
#import "MPFlatAdNativeRenderer.h"

#import "MPFlatAdNativeCustomEvent.h"

@interface MoPubNativeViewController ()<MPTableViewAdPlacerDelegate, MPNativeAdDelegate, UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) MPTableViewAdPlacer *placer;

@property (nonatomic, strong) UIView *containerView;

@property (nonatomic, strong) MPNativeAd *nativeAd;

@end

@implementation MoPubNativeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // 203642f7d20c4853865aad61fd1435b7
    
    [self.view addSubview:self.containerView];
    
    CGFloat width = self.view.frame.size.width;
    CGFloat height = self.view.frame.size.height;
    
    self.containerView.frame = CGRectMake((width - 320) * .5, (height - 280) * .5, 320, 280);

    
    [MPFlatAdNativeCustomEvent setAdInfoViewPosition:FAInfoIconButtonExpanPositionLeft];
    
    MPStaticNativeAdRendererSettings *settings = [[MPStaticNativeAdRendererSettings alloc] init];
    settings.renderingViewClass = [MPCustomNativeAdView class];
    settings.viewSizeHandler = ^(CGFloat maximumWidth) {
        return CGSizeMake(maximumWidth , 280.0f);
    };

    MPNativeAdRendererConfiguration *config = [MPFlatAdNativeRenderer rendererConfigurationWithRendererSettings:settings];
    MPNativeAdRequest *adRequest = [MPNativeAdRequest requestWithAdUnitIdentifier:@"203642f7d20c4853865aad61fd1435b7"
                                                           rendererConfigurations:@[config]];
    MPNativeAdRequestTargeting *targeting = [MPNativeAdRequestTargeting targeting];
    targeting.desiredAssets = [NSSet setWithObjects:kAdTitleKey,
                               kAdTextKey,
                               kAdCTATextKey,
                               kAdIconImageKey,
                               kAdMainImageKey,
                               kAdMainMediaViewKey,
                               nil];
//    targeting.location = [self getCurrentLocation];
    adRequest.targeting = targeting ;
    
    [adRequest startWithCompletionHandler:^(MPNativeAdRequest *request, MPNativeAd *response, NSError *error) {
        if (error) {
            // Handle error.
        } else {
            self.nativeAd = response;
            self.nativeAd.delegate = self;
            UIView *nativeAdView = [response retrieveAdViewWithError:nil];
            nativeAdView.frame = self.containerView.bounds;
            [self.containerView addSubview:nativeAdView];
        }
    }];
    
//    self.placer = [MPTableViewAdPlacer placerWithTableView:self.tableView
//                                            viewController:self
//                                    rendererConfigurations:@[config]];
//    self.placer.delegate = self;
//    [self.placer loadAdsForAdUnitID:@"203642f7d20c4853865aad61fd1435b7"];
}


/*
 This method is called when a native ad, placed by the table view ad placer, will present a modal view controller.

 @param placer The table view ad placer that contains the ad displaying the modal.
 */
- (void)nativeAdWillPresentModalForTableViewAdPlacer:(MPTableViewAdPlacer *)placer
{
    
}

/*
 This method is called when a native ad, placed by the table view ad placer, did dismiss its modal view controller.

 @param placer The table view ad placer that contains the ad that dismissed the modal.
 */
- (void)nativeAdDidDismissModalForTableViewAdPlacer:(MPTableViewAdPlacer *)placer
{
    
}

/*
 This method is called when a native ad, placed by the table view ad placer, will cause the app to background due to user interaction with the ad.

 @param placer The table view ad placer that contains the ad causing the app to background.
 */
- (void)nativeAdWillLeaveApplicationFromTableViewAdPlacer:(MPTableViewAdPlacer *)placer
{
    
}


#pragma mark - UITableViewDelegate  UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 10;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell" forIndexPath:indexPath];
    
    return cell;
}

#pragma mark - getter

- (UIView *)containerView
{
    if (!_containerView) {
        _containerView = [UIView new];
        _containerView.backgroundColor = UIColor.whiteColor;
    }
    return _containerView;
}



/** @name Managing Modal Content Presentation */

/**
 Asks the delegate for a view controller to use for presenting modal content, such as the in-app
 browser that can appear when an ad is tapped.

 @return A view controller that should be used for presenting modal content.
 */
- (UIViewController *)viewControllerForPresentingModalView
{
    return self;
}

/**
 Sent when the native ad will present its modal content.

 @param nativeAd The native ad sending the message.
 */
- (void)willPresentModalForNativeAd:(MPNativeAd *)nativeAd
{
    
}

/**
 Sent when a native ad has dismissed its modal content, returning control to your application.

 @param nativeAd The native ad sending the message.
 */
- (void)didDismissModalForNativeAd:(MPNativeAd *)nativeAd
{
    
}


/**
 Sent when a user is about to leave your application as a result of tapping this native ad.

 @param nativeAd The native ad sending the message.
 */
- (void)willLeaveApplicationFromNativeAd:(MPNativeAd *)nativeAd
{
    
}


@end
