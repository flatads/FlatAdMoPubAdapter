//
//  NSMutableArray+TCContainer.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>
#import "TCArrayProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface NSMutableArray (TCContainer)<TCMutableArraySortProtocol, TCMutableArraySafeProtocol>

@end

NS_ASSUME_NONNULL_END
