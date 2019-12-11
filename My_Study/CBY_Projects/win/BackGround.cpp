#include "BackGround.h"

bool BackGround::Init()
{
	return true;
}

bool BackGround::Frame()
{
	return true;
}

bool BackGround::Render()
{
	C_Object::GetRECT(rtdesk, rtsrc);
	C_Object::Render();
	return true;
}

bool BackGround::Release()
{
	return true;
}

BackGround::BackGround()
{
}


BackGround::~BackGround()
{
}
