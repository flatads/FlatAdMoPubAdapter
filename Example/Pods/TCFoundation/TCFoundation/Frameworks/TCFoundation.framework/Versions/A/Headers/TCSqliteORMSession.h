//
//  TCSqliteORMSession.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/16.
//

/**
 * 一次操作对应一个session，在一个session内遇到同样的的数据(即相同类且主键值相同)只会存取一次
 * 注意： sessionID是可以唯一识别出Model的串，一般情况下不需要外面维护session信息
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TCSqliteORMSession : NSObject
@property(readonly, nonnull)NSString* sessionID;

#pragma mark ---------------------------- session info ----------------------------
@property(readonly, nonnull)NSMutableDictionary* sessionInfo;           // 存储已经处理过的Model(不包括删除的)
//@property(readonly, nonnull)NSMutableDictionary* queried;
//@property(readonly, nonnull)NSMutableDictionary* updated;
//@property(readonly, nonnull)NSMutableDictionary* listInfos;

+(nullable NSString*)sessionInfoIDWithPkvs:(nonnull NSArray*)pkvs cls:(nonnull Class)cls;
+(nullable NSString*)classNameFromSessionInfoID:(nonnull NSString*)sessionInfoID;
+(nullable NSArray*)pkvsFromSessionInfoID:(nonnull NSString*)sessionInfoID;

#pragma mark ---------------------------- write transaction ----------------------------
@property(readonly, nonnull)NSMutableArray* writeOperations;            // 存储需要处理的写事务
-(void)beginWriteTransaction;
-(void)endWriteTransaction;
@end

NS_ASSUME_NONNULL_END
