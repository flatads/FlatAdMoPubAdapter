//
//  TCLoggerHookerProtocol.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/16.
//

#import <Foundation/Foundation.h>

@protocol TCLoggerHookerProtocol <NSObject>

/**
 
 @param level 日志等级
 @param module 模块
 @param path 文件名
 @param line 代码行
 @param fun 函数名
 @param info 信息
 */
-(void)logWithLevel:(nonnull NSString*)level
             module:(nullable NSString*)module
       codeFilePath:(nonnull const char*)path
               line:(int)line
            funDesc:(nonnull const char*)fun
               info:(nullable NSString*)info;
@end
