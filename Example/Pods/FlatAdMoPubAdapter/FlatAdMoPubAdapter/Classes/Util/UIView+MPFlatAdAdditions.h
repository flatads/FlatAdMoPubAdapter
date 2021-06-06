#import <UIKit/UIKit.h>

@interface UIView (MPFlatAdAdditions)

/// Adds constraints to the receiver's superview that keep the receiver the same size and position
/// as the superview.
- (void)fa_fillSuperview;

@end
