//
//  TCUtil.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/11.
//

#import <Foundation/Foundation.h>

//! Project version number for TCUtil.
FOUNDATION_EXPORT double TCUtilVersionNumber;

//! Project version string for TCUtil.
FOUNDATION_EXPORT const unsigned char TCUtilVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <TCUtil/PublicHeader.h>

// define
#import <TCUtil/TCUtilMacro.h>

// base extension
#import <TCUtil/NSObject+TCBaseExt.h>
#import <TCUtil/NSString+TCBaseExt.h>
#import <TCUtil/NSRegularExpression+TCBaseExt.h>
#import <TCUtil/NSNumber+TCBaseExt.h>
#import <TCUtil/NSObject+TCSelector.h>
#import <TCUtil/NSObject+TCSwizzle.h>

// container
#import <TCUtil/TCWeakMutableArray.h>
#import <TCUtil/TCWeakMutableDictionary.h>
#import <TCUtil/TCWeakMutableSet.h>

#import <TCUtil/NSSet+TCContainer.h>

#import <TCUtil/NSArray+TCContainer.h>
#import <TCUtil/NSMutableArray+TCContainer.h>

#import <TCUtil/NSDictionary+TCContainer.h>
#import <TCUtil/NSMutableDictionary+TCContainer.h>

//white list
#import <TCUtil/TCBlackWhiteList.h>

// debug
#import <TCUtil/TCDebugUtil.h>
#import <TCUtil/TCDebugTime.h>

// error
#import <TCUtil/NSError+TCUtil.h>

// file
#import <TCUtil/TCFileUtil.h>
#import <TCUtil/TCFileUtil+Path.h>
#import <TCUtil/NSFileManager+TCGenerator.h>

// math
#import <TCUtil/TCMathUtil.h>

// network
#import <TCUtil/TCNetworkUtil.h>
#import <TCUtil/TCRequestHelper.h>
#import <TCUtil/NSString+TCNetworkUtil.h>

// runtime
#import <TCUtil/TCRuntimeUtil.h>

// json
#import <TCUtil/NSObject+TCJSONUtil.h>

// crypto
#import <TCUtil/TCDesUtil.h>
#import <TCUtil/TCMD5Util.h>
#import <TCUtil/TCRSAUtil.h>
#import <TCUtil/TCPEMUtil.h>

// sqlite
#import <TCUtil/TCSqliteUtil.h>

// graphic
#import <TCUtil/TCGraphicUtil.h>
#import <TCUtil/TCGraphicUtil+Coordinate.h>
#import <TCUtil/TCCoordinationFunctions.h>

// keychain
#import <TCUtil/TCKeychainItemWrapper.h>

// version
#import <TCUtil/TCVersionComparation.h>

// timer
#import <TCUtil/TCWeakTimer.h>

// delegate
#import <TCUtil/TCWeakDelegate.h>

// system
#import <TCUtil/TCSystemUtil.h>
#import <TCUtil/TCSystemUtil+Device.h>
