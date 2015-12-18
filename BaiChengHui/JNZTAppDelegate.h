//
//  AppDelegate.h
//  BaiChengHui
//
//  Created by suihuan on 15/12/17.
//  Copyright (c) 2015年 ZhongTian Tec. inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface JNZTAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;
@property (strong, nonatomic) UITabBarController *tabBarController;

+ (JNZTAppDelegate *) sharedInstance;
- (BOOL) checkNetworkConnection;

@end

