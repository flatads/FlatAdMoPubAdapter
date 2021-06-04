//
//  TCNetworkDownloadRequest.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/17.
//

/**
 * 文件下载类型请求
 * 这里只是扩展了一下请求参数
 */

#import "TCNetworkRequestProtocol.h"
#import "TCNetworkRequest.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TCNetworkDownloadRequestProtocol<TCNetworkRequestProtocol>
-(nullable instancetype)initWithFileUrl:(nullable NSString*)fileUrl filePath:(nullable NSString*)filePath;
@property(nullable, nonatomic, strong)NSURLRequest* downloadRequest;
@property(nullable, nonatomic, copy)  NSString* filePath;
@property(nullable, nonatomic, copy)  NSString* fileUrl;
@end

@interface TCNetworkDownloadRequest : TCNetworkRequest<NSCopying, TCNetworkRequestDelegate, TCNetworkDownloadRequestProtocol>

@end

NS_ASSUME_NONNULL_END
