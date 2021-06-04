//
//  TCVersionComparation.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define TCSYSTEM_VERSION_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:[NSString stringWithFormat:@"%.1f",v] options:NSNumericSearch] == NSOrderedSame)
#define TCSYSTEM_VERSION_GREATER_THAN(v) ([[[UIDevice currentDevice] systemVersion] compare:[NSString stringWithFormat:@"%.1f",v] options:NSNumericSearch] == NSOrderedDescending)
#define TCSYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:[NSString stringWithFormat:@"%.1f",v] options:NSNumericSearch] != NSOrderedAscending)
#define TCSYSTEM_VERSION_LESS_THAN(v) ([[[UIDevice currentDevice] systemVersion] compare:[NSString stringWithFormat:@"%.1f",v] options:NSNumericSearch] == NSOrderedAscending)
#define TCSYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:[NSString stringWithFormat:@"%.1f",v] options:NSNumericSearch] != NSOrderedDescending)

@interface TCVersionComparation : NSObject
/**
 * 字符串比较，效率较低
 * ver1,ver2任意一个为nil，则返回ordersame
 * ver1,ver2任意一个为包括数字和.之外的字符，则返回ordersame
 * ver1,ver2长度不同时，默认用0补齐
 */
+(NSComparisonResult)stringCompare:(NSString*)ver1 ver2:(NSString*)ver2;

/**
 * 字符串转换float比较，效率较高，仅对前两位有效
 * ver1,ver2任意一个为nil，则返回ordersame
 * 将string强制转换为float类型，仅对前两位版本号有效
 */
+(NSComparisonResult)stringToFloatQuickCompare:(NSString*)ver1 ver2:(NSString*)ver2;
@end

NS_ASSUME_NONNULL_END
