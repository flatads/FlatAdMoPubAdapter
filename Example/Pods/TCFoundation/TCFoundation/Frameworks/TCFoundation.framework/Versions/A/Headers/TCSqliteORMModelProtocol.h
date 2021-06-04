//
//  TCSqliteORMModelProtocol.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/16.
//

#import <Foundation/Foundation.h>

// 这串ID用于保存时分割主键(主键的所有值不要包含该串)
#define TCSqliteORMModel_PrimaryKey_Spliter @"##pk_boundary##"

@class TCSqliteORMModel;
@protocol TCSqliteORMModelProtocol <NSObject>
#pragma mark - ----------------------- update | insert -----------------------
/**
 *  create or update data to db(u can do some job before or after model update to db by override it)
 */
-(BOOL)updateToDB;

/**
 *  create or update models to db
 *
 *  @param models models to save
 *
 */
+(nullable NSArray<TCSqliteORMModel*>*)updateToDBWithModels:(nullable NSArray<TCSqliteORMModel*>*)models;

#pragma mark ----------------------- delete -----------------------

/**
 *  Delete self from db
 *
 */
-(BOOL)deleteModelInDB;

/**
 *  delete all models in table
 */
+(void)deleteAllModelsInDB;

/**
 *  delete model by primary key's values for [self class]'s table
 *
 *  @param pkvs primary key's values for [self class]'s table
 *
 */
+(BOOL)deleteModelWithPkvs:(nonnull NSArray<NSString*>*)pkvs;

/**
 *  delete models
 */
+(void)deleteModelsInDB:(nonnull NSArray<TCSqliteORMModel*>*)models;

/**
 *  delete models by condition for for [self class]'s table
 *
 *  @param where sql where codition
 *
 */
+(BOOL)deleteModelsInDBWithWhere:(nullable NSString*)where;


#pragma mark ----------------------- query -----------------------

/**
 *  query model by pkvs in [self class]'s table
 *
 *  @param pkvs must match pkvs's count and order
 *
 *  @return first model match codition of this class
 */

+(nullable id<TCSqliteORMModelProtocol>)queryModelWithPrimaryKeyValues:(nonnull NSArray<NSString*>*)pkvs;

/**
 *  query model by codition in [self class]'s table
 *
 *  @param where   sql where
 *  @param orderBy sql orderby
 *
 *  @return first model match codition of this class
 */
+(nullable id<TCSqliteORMModelProtocol>)queryModelWithWhere:(nullable NSString*)where orderBy:(nullable NSString*)orderBy;

/**
 *  query models by codition in [self class]'s table
 *
 *  @param pkvsList @[pkvs], pkvs must match pkvs's count and order
 *
 *  @return all models match codition
 */
+(nullable NSArray<TCSqliteORMModel*>*)queryModelWithPrimaryKeyValuesList:(nonnull NSArray*)pkvsList;

/**
 *  query models by codition for [self class]'s table
 *
 *  @param where   sql where
 *  @param orderBy sql orderby
 *  @param offset  sql offset
 *  @param count   sql count, if 0, ignore it and offset
 *
 *  @return all models match codition of this class
 */
+(nullable NSArray<TCSqliteORMModel*>*)queryModelsWithWhere:(nullable NSString*)where orderBy:(nullable NSString*)orderBy offset:(int)offset count:(int)count;

/**
 *  Get all model in table for [self class]'s table
 */
+(nullable NSArray<TCSqliteORMModel*>*)allModels;

/**
 *  Get all model's pkvs in [self class]'s table
 */
+(nullable NSArray<NSArray*>*)allPkvs;
@end

@protocol TCSqliteORMModelListProtocol <NSObject>
#pragma mark ------------------------ insert -----------------------
+(void)insertToList:(nonnull NSString*)listKey models:(nullable NSArray<TCSqliteORMModel*>*)models atIndex:(NSInteger)index;
+(void)appendToList:(nonnull NSString*)listKey models:(nullable NSArray<TCSqliteORMModel*>*)models;

#pragma mark ----------------------- query -----------------------
+(NSUInteger)modelCountOfList:(nonnull NSString*)listKey;
+(nullable id<TCSqliteORMModelProtocol>)modelOfList:(nonnull NSString*)listKey atIndex:(NSUInteger)index;
+(nullable id<TCSqliteORMModelProtocol>)lastModelOfListKey:(nonnull NSString*)listKey;
+(nullable NSArray<TCSqliteORMModel*>*)allModelsOfList:(nonnull NSString*)listKey;

#pragma mark ----------------------- delete -----------------------
+(BOOL)deleteAllModelsOfList:(nonnull NSString*)listKey;
+(BOOL)deleteModelOfList:(nonnull NSString*)listKey atIndex:(NSUInteger)index;
+(BOOL)deleteModelsOfList:(nonnull NSString*)listKey fromIndex:(NSUInteger)index;
+(BOOL)deleteModelsOfList:(nonnull NSString*)listKey toIndex:(NSUInteger)index;
+(BOOL)deleteModelsOfList:(nonnull NSString*)listKey range:(NSRange)range;
@end
