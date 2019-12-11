#pragma once
#include <map>
#include <string>
#include "BitMap.h"
class C_BitMapManager
{
private:
	int BitMap_Index;
	std::map<std::wstring, BitMap*> list;

public:
	static C_BitMapManager& get()
	{
		static C_BitMapManager mgr;
		return mgr;
	}
	BitMap* Load(const TCHAR* filename);

public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();

public:
	C_BitMapManager();
	~C_BitMapManager();
};

