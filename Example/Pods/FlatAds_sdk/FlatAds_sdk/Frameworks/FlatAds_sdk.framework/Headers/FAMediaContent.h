//
//  FAMediaContent.h
//  FlatAds_sdk
//
//  Created by chenwenhao on 2021/5/25.
//  Copyright © 2021 FlatAds. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FAMediaContent : NSObject

/// Indicates whether the media content has video content.
@property(nonatomic, readonly, assign) BOOL hasVideoContent;

/// Media content aspect ratio (width/height). The value is 0 when there's no media content or the
/// media content aspect ratio is unknown.
@property(nonatomic, readonly, assign) CGFloat aspectRatio;

/// The video's duration in seconds or 0 if there's no video or the duration is unknown.
@property(nonatomic, readonly, assign) NSTimeInterval duration;

@end

NS_ASSUME_NONNULL_END
