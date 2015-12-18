//
//  JNZTHomeViewController.m
//  BaiChengHui
//
//  Created by suihuan on 15/12/17.
//  Copyright (c) 2015年 ZhongTian Tec. inc. All rights reserved.
//

#import "JNZTHomeViewController.h"

@interface JNZTHomeViewController () <UITableViewDataSource, UITableViewDelegate>
{
    UITableView *homeTableView;
    
    // 顶部广告
    NSMutableArray *topAdArray;
    // 顶部广告的ScrollView
    UIScrollView *topAdScrollView;
    // 顶部PageControl
    UIPageControl *topAdPageControl;
}

@end

@implementation JNZTHomeViewController

- (id) init
{
    self = [super init];
    
    if (self)
    {
        self.tabBarItem.image = PCImage(@"butom_title_1_h");
        self.tabBarItem.selectedImage = [PCImage(@"butom_title_1_r") imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
    }
    
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor yellowColor];
    
//    self.title = @"百城惠";
    topAdArray = [[NSMutableArray alloc] initWithCapacity:5];
    
    UIView *headerView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, 118)];
    
    topAdScrollView = [[UIScrollView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, 118)];
    topAdScrollView.pagingEnabled = YES;
    topAdScrollView.showsHorizontalScrollIndicator = NO;
    topAdScrollView.showsVerticalScrollIndicator = NO;
    topAdScrollView.delegate = self;
    [headerView addSubview:topAdScrollView];
    
    topAdPageControl = [[UIPageControl alloc] initWithFrame:CGRectMake(0, 98, kScreenWidth, 20)];
    [headerView addSubview:topAdPageControl];
    
    homeTableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, HEIGHT(self.view) - kNavigationBarHeight)];
    homeTableView.dataSource = self;
    homeTableView.delegate = self;
    [self.view addSubview:homeTableView];
    
    // 刷新
    homeTableView.header = [MJRefreshNormalHeader headerWithRefreshingBlock:^{
        
    }];
    // 加载
    homeTableView.footer = [MJRefreshBackNormalFooter footerWithRefreshingBlock:^{
        
    }];
    
    homeTableView.tableHeaderView = headerView;
    UIView *footer = [[UIView alloc] initWithFrame:CGRectZero];
    homeTableView.tableFooterView = footer;
    
    [self sendLoadAdListWithAgentcodnum:@"A3708000001" type:@"首页顶部" correspond:@""];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - 顶部广告位刷新
- (void) reloadTopAdScrollView
{
    [topAdScrollView setContentSize:CGSizeMake(([topAdArray count]+2)*kScreenWidth, 0)];
    [topAdScrollView setContentOffset:CGPointMake(kScreenWidth, 0)];
    topAdPageControl.numberOfPages = [topAdArray count];
    [topAdPageControl setCurrentPageIndicatorTintColor:[UIColor redColor]];
    [topAdPageControl setPageIndicatorTintColor:[UIColor yellowColor]];
    
    for (NSInteger i = 0; i < [topAdArray count]+2; i++)
    {
        NSDictionary *dict = nil;
        
        if (i == 0)
        {
            dict = [topAdArray lastObject];
        }
        else if (i == topAdArray.count+1)
        {
            dict = [topAdArray firstObject];
        }
        else
        {
            dict = [topAdArray objectAtIndex:i-1];
        }
        
        NSLog(@"%@", [NSString stringWithFormat:@"%@%@", kSDSH_SYS_FILEPATH, [dict objectForKey:@"iosAd"]]);
        UIButton *adButton = [UIButton buttonWithType:UIButtonTypeCustom];
        adButton.frame = CGRectMake(i*kScreenWidth, 0, kScreenWidth, 118);
        [adButton sd_setImageWithURL:[NSURL URLWithString:[NSString stringWithFormat:@"%@%@", kSDSH_SYS_FILEPATH, [dict objectForKey:@"iosAd"]]] forState:UIControlStateNormal placeholderImage:PCImage(@"placeholder")];
        [adButton handleControlEvent:UIControlEventTouchUpInside withBlock:^(id sender) {
            
        }];
        [topAdScrollView addSubview:adButton];
    }
}

#pragma mark - UITableViewDataSource
- (NSInteger) numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger) tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 0;
}

- (CGFloat) tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 80;
}

- (UITableViewCell *) tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *stadCellIndentifier = @"stadCellIndentifier";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:stadCellIndentifier];
    
    if (cell == nil)
    {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:stadCellIndentifier];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
    }
    
    return cell;
}

#pragma mark - 数据处理
- (void) sendLoadAdListWithAgentcodnum:(NSString *) agentcodnum type:(NSString *) type correspond:(NSString *) Correspond
{
    StartRequest;
    
    SDSHHttpRequest *_request = CreateHTTP(@"GetAdvert");
    [_request setPostValue:agentcodnum forKey:@"Agentcodnum"];
    [_request setPostValue:type forKey:@"type"];
    [_request setPostValue:Correspond forKey:@"Correspond"];
    
    __weak SDSHHttpRequest *request = _request;
    
    [_request setCompletionBlock:^{
        if (isValidArray(DeserializeNSStringAsArray([request responseString])))
        {
            [topAdArray setArray:DeserializeNSStringAsArray([request responseString])];
        }
        [self reloadTopAdScrollView];
    }];
    
    [_request startAsynchronous];
}

#pragma mark - UIScrollViewDelegate
- (void) scrollViewDidEndDecelerating:(UIScrollView *)scrollView
{
    // 顶部广告
    if ([scrollView isEqual:topAdScrollView])
    {
        NSInteger pageIndex = topAdScrollView.contentOffset.x/kScreenWidth;
        if (pageIndex == 0)
        {
            topAdPageControl.currentPage = topAdArray.count;
            [topAdScrollView setContentOffset:CGPointMake((topAdArray.count)*kScreenWidth, 0)];
        }
        else if (pageIndex < topAdArray.count+1)
        {
            topAdPageControl.currentPage = pageIndex-1;
        }
        else
        {
            topAdPageControl.currentPage = 0;
            [topAdScrollView setContentOffset:CGPointMake(kScreenWidth, 0)];
        }
    }
}

@end
