//
//  TCDebugHTTPModel.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/17.
//

#import <Foundation/Foundation.h>
#import "TCNetworkRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface TCDebugHTTPModel : NSObject
/************************************************************************/
#pragma mark - Parser
 /************************************************************************/
-(id)initWithRequest:(TCNetworkRequest*)request;
-(void)setRequest:(TCNetworkRequest*)request;
-(void)beginParserSendParamsWithParserType:(TCHttpRequestType)parserType;
-(void)finishParserWithError:(NSError*)error bodyLength:(NSInteger)length;

/************************************************************************/
#pragma mark - Request
/************************************************************************/
/**
 `NSURL` instance that was used for the request. Read-only.
 */
@property (nonatomic, readonly) NSURL *url;

/**
 Cache policy that was used for the request. Read-only.
 */
@property (nonatomic, readonly) NSURLRequestCachePolicy cachePolicy;

/**
 Timeout interval that was used for the request. Read-only.
 */
@property (nonatomic, readonly) NSTimeInterval timeoutInterval;

/**
 Sending date of the request. Read-only.
 */
@property (nonatomic, readonly) NSDate *sendingDate;

/**
 HTTP method of the request. Is `nil` if the request used a different protocol. Read-only.
 */
@property (nonatomic, readonly) NSString *httpMethod;

/**
 Dictionary containing all the request HTTP hearers. Is `nil` if the request used a different protocol. Read-only.
 */
@property (nonatomic, readonly) NSDictionary<NSString *, NSString *> *allRequestHTTPHeaderFields;

/**
 The size of request body in bytes. Read-only.
 */
@property (nonatomic, readonly) NSInteger requestBodyLength;

/**
 Sequence
 */
@property (nonatomic, readonly) NSUInteger sequence;
@property (nonatomic, readonly) NSUInteger globalSequence;

/*
 Parser Type
*/
@property (nonatomic, readonly)TCHttpRequestType parserType;

/************************************************************************/
#pragma mark - Error
 /************************************************************************/
/**
 The code of the client side error.
 */
@property (nonatomic, readonly) NSInteger errorCode;

/**
 The localized description of the client side error.
 */
@property (nonatomic, readonly) NSString* localizedErrorDescription;

/************************************************************************/
#pragma mark - Response
/************************************************************************/
/**
 Receiving date of the response. Read-only.
 */
@property (nonatomic, readonly) NSDate* receivingDate;

/**
 The MIME type of the response. Read-only.
 */
@property (nonatomic, readonly) NSString* MIMEType;

/**
 Text encoding name of the response. Read-only.
 */
@property (nonatomic, readonly) NSString* textEncodingName;

/**
 Request duration. Read-only.
 */
@property (nonatomic, readonly) NSTimeInterval duration;

/**
 HTTP status code of the response. Is `nil` if the request used a different protocol. Read-only.
 */
@property (nonatomic, readonly) NSNumber *statusCode;

/**
 Localized description of the response HTTP status code. Is `nil` if the request used a different protocol. Read-only.
 */
@property (nonatomic, readonly) NSString *localizedStatusCodeString;

/**
 Dictionary containing all the response HTTP hearers. Is `nil` if the request used a different protocol. Read-only.
 */
@property (nonatomic, readonly) NSDictionary<NSString *, NSString *> *allResponseHTTPHeaderFields;

/**
 The size of response body in bytes. Read-only.
 */
@property (nonatomic, readonly) NSInteger responseBodyLength;
@end

NS_ASSUME_NONNULL_END
