//
//  TCUtilMacro.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/11.
//

#import <Foundation/Foundation.h>

#ifndef TCUtilMacro_h
#define TCUtilMacro_h

#pragma mark ----------------------------- QUICK -----------------------------

// Quick declare of singleton
#define TCSingletonInterface(cls)  +(nonnull cls*)shareInstance;

// Quick implement of singleton(allow multiple instance)
#define TCSingletonImp(cls) \
static cls *_instance; \
+ (cls*)shareInstance \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
_instance = [[self alloc] init]; \
}); \
return _instance; \
} \

// Quick implement of singleton(only have one instance)
#define TCSingletonRestrictedImp(cls) \
static cls *_instance; \
+ (id)allocWithZone:(NSZone *)zone \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
_instance = [super allocWithZone:zone]; \
}); \
return _instance; \
} \
+ (cls*)shareInstance \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
_instance = [[self alloc] init]; \
}); \
return _instance; \
} \
- (id)copyWithZone:(NSZone *)zone \
{ \
return _instance; \
}

// Quick declare of nonnil
#define TCNonNilStr(x)      ((x) ? (x) : @"")
#define TCNonNilNum(x)      ((x) ? (x) : @(0))
#define TCNonNilArray(x)    ((x) ? (x) : @[])
#define TCNonNilDict(x)     ((x) ? (x) : @{})

// Quick compatible
#define TCCompatibleStr(x)  ([x tc_stringValue])
#define TCCompatibleNum(x)  ([x tc_numberValue])

// Quick declare of format
#define TCUStr(x)           ([NSString stringWithFormat:@"%u", x])
#define TC1FStr(x)          ([NSString stringWithFormat:@"%.1f", x])
#define TC2FStr(x)          ([NSString stringWithFormat:@"%.2f", x])
#define TC3FStr(x)          ([NSString stringWithFormat:@"%.3f", x])

#define IsEmptyNSString(x) ((x)==nil || [(x) length]==0)
#define IsNotEmptyNSString(x) ((x)!=nil && [(x) length]>0)

#pragma mark ----------------------------- MACORS ONLY EXIST IN ARC -----------------------------
#if !defined(__clang__) || __clang_major__ < 3
#ifndef __bridge
#define __bridge
#endif

#ifndef __bridge_retain
#define __bridge_retain
#endif

#ifndef __bridge_retained
#define __bridge_retained
#endif

#ifndef __autoreleasing
#define __autoreleasing
#endif

#ifndef __strong
#define __strong
#endif

#ifndef __unsafe_unretained
#define __unsafe_unretained
#endif

#ifndef __weak
#define __weak
#endif
#endif

#define TCWeakSelf(weakSelf) __weak typeof(self) weakSelf = self
#define TCStrongObj(name, value) __strong __typeof(value) name = value
#define TCWeakObj(name, value) __weak typeof(value) name = value

#pragma mark ----------------------------- MACROS DIFFERENT BETWEEN ARC AND MRC -----------------------------
#if __has_feature(objc_arc)
#define TCPropRetain strong
#define TCPropAssign weak

#define TCRetain(x) (x)
#define TCRelease(x) (x = nil)
#define TCAutorelease(x) (x)

#define TCBlockCopy(x) (x)
#define TCBlockRelease(x)
#define TCSuperDealloc()

#define TCAutoreleasePoolStart() @autoreleasepool {
#define TCAutoreleasePoolEnd() }

#define TCRetainAssign(obj,value){obj = value;}
#define TCCopyAssign(obj,value){obj = value;}
#else
// -
#define TCPropRetain retain
#define TCPropAssign assign

#define TCRetain(x) ([(x) retain])
#define TCRelease(x) ([(x) release], x = nil)
#define TCAutorelease(x) ([(x) autorelease])

#define TCBlockCopy(x) (Block_copy(x))
#define TCBlockRelease(x) (Block_release(x))
#define TCSuperDealloc() ([super dealloc])

#define TCAutoreleasePoolStart() NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
#define TCAutoreleasePoolEnd() [pool drain];

#define TCRetainAssign(obj,value){if(obj != value){if(obj)[obj release]; obj = [value retain];}}
#define TCCopyAssign(obj,value){if(obj != value){if(obj)[obj release]; obj = [value copy];}}
#endif


#pragma mark ----------------------------- CF MACRO -----------------------------
#define TCCFRetainAssign(obj,value){if(obj != value){if(obj)CFRelease(obj); if(value)CFRetain(value); obj = value;}}
#define TCCFRelease(obj){if(obj){CFRelease(obj), obj = nil;}}

NS_INLINE CFTypeRef TCCFAutorelease(CFTypeRef obj)
{
    // CF bridge 2 id use CFBridgingRelease directly
    if(NULL == obj)
        return NULL;
    
    id __autoreleasing ret = CFBridgingRelease(obj);// 测试该函数暂时把上面注释掉
    return (__bridge CFTypeRef)ret;
}


#pragma mark ----------------------------- SUPRESS WARNING -----------------------------
#define TCSuppressPerformSelectorLeakWarning(Stuff) \
do \
{ \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
Stuff; \
_Pragma("clang diagnostic pop") \
} \
while (0)

#define TCSuppressPerformSelectorDeprecated(Stuff) \
do \
{ \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wdeprecated-declarations\"") \
Stuff; \
_Pragma("clang diagnostic pop") \
} \
while (0)


#pragma mark ----------------------------- PLATFORM -----------------------------
#ifdef _WIN32
#define TC_IOS_PLATFORM_WIN32
#ifdef _WIN64
#define TC_IOS_PLATFORM_WIN64
#endif
#elif __APPLE__
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
#define TC_IOS_PLATFORM_IOS
#elif TARGET_OS_IPHONE
#define TC_IOS_PLATFORM_IOS
#define TC_IOS_PLATFORM_PHONE
#elif TARGET_OS_MAC
#define TC_IOS_PLATFORM_MAC
#else
// Unsupported platform
#endif
#elif __linux
#define TC_IOS_PLATFORM_LINUX
#elif __unix // all unices not caught above
#define TC_IOS_PLATFORM_NNIX
#elif __posix
#define TC_IOS_PLATFORM_POSIX
#endif


#pragma mark ----------------------------- FLAG -----------------------------
#define TC_PURE_VIRTUAL /* 纯虚(子类如果没有重载，要在Interface下标明依旧是纯需) */
#define TC_OVERRIDE     /* 推荐重载的点 */
#define TC_NON_OVERRIDE /* 表示该函数不推荐重载，逻辑已经由父类完备 */

#endif /* TCUtilMacro_h */
