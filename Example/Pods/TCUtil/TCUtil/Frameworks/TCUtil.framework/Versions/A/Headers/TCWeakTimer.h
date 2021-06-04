//
//  TCWeakTimer.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TCWeakTimer : NSObject
// automatically start
+(TCWeakTimer*)scheduledTimerWithTimeInterval:(NSTimeInterval)ti target:(id)aTarget selector:(SEL)aSelector userInfo:(id)userInfo repeats:(BOOL)yesOrNo;

// Create timer
+(TCWeakTimer*)timerWithTimeInterval:(NSTimeInterval)ti target:(id)aTarget selector:(SEL)aSelector userInfo:(id)userInfo repeats:(BOOL)yesOrNo;
-(BOOL)addToRunloop:(NSRunLoop*)runloop forMode:(NSString*)mode;

// accessor
-(id)userInfo;

// TCWeakTimer only can be released after invalidate
-(void)invalidate;
@end

NS_ASSUME_NONNULL_END
