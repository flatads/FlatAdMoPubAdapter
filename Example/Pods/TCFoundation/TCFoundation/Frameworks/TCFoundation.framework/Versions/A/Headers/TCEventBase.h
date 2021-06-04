//
//  TCEventBase.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/16.
//

/**
 * 消息的封包解包逻辑应该都放于该类，避免到处都是类似逻辑
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TCEventBase : NSObject
@property(strong) NSString* message;                // 消息名称
@property(strong) id sender;                        // 消息的发起者
@end

NS_ASSUME_NONNULL_END
