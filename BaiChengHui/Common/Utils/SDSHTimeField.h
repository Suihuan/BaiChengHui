//
//  SDSHTimeField.h
//  LiuFuYa
//
//  Created by suihuan on 14-11-25.
//  Copyright (c) 2014年 suihuan. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol SDSHTimeFieldDelegate;

@interface SDSHTimeField : UITextField
{
    UIDatePicker *datePicker;
}

@property (nonatomic, assign) id<SDSHTimeFieldDelegate> doneDelegate;

//- (id) initWithFrame:(CGRect)frame withDateMode:(UIDatePickerMode) dateMode;

@end

@protocol SDSHTimeFieldDelegate <NSObject>

- (void) didClickDoneWithField:(SDSHTimeField *) timeField;

@end
