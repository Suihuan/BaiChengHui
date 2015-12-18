//
//  SDSHDataManager.m
//  NationalTax
//
//  Created by sui huan on 13-8-23.
//  Copyright (c) 2013年 sui huan. All rights reserved.
//

#import "SDSHDataManager.h"
#include <ifaddrs.h>
#include <sys/socket.h>
#include <net/if.h>

@implementation SDSHHttpRequest

@synthesize isNeedHideHud;
@synthesize isNeedShowWaring;

- (id) initWithInterfaceName:(NSString *) interfaceName
{
    self.isNeedShowWaring = YES;
    self.isNeedHideHud = YES;
    [self setDelegate:self];
    
    NSURL *requestUrl = [[NSURL alloc] initWithString:[NSString stringWithFormat:@"%@%@", kSDSH_SYS_SERVER, interfaceName]];
    
    return [super initWithURL:requestUrl];
}

- (id) initWithURL:(NSURL *) requestUrl
{
    self.isNeedShowWaring = YES;
    self.isNeedHideHud = YES;
    [self setDelegate:self];
    [self setTimeOutSeconds:kSDSH_SYS_TIMEOUT];
    
    return [super initWithURL:requestUrl];
}

// 成功
- (void) requestFinished:(ASIHTTPRequest *) aRequest
{
    if (isNeedHideHud)
    {
        StopRequest;
    }
    
//    // 判断需不需要显示登录界面
//    NSDictionary *reponse = DeserializeNSStringAsDictionary([aRequest responseString]);
//    if ([[reponse objectForKey:@"ret"] integerValue] != 0 && [[reponse objectForKey:@"msg"] isEqualToString:@"用户已在其他地方登录"])
//    {
//        [APService setAlias:@"" callbackSelector:nil object:nil];
//        [UIAlertView showAlertTitle:@"用户已在其他地方登录!"];
//        [[JNZTAppDelegate sharedInstance] exChangeLogin];
//    }
}

// 失败
- (void) requestFailed:(ASIHTTPRequest *) aRequest
{
    if (isNeedHideHud)
    {
        StopRequest;
    }
    
    if ([[aRequest error] code] == ASIRequestTimedOutErrorType)
    {
        if (isNeedShowWaring)
        {
            AddHudFailureNotice(@"网络不给力，请稍后重试");
        }
    }
    else
    {
        if (!CheckNetWorkAvailable)
        {
            if (isNeedShowWaring)
            {
                AddHudFailureNotice(@"网络有问题，请检查网络");
            }
        }
        else
        {
            if (isNeedShowWaring)
            {
                AddHudFailureNotice(@"网络不给力，请稍后重试");
            }
        }
    }
}

+ (NSArray *) getDataCounters
{
    BOOL   success;
    struct ifaddrs *addrs;
    const struct ifaddrs *cursor;
    const struct if_data *networkStatisc;
    
    int WiFiSent = 0;
    int WiFiReceived = 0;
    int WWANSent = 0;
    int WWANReceived = 0;
    
    NSString *name=[[NSString alloc]init];
    
    success = getifaddrs(&addrs) == 0;
    if (success)
    {
        cursor = addrs;
        while (cursor != NULL)
        {
            name=[NSString stringWithFormat:@"%s",cursor->ifa_name];
            NSLog(@"ifa_name %s == %@\n", cursor->ifa_name,name);
            // names of interfaces: en0 is WiFi ,pdp_ip0 is WWAN
            if (cursor->ifa_addr->sa_family == AF_LINK)
            {
                if ([name hasPrefix:@"en"])
                {
                    networkStatisc = (const struct if_data *) cursor->ifa_data;
                    WiFiSent+=networkStatisc->ifi_obytes;
                    WiFiReceived+=networkStatisc->ifi_ibytes;
                    NSLog(@"WiFiSent %d ==%d",WiFiSent,networkStatisc->ifi_obytes);
                    NSLog(@"WiFiReceived %d ==%d",WiFiReceived,networkStatisc->ifi_ibytes);
                }
                if ([name hasPrefix:@"pdp_ip"])
                {
                    networkStatisc = (const struct if_data *) cursor->ifa_data;
                    WWANSent+=networkStatisc->ifi_obytes;
                    WWANReceived+=networkStatisc->ifi_ibytes;
                    NSLog(@"WWANSent %d ==%d",WWANSent,networkStatisc->ifi_obytes);
                    NSLog(@"WWANReceived %d ==%d",WWANReceived,networkStatisc->ifi_ibytes);
                }
            }
            cursor = cursor->ifa_next;
        }
        freeifaddrs(addrs);
    }
    
    return [NSArray arrayWithObjects:[self bytesToAvaiUnit:WiFiSent], [self bytesToAvaiUnit:WiFiReceived], [self bytesToAvaiUnit:WWANSent], [self bytesToAvaiUnit:WWANReceived], nil];
}

+ (NSString *)bytesToAvaiUnit:(int)bytes
{
    if(bytes < 1024)                // B
    {
        return [NSString stringWithFormat:@"%dB", bytes];
    }
    else if(bytes >= 1024 && bytes < 1024 * 1024)        // KB
    {
        return [NSString stringWithFormat:@"%.1fKB", (double)bytes / 1024];
    }
    else if(bytes >= 1024 * 1024 && bytes < 1024 * 1024 * 1024)        // MB
    {
        return [NSString stringWithFormat:@"%.2fMB", (double)bytes / (1024 * 1024)];
    }
    else        // GB
    {
        return [NSString stringWithFormat:@"%.3fGB", (double)bytes / (1024 * 1024 * 1024)];
    }
}

@end
