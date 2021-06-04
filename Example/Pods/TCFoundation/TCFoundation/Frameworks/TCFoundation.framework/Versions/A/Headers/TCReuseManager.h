//
//  TCReuseManager.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/16.
//

#import <Foundation/Foundation.h>
#import "TCReuseManagerItemProtocol.h"

typedef id<TCReuseManagerItemProtocol>_Nullable(^TCReuseManagerCreateItemOp)(void);              // 创建对象
typedef void(^TCReuseManagerWillRemoveItemOp)(id<TCReuseManagerItemProtocol> _Nullable item);     // 销毁对象
typedef BOOL(^TCReuseManagerCheckItemOp)(id<TCReuseManagerItemProtocol> _Nullable item);          // 检查对象是否可被复用

NS_ASSUME_NONNULL_BEGIN

@interface TCReuseManager : NSObject
#pragma mark --------------------- life cycle ---------------------
// create a manager for reuse instance of cls
-(instancetype)initWithCls:(Class)cls;

#pragma mark --------------------- config ---------------------
// defaulty, init an object directly
// set this method to init with custom method or do something at init time
@property(copy)TCReuseManagerCreateItemOp createOp;

// call when remove an object in leisureMap.
// The object will always remove from leisureMap.
@property(copy)TCReuseManagerWillRemoveItemOp willRemoveOp;

#pragma mark --------------------- operation ---------------------
// get an leisure item and move it to busy set
-(id<TCReuseManagerItemProtocol>)dequeueReusableItem;

// move an item from busy set to leisure set
-(void)enqueueReusableItem:(id<TCReuseManagerItemProtocol>)item;

// move item from busy set to leisure set batchly
-(void)reQueueWithBusyOperation:(TCReuseManagerCheckItemOp)op;

// clean lesire set
-(void)cleanLeisureItem;

#pragma mark ------------------------- accessor -------------------------
// reuse class
-(Class)itemClass;

/** cache = busy + leisure */
-(NSUInteger)busyItemCount;
-(NSUInteger)leisureItemCount;
-(NSUInteger)cacheItemCount;
@end

NS_ASSUME_NONNULL_END
