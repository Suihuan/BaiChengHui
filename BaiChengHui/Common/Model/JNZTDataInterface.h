//
//  JNZTDataInterface.h
//  BaiChengHui
//
//  Created by suihuan on 15/12/18.
//  Copyright (c) 2015年 ZhongTian Tec. inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JNZTDataInterface : NSObject

// 获取广告
+ (NSArray *) sendLoadAdListWithAgentcodnum:(NSString *) agentcodnum type:(NSString *) type correspond:(NSString *) Correspond;

@end
