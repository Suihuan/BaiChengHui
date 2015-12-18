//
//  UIAlertView+AlertUtils.h
//  SmartRebate
//
//  Created by Yuan on 13-2-28.
//  Copyright (c) 2013年 unionpaysmart.com. All rights reserved.
//

#import <UIKit/UIKit.h>

#pragma mark - CGRect Inline Functions
// Apple makes these CG_EXTERN, but I'm not sure why. So, I made them CG_INLINE for ease.

// Inset top of `rect' by `dy' -- i.e., increase origin.y by `dy', and decrease size.height by `dy'.
CG_INLINE CGRect
CGRectInsetTop(CGRect rect, CGFloat dy) {
    rect.origin.y += dy; rect.size.height -= dy; return rect;
}

// Inset left of `rect' by `dx' -- i.e., increase origin.x by `dx', and decrease size.width by `dx'.
CG_INLINE CGRect
CGRectInsetLeft(CGRect rect, CGFloat dx) {
    rect.origin.x += dx; rect.size.width -= dx; return rect;
}

#pragma mark - UIView Inline Functions

UIKIT_STATIC_INLINE void
UIViewSetFrameOrigin(UIView *view, CGPoint origin) {
    view.frame = CGRectMake(origin.x, origin.y, view.frame.size.width, view.frame.size.height);
}

UIKIT_STATIC_INLINE void
UIViewSetFrameSize(UIView *view, CGSize size) {
    view.frame = CGRectMake(view.frame.origin.x, view.frame.origin.y, size.width, size.height);
}

UIKIT_STATIC_INLINE void
UIViewSetFrameX(UIView *view, CGFloat x) {
    view.frame = CGRectMake(x, view.frame.origin.y, view.frame.size.width, view.frame.size.height);
}

UIKIT_STATIC_INLINE void
UIViewSetFrameY(UIView *view, CGFloat y) {
    view.frame = CGRectMake(view.frame.origin.x, y, view.frame.size.width, view.frame.size.height);
}

UIKIT_STATIC_INLINE void
UIViewSetFrameWidth(UIView *view, CGFloat width) {
    view.frame = CGRectMake(view.frame.origin.x, view.frame.origin.y, width, view.frame.size.height);
}

UIKIT_STATIC_INLINE void
UIViewSetFrameHeight(UIView *view, CGFloat height) {
    view.frame = CGRectMake(view.frame.origin.x, view.frame.origin.y, view.frame.size.width, height);
}

@interface UIAlertView (UIAlertView_AlertUtils)

+(void)showAlertTitle:(NSString*)title message:(NSString *)msg;

+(void)showAlertTitle:(NSString*)title message:(NSString *)msg delegate:(id)d;

+(void)showAlertTitle:(NSString*)msg;

+(void)showAlertTitle:(NSString*)msg delegate:(id)d;

@end

@interface UIButton (UIButton_Utils)

+(UIButton *)createButton:(CGRect)rect action:(SEL)sel delegate:(id)delegate;

+(UIButton *)createButton:(CGRect)rect action:(SEL)sel delegate:(id)delegate type:(UIButtonType)type;

+(UIButton *)createButton:(CGRect)rect action:(SEL)sel delegate:(id)delegate normalImage:(UIImage *)normalImage highlightedImage:(UIImage *)highlightedImage;

+(UIButton *)createButton:(CGRect)rect action:(SEL)sel delegate:(id)delegate normalBackgroundImage:(UIImage *)normalImage
highlightedBackgroundImage:(UIImage *)highlightedImage title:(NSString *)title font:(UIFont *)font color:(UIColor *)color
;

+(UIButton *)createButton:(CGRect)rect action:(SEL)sel delegate:(id)delegate title:(NSString *)title font:(UIFont *)font titleColor:(UIColor *)color;
@end

@interface UILabel (UILabel_Utils)

+(UILabel *)createLable:(CGRect)rect;
+(UILabel *)createLable:(CGRect)rect text:(NSString *)text font:(UIFont *)font textColor:(UIColor *)color textAlignment:(NSTextAlignment)textAlignment;
+(UILabel *)createLable:(CGRect)rect text:(NSString *)text font:(UIFont *)font textColor:(UIColor *)color  textAlignment:(NSTextAlignment)textAlignment shadowColor:(UIColor *)shadowColor shadowOffset:(CGSize)size;
@end

@interface UITextField (UITextField_Utils)

+(UITextField *)createTextField:(CGRect)rect;

+(UITextField *)createTextField:(CGRect)rect placeholder:(NSString *)placeholder delegate:(id)delegate font:(UIFont *)font textColor:(UIColor *)color;
@end

@interface UITextView (UITextView_Utils)

+(UITextView *)createUITextView:(CGRect)rect delegate:(id)delegate font:(UIFont *)font textColor:(UIColor *)color;

@end

@interface UIImage (iPhone5extension)
+ (UIImage*)imageNamedForDevice:(NSString*)name;

- (UIImage*)resizedImageToSize:(CGSize)size;

@end

@interface UIView (UIViewExtension)

//添加圆角
- (void)roundCorners:(UIRectCorner)corners radii:(CGFloat)radii;

//由view获得view所在的cell，没有返回nil
- (UITableViewCell *)parentTableViewCell;

//从view获得view所在的controller
- (UIViewController*)getViewController;

@end

@interface UITableView (UITableView_Extension)
/*根据点击的view来获取indexpath*/
- (NSIndexPath *)indexPathForTapedView:(UIView *)tapedView;

/*根据点击的view来获取cell*/
- (UITableViewCell *)cellForTapedView:(UIView *)tapedView;
@end

