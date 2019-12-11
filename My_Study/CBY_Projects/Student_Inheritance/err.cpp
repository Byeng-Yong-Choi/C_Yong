#include "err.h"


void err::WroongChoice()
{
	if(errcode==0)
	std::cout << "잘못된 번호를 골랐습니다 1~8번까지의 번호를 골라주세요." << std::endl;
	else if (errcode==1)
	std::cout << "85번을 고르셨습니다. 1~8번까지의 번호를 골라주세요." << std::endl;

}

err::err(int a)
{
	errcode = a;
}


err::~err()
{
}
