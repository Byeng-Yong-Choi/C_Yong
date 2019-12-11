#include "CBYCore.h"
#define MAX_STUDENT 3

class Sample :public CBYCore
{
public:
	int a=0;
	int num=1;
public :
	 bool Init();
	 bool Frame();
	 bool Render();
	 bool Release();

public:
	Sample();
	~Sample();

private:
	//static int num;
};

//int Sample::num = 0;
Sample::Sample()
{

}
Sample::~Sample()
{

}

bool Sample::Init()
{	
	CBYNode<SmapleStu>* NPC1= Node->make(num++);
	Link.BackNodein(NPC1);

	CBYNode<SmapleStu>* NPC2 = Node->make(num++);
	Link.BackNodein(NPC2);

	CBYNode<SmapleStu>* NPC3 = Node->make(num++);
	Link.BackNodein(NPC3);

	return true;
}
bool Sample::Frame()
{ 
	Sleep(500);
	int i;
	if (a != 0) 
	{
  		Init();
	}
	if (Link.NodeNumber() == 6)
	{
		CBYNode<SmapleStu>* temp;
		Node = Link.getHead();
		Node = Node->m_next;
		for (i=0; i<3;i++)
		{
			temp = Node->m_next;
			Node->Delete(Node);
			Node = temp;
		}
	}
	
	if (a == 5)
	{
		GetGameRun = false;
	}
	
	a++;
	return true;
}
bool Sample::Render()
{
	//system("cls");
	Node = Link.getHead();
	Node = Node->m_next;
	for(Node;Node!=Link.getTail();Node=Node->m_next)
	std::cout << Node->studentNode.num << "번  " << Node->studentNode.name << "  " << Node->studentNode.kuk << "점  " << Node->studentNode.eng << "점  " << Node->studentNode.su << "점  " << Node->studentNode.sum << "점  " << Node->studentNode.avg << "점  " << std::endl;
	return true;
}
bool Sample::Release()
{

	return true;
}

CBY_RUN(Sample,"C_EX","C_Windows");