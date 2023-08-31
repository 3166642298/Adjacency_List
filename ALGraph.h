#pragma once
#ifndef ALGRAPH_H
#define ALGRAPH_H
#include<iostream>
using namespace std;
enum GraphKind{DG,WDG,UDG,WUDG};
#define Max_Node 100
typedef string VexTexType;
typedef int InfoType;
//��ڵ�
struct ArcNode {
	int adjVex;//�û���ָ��Ķ����λ��
	struct ArcNode* nextArc;//ָ����һ������ָ��
	InfoType info;
};
//ͷ�ڵ�
typedef struct VNode {
	VexTexType data;//������Ϣ
	ArcNode* firstArc;//ָ���һ�������ڸö���Ļ���ָ��
}AdjList[Max_Node];
class ALGraph {
private:
	AdjList vertices;
	int Vexnum;//ͼ�ĵ�ǰ������
	int Arcnum;//ͼ�ĵ�ǰ����
	GraphKind Kind;
public:
	ALGraph() = default;
	ALGraph(int verNum, GraphKind kind) :Vexnum(verNum), Arcnum(0), Kind(kind) {
		for (int i = 0; i < this->Vexnum; i++)
		{
			this->vertices[i].firstArc = NULL;
		}
	}
	void InitVertics();
	int Locate(VexTexType vex);
	void InsertArc(VexTexType vHead, VexTexType vTail, InfoType w);//����һ������
	void CreateDG();
	void CreateWDG();
	void CreateUDG();
	void CreateWUDG();
	void Create();
	void display();
};
#endif // !ALGRAPH_H
