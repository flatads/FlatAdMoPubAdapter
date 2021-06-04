//
//  NSRegularExpression+TCBaseExt.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSRegularExpression (TCBaseExt)
#pragma mark ------------------------ match ------------------------
-(BOOL)isMatchString:(NSString*)str;
-(BOOL)isMatchString:(NSString*)str options:(NSMatchingOptions)options;

#pragma mark ------------------------ contain ------------------------
-(BOOL)isContainString:(NSString*)str;
-(BOOL)isContainString:(NSString*)str options:(NSMatchingOptions)options;

#pragma mark ------------------------ matches ------------------------
-(NSArray*)matchesInString:(NSString *)string;
-(NSArray*)matchesInString:(NSString *)string options:(NSMatchingOptions)options;

#pragma mark ------------------------ split ------------------------
-(NSArray*)splitString:(NSString*)string;
-(NSArray*)splitString:(NSString*)string options:(NSMatchingOptions)options;

#pragma mark ------------------------ format ------------------------
-(NSString*)replaceString:(NSString*)string tamplate:(NSString*)tamplate;
-(NSString*)replaceString:(NSString*)string tamplate:(NSString*)tamplate options:(NSMatchingOptions)options;
@end

NS_ASSUME_NONNULL_END
