//
//  JNZTMoreViewController.m
//  BaiChengHui
//
//  Created by suihuan on 15/12/17.
//  Copyright (c) 2015年 ZhongTian Tec. inc. All rights reserved.
//

#import "JNZTMoreViewController.h"

@interface JNZTMoreViewController ()

@end

@implementation JNZTMoreViewController

- (id) init
{
    self = [super init];
    
    if (self)
    {
        self.tabBarItem.image = PCImage(@"butom_title_5_h");
        self.tabBarItem.selectedImage = [PCImage(@"butom_title_5_r") imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
    }
    
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
