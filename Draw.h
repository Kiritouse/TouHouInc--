#pragma once
#include <conio.h>
#include "GameManager.h"
#include "LoadResources.h"
#pragma comment(lib, "MSIMG32.LIB")
/// <summary>
///指定透明色贴图（基于 Windows API 函数 TransparentBlt）
/// </summary>
/// <param name="dstimg">目标 IMAGE 对象指针。NULL 表示默认窗体</param>
/// <param name="x">目标贴图位置</param>
/// <param name="y">目标贴图位置</param>
/// <param name="srcimg">目标贴图位置</param>
/// <param name="transparentcolor">透明色。srcimg 的该颜色并不会复制到 dstimg 上，从而实现透明贴图</param>
void drawTransparentImage(IMAGE* dstimg, int x, int y, IMAGE* srcimg, UINT transparentcolor);
/// <summary>
///使用三元光栅操作实现透明贴图
///</summary>
///<param name="x">目标贴图位置</param>
///<param name="y">目标贴图位置</param>
///<param name="srcimg">目标贴图位置</param>
///<param name="maskimg">目标贴图位置</param>
void drawTransparentImage(int x, int y, IMAGE* srcimg, IMAGE* maskimg);
/// <summary>
///  根据 png 的 alpha 信息实现半透明贴图（基于直接操作显示缓冲区）
/// </summary>
/// <param name="dstimg">目标 IMAGE 对象指针。NULL 表示默认窗体</param>
/// <param name="x">目标贴图位置</param>
/// <param name="y">目标贴图位置</param>
/// <param name="srcimg">源 IMAGE 对象指针。NULL 表示默认窗体</param>
void drawBlendTransparentImage(IMAGE* dstimg, int x, int y, IMAGE* srcimg);

