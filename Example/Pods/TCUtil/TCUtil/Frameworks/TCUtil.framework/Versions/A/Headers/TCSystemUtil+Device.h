//
//  TCSystemUtil+Device.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/16.
//

#import <Foundation/Foundation.h>

#import "TCSystemUtil.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TCSystemUtilDeviceProtocol <NSObject>
/**
 *  Machine Name
 *
 *  @return such as i386, iPhone1,1, iPhone7,1....
 */
+(NSString*)machineName;

/**
 *  Product Name(currently ios device recognized only)
 *
 *  @return iPhone3, iPhone3gs, iPhone6Plus, iPod3g, iPad1...
 */
+(NSString*)deviceProductName;

#ifdef TC_IOS_PLATFORM_IOS
/**
 *  DeviceName
 *
 *  @return the name user set to it's device(xxxx's iPhone)
 */
+(NSString*)deviceName NS_AVAILABLE_IOS(6_0);

/**
 *  System Version(about osx http://cocoadevcentral.com/articles/000067.php)
 *
 *  @return such as 9.3.1
 */
+(NSString*)osVersion NS_AVAILABLE_IOS(6_0);
#endif


#pragma mark - cpu | memory
/**
 *  App cpu usage(percentage)
 */
+(float)cpuUsage;
+(float)cpuUsageV2;

/**
 * get system cpu usage(percentage)
 */
+(float)systemCpuUsage;

/**
 *  totoal memory freed
 */
+(uint64_t)totalFreedMemory;

/**
 *  Memory useage
 *
 *  @param pResident use memory for application
 *  @param pVertual virtual memory for application
 *  @note in debug mode, it around 2x~3x bigger than real usage
 *
 *  @return result
 */
+(kern_return_t)memoryOfResident:(uint64_t*)pResident virtual:(uint64_t*)pVertual;
@end


@interface TCSystemUtil(Device)<TCSystemUtilDeviceProtocol>
@end


NS_ASSUME_NONNULL_END
