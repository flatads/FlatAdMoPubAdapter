//
//  TCDesUtil.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TCDesUtil : NSObject
/**
 * 3DES解密函数，先使用base64解码，再使用3DES解密
 * @param src 为原文
 * @param key 为密钥
 * @return 返回值为明文
 */
+(NSString*)DesDecypte:(NSString*)src key:(NSString*)key;

/**
 * 3DES加密函数，先使用3DES加密，然后base64编码
 * @param src 为原文
 * @param key 为密钥
 * @return 返回值为密文
 */
+(NSString*)DesEncrypte:(NSString*)src key:(NSString*)key;
@end

NS_ASSUME_NONNULL_END
