#include<iostream>
#include"ALGraph.h"
using namespace std;
int main()
{
	cout << "构造一个8个顶点的无向图:" << endl;
	ALGraph udgGraph(8, UDG);
	udgGraph.Create();
	udgGraph.display();

	cout << "构造一个9个顶点的带权无向图:" << endl;
	ALGraph wudgGraph(9, WUDG);
	wudgGraph.Create();
	wudgGraph.display();

	cout << "构造一个6个顶点的有向图:" << endl;
	ALGraph dgGraph(6, DG);
	dgGraph.Create();
	dgGraph.display();

	cout << "构造一个9个顶点的带权有向图:" << endl;
	ALGraph wdgGraph(9, WDG);
	wdgGraph.Create();
	wdgGraph.display();

	return 0;
}