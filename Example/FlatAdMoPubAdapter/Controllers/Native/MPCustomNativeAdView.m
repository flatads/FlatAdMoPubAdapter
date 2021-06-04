//
//  MPCustomNativeAdView.m
//  ADAdapterDemo
//
//  Created by chenwenhao on 2021/6/1.
//

#import "MPCustomNativeAdView.h"

#import "MPNativeAdConstants.h"

#import "MPFlatAdNativeCustomEvent.h"

#import "MPNativeAdRenderingImageLoader.h"

#import <FlatAds_sdk/FlatAds_sdk.h>

@interface MPCustomNativeAdView()

@property ( strong , nonatomic ) UILabel *titleLabel;

@property ( strong , nonatomic ) UILabel *mainTextLabel;

@property ( strong , nonatomic ) UILabel *callToActionLabel;

@property ( strong , nonatomic ) UILabel *sponsoredByLabel;

@property ( strong , nonatomic ) UIImageView *iconImageView;

@property ( strong , nonatomic ) UIImageView *mainImageView;

@property ( strong , nonatomic ) UIImageView *privacyInformationIconImageView;

@property (nonatomic, weak) FAMediaView *mediaView;

//@property (nonatomic, strong) FAInfoIconButton *infoIconButton;


@end

@implementation MPCustomNativeAdView

- (void)layoutSubviews
{
    [super layoutSubviews];
    
    self.iconImageView.frame = CGRectMake(8, 8, 42.f, 42.f);
    self.titleLabel.frame = CGRectMake(60, 19, 232.f, 20.f);
    self.mainTextLabel.frame = CGRectMake(8, self.frame.size.height - 42.f, 230, 42.f);
    self.callToActionLabel.frame = CGRectMake(self.frame.size.width - 78 - 12, self.frame.size.height - 33.f, 78.f, 24.f);
    
    self.mainImageView.frame = CGRectMake(0, 58.f, self.frame.size.width, self.frame.size.width * (9 / 16.f));
    
//    self.mediaView.frame = CGRectMake(0, 58.f, self.frame.size.width, self.frame.size.width * (9 / 16.f));
    
    self.privacyInformationIconImageView.frame = CGRectMake(self.frame.size.width - 105.f - 2, 2, 105.f, 20.f);
}

- (UILabel *)nativeMainTextLabel
{
    return self.mainTextLabel;
}

- ( UILabel *)nativeTitleTextLabel
{
    return self.titleLabel;
}

- ( UILabel *)nativeCallToActionTextLabel
{
    return self.callToActionLabel;
}

- ( UILabel *)nativeSponsoredByCompanyTextLabel
{
    return self.sponsoredByLabel;
}

- ( UIImageView *)nativeIconImageView
{
    return self.iconImageView;
}

- ( UIImageView *)nativeMainImageView
{
    return self.mainImageView;
}

- ( UIImageView *)nativePrivacyInformationIconImageView
{
    return self.privacyInformationIconImageView;
}






- (UIColor*)colorWithRGBHex:(unsigned long long)hex
{
    CGFloat r = ((hex & 0xFF0000) >> 16) / 255.;
    CGFloat g = ((hex & 0x00FF00) >> 8) / 255.;
    CGFloat b = (hex & 0x0000FF) / 255.;
    return [UIColor colorWithRed:r green:g blue:b alpha:1.];
}

- (UIColor *)colorWithRGBHexStr:(NSString*)hexStr
{
    if(![hexStr length])
        return nil;
    
    // by pass #
    NSScanner *scanner = [NSScanner scannerWithString:hexStr];
    if([hexStr characterAtIndex:0] == '#')
    {
        [scanner setScanLocation:1];
    }
    
    unsigned long long hex = 0;
    if([scanner scanHexLongLong:&hex])
    {
        return [self colorWithRGBHex:hex];
    }
    return nil;
}


#pragma mark - getter

- (UIImageView *)iconImageView
{
    if (!_iconImageView) {
        _iconImageView = [UIImageView new];
        [self addSubview:_iconImageView];
    }
    return _iconImageView;
}

- (UILabel *)titleLabel {
    if (!_titleLabel) {
        _titleLabel = [UILabel new];
        _titleLabel.numberOfLines = 2;
        _titleLabel.font = [UIFont boldSystemFontOfSize:14.f];
        _titleLabel.textColor = [self colorWithRGBHexStr:@"#212121"];
        [self addSubview:_titleLabel];
    }
    return _titleLabel;
}

- (UILabel *)mainTextLabel {
    if (!_mainTextLabel) {
        _mainTextLabel = [UILabel new];
        _mainTextLabel.numberOfLines = 2;
        _mainTextLabel.font = [UIFont systemFontOfSize:12.f];
        _mainTextLabel.textColor = [self colorWithRGBHexStr:@"#757575"];
        [self addSubview:_mainTextLabel];
    }
    return _mainTextLabel;
}


- (UILabel *)callToActionLabel
{
    if (!_callToActionLabel) {
        _callToActionLabel = [UILabel new];
        _callToActionLabel.textAlignment = NSTextAlignmentCenter;
        _callToActionLabel.font = [UIFont boldSystemFontOfSize:12.f];
        _callToActionLabel.backgroundColor = [self colorWithRGBHexStr:@"#13C296"];
        _callToActionLabel.textColor = UIColor.whiteColor;
        [self addSubview:_callToActionLabel];
    }
    return _callToActionLabel;
}

- (UIImageView *)mainImageView
{
    if (!_mainImageView) {
        _mainImageView = [UIImageView new];
        [self addSubview:_mainImageView];
    }
    return _mainImageView;
}

- (UIImageView *)privacyInformationIconImageView
{
    if (!_privacyInformationIconImageView) {
        _privacyInformationIconImageView = [UIImageView new];
        [self addSubview:_privacyInformationIconImageView];
    }
    return _privacyInformationIconImageView;
}

@end
