//
//  MopubViewController.m
//  ADAdapterDemo
//
//  Created by chenwenhao on 2021/5/31.
//

#import "MopubBannerViewController.h"

#if __has_include(<MoPub/MoPub.h>)
#import <MoPub/MoPub.h>
#elif __has_include(<MoPubSDK/MoPub.h>)
#import <MoPubSDK/MoPub.h>
#else
#import "MoPub.h"
#import "MPAdView.h"
#endif


//#import "MoPub."

@interface MopubBannerViewController ()<MPAdViewDelegate>

@property (nonatomic, strong) MPAdView * adView;

@end

@implementation MopubBannerViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // 0a7b4585872e49d5b62932d0849cd0ca
    self.adView = [[MPAdView alloc ] initWithAdUnitId:@"0a7b4585872e49d5b62932d0849cd0ca"];//@"343cf980-a17c-11eb-ad10-bf9f4da0961d"];
    self.adView.delegate = self;
    // Ensure the adView's parent has a size set in order to use kMPPresetMaxAdSizeMatchFrame. Otherwise, give your adView's frame a specific size (eg 320 x 50)
    self.adView.frame = CGRectMake (0, 100, self.view.frame.size.width, kMPPresetMaxAdSize50Height.height);
    [self.view addSubview:self.adView];
    
    
    // You can pass in specific width and height to be requested
//    [self.adView loadAdWithMaxAdSize:];
    // Or you can use one of the height-based constants
    [self.adView loadAdWithMaxAdSize:CGSizeMake(self.view.frame.size.width, 50)];
    // Alternatively, you can use the frame as the maximum ad size
//    [self.adView loadAdWithMaxAdSize:kMPPresetMaxAdSizeMatchFrame];
    
//    [self.adView loadAd];
}

- (UIViewController *)viewControllerForPresentingModalView
{
    return self;
}

/**
 Sent when an ad view successfully loads an ad.

 Your implementation of this method should insert the ad view into the view hierarchy, if you
 have not already done so.

 @param view The ad view sending the message.
 @param adSize The size of the ad that was successfully loaded. It is recommended to resize
 the @c MPAdView frame to match the height of the loaded ad.
 */
- (void)adViewDidLoadAd:(MPAdView *)view adSize:(CGSize)adSize
{
    
}


/**
 Sent when an ad view fails to load an ad.

 To avoid displaying blank ads, you should hide the ad view in response to this message.

 @param view The ad view sending the message.
 @param error The error
 */
- (void)adView:(MPAdView *)view didFailToLoadAdWithError:(NSError *)error
{
    
}

/** @name Detecting When a User Interacts With the Ad View */

/**
 Sent when an ad view is about to present modal content.

 This method is called when the user taps on the ad view. Your implementation of this method
 should pause any application activity that requires user interaction.

 @param view The ad view sending the message.
 @see `didDismissModalViewForAd:`
 */
- (void)willPresentModalViewForAd:(MPAdView *)view
{
    
}

/**
 Sent when an ad view has dismissed its modal content, returning control to your application.

 Your implementation of this method should resume any application activity that was paused
 in response to `willPresentModalViewForAd:`.

 @param view The ad view sending the message.
 @see `willPresentModalViewForAd:`
 */
- (void)didDismissModalViewForAd:(MPAdView *)view
{
    
}

/**
 Sent when a user is about to leave your application as a result of tapping
 on an ad.

 Your application will be moved to the background shortly after this method is called.

 @param view The ad view sending the message.
 */
- (void)willLeaveApplicationFromAd:(MPAdView *)view
{
    
}

@end
