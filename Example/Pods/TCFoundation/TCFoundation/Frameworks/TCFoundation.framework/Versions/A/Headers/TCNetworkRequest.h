//
//  TCNetworkRequest.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/17.
//

/**
 * 说明：普通HTTP请求的积累
 * 设计：
 *   此类为虚类
 *   根据不同策略（并发数，安全策略，请求类型）分成不同的请求池子pool（基于URLSession的思想）。
 *   每个pool对应一个派生的基类(取名A)
 *   A根据不同协议，派生出具体请求的实现类（取名a，负责封包，解包）
 * 使用：
 *   根据产品需要创建不同通路，每个通路写一个基类A，并在A中提供好pool相关信息
 *   根据具体业务协议，派生出子类a，写好封包解包流程
 *   外部创建a设置好参数，然后发送
 * 注意：
 *   1.copying协议中不会拷贝task
 *   2. TCNetworkRequest自己也实现了TCNetworkRequestDelegate，方便做解析；
 *    其中基类默认实现是转发给delegate和block
 *    如果同时存在block，会先转给block，再转给delegate
 */

#import <Foundation/Foundation.h>

#import "TCNetworkRequestProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface TCNetworkRequest : NSObject<NSCopying, TCNetworkRequestDelegate, TCNetworkRequestProtocol>

/****************************************************/
#pragma mark Request
/****************************************************/
-(void)onConstructMultipartWithFormData:(nonnull id)formData;       // only valid in post and isMultipartPost = YES
-(nullable NSURLSessionTask*)urlSessionWithTasksessionMgr:(nonnull NSObject*)sessionMgr
                                           uploadProgress:(nullable void (^)(NSProgress * _Nonnull))uploadProgress
                                         downloadProgress:(nullable void (^)(NSProgress * _Nonnull))downloadProgress
                                          successProgress:(nullable void (^)(NSURLSessionDataTask* _Nullable task, id _Nullable responseObject))successProgress
                                          failureProgress:(nullable void (^)(NSURLSessionDataTask * _Nullable task, NSError* _Nullable error))failureProgress;


/****************************************************/
#pragma mark Parser
/****************************************************/
-(NSInteger)parseResponseData:(nullable id)response error:(NSError* _Nullable*)error;
-(void)parseResponseError:(nullable NSError*)error;

/****************************************************/
#pragma mark Authentication
/****************************************************/
-(void)setSessionDidReceiveAuthenticationChallengeBlock:(nullable NSURLSessionAuthChallengeDisposition (^)(NSURLSession *session, NSURLAuthenticationChallenge *challenge, NSURLCredential * _Nullable __autoreleasing * _Nullable credential))block;

/****************************************************/
#pragma mark Query Serialization
/****************************************************/
-(void)setQueryStringSerializationWithBlock:(NSString *(^)(NSURLRequest *request, id parameters, NSError *__autoreleasing *error))block;

/****************************************************/
#pragma mark Pool
/****************************************************/
+(nonnull NSString*)poolID  TC_PURE_VIRTUAL;                // must provided
+(nullable NSURL*)baseURL;                                  // default - nil
+(NSObject*)policy;                                 // default - nil
+(NSUInteger)concurrentCount;                               // default - 4
+(TCHttpRequestType)httpRequestType;                        // default - TCHttpRequestType_JSON
+(nullable NSURLSessionConfiguration*)configuration;        // default - nil
+(NSDictionary*)configHeaderField;                          // default - @{}  key:<forHTTPHeaderField> value:<setValue>

@end

NS_ASSUME_NONNULL_END
