//
//  UIImageView+TCUIKit.h
//  TCUIKit
//
//  Created by EkoHu on 2021/3/18.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^TCImageUrlCompletionBlock)(UIImage *image, NSError *error, NSURL *imageURL, BOOL changed);
@interface UIImageView (TCUIKit)
-(void)setImageWithString:(nonnull NSString*)url;
-(void)setImageWithString:(nonnull NSString*)url placeholderImage:(nullable UIImage *)placeholder;
-(void)setImageWithString:(nonnull NSString*)url placeholderImage:(nullable UIImage *)placeholder completionBlock:(TCImageUrlCompletionBlock)completionBlock;
@end

NS_ASSUME_NONNULL_END
