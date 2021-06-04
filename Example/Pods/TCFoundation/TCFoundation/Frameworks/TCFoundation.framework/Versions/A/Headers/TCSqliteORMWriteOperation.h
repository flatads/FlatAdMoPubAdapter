//
//  TCSqliteORMWriteOperation.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TCSqliteORMWriteOperation : NSObject
@property(nonnull) NSString* sql;
@property(nullable) NSArray* args;
+(nonnull instancetype)operationWithSql:(nonnull NSString*)sql args:(nullable NSArray*)args;
@end

NS_ASSUME_NONNULL_END
