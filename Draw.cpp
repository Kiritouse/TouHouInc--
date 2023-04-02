#include "Draw.h"
void drawTransparentImage(IMAGE* dstimg, int x, int y, IMAGE* srcimg, UINT transparentcolor) {
	HDC dstDC = GetImageHDC(dstimg);
	HDC srcDC = GetImageHDC(srcimg);
	int w = srcimg->getwidth();
	int h = srcimg->getheight();

	// ʹ�� Windows GDI ����ʵ��͸��λͼ
	TransparentBlt(dstDC, x, y, w, h, srcDC, 0, 0, w, h, transparentcolor);
}
void drawTransparentImage(int x, int y, IMAGE* srcimg, IMAGE* maskimg) {
	putimage(x, y, maskimg, SRCAND);
	putimage(x, y, srcimg, SRCPAINT);
}
void drawBlendTransparentImage(IMAGE* dstimg, int x, int y, IMAGE* srcimg) {
	DWORD* dst = GetImageBuffer(dstimg);
	DWORD* src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = (dstimg == NULL ? getwidth() : dstimg->getwidth());
	int dst_height = (dstimg == NULL ? getheight() : dstimg->getheight());

	// ������ͼ��ʵ�ʳ���
	int iwidth = (x + src_width > dst_width) ? dst_width - x : src_width;		// �������ұ߽�
	int iheight = (y + src_height > dst_height) ? dst_height - y : src_height;	// �������±߽�
	if (x < 0) { src += -x;				iwidth -= -x;	x = 0; }				// ��������߽�
	if (y < 0) { src += src_width * -y;	iheight -= -y;	y = 0; }				// �������ϱ߽�

	// ������ͼ��ʼλ��
	dst += dst_width * y + x;

	// ʵ��͸����ͼ
	for (int iy = 0; iy < iheight; iy++)
	{
		for (int ix = 0; ix < iwidth; ix++)
		{
			int sa = ((src[ix] & 0xff000000) >> 24);
			int sr = ((src[ix] & 0xff0000) >> 16);	// Դֵ�Ѿ��˹���͸��ϵ��
			int sg = ((src[ix] & 0xff00) >> 8);		// Դֵ�Ѿ��˹���͸��ϵ��
			int sb = src[ix] & 0xff;				// Դֵ�Ѿ��˹���͸��ϵ��
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