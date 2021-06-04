//
//  NSArray+TCContainer.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>
#import "TCContainerProtocol.h"
#import "TCArrayProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface NSArray(TCContainer)<TCContainerDeepCopyProtocol, TCArraySortProtocol, TCArraySetProtocol, TCArrayCheckProtocol>
@end

NS_ASSUME_NONNULL_END
