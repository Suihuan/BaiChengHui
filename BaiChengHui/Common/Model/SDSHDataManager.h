//
//  SDSHDataManager.h
//  NationalTax
//
//  Created by sui huan on 13-8-23.
//  Copyright (c) 2013年 sui huan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ASIFormDataRequest.h"
#import "Reachability.h"

// 服务器地址
#define kSDSH_SYS_SERVER          @"http://120.27.35.94:8888/jk/"
//#define kSDSH_SYS_SERVER          @"http://office.ousutec.cn:202/webapi.ashx?"

// 资源路径
#define kSDSH_SYS_FILEPATH        @"http://120.27.35.94:8888/"
//#define kSDSH_SYS_FILEPATH        @"http://office.ousutec.cn:202"

// 超时时间
#define kSDSH_SYS_TIMEOUT     8

@interface SDSHHttpRequest : ASIFormDataRequest <ASIHTTPRequestDelegate>

@property (nonatomic, assign) BOOL isNeedShowWaring;
@property (nonatomic, assign) BOOL isNeedHideHud;

- (id) initWithInterfaceName:(NSString *) interfaceName;
+ (NSArray *) getDataCounters;

@end
