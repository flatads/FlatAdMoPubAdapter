//
//  TCSqliteORMSessionProtocol.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/16.
//

/**
 * 这里的接口与TCSqliteORMModelProtocol对应，供内部使用
 */

#import <Foundation/Foundation.h>

@class TCSqliteORMSession;
@class TCSqliteORMModel;

@protocol TCSqliteORMSessionProtocol <NSObject>
#pragma mark - ----------------------- update | insert -----------------------
-(BOOL)updateToDBWithSession:(nullable TCSqliteORMSession*)session;
+(nullable NSArray<TCSqliteORMModel*>*)updateToDBWithModels:(nullable NSArray<TCSqliteORMModel*>*)models session:(nullable TCSqliteORMSession*)session;

#pragma mark ----------------------- delete -----------------------
-(BOOL)deleteModelInDBWithSession:(nullable TCSqliteORMSession*)session;
+(void)deleteAllModelsInDBWithSession:(nullable TCSqliteORMSession*)session;
+(BOOL)deleteModelWithPkvs:(nonnull NSArray<NSString*>*)pkvs session:(nullable TCSqliteORMSession*)session;

+(void)deleteModelsInDB:(nonnull NSArray<TCSqliteORMModel*>*)models session:(nullable TCSqliteORMSession*)session;
+(BOOL)deleteModelsInDBWithWhere:(nullable NSString*)where session:(nullable TCSqliteORMSession*)session;


#pragma mark ----------------------- query -----------------------
+(nullable id<TCSqliteORMModelProtocol>)queryModelWithPrimaryKeyValues:(nonnull NSArray<NSString*>*)pkvs session:(nullable TCSqliteORMSession*)session;
+(nullable id<TCSqliteORMModelProtocol>)queryModelWithWhere:(nullable NSString*)where orderBy:(nullable NSString*)orderBy session:(nullable TCSqliteORMSession*)session;
+(nullable NSArray<TCSqliteORMModel*>*)queryModelWithPrimaryKeyValuesList:(nonnull NSArray*)pkvsList session:(nullable TCSqliteORMSession*)session;
+(nullable NSArray<TCSqliteORMModel*>*)queryModelsWithWhere:(nullable NSString*)where orderBy:(nullable NSString*)orderBy offset:(int)offset count:(int)count session:(nullable TCSqliteORMSession*)session;
+(nullable NSArray<TCSqliteORMModel*>*)allModelsWithSession:(nullable TCSqliteORMSession*)session;
@end


@protocol TCSqliteORMSessionListProtocol <NSObject>
#pragma mark ------------------------ insert -----------------------
+(void)insertToList:(nonnull NSString*)listKey models:(nullable NSArray<TCSqliteORMModel*>*)models atIndex:(NSInteger)index session:(nullable TCSqliteORMSession*)session;
+(void)appendToList:(nonnull NSString*)listKey models:(nullable NSArray<TCSqliteORMModel*>*)models session:(nullable TCSqliteORMSession*)session;

#pragma mark ----------------------- query -----------------------
+(NSUInteger)modelCountOfList:(nonnull NSString*)listKey session:(nullable TCSqliteORMSession*)session;
+(nullable id<TCSqliteORMModelProtocol>)modelOfList:(nonnull NSString*)listKey atIndex:(NSUInteger)index session:(nullable TCSqliteORMSession*)session;
+(nullable id<TCSqliteORMModelProtocol>)lastModelOfListKey:(nonnull NSString*)listKey session:(nullable TCSqliteORMSession*)session;
+(nullable NSArray<TCSqliteORMModel*>*)allModelsOfList:(nonnull NSString*)listKey session:(nullable TCSqliteORMSession*)session;


#pragma mark ----------------------- delete -----------------------
+(BOOL)deleteAllModelsOfList:(nonnull NSString*)listKey session:(nullable TCSqliteORMSession*)session;
+(BOOL)deleteModelOfList:(nonnull NSString*)listKey atIndex:(NSUInteger)index session:(nullable TCSqliteORMSession*)session;
+(BOOL)deleteModelsOfList:(nonnull NSString*)listKey fromIndex:(NSUInteger)index session:(nullable TCSqliteORMSession*)session;
+(BOOL)deleteModelsOfList:(nonnull NSString*)listKey toIndex:(NSUInteger)index session:(nullable TCSqliteORMSession*)session;
+(BOOL)deleteModelsOfList:(nonnull NSString*)listKey range:(NSRange)range session:(nullable TCSqliteORMSession*)session;
@end
