//
//  FAImageInfoModel.h
//  FlatAds_sdk
//
//  Created by EkoHu on 2021/4/16.
//  Copyright © 2021 FlatAds. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface FAImageInfoModel : NSObject

@property (nonatomic, assign) NSUInteger w;

@property (nonatomic, assign) NSUInteger h;

@property (nonatomic, copy) NSString *url;

@property (nonatomic, assign) CGFloat scale;

@end

NS_ASSUME_NONNULL_END
