#include "C_BitMapManager.h"

BitMap* C_BitMapManager::Load(const TCHAR* filename)
{
	std::map<std::wstring, BitMap*>::iterator iter;
	iter = list.find(filename);
	if (iter != list.end())
	{
		return (BitMap*)iter->second;
	}

	BitMap* data = new BitMap;
	data->Init();
	if (data->Load(filename))
	{
		list.insert(std::make_pair(filename, data));
		return list[filename];
	}

	delete data;

	return nullptr;
}


bool C_BitMapManager::Init()
{
	return true;
}

bool C_BitMapManager::Frame()
{
	return true;
}

bool C_BitMapManager::Render()
{
	return true;
}

bool C_BitMapManager::Release()
{
	std::map<std::wstring, BitMap*>::iterator iter;
	for (iter = list.begin(); iter != list.end(); iter++)
	{
		BitMap* pBitMap= iter->second;
		pBitMap->Release();
		delete pBitMap;
	}
	list.clear();
	return true;
}


C_BitMapManager::C_BitMapManager()
{
	BitMap_Index = -1;
}


C_BitMapManager::~C_BitMapManager()
{
	Release();
}
