#include "ALGraph.h"

void ALGraph::InitVertics()
{
	cout << "请输入每个顶点的关键字：" << endl;
	VexTexType val;
	for (int i = 0; i < this->Vexnum; i++)
	{
		cin >> val;
		this->vertices[i].data = val;
	}
}

int ALGraph::Locate(VexTexType vex)
{
	int i = 0;
	for (i = 0; i < this->Vexnum; i++)
	{
		if (vex == this->vertices[i].data)
		{
			return i;
		}
	}
	return 0;
}

void ALGraph::InsertArc(VexTexType vHead, VexTexType vTail, InfoType w)
{
	int i = Locate(vHead);
	int j = Locate(vTail);
	//构造一个表节点
	ArcNode* newArcNode = new ArcNode;
	newArcNode->adjVex = j;
	newArcNode->nextArc = NULL;
	newArcNode->info = w;
	//arcNode 是vertics[vHead]的邻接表
	ArcNode* arcNode = this->vertices[i].firstArc;
	if (arcNode == NULL)
	{
		this->vertices[i].firstArc = newArcNode;
	}
	else {
		while (arcNode->nextArc != NULL)
		{
			arcNode = arcNode->nextArc;
		}
		arcNode->nextArc = newArcNode;
	}
	this->Arcnum++;
}

void ALGraph::CreateDG()
{
	InitVertics();
	VexTexType vHead, vTail;
	cout << "请依次输入每条边的开始顶点和结束顶点：" << endl;
	while (cin >> vHead >> vTail)
	{
		InsertArc(vHead, vTail, 0);
	}
}

void ALGraph::CreateWDG()
{
	InitVertics();
	VexTexType vHead, vTail;
	InfoType w;
	cout << "请依次输入每条边的开始顶点和结束顶点和权值：" << endl;
	while (cin >> vHead >> vTail>>w)
	{
		InsertArc(vHead, vTail, w);
	}
}

void ALGraph::CreateUDG()
{
	InitVertics();
	VexTexType vHead, vTail;
	cout << "请依次输入每条边的开始顶点和结束顶点：" << endl;
	while (cin >> vHead >> vTail)
	{
		InsertArc(vHead, vTail, 0);
		InsertArc(vTail, vHead, 0);
	}
}

void ALGraph::CreateWUDG()
{
	InitVertics();
	VexTexType vHead, vTail;
	InfoType w;
	cout << "请依次输入每条边的开始顶点和结束顶点和权值：" << endl;
	while (cin >> vHead >> vTail>>w)
	{
		InsertArc(vHead, vTail, w);
		InsertArc(vTail, vHead, w);
	}
}

void ALGraph::Create()
{
	switch (Kind)
	{
	case DG:
	{
		CreateDG();    //构造一个有向图
		break;
	}
	case WDG:
	{
		CreateWDG();    //构造一个带权有向图
		break;
	}
	case UDG:
	{
		CreateUDG();    //构造一个无向图
		break;
	}
	case WUDG:
	{
		CreateWUDG();   //构造一个带权无向图
		break;
	}
	default:
		return;
	}
}

void ALGraph::display()
{
	for (int i = 0; i < this->Vexnum; i++)
	{
		cout << "第" << i + 1 << "个顶点是：" << this->vertices[i].data
			<< " 邻接表为：";
		ArcNode* arcNode = this->vertices[i].firstArc;
		while (arcNode != NULL)
		{
			cout << "->" << this->vertices[arcNode->adjVex].data
				<< "(" << arcNode->info << ")";
			arcNode = arcNode->nextArc;
		}
		cout << endl;
	}
}
