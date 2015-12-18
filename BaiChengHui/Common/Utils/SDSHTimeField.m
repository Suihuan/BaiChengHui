//
//  SDSHTimeField.m
//  LiuFuYa
//
//  Created by suihuan on 14-11-25.
//  Copyright (c) 2014年 suihuan. All rights reserved.
//

#import "SDSHTimeField.h"

@implementation SDSHTimeField

- (id) initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    
    if (self)
    {
        self.contentVerticalAlignment = UIControlContentVerticalAlignmentCenter;
        
//        UIView *leftView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 10, frame.size.height)];
//        self.leftViewMode = UITextFieldViewModeAlways;
//        self.leftView = leftView;
        self.font = SYSTEMFONT(14);
        
        datePicker = [[UIDatePicker alloc] initWithFrame:CGRectMake(0, 0, 1024, kEnglishKeyboardHeight)];
        datePicker.datePickerMode = UIDatePickerModeDate;
        self.inputView = datePicker;
        
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
            self.text = [[[NVDate alloc] initUsingDate:[datePicker date]] stringValueWithFormat:@"yyyy-MM-dd"];
            [self resignFirstResponder];
        }];
        [accessView addSubview:confirmButton];
    }
    
    return self;
}

//- (id) initWithFrame:(CGRect)frame withDateMode:(UIDatePickerMode) dateMode
//{
//    self = [super initWithFrame:frame];
//    
//    if (self)
//    {
//        self.contentVerticalAlignment = UIControlContentVerticalAlignmentCenter;
//        
//        UIView *leftView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 10, frame.size.height)];
//        self.leftViewMode = UITextFieldViewModeAlways;
//        self.leftView = leftView;
//        self.font = SYSTEMFONT(16);
//        
//        ymPicker = [[SRMonthPicker alloc] initWithFrame:CGRectMake(0, 0, 1024, kEnglishKeyboardHeight)];
//        ymPicker.maximumYear = @2100;
//        ymPicker.minimumYear = @1900;
//        ymPicker.yearFirst = YES;
//        self.inputView = ymPicker;
//        
//        UIView *accessView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 1024, 40)];
//        accessView.backgroundColor = RGB(218, 218, 218, 1);
//        self.inputAccessoryView = accessView;
//        
//        UIButton *cancelButton = [UIButton buttonWithType:UIButtonTypeCustom];
//        cancelButton.frame = CGRectMake(20, 5, 65, 30);
//        [cancelButton setTitle:@"取消" forState:UIControlStateNormal];
//        [cancelButton setTitleColor:RGB(0, 31, 255, 1) forState:UIControlStateNormal];
//        [cancelButton handleControlEvent:UIControlEventTouchUpInside withBlock:^(id sender) {
//            [self resignFirstResponder];
//        }];
//        [accessView addSubview:cancelButton];
//        
//        UIButton *confirmButton = [UIButton buttonWithType:UIButtonTypeCustom];
//        confirmButton.frame = CGRectMake(1024-85, 5, 65, 30);
//        [confirmButton setTitle:@"确定" forState:UIControlStateNormal];
//        [confirmButton setTitleColor:RGB(0, 31, 255, 1) forState:UIControlStateNormal];
//        [confirmButton handleControlEvent:UIControlEventTouchUpInside withBlock:^(id sender) {
//            self.text = [[[NVDate alloc] initUsingDate:[ymPicker date]] stringValueWithFormat:@"yyyy-MM"];
//            [self resignFirstResponder];
//            
//            if (self.doneDelegate && [self.doneDelegate respondsToSelector:@selector(didClickDoneWithField:)])
//            {
//                [self.doneDelegate didClickDoneWithField:self];
//            }
//        }];
//        [accessView addSubview:confirmButton];
//    }
//    
//    return self;
//}

@end
