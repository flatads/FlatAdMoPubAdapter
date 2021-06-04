//
//  TCNetworkEngine.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/17.
//
#import "TCNetworkRequest.h"
#import "TCDebugHTTPModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TCNetworkEngineProtocol <NSObject>
/** register request pool */
-(BOOL)registerRequetPoolWithID:(nonnull NSString*)poolID
                        baseURL:(nullable NSURL*)baseURL
                         policy:(nullable NSObject *)policy
                concurrentCount:(NSUInteger)count
              serializationType:(TCHttpRequestType)type
                  configuration:(nullable NSURLSessionConfiguration *)configuration;

// unregister
-(BOOL)unRegisterRequestWithPoolID:(nonnull NSString*)poolID;

/** send request */
-(BOOL)sendWithRequest:(nonnull TCNetworkRequest*)request poolID:(nonnull NSString*)poolID;

/** cancel request(not cancel instantly) */
-(BOOL)cancelWithRequest:(nonnull TCNetworkRequest*)request poolID:(nonnull NSString*)poolID;
-(void)cancelRequestsWithPoolID:(nonnull NSString*)poolID;

//// 以下功能没想到使用场景，不打算暴露，等有场景使用再加上吧
//-(nullable NSArray*)requestsOfPoolID:(nonnull NSString*)poolID;
@end

@protocol TCNetworkEngineDebugDelegate <NSObject>
@optional
-(void)beginSendWithDebugModel:(TCDebugHTTPModel*)model sender:(id)sender;
-(void)finishSendWithebugModel:(TCDebugHTTPModel*)model sender:(id)sender;
@end

@protocol TCNetworkEngineDebugProtocol <NSObject>
@property(nonatomic, assign)BOOL enableDebug;
@property(nonatomic, weak, nullable)id<TCNetworkEngineDebugDelegate> debugDel;
@end

@interface TCNetworkEngine : NSObject<TCNetworkEngineProtocol, TCNetworkEngineDebugProtocol>
TCSingletonInterface(TCNetworkEngine)
@end

NS_ASSUME_NONNULL_END
