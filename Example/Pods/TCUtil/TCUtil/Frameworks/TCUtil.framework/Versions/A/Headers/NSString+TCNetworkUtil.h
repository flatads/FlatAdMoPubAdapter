//
//  NSString+TCNetworkUtil.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (TCNetworkUtil)
/** Enocde url without reserved */
-(NSString*)urlEncodedStrExceptReserved;

/** Enocde url*/
-(NSString*)urlEncodedStr;

/** Decode url*/
-(NSString*)urlDecodedStr;
@end

NS_ASSUME_NONNULL_END
