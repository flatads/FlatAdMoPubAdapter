//
//  FABiddingRequestParameter.h
//  FlatAds_sdk
//
//  Created by chenwenhao on 2021/6/7.
//  Copyright © 2021 FlatAds. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FABiddingRequestParameter : NSObject

@property(nonatomic, copy, readonly) NSString *unitId;

/// Initialize an FABiddingRequestParameter object
/// @param unitId unitId
- (instancetype)initWithUnitId:(nonnull NSString *)unitId NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
