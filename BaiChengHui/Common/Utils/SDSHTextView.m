//
//  SDSHTextView.m
//  AiBoCar
//
//  Created by suihuan on 15-3-16.
//  Copyright (c) 2015年 suihuan. All rights reserved.
//

#import "SDSHTextView.h"

@implementation SDSHTextView

- (id) initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    
    if (self)
    {
        self.font = SYSTEMFONT(15);
        
        UIView *footerView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, 40)];
        footerView.backgroundColor = RGB(233, 233, 233, 1);
        
        UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
        button.frame = CGRectMake(kScreenWidth-60, 0, 50, 40);
        [[button titleLabel] setFont:SYSTEMFONT(14)];
        [button setTitle:@"完成" forState:UIControlStateNormal];
        [button setTitleColor:RGB(246, 63, 78, 1) forState:UIControlStateNormal];
        [button handleControlEvent:UIControlEventTouchUpInside withBlock:^(id sender) {
            [self resignFirstResponder];
        }];
        [footerView addSubview:button];
        
        self.inputAccessoryView = footerView;
    }
    
    return self;
}

@end
