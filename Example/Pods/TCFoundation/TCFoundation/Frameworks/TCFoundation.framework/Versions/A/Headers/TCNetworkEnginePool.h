//
//  TCNetworkEnginePool.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/17.
//

/**
 * pool -> cache a group of request with the same config
 */

#import <Foundation/Foundation.h>
#import "AFNetworking.h"
#import "TCNetworkRequestProtocol.h"
#import "TCNetworkRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface TCNetworkEnginePool : NSObject
@property(nonatomic, strong, readonly) NSString* poolID;
@property(nonatomic, strong, readonly) NSObject* sessionMgr;
@property(nonatomic, strong, readonly) NSMutableSet<id<TCNetworkRequestProtocol>>* requests;
@property(nonatomic, assign, readonly) TCHttpRequestType parserType;
@property(nonatomic, assign) NSUInteger sequence;

-(nullable id)initWithPoolWithID:(nonnull NSString*)poolID
                         baseURL:(nullable NSURL*)baseURL
                          policy:(nullable AFSecurityPolicy*)policy
                 concurrentCount:(NSUInteger)count
               serializationType:(TCHttpRequestType)type
                   configuration:(nullable NSURLSessionConfiguration *)configuration;
-(BOOL)addRequest:(id<TCNetworkRequestProtocol>)request;
-(BOOL)removeRequest:(id<TCNetworkRequestProtocol>)request;
@end

NS_ASSUME_NONNULL_END
