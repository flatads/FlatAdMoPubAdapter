//
//  TCWeakMutableSet.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>

/**
 *  All operation seems like NSMutableSet
 *  @note:
 *      container don't retain obj
 *      can't insert nil obj
 *      enumerate abandon invailed obj(obj without owner)
 *
 */

NS_ASSUME_NONNULL_BEGIN

@interface TCWeakMutableSet : NSObject
#pragma mark - init
- (instancetype)init;
- (instancetype)initWithArray:(NSArray *)array;
- (instancetype)initWithSet:(NSSet*)set;
- (instancetype)initWithObj:(id)obj;
- (instancetype)initWithCapacity:(NSUInteger)numItems;

+ (instancetype)set;
+ (instancetype)setWithCapacity:(NSUInteger)numItems;
+ (instancetype)setWithObject:(id)object;
+ (instancetype)setWithSet:(NSSet*)set;
+ (instancetype)setWithArray:(NSArray*)array;

#pragma mark - remove
- (void)removeObject:(id)object;
- (void)removeAllObjects;

#pragma mark - accessor
@property (readonly) NSUInteger count;          // Don't call this too frequent
- (void)enumerateObjectsUsingBlock:(void (^)(id obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(id obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);
- (BOOL)containsObject:(id)anObject;

#pragma mark - add | change
- (void)addObject:(id)object;
- (void)addObjectsFromArray:(NSArray*)array;
@end

NS_ASSUME_NONNULL_END
