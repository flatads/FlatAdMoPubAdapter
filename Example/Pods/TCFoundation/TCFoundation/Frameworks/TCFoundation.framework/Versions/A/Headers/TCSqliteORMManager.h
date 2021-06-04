//
//  TCSqliteORMManager.h
//  TCFoundation
//
//  Created by EkoHu on 2021/3/16.
//

#import <fmdb/FMDB.h>

NS_ASSUME_NONNULL_BEGIN

#define TCSqliteORMManagerInstance ([TCSqliteORMManager shareInstance])
#define TCSqliteORMManager_File_Extension            @"db"

@interface TCSqliteORMManager : NSObject
#pragma mark - init & config
+(instancetype)shareInstance;
-(id)init;
-(id)initWithDBName:(NSString*)dbName;
-(void)setDBName:(NSString *)dbName;
@property(readonly)NSString* dbPath;

#pragma mark - common sqlite op
-(void)executeDB:(void(^)(FMDatabase *db))block;
-(void)executeTransaction:(void(^)(FMDatabase *db, BOOL* rollBack))block;

#pragma mark - quick sqlite op
-(void)addColumnWithName:(NSString*)columnName columnType:(NSString*)columnType tableName:(NSString*)tableName;
-(BOOL)dropModelWithTableName:(NSString*)tableName;

-(NSUInteger)versionWithTable:(NSString*)table;
-(NSString*)setTableName:(NSString*)name version:(NSUInteger)version;
@end

NS_ASSUME_NONNULL_END
