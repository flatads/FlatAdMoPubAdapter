//
//  NSObject+TCJSONUtil.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - JSON Writing
/// Adds JSON generation to NSObject
@interface NSObject (TCJSONUtil)
/**
 @brief Encodes the receiver into a JSON string
 Although defined as a category on NSObject it is only defined for NSArray and NSDictionary.
 @return the receiver encoded in JSON, or nil on error.
 */
-(NSString *)JSONRepresentation;
@end

#pragma mark - JSON Parsing
/// Adds JSON parsing methods to NSString
@interface NSString (TCJSONUtil)
/**
 @brief Decodes the receiver's JSON text
 @return the NSDictionary or NSArray represented by the receiver, or nil on error.
 */
-(id)JSONValue;
@end

/// Adds JSON parsing methods to NSData
@interface NSData (TCJSONUtil)
/**
 @brief Decodes the receiver's JSON data
 @return the NSDictionary or NSArray represented by the receiver, or nil on error.
 */
-(id)JSONValue;
@end

NS_ASSUME_NONNULL_END
