//
//  NSString+TCBaseExt.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (TCBaseExt)
#pragma mark ------------------------ Char ------------------------
/** string deleted unnecessary characters */
-(NSString*)stringByDeletingCharactersInSet:(NSCharacterSet*)set;

/** string with digital number only */
-(NSString*)stringWithNumberOnly;

/** check is string contain some characters */
-(BOOL)containCharacterInSet:(NSCharacterSet*)characterSet;

#pragma mark ------------------------ Path ------------------------
/** string deleted all path extension(/bb/aa/name.xxx.xxx.xx => /bb/aa/name) */
-(NSString*)stringByDeletingAllPathExtension;

/** get file name of path */
-(NSString*)fileName;

/** check file type(UTI such as kUTTypeApplicationFile, kUTTypeImage...) */
-(BOOL)conformsToUTI:(NSString*)UTI;

#pragma mark ------------------------ Misc ------------------------
/** compare version, if target > receiver return NSOrderedAscending*/
-(NSComparisonResult)compareVersion:(NSString*)target;

/** Convert hex string such as "789cab56 4a492c49 54b28aae 562a51b2 3234d05..." to data*/
-(NSData*)dataFromHexString;

-(NSString*)tc_stringValue;
-(NSNumber*)tc_numberValue;
@end

NS_ASSUME_NONNULL_END
