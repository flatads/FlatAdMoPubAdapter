//
//  TCWeakContainerItem.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TCWeakContainerItem : NSObject
@property(readonly)NSString* itemIdentifier;
@property(weak)id obj;
-(instancetype)initWithObj:(id)obj;
+(NSString*)identifierWithObj:(id)obj;
@end

@interface TCWeakArrayItem : TCWeakContainerItem
@end

@interface TCWeakDictionaryItem : TCWeakContainerItem
@end

@interface TCWeakSetItem : TCWeakContainerItem
@end

NS_ASSUME_NONNULL_END
