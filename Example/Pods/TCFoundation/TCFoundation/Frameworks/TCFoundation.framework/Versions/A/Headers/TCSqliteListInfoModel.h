//
//  TCSqliteListInfoModel.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/16.
//

#import "TCSqliteORMModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TCSqliteListInfoModel : TCSqliteORMModel
@property NSString* modelID;            // 数组的UniqueID
@property NSArray* modelIdentifiers;    // 元素的唯一标识（可以区分类，以及数据主键）
@end

NS_ASSUME_NONNULL_END
