//
//  TCSqliteUtil.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TCSqliteUtil : NSObject
/**
 *  check sql is empty or only with word ignore
 */
+(BOOL)isEmptySQL:(NSString*)sql;

/**
 *  @param cts       column type(the count must equal to cns's) && count != 0(can't create empty table)
 *  @param cns       column name(the count must equal to cts's) && count != 0(can't create empty table)
 *  @param pks       primary keys
 *
 */
+(NSString*)createTableSQLWithTableName:(NSString*)tableName cts:(NSArray*)cts cns:(NSArray*)cns pks:(NSArray*)pks;

/**
 *  make a saql for check table is existing
 */
+(NSString*)makeCheckTableExistSQLWithTableName:(NSString*)tableName;

/**
 *  drop table
 */
+(NSString*)makeDropTableSQLWithTableName:(NSString*)tableName;

/**
 *  make a add column sql
 */
+(NSString*)makeAddColumnSQLWithTableName:(NSString*)tableName cn:(NSString*)cn ct:(NSString*)ct;

/**
 *  make a set initial value for column sql
 */
+(NSString*)makeSetInitValueSQLWithTableName:(NSString*)tableName cn:(NSString*)cn ct:(NSString*)ct;

/**
 *  make where sql(xxxKey = xxxValue, ...)
 *
 *  @param condition key and value must be NSString type
 */

+(NSString*)makeWhereSQLWithDict:(NSDictionary*)condition;

/**
 *  make a replace sql with placeHold(?,?,?,?)
 *
 *  @param tableName table name
 *  @param cns       column names(count != 0)
 *
 */
+(NSString*)makeReplaceSQLWithTableName:(NSString*)tableName cns:(NSArray*)cns;

/**
 *  select columns from table
 *
 *  @param cns   column names(if nil => *)
 *
 *  @return sql
 */
+(NSMutableString*)makeQuerrySQLWithTableName:(NSString*)tableName cns:(NSArray*)cns;

/**
 *  add where condition for sql
 */
+(void)appendWhereForSQL:(NSMutableString*)query where:(NSString*)where;

/**
 *  add orderby, offset, limit for sql
 */
+(void)appendOrderBy:(NSString*)orderBy offset:(unsigned int)offset limit:(unsigned int)limit forSQL:(NSMutableString*)sql;
@end

NS_ASSUME_NONNULL_END
