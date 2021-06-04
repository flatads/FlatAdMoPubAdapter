//
//  TCLogMacro.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/16.
//

#ifndef TCLogMacro_h
#define TCLogMacro_h

/// how to log
typedef enum : NSInteger
{
    TCLogMode_None              = 0,
    TCLogMode_ReleaseConsole    = 1,            // log 2 console in release
    TCLogMode_DebugConsole      = 1 << 1,       // log 2 console in debug
    TCLogMode_ReleaseFile       = 1 << 2,       // log 2 file in release
    TCLogMode_DebugFile         = 1 << 3,       // log 2 file in debug
    TCLogMode_All = TCLogMode_ReleaseConsole | TCLogMode_DebugConsole | TCLogMode_ReleaseFile | TCLogMode_DebugFile,
}TCLogMode;


/// default log level
#define TCLogLevel_Error        @"E"          // TCLogMode_All
#define TCLogLevel_Warning      @"W"          // TCLogMode_All
#define TCLogLevel_Info         @"I"          // TCLogMode_DebugFile
#define TCLogLevel_Debug        @"D"          // TCLogMode_DebugFile
#define TCLogLevel_Verbose      @"V"          // TCLogMode_DebugFile

// clean logic
#define TCLoggerDefaultRecyclePeriod            (7 * 24 * 60 * 60)
#define TCLoggerFileQuota                       (9 * 1024 * 1024)
#define TCLoggerCheckCleanInterval              60
#define TCLoggerDefaultMaxNumberOfFiles         6

// Format
#define TCLogManagerFileFmt                     @"[%@][%@][%@]  %@[%@]%s[%i]\n"       // [Time][Level][Module|File]Info[Thread]Fun[Line]
#define TCLogManagerConciseFmt                  @"[%@][%@] %@\n"                       // [Level][Module|File]info

#endif /* TCLogMacro_h */
