//
//  NSObject+TCSwizzle.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/11.
//

/**
 * 常用于扩展的load方法中
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (TCSwizzle)
/**
 swizzle original instance method with block

 @param originalSelector original instance method
 @param block new block
 @param error error
 @return old implement(so that you can call old implement in block)
 */
+(IMP)tc_replaceInstanceMethodWithSelector:(SEL)originalSelector block:(id)block error:(NSError**)error;

/**
 swizzle original class method with block
 
 @param originalSelector original class method
 @param block new block
 @param error error
 @return old implement(so that you can call old implement in block)
 */
+(IMP)tc_replaceClassMethodWithSelector:(SEL)originalSelector block:(id)block error:(NSError**)error;

/**
 swizzle original instance selector with new selector
 
 @param originalSelector original selctor
 @param swizzledSelector new selctor
 @param error error
 @return success or not
 */
+(BOOL)tc_exchangeInstanceMethodWithOriginalSelector:(SEL)originalSelector swizzledSelector:(SEL)swizzledSelector error:(NSError**)error;

/**
 swizzle original class method with new selector
 
 @param originalSelector original class selector
 @param swizzledSelector new class selector
 @param error error
 @return success or not
 */
+(BOOL)tc_exchangeClassMethodsWithOriginalSelector:(SEL)originalSelector swizzledSelector:(SEL)swizzledSelector error:(NSError**)error;
@end

NS_ASSUME_NONNULL_END
