//
//  TCDictionaryProtocol.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#pragma mark ------------------------ TCDictionaryAccessorProtocol ------------------------

@protocol TCDictionaryAccessorProtocol <NSObject>
#pragma mark check type value
/****************************************************
 * check value type of key
 ****************************************************/
-(BOOL)isKindOfStringWithKey:(id)key;
-(BOOL)isKindOfNumberWithKey:(id)key;

-(BOOL)isKindOfArrayWithKey:(id)key;
-(BOOL)isKindOfDictionaryWithKey:(id)key;

-(BOOL)isKindOfClass:(Class)aClass withKey:(id)key;
-(BOOL)isMemberOfClass:(Class)aClass withKey:(id)key;

#pragma mark get type value
/****************************************************
 * get value(with implict type) of key
 * if type not correct return nil
 * typically usage: parser JSON
 ****************************************************/
-(BOOL)boolValueForKey:(id)key;
-(BOOL)boolValueForKey:(id)key defaultValue:(BOOL)defaultValue;

-(float)floatValueForKey:(id)key;
-(float)floatValueForKey:(id)key defaultValue:(float)defaultValue;

-(double)doubleValueForKey:(id)key;
-(double)doubleValueForKey:(id)key defaultValue:(double)defaultValue;

-(int)intValueForKey:(id)key;
-(int)intValueForKey:(id)key defaultValue:(int)defaultValue;

-(unsigned int)unsignedIntValueForKey:(id)key;
-(unsigned int)unsignedIntValueForKey:(id)key defaultValue:(unsigned int)defaultValue;

-(long long)longLongValueForKey:(id)key;
-(long long)longLongValueForKey:(id)key defaultValue:(long long)defaultValue;

-(unsigned long long)unsignedLongLongValueForKey:(id)key;
-(unsigned long long)unsignedLongLongValueForKey:(id)key defaultValue:(unsigned long long)defaultValue;

-(NSInteger)integerValueForKey:(id)key;
-(NSInteger)integerValueForKey:(id)key defaultValue:(NSInteger)defaultValue;

-(NSUInteger)unsignedIntegerValueForKey:(id)key;
-(NSUInteger)unsignedIntegerValueForKey:(id)key defaultValue:(NSUInteger)defaultValue;

-(NSNumber*)numberValueForKey:(id)key;
-(NSNumber*)numberValueForKey:(id)key defaultValue:(NSNumber*)defaultValue;

-(NSString*)stringValueForKey:(id)key;
-(NSString*)stringValueForKey:(id)key defaultValue:(NSString*)defaultValue;

-(NSArray*)arrayValueForKey:(id)key;
-(NSArray*)arrayValueForKey:(id)key defaultValue:(NSArray*)defaultValue;

-(NSDictionary*)dictionaryValueForKey:(id)key;
-(NSDictionary*)dictionaryValueForKey:(id)key defaultValue:(NSDictionary*)defaultValue;
@end

#pragma mark ------------------------ TCDictionarySafeExtensionProtocol ------------------------
@protocol TCDictionarySafeExtensionProtocol <NSObject>
-(BOOL)tc_containsKey:(id)key;
@end

@protocol TCMutableDictionaryAccessorProtocol <NSObject>
/****************************************************
 * get mutable value(with implict type) of key
 * force means when type not correct or value is nil, it will assign with a new obj and return
 * not force means when type not correct or value is nil, it will return
 ****************************************************/
-(NSMutableArray*)mutableArrayWithKey:(id)key force:(BOOL)force;
-(NSMutableDictionary*)mutableDictWithKey:(id)key force:(BOOL)force;
-(NSMutableSet*)mutableSetWithKey:(id)key force:(BOOL)force;
@end
