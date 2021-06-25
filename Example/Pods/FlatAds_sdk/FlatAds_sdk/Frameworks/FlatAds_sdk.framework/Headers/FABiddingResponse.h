//
//  FABiddingResponse.h
//  FlatAds_sdk
//
//  Created by chenwenhao on 2021/6/7.
//  Copyright © 2021 FlatAds. All rights reserved.
//

#import "FABiddingHeader.h"

NS_ASSUME_NONNULL_BEGIN

@interface FABiddingResponse : NSObject

@property (nonatomic, readonly, assign) BOOL success;

@property (nonatomic, readonly, strong) NSError *error;

@property (nonatomic, readonly, assign) double price;

/// Default is USD
@property (nonatomic, readonly, copy) NSString *currency;

/// You will need to use this value when you request the ads
@property (nonatomic, readonly, copy) NSString *bidToken;

- (void)notifyWin;

- (void)notifyLoss:(FABidLossedReasonCode)reasonCode;

@end

NS_ASSUME_NONNULL_END
