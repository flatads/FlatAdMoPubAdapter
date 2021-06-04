//
//  TCLogger.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/16.
//

/**
 说明： 该文件是简单的日志接口；更多配置及操作查阅TCLoggerManger
 */

#import <Foundation/Foundation.h>
#import "TCLogManager.h"

#ifndef TCLogger_h
#define TCLogger_h

/**
 * 简单的打异步log接口(写文件异步，打日志同步)；不提供模块名的话用文件名代替
 */
#define TCErrorLog(fmt, ...)            TCQuickLog(TCLogLevel_Error, fmt, ##__VA_ARGS__)
#define TCWarningLog(fmt, ...)          TCQuickLog(TCLogLevel_Warning, fmt, ##__VA_ARGS__)
#define TCInfoLog(fmt, ...)             TCQuickLog(TCLogLevel_Info, fmt, ##__VA_ARGS__)
#define TCDebugLog(fmt, ...)            TCQuickLog(TCLogLevel_Debug, fmt, ##__VA_ARGS__)
#define TCVerboseLog(fmt, ...)          TCQuickLog(TCLogLevel_Verbose, fmt, ##__VA_ARGS__)
#define TCCustomLog(level ,fmt, ...)    TCQuickLog(level, fmt, ##__VA_ARGS__)

#define TCErrorLogV2(module, fmt, ...)              TCQuickLogV2(TCLogLevel_Error, module, fmt, ##__VA_ARGS__)
#define TCWarningLogV2(module, fmt, ...)            TCQuickLogV2(TCLogLevel_Warning, module, fmt, ##__VA_ARGS__)
#define TCInfoLogV2(module, fmt, ...)               TCQuickLogV2(TCLogLevel_Info, module, fmt, ##__VA_ARGS__)
#define TCDebugLogV2(module, fmt, ...)              TCQuickLogV2(TCLogLevel_Debug, module, fmt, ##__VA_ARGS__)
#define TCVerboseLogV2(module,fmt, ...)             TCQuickLogV2(TCLogLevel_Verbose, module, fmt, ##__VA_ARGS__)
#define TCCustomLogV2(module, level ,fmt, ...)      TCQuickLogV2(level, module, fmt, ##__VA_ARGS__)

/**
 * 辅助组织log信息，不做任何操作
 */
#define TCLoggerInfo(log_level, module, fmt, ...)    TCLogInfo(log_level, module, fmt, ##__VA_ARGS__)

/**
 *  OSX, default ~/Library/TCLogs/
 *  IOS, default [NSDocumentDirectory][NSUserDomainMask]/TCLogs
 */
#define TCLoggerDir                                   [TCLogManager logDir]

#endif /* TCLogger_h */
