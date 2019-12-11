#include "student.h"

int student::number = 1;

void student::makedata(int i)
{
	num = i;
	name[0] = 65 + rand() % 26;
	name[1] = 65 + rand() % 26;
	name[2] = 65 + rand() % 26;
	name[3] = '\0';

	kuk = rand() % 101;
	eng = rand() % 101;
	su = rand() % 101;

	sum = kuk + eng + su;
	avg = (double)sum / 3;
}

void student::Show()
{
	cout <<"\t\t\t\t   "<<num <<"\t  "<<name <<"\t   "<< kuk << "\t   " <<eng <<"\t   " <<su <<"\t  " <<sum << "\t   "<< avg << endl;
}

//int student::operator+(student& plus)
//{
//	student temp;
//	temp.sum = sum + plus.sum;
//	return temp.sum;
//}
//
//int student::operator-(student& const plus)
//{
//	student temp;
//	temp.sum = sum - plus.sum;
//	return temp.sum;
//}
//double student::operator/(student& const plus)
//{
//	student temp;
//	temp.sum = sum / (double)plus.sum;
//	return temp.sum;
//}
//int student::operator*(student& const plus)
//{
//	student temp;
//	temp.sum = sum * plus.sum;
//	return temp.sum;
//}
///*student student::operator+=(student& const plus)
//student student::operator-=(student& const plus)
//student student::operator*=(student& const plus)
//student student::operator/=(student& const plus)*/

student::student()
{

}

student::student(int i)
{
	makedata(i);
}



student::~student()
{
}
