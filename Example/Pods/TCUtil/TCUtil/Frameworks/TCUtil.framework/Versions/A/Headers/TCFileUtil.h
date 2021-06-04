//
//  TCFileUtil.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark --------------------------- TCFileUtilProtocol ---------------------------
@protocol TCFileUtilProtocol <NSObject>
/**
 *  Get row number of file
 *
 *  @param path file path
 *  @note empty line count 0
 *
 *  @return -1 failed, otherwise, row number
 */
+(NSInteger)rowCountOfFile:(NSString*)path;
@end


@interface TCFileUtil : NSObject<TCFileUtilProtocol>
@end

NS_ASSUME_NONNULL_END
