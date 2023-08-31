#include "ALGraph.h"

void ALGraph::InitVertics()
{
	cout << "������ÿ������Ĺؼ��֣�" << endl;
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
	//����һ����ڵ�
	ArcNode* newArcNode = new ArcNode;
	newArcNode->adjVex = j;
	newArcNode->nextArc = NULL;
	newArcNode->info = w;
	//arcNode ��vertics[vHead]���ڽӱ�
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
	cout << "����������ÿ���ߵĿ�ʼ����ͽ������㣺" << endl;
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
	cout << "����������ÿ���ߵĿ�ʼ����ͽ��������Ȩֵ��" << endl;
	while (cin >> vHead >> vTail>>w)
	{
		InsertArc(vHead, vTail, w);
	}
}

void ALGraph::CreateUDG()
{
	InitVertics();
	VexTexType vHead, vTail;
	cout << "����������ÿ���ߵĿ�ʼ����ͽ������㣺" << endl;
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
	cout << "����������ÿ���ߵĿ�ʼ����ͽ��������Ȩֵ��" << endl;
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
		CreateDG();    //����һ������ͼ
		break;
	}
	case WDG:
	{
		CreateWDG();    //����һ����Ȩ����ͼ
		break;
	}
	case UDG:
	{
		CreateUDG();    //����һ������ͼ
		break;
	}
	case WUDG:
	{
		CreateWUDG();   //����һ����Ȩ����ͼ
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
		cout << "��" << i + 1 << "�������ǣ�" << this->vertices[i].data
			<< " �ڽӱ�Ϊ��";
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
