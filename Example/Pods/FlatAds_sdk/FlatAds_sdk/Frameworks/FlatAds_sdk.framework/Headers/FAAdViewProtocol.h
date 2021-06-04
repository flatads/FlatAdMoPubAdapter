//
//  FAAdViewProtocol.h
//  FlatAds_sdk
//
//  Created by EkoHu on 2021/4/20.
//  Copyright © 2021 FlatAds. All rights reserved.
//

/**
 * Ad View Protocol And Delegate
 */

#import <Foundation/Foundation.h>
#import "FAAdUnitModel.h"

#pragma mark -------------- Protocol --------------

@protocol FAAdViewProtocol <NSObject>
/**
 * This is a method to initialize an FAAdBaseView with the given unit id.
 * @param model Ad view request parameter info.
 * @return object
 */
- (nonnull instancetype)initWithUnitModel:(nonnull FAAdUnitModel *)model;

/**
 * Request a  Ad data.
 */
- (void)loadAds;

/**
 * Whether or not if there was a available ad to show.
 * @return YES means there was a available ad, otherwise NO.
*/
- (BOOL)isAdReady;

@optional

/**
 * Call this method when you want to relase the ad, and the adView will be removed from your presenting view.
 * @note After calling this method, if you need to continue using the FAAdBaseView, you must reinitialize a FAAdBaseView
*/
- (void)destroyView;

@end
