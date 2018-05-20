#pragma once

struct Vex
{
	int num;
	char name[20];
	char desc[1024];
};

struct Edge
{
	int vex1;
	int vex2;
	int weight;
};

typedef struct Path
{
	int vexs[20];
	Path *next;
}*PathList;

class CGraph
{
public:
	CGraph(void){};
	~CGraph(void){};

private:
	int m_aAdjMatrix[20][20]; //adjacent matrix
	Vex m_aVexs[20];		  //Vertex info array
	int m_nVexNum;			  //Current vertex number

public:
	void Init(void);
	bool InsertVex(Vex sVex); 
	bool InsertEdge(Edge sEdge); 
	
	Vex GetVex(int nVex);
	int FindEdge(int nVex, Edge aEdge[]);
	int GetVexNum();
	
	void DFSTraverse(int nVex, PathList &pList);
	int FindShortPath(int nVexStart, int nVexEnd, Edge aPath[]);
	void FindMinTree(Edge aPath[]);
private:
	void DFS(int nVex, bool visited[],int &index,PathList &pList);

};
