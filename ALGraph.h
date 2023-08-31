#pragma once
#ifndef ALGRAPH_H
#define ALGRAPH_H
#include<iostream>
using namespace std;
enum GraphKind{DG,WDG,UDG,WUDG};
#define Max_Node 100
typedef string VexTexType;
typedef int InfoType;
//表节点
struct ArcNode {
	int adjVex;//该弧所指向的顶点的位置
	struct ArcNode* nextArc;//指向下一条弧的指针
	InfoType info;
};
//头节点
typedef struct VNode {
	VexTexType data;//顶点信息
	ArcNode* firstArc;//指向第一条依附于该顶点的弧的指针
}AdjList[Max_Node];
class ALGraph {
private:
	AdjList vertices;
	int Vexnum;//图的当前顶点数
	int Arcnum;//图的当前弧数
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
	void InsertArc(VexTexType vHead, VexTexType vTail, InfoType w);//插入一个表结点
	void CreateDG();
	void CreateWDG();
	void CreateUDG();
	void CreateWUDG();
	void Create();
	void display();
};
#endif // !ALGRAPH_H
