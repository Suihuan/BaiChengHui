//
//  Macros.h
#import "Macros.h"
#import "NVDate.h"

#ifndef ACMacros_h
#define ACMacros_h

//沙盒路径
#define PATH_OF_APP_HOME    NSHomeDirectory()
#define PATH_OF_CACHE        [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) objectAtIndex:0]
#define PATH_OF_TEMP        NSTemporaryDirectory()
#define PATH_OF_DOCUMENT    [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]

//app的版本号
#define kAppVersion [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]

//app build版本号
#define kAppBuildVersion [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]

//app的显示名称
#define kAppDisplayName [[NSBundle mainBundle].localizedInfoDictionary objectForKey:@"CFBundleDisplayName"]

//app的identifier
#define kAppBundleIdentifier [[NSBundle mainBundle] bundleIdentifier]

//自定义NSLog
#ifdef DEBUG
#define HYLog(s, ... )   NSLog(@"<%p %@ %s:(%d)>%@",self,[[NSString stringWithUTF8String:__FILE__] lastPathComponent],__FUNCTION__,__LINE__,[NSString stringWithFormat:(s),##__VA_ARGS__])
#else
#define HYLog( s, ... )
#endif

//增加在打印图片路径时直接显示图片
#define EMBEDDED_IMAGE_START @"∂i"
#define EMBEDDED_IMAGE_END @"ƒi"
#define EMBEDDED_LINK_START @"∂a"
#define EMBEDDED_LINK_END @"ƒa"
#define AMLink(u) [NSString stringWithFormat:@"%@%@%@%@%@", EMBEDDED_LINK_START, @"<", u, @">", EMBEDDED_LINK_END]
#define AMLinkWithTitle(u, t) [NSString stringWithFormat:@"%@%@%@%@%@%@%@%@", EMBEDDED_LINK_START, @"![", t, @"]", @"<", u, @">", EMBEDDED_LINK_END]
#define AMImageLink(u) [NSString stringWithFormat:@"%@!!(1.0)@ref=\"%@\"%@", EMBEDDED_IMAGE_START,u, EMBEDDED_IMAGE_END]
#define AMImage(u) [NSString stringWithFormat:@"%@\n%@",AMLink(u),AMImageLink(u)]

// 本地化字符串
/** NSLocalizedString宏做的其实就是在当前bundle中查找资源文件名“Localizable.strings”(参数:键＋注释) */
#define PCString(x)     NSLocalizedString(x, nil)
/** NSLocalizedStringFromTable宏做的其实就是在当前bundle中查找资源文件名“xxx.strings”(参数:键＋文件名＋注释) */
#define AppLocalString(x, ...)  NSLocalizedStringFromTable(x, @"someName", nil)

//obj是否是 Null 或 Nil
#define ISEMPTY(obj) ((NSNull *)obj == [NSNull null]|| obj == nil)?YES:NO

//obj是否是 Null
#define ISNULL(obj) ((NSNull *)obj == [NSNull null])?YES:NO

//obj是否是 nil
#define ISNIL(obj) (obj == nil)?YES:NO

//obj是否是Class类型
#define ISCLASS(Class,obj)[obj isKindOfClass:[Class class]]

// 将NSDictionary转化为NSString
static inline NSString* serializeNSDictionaryAsNSString(NSDictionary *param)
{
    return [[NSString alloc] initWithData:[[CJSONSerializer serializer] serializeDictionary:param error:nil] encoding:NSUTF8StringEncoding];
}

//判断字符串是否合法
static inline BOOL isValidString(NSString *s)
{
    return (s && ISCLASS(NSString, s) && [s length]>0)?YES:NO;
}

//判断Number是否合法
static inline BOOL isValidNumber(id n)
{
    return (n && ISCLASS(NSNumber, n))?YES:NO;
}

//判断字典是否合法
static inline BOOL isValidDictionary(NSDictionary *d)
{
    return (d && ISCLASS(NSDictionary, d))?YES:NO;
}

//判断数组是否合法
static inline BOOL isValidArray(NSArray *a)
{
    return (a && ISCLASS(NSArray, a))?YES:NO;
}

static inline BOOL isValidateMobile(NSString *mobile)
{
    //手机号以13， 15，18开头，八个 \d 数字字符
    NSString *phoneRegex = @"^((13[0-9])|(15[0-9])|(18[0-9])|(14[0-9])|(17[0-9]))\\d{8}$";
    NSPredicate *phoneTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@",phoneRegex];
    //    NSLog(@"phoneTest is %@",phoneTest);
    return [phoneTest evaluateWithObject:mobile];
}

//格式化Number
static inline NSNumber * FormatNumber(NSObject *obj,id replaceNumber)
{
    NSNumber *result = replaceNumber;
    if (obj && (isValidString((NSString *)obj) || isValidNumber(obj))){
        result =  @([(NSString *)obj integerValue]);
    }
    return result;
}

//string指定宽和字体的size
#define StringSizeCustomBreakMode(string,width, font,breakmode) \
[string sizeWithFont:font constrainedToSize:CGSizeMake(width, MAXFLOAT) lineBreakMode:breakmode]

#define StringSize(string,width, font) \
[string sizeWithFont:font constrainedToSize:CGSizeMake(width, MAXFLOAT) lineBreakMode:NSLineBreakByWordWrapping]

//当string未nil，或null时格式化为replaceString
#define FormatString(string,replaceString) (string == nil || (NSNull *)string == [NSNull null])?replaceString:string

#define FS(string) (string == nil || (NSNull *)string == [NSNull null])?@"":string

#pragma mark - Frame (宏 x, y, width, height)

// App Frame
#define Application_Frame       [[UIScreen mainScreen] applicationFrame]

// App Frame Height&Width
#define App_Frame_Height        [[UIScreen mainScreen] applicationFrame].size.height
#define App_Frame_Width         [[UIScreen mainScreen] applicationFrame].size.width

// MainScreen Height&Width
#define Main_Screen_Height      [[UIScreen mainScreen] bounds].size.height
#define Main_Screen_Width       [[UIScreen mainScreen] bounds].size.width

#define kTabBarHeight 49

// View 坐标(x,y)和宽高(width,height)
#define X(v)                    (v).frame.origin.x
#define Y(v)                    (v).frame.origin.y
#define WIDTH(v)                (v).frame.size.width
#define HEIGHT(v)               (v).frame.size.height

#define MinX(v)                 CGRectGetMinX((v).frame)
#define MinY(v)                 CGRectGetMinY((v).frame)

#define MidX(v)                 CGRectGetMidX((v).frame)
#define MidY(v)                 CGRectGetMidY((v).frame)

#define MaxX(v)                 CGRectGetMaxX((v).frame)
#define MaxY(v)                 CGRectGetMaxY((v).frame)

// 系统控件默认高度
#define kStatusBarHeight        (20.f)

#define kTopBarHeight           (44.f)
#define kBottomBarHeight        (65.5f)

#define kCellDefaultHeight      (44.f)

#define kEnglishKeyboardHeight  (216.f)
#define kChineseKeyboardHeight  (252.f)

#define kScreenWidth    ([UIScreen mainScreen].applicationFrame.size.width)
#define kScreenHeight   ([UIScreen mainScreen].applicationFrame.size.height)

/* ****************************************************************************************************************** */
#pragma mark - Funtion Method (宏 方法)

//Image
#define PCImage(imageName) [UIImage imageNamed:imageName]

// PNG JPG 图片路径
#define PNGPATH(NAME)           [[NSBundle mainBundle] pathForResource:[NSString stringWithUTF8String:NAME] ofType:@"png"]
#define JPGPATH(NAME)           [[NSBundle mainBundle] pathForResource:[NSString stringWithUTF8String:NAME] ofType:@"jpg"]
#define PATH(NAME, EXT)         [[NSBundle mainBundle] pathForResource:(NAME) ofType:(EXT)]

// 加载图片
#define PNGIMAGE(NAME)          [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:@"png"]]
#define JPGIMAGE(NAME)          [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:@"jpg"]]
#define IMAGE(NAME, EXT)        [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:(EXT)]]

// 字体大小(常规/粗体)
#define BOLDSYSTEMFONT(FONTSIZE) [UIFont boldSystemFontOfSize:FONTSIZE]
#define SYSTEMFONT(FONTSIZE)    [UIFont systemFontOfSize:FONTSIZE]
#define FONT(NAME, FONTSIZE)    [UIFont fontWithName:(NAME) size:(FONTSIZE)]

// 颜色(RGB)
#define RGB(r,g,b,a) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]

// View 圆角和加边框
#define ViewBorderRadius(View, Radius, Width, Color)\
                                \
                                [View.layer setCornerRadius:(Radius)];\
                                [View.layer setMasksToBounds:YES];\
                                [View.layer setBorderWidth:(Width)];\
                                [View.layer setBorderColor:[Color CGColor]]

// View 圆角
#define ViewRadius(View, Radius)\
                                \
                                [View.layer setCornerRadius:(Radius)];\
                                [View.layer setMasksToBounds:YES]

// 当前版本
#define FSystemVersion          ([[[UIDevice currentDevice] systemVersion] floatValue])
#define DSystemVersion          ([[[UIDevice currentDevice] systemVersion] doubleValue])
#define SSystemVersion          ([[UIDevice currentDevice] systemVersion])

//如果当前系统版本小于v返回YES，否则返回no
#define SYSTEM_VERSION_LESS_THAN(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)

// 当前语言
#define CURRENTLANGUAGE         ([[NSLocale preferredLanguages] objectAtIndex:0])

// 是否Retina屏
#define isRetina                ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? \
                                CGSizeEqualToSize(CGSizeMake(640, 960), \
                                                  [[UIScreen mainScreen] currentMode].size) : \
                                NO)

// 是否iPhone5
#define isiPhone5               ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? \
                                CGSizeEqualToSize(CGSizeMake(640, 1136), \
                                                  [[UIScreen mainScreen] currentMode].size) : \
                                NO)

// 是否iPad
#define isPad                   (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

// UIView - viewWithTag
#define VIEWWITHTAG(_OBJECT, _TAG)\
                                \
                                [_OBJECT viewWithTag : _TAG]


// RGB颜色转换（16进制->10进制）
#define UIColorFromRGB(rgbValue)\
                                \
                                [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
                                                green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
                                                 blue:((float)(rgbValue & 0xFF))/255.0 \
                                                alpha:1.0]

#if TARGET_OS_IPHONE
/** iPhone Device */
#endif

#if TARGET_IPHONE_SIMULATOR
/** iPhone Simulator */
#endif

// ARC
#if __has_feature(objc_arc)
/** Compiling with ARC */
#else
/** Compiling without ARC */
#endif


#endif

//Singleton GCD
#ifndef SINGLETON_GCD
#define SINGLETON_GCD(classname)                        \
\
+ (classname *)shared##classname {                      \
\
static dispatch_once_t pred;                        \
__strong static classname * shared##classname = nil;\
dispatch_once( &pred, ^{                            \
shared##classname = [[self alloc] init]; });    \
return shared##classname;                           \
}
#endif

#ifdef __IPHONE_6_0
# define ALIGN_CENTER NSTextAlignmentCenter
#else
# define ALIGN_CENTER UITextAlignmentCenter
#endif

//用performSelector出现performSelector may cause a leak because its selector is unknown警告解决的办法

#define SuppressPerformSelectorLeakWarning(Stuff) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
Stuff; \
_Pragma("clang diagnostic pop") \
} while (0)

#define kNavigationBarHeight (iOS7?64:44)

// 将JSON数据解析为NSDictionary
#define DeserializeNSStringAsDictionary(stringValue)    [[CJSONDeserializer deserializer] deserializeAsDictionary:[stringValue dataUsingEncoding:NSUTF8StringEncoding] error:nil]

// 将JSON数据解析为NSArray
#define DeserializeNSStringAsArray(stringValue)    [[CJSONDeserializer deserializer] deserializeAsArray:[stringValue dataUsingEncoding:NSUTF8StringEncoding] error:nil]

// 判断网络是否可用
#define CheckNetWorkAvailable  [[JNZTAppDelegate sharedInstance] checkNetworkConnection]

// 开始请求
#define StartRequest   [MBProgressHUD showMessag:@"请稍后..." toView:[[JNZTAppDelegate sharedInstance] window]];

// 结束请求
#define StopRequest   [MBProgressHUD hideAllHUDsForView:[[JNZTAppDelegate sharedInstance] window] animated:YES];

#define AddHudSuccessNotice(NoticeText)   [MBProgressHUD showSuccess:NoticeText toView:[[JNZTAppDelegate sharedInstance] window]];

#define AddHudFailureNotice(NoticeText)     [MBProgressHUD showError:NoticeText toView:[[JNZTAppDelegate sharedInstance] window]];

// 创建HTTP请求
#define CreateHTTP(interfaceName) [[SDSHHttpRequest alloc] initWithInterfaceName:interfaceName];

// 增加通知
#define Add_Notification(selectName, notificaitonName) [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(selectName) name:notificaitonName object:nil];

// 增加返回按钮
#define Add_Back_Navi \
UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];\
[button setBackgroundImage:[UIImage imageNamed:@"top_back_normal"] forState:UIControlStateNormal];\
[button setBackgroundImage:[UIImage imageNamed:@"top_back_click"] forState:UIControlStateHighlighted];\
button.frame = CGRectMake(0, 0, 14, 14);\
[button addTarget:self action:@selector(clickLeftButtonItem) forControlEvents:UIControlEventTouchUpInside];\
\
UIBarButtonItem *leftItem = [[UIBarButtonItem alloc] initWithCustomView:button];\
self.navigationItem.leftBarButtonItem = leftItem;

// 增加左按钮(文字)
#define Add_LeftNavi_ButtonWithTitle(buttonName) \
UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];\
[button setBackgroundImage:[UIImage imageNamed:@"btn_navi_default"] forState:UIControlStateNormal];\
[[button titleLabel] setFont:[UIFont boldSystemFontOfSize:14]];\
button.frame = CGRectMake(0, 0, 53.5, 30);\
[button setTitle:buttonName forState:UIControlStateNormal];\
[button addTarget:self action:@selector(clickLeftButtonItem) forControlEvents:UIControlEventTouchUpInside];\
\
UIBarButtonItem *leftItem = [[UIBarButtonItem alloc] initWithCustomView:button];\
self.navigationItem.leftBarButtonItem = leftItem;

// 增加右按钮(文字)
#define Add_RightNavi_ButtonWithTitle(buttonName, fontSize) \
UIButton *button1 = [UIButton buttonWithType:UIButtonTypeCustom];\
[[button1 titleLabel] setFont:SYSTEMFONT(fontSize)];\
[button1 setBackgroundImage:[UIImage imageNamed:@"fafenxiang_send"] forState:UIControlStateNormal];\
button1.frame = CGRectMake(0, 0, 63.5, 32);\
[button1 setTitle:buttonName forState:UIControlStateNormal];\
[button1 addTarget:self action:@selector(clickRightButtonItem) forControlEvents:UIControlEventTouchUpInside];\
\
UIBarButtonItem *rightItem = [[UIBarButtonItem alloc] initWithCustomView:button1];\
self.navigationItem.rightBarButtonItem = rightItem;

#define Add_RightNaviWithImages(name1,name2,name3,name4)\
UIButton *button1 = [UIButton buttonWithType:UIButtonTypeCustom];\
button1.frame = CGRectMake(0, 0, 20, 20);\
[button1 setImage:PCImage(name1) forState:UIControlStateNormal];\
[button1 setImage:PCImage(name2) forState:UIControlStateSelected];\
[button1 addTarget:self action:@selector(clickRightButtonItem0) forControlEvents:UIControlEventTouchUpInside];\
\
UIBarButtonItem *rightItem1 = [[UIBarButtonItem alloc] initWithCustomView:button1];\
\
UIButton *button2 = [UIButton buttonWithType:UIButtonTypeCustom];\
button2.frame = CGRectMake(0, 0, 20, 20);\
[button2 setImage:PCImage(name3) forState:UIControlStateNormal];\
[button2 setImage:PCImage(name4) forState:UIControlStateSelected];\
[button2 addTarget:self action:@selector(clickRightButtonItem1) forControlEvents:UIControlEventTouchUpInside];\
\
UIBarButtonItem *rightItem2 = [[UIBarButtonItem alloc] initWithCustomView:button2];\
\
self.navigationItem.rightBarButtonItems = @[rightItem2, rightItem1];

#define Add_RightNavi_Button(imageName) \
UIButton *button1 = [UIButton buttonWithType:UIButtonTypeCustom];\
[button1 setImage:[UIImage imageNamed:imageName] forState:UIControlStateNormal];\
button1.frame = CGRectMake(0, 0, 25, 25);\
[button1 addTarget:self action:@selector(clickRightButtonItem) forControlEvents:UIControlEventTouchUpInside];\
\
UIBarButtonItem *rightItem = [[UIBarButtonItem alloc] initWithCustomView:button1];\
self.navigationItem.rightBarButtonItem = rightItem;

#define CurrentUserInfo  [NSKeyedUnarchiver unarchiveObjectWithData:[[NSUserDefaults standardUserDefaults] objectForKey:@"UserInfo"]]
// 当前使用者信息(JSON)
#define CurrentUserModel     [NSKeyedUnarchiver unarchiveObjectWithData:[[NSUserDefaults standardUserDefaults] objectForKey:@"UsedUserInfo"]]
// 当前使用者信息(NSDictionay)
#define CurrentUsedUserInfo DeserializeNSStringAsDictionary(CurrentUserModel)


// 登录用户的ID
#define CurrentLoginUserId      [[CurrentUserInfo objectForKey:@"id"] integerValue]

// 当前使用者性别
#define UserGender [CurrentUsedUserInfo objectForKey:@"gender"]
// 当前使用者体重
#define UserWeight [CurrentUsedUserInfo objectForKey:@"weight"]
// 当前使用者目标体重
#define UserTargetWeight [CurrentUsedUserInfo objectForKey:@"targetWeight"]
// 当前使用者身高
#define UserHeight [CurrentUsedUserInfo objectForKey:@"height"]
// 当前使用者年龄
static inline NSInteger UserAge()
{
    NSTimeInterval dateDiff = [[[[NVDate alloc] initUsingString:[CurrentUsedUserInfo objectForKey:@"birthday"] withFormat:@"yyyy-MM-dd HH:mm:ss"] date] timeIntervalSinceNow];
    return trunc((ABS(dateDiff))/(60*60*24))/365;
}

#define CurrentToken  [[NSUserDefaults standardUserDefaults] objectForKey:@"Token"]
#define CurrentUserName  [[NSUserDefaults standardUserDefaults] objectForKey:@"UserName"]
#define CurrentUserType  [[NSUserDefaults standardUserDefaults] objectForKey:@"UserType"]
#define CurrentUserId  [[NSUserDefaults standardUserDefaults] objectForKey:@"UserId"]

#define kLastEcgData(userid)     [[NSUserDefaults standardUserDefaults] objectForKey:[NSString stringWithFormat:@"ECGLASTDATA_%ld", userid]]
#define kLastBpmData(userid)     [[NSUserDefaults standardUserDefaults] objectForKey:[NSString stringWithFormat:@"BPMLASTDATA_%ld", userid]]
#define kLastScaleData(userid)     [[NSUserDefaults standardUserDefaults] objectForKey:[NSString stringWithFormat:@"SCALELASTDATA_%ld", userid]]

#define CurrentMobile     [CurrentUserInfo objectForKey:@"phone"]

#define ISTEACHER   ([[CurrentUserInfo objectForKey:@"type"] integerValue]==2?YES:NO)

#define iOS7 ([[[UIDevice currentDevice] systemVersion] floatValue]>=7.0 ? YES : NO)

#define ReadCartNum  [[NSUserDefaults standardUserDefaults] integerForKey:@"ShopCart"]

#define APP (AppDelegate*)[UIApplication sharedApplication].delegate
#define Version  [[[UIDevice currentDevice] systemVersion] floatValue]
#define  Width  (0.1*1024/125)  //两点的间距  128采样率
#define NSStringFromInt(intValue) [NSString stringWithFormat:@"%ld",intValue]
#define  P_count    ((int)(320/Width))   //正常测量是的截图
#define  Show_count  ((int)(640/Width)
#define SHAKING             @"SHAKING"
