//
//  TCArrayProtocol.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#pragma mark ------------------------ TCArraySortProtocol ------------------------
@protocol TCArraySortProtocol <NSObject>
- (NSArray*)reversedArray;
- (NSArray*)sortedArray;
- (NSArray*)caseInsensitiveSortedArray;
@end

@protocol TCMutableArraySortProtocol <NSObject>
- (void)reverse;
@end

#pragma mark ------------------------ TCArraySetProtocol ------------------------
@protocol TCArraySetProtocol <NSObject>
- (NSArray*)uniqueArray;
- (NSArray*)unionWithArray:(NSArray*)anArray;
- (NSArray*)intersectionWithArray:(NSArray*)anArray;
- (NSArray*)differenceWithArray:(NSArray*)anArray;
@end

#pragma mark ------------------------ TCMutableArraySafeProtocol ------------------------
@protocol TCArrayCheckProtocol <NSObject>
-(BOOL)isItemOnlyContainType:(Class)type;
@end

#pragma mark ------------------------ TCMutableArraySafeProtocol ------------------------
@protocol TCMutableArraySafeProtocol <NSObject>
/**
 *  If index out of range , return false
 *  If object==nil, insert nullObj instead
 */
-(BOOL)safeInsertObject:(id)object atIndex:(NSInteger)index;
@end
