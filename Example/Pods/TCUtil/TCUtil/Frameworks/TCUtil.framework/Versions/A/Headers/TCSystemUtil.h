//
//  TCSystemUtil.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>
#import "TCUtilMacro.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TCSystemUtilProtocol<NSObject>
// <xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx>
// ==>
// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
+(NSString*)formatTokenWithData:(NSData*)deviceToken;

/**
 @return nil if not known
 */
+(NSString*)carrierName;

/**
 @return carrier mncmcc
 */
+(NSString*)carrierMncMcc;

/**
 mobile network code
 */
+(NSString*)carrierMnc;

/**
 mobile country code
 */
+(NSString*)carrierMcc;
@end

@protocol TCSystemUtilAppInfoProtocol <NSObject>
+(NSString*)currentLocaleLanguage;
+(NSString*)currentLocaleScript;
+(NSString*)currentLocaleCountryCode;
+(NSString*)appVersion;
+(NSString*)appName;
@end

@protocol TCSystemUtilUUIDProtocol<NSObject>
#ifdef TC_IOS_PLATFORM_IOS
/**
 *  UUID for vender
 *
 *  @note
 *         The same value for apps that come from the same vendor running on the same device.
 *         A different value for apps on the same device that come from different vendors,
 *         A different value for apps on different devices regardless of vendor.
 *         The value changes when the user deletes all of that vendor’s apps from the device and subsequently reinstalls one or more of them
 *  @return UUID such as E621E1F8-C36C-495A-93FC-0C247A3E6E5F
 */
+(NSString*)vendorUUID NS_AVAILABLE_IOS(6_0);

/**
 *  Advertising UUID
 *
 *  @note
 *      substitution of UDID, but can reset by global setting
 *      even u disable tracking advertising in global setting, u can still get advertising uuid
 *  @return UUID such as E621E1F8-C36C-495A-93FC-0C247A3E6E5F
 */
+(NSString*)advertisingUUID NS_AVAILABLE_IOS(6_0);
#endif

/**
 *  Generate a UUID
 *
 *  @note always save to database or send to server
 *  @return UUID such as E621E1F8-C36C-495A-93FC-0C247A3E6E5F
 */
+(NSString*)generateUUID;
@end

@interface TCSystemUtil : NSObject <TCSystemUtilProtocol, TCSystemUtilAppInfoProtocol, TCSystemUtilUUIDProtocol>
@end

NS_ASSUME_NONNULL_END
