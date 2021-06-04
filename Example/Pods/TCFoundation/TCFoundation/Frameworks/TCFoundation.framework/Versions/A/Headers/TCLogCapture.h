//
//  TCLogCapture.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/16.
//

/**
 * 拦截系统输出
 */

#import <Foundation/Foundation.h>
#import <TCUtil/TCUtilMacro.h>

NS_ASSUME_NONNULL_BEGIN

@class TCLogCapture;
@protocol TCLogCaptureDelegate <NSObject>
-(void)logCapture:(TCLogCapture*)capture didReceiveLog:(NSString*)log;
@end

@interface TCLogCapture : NSObject
TCSingletonInterface(TCLogCapture)
@property(nonatomic, assign)BOOL enabled;
@property(nonatomic, weak, nullable)id<TCLogCaptureDelegate> del;
@end

NS_ASSUME_NONNULL_END
