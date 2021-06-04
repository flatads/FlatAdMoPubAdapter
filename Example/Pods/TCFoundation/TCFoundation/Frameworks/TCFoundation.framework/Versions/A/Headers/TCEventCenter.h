//
//  TCEventCenter.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/16.
//

/******************************************************************************************************
 Feature:
    事件中心，一般用于同层业务之间松耦合交互；
 
 Useage:
    1.创建一个事件子类，并在子类中实现相关封包解包逻辑，
    2.发送|监听
 
 FQA
    Q: 我们为什么需要它?NotificationCenter不行么？
    A: 1. NotificaitonCenter定义过于散乱，还没有强类型约束，严重依赖文档和注释.
       2. NotificaitonCenter更适合先写好一个组件，然后他一对多的发送出去的场景。这样发送端代码不变，接受端各自去解包。
          在同层业务中，大家是平等的，常出现的场景是多对多的通讯，这时更加注重定义消息本身。所以我们需要将封包和解包的逻
          辑抽象内聚起来，而不是每个地方都写重复又些许差异的代码；
          
       3. 随着业务变化，我们对事件处理可能会增加一些逻辑。在这个时候我们并不想修改以前写好的接收和发送端代码提高测试成本，
          我们只需要在事件中提供额外的解包或封包接口
 
    Q: 我不取消监听会怎么样
    A: 我们在监听对象dealloc时会自动取消监听
 
    Q: 接收的顺序是怎么样的
    A: 谁先监听谁先接收；本模块并不在意这顺序的问题；如果非要管理，可以另起模块管理顺序
 
    Q: 同一个对象监听两次同一个消息会有啥效果
    A: 恭喜你，回调你两次（你不应该这样做）
 
    Q：会和NSNotificationCenter的消息冲突么
    A: 不会
 **********************************************************************************************************/

#import <Foundation/Foundation.h>
#import <TCUtil/TCUtilMacro.h>
#import "TCEventBase.h"

typedef void(^MessageActionBlock)(__kindof TCEventBase* _Nonnull event, id _Nonnull  poster);

NS_ASSUME_NONNULL_BEGIN

@interface TCEventCenter : NSObject
TCSingletonInterface(TCEventCenter)

/**
 * 监听事件 (SEL形式)
 * @note action必须接受两个参数，分别为(TCEventBase*)event和(id)poster
 */
-(void)observeMessage:(nonnull NSString*)message action:(nonnull SEL)action observer:(nonnull id)observer;

/** 监听事件（Block形式） */
-(void)observeMessage:(nonnull NSString*)message actionBlock:(nonnull MessageActionBlock)actionBlock observer:(nonnull id)observer;

/** 取消监听 */
-(void)removeObserveMessage:(nonnull NSString*)message observer:(nonnull id)observer;

/** 发送事件 */
-(void)sendEvent:(nonnull __kindof TCEventBase*)event poster:(nonnull id)poster;
@end

NS_ASSUME_NONNULL_END
