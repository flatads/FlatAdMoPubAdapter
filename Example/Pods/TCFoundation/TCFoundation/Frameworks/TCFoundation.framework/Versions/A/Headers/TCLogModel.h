//
//  TCLogModel.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/16.
//

#import <Foundation/Foundation.h>
#import "TCLogMacro.h"

NS_ASSUME_NONNULL_BEGIN

@interface TCLogModel : NSObject
#pragma mark ------------------------------- property -------------------------------
@property(atomic, copy)         NSString* logLevel;                  // identifier
@property(atomic, assign)       NSInteger logMode;                   // indicate how to log
@property(atomic)               unsigned long long fileQuota;        // default - (50 * 1024 * 1024), max log size
@property(atomic, strong)       NSMutableArray* concernFiles;        // default - empty(all)
@property(atomic, strong)       NSMutableArray* concernModules;      // default - empty(all)
@property(atomic, strong)       NSMutableArray* concernThreads;      // default - empty(all)

-(instancetype)initWithLogLevel:(NSString*)level;
-(instancetype)initWithLogLevel:(NSString*)level logMode:(TCLogMode)mode logPath:(NSString*)logPath;
+(TCLogMode)defaultLogModeForLevel:(NSString*)level;

#pragma mark ------------------------------- NS_UNAVAILABLE -------------------------------
-(id)init NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
