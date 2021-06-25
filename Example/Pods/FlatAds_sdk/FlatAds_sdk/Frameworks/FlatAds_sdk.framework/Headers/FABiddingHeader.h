//
//  FABiddingHeader.h
//  FlatAds_sdk
//
//  Created by chenwenhao on 2021/6/7.
//  Copyright © 2021 FlatAds. All rights reserved.
//

#ifndef FABiddingHeader_h
#define FABiddingHeader_h

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, FABidLossedReasonCode) {
    FABidLossedReasonCodeLowPrice        = 1,
    FABidLossedReasonCodeBidTimeout      = 2,
    FABidLossedReasonCodeWonNotShow      = 3,
};

#endif /* FABiddingHeader_h */
