//
//  TCGraphicUtil+Coordinate.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import "TCGraphicUtil.h"
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

@interface TCGraphicUtil (Coordinate)
#pragma mark ---------------------------- relation ----------------------------
/** 判断一个点是否在矩形内(在边上的不算，想要包括边的用CGRectContainsPoint) */
+(BOOL)isPoint:(CGPoint)point inRect:(CGRect)rect;

/** 判断一个矩形是否在另一个矩形上(即使是旋转的矩形也可以用。注意：边不能相交，想要on的效果用CGRectContainsRect) */
+(BOOL)isRect:(CGRect)r1 inRect:(CGRect)r2;

/** 判断两个矩形是否交错(切边不算，和CGRectIntersection的结果一致) */
+(BOOL)isRect:(CGRect)r1 overlapRect:(CGRect)r2;

/** 判断两个矩形是否相触(包含或切边或切点) */
+(BOOL)isRect:(CGRect)r1 touchRect:(CGRect)r2;

/** 计算两点的距离 */
+(CGFloat)distanceWithPont1:(CGPoint)p1 point2:(CGPoint)p2;

/** 计算向量长度 */
+(CGFloat)distanceWithVector:(CGVector)vector;

#pragma mark ---------------------------- convert ----------------------------
/** 角度转弧度 */
+(CGFloat)degreeToRadian:(CGFloat)degree;

/** 弧度转角度 */
+(CGFloat)radianToDegree:(CGFloat)radian;

#pragma mark ---------------------------- rect ----------------------------
// 水平|垂直移动；改变宽|高
+(CGRect)moveHorizontalWithRect:(CGRect)rect offset:(CGFloat)offset;
+(CGRect)moveVerticalWithRect:(CGRect)rect offset:(CGFloat)offset;
+(CGRect)shitfWidthWithRect:(CGRect)rect constant:(CGFloat)constant;
+(CGRect)shitfHeightWithRect:(CGRect)rect constant:(CGFloat)constant;

#pragma mark ---------------------------- others ----------------------------
/** 通过两个点创建矩形 */
+(CGRect)rectFromPoint1:(CGPoint)p1 point2:(CGPoint)p2;

/** 远点偏移向量 */
+(CGPoint)point:(CGPoint)pt moveVector:(CGVector)vector;

/** 调整裁剪区域（去掉超出部分，注意裁剪外面需要自己去浮点CGRectIntegral） */
+(CGRect)fixCropRect:(CGRect)cropRect canvasSize:(CGSize)canvasSize;
/** 调整裁剪区域（去掉超出部分，注意裁剪外面需要自己去浮点CGRectIntegral） */
+(CGRect)fixCropRect:(CGRect)cropRect canvasRect:(CGRect)canvasRect;

/** 计算居中画图的原点 */
+(CGPoint)originForCenterDraw:(CGSize)drawSize canvasSize:(CGSize)canvasSize;
/** 计算居中画图的原点 */
+(CGPoint)originForCenterDraw:(CGSize)drawSize canvasRect:(CGRect)canvasRect;

/** Fill模式（一边填满，另一边填满或超出>=）下的的绘图尺寸 */
+(CGSize)aspectFillSizeForRawSize:(CGSize)drawSize destSize:(CGSize)destSize;

/** Fit模式（一边满屏，另一边不允许超出<=）下的的绘图尺寸 */
+(CGSize)aspectFitSizeForRawSize:(CGSize)drawSize destSize:(CGSize)destSize;

/** 给定行宽和padding，计算每个item的宽度 */
+(CGFloat)itemWidthWithLineWidth:(CGFloat)lineWidth numberOfItem:(NSUInteger)numberOfItem padding:(CGFloat)padding;
@end

NS_ASSUME_NONNULL_END
