//
//  TCSqliteORMModelProperties.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/17.
//

#import <Foundation/Foundation.h>
#import "TCSqliteORMModelProtocol.h"

NS_ASSUME_NONNULL_BEGIN

#define TCSqliteORMManager_Sql_TextType         @"text"
#define TCSqliteORMManager_Sql_IngegerType      @"integer"
#define TCSqliteORMManager_Sql_DoubleType       @"double"
//@"blob"
//@"NOT NULL"
//@"PRIMARY KEY"
//@"DEFAULT"
//@"UNIQUE"
//@"CHECK"
//@"FOREIGN KEY"

#pragma mark ----------------------------------------- TCSqliteORMProperty -----------------------------------------
@interface TCSqliteORMProperty : NSObject
// property type
@property(copy, nonatomic)NSString* ppn;
// property oc type
@property(copy, nonatomic)NSString* ppt;
// table's column type
@property(copy, nonatomic)NSString* ct;

// 以下属性考虑添加
//@property BOOL isUnique;
//@property BOOL isNotNull;
//@property(copy,nonatomic) NSString* defaultValue;
//@property(copy,nonatomic) NSString* checkValue;
//@property NSInteger length;
@end

#pragma mark ----------------------------------------- TCSqliteORMModelProperties -----------------------------------------
@interface TCSqliteORMModelProperties : NSObject

#pragma mark - life
-(instancetype)initWithPropertyNames:(NSArray*)ppns ppts:(NSArray*)ppts pks:(NSArray*)pks;

#pragma mark - query
@property(readonly)NSUInteger count;
-(NSArray*)allProperties;
-(TCSqliteORMProperty*)propertyWithName:(NSString*)ppn;
-(NSArray*)pks;

#pragma mark - pkvs <==> uniqueKey
+(NSString*)uniqueKeyWithPkvs:(NSArray*)pkvs;
+(NSArray*)pkvsWithUniqueKey:(NSString*)uniqueKey;

#pragma mark - property is list of model
+(NSString*)makeModelListSqlValue:(Class)cls pkvs:(NSArray*)pkvs ppn:(NSString*)ppn;
+(BOOL)sqlValueIsWithModelList:(NSString*)sqlValue;

#pragma mark - property is list of NSString
+(NSString*)makeJSONSqlValue:(NSString*)json;
+(NSString*)jsonWithSqlValue:(NSString*)sqlValue;
+(BOOL)sqlValueIsJSON:(NSString*)sqlValue;

#pragma mark - sqlType vs ocType
+(NSString*)sqlTypeFromObjcType:(NSString*)ocType;
@end

NS_ASSUME_NONNULL_END
