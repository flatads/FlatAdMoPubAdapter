//
//  FAMediaView.h
//  FlatAds_sdk
//
//  Created by chenwenhao on 2021/5/25.
//  Copyright © 2021 FlatAds. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "FAMediaContent.h"

NS_ASSUME_NONNULL_BEGIN

/// Displays native ad media content.
///
/// If the native ad contains video content, the media view displays the video content.
///
/// If the native ad doesn't have video content and image loading is enabled, the media view
/// displays the first image from the native ad's |images| property.
///
/// If the native ad doesn't have video content and image loading is disabled, the media view is
/// empty.
@interface FAMediaView : UIView

/// The media content displayed in the media view.
@property(nonatomic, strong, nullable) FAMediaContent *mediaContent;


- (void)playVideo;

@end

NS_ASSUME_NONNULL_END
