//
//  TCMD5Util.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TCMD5Util : NSObject
+(NSString *)file_md5:(NSString*)path;
+(NSString *)string_md5:(NSString*)str;
+(NSString*)md5EncodedWithData:(NSData*)inputData;
@end

NS_ASSUME_NONNULL_END
