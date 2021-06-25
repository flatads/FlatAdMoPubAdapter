//
//  FABiddingRequest.h
//  FlatAds_sdk
//
//  Created by chenwenhao on 2021/6/7.
//  Copyright © 2021 FlatAds. All rights reserved.
//

#import "FABiddingResponse.h"

#import "FABiddingRequestParameter.h"

NS_ASSUME_NONNULL_BEGIN

@interface FABiddingRequest : NSObject

/// Get Flat Ad Bid for current ad unit
/// You need to construct an FABiddingRequestParameter object or his subclass object.
/// @param requestParameter requestParameter
/// @param completionHandler completionHandler
+ (void)getBidWithRequestParameter:(nonnull __kindof FABiddingRequestParameter *)requestParameter
                completionHandler:(void(^)(FABiddingResponse *bidResponse))completionHandler;

@end

NS_ASSUME_NONNULL_END
