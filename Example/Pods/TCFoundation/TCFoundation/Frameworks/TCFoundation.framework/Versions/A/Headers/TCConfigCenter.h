//
//  TCConfigCenter.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/16.
//

#import <Foundation/Foundation.h>
#import <TCUtil/TCUtilMacro.h>
#import "TCConfigCenterProtocol.h"

/******************************************************************************************************
 Feature:
    本模块负责配置的存取一些配置，至于配置的内容对于本模块是个黑盒
 
 Note:
    1. 配置，分为Bundle中预置的plist(只读)和程序运行中产生的配置。
    2. 程序运行产生的配置，通过category(我们提供默认的)和配置名可以唯一确定；现在只支持Dictionary(or mutable)
       如果是Array，外面包多一层吧
    3. 下面如果不传位置参数默认都在TCConfigLocation_Document
 **********************************************************************************************************/

NS_ASSUME_NONNULL_BEGIN

@interface TCConfigCenter : NSObject <TCConfigCenterProtocol>
TCSingletonInterface(TCConfigCenter)
@end

NS_ASSUME_NONNULL_END
