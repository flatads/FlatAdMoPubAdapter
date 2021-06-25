//
//  FAAdUnitModel.h
//  FlatAds_sdk
//
//  Created by EkoHu on 2021/4/22.
//  Copyright © 2021 FlatAds. All rights reserved.
//

/**
 * Ad view request parameter info
 */

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface FAAdUnitModel : NSObject

/// The id of the ad unit. You can create your unit id from our Portal.
@property (nonatomic, copy) NSString *unitId;

/// The view controller that will be used to present  page.
@property (nonatomic, weak) UIViewController *viewController;

/// Request parameter expansion.
@property (nonatomic, copy) NSDictionary *appendInfo;

/// unique id
@property (nonatomic, copy, nullable) NSString *token;

@end

NS_ASSUME_NONNULL_END
