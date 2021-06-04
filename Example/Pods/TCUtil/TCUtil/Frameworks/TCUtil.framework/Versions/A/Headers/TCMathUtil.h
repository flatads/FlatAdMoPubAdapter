//
//  TCMathUtil.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark ------------------------- Random -------------------------
// TODO：这里应该用C++的模板比较合理
@protocol TCMathUtilRandomProtocol<NSObject>
/** 获得两个int之间的随机值[v1, v2] */
+(int)randomIntBetweenV1:(int)value1 v2:(int)value2;

/** 获得两个NSInteger之间的随机值[v1, v2] */
+(NSInteger)randomIntegerBetweenV1:(NSInteger)value1 v2:(NSInteger)value2;

/** 获得两个float之间的随机值 */
+(float)randomFloatBetweenV1:(float)value1 v2:(float)value2;

/** 获得两个double之间的随机值 */
+(double)randomDoubleBetweenV1:(double)value1 v2:(double)value2;

/** 随机两个BOOL值 */
+(BOOL)randomBool;
@end

@interface TCMathUtil : NSObject<TCMathUtilRandomProtocol>
@end

NS_ASSUME_NONNULL_END
