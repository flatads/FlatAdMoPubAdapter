//
//  TCPEMUtil.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define TCPEMUtil_X509_OLD     "X509 CERTIFICATE"
#define TCPEMUtil_X509         "CERTIFICATE"
#define TCPEMUtil_X509_PAIR    "CERTIFICATE PAIR"
#define TCPEMUtil_X509_TRUSTED "TRUSTED CERTIFICATE"
#define TCPEMUtil_X509_REQ_OLD "NEW CERTIFICATE REQUEST"
#define TCPEMUtil_X509_REQ     "CERTIFICATE REQUEST"
#define TCPEMUtil_X509_CRL     "X509 CRL"
#define TCPEMUtil_EVP_PKEY     "ANY PRIVATE KEY"
#define TCPEMUtil_PUBLIC       "PUBLIC KEY"
#define TCPEMUtil_RSA          "RSA PRIVATE KEY"
#define TCPEMUtil_RSA_PUBLIC   "RSA PUBLIC KEY"
#define TCPEMUtil_DSA          "DSA PRIVATE KEY"
#define TCPEMUtil_DSA_PUBLIC   "DSA PUBLIC KEY"
#define TCPEMUtil_PKCS7        "PKCS7"
#define TCPEMUtil_PKCS7_SIGNED "PKCS #7 SIGNED DATA"
#define TCPEMUtil_PKCS8        "ENCRYPTED PRIVATE KEY"
#define TCPEMUtil_PKCS8INF     "PRIVATE KEY"
#define TCPEMUtil_DHPARAMS     "DH PARAMETERS"
#define TCPEMUtil_DHXPARAMS    "X9.42 DH PARAMETERS"
#define TCPEMUtil_SSL_SESSION  "SSL SESSION PARAMETERS"
#define TCPEMUtil_DSAPARAMS    "DSA PARAMETERS"
#define TCPEMUtil_ECDSA_PUBLIC "ECDSA PUBLIC KEY"
#define TCPEMUtil_ECPARAMETERS "EC PARAMETERS"
#define TCPEMUtil_ECPRIVATEKEY "EC PRIVATE KEY"
#define TCPEMUtil_PARAMETERS   "PARAMETERS"
#define TCPEMUtil_CMS          "CMS"

@interface TCPEMUtil : NSObject
#pragma mark pem <=> der
+(NSString*)pemFromDER:(NSData*)derData header:(const char*)header;
+(NSData*)derDataFromPem:(NSString*)pem;
@end

NS_ASSUME_NONNULL_END
