#include "err.h"


void err::WroongChoice()
{
	if(errcode==0)
	std::cout << "�߸��� ��ȣ�� ������ϴ� 1~8�������� ��ȣ�� ����ּ���." << std::endl;
	else if (errcode==1)
	std::cout << "85���� ���̽��ϴ�. 1~8�������� ��ȣ�� ����ּ���." << std::endl;

}

err::err(int a)
{
	errcode = a;
}


err::~err()
{
}
