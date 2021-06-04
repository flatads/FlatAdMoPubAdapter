//
//  TCCoordinationFunctions.h
//  TCUtil
//
//  Created by EkoHu on 2021/3/15.
//

#import <QuartzCore/QuartzCore.h>

NS_ASSUME_NONNULL_BEGIN

//align相关坐标处理
//水平方向
CGRect CGRectMoveAlignHorizontalCenter(CGRect originalRect,CGRect relativeRect,CGFloat margin); //使original水平中心=relative的水平中心
CGRect CGRectMoveLeftToRight(CGRect originalRect,CGRect relativeRect,CGFloat margin); // originalRect左边相对relative右边的位置，坐标系为从左向右
CGRect CGRectMoveLeftToLeft(CGRect originalRect,CGRect relativeRect,CGFloat margin); // originalRect左边相对relative左边的位置，坐标系为从左向右
CGRect CGRectMoveRightToLeft(CGRect originalRect,CGRect relativeRect,CGFloat margin); // originalRect右边相对relative左边的位置，坐标系为从左向右
CGRect CGRectMoveRightToRight(CGRect originalRect,CGRect relativeRect,CGFloat margin); // originalRect右边相对relative右边的位置，坐标系为从左向右
//垂直方向
CGRect CGRectMoveAlignVertivalCenter(CGRect originalRect,CGRect relativeRect,CGFloat margin); //使original垂直中心=relative的垂直中心
CGRect CGRectMoveTopToTop(CGRect originalRect,CGRect relativeRect,CGFloat margin); // originalRect顶边标相对relative顶边的位置，坐标系为从左向右
CGRect CGRectMoveTopToBottom(CGRect originalRect,CGRect relativeRect,CGFloat margin); // originalRect顶边相对relative底边的位置，坐标系为从左向右
CGRect CGRectMoveBottomToTop(CGRect originalRect,CGRect relativeRect,CGFloat margin); // originalRect底边相对relative顶边的位置，坐标系为从左向右
CGRect CGRectMoveBottomToBottom(CGRect originalRect,CGRect relativeRect,CGFloat margin); // originalRect底边相对relative底边的位置，坐标系为从左向右

NS_ASSUME_NONNULL_END
