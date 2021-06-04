//
//  TCWeakDelegate.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TCWeakDelegate : NSObject
@property(nonatomic, weak)id delegate;
-(id)initWithDelegate:(id)delegate;
@end

NS_ASSUME_NONNULL_END
