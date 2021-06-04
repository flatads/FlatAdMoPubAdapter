//
//  NSDictionary+TCContainer.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>
#import "TCDictionaryProtocol.h"
#import "TCContainerProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface NSDictionary (TCContainer)<TCDictionaryAccessorProtocol, TCDictionarySafeExtensionProtocol, TCContainerDeepCopyProtocol>

@end

NS_ASSUME_NONNULL_END
