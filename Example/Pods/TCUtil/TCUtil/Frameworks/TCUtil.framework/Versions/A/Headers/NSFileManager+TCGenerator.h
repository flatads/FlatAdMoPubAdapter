//
//  NSFileManager+TCGenerator.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum {
    TCDirectoryWithDateAndTime = 0, ///< 时间+日期 格式例子 "D20120629T212504"
    TCDirectoryWithDateOnly = 1,    ///< 只有日期 格式例子 "D20120629"
    TCDirectoryWithTimeOnly = 2,    ///< 只有时间 格式例子 "T212504"
} TCFMDIR_Gen_DateTimeType;

/**
 * @category NSFileManager (Generator)
 * 生成目录的实用工具
 * @see createDirectoryAtPathEasily
 */
@interface NSFileManager (TCGenerator)
/**
 * 创建目录，自动生成中间目录
 * @param path 需要创建的全目录
 * @return 非nil时为创建成功的目录全路径，nil时失败，用-getLastError获取错误码。
 * @see - (BOOL)createDirectoryAtPath:(NSString *)path withIntermediateDirectories:(BOOL)createIntermediates attributes:(NSDictionary *)attributes error:(NSError **)error NS_AVAILABLE(10_5, 2_0);
 */
- (NSString*)createDirectoryAtPathEasily:(NSString *)path NS_AVAILABLE(10_5, 2_0);

/**
 * 在目标目录下以当前时间日期创建目录
 * @param path 目标目录
 * @param createIntermediates 是否自动创建中间目录
 * @param attributes 目录特性
 * @param error 错误信息
 * @param type 时间日期格式
 * @return YES成功，NO失败。
 * @see - (BOOL)createDirectoryAtPath:(NSString *)path withIntermediateDirectories:(BOOL)createIntermediates attributes:(NSDictionary *)attributes error:(NSError **)error NS_AVAILABLE(10_5, 2_0);
 */
- (BOOL)createDateTimeDirectoryAtPath:(NSString *)path
               withIntermediateDirectories:(BOOL)createIntermediates
                                attributes:(NSDictionary *)attributes
                                     error:(NSError **)error
                              datetimeType:(TCFMDIR_Gen_DateTimeType)type;

/**
 * 在目标目录下以当前时间日期创建目录，自动生成中间目录
 * @param path 目标目录
 * @param type 时间日期格式
 * @return 非nil时为创建成功的目录全路径，nil时失败，用-getLastError获取错误码。
 * @see - (BOOL)createDirectoryAtPath:(NSString *)path withIntermediateDirectories:(BOOL)createIntermediates attributes:(NSDictionary *)attributes error:(NSError **)error NS_AVAILABLE(10_5, 2_0);
 */
- (NSString*)createDateTimeDirectoryAtPathEasily:(NSString *)path
                                    datetimeType:(TCFMDIR_Gen_DateTimeType)type;
@end

NS_ASSUME_NONNULL_END
