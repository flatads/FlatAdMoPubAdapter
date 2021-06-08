//
//  MoPubInterstitialViewController.m
//  ADAdapterDemo
//
//  Created by chenwenhao on 2021/5/31.
//

#import "MoPubInterstitialViewController.h"

#if __has_include(<MoPub/MoPub.h>)
#import <MoPub/MoPub.h>
#elif __has_include(<MoPubSDK/MoPub.h>)
#import <MoPubSDK/MoPub.h>
#else
#import "MoPub.h"
#import "MPInterstitialAdController.h"
#endif

@interface MoPubInterstitialViewController ()<MPInterstitialAdControllerDelegate>

@property (nonatomic, strong) MPInterstitialAdController *interstitial;

@end

@implementation MoPubInterstitialViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [self loadInterstitial];
    // Do any additional setup after loading the view.
}

- (IBAction)showAd:(id)sender
{
    [self levelDidEnd];
}

- (void)loadInterstitial
{
    // Instantiate the interstitial using the class convenience method.
    self.interstitial = [MPInterstitialAdController interstitialAdControllerForAdUnitId:@"921e3a812a2540bc887458bbbe99d4de"];
    self.interstitial.delegate = self;
    // Fetch the interstitial ad.
    [self.interstitial loadAd];
}

// Present the ad only after it is ready.
- (void)levelDidEnd
{
    if (self.interstitial.ready) {
        
//        UIViewController* vc = [UIApplication sharedApplication].keyWindow.rootViewController;
        [self.interstitial showFromViewController:self];
    } else {
        
        // The interstitial wasn't ready, so continue as usual.
    }
}


/** @name Detecting When an Interstitial Ad is Loaded */

/**
 Sent when an interstitial ad object successfully loads an ad.

 @param interstitial The interstitial ad object sending the message.
 */
- (void)interstitialDidLoadAd:(MPInterstitialAdController *)interstitial
{

}

/**
 Sent when an interstitial ad object fails to load an ad.

 @param interstitial The interstitial ad object sending the message.
 @param error The error that occurred during the load.
 */
- (void)interstitialDidFailToLoadAd:(MPInterstitialAdController *)interstitial
                          withError:(NSError *)error
{
    
}

/** @name Detecting When an Interstitial Ad is Presented */

/**
 Sent immediately before an interstitial ad object is presented on the screen.

 @param interstitial The interstitial ad object sending the message.
 */
- (void)interstitialWillPresent:(MPInterstitialAdController *)interstitial
{
    
}

/**
 Sent after an interstitial ad object has been presented on the screen.

 Your implementation of this method should pause any application activity that requires user
 interaction.

 @param interstitial The interstitial ad object sending the message.
 */
- (void)interstitialDidPresent:(MPInterstitialAdController *)interstitial
{
    
}

/**
 Sent immediately before an interstitial ad object will be dismissed from the screen.

 Your implementation of this method should resume any application activity that was paused
 prior to the interstitial being presented on-screen.

 @param interstitial The interstitial ad object sending the message.
 */
- (void)interstitialWillDismiss:(MPInterstitialAdController *)interstitial
{
    
}

/**
 Sent after an interstitial ad object has been dismissed from the screen, returning control
 to your application.

 Your implementation of this method should resume any application activity that was paused
 prior to the interstitial being presented on-screen.

 @param interstitial The interstitial ad object sending the message.
 */
- (void)interstitialDidDismiss:(MPInterstitialAdController *)interstitial
{
    [self loadInterstitial];
}

/** @name Detecting When an Interstitial Ad Expires */

/**
 Sent when a loaded interstitial ad is no longer eligible to be displayed.

 Interstitial ads from certain networks may expire their content at any time,
 even if the content is currently on-screen. This method notifies you when the currently-
 loaded interstitial has expired and is no longer eligible for display.

 If the ad was on-screen when it expired, you can expect that the ad will already have been
 dismissed by the time this message is sent.

 Your implementation may include a call to `loadAd` to fetch a new ad, if desired.

 @param interstitial The interstitial ad object sending the message.
 */
- (void)interstitialDidExpire:(MPInterstitialAdController *)interstitial
{
    
}

/**
 Sent when the user taps the interstitial ad and the ad is about to perform its target action.

 This action may include displaying a modal or leaving your application. Certain ad networks
 may not expose a "tapped" callback so you should not rely on this callback to perform
 critical tasks.

 @param interstitial The interstitial ad object sending the message.
 */
- (void)interstitialDidReceiveTapEvent:(MPInterstitialAdController *)interstitial
{
    
}

@end
