#pragma once
#include "Cstd.h"
class CBYBitMap
{
public:
	HBITMAP c_HBitmap;			//��Ʈ�� �ڵ�
	BITMAP c_Bitmap;			//��Ʈ���� ���� ���ϱ� ���� ����
	HDC MemDC;					//��Ʈ�� �̹����� �޸�DC
	RECT BitMapRt;				//��Ʈ���� ��ġ������ �����ϱ� ���� RECT
	RECT rtdesk;				//�̹����� ��µ� ��ǥ�� ����,�� ����
	RECT rtsrc;					//��Ʈ�� �̹������� ����ҷ��� ���� ��ǥ
	float weIX;					//������ǥ X
	float weIY;					//������ǥ Y

public:
	bool Init();
	bool Frame();
	bool Render();									//�⺻ �̹��� ���
	bool Render(float IX, float IY);				//�ð� ����ȭ�� x,y��ǥ�� �Ǽ��� �Ѿ�ý� ����ϰ� �� Render
	bool Release();
	bool Load(const TCHAR* FileName);				//�̹����� �ε��Ͽ� �ڵ�� DC�� �ִ� �Լ�
	bool weaponRender(float IY);					//���� �߻�� ��µǴ� ������ ��½��۵� ��ġ���� y������ ���� �ö󰡱⸸ �Ѵ�
	void rect(RECT charRt1, RECT charRt2);			//��Ʈ�� �̹������� ��¹����� �޾Ƴ��� �Լ�

public:
	CBYBitMap();
	~CBYBitMap();
};

