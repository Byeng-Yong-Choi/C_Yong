#include "StudentMgn.h"


void StudentMgn::HighGetData()
{
	Name[0] = 90 - rand() % 26;
	Name[1] = 90 - rand() % 26;
	Name[2] = 90 - rand() % 26;
	Name[3] = '\0';
	Age = 19 - rand() % 3;
	Gender=rand() % 2;
	if (Gender == 0)
		Gender = 'M';
	else
		Gender = 'W';
}

void StudentMgn::UnivGetData()
{
	Name[0] = 90 - rand() % 26;
	Name[1] = 90 - rand() % 26;
	Name[2] = 90 - rand() % 26;
	Name[3] = '\0';
	Age = 20 + rand() % 6;
	Gender = rand() % 2;
	if (Gender == 0)
		Gender = 'M';
	else
		Gender = 'W';
}


StudentMgn::StudentMgn()
{
}

StudentMgn::~StudentMgn()
{
}
