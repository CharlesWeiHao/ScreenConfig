# ScreenConfig
iPhone屏幕适配的常用宏定义。

导入到项目中，全局的pch文件中引用一下即可，
用法如下: 
1、initWithFrame:
    UIView *newView = [[UIView alloc] initWithFrame:AutoCGRectMake(20, 20, 300, 50)];
2、.frame:
    newView.frame = AutoCGRectMake(20, 20, 300, 50);
