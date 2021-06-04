//
//  TCRequestHelper.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define TCRequestHelper_HttpGet                 @"GET"
#define TCRequestHelper_HttpPost                @"POST"
#define TCRequestHelper_ContentType             @"Content-Type"

#pragma mark ------------------------ TCRequestHelperBinaryData ------------------------
@interface TCRequestHelperBinaryData : NSObject
@property(nullable, copy) NSString* name;
@property(nullable, copy) NSString* fileName;
@property(nullable, copy) NSString* contentType;
@property(nonnull, strong) NSData* data;
@end

#pragma mark ------------------------ TCRequestHelper ------------------------
@interface TCRequestHelper : NSObject
/**
 *  GET or POST or PUT or....
 *
 *  @note case sensitive
 */
@property(nonnull, copy) NSString* httpMethod;  // default - GET

/**
 *  base url
 *  @note to generate a request, u should at least set baseUrl
 */
@property(nonnull, copy) NSString* baseUrl;

/**
 *  params,
 *  @note
    TCRequestHelper_HeaderKeyContentType generate automatically,
    however, u can set it manually by setting value of headerDict with
    TCRequestHelper_HeaderKeyContentType as key
 */
@property(nullable, strong, nonatomic) NSDictionary* headerDict;             // key: NSString, value: NSString;
@property(nullable, strong, nonatomic) NSDictionary* dataDict;               // key: NSString, value: NSString
@property(nullable, strong, nonatomic) NSArray<TCRequestHelperBinaryData*>* binaryDatas;

// others
@property(nonatomic) NSURLRequestCachePolicy cachePolicy;           // default - NSURLRequestUseProtocolCachePolicy
@property(nonatomic) NSTimeInterval timeoutInterval;                // default - 60;
@property(nonnull, nonatomic, copy) NSString* binaryBoundaryToken;  // default - 0xKhTmLbOuNdArY

/******************************************************
 *  generate request
 *
 *  @return return nil if params is invalid
 ******************************************************/
-(nullable NSURLRequest*)generateRequest;
@end

NS_ASSUME_NONNULL_END
