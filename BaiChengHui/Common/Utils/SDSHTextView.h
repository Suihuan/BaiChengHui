//
//  SDSHTextView.h
//  AiBoCar
//
//  Created by suihuan on 15-3-16.
//  Copyright (c) 2015年 suihuan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PlaceholderTextView.h"

@interface SDSHTextView : PlaceholderTextView <UITextViewDelegate>
{
    UILabel *placeLabel;
    NSString *placeText;
}

- (void) setPlaceholder:(NSString *)placeholder;

@end
