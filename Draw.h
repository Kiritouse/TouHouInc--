#pragma once
#include <conio.h>
#include "GameManager.h"
#include "LoadResources.h"
#pragma comment(lib, "MSIMG32.LIB")
#pragma comment(lib,"Winmm.lib") 
/// <summary>
/// ͸����ͼ����
/// </summary>
/// <param name="dstimg">Ŀ�� IMAGE ����ָ�롣NULL ��ʾĬ�ϴ���</param>
/// <param name="x">Ŀ����ͼλ��(Ҫ��������)</param>
/// <param name="y">Ŀ����ͼλ��(Ҫ��������)</param>
/// <param name="srcimg">ԴͼƬ</param>
void transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg);
/// <summary>
/// ���Ʋ�������͸����ͼ����
/// </summary>
/// <param name="dstimg">Ŀ�� IMAGE ����ָ�롣NULL ��ʾĬ�ϴ���</param>
/// <param name="xt">Ŀ���ͼ�����������</param>
/// <param name="yt">Ŀ���ͼ�����������</param>
/// <param name="wt">Ŀ���ͼ������ƿ��</param>
/// <param name="ht">Ŀ���ͼ������Ƹ߶�</param>
/// <param name="xo">Դ�ļ�������ѡ������</param>
/// <param name="yo">Դ�ļ�������ѡ������</param>
/// <param name="wo">Դ�ļ�������ѡ��Ŀ��</param>
/// <param name="ho">Դ�ļ�������ѡ��ĸ߶�</param>
/// <param name="srcimg">ԴͼƬָ��</param>
void transparentimage(IMAGE* dstimg, int xt, int yt, int wt, int ht,
	int xo, int yo, int wo, int ho, IMAGE* srcimg);
/// <summary>
/// ���Զ�����ƿ�ȵ�
/// </summary>
/// <param name="dstimg">Ŀ�� IMAGE ����ָ�롣NULL ��ʾĬ�ϴ���</param>
/// <param name="x">Ŀ���ͼ�����������</param>
/// <param name="y">Ŀ���ͼ�����������</param>
/// <param name="w">Ŀ���ͼ������ƿ��<</param>
/// <param name="h">Ŀ���ͼ������Ƹ߶�</param>
/// <param name="srcimg">ԴͼƬָ��</param>
void transparentimage(IMAGE* dstimg, int x, int y, int w, int h, IMAGE* srcimg);

void deleteImage();
