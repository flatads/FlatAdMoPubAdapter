//
//  NSObject+TCBaseExt.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (TCBaseExt)
/** get address of obj */
-(NSString*)addressString;

/** a null object of NSObject Type */
+(NSObject*)nullObj;
@end

NS_ASSUME_NONNULL_END
