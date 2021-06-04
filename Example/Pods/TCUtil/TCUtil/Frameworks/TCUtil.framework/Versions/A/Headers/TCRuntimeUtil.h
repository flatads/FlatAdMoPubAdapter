//
//  TCRuntimeUtil.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger
{
    TCRuntimeUtilPropertyAttribute_None,
    TCRuntimeUtilPropertyAttribute_Unsetable = 1,  // readonly and no setter
} TCRuntimeUtilPropertyAttribute;

@interface TCRuntimeUtil : NSObject
/**
 *    @brief    动态解析自身的属性
 *
 *    @param     ppns [in|out]    属性名称(数量与ppts一致)
 *    @param     ppts [in|out]    属性类型(数量与ppns一致)
 *    @param  cls             要检索的类
 *    @param  filterAttribute 过滤拥有这种属性的property
 *  @param  excludeClass    此方法会一直往父类检索，直到excludeClass
 */
+(void)getPropertyNames:(NSMutableArray*)ppns
          propertyTypes:(NSMutableArray*)ppts
                  class:(Class)cls
        filterAttribute:(TCRuntimeUtilPropertyAttribute)filterAttribute
           excludeClass:(Class)excludeClass;
@end

NS_ASSUME_NONNULL_END
