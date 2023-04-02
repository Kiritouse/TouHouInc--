#pragma once
#include <conio.h>
#include "GameManager.h"
#include "LoadResources.h"
#pragma comment(lib, "MSIMG32.LIB")
/// <summary>
///ָ��͸��ɫ��ͼ������ Windows API ���� TransparentBlt��
/// </summary>
/// <param name="dstimg">Ŀ�� IMAGE ����ָ�롣NULL ��ʾĬ�ϴ���</param>
/// <param name="x">Ŀ����ͼλ��</param>
/// <param name="y">Ŀ����ͼλ��</param>
/// <param name="srcimg">Ŀ����ͼλ��</param>
/// <param name="transparentcolor">͸��ɫ��srcimg �ĸ���ɫ�����Ḵ�Ƶ� dstimg �ϣ��Ӷ�ʵ��͸����ͼ</param>
void drawTransparentImage(IMAGE* dstimg, int x, int y, IMAGE* srcimg, UINT transparentcolor);
/// <summary>
///ʹ����Ԫ��դ����ʵ��͸����ͼ
///</summary>
///<param name="x">Ŀ����ͼλ��</param>
///<param name="y">Ŀ����ͼλ��</param>
///<param name="srcimg">Ŀ����ͼλ��</param>
///<param name="maskimg">Ŀ����ͼλ��</param>
void drawTransparentImage(int x, int y, IMAGE* srcimg, IMAGE* maskimg);
/// <summary>
///  ���� png �� alpha ��Ϣʵ�ְ�͸����ͼ������ֱ�Ӳ�����ʾ��������
/// </summary>
/// <param name="dstimg">Ŀ�� IMAGE ����ָ�롣NULL ��ʾĬ�ϴ���</param>
/// <param name="x">Ŀ����ͼλ��</param>
/// <param name="y">Ŀ����ͼλ��</param>
/// <param name="srcimg">Դ IMAGE ����ָ�롣NULL ��ʾĬ�ϴ���</param>
void drawBlendTransparentImage(IMAGE* dstimg, int x, int y, IMAGE* srcimg);

