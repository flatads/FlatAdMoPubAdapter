//
//  TCConfigCenterProtocol.h
//  TCFoundation
//
//  Created by huyaobin on 2021/4/14.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger
{
    TCConfigType_JSON,          // 最简单
    TCConfigType_PLIST,         // 比较繁琐，不过支持IDE打开
} TCConfigType;


typedef enum : NSUInteger {
    TCConfigLocation_Document,
    TCConfigLocation_Cache,
    TCConfigLocation_Tmp,
} TCConfigLocation;

@protocol TCConfigCenterProtocol <NSObject>
#pragma mark ----------------- Runtime's -----------------
// config dir
-(nonnull NSString*)configDirWithLocation:(TCConfigLocation)location;

/** read config */
-(nullable NSDictionary*)readDictionaryFromCategory:(nullable NSString*)category name:(nonnull NSString*)name type:(TCConfigType)type;
-(nullable NSDictionary*)readDictionaryFromCategory:(nullable NSString*)category name:(nonnull NSString*)name type:(TCConfigType)type location:(TCConfigLocation)location;

/** read mutable(include all container) config */
-(nullable NSMutableDictionary*)readMutableDictionaryFromCategory:(nullable NSString*)category name:(nonnull NSString*)name type:(TCConfigType)type;
-(nullable NSMutableDictionary*)readMutableDictionaryFromCategory:(nullable NSString*)category name:(nonnull NSString*)name type:(TCConfigType)type location:(TCConfigLocation)location;

/** write config */
-(void)writeConfig:(nullable NSDictionary*)config toCategory:(nullable NSString*)category name:(nonnull NSString*)name type:(TCConfigType)type;
-(void)writeConfig:(nullable NSDictionary*)config toCategory:(nullable NSString*)category name:(nonnull NSString*)name type:(TCConfigType)type location:(TCConfigLocation)location;

/** append config */
-(void)appendConfig:(nonnull NSDictionary*)config toCategory:(nullable NSString*)category name:(nonnull NSString*)name type:(TCConfigType)type;
-(void)appendConfig:(nonnull NSDictionary*)config toCategory:(nullable NSString*)category name:(nonnull NSString*)name type:(TCConfigType)type location:(TCConfigLocation)location;

/** remove config */
-(void)removeAConfig:(nonnull NSString*)key atCategory:(nullable NSString*)category name:(nonnull NSString*)name type:(TCConfigType)type;
-(void)removeAConfig:(nonnull NSString*)key atCategory:(nullable NSString*)category name:(nonnull NSString*)name type:(TCConfigType)type location:(TCConfigLocation)location;

#pragma mark ----------------- Bundle's -----------------
/**
 *  read plist in bundle(cached);
 *  @param bundle nil will query main bundle
 *  @param name name of plist
 */
-(nullable NSDictionary*)readPlistWithBundle:(nullable NSBundle*)bundle name:(nonnull NSString*)name;
@end
