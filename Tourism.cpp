#include "Tourism.h"
#include <iostream>
#include <stdlib.h>

#define VEX_FILE_NAME "Vex.txt"
#define EDGE_FILE_NAME "Edge.txt"

using namespace std;

CTourism::CTourism(void)
{
}

CTourism::~CTourism(void)
{
}

void CTourism::CreateGraph(void)
{
	cout<<"\n===== Create Scenic Spot Graph ====="<<endl;
	m_Graph.Init();
	FILE *pVex = fopen(VEX_FILE_NAME,"r");
	if(!pVex){
		cout<<"Error: T-T file couldn't not be opened.'"<<endl;
		return;}
	int nSpotCount = 0;
	fscanf(pVex,"%d\n",&nSpotCount);
	cout<<" Vertex Number : "<<nSpotCount<<endl;
	cout<<"----- Vertex -----"<<endl;
	Vex sVex;
	while(fscanf(pVex,"%d\n%s\n%s\n",&sVex.num, sVex.name, sVex.desc)!=-1)
	{
		cout<<sVex.num<<"-"<<sVex.name<<endl;
		if(!m_Graph.InsertVex(sVex))//insert info of file into the graph
		{
			cout<<"Error: missing information."<<endl;
			continue;}}
	fclose(pVex);
	pVex = NULL;
	FILE *pEdge = fopen(EDGE_FILE_NAME,"r");
	if(!pEdge){
		cout<<"Error: file couldn't not be opened."<<endl;
		return;}
	cout<<"----- Edge -----"<<endl;
	Edge sEdge;
	while(fscanf(pEdge,"%d\t%d\t%d\n",&sEdge.vex1, &sEdge.vex2 , &sEdge.weight)!=-1)
	{
		cout<<" (v"<<sEdge.vex1<<",v"<<sEdge.vex2<<") "<<sEdge.weight<<endl;
		if(!m_Graph.InsertEdge(sEdge)){
			cout<<"Error: missing information."<<endl;
			continue;}}
	fclose(pEdge);
	pVex =NULL;
}

void CTourism::GetSpotInfo(void)
{//Output all of vertex info
	cout<<"----- Spot Around -----"<<endl;
	int nVexNum = m_Graph.GetVexNum();  //how many vertexes are there
	for(int i = 0; i<nVexNum ; i++)
	{
		Vex sVex = m_Graph.GetVex(i);
		cout<<sVex.num<<"-"<<sVex.name<<endl;
	}
	int nVex;
	cout<<"Input the spot number you want to query :";
	cin>>nVex;
	if(nVex<0 || nVex>=nVexNum){
		cout<<"Error: Invalid Spot number. \nChoose an Existing SPot Number and Try again!!\n";
		return;
	}
	Vex sVex = m_Graph.GetVex(nVex);
	cout<<sVex.name<<endl;
	cout<<sVex.desc<<endl;
	Edge aEdge[20];
	int nEdgeNum = m_Graph.FindEdge(nVex,aEdge);//counts the edges
	cout<<"----- Spot Around -----"<<endl;
	for(int i = 0; i<nEdgeNum; i++)//Until number of relative vertex edge
	{ //ex> input 1 -> spotb : nEdgeNum =2
		Vex v1 = m_Graph.GetVex(aEdge[i].vex1); //already stored function FindEdge Output
		Vex v2 = m_Graph.GetVex(aEdge[i].vex2); 
		cout<<v1.name<<"->"<<v2.name<<" "<<aEdge[i].weight<<"m"<<endl;
	}
}

void CTourism::TravelPath(void)
{
	cout<<"\n===== Navigate Tourism Spot ====="<<endl;
	int nVexNum = m_Graph.GetVexNum();
	for(int i = 0 ; i<nVexNum; i++)
	{
		Vex sVex = m_Graph.GetVex(i);
		cout<<sVex.num<<"-"<<sVex.name<<endl;
	}
	int nVex;
	cout<<"Please input the number of origin : ";
	cin>>nVex;
	if(nVex<0 || nVex >= nVexNum){
		cout<<"Error: Wrong Spot number.\n";
		return;
	}
	PathList pList = (PathList)malloc(sizeof(Path));
	PathList pHead = pList;
	m_Graph.DFSTraverse(nVex,pList);
	cout<<"Tourist path :" <<endl;
	int i = 1;
	pList = pHead;
	while(pList->next){
		Vex sVex = m_Graph.GetVex(pList->vexs[0]);
		cout<<"Path"<<i++<<" : "<<sVex.name;
		for(int j = 1;j<nVexNum; j++)
		{
			sVex = m_Graph.GetVex(pList->vexs[j]);
			cout<<" -> "<<sVex.name;
		}
		cout<<endl;
		Path *temp = pList;
		pList = pList->next;
		free(temp);
	}
	free(pList);
	pList = NULL;
	pHead = NULL;
}

void CTourism::FindShortPath(void)
{
	cout<<"\n===== Search Shortest Path ====="<<endl;
	int nVexNum=m_Graph.GetVexNum();
	
	for(int i=0;i<nVexNum;i++)
	{
		Vex sVex = m_Graph.GetVex(i);
		cout<<sVex.num<<"-"<<sVex.name<<endl;
	}
	
	int nVexStart,nVexEnd;
	cout<<"\nPlease input the number of origin : ";
	cin>>nVexStart;
	cout<<"\nPlease input the number of destination : ";
	cin>>nVexEnd;
	//cout<<nVexNum;
	if(nVexStart<0 || nVexStart>= nVexNum || nVexEnd <0 || nVexEnd >= nVexNum)
	{
		cout<<"Error: Wrong Spot number. "<<endl;
		return;
	}
	Edge aPath[20];
	int nNum = m_Graph.FindShortPath(nVexStart,nVexEnd,aPath);
	Vex sVex = m_Graph.GetVex(aPath[0].vex1);
	int nLength = 0;
	cout<<"The shortest path is: ";
	cout<<sVex.name;
	for(int i = 0; i<nNum ; i++)
	{
		sVex = m_Graph.GetVex(aPath[i].vex2);
		cout<<"->"<<sVex.name;
		nLength +=aPath[i].weight;
	}
	cout<<endl;
	cout<<"The total length is: "<<nLength<<endl;
}


void CTourism::DesignPath(void)
{
	cout<<"\n===== Lay Circuit Planning ====="<<endl;
	Edge aPath[20];
	m_Graph.FindMinTree(aPath);
	int nVexNum = m_Graph.GetVexNum();
	if(nVexNum ==0)
	{
		cout<<"Error: Does not exist"<<endl;
		return;
	}
	int nAllLength=0;
	cout<<"Lay circuit between these spots : "<<endl;
	for(int i = 0 ; i<nVexNum-1;i++)
	{
		Vex sVex1 = m_Graph.GetVex(aPath[i].vex1);
		Vex sVex2 = m_Graph.GetVex(aPath[i].vex2);

		cout<<sVex1.name<<" - "<<sVex2.name<<"  "<<aPath[i].weight<<"m"<<endl;
		nAllLength += aPath[i].weight;
	}
	cout<<"The total length of laying circuit is: "<<nAllLength<<endl;
}
