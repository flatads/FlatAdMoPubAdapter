//
//  NSObject+TCSelector.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (TCSelector)
-(void)performSelectorOnMainThread:(SEL)selector withObject:(id)arg1 withObject:(id)arg2 waitUntilDone:(BOOL)wait;
-(void)performSelectorOnMainThread:(SEL)selector withObject:(id)arg1 withObject:(id)arg2 withObject:(id)arg3 waitUntilDone:(BOOL)wait;
-(id)performSelector:(SEL)selector withObject:(id)arg1 withObject:(id)arg2 withObject:(id)arg3;
-(id)performSelector:(SEL)selector withObject:(id)arg1 withObject:(id)arg2 withObject:(id)arg3 withObject:(id)arg4;
@end

NS_ASSUME_NONNULL_END
