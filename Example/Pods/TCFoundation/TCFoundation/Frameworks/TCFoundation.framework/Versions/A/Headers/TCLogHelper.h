//
//  TCLogHelper.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TCLogHelper : NSObject
/**
 *  log dir
 */
+(NSString*)logDir;

/**
 *  get current log path
 *
 *  @param shouldChange mark the old file if full or out of date
 *
 */
+(NSString*)logPath:(BOOL)shouldChange;

/**
 *  read utf-8 data from log file
 */
+(NSString*)readDataStringFromPath:(NSString*)path bytesLimited:(unsigned long long)bytesLimited;


/**
 *  open append mode file
 */
+(FILE*)openFileInAppendModeWithPath:(NSString*)path;

/**
 *  apppend log to file
 */
+(unsigned long long)appendToFile:(FILE*)file log:(NSString*)log;

/**
 *  time formatter of log file name
 */
+(NSDateFormatter*)logFileDateFormatter;

/**
 *  time formatter of log prefix
 */
+(NSDateFormatter*)logDateFormatter;

/**
 *  check if two log have same day
 */
+(BOOL)isLogAtDate:(NSDate*)date haveSameDayWithDate:(NSDate*)date2;

/**
 *  get all files at have the same day of date
 */
+(NSMutableArray*)allLogFileAtDayOfDate:(NSDate*)date;

/**
 *  get all file name in dir
 */
+(NSMutableArray*)allFileNames;

/**
 *  delete old file if need
 */
+(void)deleteOldFilesWithReserved:(NSString*)reserved countLimted:(NSInteger)countLimted;
@end

NS_ASSUME_NONNULL_END
