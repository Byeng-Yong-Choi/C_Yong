#include "SmapleStu.h"


#include "SmapleStu.h"


void SmapleStu::begin(int a)
{
	name[0] = 65 + rand() % 26;
	name[1] = 65 + rand() % 26;
	name[2] = 65 + rand() % 26;
	name[3] = '\0';
	num = a;

	kuk = rand() % 101;
	eng = rand() % 101;
	su = rand() % 101;

	sum = kuk + eng + su;
	avg = (double)sum / 3;
}


SmapleStu::SmapleStu(int a)
{
	name[5] = { 0, };
	num = 0;
	su = 0;
	kuk = 0;
	sum = 0;
	avg = 0;
	begin(a);
}

SmapleStu::SmapleStu()
{
	name[5] = { 0, };
	num = 0;
	su = 0;
	kuk = 0;
	sum = 0;
	avg = 0;
}

SmapleStu::~SmapleStu()
{
}