//
//  TCDebugTime.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TCDebugTime : NSObject<NSCopying>
#pragma mark - create
+(TCDebugTime*)debugTimeWithSecond:(uint32_t)s ms:(uint32_t)ms us:(uint32_t)us;
+(TCDebugTime*)debugTimeWithUs:(UInt64)us;

#pragma mark - op
/*************************************************
 *  substract|add time
 *
 *  @return self
 *************************************************/
-(TCDebugTime*)substractTime:(TCDebugTime*)time;
-(TCDebugTime*)addTime:(TCDebugTime*)time;

#pragma mark - accessor
-(UInt64)secondFormatValue;
-(UInt64)msFormatValue;
-(UInt64)usFormatValue;
-(NSString*)description;
@end

NS_ASSUME_NONNULL_END
