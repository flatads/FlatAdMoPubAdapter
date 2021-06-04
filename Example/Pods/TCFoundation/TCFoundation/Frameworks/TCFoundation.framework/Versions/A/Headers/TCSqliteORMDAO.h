//
//  TCSqliteORMDAO.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/16.
//

/**************************************************************************************
 * Feature：
 *      线程安全：同步 and 异步
 *      数据缓存
 *
 * 说明：
 *      1. 写DB会先写到缓存然后直接返回，同时异步写DB
 *      2. 查询操作命中缓存直接返回，否则同步查询DB
 *      3. 如果使用DAO则不要直接调用model的增删查改操作
 *
 **************************************************************************************/

#import <TCUtil/TCUtilMacro.h>
#import "TCSqliteORMModel.h"

NS_ASSUME_NONNULL_BEGIN

#define TCSqliteORMDAO_LOW_PERFORMANCE_FLAG     /* 有此标记的函数性能不高，且适用场景不多，尽量少用；如果使用，外部自己缓存好... */
#define TCSqliteORMDAO_R_PERFORMANCE_FLAG       /* 有此标记的函数为读操作，性能本身还可以，加上缓存优化会更快。但也有可能会访问DB，一旦访问DB就会排队，有可能被前面的操作阻塞 */
#define TCSqliteORMDAO_W_PERFORMANCE_FLAG       /* 有此标记的函数为写操作，不会阻塞操作，可以放心同步|异步调用。但是会在后台给DB增加任务 */

@interface TCSqliteORMDAO : NSObject
TCSingletonInterface(TCSqliteORMDAO)

#pragma mark ----------------------- Model -----------------------

#pragma mark update | insert
-(BOOL)updateToDBWithModel:(nonnull TCSqliteORMModel*)model                                                             TCSqliteORMDAO_W_PERFORMANCE_FLAG;
-(nullable NSArray<TCSqliteORMModel*>*)updateToDBWithModels:(nullable NSArray<TCSqliteORMModel*>*)models                TCSqliteORMDAO_W_PERFORMANCE_FLAG;

#pragma mark query
-(nullable TCSqliteORMModel*)queryModelWithPrimaryKeyValues:(nonnull NSArray<NSString*>*)pkvs cls:(nonnull Class)cls    TCSqliteORMDAO_R_PERFORMANCE_FLAG;
-(nullable NSArray<TCSqliteORMModel*>*)allModelsForClass:(nonnull Class)cls                                             TCSqliteORMDAO_LOW_PERFORMANCE_FLAG;

#pragma mark delete
-(BOOL)deleteAllModelsInDBForClass:(nonnull Class)cls                                                                   TCSqliteORMDAO_W_PERFORMANCE_FLAG;
-(BOOL)deleteModel:(nonnull TCSqliteORMModel*)model                                                                     TCSqliteORMDAO_W_PERFORMANCE_FLAG;
-(BOOL)deleteModelWithPkvs:(nonnull NSArray<NSString*>*)pkvs cls:(nonnull Class)cls                                     TCSqliteORMDAO_W_PERFORMANCE_FLAG;
-(void)deleteModelsInDB:(nonnull NSArray<TCSqliteORMModel*>*)models                                                     TCSqliteORMDAO_W_PERFORMANCE_FLAG;


#pragma mark ----------------------- List -----------------------
#pragma mark insert
-(nullable NSArray<__kindof TCSqliteORMModel*>*)insertToList:(nonnull NSString*)listKey
                                                      models:(nullable NSArray<__kindof TCSqliteORMModel*>*)models
                                                     atIndex:(NSInteger)index                                           TCSqliteORMDAO_W_PERFORMANCE_FLAG;

-(nullable NSArray<__kindof TCSqliteORMModel*>*)appendToList:(nonnull NSString*)listKey
                                                      models:(nullable NSArray<__kindof TCSqliteORMModel*>*)models      TCSqliteORMDAO_W_PERFORMANCE_FLAG;

#pragma mark query
-(NSUInteger)modelCountOfList:(nonnull NSString*)listKey                                                                TCSqliteORMDAO_R_PERFORMANCE_FLAG;
-(nullable NSArray<__kindof TCSqliteORMModel*>*)allModelsOfList:(nonnull NSString*)listKey                              TCSqliteORMDAO_R_PERFORMANCE_FLAG;

#pragma mark delete
-(BOOL)deleteAllModelsOfList:(nonnull NSString*)listKey;
-(BOOL)deleteModelOfList:(nonnull NSString*)listKey atIndex:(NSUInteger)index                                           TCSqliteORMDAO_W_PERFORMANCE_FLAG;
-(BOOL)deleteModelsOfList:(nonnull NSString*)listKey fromIndex:(NSUInteger)index                                        TCSqliteORMDAO_W_PERFORMANCE_FLAG;
-(BOOL)deleteModelsOfList:(nonnull NSString*)listKey toIndex:(NSUInteger)index                                          TCSqliteORMDAO_W_PERFORMANCE_FLAG;
-(BOOL)deleteModelsOfList:(nonnull NSString*)listKey range:(NSRange)range                                               TCSqliteORMDAO_W_PERFORMANCE_FLAG;


#pragma mark ----------------------- Thread -----------------------
/**
 *
 *  @param task         u can perform some fun in pragma - List| Model here
 *  @param callback     callback, u can't perform any fun in pragma - List| Model synchronized here
 *
 */
-(void)asynPerformTask:(nullable dispatch_block_t)task callback:(nullable dispatch_block_t)callback;

#pragma mark ----------------------- Flush -----------------------
/**
 *
 *  @note u can call flushDB while app to be killed
 */
-(void)flushDB;
@end

NS_ASSUME_NONNULL_END
