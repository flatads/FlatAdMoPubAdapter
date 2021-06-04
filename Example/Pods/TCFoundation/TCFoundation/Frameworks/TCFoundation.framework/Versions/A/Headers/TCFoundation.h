//
//  TCFoundation.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/11.
//

#import <Foundation/Foundation.h>

//! Project version number for TCFoundation.
FOUNDATION_EXPORT double TCFoundationVersionNumber;

//! Project version string for TCFoundation.
FOUNDATION_EXPORT const unsigned char TCFoundationVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <TCFoundation/PublicHeader.h>

// network
#import <TCFoundation/TCNetworkEngine.h>
#import <TCFoundation/TCNetworkDownloadRequest.h>
#import <TCFoundation/TCNetworkRequest.h>
#import <TCFoundation/TCDebugHTTPModel.h>

// orm
#import <TCFoundation/TCSqliteORMModelProtocol.h>
#import <TCFoundation/TCSqliteORMSessionProtocol.h>
#import <TCFoundation/TCSqliteORMModel.h>
#import <TCFoundation/TCSqliteORMModel+List.h>
#import <TCFoundation/TCSqliteORMDAO.h>

// log
#import <TCFoundation/TCLogMacro.h>
#import <TCFoundation/TCLogger.h>
#import <TCFoundation/TCLogModel.h>
#import <TCFoundation/TCLogCapture.h>
#import <TCFoundation/TCLogManager.h>

// event
#import <TCFoundation/TCEventCenter.h>
#import <TCFoundation/TCEventBase.h>

// config
#import <TCFoundation/TCConfigCenterProtocol.h>
#import <TCFoundation/TCConfigCenter.h>

// reuse
#import <TCFoundation/TCReuseManagerItemProtocol.h>
#import <TCFoundation/TCReuseManager.h>
