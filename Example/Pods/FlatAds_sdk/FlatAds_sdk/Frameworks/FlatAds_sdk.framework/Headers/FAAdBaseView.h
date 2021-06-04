//
//  FAAdBaseView.h
//  FlatAds_sdk
//
//  Created by EkoHu on 2021/4/20.
//  Copyright © 2021 FlatAds. All rights reserved.
//

/**
 * Ad Base View 
 */

#import <UIKit/UIKit.h>
#import "FAAdViewProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface FAAdBaseView : UIView <FAAdViewProtocol>
/// Override : Device Orientation Change Method
- (void)onDeviceOrientationDidPortraitChange;
- (void)onDeviceOrientationDidPortraitUpsideDownChange;
- (void)onDeviceOrientationDidLandscapeLeftChange;
- (void)onDeviceOrientationDidLandscapeRightChange;
@end

NS_ASSUME_NONNULL_END
