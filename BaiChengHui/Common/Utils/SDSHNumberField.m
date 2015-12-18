//
//  SDSHNumberField.m
//  ZhongYiWang
//
//  Created by suihuan on 15-4-23.
//  Copyright (c) 2015年 suihuan. All rights reserved.
//

#import "SDSHNumberField.h"

@implementation SDSHNumberField

- (id) initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    
    if (self)
    {
        self.contentVerticalAlignment = UIControlContentVerticalAlignmentCenter;
        self.keyboardType = UIKeyboardTypeDecimalPad;
        
//        UIView *leftView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 10, frame.size.height)];
//        self.leftViewMode = UITextFieldViewModeAlways;
//        self.leftView = leftView;
//        self.font = SYSTEMFONT(16);
//        
//        self.layer.borderWidth = 0.6;
//        self.layer.borderColor = RGB(191, 191, 191, 1).CGColor;
        
        UIView *accessView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, 40)];
        accessView.backgroundColor = RGB(218, 218, 218, 1);
        self.inputAccessoryView = accessView;
        
        UIButton *cancelButton = [UIButton buttonWithType:UIButtonTypeCustom];
        cancelButton.frame = CGRectMake(20, 5, 65, 30);
        [cancelButton setTitle:@"取消" forState:UIControlStateNormal];
        [cancelButton setTitleColor:RGB(0, 31, 255, 1) forState:UIControlStateNormal];
        [cancelButton handleControlEvent:UIControlEventTouchUpInside withBlock:^(id sender) {
            [self resignFirstResponder];
        }];
        [accessView addSubview:cancelButton];
        
        UIButton *confirmButton = [UIButton buttonWithType:UIButtonTypeCustom];
        confirmButton.frame = CGRectMake(kScreenWidth-85, 5, 65, 30);
        [confirmButton setTitle:@"确定" forState:UIControlStateNormal];
        [confirmButton setTitleColor:RGB(0, 31, 255, 1) forState:UIControlStateNormal];
        [confirmButton handleControlEvent:UIControlEventTouchUpInside withBlock:^(id sender) {
            [self resignFirstResponder];
        }];
        [accessView addSubview:confirmButton];
    }
    
    return self;
}

@end
