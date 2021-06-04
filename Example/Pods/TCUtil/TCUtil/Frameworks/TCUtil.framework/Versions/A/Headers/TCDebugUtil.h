//
//  TCDebugUtil.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/11.
//

#import <Foundation/Foundation.h>
#import "TCDebugTime.h"

NS_ASSUME_NONNULL_BEGIN

@interface TCDebugUtil : NSObject
/**
 *  calc spent of segment
 *  @param segment block to calc
 */
+(TCDebugTime*)timeSpentForSegment:(dispatch_block_t)segment;

/**
 *  get current time
 *  @note 返回的是距离1970的时间，且精确到us；外面可以直接用其创建NSDate
 */
+(TCDebugTime*)getCurrentTime;

/**
 *  print all concern information of obj(TODO - check weak prop)
 *  auto expand dict+set+array and concerned obj
 */
+(id)descriptionWithObj:(id)obj concernClasses:(NSSet*)classes;
@end

NS_ASSUME_NONNULL_END
