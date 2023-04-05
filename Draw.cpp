#include "Draw.h"
void transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg)
{
	DWORD* dst = GetImageBuffer(dstimg);
	DWORD* src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = (dstimg == NULL ? getwidth() : dstimg->getwidth());
	int dst_height = (dstimg == NULL ? getheight() : dstimg->getheight());
	int iwidth = (x + src_width > dst_width) ? dst_width - x : src_width;
	int iheight = (y + src_height > dst_height) ? dst_height - y : src_height;
	if (x < 0) { src += -x;				iwidth -= -x;	x = 0; }
	if (y < 0) { src += src_width * -y;	iheight -= -y;	y = 0; }
	dst += dst_width * y + x;
	for (int iy = 0; iy < iheight; iy++)
	{
		for (int ix = 0; ix < iwidth; ix++)
		{
			int sa = ((src[ix] & 0xff000000) >> 24);
			int sr = ((src[ix] & 0xff0000) >> 16);
			int sg = ((src[ix] & 0xff00) >> 8);
			int sb = src[ix] & 0xff;
			int dr = ((dst[ix] & 0xff0000) >> 16);
			int dg = ((dst[ix] & 0xff00) >> 8);
			int db = dst[ix] & 0xff;
			dst[ix] = ((sr + dr * (255 - sa) / 255) << 16)
				| ((sg + dg * (255 - sa) / 255) << 8)
				| (sb + db * (255 - sa) / 255);
		}
		dst += dst_width;
		src += src_width;
	}
}
void transparentimage(IMAGE* dstimg, int xt, int yt, int wt, int ht,
	int xo, int yo, int wo, int ho, IMAGE* srcimg) {
	//xt ytΪĿ�괰�ڻ�ͼ���꣨���������,wt htΪ���ƵĿ��(Ҫ���ƶ��Ͷ��),xo yo wo hoΪԴ�ļ���Ӧ����,
	//xoԴ�������Ͻǵ� x ���꣬yoԴ�������Ͻǵ� y ���꣨��ԴͼƬ�����￪ʼ���ƣ�,wo,hoҪ���ƶ��Ͷ��
	HDC dstDC = GetImageHDC(dstimg);
	HDC srcDC = GetImageHDC(srcimg);
	//int w = srcimg->getwidth();
	//int h = srcimg->getheight(); 	// �ṹ��ĵ�������Ա��ʾ�����͸���ȣ�0 ��ʾȫ͸����255 ��ʾ��͸����
	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA }; 	// ʹ�� Windows GDI ����ʵ�ְ�͸��λͼ
	AlphaBlend(dstDC, xt, yt, wt, ht, srcDC, xo, yo, wo, ho, bf);
}

void transparentimage(IMAGE* dstimg, int x, int y, int w, int h, IMAGE* srcimg)
{
	HDC dstDC = GetImageHDC(dstimg);
	HDC srcDC = GetImageHDC(srcimg);
	int wo = srcimg->getwidth();
	int ho = srcimg->getheight();

	// �ṹ��ĵ�������Ա��ʾ�����͸���ȣ�0 ��ʾȫ͸����255 ��ʾ��͸����
	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
	// ʹ�� Windows GDI ����ʵ�ְ�͸��λͼ
	AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, wo, ho, bf);
}