#include<iostream>
#include"ALGraph.h"
using namespace std;
int main()
{
	cout << "����һ��8�����������ͼ:" << endl;
	ALGraph udgGraph(8, UDG);
	udgGraph.Create();
	udgGraph.display();

	cout << "����һ��9������Ĵ�Ȩ����ͼ:" << endl;
	ALGraph wudgGraph(9, WUDG);
	wudgGraph.Create();
	wudgGraph.display();

	cout << "����һ��6�����������ͼ:" << endl;
	ALGraph dgGraph(6, DG);
	dgGraph.Create();
	dgGraph.display();

	cout << "����һ��9������Ĵ�Ȩ����ͼ:" << endl;
	ALGraph wdgGraph(9, WDG);
	wdgGraph.Create();
	wdgGraph.display();

	return 0;
}