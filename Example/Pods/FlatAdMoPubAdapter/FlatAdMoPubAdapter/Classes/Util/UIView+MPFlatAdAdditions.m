#import "UIView+MPFlatAdAdditions.h"

@implementation UIView (MPFlatAdAdditions)

- (void)fa_centerInSuperview
{
  UIView *superview = self.superview;
  if (!superview) {
    return;
  }

  self.translatesAutoresizingMaskIntoConstraints = NO;

  [superview addConstraint:[NSLayoutConstraint constraintWithItem:self
                                                        attribute:NSLayoutAttributeCenterX
                                                        relatedBy:NSLayoutRelationEqual
                                                           toItem:superview
                                                        attribute:NSLayoutAttributeCenterX
                                                       multiplier:1
                                                         constant:0]];
  [superview addConstraint:[NSLayoutConstraint constraintWithItem:self
                                                        attribute:NSLayoutAttributeCenterY
                                                        relatedBy:NSLayoutRelationEqual
                                                           toItem:superview
                                                        attribute:NSLayoutAttributeCenterY
                                                       multiplier:1
                                                         constant:0]];
}

- (void)fa_matchSuperviewSize
{
  UIView *superview = self.superview;
  if (!superview) {
    return;
  }

  self.translatesAutoresizingMaskIntoConstraints = NO;

  [superview addConstraint:[NSLayoutConstraint constraintWithItem:self
                                                        attribute:NSLayoutAttributeWidth
                                                        relatedBy:NSLayoutRelationEqual
                                                           toItem:superview
                                                        attribute:NSLayoutAttributeWidth
                                                       multiplier:1
                                                         constant:0]];
  [superview addConstraint:[NSLayoutConstraint constraintWithItem:self
                                                        attribute:NSLayoutAttributeHeight
                                                        relatedBy:NSLayoutRelationEqual
                                                           toItem:superview
                                                        attribute:NSLayoutAttributeHeight
                                                       multiplier:1
                                                         constant:0]];
}

- (void)fa_fillSuperview
{
  [self fa_centerInSuperview];
  [self fa_matchSuperviewSize];
}

@end
