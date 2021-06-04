//
//  TCWeakMutableArray.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>

/**
 *  All operation seems like NSMutableArray
 *  @note:
 *      container don't retain obj
 *      can't insert nil obj
 *      无效对象(即没有被外部持有的对象)也是占位的，此时访问相应的索引会获得nil(数组里是NSNull)。另外所有对索引的操作要算上无效对象
 *      [cleanInvalidObj]可以清空所有无效对象
 *
 */

NS_ASSUME_NONNULL_BEGIN

@interface TCWeakMutableArray : NSObject
#pragma mark - init
+ (instancetype)array;
+ (instancetype)arrayWithArray:(NSArray *)array;

- (instancetype)init;
- (instancetype)initWithCapacity:(NSUInteger)numItems;
- (instancetype)initWithArray:(NSArray*)array;

#pragma mark - add
- (void)setArray:(NSArray*)otherArray;
- (void)addObject:(id)anObject;
- (void)addObjectsFromArray:(NSArray*)otherArray;
- (void)insertObject:(id)anObject atIndex:(NSUInteger)index;
- (void)insertObjects:(NSArray*)objects atIndexes:(NSIndexSet*)indexes;

#pragma mark - remove
- (void)removeLastObject;
- (void)removeObjectAtIndex:(NSUInteger)index;
- (void)removeAllObjects;
- (void)removeObject:(id)anObject;
- (void)removeObjectsInArray:(NSArray *)otherArray;
- (void)removeObjectsInRange:(NSRange)range;
- (void)removeObjectsAtIndexes:(NSIndexSet *)indexes;
- (void)cleanInvalidObj;

#pragma mark - chage
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(id)anObject;
- (void)exchangeObjectAtIndex:(NSUInteger)idx1 withObjectAtIndex:(NSUInteger)idx2;
- (void)replaceObjectsAtIndexes:(NSIndexSet*)indexes withObjects:(NSArray *)objects;

#pragma mark - accessor
@property(readonly) NSUInteger count;
- (BOOL)containsObject:(id)anObject;
-(id)objectAtIndex:(NSUInteger)index;
-(NSArray*)allItems;
@end

NS_ASSUME_NONNULL_END
