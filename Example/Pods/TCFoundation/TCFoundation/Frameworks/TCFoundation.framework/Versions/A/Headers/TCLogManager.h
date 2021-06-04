//
//  TCLogManager.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/16.
//

/**
 * 规则：
 * 1. 启动以及后每隔一段间隔定时检查文件
 * 2. 检查文件大小超过quota会自动换新文件(会有一定时间延迟)
 * 3. 检查到文件创建日期超过RecycleInterval会将其清除
 * 4. 超过log文件最大数量，删除掉先创建的
 * 5. 按日期打文件
 */

#import <Foundation/Foundation.h>
#import <TCUtil/TCUtilMacro.h>
#import "TCLogger.h"
#import "TCLogModel.h"
#import "TCLoggerHookerProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface TCLogManager : NSObject
TCSingletonInterface(TCLogManager)

//  我们可以把Log拦截下来，用自己的方式打印
//  要注意的是日志可能从各个线程打印，所以要保护好线程
@property(weak, nullable)id<TCLoggerHookerProtocol> hooker;

#pragma mark ------------------------------- Info -------------------------------
+(nonnull NSString*)logDir;
+(nonnull NSMutableArray*)allLogFiles;
+(nonnull NSMutableArray*)logAtDayOfDate:(nonnull NSDate*)date;

#pragma mark ------------------------------- life -------------------------------
-(nonnull id)init;

#pragma mark ------------------------------- config writer -------------------------------
-(BOOL)registerCustomLogModel:(nonnull TCLogModel*)model;
-(BOOL)unregisterCustomLogModelWithLevel:(nonnull NSString*)level;
-(BOOL)setLogFileQuota:(unsigned long long)quota;
-(BOOL)setLogMaxNumberOfFiles:(NSUInteger)count;
-(BOOL)setLogRecycleInterval:(NSTimeInterval)interval;
-(BOOL)setMode:(TCLogMode)mode level:(nonnull NSString*)level;
-(BOOL)setConcernModules:(nullable NSArray<NSString*>*)modules level:(nonnull NSString*)level;
-(BOOL)addConcernModules:(nullable NSArray<NSString*>*)modules level:(nonnull NSString*)level;
-(BOOL)setConcernFiles:(nullable NSArray<NSString*>*)concernFiles level:(nonnull NSString*)level;
-(BOOL)addConcernFiles:(nullable NSArray<NSString*>*)concernFiles level:(nonnull NSString*)level;
-(BOOL)setConcernThreads:(nullable NSArray<NSString*>*)concernThreads level:(nonnull NSString*)level;
-(BOOL)addConcernThreads:(nullable NSArray<NSString*>*)concernThreads level:(nonnull NSString*)level;

#pragma mark ------------------------------- config accessor -------------------------------
-(NSInteger)logModeWithLevel:(nonnull NSString*)level;

#pragma mark ------------------------------- log -------------------------------
-(void)logWithLevel:(nonnull NSString*)level
             module:(nullable NSString*)module
       codeFilePath:(nonnull const char*)path
               line:(int)line
            funDesc:(nonnull const char*)fun
               info:(nullable NSString*)fmtStr,...;

-(nullable NSString*)logStringWithLevel:(nonnull NSString*)level
                                 module:(nullable NSString*)module
                           codeFilePath:(nonnull const char*)path
                                   line:(int)line
                                funDesc:(nonnull const char*)fun
                                   info:(nonnull NSString*)fmtStr,...;

-(nullable NSString*)currentLogPath;

#pragma mark ------------------------------- special -------------------------------
-(void)flushLog;
-(void)dumpLogFile2MemoryLimted:(unsigned long long)maxBytes complete:(nonnull void(^)(NSString*_Nullable rst))cb;

#define TCQuickLog(level, fmt, ...)         [[TCLogManager shareInstance] logWithLevel:level module:nil codeFilePath:__FILE__ line:__LINE__ funDesc:__PRETTY_FUNCTION__ info:fmt,##__VA_ARGS__]
#define TCQuickLogV2(level, m, fmt, ...)    [[TCLogManager shareInstance] logWithLevel:level module:m codeFilePath:__FILE__ line:__LINE__ funDesc:__PRETTY_FUNCTION__ info:fmt,##__VA_ARGS__]
#define TCLogInfo(level, m, fmt, ...)       [[TCLogManager shareInstance] logStringWithLevel:level module:m codeFilePath:__FILE__ line:__LINE__ funDesc:__PRETTY_FUNCTION__ info:fmt,##__VA_ARGS__]
@end

NS_ASSUME_NONNULL_END
