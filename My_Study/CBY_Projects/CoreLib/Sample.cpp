#include "TCore.h"
class TObjChild : public TObject
{
public:
	TObjChild() 
	{
	}
	TObjChild(int id, int kor, int end, int mat)
		: TObject(id, kor, end, mat)
	{

	}
	~TObjChild() {}
};
class Sample : public TCore
{
	int *    m_pData;
public:
	bool  Init()	override;
	bool  Render()	override;
	bool  Frame()	override;
	bool  Release()	override;
public:
	Sample() {};
	~Sample() {}
};
bool  Sample::Init()
{
	m_pData = new int[10];
	TObjChild* pHero = new TObjChild(
		m_ObjectList.Size(),
		rand() % 101,
		rand() % 101,
		rand() % 101);
	m_ObjectList.BackInsertData(pHero);

	TObjChild* pNpcA = new TObjChild(
		m_ObjectList.Size(),
		rand() % 101,
		rand() % 101,
		rand() % 101);
	m_ObjectList.BackInsertData(pNpcA);

	TObjChild* pNpcB = new TObjChild(
		m_ObjectList.Size(),
		rand() % 101,
		rand() % 101,
		rand() % 101);
	m_ObjectList.BackInsertData(pNpcB);
	
	return true;
}
bool  Sample::Release()
{
	delete[] m_pData;
	
	return true;
}
bool  Sample::Render()
{
	for (TNode<TObject>* pNext = 
				m_ObjectList.start() ;
		pNext != m_ObjectList.tail();
		pNext = pNext->m_pNext)
	{
		pNext->m_Data.Render();
	}
	return true;
}
bool  Sample::Frame()
{
	for (TNode<TObject>* pNext =
		m_ObjectList.start();
		pNext != m_ObjectList.tail();
		pNext = pNext->m_pNext)
	{
		pNext->m_Data.Frame();
	}
	return true;
}
void main()
{
	Sample  gDemo;
	if (gDemo.CreateWin())
	{
		gDemo.Run();
	}
}