//
//  TCRSAUtil.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TCRSAUtil : NSObject
#pragma mark SecKeyRef <=> keyData
//+(NSData*)privateKeyDataWithSecKey:(SecKeyRef)secKey tag:(NSData*)tag;    atodo9
+(NSData*)publicKeyDataWithSecKey:(SecKeyRef)secKey tag:(NSData*)tag;
+(SecKeyRef)secKeyWithPrivateKeyData:(NSData*)keyData tag:(NSData*)tag;
+(SecKeyRef)secKeyWithPublicKeyData:(NSData*)keyData tag:(NSData*)tag;

#pragma mark keyData <=> asn1(der)
//+(NSData*)privateDerDataWithKeyData:(NSData*)keyBits; atodo9
+(NSData*)derDataWithPublicKeyData:(NSData*)keyBits;
+(NSData*)privateKeyDataWithDer:(NSData*)derData;
+(NSData*)publicKeyDataWithDer:(NSData*)derData;

#pragma mark encrypt and decrypt
/****************************************************
 * 如果是私钥加密则isSign设置为YES
 ****************************************************/
+(NSData*)encryptData:(NSData*)data
           withKeyRef:(SecKeyRef)keyRef
               isSign:(BOOL)isSign
              padding:(SecPadding)padding;

+(NSData*)decryptData:(NSData*)data
           withKeyRef:(SecKeyRef)keyRef
              padding:(SecPadding)padding;

#pragma mark generate and delete
/****************************************************
 * Tag是不能重复的，这里提供一个方法删除一下
 ****************************************************/
+(void)deleteAsymmetricKeyWithPlubicTag:(NSData*)publicTag
                             privateTag:(NSData*)privateTag;

+(void)generateKeyPair:(NSUInteger)keySize
         pPublicKeyRef:(SecKeyRef _Nonnull * _Nonnull)pPublicKeyRef
        pPrivateKeyRef:(SecKeyRef _Nonnull * _Nonnull)pPrivateKeyRef
            privateTag:(NSData* _Nonnull)privateTag
             publicTag:(NSData* _Nonnull)publicTag;

#pragma mark util
+(SecKeyRef)secKeyWithPemPublicStr:(NSString*)key tag:(NSData*)tag;
+(SecKeyRef)secKeyWithPemPrivateStr:(NSString*)key tag:(NSData*)tag;

+(NSData*)decryptData:(NSData*)data
        pemPrivateStr:(NSString*)pemPrivateStr
              padding:(SecPadding)padding;

+(NSData*)decryptData:(NSData*)data
         pemPublicStr:(NSString*)pemPublicStr
              padding:(SecPadding)padding;

+(NSData*)encryptData:(NSData*)data
         pemPublicStr:(NSString*)pemPublicStr
              padding:(SecPadding)padding;

+(NSData*)encryptData:(NSData*)data
        pemPrivateStr:(NSString*)pemPrivateStr
              padding:(SecPadding)padding;
@end

NS_ASSUME_NONNULL_END
