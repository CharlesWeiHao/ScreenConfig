//
//  DeviceScreenTools.h
//  ScreenDemo
//
//  Created by Howie on 2018/12/26.
//  Copyright © 2018年 Howie. All rights reserved.
//

#ifndef DeviceScreenTools_h
#define DeviceScreenTools_h

/** ----------------------------------------- 设备的屏幕宽高 -------------------------------------------- */
/** 获取设备屏幕的宽度 */
#define ScreenWidth  [UIScreen mainScreen].bounds.size.width
/** 获取设备屏幕的高度*/
#define ScreenHeight [UIScreen mainScreen].bounds.size.height

/** 判断当前机型是否有齐刘海（iPhone X 系列机型）*/
#define iS_iPhoneX \
({BOOL isPhoneX = NO;\
if (@available(iOS 11.0, *)) {\
isPhoneX = [[UIApplication sharedApplication] delegate].window.safeAreaInsets.bottom > 0.0;\
}\
(isPhoneX);})

/** 状态栏高度 */
#define StatusBarHeight (iS_iPhoneX ? 44.f : 20.f)
/** 导航栏高度（不包含状态栏）*/
#define NavigationBarHeight 44.0f
/** 导航栏+状态栏的高度 */
#define NavigationBarAndStatusBarHeight StatusBarHeight + NavigationBarHeight

/** TabBar底部安全区域 */
#define SafeAreaHeight (iS_iPhoneX ? 34.f : 0)
/** TabBar高度 */
#define TabBarHeight SafeAreaHeight + 49.f

/** ----------------------------------------- 屏幕适配 -------------------------------------------- */
/** 是否为iPhone机型 */
#define iS_iPhone ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone)
/** 以4.7寸屏为例，当前设备的屏幕宽度比例 */
#define AutoSizeScaleX (iS_iPhone ? (ScreenWidth / 375) : 1)
/** 以4.7寸屏为例，当前设备的屏幕高度比例 */
#define AutoSizeScaleY (iS_iPhone ? (ScreenHeight / 667) : 1)

/** 给定view宽度，根据屏幕高度比例来适配view宽度 */
#define ScaleWidth(width) (width * AutoSizeScaleX)
/** 给定view高度，根据屏幕宽度比例来适配view高度 */
#define ScaleHeight(height) (height * AutoSizeScaleY)

/** 自适应 系统默认字体大小 */
#define AutoFontSize(size) [UIFont systemFontOfSize:(size * AutoSizeScaleX)]
/** 自适应 系统默认加粗字体大小 */
#define AutoBoldFontSize(size) [UIFont boldSystemFontOfSize:(size * AutoSizeScaleX)]

/** 屏幕适配比例 */
#define AutoCGRectMake(x, y, width, height) (CGRectMake(x * AutoSizeScaleX, y * AutoSizeScaleY, width * AutoSizeScaleX, height * AutoSizeScaleY))

#endif /* DeviceScreenTools_h */
