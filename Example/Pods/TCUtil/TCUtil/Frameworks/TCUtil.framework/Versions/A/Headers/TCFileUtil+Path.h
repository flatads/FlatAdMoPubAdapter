//
//  TCFileUtil+Path.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import "TCFileUtil.h"

NS_ASSUME_NONNULL_BEGIN

@interface TCFileUtil (Path)
/**
 *  用户持久化的数据（常用于保存该目录保存不可再生数据，如本地数据库）
 *  @note   该路径下的数据不会自动清除，应用程序要负责删除这些数据(一般很少删)
 *  @note   在备份时(通过iCloud，或者iTunes等)会备份该目录下的数据
 */
+(NSString*)documentPathInUserDomain;

/**
 *  用户本地缓存（常用于目录保存可再生数据，如网络数据）
 *  @note   该路径下的数据不会自动删除，应用程序要负责删除这些数据；
 *  @note   在备份时(通过iCloud，或者iTunes等)不会备份该目录下的数据；
 *  @note   在Library下
 */
+(NSString*)cachePathInUserDomain;

/**
 *  该目录保存各种临时数据（重启后不需要的数据）
 *  @note   该路径下的数据在下次启动时可能会被删掉
 *  @note   在备份时(通过iCloud，或者iTunes等)不会备份该目录下的数据
 */
+(NSString*)tmpDir;

/**
 *  程序包路径(程序安装资源打包的路径)
 *  @note   在程序编译签名以后就是只读的了，不会动态篡改
 */
+(NSString*)appBundlePath;

/**
 *  获得plist路径
 */

+(NSString*)plistPathWithName:(NSString*)name;
@end

NS_ASSUME_NONNULL_END
