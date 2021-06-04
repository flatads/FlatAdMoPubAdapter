//
//  TCBlackWhiteList.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef BOOL (^TCBlackWhiteListFilterBlock)(id item);

typedef enum : NSUInteger
{
    TCBlackWhiteListType_Whitelist = 1,
    TCBlackWhiteListType_Blacklist = 2,
} TCBlackWhiteListType;

@interface TCBlackWhiteList : NSObject

/* whitelist or blacklist **/
@property(readonly)TCBlackWhiteListType type;

/* Only items in the whitelist are allowed, available in TCBlackWhiteListType_Whitelist **/
@property(readonly)NSMutableSet* whiteList;

/* Only items in the blacklist are disallowed available in TCBlackWhiteListType_Whitelist **/
@property(readonly)NSMutableSet* blackList;

/**
 *  give a more restrict condition.
 *  For example, using prefix matching, regular expressions, etc
 */
@property(copy)TCBlackWhiteListFilterBlock filterBlock;

#pragma mark - initializer
/** Not designate initializer */
-(instancetype)init NS_UNAVAILABLE;

/** Creates a whitelist based instance */
-(instancetype)initWithWhitelist:(NSSet*)whitelist NS_DESIGNATED_INITIALIZER;

/** Creates a blacklist based instance */
-(instancetype)initWithBlacklist:(NSSet*)blacklist NS_DESIGNATED_INITIALIZER;

#pragma mark - check
-(BOOL)isItemAllowed:(id)item;
@end

NS_ASSUME_NONNULL_END
