//
//  NSError+TCUtil.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSError (TCUtil)
+(id)errorWithDomain:(NSString*)domain code:(NSInteger)code msg:(NSString*)msg;
@end

NS_ASSUME_NONNULL_END
