//
//  TCContainerProtocol.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#pragma mark ------------------------ TCContainerDeepCopyProtocol ------------------------
@protocol TCContainerDeepCopyProtocol <NSObject>
/** deep copy container's items(return obj with retain count 1) */
-(id)deepCopy;

/** mutable deep copy container's items(return obj with retain count 1) and all sub items is mutable */
-(id)mutableDeepCopy;
@end
