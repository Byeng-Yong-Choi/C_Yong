#pragma once
#include <iostream>
class err
{
public:
	err(int a);
	~err();
	enum errtype{a=0,b};

public:
	void WroongChoice();

public:
	int errcode;

};

