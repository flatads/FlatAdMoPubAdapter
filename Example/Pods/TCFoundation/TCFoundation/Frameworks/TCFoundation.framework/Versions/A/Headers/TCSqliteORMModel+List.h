//
//  TCSqliteORMModel+List.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/16.
//

#import "TCSqliteORMModel.h"
#import "TCSqliteORMModelProtocol.h"
#import "TCSqliteORMSessionProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface TCSqliteORMModel (List)<TCSqliteORMModelListProtocol, TCSqliteORMSessionListProtocol>

@end

NS_ASSUME_NONNULL_END
