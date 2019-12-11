#pragma once
#include "BitMap.h"
#include "C_BitMapManager.h"
#include <map>
#include <list>
#include <vector>

class C_Object
{
public:
	enum { KEY_FREE, KEY_UP, KEY_HOLD, KEY_PUSH };
	std::vector<RECT> m_rtlist;

public:
	HDC TransDC;
	HDC BrushDC;
	HDC MaskDC;
	HDC ColorDC;
	BLENDFUNCTION alpha;
	HBITMAP Rotat;
	HBITMAP OldBitMap;
	HBITMAP OldMaskBitMap;
	HBITMAP OldColorBitMap;
	HBRUSH TransBrush;
	BitMap* m_pBitMap;
	BitMap* m_pMaskBitMap;
	CBY_Input Input;
	RECT BitMapRt;
	RECT rtsrc;
	float IX;
	float IY;
	float DestSize;

public:
	bool Load(const TCHAR* FileName, const TCHAR* MaskFileName=nullptr);
	virtual bool SetPosition(float x, float y);
	virtual bool GetRECT(RECT rt1);
	HBITMAP GetRotationBitMap(float Angle, HDC SrcDC);
	virtual bool Init();
	virtual bool Frame();
	virtual bool Render();									//기본 이미지 출력
	virtual bool Release();

public:
	C_Object();
	virtual ~C_Object();
};

