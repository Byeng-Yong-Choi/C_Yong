#include "TObject.h"
ostream& operator << (ostream& os, TObject& t)
{
	os << t.m_ID << "," <<
		t.m_iSubject[0] << "," <<
		t.m_iSubject[1] << "," <<
		t.m_iSubject[2] << "," <<
		t.m_iTotal;
	return os;
}
istream& operator >> (istream& is, TObject& t)
{
	is >> t.m_iTotal;
	return is;
}

float operator / (int iCounter, TObject& t)
{
	return t.m_iTotal / (float)iCounter;
}
TObject TObject::operator+(const TObject& t)
{
	TObject ret;
	ret.m_iSubject[0] = m_iSubject[0] + t.m_iSubject[0];
	ret.m_iSubject[1] = m_iSubject[1] + t.m_iSubject[1];
	ret.m_iSubject[2] = m_iSubject[2] + t.m_iSubject[2];
	ret.m_iTotal = m_iTotal + t.m_iTotal;
	return ret;
}
float TObject::operator/(int iCounter)
{
	return m_iTotal / (float)iCounter;
}
TObject::TObject(const TObject& node)
{
	m_ID = node.m_ID;
	m_iSubject[0] = node.m_iSubject[0];
	m_iSubject[1] = node.m_iSubject[1];
	m_iSubject[2] = node.m_iSubject[2];
	m_iTotal = node.m_iTotal;
}
bool TObject::Render()
{
	printf("\nID=%-10d", m_ID);
	for (int iSub = 0; iSub < MAX_SUBJECT; iSub++)
	{
		printf("[S%d=%-2d],", iSub,
			m_iSubject[iSub]);
	}
	return true;
}
bool TObject::Frame()
{
	printf("\Frame");
	return true;
}
bool TObject::Release()
{
	printf("\nRelease");	
	return true;
}