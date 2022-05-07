#include "�Q�[���f�[�^�\��.h"

#include <gdiplus.h>
#pragma comment (lib, "gdiplus.lib")        // �����N���ɕK�v�ȃ��C�u����

using namespace Gdiplus;

extern HWND tenshouWND;


HBITMAP CreateWindowBitmap(HWND hWnd)
{
	HBITMAP hbmNew;
	HDC hDC, hMemDC;
	HGDIOBJ hbmOld;
	RECT rc;
	SIZE siz;
	DWORD dwError = 0;

	GetWindowRect(hWnd, &rc);
	siz.cx = rc.right - rc.left;
	siz.cy = rc.bottom - rc.top;

	hbmNew = NULL;
	hDC = GetWindowDC(hWnd);
	if (hDC != NULL)
	{
		hMemDC = CreateCompatibleDC(hDC);
		if (hMemDC != NULL)
		{
			hbmNew = CreateCompatibleBitmap(hDC, siz.cx, siz.cy);

			if (hbmNew != NULL)
			{
				hbmOld = SelectObject(hMemDC, hbmNew);
				BitBlt(hMemDC, 0, 0, siz.cx, siz.cy,
					hDC, 0, 0, SRCCOPY);
				SelectObject(hMemDC, hbmOld);
			}
			else
				dwError = GetLastError();
			DeleteDC(hMemDC);
		}
		else
			dwError = GetLastError();
		ReleaseDC(hWnd, hDC);
		SetLastError(dwError);
	}

	return hbmNew;
}


int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT  num = 0, size = 0;

	GetImageEncodersSize(&num, &size);
	if (size == 0)
		return -1;  // Failure

	ImageCodecInfo* pImageCodecInfo = (ImageCodecInfo*)malloc(size);
	if (pImageCodecInfo == NULL)
		return -1;  // Failure

	GetImageEncoders(num, size, pImageCodecInfo);

	for(UINT j = 0; j < num; ++j)
	{
		if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;  // Success
		}
	}

	free(pImageCodecInfo);
	return -1;  // Failure
}

BOOL SaveBitmapAsPngFile(LPCSTR pszFileName, HBITMAP hbm)
{
	WCHAR wszFileName[MAX_PATH];
	MultiByteToWideChar(CP_ACP, 0, pszFileName, -1, wszFileName, MAX_PATH);

	CLSID clsid;
	Bitmap b(hbm, (HPALETTE)GetStockObject(DEFAULT_PALETTE));
	if (GetEncoderClsid(L"image/png", &clsid) >= 0)
	{
		b.Save(wszFileName, &clsid, NULL);
		return TRUE;
	}
	return FALSE;
}

BOOL SaveBitmapAsJpegFile(LPCSTR pszFileName, HBITMAP hbm)
{
	WCHAR wszFileName[MAX_PATH];
	MultiByteToWideChar(CP_ACP, 0, pszFileName, -1, wszFileName, MAX_PATH);

	CLSID clsid;
	Bitmap b(hbm, (HPALETTE)GetStockObject(DEFAULT_PALETTE));
	if (GetEncoderClsid(L"image/jpeg", &clsid) >= 0)
	{
		b.Save(wszFileName, &clsid, NULL);
		return TRUE;
	}
	return FALSE;
}

BOOL SaveBitmapAsBmpFile(LPCSTR pszFileName, HBITMAP hbm)
{
	WCHAR wszFileName[MAX_PATH];
	MultiByteToWideChar(CP_ACP, 0, pszFileName, -1, wszFileName, MAX_PATH);

	CLSID clsid;
	Bitmap b(hbm, (HPALETTE)GetStockObject(DEFAULT_PALETTE));
	if (GetEncoderClsid(L"image/bmp", &clsid) >= 0)
	{
		b.Save(wszFileName, &clsid, NULL);
		return TRUE;
	}
	return FALSE;
}
//------------------------------------------------









//------------------------------------------------------


namespace �֐� {

	// �N���C�A���g��`��bmp�ւ̕ۑ�
	void �f�o�b�O�摜�o��(string �t�@�C����) {

		GdiplusStartupInput gdiplusStartupInput;
		ULONG_PTR gdiplusToken;
	    
		// GDI+�̏������B
		GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	    
		HBITMAP hbm = CreateWindowBitmap(tenshouWND);
		SaveBitmapAsBmpFile(�t�@�C����.c_str(), hbm);
		DeleteObject(hbm);
	    
		// GDI+�̌㏈���B
		GdiplusShutdown(gdiplusToken);
	}
}


