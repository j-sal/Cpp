#include <iostream>
#include <stdlib.h>
#include "Graph.h"

using namespace std;

void CGraph::Init(void)
{ 
	m_nVexNum = 0;
	for(int i = 0; i<20;i++)
	{
		for(int j=0; j<20; j++)
		{
			m_aAdjMatrix[i][j] = 0;
		}
	}
}


Vex CGraph::GetVex(int v)
{
	return m_aVexs[v];
}


bool CGraph::InsertVex(Vex vex)
{
	if(m_nVexNum==20) return false;	
	m_aVexs[m_nVexNum++]=vex;
	return true;
}


bool CGraph::InsertEdge(Edge sEdge)
{
	if(sEdge.vex1<0 || sEdge.vex1 >= m_nVexNum || sEdge.vex2<0 || sEdge.vex2>=m_nVexNum) return false;
	
	m_aAdjMatrix[sEdge.vex1][sEdge.vex2] = sEdge.weight;
	m_aAdjMatrix[sEdge.vex2][sEdge.vex1] = sEdge.weight;
	    return true;
}


int CGraph::GetVexNum()
{
	return m_nVexNum;
}


int CGraph::FindEdge(int nVex, Edge aEdge[])
{
	int nEdgeNum = 0;
	for(int i = 0; i<m_nVexNum; i++)
	{
		if(m_aAdjMatrix[nVex][i]>0)
		{
			aEdge[nEdgeNum].vex1=nVex;
			aEdge[nEdgeNum].vex2=i;
			aEdge[nEdgeNum].weight=m_aAdjMatrix[nVex][i];
			nEdgeNum++;
		}
	}
	return nEdgeNum;
}


void CGraph::DFSTraverse(int nVex,PathList &pList)
{ 
	bool visited[20] = {false};
	int index = 0;
	DFS(nVex,visited,index,pList);
}


void CGraph::DFS(int nVex, bool visited[],int &index, PathList &pList)
{     
	visited[nVex] = true; 
	pList->vexs[index++] = nVex; 
	int nVexNum = 0;  
	
	for(int i = 0; i<m_nVexNum; i++)
	{
		if(visited[i]) nVexNum++;
	}
	
	if(nVexNum == m_nVexNum){
		pList->next = (PathList)malloc(sizeof(Path));
		
		for(int i =0 ; i< m_nVexNum ; i++)
		{
			pList->next->vexs[i]=pList->vexs[i];
		}
		
		pList = pList->next;
		pList->next= NULL;
	}
	else
	{
		for(int i = 0; i<m_nVexNum; i++)
		{
			if(!visited[i] && (m_aAdjMatrix[nVex][i]>0)) 
			{ 
				DFS(i,visited,index,pList); 
				visited[i] = false;
				index--;
			}
		}
	}

}

int CGraph::FindShortPath(int nVexStart, int nVexEnd, Edge aPath[])
{ 
	int nShortPath[20][20];
	int distance[20];
	bool visited[20];
	int v;
	for(v=0; v <m_nVexNum ;v++)
	{
		visited[v]=false;
		if(m_aAdjMatrix[nVexStart][v])
		{
			distance[v] = m_aAdjMatrix[nVexStart][v];
		}
		else
		{
			distance[v]=0x7FFFFFFF;
		}

		nShortPath[v][0] = nVexStart;
		for(int w= 1; w<m_nVexNum; w++) nShortPath[v][w] = -1;
	}
	visited[nVexStart]=true;
	int min;
	for(int i=1;i<m_nVexNum ; i++) {

		min = 0x7FFFFFFF;
		bool bAdd = false;
		for(int w= 0; w<m_nVexNum; w++)
		{
			if(!visited[w]){
				if(distance[w]<min){
					v=w;
					min = distance[w];
					bAdd=true;
				}
			}	
		}
		if(!bAdd) break;

		visited[v] = true; //check visited
		nShortPath[v][i]=v; //which vertex it has visited
		for(int w=0; w<m_nVexNum; w++)
		{
			if(!visited[w] && (min+m_aAdjMatrix[v][w]<distance[w]) && (m_aAdjMatrix[v][w]!=0)){
				distance[w]=min + m_aAdjMatrix[v][w];
				for(int i=0; i<m_nVexNum; i++) nShortPath[w][i] = nShortPath[v][i];
			}
		}
	}
	int index = 0;
	int nVex1=nVexStart;
	for(int i=1; i<m_nVexNum; i++)
	{
		if(nShortPath[nVexEnd][i]!=-1)
		{
			aPath[index].vex1= nVex1;
			aPath[index].vex2= nShortPath[nVexEnd][i];
			aPath[index].weight=m_aAdjMatrix[aPath[index].vex1][aPath[index].vex2];
			nVex1 = nShortPath[nVexEnd][i];
			index++;
		}
	}
	return index;   
}


void CGraph::FindMinTree(Edge aPath[])
{
	bool visited[20];
	for(int i = 0; i< 20;i++)
	{
		visited[i] = false; 
	}
	visited[0] = true;  
	int min;
	int nVex1,nVex2;
	for(int k=0 ;k<m_nVexNum-1 ;k++)
	{
		min = 0x7FFFFFFF;
		for(int i = 0; i < m_nVexNum; i++)
		{
			if(visited[i])
			{
				for(int j =0; j<m_nVexNum; j++)
				{
					if(!visited[j])
					{
						if((m_aAdjMatrix[i][j]<min)&&(m_aAdjMatrix[i][j]!=0))
						{
							nVex1 = i;
							nVex2 = j;
							min = m_aAdjMatrix[i][j];
						}
					}
				}
			}
		}
		aPath[k].vex1 = nVex1;
		aPath[k].vex2 = nVex2;
		aPath[k].weight=m_aAdjMatrix[nVex1][nVex2];

		visited[nVex1] = true;
		visited[nVex2] = true;
	}
}

