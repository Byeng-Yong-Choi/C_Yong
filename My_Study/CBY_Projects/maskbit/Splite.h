#pragma once
#include <map>
#include <list>
#include <vector>
#include "C_Actor.h"

//typedef std::vector<RECT> RTLIST;
class Splite: public C_Actor
{
public:
	std::vector<vector<RECT>> Effect_Object_Src;

public:
	Splite();
	~Splite();
};

