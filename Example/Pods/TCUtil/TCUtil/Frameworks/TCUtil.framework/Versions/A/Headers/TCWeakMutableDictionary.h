//
//  TCWeakMutableDictionary.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>

/**
 *  All operation seems like NSMutableDictionary
 *  @note:
 *      container don't retain obj
 *      can't insert nil obj
 *      无效对象(即没有被外部持有的对象)也是占位的，此时访问相应的索引会获得nil。
 *      [cleanInvalidObj]可以清空所有无效对象
 *
 */

NS_ASSUME_NONNULL_BEGIN

@interface TCWeakMutableDictionary : NSObject
#pragma mark - init
- (instancetype)init;
- (instancetype)initWithCapacity:(NSUInteger)numItems;

+ (instancetype)dictionary;
+ (instancetype)dictionaryWithCapacity:(NSUInteger)numItems;
+ (instancetype)dictionaryWithObject:(id)object forKey:(id <NSCopying>)key;
+ (instancetype)dictionaryWithDictionary:(NSDictionary *)dict;

#pragma mark - add | change
- (void)setObject:(id)anObject forKey:(id <NSCopying>)aKey;
- (void)addEntriesFromDictionary:(NSDictionary*)otherDictionary;
- (void)setDictionary:(NSDictionary*)otherDictionary;

#pragma mark - remove
- (void)removeObjectForKey:(id)aKey;
- (void)removeAllObjects;
- (void)removeObjectsForKeys:(NSArray*)keyArray;
- (void)cleanInvalidObj;

#pragma mark - accessor
@property (readonly) NSUInteger count;
@property (readonly) NSArray* allKeys;
- (id)objectForKey:(id)aKey;
- (NSEnumerator *)keyEnumerator;
@end

NS_ASSUME_NONNULL_END
