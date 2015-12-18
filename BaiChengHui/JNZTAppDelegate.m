//
//  AppDelegate.m
//  BaiChengHui
//
//  Created by suihuan on 15/12/17.
//  Copyright (c) 2015年 ZhongTian Tec. inc. All rights reserved.
//

#import "JNZTAppDelegate.h"
#import "JNZTHomeViewController.h"
#import "JNZTShopViewController.h"
#import "JNZTShakeViewController.h"
#import "JNZTPersonalViewController.h"
#import "JNZTMoreViewController.h"
#import <SystemConfiguration/SystemConfiguration.h>
#import <netdb.h>

@interface JNZTAppDelegate ()

@end

@implementation JNZTAppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    
    [application setStatusBarStyle:UIStatusBarStyleLightContent];
    
    // 设置导航栏属性
    [[UINavigationBar appearance] setBackgroundImage:PCImage(@"headr_128") forBarMetrics:UIBarMetricsDefault];
    [[UINavigationBar appearance] setShadowImage:[[UIImage alloc] init]];
    
//    [[UITabBarItem appearance] setTitleTextAttributes:[NSDictionary dictionaryWithObjectsAndKeys:RGB(101, 170, 240, 1), NSForegroundColorAttributeName, nil] forState:UIControlStateSelected];
//    [[UITabBarItem appearance] setTitleTextAttributes:[NSDictionary dictionaryWithObjectsAndKeys:RGB(176, 176, 176, 1), NSForegroundColorAttributeName, nil] forState:UIControlStateNormal];
//    [[UITabBar appearance] setTintColor:RGB(28, 28, 28, 1)];
    
    JNZTHomeViewController *homeVC = [[JNZTHomeViewController alloc] init];
    JNZTShopViewController *shopVC = [[JNZTShopViewController alloc] init];
    JNZTShakeViewController *shakeVC = [[JNZTShakeViewController alloc] init];
    JNZTPersonalViewController *personalVC = [[JNZTPersonalViewController alloc] init];
    JNZTMoreViewController *moreVC = [[JNZTMoreViewController alloc] init];
    
    UINavigationController *homeNavi = [[UINavigationController alloc] initWithRootViewController:homeVC];
    UINavigationController *shopNavi = [[UINavigationController alloc] initWithRootViewController:shopVC];
    UINavigationController *shakeNavi = [[UINavigationController alloc] initWithRootViewController:shakeVC];
    UINavigationController *personalNavi = [[UINavigationController alloc] initWithRootViewController:personalVC];
    UINavigationController *moreNavi = [[UINavigationController alloc] initWithRootViewController:moreVC];
    
    NSArray *viewControllers = @[homeNavi, shopNavi, shakeNavi, personalNavi, moreNavi];
    
    self.tabBarController = [[UITabBarController alloc] init];
    self.tabBarController.viewControllers = viewControllers;
    
    self.window.rootViewController = self.tabBarController;
    
    [self.window makeKeyAndVisible];
    
    return YES;
}

+ (JNZTAppDelegate *) sharedInstance
{
    return (JNZTAppDelegate *)[[UIApplication sharedApplication] delegate];
}

- (BOOL) checkNetworkConnection
{
    struct sockaddr_in zeroAddress;
    bzero(&zeroAddress, sizeof(zeroAddress));
    zeroAddress.sin_len = sizeof(zeroAddress);
    zeroAddress.sin_family = AF_INET;
    
    SCNetworkReachabilityRef defaultRouteReachability = SCNetworkReachabilityCreateWithAddress(NULL, (struct sockaddr *)&zeroAddress);
    SCNetworkReachabilityFlags flags;
    
    BOOL didRetrieveFlags = SCNetworkReachabilityGetFlags(defaultRouteReachability, &flags);
    CFRelease(defaultRouteReachability);
    
    if (!didRetrieveFlags) {
        printf("Error. Count not recover network reachability flags\n");
        return NO;
    }
    
    BOOL isReachable = flags & kSCNetworkFlagsReachable;
    BOOL needsConnection = flags & kSCNetworkFlagsConnectionRequired;
    return (isReachable && !needsConnection) ? YES : NO;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
