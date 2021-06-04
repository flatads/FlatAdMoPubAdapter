//
//  TCSqliteORMModel.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/16.
//

/********************************************
 *  Useage：
 *      1. override +[TCSqliteORMModel primaryKeys] and +[TCSqliteORMModel modelVersion](opt);
 *      2. save| query| delete
 *
 *  Acronym：
 *      ppv        property value
 *      ppt        property type
 *      ppn        property name(= cn)
 *      pk         primary key
 *      pks        @[primary key]
 *      pkvs       @[primary key value]
 *      cn         column name
 *      ct         column type
 *
 *  Feature:
 *      自动映射非只读属性(property)到数据库中，其中支持的property类型有：C类型| TCSqliteORMModel及其子类| NSData| NSArray<NSString*>*| NSArray<TCSqliteORMModel*>*
 *      不支持的类型可以通过bridge相关函数实现，记得成对重载；由于设计原因，本模块不打算引入UI相关的东西，所以类似CGSize和CGRect...自己映射
 *      拷贝功能(只支持property，私有变量自己手动拷贝)
 *      支持黑白名单(默认为空)
 *      兼容策略：相同版本，会检测是否要会增加新的列，所以只是增加字段和改名是不会影响的；不同版本直接干掉旧表
 *      继承策略是：拍平放到一个表不会链接到父类的表(这个不考虑优化，虽然一定程度上冗余，但是拥有重构父类代码可以不影响子类的好处)
 *      会自动屏蔽掉NSOBject的属性和只读属性
 *      write transaction(50%+ 性能提升)
 *
 *
 *  Note：
 *      本模块并不提供线程安全机制，只能在同一个线程使用；请用DAO相关接口更快更安全
 *      一个类一个表；一个对象一条数据：成员方法操纵数据，类方法操纵表；有的类方法是操作所有表，有的类方法是操作自身model对应的表，看清楚哦；
 *      非property变量(如私有变量)不支持映射
 *      由于sqlite是忽略大小写的，所以不能同时存在a和A两个property，否则存储会有问题
 *      'rowid'关键字已被占有，他作为property不会映射到表数据库表中
 *      不认识且不提供bridge的属性在数据库的值为NULL
 *      pk暂时只支持NSString类型
 *      删除数据并不会删除关联的对象，一定程度上有冗余
 *
 *
 * TODO:
 *      表兼容，同一个属性支持修改类型
 *      错误定义，现在许多入口参数如果传错都只是简单的返回
 *      过滤weak属性
 *
 *
 * May Todo：
 *      这一层是否要提供线程安全服务?
 *      NSDictionary的支持(没想好怎么做?)
 *      主键对NSNumber支持?
 *      考虑引入引用计数，减少冗余
 *      增加在列表删除某个对象
 ********************************************/

#import "TCSqliteORMModelProtocol.h"
#import "TCSqliteORMSessionProtocol.h"
#import <TCUtil/TCUtil.h>

NS_ASSUME_NONNULL_BEGIN

@interface TCSqliteORMModel : NSObject<TCSqliteORMModelProtocol, NSCopying, TCSqliteORMSessionProtocol>
#pragma mark ----------------------- base info -----------------------
/**
 *  for model version
 */
+(NSUInteger)modelVersion TC_OVERRIDE;                                       // default - 1.0

/**
 *  blacklist for property
 */
+(nullable TCBlackWhiteList*)columnBlackList TC_OVERRIDE;                    // default - nil

/**
 *  point which properties r primary keys;
 *
 *  @note primary key property only support NSString currently
 *
 *  @return @[pk]
 */
+(nonnull NSArray<NSString*>*)primaryKeys TC_PURE_VIRTUAL;

/**
 *  use to check the model have the same ppvs
 *
 *  @note -[NSObject hash] can't tell an object's ppv has been changed or two object have the same ppvs
 *
 */
-(nullable NSString*)checksum TC_OVERRIDE;                                 // defualt - nil;

#pragma mark ----------------------- bridge -----------------------
/**
 *  subclass can perform this methd to provide a covertion from sql value to oc value for unsupport ppt
 *
 *  @param dbValue  value query from db(unsupport db value is save as TEXT)
 *  @param ppt      property type
 *
 *  @note if u override this mthod u sholud override[valueForSQLValue:ppn:ppt:ct] in pair
 *
 *  @return property value
 */
-(nullable id)valueForSQLValue:(nullable NSString*)dbValue ppt:(nonnull NSString*)ppt TC_OVERRIDE;

/**
 *  subclass can perform this methd to provide a covertion from oc value to db value for unsupport ppt
 *
 *  @param value    property value
 *  @param ppt      property type
 *
 *  @note if u override this mthod u sholud override[valueForSQLValue:ppn:ppt:ct] in pair
 *
 *  @return dbValue(unsupport db value is save as TEXT)
 */
-(nullable NSString*)sqlValueForValue:(nullable id)value ppt:(nonnull NSString*)ppt TC_OVERRIDE;


#pragma mark ----------------------- model info -----------------------
/**
 *  The table name of model
 *
 *  @return we use class name
 */
+(nonnull NSString*)modelTableName;

/**
 *  Get pkvs quickly
 *
 *  @note each primary key's value should set properly,
 *  @return return pkvs. otherwise return nil
 */
-(nullable NSArray*)primaryKeyValues;

/**
 *  path of db
 */
+(nonnull NSString*)dbPath;

/**
 *  check table whether designed well(typically pk)
 *
 */
+(BOOL)isValidTable;

/**
 *  check model whether can communicate with db
 */
-(BOOL)isValidModel;

/**
 *  get all <sessionInfoID, ppv>(recursively) which ppv r model type
 *
 */
-(nonnull NSDictionary*)childModels;
@end

NS_ASSUME_NONNULL_END
